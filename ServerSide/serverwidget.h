#ifndef SERVERWIDGET_H
#define SERVERWIDGET_H
#include "qsqlitedatabasemanager.h"
#include <QWidget>
#include <QSqlTableModel>

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
    bool addEntry();

private:
    QString addQuotes(const QString &str);
    Ui::ServerWidget *ui;
    QSQLiteDataBaseManager *tableManager;
    const QSqlDatabase *database;
    QSqlTableModel *tableModel;
};

#endif // SERVERWIDGET_H
