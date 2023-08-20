#pragma execution_character_set("utf-8")
#pragma comment(lib, "ws2_32.lib")
#include "sshhandle.h"
#include <QObject>
sshhandle::sshhandle(QObject *parent) : QObject(parent)
{

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
    LIBSSH2_SESSION *session = libssh2_session_init();
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

    channel = libssh2_channel_open_session(session);

    // 请求分配伪终端
    const char* term = "xterm";
    int ret = libssh2_channel_request_pty(channel, term);
    if (ret != 0) {
        qDebug() << "出错" << ret;
        // 请求伪终端失败，处理错误
    }
    libssh2_channel_shell(channel);
    emit send_init();
    qDebug() << "初始化完成";
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
                    qDebug() << "循环";
                    bytesRead = libssh2_channel_read(channel, buffer, sizeof(buffer) - 1);
                    buffer[bytesRead] = '\0';
                    qDebug() << buffer;
                    //a = buffer;
                    //QTest::qSleep(100);
                    //通知ui
                    emit send_channel_read(buffer);
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
        } else {
            // 发生错误，处理错误
            break;
        }
    }
}

void sshhandle::channel_write(QString command)
{
    qDebug() << "数据写入";
    libssh2_channel_write(channel, command.toStdString().c_str(), strlen(command.toStdString().c_str()));
}

void sshhandle::channel_read(QString command)
{

}
