#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QWidget>


#include "four.h"
#include "calendar.h"
#include "note.h"
#include "todolist.h"
#include"pomodoro_widget.h"


namespace Ui {
class main_window;
}

class main_window : public QWidget
{
    Q_OBJECT

public:
    explicit main_window(QWidget *parent = nullptr);
    ~main_window();
    todoList* get_page1();

private:
    Ui::main_window *ui;
    todoList* page1;
    calendar* page2;
    PomodoroWidget*   page3;
    Note*   page4;

};

#endif // MAIN_WINDOW_H
