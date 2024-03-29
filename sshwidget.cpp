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
#include<QTextCodec>
#include <QElapsedTimer>
#include <QDir>
#include <QFileDialog>
#include <QMenu>
#include <QMimeData>
#include "findwidget.h"
#include "downloadwidget.h"
#include <QTextEdit>
#include <QTextLayout>
#include <QTextBlock>
#include <QShortcut>
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

sshwidget::sshwidget(connnectInfoStruct& cInfoStruct, config * confInfo, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sshwidget)
{
    ui->setupUi(this);

    this->cInfoStruct = cInfoStruct;

    ui->textEdit_2->setOverwriteMode(true);

    ui->splitter_2->setStretchFactor(10,2);

    ui->textEdit->viewport()->setCursor(Qt::ArrowCursor);
    //表格自适应
    //ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

    setMouseTracking(true);
    QString host = cInfoStruct.host;
    QString port = cInfoStruct.port;
    QString username = cInfoStruct.userName;
    QString password = cInfoStruct.password;


    //快捷键 ctrl + shift + F 查找
    QShortcut *shortcutF = new QShortcut(QKeySequence(Qt::CTRL + Qt::SHIFT + Qt::Key_F), this);
    connect(shortcutF, SIGNAL(activated()), this, SLOT(rece_toolButton_find_clicked()));

    //快捷键 ctrl + shift + c 复制
    QShortcut *shortcutC = new QShortcut(QKeySequence(Qt::CTRL + Qt::SHIFT + Qt::Key_C), this);
    connect(shortcutC, SIGNAL(activated()), this, SLOT(rece_copy_sgin()));

    //快捷键 ctrl + shift + v 粘贴
    QShortcut *shortcutV = new QShortcut(QKeySequence(Qt::CTRL + Qt::SHIFT + Qt::Key_V), this);
    connect(shortcutV, SIGNAL(activated()), this, SLOT(rece_paste_sgin()));

    //初始化
    int connrectType = 1;
    thread = new QThread();
    m_sshhandle = new sshhandle();
    //thread2 = new QThread();
    //m_sshhandle2 = new sshhandle();
    //m_sshhandle2->channel = m_sshhandle->channel;
    // 将对象移动到线程中
    m_sshhandle->moveToThread(thread);
    //m_sshhandle2->moveToThread(thread2);

    connect(m_sshhandle,SIGNAL(send_channel_readS(QStringList)),this,
            SLOT(rece_channel_readS(QStringList)), Qt::QueuedConnection);
    connect(m_sshhandle,SIGNAL(send_init()),this,
            SLOT(rece_ssh_init()));
    connect(m_sshhandle,SIGNAL(send_getServerInfo(ServerInfoStruct)),this,
            SLOT(rece_getServerInfo(ServerInfoStruct)));
    thread->start();
    qDebug("执行0");
    //这里设置初始化方式
    //密码
    //密钥 Path name of the public key file. (e.g. /etc/ssh/hostkey.pub). If libssh2 is built against OpenSSL, this option can be set to NULL.
    QMetaObject::invokeMethod(m_sshhandle,"init",Qt::QueuedConnection, Q_ARG(int, connrectType), Q_ARG(QString, host), Q_ARG(QString,port), Q_ARG(QString,username), Q_ARG(QString,password));
    qDebug("执行01");

    //exec
    threadExec = new QThread();
    sshExec = new sshHandleExec();
    sshExec->moveToThread(threadExec);
    connect(sshExec, SIGNAL(send_getServerInfo(ServerInfoStruct)),this,
            SLOT(rece_getServerInfo(ServerInfoStruct)));
    connect(sshExec,SIGNAL(send_init()),this,
            SLOT(rece_ssh_exec_init()));
    threadExec->start();
    //QMetaObject::invokeMethod(sshExec,"init", Qt::QueuedConnection, Q_ARG(int, connrectType), Q_ARG(QString, host), Q_ARG(QString,port), Q_ARG(QString,username), Q_ARG(QString,password));

    //sftp
    sshSftp = new sshHandleSftp();
    threadSftp = new QThread();
    sshSftp->moveToThread(threadSftp);
    connect(sshSftp, SIGNAL(send_fileProgress_sgin(int64_t,int64_t)),this,
            SLOT(rece_fileProgress_sgin(int64_t,int64_t)));

    connect(sshSftp, SIGNAL(send_createNewFile_sgin(QString,QString,int,int64_t)),this,
            SLOT(rece_createNewFile_sgin(QString,QString,int,int64_t)));
    threadSftp->start();
    qDebug("执行3");
    //QMetaObject::invokeMethod(sshSftp,"init", Qt::QueuedConnection, Q_ARG(int, connrectType), Q_ARG(QString, host), Q_ARG(QString,port), Q_ARG(QString,username), Q_ARG(QString,password));
    textEdit_s = new CustomTextEdit(this);
    textEdit_s->setReadOnly(true);
    textEdit_s->viewport()->setCursor(Qt::ArrowCursor);
    textEdit_s->setLineWrapMode(QTextEdit::NoWrap); //不自动换行
    textEdit_s->setStyleSheet("CustomTextEdit{ \
                                background-color: rgb(0, 41, 169, 0);\
                                selection-background-color: rgb(50, 130, 190);\
                                font: 12pt \"Cascadia Mono,OPPOSans B\";\
                                border: none;\
                                    padding-top:0px;\
                                    padding-bottom:0px;\
                                    padding-left:0px;\
                                    padding-right:0px;\
                                    border-radius: 5px;\
                                color: rgba(255, 255, 255, 255);\
                                }\
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


    QString cc = "连接主机中...<br>";
    ui->textEdit->insertHtml(cc);

    movePositionEnd();
    textEdit_s->insertHtml(cc);

    keyFilter = new KeyFilter(this);

    connect(keyFilter,SIGNAL(send_key_sign(QString)),this,
            SLOT(rece_key_sign(QString)));

    ui->textEdit->installEventFilter(keyFilter);

    mouseFilter = new MouseFilter(this);
    QTextCursor cursor2=ui->textEdit->textCursor();
    lineNumber = cursor2.blockNumber() + 1;
    columnNumber = cursor2.columnNumber();

    movePos = false;

    ui->textEdit->setCursorWidth(2);

    dlwidget = new downloadwidget(textEdit_s);
    fwidget = new findwidget(textEdit_s);
    fwidget->hide();
    hcwidget = new historycommondwidget(textEdit_s);
    hcwidget->hide();

    QStackedLayout * Layout = new QStackedLayout;
    Layout->setStackingMode(QStackedLayout::StackAll);
    Layout->setContentsMargins(0,0,0,0);
    Layout->addWidget(textEdit_s);
    Layout->addWidget(ui->textEdit);

    ui->widget_9->setLayout(Layout);

    connect(textEdit_s,SIGNAL(send_mousePress_sign()),this,
            SLOT(rece_send_mousePress_sign()));
    connect(textEdit_s,SIGNAL(send_paste_sgin()),this,
            SLOT(rece_paste_sgin()));
    connect(textEdit_s,SIGNAL(send_resize_sign()),this,
            SLOT(rece_resize_sign()));

    scrollBar_textEdit = ui->textEdit->verticalScrollBar();

    scrollBar_textEdit_s = textEdit_s->verticalScrollBar();
    connect(scrollBar_textEdit_s,SIGNAL(valueChanged(int)),this,
            SLOT(scrollBarValueChanged(int)));

    textEdit_s->setContextMenuPolicy(Qt::CustomContextMenu);
    //textEdit_s->setContextMenuPolicy(Qt::NoContextMenu);

    QAction *findAction = new QAction(tr("查找   Ctrl+Shift+F"), textEdit_s);
    //findAction->setShortcut(QKeySequence::Copy);
    findAction->setShortcutContext(Qt::WidgetShortcut);

    QAction *copyAction = new QAction(tr("复制   Ctrl+Shift+C"), textEdit_s);
    //copyAction->setShortcut(QKeySequence::Copy);
    copyAction->setShortcutContext(Qt::WidgetShortcut);

    QAction *pasteAction = new QAction(tr("粘贴   Ctrl+Shift+V"), textEdit_s);
    //pasteAction->setShortcut(QKeySequence::Copy);
    pasteAction->setShortcutContext(Qt::WidgetShortcut);

    QAction *downloadAction = new QAction(tr("下载"), textEdit_s);
    //downloadAction->setShortcut(QKeySequence::Copy);
    downloadAction->setShortcutContext(Qt::WidgetShortcut);

    QAction *uploadAction = new QAction(tr("上传"), textEdit_s);
    //uploadAction->setShortcut(QKeySequence::Copy);
    uploadAction->setShortcutContext(Qt::WidgetShortcut);

    QAction *selectAllAction = new QAction(tr("选择全部"), textEdit_s);
    selectAllAction->setShortcut(QKeySequence::SelectAll);
    selectAllAction->setShortcutContext(Qt::WidgetShortcut);

    QAction *clearAction = new QAction(tr("清除"), textEdit_s);

    QMenu *contextMenu = new QMenu(textEdit_s);
    contextMenu->setWindowFlags(contextMenu->windowFlags()  | Qt::FramelessWindowHint | Qt::NoDropShadowWindowHint);
    contextMenu->setAttribute(Qt::WA_TranslucentBackground);
    contextMenu->addAction(findAction);
    contextMenu->addSeparator();
    contextMenu->addAction(copyAction);
    contextMenu->addSeparator();
    contextMenu->addAction(pasteAction);
    contextMenu->addSeparator();
    contextMenu->addAction(downloadAction);
    contextMenu->addSeparator();
    contextMenu->addAction(uploadAction);
    contextMenu->addSeparator();
    contextMenu->addAction(selectAllAction);
    contextMenu->addSeparator();
    contextMenu->addAction(clearAction);

    connect (findAction,SIGNAL(triggered()),this,SLOT(rece_find_sgin()));
    connect (copyAction,SIGNAL(triggered()),this,SLOT(rece_copy_sgin()));
    connect (pasteAction,SIGNAL(triggered()),this,SLOT(rece_paste_sgin()));
    connect (downloadAction,SIGNAL(triggered()),this,SLOT(rece_downloadFile_sgin()));
    connect (uploadAction,SIGNAL(triggered()),this,SLOT(on_toolButton_upload_clicked()));
    QObject::connect(textEdit_s, &QTextEdit::customContextMenuRequested, [=]()
    {
        qDebug() << "点击";
        contextMenu->move(cursor().pos());
        contextMenu->show(); });
    //ui->widget->hide();
    //ui->widget_3->hide();
    //ui->widget_4->hide();
    //ui->horizontalWidget->hide();

    ui->textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    textEdit_s->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    isScrollBar = false;
    /*
        "infoDisplay": 1,
        "historyDisplay": 1,
        "commandDisplay": 1,
        "conectStatsDisplay": 1,
    */
    if (confInfo->infoDisplay == 0) {
        ui->widget->hide();
        ui->toolButton_info->hide();
    }

    if (confInfo->historyDisplay == 0) {
        //hcwidget->hide();
        ui->toolButton_history->hide();
    }

    if (confInfo->commandDisplay == 0) {
        ui->widget_bottom->hide();
        ui->toolButton_command->hide();
    }

    if (confInfo->conectStatsDisplay == 0) {
        ui->widget->hide();
        ui->toolButton_conectStats->hide();
    }

    ui->textEdit_4->append("<scrollRegion top=\"1\" bottom=\"26\"/>\n");
    ui->textEdit_4->append("Hello, world!\n");
    ui->textEdit_4->append("<scrollDown/>\n");
}

sshwidget::~sshwidget()
{
    delete ui;
}

void sshwidget::sendCommandData(QString data)
{
    libssh2_channel_write(m_sshhandle->channel_ssh, data.toStdString().c_str(), strlen(data.toStdString().c_str()));
}

void sshwidget::sendUploadCommandData(QString local_file_path, QString remote_file_path, QString fileName)
{
    //调子线程执行
    QMetaObject::invokeMethod(sshSftp,"uploadFile", Qt::QueuedConnection, Q_ARG(QString, local_file_path), Q_ARG(QString,remote_file_path), Q_ARG(QString,fileName));
}

void sshwidget::setTerminalSize(int height, int width)
{
    if (m_sshhandle->channel_ssh == nullptr) {
        return;
    }
    int ret = libssh2_channel_request_pty_size(m_sshhandle->channel_ssh, width, height);
    if (ret != 0) {
        //qDebug() << "libssh2_channel_request_pty_size出错" << ret;
    }
}

void sshwidget::sendData(QString data)
{
    if (data == "") {
        return;
    }
//    if (data[0] == '~') {
//        data = data + "<br>";
//    }
    QTextCursor cursor = ui->textEdit->textCursor();
    int currentPosition = cursor.position();
    QTextCursor cursor_s = textEdit_s->textCursor();
    cursor_s.setPosition(currentPosition);
    textEdit_s->setTextCursor(cursor_s);


    textEdit_s->insertHtml(data);
    QString data2 =data;
    //qDebug()<< "data = " << data;
    //data2.replace("opacity: 1;","opacity: 0;");
    ui->textEdit->insertHtml(data2);
    //qDebug()<< "data2 = " << data2;
    QPalette palette = ui->textEdit->palette();
    palette.setColor(QPalette::Text, QColor(0, 0, 0, 0)); // 文字颜色设置为透明
    ui->textEdit->setPalette(palette);
}

void sshwidget::setData(QString data)
{

    ui->textEdit->setHtml("");
    ui->textEdit->setHtml(data);

    textEdit_s->setHtml("");
    textEdit_s->setHtml(data);
    movePositionEnd();
}

void sshwidget::movePositionUp(sshwidget::MoveMode mode, int n)
{
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.movePosition(QTextCursor::Up, QTextCursor::MoveAnchor, n);
    ui->textEdit->setTextCursor(cursor);

    QTextCursor cursor2 = textEdit_s->textCursor();
    cursor2.movePosition(QTextCursor::Up, QTextCursor::MoveAnchor, n);
    textEdit_s->setTextCursor(cursor2);
}

void sshwidget::movePositionDown(sshwidget::MoveMode mode, int n)
{
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.movePosition(QTextCursor::Down, QTextCursor::MoveAnchor, n);
    ui->textEdit->setTextCursor(cursor);

    QTextCursor cursor2 = textEdit_s->textCursor();
    cursor2.movePosition(QTextCursor::Down, QTextCursor::MoveAnchor, n);
    textEdit_s->setTextCursor(cursor2);
}

void sshwidget::movePositionLeft(sshwidget::MoveMode mode, int n)
{
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.movePosition(QTextCursor::Right, QTextCursor::MoveAnchor, n);
    ui->textEdit->setTextCursor(cursor);

    QTextCursor cursor2 = textEdit_s->textCursor();
    cursor2.movePosition(QTextCursor::Right, QTextCursor::MoveAnchor, n);
    textEdit_s->setTextCursor(cursor2);
}

void sshwidget::movePositionRight(sshwidget::MoveMode mode, int n)
{
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.movePosition(QTextCursor::Left, QTextCursor::MoveAnchor, n);
    ui->textEdit->setTextCursor(cursor);

    QTextCursor cursor2 = textEdit_s->textCursor();
    cursor2.movePosition(QTextCursor::Left, QTextCursor::MoveAnchor, n);
    textEdit_s->setTextCursor(cursor2);
}

void sshwidget::movePositionStartLine(sshwidget::MoveMode mode)
{
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.movePosition(QTextCursor::StartOfLine);
    ui->textEdit->setTextCursor(cursor);

    QTextCursor cursor2 = textEdit_s->textCursor();
    cursor2.movePosition(QTextCursor::StartOfLine);
    textEdit_s->setTextCursor(cursor2);
}

void sshwidget::movePositionEndLine(sshwidget::MoveMode mode)
{
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.movePosition(QTextCursor::EndOfLine);
    ui->textEdit->setTextCursor(cursor);

    QTextCursor cursor2 = textEdit_s->textCursor();
    cursor2.movePosition(QTextCursor::EndOfLine);
    textEdit_s->setTextCursor(cursor2);
}

void sshwidget::movePositionEnd(sshwidget::MoveMode mode)
{
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.movePosition(QTextCursor::End);
    ui->textEdit->setTextCursor(cursor);

    QTextCursor cursor2 = textEdit_s->textCursor();
    cursor2.movePosition(QTextCursor::End);
    textEdit_s->setTextCursor(cursor2);
}

QString sshwidget::movePositionLeftSelect(sshwidget::MoveMode mode, int n)
{
    QTextCursor cursor = textEdit_s->textCursor();
    cursor.movePosition(QTextCursor::Right, QTextCursor::KeepAnchor, n);
    return cursor.selectedText();
}

QString sshwidget::movePositionRightSelect(sshwidget::MoveMode mode, int n)
{
    QTextCursor cursor = textEdit_s->textCursor();
    cursor.movePosition(QTextCursor::Left, QTextCursor::KeepAnchor, n);
    return cursor.selectedText();
}

void sshwidget::movePositionRemoveLeftSelect(sshwidget::MoveMode mode, int n)
{
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.movePosition(QTextCursor::Right, QTextCursor::KeepAnchor, n);
    cursor.removeSelectedText();
    ui->textEdit->setTextCursor(cursor);

    QTextCursor cursor2 = textEdit_s->textCursor();
    cursor2.movePosition(QTextCursor::Right, QTextCursor::KeepAnchor, n);
    cursor2.removeSelectedText();
    textEdit_s->setTextCursor(cursor2);
}

void sshwidget::movePositionRemoveEndLineSelect(sshwidget::MoveMode mode, int n)
{
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.movePosition(QTextCursor::EndOfLine, QTextCursor::KeepAnchor);
    cursor.removeSelectedText();
    ui->textEdit->setTextCursor(cursor);
    QTextCursor cursor2 = textEdit_s->textCursor();
    cursor2.movePosition(QTextCursor::EndOfLine, QTextCursor::KeepAnchor);
    cursor2.removeSelectedText();
    textEdit_s->setTextCursor(cursor2);
}

void sshwidget::movePositionRemoveRight(sshwidget::MoveMode mode, int n)
{
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.movePosition(QTextCursor::Left, QTextCursor::KeepAnchor, n);
    cursor.deletePreviousChar();
    ui->textEdit->setTextCursor(cursor);

    QTextCursor cursor2 = textEdit_s->textCursor();
    cursor2.movePosition(QTextCursor::Left, QTextCursor::KeepAnchor, n);
    cursor2.deletePreviousChar();
    textEdit_s->setTextCursor(cursor2);
}

void sshwidget::on_textEdit_cursorPositionChanged()
{

}

void sshwidget::rece_init()
{
    // 设置焦点策略为强制获取焦点
    ui->textEdit->setFocusPolicy(Qt::NoFocus);
    ui->textEdit->setFocus();
    qDebug("开始调用init_poll");
    QString cc = "主机连接成功<br>";
    ui->textEdit->insertHtml(cc);
    movePositionEnd();

    textEdit_s->insertHtml(cc);

    //初始化完成调用
    QMetaObject::invokeMethod(m_sshhandle,"init_poll",Qt::QueuedConnection);
    //通知页面，连接成功，可以使用
    qDebug("开始调用init_poll完成");
}

void sshwidget::rece_channel_readS(QStringList data)
{
    data.removeAll("");  // 删除空字符串
    //data.append("");
    int sum = 0;
    int sum2 = 0;
    //第一条固定为工作路径
    ssh_path = data[0];
    data = data.mid(1);
    qDebug() << "rece_channel_readS data  = " << data;
    int i = 0;
    for(i = 0; i < data.length(); i++) {
        //qDebug() << "lastCommondS =  " << lastCommondS;
        if (data[i] == "\b" && lastCommondS == "\u001B[D") {
            data[i] = "\u001B[D";
            lastCommondS = "";
        }
        lastData = data[i];
        if (lastData == "\u001B[D" || lastData == "\b") {
            backspaceSum++;
        }

        if (lastCommondS == "\u001BOC") {
            //data[i].length() 可能不是1
            //删除右边一个字符，并打印
            movePositionLeft(sshwidget::MoveAnchor, 1);
            sendData(data[i]);
            lastCommondS = "";
            continue;
        }

        if (lastCommondS == "\u001BOB") {
            if (data[i] == "<br>") {
                movePositionDown(sshwidget::MoveAnchor, 1);
                movePositionStartLine(sshwidget::MoveAnchor);
            } else if (data[i].contains("<br>")) {
                int position = data[i].indexOf("<br>");
                if (position == 0) {
                    movePositionDown(sshwidget::MoveAnchor, 1);
                    movePositionStartLine(sshwidget::MoveAnchor);

                    // 获取选定文本
                    QString previousChar = movePositionLeftSelect(sshwidget::KeepAnchor, data[i].mid(4).length());
                    isRightShiftChinese = previousChar.contains(QRegExp("[\\x4e00-\\x9fa5]+"));

                    if(isRightShiftChinese) {
                        if (ChineseRightShiftSum!= 0) {
                            movePositionLeft(sshwidget::MoveAnchor, data[i].mid(4).length());
                            isRightShiftChinese = false;
                            ChineseRightShiftSum = 0;
                        } else {
                            //记录
                            isRightShiftChinese = true;
                            ChineseRightShiftSum++;
                        }
                    } else {
                        movePositionLeft(sshwidget::MoveAnchor, data[i].mid(4).length());
                    }
                }
            } else {
                int pos = 0;
                QRegExp regExp2("\\x001B\\[(\\d+);(\\d+)H");
                while ((pos = regExp2.indexIn(data[i], pos)) != -1) {
                    QTextCursor tc = ui->textEdit->textCursor(); //当前光标
                    QTextLayout *lay = tc.block().layout();
                    int iCurPos= tc.position() - tc.block().position();//当前光标在本BLOCK内的相对位置
                    int acurrentLine = lay->lineForTextPosition(iCurPos).lineNumber() + tc.block().firstLineNumber();

                    QTextCursor tc2 = textEdit_s->textCursor(); //当前光标
                    QTextLayout *lay2 = tc2.block().layout();
                    int iCurPos2= tc2.position() - tc2.block().position();//当前光标在本BLOCK内的相对位置
                    int acurrentLine2 = lay2->lineForTextPosition(iCurPos2).lineNumber() + tc2.block().firstLineNumber();
                    int moveCount = regExp2.cap(1).toInt() + currentLine - 1;
                    moveCount = moveCount - acurrentLine;
                    if (moveCount >= 0) {
                        movePositionDown(sshwidget::MoveAnchor, moveCount);
                        movePositionStartLine(sshwidget::MoveAnchor);
                        movePositionLeft(sshwidget::MoveAnchor, regExp2.cap(2).toInt() - 1);
                    } else {
                        movePositionDown(sshwidget::MoveAnchor, -moveCount);
                        movePositionStartLine(sshwidget::MoveAnchor);
                        movePositionLeft(sshwidget::MoveAnchor, regExp2.cap(2).toInt() - 1);
                    }
                    data[i].replace(regExp2.cap(0), "");
                }
            }
            lastCommondS = "";

            continue;
        }

        if (data[i] == "<br>") {
            if (!isBuffer && clearSPos == 0) {
                // 获取当前文本光标
                QTextCursor cursor = ui->textEdit->textCursor();
                // 在当前光标位置插入一个新的空白行
                cursor.insertBlock();
                // 将光标移动到新插入的空白行
                cursor.movePosition(QTextCursor::NextBlock);
                // 设置文本光标
                ui->textEdit->setTextCursor(cursor);

                QTextCursor cursor2 = textEdit_s->textCursor();
                // 在当前光标位置插入一个新的空白行
                cursor2.insertBlock();
                // 将光标移动到新插入的空白行
                cursor2.movePosition(QTextCursor::NextBlock);
                // 设置文本光标
                textEdit_s->setTextCursor(cursor2);
            } else {
                movePositionDown(sshwidget::MoveAnchor, 1);
                if (clearSPos > 0) {
                    clearSPos--;
                    qDebug() << "clearSPos-- =" << clearSPos;
                }
            }

            continue;
        } else if (data[i] == "\r") {
            movePositionStartLine(sshwidget::MoveAnchor);
            isEnter = true;
            continue;
        } else if (data[i] == "\b") {
            sum++;
            QString previousChar = movePositionRightSelect(sshwidget::KeepAnchor, 1);
            //qDebug() << "1前一个字符为" << previousChar2;
            isChinese = previousChar.contains(QRegExp("[\\x4e00-\\x9fa5]+"));

            if(isChinese) {
                if (ChineseBackspaceSum!= 0) {
                    movePositionRight(sshwidget::MoveAnchor, 1);
                    isChinese = false;
                    ChineseBackspaceSum = 0;
                } else {
                    //记录
                    isChinese = true;
                    ChineseBackspaceSum++;
                }
            } else {
                movePositionRight(sshwidget::MoveAnchor, 1);
            }
            continue;
        } else if (data[i] == "\u001B[C") {
            backspaceSum--;
            // 获取选定文本
            QString previousChar = movePositionLeftSelect(sshwidget::KeepAnchor, 1);
            //qDebug() << "后一个字符为" << previousChar;
            isRightShiftChinese = previousChar.contains(QRegExp("[\\x4e00-\\x9fa5]+"));

            if(isRightShiftChinese) {
                if (ChineseRightShiftSum!= 0) {
                    movePositionLeft(sshwidget::MoveAnchor, 1);
                    isRightShiftChinese = false;
                    ChineseRightShiftSum = 0;
                } else {
                    //记录
                    isRightShiftChinese = true;
                    ChineseRightShiftSum++;
                }
            } else {
                movePositionLeft(sshwidget::MoveAnchor, 1);
            }
            continue;
        } else if (data[i] == "\u001B[D") {
            // 获取选定文本
            QString previousChar = movePositionRightSelect(sshwidget::KeepAnchor, 1);
            isChinese = previousChar.contains(QRegExp("[\\x4e00-\\x9fa5]+"));

            if(isChinese) {
                if (ChineseBackspaceSum!= 0) {
                    movePositionRight(sshwidget::MoveAnchor, 1);
                    isChinese = false;
                    ChineseBackspaceSum = 0;
                } else {
                    //记录
                    isChinese = true;
                    ChineseBackspaceSum++;
                }
            } else {
                movePositionRight(sshwidget::MoveAnchor, 1);
            }
            continue;
        } else if (data[i] == "\u001B[K") {
            //qDebug() << "删除光标后面的数据";
            movePositionRemoveEndLineSelect(sshwidget::KeepAnchor, -1);
            sum = 0;
            continue;
        } else if (data[i] == "\u001B[?1049h") {
            //qDebug()<< "开启副缓冲区";
            //保存主缓存区位置
            ZData = ui->textEdit->toHtml();
            //切换到备缓冲区
            isBuffer = true;
            continue;
        } else if (data[i] == "\u001B[?1049l") {
            //qDebug()<< "关闭副缓冲区";
            //切换到主缓冲区
            isBuffer = false;
            currentLine = -1;
            setData(ZData);
            continue;
        } else if (data[i] == "\u001B[?1h") {
            //启用光标键应用程序模式
            continue;
        } else if (data[i] == "\u001B=") {
            //切换到应用程序键盘模式
            mode = 2;
            continue;
        } else if (data[i] == "\u001B>") {
            //切换到数字模式模式
            mode = 1;
            continue;
        } else if (data[i] == "\u001B[?12l") {
            data[i] = "";
            //continue;
            if (backspaceSum > 0) {
                //lastData == "\u001B[D" || lastData == "\b"
                //光标删除后面一位
                qDebug() << "backspaceSum1 =" << backspaceSum << " data[i] = " << data[i];
                qDebug() << "删除数据";
                //backspaceSum = backspaceSum - 1;
                lastData = "";
                int sum = 0;
                if (backspaceSum >= 1) {
                    backspaceSum = backspaceSum - 1;
                    sum = 1;
                } else {
                    sum = backspaceSum;
                    backspaceSum = 0;
                }
                //qDebug() << "backspaceSum2 =" << backspaceSum;
                movePositionRemoveLeftSelect(sshwidget::KeepAnchor, sum);
            }
        } else if (data[i] == "\u001B[?25h") {
            //显示光标
            data[i] = "";
            //continue;
            if (backspaceSum > 0) {
                //光标删除后面一位
                qDebug() << "backspaceSum1 =" << backspaceSum << " data[i] = " << data[i];
                qDebug() << "删除数据";
                lastData = "";
                int sum = 0;
                sum = backspaceSum;
                backspaceSum = 0;
                qDebug() << "backspaceSum2 =" << backspaceSum;
                movePositionRemoveLeftSelect(sshwidget::KeepAnchor, sum);
            }
        } else if (data[i] == "\u001B[?1l") {
            continue;
        } else if (data[i] == "\u001B[?1h") {
            continue;
        } else if (data[i] == "\u001B[2J") {
            //清空终端屏幕
            clearPos = i;
            lastCommondS = "clear";
            continue;
        } else if (data[i] == "\u001B[3;J") {
            data[i] = "";
            continue;
        } else if (data[i] == "\u001B[?25l") {
            //文本光标隐藏显示
            continue;
        } else if (data[i] == "\u001B[?12;25h") {
            continue;
        } else if (data[i] == "\u001B[H") {
            continue;
        }  else if (data[i] == "\u001B(B") {
            continue;
        } else {
            //qDebug() << "走到这里1 data[i] = " << data[i];
            QRegExp regExp("\\x001B\\[(\\d+)*P");
            int pos = 0;
            bool isa = false;
            while ((pos = regExp.indexIn(data[i], pos)) != -1) {
                QString match = regExp.cap(1); //删除
                //获取当前光标位置
                //movePositionEndLine(sshwidget::MoveAnchor)

                //原位置
                int pos1  = ui->textEdit->textCursor().position();
                int pos2  = textEdit_s->textCursor().position();
                movePositionEndLine(sshwidget::MoveAnchor);
                movePositionRemoveRight(sshwidget::KeepAnchor, match.toInt());

                QTextCursor cursor = ui->textEdit->textCursor();
                cursor.setPosition(pos1);
                ui->textEdit->setTextCursor(cursor);
                QTextCursor cursor2 = textEdit_s->textCursor();
                cursor2.setPosition(pos2);
                textEdit_s->setTextCursor(cursor2);
                sum = sum - match.toInt();
                data[i].replace(regExp.cap(0), "");
                isa = true;
            }
            pos = 0;
            QRegExp regExp2("\\x001B\\[(\\d+);(\\d+)H");
            while ((pos = regExp2.indexIn(data[i], pos)) != -1) {
                QTextCursor tc = ui->textEdit->textCursor(); //当前光标
                QTextLayout *lay = tc.block().layout();
                int iCurPos= tc.position() - tc.block().position();//当前光标在本BLOCK内的相对位置
                int acurrentLine = lay->lineForTextPosition(iCurPos).lineNumber() + tc.block().firstLineNumber();
                //qDebug() << "A当前光标所在行数 =" << acurrentLine;
                //qDebug() << "R当前行数 =" << currentLine;
                QTextCursor tc2 = textEdit_s->textCursor(); //当前光标
                QTextLayout *lay2 = tc2.block().layout();
                int iCurPos2= tc2.position() - tc2.block().position();//当前光标在本BLOCK内的相对位置
                int acurrentLine2 = lay2->lineForTextPosition(iCurPos2).lineNumber() + tc2.block().firstLineNumber();
                int moveCount = regExp2.cap(1).toInt() + currentLine - 1;
                moveCount = moveCount - acurrentLine;
                if (moveCount >= 0) {
                    movePositionDown(sshwidget::MoveAnchor, moveCount);
                    movePositionStartLine(sshwidget::MoveAnchor);
                    movePositionRight(sshwidget::MoveAnchor, regExp2.cap(2).toInt() - 1);
                } else {
                    movePositionDown(sshwidget::MoveAnchor, -moveCount);
                    movePositionStartLine(sshwidget::MoveAnchor);
                    movePositionRight(sshwidget::MoveAnchor, regExp2.cap(2).toInt() - 1);
                }
                data[i].replace(regExp2.cap(0), "");
            }

            pos = 0;
            QRegExp regExp3("\\x001B\\[(\\d+)*m");
            while ((pos = regExp3.indexIn(data[i], pos)) != -1) {
                //qDebug() << "检测到m系列";
                data[i].replace(regExp3.cap(0), "");
                //break;
            }

            pos = 0;
            QRegExp regExp6("\\x001B\\[(\\d+)*;(\\d+)*m");
            while ((pos = regExp6.indexIn(data[i], pos)) != -1) {
                //qDebug() << "检测到m系列";
                data[i].replace(regExp6.cap(0), "");
                //break;
            }

            pos = 0;
            QRegExp regExp4("\\x001B\\[(\\d+)*;(\\d+)*r");
            while ((pos = regExp4.indexIn(data[i], pos)) != -1) {
                qDebug() << "检测到r系列";
                if (currentLine == -1) {
                    QTextCursor tc = ui->textEdit->textCursor(); //当前光标
                    QTextLayout *lay = tc.block().layout();
                    int iCurPos= tc.position() - tc.block().position();//当前光标在本BLOCK内的相对位置
                    currentLine = lay->lineForTextPosition(iCurPos).lineNumber() + tc.block().firstLineNumber();
                    qDebug() << "R当前行数 =" << currentLine;
                    scrollZone = regExp4.cap(2).toInt();
                    if (regExp4.cap(1) == "1") {
                        for (int i = 1; i <= regExp4.cap(2).toInt(); ++i) {
                            //qDebug() << "打印空行" << i;
                            //sendData(QString::number(i) + "=<br>");
                            //这里应该发送当前列数
                            sendData("<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;");
                            //textEdit->insertPlainText("\n");
                        }
                    }
                    data[i].replace(regExp4.cap(0), "");
                } else {
                    int a = 0;
                    if(scrollZone <= regExp4.cap(2).toInt()) {
                        a = regExp4.cap(2).toInt() - scrollZone;
                        scrollZone = regExp4.cap(2).toInt();
                    }
                    qDebug() << "扩大滚动区为" << scrollZone;
                    qDebug() << "增加行数" << a;
                    if (regExp4.cap(1) == "1") {
                        for (int i = 1; i <= a; ++i) {
                            //qDebug() << "打印空行" << i;
                            //sendData(QString::number(i) + "=<br>");
                            //这里应该发送当前列数
                            sendData("<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;");
                            //textEdit->insertPlainText("\n");
                        }
                    }
                    data[i].replace(regExp4.cap(0), "");
                }
                //break;
            }

            pos = 0;
            QRegExp regExp5("\\x001B\\[(\\d+)G");
            while ((pos = regExp5.indexIn(data[i], pos)) != -1) {
                //qDebug() << "检测到G系列 =" << regExp5.cap(1);
                movePositionLeft(sshwidget::MoveAnchor, regExp5.cap(1).toInt()-1);
                data[i].replace(regExp5.cap(0), "");
                //break;
            }
            if (!isa) {
                if (sum != 0) {
                    //qDebug() << "走到这里7";
                    QTextCursor cursor4 = ui->textEdit->textCursor();
                    //QTextCursor cursor2 = textEdit_s->textCursor();
                    int cursorPos = cursor4.position();
                    int textLength = ui->textEdit->toPlainText().length();
                    int charsToEnd = textLength - cursorPos;

                    //覆盖 如果data[i]有数据就覆盖几个，剩下的继续覆盖
                    if (sum != 0) {
                        QTextCursor cursor = ui->textEdit->textCursor();
                        cursor.movePosition(QTextCursor::Right, QTextCursor::KeepAnchor, sum);
                        cursor.deletePreviousChar();
                        ui->textEdit->setTextCursor(cursor);

                        QTextCursor cursor2 = textEdit_s->textCursor();
                        cursor2.movePosition(QTextCursor::Right, QTextCursor::KeepAnchor, sum);
                        cursor2.deletePreviousChar();
                        textEdit_s->setTextCursor(cursor2);
                        sum = 0;
                    }
                }
                if (isEnter && data[i].length()!= 0) {
                    //qDebug() << "1删除" << data[i].length();

                    isEnter = false;
                    movePositionRemoveLeftSelect(sshwidget::KeepAnchor, data[i].length());
                }
                qDebug() << "A准备打印" << data[i];

                if (data[i].contains("<br>")) {
                    int position = data[i].indexOf("<br>");
                    if (position == -4) {
                        //dataS.append(data[i].mid(0, 3));
                    } else {
                        while(1) {
                            int position2 = 0;
                            if (data[i].contains("<br>")) {
                                position2 = data[i].indexOf("<br>");
                                sendData(data[i].mid(0, position2));
                                //如果下面有空行，则直接下移，没有则创建
                                //qDebug() << "总行数为" << lineCount << " data[i].mid(0, position2) = " << data[i].mid(0, position2);
                                QTextCursor tc = ui->textEdit->textCursor(); //当前光标
                                QTextLayout *lay = tc.block().layout();
                                int iCurPos= tc.position() - tc.block().position();//当前光标在本BLOCK内的相对位置
                                int acurrentLine = lay->lineForTextPosition(iCurPos).lineNumber() + tc.block().firstLineNumber();
                                //qDebug() << "sendData 当前光标所在行数 =" << acurrentLine - currentLine + 1 << " 起点行数=" << currentLine << " 共" << scrollZone << "行";
                                if (acurrentLine - currentLine + 1 < scrollZone) {
                                    movePositionDown(sshwidget::MoveAnchor, 1);
                                    movePositionStartLine(sshwidget::MoveAnchor);
                                } else {
                                    sendData("<br>");
                                }
                                data[i] = data[i].mid(position2 + 4);
                            } else {
                                sendData(data[i]);
                                break;
                            }

                        }
                    }
                } else {

                    sendData(data[i]);
                    if (clearPos + 1 == i && lastCommondS == "clear") {
                        qDebug() << "lineCount = " << lineCount;
                        int sum = lineCount - clearSPos;
                        for(int i = 0; i < sum; i++) {
                            sendData("<br>");
                            clearSPos++;
                        }
                        movePositionUp(sshwidget::MoveAnchor, sum);
                        movePositionEndLine(sshwidget::MoveAnchor);
                    }
                    //向上移动24行并移动到行末

                    if (backspaceSum > 0) {
                        //lastData == "\u001B[D" || lastData == "\b"
                        //光标删除后面一位
                        lastData = "";
                        qDebug() << "backspaceSum sum=" << backspaceSum;
                        int sum = 0;
                        if (backspaceSum >= data[i].length()) {
                            backspaceSum = backspaceSum - data[i].length();
                            sum = data[i].length();
                        } else {
                            sum = backspaceSum;
                            backspaceSum = 0;
                        }
                        qDebug() << "backspaceSum sum=" << backspaceSum;
                        qDebug() << "删除数据";
                        // 获取选定文本
                        QString previousChar2 = movePositionLeftSelect(sshwidget::KeepAnchor, 1);;
                        movePositionRemoveLeftSelect(sshwidget::KeepAnchor, sum);
                    }
                }
            } else {
                if (isEnter && data[i].length()!= 0) {
                    movePositionRemoveLeftSelect(sshwidget::KeepAnchor, data[i].length());
                    isEnter = false;
                }
                qDebug() << "B准备打印" << data[i];
                sendData(data[i]);
            }
        }
    }

    if (scrollBar_textEdit && scrollBar_textEdit_s) {
        //qDebug() << "设置滑动条 read " << scrollBar_textEdit->value();
        scrollBar_textEdit->setValue(scrollBar_textEdit->maximum());
        scrollBar_textEdit_s->setValue(scrollBar_textEdit->value());
    }
}

void sshwidget::rece_key_sign(QString key)
{
    qDebug() << "触发rece_key_sign = " << key;
    if (key == "") {
        return;
    }
    lastCommondS = key;
    if (key == "\r") {
        movePositionEndLine(sshwidget::MoveAnchor);
        backspaceSum = 0;
    }
    sendCommandData(key);
}

void sshwidget::rece_getServerInfo(ServerInfoStruct serverInfo)
{
    ui->label_ip->setText(serverInfo.ip);
    ui->label_load->setText(serverInfo.load);
    ui->label_runTime->setText(serverInfo.runTime);
    ui->label_loginCount->setText(serverInfo.loginCount);
    ui->label_architecture->setText(serverInfo.architecture);
    ui->label_cpuInfo->setText(serverInfo.cpuInfo);

    ui->progressBar_mem->setFormat("%p%   " + serverInfo.memUse + " ");
    ui->progressBar_swap->setFormat("%p%   " + serverInfo.swapUse + " ");
    ui->progressBar_cpu->setValue(serverInfo.cpuUseRate.toInt());
    ui->progressBar_disk->setValue(serverInfo.diskUseRate.toInt());
    ui->progressBar_mem->setValue(serverInfo.memUseRate.toInt());
    ui->progressBar_swap->setValue(serverInfo.swapUseRate.toInt());

}

void sshwidget::rece_fileProgress_sgin(int64_t sum, int64_t filesize)
{
    //dlwidget->updateFileProgress(sum, filesize);
    dlwidget->fwidget->rece_file_progress_sgin(sum, filesize);
    //更新文件进度
    //    qDebug() << "sum =" << sum << " filesize = " << filesize;
    //    //计算大小
    //    double count_m = (double)filesize / (double)1024 / (double)1024;
    //    double count_g = 0.0;
    //    QString countStr = "";
    //    if (count_m >= 1024) {
    //        count_g = count_m / 1024;
    //        countStr = QString::number(count_g, 'f', 1) + "G";
    //    } else {
    //        countStr = QString::number(count_m, 'f', 1) + "M";
    //    }

    //    double sum_m = (double)sum / (double)1024 / (double)1024;
    //    double sum_g = 0.0;
    //    QString sumStr = "";
    //    if (sum_m >= 1024) {
    //        sum_g = count_m / 1024;
    //        sumStr = QString::number(sum_g, 'f', 1) + "G";
    //    } else {
    //        sumStr = QString::number(sum_m, 'f', 1) + "M";
    //    }
    //    ui->progressBar->setFormat("%p%   " + sumStr + "/" + countStr);
    //    ui->progressBar->setMaximum(filesize);
    //    ui->progressBar->setValue(sum);
}

void sshwidget::on_pushButton_clicked()
{

    //    QTextCursor cursor(ui->textEdit->document());
    //    cursor.movePosition(QTextCursor::Start);

    //    for (int i = 0; i < 5 - 1; ++i)
    //    {
    //        cursor.movePosition(QTextCursor::Down);
    //    }

    //    ui->textEdit->setTextCursor(cursor);
    //    ui->textEdit->ensureCursorVisible();
    //    ui->textEdit->setFocusPolicy(Qt::StrongFocus);
    //    ui->textEdit->setFocus();

    // 保存原始的文本格式
    //    cursor_s = ui->textEdit->textCursor();
    //    originalFormat_s = cursor_s.charFormat();

    /* 需要搜索的文本 */
    QString searchString = ui->lineEdit->text();
    /* 文本框的全部内容 */
    QTextDocument *document = ui->textEdit->document();

    document->undo();

    bool found = false;

    if (searchString.isEmpty()) {

    } else {
        /* 高亮本文配置 */
        QTextCursor highlightCursor(document);

        QTextCharFormat plainFormat(highlightCursor.charFormat());

        QTextCharFormat colorFormat = plainFormat;
        colorFormat.setForeground(Qt::black);
        colorFormat.setBackground(Qt::yellow);

        while (!highlightCursor.isNull() && !highlightCursor.atEnd()) {
            /* 搜索给定文本的位置 */
            highlightCursor = document->find(searchString, highlightCursor,
                                             QTextDocument::FindWholeWords);

            if (!highlightCursor.isNull()) {
                found = true;
                highlightCursor.movePosition(QTextCursor::WordRight,
                                             QTextCursor::KeepAnchor);
                /* 设置高亮文本 */
                highlightCursor.mergeCharFormat(colorFormat);
            }
        }
    }
}

void sshwidget::on_textEdit_selectionChanged()
{
    QTextCursor cursor = ui->textEdit->textCursor();

    if (!cursor.hasSelection()) {
        return;
    }
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

void sshwidget::rece_find_sgin()
{
    QString copyData = textEdit_s->textCursor().selectedText();
    copyData.replace(QChar(0xA0), ' ');
    fwidget->show();
    fwidget->setFindText(copyData);
}

void sshwidget::rece_copy_sgin()
{
    QString copyData = textEdit_s->textCursor().selectedText();
    copyData.replace(QChar(0xA0), ' ');
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(copyData);
    QTextCursor cursor = textEdit_s->textCursor();
    //cursor.clearSelection();
    textEdit_s->setTextCursor(cursor);
    ui->textEdit->setFocus();
}

void sshwidget::rece_paste_sgin()
{
    QClipboard *clipboard = QGuiApplication::clipboard();
    const QMimeData *mimeData = clipboard->mimeData();

    if (mimeData->hasText()) {
        QString clipboardText = mimeData->text();
        //qDebug() << "剪贴板内容：" << clipboardText;
        sendCommandData(clipboardText);
    }
    ui->textEdit->setFocus();
}

void sshwidget::rece_resize_sign()
{
    //qDebug() << "终端大小改变为" << textEdit_s->size();
    // 获取标签的坐标和大小
    //int x = textEdit_s->geometry().x();
    //int y = textEdit_s->geometry().y();
    int width = textEdit_s->geometry().width();
    //int height = textEdit_s->geometry().height();
    fwidget->move(width - fwidget->geometry().width() - 50, 10);
    dlwidget->move(width - dlwidget->geometry().width() - 20, 10);

    QPoint widgetAPos = ui->toolButton_history->mapToGlobal(QPoint(0, 0)); // 获取控件a在屏幕上的位置
    QPoint widgetBPos = textEdit_s->mapFromGlobal(widgetAPos); // 将控件a的全局坐标映射为控件b的局部坐标
    hcwidget->move(widgetBPos.x()- 100, widgetBPos.y() - 250);

    // 获取文本编辑框的视口大小
    QSize viewportSize = textEdit_s->viewport()->size();

    // 获取字体的行高和字符宽度
    QFontMetrics metrics(textEdit_s->font());
    int lineHeight = metrics.lineSpacing();
    int charWidth = metrics.averageCharWidth();
    // qDebug() << "字体 高 = " << lineHeight;
    // qDebug() << "字体 宽 = " << charWidth;
    // qDebug() << "视图 高 = " << viewportSize.height();
    // qDebug() << "视图 宽 = " << viewportSize.width();

//    // 检查垂直滚动条的可见性
    //bool isScrollBarVisible = textEdit_s->verticalScrollBar()->isVisible();
    // 显示垂直滚动条的可见性状态
    //qDebug() << "Vertical Scrollbar Visible:" << isScrollBarVisible;

    // 计算可见行数和列数
    int visibleLines = viewportSize.height() / lineHeight - 1;
    int visibleColumns = viewportSize.width() / charWidth - 5;

    // 显示当前可显示的行数
    // 输出行数和列数
    //qDebug() << "Visible Line count:" << visibleLines;
    //qDebug() << "Visible Column count:" << visibleColumns;

    //如果宽在2范围则不触发
//    if (visibleColumns != columnCount && columnCount - 5 < visibleColumns && visibleColumns < columnCount + 5) {
//        return;
//    }

    if (columnCount != visibleColumns || lineCount != visibleLines) {
        // 检查垂直滚动条的可见性 是否有滚动条可见导致的大小变化 屏蔽由该变化导致的刷新
//        if (!isScrollBar) {
//            isScrollBar = textEdit_s->verticalScrollBar()->isVisible();
//            if (isScrollBar) {
//                return;
//            }
//        } else {
//            isScrollBar = textEdit_s->verticalScrollBar()->isHidden();
//            if (!isScrollBar) {
//                return;
//            }
//        }
        //qDebug() << "终端大小被调用 visibleLines = " << visibleLines << " visibleColumns = " << visibleColumns - 5;
        setTerminalSize(visibleLines, visibleColumns);
        columnCount = visibleColumns;
        lineCount = visibleLines;
    }
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
        //qDebug() << "选择路径：" << fileList.at(i);
    }
    //获取当前服务器目录，然后上传
    QString path = fileList.at(0);
    QString fileName;
    int colonIndex = path.lastIndexOf('/');
    if (colonIndex != 1) {
        //qDebug() << "上传文件 文件名" << A.mid(colonIndex + 1);
        fileName = path.mid(colonIndex + 1);
    }

    //sendUploadCommandData("C:\\Users\\张旭\\Desktop\\fsdownload\\apinfo.json", "/data/linkdood/im/apinfo.json");
    //调子线程执行
    if (ssh_path.contains("~")) {
        ssh_path.replace("~","/root");
    }
    sendUploadCommandData(path, ssh_path + "/" + fileName, fileName);
}

void sshwidget::on_toolButton_fullScreen_clicked()
{
    emit send_toolButton_fullScreen_sign();
}

void sshwidget::on_toolButton_find_clicked()
{
    if (fwidget->isHidden()) {
        fwidget->show();
    } else {
        fwidget->hide();
    }
}

void sshwidget::rece_toolButton_find_clicked()
{
    QString copyData = textEdit_s->textCursor().selectedText();
    copyData.replace(QChar(0xA0), ' ');
    fwidget->setFindText(copyData);
    if (fwidget->isHidden()) {
        fwidget->show();
    }
}

void sshwidget::on_tabWidget_customContextMenuRequested(const QPoint &pos)
{
    if (ui->tabWidget->currentIndex() == ui->tabWidget->tabBar()->tabAt(pos)) {
        //qDebug() << "标签";
        QMenu *menu = new QMenu(ui->tabWidget);
        menu->setWindowFlags(menu->windowFlags()  | Qt::FramelessWindowHint | Qt::NoDropShadowWindowHint);
        menu->setAttribute(Qt::WA_TranslucentBackground);
        QAction *pnew = new QAction("添加命令", ui->tabWidget);
        QAction *pnew1 = new QAction("创建分类", ui->tabWidget);
        QAction *pnew2 = new QAction("重命名", ui->tabWidget);
        QAction *pnew3 = new QAction("删除", ui->tabWidget);
        connect (pnew,SIGNAL(triggered()),this,SLOT(rece_addCommond_sgin()));
        connect (pnew1,SIGNAL(triggered()),this,SLOT(rece_mkdirFolder_sgin()));
        menu->addAction(pnew);
        menu->addSeparator();
        menu->addAction(pnew1);
        menu->addSeparator();
        menu->addAction(pnew2);
        menu->addSeparator();
        menu->addAction(pnew3);
        menu->move(cursor().pos());
        menu->show();
    } else {
        //qDebug() << "内容";
        QMenu *menu = new QMenu(ui->tabWidget);
        menu->setWindowFlags(menu->windowFlags()  | Qt::FramelessWindowHint | Qt::NoDropShadowWindowHint);
        menu->setAttribute(Qt::WA_TranslucentBackground);
        QAction *pnew = new QAction("添加命令", ui->tabWidget);
        QAction *pnew1 = new QAction("创建分类", ui->tabWidget);
        connect (pnew,SIGNAL(triggered()),this,SLOT(rece_addCommond_sgin()));
        connect (pnew1,SIGNAL(triggered()),this,SLOT(rece_mkdirFolder_sgin()));
        menu->addAction(pnew);
        menu->addSeparator();
        menu->addAction(pnew1);
        menu->move(cursor().pos());
        menu->show();
    }



}

void sshwidget::rece_addCommond_sgin()
{
    //添加命令
    addcommondwidget * addcwidget = new addcommondwidget();
    addcwidget->show();
}

void sshwidget::rece_mkdirFolder_sgin()
{
    //创建文件夹
    mkdirfolderwidget * mkdirfwidget = new mkdirfolderwidget();
    mkdirfwidget->show();
}

void sshwidget::rece_createNewFile_sgin(QString filePath, QString fileName, int fileType, int64_t fileSize)
{
    dlwidget->createNewFile(filePath, fileName, fileType, fileSize);
    fwidgetList.append(dlwidget->fwidget);
}

void sshwidget::on_toolButton_command_clicked()
{
    if (ui->widget_bottom->isHidden()) {
        ui->widget_bottom->show();
    } else {
        ui->widget_bottom->hide();
    }
}

void sshwidget::on_toolButton_info_clicked()
{
    if (ui->widget->isHidden()) {
        ui->widget->show();
    } else {
        ui->widget->hide();
    }
}

void sshwidget::on_toolButton_history_clicked()
{
    if (hcwidget->isHidden()) {
        hcwidget->show();
    } else {
        hcwidget->hide();
    }
}

void sshwidget::on_toolButton_conectStats_clicked()
{

}

void sshwidget::rece_downloadFile_sgin(QString fileName)
{
    //下载文件
    QString copyData = textEdit_s->textCursor().selectedText();
    copyData.replace(QChar(0xA0), ' ');
    if (ssh_path.contains("~")) {
        ssh_path.replace("~","/root");
    }

    //调子线程执行
    QString fileName2 = copyData;
    QString remote_file_path = ssh_path + "/" + copyData;
    QString local_file_path = "C:\\Users\\张旭\\Desktop\\fsdownload\\" + copyData;

    QMetaObject::invokeMethod(sshSftp,"downloadFile", Qt::QueuedConnection, Q_ARG(QString, remote_file_path), Q_ARG(QString,local_file_path), Q_ARG(QString,fileName2));
}

void sshwidget::rece_ssh_init()
{
    // 设置焦点策略为强制获取焦点
    ui->textEdit->setFocusPolicy(Qt::NoFocus);
    ui->textEdit->setFocus();
    qDebug("开始调用init_poll");
    QString cc = "主机连接成功<br>";
    ui->textEdit->insertHtml(cc);
    movePositionEnd();

    textEdit_s->insertHtml(cc);

    //初始化完成调用
    QMetaObject::invokeMethod(m_sshhandle,"init_poll",Qt::QueuedConnection);
    //通知页面，连接成功，可以使用
    qDebug("开始调用init_poll完成");

    QString host = cInfoStruct.host;
    QString port = cInfoStruct.port;
    QString username = cInfoStruct.userName;
    QString password = cInfoStruct.password;
    int connrectType = 1;
    QMetaObject::invokeMethod(sshExec,"init", Qt::QueuedConnection, Q_ARG(int, connrectType), Q_ARG(QString, host), Q_ARG(QString,port), Q_ARG(QString,username), Q_ARG(QString,password));
}

void sshwidget::rece_ssh_exec_init()
{
    QString host = cInfoStruct.host;
    QString port = cInfoStruct.port;
    QString username = cInfoStruct.userName;
    QString password = cInfoStruct.password;
    int connrectType = 1;
    QMetaObject::invokeMethod(sshSftp,"init", Qt::QueuedConnection, Q_ARG(int, connrectType), Q_ARG(QString, host), Q_ARG(QString,port), Q_ARG(QString,username), Q_ARG(QString,password));
}

void sshwidget::rece_ssh_sftp_init()
{
    //初始化完成
}
