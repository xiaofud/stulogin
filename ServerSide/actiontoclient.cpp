#include "actiontoclient.h"
#include <QDebug>
#include <QEventLoop>
#include <QDataStream>
//#include <QThread>

ActionToClient::ActionToClient(int sfd): socketDescriptor(sfd){
//! must, qint16 won't be set to zero automatically!!!!!!!!!!!!!!!!!!
//    qDebug() << totalSize << " , " << bytesRead;
    totalSize = 0;
    bytesRead = 0;
    client = new QTcpSocket;
    if (!client->setSocketDescriptor(socketDescriptor)){
        qDebug() << client->errorString();
        valid = false;
    }else{
        valid = true;
    }
}


void ActionToClient::run(){
    qDebug() << "handling a client";

    connect(client, SIGNAL(readyRead()),
            this, SLOT(readFromClient()), Qt::QueuedConnection);
    connect(this, SIGNAL(finishedRead()),
            this, SLOT(reactToClient()),  Qt::QueuedConnection);
    connect(client, SIGNAL(disconnected()),
            this, SLOT(clientDisconnected()), Qt::QueuedConnection);

    QEventLoop eventloop;   // because the QRunnable object live in another thread than the socket
                            // so an eventloop is needed for signal and slot mechanism
    connect(client, SIGNAL(readyRead()),
            this, SLOT(readFromClient()), Qt::QueuedConnection);
    connect(this, SIGNAL(jobFinished()),
            &eventloop, SLOT(quit()), Qt::QueuedConnection);
    eventloop.exec();
}

ActionToClient::~ActionToClient(){
    delete client;
}

void ActionToClient::readFromClient(){
    QDataStream in(client);
    in.setVersion(QDataStream::Qt_4_8);
    // get the total size this connection need to read
    if (totalSize == 0 ){
        if (client->bytesAvailable() >= sizeof(qint16)){
            in >> totalSize;
            qDebug() << "totalSize is " << totalSize;
            bytesRead += sizeof(qint16);
        }else
            return;     // means the size info has not been complete yet
    }

    if (bytesRead + client->bytesAvailable() == totalSize){     // all data is already
        in >> clientRequest;
        emit finishedRead();
        bytesRead = totalSize = 0;
    }
    return; // wait for more data coming
}

void ActionToClient::reactToClient(){
    qDebug() << clientRequest.size();
    if (clientRequest.size() == 0){
        emit jobFinished();
        return;
    }

    if (clientRequest.at(0) == "pull"){     // pull
        sendAccount();
        emit jobFinished();
    }else if (clientRequest.at(0) == "push"){    // push
        addAccountToDataBase();
    }else if (clientRequest.at(0) == "getinfo"){   // getinfo
        emit needAccount(clientRequest.at(1));      // to get account from database
    }
}

bool ActionToClient::sendAccount(){
    qDebug() << "Sending account to client";
    return true;
}

bool ActionToClient::sendAccount(ExAccount account){
    account.toNumFields();
    account.toStrFileds();
    buffer.resize(0);
    QDataStream out(&buffer, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_8);
    out << (qint16) 0;
    out << account.strFields << account.numberFields;
    out.device()->seek(0);
    out << (qint16) buffer.size();
    client->write(buffer);
    if (client->waitForBytesWritten(1000)){
        qDebug() << "send account to user successfully";
        client->disconnectFromHost();
        return true;
    }else{
        qDebug() << "Failed to send account";
        client->disconnectFromHost();
        return false;
    }

}

bool ActionToClient::addAccountToDataBase(){
    QString username = clientRequest[1];
    QString passwd = clientRequest[2];
    qDebug() << "adding " + username + "," + passwd + " to database!";
    ExAccount account(username, passwd);
    account.startShare = clientRequest[3].toDouble();
    account.endShare = clientRequest[4].toDouble();
    account.shareFlow = clientRequest[5].toDouble();
    account.update();
    emit accountPushed(account);
    emit jobFinished();
    return true;
}

void ActionToClient::clientDisconnected(){
    qDebug() << "The client disconnected!";
    emit jobFinished();     // also need to end the thread
}
