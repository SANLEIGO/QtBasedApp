#ifndef NOTE_H
#define NOTE_H

#include <QWidget>
#include <QStandardItemModel>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QShowEvent>

namespace Ui {
class Note;
}

class Note : public QWidget
{
    Q_OBJECT

public:
    explicit Note(QWidget *parent = nullptr);
    ~Note();

protected:
    void showEvent(QShowEvent *event) override;

private slots:
    void on_newFileButton_clicked();
    void on_saveButton_clicked();
    void on_fileListView_clicked(const QModelIndex &index);
    void on_showOtherNotesButton_clicked();
    void on_otherFileListView_clicked(const QModelIndex &index);

private:
    Ui::Note *ui;
    QStandardItemModel *fileModel;
    QString currentFileName;
    QString currentFileContent;

    // 他人笔记相关
    QStandardItemModel *otherFileModel;
    QString otherUserId;
    bool otherUserSharing;

    void loadNotesFromDatabase(); // 加载当前用户所有笔记
    void loadNoteContent(const QString &fileName); // 加载单个笔记内容
    void saveNoteToDatabase(const QString &fileName, const QString &content); // 保存笔记
    void updateFileList(); // 刷新文件列表

    // 他人笔记相关
    void loadOtherUserNotes(const QString &userId);
    void loadOtherUserNoteContent(const QString &fileName);
    void clearOtherUserNotes();

    QString getOtherUserID();
};

#endif // NOTE_H
