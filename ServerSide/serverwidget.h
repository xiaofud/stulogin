#ifndef SERVERWIDGET_H
#define SERVERWIDGET_H
#include <QWidget>
#include <QSqlTableModel>
#include "exaccount.h"
#include "qsqlitedatabasemanager.h"
#include "serversocket.h"

namespace Ui {
class ServerWidget;
}

class ServerWidget : public QWidget{
    Q_OBJECT

public:
    const static QString DATA_BASE_NAME;
    const static QString CONNECTION_NAME;

    explicit ServerWidget(QWidget *parent = 0);
    ~ServerWidget();

public slots:
    bool addEntryFromLineEdit();
    bool addEntry(ExAccount accout);
    bool updataEntryFromButton();
    bool updateEntry(const ExAccount &account);
    ExAccount selectUser(const QString &name);

signals:
    void selectedAccount(ExAccount account);

private:
    Ui::ServerWidget *ui;
    static QString TABLENAME;
    static QString COLUMNS;
    static QString FIELDS;
    QString addQuotes(const QString &str);
    QSQLiteDataBaseManager *tableManager;
    QSqlDatabase database;
    QSqlTableModel *tableModel;
    ServerSocket *server;
};

#endif // SERVERWIDGET_H
