#ifndef SERVERSOCKET_H
#define SERVERSOCKET_H
#include <QTcpServer>

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
    void accountPushed(QString user, QString passwd);   // client sent the account

protected:
    void incomingConnection(int sfd);

private:
    QThreadPool *pool;
};

#endif // SERVERSOCKET_H
