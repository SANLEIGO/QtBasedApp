/********************************************************************************
** Form generated from reading UI file 'todolist.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TODOLIST_H
#define UI_TODOLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_todoList
{
public:
    QHBoxLayout *horizontalLayout_2;
    QFrame *frame_2;
    QGridLayout *gridLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_3;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer_4;
    QFrame *line;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_3;
    QSpacerItem *verticalSpacer_2;
    QTabWidget *tabWidget;
    QWidget *ALL;
    QVBoxLayout *verticalLayout_3;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout;
    QLineEdit *add_to;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_2;
    QWidget *list_show;
    QWidget *tab_3;
    QWidget *tab_4;
    QWidget *tab_5;
    QWidget *dsad;

    void setupUi(QWidget *todoList)
    {
        if (todoList->objectName().isEmpty())
            todoList->setObjectName(QString::fromUtf8("todoList"));
        todoList->resize(682, 432);
        horizontalLayout_2 = new QHBoxLayout(todoList);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        frame_2 = new QFrame(todoList);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        frame = new QFrame(frame_2);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_3 = new QSpacerItem(20, 84, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        verticalSpacer_4 = new QSpacerItem(20, 36, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        line = new QFrame(frame);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        verticalSpacer = new QSpacerItem(20, 35, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pushButton_3 = new QPushButton(frame);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);

        verticalSpacer_2 = new QSpacerItem(20, 84, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        gridLayout->addWidget(frame, 0, 0, 1, 1);

        tabWidget = new QTabWidget(frame_2);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        ALL = new QWidget();
        ALL->setObjectName(QString::fromUtf8("ALL"));
        verticalLayout_3 = new QVBoxLayout(ALL);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        scrollArea = new QScrollArea(ALL);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 562, 368));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        frame_3 = new QFrame(scrollAreaWidgetContents);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setMinimumSize(QSize(0, 100));
        frame_3->setMaximumSize(QSize(16777215, 100));
        frame_3->setStyleSheet(QString::fromUtf8("background-color: rgb(246, 246, 246);\n"
"border: 1px solid #E0E0E0;\n"
"    border - radius: 80px;\n"
"    padding: 5px;\n"
"    color: #333;\n"
"    selection - color: white;\n"
"    selection - background - color: #007ACC;\n"
""));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame_3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        add_to = new QLineEdit(frame_3);
        add_to->setObjectName(QString::fromUtf8("add_to"));
        add_to->setMinimumSize(QSize(40, 20));

        horizontalLayout->addWidget(add_to);

        horizontalSpacer = new QSpacerItem(211, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_2 = new QPushButton(frame_3);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        horizontalLayout->setStretch(0, 3);
        horizontalLayout->setStretch(1, 7);
        horizontalLayout->setStretch(2, 1);
        horizontalLayout->setStretch(3, 1);

        verticalLayout_2->addWidget(frame_3);

        list_show = new QWidget(scrollAreaWidgetContents);
        list_show->setObjectName(QString::fromUtf8("list_show"));

        verticalLayout_2->addWidget(list_show);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_3->addWidget(scrollArea);

        tabWidget->addTab(ALL, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        tabWidget->addTab(tab_5, QString());
        dsad = new QWidget();
        dsad->setObjectName(QString::fromUtf8("dsad"));
        tabWidget->addTab(dsad, QString());

        gridLayout->addWidget(tabWidget, 0, 1, 1, 1);


        horizontalLayout_2->addWidget(frame_2);


        retranslateUi(todoList);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(todoList);
    } // setupUi

    void retranslateUi(QWidget *todoList)
    {
        todoList->setWindowTitle(QCoreApplication::translate("todoList", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("todoList", "Smart List", nullptr));
        pushButton_3->setText(QCoreApplication::translate("todoList", "Add List", nullptr));
        add_to->setText(QString());
        pushButton_2->setText(QCoreApplication::translate("todoList", "Add", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(ALL), QCoreApplication::translate("todoList", "All", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("todoList", "Day", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("todoList", "3 days", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("todoList", "Week", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(dsad), QCoreApplication::translate("todoList", "Month", nullptr));
    } // retranslateUi

};

namespace Ui {
    class todoList: public Ui_todoList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TODOLIST_H
