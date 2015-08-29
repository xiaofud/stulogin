#include "serverwidget.h"
#include "ui_serverwidget.h"
#include <QHeaderView>
const QString ServerWidget::DATA_BASE_NAME = "account.db";
const QString ServerWidget::CONNECTION_NAME = "server_connection";

ServerWidget::ServerWidget(QWidget *parent) :QWidget(parent),ui(new Ui::ServerWidget){
    ui->setupUi(this);
    tableManager = new QSQLiteTableManager(DATA_BASE_NAME, CONNECTION_NAME);
    tableManager->openDatabase();
    tableManager->createTable("account", "username INT NOT NULL UNIQUE, passwd char(20)");
    database = tableManager->getDatabase();
    tableModel = new QSqlTableModel(this, *database);
    tableModel->setEditStrategy(QSqlTableModel::OnFieldChange);
    tableModel->setTable("account");
    tableModel->select();

    // setup for table view
    ui->view->setModel(tableModel);
    ui->view->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    ui->view->resizeColumnsToContents();

    connect(ui->addEntryButton, SIGNAL(clicked(bool)),
            this, SLOT(addEntry()));
}

ServerWidget::~ServerWidget(){
    delete ui;
    delete tableManager;
}

QString ServerWidget::addQuotes(const QString &str){
    return "'" + str + "'";
}

bool ServerWidget::addEntry(){
    QString username = addQuotes( ui->userLineEdit->text() );
    QString passwd = addQuotes(ui->passwdLineEdit->text());
    if(tableManager->insertValues("account", username + "," + passwd)){
        tableModel->select();
        return true;
    }else
        return false;
}
