/********************************************************************************
** Form generated from reading UI file 'pomodoro_history_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POMODORO_HISTORY_WIDGET_H
#define UI_POMODORO_HISTORY_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PomodoroHistoryWidget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDateEdit *startDateEdit;
    QLabel *label_2;
    QDateEdit *endDateEdit;
    QPushButton *filterButton;
    QPushButton *refreshButton;
    QSpacerItem *horizontalSpacer;
    QTableView *historyTable;
    QHBoxLayout *horizontalLayout_2;
    QLabel *statsLabel;

    void setupUi(QWidget *PomodoroHistoryWidget)
    {
        if (PomodoroHistoryWidget->objectName().isEmpty())
            PomodoroHistoryWidget->setObjectName(QString::fromUtf8("PomodoroHistoryWidget"));
        PomodoroHistoryWidget->resize(800, 600);
        verticalLayout = new QVBoxLayout(PomodoroHistoryWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(PomodoroHistoryWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        startDateEdit = new QDateEdit(PomodoroHistoryWidget);
        startDateEdit->setObjectName(QString::fromUtf8("startDateEdit"));
        startDateEdit->setCalendarPopup(true);

        horizontalLayout->addWidget(startDateEdit);

        label_2 = new QLabel(PomodoroHistoryWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        endDateEdit = new QDateEdit(PomodoroHistoryWidget);
        endDateEdit->setObjectName(QString::fromUtf8("endDateEdit"));
        endDateEdit->setCalendarPopup(true);

        horizontalLayout->addWidget(endDateEdit);

        filterButton = new QPushButton(PomodoroHistoryWidget);
        filterButton->setObjectName(QString::fromUtf8("filterButton"));

        horizontalLayout->addWidget(filterButton);

        refreshButton = new QPushButton(PomodoroHistoryWidget);
        refreshButton->setObjectName(QString::fromUtf8("refreshButton"));

        horizontalLayout->addWidget(refreshButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        historyTable = new QTableView(PomodoroHistoryWidget);
        historyTable->setObjectName(QString::fromUtf8("historyTable"));

        verticalLayout->addWidget(historyTable);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        statsLabel = new QLabel(PomodoroHistoryWidget);
        statsLabel->setObjectName(QString::fromUtf8("statsLabel"));

        horizontalLayout_2->addWidget(statsLabel);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(PomodoroHistoryWidget);

        QMetaObject::connectSlotsByName(PomodoroHistoryWidget);
    } // setupUi

    void retranslateUi(QWidget *PomodoroHistoryWidget)
    {
        PomodoroHistoryWidget->setWindowTitle(QCoreApplication::translate("PomodoroHistoryWidget", "\347\225\252\350\214\204\351\222\237\345\216\206\345\217\262\350\256\260\345\275\225", nullptr));
        label->setText(QCoreApplication::translate("PomodoroHistoryWidget", "\346\227\245\346\234\237\350\214\203\345\233\264\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("PomodoroHistoryWidget", "\350\207\263", nullptr));
        filterButton->setText(QCoreApplication::translate("PomodoroHistoryWidget", "\347\255\233\351\200\211", nullptr));
        refreshButton->setText(QCoreApplication::translate("PomodoroHistoryWidget", "\345\210\267\346\226\260", nullptr));
        statsLabel->setText(QCoreApplication::translate("PomodoroHistoryWidget", "\347\273\237\350\256\241\344\277\241\346\201\257\357\274\232\346\200\273\347\225\252\350\214\204\346\225\260\357\274\2320 | \345\256\214\346\210\220\347\216\207\357\274\2320% | \346\200\273\344\270\223\346\263\250\346\227\266\351\225\277\357\274\2320\345\210\206\351\222\237 | \345\271\263\345\235\207\346\232\202\345\201\234\346\254\241\346\225\260\357\274\2320", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PomodoroHistoryWidget: public Ui_PomodoroHistoryWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POMODORO_HISTORY_WIDGET_H
