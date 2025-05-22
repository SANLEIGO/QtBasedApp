#ifndef TASKINFO_H
#define TASKINFO_H

#include <QWidget>

namespace Ui {
class taskInfo;
}

class taskInfo : public QWidget
{
    Q_OBJECT

public:
    explicit taskInfo(QWidget *parent = nullptr);
    ~taskInfo();

signals:
    void confirmSignal(const QString& taskName, const QString& notes,const QString& deadTime,const QString& priority);
    void  CancelSignal();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::taskInfo *ui;
};

#endif // TASKINFO_H
