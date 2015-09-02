#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QSystemTrayIcon>

#include "ui_loginwindow.h"
#include "stulogin.h"
#include "account.h"
#include "suspendingwindow.h"
#include "clientdialog.h"

class QSettings;
class QTimer;
class QAction;
class QMenu;

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
    void showHelpMessage();
    void showConnectionError();
    void showClientWindow();
signals:
    void accountChanged(QList<Account> *list);
    void newConnectionState(double left, double speed);


private:
    void saveUsers();
    void loadUsers();
    void updateAccountToTable();
    /*-------------------*
     * constructor helper*
     *-------------------*/
    void setupSuspending();
    void setupButtons();
    void setupLineEdit();
    void setupUserTableView();
    void setupSpinAndCheck();
    void setupStatusBar();
    void setupSettings();
    void setupMenu();
    void startup();
    void setupTrayIcon();
    void setupStyle();
    QString getExeDir()const;
    STULogin *loginAction;
    QSettings *settings;
    QTimer *stateTimer;
    QLabel *authorLabel;
    QSystemTrayIcon *trayIcon;
    QAction *exitAction;
    QAction *showSuspendingWin;
    SuspendingWindow *smallWindow;
    ClientDialog *shareDialog;
    QMenu *aboutMenu;
    QAction *helpAction;
    QAction *aboutQt;
    bool logining;  // flag : whether the login button is pressed
    int shownRow;   // used for displaying the password behind the table
    int shownCol;
    double previousLeft;    // used to figure the flow speed
    int badConnectionCount;
    bool hasShownBadConnection;
    double totalFlow;
    double leftFlow;    // left flow
    QString currentUserName;
    QList<Account> accounts;    // contains all the accouts

    static double THRESHOLDVALUR;   // if left flow is less than this consider to change the account.
    static double UPDATE_PERIOD;
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
