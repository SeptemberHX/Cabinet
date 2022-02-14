//
// Created by SeptemberHX on 2022/2/14.
//

#ifndef CABINET_TODOITEMRECORD_H
#define CABINET_TODOITEMRECORD_H


#include <QString>
#include <QDateTime>

class TodoItemRecord {

public:
    const QString &getId() const;

    void setId(const QString &id);

    const QString &getItemId() const;

    void setItemId(const QString &itemId);

    const QDateTime &getFromTime() const;

    void setFromTime(const QDateTime &fromTime);

    const QDateTime &getToTime() const;

    void setToTime(const QDateTime &toTime);

private:
    QString id;
    QString itemId;
    QDateTime fromTime;
    QDateTime toTime;
};


#endif //CABINET_TODOITEMRECORD_H
