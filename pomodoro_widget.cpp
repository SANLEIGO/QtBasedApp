#include "pomodoro_widget.h"
#include "ui_pomodoro_widget.h"
#include "pomodoro_history_widget.h"
#include <QSqlError>
#include <QDebug>

PomodoroWidget::PomodoroWidget(const QString &account, QWidget *parent)
    : QWidget(parent), ui(new Ui::PomodoroWidget), userAccount(account)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    remainingTime = 25 * 60; // 25分钟
    pauseCount = 0;
    isPaused = false;
    currentTaskId = -1;

    setupConnections();
    loadTasks();
    updateTaskList();

    ui->pauseButton->setEnabled(false);
    ui->stopButton->setEnabled(false);
}

PomodoroWidget::~PomodoroWidget()
{
    delete ui;
}

void PomodoroWidget::setupConnections()
{
    connect(timer, &QTimer::timeout, this, &PomodoroWidget::updateTimer);
    connect(ui->startButton, &QPushButton::clicked, this, &PomodoroWidget::startPomodoro);
    connect(ui->pauseButton, &QPushButton::clicked, this, &PomodoroWidget::pausePomodoro);
    connect(ui->stopButton, &QPushButton::clicked, this, &PomodoroWidget::stopPomodoro);
    connect(ui->historyButton, &QPushButton::clicked, this, &PomodoroWidget::showHistory);
    connect(ui->deleteHistoryButton, &QPushButton::clicked, this, &PomodoroWidget::deleteHistory);
}

void PomodoroWidget::updateTimer()
{
    if (remainingTime > 0) {
        remainingTime--;
        int minutes = remainingTime / 60;
        int seconds = remainingTime % 60;
        ui->timerLabel->setText(QString("%1:%2").arg(minutes, 2, 10, QChar('0')).arg(seconds, 2, 10, QChar('0')));
    } else {
        timer->stop();
        saveSession(true);
        QMessageBox::information(this, "完成", "番茄钟时间到！");
        ui->startButton->setEnabled(true);
        ui->pauseButton->setEnabled(false);
        ui->stopButton->setEnabled(false);
        remainingTime = 25 * 60;
        ui->timerLabel->setText("25:00");
    }
}

void PomodoroWidget::startPomodoro()
{
    if (ui->taskList->currentItem() == nullptr) {
        QMessageBox::warning(this, "警告", "请先选择一个任务！");
        return;
    }

    if (!isPaused) {
        currentTaskId = ui->taskList->currentItem()->data(Qt::UserRole).toInt();
        startTime = QDateTime::currentDateTime();
        pauseCount = 0;
    }

    timer->start(1000);
    ui->startButton->setEnabled(false);
    ui->pauseButton->setEnabled(true);
    ui->stopButton->setEnabled(true);
    isPaused = false;
}

void PomodoroWidget::pausePomodoro()
{
    if (timer->isActive()) {
        timer->stop();
        ui->startButton->setEnabled(true);
        pauseCount++;
        isPaused = true;
    }
}

void PomodoroWidget::stopPomodoro()
{
    timer->stop();
    saveSession(false);
    remainingTime = 25 * 60;
    ui->timerLabel->setText("25:00");
    ui->startButton->setEnabled(true);
    ui->pauseButton->setEnabled(false);
    ui->stopButton->setEnabled(false);
    isPaused = false;
}

void PomodoroWidget::loadTasks()
{
    QSqlQuery query;
    query.prepare("SELECT id, task_name FROM tasks WHERE account = :account AND completed = 0");
    query.bindValue(":account", userAccount);

    if (!query.exec()) {
        qDebug() << "Error loading tasks:" << query.lastError().text();
        return;
    }

    ui->taskList->clear();
    while (query.next()) {
        QListWidgetItem *item = new QListWidgetItem(query.value("task_name").toString());
        item->setData(Qt::UserRole, query.value("id").toInt());
        ui->taskList->addItem(item);
    }
}

void PomodoroWidget::updateTaskList()
{
    loadTasks();
}

void PomodoroWidget::saveSession(bool completed)
{
    QDateTime endTime = QDateTime::currentDateTime();
    int duration = startTime.secsTo(endTime);

    QSqlQuery query;
    query.prepare("INSERT INTO pomodoro_sessions (session_id, task_id, account, start_time, end_time, duration, is_completed, pause_count, notes) "
                  "VALUES (NULL, :task_id, :account, :start_time, :end_time, :duration, :is_completed, :pause_count, '')");

    query.bindValue(":task_id", currentTaskId);
    query.bindValue(":account", userAccount);
    query.bindValue(":start_time", startTime);
    query.bindValue(":end_time", endTime);
    query.bindValue(":duration", duration);
    query.bindValue(":is_completed", completed ? 1 : 0);
    query.bindValue(":pause_count", pauseCount);

    if (!query.exec()) {
        qDebug() << "Error saving session:" << query.lastError().text();
        return;
    }

    updateStatistics();
}

void PomodoroWidget::updateStatistics()
{
    QDate currentDate = QDate::currentDate();

    QSqlQuery query;
    query.prepare("SELECT COUNT(*) as total_pomos, "
                  "SUM(CASE WHEN is_completed = 1 THEN 1 ELSE 0 END) as completed_pomos, "
                  "SUM(duration) as total_duration, "
                  "AVG(pause_count) as avg_pauses "
                  "FROM pomodoro_sessions "
                  "WHERE account = :account AND DATE(start_time) = :date");

    query.bindValue(":account", userAccount);
    query.bindValue(":date", currentDate);

    if (!query.exec() || !query.next()) {
        qDebug() << "Error updating statistics:" << query.lastError().text();
        return;
    }

    int totalPomos = query.value("total_pomos").toInt();
    int completedPomos = query.value("completed_pomos").toInt();
    int totalDuration = query.value("total_duration").toInt();
    double avgPauses = query.value("avg_pauses").toDouble();
    double completionRate = totalPomos > 0 ? (double)completedPomos / totalPomos * 100 : 0;

    QSqlQuery statsQuery;
    statsQuery.prepare("INSERT INTO user_pomodoro_stats (account, date, total_pomos, total_focus_time, completion_rate, avg_pause_count) "
                       "VALUES (:account, :date, :total_pomos, :total_focus_time, :completion_rate, :avg_pause_count) "
                       "ON DUPLICATE KEY UPDATE "
                       "total_pomos = :total_pomos, "
                       "total_focus_time = :total_focus_time, "
                       "completion_rate = :completion_rate, "
                       "avg_pause_count = :avg_pause_count");

    statsQuery.bindValue(":account", userAccount);
    statsQuery.bindValue(":date", currentDate);
    statsQuery.bindValue(":total_pomos", totalPomos);
    statsQuery.bindValue(":total_focus_time", totalDuration / 60); // 转换为分钟
    statsQuery.bindValue(":completion_rate", completionRate);
    statsQuery.bindValue(":avg_pause_count", avgPauses);

    if (!statsQuery.exec()) {
        qDebug() << "Error inserting/updating statistics:" << statsQuery.lastError().text();
    }
}

void PomodoroWidget::showHistory()
{
    PomodoroHistoryWidget *historyWidget = new PomodoroHistoryWidget(userAccount);
    historyWidget->setAttribute(Qt::WA_DeleteOnClose);
    historyWidget->show();
}

void PomodoroWidget::deleteHistory()
{
    if (QMessageBox::question(this, "确认", "确定要删除所有历史记录吗？") != QMessageBox::Yes) {
        return;
    }

    QSqlQuery query;
    query.prepare("DELETE FROM pomodoro_sessions WHERE account = :account");
    query.bindValue(":account", userAccount);

    if (!query.exec()) {
        QMessageBox::warning(this, "错误", "删除历史记录失败！");
        return;
    }

    QMessageBox::information(this, "成功", "历史记录已删除！");
}
