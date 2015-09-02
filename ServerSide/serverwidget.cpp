#include "serverwidget.h"
#include "ui_serverwidget.h"
#include <QHeaderView>
const QString ServerWidget::DATA_BASE_NAME = "account.db";
const QString ServerWidget::CONNECTION_NAME = "server_connection";

//QString username;
//QString password;
//QString startShare;     // the start point when the user's willing to share
//QString endShare;       // the end point when the user refuse to share
//double leftAtMost;      // because left flow can't be more than this
//double shareRate;       // the share rate determines whether the user can still fetch shared flow
//double totalShare;      // record of the amount flow the user has shared
//double shareFlow;       // amount of flow the user want to share during a specific time
//double totolFetchedFlow;    // the amount of total flow the user has fetched so far
//double fetchedFlow;         // fetched how much this time
//double credit;              // like login as others but force to close the application
//bool valid;                 // is the password (still) match the username

QString ServerWidget::TABLENAME = "ACCOUNT";
QString ServerWidget::COLUMNS = "username VARCHAR(20) UNIQUE, password VARCHAR(20), start_time INTEGER, end_time INTEGER, left_at_most INTEGER, "
                                "share_rate REAL, total_share INTEGER, share_this_time INTEGER, total_fetch INTEGER, fetch_this_time INTEGER, "
                                "credit REAL, valid INT";
QString ServerWidget::FIELDS = "username, password, start_time, end_time, left_at_most, share_rate, total_share, share_this_time, total_fetch, "
                               "fetch_this_time, credit, valid";


ServerWidget::ServerWidget(QWidget *parent) :QWidget(parent),ui(new Ui::ServerWidget){
    ui->setupUi(this);
    tableManager = new QSQLiteDataBaseManager(DATA_BASE_NAME, CONNECTION_NAME);
    tableManager->openDatabase();
    tableManager->createTable(TABLENAME, COLUMNS);
    database = tableManager->getDatabase();
    tableModel = new QSqlTableModel(this, database);
    tableModel->setEditStrategy(QSqlTableModel::OnFieldChange);
    tableModel->setTable(TABLENAME);
    tableModel->select();

    // setup for table view
    ui->view->setModel(tableModel);
    ui->view->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    ui->view->resizeColumnsToContents();

    connect(ui->addEntryButton, SIGNAL(clicked(bool)),
            this, SLOT(addEntryFromLineEdit()));

    server = new ServerSocket(this);
    connect(server, SIGNAL(accountPushed(ExAccount)),
            this, SLOT(addEntry(ExAccount)));
    server->startServer();

}

ServerWidget::~ServerWidget(){
    delete ui;
    delete tableManager;
}

QString ServerWidget::addQuotes(const QString &str){
    return "'" + str + "'";
}

bool ServerWidget::addEntry(const ExAccount &accout){

    if(tableManager->insertValues(TABLENAME, accout.toInsertStr(), FIELDS)){
        tableModel->select();
        return true;
    }else
        return false;
}

bool ServerWidget::addEntryFromLineEdit(){
    QString username =  ui->userLineEdit->text();
    QString passwd = ui->passwdLineEdit->text();
    ExAccount new_account(username, passwd);
    return addEntry(new_account);
}
