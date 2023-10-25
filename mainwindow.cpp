#pragma execution_character_set("utf-8")
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsDropShadowEffect>
#include <QColor>
#include <QMouseEvent>
#include <QPushButton>
#include <QMenuBar>
#include <QMenu>
#include <QDebug>
#include <QPropertyAnimation>
#include <QScreen>
#include <QCoreApplication>
#include <QTimer>
#include <QDateTime>
#include <QClipboard>
#include "smalltoolwidget.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //透明背景
    this->setAttribute(Qt::WA_TranslucentBackground);
    //设置无边框
    setWindowFlag(Qt::FramelessWindowHint);
    //setWindowFlags(windowFlags()|Qt::FramelessWindowHint);
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

    isPressedWidget = false;
    m_isMousePressed = false;

    setSupportStretch(true);

    //创建菜单栏及相关菜单
//    men = new QMenu();
//    men->setStyleSheet("QMenu{background-color: rgb(67, 77, 88); font: 10pt \"OPPOSans B\"; color: rgb(255, 255, 255); border:1px solid rgb(255, 255, 255,200);} "
//                       "QMenu::item:selected {background-color: #0B0E11;}");
//    ssh = new QAction(QIcon(":lib/powershell.png"), "ssh连接");
//    men->addAction(ssh);
//    zk = new QAction(QIcon(":lib/Zookeeper.png"), "zk连接");
//    men->addAction(zk);
//    kafka = new QAction(QIcon(":lib/Kafka.png"), "kafka连接");
//    men->addAction(kafka);
//    redis = new QAction(QIcon(":lib/Redis.png"), "redis连接");
//    men->addAction(redis);
//    db = new QAction(QIcon(":lib/db.png"), "database连接");
//    men->addAction(db);
//    //将选项添加到新建按钮下
//    ui->toolButton_newCreate->setMenu(men);

    //添加信号
//    connect(ssh, SIGNAL(triggered()), this, SLOT(on_newCreate()));
//    connect(zk, SIGNAL(triggered()), this, SLOT(on_newCreate()));
//    connect(kafka, SIGNAL(triggered()), this, SLOT(on_newCreate()));
//    connect(redis, SIGNAL(triggered()), this, SLOT(on_newCreate()));
//    connect(db, SIGNAL(triggered()), this, SLOT(on_newCreate()));


    men_tool = new QMenu();
    men_tool->setStyleSheet("QMenu{background-color: rgb(67, 77, 88); font: 10pt \"OPPOSans B\"; color: rgb(255, 255, 255); border:1px solid rgb(255, 255, 255,200);} "
                       "QMenu::item:selected {background-color: #0B0E11;}");

    jsonFormat = new QAction(QIcon(":lib/powershell.png"), "JSON格式化");
    men_tool->addAction(jsonFormat);
    xmlFormat = new QAction(QIcon(":lib/powershell.png"), "XML格式化");
    men_tool->addAction(xmlFormat);
    textDiff = new QAction(QIcon(":lib/powershell.png"), "文本对比");
    men_tool->addAction(textDiff);
    toolAssemble = new QAction(QIcon(":lib/powershell.png"), "小工具集合");
    men_tool->addAction(toolAssemble);
    ui->toolButton_tool->setMenu(men_tool);

    connect(jsonFormat, SIGNAL(triggered()), this, SLOT(on_newTool()));
    connect(xmlFormat, SIGNAL(triggered()), this, SLOT(on_newTool()));
    connect(textDiff, SIGNAL(triggered()), this, SLOT(on_newTool()));
    connect(toolAssemble, SIGNAL(triggered()), this, SLOT(on_newTool()));

    ui->widget_line->hide();
    ui->stackedWidget->setCurrentIndex(2);

    ui->widget_welcome_body_widget2_info_text->hide();

    //smalltoolwidget * a = new smalltoolwidget(ui->widget_4);
    //a->show();

    // 创建定时器
    QTimer * timer = new QTimer();

    // 设置定时器的间隔为1000毫秒（1秒）
    timer->setInterval(1000);

    // 连接定时器的timeout()信号到槽函数
    connect(timer,SIGNAL(timeout()), this,
                            SLOT(rece_showtimestamp()));
    // 启动定时器
    timer->start();

    ui->widget_4->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::calculateCurrentStrechRect()
{

    // 四个角Rect;
    m_leftTopRect = QRect(0, 0, STRETCH_RECT_WIDTH, STRETCH_RECT_HEIGHT);
    m_leftBottomRect = QRect(0, this->height() - STRETCH_RECT_HEIGHT, STRETCH_RECT_WIDTH, STRETCH_RECT_WIDTH);
    m_rightTopRect = QRect(this->width() - STRETCH_RECT_WIDTH, 0, STRETCH_RECT_WIDTH, STRETCH_RECT_HEIGHT);
    m_rightBottomRect = QRect(this->width() - STRETCH_RECT_WIDTH, this->height() - STRETCH_RECT_HEIGHT, STRETCH_RECT_WIDTH, STRETCH_RECT_HEIGHT);

    // 四条边Rect;
    m_topBorderRect = QRect(STRETCH_RECT_WIDTH, 0, this->width() - STRETCH_RECT_WIDTH * 2, STRETCH_RECT_HEIGHT);
    m_rightBorderRect = QRect(this->width() - STRETCH_RECT_WIDTH, STRETCH_RECT_HEIGHT, STRETCH_RECT_WIDTH, this->height() - STRETCH_RECT_HEIGHT * 2);
    m_bottomBorderRect = QRect(STRETCH_RECT_WIDTH, this->height() - STRETCH_RECT_HEIGHT, this->width() - STRETCH_RECT_WIDTH * 2, STRETCH_RECT_HEIGHT);
    m_leftBorderRect = QRect(0, STRETCH_RECT_HEIGHT, STRETCH_RECT_WIDTH, this->height() - STRETCH_RECT_HEIGHT * 2);
}

WindowStretchRectState MainWindow::getCurrentStretchState(QPoint cursorPos)
{
    //qDebug() << "触发getCurrentStretchState ="<< cursorPos;
    WindowStretchRectState stretchState;
    if (m_leftTopRect.contains(cursorPos))
    {
        stretchState = LEFT_TOP_RECT;
    }
    else if (m_rightTopRect.contains(cursorPos))
    {
        stretchState = RIGHT_TOP_RECT;
    }
    else if (m_rightBottomRect.contains(cursorPos))
    {
        stretchState = RIGHT_BOTTOM_RECT;
    }
    else if (m_leftBottomRect.contains(cursorPos))
    {
        stretchState = LEFT_BOTTOM_RECT;
    }
    else if (m_topBorderRect.contains(cursorPos))
    {
        stretchState = TOP_BORDER;
    }
    else if (m_rightBorderRect.contains(cursorPos))
    {
        stretchState = RIGHT_BORDER;
    }
    else if (m_bottomBorderRect.contains(cursorPos))
    {
        stretchState = BOTTOM_BORDER;
    }
    else if (m_leftBorderRect.contains(cursorPos))
    {
        stretchState = LEFT_BORDER;
    }
    else
    {
        stretchState = NO_SELECT;
    }
    //qDebug() << "stretchState 值为" << stretchState;

    return stretchState;

}

void MainWindow::updateMouseStyle(WindowStretchRectState stretchState)
{

    switch (stretchState)
    {
    case NO_SELECT:
        setCursor(Qt::ArrowCursor);
        break;
    case LEFT_TOP_RECT:
    case RIGHT_BOTTOM_RECT:
        setCursor(Qt::SizeFDiagCursor);
        break;
    case TOP_BORDER:
    case BOTTOM_BORDER:
        setCursor(Qt::SizeVerCursor);
        break;
    case RIGHT_TOP_RECT:
    case LEFT_BOTTOM_RECT:
        setCursor(Qt::SizeBDiagCursor);
        break;
    case LEFT_BORDER:
    case RIGHT_BORDER:
        setCursor(Qt::SizeHorCursor);
        break;
    default:
        setCursor(Qt::ArrowCursor);
        break;
    }

}

void MainWindow::updateWindowSize()
{
    // 拉伸时要注意设置窗口最小值;
    QRect windowRect = m_windowRectBeforeStretch;
    int delValue_X = m_startPoint.x() - m_endPoint.x();
    int delValue_Y = m_startPoint.y() - m_endPoint.y();

    if (m_stretchRectState == LEFT_BORDER)
    {
        QPoint topLeftPoint = windowRect.topLeft();
        topLeftPoint.setX(topLeftPoint.x() - delValue_X);
        windowRect.setTopLeft(topLeftPoint);
    }
    else if (m_stretchRectState == RIGHT_BORDER)
    {
        QPoint bottomRightPoint = windowRect.bottomRight();
        bottomRightPoint.setX(bottomRightPoint.x() - delValue_X);
        windowRect.setBottomRight(bottomRightPoint);
    }
    else if (m_stretchRectState == TOP_BORDER)
    {
        QPoint topLeftPoint = windowRect.topLeft();
        topLeftPoint.setY(topLeftPoint.y() - delValue_Y);
        windowRect.setTopLeft(topLeftPoint);
    }
    else if (m_stretchRectState == BOTTOM_BORDER)
    {
        QPoint bottomRightPoint = windowRect.bottomRight();
        bottomRightPoint.setY(bottomRightPoint.y() - delValue_Y);
        windowRect.setBottomRight(bottomRightPoint);
    }
    else if (m_stretchRectState == LEFT_TOP_RECT)
    {
        QPoint topLeftPoint = windowRect.topLeft();
        topLeftPoint.setX(topLeftPoint.x() - delValue_X);
        topLeftPoint.setY(topLeftPoint.y() - delValue_Y);
        windowRect.setTopLeft(topLeftPoint);
    }
    else if (m_stretchRectState == RIGHT_TOP_RECT)
    {
        QPoint topRightPoint = windowRect.topRight();
        topRightPoint.setX(topRightPoint.x() - delValue_X);
        topRightPoint.setY(topRightPoint.y() - delValue_Y);
        windowRect.setTopRight(topRightPoint);
    }
    else if (m_stretchRectState == RIGHT_BOTTOM_RECT)
    {
        QPoint bottomRightPoint = windowRect.bottomRight();
        bottomRightPoint.setX(bottomRightPoint.x() - delValue_X);
        bottomRightPoint.setY(bottomRightPoint.y() - delValue_Y);
        windowRect.setBottomRight(bottomRightPoint);
    }
    else if (m_stretchRectState == LEFT_BOTTOM_RECT)
    {
        QPoint bottomLeftPoint = windowRect.bottomLeft();
        bottomLeftPoint.setX(bottomLeftPoint.x() - delValue_X);
        bottomLeftPoint.setY(bottomLeftPoint.y() - delValue_Y);
        windowRect.setBottomLeft(bottomLeftPoint);
    }

    // 避免宽或高为零窗口显示有误，这里给窗口设置最小拉伸高度、宽度;
    int m_windowMinWidth = 50;
    int m_windowMinHeight = 50;
    if (windowRect.width() < m_windowMinWidth)
    {
        windowRect.setLeft(this->geometry().left());
        windowRect.setWidth(m_windowMinWidth);
    }
    if (windowRect.height() < m_windowMinHeight)
    {
        windowRect.setTop(this->geometry().top());
        windowRect.setHeight(m_windowMinHeight);
    }

    this->setGeometry(windowRect);

}

void MainWindow::setSupportStretch(bool isSupportStretch)
{
    // 因为需要在鼠标未按下的情况下通过mouseMoveEvent事件捕捉鼠标位置，所以需要设置setMouseTracking为true（如果窗口支持拉伸）;

        m_isSupportStretch = isSupportStretch;
        this->setMouseTracking(isSupportStretch);
        // 这里对子控件也进行了设置，是因为如果不对子控件设置，当鼠标移动到子控件上时，不会发送mouseMoveEvent事件，也就获取不到当前鼠标位置，无法判断鼠标状态及显示样式了。
        QList<QWidget*> widgetList = this->findChildren<QWidget*>();
        for(int i = 0; i < widgetList.length(); i ++) {
            widgetList[i]->setMouseTracking(isSupportStretch);
        // 这里加了非空判断，防止m_titleBar未创建;
//        if (m_titleBar != NULL)
//        {
//            // m_titleBar同理,也需要对自己及子控件进行调用setMouseTracking进行设置，见上方注释;
//            m_titleBar->setSupportStretch(isSupportStretch);
//        }
    }

}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(ui->widget_title->underMouse() && !showFlag) {
        isPressedWidget = true; // 当前鼠标按下的即是QWidget而非界面上布局的其它控件
    }
    last = event->globalPos();
    // 当前鼠标进入了以上指定的8个区域，并且是左键按下时才开始进行窗口拉伸;
     if (m_stretchRectState != NO_SELECT && event->button() == Qt::LeftButton)
     {
         m_isMousePressed = true;
         // 记录下当前鼠标位置，为后面计算拉伸位置;
         m_startPoint = this->mapToGlobal(event->pos());
         // 保存下拉伸前的窗口位置及大小;
         m_windowRectBeforeStretch = this->geometry();
     }
        //return QObject::mouseMoveEvent(event);
}

void MainWindow::mouseMoveEvent(QMouseEvent *event) {   //qDebug() << ui->widget_body->parent();
    //qDebug() << "鼠标移动到 " << event->x() << "," << event->y();
    if (isPressedWidget) {
        int dx = event->globalX() - last.x();
        int dy = event->globalY() - last.y();
        last = event->globalPos();
        move(x()+dx, y()+dy);
    }

    if (!m_isMousePressed)
    {
        QPoint cursorPos = event->pos();
        // 根据当前鼠标的位置显示不同的样式;
        m_stretchRectState = getCurrentStretchState(cursorPos);
        updateMouseStyle(m_stretchRectState);
    }
    // 如果当前鼠标左键已经按下，则记录下第二个点的位置，并更新窗口的大小;
    else
    {
        m_endPoint = this->mapToGlobal(event->pos());
        updateWindowSize();
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    isPressedWidget = false; // 鼠标松开时，置为false

    // 鼠标松开后意味之窗口拉伸结束，置标志位，并且重新计算用于拉伸的8个区域Rect;
    m_isMousePressed = false;
    calculateCurrentStrechRect();

    //return QObject::mouseReleaseEvent(event);
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(ui->widget_title->underMouse() && !showFlag) {
        setContentsMargins(0, 0, 0, 0);
        ui->centralWidget->setStyleSheet("QMainWindow,QWidget#centralWidget {background-color: rgb(30, 45, 54);border-radius:0px;}");
        ui->toolButton_max->setIcon(QIcon(":lib/icon-copy.png"));
        this->showMaximized();
        showFlag = true;
    } else if (ui->widget_title->underMouse() && showFlag) {
        setContentsMargins(10, 10, 10, 10);
        ui->centralWidget->setStyleSheet("QMainWindow,QWidget#centralWidget {background-color: rgb(30, 45, 54);border-radius:6px;}");
        ui->toolButton_max->setIcon(QIcon(":lib/Icon_max2.png"));
        this->showNormal();
        showFlag = false;
    }
}

void MainWindow::showEvent(QShowEvent *event)
{
    calculateCurrentStrechRect();

    //return MainWindow::showEvent(event);
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
    // 获取任务栏的位置
    QRect taskbarRect;
    QScreen *screen = QGuiApplication::primaryScreen();
    if (screen) {
        QRect screenRect = screen->geometry();
        QRect availableRect = screen->availableGeometry();
        taskbarRect = QRect(screenRect.x(), availableRect.y() + availableRect.height(), screenRect.width(), screenRect.height() - availableRect.height());
    }

    QPropertyAnimation *minimumAnimation = new QPropertyAnimation(this, "geometry");

    //minimumAnimation->setDuration(500); // 设置动画持续时间（以毫秒为单位）
    //minimumAnimation->setStartValue(this->geometry()); // 设置动画起始位置为当前窗体的几何属性
   // minimumAnimation->setEndValue(QRect(this->x(), this->y(), 0, 0)); // 设置动画结束位置为窗体的左上角，宽度和高度为0

//    minimumAnimation->setDuration(500); // 设置动画持续时间（以毫秒为单位）
//    minimumAnimation->setStartValue(this->geometry()); // 设置动画起始位置为当前窗体的几何属性
//    minimumAnimation->setEndValue(taskbarRect); // 设置动画结束位置为任务栏的位置
//    minimumAnimation->start();
    this->showMinimized();
}

void MainWindow::on_toolButton_max_clicked()
{
    //最大化
    if (!showFlag) {
        setContentsMargins(0, 0, 0, 0);
        ui->centralWidget->setStyleSheet("QMainWindow,QWidget#centralWidget {background-color: rgb(30, 45, 54);border-radius:0px;}");
        ui->toolButton_max->setIcon(QIcon(":lib/icon-copy.png"));
        this->showMaximized();
        showFlag = true;
    } else {
        setContentsMargins(10, 10, 10, 10); //rgb(67, 77, 88)
        ui->centralWidget->setStyleSheet("QMainWindow,QWidget#centralWidget {background-color: rgb(30, 45, 54);border-radius:6px;}");
        ui->toolButton_max->setIcon(QIcon(":lib/Icon_max2.png"));
        this->showNormal();
        showFlag = false;
    }
}

void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    ui->tabWidget->removeTab(index);
    if(ui->tabWidget->count() == 0) {
        ui->stackedWidget->setCurrentIndex(2);
    }
}

void MainWindow::on_newCreate()
{
    if (ccwidget == nullptr) {
        //获取发送者
        //QString actionText = qobject_cast<QAction*>(sender())->text();
        int8_t connectType = 0;
//        if (actionText == "ssh连接") {
//            connectType =SSH_CONNECT_TYPE;
//        } else if (actionText == "zk连接") {
//            connectType =ZK_CONNECT_TYPE;
//        } else if (actionText == "redis连接") {
//            connectType =REDIS_CONNECT_TYPE;
//        } else if (actionText == "kafka连接") {
//            connectType =KAFKA_CONNECT_TYPE;
//        } else if (actionText == "database连接") {
//            connectType =DB_CONNECT_TYPE;
//        }

        //创建连接窗口
        ccwidget = new createconnect(connectType);
        connect(ccwidget,SIGNAL(newCreate(connnectInfoStruct&)),this,SLOT(on_newConnnect(connnectInfoStruct&)));
        ccwidget->show();
    } else {
        //不创建
        ccwidget->setFocus();
    }

}

void MainWindow::on_newTool()
{
    if (ccwidget == nullptr) {
        //获取发送者
        QString toolName;
        QString actionText = qobject_cast<QAction*>(sender())->text();
        int8_t connectType = 0;
        if (actionText == "小工具集合") {
            ui->widget_4->show();
            return;
            //connectType =SSH_CONNECT_TYPE;
        } else if (actionText == "JSON格式化") {
            toolName = "JSON格式化";
            //connectType =ZK_CONNECT_TYPE;
        } else if (actionText == "XML格式化") {
            toolName = "XML格式化";
            //connectType =REDIS_CONNECT_TYPE;
        } else if (actionText == "文本对比") {
            toolName = "文本对比";
        }

        //创建连接窗口
        tswidget = new toolswidget();
        //connect(tswidget,SIGNAL(newCreate(connnectInfoStruct&)),this,SLOT(on_newConnnect(connnectInfoStruct&)));
        QSize iconSize(16, 16); // 设置图标的大小
        //sshWidgetList.push_back(tswidget);
        ui->tabWidget->addTab(tswidget, QIcon(":lib/tool.png").pixmap(iconSize), toolName);
        ui->tabWidget->setCurrentIndex(ui->tabWidget->count()-1);
        //sshWidgetList.push_back(tswidget);
        tswidget->show();
    } else {
        //不创建
        tswidget->setFocus();
    }
    ui->tabWidget->setCurrentIndex(ui->tabWidget->count()-1);
    ui->stackedWidget->setCurrentIndex(0);
    ui->widget_line->show();
}

void MainWindow::on_newConnnect(connnectInfoStruct& cInfoStruct)
{
    qDebug() << cInfoStruct.connectType;
    QSize iconSize(16, 16); // 设置图标的大小

    if (cInfoStruct.connectType == SSH_CONNECT_TYPE) {
        sshwidget * sshWidget = new sshwidget(cInfoStruct);
        sshWidgetList.push_back(sshWidget);
        ui->tabWidget->addTab(sshWidget, QIcon(":lib/powershell.png").pixmap(iconSize), cInfoStruct.name);
    } else if (cInfoStruct.connectType == WINDOWS_CONNECT_TYPE) {

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
    ui->stackedWidget->setCurrentIndex(0);
    ui->widget_line->show();
}

void MainWindow::on_newClose()
{
    qDebug() << "删除";
    delete(ccwidget);
    ccwidget = nullptr;
}

void MainWindow::on_widget_welcome_body_widget2_newCreate_newTerminal_clicked()
{
    //新建终端
    int8_t connectType = 0;
    ccwidget = new createconnect(connectType);
    connect(ccwidget,SIGNAL(newCreate(connnectInfoStruct&)),this,SLOT(on_newConnnect(connnectInfoStruct&)));
    ccwidget->show();
}

void MainWindow::on_widget_welcome_body_widget2_newCreate_newTool_clicked()
{
    //创建连接窗口
//    tswidget = new toolswidget();
//    //connect(tswidget,SIGNAL(newCreate(connnectInfoStruct&)),this,SLOT(on_newConnnect(connnectInfoStruct&)));
//    QSize iconSize(16, 16); // 设置图标的大小
//    //sshWidgetList.push_back(tswidget);
//    ui->tabWidget->addTab(tswidget, QIcon(":lib/tool.png").pixmap(iconSize), "工具");
//    ui->tabWidget->setCurrentIndex(ui->tabWidget->count()-1);
//    //sshWidgetList.push_back(tswidget);
//    tswidget->show();
    ui->stackedWidget->setCurrentIndex(0);
    ui->widget_4->show();
}

void MainWindow::on_comboBox_tool_currentIndexChanged(int index)
{
    ui->stackedWidget_tool->setCurrentIndex(index);
}

void MainWindow::on_lineEdit_hex_textChanged(const QString &arg1)
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

void MainWindow::on_lineEdit_dec_textChanged(const QString &arg1)
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

void MainWindow::on_lineEdit_oct_textChanged(const QString &arg1)
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

void MainWindow::on_lineEdit_bin_textChanged(const QString &arg1)
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

void MainWindow::on_toolButton_decode_clicked()
{
    //解码
    QString url = ui->lineEdit_encode_in->text();
    QString decodedUrl = QUrl::fromPercentEncoding(url.toUtf8());
    ui->lineEdit_decode_out->setText(decodedUrl);
}

void MainWindow::on_toolButton_encode_clicked()
{
    //编码
    QString url = ui->lineEdit_encode_in->text();
    QString encodedUrl = QUrl::toPercentEncoding(url);
    ui->lineEdit_decode_out->setText(encodedUrl);
}

void MainWindow::rece_showtimestamp()
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

void MainWindow::on_toolButton_time2date_clicked()
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

void MainWindow::on_toolButton_date2time_clicked()
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

void MainWindow::on_toolButton_timestamp_copy_clicked()
{
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(ui->lineEdit_now_timestamp->text());
}

void MainWindow::on_toolButton_closetool_clicked()
{
    ui->widget_4->hide();
}

void MainWindow::on_toolButton_newCreate_clicked()
{
    if (ccwidget == nullptr) {
        int8_t connectType = 0;
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

void MainWindow::on_toolButton_newCreate_2_clicked()
{
    //if (hcwidget == nullptr) {
        int8_t connectType = 0;
        //创建连接窗口
        hcwidget = new historyconnectwidget(connectType);
        //connect(hcwidget,SIGNAL(newCreate(connnectInfoStruct&)),this,SLOT(on_newConnnect(connnectInfoStruct&)));
        ui->tabWidget->addTab(hcwidget, "快速连接");
        ui->tabWidget->setCurrentIndex(ui->tabWidget->count()-1);
        ui->stackedWidget->setCurrentIndex(0);
        hcwidget->show();
//    } else {
//        //不创建
//        hcwidget->setFocus();
//    }
}
