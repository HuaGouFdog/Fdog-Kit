#pragma execution_character_set("utf-8")
#pragma comment(lib, "ws2_32.lib")
#include "sshwidget.h"
#include "ui_sshwidget.h"
#include "libssh2.h"
#include <libssh2_sftp.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <QDebug>
#include <QTest>
#include <QTextBlock>
QString a = "";


enum state
{
    INCOMPLETED,
    COMPLETED,
    TIMEOUT
};

ssize_t handle_read(LIBSSH2_CHANNEL *channel, char *buffer, size_t buf_size, enum state *state, int timeout)
{
    LIBSSH2_POLLFD fds;
    fds.type = LIBSSH2_POLLFD_CHANNEL;
    fds.fd.channel = channel;
    fds.events = LIBSSH2_POLLFD_POLLIN | LIBSSH2_POLLFD_POLLOUT;

    ssize_t read_size = 0;
    while (timeout > 0)
    {
        int rc = (libssh2_poll(&fds, 1, 10));
        if (rc < 1)
        {
            timeout -= 10;
            QTest::qSleep(10);
            continue;
        }

        if (fds.revents & LIBSSH2_POLLFD_POLLIN)
        {
            int n = libssh2_channel_read(channel, &buffer[read_size], buf_size - read_size);
            if (n == LIBSSH2_ERROR_EAGAIN)
            {
                continue;
            }
            else if (n < 0)
            {
                *state = COMPLETED;
                return read_size;
            }
            else
            {
                read_size += n;
                if (libssh2_channel_eof(channel))
                {
                    *state = COMPLETED;
                    return read_size;
                }
                char end = buffer[read_size - 2];
                if (end == '$' || end == '#')
                {
                    *state = COMPLETED;
                    return read_size;
                }
            }
            if (read_size == buf_size)
            {
                *state = INCOMPLETED;
                return read_size;
            }
        }
        QTest::qSleep(10);
        timeout -= 10;
    }

    *state = TIMEOUT;
    return 0;
}

void handle_loop(LIBSSH2_CHANNEL *channel)
{
    char buffer[8192];
    char cmd[64];
    int len = 0;
    ssize_t n;
    while (1)
    {
        enum state state = INCOMPLETED;
        do
        {
            n = handle_read(channel, buffer, sizeof(buffer) - 1, &state, 3000);
            if (state == TIMEOUT)
            {
                if (len > 0)
                {
                    cmd[len - 1] = 0;
                }
                printf("exec cmd:`%s` timeout\n", cmd);
                break;
            }
            buffer[n] = 0;
            if (len > 0)
            {
                printf("%s", &buffer[len + 1]);
                len = 0;
            }
            else
            {
                printf("%s", buffer);
            }
        } while (state == INCOMPLETED);

        fgets(cmd, sizeof(cmd), stdin);
        len = strlen(cmd);
        libssh2_channel_write(channel, cmd, len);
    }
    libssh2_channel_close(channel);
}

// 建立 TCP 连接并返回套接字句柄
//SOCKET createSocket(const char* host, int port)
//{
//    WSADATA wsaData;
//    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
//        fprintf(stderr, "Failed to initialize Winsock\n");
//        return INVALID_SOCKET;
//    }

//    struct addrinfo hints;
//    struct addrinfo* result = NULL;
//    struct addrinfo* ptr = NULL;

//    ZeroMemory(&hints, sizeof(hints));
//    hints.ai_family = AF_UNSPEC;
//    hints.ai_socktype = SOCK_STREAM;
//    hints.ai_protocol = IPPROTO_TCP;

//    if (getaddrinfo(host, std::to_string(port).c_str(), &hints, &result) != 0) {
//        fprintf(stderr, "Failed to get address info\n");
//        WSACleanup();
//        return INVALID_SOCKET;
//    }

//    SOCKET sockfd = INVALID_SOCKET;
//    for (ptr = result; ptr != NULL; ptr = ptr->ai_next) {
//        sockfd = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
//        if (sockfd == INVALID_SOCKET) {
//            fprintf(stderr, "Failed to create socket\n");
//            continue;
//        }

//        if (connect(sockfd, ptr->ai_addr, (int)ptr->ai_addrlen) == SOCKET_ERROR) {
//            closesocket(sockfd);
//            sockfd = INVALID_SOCKET;
//            continue;
//        }

//        break;
//    }

//    freeaddrinfo(result);

//    if (sockfd == INVALID_SOCKET) {
//        fprintf(stderr, "Failed to connect\n");
//        WSACleanup();
//        return INVALID_SOCKET;
//    }

//    return sockfd;
//}

//void connectAndExecuteCommand(const QString& host, int port, const QString& username, const QString& password, const QString& command)
//{
//    int rc;

//    // 创建套接字并建立连接
//    SOCKET sockfd = createSocket("172.16.8.154", port);
//    if (sockfd == INVALID_SOCKET) {
//    }

//    // 初始化 libssh2 库
//    rc = libssh2_init(0);
//    if (rc != 0) {
//        qWarning() << "libssh2 initialization failed";
//        return;
//    }

//    // 创建 SSH session
//    LIBSSH2_SESSION *session = libssh2_session_init();
//    if (!session) {
//        qWarning() << "Failed to create SSH session";
//        return;
//    }

//    // 设置会话选项
//    libssh2_session_set_blocking(session, 1);
//    libssh2_session_set_timeout(session, 10000);

//    // 建立 SSH 连接
//    rc = libssh2_session_handshake(session, sockfd);
//    if (rc) {
//        qWarning() << "SSH handshake failed";
//        libssh2_session_free(session);
//        return;
//    }

//    // 进行身份验证
//    rc = libssh2_userauth_password(session, username.toUtf8().constData(), password.toUtf8().constData());
//    if (rc) {
//        qWarning() << "Authentication failed";
//        libssh2_session_disconnect(session, "Authentication failed");
//        libssh2_session_free(session);
//        return;
//    }




//    // 执行命令
//    LIBSSH2_CHANNEL *channel = libssh2_channel_open_session(session);
//     //Channel *m_channel = new Channel(channel);
//    // 请求分配伪终端
//    const char* term = "";
//    int ret = libssh2_channel_request_pty(channel, "xterm");
//    if (ret != 0) {
//        qDebug() << "出错" << ret;
//        // 请求伪终端失败，处理错误
//    }
//    qDebug() << "没出错" << ret;
//    libssh2_channel_shell(channel);

//    QString command2 = "ls -l\n";
//    libssh2_channel_write(channel, command.toStdString().c_str(), strlen(command.toStdString().c_str()));
//    libssh2_channel_write(channel, command2.toStdString().c_str(), strlen(command2.toStdString().c_str()));

//    LIBSSH2_POLLFD *fds = new LIBSSH2_POLLFD;
//            fds->type = LIBSSH2_POLLFD_CHANNEL;
//            fds->fd.channel = channel;
//            fds->events = LIBSSH2_POLLFD_POLLIN | LIBSSH2_POLLFD_POLLOUT;

//    while (1) {
//        // 使用libssh2_poll函数等待事件
//        int rc = libssh2_poll(fds, 1, 1000);
//        if (rc > 0) {
//            // 有事件发生，检查revents字段以确定具体事件类型
//            if (fds->revents & LIBSSH2_POLLFD_POLLIN) {
//                // 可读事件发生，可以读取数据
//                // 使用libssh2_channel_read等函数读取数据
//                char buffer[4096] = {0};
//                int bytesRead;
//                int c = 0;
//                while (c++ < 2) {
//                    qDebug() << "循环";
//                    bytesRead = libssh2_channel_read(channel, buffer, sizeof(buffer) - 1);
//                    buffer[bytesRead] = '\0';
//                    qDebug() << buffer;
//                    a = buffer;
//                    QTest::qSleep(100);
//                    // 处理输出数据
//                    // 例如，将输出数据打印到控制台
//                    //std::string aa = sprintf("%.*s", bytesRead, buffer);
//                }
//            }

//            if (fds->revents & LIBSSH2_POLLFD_POLLOUT) {
//                // 可写事件发生，可以写入数据
//                // 使用libssh2_channel_write等函数写入数据

//            }
//        } else if (rc == 0) {
//            // 超时，没有事件发生
//        } else {
//            // 发生错误，处理错误
//            break;
//        }
//    }


//    //handle_loop(channel);
//    //const char* command = "ls -l";
//    //const char * aa = command.toStdString().c_str();


//    // 读取命令输出


////    if (channel) {
////        rc = libssh2_channel_exec(channel, command.toUtf8().constData());
////        if (rc == 0) {
////            // 读取命令输出
////            char buffer[4096];
////            int bytesRead;
////            while ((bytesRead = libssh2_channel_read(channel, buffer, sizeof(buffer) - 1)) > 0) {
////                buffer[bytesRead] = '\0';
////                qDebug() << buffer;
////                a = buffer;

////            }
////        }
////        libssh2_channel_close(channel);
////        libssh2_channel_free(channel);
////    }

//    // 关闭 SSH 连接
//    libssh2_session_disconnect(session, "Normal shutdown");
//    libssh2_session_free(session);
//    libssh2_exit();
//}

sshwidget::sshwidget(connnectInfoStruct& cInfoStruct, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sshwidget)
{
    ui->setupUi(this);
    ui->splitter_1->setStretchFactor(0,1);
    ui->splitter_1->setStretchFactor(1,100);
    ui->splitter_2->setStretchFactor(0,20);
    ui->splitter_2->setStretchFactor(1,2);

    ui->splitter_3->setStretchFactor(0,20);
    ui->splitter_3->setStretchFactor(1,0);

    ui->splitter_4->setStretchFactor(0,1);
    ui->splitter_4->setStretchFactor(1,1);

    ui->textEdit->setPlainText(ui->textEdit->toPlainText() + "连接主机中...\n");

    QString host = "172.16.8.154";
    QString port = 22;
    QString username = "root";
    QString password = "Linkdood@123456";

    QTextCharFormat format;

    // 设置格式
    QFont font;
    font.setFamily("Cascadia Mono,OPPOSans B");
    font.setPointSize(10);
    //format.setFontWeight(QFont::Bold);
    //format.setForeground(Qt::red);
    format.setFont(font);
    ui->textEdit->setCurrentCharFormat(format);

    //初始化
    thread = new QThread();
    m_sshhandle = new sshhandle();

    thread2 = new QThread();
    m_sshhandle2 = new sshhandle();
    m_sshhandle2->channel = m_sshhandle->channel;
    // 将对象移动到线程中
    m_sshhandle->moveToThread(thread);
    m_sshhandle2->moveToThread(thread2);

    connect(m_sshhandle,SIGNAL(send_channel_read(QString)),this,
                            SLOT(rece_channel_read(QString)));
    connect(m_sshhandle,SIGNAL(send_init()),this,
                            SLOT(rece_init()));

    thread->start();
    thread2->start();
    int connrectType = 1;
    QMetaObject::invokeMethod(m_sshhandle,"init",Qt::QueuedConnection, Q_ARG(int, connrectType), Q_ARG(QString, host), Q_ARG(QString,port), Q_ARG(QString,username), Q_ARG(QString,password));


    QString command = "ls\n";

    //connectAndExecuteCommand(host, port, username, password, command);
    //ui->textEdit->setPlainText(a);

    /*
https://blog.51cto.com/xiaohaiwa/5379626

*/

    keyFilter = new KeyFilter(this);
    connect(keyFilter,SIGNAL(send_enter_sign()),this,
                            SLOT(rece_enter_sign()));
    ui->textEdit->installEventFilter(keyFilter);

    QTextCursor cursor=ui->textEdit->textCursor();
            cursor.movePosition(QTextCursor::End);
            ui->textEdit->setTextCursor(cursor);

            lineNumber = cursor.blockNumber() + 1;
            columnNumber = cursor.columnNumber();

    ui->textEdit->setFocus();

}

sshwidget::~sshwidget()
{
    delete ui;
}

void sshwidget::sendCommandData(QString data)
{
    //libssh2_channel_write(m_sshhandle->channel, data.toStdString().c_str(), strlen(data.toStdString().c_str()));
    qDebug() << "开始调用invokeMethod channel_write 1";
    libssh2_channel_write(m_sshhandle->channel, data.toStdString().c_str(), strlen(data.toStdString().c_str()));
    //QMetaObject::invokeMethod(m_sshhandle,"channel_write",Qt::QueuedConnection, Q_ARG(QString, data));
    qDebug() << "开始调用invokeMethod channel_write 2";
}

void sshwidget::on_textEdit_cursorPositionChanged()
{

    //记录当前光标位置
    int rowCount = ui->textEdit->document()->lineCount(); //获取行数

//    QTextCursor cursor = ui->textEdit->textCursor();
//    int lineNumber1 = cursor.blockNumber() + 1;
//    int columnNumber1 = cursor.columnNumber();

    QTextCursor cursor2=ui->textEdit->textCursor();
    cursor2.movePosition(QTextCursor::End);
    ui->textEdit->setTextCursor(cursor2);
    //行
//    if (lineNumber1 != rowCount) {
//        qDebug() << "行数不是最后";
//        QTextCursor cursor=ui->textEdit->textCursor();
//                cursor.movePosition(QTextCursor::End);
//                ui->textEdit->setTextCursor(cursor);

//                lineNumber = cursor.blockNumber() + 1;
//                columnNumber = cursor.columnNumber();
//    }

//    if (columnNumber1 < 20) {
//        // 获取文档对象
//        QTextDocument *document = ui->textEdit->document();

//        // 获取指定行的文本块
//        QTextBlock block = document->findBlockByLineNumber(lineNumber-1);  // 将行号转换为从 0 开始计数

//        // 创建一个新的光标，并将其设置到指定行的指定列
//        QTextCursor cursor(block);
//        cursor.movePosition(QTextCursor::StartOfBlock);
//        cursor.movePosition(QTextCursor::Right, QTextCursor::MoveAnchor, 20);  // 将列号转换为从 0 开始计数

//        // 设置文本编辑器的光标
//        ui->textEdit->setTextCursor(cursor);
//    }










//    记录当前光标
//            当光标移动时，获取最新的光标数据和文本行数
//            如果光标数据不在文本行数范围，则使用旧数据

    //int rowCount = ui->textEdit->document()->lineCount(); //获取行数
    //判断移动后的光标是否在最后一行
//    QTextCursor cursor = ui->textEdit->textCursor();
//    lineNumber = cursor.blockNumber() + 1;
//    columnNumber = cursor.columnNumber();
//    qDebug() << "当前光标所在行数 = " << lineNumber << " 所在列数 = " << columnNumber;


    //qDebug() << "当前光标所在行数 = " << lineNumber1 << " 所在列数 = " << columnNumber1;

    //if (lineNumber1 != rowCount) {
//        QTextCursor cursor2=ui->textEdit->textCursor();
//        cursor2.movePosition(QTextCursor::End);
//        ui->textEdit->setTextCursor(cursor2);
    //}
        //qDebug() << "光标不在最后一个行了";
        //返回到刚才的位置

        // 获取文档对象
//        QTextDocument *document = ui->textEdit->document();

//        // 获取指定行的文本块
//        QTextBlock block = document->findBlockByLineNumber(lineNumber-1);  // 将行号转换为从 0 开始计数

//        // 创建一个新的光标，并将其设置到指定行的指定列
//        QTextCursor cursor(block);
//        cursor.movePosition(QTextCursor::StartOfBlock);
//        cursor.movePosition(QTextCursor::Right, QTextCursor::MoveAnchor, columnNumber-1);  // 将列号转换为从 0 开始计数

//        // 设置文本编辑器的光标
//        ui->textEdit->setTextCursor(cursor);





//        QTextCursor cursor2=ui->textEdit->textCursor();
//                cursor2.movePosition(QTextCursor::End);
//                ui->textEdit->setTextCursor(cursor2);
    //}


    //qDebug() << "光标移动";
    //int rowCount = ui->textEdit->document()->lineCount(); //获取行数
    //qDebug() << "行数 = " << rowCount;

    //qDebug() << "当前光标所在行数 = " << lineNumber_ << " 所在列数 = " << columnNumber_;
    //myEdit ->document()->setMaximumBlockCount(1000) //设置最大行数是1000


}

void sshwidget::rece_init()
{
    qDebug("开始调用init_poll");
    ui->textEdit->setPlainText(ui->textEdit->toPlainText() + "主机连接成功\n");
    //初始化完成调用
    QMetaObject::invokeMethod(m_sshhandle,"init_poll",Qt::QueuedConnection);
    //通知页面，连接成功，可以使用
    qDebug("开始调用init_poll完成");
}

void sshwidget::rece_channel_read(QString data)
{
    qDebug().noquote() << "我收到数据啦" << data;
    qDebug().noquote() << "也收到数据啦" << commond;

    datahandle ac;
    data = ac.processData(data);

    if (data == commond) {
        qDebug().noquote() << "3我收到数据啦" << commond;
        ui->textEdit->setPlainText(ui->textEdit->toPlainText() + "\r\n");
        return;
    }
    //ui->textEdit->setPlainText(ui->textEdit->toPlainText() + data);
    //ui->lineEdit->setText(data);

    // 创建 QTextDocument
    //QTextDocument* document = new QTextDocument();
    //ui->textEdit->setDocument(document);

    // 创建 QTextCursor
    //QTextCursor cursor(document);

    // 创建 QTextCharFormat

    // 将格式应用于文本的一部分
    //qDebug() << "原数据 = " << ui->textEdit->toPlainText();
    //QTextCursor cursor2 = ui->textEdit->textCursor();  // 获取 QTextEdit 中的光标
    //cursor2.insertText(data, format);
    ui->textEdit->setPlainText(ui->textEdit->toPlainText() + data);
    //处理数据
}

void sshwidget::rece_enter_sign()
{
    // 获取整个文本内容
    //QString text = ui->textEdit->toPlainText();

    // 按换行符拆分文本内容为行列表
    //QStringList lines = text.split("\n");

    // 获取最后一行数据
//    QString lastLine;
//    if (!lines.isEmpty()) {
//        lastLine = lines.last();
//    }
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.movePosition(QTextCursor::End);
    cursor.movePosition(QTextCursor::StartOfLine, QTextCursor::KeepAnchor);
    QString lastLine = cursor.selectedText();
    // 打印最后一行数据
    //QString a = "\u001B]0;root@localhost:~\u0007[root@localhost ~]# ";
    //qDebug() << "a: " << a.length();
    //qDebug() << "Last Line: " << lastLine;
    //从最后一行数据中获取命令
    int index1 = lastLine.indexOf("# ");
    QString a = lastLine.mid(0,index1+2);
    int index2 = lastLine.indexOf("# ");
    QString b = lastLine.mid(index2+2);
    qDebug() << "Last Line a: " << a;
    qDebug() << "Last Line b: " << b;
    qDebug() << "Last Line a + b: " << a + b;
    qDebug() << "ui->textEdit->toPlainText() = " << ui->textEdit->toPlainText();

    //删除命令
    // 使用 QTextCursor 定位到最后一行

    // 删除最后一行
    //cursor.removeSelectedText();
    //添加前缀
    //ui->textEdit->setPlainText(ui->textEdit->toPlainText() + a);
    //qDebug() << "ui->textEdit->toPlainText() = " << ui->textEdit->toPlainText();
    //获取信息
    commond = b + "\r\n";
    sendCommandData(b + "\n");
}

void sshwidget::on_pushButton_clicked()
{
    QString data = "ls -l\n";
    sendCommandData(data);
}
