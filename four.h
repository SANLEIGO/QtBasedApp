#ifndef FOUR_H
#define FOUR_H

#include <QWidget>

namespace Ui {
class four;
}

class four : public QWidget
{
    Q_OBJECT
//dishengge commit
public:
    explicit four(QWidget *parent = nullptr);
    ~four();

private:
    Ui::four *ui;
};

#endif // FOUR_H
