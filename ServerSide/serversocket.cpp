#include <QThreadPool>
#include <QDebug>
#include "serversocket.h"
#include "actiontoclient.h"
#include "serverwidget.h"



int ServerSocket::PORT = 4567;
QHostAddress ServerSocket::ADDRESS = QHostAddress::Any;

ServerSocket::ServerSocket(QObject *parent) :  QTcpServer(parent){
    pool = new QThreadPool(this);
    pool->setMaxThreadCount(10);
}

ServerSocket::~ServerSocket(){
    delete pool;
}


void ServerSocket::incomingConnection(int sfd){
    // use threadpool to do tasks
    ActionToClient *action = new ActionToClient(sfd);
    // notice that widget and action belong to the same thread. But action's run() method runs in a different thread, so take care of this.
    connect(action, SIGNAL(accountPushed(ExAccount)),
            this, SLOT(emitAccount(ExAccount)));
    connect(action, SIGNAL(needAccount(QString)),
            widget, SLOT(selectUser(QString)));
    connect(widget, SIGNAL(selectedAccount(ExAccount)),
            action, SLOT(sendAccount(ExAccount)));
    action->setAutoDelete(true);
    pool->start(action);
    qDebug() << "a client 's coming!";
}

bool ServerSocket::startServer(){
    if (this->listen(ADDRESS, PORT)){
        return true;
    }else{
        qDebug() << this->errorString();
        return false;
    }

}

void ServerSocket::emitAccount(ExAccount account){
    emit accountPushed(account);
}

void ServerSocket::setWidget(ServerWidget *widget){
    this->widget = widget;
}
