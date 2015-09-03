#include <QApplication>
#include "loginwindow.h"
#include "clientdialog.h"
#include "clientdialog.h"
int main(int argc, char *argv[]){
    QApplication app(argc, argv);
    LoginWindow loginWin;
    loginWin.show();
//    ClientDialog client;
//    client.show();
    return app.exec();
}
