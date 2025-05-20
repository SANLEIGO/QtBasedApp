#include "taskframe.h"
#include "ui_taskframe.h"
#include<QtDebug>

taskFrame::taskFrame(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::taskFrame)
{
    ui->setupUi(this);
}

taskFrame::~taskFrame()
{
    delete ui;
}


taskFrame::taskFrame(QString _name, QString _time) : QFrame(nullptr), ui(new Ui::taskFrame)
{

        ui->setupUi(this);
        ui->content->setText(_name);
        ui->time_show->setText(_time);


}
