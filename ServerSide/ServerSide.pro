#-------------------------------------------------
#
# Project created by QtCreator 2015-08-29T10:04:27
#
#-------------------------------------------------

QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ServerSide
TEMPLATE = app


SOURCES += main.cpp\
        serverwidget.cpp \
    exaccount.cpp \
    qsqlitetablemanager.cpp

HEADERS  += serverwidget.h \
    exaccount.h \
    qsqlitetablemanager.h

FORMS    += serverwidget.ui
