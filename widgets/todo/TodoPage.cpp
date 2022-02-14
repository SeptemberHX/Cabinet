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

        std::sort(todoItems.begin(), todoItems.end(), [](const TodoItem& t1, const TodoItem &t2) -> bool {
            if (t1.getStartDate() && !t2.getStartDate()) {
                return true;
            } else if (!t1.getStartDate() && t2.getStartDate()) {
                return false;
            } else {
                if (t1.getStartDate() != t2.getStartDate()) {
                    return t1.getStartDate() < t2.getStartDate();
                } else if (t1.getPriority() != t2.getPriority()) {
                    return t1.getPriority() > t2.getPriority();
                } else {
                    return t1.getTitle() < t2.getTitle();
                }
            }
        });
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
    int firstEle = true;
    QDate lastDate;
    for (auto const &item : this->todoItems) {
        // add group title
        if (firstEle) {
            if (item.getStartDate()->date() < QDate::currentDate() &&
                    (item.getDueDate() && item.getDueDate()->date() < QDate::currentDate())) {
                QListWidgetItem *groupItem = new QListWidgetItem("已过期", ui->listWidget);
                ui->listWidget->addItem(groupItem);
                groupItem->setFlags(Qt::NoItemFlags);
            } else if (item.getStartDate()->date() > QDate::currentDate()) {
                QListWidgetItem *groupItem = new QListWidgetItem(item.getStartDate()->toString("dddd,MMMM dd"), ui->listWidget);
                groupItem->setFlags(Qt::NoItemFlags);
                ui->listWidget->addItem(groupItem);
            } else {
                QListWidgetItem *groupItem = new QListWidgetItem(tr("今天"), ui->listWidget);
                groupItem->setFlags(Qt::NoItemFlags);
                ui->listWidget->addItem(groupItem);
            }
            firstEle = false;
        } else {
            if (item.getStartDate()->date() != lastDate) {
                QListWidgetItem *groupItem = new QListWidgetItem(item.getStartDate()->toString("dddd,MMMM dd"), ui->listWidget);
                groupItem->setFlags(Qt::NoItemFlags);
                ui->listWidget->addItem(groupItem);
            }
        }
        lastDate = item.getStartDate()->date();

        // add todoitem
        auto listItem = new QListWidgetItem(ui->listWidget);
        ui->listWidget->addItem(listItem);
        auto itemWidget = new TodoItemWidget(ui->listWidget);
        itemWidget->setTodoItem(item);
        ui->listWidget->setItemWidget(listItem, itemWidget);
        listItem->setSizeHint(itemWidget->size());
    }
}
