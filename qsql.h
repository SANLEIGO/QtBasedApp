#ifndef QSQL_H
#define QSQL_H


#include<QSqlDatabase>
#include<QSqlQuery>
#include<QVBoxLayout>

#include"taskframe.h"



class qsql
{
public:
    qsql();
    static void select_tasks(QVBoxLayout*layout,int completed = 0,int time = 999);
    void selectByTime();
    //void selectComp
};

#endif // QSQL_H
