/*
   Copyright 2023 花狗Fdog(张旭)
   
   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/
#pragma execution_character_set("utf-8")
#include "zookeepermanagewidget.h"
#include "ui_zookeepermanagewidget.h"
#include <QUrl>
#include <QDesktopServices>
#include <QGraphicsDropShadowEffect>
#include "module_utils/utils.h"

zookeepermanagewidget::zookeepermanagewidget(QWidget *parent) :
    QWidget(parent), ui(new Ui::zookeepermanagewidget) {
    ui->setupUi(this);
    //切换至欢迎页
    ui->stackedWidget->setCurrentIndex(0);
    m_buttonGroup = new QButtonGroup(this);
    //设置按钮互斥
    m_buttonGroup->setExclusive(true);
    connect(m_buttonGroup, SIGNAL(buttonClicked(int)), this, SLOT(rece_buttonClicked(int)));
    //初始化数据库信息
    initDBInfo();
    //设置鼠标跟踪
    setSupportStretch(this, true);
}

zookeepermanagewidget::zookeepermanagewidget(connnectInfoStruct &cInfoStruct, QWidget *parent) :
    QWidget(parent), ui(new Ui::zookeepermanagewidget) {
    ui->setupUi(this);
    //切换至欢迎页
    ui->stackedWidget->setCurrentIndex(0);
    m_buttonGroup = new QButtonGroup(this);
    //设置按钮互斥
    m_buttonGroup->setExclusive(true);
    connect(m_buttonGroup, SIGNAL(buttonClicked(int)), this, SLOT(rece_buttonClicked(int)));
    //初始化数据库信息
    initDBInfo();
    //创建连接
    newZKWidget(cInfoStruct);
    //设置鼠标跟踪
    setSupportStretch(this, true);
}

zookeepermanagewidget::~zookeepermanagewidget() {
    delete ui;
}

void zookeepermanagewidget::initDBInfo() {
    //初始化数据库
    db = new zookeepersql();
    //获取数据库已经存在的zk连接信息
    QVector<zkInfoStruct> zkInfoList =  db->zk_getAllZkInfo();
    for (int i = 0; i <zkInfoList.length();i++) {
        QString data = zkInfoList[i].host + ":" + zkInfoList[i].port;
        //只创建按钮,不创建连接
        createButton(data);
    }
}

void zookeepermanagewidget::newZKWidget(connnectInfoStruct &cInfoStruct) {
    QString data = cInfoStruct.host + ":" + cInfoStruct.port;
    zkInfoStruct zkInfo;
    zkInfo.name = "测试";
    zkInfo.host = cInfoStruct.host;
    zkInfo.port = cInfoStruct.port;
    db->zk_insertZkInfo(zkInfo);
    cInfoStruct.buttonSid = count;
    qDebug() << "cInfoStruct.buttonSid = " << cInfoStruct.buttonSid;
    zookeeperwidget * zkWidget = new zookeeperwidget(cInfoStruct);
    connect(zkWidget, SIGNAL(send_init(int, int)), this, SLOT(rece_init(int, int)));
    ui->stackedWidget->addWidget(zkWidget);
    connectManager.insert(count-1, ui->stackedWidget->count()-1);
    ui->stackedWidget->setCurrentIndex(ui->stackedWidget->count()-1);
    createButton(data, true, zkWidget);
}

void zookeepermanagewidget::createButton(QString text, bool isConnect, zookeeperwidget * zkWidget) {
    QToolButton * qbutton = new QToolButton(this);
    if (isConnect) {
        qbutton->setIcon(QIcon(":lib/yellow.svg"));
        qDebug() << "显示黄色 count = " << count;
    } else {
        qbutton->setIcon(QIcon(":lib/grey.svg"));
    }
    qbutton->setText(text);
    qbutton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    qbutton->setMinimumHeight(50);
    qbutton->setMinimumWidth(180);
    qbutton->setMaximumWidth(180);
    qbutton->setCheckable(true);
    m_buttonGroup->addButton(qbutton, count++);
    QVBoxLayout *layout = (QVBoxLayout *)ui->scrollAreaWidgetContents->layout();
    layout->insertWidget(layout->count()-1, qbutton);
    m_buttonGroup->button(count-1)->setChecked(true);
    zkStatusInfoMap[qbutton].status_ = 1;
    zkStatusInfoMap[qbutton].zkWidget_ =zkWidget;
    qbutton->setContextMenuPolicy(Qt::CustomContextMenu);
    QMenu * menu = new QMenu(qbutton);
    menu->setWindowFlags(menu->windowFlags()  | Qt::FramelessWindowHint | Qt::NoDropShadowWindowHint);
    menu->setAttribute(Qt::WA_TranslucentBackground);
    QAction *againAction = new QAction(tr("重连"), qbutton);
    QAction *closeAction = new QAction(tr("关闭"), qbutton);
    QAction *clearAction = new QAction(tr("删除"), qbutton);
    menu->addAction(closeAction);
    menu->addAction(clearAction);
    qbutton->setContextMenuPolicy(Qt::CustomContextMenu);
    qbutton->setMenu(menu);
    QObject::connect(againAction, &QAction::triggered, this, [=](){
        QToolButton* button_ =qobject_cast<QToolButton*>(sender()->parent());
        QStringList dataList;
        if (button_ != NULL) {
            dataList = button_->text().split(":");
        }
    });

    QObject::connect(closeAction, &QAction::triggered, this, [=](){
        QToolButton* button_ =qobject_cast<QToolButton*>(sender()->parent());
        QStringList dataList;
        if (button_ != NULL) {
            dataList = button_->text().split(":");
        }
        delete zkWidget;
        ui->stackedWidget->setCurrentIndex(0);
        zkStatusInfoMap[qbutton].status_ = 2;
        zkStatusInfoMap[qbutton].zkWidget_ =nullptr;
        qbutton->setIcon(QIcon(":lib/grey.svg"));//灰色
    });

    QObject::connect(clearAction, &QAction::triggered, this, [=](){
        QToolButton* button_ =qobject_cast<QToolButton*>(sender()->parent());
        QStringList dataList;
        if (button_ != NULL) {
            dataList = button_->text().split(":");
        }
        zkInfoStruct zkInfo;
        zkInfo.host = dataList[0];
        zkInfo.port = dataList[1];
        db->zk_deleteZkInfo(zkInfo);
        delete zkWidget;
        ui->stackedWidget->setCurrentIndex(0);
        zkStatusInfoMap[qbutton].status_ = 2;
        zkStatusInfoMap[qbutton].zkWidget_ =nullptr;
        m_buttonGroup->removeButton(button_);
        delete(button_);
    });

    QObject::connect(qbutton, &QToolButton::customContextMenuRequested, this, [=]()
    {
        menu->move(cursor().pos());
        menu->show();           //记录button对应的连接和状态
        zkStatusInfoMap[qbutton].status_ = 2;
        zkStatusInfoMap[qbutton].zkWidget_ = zkWidget;
    });
}

void zookeepermanagewidget::changeMainWindowTheme(bool isChange, int windowsType) {
    if (isChange) {
        mode = (mode + 1) % 3;
    }
    if (mode == DARK_THEME) {
        style()->unpolish(ui->widget_left);
        ui->widget_left->setStyleSheet("");
        ui->widget_left->setStyleSheet(getStyleFile(":/module_zookeeper/qss/main-dark.qss"));
        style()->polish(ui->widget_left);
    } else if (mode == LIGHT_THEME) {
        style()->unpolish(ui->widget_left);
        ui->widget_left->setStyleSheet("");
        ui->widget_left->setStyleSheet(getStyleFile(":/module_zookeeper/qss/main-light.qss"));
        style()->polish(ui->widget_left);
    } else if (mode == BLUE_THEME) {
        style()->unpolish(ui->widget_left);
        ui->widget_left->setStyleSheet("");
        ui->widget_left->setStyleSheet(getStyleFile(":/module_zookeeper/qss/main-blue.qss"));
        style()->polish(ui->widget_left);
    }
}

void zookeepermanagewidget::changeMainWindowRadius(int windowsType) {
    //不需要
}

void zookeepermanagewidget::on_toolButton_newCreate_clicked() {
    ui->stackedWidget->setCurrentIndex(1);
}

void zookeepermanagewidget::on_toolButton_save_clicked() {
    QString data = ui->lineEdit_host_zk_data->text() + ":" + ui->lineEdit_port_zk_data->text();
    createButton(data, false);
}

void zookeepermanagewidget::on_toolButton_close_clicked() {
    //切回主界面
    ui->stackedWidget->setCurrentIndex(0);
}

void zookeepermanagewidget::on_toolButton_connect_clicked() {
    connnectInfoStruct cInfoStruct;
    cInfoStruct.host = ui->lineEdit_host_zk_data->text();
    cInfoStruct.port = ui->lineEdit_port_zk_data->text();
    cInfoStruct.timeout = 5000;
    newZKWidget(cInfoStruct);
}

void zookeepermanagewidget::on_toolButton_clicked() {
    QDesktopServices::openUrl(QUrl(QLatin1String("https://github.com/HuaGouFdog/Fdog-Kit")));
}

void zookeepermanagewidget::rece_init(int buttonSid, int code) {
    qDebug() << "rece_init buttonSid = " << buttonSid;
    if (code == ZOK) {
        m_buttonGroup->button(buttonSid)->setIcon(QIcon(":lib/green.svg"));//绿色
        qDebug() << "显示绿色";
        zkStatusInfoMap[m_buttonGroup->checkedButton()].status_ = 0;
    } else {
        m_buttonGroup->button(buttonSid)->setIcon(QIcon(":lib/grey.svg")); //灰色
        zkStatusInfoMap[m_buttonGroup->checkedButton()].status_ = 3;
        connectManager.remove(buttonSid);
    }
}

void zookeepermanagewidget::rece_buttonClicked(int index) {
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
    //只有0才是成功
    if (zkStatusInfoMap[m_buttonGroup->checkedButton()].status_ == 0) {
        int widgetCount = ui->stackedWidget->count();
        for (int i = 0; i < widgetCount; ++i) {
            // 获取索引处的widget
            zookeeperwidget* widget =qobject_cast<zookeeperwidget*>(ui->stackedWidget->widget(i));
            if (widget) {
                if (widget == zkStatusInfoMap[m_buttonGroup->checkedButton()].zkWidget_) {
                    ui->stackedWidget->setCurrentIndex(i);
                    return;
                }
            }
        }
    }
        //创建连接
        m_buttonGroup->checkedButton()->setIcon(QIcon(":lib/yellow.svg"));//黄色
        qDebug() << "显示黄色 index = " << index;
        zookeeperwidget * zkWidget = new zookeeperwidget(cInfoStruct);
        connect(zkWidget, SIGNAL(send_init(int, int)), this, SLOT(rece_init(int, int)));

        ui->stackedWidget->addWidget(zkWidget);
        connectManager.insert(index, ui->stackedWidget->count()-1);
        ui->stackedWidget->setCurrentIndex(ui->stackedWidget->count()-1);
        zkStatusInfoMap[m_buttonGroup->checkedButton()].status_ = 1;
        zkStatusInfoMap[m_buttonGroup->checkedButton()].zkWidget_ =zkWidget;
}