#-------------------------------------------------
#
# Project created by QtCreator 2016-09-08T17:03:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = army_app
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    addsoldierdialog.cpp

HEADERS  += widget.h \
    addsoldierdialog.h

FORMS    += widget.ui \
    addsoldierdialog.ui

RESOURCES += \
    resources.qrc
