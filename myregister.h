#ifndef MYREGISTER_H
#define MYREGISTER_H

#include <QWidget>
#include <QString>
#include<QSqlDatabase>
#include<QMessageBox>
#include<QSqlQuery>



namespace Ui {
class myregister;
}

class myregister : public QWidget
{
    Q_OBJECT

public:
    explicit myregister(QWidget *parent = nullptr);
    ~myregister();

private slots:
    void on_register_button_clicked();

private:
    Ui::myregister *ui;
    QSqlDatabase db;
};

#endif // MYREGISTER_H
