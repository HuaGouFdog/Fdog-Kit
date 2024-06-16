#ifndef SSHHANDLE_H
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
#include "historycommondwidget.h"
#include <QThread>

#define SSH_PASSWORD 1
#define SSH_SECRET_KEY 2
struct ServerInfoStruct {
    //基础信息
    QString ip;            //ip
    QString runTime;       //运行时间
    QString architecture;  //硬件架构
    QString cpuInfo;       //CPU信息
    QString systemName;    //操作系统名称
    QString loginCount;    //当前登录数

    QString cpuUseRate;    //cpu使用率
    QString memUseRate;    //内存使用率
    QString swapUseRate;   //交换使用率
    QString diskUseRate;   //磁盘使用率

    QString memUse;
    QString swapUse;
    //QString swapFree;

    QString load; //负载

    QString time;          //系统时间
};

Q_DECLARE_METATYPE(ServerInfoStruct);

class sshHandleExec : public QObject {
    Q_OBJECT
public:
    explicit sshHandleExec(QObject *parent = nullptr);
    void getServerInfo();
    QString commondExec(QString commond);
signals:
    void send_getServerInfo(ServerInfoStruct serverInfo);
    void send_init(bool isok);
public slots:
    void init(int connrectType, QString host, QString port, QString username, QString password);
private:
    LIBSSH2_SESSION *session_exec = nullptr; //exec session
    LIBSSH2_CHANNEL *channel_exec = nullptr; //exec channel
    int connrectType;
    QString host;
    QString port;
    QString username;
    QString password;
};

class sshHandleSftp : public QObject {
    Q_OBJECT
public:
    explicit sshHandleSftp(QObject *parent = nullptr);
    //void getServerInfo();
    //QString commondExec(QString commond);
signals:
    //void send_getServerInfo(ServerInfoStruct serverInfo);
    void send_createNewFile_sgin(QString filePath = "", QString fileName = "", int fileType = -1, int64_t fileSize = 0);
    void send_fileProgress_sgin(int64_t sum, int64_t filesize);
public slots:
    void init(int connrectType, QString host, QString port, QString username, QString password);
    bool uploadFile(QString local_file_path, QString remote_file_path, QString fileName);
    bool downloadFile(QString remote_file_path, QString local_file_path, QString fileName);
private:
    LIBSSH2_SESSION *       session_ssh_sftp = nullptr;   //exec session
    LIBSSH2_SFTP*           session_sftp = nullptr;       //sftp
    LIBSSH2_SFTP_HANDLE *   handle_sftp = nullptr;        //sftp
    int connrectType;
    QString host;
    QString port;
    QString username;
    QString password;
};

class sshhandle : public QObject
{
    Q_OBJECT
public:
    explicit sshhandle(QObject *parent = nullptr);
    ~sshhandle();
    datahandle ac;
    SOCKET sockfd;
    LIBSSH2_SESSION *session_ssh = nullptr;  //ssh session
    LIBSSH2_CHANNEL *channel_ssh = nullptr;  //ssh channel

    LIBSSH2_SESSION *session_exec = nullptr; //exec session
    LIBSSH2_CHANNEL *channel_exec = nullptr; //exec channel

    LIBSSH2_SESSION *       session_ssh_sftp = nullptr;   //exec session
    LIBSSH2_SFTP*           session_sftp = nullptr;       //sftp
    LIBSSH2_SFTP_HANDLE *   handle_sftp = nullptr;        //sftp

    //void handlechannel_readS(QStringList data);
signals:
    void send_init(bool isok);
    void send_init_poll();
    void send_channel_write(QString data);
    void send_channel_read(QString data);
    void send_channel_readS(QStringList data);
    void send_getServerInfo(ServerInfoStruct serverInfo);
public slots:

    void init(int connrectType, QString host, QString port, QString username, QString password);
    void init_poll();
    void channel_write(QString command);
    void channel_read(QString command);
    void getServerInfo();
    void rece_getServerInfo(ServerInfoStruct serverInfo);
    QString commondExec(QString commond);

private:
    QVector<QStringList> messageList;
};

#endif // SSHHANDLE_H
