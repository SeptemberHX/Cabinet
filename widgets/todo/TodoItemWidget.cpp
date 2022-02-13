#include "TodoItemWidget.h"
#include "ui_TodoItemWidget.h"

TodoItemWidget::TodoItemWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TodoItemWidget)
{
    ui->setupUi(this);
}

TodoItemWidget::~TodoItemWidget()
{
    delete ui;
}

void TodoItemWidget::setTodoItem(const TodoItem &item) {
    this->todoItem = item;

    ui->checkBox->setText(item.getTitle());
    if (item.getStartDate()) {
        ui->label->setText(item.getStartDate()->date().toString());
    }
}
