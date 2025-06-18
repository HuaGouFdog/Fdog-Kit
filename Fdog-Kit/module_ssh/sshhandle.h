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
#include "module_utils/utils.h"
#include <QThread>

#define SSH_PASSWORD "1"
#define SSH_PUBLICKEY  "2"

Q_DECLARE_METATYPE(ServerInfoStruct);

class sshHandleExec : public QObject {
    Q_OBJECT
public:
    explicit sshHandleExec(QObject *parent = nullptr);
    ~sshHandleExec();
    void getServerInfo();
signals:
    void send_getServerInfo(ServerInfoStruct serverInfo);
    void send_execCommand(QString command);
    void send_init(bool isok);
public slots:
    void init(int connrectType, QString host, QString port, QString username, QString password, QString command);
    QString commondExec(QString commond);
private:
    LIBSSH2_SESSION *session_exec = nullptr; //exec session
    LIBSSH2_CHANNEL *channel_exec = nullptr; //exec channel
    int connrectType;
    QString host;
    QString port;
    QString username;
    QString password;

    bool isOK = false;
    bool isBreak = false;
};

class sshHandleSftp : public QObject {
    Q_OBJECT
public:
    explicit sshHandleSftp(QObject *parent = nullptr);
    ~sshHandleSftp();
    //void getServerInfo();
    //QString commondExec(QString commond);
signals:
    //void send_getServerInfo(ServerInfoStruct serverInfo);
    void send_createNewFile_sgin(QString filePath = "", QString fileName = "", int fileType = -1, int64_t fileSize = 0);
    void send_fileProgress_sgin(int64_t sum, int64_t filesize, int status = 0);
public slots:
    void init(int connrectType, QString host, QString port, QString username, QString password);
    bool uploadFile(QString local_file_path, QString remote_file_path, QString fileName);
    bool downloadFile(QString remote_file_path, QString local_file_path, QString fileName, int status);
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
    bool isOK = false;
    bool isBreak = false;

    // LIBSSH2_SESSION *session_exec = nullptr; //exec session
    // LIBSSH2_CHANNEL *channel_exec = nullptr; //exec channel

    // LIBSSH2_SESSION *       session_ssh_sftp = nullptr;   //exec session
    // LIBSSH2_SFTP*           session_sftp = nullptr;       //sftp
    // LIBSSH2_SFTP_HANDLE *   handle_sftp = nullptr;        //sftp

    //void handlechannel_readS(QStringList data);
signals:
    void send_init(bool isok);
    void send_init_poll();
    void send_channel_write(QString data);
    void send_channel_read(QString data);
    void send_channel_readS(QStringList data);
    void send_getServerInfo(ServerInfoStruct serverInfo);
public slots:

    void init(int connrectType, QString host, QString port, QString username, QString password, QString sshType = SSH_PASSWORD, QString publickey = 0, int visibleLines = 24, int visibleColumns = 80);
    void init_poll();
    void channel_write(QString command);
    void channel_read(QString command);
    //void getServerInfo();
    //void rece_getServerInfo(ServerInfoStruct serverInfo);
    //QString commondExec(QString commond);

private:
    QVector<QStringList> messageList;
};

#endif // SSHHANDLE_H
