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

#include"taskinfo.h"
#include"globalValue.h"
#include"databasemanager.h"



namespace Ui {
class todoList;
}

class todoList : public QWidget
{
    Q_OBJECT

public:
    explicit todoList(QWidget *parent = nullptr);

    ~todoList();

    void to_load(int is_completed);

    void clearLayoutAll(QLayout* layout);

private slots:
    void on_pushButton_2_clicked();

     void on_tabWidget_tabBarClicked(int index);

    void on_search_not_clicked();

     void on_search_is_clicked();

    void on_pushButton_4_clicked();

     void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

     void on_pushButton_7_clicked();

 private:
    Ui::todoList *ui;

    int loaded[4];
};

#endif // TODOLIST_H
