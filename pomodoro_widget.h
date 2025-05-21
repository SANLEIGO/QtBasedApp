#ifndef POMODORO_WIDGET_H
#define POMODORO_WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QDateTime>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QListWidget>

namespace Ui {
class PomodoroWidget;
}

class PomodoroWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PomodoroWidget(const QString &account, QWidget *parent = nullptr);
    ~PomodoroWidget();

private slots:
    void updateTimer();
    void startPomodoro();
    void pausePomodoro();
    void stopPomodoro();
    void showHistory();
    void deleteHistory();
    void loadTasks();
    void updateTaskList();

private:
    Ui::PomodoroWidget *ui;
    QTimer *timer;
    QString userAccount;
    int remainingTime;
    int pauseCount;
    bool isPaused;
    int currentTaskId;
    QDateTime startTime;

    void saveSession(bool completed);
    void updateStatistics();
    void setupConnections();
};

#endif // POMODORO_WIDGET_H
