#include <QDebug>
#include "clientdialog.h"
#include "ui_clientdialog.h"

ClientDialog::ClientDialog(QWidget *parent) :QDialog(parent),ui(new Ui::ClientDialog), isConnected(false){
    ui->setupUi(this);
    clientSocket = new QTcpSocket(this);

    connect(clientSocket, SIGNAL(connected()),
            this, SLOT(handleConnection()));

    connect(clientSocket, SIGNAL(disconnected()),
            this, SLOT(handleDisconnection()));

    connect(clientSocket, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(displayError(QAbstractSocket::SocketError)));

    connect(ui->pushUserButton, SIGNAL(clicked(bool)),
            this, SLOT(pushAccount()));
    connect(ui->getUserButton, SIGNAL(clicked(bool)),
            this, SLOT(pullAccount()));
}

ClientDialog::~ClientDialog(){
    delete ui;
}

void ClientDialog::displayError(QAbstractSocket::SocketError err){
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
    out.device()->seek(0);
    out << (qint16)buffer.size();
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

void ClientDialog::pullAccount(){
    strList.clear();
    strList.append("pull");
    sendData();
}

void ClientDialog::pushAccount(){
    strList.clear();
    strList << "push" << ui->userLineEdit->text() << ui->passwdLineEdit->text();
    sendData();
}

void ClientDialog::handleConnection(){
    isConnected = true;
    qDebug() << "connected to the server!";
}


