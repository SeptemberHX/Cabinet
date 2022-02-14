//
// Created by SeptemberHX on 2022/2/12.
//

#ifndef CABINET_TODOITEM_H
#define CABINET_TODOITEM_H

#include <QString>
#include <QDateTime>

class TodoItem {

public:
    TodoItem(const QString &id, const QString &title, int priority, QDateTime startDate, QDateTime dueDate);

    const QString &getId() const;

    const QString &getTitle() const;

    int getPriority() const;

    const std::optional<QDateTime> &getStartDate() const;

    const std::optional<QDateTime> &getDueDate() const;

private:
    QString id;
    QString title;
    int priority;
    std::optional<QDateTime> startDate;
    std::optional<QDateTime> dueDate;
};


#endif //CABINET_TODOITEM_H
