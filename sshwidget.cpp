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
    ui->splitter_1->setStretchFactor(0,1);
    ui->splitter_1->setStretchFactor(1,100);

    ui->splitter_2->setStretchFactor(0,100);
    ui->splitter_2->setStretchFactor(1,2);

    ui->splitter_3->setStretchFactor(0,100);
    ui->splitter_3->setStretchFactor(1,1);

    ui->splitter_4->setStretchFactor(0,1);
    ui->splitter_4->setStretchFactor(1,1);

    ui->textEdit->viewport()->setCursor(Qt::ArrowCursor);
    //表格自适应
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

    setMouseTracking(true);
//    ui->textEdit->insertHtml("<span style=\" color:#ff0505;\"> 扎根  </span>");
//    ui->textEdit->insertHtml("<span style=\" color:#3effc5;\"> 扎根  </span>");
//    ui->textEdit->insertHtml("<span style=\" color:#ffffff;\"> 扎根  </span>");
//    ui->textEdit->insertHtml("<span style=\" color:#3effc5;\"> 扎根  </span>");
    QString host = "172.16.8.154";
    QString port = 22;
    QString username = "root";
    QString password = "Linkdood@123456";

    QTextCharFormat format;

    // 设置格式
//    QFont font;
//    font.setFamily("Cascadia Mono,OPPOSans B");
//    font.setPointSize(10);
//    //format.setFontWeight(QFont::Bold);
//    //format.setForeground(Qt::red);
//    format.setFont(font);
//    ui->textEdit->setCurrentCharFormat(format);

    //初始化
    thread = new QThread();
    m_sshhandle = new sshhandle();

    //thread2 = new QThread();
    m_sshhandle2 = new sshhandle();
    //m_sshhandle2->channel = m_sshhandle->channel;
    // 将对象移动到线程中
    m_sshhandle->moveToThread(thread);
    //m_sshhandle2->moveToThread(thread2);

    connect(m_sshhandle,SIGNAL(send_channel_read(QString)),this,
                            SLOT(rece_channel_read(QString)));
    connect(m_sshhandle,SIGNAL(send_init()),this,
                            SLOT(rece_init()));
    connect(m_sshhandle,SIGNAL(send_getServerInfo(ServerInfoStruct)),this,
                            SLOT(rece_getServerInfo(ServerInfoStruct)));
    thread->start();
    //thread2->start();
    int connrectType = 1;
    QMetaObject::invokeMethod(m_sshhandle,"init",Qt::QueuedConnection, Q_ARG(int, connrectType), Q_ARG(QString, host), Q_ARG(QString,port), Q_ARG(QString,username), Q_ARG(QString,password));


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
    QString cc = "连接主机中...\n";
    QColor  clrR(255,255,255);
    stringToHtmlFilter(cc);
    stringToHtml(cc,clrR);
    ui->textEdit->insertHtml(cc);
    //ui->textEdit->append("连接主机中...");
    //connectAndExecuteCommand(host, port, username, password, command);
    //ui->textEdit->setPlainText(a);

    /*
https://blog.51cto.com/xiaohaiwa/5379626

*/

    keyFilter = new KeyFilter(this);
    connect(keyFilter,SIGNAL(send_enter_sign()),this,
                            SLOT(rece_enter_sign()));
    connect(keyFilter,SIGNAL(send_tab_sign(int)),this,
                            SLOT(rece_tab_sign(int)));
    connect(keyFilter,SIGNAL(send_backSpace_sign(int)),this,
                            SLOT(send_backSpace_sign(int)));
    ui->textEdit->installEventFilter(keyFilter);

    QTextCursor cursor2=ui->textEdit->textCursor();
            cursor2.movePosition(QTextCursor::End);
            ui->textEdit->setTextCursor(cursor2);

            lineNumber = cursor2.blockNumber() + 1;
            columnNumber = cursor2.columnNumber();

    ui->textEdit->setFocus();

}

sshwidget::~sshwidget()
{
    delete ui;
}

void sshwidget::sendCommandData(QString data)
{
    libssh2_channel_write(m_sshhandle->channel, data.toStdString().c_str(), strlen(data.toStdString().c_str()));
}

void sshwidget::on_textEdit_cursorPositionChanged()
{

    //记录当前光标位置
    int rowCount = ui->textEdit->document()->lineCount(); //获取行数

    QTextCursor cursor2=ui->textEdit->textCursor();
    cursor2.movePosition(QTextCursor::End);
    ui->textEdit->setTextCursor(cursor2);
}

void sshwidget::rece_init()
{
    // 设置焦点策略为强制获取焦点
    ui->textEdit->setFocusPolicy(Qt::StrongFocus);
    ui->textEdit->setFocus();
    qDebug("开始调用init_poll");
    QColor  clrR(255,255,255);
    QString cc = "主机连接成功\n";
    stringToHtmlFilter(cc);
    stringToHtml(cc,clrR);
    ui->textEdit->insertHtml(cc);
    //初始化完成调用
    QMetaObject::invokeMethod(m_sshhandle,"init_poll",Qt::QueuedConnection);
    //通知页面，连接成功，可以使用
    qDebug("开始调用init_poll完成");
}

void sshwidget::rece_channel_read(QString data)
{
    //这个接口应该是输出数据，不进行逻辑处理
    qDebug() << "我收到数据啦" << data;
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


    qDebug() << "commond2 = " << commond2;
    qDebug() << "222我收到数据啦" << data << " len = " << data.length();
    qDebug() << "222也收到数据啦" << commond << " len = " <<commond.length();
    int type = 0;
    QString data2 = "";
    if (commond != "" && data.startsWith(commond) && data.length() > commond.length()) {
        //说明命令后面带了数据，提取需要的数据

        data2 = data.mid(commond.length());
        data = commond;
        qDebug() << "2我收到数据啦" << data2;
        type = 1;
    } else if (data == commond && commond != "" && lastCommond == 2) {
        qDebug() << "3我收到数据啦" << data;
        //qDebug() << "3也收到数据啦" << commond;
        QColor  clrR(255,0,0);
        QString cc = "\r\n";
        stringToHtmlFilter(cc);
        stringToHtml(cc,clrR);
        ui->textEdit->insertHtml(cc);
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
        QTextCursor cursor = ui->textEdit->textCursor();
        cursor.movePosition(QTextCursor::End);
        cursor.movePosition(QTextCursor::StartOfLine, QTextCursor::KeepAnchor);
        QString lastLine = cursor.selectedText();
        commond2 = lastLine;
        return;
    }

    if (type != 0) {
        ui->textEdit->insertHtml(data2);
    } else {
        ui->textEdit->insertHtml(data);
    }
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.movePosition(QTextCursor::End);
    cursor.movePosition(QTextCursor::StartOfLine, QTextCursor::KeepAnchor);
    QString lastLine = cursor.selectedText();
    // 打印最后一行数据
    //QString a = "\u001B]0;root@localhost:~\u0007[root@localhost ~]# ";
    //qDebug() << "a: " << a.length();
    qDebug() << "Last Line: " << lastLine;
    commond2 = lastLine;
}

void sshwidget::rece_enter_sign()
{
    lastCommond = 2;
    qDebug() << "命令行前缀为" << commond2;
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.movePosition(QTextCursor::End);
    cursor.movePosition(QTextCursor::StartOfLine, QTextCursor::KeepAnchor);
    QString lastLine = cursor.selectedText();
    // 打印最后一行数据
    //QString a = "\u001B]0;root@localhost:~\u0007[root@localhost ~]# ";
    //qDebug() << "a: " << a.length();
    qDebug() << "Last Line: " << lastLine;
    //从最后一行数据中获取命令
    //int index1 = lastLine.indexOf(commond2);
    QString a = lastLine.mid(0,commond2.length());
    //int index2 = lastLine.indexOf(commond2 + " ");
    QString b = lastLine.mid(commond2.length());
    qDebug() << "Last Line a: " << a;
    qDebug() << "Last Line b: " << b;
    qDebug() << "Last Line a + b: " << a + b;
    //qDebug() << "ui->textEdit->toPlainText() = " << ui->textEdit->toPlainText();

    //删除命令
    // 使用 QTextCursor 定位到最后一行

    // 删除最后一行
    //cursor.removeSelectedText();
    //添加前缀
    //ui->textEdit->setPlainText(ui->textEdit->toPlainText() + a);
    //qDebug() << "ui->textEdit->toPlainText() = " << ui->textEdit->toPlainText();
    //获取信息
    commond = b;
    commond.replace(" ","&nbsp;");
    sendCommandData(b + "\n");
}

void sshwidget::rece_tab_sign(int type)
{
    qDebug() << "命令行前缀为" << commond2;
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.movePosition(QTextCursor::End);
    cursor.movePosition(QTextCursor::StartOfLine, QTextCursor::KeepAnchor);
    QString lastLine = cursor.selectedText();

    qDebug() << "Last Line: " << lastLine;
    QString a = lastLine.mid(0,commond2.length());
    QString b = lastLine.mid(commond2.length());
    qDebug() << "Last Line a: " << a;
    qDebug() << "Last Line b: " << b;
    qDebug() << "Last Line a + b: " << a + b;

    sendCommandData(b + "\t");

    commond = b.replace(" ","&nbsp;");
    lastCommond = 1;
}

void sshwidget::send_backSpace_sign(int type)
{
    qDebug() << "命令行前缀为" << commond2;
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.movePosition(QTextCursor::End);
    // 将光标向前移动一个字符
    cursor.movePosition(QTextCursor::Left, QTextCursor::KeepAnchor);
    // 删除选中的字符
    cursor.deletePreviousChar();

    cursor.movePosition(QTextCursor::End);
    cursor.movePosition(QTextCursor::StartOfLine, QTextCursor::KeepAnchor);
    QString lastLine = cursor.selectedText();

    qDebug() << "Last Line: " << lastLine;
    QString a = lastLine.mid(0,commond2.length());
    QString b = lastLine.mid(commond2.length());
    qDebug() << "Last Line a: " << a;
    qDebug() << "Last Line b: " << b;
    qDebug() << "Last Line a + b: " << a + b;

    sendCommandData(b + "\b");

    commond = b.replace(" ","&nbsp;");
    lastCommond = 3;
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
    QString data = "ls -l\n";
    sendCommandData(data);
}
