#include "todolist.h"
#include "ui_todolist.h"
#include"taskframe.h"
#include<QDateTime>
#include <QMessageBox>
#include"databasemanager.h"
#include"globalValue.h"
#include<QtDebug>


todoList::todoList(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::todoList)
{
    ui->setupUi(this);
    ui->add_to->setPlaceholderText("Add to '任务箱'");

    // 设置list_show的布局
    QVBoxLayout *listShowLayout = new QVBoxLayout(ui->list_show);
    listShowLayout->setAlignment(Qt::AlignTop);  // 添加顶部对齐
    listShowLayout->setSpacing(5);              // 设置任务项之间的间距
    listShowLayout->setContentsMargins(10, 10, 10, 10);  // 设置布局边距
    ui->list_show->setLayout(listShowLayout);
}

todoList::~todoList()
{
    delete ui;
}

void todoList::on_pushButton_2_clicked()
{

   //QMessageBox::information(this,"注册提示","注册成功,点击为您跳转登录");


    QVBoxLayout *listShowLayout = qobject_cast<QVBoxLayout*>(ui->list_show->layout());

    //查找该用户未完成的任务
   // QString _account = staticVal::getAccount();   //获取用户名
    QString _account = "1111111116";

    //已经登录
    if(_account!="null"){

        QSqlDatabase &db = databaseManager::getDataBase();


        if(db.isOpen()){

            QSqlQuery query1;
            QString sql = QString("SELECT * FROM tasks WHERE account = '%1' ;").arg(_account);


            if(query1.exec(sql)){


                while(query1.next()){

                    qDebug()<<query1.value("task_name").toString();
                    qDebug()<<query1.value("dead_time").toString();

                    taskFrame* t = new taskFrame(query1.value("task_name").toString(),query1.value("dead_time").toString());

                    listShowLayout->addWidget(t);

                }

            }
            else{
                qDebug() << "SQL Error:" << query1.lastError().text();
                qDebug() << "Failed SQL:" << sql;

            }

        }



    }






}
