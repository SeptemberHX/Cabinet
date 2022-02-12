//
// Created by SeptemberHX on 2022/2/12.
//

#include "TodoItem.h"

const QString &TodoItem::getId() const {
    return id;
}

TodoItem::TodoItem(const QString &id, const QString &title, int priority, QDateTime startDate)
    : id(id), title(title), priority(priority), startDate(startDate) {}
