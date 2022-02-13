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
#include <QWebSocket>
#include <QTimer>


class DiDa365Tools : public QObject{
    Q_OBJECT

public:
    explicit DiDa365Tools(QObject *parent = nullptr);

    void getTodoItems(int status,
                      QList<DiDaTask> &tasks,
                      QList<DiDaProject> &projects,
                      QList<DiDaGroup> &groups,
                      QList<DiDaTag> &tags);

    void setCookie(const QString &cookie);

    bool login(const QString &username, const QString &password);

signals:
    void needSync(qint64 data);

private slots:
    void socketMsgReceived(const QString &msg);
    void socketHeartBeat();

private:
    void connectSocket();
    bool registerPushToken(const QString &token);
    QJsonDocument sendDiDaRequest(QString strUrl);

private:
    QString cookie;
    QNetworkAccessManager *naManager;

    QWebSocket *socketClient;
    bool firstSocketMsg;
    QTimer *heartbeatTimer;
};


#endif //CABINET_DIDA365TOOLS_H
