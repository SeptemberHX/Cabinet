//
// Created by SeptemberHX on 2022/2/11.
//

#ifndef CABINET_DIDA365TOOLS_H
#define CABINET_DIDA365TOOLS_H

#include <QString>
#include <QNetworkAccessManager>
#include "DiDaTask.h"
#include "DiDaProject.h"
#include "DiDaGroup.h"
#include "DiDaTag.h"


class DiDa365Tools : public QObject{

public:
    explicit DiDa365Tools(QObject *parent = nullptr);

    void getTodoItems(int status,
                      QList<DiDaTask> &tasks,
                      QList<DiDaProject> &projects,
                      QList<DiDaGroup> &groups,
                      QList<DiDaTag> &tags);

    void setCookie(const QString &cookie);

private:
    QJsonDocument sendDiDaRequest(QString strUrl);

private:
    QString cookie;
    QNetworkAccessManager *naManager;
};


#endif //CABINET_DIDA365TOOLS_H
