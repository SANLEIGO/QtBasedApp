#include "taskinfo.h"
#include "ui_taskinfo.h"

taskInfo::taskInfo(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::taskInfo)
{
    ui->setupUi(this);
}

taskInfo::~taskInfo()
{
    delete ui;
}



void taskInfo::on_pushButton_clicked()  //确认任务表单
{
    QString taskName = ui->lineEdit->text();
    QString notes = ui->lineEdit_2->text();
    QString deadTime = ui->dateTimeEdit->text();
    QString priority = ui->comboBox_2->currentText();

    if (!taskName.isEmpty() && !deadTime.isEmpty()) {
        emit confirmSignal(taskName, notes,deadTime,priority);
        this->close();
    }
}


void taskInfo::on_pushButton_2_clicked()
{
    emit CancelSignal();
    this->close();
}

