
#include "todolist.h"
#include <QApplication>
#include"login.h"

#include "main_window.h"
#include"myregister.h"


#include"list_frame.h"

#include"taskframe.h"
#include"globalValue.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //主函数

 //   MainWindow w;
 //   w.show();

    // login l;
    // main_window m;
    // m.show();
    // l.show();
    // QObject::connect(&l, &login::loginSuccess, &l, [&l, &m]() {
    //     l.close();
    //     m.show();
    // });


        login loginDialog;
        main_window w;

        QObject::connect(&loginDialog, &login::loginSuccess, [&]() {
            loginDialog.close();
            w.show();
        });

        loginDialog.show();



//    login l;
//    l.show();

    // myregister m;
    // m.show();

//    list_frame l;

 //   taskFrame t;
 //  t.show();


    return a.exec();
}
