//
// Created by SeptemberHX on 2022/2/14.
//

#ifndef CABINET_CABINETSETTINGS_H
#define CABINET_CABINETCONFIG_H

#include <QString>


class CabinetSettings {

public:
    static CabinetSettings* inst();

    const QString &getDida365UserName() const;

    const QString &getDida365Password() const;

private:
    CabinetSettings();

    QString dida365UserName;
    QString dida365Password;
};


#endif //CABINET_CABINETSETTINGS_H
