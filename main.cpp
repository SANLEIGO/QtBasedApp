
#include "todolist.h"
#include <QApplication>
#include"login.h"

#include "main_window.h"
#include"myregister.h"


#include"list_frame.h"

#include"taskframe.h"
#include"globalValue.h"


#include"taskinfo.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

 //   MainWindow w;
 //   w.show();

    login l;
    main_window m;
    l.show();
    QObject::connect(&l, &login::loginSuccess, &l, [&l, &m]() {

        l.close();
        m.show();
        m.get_page1()->to_load(0);

    });


    // taskInfo t;
    // t.show();


//    login l;
//    l.show();

//    myregister m;
//    m.show()

//    list_frame l;

 //   taskFrame t;
 //  t.show();


    return a.exec();
}
