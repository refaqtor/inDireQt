#-------------------------------------------------
#
# Project created by QtCreator 2015-07-12T00:59:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qt-stdio-process
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    processconnection.cpp \
    processconnectiontablemodel.cpp

HEADERS  += mainwindow.h \
    processconnection.h \
    processconnectiontablemodel.h

FORMS    += mainwindow.ui

RESOURCES += \
    resources.qrc
