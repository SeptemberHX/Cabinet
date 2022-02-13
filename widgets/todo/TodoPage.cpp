#include "TodoPage.h"
#include "ui_TodoPage.h"
#include "CabinetSettings.h"

TodoPage::TodoPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TodoPage)
{
    ui->setupUi(this);
    this->diDa365Tools = new DiDa365Tools();

    if (!CabinetSettings::inst()->getDida365UserName().isEmpty()) {
        this->diDa365Tools->login(CabinetSettings::inst()->getDida365UserName(),
                                  CabinetSettings::inst()->getDida365Password());

        QList<DiDaTask> tasks;
        QList<DiDaProject> projects;
        QList<DiDaGroup> groups;
        QList<DiDaTag> tags;
        this->diDa365Tools->getTodoItems(0, tasks, projects, groups, tags);

        QList<TodoItem> todoItems;
        for (auto task : tasks) {
            if (task.getStartDate()) {
                todoItems << task.convertItem();
            }
        }
        this->loadTodoItems(todoItems);
    }
}

TodoPage::~TodoPage()
{
    delete ui;
}

void TodoPage::loadTodoItems(const QList<TodoItem> &todoItems) {
    this->todoItems = todoItems;

    ui->listWidget->clear();
    for (auto const &item : this->todoItems) {
        auto listItem = new QListWidgetItem(ui->listWidget);
        ui->listWidget->addItem(listItem);
        auto itemWidget = new TodoItemWidget(ui->listWidget);
        itemWidget->setTodoItem(item);
        ui->listWidget->setItemWidget(listItem, itemWidget);
        listItem->setSizeHint(itemWidget->sizeHint());
    }
}
