#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QWidget>


#include "four.h"
#include "calendar.h"
#include "note.h"
#include "todolist.h"
#include "pomodoro_widget.h"


namespace Ui {
class main_window;
}

class main_window : public QWidget
{
    Q_OBJECT

public:
    explicit main_window(QWidget *parent = nullptr);
    ~main_window();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void showPomodoroWidget();

private:
    Ui::main_window *ui;
    todoList* page1;
    calendar* page2;
    Note*   page3;
    PomodoroWidget* page4;
    PomodoroWidget *pomodoroWidget;

};

#endif // MAIN_WINDOW_H
