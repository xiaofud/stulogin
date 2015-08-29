#ifndef SERVERSOCKET_H
#define SERVERSOCKET_H
#include <QTcpServer>

class ServerSocket : public QTcpServer{
public:
    Q_OBJECT
    ServerSocket(QObject *parent = 0);

protected:
    void incomingConnection(int sfd);

};

#endif // SERVERSOCKET_H
