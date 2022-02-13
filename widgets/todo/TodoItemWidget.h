#ifndef TODOITEMWIDGET_H
#define TODOITEMWIDGET_H

#include <QWidget>
#include "../../apis/todolist/TodoItem.h"

namespace Ui {
class TodoItemWidget;
}

class TodoItemWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TodoItemWidget(QWidget *parent = nullptr);
    ~TodoItemWidget();

    void setTodoItem(const TodoItem &item);

private:
    Ui::TodoItemWidget *ui;
    std::optional<TodoItem> todoItem;
};

#endif // TODOITEMWIDGET_H
