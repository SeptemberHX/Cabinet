#include "FileListWidget.h"
#include "ui_FileListWidget.h"

#include <QDir>

FileListWidget::FileListWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FileListWidget)
{
    ui->setupUi(this);

    // file list table style
    ui->fileTableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->fileTableWidget->setColumnWidth(1, 100);
    ui->fileTableWidget->setColumnWidth(2, 100);
    ui->fileTableWidget->setColumnWidth(3, 180);
    ui->fileTableWidget->setShowGrid(false);

    ui->fileTableWidget->verticalHeader()->setDefaultSectionSize(24);
    connect(ui->fileTableWidget->horizontalHeader(), &QHeaderView::sectionClicked, this, &FileListWidget::setTableStyle);

    this->loadDir("/Users/septemberhx/Downloads");
}

FileListWidget::~FileListWidget()
{
    delete ui;
}

void FileListWidget::loadDir(const QString &dirPath)
{
    QDir dir(dirPath);
    if (dir.exists()) {
        ui->fileTableWidget->clearContents();

        this->currDirPath = dirPath;
        QFileInfoList fileList = dir.entryInfoList();
        int currRow = 0;
        for (const QFileInfo &fileInfo : fileList) {
            if (fileInfo.fileName() == "." || fileInfo.fileName() == "..") {
                continue;
            }
            ui->fileTableWidget->insertRow(currRow);
            ui->fileTableWidget->setItem(currRow, 0, new QTableWidgetItem(this->iconForFile(fileInfo.absoluteFilePath()), fileInfo.fileName()));
            ui->fileTableWidget->setItem(currRow, 1, new QTableWidgetItem(this->locale().formattedDataSize(fileInfo.size())));
            ui->fileTableWidget->setItem(currRow, 2, new QTableWidgetItem("Not working now."));
            ui->fileTableWidget->setItem(currRow, 3, new QTableWidgetItem(fileInfo.lastModified().toString("yyyy-MM-dd HH:mm:ss")));
            currRow++;
        }

        this->setTableStyle();
    }
}

void FileListWidget::setTableStyle()
{
    for (int currRow = 0; currRow < ui->fileTableWidget->rowCount(); ++currRow) {
        for (int i = 0; i < ui->fileTableWidget->columnCount(); ++i) {
            if (currRow % 2 == 1) {
                ui->fileTableWidget->item(currRow, i)->setBackground(QColor(244, 245, 245));
            } else {
                ui->fileTableWidget->item(currRow, i)->setBackground(Qt::white);
            }
        }
    }
}

QIcon FileListWidget::iconForFile(const QString &filename)
{
    QIcon icon;
    QList<QMimeType> mime_types = this->mime_database.mimeTypesForFileName(filename);
    for (int i=0; i < mime_types.count() && icon.isNull(); i++)
      icon = QIcon::fromTheme(mime_types[i].iconName());

    if (icon.isNull())
      return QApplication::style()->standardIcon(QStyle::SP_FileIcon);
    else
      return icon;
}
