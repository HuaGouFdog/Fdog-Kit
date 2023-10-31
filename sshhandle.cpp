#pragma execution_character_set("utf-8")
#pragma comment(lib, "ws2_32.lib")
#include "sshhandle.h"
#include <QObject>
#include <QTextCodec>
#include <QThread>
#include <QTimer>
sshhandle::sshhandle(QObject *parent) : QObject(parent)
{
    qRegisterMetaType<ServerInfoStruct>("ServerInfoStruct&");
}

SOCKET createSocket(const char* host, int port)
{
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        fprintf(stderr, "Failed to initialize Winsock\n");
        return INVALID_SOCKET;
    }

    struct addrinfo hints;
    struct addrinfo* result = NULL;
    struct addrinfo* ptr = NULL;

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    if (getaddrinfo(host, std::to_string(port).c_str(), &hints, &result) != 0) {
        fprintf(stderr, "Failed to get address info\n");
        WSACleanup();
        return INVALID_SOCKET;
    }

    SOCKET sockfd = INVALID_SOCKET;
    for (ptr = result; ptr != NULL; ptr = ptr->ai_next) {
        sockfd = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
        if (sockfd == INVALID_SOCKET) {
            fprintf(stderr, "Failed to create socket\n");
            continue;
        }

        if (connect(sockfd, ptr->ai_addr, (int)ptr->ai_addrlen) == SOCKET_ERROR) {
            closesocket(sockfd);
            sockfd = INVALID_SOCKET;
            continue;
        }

        break;
    }

    freeaddrinfo(result);

    if (sockfd == INVALID_SOCKET) {
        fprintf(stderr, "Failed to connect\n");
        WSACleanup();
        return INVALID_SOCKET;
    }

    return sockfd;
}
void sshhandle::init(int connrectType, QString host, QString port, QString username, QString password)
{
    int rc;

    // 创建套接字并建立连接

    SOCKET sockfd = createSocket("172.16.8.154", 22);
    if (sockfd == INVALID_SOCKET) {
    }

    // 初始化 libssh2 库
    rc = libssh2_init(0);
    if (rc != 0) {
        qWarning() << "libssh2 initialization failed";
        return;
    }

    // 创建 SSH session
    session = libssh2_session_init();
    if (!session) {
        qWarning() << "Failed to create SSH session";
        return;
    }

    // 设置会话选项
    libssh2_session_set_blocking(session, 1);
    libssh2_session_set_timeout(session, 10000);

    // 建立 SSH 连接
    rc = libssh2_session_handshake(session, sockfd);
    if (rc) {
        qWarning() << "SSH handshake failed";
        libssh2_session_free(session);
        return;
    }

    // 进行身份验证
    rc = libssh2_userauth_password(session, username.toUtf8().constData(), password.toUtf8().constData());
    if (rc) {
        qWarning() << "Authentication failed";
        libssh2_session_disconnect(session, "Authentication failed");
        libssh2_session_free(session);
        return;
    }
    //初始化 SFTP 会话
    sftp_session = NULL;
    sftp_session = libssh2_sftp_init(session);
    if (sftp_session == NULL) {
        qDebug() << "初始化失败";
        return;
    }

//    channel = libssh2_channel_open_session(session);
//    // 请求分配伪终端
//    const char* term = "xterm";
//    int ret = libssh2_channel_request_pty_size(channel, 80, 24);
//        qDebug() << "libssh2_channel_request_pty_size = " << ret;
//        // 请求伪终端失败，处理错误
//    ret = libssh2_channel_request_pty(channel, term);
//    if (ret != 0) {
//        qDebug() << "出错" << ret;
//        // 请求伪终端失败，处理错误
//    }
//    //libssh2_channel_handle_extended_data2(channel, SSH_EXTENDED_DATA_STDIN, &handlePseudoTerminalData);
//    libssh2_channel_shell(channel);
//    emit send_init();
    qDebug() << "初始化完成";

//	connect(monitor_thread__, SIGNAL(started()), monitor_timer__, SLOT(start()));
//	connect(monitor_thread__, SIGNAL(finished()), monitor_timer__, SLOT(stop()));


    //getServerInfo();
    return;
}

void sshhandle::init_poll()
{
    //循环监听
    qDebug() << "init_poll初始化完成";
    LIBSSH2_POLLFD *fds = new LIBSSH2_POLLFD;
            fds->type = LIBSSH2_POLLFD_CHANNEL;
            fds->fd.channel = channel;
            fds->events = LIBSSH2_POLLFD_POLLIN | LIBSSH2_POLLFD_POLLOUT;

    while (1) {
        //qDebug() << "循环";
        // 使用libssh2_poll函数等待事件
        int rc = libssh2_poll(fds, 1, 1000);
        if (rc > 0) {
            // 有事件发生，检查revents字段以确定具体事件类型
            if (fds->revents & LIBSSH2_POLLFD_POLLIN) {
                // 可读事件发生，可以读取数据
                // 使用libssh2_channel_read等函数读取数据
                char buffer[4096] = {0};
                int bytesRead;
                //int c = 0;
                //while (c++ < 2) {
                    //qDebug() << "循环";
                    bytesRead = libssh2_channel_read(channel, buffer, sizeof(buffer) - 1);
                    buffer[bytesRead] = '\0';
                    //qDebug() << buffer;
                    //a = buffer;
                    QTest::qSleep(100);
                    //通知ui
                    //processData只处理颜色，属性，类似退格等由sshwidget完成
                    //对内容进行分组处理
                    //QStringList = ac.processDataS(buffer);
                    QString a = ac.processData(buffer);
                    emit send_channel_readS(ac.processDataS(a));
                    //emit send_channel_read(ac.processData(buffer));
                    // 处理输出数据
                    // 例如，将输出数据打印到控制台
                    //std::string aa = sprintf("%.*s", bytesRead, buffer);
                //}
            }

            if (fds->revents & LIBSSH2_POLLFD_POLLOUT) {
                // 可写事件发生，可以写入数据
                // 使用libssh2_channel_write等函数写入数据

            }
        } else if (rc == 0) {
            // 超时，没有事件发生
            //qDebug() << "循环";
            QTest::qSleep(200);
        } else {
            // 发生错误，处理错误
            break;
            QTest::qSleep(200);
        }
    }
}

void sshhandle::channel_write(QString command)
{
    qDebug() << "数据写入 = " << command;
    libssh2_channel_write(channel, command.toStdString().c_str(), strlen(command.toStdString().c_str()));
}

void sshhandle::channel_read(QString command)
{

}

void sshhandle::getServerInfo()
{
    qDebug() << "getServerInfo";
    ServerInfoStruct serverInfo;
    QString commond;
    QString data;
    //获取服务器IP
    commond = "hostname -I";
    QStringList dataList = commondExec(commond).split(" ");
    serverInfo.ip = "IP：" + dataList[0];
    //获取服务器运行时间
    commond = "uptime";
    QStringList dataList2 = commondExec(commond).split(",");
    QStringList dataList3 = dataList2[0].split(" ");
    serverInfo.time = "系统时间：" + dataList3[0];
    qDebug() << "dataList3.length() = " << dataList3.length();
    qDebug() << " 0 = " << dataList3[0];
    qDebug() << " 1 = " << dataList3[1];
    qDebug() << " 2 = " << dataList3[2];
    serverInfo.time = "系统时间：" + dataList3[1];
    if (dataList3.length()==5) {
        serverInfo.runTime = "运行时间：" + dataList3[3] + "天";
    } else {
        serverInfo.runTime = "运行时间：" + dataList2[1];
    }
    //获取服务器信息
    commond = "uname -p -i -o";
    QStringList dataList5 = commondExec(commond).split(" ");
    serverInfo.architecture = "系统架构：" + dataList5[0];// + "/" + dataList5[1];
    QStringList dataList6 = dataList5[2].split("\n");
    serverInfo.systemType = "系统类型：" + dataList6[0];
    //获取服务器登录人数
    commond = "who | wc -l";
    QStringList dataList7 = commondExec(commond).split("\n");
    qDebug() << " 3 = " << dataList7[0];
    serverInfo.loginCount = "终端连接：" + dataList7[0];

    commond = "top -n 1 -b | head -n 20";
    QStringList dataList8 = commondExec(commond).split("\n");
    QStringList dataList8_cpu = dataList8[2].split(" ");
    QStringList dataList8_mem = dataList8[3].split(" ");
    QStringList dataList8_swap = dataList8[4].split(" ");

    qDebug() << " cpu = " << dataList8_cpu[1] + dataList8_cpu[3] << " dataList8_swap = " << dataList8_cpu;
    qDebug() << " mem = " << dataList8_mem[4] + dataList8_mem[5]<< " dataList8_mem = " << dataList8_mem;
    qDebug() << " swap = " << dataList8_swap[3] + dataList8_swap[5]<< " dataList8_swap = " << dataList8_swap;

    double cpuUseRate_ = dataList8_cpu[1].toDouble() + dataList8_cpu[3].toDouble();
    serverInfo.cpuUseRate = QString::number(int(cpuUseRate_)) + "%";

    double memFree_ = dataList8_mem[8].toDouble() + dataList8_mem[14].toDouble();
    double memUse_ =dataList8_mem[4].toDouble() - memFree_;
    serverInfo.memUseRate = QString::number(int(memUse_/dataList8_mem[4].toDouble()*100)) + "%";

    double swapFree_ = dataList8_swap[6].toDouble();
    double swapUse_ = dataList8_swap[3].toDouble() - swapFree_;
    serverInfo.swapUseRate = QString::number(int(swapUse_/dataList8_swap[3].toDouble()*100)) + "%";
    qDebug() << memFree_  << " " << memUse_;
    qDebug() << dataList8_mem[4].toDouble();
    qDebug() << "cpuUseRate" << serverInfo.cpuUseRate;
    qDebug() << "memUseRate" << serverInfo.memUseRate;
    qDebug() << "swapUseRate" << serverInfo.swapUseRate;

    emit send_getServerInfo(serverInfo);
    return;
}

QString sshhandle::commondExec(QString commond)
{
    channel2 = libssh2_channel_open_session(session);
    int rc = libssh2_channel_exec(channel2, commond.toStdString().c_str());
    if (rc != 0) {
        qDebug() << "libssh2_channel_exec faild commond =" << commond;
        return "";
    }

    char buffer[1024] = {0};
    int bytesRead = libssh2_channel_read(channel2, buffer, sizeof(buffer) - 1);
    buffer[bytesRead] = '\0';
    qDebug() << "getServerInfo = " << buffer;
    return buffer;
}
