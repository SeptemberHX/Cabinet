#ifndef FILELISTWIDGET_H
#define FILELISTWIDGET_H

#include <QMimeDatabase>
#include <QWidget>

namespace Ui {
class FileListWidget;
}

class FileListWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FileListWidget(QWidget *parent = nullptr);
    ~FileListWidget();

public slots:
    void loadDir(const QString &dirPath);

private slots:
    void setTableStyle();

private:
    QIcon iconForFile(const QString &filename);

private:
    Ui::FileListWidget *ui;
    QString currDirPath;
    QMimeDatabase mime_database;
};

#endif // FILELISTWIDGET_H
