#ifndef CLIENTDIALOG_H
#define CLIENTDIALOG_H
#include <QDataStream>
#include <QTcpSocket>
#include <QDialog>
#include <QByteArray>
#include <QStringList>

namespace Ui {
class ClientDialog;
}

class ClientDialog : public QDialog{
    Q_OBJECT

public:
    explicit ClientDialog(QWidget *parent = 0);
    ~ClientDialog();


public slots:
    void pullAccount();
    void pushAccount();
    void enableButtons();
private:
    Ui::ClientDialog *ui;
    QTcpSocket *clientSocket;
    QStringList strList;
    QByteArray buffer;
};

#endif // CLIENTDIALOG_H
