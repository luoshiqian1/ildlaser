#-------------------------------------------------
#
# Project created by QtCreator 2018-11-05T20:46:57
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ildlaser
TEMPLATE = app

INCLUDEPATH += $$PWD/include/QsLog/QsLog.h \
               $$PWD/include/QsLog/QsLogDest.h \
               $$PWD/include/QsLog/QsLogDestConsole.h \
               $$PWD/include/QsLog/QsLogDestFile.h \
               $$PWD/include/QsLog/QsLogDestFunctor.h \
               $$PWD/include/QsLog/QsLogDisableForThisFile.h \
               $$PWD/include/QsLog/QsLogLevel.h

LIBS += QsLog2.lib

SOURCES += main.cpp\
        mainwindow.cpp \
    scene.cpp \
    tools.cpp \
    testtool.cpp \
    serialthread.cpp \
    gam.cpp \
    log.cpp \
    plt.cpp

HEADERS  += mainwindow.h \
    scene.h \
    tools.h \
    common.h \
    testtool.h \
    serialthread.h \
    gam.h \
    log.h \
    qslog/QsLog.h \
    qslog/QsLogDest.h \
    qslog/QsLogDestConsole.h \
    qslog/QsLogDestFile.h \
    qslog/QsLogDestFunctor.h \
    qslog/QsLogDisableForThisFile.h \
    qslog/QsLogLevel.h \
    plt.h

FORMS    += mainwindow.ui \
    testtool.ui

RESOURCES += \
    ildlaser.qrc
