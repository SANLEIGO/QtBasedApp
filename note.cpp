#include "note.h"
#include "ui_note.h"
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>
#include <QStandardItem>
#include <QFileInfo>
#include <QInputDialog>

Note::Note(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Note)
{
    ui->setupUi(this);
    
    // Initialize folder model
    folderModel = new QFileSystemModel(this);
    folderModel->setFilter(QDir::Dirs | QDir::NoDotAndDotDot);
    ui->folderTreeView->setModel(folderModel);
    
    // Hide unnecessary columns in folder view
    for (int i = 1; i < folderModel->columnCount(); ++i) {
        ui->folderTreeView->hideColumn(i);
    }
    
    // Initialize file model
    fileModel = new QStandardItemModel(this);
    ui->fileListView->setModel(fileModel);
    
    // Connect signals and slots
    connect(ui->folderTreeView, &QTreeView::clicked, this, &Note::on_folderTreeView_clicked);
    connect(ui->fileListView, &QListView::clicked, this, &Note::on_fileListView_clicked);
}

Note::~Note()
{
    delete ui;
}

void Note::on_createFolderButton_clicked()
{
    // Ask user for the folder location
    QString folderPath = QFileDialog::getExistingDirectory(this, tr("Select Location for New Folder"));
    
    if (folderPath.isEmpty()) {
        return;  // User canceled
    }
    
    // Ask user for folder name
    bool ok;
    QString folderName = QInputDialog::getText(this, tr("Create Folder"),
                                             tr("Folder name:"), QLineEdit::Normal,
                                             "New Folder", &ok);
    if (!ok || folderName.isEmpty()) {
        return;  // User canceled or entered empty name
    }
    
    // Create the folder
    QDir dir(folderPath);
    if (!dir.mkdir(folderName)) {
        QMessageBox::critical(this, tr("Error"), tr("Failed to create folder"));
        return;
    }
    
    // Set the root path to show the folders
    folderModel->setRootPath(folderPath);
    ui->folderTreeView->setRootIndex(folderModel->index(folderPath));
}

void Note::on_importFolderButton_clicked()
{
    // Ask user to select a folder to import
    QString folderPath = QFileDialog::getExistingDirectory(this, tr("Import Folder"));
    
    if (folderPath.isEmpty()) {
        return;  // User canceled
    }
    
    // Set the root path to show the imported folder
    folderModel->setRootPath(QFileInfo(folderPath).path());
    ui->folderTreeView->setRootIndex(folderModel->index(QFileInfo(folderPath).path()));
    
    // Expand to show the imported folder
    QModelIndex folderIndex = folderModel->index(folderPath);
    ui->folderTreeView->expand(folderIndex);
    ui->folderTreeView->scrollTo(folderIndex);
    ui->folderTreeView->setCurrentIndex(folderIndex);
    
    // Update file list for the imported folder
    updateFileList(folderPath);
}

void Note::on_newFileButton_clicked()
{
    if (currentFolderPath.isEmpty()) {
        QMessageBox::warning(this, tr("Warning"), tr("Please select a folder first"));
        return;
    }
    
    // Ask user for file name
    bool ok;
    QString fileName = QInputDialog::getText(this, tr("New Text File"),
                                            tr("File name (with .txt extension):"), QLineEdit::Normal,
                                            "new_file.txt", &ok);
    if (!ok || fileName.isEmpty()) {
        return;  // User canceled or entered empty name
    }
    
    // Ensure the file has .txt extension
    if (!fileName.endsWith(".txt", Qt::CaseInsensitive)) {
        fileName += ".txt";
    }
    
    // Create new file
    QString filePath = currentFolderPath + "/" + fileName;
    QFile file(filePath);
    
    if (file.exists()) {
        QMessageBox::warning(this, tr("Warning"), tr("File already exists"));
        return;
    }
    
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(this, tr("Error"), tr("Failed to create file"));
        return;
    }
    
    file.close();
    
    // Update file list and select the new file
    updateFileList(currentFolderPath);
    
    // Find and select the new file in the list view
    for (int i = 0; i < fileModel->rowCount(); ++i) {
        QStandardItem *item = fileModel->item(i);
        if (item->text() == fileName) {
            ui->fileListView->setCurrentIndex(item->index());
            loadTextFile(filePath);
            break;
        }
    }
}

void Note::on_saveButton_clicked()
{
    if (currentFilePath.isEmpty()) {
        QMessageBox::warning(this, tr("Warning"), tr("No file is currently open"));
        return;
    }
    
    saveTextFile(currentFilePath, ui->textEdit->toPlainText());
}

void Note::on_folderTreeView_clicked(const QModelIndex &index)
{
    currentFolderPath = folderModel->filePath(index);
    updateFileList(currentFolderPath);
    
    // Clear text editor when folder changes
    ui->textEdit->clear();
    currentFilePath = "";
}

void Note::on_fileListView_clicked(const QModelIndex &index)
{
    QString fileName = fileModel->itemFromIndex(index)->text();
    currentFilePath = currentFolderPath + "/" + fileName;
    loadTextFile(currentFilePath);
}

void Note::loadTextFile(const QString &filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, tr("Error"), tr("Failed to open file"));
        return;
    }
    
    QTextStream in(&file);
    ui->textEdit->setText(in.readAll());
    file.close();
}

void Note::updateFileList(const QString &folderPath)
{
    fileModel->clear();
    
    QDir dir(folderPath);
    QStringList files = dir.entryList(QDir::Files);
    
    for (const QString &fileName : files) {
        if (isTxtFile(fileName)) {
            QStandardItem *item = new QStandardItem(fileName);
            fileModel->appendRow(item);
        }
    }
}

void Note::saveTextFile(const QString &filePath, const QString &content)
{
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(this, tr("Error"), tr("Failed to save file"));
        return;
    }
    
    QTextStream out(&file);
    out << content;
    file.close();
    
    QMessageBox::information(this, tr("Success"), tr("File saved successfully"));
}

bool Note::isTxtFile(const QString &fileName)
{
    return fileName.endsWith(".txt", Qt::CaseInsensitive);
}
