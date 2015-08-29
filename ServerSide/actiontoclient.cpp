#include "actiontoclient.h"
#include <QDebug>
#include <QEventLoop>
#include <QDataStream>

ActionToClient::ActionToClient(int sfd): socketDescriptor(sfd){
//! must, qint16 won't be set to zero automatically!!!!!!!!!!!!!!!!!!
    qDebug() << totalSize << " , " << bytesRead;
    totalSize = 0;
    bytesRead = 0;
}


void ActionToClient::run(){
    qDebug() << "handling a client";
    client = new QTcpSocket;
    if (!client->setSocketDescriptor(socketDescriptor)){
        qDebug() << client->errorString();
        return;
    }

    connect(client, SIGNAL(readyRead()),
            this, SLOT(readFromClient()));
    connect(this, SIGNAL(finishedRead()),
            this, SLOT(reactToClient()));
    connect(client, SIGNAL(disconnected()),
            this, SLOT(clientDisconnected()));

    QEventLoop eventloop;   // because the QRunnable object live in another thread than the socket
                            // so an eventloop is needed for signal and slot mechanism
    connect(client, SIGNAL(readyRead()),
            this, SLOT(readFromClient()));
    connect(this, SIGNAL(jobFinished()),
            &eventloop, SLOT(quit()));
    eventloop.exec();
}

ActionToClient::~ActionToClient(){
    delete client;
}

void ActionToClient::readFromClient(){
//    qDebug() << "starting reading data totalSize =" << totalSize << " bytesRead = " + bytesRead;
    QDataStream in(client);
    in.setVersion(QDataStream::Qt_4_8);
    // get the total size this connection need to read
    if (totalSize == 0 ){
        if (client->bytesAvailable() >= sizeof(qint16)){
            in >> totalSize;
//            qDebug() << "the total size is " << totalSize;
            bytesRead += sizeof(qint16);
        }else
            return;     // means the size info has not been complete yet
    }

    if (bytesRead + client->bytesAvailable() == totalSize){     // all data is already
        in >> clientRequest;
        emit finishedRead();
        bytesRead = totalSize = 0;
        return;
    }else
        return;     // wait for more data coming

}

void ActionToClient::reactToClient(){
    if (clientRequest.size() == 1){     // pull
        sendAccount();
    }else if (clientRequest.size() == 3){    // push
        addAccountToDataBase();
    }
    client->close();    // all the work is done
}

bool ActionToClient::sendAccount(){
    qDebug() << "Sending account to client";
    return true;
}

bool ActionToClient::addAccountToDataBase(){
    QString username = clientRequest[1];
    QString passwd = clientRequest[2];
    qDebug() << "adding" + username + "," + passwd + " to database!";
    return true;
}

void ActionToClient::clientDisconnected(){
    qDebug() << "The client disconnected!";
    emit jobFinished();     // also need to end the thread
}
