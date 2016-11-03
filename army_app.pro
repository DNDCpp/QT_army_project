#-------------------------------------------------
#
# Project created by QtCreator 2016-09-08T17:03:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QMAKE_MAC_SDK = macosx10.12

TARGET = army_app
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    addsoldierdialog.cpp \
    addgundialog.cpp \
    postdialog.cpp

HEADERS  += widget.h \
    addsoldierdialog.h \
    addgundialog.h \
    postdialog.h

FORMS    += widget.ui \
    addsoldierdialog.ui \
    addgundialog.ui \
    postdialog.ui

RESOURCES += \
    resources.qrc
