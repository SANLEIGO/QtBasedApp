QT       += core gui  sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    calendar.cpp \
    databasemanager.cpp \
    four.cpp \
    globalValue.cpp \
    list_frame.cpp \
    login.cpp \
    main.cpp \
    main_window.cpp \
    myregister.cpp \
    note.cpp \
    qselect.cpp \
    taskframe.cpp \
    todolist.cpp

HEADERS += \
    calendar.h \
    databasemanager.h \
    four.h \
    globalValue.h \
    list_frame.h \
    login.h \
    main_window.h \
    myregister.h \
    note.h \
    qselect.h \
    taskframe.h \
    todolist.h

FORMS += \
    calendar.ui \
    four.ui \
    login.ui \
    main_window.ui \
    myregister.ui \
    note.ui \
    taskframe.ui \
    todolist.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
