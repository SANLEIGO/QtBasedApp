#include "list_frame.h"

list_frame::list_frame() {
    QFrame *frame = new QFrame;
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

    //分割线
    QFrame *separator = new QFrame();
    separator->setFrameShape(QFrame::HLine);
    separator->setFrameShadow(QFrame::Sunken);
    separator->setStyleSheet("color: #eee;");


    QVBoxLayout * vlayout = new QVBoxLayout(frame);
    vlayout->addLayout(layout);
    vlayout->addWidget(separator);


}
