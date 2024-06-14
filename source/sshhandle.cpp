#pragma execution_character_set("utf-8")
#pragma comment(lib, "ws2_32.lib")
#include "sshhandle.h"
#include <QObject>
#include <QTextCodec>
#include <QThread>
#include <QTimer>

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

sshhandle::sshhandle(QObject *parent) : QObject(parent)
{
    qRegisterMetaType<ServerInfoStruct>("ServerInfoStruct&");
}

sshhandle::~sshhandle()
{
    qDebug() << "释放连接句柄";
    // libssh2_session_disconnect(session_ssh, "Bye bye... session_ssh");
    // libssh2_session_free(session_ssh);

    // libssh2_session_disconnect(session_exec, "Bye bye... session_exec");
    // libssh2_session_free(session_exec);

    // libssh2_session_disconnect(session_ssh_sftp, "Bye bye... session_ssh_sftp");
    // libssh2_session_free(session_ssh_sftp);
    
    //libssh2_exit();
    qDebug() << "释放连接句柄结束";
}

void sshhandle::initSSH(int connrectType, QString host, QString port, QString username, QString password)
{
    int rc;

    // 创建套接字并建立连接
    
    sockfd = createSocket(host.toStdString().c_str(), port.toInt());
    if (sockfd == INVALID_SOCKET) {
        qDebug() << "createSocket sockfd";
    }

    // 初始化 libssh2 库
    rc = libssh2_init(0);
    if (rc != 0) {
        qDebug() << "libssh2 initialization failed";
        return;
    }

    // 创建 SSH session
    session_ssh = libssh2_session_init();
    if (session_ssh == nullptr) {
        qDebug() << "Failed to create SSH session";
        return;
    }

    // 设置会话选项
    libssh2_session_set_blocking(session_ssh, 1);
    //libssh2_session_set_timeout(session_ssh, 1000);

    // 建立 SSH 连接
    
    for (int i = 0; i < 10; i++) {
        rc = libssh2_session_handshake(session_ssh, sockfd);
        if (rc == 0) {
            qDebug() << "SSH handshake ok";
            break;
        } else {
            qDebug() << "SSH handshake failed rc = " << rc << " i = " << i;
        }
    }
    if (rc) {
        qDebug() << "SSH handshake failed rc = " << rc;
        libssh2_session_disconnect(session_ssh, "Goodbye");
        libssh2_session_free(session_ssh);
        return; 
    }
    qDebug() << "sockfd addr = " << &sockfd << " sockfd = " << sockfd;
    qDebug() << "session_ssh addr = " << &session_ssh << " session_ssh = " << session_ssh;
    // 进行身份验证
    qDebug() << "user = " << username << " password = " << password;
    for (int i = 0; i < 10; i++) {
        rc = libssh2_userauth_password(session_ssh, username.toUtf8().constData(), password.toUtf8().constData());
        if (rc == 0) {
            qDebug() << "initSSH Authentication ok";
            break;
        } else {
            qDebug() << "initSSH Authentication failed rc = " << rc << " i = " << i;
        }
    }
    
    if (rc) {
        qDebug() << "initSSH Authentication failed rc = " << rc;
        //libssh2_session_disconnect(session_ssh, "Authentication failed");
        //libssh2_session_free(session_ssh);
        //close(sockfd);
        return;
    }

    channel_ssh = libssh2_channel_open_session(session_ssh);
    // 请求分配伪终端
    const char* term = "xterm";
    //int ret = libssh2_channel_request_pty_size(channel_ssh, 50, 24);
        //qDebug() << "libssh2_channel_request_pty_size = " << ret;
        // 请求伪终端失败，处理错误
    int ret = libssh2_channel_request_pty(channel_ssh, term);
    if (ret != 0) {
        qDebug() << "出错" << ret;
        // 请求伪终端失败，处理错误
    }
    //ret = libssh2_channel_request_pty_size(channel_ssh, 200, 24);
    //libssh2_channel_handle_extended_data2(channel, SSH_EXTENDED_DATA_STDIN, &handlePseudoTerminalData);
    libssh2_channel_shell(channel_ssh);
    emit send_init();

//	connect(monitor_thread__, SIGNAL(started()), monitor_timer__, SLOT(start()));
//	connect(monitor_thread__, SIGNAL(finished()), monitor_timer__, SLOT(stop()));

    //getServerInfo();
}

void sshhandle::initEXEC(int connrectType, QString host, QString port, QString username, QString password)
{
    int rc;

    // 创建套接字并建立连接

    SOCKET sockfd = createSocket(host.toStdString().c_str(), port.toInt());
    if (sockfd == INVALID_SOCKET) {
    }

    // 初始化 libssh2 库
    rc = libssh2_init(0);
    if (rc != 0) {
        qWarning() << "libssh2 initialization failed";
        return;
    }

    // 创建 SSH session
    session_exec = libssh2_session_init();
    if (!session_exec) {
        qWarning() << "Failed to create SSH session";
        return;
    }

    // 设置会话选项
    libssh2_session_set_blocking(session_exec, 1);
    libssh2_session_set_timeout(session_exec, 10000);

    // 建立 SSH 连接
    rc = libssh2_session_handshake(session_exec, sockfd);
    if (rc) {
        qWarning() << "SSH handshake failed";
        libssh2_session_free(session_exec);
        close(sockfd);
        return;
    }

    // 进行身份验证
    rc = libssh2_userauth_password(session_exec, username.toUtf8().constData(), password.toUtf8().constData());
    if (rc) {
        qWarning() << "initEXEC Authentication failed";
        // libssh2_session_disconnect(session_exec, "Authentication failed");
        // libssh2_session_free(session_exec);
        return;
    }

    channel_exec = libssh2_channel_open_session(session_exec);
    qDebug() << "exec初始化完成";
}

void sshhandle::initSFTP(int connrectType, QString host, QString port, QString username, QString password)
{
    int rc;

    // 创建套接字并建立连接

    SOCKET sockfd = createSocket(host.toStdString().c_str(), port.toInt());
    if (sockfd == INVALID_SOCKET) {
    }

    // 初始化 libssh2 库
    rc = libssh2_init(0);
    if (rc != 0) {
        qWarning() << "libssh2 initialization failed";
        return;
    }

    // 创建 SSH_STFP session
    session_ssh_sftp = libssh2_session_init();
    if (!session_ssh_sftp) {
        qWarning() << "Failed to create SSH session";
        return;
    }

    // 设置会话选项
    libssh2_session_set_blocking(session_ssh_sftp, 1);
    libssh2_session_set_timeout(session_ssh_sftp, 10000);

    // 建立 SSH 连接
    rc = libssh2_session_handshake(session_ssh_sftp, sockfd);
    if (rc) {
        qWarning() << "SSH handshake failed";
        libssh2_session_free(session_ssh_sftp);
        return;
    }

    // 进行身份验证
    rc = libssh2_userauth_password(session_ssh_sftp, username.toUtf8().constData(), password.toUtf8().constData());
    if (rc) {
        qWarning() << "initSFTP Authentication failed";
        // libssh2_session_disconnect(session_ssh_sftp, "Authentication failed");
        // libssh2_session_free(session_ssh_sftp);
        return;
    }
    //初始化 SFTP 会话
    session_sftp = NULL;
    session_sftp = libssh2_sftp_init(session_ssh_sftp);
    if (session_sftp == NULL) {
        qDebug() << "sftp初始化失败";
        return;
    }
    qDebug() << "sftp初始化完成";
    //getServerInfo();
}

void sshhandle::init(int connrectType, QString host, QString port, QString username, QString password)
{
    qDebug() << "执行initSSH" << " host = " << host << " port = " << port << " username = " << username << " password = " << password;
    initSSH(connrectType, host, port, username, password);
    qDebug() << "执行initSSH init 完成";
    ////发送信号
    //emit send_init_ssh_done();
    return;
}

void sshhandle::init_poll()
{
    //循环监听
    qDebug() << "init_poll初始化完成";
    LIBSSH2_POLLFD *fds = new LIBSSH2_POLLFD;
            fds->type = LIBSSH2_POLLFD_CHANNEL;
            fds->fd.channel = channel_ssh;
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
                char buffer[4096 * 100] = {0};
                int bytesRead;
                //int c = 0;
                //while (c++ < 2) {
                    //qDebug() << "循环";
                    bytesRead = libssh2_channel_read(channel_ssh, buffer, sizeof(buffer) - 1);
                    buffer[bytesRead] = '\0';
                    //qDebug() << buffer;
                    //a = buffer;
                    //QTest::qSleep(100);
                    //通知ui
                    //processData只处理颜色，属性，类似退格等由sshwidget完成
                    //对内容进行分组处理
                    //QStringList = ac.processDataS(buffer);
                    QString a = ac.processData(buffer);
                    QStringList dataList = ac.processDataS(a);
                    //qDebug() << "添加工作路径" << ac.ssh_path;
                    if (ac.ssh_path == "") {
                        ac.ssh_path = "~";
                    }
                    dataList.insert(0, ac.ssh_path);
                    emit send_channel_readS(dataList);
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
            //QTest::qSleep(100);
        } else {
            // 发生错误，处理错误
            break;
            //QTest::qSleep(100);
        }
    }
}

void sshhandle::channel_write(QString command)
{
    qDebug() << "数据写入 = " << command;
    libssh2_channel_write(channel_ssh, command.toStdString().c_str(), strlen(command.toStdString().c_str()));
}

void sshhandle::channel_read(QString command)
{

}

void sshhandle::getServerInfo()
{
    //qDebug() << "getServerInfo";
    ServerInfoStruct serverInfo;
    QString commond;
    QString data;
    //获取服务器IP

    commond = "hostname -I";
    QStringList dataList = commondExec(commond).split(" ");
    serverInfo.ip = "IP " + dataList[0];

    commond = "top -n 1 -b | head -n 5";
    QStringList dataList2 = commondExec(commond).split("\n");
    //qDebug() << "top =" << dataList2;

    QRegExp reTime("up ((\\d+) days,)?\\s*(\\d+:\\d+)*\\s*(min)*");
    if (reTime.indexIn(dataList2[0]) != -1) {
        //qDebug() << "运行时间:" << reTime.cap(2); //天
        //qDebug() << "运行时间:" << reTime.cap(3); //时间
        //qDebug() << "运行时间:" << reTime.cap(4); //小时或者分钟 没有就是小时
        if (reTime.cap(2) != "") {
            serverInfo.runTime = "运行 " + reTime.cap(2) + "天";
        } else if (reTime.cap(3) != "" && reTime.cap(4) != "") {
            serverInfo.runTime = "运行 " + reTime.cap(3) + " " + reTime.cap(4);
        } else if (reTime.cap(3) != "") {
            serverInfo.runTime = "运行 " + reTime.cap(3);
        }
    } else {
        qDebug() << "找不到运行时间.";
    }

    // 提取当前用户数
    QRegExp reUsers("(\\d+) user");
    if (reUsers.indexIn(dataList2[0]) != -1) {
        QString users = reUsers.cap(1);
        //qDebug() << "当前用户数:" << users;
        serverInfo.loginCount = "终端用户 " + reUsers.cap(1);
    } else {
        qDebug() << "未找到当前用户数.";
    }

    // 提取负载
    QRegExp reLoad("load average: ([\\d.]+), ([\\d.]+), ([\\d.]+)");
    if (reLoad.indexIn(dataList2[0]) != -1) {
        QString load1 = reLoad.cap(1);
        QString load2 = reLoad.cap(2);
        QString load3 = reLoad.cap(3);
        //qDebug() << "负载:" << load1 << load2 << load3;
        serverInfo.load = "负载 " + reLoad.cap(1) + ", " + reLoad.cap(2) + ", " + reLoad.cap(3);
    } else {
        qDebug() << "未找到负载.";
    }


    // 提取cpu
    QRegExp recpu("(\\d+.\\d+) id");
    if (recpu.indexIn(dataList2[2]) != -1) {
        QString cpu1 = recpu.cap(1);
        serverInfo.cpuUseRate = QString::number((int)(100.00 - recpu.cap(1).toDouble()));
        //qDebug() << "cpu:" << serverInfo.cpuUseRate;
    } else {
        qDebug() << "未找到cpu.";
    }

    //核数
    commond = "grep 'physical id' /proc/cpuinfo | uniq | wc -l";
    QStringList phy = commondExec(commond).split("\n");
    //qDebug() << "核数 " << phy[0];
    //线程数
    commond = "grep 'processor' /proc/cpuinfo | wc -l";
    QStringList pro = commondExec(commond).split("\n");
    //qDebug() << "线程数 " << pro[0];

    serverInfo.cpuInfo = "cpu信息 " + phy[0] + "核" + pro[0] + "线程";

    //提取io
    QRegExp reio("(\\d+.\\d+) wa");
    if (reio.indexIn(dataList2[2]) != -1) {
        QString io1 = reio.cap(1);

        serverInfo.diskUseRate = QString::number(((int)reio.cap(1).toDouble()));
        //qDebug() << "io:" << serverInfo.diskUseRate;
    } else {
        qDebug() << "未找到io.";
    }

    QRegExp reMem("KiB Mem\\s*:\\s*(\\d+) total,\\s*(\\d+) free,\\s*(\\d+) used,\\s*(\\d+) buff/cache");
    if (reMem.indexIn(dataList2[3]) != -1) {
        QString mem1 = reMem.cap(1);
        QString mem2 = reMem.cap(2);
        QString mem3 = reMem.cap(3);
        QString mem4 = reMem.cap(4);
        //qDebug() << "内存:" << mem1 << " " << mem2 << " " << mem3 << " " << mem4;
        serverInfo.memUseRate = QString::number((int)(reMem.cap(2).toDouble() / reMem.cap(1).toDouble() * 100));
        //qDebug() << "内存:" << serverInfo.memUseRate;

        double mem_m = reMem.cap(1).toDouble() / 1024;
        double mem_g =0.0;
        if (mem_m >= 1024) {
            mem_g = mem_m / 1024;
            serverInfo.memUse = "/" + QString::number(mem_g, 'f', 1) + "G";
        } else {
            serverInfo.memUse = "/" + QString::number(mem_m, 'f', 1) + "M";
        }

        double mem_mf = (reMem.cap(2).toDouble()) / 1024;
        double mem_gf =0.0;
        if (mem_mf >= 1024) {
            mem_gf = mem_mf / 1024;
            serverInfo.memUse = QString::number(mem_gf, 'f', 1) + "G" + serverInfo.memUse;
        } else {
            serverInfo.memUse = QString::number(mem_mf, 'f', 1) + "M" + serverInfo.memUse;
        }
        //qDebug() << "内存总共" << mem_g << "G";
        //qDebug() << "当前可用" << mem_gf << "G";
    } else {
        qDebug() << "未找到内存.";
    }

    QRegExp reSwap("KiB Swap\\s*:\\s*(\\d+) total,\\s*(\\d+) free,\\s*(\\d+) used.\\s*(\\d+) avail Mem");
    if (reSwap.indexIn(dataList2[4]) != -1) {
        QString swap1 = reSwap.cap(1);
        QString swap2 = reSwap.cap(2);
        QString swap3 = reSwap.cap(3);
        QString swap4 = reSwap.cap(4);
        //qDebug() << "交换:" << swap1 << " " << swap2 << " " << swap3 << " " << swap4;
        serverInfo.swapUseRate = QString::number(100 - (int)(reSwap.cap(2).toDouble() / reSwap.cap(1).toDouble() * 100));
        //qDebug() << "交换:" << serverInfo.swapUseRate;

        double swap_m = reSwap.cap(1).toDouble() / 1024;
        double swap_g =0.0;
        if (swap_m >= 1024) {
            swap_g = swap_m / 1024;
            serverInfo.swapUse = "/" + QString::number(swap_g, 'f', 1) + "G";
        } else {
            serverInfo.swapUse = "/" + QString::number(swap_m, 'f', 1) + "M";
        }

        double swap_mf = (reSwap.cap(1).toDouble() - reSwap.cap(2).toDouble()) / 1024;
        double swap_gf =0.0;
        if (swap_mf >= 1024) {
            swap_gf = swap_mf / 1024;
            serverInfo.swapUse = QString::number(swap_gf, 'f', 1) + "G" + serverInfo.swapUse;
        } else {
            serverInfo.swapUse = QString::number(swap_mf, 'f', 1) + "M" + serverInfo.swapUse;
        }

    } else {
        //qDebug() << "未找到交换.";
    }

    //获取服务器信息
    commond = "uname -p -i -o";
    QStringList dataList5 = commondExec(commond).split(" ");
    serverInfo.architecture = "系统架构 " + dataList5[0];

    emit send_getServerInfo(serverInfo);
    return;
}

void sshhandle::rece_getServerInfo(ServerInfoStruct serverInfo)
{
    //qDebug() << "收到send_getServerInfo";
    emit send_getServerInfo(serverInfo);
}

QString sshhandle::commondExec(QString commond)
{
    channel_exec = libssh2_channel_open_session(session_exec);
    int rc = libssh2_channel_exec(channel_exec, commond.toStdString().c_str());
    if (rc != 0) {
        qDebug() << "libssh2_channel_exec faild commond =" << commond;
        return "";
    }

    char buffer[1024] = {0};
    int bytesRead = libssh2_channel_read(channel_exec, buffer, sizeof(buffer) - 1);
    buffer[bytesRead] = '\0';
    //qDebug() << "getServerInfo = " << buffer;
    return buffer;
}

sshHandleExec::sshHandleExec(QObject *parent)
{

}

void sshHandleExec::init(int connrectType, QString host, QString port, QString username, QString password)
{
    qDebug() << "执行sshHandleExec init";
    int rc;

    // 创建套接字并建立连接

    SOCKET sockfd = createSocket(host.toStdString().c_str(), port.toInt());
    if (sockfd == INVALID_SOCKET) {
    }

    // 初始化 libssh2 库
    rc = libssh2_init(0);
    if (rc != 0) {
        qWarning() << "libssh2 initialization failed";
        return;
    }

    // 创建 SSH session
    session_exec = libssh2_session_init();
    if (!session_exec) {
        qWarning() << "Failed to create SSH session";
        return;
    }
    qDebug() << "执行sshHandleExec init2";
    // 设置会话选项
    libssh2_session_set_blocking(session_exec, 1);
    //libssh2_session_set_timeout(session_exec, 10000);

    // 建立 SSH 连接
    rc = libssh2_session_handshake(session_exec, sockfd);
    if (rc) {
        qWarning() << "session_exec SSH handshake failed";
        // libssh2_session_disconnect(session_exec, "Authentication failed");
        // libssh2_session_free(session_exec);
        // close(sockfd);
        return;
    }

    // 进行身份验证
    rc = libssh2_userauth_password(session_exec, username.toUtf8().constData(), password.toUtf8().constData());
    if (rc) {
        qWarning() << "session_exec init Authentication failed rc = " << rc;
        // libssh2_session_disconnect(session_exec, "Authentication failed");
        // libssh2_session_free(session_exec);
        // close(sockfd);
        return;
    }

    qDebug() << "执行sshHandleExec init3";

    channel_exec = libssh2_channel_open_session(session_exec);
    while(1) {
        getServerInfo();
        QThread::msleep(1000);
    }

    qDebug() << "执行sshHandleExec init 完成";
    emit send_init();
}

void sshHandleExec::getServerInfo()
{
    //qDebug() << "getServerInfo";
    ServerInfoStruct serverInfo;
    QString commond;
    QString data;
    //获取服务器IP

    commond = "hostname -I";
    QStringList dataList = commondExec(commond).split(" ");
    serverInfo.ip = "IP " + dataList[0];

    commond = "top -n 1 -b | head -n 5";
    QStringList dataList2 = commondExec(commond).split("\n");
    //qDebug() << "top =" << dataList2;

    QRegExp reTime("up ((\\d+) days,)?\\s*(\\d+:\\d+)*\\s*(min)*");
    if (reTime.indexIn(dataList2[0]) != -1) {
        //qDebug() << "运行时间:" << reTime.cap(2); //天
        //qDebug() << "运行时间:" << reTime.cap(3); //时间
        //qDebug() << "运行时间:" << reTime.cap(4); //小时或者分钟 没有就是小时
        if (reTime.cap(2) != "") {
            serverInfo.runTime = "运行 " + reTime.cap(2) + "天";
        } else if (reTime.cap(3) != "" && reTime.cap(4) != "") {
            serverInfo.runTime = "运行 " + reTime.cap(3) + " " + reTime.cap(4);
        } else if (reTime.cap(3) != "") {
            serverInfo.runTime = "运行 " + reTime.cap(3);
        }
    } else {
        //qDebug() << "找不到运行时间.";
    }

    // 提取当前用户数
    QRegExp reUsers("(\\d+) user");
    if (reUsers.indexIn(dataList2[0]) != -1) {
        QString users = reUsers.cap(1);
        //qDebug() << "当前用户数:" << users;
        serverInfo.loginCount = "终端用户 " + reUsers.cap(1);
    } else {
        qDebug() << "未找到当前用户数.";
    }

    // 提取负载
    QRegExp reLoad("load average: ([\\d.]+), ([\\d.]+), ([\\d.]+)");
    if (reLoad.indexIn(dataList2[0]) != -1) {
        QString load1 = reLoad.cap(1);
        QString load2 = reLoad.cap(2);
        QString load3 = reLoad.cap(3);
        //qDebug() << "负载:" << load1 << load2 << load3;
        serverInfo.load = "负载 " + reLoad.cap(1) + ", " + reLoad.cap(2) + ", " + reLoad.cap(3);
    } else {
        qDebug() << "未找到负载.";
    }


    // 提取cpu
    QRegExp recpu("(\\d+.\\d+) id");
    if (recpu.indexIn(dataList2[2]) != -1) {
        QString cpu1 = recpu.cap(1);
        serverInfo.cpuUseRate = QString::number((int)(100.00 - recpu.cap(1).toDouble()));
        //qDebug() << "cpu:" << serverInfo.cpuUseRate;
    } else {
        qDebug() << "未找到cpu.";
    }

    //核数
    commond = "grep 'physical id' /proc/cpuinfo | uniq | wc -l";
    QStringList phy = commondExec(commond).split("\n");
    //qDebug() << "核数 " << phy[0];
    //线程数
    commond = "grep 'processor' /proc/cpuinfo | wc -l";
    QStringList pro = commondExec(commond).split("\n");
    //qDebug() << "线程数 " << pro[0];

    serverInfo.cpuInfo = "cpu信息 " + phy[0] + "核" + pro[0] + "线程";

    //提取io
    QRegExp reio("(\\d+.\\d+) wa");
    if (reio.indexIn(dataList2[2]) != -1) {
        QString io1 = reio.cap(1);

        serverInfo.diskUseRate = QString::number(((int)reio.cap(1).toDouble()));
        //qDebug() << "io:" << serverInfo.diskUseRate;
    } else {
        qDebug() << "未找到io.";
    }

    QRegExp reMem("KiB Mem\\s*:\\s*(\\d+) total,\\s*(\\d+) free,\\s*(\\d+) used,\\s*(\\d+) buff/cache");
    if (reMem.indexIn(dataList2[3]) != -1) {
        QString mem1 = reMem.cap(1);
        QString mem2 = reMem.cap(2);
        QString mem3 = reMem.cap(3);
        QString mem4 = reMem.cap(4);
        //qDebug() << "内存:" << mem1 << " " << mem2 << " " << mem3 << " " << mem4;
        serverInfo.memUseRate = QString::number(100 - (int)(reMem.cap(2).toDouble() / reMem.cap(1).toDouble() * 100));
        //qDebug() << "内存:" << serverInfo.memUseRate;

        double mem_m = (reMem.cap(1).toDouble()) / 1024;
        double mem_g =0.0;
        if (mem_m >= 1024) {
            mem_g = mem_m / 1024;
            serverInfo.memUse = "/" + QString::number(mem_g, 'f', 1) + "G ";
        } else {
            serverInfo.memUse = "/" + QString::number(mem_m, 'f', 1) + "M ";
        }

        double mem_mf = (reMem.cap(1).toDouble() - reMem.cap(2).toDouble()) / 1024;
        double mem_gf =0.0;
        if (mem_mf >= 1024) {
            mem_gf = mem_mf / 1024;
            serverInfo.memUse = QString::number(mem_gf, 'f', 1) + "G " + serverInfo.memUse;
        } else {
            serverInfo.memUse = QString::number(mem_mf, 'f', 1) + "M " + serverInfo.memUse;
        }
        //qDebug() << "内存总共" << mem_g << "G";
        //qDebug() << "当前可用" << mem_gf << "G";
    } else {
        qDebug() << "未找到内存.";
    }

    QRegExp reSwap("KiB Swap\\s*:\\s*(\\d+) total,\\s*(\\d+) free,\\s*(\\d+) used.\\s*(\\d+) avail Mem");
    if (reSwap.indexIn(dataList2[4]) != -1) {
        QString swap1 = reSwap.cap(1);
        QString swap2 = reSwap.cap(2);
        QString swap3 = reSwap.cap(3);
        QString swap4 = reSwap.cap(4);
        //qDebug() << "交换:" << swap1 << " " << swap2 << " " << swap3 << " " << swap4;
        serverInfo.swapUseRate = QString::number(100 - (int)(reSwap.cap(2).toDouble() / reSwap.cap(1).toDouble() * 100));
        //qDebug() << "交换:" << serverInfo.swapUseRate;

        double swap_m = reSwap.cap(1).toDouble() / 1024;
        double swap_g =0.0;
        if (swap_m >= 1024) {
            swap_g = swap_m / 1024;
            serverInfo.swapUse = "/" + QString::number(swap_g, 'f', 1) + "G";
        } else {
            serverInfo.swapUse = "/" + QString::number(swap_m, 'f', 1) + "M";
        }

        double swap_mf = (reSwap.cap(1).toDouble() - reSwap.cap(2).toDouble()) / 1024;
        double swap_gf =0.0;
        if (swap_mf >= 1024) {
            swap_gf = swap_mf / 1024;
            serverInfo.swapUse = QString::number(swap_gf, 'f', 1) + "G" + serverInfo.swapUse;
        } else {
            serverInfo.swapUse = QString::number(swap_mf, 'f', 1) + "M" + serverInfo.swapUse;
        }

    } else {
        //qDebug() << "未找到交换.";
    }

    //获取服务器信息
    commond = "uname -p -i -o";
    QStringList dataList5 = commondExec(commond).split(" ");
    serverInfo.architecture = "系统架构 " + dataList5[0];
    emit send_getServerInfo(serverInfo);
    return;
}

QString sshHandleExec::commondExec(QString commond)
{
    channel_exec = libssh2_channel_open_session(session_exec);
    int rc = libssh2_channel_exec(channel_exec, commond.toStdString().c_str());
    if (rc != 0) {
        qDebug() << "libssh2_channel_exec faild commond =" << commond << " rc = " << rc;
        return "";
    }

    char buffer[1024] = {0};
    int bytesRead = libssh2_channel_read(channel_exec, buffer, sizeof(buffer) - 1);
    buffer[bytesRead] = '\0';
    //qDebug() << "getServerInfo = " << buffer;
    libssh2_channel_close(channel_exec);
    return buffer;
}

sshHandleSftp::sshHandleSftp(QObject *parent)
{
    qRegisterMetaType<int64_t>("int64_t");
}


bool sshHandleSftp::uploadFile(QString local_file_path, QString remote_file_path, QString fileName)
{
    //调子线程执行
    qDebug() << "开始上传 local_file_path = " << local_file_path << " remote_file_path = " << remote_file_path;
    QTextCodec *code = QTextCodec::codecForName("GB2312");
    std::string name = code->fromUnicode(local_file_path.toStdString().c_str()).data();
    // 打开本地文件
    FILE *local_file = NULL;
    local_file= fopen(name.c_str(), "rb");
    if (local_file == NULL) {
        qDebug() << "打开文件失败";
        // 处理本地文件打开失败的情况
        //libssh2_sftp_shutdown(sftp_session);
        //libssh2_session_disconnect(session, "Failed to open local file");
        //libssh2_session_free(session);
        //libssh2_exit();
        return false;
    } else {
        qDebug() << "打开文件成功";
    }

    fseek(local_file, 0, SEEK_END);
    //获取文件指针的位置，此时就相当于文件大小了
    int filesize = ftell(local_file);
    //文件指针移到文件开头
    fseek(local_file, 0, SEEK_SET);

    qDebug() << "文件大小为" << filesize;
    emit send_createNewFile_sgin(local_file_path, fileName, 2, filesize);
    int sum = 0;

    handle_sftp = NULL;
    handle_sftp = libssh2_sftp_open(session_sftp, remote_file_path.toStdString().c_str(),
                                                            LIBSSH2_FXF_WRITE | LIBSSH2_FXF_CREAT | LIBSSH2_FXF_TRUNC,
                                                            LIBSSH2_SFTP_S_IRUSR | LIBSSH2_SFTP_S_IWUSR);
    if (handle_sftp == NULL) {
        qDebug() << "sftp_handle失败";
        int error_code = libssh2_sftp_last_error(session_sftp);
        qDebug() << "Failed to open file: " << error_code;
        // 处理远程文件创建失败的情况
        fclose(local_file);
        libssh2_sftp_shutdown(session_sftp);
        //            libssh2_session_disconnect(session, "Failed to create remote file");
        //libssh2_session_free(session_ssh_sftp);
        //            libssh2_exit();
        return false;
    } else {
        qDebug() << "sftp_handle成功";
    }


    // 读取本地文件内容并写入到远程文件
    char buffer[100000 * 2] = { 0 }; //100000 * 2

    /* 上传数据 */
    QElapsedTimer timer;
    timer.start(); // 启动计时器
    while (TRUE){
        int nread = fread(buffer, 1,sizeof(buffer), local_file);
        if(nread <= 0) {
            break;
        }
        for(char * ptr = buffer; nread;){
            //qDebug() << "循环读取1";
            //发现个问题 这个函数最高只能写入30000字节数据 所以调太大是没用的 后来还发现如果缓冲区设成30000 上传速度也会变慢
            // 必须高于30000的2倍数 所以 我设置成了2倍
            int len = libssh2_sftp_write(handle_sftp, ptr, nread);
            //qDebug() << "nread = " << len;
            //发送进度条
            sum = sum + len;
            emit send_fileProgress_sgin(sum, filesize);
            if(len <= 0) {
                break;
            }
            ptr += len;
            nread -= len;
        }
    }
    qint64 elapsedTime = timer.elapsed(); // 获取经过的时间，单位为毫秒
    qDebug() << "Elapsed Time:" << elapsedTime << "ms";
    qDebug() <<"上传完成";
    // 关闭文件句柄和本地文件
    libssh2_sftp_close(handle_sftp);
    fclose(local_file);

    // 断开 SSH 连接和释放会话
    //libssh2_sftp_shutdown(session_sftp);
    //        libssh2_session_disconnect(session, "Upload complete");
    //libssh2_session_free(session_ssh_sftp);
    //        libssh2_exit();
    return true;
}

bool sshHandleSftp::downloadFile(QString remote_file_path, QString local_file_path, QString fileName)
{
    session_sftp = NULL;
    session_sftp = libssh2_sftp_init(session_ssh_sftp);
    if (session_sftp == NULL) {
        qDebug() << "sftp初始化失败";
        return false;
    }
    //qDebug() << " 执行sshHandleSftp init 完成";

    handle_sftp = NULL;
    handle_sftp = libssh2_sftp_open(session_sftp, remote_file_path.toStdString().c_str(), LIBSSH2_FXF_READ, 0);
    if (handle_sftp == NULL) {
        qDebug() << "sftp_handle失败";
        int error_code = libssh2_sftp_last_error(session_sftp);
        qDebug() << "Failed to open file: " << error_code;
        // 处理远程文件创建失败的情况
        //fclose(local_file);
        libssh2_sftp_shutdown(session_sftp);
        //            libssh2_session_disconnect(session, "Failed to create remote file");
        //libssh2_session_free(session_ssh_sftp);
        //            libssh2_exit();
        return false;
    } else {
        qDebug() << "sftp_handle成功";
    }
    //qDebug() << "downloadFile";
    LIBSSH2_SFTP_ATTRIBUTES attrs;
    int rc = libssh2_sftp_fstat(handle_sftp, &attrs);
    int filesize;
    if (attrs.flags & LIBSSH2_SFTP_ATTR_SIZE) {
        filesize = attrs.filesize;
        //qDebug() << "文件大小为" << filesize;
        emit send_createNewFile_sgin(local_file_path, fileName, 1, filesize);
        //qDebug() << "rc = " << rc;
    }

    QTextCodec *code = QTextCodec::codecForName("GB2312");
    std::string name = code->fromUnicode(local_file_path.toStdString().c_str()).data();
    // 打开本地文件
    FILE *local_file = NULL;
    local_file= fopen(name.c_str(), "wb");
    if (local_file == NULL) {
        qDebug() << "打开文件失败";
        // 处理本地文件打开失败的情况
        //libssh2_sftp_shutdown(sftp_session);
        //libssh2_session_disconnect(session, "Failed to open local file");
        //libssh2_session_free(session);
        //libssh2_exit();
        return false;
    } else {
        qDebug() << "打开文件成功";
    }

    int sum = 0;

    //QElapsedTimer timer;
    //timer.start(); // 启动计时器

    rc = 0;
    char mem[40960] = { 0 };
    while (0 < (rc = libssh2_sftp_read(handle_sftp, mem, sizeof(mem))))
    {
        //qDebug() << "nread = " << rc;
        fwrite(mem, rc, 1, local_file);
        sum = sum + rc;
        emit send_fileProgress_sgin(sum, filesize);
        memset(mem, 0, sizeof(mem));
    }

    //qint64 elapsedTime = timer.elapsed(); // 获取经过的时间，单位为毫秒
    //qDebug() << "Elapsed Time:" << elapsedTime << "ms";
    qDebug() << "下载完成";
    libssh2_sftp_close(handle_sftp);
    fclose(local_file);
    // 断开 SSH 连接和释放会话
    //libssh2_sftp_shutdown(session_sftp);
    //        libssh2_session_disconnect(session, "DownLaod complete");
    //libssh2_session_free(session_ssh_sftp);
    //        libssh2_exit();
    return true;
}

void sshHandleSftp::init(int connrectType, QString host, QString port, QString username, QString password)
{
    qDebug() << " 执行sshHandleSftp init";
    int rc;
    // 创建套接字并建立连接

    SOCKET sockfd = createSocket(host.toStdString().c_str(), port.toInt());
    if (sockfd == INVALID_SOCKET) {
    }

    // 初始化 libssh2 库
    rc = libssh2_init(0);
    if (rc != 0) {
        qWarning() << "libssh2 initialization failed";
        return;
    }

    // 创建 SSH_STFP session
    session_ssh_sftp = libssh2_session_init();
    if (!session_ssh_sftp) {
        qWarning() << "Failed to create SSH session";
        return;
    }

    qDebug() << " 执行sshHandleSftp init2";

    // 设置会话选项
    libssh2_session_set_blocking(session_ssh_sftp, 1);
    //libssh2_session_set_timeout(session_ssh_sftp, 10000);

    // 建立 SSH 连接
    rc = libssh2_session_handshake(session_ssh_sftp, sockfd);
    if (rc) {
        qWarning() << "SSH handshake failed";
        libssh2_session_free(session_ssh_sftp);
        return;
    }

    // 进行身份验证
    rc = libssh2_userauth_password(session_ssh_sftp, username.toUtf8().constData(), password.toUtf8().constData());
    if (rc) {
        qWarning() << "session_ssh_sftp init Authentication failed";
        // libssh2_session_disconnect(session_ssh_sftp, "Authentication failed");
        // libssh2_session_free(session_ssh_sftp);
        // close(sockfd);
        return;
    }
    qDebug() << " 执行sshHandleSftp init3";
    session_sftp = NULL;
    session_sftp = libssh2_sftp_init(session_ssh_sftp);
    if (session_sftp == NULL) {
        qDebug() << "sftp初始化失败";
        return;
    }
    qDebug() << " 执行sshHandleSftp init 完成";
}

