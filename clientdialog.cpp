#include "clientdialog.h"
#include "ui_clientdialog.h"

ClientDialog::ClientDialog(QWidget *parent) :QDialog(parent),ui(new Ui::ClientDialog){
    ui->setupUi(this);
}

ClientDialog::~ClientDialog(){
    delete ui;
}
