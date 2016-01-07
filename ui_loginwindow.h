/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_7;
    QGroupBox *loginGroupBox;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *userLabel;
    QLineEdit *userLineEdit;
    QPushButton *loginButton;
    QHBoxLayout *horizontalLayout_2;
    QLabel *passwdLabel;
    QLineEdit *passwdLineEdit;
    QPushButton *logoutButton;
    QVBoxLayout *verticalLayout;
    QLabel *nowUserLabel;
    QLabel *usedLabel;
    QLabel *totalLabel;
    QLabel *leftLabel;
    QLabel *noticeLabel;
    QPushButton *defaultButton;
    QGroupBox *infoGroupBox;
    QVBoxLayout *verticalLayout_5;
    QLabel *usersHelp;
    QHBoxLayout *horizontalLayout_4;
    QTableWidget *userTableWidget;
    QVBoxLayout *verticalLayout_3;
    QPushButton *adduserButton;
    QPushButton *delUserButton;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QSpinBox *switchSpinBox;
    QCheckBox *autoChange;
    QPushButton *sharedButton;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName(QString::fromUtf8("LoginWindow"));
        LoginWindow->resize(474, 406);
        centralWidget = new QWidget(LoginWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_7 = new QVBoxLayout(centralWidget);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        loginGroupBox = new QGroupBox(centralWidget);
        loginGroupBox->setObjectName(QString::fromUtf8("loginGroupBox"));
        verticalLayout_6 = new QVBoxLayout(loginGroupBox);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        userLabel = new QLabel(loginGroupBox);
        userLabel->setObjectName(QString::fromUtf8("userLabel"));

        horizontalLayout->addWidget(userLabel);

        userLineEdit = new QLineEdit(loginGroupBox);
        userLineEdit->setObjectName(QString::fromUtf8("userLineEdit"));
        userLineEdit->setEnabled(true);

        horizontalLayout->addWidget(userLineEdit);

        loginButton = new QPushButton(loginGroupBox);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));

        horizontalLayout->addWidget(loginButton);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        passwdLabel = new QLabel(loginGroupBox);
        passwdLabel->setObjectName(QString::fromUtf8("passwdLabel"));

        horizontalLayout_2->addWidget(passwdLabel);

        passwdLineEdit = new QLineEdit(loginGroupBox);
        passwdLineEdit->setObjectName(QString::fromUtf8("passwdLineEdit"));
        passwdLineEdit->setEnabled(true);
        passwdLineEdit->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(passwdLineEdit);

        logoutButton = new QPushButton(loginGroupBox);
        logoutButton->setObjectName(QString::fromUtf8("logoutButton"));

        horizontalLayout_2->addWidget(logoutButton);


        verticalLayout_2->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        nowUserLabel = new QLabel(loginGroupBox);
        nowUserLabel->setObjectName(QString::fromUtf8("nowUserLabel"));

        verticalLayout->addWidget(nowUserLabel);

        usedLabel = new QLabel(loginGroupBox);
        usedLabel->setObjectName(QString::fromUtf8("usedLabel"));

        verticalLayout->addWidget(usedLabel);

        totalLabel = new QLabel(loginGroupBox);
        totalLabel->setObjectName(QString::fromUtf8("totalLabel"));

        verticalLayout->addWidget(totalLabel);

        leftLabel = new QLabel(loginGroupBox);
        leftLabel->setObjectName(QString::fromUtf8("leftLabel"));

        verticalLayout->addWidget(leftLabel);


        horizontalLayout_3->addLayout(verticalLayout);


        verticalLayout_4->addLayout(horizontalLayout_3);

        noticeLabel = new QLabel(loginGroupBox);
        noticeLabel->setObjectName(QString::fromUtf8("noticeLabel"));

        verticalLayout_4->addWidget(noticeLabel);

        defaultButton = new QPushButton(loginGroupBox);
        defaultButton->setObjectName(QString::fromUtf8("defaultButton"));

        verticalLayout_4->addWidget(defaultButton);


        verticalLayout_6->addLayout(verticalLayout_4);


        verticalLayout_7->addWidget(loginGroupBox);

        infoGroupBox = new QGroupBox(centralWidget);
        infoGroupBox->setObjectName(QString::fromUtf8("infoGroupBox"));
        verticalLayout_5 = new QVBoxLayout(infoGroupBox);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        usersHelp = new QLabel(infoGroupBox);
        usersHelp->setObjectName(QString::fromUtf8("usersHelp"));

        verticalLayout_5->addWidget(usersHelp);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        userTableWidget = new QTableWidget(infoGroupBox);
        userTableWidget->setObjectName(QString::fromUtf8("userTableWidget"));
        userTableWidget->setFrameShape(QFrame::StyledPanel);
        userTableWidget->setFrameShadow(QFrame::Plain);
        userTableWidget->setColumnCount(0);

        horizontalLayout_4->addWidget(userTableWidget);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        adduserButton = new QPushButton(infoGroupBox);
        adduserButton->setObjectName(QString::fromUtf8("adduserButton"));

        verticalLayout_3->addWidget(adduserButton);

        delUserButton = new QPushButton(infoGroupBox);
        delUserButton->setObjectName(QString::fromUtf8("delUserButton"));

        verticalLayout_3->addWidget(delUserButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        label = new QLabel(infoGroupBox);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_3->addWidget(label);

        switchSpinBox = new QSpinBox(infoGroupBox);
        switchSpinBox->setObjectName(QString::fromUtf8("switchSpinBox"));

        verticalLayout_3->addWidget(switchSpinBox);

        autoChange = new QCheckBox(infoGroupBox);
        autoChange->setObjectName(QString::fromUtf8("autoChange"));

        verticalLayout_3->addWidget(autoChange);


        horizontalLayout_4->addLayout(verticalLayout_3);


        verticalLayout_5->addLayout(horizontalLayout_4);


        verticalLayout_7->addWidget(infoGroupBox);

        sharedButton = new QPushButton(centralWidget);
        sharedButton->setObjectName(QString::fromUtf8("sharedButton"));

        verticalLayout_7->addWidget(sharedButton);

        LoginWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(LoginWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        LoginWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(userLineEdit, passwdLineEdit);
        QWidget::setTabOrder(passwdLineEdit, loginButton);
        QWidget::setTabOrder(loginButton, logoutButton);

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LoginWindow)
    {
        LoginWindow->setWindowTitle(QApplication::translate("LoginWindow", "LoginWindow", 0, QApplication::UnicodeUTF8));
        loginGroupBox->setTitle(QApplication::translate("LoginWindow", "\347\231\273\345\275\225\345\214\272:", 0, QApplication::UnicodeUTF8));
        userLabel->setText(QApplication::translate("LoginWindow", "\350\264\246\345\217\267:", 0, QApplication::UnicodeUTF8));
        userLineEdit->setPlaceholderText(QString());
        loginButton->setText(QApplication::translate("LoginWindow", "\347\231\273\345\275\225", 0, QApplication::UnicodeUTF8));
        passwdLabel->setText(QApplication::translate("LoginWindow", "\345\257\206\347\240\201:", 0, QApplication::UnicodeUTF8));
        passwdLineEdit->setInputMask(QString());
        passwdLineEdit->setText(QString());
        passwdLineEdit->setPlaceholderText(QString());
        logoutButton->setText(QApplication::translate("LoginWindow", "\347\231\273\345\207\272", 0, QApplication::UnicodeUTF8));
        nowUserLabel->setText(QApplication::translate("LoginWindow", "\345\275\223\345\211\215\350\264\246\345\217\267:", 0, QApplication::UnicodeUTF8));
        usedLabel->setText(QApplication::translate("LoginWindow", "\345\267\262\347\224\250\346\265\201\351\207\217:", 0, QApplication::UnicodeUTF8));
        totalLabel->setText(QApplication::translate("LoginWindow", "\345\205\250\351\203\250\346\265\201\351\207\217:", 0, QApplication::UnicodeUTF8));
        leftLabel->setText(QApplication::translate("LoginWindow", "\345\211\251\344\275\231\346\265\201\351\207\217:", 0, QApplication::UnicodeUTF8));
        noticeLabel->setText(QString());
        defaultButton->setText(QApplication::translate("LoginWindow", "\350\256\276\344\270\272\351\273\230\350\256\244\350\264\246\345\217\267", 0, QApplication::UnicodeUTF8));
        infoGroupBox->setTitle(QApplication::translate("LoginWindow", "\350\256\276\347\275\256\345\214\272:", 0, QApplication::UnicodeUTF8));
        usersHelp->setText(QApplication::translate("LoginWindow", "\345\217\214\345\207\273\345\267\246\350\276\271\347\232\204\350\241\214\345\217\267\345\217\257\344\273\245\345\210\207\346\215\242\350\264\246\345\217\267:", 0, QApplication::UnicodeUTF8));
        adduserButton->setText(QApplication::translate("LoginWindow", "\346\267\273\345\212\240", 0, QApplication::UnicodeUTF8));
        delUserButton->setText(QApplication::translate("LoginWindow", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("LoginWindow", "\345\275\223\346\265\201\351\207\217\344\275\216\344\272\216:", 0, QApplication::UnicodeUTF8));
        autoChange->setText(QApplication::translate("LoginWindow", "\350\207\252\345\212\250\345\210\207\346\215\242", 0, QApplication::UnicodeUTF8));
        sharedButton->setText(QApplication::translate("LoginWindow", "\345\210\206\344\272\253", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
