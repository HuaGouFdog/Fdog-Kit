#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsDropShadowEffect>
#include <QColor>
#include <QMouseEvent>
#include <QPushButton>
#include <QMenuBar>
#include <QMenu>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //透明背景
    this->setAttribute(Qt::WA_TranslucentBackground);
    //设置无边框
    setWindowFlag(Qt::FramelessWindowHint);
    //设置内边距
    setContentsMargins(10, 10, 10, 10);
    //设置阴影效果
    defaultShadow = new QGraphicsDropShadowEffect();
    //模糊半径
    defaultShadow->setBlurRadius(15.0);
    //颜色值
    defaultShadow->setColor(QColor(0, 0, 0, 250));
    //横纵偏移量
    defaultShadow->setOffset(0, 0);
    //不要直接给this，会报UpdateLayeredWindowIndirect failed
    ui->centralWidget->setGraphicsEffect(defaultShadow);

    //创建菜单栏及相关菜单
    men = new QMenu();
    men->setStyleSheet("QMenu{background-color: rgb(67, 77, 88); font: 10pt \"OPPOSans B\"; color: rgb(255, 255, 255); border:1px solid rgb(255, 255, 255,200);} "
                       "QMenu::item:selected {background-color: #0B0E11;}");
    ssh = new QAction(QIcon(":lib/powershell.png"), "ssh连接");
    men->addAction(ssh);
    zk = new QAction(QIcon(":lib/Zookeeper.png"), "zk连接");
    men->addAction(zk);
    kafka = new QAction(QIcon(":lib/Kafka.png"), "kafka连接");
    men->addAction(kafka);
    redis = new QAction(QIcon(":lib/Redis.png"), "redis连接");
    men->addAction(redis);
    db = new QAction(QIcon(":lib/db.png"), "database连接");
    men->addAction(db);
    //将选项添加到新建按钮下
    ui->toolButton_newCreate->setMenu(men);

    //添加信号
    connect(ssh, SIGNAL(triggered()), this, SLOT(on_newCreate()));
    connect(zk, SIGNAL(triggered()), this, SLOT(on_newCreate()));
    connect(kafka, SIGNAL(triggered()), this, SLOT(on_newCreate()));
    connect(redis, SIGNAL(triggered()), this, SLOT(on_newCreate()));
    connect(db, SIGNAL(triggered()), this, SLOT(on_newCreate()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(ui->widget_title->underMouse() && !showFlag) {
        isPressedWidget = true; // 当前鼠标按下的即是QWidget而非界面上布局的其它控件
    }
    last = event->globalPos();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (isPressedWidget)
        {
            int dx = event->globalX() - last.x();
            int dy = event->globalY() - last.y();
            last = event->globalPos();
            move(x()+dx, y()+dy);
        }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    isPressedWidget = false; // 鼠标松开时，置为false
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(ui->widget_title->underMouse() && !showFlag) {
        setContentsMargins(0, 0, 0, 0);
        ui->centralWidget->setStyleSheet("QMainWindow,QWidget#centralWidget {background-color: rgb(67, 77, 88);border-radius:0px;}");
        ui->toolButton_max->setIcon(QIcon(":lib/icon-copy.png"));
        this->showMaximized();
        showFlag = true;
    } else if (ui->widget_title->underMouse() && showFlag) {
        setContentsMargins(10, 10, 10, 10);
        ui->centralWidget->setStyleSheet("QMainWindow,QWidget#centralWidget {background-color: rgb(67, 77, 88);border-radius:6px;}");
        ui->toolButton_max->setIcon(QIcon(":lib/Icon_max2.png"));
        this->showNormal();
        showFlag = false;
    }
}

void MainWindow::newConnectZk(QString name, QString host, QString port)
{

}

void MainWindow::on_toolButton_close_clicked()
{
    //关闭
    this->close();
}

void MainWindow::on_toolButton_min_clicked()
{
    //最小化
    this->showMinimized();
}

void MainWindow::on_toolButton_max_clicked()
{
    //最大化
    if (!showFlag) {
        setContentsMargins(0, 0, 0, 0);
        ui->centralWidget->setStyleSheet("QMainWindow,QWidget#centralWidget {background-color: rgb(67, 77, 88);border-radius:0px;}");
        ui->toolButton_max->setIcon(QIcon(":lib/icon-copy.png"));
        this->showMaximized();
        showFlag = true;
    } else {
        setContentsMargins(10, 10, 10, 10);
        ui->centralWidget->setStyleSheet("QMainWindow,QWidget#centralWidget {background-color: rgb(67, 77, 88);border-radius:6px;}");
        ui->toolButton_max->setIcon(QIcon(":lib/Icon_max2.png"));
        this->showNormal();
        showFlag = false;
    }
}

void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    ui->tabWidget->removeTab(index);
}

void MainWindow::on_newCreate()
{
    if (ccwidget == nullptr) {
        //获取发送者
        QString actionText = qobject_cast<QAction*>(sender())->text();
        int8_t connectType = 0;
        if (actionText == "ssh连接") {
            connectType =SSH_CONNECT_TYPE;
        } else if (actionText == "zk连接") {
            connectType =ZK_CONNECT_TYPE;
        } else if (actionText == "redis连接") {
            connectType =REDIS_CONNECT_TYPE;
        } else if (actionText == "kafka连接") {
            connectType =KAFKA_CONNECT_TYPE;
        } else if (actionText == "database连接") {
            connectType =DB_CONNECT_TYPE;
        }

        //创建连接窗口
        ccwidget = new createconnect(connectType);
        connect(ccwidget,SIGNAL(newCreate(connnectInfoStruct&)),this,SLOT(on_newConnnect(connnectInfoStruct&)));
        connect(ccwidget,SIGNAL(newClose()),this,SLOT(on_newClose()));
        ccwidget->show();
    } else {
        //不创建
        ccwidget->setFocus();
    }

}

void MainWindow::on_newConnnect(connnectInfoStruct& cInfoStruct)
{
    qDebug() << cInfoStruct.connectType;
    QSize iconSize(14, 14); // 设置图标的大小

    if (cInfoStruct.connectType == SSH_CONNECT_TYPE) {

    } else if (cInfoStruct.connectType == ZK_CONNECT_TYPE) {
        zookeeperwidget * zkWidget = new zookeeperwidget(cInfoStruct);
        zkWidgetList.push_back(zkWidget);
        ui->tabWidget->addTab(zkWidget, QIcon(":lib/Zookeeper.png").pixmap(iconSize), cInfoStruct.name);
    } else if (cInfoStruct.connectType == REDIS_CONNECT_TYPE) {
        //ui->tabWidget->addTab(&zkwidget4, QIcon(":lib/Redis.png").pixmap(iconSize), "172.16.8.153");
    } else if (cInfoStruct.connectType == KAFKA_CONNECT_TYPE) {
        //ui->tabWidget->addTab(&zkwidget3, QIcon(":lib/Kafka.png").pixmap(iconSize), "172.16.8.157");
    } else if (cInfoStruct.connectType == DB_CONNECT_TYPE) {
        //ui->tabWidget->addTab(&zkwidget2, QIcon(":lib/db.png").pixmap(iconSize), "172.16.8.166");
    }

    ui->tabWidget->setCurrentIndex(ui->tabWidget->count()-1);

    //null
    ccwidget = nullptr;
}

void MainWindow::on_newClose()
{
    //null
    //delete(ccwidget);
    ccwidget = nullptr;
}
