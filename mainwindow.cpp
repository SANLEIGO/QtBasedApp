#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qDebug() << "Before adding TodoList:";
    qDebug() << "StackedWidget count:" << ui->stackedWidget->count();

    page1 = new todoList(this);
    ui->stackedWidget->insertWidget(0,page1);
    ui->stackedWidget->setCurrentIndex(0);     //设置默认显示





}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(page1);
}

