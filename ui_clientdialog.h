/********************************************************************************
** Form generated from reading UI file 'clientdialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTDIALOG_H
#define UI_CLIENTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDateTimeEdit>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ClientDialog
{
public:
    QVBoxLayout *verticalLayout_7;
    QGroupBox *infoBox;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_3;
    QLabel *usernameLabel;
    QLabel *totalShareLabel;
    QLabel *totalFetchLabel;
    QLabel *shareRateLabel;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *addressLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *portLineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *userLineEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *passwdLineEdit;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_5;
    QDateTimeEdit *fromDateTimeEdit;
    QLabel *label_6;
    QDateTimeEdit *toDateTimeEdit;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QPushButton *getUserButton;
    QPushButton *pushUserButton;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_7;
    QSpinBox *shareSpinBox;

    void setupUi(QDialog *ClientDialog)
    {
        if (ClientDialog->objectName().isEmpty())
            ClientDialog->setObjectName(QString::fromUtf8("ClientDialog"));
        ClientDialog->resize(412, 466);
        verticalLayout_7 = new QVBoxLayout(ClientDialog);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        infoBox = new QGroupBox(ClientDialog);
        infoBox->setObjectName(QString::fromUtf8("infoBox"));
        horizontalLayout_6 = new QHBoxLayout(infoBox);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        usernameLabel = new QLabel(infoBox);
        usernameLabel->setObjectName(QString::fromUtf8("usernameLabel"));

        verticalLayout_3->addWidget(usernameLabel);

        totalShareLabel = new QLabel(infoBox);
        totalShareLabel->setObjectName(QString::fromUtf8("totalShareLabel"));

        verticalLayout_3->addWidget(totalShareLabel);

        totalFetchLabel = new QLabel(infoBox);
        totalFetchLabel->setObjectName(QString::fromUtf8("totalFetchLabel"));

        verticalLayout_3->addWidget(totalFetchLabel);

        shareRateLabel = new QLabel(infoBox);
        shareRateLabel->setObjectName(QString::fromUtf8("shareRateLabel"));

        verticalLayout_3->addWidget(shareRateLabel);


        horizontalLayout_6->addLayout(verticalLayout_3);


        verticalLayout_7->addWidget(infoBox);

        groupBox = new QGroupBox(ClientDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout_5 = new QHBoxLayout(groupBox);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        addressLineEdit = new QLineEdit(groupBox);
        addressLineEdit->setObjectName(QString::fromUtf8("addressLineEdit"));

        horizontalLayout->addWidget(addressLineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        portLineEdit = new QLineEdit(groupBox);
        portLineEdit->setObjectName(QString::fromUtf8("portLineEdit"));

        horizontalLayout_2->addWidget(portLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        userLineEdit = new QLineEdit(groupBox);
        userLineEdit->setObjectName(QString::fromUtf8("userLineEdit"));

        horizontalLayout_3->addWidget(userLineEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        passwdLineEdit = new QLineEdit(groupBox);
        passwdLineEdit->setObjectName(QString::fromUtf8("passwdLineEdit"));

        horizontalLayout_4->addWidget(passwdLineEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_4->addWidget(label_5);

        fromDateTimeEdit = new QDateTimeEdit(groupBox);
        fromDateTimeEdit->setObjectName(QString::fromUtf8("fromDateTimeEdit"));

        verticalLayout_4->addWidget(fromDateTimeEdit);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_4->addWidget(label_6);

        toDateTimeEdit = new QDateTimeEdit(groupBox);
        toDateTimeEdit->setObjectName(QString::fromUtf8("toDateTimeEdit"));

        verticalLayout_4->addWidget(toDateTimeEdit);


        verticalLayout->addLayout(verticalLayout_4);


        horizontalLayout_5->addLayout(verticalLayout);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        getUserButton = new QPushButton(groupBox);
        getUserButton->setObjectName(QString::fromUtf8("getUserButton"));

        verticalLayout_2->addWidget(getUserButton);

        pushUserButton = new QPushButton(groupBox);
        pushUserButton->setObjectName(QString::fromUtf8("pushUserButton"));

        verticalLayout_2->addWidget(pushUserButton);


        verticalLayout_6->addLayout(verticalLayout_2);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_5->addWidget(label_7);

        shareSpinBox = new QSpinBox(groupBox);
        shareSpinBox->setObjectName(QString::fromUtf8("shareSpinBox"));
        shareSpinBox->setMinimum(50);
        shareSpinBox->setMaximum(800);

        verticalLayout_5->addWidget(shareSpinBox);


        verticalLayout_6->addLayout(verticalLayout_5);


        horizontalLayout_5->addLayout(verticalLayout_6);


        verticalLayout_7->addWidget(groupBox);


        retranslateUi(ClientDialog);

        QMetaObject::connectSlotsByName(ClientDialog);
    } // setupUi

    void retranslateUi(QDialog *ClientDialog)
    {
        ClientDialog->setWindowTitle(QApplication::translate("ClientDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        infoBox->setTitle(QApplication::translate("ClientDialog", "\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        usernameLabel->setText(QApplication::translate("ClientDialog", "\347\224\250\346\210\267\345\220\215:", 0, QApplication::UnicodeUTF8));
        totalShareLabel->setText(QApplication::translate("ClientDialog", "\346\200\273\345\210\206\344\272\253:", 0, QApplication::UnicodeUTF8));
        totalFetchLabel->setText(QApplication::translate("ClientDialog", "\346\200\273\350\216\267\345\217\226:", 0, QApplication::UnicodeUTF8));
        shareRateLabel->setText(QApplication::translate("ClientDialog", "\345\210\206\344\272\253\347\216\207:", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("ClientDialog", "\345\210\206\344\272\253/\350\216\267\345\217\226", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ClientDialog", "\345\234\260\345\235\200:", 0, QApplication::UnicodeUTF8));
        addressLineEdit->setText(QApplication::translate("ClientDialog", "http://127.0.0.1:5000/api/user", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ClientDialog", "\347\253\257\345\217\243:", 0, QApplication::UnicodeUTF8));
        portLineEdit->setText(QApplication::translate("ClientDialog", "5000", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ClientDialog", "\347\224\250\346\210\267:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ClientDialog", "\345\257\206\347\240\201:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("ClientDialog", "\345\274\200\345\247\213\345\210\206\344\272\253\347\232\204\346\227\266\351\227\264:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("ClientDialog", "\345\201\234\346\255\242\345\210\206\344\272\253\347\232\204\346\227\266\351\227\264:", 0, QApplication::UnicodeUTF8));
        getUserButton->setText(QApplication::translate("ClientDialog", "GET", 0, QApplication::UnicodeUTF8));
        pushUserButton->setText(QApplication::translate("ClientDialog", "PUSH", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("ClientDialog", "\345\210\206\344\272\253\351\207\217:", 0, QApplication::UnicodeUTF8));
        shareSpinBox->setSuffix(QApplication::translate("ClientDialog", "MB", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ClientDialog: public Ui_ClientDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTDIALOG_H
