#include "databasemanager.h"

#include <QSqlDatabase>
#include <QString>
#include <QDebug> // 用于输出调试信息
#include <QSqlError>

QSqlDatabase databaseManager::db;  // 静态成员变量定义


// bool databaseManager::init() {
//     db = QSqlDatabase::addDatabase("QODBC");
//     db.setDatabaseName("dolist");
//     db.setHostName("192.168.193.125");
//     db.setPort(4406);
//     db.setUserName("root");
//     db.setPassword("Rinatech0800%");
//     return db.open();
// } 劫匪测试

bool databaseManager::init() {
    // 移除可能存在的旧连接（如果这是重新初始化）
    // 如果你的 db 对象是每次调用 init 时新创建的，则不需要这一步。
    // 但如果 db 是一个持久的成员变量，并且可能被多次调用 init，则需要确保旧连接被正确处理。
    // 创建并配置数据库连接
    db = QSqlDatabase::addDatabase("QODBC"); // 指定连接名称

    // 配置ODBC连接参数
    QString connectString =
        "DRIVER={MySQL ODBC 8.0 Unicode Driver};"  // 驱动名称（需与实际安装的驱动名称一致）
        "SERVER=100.80.134.24;"      // 服务器地址
        "PORT=4406;"            // 端口
        "DATABASE=dolist;"      // 数据库名
        "USER=root;"           // 用户名
        "PASSWORD=Rinatech0800%;";// 密码
    db.setDatabaseName(connectString);


    if (db.open()) {
        qDebug() << "数据库连接成功 (ODBC 连接方式)!";
        return true;
    }else {
        QSqlError error = db.lastError();
        qDebug() << "数据库连接失败:";
        //qDebug() << "错误类型:" << errorTypeToString(error.type());
        qDebug() << "错误代码:" << error.nativeErrorCode();
        qDebug() << "错误描述:" << error.text();
        qDebug() << "可能的原因:";

        // 常见错误的中文解释
        if (error.text().contains("driver not loaded")) {
            qDebug() << "  - 未找到ODBC驱动，请检查:";
            qDebug() << "    1. 是否安装了MySQL ODBC驱动";
            qDebug() << "    2. 驱动名称是否正确（当前使用:" << connectString.section('=', 1, 1).section('}', 0, 0) << ")";
        } else if (error.text().contains("Unknown MySQL server host")) {
            qDebug() << "  - 无法连接到MySQL服务器，请检查:";
            qDebug() << "    1. MySQL服务是否正在运行";
            qDebug() << "    2. 服务器地址和端口是否正确";
        } else if (error.text().contains("Access denied")) {
            qDebug() << "  - 访问被拒绝，请检查用户名和密码是否正确";
        }

        return false;
    }

}




QSqlDatabase& databaseManager::getDataBase() {
    static bool initialized = init();  // 首次调用时初始化
    if (!initialized) {
        qDebug()<<"cuowu";
    }
    return db;
}
