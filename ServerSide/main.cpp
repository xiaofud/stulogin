#include <QApplication>
#include "serverwidget.h"
#include "qsqlitedatabasemanager.h"

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    ServerWidget w;
    w.show();
    return a.exec();
}
