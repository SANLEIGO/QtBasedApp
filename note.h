#ifndef NOTE_H
#define NOTE_H

#include <QWidget>
#include <QFileSystemModel>
#include <QStandardItemModel>
#include <QFile>
#include <QTextStream>
#include <QString>

namespace Ui {
class Note;
}

class Note : public QWidget
{
    Q_OBJECT

public:
    explicit Note(QWidget *parent = nullptr);
    ~Note();

private slots:
    void on_createFolderButton_clicked();
    void on_importFolderButton_clicked();
    void on_newFileButton_clicked();
    void on_saveButton_clicked();
    void on_folderTreeView_clicked(const QModelIndex &index);
    void on_fileListView_clicked(const QModelIndex &index);

private:
    Ui::Note *ui;
    QFileSystemModel *folderModel;
    QStandardItemModel *fileModel;
    QString currentFolderPath;
    QString currentFilePath;
    
    void loadTextFile(const QString &filePath);
    void updateFileList(const QString &folderPath);
    void saveTextFile(const QString &filePath, const QString &content);
    bool isTxtFile(const QString &fileName);
};

#endif // NOTE_H
