#ifndef CLIENTDIALOG_H
#define CLIENTDIALOG_H
#include <QDataStream>
#include <QTcpSocket>
#include <QDialog>
#include <QByteArray>
#include <QStringList>
#include <QList>
#include "exaccount.h"

namespace Ui {
class ClientDialog;
}

class ClientDialog : public QDialog{
    Q_OBJECT

public:
    explicit ClientDialog(QWidget *parent = 0);
    ~ClientDialog();


public slots:
    bool pullAccount();
    bool pushAccount();
    void handleConnection();
    void handleDisconnection();
    bool connectToHost(const QString &addr, int port);
    bool sendData();
    void readAccount();     // read account from the server
    void getAccount(const QString &username);   // try to get user info from the server
    void displayError(QAbstractSocket::SocketError err);
    void displayInfo();
    void setCurAccount(bool connected,const QString &user, double used, double total, double left);
    bool checkDataValid();

signals:
    void accountRead();     // emited when the account information is transferred to the client

private:

    Ui::ClientDialog *ui;
    bool isConnected;
    QTcpSocket *clientSocket;
    QStringList strList;
    QByteArray buffer;
    ExAccount cur_account;
    ExAccount account_info;

    qint16 totalSize;
    qint16 bytesRead;
    QList<QString> strFields;
    QList<double> numFields;

};

#endif // CLIENTDIALOG_H
