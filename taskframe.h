#ifndef TASKFRAME_H
#define TASKFRAME_H

#include <QFrame>

namespace Ui {
class taskFrame;
}

class taskFrame : public QFrame
{
    Q_OBJECT

public:
    explicit taskFrame(QWidget *parent = nullptr);
    ~taskFrame();

private:
    Ui::taskFrame *ui;
};

#endif // TASKFRAME_H
