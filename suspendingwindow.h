#ifndef SUSPENDINGWINDOW_H
#define SUSPENDINGWINDOW_H

#include <QWidget>
#include <QPixmap>
#include <ui_suspendingwindow.h>

class QPoint;

namespace Ui {
class SuspendingWindow;
}

class SuspendingWindow : public QWidget, public Ui::SuspendingWindow{
    Q_OBJECT

public:
    explicit SuspendingWindow(QWidget *parent = 0);
    void showAtCorner();

public slots:
    void updateDisplay(double left, double speed);
    void exit();

protected:
    void mouseDoubleClickEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);

signals:
    void doubleClicked();

private:
    QPoint previousPos;
    QPixmap pixmap;
};

#endif // SUSPENDINGWINDOW_H
