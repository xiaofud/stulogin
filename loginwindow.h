#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QSystemTrayIcon>

#include "ui_loginwindow.h"
#include "stulogin.h"
#include "account.h"
#include "suspendingwindow.h"

class QSettings;
class QTimer;
class QAction;

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QMainWindow, public Ui::LoginWindow{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = 0);
    void saveSettings();
    void loadSettings();
    void setUserTable(QStringList &users);

public slots:
    void updateState(bool connected,const QString &USER_STR, double USED_STR, double TOTAL_STR, double LEFT_STR);
    void setDefaultUser();
    void login();
    void logout();
    bool eventFilter(QObject *, QEvent *);
    void closeEvent(QCloseEvent *event);
    void openSTUEmail();
    void iconActivated(QSystemTrayIcon::ActivationReason reason);
    void exit();
private slots:
    void addRow(const QString &USER_STR = QString(), const QString &passwd = QString(), bool sendSignal = true);
    void deleteRow();
    void showPassword(int,int);
    void hidePassword();
    void editAccountLineEdit(int);     // change the current input of the account


signals:
    void accountChanged(const QList<Account> &list);
    void newConnectionState(double left, double speed);
private:
    void saveUsers();
    void loadUsers();
    void updateAccountToTable();
    /*-------------------*
     * constructor helper*
     *-------------------*/
    void setupButtons();
    void setupLineEdit();
    void setupUserTableView();
    void setupSpinAndCheck();
    void setupStatusBar();
    void setupSettings();
    void startup();
    void setupTrayIcon();
    void setupStyle();
    QString getExePath()const;
    STULogin *loginAction;
    QSettings *settings;
    QTimer *stateTimer;
    QLabel *authorLabel;
    QSystemTrayIcon *trayIcon;
    QAction *exitAction;
    QAction *showSuspendingWin;
    SuspendingWindow *smallWindow;
    bool logining;  // flag : whether the login button is pressed
    int shownRow;   // used for displaying the password behind the table
    int shownCol;
    double previousLeft;    // used to figure the flow speed
    double totalFlow;
    double leftFlow;    // left flow
    QString currentUserName;
    QList<Account> accounts;    // contains all the accouts

    static double thresholdValue;   // if left flow is less than this consider to change the account.

    // some string constant
    static QString USER_STR;
    static QString USED_STR;
    static QString TOTAL_STR;
    static QString LEFT_STR;
    static QString DEFAULT_USER;
    static QString RECORD_FILE;
    static QString ICON_PATH;
};

#endif // LOGINWINDOW_H
