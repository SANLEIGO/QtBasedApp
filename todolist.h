#ifndef TODOLIST_H
#define TODOLIST_H

#include <QWidget>
#include<QFrame>
#include<QHBoxLayout>
#include<QCheckBox>
#include<QLine>
#include<QLabel>
#include<QSqlDatabase>
#include<QSqlQuery>
#include <QSqlError>



namespace Ui {
class todoList;
}

class todoList : public QWidget
{
    Q_OBJECT

public:
    explicit todoList(QWidget *parent = nullptr);

    ~todoList();

private slots:
    void on_pushButton_2_clicked();

private:
Ui::todoList *ui;

};

#endif // TODOLIST_H
