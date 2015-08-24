#include <QSettings>
#include <QTimer>
#include <QKeyEvent>
#include <QDesktopServices>
#include <QDir>
#include <QSystemTrayIcon>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>
#include <QTextCodec>
#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "suspendingwindow.h"
#include "auxiliary.h"
#include <QDebug>
QString LoginWindow::USED_STR = QObject::trUtf8("已用流量:");
QString LoginWindow::USER_STR = QObject::trUtf8("当前账号:");
QString LoginWindow::TOTAL_STR= QObject::trUtf8("全部流量:");
QString LoginWindow::LEFT_STR = QObject::trUtf8("<font color=red>剩余流量:</font>");
QString LoginWindow::DEFAULT_USER = "";
QString LoginWindow::RECORD_FILE = "user.dat";
QString LoginWindow::ICON_PATH = ":/images/icons/mainicon.png";
double LoginWindow::thresholdValue = 1.0;   // 1.0 mb


LoginWindow::LoginWindow(QWidget *parent) :QMainWindow(parent), logining(false), shownRow(-1), shownCol(-1),previousLeft(-1){
    setupUi(this);
    loginAction = new STULogin(this);
    connect(loginAction, SIGNAL(stateChanged(bool,QString,double,double,double)),
            this, SLOT(updateState(bool,QString,double,double,double)));    // update the connetion state

    QMainWindow::setWindowIcon(QIcon(ICON_PATH));

    smallWindow = new SuspendingWindow;
    connect(this, SIGNAL(newConnectionState(double,double)),
            smallWindow, SLOT(updateDisplay(double,double)));
    connect(smallWindow, SIGNAL(doubleClicked()),
            this, SLOT(show()));

    // call helpers
    setupButtons();
    setupLineEdit();
    setupStyle();
    setupUserTableView();
    setupSpinAndCheck();
    setupStatusBar();
    setupSettings();
    setupTrayIcon();
    setupMenu();
    startup();
    smallWindow->show();
    smallWindow->showAtCorner();
}



void LoginWindow::setupStyle(){
    QString qss("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    userLineEdit->setStyleSheet(qss);
    passwdLineEdit->setStyleSheet(qss);
//    loginButton->setStyleSheet(qss);
//    logoutButton->setStyleSheet(qss);
//    defaultButton->setStyleSheet(qss);
//    switchSpinBox->setStyleSheet(qss);
//    userTableWidget->setStyleSheet(qss);
}

void LoginWindow::setupButtons(){

    loginButton->setStatusTip("Login");
    logoutButton->setStatusTip("Logout");
    defaultButton->setToolTip(trUtf8("设置输入框内的账号为默认账号(程序启动时自动登录)"));

    connect(loginButton,SIGNAL(clicked()),
            this, SLOT(login()));

    connect(logoutButton, SIGNAL(clicked()),
            this, SLOT(logout()));

    connect(defaultButton,SIGNAL(clicked()),
            this, SLOT(setDefaultUser()));


    connect(delUserButton, SIGNAL(clicked()),   // delete an account, default: the last account if none selected
            this, SLOT(deleteRow()));

    connect(adduserButton, SIGNAL(clicked()),
            this, SLOT(addRow()));

}

void LoginWindow::setupLineEdit(){

    userLineEdit->installEventFilter(this);
    passwdLineEdit->installEventFilter(this);

    connect(userLineEdit, SIGNAL(textChanged(QString)),
            loginAction, SLOT(clearErrorCount()));      // erase the wrongCount
    connect(passwdLineEdit, SIGNAL(textChanged(QString)),
            loginAction, SLOT(clearErrorCount()));      // erase the wrongCount
    connect(this, SIGNAL(accountChanged(QList<Account>)),
            loginAction, SLOT(setAccounts(QList<Account>)));

}

void LoginWindow::setupUserTableView(){
    userTableWidget->setRowCount(0);
    userTableWidget->setColumnCount(2);
    userTableWidget->setHorizontalHeaderLabels(QStringList() << trUtf8("账号") << trUtf8("密码"));
    userTableWidget->horizontalHeader()->setResizeMode(QHeaderView::Stretch);      // the content will fill up the space
    connect(userTableWidget, SIGNAL(cellDoubleClicked(int,int)),
            this, SLOT(showPassword(int,int)));     // show the cleartext when edited the passwd
    connect(userTableWidget, SIGNAL(itemSelectionChanged()),
            this, SLOT(hidePassword()));            // hide the cleartext when the edition gets done
    connect(userTableWidget->verticalHeader(), SIGNAL(sectionDoubleClicked(int)),   // switch the account
            this, SLOT(editAccountLineEdit(int)));
}

void LoginWindow::setupSpinAndCheck(){
    switchSpinBox->setSuffix(tr("MB"));
    switchSpinBox->setRange(0,800);
    switchSpinBox->setValue(1);
    connect(switchSpinBox, SIGNAL(valueChanged(int)),       // determine when to change the account
            loginAction, SLOT(setThresholdValue(int)));

    // checkbox for determining whether to auto switch the account when the left-flow is less than the thresholdValue
    connect(autoChange,SIGNAL(toggled(bool)),
            loginAction, SLOT(setAutoChangeState(bool)));

}

void LoginWindow::setupStatusBar(){
    authorLabel = new QLabel(tr("E-mail: <a href=\"http://webmail.stu.edu.cn/\">14xfdeng@stu.edu.cn</a>"));
    QMainWindow::statusBar()->addPermanentWidget(authorLabel);      // show e-main address
    connect(authorLabel, SIGNAL(linkActivated(QString)),
            this, SLOT(openSTUEmail()));
}

void LoginWindow::setupSettings(){
    settings = new QSettings("tweak","stu_flow",this);
    loadSettings();
    autoChange->setEnabled(true);
}

void LoginWindow::setupMenu(){
    aboutMenu = QMainWindow::menuBar()->addMenu(trUtf8("帮助"));
    helpAction = new QAction(trUtf8("帮助"), this);
    aboutQt = new QAction(trUtf8("关于Qt"), this);

    connect(helpAction, SIGNAL(triggered(bool)),
            this, SLOT(showHelpMessage()));
    connect(aboutQt, SIGNAL(triggered(bool)),
            qApp, SLOT(aboutQt()));
    aboutMenu->addAction(helpAction);
    aboutMenu->addAction(aboutQt);

}

void LoginWindow::startup(){
    stateTimer = new QTimer(this);   // update the state
    stateTimer->setInterval(1500);
    connect(stateTimer, SIGNAL(timeout()),
            loginAction, SLOT(getState()));
    stateTimer->start();
    show();
    if (!userLineEdit->text().isEmpty() && !passwdLineEdit->text().isEmpty())   // the loadSettings() will fill the lineEdit if
                                                                                // any default account
        login();
}

void LoginWindow::exit(){
    saveSettings();
    qApp->quit();
}

void LoginWindow::showHelpMessage(){
    QFile help(getExeDir().append("HELP.txt"));
    QString message;
    if (!help.open(QIODevice::ReadOnly)){
        message = trUtf8("找不到目录下的HELP.txt");
        QMessageBox::warning(this, trUtf8("找不到帮助文件"), message,
                             QMessageBox::Ok);
    }else{
        QTextCodec *codec = QTextCodec::codecForName("utf-8");
        message = codec->toUnicode(help.readAll());
        QMessageBox msgBox(this);
        msgBox.setTextFormat(Qt::RichText);     // hyper text link enabled
        msgBox.setWindowTitle(tr("Help"));
        msgBox.setText(message);
        msgBox.exec();
    }
}

void LoginWindow::iconActivated(QSystemTrayIcon::ActivationReason reason){
    switch(reason){
    case QSystemTrayIcon::Trigger:
    case QSystemTrayIcon::DoubleClick:
        this->show();
        break;
    default:
        break;
    }
}

void LoginWindow::setupTrayIcon(){
    trayIcon = new QSystemTrayIcon(QIcon(ICON_PATH), this);
    QMenu *menu = new QMenu(this);
    exitAction = new QAction(trUtf8("退出"),this);
    showSuspendingWin = new QAction(trUtf8("显示悬浮窗口"), this);
    connect(showSuspendingWin, SIGNAL(triggered(bool)),
            smallWindow, SLOT(show()));
    connect(exitAction, SIGNAL(triggered(bool)),
            this, SLOT(exit()));

    menu->addAction(showSuspendingWin);
    menu->addAction(exitAction);

    trayIcon->setContextMenu(menu);     // auto pop up when suitable click happens
    connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
            this, SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));
}


void LoginWindow::updateState(bool connected, const QString &user, double used, double total, double left){
    if (!connected /*&& !logining */){   // insufficient logic
        loginButton->setEnabled(true);
    }
    else{
        loginButton->setEnabled(false);
    }

    currentUserName = user;
    totalFlow = Auxiliary::setDecimalBit( total, 3);
    leftFlow = Auxiliary::setDecimalBit( left, 3);

    // figure the speed
    QString speed_str;
    double speed;
    if (previousLeft != -1){    // means this is the first left data
        double diff = previousLeft - leftFlow;
        speed = ( diff * 1024 ) / 1.5;   // kbs
        speed = Auxiliary::setDecimalBit(speed, 3);
        speed_str =/* trUtf8("速度: ") + */ QString::number(speed) + " kb/s";
        QMainWindow::statusBar()->showMessage(speed_str);
        previousLeft = leftFlow;
        emit newConnectionState(left, speed);
    }else
        previousLeft = leftFlow;

    if (!connected){
        previousLeft = -1;  // set back to the impossible value
        QMainWindow::statusBar()->showMessage("");  // empty
        emit newConnectionState(0.0, 0.0);
    }

    // update the displaying
//    int left_int = (int) left;
    QString title = connected ? QString::number((int) left) + "MB": "not connected yet";
    setWindowTitle(title + "|" + speed_str + "|" + user );
    usedLabel->setText(this->USED_STR + QString::number(Auxiliary::setDecimalBit(used, 3)) + "MB");
    nowUserLabel->setText(this->USER_STR + user);
    totalLabel->setText(this->TOTAL_STR + QString::number(total) + "MB");
    leftLabel->setText(this->LEFT_STR + QString::number(left)  + "MB");
}

void LoginWindow::saveSettings(){
    // save the check box value
    settings->setValue("autoChange",autoChange->isChecked());
    saveUsers();
}

void LoginWindow::loadSettings(){
    QString username = settings->value("USERNAME","").toString();
    QString passwd = settings->value("PASSWORD","").toString();
    bool autoChangeFlag = settings->value("autoChange",false).toBool();
    DEFAULT_USER = username;
    userLineEdit->setText(username);
    passwdLineEdit->setText(passwd);
    autoChange->setChecked(autoChangeFlag);
    loadUsers();    // read the user data
}

void LoginWindow::setDefaultUser(){
    if (userLineEdit->text().isEmpty() || passwdLineEdit->text().isEmpty()){
        setStatusTip("username or password can't be empty");
        return;
    }
    settings->setValue("USERNAME",userLineEdit->text());
    settings->setValue("PASSWORD",passwdLineEdit->text());
}

void LoginWindow::login(){
    if (userLineEdit->text().isEmpty() || passwdLineEdit->text().isEmpty()){
        QMainWindow::statusBar()->showMessage(trUtf8("错误:账号或密码为空...."));
        return;
    }
    logining = true;
    loginButton->setEnabled(false);
    loginAction->login(userLineEdit->text(), passwdLineEdit->text());
    QString tmp = trUtf8("正在登录用户:");
    QMainWindow::statusBar()->showMessage( tmp + userLineEdit->text(), 1500);
}

void LoginWindow::logout(){
    loginAction->logout();
    if (loginAction->isConnected()){
    }else{
        logining = false;
    }

}

bool LoginWindow::eventFilter(QObject *dest, QEvent *event){
    if (passwdLineEdit->text().isEmpty() || userLineEdit->text().isEmpty()  || !loginButton->isEnabled() )
        return QMainWindow::eventFilter(dest, event);   // pass to parent's handler
    if (dest == passwdLineEdit || dest == userLineEdit){
        if (event->type() == QEvent::KeyPress){
            QKeyEvent *key_event = static_cast<QKeyEvent *>(event);
                if (key_event->key() == Qt::Key_Return || key_event->key() == Qt::Key_Enter){     // the keypad's enter is enter but the main is return
                    loginButton->click();
                    return true;
                }else{
                    return QMainWindow::eventFilter(dest, event);   // or other input will be ignored
                }

        }
    }
    return QMainWindow::eventFilter(dest, event);
}

void LoginWindow::addRow(const QString &user, const QString &passwd, bool sendSignal){
    int index = userTableWidget->rowCount();  // start from zero
    userTableWidget->insertRow(index);

    // each row has two items
    QTableWidgetItem *item1 = new QTableWidgetItem;
    item1->setTextAlignment(Qt::AlignCenter | Qt::AlignVCenter);
    item1->setText(user);
    userTableWidget->setItem(index,0,item1);

    QTableWidgetItem *item2 = new QTableWidgetItem;
    item2->setTextAlignment(Qt::AlignCenter | Qt::AlignVCenter);
    item2->setData(Qt::UserRole,passwd);
    if (!passwd.isEmpty())
        item2->setText(QString(passwd.length(), '*'));
    userTableWidget->setItem(index,1,item2);
    userTableWidget->setCurrentCell(index, 0);    

    if (sendSignal)     // when loading records from file, don't send signals
        updateAccountToTable();

}

void LoginWindow::deleteRow(){
    int row = userTableWidget->currentRow();
    //setWindowTitle(QString::number(row));
    if (row >= 0){
        if (row == shownRow)
            shownRow = shownCol = -1;
        userTableWidget->removeRow(row);
        updateAccountToTable();
    }
}

void LoginWindow::showPassword(int row, int column){
    // double click the cell the password will display
    if (column == 0)
        return;
    QTableWidgetItem *current = userTableWidget->item(row, column);
    current->setText(current->data(Qt::UserRole).toString());

    // record the cell
    shownRow = row;
    shownCol = column;


}

void LoginWindow::hidePassword(){
    // get out of the cell the disply will be something like this ****

    if (shownRow == -1 || shownCol == -1)
        return;

    QTableWidgetItem *item = userTableWidget->item(shownRow, shownCol);
    const QString &passwd = item->text();
    item->setData(Qt::UserRole,passwd);
    shownRow = shownCol = -1;  // reset the value
    int len = passwd.length();
    item->setText(QString(len,'*'));
}

QString LoginWindow::getExeDir() const{
    // return format /dirname/ with tailing '/'
    char **argv = qApp->argv();
//    qDebug() << argv[0];
    QString path(argv[0]);
    int index = path.lastIndexOf(QDir::separator());    // for splitting the name and the dir
    if (index != -1){
        path = path.mid(0, index + 1);  // because mid doesn't include the right-hand-side index
    }else
        path = "";
    return path;
}


void LoginWindow::saveUsers(){
    int count = userTableWidget->rowCount();
    QStringList users;
    for(int i = 0 ; i < count ; ++i){
        QTableWidgetItem *user_item = userTableWidget->item(i, 0);
        QTableWidgetItem *passwd_item = userTableWidget->item(i, 1);
        if (user_item->text().isEmpty() || passwd_item->data(Qt::UserRole).toString().isEmpty())    // skip the invalid data
            continue;
        users << user_item->text() << passwd_item->data(Qt::UserRole).toString();
    }
    QString path = getExeDir().append(RECORD_FILE);
    QFile file(path);
    if (!file.open(QIODevice::WriteOnly)){
        //qDebug() << "Can't open file" + RECORD_FILE;
        return;
    }
    QDataStream out(&file);
    out.setVersion(QDataStream::Qt_4_8);
    out << users;
    //printf("Save Done! %s\n",RECORD_FILE.toStdString().c_str());
}

void LoginWindow::loadUsers(){
    QString path = getExeDir().append(RECORD_FILE);
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly)){
        return;     // means no such file
    }
    //printf("everything is okay\n");
    QDataStream in(&file);
    in.setVersion(QDataStream::Qt_4_8);
    QStringList users;
    in >> users;
    setUserTable(users);

}

void LoginWindow::setUserTable(QStringList &users){
    int count = users.count();
    QString user, passwd;
    for(int i = 0 ; i < count / 2 ; ++i ){   // pairs
        user = users.at(0);
        passwd = users.at(1);
        if (i < count / 2 - 1)
            addRow(user,passwd,false);
        else
            addRow(user,passwd,true);
        users.pop_front();
        users.pop_front();
    }
}

void LoginWindow::closeEvent(QCloseEvent *event){
    static bool showed = false;
    trayIcon->show();
    if (!showed){
//        trayIcon->showMessage("Run in the background", "You can click the trayIcon to exit the program", QSystemTrayIcon::Information, 1000);
        showed = true;
    }
    hide();
    event->ignore();

//    saveSettings();
//    event->accept();
}


void LoginWindow::editAccountLineEdit(int index){
    int row = index;
    //printf("the row is %d\n",row);
    QString username = userTableWidget->item(row,0)->text();
    QString password = userTableWidget->item(row,1)->data(Qt::UserRole).toString();
    userLineEdit->setText(username);
    passwdLineEdit->setText(password);
}

void LoginWindow::updateAccountToTable(){
    accounts.clear();       // clear the previous data
    int row = userTableWidget->rowCount();
//    qDebug() << row;
    QString tmp_user, tmp_passwd;
    for(int i = 0 ; i < row ; ++i){
        QTableWidgetItem *item1 = userTableWidget->item(i,0);
        QTableWidgetItem *item2 = userTableWidget->item(i,1);
        tmp_user = item1->text();
        tmp_passwd = item2->data(Qt::UserRole).toString();
        if (tmp_user.isEmpty() || tmp_passwd.isEmpty())  // skip the empty entry
            continue;
        accounts.append(Account(tmp_user, tmp_passwd));
    }
    emit accountChanged(accounts);
}

void LoginWindow::openSTUEmail(){
    QDesktopServices::openUrl(QUrl("http://webmail.stu.edu.cn/"));
}
