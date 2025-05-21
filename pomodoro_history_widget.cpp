#include "pomodoro_history_widget.h"
#include "ui_pomodoro_history_widget.h"
#include <QSqlError>
#include <QDebug>
#include <QDate>

PomodoroHistoryWidget::PomodoroHistoryWidget(const QString &account, QWidget *parent)
    : QWidget(parent), ui(new Ui::PomodoroHistoryWidget), userAccount(account)
{
    ui->setupUi(this);

    // 设置日期范围
    QDate currentDate = QDate::currentDate();
    ui->startDateEdit->setDate(currentDate.addDays(-30));
    ui->endDateEdit->setDate(currentDate);

    setupModel();
    setupConnections();
    refreshHistory();
}

PomodoroHistoryWidget::~PomodoroHistoryWidget()
{
    delete ui;
}

void PomodoroHistoryWidget::setupModel()
{
    model = new QSqlTableModel(this);
    model->setTable("pomodoro_sessions");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    // 设置表头
    model->setHeaderData(0, Qt::Horizontal, "ID");
    model->setHeaderData(1, Qt::Horizontal, "任务ID");
    model->setHeaderData(2, Qt::Horizontal, "账号");
    model->setHeaderData(3, Qt::Horizontal, "开始时间");
    model->setHeaderData(4, Qt::Horizontal, "结束时间");
    model->setHeaderData(5, Qt::Horizontal, "持续时间(秒)");
    model->setHeaderData(6, Qt::Horizontal, "是否完成");
    model->setHeaderData(7, Qt::Horizontal, "暂停次数");
    model->setHeaderData(8, Qt::Horizontal, "备注");

    ui->historyTable->setModel(model);
    ui->historyTable->setColumnHidden(1, true); // 隐藏任务ID列
    ui->historyTable->setColumnHidden(2, true); // 隐藏账号列
}

void PomodoroHistoryWidget::setupConnections()
{
    connect(ui->filterButton, &QPushButton::clicked, this, &PomodoroHistoryWidget::filterHistory);
    connect(ui->refreshButton, &QPushButton::clicked, this, &PomodoroHistoryWidget::refreshHistory);
}

void PomodoroHistoryWidget::refreshHistory()
{
    QString filter = QString("account = '%1'").arg(userAccount);
    model->setFilter(filter);
    model->select();

    // 更新统计信息
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) as total_pomos, "
                  "SUM(CASE WHEN is_completed = 1 THEN 1 ELSE 0 END) as completed_pomos, "
                  "SUM(duration) as total_duration, "
                  "AVG(pause_count) as avg_pauses "
                  "FROM pomodoro_sessions "
                  "WHERE account = :account");

    query.bindValue(":account", userAccount);

    if (query.exec() && query.next()) {
        int totalPomos = query.value("total_pomos").toInt();
        int completedPomos = query.value("completed_pomos").toInt();
        int totalDuration = query.value("total_duration").toInt();
        double avgPauses = query.value("avg_pauses").toDouble();
        double completionRate = totalPomos > 0 ? (double)completedPomos / totalPomos * 100 : 0;

        ui->statsLabel->setText(QString("统计信息：总番茄数：%1 | 完成率：%2% | 总专注时长：%3分钟 | 平均暂停次数：%4")
                                    .arg(totalPomos)
                                    .arg(QString::number(completionRate, 'f', 1))
                                    .arg(totalDuration / 60)
                                    .arg(QString::number(avgPauses, 'f', 1)));
    }
}

void PomodoroHistoryWidget::filterHistory()
{
    QDate startDate = ui->startDateEdit->date();
    QDate endDate = ui->endDateEdit->date();

    QString filter = QString("account = '%1' AND DATE(start_time) BETWEEN '%2' AND '%3'")
                         .arg(userAccount)
                         .arg(startDate.toString(Qt::ISODate))
                         .arg(endDate.toString(Qt::ISODate));

    model->setFilter(filter);
    model->select();

    // 更新统计信息
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) as total_pomos, "
                  "SUM(CASE WHEN is_completed = 1 THEN 1 ELSE 0 END) as completed_pomos, "
                  "SUM(duration) as total_duration, "
                  "AVG(pause_count) as avg_pauses "
                  "FROM pomodoro_sessions "
                  "WHERE account = :account "
                  "AND DATE(start_time) BETWEEN :start_date AND :end_date");

    query.bindValue(":account", userAccount);
    query.bindValue(":start_date", startDate);
    query.bindValue(":end_date", endDate);

    if (query.exec() && query.next()) {
        int totalPomos = query.value("total_pomos").toInt();
        int completedPomos = query.value("completed_pomos").toInt();
        int totalDuration = query.value("total_duration").toInt();
        double avgPauses = query.value("avg_pauses").toDouble();
        double completionRate = totalPomos > 0 ? (double)completedPomos / totalPomos * 100 : 0;

        ui->statsLabel->setText(QString("统计信息：总番茄数：%1 | 完成率：%2% | 总专注时长：%3分钟 | 平均暂停次数：%4")
                                    .arg(totalPomos)
                                    .arg(QString::number(completionRate, 'f', 1))
                                    .arg(totalDuration / 60)
                                    .arg(QString::number(avgPauses, 'f', 1)));
    }
}
