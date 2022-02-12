//
// Created by SeptemberHX on 2022/2/13.
//

#include "DiDaProject.h"


DiDaProject DiDaProject::fromJson(const QJsonObject &jsonObj) {
    DiDaProject project;

    project.setId(jsonObj.value("id").toString());
    project.setName(jsonObj.value("name").toString());
    project.setIsOwner(jsonObj.value("isOwner").toBool());
    project.setColor(jsonObj.value("color").toString());
    project.setInAll(jsonObj.value("inAll").toBool());
    project.setSortOrder(jsonObj.value("sortOrder").toInteger());
    project.setSortType(jsonObj.value("sortType").toString());
    project.setUserCount(jsonObj.value("userCount").toInt());
    project.setEtag(jsonObj.value("etag").toString());
    project.setModifiedTime(QDateTime::fromString(jsonObj.value("modifiedTime").toString(), "yyyy-MM-ddTHH:mm:ss.fff+0000"));
    project.setGroupId(jsonObj.value("groupId").toString());
    project.setKind(jsonObj.value("kind").toString());

    return project;
}

QDebug operator<<(QDebug os, const DiDaProject &project) {
    os << project.getId() << project.getGroupId() << project.getName();
    return os;
}

const QString &DiDaProject::getId() const {
    return id;
}

void DiDaProject::setId(const QString &id) {
    DiDaProject::id = id;
}

const QString &DiDaProject::getName() const {
    return name;
}

void DiDaProject::setName(const QString &name) {
    DiDaProject::name = name;
}

bool DiDaProject::isOwner1() const {
    return isOwner;
}

void DiDaProject::setIsOwner(bool isOwner) {
    DiDaProject::isOwner = isOwner;
}

const QString &DiDaProject::getColor() const {
    return color;
}

void DiDaProject::setColor(const QString &color) {
    DiDaProject::color = color;
}

bool DiDaProject::isInAll() const {
    return inAll;
}

void DiDaProject::setInAll(bool inAll) {
    DiDaProject::inAll = inAll;
}

qint64 DiDaProject::getSortOrder() const {
    return sortOrder;
}

void DiDaProject::setSortOrder(qint64 sortOrder) {
    DiDaProject::sortOrder = sortOrder;
}

const QString &DiDaProject::getSortType() const {
    return sortType;
}

void DiDaProject::setSortType(const QString &sortType) {
    DiDaProject::sortType = sortType;
}

int DiDaProject::getUserCount() const {
    return userCount;
}

void DiDaProject::setUserCount(int userCount) {
    DiDaProject::userCount = userCount;
}

const QString &DiDaProject::getEtag() const {
    return etag;
}

void DiDaProject::setEtag(const QString &etag) {
    DiDaProject::etag = etag;
}

const QDateTime &DiDaProject::getModifiedTime() const {
    return modifiedTime;
}

void DiDaProject::setModifiedTime(const QDateTime &modifiedTime) {
    DiDaProject::modifiedTime = modifiedTime;
}

const QString &DiDaProject::getGroupId() const {
    return groupId;
}

void DiDaProject::setGroupId(const QString &groupId) {
    DiDaProject::groupId = groupId;
}

const QString &DiDaProject::getKind() const {
    return kind;
}

void DiDaProject::setKind(const QString &kind) {
    DiDaProject::kind = kind;
}