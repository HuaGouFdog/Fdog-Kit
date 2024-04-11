#-------------------------------------------------
#
# Project created by QtCreator 2023-08-08T21:16:39
#
#-------------------------------------------------

QT       += core gui
QT +=testlib
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FdogShell
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    zookeeperwidget.cpp \
    createconnect.cpp \
    zookeeperhandle.cpp \
    sshwidget.cpp \
    sshhandle.cpp \
    datahandle.cpp \
    toolswidget.cpp \
    toolshandle.cpp \
    settingwidget.cpp \
    secretkeywidget.cpp \
    smalltoolwidget.cpp \
    historyconnectwidget.cpp \
    keywidget.cpp \
    utils.cpp \
    colormatch.cpp \
    findwidget.cpp \
    aboutwidget.cpp \
    downloadwidget.cpp \
    mkdirfolderwidget.cpp \
    addcommondwidget.cpp \
    historycommondwidget.cpp \
    config.cpp \
    thriftwidget.cpp \
    zookeepertipswidget.cpp \
    zookeepermanagewidget.cpp

HEADERS += \
        mainwindow.h \
    zookeeperwidget.h \
    createconnect.h \
    zookeeperhandle.h \
    sshwidget.h \
    sshhandle.h \
    datahandle.h \
    toolswidget.h \
    toolshandle.h \
    settingwidget.h \
    secretkeywidget.h \
    smalltoolwidget.h \
    historyconnectwidget.h \
    keywidget.h \
    utils.h \
    colormatch.h \
    findwidget.h \
    aboutwidget.h \
    downloadwidget.h \
    mkdirfolderwidget.h \
    addcommondwidget.h \
    historycommondwidget.h \
    config.h \
    thriftwidget.h \
    zookeepertipswidget.h \
    zookeepermanagewidget.h

FORMS += \
        mainwindow.ui \
    zookeeperwidget.ui \
    createconnect.ui \
    sshwidget.ui \
    toolswidget.ui \
    settingwidget.ui \
    secretkeywidget.ui \
    smalltoolwidget.ui \
    historyconnectwidget.ui \
    keywidget.ui \
    colormatch.ui \
    findwidget.ui \
    aboutwidget.ui \
    downloadwidget.ui \
    mkdirfolderwidget.ui \
    addcommondwidget.ui \
    historycommondwidget.ui \
    thriftwidget.ui \
    zookeepertipswidget.ui \
    zookeepermanagewidget.ui

RESOURCES += \
    lib.qrc \
    conf.qrc \
    fonts.qrc \
    qss.qrc

QT += network

win32: LIBS += -L$$PWD/../zookeeper/lib/ -lzookeeper

INCLUDEPATH += $$PWD/../zookeeper/include
DEPENDPATH += $$PWD/../zookeeper/include

win32: LIBS += -L$$PWD/../libssh2.11.0/lib/ -llibssh2

INCLUDEPATH += $$PWD/../libssh2.11.0/include
DEPENDPATH += $$PWD/../libssh2.11.0/include

LIBS += -luser32

DISTFILES += \
    lib/Fdogicon.ico

RC_ICONS = lib/Fdogicon.ico


QT.testlib.CONFIG -= console

CONFIG += resources_big
