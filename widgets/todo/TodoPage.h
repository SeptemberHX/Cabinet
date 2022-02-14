#ifndef TODOPAGE_H
#define TODOPAGE_H

#include <QWidget>
#include <QList>
#include "TodoItemWidget.h"
#include "apis/todolist/dida365/DiDa365Tools.h"
#include "items/CabinetDB.h"

namespace Ui {
class TodoPage;
}

class TodoPage : public QWidget
{
    Q_OBJECT

public:
    explicit TodoPage(QWidget *parent = nullptr);
    ~TodoPage();

private:
    Ui::TodoPage *ui;
    QList<TodoItem> todoItems;
    DiDa365Tools *diDa365Tools;

    void loadTodoItems(const QList<TodoItem> &todoItems);
};

#endif // TODOPAGE_H
