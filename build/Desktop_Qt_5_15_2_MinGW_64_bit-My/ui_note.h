/********************************************************************************
** Form generated from reading UI file 'note.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTE_H
#define UI_NOTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Note
{
public:
    QHBoxLayout *horizontalLayout;
    QSplitter *splitter;
    QWidget *fileWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *fileLabel;
    QListView *fileListView;
    QPushButton *newFileButton;
    QWidget *editorWidget;
    QVBoxLayout *verticalLayout_3;
    QLabel *editorLabel;
    QTextEdit *textEdit;
    QPushButton *saveButton;

    void setupUi(QWidget *Note)
    {
        if (Note->objectName().isEmpty())
            Note->setObjectName(QString::fromUtf8("Note"));
        Note->resize(900, 600);
        Note->setMinimumSize(QSize(900, 600));
        horizontalLayout = new QHBoxLayout(Note);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        splitter = new QSplitter(Note);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        fileWidget = new QWidget(splitter);
        fileWidget->setObjectName(QString::fromUtf8("fileWidget"));
        verticalLayout_2 = new QVBoxLayout(fileWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        fileLabel = new QLabel(fileWidget);
        fileLabel->setObjectName(QString::fromUtf8("fileLabel"));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        fileLabel->setFont(font);

        verticalLayout_2->addWidget(fileLabel);

        fileListView = new QListView(fileWidget);
        fileListView->setObjectName(QString::fromUtf8("fileListView"));

        verticalLayout_2->addWidget(fileListView);

        newFileButton = new QPushButton(fileWidget);
        newFileButton->setObjectName(QString::fromUtf8("newFileButton"));

        verticalLayout_2->addWidget(newFileButton);

        splitter->addWidget(fileWidget);
        editorWidget = new QWidget(splitter);
        editorWidget->setObjectName(QString::fromUtf8("editorWidget"));
        verticalLayout_3 = new QVBoxLayout(editorWidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        editorLabel = new QLabel(editorWidget);
        editorLabel->setObjectName(QString::fromUtf8("editorLabel"));
        editorLabel->setFont(font);

        verticalLayout_3->addWidget(editorLabel);

        textEdit = new QTextEdit(editorWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout_3->addWidget(textEdit);

        saveButton = new QPushButton(editorWidget);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));

        verticalLayout_3->addWidget(saveButton);

        splitter->addWidget(editorWidget);

        horizontalLayout->addWidget(splitter);


        retranslateUi(Note);

        QMetaObject::connectSlotsByName(Note);
    } // setupUi

    void retranslateUi(QWidget *Note)
    {
        Note->setWindowTitle(QCoreApplication::translate("Note", "Text Editor", nullptr));
        fileLabel->setText(QCoreApplication::translate("Note", "Files", nullptr));
        newFileButton->setText(QCoreApplication::translate("Note", "New File", nullptr));
        editorLabel->setText(QCoreApplication::translate("Note", "Editor", nullptr));
        saveButton->setText(QCoreApplication::translate("Note", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Note: public Ui_Note {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTE_H
