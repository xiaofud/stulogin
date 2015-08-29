#include <QDebug>
#include "clientdialog.h"
#include "ui_clientdialog.h"

ClientDialog::ClientDialog(QWidget *parent) :QDialog(parent),ui(new Ui::ClientDialog){
    ui->setupUi(this);
    clientSocket = new QTcpSocket(this);
    ui->pushUserButton->setEnabled(false);
    ui->getUserButton->setEnabled(false);

    connect(clientSocket, SIGNAL(connected()),
            this, SLOT(enableButtons()));
    clientSocket->connectToHost("127.0.0.1", 4567);

    connect(ui->pushUserButton, SIGNAL(clicked(bool)),
            this, SLOT(pushAccount()));
    connect(ui->getUserButton, SIGNAL(clicked(bool)),
            this, SLOT(pullAccount()));

}

ClientDialog::~ClientDialog(){
    delete ui;
}

void ClientDialog::pullAccount(){
    strList.clear();
    QDataStream out(&buffer, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_8);
    out << (qint16) 0;
    strList.append("pull");
    out << strList;
    out.device()->seek(0);
    out << (qint16)buffer.size();
    clientSocket->write(buffer);
    clientSocket->waitForBytesWritten();
    qDebug() << "the data has been written";
    buffer.resize(0);   // don't forget to do this
//    clientSocket->close();
}

void ClientDialog::pushAccount(){
    strList.clear();
    QDataStream out(&buffer, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_8);
    out << (qint16) 0;

    strList << "push" << ui->userLineEdit->text() << ui->passwdLineEdit->text();

    out << strList;
    out.device()->seek(0);
    out << (qint16)buffer.size();
    clientSocket->write(buffer);
    clientSocket->waitForBytesWritten();
    qDebug() << "【push】the data has been written";
    buffer.resize(0);
}

void ClientDialog::enableButtons(){
    qDebug() << "connected to the server!";
    ui->pushUserButton->setEnabled(true);
    ui->getUserButton->setEnabled(true);
}
