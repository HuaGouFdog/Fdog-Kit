#-------------------------------------------------
#
# Project created by QtCreator 2023-08-08T21:16:39
#
#-------------------------------------------------
DEFINES += Q_COMPILER_UNIFORM_INIT
DEFINES+=WIN32_LEAN_AND_MEAN
QT       += core gui
QT +=testlib
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FdogShell
TEMPLATE = app

QMAKE_LFLAGS_WINDOWS += /LARGEADDRESSAWARE

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
    module_database/databasehandle.cpp \
    module_database/databasesql.cpp \
    module_database/databasewidget.cpp \
    module_mainwindow/mainwindow.cpp \
    module_ssh/sshsql.cpp \
    module_thrift/prefabricatedata.cpp \
    module_zookeeper/zookeepersql.cpp \
    module_zookeeper/zookeeperwidget.cpp \
    module_connect/createconnect.cpp \
    module_zookeeper/zookeeperhandle.cpp \
    module_ssh/sshwidget.cpp \
    module_ssh/sshhandle.cpp \
    module_ssh/datahandle.cpp \
    module_tool/toolswidget.cpp \
    module_tool/toolshandle.cpp \
    module_setting/settingwidget.cpp \
    module_connect/secretkeywidget.cpp \
    module_smalltool/smalltoolwidget.cpp \
    module_ssh/historyconnectwidget.cpp \
    module_connect/keywidget.cpp \
    module_utils/utils.cpp \
    module_setting/colormatch.cpp \
    module_ssh/findwidget.cpp \
    module_ssh/downloadwidget.cpp \
    module_ssh/mkdirfolderwidget.cpp \
    module_ssh/addcommondwidget.cpp \
    module_ssh/historycommondwidget.cpp \
    module_utils/config.cpp \
    module_thrift/thriftwidget.cpp \
    module_zookeeper/zookeepermanagewidget.cpp \
    module_utils/flowlayout.cpp \
    module_activate/activate.cpp \
    module_qss/qss.cpp \
    module_ssh/sshwidgetmanagewidget.cpp

HEADERS += \
    module_database/databasehandle.h \
    module_database/databasesql.h \
    module_database/databasewidget.h \
    module_mainwindow/mainwindow.h \
    module_ssh/sshsql.h \
    module_thrift/prefabricatedata.h \
    module_zookeeper/zookeepersql.h \
    module_zookeeper/zookeeperwidget.h \
    module_connect/createconnect.h \
    module_zookeeper/zookeeperhandle.h \
    module_ssh/sshwidget.h \
    module_ssh/sshhandle.h \
    module_ssh/datahandle.h \
    module_tool/toolswidget.h \
    module_tool/toolshandle.h \
    module_setting/settingwidget.h \
    module_connect/secretkeywidget.h \
    module_smalltool/smalltoolwidget.h \
    module_ssh/historyconnectwidget.h \
    module_connect/keywidget.h \
    module_utils/utils.h \
    module_setting/colormatch.h \
    module_ssh/findwidget.h \
    module_ssh/downloadwidget.h \
    module_ssh/mkdirfolderwidget.h \
    module_ssh/addcommondwidget.h \
    module_ssh/historycommondwidget.h \
    module_utils/config.h \
    module_thrift/thriftwidget.h \
    module_zookeeper/zookeepermanagewidget.h \
    module_utils/flowlayout.h \
    module_activate/activate.h \
    module_qss/qss.h \
    module_ssh/sshwidgetmanagewidget.h

FORMS += \
    module_database/databasewidget.ui \
        module_mainwindow/mainwindow.ui \
    module_thrift/prefabricatedata.ui \
    module_zookeeper/zookeeperwidget.ui \
    module_connect/createconnect.ui \
    module_ssh/sshwidget.ui \
    module_tool/toolswidget.ui \
    module_setting/settingwidget.ui \
    module_connect/secretkeywidget.ui \
    module_smalltool/smalltoolwidget.ui \
    module_ssh/historyconnectwidget.ui \
    module_connect/keywidget.ui \
    module_setting/colormatch.ui \
    module_ssh/findwidget.ui \
    module_ssh/downloadwidget.ui \
    module_ssh/mkdirfolderwidget.ui \
    module_ssh/addcommondwidget.ui \
    module_ssh/historycommondwidget.ui \
    module_thrift/thriftwidget.ui \
    module_zookeeper/zookeepermanagewidget.ui \
    module_activate/activate.ui \
    module_qss/qss.ui \
    module_ssh/sshwidgetmanagewidget.ui

RESOURCES += \
    images.qrc \
    lib.qrc \
    conf.qrc \
    fonts.qrc \
    qss.qrc \
    qss_image.qrc

QT += network
QT += charts

LIBS += -ldwmapi

win32: LIBS += -L$$PWD/../../mysql/lib/ -llibmysql

INCLUDEPATH += $$PWD/../../mysql/include
DEPENDPATH += $$PWD/../../mysql/include

win32: LIBS += -L$$PWD/../zookeeper/lib/ -lzookeeper

INCLUDEPATH += $$PWD/../zookeeper/include
DEPENDPATH += $$PWD/../zookeeper/include

win32: LIBS += -L$$PWD/../libssh2.11.0/lib/ -llibssh2

INCLUDEPATH += $$PWD/../libssh2.11.0/include
DEPENDPATH += $$PWD/../libssh2.11.0/include

win32: LIBS += -L$$PWD/../openssl1.1.1k/lib/ -llibssl
win32: LIBS += -L$$PWD/../openssl1.1.1k/lib/ -llibcrypto

INCLUDEPATH += $$PWD/../openssl1.1.1k/include
DEPENDPATH += $$PWD/../openssl1.1.1k/include

LIBS += -luser32

DISTFILES += \
    lib/Fdogicon.ico

RC_ICONS = lib/Fdogicon.ico


//QT.testlib.CONFIG -= console
CONFIG -= console
CONFIG -= resources_big

QT += sql


