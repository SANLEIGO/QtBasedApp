/********************************************************************************
** Form generated from reading UI file 'taskframe.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKFRAME_H
#define UI_TASKFRAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_taskFrame
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QCheckBox *check_over;
    QLineEdit *content;
    QSpacerItem *horizontalSpacer_2;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *time_show;
    QFrame *line;

    void setupUi(QFrame *taskFrame)
    {
        if (taskFrame->objectName().isEmpty())
            taskFrame->setObjectName(QString::fromUtf8("taskFrame"));
        taskFrame->resize(729, 120);
        taskFrame->setMinimumSize(QSize(0, 120));
        taskFrame->setMaximumSize(QSize(16777215, 120));
        verticalLayout = new QVBoxLayout(taskFrame);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 50, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        frame_2 = new QFrame(taskFrame);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame_2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(33, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        frame = new QFrame(frame_2);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        check_over = new QCheckBox(frame);
        check_over->setObjectName(QString::fromUtf8("check_over"));

        horizontalLayout->addWidget(check_over);

        content = new QLineEdit(frame);
        content->setObjectName(QString::fromUtf8("content"));
        content->setStyleSheet(QString::fromUtf8("border: none;"));

        horizontalLayout->addWidget(content);


        horizontalLayout_3->addWidget(frame);

        horizontalSpacer_2 = new QSpacerItem(142, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        frame_3 = new QFrame(frame_2);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(frame_3);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        time_show = new QLabel(frame_3);
        time_show->setObjectName(QString::fromUtf8("time_show"));

        horizontalLayout_2->addWidget(time_show);


        horizontalLayout_3->addWidget(frame_3);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 12);
        horizontalLayout_3->setStretch(2, 4);
        horizontalLayout_3->setStretch(3, 1);

        verticalLayout->addWidget(frame_2);

        line = new QFrame(taskFrame);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);


        retranslateUi(taskFrame);

        QMetaObject::connectSlotsByName(taskFrame);
    } // setupUi

    void retranslateUi(QFrame *taskFrame)
    {
        taskFrame->setWindowTitle(QCoreApplication::translate("taskFrame", "Frame", nullptr));
        check_over->setText(QString());
        label->setText(QCoreApplication::translate("taskFrame", "add", nullptr));
        time_show->setText(QCoreApplication::translate("taskFrame", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class taskFrame: public Ui_taskFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKFRAME_H
