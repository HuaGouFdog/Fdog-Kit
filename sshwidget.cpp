﻿#pragma execution_character_set("utf-8")
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
QString a = "";

//    // 关闭 SSH 连接
//    libssh2_session_disconnect(session, "Normal shutdown");
//    libssh2_session_free(session);
//    libssh2_exit();
//}

class CustomTextEdit : public QTextEdit {
public:
    CustomTextEdit(QWidget *parent = nullptr) : QTextEdit(parent) {}

protected:
    void mousePressEvent(QMouseEvent *event) override {
        if (event->button() == Qt::LeftButton) {
            // 获取鼠标按下的位置
            startPos = event->pos();
        }

        // 调用父类的事件处理函数
        //QTextEdit::mousePressEvent(event);
    }

    void mouseReleaseEvent(QMouseEvent *event) override {
        if (event->button() == Qt::LeftButton) {
            // 获取鼠标释放的位置
            endPos = event->pos();

            // 设置选择区域
            QTextCursor cursor = cursorForPosition(startPos);
            cursor.setPosition(cursorForPosition(endPos).position(), QTextCursor::KeepAnchor);
            setTextCursor(cursor);
        }

        // 调用父类的事件处理函数
        //QTextEdit::mouseReleaseEvent(event);
    }

private:
    QPoint startPos;
    QPoint endPos;
};


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
    QTextCursor cursor6 = ui->textEdit_6->textCursor();
    cursor6.movePosition(QTextCursor::End);
    ui->textEdit_6->setTextCursor(cursor6);
    ui->textEdit_6->insertHtml(cc);
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

    ui->textEdit_4->setFocus();
    movePos = false;

    ui->textBrowser->setText("这是一段可选中但无需移动光标的文本。");

    // 禁用编辑和光标显示
    //QTextCursor cursor = ui->textEdit->textCursor();
    //cursor.setKeepPositionOnInsert(false);
    //cursor.set
    //ui->textEdit->setTextCursor(cursor);

    CustomTextEdit *textEdit2 = new CustomTextEdit(this);
    textEdit2->setPlainText("Example text");
    //textEdit2.show();

    QPushButton * aa = new QPushButton("xxxxx", this);
    ui->verticalLayout_13->addWidget(aa);
    ui->verticalLayout_13->addWidget(textEdit2);

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
    Layout->addWidget(ui->textEdit_6);
    Layout->addWidget(ui->textEdit);
    ui->widget_10->setLayout(Layout);



    scrollBar_textEdit = ui->textEdit->verticalScrollBar();
//    connect(scrollBar_textEdit,SIGNAL(valueChanged(int)),this,
//                            SLOT(scrollBarValueChanged2(int)));

    scrollBar_textEdit_s = ui->textEdit_6->verticalScrollBar();
    connect(scrollBar_textEdit_s,SIGNAL(valueChanged(int)),this,
                               SLOT(scrollBarValueChanged(int)));

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
    qDebug() << "移动 ";
    // 创建一个选择项
    //记录当前光标位置
//    int rowCount = ui->textEdit->document()->lineCount(); //获取行数
    // 获取鼠标点击位置的 QTextCursor

    QTextCursor cursor = ui->textEdit->textCursor();
//    int currentCursorPosition = cursor.position();
//    cursor.setPosition(currentCursorPosition, QTextCursor::KeepAnchor);

    cursor.movePosition(QTextCursor::End);
    ui->textEdit->setTextCursor(cursor);
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
    QString cc = "主机连接成功\n";
    stringToHtmlFilter(cc);
    stringToHtml(cc,clrR);
    ui->textEdit->insertHtml(cc);
    QTextCursor cursor6 = ui->textEdit_6->textCursor();
    cursor6.movePosition(QTextCursor::End);
    ui->textEdit_6->setTextCursor(cursor6);
    ui->textEdit_6->insertHtml(cc);
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
        QTextCursor cursor6 = ui->textEdit_6->textCursor();
        cursor6.movePosition(QTextCursor::End);
        ui->textEdit_6->setTextCursor(cursor6);
        ui->textEdit_6->insertHtml(cc);
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
        QTextCursor cursor6 = ui->textEdit_6->textCursor();
        cursor6.movePosition(QTextCursor::End);
        ui->textEdit_6->setTextCursor(cursor6);
        ui->textEdit_6->insertHtml(data.mid(commond.length()-1));
        QTextCursor cursor = ui->textEdit->textCursor();
        cursor.movePosition(QTextCursor::End);
        cursor.movePosition(QTextCursor::StartOfLine, QTextCursor::KeepAnchor);
        QString lastLine = cursor.selectedText();
        commond2 = lastLine;
        return;
    }

    if (type != 0) {
        ui->textEdit->insertHtml(data2);
        QTextCursor cursor6 = ui->textEdit_6->textCursor();
        cursor6.movePosition(QTextCursor::End);
        ui->textEdit_6->setTextCursor(cursor6);
        ui->textEdit_6->insertHtml(data2);
    } else {
        ui->textEdit->insertHtml(data);
        QTextCursor cursor6 = ui->textEdit_6->textCursor();
        cursor6.movePosition(QTextCursor::End);
        ui->textEdit_6->setTextCursor(cursor6);
        ui->textEdit_6->insertHtml(data);
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
    //QTextCursor cursor = ui->textEdit->textCursor();

//        QTextCharFormat format;
//        format.setBackground(Qt::transparent);
//        QTextEdit::ExtraSelection selection;
//        selection.format = format;
//        selection.format.setProperty(QTextFormat::FullWidthSelection, true);
//        selection.cursor = cursor;
//        ui->textEdit->setExtraSelections({selection});

    if (scrollBar_textEdit && scrollBar_textEdit_s) {
        qDebug() << "设置滑动条 read " << scrollBar_textEdit->value();
        scrollBar_textEdit->setValue(scrollBar_textEdit->maximum());
        scrollBar_textEdit_s->setValue(scrollBar_textEdit->value());
    }
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

    qDebug() << "x Last Line: " << lastLine;
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

    qDebug() << "z Last Line: " << lastLine;
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
    //QString data = "ls -l\n";
    //sendCommandData(data);
//    movePos = true;
//    QTextCursor tmpCursor = ui->textEdit->textCursor();
//    tmpCursor.movePosition(QTextCursor::Left, QTextCursor::KeepAnchor, 4);//KeepAnchor 是选中 MoveAnchor是正常
//    ui->textEdit->setTextCursor(tmpCursor);
//    ui->textEdit->setFocusPolicy(Qt::StrongFocus);
//    ui->textEdit->setFocus();
//    movePos = false;

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
    ui->textEdit_4->setFocus();
}

void sshwidget::on_textEdit_6_cursorPositionChanged()
{
    ui->textEdit->setFocus();
}

void sshwidget::scrollBarValueChanged(int value)
{
    qDebug() << "滑动条值改变为1：" << value;
    QScrollBar *scrollBar = ui->textEdit->verticalScrollBar();
    scrollBar->setValue(value);
}

void sshwidget::scrollBarValueChanged2(int value)
{
    qDebug() << "滑动条值改变为2：" << value;
    qDebug() << "当前值：" << scrollBar_textEdit->value();
    QScrollBar *scrollBar = ui->textEdit_6->verticalScrollBar();
    scrollBar->setValue(value);
}

void sshwidget::on_textEdit_textChanged()
{
        if (scrollBar_textEdit && scrollBar_textEdit_s) {
            qDebug() << "设置滑动条 ";
            scrollBar_textEdit_s->setValue(scrollBar_textEdit->value());
        }
}