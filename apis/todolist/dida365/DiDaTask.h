//
// Created by SeptemberHX on 2022/2/12.
//

#ifndef APIS_DIDATASK_H
#define APIS_DIDATASK_H


#include <QList>
#include <QString>
#include <QDateTime>
#include <QJsonObject>
#include <QDebug>
#include <ostream>
#include "../TodoItem.h"


class DiDaReminder {
public:
    DiDaReminder(const QString &id, const QString &trigger);

    const QString &getId() const;

    void setId(const QString &id);

    const QString &getTrigger() const;

    void setTrigger(const QString &trigger);

private:
    QString id;
    QString trigger;
};

class DiDaTask {

public:

    static DiDaTask fromJson(const QJsonObject &jsonObj);

    friend QDebug operator<<(QDebug os, const DiDaTask &task);

    TodoItem convertItem();

    const QString &getId() const;

    void setId(const QString &id);

    const QString &getProjectId() const;

    void setProjectId(const QString &projectId);

    qint64 getSortOrder() const;

    void setSortOrder(qint64 sortOrder);

    const QString &getTitle() const;

    void setTitle(const QString &title);

    const QString &getContent() const;

    void setContent(const QString &content);

    const QString &getDesc() const;

    void setDesc(const QString &desc);

    const QString &getTimeZone() const;

    void setTimeZone(const QString &timeZone);

    bool isFloating1() const;

    void setIsFloating(bool isFloating);

    bool isAllDay1() const;

    void setIsAllDay(bool isAllDay);

    const QString &getReminder() const;

    void setReminder(const QString &reminder);

    const QList<DiDaReminder> &getReminders() const;

    void setReminders(const QList<DiDaReminder> &reminders);

    int getPriority() const;

    void setPriority(int priority);

    int getStatus() const;

    void setStatus(int status);

    int getProgress() const;

    void setProgress(int progress);

    const QDateTime &getModifiedTime() const;

    void setModifiedTime(const QDateTime &modifiedTime);

    const QString &getEtag() const;

    void setEtag(const QString &etag);

    int getDeleted() const;

    void setDeleted(int deleted);

    const QDateTime &getCreatedTime() const;

    void setCreatedTime(const QDateTime &createdTime);

    int getCreator() const;

    void setCreator(int creator);

    const QStringList &getTags() const;

    void setTags(const QStringList &tags);

    int getCommentCount() const;

    void setCommentCount(int commentCount);

    const QString &getKind() const;

    void setKind(const QString &kind);

    virtual ~DiDaTask();

private:

    QString id;
    QString projectId;
    qint64 sortOrder;
    QString title;
    QString content;
    QString desc;
    QString timeZone;
    bool isFloating;
    bool isAllDay;
    QString reminder;
    QList<DiDaReminder> reminders;
    int priority;
    int status;

    // items: not used

    int progress;
    QDateTime modifiedTime;
    QString etag;
    int deleted;
    QDateTime createdTime;
    int creator;
    QStringList tags;
    int commentCount;
    // pomodoroSummaries

    QString kind;

    std::optional<QDateTime> startDate;
    std::optional<QDateTime> dueDate;
};


#endif //APIS_DIDATASK_H
