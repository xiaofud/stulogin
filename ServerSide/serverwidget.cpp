#include "serverwidget.h"
#include "ui_serverwidget.h"
#include <QHeaderView>
#include <QSqlRecord>

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
QString ServerWidget::COLUMNS = "username VARCHAR(20) UNIQUE, password VARCHAR(20), start_time REAL, end_time REAL, left_at_most REAL, "
                                "share_rate REAL, total_share REAL, share_this_time REAL, total_fetch REAL, fetch_this_time REAL, "
                                "credit REAL, valid REAL";
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
    connect(ui->updateButton, SIGNAL(clicked(bool)),
            this, SLOT(updataEntryFromButton()));

    server = new ServerSocket(this);
    server->setWidget(this);
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

bool ServerWidget::addEntry(ExAccount accout){

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


bool ServerWidget::updateEntry(const ExAccount &account){
    // use TableModel to delete the row, and insert the updated row
    QSqlTableModel model(this, database);
    model.setTable(TABLENAME);
    model.setFilter("username == " + addQuotes(account.username));
    model.select();
    if (model.rowCount() == 1){
        if (model.removeRow(0) && model.submitAll() && addEntry(account))
            return true;
        else{
            qDebug() << "In ServerWidget::updateEntry, Failed to update";
            return false;
        }

    }else{
        qDebug() << "In ServerWidget::updateEntry, the rowCount is " << model.rowCount();
        return true;
    }
}

bool ServerWidget::updataEntryFromButton(){
    QString username =  ui->userLineEdit->text();
    QString passwd = ui->passwdLineEdit->text();
    ExAccount new_account(username, passwd);
//    ExAccount tmp;
//    tmp.fromStrFields(new_account.strFields);
//    tmp.fromNumFields(new_account.numberFields);
//    qDebug() << tmp.username;
//    qDebug() << tmp.password;
    return updateEntry(new_account);
}

ExAccount ServerWidget::selectUser(const QString &name){
    QSqlTableModel model(this, database);
    model.setTable(TABLENAME);
    model.setFilter("username == " + addQuotes(name));
    model.select();
    if (model.rowCount() == 0){
        qDebug() << "want to select " + name + " but not found";
        emit selectedAccount(ExAccount());
        return ExAccount();
    }
    QSqlRecord user = model.record(0);
    ExAccount account;
//    "username, password, start_time, end_time, left_at_most, share_rate, total_share, share_this_time, total_fetch, "
//                                   "fetch_this_time, credit, valid";
    account.username = name;
    account.totalShare = user.value("total_share").toDouble();
    account.totalFetchedFlow = user.value("total_fetch").toDouble();
    account.shareRate = user.value("share_rate").toDouble();
    account.shareFlow = user.value("share_this_time").toDouble();
    account.fetchedFlow = user.value("fetch_this_time").toDouble();
    account.credit = user.value("credit").toDouble();
    account.toStrFileds();
    account.toNumFields();
//    qDebug() << "the selected user is " + account.username << "\ncredit " << account.credit;
    emit selectedAccount(account);
    return account;
}
















