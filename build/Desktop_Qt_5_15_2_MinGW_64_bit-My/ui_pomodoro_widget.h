/********************************************************************************
** Form generated from reading UI file 'pomodoro_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POMODORO_WIDGET_H
#define UI_POMODORO_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PomodoroWidget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QListWidget *taskList;
    QVBoxLayout *verticalLayout_2;
    QLabel *timerLabel;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *startButton;
    QPushButton *pauseButton;
    QPushButton *stopButton;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *historyButton;
    QPushButton *deleteHistoryButton;

    void setupUi(QWidget *PomodoroWidget)
    {
        if (PomodoroWidget->objectName().isEmpty())
            PomodoroWidget->setObjectName(QString::fromUtf8("PomodoroWidget"));
        PomodoroWidget->resize(800, 600);
        verticalLayout = new QVBoxLayout(PomodoroWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        taskList = new QListWidget(PomodoroWidget);
        taskList->setObjectName(QString::fromUtf8("taskList"));
        taskList->setMinimumWidth(300);

        horizontalLayout->addWidget(taskList);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        timerLabel = new QLabel(PomodoroWidget);
        timerLabel->setObjectName(QString::fromUtf8("timerLabel"));
        QFont font;
        font.setPointSize(48);
        font.setBold(true);
        timerLabel->setFont(font);
        timerLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(timerLabel);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        startButton = new QPushButton(PomodoroWidget);
        startButton->setObjectName(QString::fromUtf8("startButton"));

        horizontalLayout_2->addWidget(startButton);

        pauseButton = new QPushButton(PomodoroWidget);
        pauseButton->setObjectName(QString::fromUtf8("pauseButton"));

        horizontalLayout_2->addWidget(pauseButton);

        stopButton = new QPushButton(PomodoroWidget);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));

        horizontalLayout_2->addWidget(stopButton);


        verticalLayout_2->addLayout(horizontalLayout_2);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        historyButton = new QPushButton(PomodoroWidget);
        historyButton->setObjectName(QString::fromUtf8("historyButton"));

        horizontalLayout_3->addWidget(historyButton);

        deleteHistoryButton = new QPushButton(PomodoroWidget);
        deleteHistoryButton->setObjectName(QString::fromUtf8("deleteHistoryButton"));

        horizontalLayout_3->addWidget(deleteHistoryButton);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(PomodoroWidget);

        QMetaObject::connectSlotsByName(PomodoroWidget);
    } // setupUi

    void retranslateUi(QWidget *PomodoroWidget)
    {
        PomodoroWidget->setWindowTitle(QCoreApplication::translate("PomodoroWidget", "\347\225\252\350\214\204\351\222\237", nullptr));
        timerLabel->setText(QCoreApplication::translate("PomodoroWidget", "25:00", nullptr));
        startButton->setText(QCoreApplication::translate("PomodoroWidget", "\345\274\200\345\247\213", nullptr));
        pauseButton->setText(QCoreApplication::translate("PomodoroWidget", "\346\232\202\345\201\234", nullptr));
        stopButton->setText(QCoreApplication::translate("PomodoroWidget", "\345\201\234\346\255\242", nullptr));
        historyButton->setText(QCoreApplication::translate("PomodoroWidget", "\346\237\245\347\234\213\345\216\206\345\217\262\350\256\260\345\275\225", nullptr));
        deleteHistoryButton->setText(QCoreApplication::translate("PomodoroWidget", "\345\210\240\351\231\244\345\216\206\345\217\262\350\256\260\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PomodoroWidget: public Ui_PomodoroWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POMODORO_WIDGET_H
