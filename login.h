#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QString>
#include<QSqlDatabase>
#include<QMessageBox>
#include<QSqlQuery>
#include<QDebug>
#include<QDateTime>




namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

signals:
    void loginSuccess();
    void registerSuccess();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::login *ui;
    QString Account;
};

#endif // LOGIN_H
