#include "TodoPage.h"
#include "ui_TodoPage.h"

TodoPage::TodoPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TodoPage)
{
    ui->setupUi(this);
}

TodoPage::~TodoPage()
{
    delete ui;
}
