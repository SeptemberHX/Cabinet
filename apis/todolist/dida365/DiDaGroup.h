//
// Created by SeptemberHX on 2022/2/13.
//

#ifndef APIS_DIDAGROUP_H
#define APIS_DIDAGROUP_H

#include <QString>
#include <QJsonObject>


class DiDaGroup {

public:
    static DiDaGroup fromJson(const QJsonObject &jsonObj);

    friend QDebug operator<<(QDebug os, const DiDaGroup &project);

    const QString &getId() const;

    void setId(const QString &id);

    const QString &getEtag() const;

    void setEtag(const QString &etag);

    const QString &getName() const;

    void setName(const QString &name);

    bool isShowAll() const;

    void setShowAll(bool showAll);

    int getDeleted() const;

    void setDeleted(int deleted);

    int getUserId() const;

    void setUserId(int userId);

private:
    QString id;
    QString etag;
    QString name;
    bool showAll;

    // unused key sortOrder
    int deleted;
    int userId;

    // unused key sortType
    // unused key teamId
};


#endif //APIS_DIDAGROUP_H
