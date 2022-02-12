#include "CabinetMainWidget.h"
#include "ui_CabinetMainWidget.h"
#include "widgets/PreviewPage.h"
#include <QWebChannel>

CabinetMainWidget::CabinetMainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CabinetMainWidget)
{
    ui->setupUi(this);
    ui->mdPreview->setContextMenuPolicy(Qt::NoContextMenu);
    ui->mdPreview->setPage(new PreviewPage(this));
    ui->mdPreview->setUrl(QUrl("qrc:/page/index.html"));

    // markdown preview
    QWebChannel *channel = new QWebChannel(this);
    channel->registerObject(QStringLiteral("content"), &this->previewMdDoc);
    ui->mdPreview->page()->setWebChannel(channel);
}

CabinetMainWidget::~CabinetMainWidget()
{
    delete ui;
}

void CabinetMainWidget::changeCurrDir(const QString &dirPath)
{
    if (dirPath == this->currDirPath) {
        qDebug() << "Changed to current dir path! Ingnored.";
        return;
    }

    this->currDirPath = dirPath;
}
