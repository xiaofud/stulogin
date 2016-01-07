#include <QDebug>
#include "clientdialog.h"
#include "ui_clientdialog.h"
#include <QTextCodec>
#include <QDate>
#include <QTime>
#include <QMessageBox>
#include <QNetworkRequest>

ClientDialog::ClientDialog(QWidget *parent) :QDialog(parent),ui(new Ui::ClientDialog){
    ui->setupUi(this);

    codec = QTextCodec::codecForName("utf-8");


    // set proper date
    ui->fromDateTimeEdit->setDate(QDate::currentDate());
    ui->fromDateTimeEdit->setTime(QTime::currentTime());
    ui->toDateTimeEdit->setDate(QDate::currentDate().addDays(1));
    ui->toDateTimeEdit->setTime(QTime(24, 0, 0));

    connect(ui->pushUserButton, SIGNAL(clicked()), SLOT(push_account()));

    network_manager = new QNetworkAccessManager(this);
    connect(network_manager, SIGNAL(finished(QNetworkReply*)),
            this , SLOT(post_callback(QNetworkReply*)));

}

bool ClientDialog::checkDataValid(){
    // 注意 time_t 是无符号类型
    long diff = (signed long) ui->fromDateTimeEdit->dateTime().toTime_t() - ui->toDateTimeEdit->dateTime().toTime_t();
    if (diff > 0 || qAbs(diff) < 30 * 60){
        qDebug() << ui->fromDateTimeEdit->dateTime().toTime_t() << "\n" << ui->toDateTimeEdit->dateTime().toTime_t();;
        return false;
    }
    return true;
}


void ClientDialog::push_account(){
    if (!checkDataValid()){
        QMessageBox::warning(this, trUtf8("时间设置错误"), trUtf8("请保证起始时间先于结束时间半个钟以上: )"));
        return;
    }

    // 获取各种属性
    long start_time = (signed long) ui->fromDateTimeEdit->dateTime().toTime_t();
    long end_time =  (signed long) ui->toDateTimeEdit->dateTime().toTime_t();
//    bool ok;

    long share_flow = ui->shareSpinBox->cleanText().toLong();

    QString username = ui->userLineEdit->text();
    QString password = ui->passwdLineEdit->text();

    QString url = ui->addressLineEdit->text();

    QNetworkRequest request;
    request.setUrl(QUrl(url));

    QUrl params;

    params.addQueryItem("username", username);
    params.addQueryItem("password", password);
    params.addQueryItem("share_flow", QString::number(share_flow));
    params.addQueryItem("start_time", QString::number(start_time));
    params.addQueryItem("end_time", QString::number(end_time));

    QByteArray post_data = params.encodedQuery();
//    qDebug() << post_data;
    request.setHeader(QNetworkRequest::ContentTypeHeader,
                      "application/x-www-form-urlencoded");
    network_manager->post(request, post_data);


}

void ClientDialog::post_callback(QNetworkReply *reply){
    QByteArray response = reply->readAll();
    reply->deleteLater();
    QString info = codec->toUnicode(response);
    qDebug() << info;
    if (info.contains("status")){
        QMessageBox::information(this, trUtf8("提示"), trUtf8("分享成功"));
    }
    else{
        QMessageBox::information(this, trUtf8("提示"), trUtf8("分享失败"));
    }
    network_manager->setNetworkAccessible(
                QNetworkAccessManager::Accessible);
    return;
}

ClientDialog::~ClientDialog(){
    delete ui;
}
















