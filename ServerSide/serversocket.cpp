#include "serversocket.h"

ServerSocket::ServerSocket(QObject *parent) : QTcpServer(parent){

}


void ServerSocket::incomingConnection(int sfd){
    // use threadpool to do tasks
}
