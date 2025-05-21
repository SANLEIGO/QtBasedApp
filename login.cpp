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
    QString password = ui->login_password->text();
    QSqlDatabase& db = databaseManager::getDataBase();
    if (db.open()) {
        QSqlQuery query;
        // 先查找用户是否存在
        query.prepare("SELECT password FROM users WHERE account = :account");
        query.bindValue(":account", account);
        if (query.exec() && query.next()) {
            // 用户存在，校验密码
            QString dbPassword = query.value(0).toString();
            if (dbPassword == password) {
                staticVal::setAccount(account);
                QMessageBox::information(this, "登录提示", "登录成功");
                emit loginSuccess();
            } else {
                QMessageBox::information(this, "登录提示", "账号或者密码错误");
            }
        } else {
            // 用户不存在，自动注册
            QSqlQuery regQuery;
            regQuery.prepare("INSERT INTO users (account, password, established_time) VALUES (:account, :password, :established_time)");
            regQuery.bindValue(":account", account);
            regQuery.bindValue(":password", password);
            regQuery.bindValue(":established_time", QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"));
            if (regQuery.exec()) {
                staticVal::setAccount(account);
                QMessageBox::information(this, "注册提示", "用户未注册，已自动为您注册并登录！");
                emit loginSuccess();
            } else {
                QMessageBox::information(this, "注册提示", "注册失败，请重试");
            }
        }
    } else {
        QMessageBox::information(this, "登录提示", "服务器忙");
    }
}

