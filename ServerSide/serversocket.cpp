﻿#include <QThreadPool>
#include <QDebug>
#include "serversocket.h"
#include "actiontoclient.h"

ServerSocket::ServerSocket(QObject *parent) : QTcpServer(parent){
    pool = new QThreadPool(this);
    pool->setMaxThreadCount(10);
}

ServerSocket::~ServerSocket(){
    delete pool;
}


void ServerSocket::incomingConnection(int sfd){
    // use threadpool to do tasks
    ActionToClient *action = new ActionToClient(sfd);
    connect(action, SIGNAL(accountPushed(QString,QString)),
            this, SLOT(emitAccount(QString,QString)));
    action->setAutoDelete(true);
    pool->start(action);
    qDebug() << "a client 's coming!";
}

bool ServerSocket::startServer(){
    if (this->listen(QHostAddress::Any, 4567)){
        return true;
    }else{
        qDebug() << this->errorString();
        return false;
    }

}

void ServerSocket::emitAccount(QString user, QString passwd){
    emit accountPushed(user, passwd);
}
