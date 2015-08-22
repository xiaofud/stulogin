#include <QMouseEvent>
#include <QPoint>
#include <QPalette>
#include <QPixmap>
#include <QBitmap>
#include <QPainter>
#include <QDesktopWidget>
#include <QRect>
#include "suspendingwindow.h"
#include "ui_suspendingwindow.h"
#include <QDebug>

void SuspendingWindow::showAtCorner(){
    QDesktopWidget *desktop = qApp->desktop();
    QRect availableSpace = desktop->availableGeometry();
    move(availableSpace.width() - width()- 10, availableSpace.height() - height() - 5);
}

SuspendingWindow::SuspendingWindow(QWidget *parent) :QWidget(parent){
    setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint |     // no frame
                   Qt::WindowStaysOnTopHint|
                   Qt::Tool);   // hide the taskIcon
    setAttribute(Qt::WA_TranslucentBackground, true);
    setWindowOpacity(0.8);
    updateDisplay(0.444, 4444);
}

void SuspendingWindow::exit(){
    qApp->quit();
}

void SuspendingWindow::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.setBrush(QColor(Qt::gray));
    painter.setPen(QColor(Qt::gray));
    painter.drawRoundedRect(0, 0, width(), height(), 20, 20);
    QWidget::paintEvent(event);
}


void SuspendingWindow::mousePressEvent(QMouseEvent *event){
    if (event->button() == Qt::LeftButton){
        previousPos = event->globalPos();
        event->accept();
    }else
        hide();
}


void SuspendingWindow::mouseMoveEvent(QMouseEvent *event){
    if (event->buttons() & Qt::LeftButton){
        int dx = event->globalPos().x()  - previousPos.x();     // figure the move in the x-axis
        int dy = event->globalPos().y() - previousPos.y();
        previousPos = event->globalPos();
        move(this->x() + dx, this->y() + dy);   // move to
        event->accept();
    }
}

void SuspendingWindow::updateDisplay(double left, double speed){
    static QString leftStr = trUtf8("剩余流量:");
    static QString speedStr = trUtf8("速度:");
    leftLabel->setText(leftStr + "<font color=white><b>" +QString::number((int)left) + "</b></font> MB");
    speedLabel->setText(speedStr + "<font color=white><b>" +QString::number((int)speed) + "</b></font> KB/s");
}

void SuspendingWindow::mouseDoubleClickEvent(QMouseEvent *event){
    emit doubleClicked();
    event->accept();
}



