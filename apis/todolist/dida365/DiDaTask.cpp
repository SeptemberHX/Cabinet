//
// Created by SeptemberHX on 2022/2/12.
//

#include "DiDaTask.h"
#include "TodoItem.h"
#include <QJsonArray>

DiDaReminder::DiDaReminder(const QString &id, const QString &trigger) : id(id), trigger(trigger) {}

TodoItem DiDaTask::convertItem() {
    return TodoItem(this->id, this->title, this->priority, this->startDate.value(), this->dueDate.value());
}

DiDaTask DiDaTask::fromJson(const QJsonObject &jsonObj) {
    DiDaTask task;

    task.setId(jsonObj.value("id").toString());
    task.setProjectId(jsonObj.value("projectId").toString());
    task.setSortOrder(jsonObj.value("sortOrder").toInteger());
    task.setTitle(jsonObj.value("title").toString());
    task.setContent(jsonObj.value("content").toString());
    task.setDesc(jsonObj.value("desc").toString());
    task.setTimeZone(jsonObj.value("timeZone").toString());
    task.setIsFloating(jsonObj.value("isFloating").toBool());
    task.setIsAllDay(jsonObj.value("isAllDay").toBool());
    task.setReminder(jsonObj.value("reminder").toString());

    QList<DiDaReminder> reminders;
    for (QJsonValue value : jsonObj.value("reminders").toArray()) {
        QJsonObject reminderObj = value.toObject();
        DiDaReminder diDaReminder(reminderObj.value("id").toString(), reminderObj.value("trigger").toString());
        reminders << diDaReminder;
    }
    task.setReminders(reminders);

    task.setPriority(jsonObj.value("priority").toInt());
    task.setStatus(jsonObj.value("status").toInt());

    // items

    task.setProgress(jsonObj.value("progress").toInt());
    task.setModifiedTime(QDateTime::fromString(jsonObj.value("modifiedTime").toString(), "yyyy-MM-ddTHH:mm:ss.fff+0000"));
    task.setEtag(jsonObj.value("etag").toString());
    task.setDeleted(jsonObj.value("deleted").toInt());
    task.setCreatedTime(QDateTime::fromString(jsonObj.value("createdTime").toString(), "yyyy-MM-ddTHH:mm:ss.zzz+0000"));
    task.setCreator(jsonObj.value("creator").toInt());

    // tags
    QStringList tags;
    for (QJsonValue value : jsonObj.value("tags").toArray()) {
        tags << value.toString();
    }
    task.setTags(tags);

    task.setCommentCount(jsonObj.value("commentCount").toInt());

    if (jsonObj.contains("startDate")) {
        task.startDate = QDateTime::fromString(jsonObj.value("startDate").toString(), "yyyy-MM-ddTHH:mm:ss.zzz+0000");
    }

    if (jsonObj.contains("dueDate")) {
        task.dueDate = QDateTime::fromString(jsonObj.value("dueDate").toString(), "yyyy-MM-ddTHH:mm:ss.zzz+0000");
    }

    return task;
}

QDebug operator<<(QDebug os, const DiDaTask &task) {
    os << "id: " << task.id << " projectId: " << task.projectId << " title: " << task.title;
    return os;
}

const QString &DiDaReminder::getId() const {
    return id;
}

void DiDaReminder::setId(const QString &id) {
    DiDaReminder::id = id;
}

const QString &DiDaReminder::getTrigger() const {
    return trigger;
}

void DiDaReminder::setTrigger(const QString &trigger) {
    DiDaReminder::trigger = trigger;
}

const QString &DiDaTask::getId() const {
    return id;
}

void DiDaTask::setId(const QString &id) {
    DiDaTask::id = id;
}

const QString &DiDaTask::getProjectId() const {
    return projectId;
}

void DiDaTask::setProjectId(const QString &projectId) {
    DiDaTask::projectId = projectId;
}

qint64 DiDaTask::getSortOrder() const {
    return sortOrder;
}

void DiDaTask::setSortOrder(qint64 sortOrder) {
    DiDaTask::sortOrder = sortOrder;
}

const QString &DiDaTask::getTitle() const {
    return title;
}

void DiDaTask::setTitle(const QString &title) {
    DiDaTask::title = title;
}

const QString &DiDaTask::getContent() const {
    return content;
}

void DiDaTask::setContent(const QString &content) {
    DiDaTask::content = content;
}

const QString &DiDaTask::getDesc() const {
    return desc;
}

void DiDaTask::setDesc(const QString &desc) {
    DiDaTask::desc = desc;
}

const QString &DiDaTask::getTimeZone() const {
    return timeZone;
}

void DiDaTask::setTimeZone(const QString &timeZone) {
    DiDaTask::timeZone = timeZone;
}

bool DiDaTask::isFloating1() const {
    return isFloating;
}

void DiDaTask::setIsFloating(bool isFloating) {
    DiDaTask::isFloating = isFloating;
}

bool DiDaTask::isAllDay1() const {
    return isAllDay;
}

void DiDaTask::setIsAllDay(bool isAllDay) {
    DiDaTask::isAllDay = isAllDay;
}

const QString &DiDaTask::getReminder() const {
    return reminder;
}

void DiDaTask::setReminder(const QString &reminder) {
    DiDaTask::reminder = reminder;
}

const QList<DiDaReminder> &DiDaTask::getReminders() const {
    return reminders;
}

void DiDaTask::setReminders(const QList<DiDaReminder> &reminders) {
    DiDaTask::reminders = reminders;
}

int DiDaTask::getPriority() const {
    return priority;
}

void DiDaTask::setPriority(int priority) {
    DiDaTask::priority = priority;
}

int DiDaTask::getStatus() const {
    return status;
}

void DiDaTask::setStatus(int status) {
    DiDaTask::status = status;
}

int DiDaTask::getProgress() const {
    return progress;
}

void DiDaTask::setProgress(int progress) {
    DiDaTask::progress = progress;
}

const QDateTime &DiDaTask::getModifiedTime() const {
    return modifiedTime;
}

void DiDaTask::setModifiedTime(const QDateTime &modifiedTime) {
    DiDaTask::modifiedTime = modifiedTime;
}

const QString &DiDaTask::getEtag() const {
    return etag;
}

void DiDaTask::setEtag(const QString &etag) {
    DiDaTask::etag = etag;
}

int DiDaTask::getDeleted() const {
    return deleted;
}

void DiDaTask::setDeleted(int deleted) {
    DiDaTask::deleted = deleted;
}

const QDateTime &DiDaTask::getCreatedTime() const {
    return createdTime;
}

void DiDaTask::setCreatedTime(const QDateTime &createdTime) {
    DiDaTask::createdTime = createdTime;
}

int DiDaTask::getCreator() const {
    return creator;
}

void DiDaTask::setCreator(int creator) {
    DiDaTask::creator = creator;
}

const QStringList &DiDaTask::getTags() const {
    return tags;
}

void DiDaTask::setTags(const QStringList &tags) {
    DiDaTask::tags = tags;
}

int DiDaTask::getCommentCount() const {
    return commentCount;
}

void DiDaTask::setCommentCount(int commentCount) {
    DiDaTask::commentCount = commentCount;
}

const QString &DiDaTask::getKind() const {
    return kind;
}

void DiDaTask::setKind(const QString &kind) {
    DiDaTask::kind = kind;
}

DiDaTask::~DiDaTask() {

}

const std::optional<QDateTime> &DiDaTask::getStartDate() const {
    return startDate;
}

const std::optional<QDateTime> &DiDaTask::getDueDate() const {
    return dueDate;
}
