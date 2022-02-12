#ifndef TODOITEMWIDGET_H
#define TODOITEMWIDGET_H

#include <QWidget>

namespace Ui {
class TodoItemWidget;
}

class TodoItemWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TodoItemWidget(QWidget *parent = nullptr);
    ~TodoItemWidget();

private:
    Ui::TodoItemWidget *ui;
};

#endif // TODOITEMWIDGET_H
