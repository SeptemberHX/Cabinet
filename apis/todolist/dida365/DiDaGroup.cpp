//
// Created by SeptemberHX on 2022/2/13.
//

#include "DiDaGroup.h"


DiDaGroup DiDaGroup::fromJson(const QJsonObject &jsonObj) {
    DiDaGroup group;

    group.setId(jsonObj.value("id").toString());
    group.setEtag(jsonObj.value("etag").toString());
    group.setName(jsonObj.value("name").toString());
    group.setShowAll(jsonObj.value("showAll").toBool());
    group.setDeleted(jsonObj.value("deleted").toInt());
    group.setUserId(jsonObj.value("userId").toInt());

    return group;
}

QDebug operator<<(QDebug os, const DiDaGroup &group) {
    os << group.getId() << group.getName();
    return os;
}

const QString &DiDaGroup::getId() const {
    return id;
}

void DiDaGroup::setId(const QString &id) {
    DiDaGroup::id = id;
}

const QString &DiDaGroup::getEtag() const {
    return etag;
}

void DiDaGroup::setEtag(const QString &etag) {
    DiDaGroup::etag = etag;
}

const QString &DiDaGroup::getName() const {
    return name;
}

void DiDaGroup::setName(const QString &name) {
    DiDaGroup::name = name;
}

bool DiDaGroup::isShowAll() const {
    return showAll;
}

void DiDaGroup::setShowAll(bool showAll) {
    DiDaGroup::showAll = showAll;
}

int DiDaGroup::getDeleted() const {
    return deleted;
}

void DiDaGroup::setDeleted(int deleted) {
    DiDaGroup::deleted = deleted;
}

int DiDaGroup::getUserId() const {
    return userId;
}

void DiDaGroup::setUserId(int userId) {
    DiDaGroup::userId = userId;
}
