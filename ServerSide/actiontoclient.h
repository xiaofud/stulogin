#ifndef ACTIONTOCLIENT_H
#define ACTIONTOCLIENT_H
#include <QRunnable>
#include <QTcpSocket>
#include <QObject>
#include <QByteArray>
#include <QStringList>
/** this class handles the client's request
 * 1.pull data from the server.
 * 2.push data to the server
 * both based on QDataStream to transfer data
 *
 * clientMessage Format:
 * commandType: 1.pull 2.push
 * qint16, pull(use QStringList to save the data)
 * qint16, push, "username, password"
 *
 * response Format:
 * for pull:
 * qint16, bool(indicate whether there is suitable account), "username, password"
 * for push:
 * qint16, bool(indicate if the insert action succeed)
 *
 * eg.
 * request:
 * size, push, "14xfdeng,xxxx"
 *
 * response:
 * size, true, "14xxxx,xxxxx"
 **/

class ActionToClient : public QObject, public QRunnable{
    Q_OBJECT
public:
    ActionToClient(int sfd);
    ~ActionToClient();

public slots:
    void readFromClient();
    void reactToClient();
    void clientDisconnected();
signals:
    void jobFinished();    // quit the local event loop
    void finishedRead();
    void accountPushed(QString user, QString passwd);   // client sent the account

protected:
    void run();
private:
    bool sendAccount();     // send account to client
    bool addAccountToDataBase();
//    void startup();     // create the TcpSocket and connect some signal and slots
    int socketDescriptor;
    QByteArray data;
    QTcpSocket *client;
    QStringList clientRequest;
    qint16 totalSize;
    qint16 bytesRead;

};

#endif // ACTIONTOCLIENT_H
