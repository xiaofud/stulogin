#include "serverwidget.h"
#include "ui_serverwidget.h"
#include <QHeaderView>
const QString ServerWidget::DATA_BASE_NAME = "account.db";
const QString ServerWidget::CONNECTION_NAME = "server_connection";

ServerWidget::ServerWidget(QWidget *parent) :QWidget(parent),ui(new Ui::ServerWidget){
    ui->setupUi(this);
    tableManager = new QSQLiteDataBaseManager(DATA_BASE_NAME, CONNECTION_NAME);
    tableManager->openDatabase();
    tableManager->createTable("account", "username INT NOT NULL UNIQUE, passwd char(20)");
    database = tableManager->getDatabase();
    tableModel = new QSqlTableModel(this, database);
    tableModel->setEditStrategy(QSqlTableModel::OnFieldChange);
    tableModel->setTable("account");
    tableModel->select();

    // setup for table view
    ui->view->setModel(tableModel);
    ui->view->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    ui->view->resizeColumnsToContents();

    connect(ui->addEntryButton, SIGNAL(clicked(bool)),
            this, SLOT(addEntryFromLineEdit()));

    server = new ServerSocket(this);
    connect(server, SIGNAL(accountPushed(QString,QString)),
            this, SLOT(addEntry(QString,QString)));
    server->startServer();

}

ServerWidget::~ServerWidget(){
    delete ui;
    delete tableManager;
}

QString ServerWidget::addQuotes(const QString &str){
    return "'" + str + "'";
}

bool ServerWidget::addEntry(const QString &username, const QString &passwd){
    if(tableManager->insertValues("account", addQuotes( username ) + "," + addQuotes( passwd ))){
        tableModel->select();
        return true;
    }else
        return false;
}

bool ServerWidget::addEntryFromLineEdit(){
    QString username =  ui->userLineEdit->text();
    QString passwd = ui->passwdLineEdit->text();
    return addEntry(username, passwd);
}
