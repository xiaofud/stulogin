#ifndef SERVERWIDGET_H
#define SERVERWIDGET_H

#include <QWidget>

namespace Ui {
class ServerWidget;
}

class ServerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ServerWidget(QWidget *parent = 0);
    ~ServerWidget();

private:
    Ui::ServerWidget *ui;
};

#endif // SERVERWIDGET_H
