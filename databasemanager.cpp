#include "databasemanager.h"


QSqlDatabase databaseManager::db;  // 静态成员变量定义


bool databaseManager::init() {
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName("dolist");
    db.setHostName("localhost");
    db.setUserName("qt_user");
    db.setPassword("123456");
    return db.open();
}

QSqlDatabase& databaseManager::getDataBase() {
    static bool initialized = init();  // 首次调用时初始化
    if (!initialized) {
        qDebug()<<"cuowu";
    }
    return db;
}
