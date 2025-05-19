#include "todolist.h"
#include "ui_todolist.h"
#include"taskframe.h"

todoList::todoList(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::todoList)
{
    ui->setupUi(this);
    ui->add_to->setPlaceholderText("Add to '任务箱'");

    // 设置list_show的布局
    QVBoxLayout *listShowLayout = new QVBoxLayout(ui->list_show);
    listShowLayout->setAlignment(Qt::AlignTop);  // 添加顶部对齐
    listShowLayout->setSpacing(10);              // 设置任务项之间的间距
    listShowLayout->setContentsMargins(10, 10, 10, 10);  // 设置布局边距
    ui->list_show->setLayout(listShowLayout);
}

todoList::~todoList()
{
    delete ui;
}

void todoList::on_pushButton_2_clicked()
{

    taskFrame* t = new taskFrame();

    //查找该用户未完成的任务
    QString account = staticVal::getAccount();   //获取用户名



    QVBoxLayout *listShowLayout = qobject_cast<QVBoxLayout*>(ui->list_show->layout());
    listShowLayout->addWidget(t);



}
