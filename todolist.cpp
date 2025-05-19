#include "todolist.h"
#include "ui_todolist.h"

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
    QFrame *frame = new QFrame(this);
    frame->setFrameShadow(QFrame::Sunken);

    // 创建水平布局
    QHBoxLayout *layout = new QHBoxLayout(frame);
    layout->setSpacing(10);  // 设置控件间距为10像素

    // 创建复选框
    QCheckBox *checkBox = new QCheckBox(frame);
    layout->addWidget(checkBox);

    // 创建文本标签
    QLabel *label = new QLabel("头歌 数据库 在线考试", frame);
    layout->addWidget(label);

    // 创建加号按钮
    QPushButton *addButton = new QPushButton("+", frame);
    layout->addWidget(addButton);

    // 获取list_show的布局并添加新frame
    QVBoxLayout *listShowLayout = qobject_cast<QVBoxLayout*>(ui->list_show->layout());
    if (listShowLayout) {
        listShowLayout->addWidget(frame);

        // 添加分隔线（可选）
        QFrame *separator = new QFrame(this);
        separator->setFrameShape(QFrame::HLine);
        separator->setFrameShadow(QFrame::Sunken);
        separator->setStyleSheet("color: #eee;");
        listShowLayout->addWidget(separator);
    }
}
