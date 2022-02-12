//
// Created by SeptemberHX on 2022/2/11.
//

#include <QNetworkRequest>
#include <QEventLoop>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <iostream>
#include "DiDa365Tools.h"
#include "DiDaTask.h"


void DiDa365Tools::getTodoItems(int status, QList<DiDaTask> &tasks, QList<DiDaProject> &projects,
                                QList<DiDaGroup> &groups, QList<DiDaTag> &tags) {
    QJsonDocument jsonDoc = this->sendDiDaRequest(QString("https://api.dida365.com/api/v2/batch/check/") + QString::number(status));
    for (QJsonValue value : jsonDoc.object()["syncTaskBean"].toObject()["update"].toArray()) {
        tasks << DiDaTask::fromJson(value.toObject());
    }

    for (QJsonValue value : jsonDoc.object()["projectProfiles"].toArray()) {
        projects << DiDaProject::fromJson(value.toObject());
    }

    for (QJsonValue value : jsonDoc.object()["projectGroups"].toArray()) {
        groups << DiDaGroup::fromJson(value.toObject());
    }

    for (QJsonValue value : jsonDoc.object()["tags"].toArray()) {
        tags << DiDaTag::fromJson(value.toObject());
    }
}

void DiDa365Tools::setCookie(const QString &cookie) {
    this->cookie = cookie;
}

DiDa365Tools::DiDa365Tools(QObject *parent) : QObject(parent) {
    this->naManager = new QNetworkAccessManager(this);
}

QJsonDocument DiDa365Tools::sendDiDaRequest(QString strUrl) {
    QNetworkRequest request;
    request.setRawHeader("cookie", this->cookie.toStdString().c_str());
    request.setRawHeader("User-Agent", "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/98.0.4758.80 Safari/537.36 Edg/98.0.1108.43");
    request.setRawHeader("Host", "dida365.com");
    request.setRawHeader("accept", "application/json, text/plain, */*");
    request.setUrl(strUrl);

    QNetworkReply* reply = naManager->get(request);
    QByteArray responseData;
    QEventLoop eventLoop;
    connect(naManager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
    eventLoop.exec();

    if (reply->error() != QNetworkReply::NoError) {
        qDebug() << reply->error();
        throw std::exception();
    }

    QJsonDocument jsonResponse = QJsonDocument::fromJson(QString(reply->readAll()).toUtf8());
    reply->deleteLater();
    return jsonResponse;
}
