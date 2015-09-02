#ifndef SERVERSOCKET_H
#define SERVERSOCKET_H
#include <QTcpServer>
#include <QHostAddress>
#include "exaccount.h"
class QThreadPool;

class ServerSocket : public QTcpServer{
    Q_OBJECT
public:
    ServerSocket(QObject *parent = 0);
    ~ServerSocket();
    bool startServer();

public slots:
    void emitAccount(QString user, QString passwd);

signals:
    void accountPushed(const ExAccount& account);   // client sent the account

protected:
    void incomingConnection(int sfd);

private:
    static QHostAddress ADDRESS;
    static int PORT;
    QThreadPool *pool;
};

#endif // SERVERSOCKET_H
