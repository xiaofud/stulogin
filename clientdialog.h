#ifndef CLIENTDIALOG_H
#define CLIENTDIALOG_H
#include <QDialog>
#include <QNetworkAccessManager>
#include <QNetworkReply>

namespace Ui {
class ClientDialog;
}

class QTextCodec;

class ClientDialog : public QDialog{
    Q_OBJECT

public:
    explicit ClientDialog(QWidget *parent = 0);
    ~ClientDialog();
    bool checkDataValid();

public slots:
    void push_account();
    void post_callback(QNetworkReply*);

private:
    QNetworkAccessManager *network_manager;
    Ui::ClientDialog *ui;
    QTextCodec *codec;

};

#endif // CLIENTDIALOG_H
