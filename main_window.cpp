#include "main_window.h"
#include "ui_main_window.h"



main_window::main_window(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::main_window)
{
    ui->setupUi(this);
    page1 = new todoList(this);
    page2 = new calendar(this);
    page3 = new PomodoroWidget(staticVal::getAccount(),this);
    page4 = new Note(this);


    //设置四个分页面
    ui->stackedWidget->insertWidget(0,page1);
    ui->stackedWidget->insertWidget(1,page2);
    ui->stackedWidget->insertWidget(2,page3);
    ui->stackedWidget->insertWidget(3,page4);
    ui->stackedWidget->setCurrentIndex(0);

}

main_window::~main_window()
{
    delete ui;
}

todoList* main_window::get_page1()
{
    return page1;
}
