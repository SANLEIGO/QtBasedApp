#include "main_window.h"
#include "ui_main_window.h"
#include "pomodoro_widget.h"
#include "globalValue.h"

main_window::main_window(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::main_window)
{
    ui->setupUi(this);
    page1 = new todoList(this);
    page2 = new calendar(this);
    page3 = new Note(this);
    page4 = new PomodoroWidget(staticVal::getAccount(), this);

    //设置四个分页面阿萨
    ui->stackedWidget->insertWidget(0, page1);
    ui->stackedWidget->insertWidget(1, page2);
    ui->stackedWidget->insertWidget(2, page3);
    ui->stackedWidget->insertWidget(3, page4);
    ui->stackedWidget->setCurrentIndex(0);

    connect(ui->pushButton, &QPushButton::clicked, this, [this]() { ui->stackedWidget->setCurrentIndex(0); });
    connect(ui->pushButton_2, &QPushButton::clicked, this, [this]() { ui->stackedWidget->setCurrentIndex(1); });
    connect(ui->pushButton_3, &QPushButton::clicked, this, [this]() { ui->stackedWidget->setCurrentIndex(2); });
    connect(ui->pomodoroButton, &QPushButton::clicked, this, [this]() { ui->stackedWidget->setCurrentIndex(3); });
}

main_window::~main_window()
{
    delete ui;
}

void main_window::on_pushButton_3_clicked()
{
    // 假设 pushButton_3 用于显示 page3
    // 方法一：通过索引设置当前页面
    // page3 是在索引 2 的位置插入的 (0-indexed)
    ui->stackedWidget->setCurrentIndex(2);

    // 方法二：通过页面指针设置当前页面 (更直观)
    // ui->stackedWidget->setCurrentWidget(page3);

    // 你可以根据 pushButton_3 的实际用途选择要显示的页面。
    // 例如，如果 pushButton_3 是为了显示 page1:
    // ui->stackedWidget->setCurrentIndex(0);
    // 或者
    // ui->stackedWidget->setCurrentWidget(page1);

    // 例如，如果 pushButton_3 是为了显示 page4:
    // ui->stackedWidget->setCurrentIndex(3);
    // 或者
    // ui->stackedWidget->setCurrentWidget(page4);
}



void main_window::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

