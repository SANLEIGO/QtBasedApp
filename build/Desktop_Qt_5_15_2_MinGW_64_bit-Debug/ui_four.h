/********************************************************************************
** Form generated from reading UI file 'four.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FOUR_H
#define UI_FOUR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_four
{
public:
    QFrame *frame_4;
    QGridLayout *gridLayout_5;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_13;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_7;
    QSpacerItem *horizontalSpacer_9;
    QFrame *frame_5;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_41;
    QLabel *label_14;
    QLineEdit *lineEdit_9;
    QSpacerItem *verticalSpacer_13;
    QHBoxLayout *horizontalLayout_42;
    QLabel *label_15;
    QLineEdit *lineEdit_10;
    QSpacerItem *horizontalSpacer_16;
    QSpacerItem *verticalSpacer_14;
    QSpacerItem *horizontalSpacer_31;
    QPushButton *pushButton_13;
    QSpacerItem *horizontalSpacer_45;
    QSpacerItem *verticalSpacer_20;

    void setupUi(QWidget *four)
    {
        if (four->objectName().isEmpty())
            four->setObjectName(QString::fromUtf8("four"));
        four->resize(693, 382);
        frame_4 = new QFrame(four);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setGeometry(QRect(470, 244, 282, 249));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        gridLayout_5 = new QGridLayout(frame_4);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        verticalSpacer_6 = new QSpacerItem(20, 12, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_6, 0, 2, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(59, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_5, 1, 1, 2, 1);

        label_13 = new QLabel(frame_4);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_5->addWidget(label_13, 1, 2, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(59, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_6, 1, 3, 2, 1);

        verticalSpacer_7 = new QSpacerItem(20, 17, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_7, 2, 2, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_9, 3, 0, 1, 1);

        frame_5 = new QFrame(frame_4);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame_5);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_41 = new QHBoxLayout();
        horizontalLayout_41->setObjectName(QString::fromUtf8("horizontalLayout_41"));
        label_14 = new QLabel(frame_5);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_41->addWidget(label_14);

        lineEdit_9 = new QLineEdit(frame_5);
        lineEdit_9->setObjectName(QString::fromUtf8("lineEdit_9"));

        horizontalLayout_41->addWidget(lineEdit_9);


        verticalLayout->addLayout(horizontalLayout_41);

        verticalSpacer_13 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_13);

        horizontalLayout_42 = new QHBoxLayout();
        horizontalLayout_42->setObjectName(QString::fromUtf8("horizontalLayout_42"));
        label_15 = new QLabel(frame_5);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout_42->addWidget(label_15);

        lineEdit_10 = new QLineEdit(frame_5);
        lineEdit_10->setObjectName(QString::fromUtf8("lineEdit_10"));

        horizontalLayout_42->addWidget(lineEdit_10);


        verticalLayout->addLayout(horizontalLayout_42);


        gridLayout_5->addWidget(frame_5, 3, 1, 1, 3);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_16, 3, 4, 1, 1);

        verticalSpacer_14 = new QSpacerItem(13, 16, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_14, 4, 2, 1, 1);

        horizontalSpacer_31 = new QSpacerItem(106, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_31, 5, 0, 1, 2);

        pushButton_13 = new QPushButton(frame_4);
        pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));

        gridLayout_5->addWidget(pushButton_13, 5, 2, 1, 2);

        horizontalSpacer_45 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_45, 5, 4, 1, 1);

        verticalSpacer_20 = new QSpacerItem(20, 39, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_20, 6, 2, 1, 1);


        retranslateUi(four);

        QMetaObject::connectSlotsByName(four);
    } // setupUi

    void retranslateUi(QWidget *four)
    {
        four->setWindowTitle(QCoreApplication::translate("four", "Form", nullptr));
        label_13->setText(QCoreApplication::translate("four", "REGISTER", nullptr));
        label_14->setText(QCoreApplication::translate("four", "TextLabel", nullptr));
        label_15->setText(QCoreApplication::translate("four", "TextLabel", nullptr));
        pushButton_13->setText(QCoreApplication::translate("four", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class four: public Ui_four {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FOUR_H
