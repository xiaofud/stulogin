#include "actiontoclient.h"
#include <QDebug>
#include <QEventLoop>
#include <QDataStream>
#include <QThread>

ActionToClient::ActionToClient(int sfd): socketDescriptor(sfd){
//! must, qint16 won't be set to zero automatically!!!!!!!!!!!!!!!!!!
//    qDebug() << totalSize << " , " << bytesRead;
    totalSize = 0;
    bytesRead = 0;
    client = new QTcpSocket;
    if (!client->setSocketDescriptor(socketDescriptor)){
        qDebug() << client->errorString();
        return;
    }
}


void ActionToClient::run(){
    qDebug() << "handling a client";
    qDebug() << "ActionToClient::run runs in " << QThread::currentThread();
//    client = new QTcpSocket;
//    client->moveToThread(QThread::currentThread());
//    qDebug() << "Moved the client to another thread " << client->thread();
//    if (!client->setSocketDescriptor(socketDescriptor)){
//        qDebug() << client->errorString();
//        return;
//    }

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
    }else if (clientRequest.size() == 2){   // getinfo
        qDebug() << "needAccount emitted in QThread " << QThread::currentThread();
        emit needAccount(clientRequest.at(1));      // to get account from database
    }
//    client->close();    // all the work is done
}

bool ActionToClient::sendAccount(){
    qDebug() << "Sending account to client";
    return true;
}

bool ActionToClient::sendAccount(ExAccount account){
    account.toNumFields();
    account.toStrFileds();
    qDebug() << "start send Account " << account.username << " at QThread(" << QThread::currentThread() << ")";
    buffer.resize(0);
    QDataStream out(&buffer, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_8);
    out << (qint16) 0;
    out << account.strFields << account.numberFields;
    out.device()->seek(0);
    out << (qint16) buffer.size();
    qDebug() << "client is at QThread(" << QThread::currentThread() << ")";
    qDebug() << "client belongs to QThread " << client->thread();
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
    emit accountPushed(username, passwd);
    return true;
}

void ActionToClient::clientDisconnected(){
    qDebug() << "The client disconnected!";
    emit jobFinished();     // also need to end the thread
}
