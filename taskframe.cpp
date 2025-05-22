#include "taskframe.h"
#include "ui_taskframe.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QtDebug>
#include "taskInfo.h"
#include "databasemanager.h"
#include "globalValue.h"

taskFrame::taskFrame(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::taskFrame)
{
    ui->setupUi(this);
    menu = new QMenu(this);  // 初始化菜单
    // 添加菜单项
    menu->addAction("修改");
    menu->addAction("添加到番茄钟");
    menu->addAction("删除");
}

taskFrame::~taskFrame()
{
    delete ui;
}

taskFrame::taskFrame(QString _name, QString _time, int uid, bool selected) : QFrame(nullptr), ui(new Ui::taskFrame)
{
    ui->setupUi(this);
    ui->content->setText(_name);
    ui->time_show->setText(_time);
    id = uid;

    if (selected)
        ui->check_over->setCheckState(Qt::Checked);
    else
        ui->check_over->setCheckState(Qt::Unchecked);

    menu = new QMenu(this);

    QAction *action1 =menu->addAction("修改");
    QAction *action2 =menu->addAction("添加到番茄钟");
    QAction *action3 =menu->addAction("删除");

    connect(action1, &QAction::triggered, this, [this, action1]() { onMenuItemTriggered(action1); });
    connect(action2, &QAction::triggered, this, [this, action2]() { onMenuItemTriggered(action2); });
    connect(action3, &QAction::triggered, this, [this, action3]() { onMenuItemTriggered(action3); });
}

void taskFrame::on_check_over_stateChanged(int arg1)
{
    int st = 0;

    if (arg1 == Qt::Checked)
        st = 1;

    QString account = staticVal::getAccount();

    QSqlDatabase& db = databaseManager::getDataBase();

    if (db.isOpen()) {
        QSqlQuery query;
        qDebug() << id;
        QString sql = QString("UPDATE tasks SET completed = %1 WHERE account = '%2' AND id = %3")
                          .arg(st)
                          .arg(account)
                          .arg(id);

        query.exec(sql);
    }
    this->close();
}

void taskFrame::on_pushButton_clicked()
{
    // 在按钮下方显示菜单
    menu->exec(ui->pushButton->mapToGlobal(QPoint(0, ui->pushButton->height())));



}


void taskFrame::onMenuItemTriggered(QAction *action)
{
    if (action->text() == "修改") {

        taskInfo *t = new taskInfo;
        t->show();

        QObject::connect(t, &taskInfo::confirmSignal, this, [this](const QString& taskName, const QString& notes, const QString& deadTime, const QString& priority) {
            QString account = staticVal::getAccount();
            QSqlDatabase& db = databaseManager::getDataBase();
            if (db.isOpen()) {
                QSqlQuery query;
                QString sql = QString("UPDATE tasks SET task_name = '%1', dead_time = '%2', priority = '%3', notes = '%4' WHERE account = '%5' AND id = %6")
                                  .arg(taskName)
                                  .arg(deadTime)
                                  .arg(priority)
                                  .arg(notes)
                                  .arg(account)
                                  .arg(id);

                query.exec(sql) ;
                this->ui->content->setText(taskName);
                this->ui->time_show->setText(deadTime);
            }
        });


    } else if (action->text() == "添加到番茄钟") {



    } else if (action->text() == "删除") {

        QString account = staticVal::getAccount();
        QSqlDatabase& db = databaseManager::getDataBase();

        if(db.isOpen()){
            QSqlQuery query;
            QString sql =QString("delete from tasks where id =%1 ").arg(id);
            query.exec(sql);
            this->close();

        }

    }
}
