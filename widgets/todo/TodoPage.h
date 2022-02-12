#ifndef TODOPAGE_H
#define TODOPAGE_H

#include <QWidget>

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
};

#endif // TODOPAGE_H
