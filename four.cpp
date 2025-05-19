#include "four.h"
#include "ui_four.h"

four::four(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::four)
{
    ui->setupUi(this);
}

four::~four()
{
    delete ui;
}
