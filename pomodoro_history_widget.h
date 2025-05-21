#ifndef POMODORO_HISTORY_WIDGET_H
#define POMODORO_HISTORY_WIDGET_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>

namespace Ui {
class PomodoroHistoryWidget;
}

class PomodoroHistoryWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PomodoroHistoryWidget(const QString &account, QWidget *parent = nullptr);
    ~PomodoroHistoryWidget();

private slots:
    void refreshHistory();
    void filterHistory();

private:
    Ui::PomodoroHistoryWidget *ui;
    QString userAccount;
    QSqlTableModel *model;

    void setupModel();
    void setupConnections();
};

#endif // POMODORO_HISTORY_WIDGET_H
