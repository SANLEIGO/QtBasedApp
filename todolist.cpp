#include "todolist.h"
#include "ui_todolist.h"
#include<QDateTime>
#include <QMessageBox>
//#include"databasemanager.h"
//#include"globalValue.h"
#include<QtDebug>
#include"qsql.h"


todoList::todoList(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::todoList)
{
    loaded[0] = loaded[1] = loaded[2] = loaded[3] = 0;

    ui->setupUi(this);
    ui->add_to->setPlaceholderText("Add to '任务箱'");
    ui->add_to_2->setPlaceholderText("Add to '任务箱'");
    ui->add_to_3->setPlaceholderText("Add to '任务箱'");
    ui->add_to_4->setPlaceholderText("Add to '任务箱'");
    ui->add_to_5->setPlaceholderText("Add to '任务箱'");

    // 设置list_show的布局
    QVBoxLayout *listShowLayout1 = new QVBoxLayout(ui->list_show_1);
    listShowLayout1->setAlignment(Qt::AlignTop);  // 添加顶部对齐
    listShowLayout1->setSpacing(5);              // 设置任务项之间的间距
    listShowLayout1->setContentsMargins(10, 10, 10, 10);  // 设置布局边距
    ui->list_show_1->setLayout(listShowLayout1);

    QVBoxLayout *listShowLayout2 = new QVBoxLayout(ui->list_show_2);
    listShowLayout2->setAlignment(Qt::AlignTop);  // 添加顶部对齐
    listShowLayout2->setSpacing(5);              // 设置任务项之间的间距
    listShowLayout2->setContentsMargins(10, 10, 10, 10);  // 设置布局边距
    ui->list_show_2->setLayout(listShowLayout2);

    QVBoxLayout *listShowLayout3 = new QVBoxLayout(ui->list_show_3);
    listShowLayout3->setAlignment(Qt::AlignTop);  // 添加顶部对齐
    listShowLayout3->setSpacing(5);              // 设置任务项之间的间距
    listShowLayout3->setContentsMargins(10, 10, 10, 10);  // 设置布局边距
    ui->list_show_3->setLayout(listShowLayout3);

    QVBoxLayout *listShowLayout4 = new QVBoxLayout(ui->list_show_4);
    listShowLayout4->setAlignment(Qt::AlignTop);  // 添加顶部对齐
    listShowLayout4->setSpacing(5);              // 设置任务项之间的间距
    listShowLayout4->setContentsMargins(10, 10, 10, 10);  // 设置布局边距
    ui->list_show_4->setLayout(listShowLayout4);

    QVBoxLayout *listShowLayout5 = new QVBoxLayout(ui->list_show_5);
    listShowLayout5->setAlignment(Qt::AlignTop);  // 添加顶部对齐
    listShowLayout5->setSpacing(5);              // 设置任务项之间的间距
    listShowLayout5->setContentsMargins(10, 10, 10, 10);  // 设置布局边距
    ui->list_show_5->setLayout(listShowLayout5);



}

todoList::~todoList()
{
    delete ui;
}



void todoList::to_load(int index)
{

    QVBoxLayout *listShowLayout1 = qobject_cast<QVBoxLayout*>(ui->list_show_1->layout());
    QVBoxLayout *listShowLayout2 = qobject_cast<QVBoxLayout*>(ui->list_show_2->layout());
    QVBoxLayout *listShowLayout3 = qobject_cast<QVBoxLayout*>(ui->list_show_3->layout());
    QVBoxLayout *listShowLayout4 = qobject_cast<QVBoxLayout*>(ui->list_show_4->layout());
    QVBoxLayout *listShowLayout5 = qobject_cast<QVBoxLayout*>(ui->list_show_5->layout());
    //实现不重复挂载;实现完成与否分开挂载
    if(loaded[index] == 0){
        if(loaded[1-index]==1){
            //删除
            clearLayoutAll(listShowLayout1);
            clearLayoutAll(listShowLayout2);
            clearLayoutAll(listShowLayout3);
            clearLayoutAll(listShowLayout4);
            clearLayoutAll(listShowLayout5);

            loaded[1-index] = 0;
        }



        //查找该用户未完成的任务

        qsql::select_tasks(listShowLayout1,index);
        qsql::select_tasks(listShowLayout2,index,1);
        qsql::select_tasks(listShowLayout3,index,3);
        qsql::select_tasks(listShowLayout4,index,7);
        qsql::select_tasks(listShowLayout5,index,30);

        loaded[index] = 1;
    }



}



void todoList::on_pushButton_2_clicked()   // Add
{
    taskInfo *t = new taskInfo;
    t->show();

    QObject::connect(t, &taskInfo::confirmSignal, this, [this](const QString& taskName, const QString& notes, const QString& deadTime, const QString& priority) {

        QString account = staticVal::getAccount();

        // 插入新任务到数据库
        QSqlDatabase& db = databaseManager::getDataBase();
        QDateTime currentTime = QDateTime::currentDateTime();
        QString establishedTime = currentTime.toString("yyyy-MM-dd hh:mm:ss");
        if (db.isOpen()) {
            QSqlQuery query;
            QString sql = QString("INSERT INTO tasks (task_name, established_time, dead_time,completed,priority,notes,account) "
                                  "VALUES ('%1', '%2', '%3', 0, '%4', '%5', '%6')")
                              .arg(taskName)
                              .arg(establishedTime)
                              .arg(deadTime)
                              .arg(priority)
                              .arg(notes)
                              .arg(account);

            if (query.exec(sql)) {
                QMessageBox::information(this, "提示", "任务添加成功");
                // 重新加载任务列表
                loaded[0]= 0;
                loaded[1] = 1;
                to_load(0);
            } else {
                QMessageBox::information(this, "提示", "任务添加失败");
            }
        } else {
            QMessageBox::information(this, "提示", "数据库连接失败");
        }
    });
}


void todoList::clearLayoutAll(QLayout* layout){

    if (!layout) return;
    while (QLayoutItem* item = layout->takeAt(0)) {
        if (QWidget* widget = item->widget()) {
            delete widget;
        }
        delete item;
    }

}



void todoList::on_tabWidget_tabBarClicked(int index){}


void todoList::on_search_not_clicked()
{
    to_load(1);
}


void todoList::on_search_is_clicked()
{
    to_load(0);
}


void todoList::on_pushButton_4_clicked()
{
    on_pushButton_2_clicked();
}


void todoList::on_pushButton_6_clicked()
{
    on_pushButton_2_clicked();
}

void todoList::on_pushButton_7_clicked()
{
    on_pushButton_2_clicked();
}



void todoList::on_pushButton_5_clicked()
{
    on_pushButton_2_clicked();
}

