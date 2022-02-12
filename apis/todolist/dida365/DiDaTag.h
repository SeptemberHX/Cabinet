//
// Created by SeptemberHX on 2022/2/13.
//

#ifndef APIS_DIDATAG_H
#define APIS_DIDATAG_H

#include <QJsonObject>
#include <QString>


class DiDaTag {

public:
    static DiDaTag fromJson(const QJsonObject &jsonObj);

    friend QDebug operator<<(QDebug os, const DiDaTag &project);

    const QString &getName() const;

    void setName(const QString &name);

    const QString &getLabel() const;

    void setLabel(const QString &label);

    qint64 getSortOrder() const;

    void setSortOrder(qint64 sortOrder);

    const QString &getSortType() const;

    void setSortType(const QString &sortType);

    const QString &getColor() const;

    void setColor(const QString &color);

    const QString &getEtag() const;

    void setEtag(const QString &etag);

    const QString &getRawName() const;

    void setRawName(const QString &rawName);

private:
    QString name;
    QString label;
    qint64 sortOrder;
    QString sortType;
    QString color;
    QString etag;
    QString rawName;
};


#endif //APIS_DIDATAG_H
