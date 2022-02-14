//
// Created by SeptemberHX on 2022/2/14.
//

#include "CabinetDB.h"
#include <QSqlQuery>

CabinetDB *CabinetDB::inst() {
    static CabinetDB db;
    return &db;
}

CabinetDB::CabinetDB() {
    this->m_db = QSqlDatabase::addDatabase("QSQLITE");
    this->m_db.setDatabaseName("/Users/septemberhx/.config/Cabinet/cabinet.db");

    this->m_db.open();

    QSqlQuery query(this->m_db);
    query.exec("create table if not exists TodoRecord (id INT UNSIGNED AUTO_INCREMENT NOT NULL PRIMARY KEY, "
               "itemId VARCHAR(255) UNICODE, fromTime TIMESTAMP, toTime TIMESTAMP) ENGINE=InnoDB");
}
