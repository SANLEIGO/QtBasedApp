    #include "myregister.h"
    #include "ui_myregister.h"
    #include "databasemanager.h"
    #include<QDateTime>


    myregister::myregister(QWidget *parent)
        : QWidget(parent)
        , ui(new Ui::myregister)
    {
        ui->setupUi(this);
    }

    myregister::~myregister()
    {
        delete ui;
    }

    void myregister::on_register_button_clicked()
    {
        QString account = ui->register_account->text();
        QString password= ui->register_password->text();

        QSqlDatabase& db = databaseManager::getDataBase();

        if(db.isOpen()){


            //检查输入是否为空
            if(account=="" || password==""){
                QMessageBox::information(this,"注册提示","用户名或者密码为空");
                ui->register_account->setText("");
                ui->register_password->setText("");
                return;
            }


            //用户名的规范
            if(account.length()!=11){
                QMessageBox::information(this,"注册提示","用户名不合规范,请重新输入");
                ui->register_account->setText("");
                ui->register_password->setText("");
                return;
            }

            for(auto i: account){
                if(i<'0' || i>'9'){
                    QMessageBox::information(this,"注册提示","用户名不合规范,请重新输入");
                    ui->register_account->setText("");
                    ui->register_password->setText("");
                    return;
                }

            }


            //用户名重复
            QSqlQuery query1;
            QString sql = QString("select account from users");
            if(query1.exec(sql)){
                while(query1.next()){
                    if(query1.value(0).toString()==account){
                        QMessageBox::information(this,"注册提示","用户名重复,请重新输入");
                        ui->register_account->setText("");
                        ui->register_password->setText("");
                        return;
                    }
                }
            }
            else{
                qDebug()<<"wrong";
            }


            //插入,注册
            QSqlQuery query;
            query.prepare("insert into users (account, password, established_time) VALUES (:account, :password, :established_time)");
            //这里不使用Qstring的构造方法,而是通过query的绑定,可以防止sql注入

            QDateTime time = QDateTime::currentDateTime();
            QString formattedTime = time.toString("yyyy-MM-dd HH:mm:ss");

            query.bindValue(":account", account);
            query.bindValue(":password", password);
            query.bindValue(":established_time",formattedTime);

            qDebug()<<formattedTime;


            if(query.exec()){
                QMessageBox::information(this,"注册提示","注册成功,点击为您跳转登录");

            }
            else{
                QMessageBox::information(this,"注册提示","注册失败");
            }


        }
    }



