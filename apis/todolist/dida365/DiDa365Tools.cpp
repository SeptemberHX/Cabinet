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

DiDa365Tools::DiDa365Tools(QObject *parent) : QObject(parent), firstSocketMsg(false) {
    this->naManager = new QNetworkAccessManager(this);
    this->socketClient = new QWebSocket("https://www.dida365.com", QWebSocketProtocol::Version13, this);
    connect(this->socketClient, &QWebSocket::textMessageReceived, this, &DiDa365Tools::socketMsgReceived);

    this->heartbeatTimer = new QTimer(this);
    this->heartbeatTimer->setInterval(9 * 60 * 1000);
    connect(this->heartbeatTimer, &QTimer::timeout, this, &DiDa365Tools::socketHeartBeat);
}

QJsonDocument DiDa365Tools::sendDiDaRequest(QString strUrl) {
    QNetworkRequest request;
    request.setRawHeader("cookie", this->cookie.toStdString().c_str());
    request.setRawHeader("User-Agent", "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/98.0.4758.80 Safari/537.36 Edg/98.0.1108.43");
    request.setRawHeader("Host", "dida365.com");
    request.setRawHeader("accept", "application/json, text/plain, */*");
    request.setRawHeader("x-device", R"({"platform":"web","os":"macOS 10.15.7","device":"Chrome 98.0.4758.80","name":"","version":4120,"id":"6208be7339efa90473e1e352","channel":"website","campaign":"","websocket":"6208be7439efa96ca1734cfd"})");
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

void DiDa365Tools::connectSocket() {
    if (this->socketClient->isValid()) {
        return;
    }

    this->firstSocketMsg = false;
    this->socketClient->open(QUrl("wss://wss.dida365.com/web"));
}

void DiDa365Tools::socketMsgReceived(const QString &msg) {
    qDebug() << msg;
    // we will receive the push token when we connect to the websocket server
    if (!firstSocketMsg && msg.length() == 60) {
        this->firstSocketMsg = true;

        // register the push token we get here
        this->registerPushToken(msg);
    } else if (msg.startsWith('{') && msg.endsWith("}")) {
        QJsonDocument jsonResponse = QJsonDocument::fromJson(msg.toUtf8());
        QJsonObject jsonObj = jsonResponse.object();
        if (jsonObj.contains("needSync")) {
            Q_EMIT needSync(jsonObj["data"].toInteger());
        }
    }
}

bool DiDa365Tools::registerPushToken(const QString &token) {
    QNetworkRequest registryRequest;
    registryRequest.setRawHeader("Cookie", this->cookie.toStdString().c_str());
    registryRequest.setRawHeader("User-Agent", "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/98.0.4758.80 Safari/537.36 Edg/98.0.1108.43");
    registryRequest.setRawHeader("Host", "dida365.com");
    registryRequest.setRawHeader("content-type", "application/json;charset=UTF-8");
    registryRequest.setRawHeader("accept", "application/json, text/plain, */*");
    registryRequest.setRawHeader("x-device", R"({"platform":"web","os":"macOS 10.15.7","device":"Chrome 98.0.4758.80","name":"","version":4120,"id":"6208be7339efa90473e1e352","channel":"website","campaign":"","websocket":"6208be7439efa96ca1734cfd"})");
    registryRequest.setUrl(QUrl("https://api.dida365.com/api/v2/push/register"));

    QJsonObject bodyJson;
    bodyJson["pushToken"] = token;
    bodyJson["osType"] = 41;

    QByteArray body = QJsonDocument(bodyJson).toJson();
    QNetworkReply* reply = naManager->post(registryRequest, body);
    QEventLoop eventLoop;
    connect(naManager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
    eventLoop.exec();

    if (reply->error() != QNetworkReply::NoError) {
        qDebug() << reply->error();
        qDebug() << reply->readAll();
        reply->deleteLater();
        return false;
    }

    reply->deleteLater();
    return true;
}

bool DiDa365Tools::login(const QString &username, const QString &password) {
    QNetworkRequest registryRequest;
    registryRequest.setRawHeader("User-Agent", "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/98.0.4758.80 Safari/537.36 Edg/98.0.1108.43");
    registryRequest.setRawHeader("Host", "dida365.com");
    registryRequest.setRawHeader("content-type", "application/json;charset=UTF-8");
    registryRequest.setRawHeader("accept", "application/json, text/plain, */*");
    registryRequest.setRawHeader("x-device", R"({"platform":"web","os":"macOS 10.15.7","device":"Chrome 98.0.4758.80","name":"","version":4120,"id":"6208be7339efa90473e1e352","channel":"website","campaign":"","websocket":"6208be7439efa96ca1734cfd"})");
    registryRequest.setUrl(QUrl("https://api.dida365.com/api/v2/user/signon?wc=true&remember=true"));

    for (auto header : registryRequest.rawHeaderList()) {
        qDebug() << header << registryRequest.rawHeader(header);
    }

    QJsonObject bodyJson;
    bodyJson["username"] = username;
    bodyJson["password"] = password;

    QByteArray body = QJsonDocument(bodyJson).toJson();

    QNetworkReply* reply = naManager->post(registryRequest, body);
    QEventLoop eventLoop;
    connect(naManager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
    eventLoop.exec();

    if (reply->error() != QNetworkReply::NoError) {
        qDebug() << reply->error();
        qDebug() << reply->readAll();
        reply->deleteLater();
        return false;
    }

    QJsonDocument jsonResponse = QJsonDocument::fromJson(QString(reply->readAll()).toUtf8());
    this->setCookie(QString("t=") + jsonResponse.object()["token"].toString());
    qDebug() << this->cookie;

    this->connectSocket();
    this->heartbeatTimer->start();
    reply->deleteLater();
    return true;
}

void DiDa365Tools::socketHeartBeat() {
    if (!this->socketClient->isValid()) {
        return;
    }
    qDebug() << "Sending heartbeat to websocket...";
    this->socketClient->sendTextMessage("Hello");
}
