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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Note
{
public:
    QHBoxLayout *horizontalLayout;
    QSplitter *splitter;
    QWidget *folderWidget;
    QVBoxLayout *verticalLayout;
    QLabel *folderLabel;
    QTreeView *folderTreeView;
    QHBoxLayout *folderButtonsLayout;
    QPushButton *createFolderButton;
    QPushButton *importFolderButton;
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
        Note->resize(1384, 856);
        Note->setMinimumSize(QSize(1384, 856));
        horizontalLayout = new QHBoxLayout(Note);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        splitter = new QSplitter(Note);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        folderWidget = new QWidget(splitter);
        folderWidget->setObjectName(QString::fromUtf8("folderWidget"));
        verticalLayout = new QVBoxLayout(folderWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        folderLabel = new QLabel(folderWidget);
        folderLabel->setObjectName(QString::fromUtf8("folderLabel"));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        folderLabel->setFont(font);

        verticalLayout->addWidget(folderLabel);

        folderTreeView = new QTreeView(folderWidget);
        folderTreeView->setObjectName(QString::fromUtf8("folderTreeView"));

        verticalLayout->addWidget(folderTreeView);

        folderButtonsLayout = new QHBoxLayout();
        folderButtonsLayout->setObjectName(QString::fromUtf8("folderButtonsLayout"));
        createFolderButton = new QPushButton(folderWidget);
        createFolderButton->setObjectName(QString::fromUtf8("createFolderButton"));

        folderButtonsLayout->addWidget(createFolderButton);

        importFolderButton = new QPushButton(folderWidget);
        importFolderButton->setObjectName(QString::fromUtf8("importFolderButton"));

        folderButtonsLayout->addWidget(importFolderButton);


        verticalLayout->addLayout(folderButtonsLayout);

        splitter->addWidget(folderWidget);
        fileWidget = new QWidget(splitter);
        fileWidget->setObjectName(QString::fromUtf8("fileWidget"));
        verticalLayout_2 = new QVBoxLayout(fileWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        fileLabel = new QLabel(fileWidget);
        fileLabel->setObjectName(QString::fromUtf8("fileLabel"));
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
        folderLabel->setText(QCoreApplication::translate("Note", "Folders", nullptr));
        createFolderButton->setText(QCoreApplication::translate("Note", "Create Folder", nullptr));
        importFolderButton->setText(QCoreApplication::translate("Note", "Import Folder", nullptr));
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
