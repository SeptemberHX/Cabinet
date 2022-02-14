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

    ui->titleLabel->setText(item.getTitle());
    if (item.getStartDate()) {
        if (item.getStartDate()->date() == QDate::currentDate()) {
            ui->label->setText(tr("Today"));
        } else if (QDate::currentDate().daysTo(item.getStartDate()->date()) == 1) {
            ui->label->setText(tr("Tomorrow"));
        } else {
            ui->label->setText(item.getStartDate()->date().toString("MMM dd"));
        }
    }

    QColor priorityColor("#a9a9a9");
    switch (this->todoItem->getPriority()) {
        case 5:
            priorityColor = QColor("#d76450");
            break;
        case 4:
            priorityColor = QColor("#f7d25c");
            break;
        case 3:
            priorityColor = QColor("#7c94e0");
            break;
        default:
            break;
    }
    ui->checkBox->setStyleSheet(QString("QCheckBox::indicator {\n"
                                        "width: 12px;\n"
                                        "height: 12px;\n"
                                "    border: 1px solid %1;\n"
                                "    border-radius: 4px;\n"
                                "    background: none;\n"
                                "}").arg(priorityColor.name()));
}
