//
// Created by SeptemberHX on 2022/2/13.
//

#ifndef APIS_DIDAPROJECT_H
#define APIS_DIDAPROJECT_H

#include <QString>
#include <QJsonObject>
#include <QDateTime>


class DiDaProject {

public:
    static DiDaProject fromJson(const QJsonObject &jsonObj);

    friend QDebug operator<<(QDebug os, const DiDaProject &project);

    const QString &getId() const;

    void setId(const QString &id);

    const QString &getName() const;

    void setName(const QString &name);

    bool isOwner1() const;

    void setIsOwner(bool isOwner);

    const QString &getColor() const;

    void setColor(const QString &color);

    bool isInAll() const;

    void setInAll(bool inAll);

    qint64 getSortOrder() const;

    void setSortOrder(qint64 sortOrder);

    const QString &getSortType() const;

    void setSortType(const QString &sortType);

    int getUserCount() const;

    void setUserCount(int userCount);

    const QString &getEtag() const;

    void setEtag(const QString &etag);

    const QDateTime &getModifiedTime() const;

    void setModifiedTime(const QDateTime &modifiedTime);

    const QString &getGroupId() const;

    void setGroupId(const QString &groupId);

    const QString &getKind() const;

    void setKind(const QString &kind);

private:
    QString id;
    QString name;
    bool isOwner;
    QString color;
    bool inAll;
    qint64 sortOrder;
    QString sortType;
    int userCount;
    QString etag;
    QDateTime modifiedTime;

    // unused key: closed
    // unused key: muted
    // unused key: transferred

    QString groupId;
    // unused key: viewMode
    // unused key: notificationOptions
    // unused key: teamId
    // unused key: permission
    QString kind;
};


#endif //APIS_DIDAPROJECT_H
