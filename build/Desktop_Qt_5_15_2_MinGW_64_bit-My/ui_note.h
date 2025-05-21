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
    QVBoxLayout *mainVerticalLayout;
    QSplitter *splitter;
    QWidget *fileWidget;
    QVBoxLayout *verticalLayout_2;
    QPushButton *showOtherNotesButton;
    QLabel *fileLabel;
    QListView *fileListView;
    QPushButton *newFileButton;
    QListView *otherFileListView;
    QWidget *editorWidget;
    QVBoxLayout *verticalLayout_3;
    QLabel *editorLabel;
    QTextEdit *textEdit;
    QPushButton *saveButton;

    void setupUi(QWidget *Note)
    {
        if (Note->objectName().isEmpty())
            Note->setObjectName(QString::fromUtf8("Note"));
        Note->resize(1300, 800);
        mainVerticalLayout = new QVBoxLayout(Note);
        mainVerticalLayout->setObjectName(QString::fromUtf8("mainVerticalLayout"));
        splitter = new QSplitter(Note);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        fileWidget = new QWidget(splitter);
        fileWidget->setObjectName(QString::fromUtf8("fileWidget"));
        verticalLayout_2 = new QVBoxLayout(fileWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        showOtherNotesButton = new QPushButton(fileWidget);
        showOtherNotesButton->setObjectName(QString::fromUtf8("showOtherNotesButton"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(showOtherNotesButton->sizePolicy().hasHeightForWidth());
        showOtherNotesButton->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(showOtherNotesButton);

        fileLabel = new QLabel(fileWidget);
        fileLabel->setObjectName(QString::fromUtf8("fileLabel"));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        fileLabel->setFont(font);

        verticalLayout_2->addWidget(fileLabel);

        fileListView = new QListView(fileWidget);
        fileListView->setObjectName(QString::fromUtf8("fileListView"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(fileListView->sizePolicy().hasHeightForWidth());
        fileListView->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(fileListView);

        newFileButton = new QPushButton(fileWidget);
        newFileButton->setObjectName(QString::fromUtf8("newFileButton"));
        sizePolicy.setHeightForWidth(newFileButton->sizePolicy().hasHeightForWidth());
        newFileButton->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(newFileButton);

        splitter->addWidget(fileWidget);
        otherFileListView = new QListView(splitter);
        otherFileListView->setObjectName(QString::fromUtf8("otherFileListView"));
        sizePolicy1.setHeightForWidth(otherFileListView->sizePolicy().hasHeightForWidth());
        otherFileListView->setSizePolicy(sizePolicy1);
        otherFileListView->setVisible(false);
        splitter->addWidget(otherFileListView);
        editorWidget = new QWidget(splitter);
        editorWidget->setObjectName(QString::fromUtf8("editorWidget"));
        verticalLayout_3 = new QVBoxLayout(editorWidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        editorLabel = new QLabel(editorWidget);
        editorLabel->setObjectName(QString::fromUtf8("editorLabel"));
        editorLabel->setFont(font);

        verticalLayout_3->addWidget(editorLabel);

        textEdit = new QTextEdit(editorWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setEnabled(true);
        sizePolicy1.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy1);

        verticalLayout_3->addWidget(textEdit);

        saveButton = new QPushButton(editorWidget);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));

        verticalLayout_3->addWidget(saveButton);

        splitter->addWidget(editorWidget);

        mainVerticalLayout->addWidget(splitter);


        retranslateUi(Note);

        QMetaObject::connectSlotsByName(Note);
    } // setupUi

    void retranslateUi(QWidget *Note)
    {
        Note->setWindowTitle(QCoreApplication::translate("Note", "Text Editor", nullptr));
        showOtherNotesButton->setText(QCoreApplication::translate("Note", "\346\230\276\347\244\272\344\273\226\344\272\272\347\254\224\350\256\260", nullptr));
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
