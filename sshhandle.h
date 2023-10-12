﻿#ifndef SSHHANDLE_H
#define SSHHANDLE_H

#include <QObject>
#include "libssh2.h"
#include <libssh2_sftp.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <QDebug>
#include <QTest>
#include <QTextBlock>
#include "datahandle.h"
#define SSH_PASSWORD 1
#define SSH_SECRET_KEY 2
struct ServerInfoStruct {
    //基础信息
    QString ip;            //ip
    QString time;          //系统时间
    QString runTime;       //运行时间
    QString architecture;  //硬件架构
    QString systemType;    //系统类型
    QString systemName;    //操作系统名称
    QString loginCount;    //当前登录数
    QString cpuUseRate;    //cpu使用率
    QString memUseRate;    //内存使用率
    QString memUse;
    QString swapUseRate;   //交换使用率
    QString swapFree;
    QString swapUse;
};

Q_DECLARE_METATYPE(ServerInfoStruct);

class sshhandle : public QObject
{
    Q_OBJECT
public:
    explicit sshhandle(QObject *parent = nullptr);
    datahandle ac;
    LIBSSH2_SESSION *session;
    LIBSSH2_CHANNEL *channel; //通道
    LIBSSH2_CHANNEL *channel2; //通道2
signals:
    void send_init();
    void send_init_poll();
    void send_channel_write(QString data);
    void send_channel_read(QString data);
    void send_getServerInfo(ServerInfoStruct serverInfo);
public slots:
    //connectAndExecuteCommand(host, port, username, password, command);
    void init(int connrectType, QString host, QString port, QString username, QString password);
    void init_poll();
    void channel_write(QString command);
    void channel_read(QString command);

    void getServerInfo();

    QString commondExec(QString commond);

private:

};

#endif // SSHHANDLE_H