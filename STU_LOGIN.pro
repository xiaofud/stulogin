#-------------------------------------------------
#
# Project created by QtCreator 2015-08-06T19:04:53
#
#-------------------------------------------------

QT       += core gui	\
	    network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = STU_LOGIN
TEMPLATE = app


SOURCES += main.cpp\
        loginwindow.cpp \
    stulogin.cpp \
    account.cpp \
    suspendingwindow.cpp \
    auxiliary.cpp \
    exaccount.cpp \
    clientdialog.cpp

HEADERS  += loginwindow.h \
    stulogin.h \
    account.h \
    suspendingwindow.h \
    auxiliary.h \
    exaccount.h \
    clientdialog.h

FORMS    += loginwindow.ui \
    suspendingwindow.ui \
    clientdialog.ui

RESOURCES += \
    resource/icons/icons.qrc

DISTFILES += \
    myRc.rc

RC_FILE = \
    myRc.rc
