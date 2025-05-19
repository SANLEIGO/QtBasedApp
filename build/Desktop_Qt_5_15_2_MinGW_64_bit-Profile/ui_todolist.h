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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_todoList
{
public:
    QPushButton *pushButton;
    QToolButton *toolButton;

    void setupUi(QWidget *todoList)
    {
        if (todoList->objectName().isEmpty())
            todoList->setObjectName(QString::fromUtf8("todoList"));
        todoList->resize(274, 180);
        pushButton = new QPushButton(todoList);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(110, 80, 56, 18));
        toolButton = new QToolButton(todoList);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(270, 130, 20, 18));

        retranslateUi(todoList);

        QMetaObject::connectSlotsByName(todoList);
    } // setupUi

    void retranslateUi(QWidget *todoList)
    {
        todoList->setWindowTitle(QCoreApplication::translate("todoList", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("todoList", "\347\255\211\347\255\211", nullptr));
        toolButton->setText(QCoreApplication::translate("todoList", "\344\277\204\344\271\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class todoList: public Ui_todoList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TODOLIST_H
