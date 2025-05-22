#ifndef TASKFRAME_H
#define TASKFRAME_H

#include <QFrame>
#include <QDateTime>
#include <QMenu>  // 新增头文件

namespace Ui {
class taskFrame;
}

class taskFrame : public QFrame
{
    Q_OBJECT

public:
    explicit taskFrame(QWidget *parent = nullptr);
    taskFrame(QString name, QString time, int id,bool selected = false);
    ~taskFrame();

private slots:
    void on_check_over_stateChanged(int arg1);
    void on_pushButton_clicked();
    void onMenuItemTriggered(QAction *action);

private:
    Ui::taskFrame *ui;
    int id;
    QMenu *menu;
};

#endif // TASKFRAME_H
