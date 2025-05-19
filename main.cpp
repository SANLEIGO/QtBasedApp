#include "mainwindow.h"
#include "todolist.h"
#include <QApplication>
#include"login.h"

#include "main_window.h"
#include"myregister.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //主函数

 //   MainWindow w;
 //   w.show();

    main_window m;
    m.show();

//    login l;
//    l.show();

//    myregister m;
//    m.show();




    return a.exec();
}
