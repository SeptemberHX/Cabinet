#ifndef CABINETMAINWIDGET_H
#define CABINETMAINWIDGET_H

#include <QWidget>
#include "items/PreviewMDDoc.h"
#include "apis/todolist/dida365/DiDa365Tools.h"

namespace Ui {
class CabinetMainWidget;
}

class CabinetMainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CabinetMainWidget(QWidget *parent = nullptr);
    ~CabinetMainWidget();

public slots:
    void changeCurrDir(const QString &dirPath);

private:
    Ui::CabinetMainWidget *ui;

    QString currDirPath;
    PreviewMDDoc previewMdDoc;
};

#endif // CABINETMAINWIDGET_H
