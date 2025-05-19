#include "login.h"
#include "ui_login.h"
#include "databasemanager.h"
#include"globalValue.h"

login::login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::login)
{
    Account = "null";
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_3_clicked()
{


    QString account = ui->login_account->text();
    QString password= ui->login_password->text();

    QSqlDatabase& db = databaseManager::getDataBase();

    if(db.open()){

        QSqlQuery query;

        QString sql = QString("select account,password from users");

        bool sign = 0;

        if(query.exec(sql)){
            while(query.next()){
                if(query.value(0).toString()==account && query.value(1).toString()==password){
                    sign = 1;
                    staticVal::setAccount(account);
                    QMessageBox::information(this,"登录提示","登录成功");
                }

            }
            if(!sign){
                QMessageBox::information(this,"登录提示", "账号或者密码错误");
            }

        }

        else{
             qDebug()<<"服务器忙,无法提供查询服务";
        }

    }
    else{
        QMessageBox::information(this,"登录提示","服务器忙");
    }

}

