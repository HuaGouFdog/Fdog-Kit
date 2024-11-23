#-------------------------------------------------
#
# Project created by QtCreator 2024-11-23T18:21:45
#
#-------------------------------------------------

QT       += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Fdog-Kit-Zookeeper
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
QT +=testlib

SOURCES += \
        main.cpp \
        module_zookeeper/zookeeperwidget.cpp \
        module_zookeeper/zookeeperhandle.cpp \
        module_zookeeper/zookeepertipswidget.cpp \
        module_zookeeper/zookeepermanagewidget.cpp \
        module_sql/sqlhandle.cpp \
        module_utils/utils.cpp \
        mainwindow.cpp

HEADERS += \
        mainwindow.h\
        module_zookeeper/zookeeperwidget.h \
        module_connect/createconnect.h \
        module_zookeeper/zookeeperhandle.h \
        module_zookeeper/zookeepertipswidget.h \
        module_zookeeper/zookeepermanagewidget.h\
        module_utils/utils.h \
        module_sql/sqlhandle.h

FORMS += \
        mainwindow.ui\
        module_zookeeper/zookeeperwidget.ui \
        module_zookeeper/zookeepertipswidget.ui \
        module_zookeeper/zookeepermanagewidget.ui

win32: LIBS += -L$$PWD/../../zookeeper/lib/ -lzookeeper

INCLUDEPATH += $$PWD/../../zookeeper/include
DEPENDPATH += $$PWD/../../zookeeper/include

RESOURCES += \
    lib.qrc \
    fonts.qrc

LIBS += -luser32
