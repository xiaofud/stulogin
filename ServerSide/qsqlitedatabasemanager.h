#ifndef QSQLITETABLEMANAGER_H
#define QSQLITETABLEMANAGER_H
#include <QString>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QObject>
class QSQLiteDataBaseManager : public QObject{
    Q_OBJECT
public:
    // some constants
    const static QString  DATA_BASE_DRIVER;

    QSQLiteDataBaseManager(const QString &dataBaseName, const QString &connectionName,
                        const QString& driverName = "QSQLITE");

    bool openDatabase();
    const QSqlDatabase getDatabase();
    bool createTable(const QString &tableName, const QString &fields);
    bool insertValues(const QString &tableName, const QString &values, const QString &fieldNames = QString());


private:
    QSqlQuery *query;
    QSqlDatabase dataBase;
    QString dataBaseName;   // include external file name
    QString connectionName;
    QString driverName;
};

#endif // QSQLITETABLEMANAGER_H
