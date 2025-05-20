#include "note.h"
#include "ui_note.h"
#include <QMessageBox>
#include <QInputDialog>
#include <QDateTime>
#include "globalValue.h"
#include "databasemanager.h"

Note::Note(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Note)
{
    ui->setupUi(this);
    QList<int> sizes;
    sizes << 150 << 450;
    ui->splitter->setSizes(sizes);
    fileModel = new QStandardItemModel(this);
    ui->fileListView->setModel(fileModel);
    connect(ui->fileListView, &QListView::clicked, this, &Note::on_fileListView_clicked);
    loadNotesFromDatabase();
}

Note::~Note()
{
    delete ui;
}

void Note::loadNotesFromDatabase()
{
    fileModel->clear();
    QString user = staticVal::getAccount();
    QSqlDatabase& db = databaseManager::getDataBase();
    if (!db.isOpen()) db.open();
    QSqlQuery query(db);
    query.prepare("SELECT file_name FROM text_files WHERE user_account = :user");
    query.bindValue(":user", user);
    if (query.exec()) {
        while (query.next()) {
            QString fileName = query.value(0).toString();
            QStandardItem *item = new QStandardItem(fileName);
            fileModel->appendRow(item);
        }
    }
}

void Note::on_newFileButton_clicked()
{
    bool ok;
    QString fileName = QInputDialog::getText(this, tr("新建笔记"), tr("文件名（.txt）："), QLineEdit::Normal, "new_note.txt", &ok);
    if (!ok || fileName.isEmpty()) return;
    if (!fileName.endsWith(".txt", Qt::CaseInsensitive)) fileName += ".txt";
    // 检查是否重名
    for (int i = 0; i < fileModel->rowCount(); ++i) {
        if (fileModel->item(i)->text() == fileName) {
            QMessageBox::warning(this, tr("警告"), tr("文件名已存在"));
            return;
        }
    }
    saveNoteToDatabase(fileName, "");
    loadNotesFromDatabase();
}

void Note::on_saveButton_clicked()
{
    if (currentFileName.isEmpty()) {
        QMessageBox::warning(this, tr("警告"), tr("请先选择一个文件"));
        return;
    }
    QString content = ui->textEdit->toPlainText();
    saveNoteToDatabase(currentFileName, content);
}

void Note::on_fileListView_clicked(const QModelIndex &index)
{
    QString fileName = fileModel->itemFromIndex(index)->text();
    currentFileName = fileName;
    loadNoteContent(fileName);
}

void Note::loadNoteContent(const QString &fileName)
{
    QString user = staticVal::getAccount();
    QSqlDatabase& db = databaseManager::getDataBase();
    if (!db.isOpen()) db.open();
    QSqlQuery query(db);
    query.prepare("SELECT content FROM text_files WHERE user_account = :user AND file_name = :file");
    query.bindValue(":user", user);
    query.bindValue(":file", fileName);
    if (query.exec() && query.next()) {
        QString content = query.value(0).toString();
        ui->textEdit->setText(content);
    } else {
        ui->textEdit->clear();
    }
}

void Note::saveNoteToDatabase(const QString &fileName, const QString &content)
{
    QString user = staticVal::getAccount();
    QSqlDatabase& db = databaseManager::getDataBase();
    if (!db.isOpen()) db.open();
    QSqlQuery query(db);
    // 判断是插入还是更新
    query.prepare("SELECT id FROM text_files WHERE user_account = :user AND file_name = :file");
    query.bindValue(":user", user);
    query.bindValue(":file", fileName);
    if (query.exec() && query.next()) {
        // 已存在，更新
        int id = query.value(0).toInt();
        QSqlQuery updateQuery(db);
        updateQuery.prepare("UPDATE text_files SET content = :content, uploaded_at = :time WHERE id = :id");
        updateQuery.bindValue(":content", content);
        updateQuery.bindValue(":time", QDateTime::currentDateTime());
        updateQuery.bindValue(":id", id);
        if (updateQuery.exec()) {
            QMessageBox::information(this, tr("成功"), tr("保存成功"));
        } else {
            QMessageBox::critical(this, tr("错误"), tr("保存失败"));
        }
    } else {
        // 不存在，插入
        QSqlQuery insertQuery(db);
        insertQuery.prepare("INSERT INTO text_files (user_account, file_name, content, uploaded_at) VALUES (:user, :file, :content, :time)");
        insertQuery.bindValue(":user", user);
        insertQuery.bindValue(":file", fileName);
        insertQuery.bindValue(":content", content);
        insertQuery.bindValue(":time", QDateTime::currentDateTime());
        if (insertQuery.exec()) {
            QMessageBox::information(this, tr("成功"), tr("新建并保存成功"));
        } else {
            QMessageBox::critical(this, tr("错误"), tr("新建失败"));
        }
    }
    loadNotesFromDatabase();
}

void Note::updateFileList()
{
    loadNotesFromDatabase();
}

void Note::showEvent(QShowEvent *event)
{
    QWidget::showEvent(event);
    loadNotesFromDatabase();
}
