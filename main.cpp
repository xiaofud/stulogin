#include <QApplication>
#include "loginwindow.h"
int main(int argc, char *argv[]){
    QApplication app(argc, argv);
    LoginWindow loginWin;
    loginWin.show();
    return app.exec();
}
