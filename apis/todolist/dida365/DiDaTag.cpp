//
// Created by SeptemberHX on 2022/2/13.
//

#include "DiDaTag.h"

DiDaTag DiDaTag::fromJson(const QJsonObject &jsonObj) {
    DiDaTag tag;

    tag.setName(jsonObj.value("name").toString());
    tag.setLabel(jsonObj.value("label").toString());
    tag.setSortOrder(jsonObj.value("sortOrder").toInteger());
    tag.setSortType(jsonObj.value("sortType").toString());
    tag.setColor(jsonObj.value("color").toString());
    tag.setEtag(jsonObj.value("etag").toString());
    tag.setRawName(jsonObj.value("rawName").toString());

    return tag;
}

QDebug operator<<(QDebug os, const DiDaTag &tag) {
    os << tag.getName() << tag.getLabel() << tag.getRawName();
    return os;
}


const QString &DiDaTag::getName() const {
    return name;
}

void DiDaTag::setName(const QString &name) {
    DiDaTag::name = name;
}

const QString &DiDaTag::getLabel() const {
    return label;
}

void DiDaTag::setLabel(const QString &label) {
    DiDaTag::label = label;
}

qint64 DiDaTag::getSortOrder() const {
    return sortOrder;
}

void DiDaTag::setSortOrder(qint64 sortOrder) {
    DiDaTag::sortOrder = sortOrder;
}

const QString &DiDaTag::getSortType() const {
    return sortType;
}

void DiDaTag::setSortType(const QString &sortType) {
    DiDaTag::sortType = sortType;
}

const QString &DiDaTag::getColor() const {
    return color;
}

void DiDaTag::setColor(const QString &color) {
    DiDaTag::color = color;
}

const QString &DiDaTag::getEtag() const {
    return etag;
}

void DiDaTag::setEtag(const QString &etag) {
    DiDaTag::etag = etag;
}

const QString &DiDaTag::getRawName() const {
    return rawName;
}

void DiDaTag::setRawName(const QString &rawName) {
    DiDaTag::rawName = rawName;
}
