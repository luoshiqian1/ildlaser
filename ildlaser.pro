#-------------------------------------------------
#
# Project created by QtCreator 2018-11-05T20:46:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ildlaser
TEMPLATE = app

RC_FILE = logo.rc

SOURCES += main.cpp\
        mainwindow.cpp \
    scene.cpp \
    tools.cpp \
    testtool.cpp \
    serialporttools.cpp

HEADERS  += mainwindow.h \
    scene.h \
    tools.h \
    common.h \
    testtool.h \
    serialporttools.h

FORMS    += mainwindow.ui \
    testtool.ui

RESOURCES += \
    ildlaser.qrc
