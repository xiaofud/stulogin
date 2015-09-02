#ifndef STULOGIN_H
#define STULOGIN_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QUrl>
#include <QNetworkReply>
#include "account.h"

class QTextCodec;
class QTimer;
class STULogin: public QObject{
    Q_OBJECT
public:
    STULogin(QObject *parent);
    bool isConnected() const {return is_connected;}

    void processStates(const QString &data);


signals:
    void stateChanged(bool connected,const QString &user, double used, double total, double left);
    void badConnection();   // emited when the connection is over

public slots:
    void logout();
    void login(const QString &user, const QString &passwd);
    void handleReply(QNetworkReply *reply);
    void getState();
    void setAccounts(QList<Account> *accounts);
    void setThresholdValue(int);
    void setAutoChangeState(bool);
    void changeAccount();   // switch the account
    void resetAllAccounts();
    void delayForSomeTime(int ms);
    QNetworkReply *syncHttpPost(const QNetworkRequest & request, const QByteArray & data);
    QNetworkReply *syncHttpGet(const QNetworkRequest &request);

private slots:
    void clearErrorCount();
    void login();

private:
    int getNextFreshAccount();
    QString replyData;
    QNetworkAccessManager *manager;
    QUrl *requestAddr;
    QTextCodec *codec;
    bool is_connected;
    bool autoChange;
    bool stopChaneing;
    bool bad_connection;
    mutable bool logining;  // bool for clicking button
    int wrongCount;     // the server return ERROR when trying to connect immediately after the Logout action.
    QString user;
    QString user_copy;  // for trying logining again for the sucking server
    QString passwd;
    double used;
    double total;
    double left;
    double thresholdValue;  // when to switch the account
    QTimer *delayTimer;
    QList<Account> *allAccounts;
    int ptr_account;    // point to which account's being used start from zero

/******************************/
    static QString LOGIN_REQUEST_ADDR;      // where to send the request to login
    static QString LOGOUT_REQUEST_ADDR;     // where to send the request to logout
    static QString USERNAME_INPUT;          // the form data
    static QString PASSWD_INPUT;
    static QString LOGIN_INPUT;
    static QString LOGOUT_INPUT;
    static QString USERNAME_POSITION;
    static QString USEDBYTE_POSITION;
    static QString TOTALBYTE_POSITION;
    static QString POSITION_END;
    static QString INVALID;
    static QString CONNECTED;
    static int CONVERT_RATE;
    static int MAX_ERROR_COUNT;         // the max error counts that ensure the user/password is wrong
                                        // because the server in school is not so good.
};

#endif // STULOGIN_H
