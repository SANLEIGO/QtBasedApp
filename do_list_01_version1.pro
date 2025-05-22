QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# 设置应用程序名称
TARGET = do_list_01_version1
TEMPLATE = app

# 设置应用程序图标（如果有的话）
# RC_ICONS = app.ico

# 源文件
SOURCES += \
    main.cpp \
    main_window.cpp \
    note.cpp \
    todolist.cpp \
    taskframe.cpp \
    taskinfo.cpp \
    pomodoro_widget.cpp \
    pomodoro_history_widget.cpp \
    qsql.cpp

# 头文件
HEADERS += \
    main_window.h \
    note.h \
    todolist.h \
    taskframe.h \
    taskinfo.h \
    pomodoro_widget.h \
    pomodoro_history_widget.h \
    qsql.h

# UI文件
FORMS += \
    main_window.ui \
    note.ui \
    todolist.ui \
    taskframe.ui \
    taskinfo.ui \
    pomodoro_widget.ui \
    pomodoro_history_widget.ui

# 默认规则
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# 添加数据库文件
RESOURCES += \
    database.sql 