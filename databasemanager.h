#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include<QSqlDatabase>
#include<QDebug>

class databaseManager
{
public:

    static QSqlDatabase& getDataBase();  //引用的原因:加上下面禁止了复制和static,所以整个程序都是唯一实例

private:
    databaseManager() = delete;          // 禁用构造函数
    ~databaseManager() = delete;         // 禁用析构函数
    databaseManager(const databaseManager&) = delete;    //禁用复制
    databaseManager& operator=(const databaseManager&) = delete;  //禁用赋值
    static QSqlDatabase db;              // 静态数据库连接
    static bool init();                  // 初始化数据库（私有）

};

#endif // DATABASEMANAGER_H
