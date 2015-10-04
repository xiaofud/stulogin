#include <QDebug>
#include "clientdialog.h"
#include "ui_clientdialog.h"
#include <QDate>
#include <QTime>
#include <QMessageBox>

ClientDialog::ClientDialog(QWidget *parent) :QDialog(parent),ui(new Ui::ClientDialog){
    ui->setupUi(this);

    // set proper date
    ui->fromDateTimeEdit->setDate(QDate::currentDate());
    ui->fromDateTimeEdit->setTime(QTime::currentTime());
    ui->toDateTimeEdit->setDate(QDate::currentDate().addDays(1));
    ui->toDateTimeEdit->setTime(QTime(24, 0, 0));

}

//bool ClientDialog::checkDataValid(){
//    long diff = ui->fromDateTimeEdit->dateTime().toTime_t() - ui->toDateTimeEdit->dateTime().toTime_t();
//    if (diff > 0 || qAbs(diff) < 30 * 60){
//        QMessageBox::warning(this, trUtf8("时间设置错误"), trUtf8("请保证起始时间先于结束时间半个钟以上: )"));
//        return false;
//    }
//    return true;
//}


ClientDialog::~ClientDialog(){
    delete ui;
}
















