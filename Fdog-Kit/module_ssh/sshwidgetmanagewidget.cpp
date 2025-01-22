#pragma execution_character_set("utf-8")
#include "sshwidgetmanagewidget.h"
#include "ui_sshwidgetmanagewidget.h"
#include "QDebug"
#include <QTimer>
#include <QMenu>
sshwidgetmanagewidget::sshwidgetmanagewidget(config * confInfo, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sshwidgetmanagewidget)
{
    ui->setupUi(this);
    this->confInfo = confInfo;
    // 创建定时器
    QTimer * timer = new QTimer();

    // 设置定时器的间隔为1000毫秒（1秒）
    timer->setInterval(1000);

    // 连接定时器的timeout()信号到槽函数
    connect(timer,SIGNAL(timeout()), this,
                            SLOT(rece_showtimestamp()));

    // 启动定时器
    timer->start();

    //ui->comboBox_tool->setView(new QListView());
    ui->widget_tool->hide();
    ui->splitter->setStretchFactor(0,20);
    ui->splitter->setStretchFactor(1,2);

    //打开数据库
    //db = new sqlhandle();

    db = new sshsql();

    QVector<connnectInfoStruct> cInfoStructList = db->ssh_getAllSSHInfo();
    qDebug() << "sshinfo 3 size = " << cInfoStructList.length();
    //isFirst = true;
    //创建快速连接
    //创建快速连接
    int8_t connectType = 0;
    //创建连接窗口
    hcwidget = new historyconnectwidget(connectType, cInfoStructList, confInfo, this);
    connect(hcwidget,SIGNAL(send_fastConnection(connnectInfoStruct&)),this,SLOT(rece_fastConnection(connnectInfoStruct&)));
    connect(hcwidget,SIGNAL(send_findConnection(QString, int)),this,SLOT(rece_findConnection(QString, int)));
    QSize iconSize(20, 20); // 设置图标的大小
    ui->tabWidget->addTab(hcwidget, QIcon(":lib/kuaisu2.png").pixmap(iconSize), "快速连接");
    ui->tabWidget->setCurrentIndex(ui->tabWidget->count()-1);
    hcwidget->show();

    TreeWidgetFilter *filter = new TreeWidgetFilter(this);
    connect(filter,SIGNAL(send_updateMouseStyle()),this,SLOT(rece_updateMouseStyle()));
    setSupportStretch(this, true);
    ui->tabWidget->setMouseTracking(true);
    ui->tabWidget->installEventFilter(filter);
}



void sshwidgetmanagewidget::newSSHWidget(connnectInfoStruct &cInfoStruct, config *confInfo)
{
    qDebug() << "设置ssh";
    QSize iconSize(16, 16); // 设置图标的大小
    QString sign = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    sshwidget * sshWidget = new sshwidget(cInfoStruct, confInfo, cInfoStruct.name + sign);
    connect(sshWidget,SIGNAL(send_toolButton_toolkit_sign()),this,SLOT(rece_widget_welcome_body_widget2_newCreate_newTool_clicked()));
    connect(sshWidget,SIGNAL(send_toolButton_fullScreen_sign()),this,SLOT(rece_toolButton_fullScreen_sign()));
    connect(sshWidget,SIGNAL(send_connection_success(sshwidget *)),this,SLOT(rece_connection_success(sshwidget *)));
    connect(sshWidget,SIGNAL(send_connection_fail(sshwidget *)),this,SLOT(rece_connection_fail(sshwidget *)));
    connect(sshWidget,SIGNAL(send_windowsSetting()),this,SLOT(rece_windowsSetting()));
    sshWidgetList.push_back(sshWidget);
    ui->tabWidget->addTab(sshWidget, QIcon(":lib/yellow.svg").pixmap(iconSize), cInfoStruct.name);
    //插入数据
    if (cInfoStruct.sshType == SSH_PASSWORD) {

    } else if (cInfoStruct.sshType == SSH_PUBLICKEY) {
        cInfoStruct.password = cInfoStruct.userName;
    }
    //这里是添加在最后一个标签页，后面要根据设置来
    ui->tabWidget->setCurrentIndex(ui->tabWidget->count()-1);
}

sshwidgetmanagewidget::~sshwidgetmanagewidget()
{
    delete ui;
}

void sshwidgetmanagewidget::rece_widget_welcome_body_widget2_newCreate_newTool_clicked()
{
    //显示工具栏窗口
    if (!isShowToolKit) {
        ui->widget_tool->show();
        isShowToolKit = true;
    } else {
        ui->widget_tool->hide();
        isShowToolKit = false;
    }
}

void sshwidgetmanagewidget::rece_toolButton_fullScreen_sign()
{
    //给主窗口发信号
}

void sshwidgetmanagewidget::rece_connection_success(sshwidget *sw)
{
    qDebug() << "连接成功,更换标识";
    for (int i = 0; i < ui->tabWidget->count(); ++i) {
        sshwidget * swTemp = qobject_cast<sshwidget*>(ui->tabWidget->widget(i));
        if (swTemp) {
            //转换成功
            if (swTemp->m_sign == sw->m_sign) {
                qDebug() << "找到对应页，更新状态图标";
                QSize iconSize(16, 16); // 设置图标的大小
                ui->tabWidget->setTabIcon(i, QIcon(":lib/green.svg").pixmap(iconSize));
                break;
            }
        } else {
            qDebug() << "转换失败";
        }
    }
}

void sshwidgetmanagewidget::rece_connection_fail(sshwidget *sw)
{
    qDebug() << "连接失败,更换标识";
    for (int i = 0; i < ui->tabWidget->count(); ++i) {
        sshwidget * swTemp = qobject_cast<sshwidget*>(ui->tabWidget->widget(i));
        if (swTemp) {
            //转换成功
            if (swTemp->m_sign == sw->m_sign) {
                qDebug() << "找到对应页，更新状态图标";
                QSize iconSize(16, 16); // 设置图标的大小
                ui->tabWidget->setTabIcon(i, QIcon(":lib/grey.svg").pixmap(iconSize));
                break;
            }
        } else {
            qDebug() << "转换失败";
        }
    }
}

void sshwidgetmanagewidget::rece_windowsSetting()
{
    //给主窗口发信号
}

void sshwidgetmanagewidget::on_tabWidget_customContextMenuRequested(const QPoint &pos)
{
    if (ui->tabWidget->currentIndex() == ui->tabWidget->tabBar()->tabAt(pos)) {
        //qDebug() << "标签";
        QMenu *menu = new QMenu(ui->tabWidget);
        menu->setWindowFlags(menu->windowFlags()  | Qt::FramelessWindowHint | Qt::NoDropShadowWindowHint);
        menu->setAttribute(Qt::WA_TranslucentBackground);
        QAction *action_reconnection = new QAction("重连", ui->tabWidget);
        QAction *action_copyTag = new QAction("复制标签", ui->tabWidget);
        QAction *action_close = new QAction("关闭", ui->tabWidget);
        QAction *action_closeOther = new QAction("关闭其他标签", ui->tabWidget);
        QAction *action_closeAll = new QAction("关闭全部标签", ui->tabWidget);

        connect (action_reconnection,SIGNAL(triggered()),this,SLOT(rece_reconnection_sgin()));
        connect (action_copyTag,SIGNAL(triggered()),this,SLOT(rece_copyTag_sgin()));
        connect (action_close,SIGNAL(triggered()),this,SLOT(rece_close_sgin()));
        connect (action_closeOther,SIGNAL(triggered()),this,SLOT(rece_closeOther_sgin()));
        connect (action_closeAll,SIGNAL(triggered()),this,SLOT(rece_closeAll_sgin()));

        menu->addAction(action_reconnection);
        menu->addAction(action_copyTag);
        menu->addAction(action_close);
        menu->addAction(action_closeOther);
        menu->addAction(action_closeAll);
        menu->move(cursor().pos());
        menu->show();
    }
}

void sshwidgetmanagewidget::rece_reconnection_sgin()
{

}

void sshwidgetmanagewidget::rece_copyTag_sgin()
{

}

void sshwidgetmanagewidget::rece_close_sgin()
{

}

void sshwidgetmanagewidget::rece_closeOther_sgin()
{

}

void sshwidgetmanagewidget::rece_closeAll_sgin()
{

}


void sshwidgetmanagewidget::on_tabWidget_tabCloseRequested(int index)
{
   QString closeName = ui->tabWidget->tabText(index);
   ui->tabWidget->removeTab(index);
   //没释放内存
    if(ui->tabWidget->count() == 0) {
        //创建快速连接
        int8_t connectType = 0;
        //创建连接窗口
        QVector<connnectInfoStruct> cInfoStructList = db->ssh_getAllSSHInfo();
        qDebug() << "sshinfo 1 size = " << cInfoStructList.length();
        hcwidget = new historyconnectwidget(connectType, cInfoStructList, confInfo, this);
        connect(hcwidget,SIGNAL(send_fastConnection(connnectInfoStruct&)),this,SLOT(rece_fastConnection(connnectInfoStruct&)));
        connect(hcwidget,SIGNAL(send_findConnection(QString, int)),this,SLOT(rece_findConnection(QString, int)));
        QSize iconSize(20, 20); // 设置图标的大小
        ui->tabWidget->addTab(hcwidget, QIcon(":lib/kuaisu2.png").pixmap(iconSize), "快速连接");
        ui->tabWidget->setCurrentIndex(ui->tabWidget->count()-1);
        hcwidget->show();
    }
}

void sshwidgetmanagewidget::rece_fastConnection(connnectInfoStruct &cInfoStruct)
{
    //双击快速连接
    //按照昵称查
    connnectInfoStruct cInfo_ = db->ssh_getSSHInfoByName(cInfoStruct.name);
    int type = cInfoStruct.connectType;
    cInfoStruct = cInfo_;
    cInfoStruct.connectType = type;
    //cInfoStruct.password = cInfo_.password;
    if (cInfoStruct.sshType == SSH_PUBLICKEY) {
        sshKeyStruct sshKeyInfo = db->sshKey_getSSHKeyInfoByName(cInfoStruct.password);
        cInfoStruct.password = sshKeyInfo.password;
        cInfoStruct.publickey = sshKeyInfo.path;
    }
    //cInfoStruct.sshType = SSH_PASSWORD;
    QSize iconSize(16, 16); // 设置图标的大小
    qDebug() << "收到双击连接" << cInfoStruct.host << " " << cInfoStruct.password;
    if (cInfoStruct.connectType == SSH_CONNECT_TYPE) {
        //已经存在
        newSSHWidget(cInfoStruct, confInfo);
        // qDebug() << "调用ssh " << cInfoStruct.host << " " << cInfoStruct.password;
        // QString sign = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
        // sshwidget * sshWidget = new sshwidget(cInfoStruct, confInfo, cInfoStruct.name + sign);
        // connect(sshWidget,SIGNAL(send_toolButton_toolkit_sign()),this,SLOT(rece_widget_welcome_body_widget2_newCreate_newTool_clicked()));
        // connect(sshWidget,SIGNAL(send_toolButton_fullScreen_sign()),this,SLOT(rece_toolButton_fullScreen_sign()));
        // connect(sshWidget,SIGNAL(send_connection_success(sshwidget *)),this,SLOT(rece_connection_success(sshwidget *)));
        // connect(sshWidget,SIGNAL(send_connection_fail(sshwidget *)),this,SLOT(rece_connection_fail(sshwidget *)));
        // connect(sshWidget,SIGNAL(send_windowsSetting()),this,SLOT(rece_windowsSetting()));
        // sshWidgetList.push_back(sshWidget);
        // ui->tabWidget->addTab(sshWidget, QIcon(":lib/yellow.svg").pixmap(iconSize), cInfoStruct.name);
    }
}

void sshwidgetmanagewidget::rece_findConnection(QString text, int type)
{
    //和rece_fastConnection一样
    if (type == 0) {
        //昵称搜索
        connnectInfoStruct cInfoStruct;
        cInfoStruct.name = text;
        //先这么干
        rece_fastConnection(cInfoStruct);
    }
}

void sshwidgetmanagewidget::on_comboBox_tool_currentIndexChanged(int index)
{
    ui->stackedWidget_tool->setCurrentIndex(index);
}

void sshwidgetmanagewidget::on_lineEdit_hex_textChanged(const QString &arg1)
{
    if (ui->lineEdit_hex->hasFocus()) {
        bool ok;
        qint64 decimalValue = arg1.toLongLong(&ok, 16);
        if (ok) {
            ui->lineEdit_dec->setText(QString::number(decimalValue));
        }

        qint64 binaryValue = arg1.toLongLong(&ok, 16);
        if (ok) {
            QString binaryString = QString::number(binaryValue, 2);
            ui->lineEdit_bin->setText(binaryString);
        }

        qint64 octalValue = arg1.toLongLong(&ok, 16);
        if (ok) {
            QString octalString = QString::number(octalValue, 8);
            ui->lineEdit_oct->setText(octalString);
        }
    }
}

void sshwidgetmanagewidget::on_lineEdit_dec_textChanged(const QString &arg1)
{
    if (ui->lineEdit_dec->hasFocus()) {
        qint64 decimalValue = arg1.toLongLong();
        QString binaryString = QString::number(decimalValue, 2);
        QString octalString = QString::number(decimalValue, 8);
        QString hexadecimalString = QString::number(decimalValue, 16);
        ui->lineEdit_hex->setText(hexadecimalString);
        ui->lineEdit_oct->setText(octalString);
        ui->lineEdit_bin->setText(binaryString);
    }
}

void sshwidgetmanagewidget::on_lineEdit_oct_textChanged(const QString &arg1)
{
    if (ui->lineEdit_oct->hasFocus()) {
        bool ok;
        qint64 decimalValue = arg1.toLongLong(&ok, 8);
        if (ok) {
            ui->lineEdit_dec->setText(QString::number(decimalValue));
        }

        qint64 binaryValue = arg1.toLongLong(&ok, 8);
        if (ok) {
            QString binaryString = QString::number(binaryValue, 2);
            ui->lineEdit_bin->setText(binaryString);
        }

        qint64 heximalValue = arg1.toLongLong(&ok, 8);
        if (ok) {
            QString octalString = QString::number(heximalValue, 16);
            ui->lineEdit_hex->setText(octalString);
        }
    }
}

void sshwidgetmanagewidget::on_lineEdit_bin_textChanged(const QString &arg1)
{
    if (ui->lineEdit_bin->hasFocus()) {
        bool ok;
        qint64 binaryValue = arg1.toLongLong(&ok, 2);
        if (ok) {
            ui->lineEdit_dec->setText(QString::number(binaryValue));
        }

        qint64 heximalValue = arg1.toLongLong(&ok, 2);
        if (ok) {
            QString hexString = QString::number(heximalValue, 16);
            ui->lineEdit_hex->setText(hexString);
        }

        qint64 octalValue = arg1.toLongLong(&ok, 2);
        if (ok) {
            QString octalString = QString::number(octalValue, 8);
            ui->lineEdit_oct->setText(octalString);
        }
    }
}

void sshwidgetmanagewidget::on_toolButton_decode_clicked()
{
    //解码
    QString url = ui->lineEdit_encode_in->text();
    QString decodedUrl = QUrl::fromPercentEncoding(url.toUtf8());
    ui->lineEdit_decode_out->setText(decodedUrl);
}

void sshwidgetmanagewidget::on_toolButton_encode_clicked()
{
    //编码
    QString url = ui->lineEdit_encode_in->text();
    QString encodedUrl = QUrl::toPercentEncoding(url);
    ui->lineEdit_decode_out->setText(encodedUrl);
}

void sshwidgetmanagewidget::rece_showtimestamp()
{
    // 获取当前时间
    QDateTime currentTime = QDateTime::currentDateTime();

    // 将时间转换为时间戳（秒数）
    qint64 timestamp = currentTime.toSecsSinceEpoch();

    // 将时间戳转换为字符串
    QString timestampStr = QString::number(timestamp);

    // 在标签上显示时间戳
    ui->lineEdit_now_timestamp->setText(timestampStr);

}

void sshwidgetmanagewidget::on_toolButton_time2date_clicked()
{
    QString in = ui->lineEdit_time2date_in->text();
    qint64 timestamp = in.toLongLong();
    if (ui->comboBox_time2date->currentIndex() == 0) {
        //秒
        QDateTime dateTime = QDateTime::fromSecsSinceEpoch(timestamp);

        // 将 QDateTime 对象格式化为日期字符串
        QString dateString = dateTime.toString("yyyy-MM-dd hh:mm:ss");
        ui->lineEdit_time2date_out->setText(dateString);
    } else {
        //毫秒
        QDateTime dateTime = QDateTime::fromMSecsSinceEpoch(timestamp);
        QString dateString = dateTime.toString("yyyy-MM-dd hh:mm:ss");
        ui->lineEdit_time2date_out->setText(dateString);
    }
}

void sshwidgetmanagewidget::on_toolButton_date2time_clicked()
{
    QString in = ui->lineEdit_date2time_in->text();
    if (ui->comboBox_date2time->currentIndex() == 0) {
        //秒
        QDateTime dateTime = QDateTime::fromString(in, "yyyy-MM-dd hh:mm:ss");
        qint64 secondsTimestamp = dateTime.toSecsSinceEpoch();
        ui->lineEdit_date2time_out->setText(QString::number(secondsTimestamp));
    } else {
        //毫秒
        QDateTime dateTime = QDateTime::fromString(in, "yyyy-MM-dd hh:mm:ss");
        qint64 millisecondsTimestamp = dateTime.toMSecsSinceEpoch();
        ui->lineEdit_date2time_out->setText(QString::number(millisecondsTimestamp));
    }
}

void sshwidgetmanagewidget::on_toolButton_timestamp_copy_clicked()
{
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(ui->lineEdit_now_timestamp->text());
}

void sshwidgetmanagewidget::on_toolButton_closetool_clicked()
{
    ui->widget_tool->hide();
    isShowToolKit = false;
}

void sshwidgetmanagewidget::rece_updateMouseStyle() {
    //设置为箭头
    setCursor(Qt::ArrowCursor);
}