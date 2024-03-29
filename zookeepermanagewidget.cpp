﻿#pragma execution_character_set("utf-8")
#include "zookeepermanagewidget.h"
#include "ui_zookeepermanagewidget.h"
#include <QDesktopServices>
#include <QUrl>
zookeepermanagewidget::zookeepermanagewidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::zookeepermanagewidget)
{
    ui->setupUi(this);
    lastIndex = 0;
    count = 0;
    m_buttonGroup = new QButtonGroup(this);
    m_buttonGroup->setExclusive(true);
    connect(m_buttonGroup, SIGNAL(buttonClicked(int)), this, SLOT(rece_buttonClicked(int)));
    //只是创建一个界面
    zookeeperwidget * zkWidget = new zookeeperwidget();
    ui->stackedWidget->addWidget(zkWidget);
}

zookeepermanagewidget::zookeepermanagewidget(connnectInfoStruct &cInfoStruct, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::zookeepermanagewidget)
{
    ui->setupUi(this);
    lastIndex = 0;
    count = 0;
    m_buttonGroup = new QButtonGroup(this);
    m_buttonGroup->setExclusive(true);
    connect(m_buttonGroup, SIGNAL(buttonClicked(int)), this, SLOT(rece_buttonClicked(int)));
    //保存
    QString data = cInfoStruct.host + ":" + cInfoStruct.port;
    QToolButton * qbutton = new QToolButton(this);
    qbutton->setIcon(QIcon(":lib/node2.png"));
    qbutton->setText(data);
    qbutton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    qbutton->setMinimumHeight(50);
    qbutton->setMinimumWidth(180);
    qbutton->setCheckable(true);
    m_buttonGroup->addButton(qbutton, count++);
    QVBoxLayout *layout = (QVBoxLayout *)ui->scrollAreaWidgetContents->layout();
    layout->insertWidget(layout->count()-1, qbutton);
    //连接
    cInfoStruct.buttonSid = count-1;
    cInfoStruct.timeout = 5000;
    qbutton->setIcon(QIcon(":lib/node3.png"));//黄色
    zookeeperwidget * zkWidget = new zookeeperwidget(cInfoStruct);
    connect(zkWidget, SIGNAL(send_init(int, int)), this, SLOT(rece_init(int, int)));
    ui->stackedWidget->addWidget(zkWidget);
    connectManager.insert(count-1, ui->stackedWidget->count()-1);
    ui->stackedWidget->setCurrentIndex(ui->stackedWidget->count()-1);
    m_buttonGroup->button(count-1)->setChecked(true);
}

void zookeepermanagewidget::newCreate(connnectInfoStruct &cInfoStruct)
{
    //保存
    QString data = cInfoStruct.host + ":" + cInfoStruct.port;
    QToolButton * qbutton = new QToolButton(this);
    qbutton->setIcon(QIcon(":lib/node2.png"));
    qbutton->setText(data);
    qbutton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    qbutton->setMinimumHeight(50);
    qbutton->setMinimumWidth(180);
    qbutton->setCheckable(true);
    m_buttonGroup->addButton(qbutton, count++);
    QVBoxLayout *layout = (QVBoxLayout *)ui->scrollAreaWidgetContents->layout();
    layout->insertWidget(layout->count()-1, qbutton);
    //连接
    cInfoStruct.buttonSid = count-1;
    cInfoStruct.timeout = 5000;
    qbutton->setIcon(QIcon(":lib/node3.png"));//黄色
    zookeeperwidget * zkWidget = new zookeeperwidget(cInfoStruct);
    connect(zkWidget, SIGNAL(send_init(int, int)), this, SLOT(rece_init(int, int)));
    ui->stackedWidget->addWidget(zkWidget);
    connectManager.insert(count-1, ui->stackedWidget->count()-1);
    ui->stackedWidget->setCurrentIndex(ui->stackedWidget->count()-1);
    m_buttonGroup->button(count-1)->setChecked(true);
}

zookeepermanagewidget::~zookeepermanagewidget()
{
    delete ui;
}

void zookeepermanagewidget::on_toolButton_newCreate_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void zookeepermanagewidget::on_toolButton_save_clicked()
{
    //保存
    QString data = ui->lineEdit_host_zk_data->text() + ":" + ui->lineEdit_port_zk_data->text();
    QToolButton * qbutton = new QToolButton(this);
    qbutton->setIcon(QIcon(":lib/node2.png"));
    qbutton->setText(data);
    qbutton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    qbutton->setMinimumHeight(50);
    qbutton->setMinimumWidth(180);
    qbutton->setCheckable(true);
    m_buttonGroup->addButton(qbutton, count++);
    QVBoxLayout *layout = (QVBoxLayout *)ui->scrollAreaWidgetContents->layout();
    layout->insertWidget(layout->count()-1, qbutton);
    ui->stackedWidget->setCurrentIndex(lastIndex);
}

void zookeepermanagewidget::on_toolButton_close_clicked()
{
    //取消
    ui->stackedWidget->setCurrentIndex(0);
}

void zookeepermanagewidget::on_toolButton_connect_clicked()
{
    //保存
    QString data = ui->lineEdit_host_zk_data->text() + ":" + ui->lineEdit_port_zk_data->text();
    QToolButton * qbutton = new QToolButton(this);
    qbutton->setIcon(QIcon(":lib/node2.png"));
    qbutton->setText(data);
    qbutton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    qbutton->setMinimumHeight(50);
    qbutton->setMinimumWidth(180);
    qbutton->setCheckable(true);
    m_buttonGroup->addButton(qbutton, count++);
    QVBoxLayout *layout = (QVBoxLayout *)ui->scrollAreaWidgetContents->layout();
    layout->insertWidget(layout->count()-1, qbutton);
    //连接
    connnectInfoStruct cInfoStruct;
    cInfoStruct.host = ui->lineEdit_host_zk_data->text();
    cInfoStruct.port = ui->lineEdit_port_zk_data->text();
    cInfoStruct.buttonSid = count-1;
    cInfoStruct.timeout = 5000;
    qbutton->setIcon(QIcon(":lib/node3.png"));//黄色
    zookeeperwidget * zkWidget = new zookeeperwidget(cInfoStruct);
    connect(zkWidget, SIGNAL(send_init(int, int)), this, SLOT(rece_init(int, int)));
    ui->stackedWidget->addWidget(zkWidget);
    connectManager.insert(count-1, ui->stackedWidget->count()-1);
    ui->stackedWidget->setCurrentIndex(ui->stackedWidget->count()-1);
    m_buttonGroup->button(count-1)->setChecked(true);
}

void zookeepermanagewidget::rece_buttonClicked(int index)
{
    //被点击按钮 创建连接
    QString buttonText = m_buttonGroup->checkedButton()->text();
    int index2 = buttonText.indexOf(":");
    QString host = buttonText.mid(0, index2);
    QString port = buttonText.mid(index2+1);
    connnectInfoStruct cInfoStruct;
    cInfoStruct.host = host;
    cInfoStruct.port = port;
    cInfoStruct.buttonSid = index;
    cInfoStruct.timeout = 5000;
    qDebug() << index;
    //判断index有没有连接，没有则连接，有则跳转
    bool isok = connectManager.contains(index);
    if (isok) {
        ui->stackedWidget->setCurrentIndex(connectManager.value(index));
    } else {
        m_buttonGroup->checkedButton()->setIcon(QIcon(":lib/node3.png"));//黄色

        zookeeperwidget * zkWidget = new zookeeperwidget(cInfoStruct);
        connect(zkWidget, SIGNAL(send_init(int, int)), this, SLOT(rece_init(int, int)));

        ui->stackedWidget->addWidget(zkWidget);
        connectManager.insert(index, ui->stackedWidget->count()-1);
        ui->stackedWidget->setCurrentIndex(ui->stackedWidget->count()-1);
    }
}

void zookeepermanagewidget::rece_init(int buttonSid, int code)
{
    if (code == ZOK) {
        m_buttonGroup->button(buttonSid)->setIcon(QIcon(":lib/node.png"));//绿色
    } else {
        m_buttonGroup->button(buttonSid)->setIcon(QIcon(":lib/node2.png")); //灰色
        //移除
        connectManager.remove(buttonSid);
    }
}

void zookeepermanagewidget::on_toolButton_clicked()
{
    QDesktopServices::openUrl(QUrl(QLatin1String("https://github.com/HuaGouFdog/Fdog-Kit")));
}
