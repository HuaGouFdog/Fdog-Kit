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
#include <QMenu>
#include <QMimeData>
#include "findwidget.h"
#include "downloadwidget.h"
#include <QTextEdit>
#include <QTextLayout>
#include <QTextBlock>
#include <QShortcut>
#include "datahandle.h"
#include "module_utils/FlowLayout.h"
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

// void stringToHtml(QString &str, QColor crl)
// {
//     QByteArray array;
//     array.append(crl.red());
//     array.append(crl.green());
//     array.append(crl.blue());
//     QString strC(array.toHex());
//     str = QString("<span style=\" color:#%1;\">%2</span>").arg(strC).arg(str);
// }

sshwidget::sshwidget(connnectInfoStruct& cInfoStruct, config * confInfo, QString sign, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sshwidget)
{
    ui->setupUi(this);
    setSupportStretch(this, true);
    this->cInfoStruct = cInfoStruct;

    m_sign = sign;
    ui->splitter_2->setStretchFactor(0,5);
    ui->splitter_2->setStretchFactor(1,1);

    ui->plainTextEdit->viewport()->setCursor(Qt::ArrowCursor);

    ResizeFilter * filter = new ResizeFilter(this);
    connect(filter,SIGNAL(send_resize_sign()),this, SLOT(rece_resize_sign()));
    ui->widget_bottom->installEventFilter(filter);
    //表格自适应
    //ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

    setMouseTracking(true);
    QString host = cInfoStruct.host;
    QString port = cInfoStruct.port;
    QString username = cInfoStruct.userName;
    QString password = cInfoStruct.password;
    QString sshType = cInfoStruct.sshType;
    QString publicKey = cInfoStruct.publickey;

    qDebug() << "sshwidget host = " << host;
    qDebug() << "sshwidget port = " << port;
    qDebug() << "sshwidget username = " << username;
    qDebug() << "sshwidget password = " << password;
    qDebug() << "sshwidget sshType = " << sshType;
    qDebug() << "sshwidget publicKey = " << publicKey;

    //快捷键 ctrl + shift + F 查找
    QShortcut *shortcutF = new QShortcut(QKeySequence(Qt::CTRL + Qt::SHIFT + Qt::Key_F), this);
    connect(shortcutF, SIGNAL(activated()), this, SLOT(rece_toolButton_find_clicked()));

    //快捷键 ctrl + shift + c 复制
    QShortcut *shortcutC = new QShortcut(QKeySequence(Qt::CTRL + Qt::SHIFT + Qt::Key_C), this);
    connect(shortcutC, SIGNAL(activated()), this, SLOT(rece_copy_sgin()));

    //快捷键 ctrl + shift + v 粘贴
    QShortcut *shortcutV = new QShortcut(QKeySequence(Qt::CTRL + Qt::SHIFT + Qt::Key_V), this);
    connect(shortcutV, SIGNAL(activated()), this, SLOT(rece_paste_sgin()));

 
    //qDebug("执行3");
    //QMetaObject::invokeMethod(sshSftp,"init", Qt::QueuedConnection, Q_ARG(int, connrectType), Q_ARG(QString, host), Q_ARG(QString,port), Q_ARG(QString,username), Q_ARG(QString,password));
    textEdit_s = new CustomPlainTextEdit(this);
    textEdit_s->setReadOnly(true);
    textEdit_s->viewport()->setCursor(Qt::ArrowCursor);
    textEdit_s->setLineWrapMode(QPlainTextEdit::NoWrap); //自动换行
    //textEdit_s->setLineWrapColumnOrWidth(200);
    textEdit_s->setStyleSheet("CustomPlainTextEdit{ \
                                background-color: rgb(0, 41, 169, 0);\
                                selection-background-color: rgb(50, 130, 190);\
                                font: 57 12pt \"Maple Mono NF CN Medium\";\
                                border: none;\
                                    padding-top:0px;\
                                    padding-bottom:0px;\
                                    padding-left:0px;\
                                    padding-right:0px;\
                                    border-radius: 0px;\
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

    //设置默认行高
    // QTextBlockFormat blockFormat;
    // blockFormat.setLineHeight(50, QTextBlockFormat::FixedHeight);  // 设置固定行高 20 像素

    // QTextCursor cursor_textEdit_s = textEdit_s->textCursor();
    // cursor_textEdit_s.select(QTextCursor::Document);
    // cursor_textEdit_s.mergeBlockFormat(blockFormat);
    // textEdit_s->setTextCursor(cursor_textEdit_s);

    // QTextCursor cursor_plainTextEdit = ui->plainTextEdit->textCursor();
    // cursor_plainTextEdit.select(QTextCursor::Document);
    // cursor_plainTextEdit.mergeBlockFormat(blockFormat);
    // ui->plainTextEdit->setTextCursor(cursor_plainTextEdit);



    QString cc = "连接主机中...";
    ui->plainTextEdit->appendPlainText(cc);
    QString cc2 = "连接主机中...";
    movePositionEnd();
    textEdit_s->appendPlainText(cc2);

    QPalette palette = textEdit_s->palette();
    palette.setColor(QPalette::Text, QColor(0, 0, 0, 0)); // 文字颜色设置为透明
    textEdit_s->setPalette(palette);

    keyFilter = new KeyFilter(this);

    connect(keyFilter,SIGNAL(send_key_sign(QString)),this,
            SLOT(rece_key_sign(QString)));

    ui->plainTextEdit->installEventFilter(keyFilter);

    mouseFilter = new MouseFilter(this);
    QTextCursor cursor2=ui->plainTextEdit->textCursor();
    lineNumber = cursor2.blockNumber() + 1;
    columnNumber = cursor2.columnNumber();

    movePos = false;

    ui->plainTextEdit->setCursorWidth(2);

    dlwidget = new downloadwidget(textEdit_s);
    connect(dlwidget,SIGNAL(send_setting()),this,
        SLOT(rece_setting()));

    fwidget = new findwidget(textEdit_s);
    connect(fwidget,SIGNAL(send_searchTextChanged(const QString)),this,
        SLOT(rece_searchTextChanged(const QString)));

    connect(this,SIGNAL(send_searchTextNumbers(int, int)),fwidget,
        SLOT(rece_searchTextNumbers(int, int)));

    fwidget->hide();
    hcwidget = new historycommondwidget(textEdit_s);
    hcwidget->hide();

    QStackedLayout * Layout = new QStackedLayout;
    Layout->setStackingMode(QStackedLayout::StackAll);
    Layout->setContentsMargins(0,0,0,0);
    Layout->addWidget(textEdit_s);
    Layout->addWidget(ui->plainTextEdit);

    ui->widget_9->setLayout(Layout);

    connect(textEdit_s,SIGNAL(send_mousePress_sign()),this,
            SLOT(rece_send_mousePress_sign()));
    connect(textEdit_s,SIGNAL(send_paste_sgin()),this,
            SLOT(rece_paste_sgin()));
    connect(textEdit_s,SIGNAL(send_resize_sign()),this,
            SLOT(rece_resize_sign()));

    scrollBar_textEdit = ui->plainTextEdit->verticalScrollBar();

    scrollBar_textEdit_s = textEdit_s->verticalScrollBar();
    connect(scrollBar_textEdit_s,SIGNAL(valueChanged(int)),this,
            SLOT(scrollBarValueChanged(int)));

    textEdit_s->setContextMenuPolicy(Qt::CustomContextMenu);
    //textEdit_s->setContextMenuPolicy(Qt::NoContextMenu);

    textEdit_s->setUndoRedoEnabled(false);
    ui->plainTextEdit->setUndoRedoEnabled(false);
    textEdit_s->setLineWrapMode(QPlainTextEdit::WidgetWidth);
    ui->plainTextEdit->setLineWrapMode(QPlainTextEdit::WidgetWidth);

    ui->plainTextEdit->document ()->setMaximumBlockCount(1000);
    textEdit_s->document ()->setMaximumBlockCount(1000);


   //初始化
    int connrectType = 1;
    thread = new QThread();
    m_sshhandle = new sshhandle();
    // 将对象移动到线程中
    m_sshhandle->moveToThread(thread);

    connect(m_sshhandle,SIGNAL(send_channel_readS(QStringList)),this,
            SLOT(rece_channel_readS(QStringList)), Qt::QueuedConnection);
    connect(m_sshhandle,SIGNAL(send_init(bool)),this,
            SLOT(rece_ssh_init(bool)));
    connect(m_sshhandle,SIGNAL(send_getServerInfo(ServerInfoStruct)),this,
            SLOT(rece_getServerInfo(ServerInfoStruct)));
    thread->start();
    //qDebug("执行0");
    //这里设置初始化方式
    //密码
    //密钥 Path name of the public key file. (e.g. /etc/ssh/hostkey.pub). If libssh2 is built against OpenSSL, this option can be set to NULL.
    //setTerminalSize(m_visibleLines, m_visibleColumns);
    m_visibleLines = 25;
    m_visibleColumns = 120;
    //qDebug() << "准备init 设置当前终端高=" << m_visibleLines << " 宽=" << m_visibleColumns;
    QMetaObject::invokeMethod(m_sshhandle,"init",Qt::QueuedConnection, Q_ARG(int, connrectType), Q_ARG(QString, host), Q_ARG(QString,port), 
    Q_ARG(QString,username), Q_ARG(QString,password), Q_ARG(QString,sshType), Q_ARG(QString,publicKey), Q_ARG(int,m_visibleColumns), Q_ARG(int,m_visibleLines));
    //qDebug("执行01");

    //exec
    threadExec = new QThread();
    sshExec = new sshHandleExec();
    sshExec->moveToThread(threadExec);
    connect(sshExec, SIGNAL(send_getServerInfo(ServerInfoStruct)),this,
            SLOT(rece_getServerInfo(ServerInfoStruct)));
    connect(sshExec,SIGNAL(send_init(bool)),this,
            SLOT(rece_ssh_exec_init(bool)));
    threadExec->start();
    //在其他地方调用
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

    QAction *findAction = new QAction(tr("查找     Ctrl+Shift+F"), textEdit_s);
    //findAction->setShortcut(QKeySequence::Copy);
    findAction->setShortcutContext(Qt::WidgetShortcut);

    QAction *copyAction = new QAction(tr("复制     Ctrl+Shift+C"), textEdit_s);
    //copyAction->setShortcut(QKeySequence::Copy);
    copyAction->setShortcutContext(Qt::WidgetShortcut);

    QAction *pasteAction = new QAction(tr("粘贴     Ctrl+Shift+V"), textEdit_s);
    //pasteAction->setShortcut(QKeySequence::Copy);
    pasteAction->setShortcutContext(Qt::WidgetShortcut);

    QAction *pasteActionSelect = new QAction(tr("粘贴选中"), textEdit_s);

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

   QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect(contextMenu);
   effect->setOffset(0, 0);          //设置向哪个方向产生阴影效果(dx,dy)，特别地，(0,0)代表向四周发散
   effect->setColor(QColor(50, 50, 50));       //设置阴影颜色，也可以setColor(QColor(220,220,220))
   effect->setBlurRadius(15);        //设定阴影的模糊半径，数值越大越模糊
   //contextMenu->setGraphicsEffect(effect);

    contextMenu->addAction(findAction);
    //contextMenu->addSeparator();
    contextMenu->addAction(copyAction);
    //contextMenu->addSeparator();
    contextMenu->addAction(pasteAction);
    //contextMenu->addSeparator();
    contextMenu->addAction(pasteActionSelect);
    contextMenu->addSeparator();
    contextMenu->addAction(downloadAction);
    //contextMenu->addSeparator();
    contextMenu->addAction(uploadAction);
    contextMenu->addSeparator();
    contextMenu->addAction(selectAllAction);
    //contextMenu->addSeparator();
    contextMenu->addAction(clearAction);

    connect (findAction,SIGNAL(triggered()),this,SLOT(rece_find_sgin()));
    connect (copyAction,SIGNAL(triggered()),this,SLOT(rece_copy_sgin()));
    connect (pasteAction,SIGNAL(triggered()),this,SLOT(rece_paste_sgin()));
    connect (pasteActionSelect,SIGNAL(triggered()),this,SLOT(rece_pasteSelect_sgin()));
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

    ui->plainTextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    textEdit_s->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    ui->plainTextEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
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

    //获取当前tab页widget
    qDebug() << "设置命令";
    QWidget * cWidget = ui->tabWidget->currentWidget();
    FlowLayout *flowLayout = new FlowLayout(5, 0, 0);
    for(int i = 0; i< 20; i++) {
        flowLayout->addWidget(createCommand("命令" + QString::number(i), "cd /data/linkdood", true));
       //flowLayout->addWidget(new QPushButton("命令" + QString::number(i)));
    }
    flowLayout->setSpacing(30);
    cWidget->setLayout(flowLayout);
    //设置流式布局
    //
}

sshwidget::~sshwidget()
{
    qDebug() << "析构sshwidget";
    if (m_sshhandle != NULL) {
        delete m_sshhandle;
    }
    if (sshExec != NULL) {
        delete sshExec;
    }
    if (sshSftp != NULL) {
        delete sshSftp;
    }
    delete ui;
}

void sshwidget::resizeEvent(QResizeEvent *event) {
    qDebug() << "sshwidget resizeEvent 被调用";
    int width = textEdit_s->geometry().width();
    //int height = textEdit_s->geometry().height();
    fwidget->move(width - fwidget->geometry().width() - 50, 5);
    dlwidget->move(width - dlwidget->geometry().width() - 20, 5);

    //QPoint widgetAPos = ui->toolButton_history->mapToGlobal(QPoint(0, 0)); // 获取控件a在屏幕上的位置
    //QPoint widgetBPos = textEdit_s->mapFromGlobal(widgetAPos); // 将控件a的全局坐标映射为控件b的局部坐标
    int width2 = ui->widget_2->geometry().width();
    int height2 = ui->widget_2->geometry().height();
    hcwidget->move(width2/2 - 180, height2- 300);
    //qDebug() << "width2 = " << width2 << " height2 = " << height2;
    //qDebug() << "widgetBPos.x()- 120 = " << widgetBPos.x()- 120 << " widgetBPos.y() - 260 = " << widgetBPos.y() - 260;
    // 获取文本编辑框的视口大小
    QSize viewportSize = textEdit_s->viewport()->size();

    // 获取字体的行高和字符宽度
    QFontMetrics metrics(textEdit_s->font());
    int lineHeight = metrics.lineSpacing();
    int charWidth = metrics.averageCharWidth();
    //qDebug() << "字体 高 = " << lineHeight << " 字体 宽 = " << charWidth;
    //qDebug() << "视图 高 = " << viewportSize.height()  << "  视图 宽 = " << viewportSize.width();
    qDebug() << "widget_2 高 = " << ui->widget_2->geometry().height() << "  widget_toolbar 高 = " << ui->widget_toolbar->geometry().height();
    int s = (ui->widget_2->geometry().height() - ui->widget_toolbar->geometry().height()) % lineHeight;
    if (s >= 0) {
        ui->widget_10->setFixedHeight((ui->widget_2->geometry().height() - ui->widget_toolbar->geometry().height()) - s);
        ui->widget_cache->setFixedHeight(s);
        //qDebug() << "widget_10 高 = " << ui->widget_10->geometry().height() - s << "  widget_cache 高 = " << s;
    }
}

QWidget * sshwidget::createCommand(QString name, QString data, bool isLineFeed) {
    QWidget * widget = new QWidget();
    widget->setObjectName(name);
    //widget->setText(name);
    QToolButton * button_name = new QToolButton();
    button_name->setText(name);
    button_name->setObjectName(name);
    button_name->setStyleSheet("background-color: rgba(200, 200, 200, 0);");
    connect (button_name,SIGNAL(clicked()),this,SLOT(rece_clicked_run()));

    QToolButton * button = new QToolButton();
    button->setText(name);
    button->setIcon(QIcon((":lib/setting.png")));
    button->setStyleSheet("background-color: rgba(200, 200, 200, 0);");
    connect (button,SIGNAL(clicked()),this,SLOT(rece_clicked_edit()));

    commondInfo cinfo;
    cinfo.commond = data;
    cinfo.isLineFeed = isLineFeed;

    commondList[name] = cinfo;
    QHBoxLayout* layout = new QHBoxLayout();
    layout->setSpacing(0);
    layout->setContentsMargins(2, 2, 2, 2);
    layout->addWidget(button_name);
    layout->addWidget(button);
    widget->setLayout(layout);
    widget->setStyleSheet("QWidget:hover{background-color: rgba(200, 200, 200, 100); border-radius:5px;}");
    widget->setMaximumHeight(25);
    return widget;
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
    qDebug() << "设置当前终端高=" << height << " 宽=" << width;
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
    //str.replace("&nbsp;", " ");
    //qDebug() << "当前数据 = " << textEdit_s->toPlainText();
    //记录当前终端图标位置
    //ui->plainTextEdit->setHtml("");
    //textEdit_s->setHtml("");
    int cpos = getCurrentRowPositionByLocal();

    // if (!isBuffer) {
    //     currentLine = getCurrentRowPosition();
    //     qDebug() << "更新当前行数 currentLineLocal = " << currentLine;
    // }

    //qDebug() << "sendData 打印" << data;

    if (data == "") {
        return;
    }

    lastM = "34";
    //qDebug() << "lastM = " << lastM;
    if (lastM != "" && lastM == "34" && data.mid(0,1) == "~") {
        //qDebug() << "原数据 = " << data;
        //datahandle::stringToHtmlFilter(data);
        QColor *fontCrl = new QColor(20, 96, 210);
        datahandle::stringToHtml(data, fontCrl);
        //qDebug() << "现数据 = " << data;
    }

    QString data2 =data;

    // QRegularExpression regex("<span style=\\\" color:#\\w{6};opacity: 1;");
    data.replace("<br>", "\n");
    data.replace("&nbsp;", " ");
    // data2.replace(regex, "<span style=\\\" opacity: 0;");
    data2.replace("<br>", "\n");
    data2.replace("&nbsp;", " ");

    setUpdatesEnabled(false);
    
    QTextCursor cursor_s = textEdit_s->textCursor();
    
    QTextCursor cursor = ui->plainTextEdit->textCursor();
    // QPalette palette2 = textEdit_s->palette();
    // palette2.setColor(QPalette::Text, Qt::red);
    // textEdit_s->setPalette(palette2);
    cursor_s.beginEditBlock();
    cursor.beginEditBlock();

    
    cursor_s.insertText(data);


    cursor.insertText(data2); //color:ffffff:

    cursor_s.endEditBlock();
    cursor.endEditBlock();  

    setUpdatesEnabled(true);

    int cpos2 = getCurrentRowPositionByLocal();


    QPalette palette = ui->plainTextEdit->palette();
    palette.setColor(QPalette::Text, QColor(0, 0, 0, 0)); // 文字颜色设置为透明
    ui->plainTextEdit->setPalette(palette);

    cpos2 = getCurrentRowPositionByLocal();
    //qDebug() << "移动了" << cpos2 - cpos << "行";
    setCurrentRowPosition(cpos2 - cpos);

    //qDebug() << "sendData 当前光标所在行数(相对于终端内部) =" << getCurrentRowPosition() << "  当前行数 =" << cpos2;
}

void sshwidget::sendData2(QString data) {
    //qDebug() << "sendData 打印" << data;

    if (data == "") {
        return;
    }

    // QTextCursor cursor = ui->plainTextEdit->textCursor();
    // int currentPosition = cursor.position();
    // QTextCursor cursor_s = textEdit_s->textCursor();
    // cursor_s.setPosition(currentPosition);
    // textEdit_s->setTextCursor(cursor_s);
    lastM = "34";
    qDebug() << "lastM = " << lastM;
    if (lastM != "" && lastM == "34" && data.mid(0,1) == "~") {
        qDebug() << "原数据 = " << data;
        //datahandle::stringToHtmlFilter(data);
        QColor *fontCrl = new QColor(20, 96, 210);
        datahandle::stringToHtml(data, fontCrl);
        qDebug() << "现数据 = " << data;
    }

    textEdit_s->appendPlainText(data);
    QString data2 =data;
    //qDebug()<< "data = " << data;
    //data2.replace("opacity: 1;","opacity: 0;");
    ui->plainTextEdit->appendPlainText(data2);


    //qDebug()<< "data2 = " << data2;
    QPalette palette = ui->plainTextEdit->palette();
    palette.setColor(QPalette::Text, QColor(0, 0, 0, 0)); // 文字颜色设置为透明
    ui->plainTextEdit->setPalette(palette);
    qDebug() << "sendData2 当前行数据 =" << movePositionEndLineSelect();
}

void sshwidget::setData(QString data)
{

    ui->plainTextEdit->clear();
    ui->plainTextEdit->appendPlainText(data);

    textEdit_s->clear();
    textEdit_s->appendPlainText(data);
    movePositionEnd();
}

void sshwidget::movePositionUp(sshwidget::MoveMode mode, int n)
{
    QTextCursor cursor = ui->plainTextEdit->textCursor();
    cursor.movePosition(QTextCursor::Up, QTextCursor::MoveAnchor, n);
    ui->plainTextEdit->setTextCursor(cursor);

    QTextCursor cursor2 = textEdit_s->textCursor();
    cursor2.movePosition(QTextCursor::Up, QTextCursor::MoveAnchor, n);
    textEdit_s->setTextCursor(cursor2);
}

void sshwidget::movePositionUp_s(sshwidget::MoveMode mode, int n)
{
    QTextCursor cursor2 = textEdit_s->textCursor();
    cursor2.movePosition(QTextCursor::Up, QTextCursor::MoveAnchor, n);
    textEdit_s->setTextCursor(cursor2);
}

void sshwidget::movePositionDown(sshwidget::MoveMode mode, int n)
{
    QTextCursor cursor = ui->plainTextEdit->textCursor();
    cursor.movePosition(QTextCursor::Down, QTextCursor::MoveAnchor, n);
    ui->plainTextEdit->setTextCursor(cursor);

    QTextCursor cursor2 = textEdit_s->textCursor();
    cursor2.movePosition(QTextCursor::Down, QTextCursor::MoveAnchor, n);
    textEdit_s->setTextCursor(cursor2);
}

void sshwidget::movePositionDown_s(sshwidget::MoveMode mode, int n)
{
    QTextCursor cursor2 = textEdit_s->textCursor();
    cursor2.movePosition(QTextCursor::Down, QTextCursor::MoveAnchor, n);
    textEdit_s->setTextCursor(cursor2);
}

void sshwidget::movePositionLeft(sshwidget::MoveMode mode, int n)
{
    QTextCursor cursor = ui->plainTextEdit->textCursor();
    cursor.movePosition(QTextCursor::Right, QTextCursor::MoveAnchor, n);
    ui->plainTextEdit->setTextCursor(cursor);

    QTextCursor cursor2 = textEdit_s->textCursor();
    cursor2.movePosition(QTextCursor::Right, QTextCursor::MoveAnchor, n);
    textEdit_s->setTextCursor(cursor2);
}

void sshwidget::movePositionLeft_s(sshwidget::MoveMode mode, int n)
{
    QTextCursor cursor2 = textEdit_s->textCursor();
    cursor2.movePosition(QTextCursor::Right, QTextCursor::MoveAnchor, n);
    textEdit_s->setTextCursor(cursor2);
}

void sshwidget::movePositionRight(sshwidget::MoveMode mode, int n)
{
    QTextCursor cursor = ui->plainTextEdit->textCursor();
    cursor.movePosition(QTextCursor::Left, QTextCursor::MoveAnchor, n);
    ui->plainTextEdit->setTextCursor(cursor);

    QTextCursor cursor2 = textEdit_s->textCursor();
    cursor2.movePosition(QTextCursor::Left, QTextCursor::MoveAnchor, n);
    textEdit_s->setTextCursor(cursor2);
}

void sshwidget::movePositionRight_s(sshwidget::MoveMode mode, int n)
{
    QTextCursor cursor2 = textEdit_s->textCursor();
    cursor2.movePosition(QTextCursor::Left, QTextCursor::MoveAnchor, n);
    textEdit_s->setTextCursor(cursor2);
}

void sshwidget::movePositionStartLine(sshwidget::MoveMode mode)
{
    QTextCursor cursor = ui->plainTextEdit->textCursor();
    cursor.movePosition(QTextCursor::StartOfLine);
    ui->plainTextEdit->setTextCursor(cursor);

    QTextCursor cursor2 = textEdit_s->textCursor();
    cursor2.movePosition(QTextCursor::StartOfLine);
    textEdit_s->setTextCursor(cursor2);
}

void sshwidget::movePositionEndLine(sshwidget::MoveMode mode)
{
    QTextCursor cursor = ui->plainTextEdit->textCursor();
    cursor.movePosition(QTextCursor::EndOfLine);
    ui->plainTextEdit->setTextCursor(cursor);

    QTextCursor cursor2 = textEdit_s->textCursor();
    cursor2.movePosition(QTextCursor::EndOfLine);
    textEdit_s->setTextCursor(cursor2);
}

void sshwidget::movePositionEnd(sshwidget::MoveMode mode)
{
    QTextCursor cursor = ui->plainTextEdit->textCursor();
    cursor.movePosition(QTextCursor::End);
    ui->plainTextEdit->setTextCursor(cursor);

    QTextCursor cursor2 = textEdit_s->textCursor();
    cursor2.movePosition(QTextCursor::End);
    textEdit_s->setTextCursor(cursor2);
}

QString sshwidget::movePositionLeftSelect(sshwidget::MoveMode mode, int n)
{
    QTextCursor cursor = ui->plainTextEdit->textCursor();
    cursor.movePosition(QTextCursor::Right, QTextCursor::KeepAnchor, n);
    return cursor.selectedText();
}

QString sshwidget::movePositionEndLineSelect(sshwidget::MoveMode mode, int n) {
    QTextCursor cursor = ui->plainTextEdit->textCursor();
    cursor.movePosition(QTextCursor::EndOfLine, QTextCursor::KeepAnchor);
    return cursor.selectedText();
}

QString sshwidget::getSelectText_s() {
    QTextCursor cursor = textEdit_s->textCursor();
    return cursor.selectedText();
}

QString sshwidget::movePositionRightSelect(sshwidget::MoveMode mode, int n)
{
    QTextCursor cursor = ui->plainTextEdit->textCursor();
    cursor.movePosition(QTextCursor::Left, QTextCursor::KeepAnchor, n);
    return cursor.selectedText();
}

void sshwidget::movePositionRemoveLeftSelect(sshwidget::MoveMode mode, int n)
{

    QTextCursor cursor = ui->plainTextEdit->textCursor();
    cursor.movePosition(QTextCursor::Right, QTextCursor::KeepAnchor, n);
    cursor.removeSelectedText();
    ui->plainTextEdit->setTextCursor(cursor);

    QTextCursor cursor2 = textEdit_s->textCursor();
    cursor2.movePosition(QTextCursor::Right, QTextCursor::KeepAnchor, n);
    cursor2.removeSelectedText();
    textEdit_s->setTextCursor(cursor2);
}

void sshwidget::movePositionRemoveRightSelect(sshwidget::MoveMode mode, int n)
{
    QTextCursor cursor = ui->plainTextEdit->textCursor();
    cursor.movePosition(QTextCursor::Left, QTextCursor::KeepAnchor, n);
    cursor.removeSelectedText();
    ui->plainTextEdit->setTextCursor(cursor);

    QTextCursor cursor2 = textEdit_s->textCursor();
    cursor2.movePosition(QTextCursor::Left, QTextCursor::KeepAnchor, n);
    cursor2.removeSelectedText();
    textEdit_s->setTextCursor(cursor2);
}

void sshwidget::movePositionRemoveEndLineSelect(sshwidget::MoveMode mode, int n)
{
    // QTextCursor cursor3 = ui->plainTextEdit->textCursor();
    // cursor3.movePosition(QTextCursor::StartOfLine);
    // cursor3.movePosition(QTextCursor::EndOfLine, QTextCursor::KeepAnchor);
    // QString currentLine = cursor3.selectedText();

    // // 输出到控制台
    // qDebug() << "当前光标所在行的内容：" << currentLine;

    QTextCursor cursor = ui->plainTextEdit->textCursor();
    cursor.movePosition(QTextCursor::EndOfLine, QTextCursor::KeepAnchor);
    qDebug() << "选择删除 = " << cursor.selectedText();
    cursor.removeSelectedText();
    ui->plainTextEdit->setTextCursor(cursor);

    QTextCursor cursor2 = textEdit_s->textCursor();
    cursor2.movePosition(QTextCursor::EndOfLine, QTextCursor::KeepAnchor);
    cursor2.removeSelectedText();
    textEdit_s->setTextCursor(cursor2);
}

void sshwidget::movePositionRemoveRight(sshwidget::MoveMode mode, int n)
{
    QTextCursor cursor = ui->plainTextEdit->textCursor();
    cursor.movePosition(QTextCursor::Left, QTextCursor::KeepAnchor, n);
    cursor.deletePreviousChar();
    ui->plainTextEdit->setTextCursor(cursor);

    QTextCursor cursor2 = textEdit_s->textCursor();
    cursor2.movePosition(QTextCursor::Left, QTextCursor::KeepAnchor, n);
    cursor2.deletePreviousChar();
    textEdit_s->setTextCursor(cursor2);
}

//获取当前行位置对于终端内部维护的位置。
int sshwidget::getCurrentRowPosition() {
    return currentLine;
}

//这个光标是跟随控件位置的
void sshwidget::setCurrentRowPosition(int n) {
    //qDebug() << "currentLine = " << currentLine << " + " << n;
    currentLine = currentLine + n;
}

//设置终端内部维护的光标归零
void sshwidget::setCurrentRowPositionToZero() {
    currentLine = 0;
}

//获取当前光标对于控件位置
int sshwidget::getCurrentRowPositionByLocal() {
    QTextCursor tc = ui->plainTextEdit->textCursor(); //当前光标
    QTextLayout *lay = tc.block().layout();
    int iCurPos= tc.position() - tc.block().position();//当前光标在本BLOCK内的相对位置
    int currentLineLocal = lay->lineForTextPosition(iCurPos).lineNumber() + tc.block().firstLineNumber();
    //qDebug() << "当前行数 =" << currentLineLocal + 1;
    return currentLineLocal + 1;
}

int sshwidget::getCurrentRowPositionByLocal_s() {
    QTextCursor tc = textEdit_s->textCursor(); //当前光标
    QTextLayout *lay = tc.block().layout();
    int iCurPos= tc.position() - tc.block().position();//当前光标在本BLOCK内的相对位置
    int currentLineLocal = lay->lineForTextPosition(iCurPos).lineNumber() + tc.block().firstLineNumber();
    //qDebug() << "当前行数 =" << currentLineLocal + 1;
    return currentLineLocal + 1;
}

//获取当前列位置
int sshwidget::getCurrentColumnPosition() {
    QTextCursor tc = ui->plainTextEdit->textCursor(); //当前光标
    QTextLayout *lay = tc.block().layout();
    int iCurPos= tc.position() - tc.block().position();//当前光标在本BLOCK内的相对位置
    return iCurPos;
}

int sshwidget::getCurrentColumnPositionByLocal() {
    QTextCursor tc = ui->plainTextEdit->textCursor(); //当前光标
    QTextLayout *lay = tc.block().layout();
    int iCurPos= tc.position() - tc.block().position();//当前光标在本BLOCK内的相对位置
    return iCurPos;
}

int sshwidget::getCurrentColumnPositionByLocal_s() {
    QTextCursor tc = textEdit_s->textCursor(); //当前光标
    QTextLayout *lay = tc.block().layout();
    int iCurPos= tc.position() - tc.block().position();//当前光标在本BLOCK内的相对位置
    return iCurPos;
}


//获取当前列对于行尾长度
int sshwidget::getTolineLength() {
    //获取当前光标位置
    QTextCursor tc = ui->plainTextEdit->textCursor(); //当前光标
    // 移动光标到行尾
    //tc.movePosition(QTextCursor::EndOfLine);
    tc.movePosition(QTextCursor::EndOfLine, QTextCursor::KeepAnchor);
    //qDebug() << "选择的字符 = " << tc.selectedText();
    // 计算光标当前位置到行尾的长度
    int length = tc.position() - ui->plainTextEdit->textCursor().position();
    //qDebug() << "当前光标距离尾行长度为 =" << length;


    return length;
}

void sshwidget::amendPosition() {
    //获取两个文本框的位置
    int testEdit_s_r = getCurrentRowPositionByLocal_s();
    int testEdit_r = getCurrentRowPositionByLocal();
    //qDebug() << "testEdit_s 的位置位于 " << testEdit_s_r;
    //qDebug() << "testEdit   的位置位于 " << testEdit_r;
    if (testEdit_r != testEdit_s_r) {
        //qDebug() << "两个光标不在同一行，修正";
        if (testEdit_r - testEdit_s_r > 0) {
            //说明testEdit_s_r光标往上跑了
            movePositionDown_s(sshwidget::MoveAnchor, testEdit_r - testEdit_s_r);
            //qDebug() << "向下移动" << testEdit_r - testEdit_s_r;
        } else if (testEdit_r - testEdit_s_r < 0) {
            //说明testEdit_s_r光标往下跑了
            movePositionUp_s(sshwidget::MoveAnchor, testEdit_s_r - testEdit_r);
            //qDebug() << "向上移动" << testEdit_s_r - testEdit_r;
        }
    }

    int testEdit_s_c = getCurrentColumnPositionByLocal_s();
    int testEdit_c = getCurrentColumnPositionByLocal();
    //qDebug() << "testEdit_s_c 的位置位于 " << testEdit_s_c;
    //qDebug() << "testEdit_c   的位置位于 " << testEdit_c;
    if (testEdit_c != testEdit_s_c) {
        //qDebug() << "两个光标不在同一列，修正";
        if (testEdit_c - testEdit_s_c > 0) {
            //说明testEdit_s_c光标往左跑了
            movePositionLeft_s(sshwidget::MoveAnchor, testEdit_c - testEdit_s_c);
            //qDebug() << "向右移动" << testEdit_c - testEdit_s_c;
        } else if (testEdit_c - testEdit_s_c < 0) {
            //说明testEdit_s_c光标往右跑了
            movePositionRight_s(sshwidget::MoveAnchor, testEdit_s_c - testEdit_c);
            //qDebug() << "向左移动" << testEdit_s_c - testEdit_c;
        }
    }

}

void sshwidget::sendBuffData() {
    if (buffData != "") {
        sendData(buffData);
        buffData = "";
    }

}

void sshwidget::appendData(QString data) {
    //获取滚动条位置
    bool atEnd = ui->plainTextEdit->verticalScrollBar()->value() >= ui->plainTextEdit->verticalScrollBar()->maximum();
    QTextCharFormat fmt;

    QTextCursor tmp(ui->plainTextEdit->document());

    tmp.beginEditBlock();
    tmp.movePosition(QTextCursor::End);

    if (!ui->plainTextEdit->document()->isEmpty())
    {
        tmp.insertBlock(ui->plainTextEdit->textCursor().blockFormat(), ui->plainTextEdit->textCursor().charFormat());
    }
    else {

        tmp.setCharFormat(ui->plainTextEdit->textCursor().charFormat());
    }

    tmp.movePosition(QTextCursor::End);
    tmp.deletePreviousChar();

    tmp.insertText(data, fmt);

    // preserve the char format
    QTextCharFormat oldCharFormat = ui->plainTextEdit->textCursor().charFormat();

    if (!ui->plainTextEdit->textCursor().hasSelection())
        ui->plainTextEdit->textCursor().setCharFormat(oldCharFormat);

    tmp.endEditBlock();
    if (atEnd)
        ui->plainTextEdit->verticalScrollBar()->setValue(ui->plainTextEdit->verticalScrollBar()->maximum());
}


void sshwidget::appendData_s(QString data) {
    //获取滚动条位置
    bool atEnd = textEdit_s->verticalScrollBar()->value() >= textEdit_s->verticalScrollBar()->maximum();
    QTextCharFormat fmt;

    QTextCursor tmp(textEdit_s->document());

    tmp.beginEditBlock();
    tmp.movePosition(QTextCursor::End);

    if (!textEdit_s->document()->isEmpty())
    {
        tmp.insertBlock(textEdit_s->textCursor().blockFormat(), textEdit_s->textCursor().charFormat());
    }
    else {

        tmp.setCharFormat(textEdit_s->textCursor().charFormat());
    }

    tmp.movePosition(QTextCursor::End);
    tmp.deletePreviousChar();

    tmp.insertText(data, fmt);

    // preserve the char format
    QTextCharFormat oldCharFormat = textEdit_s->textCursor().charFormat();

    if (!textEdit_s->textCursor().hasSelection())
        textEdit_s->textCursor().setCharFormat(oldCharFormat);

    tmp.endEditBlock();
    if (atEnd)
        textEdit_s->verticalScrollBar()->setValue(textEdit_s->verticalScrollBar()->maximum());
}

// void sshwidget::on_textEdit_cursorPositionChanged()
// {
//     //qDebug() << "光标位置改变";
// }

void sshwidget::rece_channel_readS(QStringList data)
{
    data.removeAll("");  // 删除空字符串
    QElapsedTimer timer;
    timer.start();
    qDebug() << "rece_channel_readS data = " << data << "   isBuffer = " << isBuffer;
    //data.append("");
    int sum = 0;
    int sum2 = 0;
    //第一条固定为工作路径
    ssh_path = data[0];
    data = data.mid(1);
    int i = 0;
    for(i = 0; i < data.length(); i++) {
        //这块还要优化才行
        if (lastCommondS.contains("cat")) {
            if (gsum++ % 20 == 0) {
                //qDebug() << "刷新";
                ui->plainTextEdit->repaint();
                textEdit_s->repaint();
            }
            if (gsum++ % 100 == 0) {
                //qDebug() << "刷新";
                qApp->processEvents();
            }
        }

        //如果有颜色参数，则直接打印，如果没有就累加输出
        bool isSend = false;
        if (data.at(i).contains("color:")) {
            isSend = true;
        }
        //QCoreApplication::processEvents();
        if (data[i] == "\u001B[m") {
            qDebug() << "检测到\u001B[m" << "跳过";
            continue;
        }

        if (lastCommondS == "\u001BOC") {
            //data[i].length() 可能不是1
            //qDebug() << "删除右边一个字符，并打印";
            ////sendBuffData();
            //qDebug() << "func" << Q_FUNC_INFO  << "line" << __LINE__ ;
            movePositionRemoveLeftSelect(sshwidget::MoveAnchor, 1);
            sendData(data[i]);
            qDebug() << "向右移动一个光标，并打印" << data[i];
            //buffData = buffData + data[i];
            lastCommondS = "";
            int testEdit_s_c2 = getCurrentColumnPositionByLocal_s();
            qDebug() << "testEdit_s_c 的位置位于 " << testEdit_s_c2;
            continue;
        }

        if (lastCommondS == "\u001BOB") {
            if (data[i] == "\b") {
                // qDebug() << "BOD走到这里2" << " i = " << i;
                // sum++;
                // QString previousChar = movePositionRightSelect(sshwidget::KeepAnchor, 1);
                // //qDebug() << "1前一个字符为" << previousChar2;
                // isChinese = previousChar.contains(QRegExp("[\\x4e00-\\x9fa5]+"));

                // if(isChinese) {
                //     if (ChineseBackspaceSum!= 0) {
                //         movePositionRight(sshwidget::MoveAnchor, 1);
                //         isChinese = false;
                //         ChineseBackspaceSum = 0;
                //         //qDebug() << "走了这里？2";
                //     } else {
                //         //记录
                //         isChinese = true;
                //         ChineseBackspaceSum++;
                //     }
                // } else {
                //     movePositionRight(sshwidget::MoveAnchor, 1);
                // }
            } else if (data[i] == "\n") {
                ////sendBuffData();
                ////qDebug() << "func" << Q_FUNC_INFO  << "line" << __LINE__ ;
                movePositionDown(sshwidget::MoveAnchor, 1);
                setCurrentRowPosition(1);
                movePositionStartLine(sshwidget::MoveAnchor);
            } else if (data[i].contains("\n")) {
                int position = data[i].indexOf("\n");
                if (position == 0) {
                    ////sendBuffData();
                    ////qDebug() << "func" << Q_FUNC_INFO  << "line" << __LINE__ ;
                    movePositionDown(sshwidget::MoveAnchor, 1);
                    setCurrentRowPosition(1);
                    movePositionStartLine(sshwidget::MoveAnchor);
                    // 获取选定文本
                    // QString previousChar = movePositionLeftSelect(sshwidget::KeepAnchor, data[i].mid(4).length());
                    // isRightShiftChinese = previousChar.contains(QRegExp("[\\x4e00-\\x9fa5]+"));

                    // if(isRightShiftChinese) {
                    //     if (ChineseRightShiftSum!= 0) {
                    //         movePositionLeft(sshwidget::MoveAnchor, data[i].mid(4).length());
                    //         isRightShiftChinese = false;
                    //         ChineseRightShiftSum = 0;
                    //     } else {
                    //         //记录
                    //         isRightShiftChinese = true;
                    //         ChineseRightShiftSum++;
                    //     }
                    // } else {
                    //     movePositionLeft(sshwidget::MoveAnchor, data[i].mid(4).length());
                    // }

                    //判断后面有多少普通字符，直接输出 /n123 4 1
                    movePositionRemoveLeftSelect(sshwidget::MoveAnchor, data[i].length() - 1);
                    qDebug() << data << "向右移动光标(删除)" << data[i].length() - 1 << " 打印" << data[i].mid(1);
                    sendData(data[i].mid(1));

                }
            } else {
                int pos = 0;
                QRegExp regExp2("\\x001B\\[(\\d+);(\\d+)H");
                while ((pos = regExp2.indexIn(data[i], pos)) != -1) {
                    ////sendBuffData();
                    QTextCursor tc = ui->plainTextEdit->textCursor(); //当前光标
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
                        qDebug() << "走这里1";
                        movePositionDown(sshwidget::MoveAnchor, moveCount);
                        movePositionStartLine(sshwidget::MoveAnchor);
                        movePositionLeft(sshwidget::MoveAnchor, regExp2.cap(2).toInt() - 1);
                    } else {
                        qDebug() << "走这里2";
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

        if (data[i] == "\n") {
            //qDebug() << "走br";
            if (!isBuffer && clearSPos == 0) {
                //是否主缓冲区
                //buffData = buffData + " <br>";
                qDebug() << "isBuffer走这里";
                //sendBuffData();
                int cpos = getCurrentRowPositionByLocal();
                movePositionDown(sshwidget::MoveAnchor, 1);
                int cpos2 = getCurrentRowPositionByLocal();
                if (cpos2 - cpos == 0) {
                    sendData("\n");
                    //buffData = buffData + " <br>";
                }
                setCurrentRowPosition(1);
                int acurrentLine = getCurrentRowPosition();
                int cpos3 = getCurrentRowPositionByLocal();
                qDebug() << "isBuffer当前光标所在行数(相对于终端内部)1 =" << acurrentLine << "  R当前行数 =" << cpos3;
            } else if (isBuffer && isfirstR2) {
                //是否副缓冲区，并且有二级滚动区域
                //sendBuffData();
                //qDebug() << "func" << Q_FUNC_INFO  << "line" << __LINE__ ;
                if (getCurrentRowPosition() == firstE2) {
                    //qDebug() << "最后一行，需要滚动" << "从" << firstS2 << "到" << firstE2 << "滚动一行";
                    movePositionUp(sshwidget::MoveAnchor, firstE2 - firstS2 - 1);
                    setCurrentRowPosition(-(firstE2 - firstS2 - 1));
                    movePositionStartLine(sshwidget::MoveAnchor);
                    //qDebug() << "向上移动" << firstE2 - firstS2 - 1 << "行";
                    for (int i = 0; i < firstE2 - firstS2; i++) {
                        //从开始复制到结尾，并且最后一行不需要管
                        movePositionStartLine(sshwidget::MoveAnchor);
                        QString SelectData = movePositionEndLineSelect(sshwidget::KeepAnchor, -1);
                        //qDebug() << "需要复制到上一行内容 = " <<  SelectData;
                        movePositionUp(sshwidget::MoveAnchor, 1);
                        setCurrentRowPosition(-1);
                        movePositionStartLine(sshwidget::MoveAnchor);
                        //qDebug() << "打印数据";
                        sendData(SelectData);
                        //buffData = buffData + SelectData;
                        //sendBuffData();
                        //qDebug() << "func" << Q_FUNC_INFO  << "line" << __LINE__ ;
                        //qDebug() << "删除光标后面的数据";
                        movePositionRemoveEndLineSelect(sshwidget::KeepAnchor, -1);
                        movePositionDown(sshwidget::MoveAnchor, 2);
                        setCurrentRowPosition(2);
                        movePositionStartLine(sshwidget::MoveAnchor);
                    }
                }
            } else if (isBuffer) {
                //备用缓冲区
                //sendBuffData();
                movePositionDown(sshwidget::MoveAnchor, 1);
                setCurrentRowPosition(1);
                movePositionStartLine(sshwidget::MoveAnchor);
            } else {
                //sendBuffData();
                //qDebug() << "func" << Q_FUNC_INFO  << "line" << __LINE__ ;
                qDebug() << "向下滚动移动一行 clearSPos = " << clearSPos;
                movePositionDown(sshwidget::MoveAnchor, 1);
                if (clearSPos > 0) {
                    clearSPos--;
                    //qDebug() << "clearSPos-- =" << clearSPos;
                }
            }

            continue;
        } else if (data[i] == "\r") {
            //qDebug() << "移动到行首" << " 当前列位置 = " << getCurrentColumnPosition();
            //不是行首的意思
            //sendBuffData();
            //qDebug() << "func" << Q_FUNC_INFO  << "line" << __LINE__ ;
            movePositionStartLine(sshwidget::MoveAnchor);
            //qDebug() << "移动到行首" << " 当前列位置 = " << getCurrentColumnPosition();
            //isEnter = true;
            continue;
        //} else if (data[i] == "\u001BOD") {
        } else if (data[i] == "\b") {
            //qDebug() << "BOD走到这里" << " i = " << i;
            sum++;
            //sendBuffData();
            //qDebug() << "func" << Q_FUNC_INFO  << "line" << __LINE__ ;
            QString previousChar = movePositionRightSelect(sshwidget::KeepAnchor, 1);
            //qDebug() << "1前一个字符为" << previousChar2;
            isChinese = previousChar.contains(QRegExp("[\\x4e00-\\x9fa5]+"));

            if(isChinese) {
                if (ChineseBackspaceSum!= 0) {
                    movePositionRight(sshwidget::MoveAnchor, 1);
                    isChinese = false;
                    ChineseBackspaceSum = 0;
                    //qDebug() << "走了这里？";
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
            //sendBuffData();
            //qDebug() << "func" << Q_FUNC_INFO  << "line" << __LINE__ ;
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

            // 获取光标当前位置到行尾的长度
            int length = getTolineLength();
            //qDebug() << "当前光标距离尾行长度为 =" << length;

            continue;
        } else if (data[i] == "\u001B[D") {
            // 获取选定文本
            //sendBuffData();
            //qDebug() << "func" << Q_FUNC_INFO  << "line" << __LINE__ ;
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
            qDebug() << "删除光标后面的数据";
            //sendBuffData();
            ////qDebug() << "func" << Q_FUNC_INFO  << "line" << __LINE__ ;
            movePositionRemoveEndLineSelect(sshwidget::KeepAnchor, -1);
            sum = 0;
            continue;
        } else if (data[i] == "\u001B[?1049h") {
            qDebug()<< "开启副缓冲区";
            //保存主缓存区位置
            ZData = ui->plainTextEdit->toPlainText();
            //切换到备缓冲区
            isBuffer = true;
            isFirstBuffer = true;
            continue;
        } else if (data[i] == "\u001B[?1049l") {
            qDebug()<< "关闭副缓冲区";
            //切换到主缓冲区
            isfirstR = false;
            isfirstR2  = false;
            isBuffer = false;
            isFirstBuffer = false;
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
                qDebug() << "删除数据1";
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
                //sendBuffData();
                //qDebug() << "func" << Q_FUNC_INFO  << "line" << __LINE__ ;
                movePositionRemoveLeftSelect(sshwidget::KeepAnchor, sum);
            }
        } else if (data[i] == "\u001B[?25h") {
            //显示光标
            data[i] = "";
            //continue;
            if (backspaceSum > 0) {
                //光标删除后面一位
                qDebug() << "backspaceSum1 =" << backspaceSum << " data[i] = " << data[i];
                qDebug() << "删除数据2";
                lastData = "";
                int sum = 0;
                sum = backspaceSum;
                backspaceSum = 0;
                qDebug() << "backspaceSum2 =" << backspaceSum;
                //sendBuffData();
                //qDebug() << "func" << Q_FUNC_INFO  << "line" << __LINE__ ;
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
            //qDebug() << "清屏时行数(终端内部) =" << getCurrentRowPosition() << " 当前行数 = " << getCurrentRowPositionByLocal();
            int currentLine = 0;
            if (isBuffer && !isFirstBuffer) {
                //副缓冲区清屏，先把当前缓存区清空
                //上次19.这次从第一行也移动19
                //获取当前光标位置，移动到
                int acurrentLine = getCurrentRowPosition();
                int cpos2 = getCurrentRowPositionByLocal();
                qDebug() << "准备对副缓冲区清屏 A当前光标所在行数(相对于终端内部)1 =" << acurrentLine << "  R当前行数 =" << cpos2;
                movePositionUp(sshwidget::MoveAnchor, acurrentLine - 1);
                qDebug() << "向移动" << acurrentLine - 1 << "行";
                qDebug() << "副缓冲区移动完毕 A当前光标所在行数(相对于终端内部)1 =" << acurrentLine << "  R当前行数 =" << cpos2;

                //从当前行算起，清除20行
                for(int i = 0; i < 20; i++) {
                    movePositionStartLine(sshwidget::MoveAnchor);
                    //清除内容
                    movePositionRemoveEndLineSelect(sshwidget::KeepAnchor, -1);
                    int cpos_ = getCurrentRowPositionByLocal();
                    movePositionDown(sshwidget::MoveAnchor, 1);
                    int cpos2_ = getCurrentRowPositionByLocal();
                    setCurrentRowPosition(cpos2_ - cpos_);
                    int acurrentLine = getCurrentRowPosition();
                    int cpos2 = getCurrentRowPositionByLocal();
                    qDebug() << "光标所在行数(相对于终端内部)1 =" << acurrentLine << "  R当前行数 =" << cpos2;
                }
                int acurrentLine11 = getCurrentRowPosition();
                int cpos211 = getCurrentRowPositionByLocal();
                currentLine = acurrentLine11;
                qDebug() << "副缓冲区清除完毕 A当前光标所在行数(相对于终端内部)1 =" << acurrentLine11 << "  R当前行数 =" << cpos211;
            } else {
                setCurrentRowPositionToZero();
                setCurrentRowPosition(1);
                currentLine = getCurrentRowPosition();
            }

            // 获取文本编辑框的视口大小
            QSize viewportSize = textEdit_s->viewport()->size();
            // 获取字体的行高和字符宽度
            QFontMetrics metrics(textEdit_s->font());
            int lineHeight = metrics.lineSpacing();
            int charWidth = metrics.averageCharWidth();
            int visibleLines = viewportSize.height() / lineHeight;  //字体高度
            int visibleColumns = viewportSize.width() / charWidth - 5;
            int buchang = visibleLines - 2;
            int buchang2 = buchang;
            qDebug() << "清屏 向下移动" << buchang << "行";

            if (buchang >= currentLine) {
                buchang = buchang - currentLine;
            }
            qDebug() << "当前位于" << currentLine << "行" << " 修正后应移动" << buchang << "行";

            int cpos = getCurrentRowPositionByLocal();
            movePositionDown(sshwidget::MoveAnchor, buchang);
            int cpos2 = getCurrentRowPositionByLocal();
            
            setCurrentRowPosition(cpos2 - cpos);
            qDebug() << "移动" << cpos2 - cpos  << "剩下使用换行符移动";
            //setCurrentRowPosition(cpos3 - cpos2);
            int acurrentLine1122 = getCurrentRowPosition();
            int cpos23222 = getCurrentRowPositionByLocal();
            qDebug() << "A当前光标所在行数(相对于终端内部)1 =" << acurrentLine1122 << "  R当前行数 =" << cpos23222;
            if (cpos2 - cpos != buchang && cpos2 - cpos < buchang) {
                for (int i = cpos2 - cpos; i<buchang; i++) {
                    sendData("\n");
                }
            }
            int acurrentLine112 = getCurrentRowPosition();
            int cpos2322 = getCurrentRowPositionByLocal();
            qDebug() << "A当前光标所在行数(相对于终端内部)1 =" << acurrentLine112 << "  R当前行数 =" << cpos2322;

            qDebug() << "清屏 向上移动" << buchang << "行";
            movePositionUp(sshwidget::MoveAnchor, buchang);
            setCurrentRowPosition(-buchang);
            int acurrentLine = getCurrentRowPosition();
            int cpos23 = getCurrentRowPositionByLocal();
            qDebug() << "A当前光标所在行数(相对于终端内部)1 =" << acurrentLine << "  R当前行数 =" << cpos23;
            isFirstBuffer = false;
            continue;
        } else if (data[i] == "\u001B[L") {
            qDebug() << "遇到[L 向上移动";
            //sendBuffData();
            //qDebug() << "func" << Q_FUNC_INFO  << "line" << __LINE__ ;
            if (isBuffer && isfirstR2) {
                qDebug() << "A当前光标所在行数(相对于滚动区域) =" << getCurrentRowPosition() << "  R当前行数 =" << getCurrentRowPositionByLocal();
                if (getCurrentRowPosition()  == firstS2) {
                    qDebug() << "需要滚动" << "从" << firstE2 << "到" << firstS2 << "滚动一行";
                    movePositionDown(sshwidget::MoveAnchor, firstE2 - firstS2 - 1);
                    setCurrentRowPosition(firstE2 - firstS2 - 1);
                    movePositionStartLine(sshwidget::MoveAnchor);
                    qDebug() << "向下移动" << firstE2 - firstS2 - 1 << "行";
                    for (int i = 0; i < firstE2 - firstS2; i++) {
                        //从开始复制到结尾，并且最后一行不需要管
                        movePositionStartLine(sshwidget::MoveAnchor);
                        QString SelectData = movePositionEndLineSelect(sshwidget::KeepAnchor, -1);
                        qDebug() << "需要复制到上一行内容 = " <<  SelectData;
                        movePositionDown(sshwidget::MoveAnchor, 1);
                        setCurrentRowPosition(1);
                        movePositionStartLine(sshwidget::MoveAnchor);
                        qDebug() << "打印数据";
                        sendData(SelectData);
                        //buffData = buffData + SelectData;
                        //sendBuffData();
                        //qDebug() << "func" << Q_FUNC_INFO  << "line" << __LINE__ ;
                        qDebug() << "删除光标后面的数据";
                        movePositionRemoveEndLineSelect(sshwidget::KeepAnchor, -1);
                        movePositionUp(sshwidget::MoveAnchor, 2);
                        setCurrentRowPosition(-2);
                        movePositionStartLine(sshwidget::MoveAnchor);
                    }
                }
            }
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
        } else if (data[i] == "\u001B[1@") {
            //插入一个占位符
            sendData(" ");
            //光标左移1个
            movePositionRight(sshwidget::MoveAnchor, 1);
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
                //sendBuffData();
                //qDebug() << "func" << Q_FUNC_INFO  << "line" << __LINE__ ;
                //原位置
                int pos1  = ui->plainTextEdit->textCursor().position();
                int pos2  = textEdit_s->textCursor().position();
                movePositionEndLine(sshwidget::MoveAnchor);
                movePositionRemoveRight(sshwidget::KeepAnchor, match.toInt());

                QTextCursor cursor = ui->plainTextEdit->textCursor();
                cursor.setPosition(pos1);
                ui->plainTextEdit->setTextCursor(cursor);
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
                //sendBuffData();
                //qDebug() << "func" << Q_FUNC_INFO  << "line" << __LINE__ ;
                int acurrentLine = getCurrentRowPosition();
                int cpos2 = getCurrentRowPositionByLocal();
                qDebug() << "A当前光标所在行数(相对于终端内部)1 =" << acurrentLine << "  R当前行数 =" << cpos2 << " data[i] = " << data[i];

                int moveCount = regExp2.cap(1).toInt() - acurrentLine;
                int columnCount = regExp2.cap(2).toInt() - 1;
                
                qDebug() << "moveCount = " << moveCount;
                int testEdit_s_c22 = getCurrentColumnPositionByLocal_s();
                qDebug() << "testEdit_s_c 的位置位于 " << testEdit_s_c22;
                //第一个参数是移动到第几行，第二个参数是第几位
                if (moveCount > 0) {

                    qDebug() << "移动" << moveCount << "行2";

                    int cpos = getCurrentRowPositionByLocal();
                    movePositionDown(sshwidget::MoveAnchor, moveCount);
                    int cpos2 = getCurrentRowPositionByLocal();
                    setCurrentRowPosition(cpos2 - cpos);
                    qDebug() << "向下移动" << cpos2 - cpos  << "剩下使用换行符移动";
                    if (cpos2 - cpos != moveCount && cpos2 - cpos < moveCount) {
                        for (int i = cpos2 - cpos; i<moveCount; i++) {
                            if (isBuffer) {
                                //sendData("        ");
                                if (cpos2 - cpos < moveCount - 1) {
                                    sendData("\n");
                                }
                            } else {
                                sendData("\n");
                            }
                        }
                    }

                    //qDebug() << "A当前光标所在行数(相对于终端内部)2 =" << getCurrentRowPosition() << "  R当前行数 =" << getCurrentRowPositionByLocal();

                } else if (moveCount < 0) {
                    qDebug() << "向上移动" << moveCount << "行";
                    //sendBuffData();
                    //qDebug() << "func" << Q_FUNC_INFO  << "line" << __LINE__ ;
                    // movePositionUp(sshwidget::MoveAnchor, -moveCount);
                    // movePositionStartLine(sshwidget::MoveAnchor);
                    // setCurrentRowPosition(moveCount);

                    int cpos = getCurrentRowPositionByLocal();
                    movePositionUp(sshwidget::MoveAnchor, -moveCount);
                    movePositionStartLine(sshwidget::MoveAnchor);
                    int cpos2 = getCurrentRowPositionByLocal();
                    setCurrentRowPosition(cpos2 - cpos);
                    qDebug() << "向上移动" << cpos2 - cpos;
                } else {
                    //qDebug() << "不需要移动";
                }
                int testEdit_s_c = getCurrentColumnPositionByLocal_s();
                qDebug() << "收到columnCount应位于" << columnCount;
                qDebug() << "testEdit_s_c 的位置位于 " << testEdit_s_c;
                qDebug() << "移动" << testEdit_s_c - columnCount;
                columnCount = testEdit_s_c - columnCount;

                if (columnCount >= 0) {
                    //sendBuffData();

                    //qDebug() << "func" << Q_FUNC_INFO  << "line" << __LINE__ ;
                    //movePositionStartLine(sshwidget::MoveAnchor);
                    int length_ = getTolineLength();
                    qDebug() << "移动到" << columnCount << "列" << " 当前行长度 " << length_;
                    if (columnCount <= length_) {
                        //长度够直接移动
                        qDebug() << "movePositionLeft" << columnCount;
                        movePositionRight(sshwidget::MoveAnchor, columnCount);
                    } else {
                        //如果长度不够直接移动，会移动到下一行,所以移动之前先补空格，权宜之计，后面会正整行生成空格
                        int diff = columnCount - length_;
                        qDebug() << "补" << diff << "个空格";
                        for(int i =0; i< diff; i++) {
                            sendData(" ");
                            //buffData = buffData + "&nbsp;";
                        }
                        //sendBuffData();
                        //qDebug() << "func" << Q_FUNC_INFO  << "line" << __LINE__ ;
                        movePositionStartLine(sshwidget::MoveAnchor);
                        movePositionLeft(sshwidget::MoveAnchor, columnCount);
                    }
                    qDebug() << "当前光标到行尾部 距离" << length_;

                    QTextCursor tc = ui->plainTextEdit->textCursor(); //当前光标
                    QTextLayout *lay = tc.block().layout();
                    int iCurPos= tc.position() - tc.block().position();//当前光标在本BLOCK内的相对位置
                    int acurrentLine = lay->lineForTextPosition(iCurPos).lineNumber() + tc.block().firstLineNumber();
                    //qDebug() << "A当前光标所在行数(相对于滚动区域) =" << acurrentLine - currentLine + 1 << "  R当前行数 =" << currentLine;

                } else if (columnCount < 0) {
                    //这里要考虑如果移动大于现有字符
                    movePositionLeft(sshwidget::MoveAnchor, -columnCount);
                } else {
                    qDebug() << "不需要移动列";
                }
                int acurrentLine2 = getCurrentRowPosition();
                int cpos22 = getCurrentRowPositionByLocal();
                qDebug() << "移动完成 当前光标所在行数(相对于终端内部)1 =" << acurrentLine2 << "  R当前行数 =" << cpos22;
                int testEdit_s_c2 = getCurrentColumnPositionByLocal_s();
                qDebug() << "testEdit_s_c 的位置位于 " << testEdit_s_c2;

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
                qDebug() << "检测到滚动系列";
                if (!isfirstR) {
                    isfirstR = true;
                    firstS = regExp4.cap(1).toInt();
                    qDebug() << "滚动开始" << regExp4.cap(1).toInt();
                    firstE = regExp4.cap(2).toInt();
                    qDebug() << "滚动结束" << regExp4.cap(2).toInt();
                } else {
                    if (regExp4.cap(1).toInt() != firstS || regExp4.cap(2).toInt() != firstE ) {
                        isfirstR2 = true;
                        //当前处于备用缓冲区，如果碰到r可能就要滚动了
                        //\u001B[15;23r 设置二级滚动区域 后面如果在23更新，就需要更新15-23里面的数据
                        firstS2 = regExp4.cap(1).toInt();
                        qDebug() << "2级滚动开始" << regExp4.cap(1).toInt();
                        firstE2 = regExp4.cap(2).toInt();
                        qDebug() << "2级滚动结束" << regExp4.cap(2).toInt();
                    } else if (regExp4.cap(1).toInt() == firstS && regExp4.cap(2).toInt() == firstE) {
                        isfirstR2 = false;
                        firstS = regExp4.cap(1).toInt();
                        qDebug() << "滚动开始" << regExp4.cap(1).toInt();
                        firstE = regExp4.cap(2).toInt();
                        qDebug() << "滚动结束" << regExp4.cap(2).toInt();
                    }
                }
                    data[i].replace(regExp4.cap(0), "");
            }

            pos = 0;
            QRegExp regExp5("\\x001B\\[(\\d+)G");
            while ((pos = regExp5.indexIn(data[i], pos)) != -1) {
                //qDebug() << "检测到G系列 =" << regExp5.cap(1);
                //sendBuffData();
                //qDebug() << "func" << Q_FUNC_INFO  << "line" << __LINE__ ;
                movePositionLeft(sshwidget::MoveAnchor, regExp5.cap(1).toInt()-1);
                data[i].replace(regExp5.cap(0), "");
                //break;
            }

            //到了这边就只有打印了数据了
            if (!isa) {
                if (sum != 0) {
                    qDebug() << "走到这里7";
                    //sendBuffData();
                    //qDebug() << "func" << Q_FUNC_INFO  << "line" << __LINE__ ;
                    QTextCursor cursor4 = ui->plainTextEdit->textCursor();
                    int cursorPos = cursor4.position();
                    int textLength = ui->plainTextEdit->toPlainText().length();
                    int charsToEnd = textLength - cursorPos;

                    //覆盖 如果data[i]有数据就覆盖几个，剩下的继续覆盖
                    if (sum != 0) {
                        qDebug() << "走到这里8";

                        QTextCursor cursor = ui->plainTextEdit->textCursor();
                        cursor.movePosition(QTextCursor::Right, QTextCursor::KeepAnchor, sum);
                        cursor.deletePreviousChar();
                        ui->plainTextEdit->setTextCursor(cursor);

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
                    //sendBuffData();
                    //qDebug() << "func" << Q_FUNC_INFO  << "line" << __LINE__ ;
                    movePositionRemoveLeftSelect(sshwidget::KeepAnchor, data[i].length());
                }

                /*测试*/
                if (data[i] == "") {
                    continue;
                }

                //qDebug() << "A准备打印" << data[i];



                if (data[i].contains("\n")) {
                    int position = data[i].indexOf("\n");
                    if (position == -4) {
                        //dataS.append(data[i].mid(0, 3));
                    } else {
                        while(1) {
                            int position2 = 0;
                            if (data[i].contains("\n")) {
                                position2 = data[i].indexOf("\n");
                                //qDebug() << "打印1";
                                sendData(data[i].mid(0, position2));
                                //尝试光标向下移动一行
                                int cpos = getCurrentRowPositionByLocal();
                                movePositionDown(sshwidget::MoveAnchor, 1);
                                int cpos2 = getCurrentRowPositionByLocal();
                                setCurrentRowPosition(cpos2 - cpos);
                                //qDebug() << "移动" << cpos2 - cpos  << "剩下使用换行符移动";
                                if (cpos2 - cpos != 1 && cpos2 - cpos < 1) {
                                    sendData("\n");
                                }
                                data[i] = data[i].mid(position2 + 1);
                            } else {
                                //qDebug() << "打印6";
                                sendData(data[i]);
                                //buffData = buffData + data[i];
                                break;
                            }

                        }
                    }
                } else {

                    // 计算光标当前位置到行尾的长度
                    ////sendBuffData();
                    ////qDebug() << "func" << Q_FUNC_INFO  << "line" << __LINE__ ;
                    int length = getTolineLength();
                    //qDebug() << "当前光标距离尾行长度为 =" << length;
                    //计算需要清除长度

                    if (data[i].length() >= length) {
                        //删除length
                        movePositionRemoveLeftSelect(sshwidget::KeepAnchor, length);
                        //qDebug() << "删除右边" << length;
                    } else {
                        //删除data[i].length()
                        movePositionRemoveLeftSelect(sshwidget::KeepAnchor, data[i].length());
                        //qDebug() << "删除右边" << data[i].length();
                    }
                    sendData(data[i]);
                    //buffData = buffData + data[i];

                    //如果是vi 模式 在输出字符的同时，删除后面对应长度的字符
                    if (mode == 2) {
                        //记录输出长度
                        mode_2_length = data[i].length();
                    }
                    if (clearPos + 1 == i && lastCommondS == "clear") {
                        qDebug() << "lineCount = " << lineCount;
                        int sum = lineCount - clearSPos;
                        for(int i = 0; i < sum; i++) {
                            qDebug() << "打印9";
                            sendData("\n");
                            //buffData = buffData + "<br>";
                            clearSPos++;
                        }
                        //sendBuffData();
                        //qDebug() << "func" << Q_FUNC_INFO  << "line" << __LINE__ ;
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
                        qDebug() << "backspaceSum sum=" << sum;
                        qDebug() << "删除数据3";
                        // 获取选定文本
                        //qDebug() << "func" << Q_FUNC_INFO  << "line" << __LINE__ ;
                        //sendBuffData();
                        //qDebug() << "func" << Q_FUNC_INFO  << "line" << __LINE__ ;
                        QString previousChar2 = movePositionLeftSelect(sshwidget::KeepAnchor, 1);;
                        movePositionRemoveLeftSelect(sshwidget::KeepAnchor, sum);
                    }
                }
            } else {
                //qDebug() << "func" << Q_FUNC_INFO  << "line" << __LINE__ ;
                ////sendBuffData();
                //qDebug() << "func" << Q_FUNC_INFO  << "line" << __LINE__ ;
                if (isEnter && data[i].length()!= 0) {
                    movePositionRemoveLeftSelect(sshwidget::KeepAnchor, data[i].length());
                    isEnter = false;
                }
                qDebug() << "打印数据=" << data[i];
                sendData(data[i]);
                //buffData = buffData + data[i];
            }
        }
    }
    ////qDebug() << "func" << Q_FUNC_INFO  << "line" << __LINE__ ;
    //sendBuffData();
    if (scrollBar_textEdit && scrollBar_textEdit_s) {
        //qDebug() << "设置滑动条 read " << scrollBar_textEdit->value();
        scrollBar_textEdit->setValue(scrollBar_textEdit->maximum());
        scrollBar_textEdit_s->setValue(scrollBar_textEdit->value());
    }
    QScrollBar * scrollBar_textEdit_h = ui->plainTextEdit->horizontalScrollBar();
    scrollBar_textEdit_h->setValue(0);
    QScrollBar * scrollBar_textEdit_s_h = textEdit_s->horizontalScrollBar();
    scrollBar_textEdit_s_h->setValue(0);
    qint64 elapsedMilliseconds = timer.elapsed();
    qDebug() << "响应时间：" + QString::number(elapsedMilliseconds) + "ms";
    ui->verticalScrollBar->setMinimum(ui->plainTextEdit->verticalScrollBar()->minimum());
    ui->verticalScrollBar->setSingleStep(ui->plainTextEdit->verticalScrollBar()->singleStep());
    ui->verticalScrollBar->setPageStep(ui->plainTextEdit->verticalScrollBar()->pageStep());
    ui->verticalScrollBar->setMaximum(ui->plainTextEdit->verticalScrollBar()->maximum());
    ui->verticalScrollBar->setValue(ui->plainTextEdit->verticalScrollBar()->value());
}

void sshwidget::rece_key_sign(QString key)
{
    qDebug() << "触发rece_key_sign = " << key;
    //调用前修正光标位置
    amendPosition();
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

    ui->progressBar_mem->setFormat("%p%   " + serverInfo.memUse);
    ui->progressBar_swap->setFormat("%p%   " + serverInfo.swapUse);
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

//void sshwidget::on_pushButton_clicked()
//{

    //    QTextCursor cursor(ui->plainTextEdit->document());
    //    cursor.movePosition(QTextCursor::Start);

    //    for (int i = 0; i < 5 - 1; ++i)
    //    {
    //        cursor.movePosition(QTextCursor::Down);
    //    }

    //    ui->plainTextEdit->setTextCursor(cursor);
    //    ui->plainTextEdit->ensureCursorVisible();
    //    ui->plainTextEdit->setFocusPolicy(Qt::StrongFocus);
    //    ui->plainTextEdit->setFocus();

    // 保存原始的文本格式
    //    cursor_s = ui->plainTextEdit->textCursor();
    //    originalFormat_s = cursor_s.charFormat();

    /* 需要搜索的文本 */
    //QString searchString = ui->lineEdit->text();
    /* 文本框的全部内容 */
//    QTextDocument *document = ui->plainTextEdit->document();

//    document->undo();

//    bool found = false;

//    if (searchString.isEmpty()) {

//    } else {
//        /* 高亮本文配置 */
//        QTextCursor highlightCursor(document);

//        QTextCharFormat plainFormat(highlightCursor.charFormat());

//        QTextCharFormat colorFormat = plainFormat;
//        colorFormat.setForeground(Qt::black);
//        colorFormat.setBackground(Qt::yellow);

//        while (!highlightCursor.isNull() && !highlightCursor.atEnd()) {
//            /* 搜索给定文本的位置 */
//            highlightCursor = document->find(searchString, highlightCursor,
//                                             QTextDocument::FindWholeWords);

//            if (!highlightCursor.isNull()) {
//                found = true;
//                highlightCursor.movePosition(QTextCursor::WordRight,
//                                             QTextCursor::KeepAnchor);
//                /* 设置高亮文本 */
//                highlightCursor.mergeCharFormat(colorFormat);
//            }
//        }
//    }
//}

// void sshwidget::on_textEdit_selectionChanged()
// {
//     QTextCursor cursor = ui->plainTextEdit->textCursor();

//     if (!cursor.hasSelection()) {
//         return;
//     }
// }


void sshwidget::scrollBarValueChanged(int value)
{
    qDebug() << "滑动条值改变为1：" << value;
    QScrollBar *scrollBar = ui->plainTextEdit->verticalScrollBar();
    scrollBar->setValue(value);
    ui->verticalScrollBar->setValue(value);
}

void sshwidget::scrollBarValueChanged2(int value)
{
    //qDebug() << "滑动条值改变为2：" << value;
    //qDebug() << "当前值：" << scrollBar_textEdit->value();
    //QScrollBar *scrollBar = ui->textEdit_6->verticalScrollBar();
    //scrollBar->setValue(value);

}

// void sshwidget::on_textEdit_textChanged()
// {
//     if (scrollBar_textEdit && scrollBar_textEdit_s) {
//         //qDebug() << "设置滑动条 ";
//         scrollBar_textEdit_s->setValue(scrollBar_textEdit->value());
//     }
//     //获取最后一行数据放在textEdit_6
//     //ui->verticalScrollBar->setValue(ui->plainTextEdit->verticalScrollBar()->value());
//     //ui->verticalScrollBar->setMaximum(ui->plainTextEdit->verticalScrollBar()->maximum());
// }

void sshwidget::rece_send_mousePress_sign()
{
    ui->plainTextEdit->setFocusPolicy(Qt::NoFocus);
    ui->plainTextEdit->setFocus();
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
    ui->plainTextEdit->setFocus();
}

void sshwidget::rece_paste_sgin()
{
    //以防光标不一致
    amendPosition();
    QClipboard *clipboard = QGuiApplication::clipboard();
    const QMimeData *mimeData = clipboard->mimeData();

    if (mimeData->hasText()) {
        QString clipboardText = mimeData->text();
        sendCommandData(clipboardText);
    }
    ui->plainTextEdit->setFocus();
}

void sshwidget::rece_pasteSelect_sgin()
{
    //这个时候textEdit_s的光标必然和textEdit不同
    //获取选中数据后，进行光标修正
    QString selectText = getSelectText_s();
    qDebug() << "选中文本 =" << selectText;
    amendPosition();
    sendCommandData(selectText);
    ui->plainTextEdit->setFocus();
}

void sshwidget::rece_resize_sign() {
    int width = textEdit_s->geometry().width();
    //int height = textEdit_s->geometry().height();
    fwidget->move(width - fwidget->geometry().width() - 50, 5);
    dlwidget->move(width - dlwidget->geometry().width() - 20, 5);
    int width2 = ui->widget_2->geometry().width();
    int height2 = ui->widget_2->geometry().height();
    hcwidget->move(width2/2 - 180, height2- 300);
    //qDebug() << "width2 = " << width2 << " height2 = " << height2;
    // 获取文本编辑框的视口大小
    QSize viewportSize = textEdit_s->viewport()->size();

    // 获取字体的行高和字符宽度
    QFontMetrics metrics(textEdit_s->font());
    int lineHeight = metrics.lineSpacing();
    int charWidth = metrics.averageCharWidth();
    // int s = (ui->widget_2->geometry().height() - ui->widget_toolbar->geometry().height()) % lineHeight;
    // if (s >= 0) {
    //     ui->widget_10->setFixedHeight((ui->widget_2->geometry().height() - ui->widget_toolbar->geometry().height()) - s);
    //     ui->widget_cache->setFixedHeight(s);
    // }

    ui->widget_10->setMinimumHeight(0);
    ui->widget_10->setMaximumHeight(QWIDGETSIZE_MAX);
    ui->widget_10->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    ui->widget_cache->setMinimumHeight(0);
    ui->widget_cache->setMaximumHeight(QWIDGETSIZE_MAX);
    ui->widget_cache->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);


    //qDebug() << "rece_resize_sign 字体 高 = " << lineHeight << " 字体 宽 = " << charWidth;
    //qDebug() << "rece_resize_sign 视图 高 = " << viewportSize.height()  << "  视图 宽 = " << viewportSize.width();
    // 计算可见行数和列数
    int visibleLines = viewportSize.height() / lineHeight;
    m_visibleLines = visibleLines;
    int visibleColumns = viewportSize.width() / charWidth - 5;
    m_visibleColumns = visibleColumns;
    if (columnCount != visibleColumns || lineCount != visibleLines || isfup) {
        ui->label->setText(QString::number(visibleLines) +","+ QString::number(visibleColumns));
        setTerminalSize(visibleLines - 2, visibleColumns);
       QPalette palette = ui->plainTextEdit->palette();
       palette.setColor(QPalette::Text, QColor(0, 0, 0, 0)); // 文字颜色设置为透明
       ui->plainTextEdit->setPalette(palette);
        columnCount = visibleColumns;
        lineCount = visibleLines;
        if (isfup) {
            isfup = false;
        }
    }
}

void sshwidget::rece_setting() {
    //跳转到设置页面-终端
    emit send_windowsSetting();
}

void sshwidget::rece_searchTextChanged(const QString data) {
    QPalette palette = ui->plainTextEdit->palette();
    palette.setColor(QPalette::Text, QColor(0, 0, 0, 0)); // 文字颜色设置为透明
    ui->plainTextEdit->setPalette(palette);

    //qDebug() << "toHtml = " << ui->plainTextEdit->toHtml();

    qDebug() << "搜索内容为" << data;
    QString searchString = data;
    QTextDocument *document = ui->plainTextEdit->document();
    int sum = 0;
    bool found = false;
//    bool isFirstTime = true;
//    if (isFirstTime == false) {
        document->undo();
    //}

    if (searchString == "") {
        emit send_searchTextNumbers(0, 0);
        qDebug() << "Empty Search Field";
    } else {
        QTextCursor highlightCursor(document);
        QTextCursor cursor(document);
        //***************开始***************
        cursor.beginEditBlock();
        QTextCharFormat plainFormat(highlightCursor.charFormat());
        QTextCharFormat colorFormat = plainFormat;
        colorFormat.setForeground(Qt::black);
        colorFormat.setBackground(Qt::yellow);
        while (!highlightCursor.isNull() && !highlightCursor.atEnd()) {
            highlightCursor = document->find(searchString, highlightCursor);
            if (!highlightCursor.isNull()) {
                found = true;
                qDebug() << "找到";
                sum++;
//                highlightCursor.movePosition(QTextCursor::WordRight,
//                        QTextCursor::KeepAnchor);
                highlightCursor.mergeCharFormat(colorFormat);
            }
        }
        cursor.endEditBlock();

        emit send_searchTextNumbers(0, sum);
        //***************结束***************
        //isFirstTime = false;
        if (found == false) {
            qDebug() << "Word Not Found";
        }

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
    
    if (fileList.isEmpty()) {
        qDebug() << "取消文件选择";
        return;
    }

    for(int i=0;i<fileList.count();i++) {   //添加文件名到文本框
        qDebug() << "选择路径：" << fileList.at(i);
    }
    //获取当前服务器目录，然后上传
    QString path = fileList.at(0);
    QString fileName;
    int colonIndex = path.lastIndexOf('/');
    if (colonIndex != 1) {
        //qDebug() << "上传文件 文件名" << A.mid(colonIndex + 1);
        fileName = path.mid(colonIndex + 1);
    }

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

        QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect(this);
        effect->setOffset(0, 0);          //设置向哪个方向产生阴影效果(dx,dy)，特别地，(0,0)代表向四周发散
        effect->setColor(QColor(50, 50, 50));       //设置阴影颜色，也可以setColor(QColor(220,220,220))
        effect->setBlurRadius(15);        //设定阴影的模糊半径，数值越大越模糊
        //menu->setGraphicsEffect(effect);

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

        QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect(this);
        effect->setOffset(0, 0);          //设置向哪个方向产生阴影效果(dx,dy)，特别地，(0,0)代表向四周发散
        effect->setColor(QColor(50, 50, 50));       //设置阴影颜色，也可以setColor(QColor(220,220,220))
        effect->setBlurRadius(15);        //设定阴影的模糊半径，数值越大越模糊
        //menu->setGraphicsEffect(effect);

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
    addcwidget = new addcommondwidget();
    connect(addcwidget,SIGNAL(send_addCommond(QString, QString, QString, bool)),this,SLOT(rece_addCommond(QString, QString, QString, bool)));
    addcwidget->show();
}

void sshwidget::rece_mkdirFolder_sgin()
{
    //创建文件夹
    mkdirfwidget = new mkdirfolderwidget();
    connect(mkdirfwidget,SIGNAL(send_mkdirFolder(QString)),this,SLOT(rece_mkdirFolder(QString)));
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

void sshwidget::rece_ssh_init(bool isok)
{
    // 设置焦点策略为强制获取焦点
    ui->plainTextEdit->setFocusPolicy(Qt::NoFocus);
    ui->plainTextEdit->setFocus();
    if (!isok) {
        QString cc = "主机连接失败\n";
        ui->plainTextEdit->appendPlainText(cc);
        movePositionEnd();
        textEdit_s->appendPlainText(cc);
        //更新状态图标
        //qDebug("发送更新图标状态");
        emit send_connection_fail(this);
        return;
    }

    //qDebug("开始调用init_poll");
    QString cc = "主机连接成功\n";
    ui->plainTextEdit->appendPlainText(cc);
    movePositionEnd();
    textEdit_s->appendPlainText(cc);

    //更新状态图标
    //qDebug("发送更新图标状态");
    emit send_connection_success(this);
    //更新终端size
    isfup = true;
    rece_resize_sign();
    //初始化完成调用
    QMetaObject::invokeMethod(m_sshhandle,"init_poll",Qt::QueuedConnection);
    //通知页面，连接成功，可以使用
    //qDebug("开始调用init_poll完成");

    QString host = cInfoStruct.host;
    QString port = cInfoStruct.port;
    QString username = cInfoStruct.userName;
    QString password = cInfoStruct.password;
    int connrectType = 1;
    QMetaObject::invokeMethod(sshExec,"init", Qt::QueuedConnection, Q_ARG(int, connrectType), Q_ARG(QString, host), Q_ARG(QString,port), Q_ARG(QString,username), Q_ARG(QString,password), Q_ARG(QString,""));
    QMetaObject::invokeMethod(sshSftp,"init", Qt::QueuedConnection, Q_ARG(int, connrectType), Q_ARG(QString, host), Q_ARG(QString,port), Q_ARG(QString,username), Q_ARG(QString,password));
}

void sshwidget::rece_ssh_exec_init(bool isok)
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

void sshwidget::rece_addCommond(QString name, QString data, QString oldData, bool isLineFeed) {
    //添加命令
    qDebug() << "rece_addCommond name = " << name  << " data = " << data;
    if (oldData == "") {
        qDebug() << "新增";
        QWidget * commondWidget = createCommand(name, data, isLineFeed);
        QWidget * cWidget = ui->tabWidget->currentWidget();
        cWidget->layout()->addWidget(commondWidget);
    } else {
        qDebug() << "修改";
        //查找原name所属
        QString oldName = ui->label_command->text();
        //遍历当前命令查找oldName
        //
        QWidget * cWidget = ui->tabWidget->currentWidget();
        QObjectList children = cWidget->children();
        foreach(QObject *child, children) {
            if (QWidget *childWidget = qobject_cast<QWidget*>(child)) {
                // 这里可以对子部件执行操作，比如打印部件的类型或者执行其他操作
                qDebug() << "Found child widget: " << childWidget->objectName();
                if (childWidget->objectName() == oldName) {
                    qDebug() << "找到需要修改的部件widget";
                    QObjectList children2 = childWidget->children();
                    foreach(QObject *child, children2) {
                        if (QToolButton *button = qobject_cast<QToolButton *>(child)) {
                            qDebug() << "Found child widget: " << button->text();
                            if (button->text() == oldName) {
                                qDebug() << "找到需要修改的部件button";
                                button->setText(name);
                                //删除旧数据
                                commondList.remove(oldName);
                                commondInfo cInfo;
                                cInfo.commond = data;
                                cInfo.isLineFeed = isLineFeed;
                                commondList[name] = cInfo;
                                ui->label_command->setText(name);
                                ui->label_edit->setText(data);
                            }
                        }
                    }
                }
            }
        }

        if (ui->label_command->text() == name) {
            //没有修改命令名字
        } else {
            //修改了命令名字
        }

        if (ui->label_edit->text() == data) {
            //没有修改命令
        } else {
            //修改了命令
        }
    }
}

void sshwidget::rece_mkdirFolder(QString data) {
    //创建tab
    qDebug() << "rece_addCommond data = " << data;
    ui->tabWidget->addTab(new QWidget(this), data);
}

void sshwidget::rece_clicked_run()
{
    QToolButton *button = qobject_cast<QToolButton*>(sender());
    if (button) {
        ui->label_command->setText(button->text());
        ui->label_edit->clear();
        ui->label_edit->setText(commondList[button->text()].commond);
        qDebug() << "执行" << button->text() << "命令:" << commondList[button->text()].commond;
        if (commondList[button->text()].isLineFeed) {
            sendCommandData(commondList[button->text()].commond + "\n");
        } else {
            sendCommandData(commondList[button->text()].commond);
        }
        
    }
}

void sshwidget::rece_clicked_edit()
{
    QToolButton *button = qobject_cast<QToolButton*>(sender());
    if (button) {
        ui->label_command->setText(button->text());
        ui->label_edit->clear();
        ui->label_edit->setText(commondList[button->text()].commond);
        //qDebug() << "执行" << button->text() << "命令:" << commondList[button->text()];
    }
}

void sshwidget::on_toolButton_edit_clicked()
{
    //修改
    addcwidget = new addcommondwidget(ui->label_command->text(), ui->label_edit->text(), commondList[ui->label_command->text()].isLineFeed);
    //addcwidget->textEdit_date
    connect(addcwidget,SIGNAL(send_addCommond(QString, QString, QString, bool)),this,SLOT(rece_addCommond(QString, QString, QString, bool)));
    addcwidget->show();
}

// void sshwidget::on_toolButton_2_clicked()
// {
//     ui->verticalScrollBar->setMaximum(ui->plainTextEdit->verticalScrollBar()->maximum());
// }

void sshwidget::on_verticalScrollBar_valueChanged(int value)
{
    ui->plainTextEdit->verticalScrollBar()->setValue(value);
    textEdit_s->verticalScrollBar()->setValue(value);
}

void sshwidget::on_toolButton_setting_clicked()
{
    //设置
    emit send_windowsSetting();
}
