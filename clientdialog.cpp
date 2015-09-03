#include <QDebug>
#include "clientdialog.h"
#include "ui_clientdialog.h"
#include <QDate>
#include <QTime>
#include <QMessageBox>

ClientDialog::ClientDialog(QWidget *parent) :QDialog(parent),ui(new Ui::ClientDialog), isConnected(false){
    ui->setupUi(this);
    clientSocket = new QTcpSocket(this);

    connect(clientSocket, SIGNAL(connected()),
            this, SLOT(handleConnection()));

    connect(clientSocket, SIGNAL(disconnected()),
            this, SLOT(handleDisconnection()));

    connect(clientSocket, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(displayError(QAbstractSocket::SocketError)));

    connect(clientSocket, SIGNAL(readyRead()),
            this, SLOT(readAccount()));

    connect(this, SIGNAL(accountRead()),
            this, SLOT(displayInfo()));

    connect(ui->pushUserButton, SIGNAL(clicked(bool)),
            this, SLOT(pushAccount()));
    connect(ui->getUserButton, SIGNAL(clicked(bool)),
            this, SLOT(pullAccount()));


    // set proper date
    ui->fromDateTimeEdit->setDate(QDate::currentDate());
    ui->fromDateTimeEdit->setTime(QTime::currentTime());
    ui->toDateTimeEdit->setDate(QDate::currentDate().addDays(1));
    ui->toDateTimeEdit->setTime(QTime(24, 0, 0));

}

bool ClientDialog::checkDataValid(){
    long diff = ui->fromDateTimeEdit->dateTime().toTime_t() - ui->toDateTimeEdit->dateTime().toTime_t();
    if (diff > 0 || qAbs(diff) < 30 * 60){
        QMessageBox::warning(this, trUtf8("时间设置错误"), trUtf8("请保证起始时间先于结束时间半个钟以上: )"));
        return false;
    }
    return true;
}


ClientDialog::~ClientDialog(){
    delete ui;
}

void ClientDialog::displayError(QAbstractSocket::SocketError err){
    err = err;
    qDebug() << clientSocket->errorString();
}

bool ClientDialog::connectToHost(const QString &addr, int port){
    clientSocket->connectToHost(addr, port);
    return clientSocket->waitForConnected(1000);
}

bool ClientDialog::sendData(){
    buffer.resize(0);   // don't forget to do this
    if (!isConnected){
        if (!connectToHost(ui->addressLineEdit->text(), ui->portLineEdit->text().toInt()))
            return false;
    }
    QDataStream out(&buffer, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_8);
    out << (qint16) 0;
    out << strList;
//    qDebug() << strList.size();
    out.device()->seek(0);
    out << (qint16)buffer.size();
    qDebug() << "total size is " << buffer.size();
    clientSocket->write(buffer);
    if (clientSocket->waitForBytesWritten(1000)){
        qDebug() << "the data has been written";
        return true;
    }else{
        qDebug() << "failed to send the data";
        return false;
    }

}

void ClientDialog::handleDisconnection(){
    isConnected = false;
}

bool ClientDialog::pullAccount(){
    strList.clear();
    strList.append("pull");
    return sendData();
}

bool ClientDialog::pushAccount(){
    if (!checkDataValid()){
        return false;
    }
    strList.clear();
    strList << "push" << ui->userLineEdit->text() << ui->passwdLineEdit->text() << QString::number(ui->fromDateTimeEdit->dateTime().toTime_t())
            << QString::number(ui->toDateTimeEdit->dateTime().toTime_t()) << QString::number(ui->shareSpinBox->value());
    if (sendData()){
        setWindowTitle(trUtf8("分享成功"));
        return true;
    }else{
        setWindowTitle(trUtf8("分享失败"));
        return false;
    }
}

void ClientDialog::handleConnection(){
    isConnected = true;
    qDebug() << "connected to the server!";
}

void ClientDialog::setCurAccount(bool connected, const QString &user, double used, double total, double left){
    if (!connected){
        cur_account.username = "";
        cur_account.password = "";
        setWindowTitle("Not Connected yet!");
        return;
    }
    bool new_account = false;
    if (cur_account.username != user){
        qDebug() << user << "|" << cur_account.username;
        new_account = true;
    }
    cur_account.username = user;
    cur_account.used = used;
    cur_account.total = total;
    cur_account.left = left;
    totalSize = 0;      // prepare to read the account
    bytesRead = 0;
//    setWindowTitle(user);
    if (new_account)
        getAccount(user);

}

void ClientDialog::getAccount(const QString &username){
    if (!this->isVisible()){    // don't connect to server when the form is not visible
        return;
    }

    strList.clear();
    strList << "getinfo" << username;
    if (!sendData()){
        qDebug() << "ClientDialog::getAccount: Failed to senddata to the server";
    }
}

void ClientDialog::readAccount(){
    QDataStream in(clientSocket);
    in.setVersion(QDataStream::Qt_4_8);
    if (totalSize == 0){
        if (clientSocket->bytesAvailable() < sizeof(qint16))
            return;
        in >> totalSize;
        bytesRead += sizeof(qint16);
    }

    if (bytesRead + clientSocket->bytesAvailable() == totalSize){
        in >> strFields;
        in >> numFields;
        qDebug() << strFields.at(0);
        account_info.fromStrFields(strFields);
        account_info.fromNumFields(numFields);

        emit accountRead();     // the account is read from the server
    }

}

void ClientDialog::displayInfo(){
    if (account_info.username.isEmpty()){
        setWindowTitle(tr("No information about ") + cur_account.username);
        return;
    }
    ui->usernameLabel->setText(trUtf8("用户名:") + account_info.username );
    ui->shareRateLabel->setText(trUtf8("分享率:") + QString::number(account_info.shareRate));
    ui->totalFetchLabel->setText(trUtf8("总获取:") + QString::number( account_info.totalFetchedFlow) );
    ui->totalShareLabel->setText(trUtf8("总分享:") + QString::number( account_info.totalShare) );

}














