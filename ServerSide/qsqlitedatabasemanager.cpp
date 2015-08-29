#include <QDebug>
#include <QSqlError>
#include "qsqlitedatabasemanager.h"

const QString QSQLiteDataBaseManager::DATA_BASE_DRIVER = "QSQLITE";

QSQLiteDataBaseManager::QSQLiteDataBaseManager
    (const QString &dbName, const QString &connName, const QString &driver_Name)
        : dataBaseName(dbName), connectionName(connName), driverName(driver_Name)
{

}


// open the database for use
bool QSQLiteDataBaseManager::openDatabase(){
    dataBase = QSqlDatabase::addDatabase(driverName, connectionName);
    dataBase.setDatabaseName(dataBaseName);
    if (dataBase.open()){
        query = new QSqlQuery(dataBase);
        return true;
    }else{
        qDebug() << dataBase.lastError().text();
        return false;
    }
}

const QSqlDatabase QSQLiteDataBaseManager::getDatabase(){
    return dataBase;
}


// usage:
// eg. createTable("person", "id INT PRIMARY KEY UNIQUE, name char(20)")
bool QSQLiteDataBaseManager::createTable(const QString &tableName, const QString &fields){
    QString createStatement = "CREATE TABLE " + tableName + " (" + fields + ")";
    if (query == 0)
        return false;
    if (query->exec(createStatement)){
        return true;
    }else{
        qDebug() << query->lastError().text();
        return false;
    }
}



bool QSQLiteDataBaseManager::insertValues(const QString &tableName, const QString &values, const QString &fieldNames){
    if (query == 0)
        return false;
    QString insertStatement;
    if (fieldNames == "")
        insertStatement =
                "INSERT INTO " + tableName + " VALUES(" + values + ")";
    else
        insertStatement =
                "INSERT INTO " + tableName + " (" + fieldNames + ")" + " VALUES(" +values + ")";
    // execute the query
    if (query->exec(insertStatement)){
        return true;
    }else{
        qDebug() << query->lastError().text();
        return false;
    }
}













