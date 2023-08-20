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
#define SSH_PASSWORD 1
#define SSH_SECRET_KEY 2

class sshhandle : public QObject
{
    Q_OBJECT
public:
    explicit sshhandle(QObject *parent = nullptr);
    LIBSSH2_CHANNEL *channel; //通道
signals:
    void send_init();
    void send_init_poll();
    void send_channel_write(QString data);
    void send_channel_read(QString data);
public slots:
    //connectAndExecuteCommand(host, port, username, password, command);
    void init(int connrectType, QString host, QString port, QString username, QString password);
    void init_poll();
    void channel_write(QString command);
    void channel_read(QString command);

private:

};

#endif // SSHHANDLE_H
