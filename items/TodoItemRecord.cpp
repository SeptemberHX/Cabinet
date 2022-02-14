//
// Created by SeptemberHX on 2022/2/14.
//

#include "TodoItemRecord.h"

const QString &TodoItemRecord::getId() const {
    return id;
}

void TodoItemRecord::setId(const QString &id) {
    TodoItemRecord::id = id;
}

const QString &TodoItemRecord::getItemId() const {
    return itemId;
}

void TodoItemRecord::setItemId(const QString &itemId) {
    TodoItemRecord::itemId = itemId;
}

const QDateTime &TodoItemRecord::getFromTime() const {
    return fromTime;
}

void TodoItemRecord::setFromTime(const QDateTime &fromTime) {
    TodoItemRecord::fromTime = fromTime;
}

const QDateTime &TodoItemRecord::getToTime() const {
    return toTime;
}

void TodoItemRecord::setToTime(const QDateTime &toTime) {
    TodoItemRecord::toTime = toTime;
}
