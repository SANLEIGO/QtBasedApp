#include "qsql.h"
#include"databasemanager.h"
#include"globalValue.h"

qsql::qsql() {}


void qsql::select_tasks(QVBoxLayout* layout, int completed, int time) {
    QSqlDatabase& db = databaseManager::getDataBase();
    QString _account = staticVal::getAccount();

    if (db.isOpen()) {
        qDebug() << _account;
        QSqlQuery query1;
        QString sql;

        // 获取当前日期
        QDate currentDate = QDate::currentDate();

        if (time == 999) {
            sql = QString("SELECT * FROM tasks WHERE account = '%1' and completed = %2 ORDER BY dead_time ").arg(_account).arg(completed);
        } else {

            // 计算截止日期

            QDate endDate = currentDate.addDays(time);
            QString startDateStr = currentDate.toString("yyyy-MM-dd");
            QString endDateStr = endDate.toString("yyyy-MM-dd");

            sql = QString("SELECT * FROM tasks WHERE account = '%1' and completed = %2 AND DATE(dead_time) BETWEEN '%3' AND '%4' ORDER BY dead_time     ")
                      .arg(_account)
                      .arg(completed)
                      .arg(startDateStr)
                      .arg(endDateStr);
        }

        if (query1.exec(sql)) {
            while (query1.next()) {
                QString taskName = query1.value("task_name").toString();
                QString deadTimeStr = query1.value("dead_time").toString();
                QString dateOnly = deadTimeStr.left(10); //截断10个字符
                int st = query1.value("completed").toInt();
                int id = query1.value("id").toInt();

                taskFrame* t = new taskFrame(taskName, dateOnly,id,st);
                layout->addWidget(t);
            }
        }
    } else {
        qDebug() << _account;
    }
}
