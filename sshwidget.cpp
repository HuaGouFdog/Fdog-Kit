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
#include <QInputMethod>
#include <windows.h>
#include <QTimer>
#include <QTextCursor>
#include <QTextCharFormat>
#include <QTextOption>
#include <QPushButton>
#include <QStackedLayout>
#include <QScrollBar>
#include<QTextCodec>
#include <QElapsedTimer>
#include <QDir>
#include <QFileDialog>

QString a = "";

//    // 关闭 SSH 连接
//    libssh2_session_disconnect(session, "Normal shutdown");
//    libssh2_session_free(session);
//    libssh2_exit();
//}

void stringToHtmlFilter(QString &str)
{
//注意这几行代码的顺序不能乱，否则会造成多次替换
str.replace("&","&amp;");
str.replace(">","&gt;");
str.replace("<","&lt;");
str.replace("\"","&quot;");
str.replace("\'","&#39;");
str.replace(" ","&nbsp;");
str.replace("\r\r\n","<br>");
str.replace("\r\n","<br>");
str.replace("\n","<br>");
}

void stringToHtml(QString &str, QColor crl)
{
 QByteArray array;
 array.append(crl.red());
 array.append(crl.green());
 array.append(crl.blue());
 QString strC(array.toHex());
 str = QString("<span style=\" color:#%1;\">%2</span>").arg(strC).arg(str);
 }

sshwidget::sshwidget(connnectInfoStruct& cInfoStruct, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sshwidget)
{
    ui->setupUi(this);
    //ui->splitter_1->setStretchFactor(0,1);
    //ui->splitter_1->setStretchFactor(1,100);

    ui->splitter_2->setStretchFactor(0,100);
    ui->splitter_2->setStretchFactor(1,2);

    //ui->splitter_3->setStretchFactor(0,100);
    //ui->splitter_3->setStretchFactor(1,1);

    //ui->splitter_4->setStretchFactor(0,1);
    //ui->splitter_4->setStretchFactor(1,1);

    ui->textEdit->viewport()->setCursor(Qt::ArrowCursor);
    //表格自适应
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

    setMouseTracking(true);
    QString host = cInfoStruct.host;
    QString port = cInfoStruct.port;
    QString username = cInfoStruct.userName;
    QString password = cInfoStruct.password;


    //初始化
    thread = new QThread();
    m_sshhandle = new sshhandle();

    //thread2 = new QThread();
    m_sshhandle2 = new sshhandle();
    //m_sshhandle2->channel = m_sshhandle->channel;
    // 将对象移动到线程中
    m_sshhandle->moveToThread(thread);
    //m_sshhandle2->moveToThread(thread2);

//    connect(m_sshhandle,SIGNAL(send_channel_read(QString)),this,
//                            SLOT(rece_channel_read(QString)));
    connect(m_sshhandle,SIGNAL(send_channel_readS(QStringList)),this,
                            SLOT(rece_channel_readS(QStringList)));
    connect(m_sshhandle,SIGNAL(send_init()),this,
                            SLOT(rece_init()));
    connect(m_sshhandle,SIGNAL(send_getServerInfo(ServerInfoStruct)),this,
                            SLOT(rece_getServerInfo(ServerInfoStruct)));
    thread->start();
    //thread2->start();
    int connrectType = 1;
    //这里设置初始化方式
    //密码
    //密钥 Path name of the public key file. (e.g. /etc/ssh/hostkey.pub). If libssh2 is built against OpenSSL, this option can be set to NULL.
    QMetaObject::invokeMethod(m_sshhandle,"init",Qt::QueuedConnection, Q_ARG(int, connrectType), Q_ARG(QString, host), Q_ARG(QString,port), Q_ARG(QString,username), Q_ARG(QString,password));

    textEdit_s = new CustomTextEdit(this);
    textEdit_s->setReadOnly(true);
    textEdit_s->viewport()->setCursor(Qt::ArrowCursor);
    textEdit_s->setStyleSheet("QTextEdit{ \
                             background-color: rgb(0, 41, 169, 0);\
                             font: 12pt \"Cascadia Mono,OPPOSans B\";\
                             border: none;\
                             padding-top:0px;\
                             padding-bottom:0px;\
                             padding-left:0px;\
                             padding-right:0px;\
                             border-radius: 5px;\
                             color: rgba(255, 255, 255, 0);\
                         }\
                         \
                         QScrollBar:vertical {\
                             width: 10px;\
                             background-color: rgba(0, 41, 69, 0);\
                             margin: 0px,0px,0px,0px;\
                             padding-top: 0px;		/*//隐藏上下的箭头*/\
                             padding-bottom: 0px;\
                         }\
                         QScrollBar::handle:vertical {\
                             width: 10px;\
                             \
                             background-color: rgb(239, 239, 239);\
                             /*滚动条两端变成椭圆 */\
                             border-radius: 2px;\
                             min-height: 0;\
                         }\
                         \
                         QScrollBar::sub-page:vertical {\
                             \
                             background-color: rgba(255, 255, 255, 0);\
                         }\
                         QScrollBar::add-page:vertical \
                         {\
                             background-color: rgba(255, 255, 255, 0);\
                         }\
                         \
                         QScrollBar::add-line:vertical {\
                             border: none;\
                             height: 0px;\
                             subcontrol-position: bottom;\
                             subcontrol-origin: margin;\
                         }\
                         QScrollBar::sub-line:vertical {\
                             border: none;\
                             height: 0px;\
                             subcontrol-position: top;\
                             subcontrol-origin: margin;\
                         }\
                         \
                         QScrollBar::down-arrow:vertical {\
                             border:none;\
                         }\
                         QScrollBar::up-arrow:vertical {\
                             border:none;\
                         }");

    //const int m_timer_interval__ = 1000;
    //QTimer* monitor_timer__ = nullptr;
    //QThread* monitor_thread__ = nullptr;

    //monitor_thread__ = new QThread(this);
    //monitor_timer__ = new QTimer();
    //connect(monitor_timer__, SIGNAL(timeout()), m_sshhandle, SLOT(getServerInfo()));
    //monitor_timer__->start(m_timer_interval__);
    //monitor_timer__->moveToThread(monitor_thread__);
    //monitor_thread__->start();
//    QString str(" < Hello Qt!>");
//    QColor  clrR(255,255,255);
//    stringToHtmlFilter(str);
//    stringToHtml(str,clrR);
//    ui->textEdit->insertHtml(str);

//    QString str2(" < Hello Qt!>");
//    QColor clrR2(255,255,255);
//    stringToHtmlFilter(str2);
//    stringToHtml(str2,clrR2);
//    ui->textEdit->insertHtml(str2);

//    QString str3(" < Hello Qt!>\n");
//    QColor clrR3(155,155,155);
//    stringToHtmlFilter(str3);
//    stringToHtml(str3,clrR3);
//    ui->textEdit->insertHtml(str3);

    QString command = "ls\n";
    QString cc = "连接主机中...<br>";
//    QColor  clrR(255,255,255);
//    stringToHtmlFilter(cc);
//    stringToHtml(cc,clrR);
    ui->textEdit->insertHtml(cc);

//    QTextCursor cursor6 = ui->textEdit_6->textCursor();
//    cursor6.movePosition(QTextCursor::End);
//    ui->textEdit_6->setTextCursor(cursor6);
//    ui->textEdit_6->insertHtml(cc);

    QTextCursor cursor_s = textEdit_s->textCursor();
    cursor_s.movePosition(QTextCursor::End);
    textEdit_s->setTextCursor(cursor_s);
    textEdit_s->insertHtml(cc);

    //ui->textEdit->append("连接主机中...");
    //connectAndExecuteCommand(host, port, username, password, command);
    //ui->textEdit->setPlainText(a);

    /*
https://blog.51cto.com/xiaohaiwa/5379626

*/

    keyFilter = new KeyFilter(this);
//    connect(keyFilter,SIGNAL(send_enter_sign()),this,
//                            SLOT(rece_enter_sign()));
//    connect(keyFilter,SIGNAL(send_tab_sign(int)),this,
//                            SLOT(rece_tab_sign(int)));
//    connect(keyFilter,SIGNAL(send_backSpace_sign(int)),this,
//                            SLOT(rece_backSpace_sign(int)));

    connect(keyFilter,SIGNAL(send_key_sign(QString)),this,
                            SLOT(rece_key_sign(QString)));

    ui->textEdit->installEventFilter(keyFilter);

    mouseFilter = new MouseFilter(this);
    //ui->textEdit_6->installEventFilter(mouseFilter);
    QTextCursor cursor2=ui->textEdit->textCursor();
            cursor2.movePosition(QTextCursor::End);
            ui->textEdit->setTextCursor(cursor2);

            lineNumber = cursor2.blockNumber() + 1;
            columnNumber = cursor2.columnNumber();

    //ui->textEdit_4->setFocus();
    movePos = false;

    //ui->textBrowser->setText("这是一段可选中但无需移动光标的文本。");

    // 禁用编辑和光标显示
    //QTextCursor cursor = ui->textEdit->textCursor();
    //cursor.setKeepPositionOnInsert(false);
    //cursor.set
    //ui->textEdit->setTextCursor(cursor);

    //textEdit2->setPlainText("Example text");
    //textEdit2.show();

    //QPushButton * aa = new QPushButton("xxxxx", this);
    //ui->verticalLayout_13->addWidget(aa);
    //ui->verticalLayout_13->addWidget(textEdit2);

    ui->textEdit->setCursorWidth(8);

//    QTextCursor cursor = ui->textEdit->textCursor();
//    int startPosition = 2;
//    int endPosition = 7;

//    cursor.setPosition(startPosition);
//    cursor.setPosition(endPosition, QTextCursor::KeepAnchor);
//    ui->textEdit->setTextCursor(cursor);

//    QTextCursor cursor = ui->textEdit->textCursor();
//    int startPosition = 2;
//    int endPosition = 7;

//    cursor.setPosition(startPosition);
//    cursor.setPosition(endPosition, QTextCursor::KeepAnchor);
//    ui->textEdit->setTextCursor(cursor);

    //ui->textEdit->setTextInteractionFlags(Qt::TextSelectableByMouse | Qt::TextSelectableByKeyboard);
    QStackedLayout * Layout = new QStackedLayout;
    Layout->setStackingMode(QStackedLayout::StackAll);
    Layout->setContentsMargins(0,0,0,0);
    Layout->addWidget(textEdit_s);
    Layout->addWidget(ui->textEdit);
    ui->widget_10->setLayout(Layout);

    connect(textEdit_s,SIGNAL(cursorPositionChanged()),this,
                               SLOT(on_textEdit_s_cursorPositionChanged()));
    connect(textEdit_s,SIGNAL(send_mousePress_sign()),this,
                               SLOT(rece_send_mousePress_sign()));

    scrollBar_textEdit = ui->textEdit->verticalScrollBar();
//    connect(scrollBar_textEdit,SIGNAL(valueChanged(int)),this,
//                            SLOT(scrollBarValueChanged2(int)));


    //scrollBar_textEdit_s = ui->textEdit_6->verticalScrollBar();
    scrollBar_textEdit_s = textEdit_s->verticalScrollBar();
    connect(scrollBar_textEdit_s,SIGNAL(valueChanged(int)),this,
                               SLOT(scrollBarValueChanged(int)));

    //ui->widget->hide();
    //ui->widget_3->hide();
    //ui->widget_4->hide();
    //ui->horizontalWidget->hide();
}

sshwidget::~sshwidget()
{
    delete ui;
}

void sshwidget::sendCommandData(QString data)
{
    libssh2_channel_write(m_sshhandle->channel_ssh, data.toStdString().c_str(), strlen(data.toStdString().c_str()));
}




void sshwidget::sendUploadCommandData(QString local_file_path, QString remote_file_path)
{

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
        return;
    } else {
        qDebug() << "打开文件成功";
    }

    m_sshhandle->handle_sftp = NULL;
    m_sshhandle->handle_sftp = libssh2_sftp_open(m_sshhandle->session_sftp, remote_file_path.toStdString().c_str(),
                                                            LIBSSH2_FXF_WRITE | LIBSSH2_FXF_CREAT | LIBSSH2_FXF_TRUNC,
                                                            LIBSSH2_SFTP_S_IRUSR | LIBSSH2_SFTP_S_IWUSR);
        if (m_sshhandle->handle_sftp == NULL) {
            qDebug() << "sftp_handle失败";
            int error_code = libssh2_sftp_last_error(m_sshhandle->session_sftp);
            qDebug() << "Failed to open file: " << error_code;
            // 处理远程文件创建失败的情况
            fclose(local_file);
            libssh2_sftp_shutdown(m_sshhandle->session_sftp);
//            libssh2_session_disconnect(session, "Failed to create remote file");
//            libssh2_session_free(session);
//            libssh2_exit();
            return;
        } else {
            qDebug() << "sftp_handle成功";
        }

        // 读取本地文件内容并写入到远程文件
        char buffer[100000 * 2] = { 0 };
        qDebug() << "准备" << 1;

        /* 上传数据 */
        QElapsedTimer timer;
            timer.start(); // 启动计时器
        while (TRUE){
            int nread = fread(buffer,1,sizeof(buffer), local_file);
            if(nread <= 0) {
                break;
            }
            for(char * ptr = buffer; nread;){
                //qDebug() << "循环读取1";
                //发现个问题 这个函数最高只能写入30000字节数据 所以调太大是没用的 后来还发现如果缓冲区设成30000 上传速度也会变慢
                // 必须高于30000的2倍数 所以 我设置成了2倍
                int len = libssh2_sftp_write(m_sshhandle->handle_sftp, ptr, nread);
                //qDebug() << "循环读取2";
                if(len < 0) {
                    break;
                }
                ptr += len;
                nread -= len;
            }
        }
        qint64 elapsedTime = timer.elapsed(); // 获取经过的时间，单位为毫秒
            qDebug() << "Elapsed Time:" << elapsedTime << "ms";
        qDebug() <<"开始完成";
        // 关闭文件句柄和本地文件
        libssh2_sftp_close(m_sshhandle->handle_sftp);
        fclose(local_file);

        // 断开 SSH 连接和释放会话
        libssh2_sftp_shutdown(m_sshhandle->session_sftp);
//        libssh2_session_disconnect(session, "Upload complete");
//        libssh2_session_free(session);
//        libssh2_exit();
}

void sshwidget::sendData(QString data)
{
    ui->textEdit->insertHtml(data);
    QTextCursor cursor_s = textEdit_s->textCursor();
    cursor_s.movePosition(QTextCursor::End);
    textEdit_s->setTextCursor(cursor_s);
    textEdit_s->insertHtml(data);
}

void sshwidget::on_textEdit_cursorPositionChanged()
{
    //qDebug() << "移动 ";
    // 创建一个选择项
    //记录当前光标位置
//    int rowCount = ui->textEdit->document()->lineCount(); //获取行数
    // 获取鼠标点击位置的 QTextCursor

    //QTextCursor cursor = ui->textEdit->textCursor();
//    int currentCursorPosition = cursor.position();
//    cursor.setPosition(currentCursorPosition, QTextCursor::KeepAnchor);

    //cursor.movePosition(QTextCursor::End);
    //ui->textEdit->setTextCursor(cursor);
//    if (scrollBar_textEdit && scrollBar_textEdit_s) {
//        qDebug() << "设置滑动条 ";
//        scrollBar_textEdit_s->setValue(scrollBar_textEdit->value());
//    }


//    QString selectedText = cursor.selectedText();

//    qDebug() << "Selected Text: " << selectedText;

    //当前光标
//    qDebug()<<"coming";           //可以看到行号随着光标的改变而改变

//    QTextCursor tc = ui->textEdit->textCursor();
//    QTextLayout *pLayout = tc.block().layout();
//    //当前光标在本BLOCK内的相对位置
//    int nCurpos = tc.position() - tc.block().position();
//    int nTextline = pLayout->lineForTextPosition(nCurpos).lineNumber() + tc.block().firstLineNumber();
//    qDebug()<<nTextline;           //可以看到行号随着光标的改变而改变
//    QTextCursor cursor = ui->textEdit->textCursor();
//    QString selectedText = cursor.selectedText();

//    qDebug() << "Selected Text: " << selectedText;

//    if (!cursor.atEnd()) {
//        cursor.movePosition(QTextCursor::End);
//        ui->textEdit->setTextCursor(cursor);
//     }
    //QTextCursor cursor2(&ui->textEdit->document());


//    QTextCursor cursor = ui->textEdit->textCursor();
//    //选中从start到end的这一段文本

//    int start = cursor.position()-50;

//    int end = cursor.position();

//    cursor.setPosition(start,QTextCursor::MoveAnchor);

//    cursor.setPosition(end,QTextCursor::KeepAnchor);
//    ui->textEdit->setTextCursor(cursor);

//    QTextCursor cursor2=ui->textEdit->textCursor();
//    int position = cursor2.position();
//    if (position != 590) {
//        qDebug() << "Current cursor position:" << position << " movePos = " <<movePos;
//    }

//    if (!movePos) {
//        cursor2.movePosition(QTextCursor::End);
//        ui->textEdit->setTextCursor(cursor2);
//        qDebug() << "设置光标为最后";
//        movePos = false;
//    }
}

void sshwidget::rece_init()
{
    // 设置焦点策略为强制获取焦点
    ui->textEdit->setFocusPolicy(Qt::NoFocus);
    ui->textEdit->setFocus();
    qDebug("开始调用init_poll");
    QColor  clrR(255,255,255);
    QString cc = "主机连接成功<br>";
//    stringToHtmlFilter(cc);
//    stringToHtml(cc,clrR);
    ui->textEdit->insertHtml(cc);
//    QTextCursor cursor6 = ui->textEdit_6->textCursor();
//    cursor6.movePosition(QTextCursor::End);
//    ui->textEdit_6->setTextCursor(cursor6);
//    ui->textEdit_6->insertHtml(cc);

    QTextCursor cursor_s = textEdit_s->textCursor();
    cursor_s.movePosition(QTextCursor::End);
    textEdit_s->setTextCursor(cursor_s);
    textEdit_s->insertHtml(cc);

    //初始化完成调用
    QMetaObject::invokeMethod(m_sshhandle,"init_poll",Qt::QueuedConnection);
    //通知页面，连接成功，可以使用
    qDebug("开始调用init_poll完成");
}

void sshwidget::rece_channel_read(QString data)
{
    while(1) {
        //检测\b
        if (data.contains("\b")) {
            //光标左移动
            int position = data.indexOf("\b");
            data = data.mid(0, position) + data.mid(position);
        }
        if (data.length() == 0) {
            break;
        }
    }
//    if (data == "\b\u001B[K") {
//        //退格键 光标左移一位 删除后面一个字符
//        QTextCursor cursor = ui->textEdit->textCursor();
//        //cursor.movePosition(QTextCursor::End);
//        // 将光标向前移动一个字符
//        cursor.movePosition(QTextCursor::Left, QTextCursor::KeepAnchor);
//        // 删除选中的字符
//        cursor.deletePreviousChar();
//        data = "";
//        return;
//    }

//    if (data == "\b") {
//        //光标左移一位
//        QTextCursor cursor = ui->textEdit->textCursor();
//        cursor.movePosition(QTextCursor::Left);
//        ui->textEdit->setTextCursor(cursor);
//        return;
//    }

//    if (data == "\u001B[C") {
//        //光标右移一位
//        QTextCursor cursor = ui->textEdit->textCursor();
//        cursor.movePosition(QTextCursor::Right);
//        ui->textEdit->setTextCursor(cursor);
//        return;
//    }


    //处理退格
//    while(0) {
//        if (data.contains("\b")) {
//                int position = data.indexOf("\b");
//                if (position == 0) {
//                    //删除光标前一个
//                    QTextCursor cursor = ui->textEdit->textCursor();
//                    cursor.movePosition(QTextCursor::End);
//                    // 将光标向前移动一个字符
//                    cursor.movePosition(QTextCursor::Left, QTextCursor::KeepAnchor);
//                    // 删除选中的字符
//                    cursor.deletePreviousChar();
//                    data = data.mid(position + 1);
//                } else {

//                    QString data1 = data.mid(0, position);
//                    QString data2 = data.mid(position + 1);
//                    //data = data.mid(position) + data.mid(position);
//                    qDebug() << "data1 = " << data1 << "  data2 = " << data2;
//                    data = data1 + data2;
//                }

//        } else {
//            break;
//        }
//    }

//    while(0) {
//        if (data.contains("\u001B[K")) {
//            int position = data.indexOf("\u001B[K");
//            QString data1 = data.mid(0, position);
//            QString data2 = data.mid(position + 7);
//            qDebug() << "data1 = " << data1 << "  data2 = " << data2;
//            data = data1 + data2;
//        } else {
//            break;
//        }
//    }

    // \b\b\b\b\b\b\b\b\b\b\b\b\b\b\u001B[4P



    //这个接口应该是输出数据，不进行逻辑处理
    //qDebug() << "我收到数据啦" << data;
    if (data[data.length()-1] == "\u0007") {
        qDebug() << "发现t加1" << endl;
        isDTab++;
    }
    if (data == "") {
        QTextCursor cursor = ui->textEdit->textCursor();
        cursor.movePosition(QTextCursor::End);
        cursor.movePosition(QTextCursor::StartOfLine, QTextCursor::KeepAnchor);
        QString lastLine = cursor.selectedText();
        commond2 = lastLine;
        return;
    }
    //data可能包含空行，只取最后一行的数据
    //commond2 = "[root@localhost ~]# ";
    int index = data.lastIndexOf("\n");
    if (index != -1) {
        //commond2 = data.mid(index + 1);
    } else {
        //commond2 = data;
    }
    if (lastCommond == 1) {
        int index = data.lastIndexOf("\n");
        if (index != -1) {
            if (data.mid(index).mid(commond2.length() + 1).startsWith(tabCommond)) {
                tabCommond= data.mid(index).mid(commond2.length() + 1);
            }
        } else if (data.startsWith(tabCommond)) {
            tabCommond = data;
        }
//        int index = data.lastIndexOf("\n");
//            tabCommond= data.mid(index).mid(commond2.length() + 1);
            qDebug() << "tabCommond2 = " << tabCommond << " data = " << data << " commond2 = " << commond2;
    }


    //qDebug() << "commond2 = " << commond2;
    //qDebug() << "222我收到数据啦" << data << " len = " << data.length();
    //qDebug() << "222也收到数据啦" << commond << " len = " <<commond.length();
    int type = 0;
    QString data2 = "";
    if (commond != "" && data.startsWith(commond) && data.length() > commond.length()) {
        //说明命令后面带了数据，提取需要的数据

        data2 = data.mid(commond.length());
        data = commond;
        //qDebug() << "2我收到数据啦" << data2;
        type = 1;
    } else if (data == commond && commond != "" && lastCommond == 2) {
        //qDebug() << "3我收到数据啦" << data;
        //qDebug() << "3也收到数据啦" << commond;
        QColor  clrR(255,0,0);
        QString cc = "\r\n";
        stringToHtmlFilter(cc);
        stringToHtml(cc,clrR);
        ui->textEdit->insertHtml(cc);
        //        QTextCursor cursor6 = ui->textEdit_6->textCursor();
        //        cursor6.movePosition(QTextCursor::End);
        //        ui->textEdit_6->setTextCursor(cursor6);
        //        ui->textEdit_6->insertHtml(cc);

        QTextCursor cursor_s = textEdit_s->textCursor();
        cursor_s.movePosition(QTextCursor::End);
        textEdit_s->setTextCursor(cursor_s);
        textEdit_s->insertHtml(cc);

        if (type == 0) {
            QTextCursor cursor = ui->textEdit->textCursor();
            cursor.movePosition(QTextCursor::End);
            cursor.movePosition(QTextCursor::StartOfLine, QTextCursor::KeepAnchor);
            QString lastLine = cursor.selectedText();
            commond2 = lastLine;
            return;
        }

    } else if (data == commond && commond != "") {
        qDebug() << "进入";
        QTextCursor cursor = ui->textEdit->textCursor();
        cursor.movePosition(QTextCursor::End);
        cursor.movePosition(QTextCursor::StartOfLine, QTextCursor::KeepAnchor);
        QString lastLine = cursor.selectedText();
        commond2 = lastLine;
        return;
    } else if (commond.mid(commond.length()-1) == "\t" && data.startsWith(commond.mid(0,commond.length()-1))) {
        qDebug() << "进入tab " << data.mid(commond.length()-1);
        ui->textEdit->insertHtml(data.mid(commond.length()-1));
        //        QTextCursor cursor6 = ui->textEdit_6->textCursor();
        //        cursor6.movePosition(QTextCursor::End);
        //        ui->textEdit_6->setTextCursor(cursor6);
        //        ui->textEdit_6->insertHtml(data.mid(commond.length()-1));
        QTextCursor cursor_s = textEdit_s->textCursor();
        cursor_s.movePosition(QTextCursor::End);
        textEdit_s->setTextCursor(cursor_s);
        textEdit_s->insertHtml(data.mid(commond.length()-1));
        QTextCursor cursor = ui->textEdit->textCursor();
        cursor.movePosition(QTextCursor::End);
        cursor.movePosition(QTextCursor::StartOfLine, QTextCursor::KeepAnchor);
        QString lastLine = cursor.selectedText();
        commond2 = lastLine;
        return;
    }

    if (type != 0) {
        ui->textEdit->insertHtml(data2);
        //        QTextCursor cursor6 = ui->textEdit_6->textCursor();
        //        cursor6.movePosition(QTextCursor::End);
        //        ui->textEdit_6->setTextCursor(cursor6);
        //        ui->textEdit_6->insertHtml(data2);
        QTextCursor cursor_s = textEdit_s->textCursor();
        cursor_s.movePosition(QTextCursor::End);
        textEdit_s->setTextCursor(cursor_s);
        textEdit_s->insertHtml(data2);
    } else {
        ui->textEdit->insertHtml(data);
        //        QTextCursor cursor6 = ui->textEdit_6->textCursor();
        //        cursor6.movePosition(QTextCursor::End);
        //        ui->textEdit_6->setTextCursor(cursor6);
        //        ui->textEdit_6->insertHtml(data);
        QTextCursor cursor_s = textEdit_s->textCursor();
        cursor_s.movePosition(QTextCursor::End);
        textEdit_s->setTextCursor(cursor_s);
        textEdit_s->insertHtml(data);
    }
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.movePosition(QTextCursor::End);
    cursor.movePosition(QTextCursor::StartOfLine, QTextCursor::KeepAnchor);
    QString lastLine = cursor.selectedText();
    // 打印最后一行数据
    //QString a = "\u001B]0;root@localhost:~\u0007[root@localhost ~]# ";
    //qDebug() << "a: " << a.length();
    qDebug() << "x Last Line: " << lastLine;
    commond2 = lastLine;

    if (scrollBar_textEdit && scrollBar_textEdit_s) {
        //qDebug() << "设置滑动条 read " << scrollBar_textEdit->value();
        scrollBar_textEdit->setValue(scrollBar_textEdit->maximum());
        scrollBar_textEdit_s->setValue(scrollBar_textEdit->value());
    }
}

void sshwidget::rece_channel_readS(QStringList data)
{

    int sum = 0;
    int sum2 = 0;
    //第一条固定为工作路径
    ssh_path = data[0];
    for(int i = 1; i < data.length(); i++) {
        //qDebug() << "获取数据： " << data[i];
        if (data[i] == "\b" && lastCommondS == "\u001B[D") {
            data[i] = "\u001B[D";
        }

        if (data[i] == "\b") {
            sum++;
            //sum2--;
            qDebug() << "sum2 = " << sum2;
            if (sum2 != 0) {
                sum2--;
                continue;
            }
            QTextCursor cursor = ui->textEdit->textCursor();
            cursor.movePosition(QTextCursor::Left, QTextCursor::KeepAnchor);
            cursor.deletePreviousChar();
            ui->textEdit->setTextCursor(cursor);

            QTextCursor cursor2 = textEdit_s->textCursor();
            cursor2.movePosition(QTextCursor::Left, QTextCursor::KeepAnchor);
            cursor2.deletePreviousChar();
            textEdit_s->setTextCursor(cursor2);
        } else if (data[i] == "\u001B[C") {
            sum2++;
            qDebug() << "sum2++";
            QTextCursor cursor = ui->textEdit->textCursor();
            cursor.movePosition(QTextCursor::Right);
            ui->textEdit->setTextCursor(cursor);

            QTextCursor cursor2 = textEdit_s->textCursor();
            cursor2.movePosition(QTextCursor::Right);
            textEdit_s->setTextCursor(cursor2);
        } else if (data[i] == "\u001B[D") {
            QTextCursor cursor = ui->textEdit->textCursor();
            cursor.movePosition(QTextCursor::Left);
            ui->textEdit->setTextCursor(cursor);

            QTextCursor cursor2 = textEdit_s->textCursor();
            cursor2.movePosition(QTextCursor::Left);
            textEdit_s->setTextCursor(cursor2);
        } else if (data[i] == "\u001B[K") {
            QTextCursor cursor = ui->textEdit->textCursor();
            int cursorPos = cursor.position();
            int textLength = ui->textEdit->toPlainText().length();
            int charsToEnd = textLength - cursorPos;
//            cursor.movePosition(QTextCursor::Right, QTextCursor::KeepAnchor, charsToEnd);
//            cursor.deletePreviousChar();

//            QTextCursor cursor2 = textEdit_s->textCursor();
//            cursor2.movePosition(QTextCursor::Right, QTextCursor::KeepAnchor, charsToEnd);
//            cursor2.deletePreviousChar();
            sum = 0;
            continue;
        } else {
            QRegExp regExp("\\x001B\\[(\\d+)P");
            int pos = 0;
            bool isa = false;
            while ((pos = regExp.indexIn(data[i], pos)) != -1) {
                QString match = regExp.cap(1); //删除
                QTextCursor cursor = ui->textEdit->textCursor();
                cursor.movePosition(QTextCursor::Right, QTextCursor::KeepAnchor, match.toInt());
                cursor.deletePreviousChar();
                QTextCursor cursor2 = textEdit_s->textCursor();
                cursor2.movePosition(QTextCursor::Right, QTextCursor::KeepAnchor, match.toInt());
                cursor2.deletePreviousChar();
                sum = sum - match.toInt();
                isa = true;
                break;
            }
            if (!isa) {
                if (sum != 0) {
                    QTextCursor cursor = ui->textEdit->textCursor();
                    QTextCursor cursor2 = textEdit_s->textCursor();
                    int cursorPos = cursor.position();
                    int textLength = ui->textEdit->toPlainText().length();
                    int charsToEnd = textLength - cursorPos;
                    qDebug() << "有字符：" << charsToEnd << "有b:" <<sum;
                    qDebug() << i;
                    qDebug() << data.length() - 1;
                    if (data[i] == "" && data[i - 1] == "\b") {
                        sum--;
                        qDebug() << "sum--";
                        continue;
                    } else {
//                        if (data[i].length() != 0 && data[i].length() <= charsToEnd) {
//                            cursor.movePosition(QTextCursor::Right, QTextCursor::KeepAnchor, data[i].length());
//                            cursor.deletePreviousChar();
//                            qDebug() << "删除" <<data[i].length();
//                            cursor2.movePosition(QTextCursor::Right, QTextCursor::KeepAnchor, data[i].length());
//                            cursor2.deletePreviousChar();
//                        } else {
//                            cursor.movePosition(QTextCursor::Right, QTextCursor::KeepAnchor, charsToEnd);
//                            cursor.deletePreviousChar();
//                            qDebug() << "删除" <<charsToEnd;
//                            cursor2.movePosition(QTextCursor::Right, QTextCursor::KeepAnchor, charsToEnd);
//                            cursor2.deletePreviousChar();
//                        }
                    }
                    sum = 0;
                }
                sendData(data[i]);
                //qDebug() << "发送数据" << data[i];
                //QTextCursor cursor = ui->textEdit->textCursor();
                //QTextCursor cursor2 = textEdit_s->textCursor();
                //qDebug() << "向右移动" << data[i].length();
                //cursor.movePosition(QTextCursor::Right, QTextCursor::MoveAnchor, data[i].length());
                //cursor2.movePosition(QTextCursor::Right, QTextCursor::MoveAnchor, data[i].length());
               // ui->textEdit->setTextCursor(cursor);
                //textEdit_s->setTextCursor(cursor2);
            }
        }
    }
//    QTextCursor cursor = ui->textEdit->textCursor();
//    cursor.movePosition(QTextCursor::End);
//    cursor.movePosition(QTextCursor::StartOfLine, QTextCursor::MoveAnchor);

//    QTextCursor cursor2 = textEdit_s->textCursor();
//    cursor2.movePosition(QTextCursor::End);
//    cursor2.movePosition(QTextCursor::StartOfLine, QTextCursor::MoveAnchor);

    if (scrollBar_textEdit && scrollBar_textEdit_s) {
        //qDebug() << "设置滑动条 read " << scrollBar_textEdit->value();
        scrollBar_textEdit->setValue(scrollBar_textEdit->maximum());
        scrollBar_textEdit_s->setValue(scrollBar_textEdit->value());
    }
}

void sshwidget::rece_key_sign(QString key)
{
    qDebug() << "rece_key_sign = " << key;
    lastCommondS = key;
    if (key == "\r") {
        QTextCursor cursor = ui->textEdit->textCursor();
        cursor.movePosition(QTextCursor::End);
        ui->textEdit->setTextCursor(cursor);
        QTextCursor cursor2 = textEdit_s->textCursor();
        cursor2.movePosition(QTextCursor::End);
        textEdit_s->setTextCursor(cursor2);
    }
    sendCommandData(key);
}

void sshwidget::rece_getServerInfo(ServerInfoStruct serverInfo)
{
    ui->label_ip->setText(serverInfo.ip);
    ui->label_time->setText(serverInfo.time);
    ui->label_runTime->setText(serverInfo.runTime);
    ui->label_loginCount->setText(serverInfo.loginCount);
    ui->label_architecture->setText(serverInfo.architecture);
    ui->label_systemType->setText(serverInfo.systemType);
    ui->label_cpuUseRate->setText(serverInfo.cpuUseRate);
    ui->label_memUseRate->setText(serverInfo.memUseRate);
    ui->label_swapUseRate->setText(serverInfo.swapUseRate);
}

void sshwidget::on_pushButton_clicked()
{

    QTextCursor cursor(ui->textEdit->document());
    cursor.movePosition(QTextCursor::Start);

    for (int i = 0; i < 5 - 1; ++i)
    {
        cursor.movePosition(QTextCursor::Down);
    }

    ui->textEdit->setTextCursor(cursor);
    ui->textEdit->ensureCursorVisible();
    ui->textEdit->setFocusPolicy(Qt::StrongFocus);
    ui->textEdit->setFocus();
}

void sshwidget::on_textEdit_selectionChanged()
{
    QTextCursor cursor = ui->textEdit->textCursor();

       if (!cursor.hasSelection()) {
           return;
       }
       // 获取当前光标位置
       //int currentCursorPosition = cursor.position();
       // 移动光标到文档的末尾

       // 设置选中文本范围（从文档开头到之前的光标位置）
       //cursor.setPosition(currentCursorPosition, QTextCursor::KeepAnchor);

       //cursor.movePosition(QTextCursor::NoMove);

       // 更新选中范围
       //ui->textEdit->setTextCursor(cursor);
       //QTextCursor cursor2;
       //cursor2.movePosition(QTextCursor::End);
       //ui->textEdit->setTextCursor(cursor2);
}

void sshwidget::on_textEdit_5_cursorPositionChanged()
{
    //焦点变成4
    //ui->textEdit_4->setFocus();

}

void sshwidget::on_textEdit_s_cursorPositionChanged()
{
    ui->textEdit->setFocusPolicy(Qt::NoFocus);
    ui->textEdit->setFocus();
    //qDebug() << "textEdit_s_cursorPositionChanged设置焦点";
}

void sshwidget::on_textEdit_6_cursorPositionChanged()
{
    ui->textEdit->setFocusPolicy(Qt::NoFocus);
    ui->textEdit->setFocus();
    qDebug() << "textEdit_6_cursorPositionChanged设置焦点";
}

void sshwidget::scrollBarValueChanged(int value)
{
    //qDebug() << "滑动条值改变为1：" << value;
    QScrollBar *scrollBar = ui->textEdit->verticalScrollBar();
    scrollBar->setValue(value);
}

void sshwidget::scrollBarValueChanged2(int value)
{
    //qDebug() << "滑动条值改变为2：" << value;
    //qDebug() << "当前值：" << scrollBar_textEdit->value();
    //QScrollBar *scrollBar = ui->textEdit_6->verticalScrollBar();
    //scrollBar->setValue(value);
}

void sshwidget::on_textEdit_textChanged()
{
    if (scrollBar_textEdit && scrollBar_textEdit_s) {
        //qDebug() << "设置滑动条 ";
        scrollBar_textEdit_s->setValue(scrollBar_textEdit->value());
    }
    //获取最后一行数据放在textEdit_6
}

void sshwidget::rece_send_mousePress_sign()
{
    ui->textEdit->setFocusPolicy(Qt::NoFocus);
    ui->textEdit->setFocus();
    //qDebug() << "textEdit_s_cursorPositionChanged设置焦点";
}

void sshwidget::on_toolButton_toolkit_clicked()
{
    emit send_toolButton_toolkit_sign();
}

void sshwidget::on_toolButton_upload_clicked()
{
    QString curPath=QDir::currentPath();  //初始化目录
    QString dlgTitle="选择多个文件";   //对话框标题
    QString filter = "所有文件(*.*);;文本文件(*.txt);;图片文件(*.jpg *.gif)";   //文件过滤器
    QStringList fileList = QFileDialog::getOpenFileNames(this,dlgTitle,curPath,filter);  //getOpenFileNames返回选择文件的带路径的完整文件名
    for(int i=0;i<fileList.count();i++) {   //添加文件名到文本框
        qDebug() << "选择路径：" << fileList.at(i);
    }
    //获取当前服务器目录，然后上传
    QString A = fileList.at(0);
    QString fileName;
    int colonIndex = A.lastIndexOf('/');
    if (colonIndex != 1) {
        qDebug() << "上传文件 文件名" << A.mid(colonIndex + 1);
        fileName = A.mid(colonIndex + 1);
    }

    //sendUploadCommandData("C:\\Users\\张旭\\Desktop\\fsdownload\\apinfo.json", "/data/linkdood/im/apinfo.json");
    sendUploadCommandData(A, ssh_path + "/" + fileName);
}
