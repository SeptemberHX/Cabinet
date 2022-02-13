//
// Created by SeptemberHX on 2022/2/14.
//

#include "CabinetSettings.h"
#include <QSettings>

CabinetSettings *CabinetSettings::inst() {
    static CabinetSettings cabinetSettings;
    return &cabinetSettings;
}

CabinetSettings::CabinetSettings() {
    QSettings settings(QSettings::IniFormat, QSettings::UserScope, "Cabinet", "settings");
    qDebug() << settings.fileName();

    this->dida365UserName = settings.value("todo/dida365-username", "").toString();
    this->dida365Password = settings.value("todo/dida365-password", "").toString();
}

const QString &CabinetSettings::getDida365UserName() const {
    return dida365UserName;
}

const QString &CabinetSettings::getDida365Password() const {
    return dida365Password;
}
