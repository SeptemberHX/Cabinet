//
// Created by SeptemberHX on 2022/2/14.
//

#ifndef CABINET_CABINETDB_H
#define CABINET_CABINETDB_H

#include <QSqlDatabase>
#include "TodoItemRecord.h"

class CabinetDB {

public:
    static CabinetDB *inst();

private:
    CabinetDB();
    QSqlDatabase m_db;
};


#endif //CABINET_CABINETDB_H
