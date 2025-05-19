#include "taskframe.h"
#include "ui_taskframe.h"

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
