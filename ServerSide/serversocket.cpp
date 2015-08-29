#include <QThreadPool>
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
    action->setAutoDelete(true);
    pool->start(action);
}

bool ServerSocket::startServer(){
    if (this->listen(QHostAddress::Any, 4567)){
        return true;
    }else{
        qDebug() << this->errorString();
        return false;
    }

}
