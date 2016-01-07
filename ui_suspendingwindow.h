/********************************************************************************
** Form generated from reading UI file 'suspendingwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUSPENDINGWINDOW_H
#define UI_SUSPENDINGWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SuspendingWindow
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *speedLabel;
    QLabel *leftLabel;

    void setupUi(QWidget *SuspendingWindow)
    {
        if (SuspendingWindow->objectName().isEmpty())
            SuspendingWindow->setObjectName(QString::fromUtf8("SuspendingWindow"));
        SuspendingWindow->resize(108, 30);
        horizontalLayout = new QHBoxLayout(SuspendingWindow);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        speedLabel = new QLabel(SuspendingWindow);
        speedLabel->setObjectName(QString::fromUtf8("speedLabel"));

        horizontalLayout->addWidget(speedLabel);

        leftLabel = new QLabel(SuspendingWindow);
        leftLabel->setObjectName(QString::fromUtf8("leftLabel"));

        horizontalLayout->addWidget(leftLabel);


        retranslateUi(SuspendingWindow);

        QMetaObject::connectSlotsByName(SuspendingWindow);
    } // setupUi

    void retranslateUi(QWidget *SuspendingWindow)
    {
        SuspendingWindow->setWindowTitle(QApplication::translate("SuspendingWindow", "Form", 0, QApplication::UnicodeUTF8));
        speedLabel->setText(QApplication::translate("SuspendingWindow", "\351\200\237\345\272\246:", 0, QApplication::UnicodeUTF8));
        leftLabel->setText(QApplication::translate("SuspendingWindow", "\345\211\251\344\275\231\346\265\201\351\207\217:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SuspendingWindow: public Ui_SuspendingWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUSPENDINGWINDOW_H
