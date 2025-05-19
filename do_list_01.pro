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
    list_frame.cpp \
    login.cpp \
    main.cpp \
    main_window.cpp \
    mainwindow.cpp \
    myregister.cpp \
    note.cpp \
    todolist.cpp

HEADERS += \
    calendar.h \
    databasemanager.h \
    four.h \
    list_frame.h \
    login.h \
    main_window.h \
    mainwindow.h \
    myregister.h \
    note.h \
    todolist.h

FORMS += \
    calendar.ui \
    four.ui \
    login.ui \
    main_window.ui \
    mainwindow.ui \
    myregister.ui \
    note.ui \
    todolist.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
