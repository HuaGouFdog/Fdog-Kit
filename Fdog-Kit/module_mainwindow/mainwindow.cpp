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
#include <QParallelAnimationGroup>
#include <Windows.h>
#include <qt_windows.h>
#include <QSystemTrayIcon>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QShortcut>
#include <QDesktopServices>
#include <QFile>
#include <QListView>
#include "module_utils/utils.h"
#include <QFormLayout>
#include <QDesktopWidget>
#include "module_smalltool/smalltoolwidget.h"
#include "windows.h"
#include "windowsx.h"

QVariant mySheetStyle(const QString & start, const QString & end, qreal progress)
{
    int red   = 255 - (int)(235 * progress);
    int green = 255 - (int)(225 * progress);
    int blue  = 127 - (int)(90 * progress);
    //255, 255, 127
    QString style = QString("background-color: rgb(%1,%2,%3)").arg(red).arg(green).arg(blue);
    qDebug()<<"style = "<<style;
    return style;
}

MainWindow::MainWindow(config * confInfo, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->confInfo = confInfo;
    getGraphicsEffectUtils(ui->centralWidget, 0, 0, 15, QColor(30, 30, 30));

    //设置全局样式表
    changeMainWindowTheme();

    Qt::WindowFlags flags = this->windowFlags();
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint); //Qt::WindowStaysOnTopHint
    // QMainWindow透明显示，当设置主显示窗口的外边距时，防止外边距显示出来。
    this->setAttribute(Qt::WA_TranslucentBackground, true);
    setContentsMargins(10, 10, 10, 10);
    HWND hwnd = (HWND)this->winId();
    DWORD style = ::GetWindowLong(hwnd, GWL_STYLE);
    //窗口标题最小化，最大化，在这里实现
    SetWindowLong(hwnd, GWL_STYLE, style | WS_MAXIMIZEBOX | WS_THICKFRAME | WS_CAPTION | CS_DBLCLKS);
    //getGraphicsEffectUtils(ui->widget_side, 2, 0, 15);

    isPressedWidget = false;
    m_isMousePressed = false;
    //快捷键 F11 全屏
    QShortcut *shortcut = new QShortcut(QKeySequence(Qt::Key_F11), this);
    connect(shortcut, SIGNAL(activated()), this, SLOT(rece_toolButton_fullScreen_sign()));

    ui->widget_line->hide();
    ui->stackedWidget->setCurrentIndex(0);


    QAction *action = new QAction(this);
    action->setIcon(QIcon(":/lib/soucuo2.png"));

    // //读取配置文件信息
    // confInfo = new config();
    // // 读取JSON文件
    // confInfo->readSettingConf();
    qDebug() << "confInfo->isFirstStart" << confInfo->isFirstStart;
    qDebug() << "confInfo->autoPackage" << confInfo->autoPackage;
    qDebug() << "confInfo->thrift" << confInfo->thrift;
    qDebug() << "confInfo->zookeeper" << confInfo->zookeeper;
    qDebug() << "confInfo->shell" << confInfo->shell;
    qDebug() << "confInfo->db" << confInfo->db;
    qDebug() << "confInfo->qss" << confInfo->qss;
    qDebug() << "confInfo->tool" << confInfo->tool;
    qDebug() << "confInfo->extend" << confInfo->extend;

    //判断要隐藏的功能
    if (confInfo->autoPackage == 0) {
        ui->toolButton_side_build->hide();
    }
    if (confInfo->thrift == 0) {
        ui->toolButton_side_thrift->hide();
    }
    if (confInfo->zookeeper == 0) {
        ui->toolButton_side_zookeeper->hide();
    }
    if (confInfo->shell == 0) {
        ui->toolButton_side_shell->hide();
    }
    if (confInfo->db == 0) {
        ui->toolButton_side_mysql->hide();
    }
    if (confInfo->qss == 0) {
        ui->toolButton_side_qss->hide();
    }
    if (confInfo->tool == 0) {
        ui->toolButton_side_tool->hide();
    }
    if (confInfo->extend == 0) {
        ui->toolButton_side_plugIn->hide();
    }

    //设置窗口样式
    setWindowsByConf();
    //confInfo->writeSettingConf();
    qRegisterAnimationInterpolator<QString>(mySheetStyle);

    setSupportStretch(true);

    //打开数据库
    //db_ = new sqlhandle();

    ui->toolButton_newVersion->setToolTip("");
    ui->toolButton_newVersion->setIcon(QIcon());
    ui->toolButton_newVersion->hide();
    //checkNewVersion();

    //设置系统托盘
    createSystemTray();
    qDebug() << "初始化完毕";
}

MainWindow::~MainWindow()
{
    qDebug() <<  "关闭MainWindow";
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
    if (isMaxShow) {
        return;
    }
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
    if (isMaxShow) {
        return;
    }
    QRect windowRect = m_windowRectBeforeStretch;
    int delValue_X = m_startPoint.x() - m_endPoint.x();
    int delValue_Y = m_startPoint.y() - m_endPoint.y();
    int m_windowMinWidth = 600;
    int m_windowMinHeight = 600;
    if (m_stretchRectState == LEFT_BORDER) {
        //qDebug() << "更新窗口大小 this->geometry().width() = "<< this->geometry().width() << " delValue_X= " << delValue_X;
        if (this->geometry().width() <= m_windowMinWidth && delValue_X <= 0) {
            //qDebug() << "已经达到最小值 delValue_X=" << delValue_X;
            return;
        }
        QPoint bottomLeftPoint = windowRect.bottomLeft();
        bottomLeftPoint.setX(bottomLeftPoint.x() - delValue_X);
        windowRect.setBottomLeft(bottomLeftPoint);
        //qDebug() << "走这里";
        //qDebug() << "当前高度" << this->geometry().height();
        //qDebug() << "windowRect = " << windowRect;
        this->setGeometry(windowRect);
        //qDebug() << "现在高度" << this->geometry().height();

    } else if (m_stretchRectState == RIGHT_BORDER) {
        QPoint bottomRightPoint = windowRect.bottomRight();
        bottomRightPoint.setX(bottomRightPoint.x() - delValue_X);
        windowRect.setBottomRight(bottomRightPoint);
        this->setGeometry(windowRect);
    } else if (m_stretchRectState == TOP_BORDER) {
        if (this->geometry().height() <= m_windowMinHeight && delValue_Y <= 0) {
            //qDebug() << "已经达到最小值 delValue_Y=" << delValue_Y;
            return;
        }
        QPoint topLeftPoint = windowRect.topLeft();
        topLeftPoint.setY(topLeftPoint.y() - delValue_Y);
        windowRect.setTopLeft(topLeftPoint);
        this->setGeometry(windowRect);
    } else if (m_stretchRectState == BOTTOM_BORDER)  {
        //qDebug() << "下边BOTTOM_BORDER";
        QPoint bottomRightPoint = windowRect.bottomRight();
        bottomRightPoint.setY(bottomRightPoint.y() - delValue_Y);
        windowRect.setBottomRight(bottomRightPoint);
        this->setGeometry(windowRect);
    } else if (m_stretchRectState == LEFT_TOP_RECT) {
        //qDebug() << "更新窗口大小 this->geometry().width() = "<< this->geometry().width() << " delValue_X= " << delValue_X;
        //qDebug() << "更新窗口大小 this->geometry().height() = "<< this->geometry().height() << " delValue_Y= " << delValue_Y;
        if (this->geometry().width() - 3 <= m_windowMinWidth && delValue_X <= 0
                && this->geometry().height() -3 <= m_windowMinHeight && delValue_Y <= 0) {
            //qDebug() << "已经达到最小值 delValue_X=" << delValue_X;
            return;
        }
        int a = 0;
        if (this->geometry().width() - 3 <= m_windowMinWidth && delValue_X <= 0) {
            //qDebug() << "已经达到最小值 delValue_X=" << delValue_X;
            a = 1;
        }
        if (this->geometry().height() - 3 <= m_windowMinHeight && delValue_Y <= 0) {
            //qDebug() << "已经达到最小值 delValue_Y=" << delValue_Y;
            a = 2;
        }
        //qDebug() << " windowRect1 = " << this->geometry();
        if (a == 0) {
            //qDebug() << "走1";
            QPoint topLeftPoint = windowRect.topLeft();
            topLeftPoint.setX(topLeftPoint.x() - delValue_X);
            topLeftPoint.setY(topLeftPoint.y() - delValue_Y);
            windowRect.setTopLeft(topLeftPoint);
            this->setGeometry(windowRect);
        } else if (a == 1) {
            //qDebug() << "走2";
            QPoint topLeftPoint = windowRect.topLeft();
            topLeftPoint.setX(this->geometry().x());
            topLeftPoint.setY(topLeftPoint.y() - delValue_Y);
            windowRect.setTopLeft(topLeftPoint);
            //qDebug() << " topLeftPoint2 = " << topLeftPoint;
            //qDebug() << " windowRect2 = " << this->geometry();
            this->setGeometry(windowRect);
        } else if (a == 2) {
            //qDebug() << "走3";
            QPoint topLeftPoint = windowRect.topLeft();
            topLeftPoint.setX(topLeftPoint.x() - delValue_X);
            topLeftPoint.setY(this->geometry().y());
            windowRect.setTopLeft(topLeftPoint);
            this->setGeometry(windowRect);
        }
        //qDebug() << " windowRect3 = " << this->geometry();
    } else if (m_stretchRectState == RIGHT_TOP_RECT) {
        if (this->geometry().width() - 3 <= m_windowMinWidth && delValue_X <= 0
                && this->geometry().height() -3 <= m_windowMinHeight && delValue_Y <= 0) {
            //qDebug() << "已经达到最小值 delValue_X=" << delValue_X;
            return;
        }
        int a = 0;
        if (this->geometry().width() - 3 <= m_windowMinWidth && delValue_X <= 0) {
            //qDebug() << "已经达到最小值 delValue_X=" << delValue_X;
            a = 1;
        }
        if (this->geometry().height() - 3 <= m_windowMinHeight && delValue_Y <= 0) {
            //qDebug() << "已经达到最小值 delValue_Y=" << delValue_Y;
            a = 2;
        }

        if (a == 0) {
            //qDebug() << "走1";
            QPoint topRightPoint = windowRect.topRight();
            topRightPoint.setX(topRightPoint.x() - delValue_X);
            topRightPoint.setY(topRightPoint.y() - delValue_Y);
            windowRect.setTopRight(topRightPoint);
            this->setGeometry(windowRect);
        } else if (a == 1) {
            //qDebug() << "走2";
            QPoint topRightPoint = windowRect.topRight();
            topRightPoint.setX(this->geometry().x());
            topRightPoint.setY(topRightPoint.y() - delValue_Y);
            windowRect.setTopRight(topRightPoint);
            //qDebug() << " topLeftPoint2 = " << topRightPoint;
            //qDebug() << " windowRect2 = " << this->geometry();
            this->setGeometry(windowRect);
        } else if (a == 2) {
            //qDebug() << "走3";
            QPoint topRightPoint = windowRect.topRight();
            topRightPoint.setX(topRightPoint.x() - delValue_X);
            topRightPoint.setY(this->geometry().y());
            windowRect.setTopRight(topRightPoint);
            this->setGeometry(windowRect);
        }
//        QPoint topRightPoint = windowRect.topRight();
//        topRightPoint.setX(topRightPoint.x() - delValue_X);
//        topRightPoint.setY(topRightPoint.y() - delValue_Y);
//        windowRect.setTopRight(topRightPoint);
//        this->setGeometry(windowRect);
    } else if (m_stretchRectState == RIGHT_BOTTOM_RECT) {
        QPoint bottomRightPoint = windowRect.bottomRight();
        bottomRightPoint.setX(bottomRightPoint.x() - delValue_X);
        bottomRightPoint.setY(bottomRightPoint.y() - delValue_Y);
        windowRect.setBottomRight(bottomRightPoint);
        this->setGeometry(windowRect);
    } else if (m_stretchRectState == LEFT_BOTTOM_RECT) {
        if (this->geometry().width() - 3 <= m_windowMinWidth && delValue_X <= 0
                && this->geometry().height() -3 <= m_windowMinHeight && delValue_Y <= 0) {
            //qDebug() << "已经达到最小值 delValue_X=" << delValue_X;
            return;
        }
        int a = 0;
        if (this->geometry().width() - 3 <= m_windowMinWidth && delValue_X <= 0) {
            //qDebug() << "已经达到最小值 delValue_X=" << delValue_X;
            a = 1;
        }
        if (this->geometry().height() - 3 <= m_windowMinHeight && delValue_Y <= 0) {
            //qDebug() << "已经达到最小值 delValue_Y=" << delValue_Y;
            a = 2;
        }
        if (a == 0) {
            //qDebug() << "走1";
            QPoint bottomLeftPoint = windowRect.bottomLeft();
            bottomLeftPoint.setX(bottomLeftPoint.x() - delValue_X);
            bottomLeftPoint.setY(bottomLeftPoint.y() - delValue_Y);
            windowRect.setBottomLeft(bottomLeftPoint);
            this->setGeometry(windowRect);
        } else if (a == 1) {
            //qDebug() << "走2";
            QPoint bottomLeftPoint = windowRect.bottomLeft();
            bottomLeftPoint.setX(this->geometry().x());
            bottomLeftPoint.setY(bottomLeftPoint.y() - delValue_Y);
            windowRect.setBottomLeft(bottomLeftPoint);
            //qDebug() << " topLeftPoint2 = " << bottomLeftPoint;
            //qDebug() << " windowRect2 = " << this->geometry();
            this->setGeometry(windowRect);
        } else if (a == 2) {
            //qDebug() << "走3";
            QPoint bottomLeftPoint = windowRect.bottomLeft();
            bottomLeftPoint.setX(bottomLeftPoint.x() - delValue_X);
            bottomLeftPoint.setY(this->geometry().y());
            windowRect.setBottomLeft(bottomLeftPoint);
            this->setGeometry(windowRect);
        }
    }
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
    if(ui->widget_title2->underMouse() && !showFlag) {
        isPressedWidget = true; // 当前鼠标按下的即是QWidget而非界面上布局的其它控件
        //qDebug() << "mousePressEvent 标题栏被按下";
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
        //m_windowRectBeforeStretch = this->geometry();
        updateWindowSize();
        //qDebug() << "刷新m_windowRectBeforeStretch";
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
    //标题双击不走这里
}

// void MainWindow::resizeEvent(QResizeEvent *event)
// {
//     qDebug() << "resizeEvent 被调用";
//     //QTextEdit::resizeEvent(event);
// }

void MainWindow::showEvent(QShowEvent *event)
{
    calculateCurrentStrechRect();

    //防止假死
    setAttribute(Qt::WA_Mapped);
    QMainWindow::showEvent(event);

    QSize oldSize = this->size();
    resize(oldSize + QSize(10, 10));
    resize(oldSize);
}

void MainWindow::changeEvent(QEvent *event)
{
    if(QEvent::WindowStateChange == event->type())
    {
    	//判断为窗口状态改变事件
        QWindowStateChangeEvent * stateEvent = dynamic_cast<QWindowStateChangeEvent*>(event);
        if(Q_NULLPTR != stateEvent)
        {
            if (this->windowState() == Qt::WindowNoState && stateEvent->oldState() == Qt::WindowMaximized) {
                //qDebug() << "当前正常";
                changeMainWindowRadius(1);
            } else if (this->windowState() == Qt::WindowMaximized && stateEvent->oldState() == Qt::WindowNoState) {
                //qDebug() << "当前最大化";
                changeMainWindowRadius(2);
            }
        }
    }
}

bool MainWindow::nativeEvent(const QByteArray &eventType, void *message, long *result)
{
    MSG* msg = (MSG*)message;

    switch (msg->message) {
        //没有这一段，将不会显示窗口
        case WM_NCCALCSIZE:
            return true;
        //最大化是填充屏幕
        case WM_NCHITTEST:
        {
            //qDebug() << "触发WM_NCHITTEST";
            qreal ratio = 1.0;
            long x = GET_X_LPARAM(msg->lParam) / ratio;
            long y = GET_Y_LPARAM(msg->lParam) / ratio;
            QPoint pos = mapFromGlobal(QPoint(x, y));
            //qDebug() << "pos = " << pos;
            if (pos.y() > 10 && ui->widget_title2->rect().contains(pos)) {
                //qDebug() << "标题栏被按下";
                // 根据当前鼠标的位置显示不同的样式;
                *result = HTCAPTION;
                return true;
            }
        }   
        case WM_GETMINMAXINFO:
        {
            if (::IsZoomed(msg->hwnd)) {
                isMaxShow = true;
                showFlag = true;
                // 最大化时会超出屏幕，所以填充边框间距
                RECT frame = { 0, 0, 0, 0 };
                AdjustWindowRectEx(&frame, WS_OVERLAPPEDWINDOW, FALSE, 0);
                frame.left = abs(frame.left);
                frame.top = abs(frame.bottom);
                this->setContentsMargins(frame.left, frame.top, frame.right, frame.bottom);
            } else {
                isMaxShow = false;
                showFlag = false;
            }
            *result = ::DefWindowProc(msg->hwnd, msg->message, msg->wParam, msg->lParam);
            return true;
        }
    }
    return QMainWindow::nativeEvent(eventType, message, result);
}

void MainWindow::newConnectZk(QString name, QString host, QString port)
{

}

void MainWindow::createSystemTray()
{
    // 创建系统托盘图标
    trayIcon = new QSystemTrayIcon(QIcon(":lib/icon9.png"), this);
    trayIcon->setToolTip("Fdog-Kit");
	QString title = tr("欢迎使用Fdog-Kit");
	QString text = tr("让一切变的简单");
	trayIcon->show();
    //trayIcon->showMessage(title, text, QSystemTrayIcon::Information, 5000);
    // 创建一个菜单
    QMenu* menu = new QMenu();
    menu->setWindowFlags(menu->windowFlags()  | Qt::FramelessWindowHint | Qt::NoDropShadowWindowHint);
    menu->setAttribute(Qt::WA_TranslucentBackground);
    QAction* openAction = new QAction("打开");
    QAction* closeAction = new QAction("退出");
    menu->addAction(openAction);
    menu->addAction(closeAction);
    menu->setStyleSheet(getStyleFile(":qss/menu.qss"));
    // 将菜单设置给系统托盘图标
    trayIcon->setContextMenu(menu);

    connect(openAction, SIGNAL(triggered()), this, SLOT(rece_systemTrayMenu()));
    connect(closeAction, SIGNAL(triggered()), this, SLOT(rece_systemTrayMenu()));
}

void MainWindow::setWindowsByConf()
{
    if (confInfo->selfStart == 1) {

    } else if (confInfo->selfStart == 2) {

    }

    if (confInfo->startMode == 1) {
        //默认
    } else if (confInfo->startMode == 2) {
        //最大化
        setContentsMargins(0, 0, 0, 0);
        ui->centralWidget->setStyleSheet("#centralWidget {border-image: url(:/lib/back1.png);border-radius:0px;}");
        ui->toolButton_max->setIcon(QIcon(":lib/icon-copy.png"));
        this->showMaximized();
        isMaxShow = true;
        showFlag = true;
    } else if (confInfo->startMode == 3) {
        //全屏
        setContentsMargins(0, 0, 0, 0);
        ui->centralWidget->setStyleSheet("#centralWidget {border-image: url(:/lib/back1.png);border-radius:0px;}");
        ui->toolButton_max->setIcon(QIcon(":lib/icon-copy.png"));
        ui->toolButton_min->hide();
        ui->toolButton_max->hide();
        ui->toolButton_close->hide();
        setWindowState(Qt::WindowFullScreen);
        isFullScreen = true;
    }

    if (confInfo->startCenter == 1) {
        QDesktopWidget dw;
        int deskWidth = dw.width();
        int deskHeight = dw.height();

        this->setGeometry(deskWidth/2 - confInfo->startPositionX/2, deskHeight/2 - confInfo->startPositionY/2, confInfo->startPositionX,confInfo->startPositionY);
        //qDebug() << "居中显示";
    } else {
        this->setGeometry(confInfo->physicalDpiX(),confInfo->physicalDpiY(),confInfo->startPositionX,confInfo->startPositionY);
        //qDebug() << "不居中显示";
    }
}

bool MainWindow::isVersionGreater(const QString &version1, const QString &version2) {
    //qDebug() << "get v " << version1;
    //qDebug() << "old v " << version2;
    QStringList v1Parts = version1.split(".");
    QStringList v2Parts = version2.split(".");
    int maxLength = qMax(v1Parts.size(), v2Parts.size());

    for (int i = 0; i < maxLength; ++i) {
        int v1Part = i < v1Parts.size() ? v1Parts[i].toInt() : 0;
        int v2Part = i < v2Parts.size() ? v2Parts[i].toInt() : 0;

        if (v1Part > v2Part) {
            return true;
        } else if (v1Part < v2Part) {
            return false;
        }
    }

    return false;
}

void MainWindow::changeMainWindowTheme(bool isChange, int windowsType)
{
    if (windowsType == 1) {
        //正常qss
        ui->widget_side->setProperty("State","WindowNoState");
        ui->toolButton_close->setProperty("State","WindowNoState");
        ui->centralWidget->setProperty("State","WindowNoState");
    } else {
        //最大化qss
        ui->widget_side->setProperty("State","WindowMaximized");
        ui->toolButton_close->setProperty("State","WindowMaximized");
        ui->centralWidget->setProperty("State","WindowMaximized");
    }

    if (isChange) {
        //更换主题
        qDebug() << "切换主题" << mode;
        mode = (mode + 1) % 3;
    }
    mode = DARK_THEME;
    //暂时使用DARK_THEME
    if (mode == DARK_THEME) {
        qDebug() << "切换暗黑模式";
        //暗黑模式
        //清除样式表
        style()->unpolish(ui->widget_side);
        style()->unpolish(ui->centralWidget);
        style()->unpolish(ui->widget_right);

        ui->widget_side->setStyleSheet("");
        ui->centralWidget->setStyleSheet("");
        ui->widget_right->setStyleSheet("");
        ui->widget_welcome_body_widget2_info_widget_icon->setStyleSheet("");

        //设置新的样式表
        ui->widget_side->setStyleSheet(getStyleFile(":/module_mainwindow/qss/side_dark.qss"));
        ui->centralWidget->setStyleSheet(getStyleFile(":/module_mainwindow/qss/centralWidget_dark.qss"));
        ui->widget_right->setStyleSheet(getStyleFile(":/module_mainwindow/qss/body_dark.qss"));
        ui->widget_welcome_body_widget2_info_widget_icon->setStyleSheet("image: url(:/module_mainwindow/images/light/iconmain-light.png);");
        //刷新
        style()->polish(ui->widget_side);
        style()->polish(ui->centralWidget);
        style()->polish(ui->widget_right);
        style()->polish(ui->widget_welcome_body_widget2_info_widget_icon);
        ui->toolButton_side_theme->setIcon(QIcon(":/module_mainwindow/images/light/moon-light.png"));
        ui->toolButton_min->setIcon(QIcon(":/module_mainwindow/images/light/min-light.png"));
        if (windowsType == 2) {
            ui->toolButton_max->setIcon(QIcon(":/module_mainwindow/images/light/normal-light.png"));
        } else {
            ui->toolButton_max->setIcon(QIcon(":/module_mainwindow/images/light/max-light.png"));
        }
        ui->toolButton_close->setIcon(QIcon(":/module_mainwindow/images/light/close-light.png"));

        ui->toolButton_side_home->setIcon(QIcon(":/module_mainwindow/images/light/home-light.png"));
        ui->toolButton_side_build->setIcon(QIcon(":/module_mainwindow/images/light/build-light.png"));
        ui->toolButton_side_thrift->setIcon(QIcon(":/module_mainwindow/images/light/func-light.png"));
        ui->toolButton_side_zookeeper->setIcon(QIcon(":/module_mainwindow/images/light/zookeeper-light.png"));
        ui->toolButton_side_shell->setIcon(QIcon(":/module_mainwindow/images/light/terminal-light.png"));
        ui->toolButton_side_mysql->setIcon(QIcon(":/module_mainwindow/images/light/mysql-light.png"));
        ui->toolButton_side_qss->setIcon(QIcon(":/module_mainwindow/images/light/qss-light.png"));
        ui->toolButton_side_tool->setIcon(QIcon(":/module_mainwindow/images/light/too-light.png"));
        ui->toolButton_side_plugIn->setIcon(QIcon(":/module_mainwindow/images/light/extend-light.png"));
        ui->toolButton_side_setting->setIcon(QIcon(":/module_mainwindow/images/light/setting-light.png"));

        ui->widget_welcome_body_widget2_newCreate_newTerminal->setIcon(QIcon(":/module_mainwindow/images/light/add-light.png"));
        ui->toolButton_zk_tool->setIcon(QIcon(":/module_mainwindow/images/light/zookeeper-light.png"));
        ui->toolButton_thrift_tool->setIcon(QIcon(":/module_mainwindow/images/light/func-light.png"));
        //更新阴影颜色
        getGraphicsEffectUtils(ui->widget_side, 2, 0, 15);
    } else if (mode == LIGHT_THEME) {
        qDebug() << "切换明亮模式";
        //明亮模式
        //清除样式表
        style()->unpolish(ui->widget_side);
        style()->unpolish(ui->centralWidget);
        style()->unpolish(ui->widget_right);

        ui->widget_side->setStyleSheet("");
        ui->centralWidget->setStyleSheet("");
        ui->widget_right->setStyleSheet("");
        ui->widget_welcome_body_widget2_info_widget_icon->setStyleSheet("");
        //设置新的样式表
        ui->widget_side->setStyleSheet(getStyleFile(":/module_mainwindow/qss/side_light.qss"));
        ui->centralWidget->setStyleSheet(getStyleFile(":/module_mainwindow/qss/centralWidget_light.qss"));
        ui->widget_right->setStyleSheet(getStyleFile(":/module_mainwindow/qss/body_light.qss"));
        ui->widget_welcome_body_widget2_info_widget_icon->setStyleSheet("image: url(:/module_mainwindow/images/light/iconmain-light.png);");
        //刷新
        style()->polish(ui->widget_side);
        style()->polish(ui->centralWidget);
        style()->polish(ui->widget_right);
        style()->polish(ui->widget_welcome_body_widget2_info_widget_icon);

        ui->toolButton_side_theme->setIcon(QIcon(":/module_mainwindow/images/dark/sun-dark.png"));
        ui->toolButton_min->setIcon(QIcon(":/module_mainwindow/images/dark/min-dark.png"));
        ui->toolButton_max->setIcon(QIcon(":/module_mainwindow/images/dark/max-dark.png"));
        if (windowsType == 2) {
            ui->toolButton_max->setIcon(QIcon(":/module_mainwindow/images/dark/normal-dark.png"));
        } else {
            ui->toolButton_max->setIcon(QIcon(":/module_mainwindow/images/dark/max-dark.png"));
        }
        ui->toolButton_close->setIcon(QIcon(":/module_mainwindow/images/dark/close-dark.png"));

        ui->toolButton_side_home->setIcon(QIcon(":/module_mainwindow/images/dark/home-dark.png"));
        ui->toolButton_side_build->setIcon(QIcon(":/module_mainwindow/images/dark/build-dark.png"));
        ui->toolButton_side_thrift->setIcon(QIcon(":/module_mainwindow/images/dark/func-dark.png"));
        ui->toolButton_side_zookeeper->setIcon(QIcon(":/module_mainwindow/images/dark/zookeeper-dark.png"));
        ui->toolButton_side_shell->setIcon(QIcon(":/module_mainwindow/images/dark/terminal-dark.png"));
        ui->toolButton_side_mysql->setIcon(QIcon(":/module_mainwindow/images/dark/mysql-dark.png"));
        ui->toolButton_side_qss->setIcon(QIcon(":/module_mainwindow/images/dark/qss-dark.png"));
        ui->toolButton_side_tool->setIcon(QIcon(":/module_mainwindow/images/dark/too-dark.png"));
        ui->toolButton_side_plugIn->setIcon(QIcon(":/module_mainwindow/images/dark/extend-dark.png"));
        ui->toolButton_side_setting->setIcon(QIcon(":/module_mainwindow/images/dark/setting-dark.png"));

        ui->widget_welcome_body_widget2_newCreate_newTerminal->setIcon(QIcon(":/module_mainwindow/images/dark//add-dark.png"));
        ui->toolButton_zk_tool->setIcon(QIcon(":/module_mainwindow/images/dark/zookeeper-dark.png"));
        ui->toolButton_thrift_tool->setIcon(QIcon(":/module_mainwindow/images/dark/func-dark.png"));

        //更新阴影颜色
        getGraphicsEffectUtils(ui->widget_side, 2, 0, 15);
    } else if (mode == BLUE_THEME) {
        qDebug() << "切换蓝色模式";
        //蓝色模式
        //清除样式表
        style()->unpolish(ui->widget_side);
        style()->unpolish(ui->centralWidget);
        style()->unpolish(ui->widget_right);

        ui->widget_side->setStyleSheet("");
        ui->centralWidget->setStyleSheet("");
        ui->widget_right->setStyleSheet("");
        ui->widget_welcome_body_widget2_info_widget_icon->setStyleSheet("");

        //设置新的样式表
        ui->widget_side->setStyleSheet(getStyleFile(":/module_mainwindow/qss/side_blue.qss"));
        ui->centralWidget->setStyleSheet(getStyleFile(":/module_mainwindow/qss/centralWidget_blue.qss"));
        ui->widget_right->setStyleSheet(getStyleFile(":/module_mainwindow/qss/body_blue.qss"));
        ui->widget_welcome_body_widget2_info_widget_icon->setStyleSheet("image: url(:/module_mainwindow/images/light/iconmain-light.png);");
        //刷新
        style()->polish(ui->widget_side);
        style()->polish(ui->centralWidget);
        style()->polish(ui->widget_right);
        style()->polish(ui->widget_welcome_body_widget2_info_widget_icon);
        ui->toolButton_side_theme->setIcon(QIcon(":/module_mainwindow/images/light/cloud-light.png"));
        ui->toolButton_min->setIcon(QIcon(":/module_mainwindow/images/light/min-light.png"));
        ui->toolButton_max->setIcon(QIcon(":/module_mainwindow/images/light/max-light.png"));
        if (windowsType == 2) {
            ui->toolButton_max->setIcon(QIcon(":/module_mainwindow/images/light/normal-light.png"));
        } else {
            ui->toolButton_max->setIcon(QIcon(":/module_mainwindow/images/light/max-light.png"));
        }
        ui->toolButton_close->setIcon(QIcon(":/module_mainwindow/images/light/close-light.png"));

        ui->toolButton_side_home->setIcon(QIcon(":/module_mainwindow/images/light/home-light.png"));
        ui->toolButton_side_build->setIcon(QIcon(":/module_mainwindow/images/light/build-light.png"));
        ui->toolButton_side_thrift->setIcon(QIcon(":/module_mainwindow/images/light/func-light.png"));
        ui->toolButton_side_zookeeper->setIcon(QIcon(":/module_mainwindow/images/light/zookeeper-light.png"));
        ui->toolButton_side_shell->setIcon(QIcon(":/module_mainwindow/images/light/terminal-light.png"));
        ui->toolButton_side_mysql->setIcon(QIcon(":/module_mainwindow/images/light/mysql-light.png"));
        ui->toolButton_side_qss->setIcon(QIcon(":/module_mainwindow/images/light/qss-light.png"));
        ui->toolButton_side_tool->setIcon(QIcon(":/module_mainwindow/images/light/too-light.png"));
        ui->toolButton_side_plugIn->setIcon(QIcon(":/module_mainwindow/images/light/extend-light.png"));
        ui->toolButton_side_setting->setIcon(QIcon(":/module_mainwindow/images/light/setting-light.png"));

        ui->widget_welcome_body_widget2_newCreate_newTerminal->setIcon(QIcon(":/module_mainwindow/images/light/add-light.png"));
        ui->toolButton_zk_tool->setIcon(QIcon(":/module_mainwindow/images/light/zookeeper-light.png"));
        ui->toolButton_thrift_tool->setIcon(QIcon(":/module_mainwindow/images/light/func-light.png"));
        //更新阴影颜色
        getGraphicsEffectUtils(ui->widget_side, 2, 0, 15);
    }

    if (zmanagewidget != NULL) {
        zmanagewidget->changeMainWindowTheme(isChange, windowsType);
    }
}

void MainWindow::changeMainWindowRadius(int windowsType) {
    //centralWidget不应该包含大量qss属性,切换时会引起卡顿
    if (windowsType == 1) {
        //正常qss
        ui->centralWidget->setProperty("State","WindowNoState");
        ui->widget_side->setProperty("State","WindowNoState");
        ui->toolButton_close->setProperty("State","WindowNoState");
    } else {
        //最大化qss
        ui->centralWidget->setProperty("State","WindowMaximized");
        ui->widget_side->setProperty("State","WindowMaximized");
        ui->toolButton_close->setProperty("State","WindowMaximized");
    }
    if (mode == DARK_THEME) {
        ui->centralWidget->setStyleSheet(getStyleFile(":/module_mainwindow/qss/centralWidget_dark.qss"));
    } else if (mode == LIGHT_THEME) {
        ui->centralWidget->setStyleSheet(getStyleFile(":/module_mainwindow/qss/centralWidget_light.qss"));
    } else if (mode == BLUE_THEME) {
        ui->centralWidget->setStyleSheet(getStyleFile(":/module_mainwindow/qss/centralWidget_blue.qss"));
    }
}
void MainWindow::checkNewVersion()
{
    //检测
    QSslConfiguration sslConfig = QSslConfiguration::defaultConfiguration();

    //qDebug() << "默认配置" << sslConfig.peerVerifyMode();
    sslConfig.setPeerVerifyMode(QSslSocket::VerifyNone);
    //qDebug() << "现在配置" << sslConfig.peerVerifyMode();

    sslConfig.setProtocol(QSsl::SslProtocol::AnyProtocol);
    QSslConfiguration::setDefaultConfiguration(sslConfig);

    QNetworkAccessManager manager;
    QUrl url("https://api.github.com/repos/HuaGouFdog/Fdog-Kit/releases/latest");
    QNetworkRequest request;
    request.setUrl(url);
    QNetworkReply* reply = manager.get(request);

        QEventLoop loop;
        QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
        loop.exec();

        // 检查错误
        if (reply->error() != QNetworkReply::NoError) {
            qDebug() << "请求失败:" << reply->errorString();
        } else {
            //qDebug() << "请求成功";
            //qDebug() << "响应:" << reply->readAll();
            QByteArray responseData = reply->readAll();
            QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);
            if (!jsonDoc.isNull()) {
                if (jsonDoc.isObject()) {
                    QJsonObject jsonObj = jsonDoc.object();

                    QString tagName = jsonObj.value("tag_name").toString();
                    QString body = jsonObj.value("body").toString();
                    newVersion = tagName;
                    NewVersionData = body;
                    //qDebug() << "tag_name:" << tagName;
                    //qDebug() << "body:" << body;


                    QJsonArray assetsArray = jsonObj.value("assets").toArray();

                    for (const QJsonValue &assetValue : assetsArray) {
                        if (assetValue.isObject()) {
                            QJsonObject assetObj = assetValue.toObject();
                            QString browserDownloadUrl = assetObj.value("browser_download_url").toString();
                            NewVersiondownLoad = browserDownloadUrl;
                            //qDebug() << "browser_download_url:" << browserDownloadUrl;
                        }
                    }
                } else {
                    qDebug() << "响应不是有效的 JSON 对象";
                }
            } else {
                qDebug() << "无法解析 JSON 响应";
            }
        }
        // 清理
        reply->deleteLater();

        //判断有没有新版本生成
        if (isVersionGreater(newVersion, ui->label_side_version->text())) {
            ui->toolButton_newVersion->show();
            ui->toolButton_newVersion->setIcon(QIcon(":lib/node.png"));
            ui->toolButton_newVersion->setToolTip("当前有新版本，点击查看");
        } else {
            qDebug() << "没有新版本";
        }
        
}

void MainWindow::on_toolButton_close_clicked()
{
    this->close();
}

void MainWindow::closeWindow()
{
    this->close();
}

void MainWindow::on_toolButton_min_clicked()
{
    this->showMinimized();
}

void MainWindow::minWindow()
{
    this->showMinimized();
}

void MainWindow::maxWindow()
{
    //mWindow
}

void MainWindow::trayIconActivated(QSystemTrayIcon::ActivationReason reason)
{
    if (reason == QSystemTrayIcon::Trigger) {
        // 处理单击事件，例如还原窗口
        //qDebug() << "点击";
        //this->showMaximized();
        //restoreWindow();
    } else if (reason == QSystemTrayIcon::DoubleClick) {
        // 处理双击事件
        // 双击任务栏图标时的操作
    } else if (reason == QSystemTrayIcon::Context) {
        // 处理右键点击事件
        // 右键点击任务栏图标时的操作
    }
    // 其他操作
}

void MainWindow::restoreWindow()
{

}

void MainWindow::on_toolButton_max_clicked()
{
    if (!showFlag) {
        qDebug() << "最大化开始";
        setContentsMargins(0, 0, 0, 0);
        this->setWindowState(Qt::WindowState::WindowMaximized);
        //changeMainWindowTheme(false, 2);
        qDebug() << "最大化结束";
        isMaxShow = true;
        showFlag = true;
    } else {
        qDebug() << "正常开始";
        setContentsMargins(10, 10, 10, 10);
        this->setWindowState(Qt::WindowState::WindowNoState);
        qDebug() << "正常结束";
        isMaxShow = false;
        showFlag = false;
    }
}

void MainWindow::rece_newConnnect(connnectInfoStruct& cInfoStruct)
{
    //qDebug() << cInfoStruct.connectType;
    QSize iconSize(16, 16); // 设置图标的大小

    if (cInfoStruct.connectType == SSH_CONNECT_TYPE) {
        on_toolButton_side_shell_clicked();
        smanagewidget->newSSHWidget(cInfoStruct, confInfo);
        smanagewidget->db->ssh_insertSSHInfo(cInfoStruct);
        smanagewidget->hcwidget->loadSSHinfo(cInfoStruct);
    } else if (cInfoStruct.connectType == WINDOWS_CONNECT_TYPE) {

    } else if (cInfoStruct.connectType == ZK_CONNECT_TYPE) {
        on_toolButton_side_zookeeper_clicked();
        zmanagewidget->newZKWidget(cInfoStruct);
    } else if (cInfoStruct.connectType == REDIS_CONNECT_TYPE) {
        //ui->tabWidget->addTab(&zkwidget4, QIcon(":lib/Redis.png").pixmap(iconSize), "172.16.8.153");
    } else if (cInfoStruct.connectType == KAFKA_CONNECT_TYPE) {
        //ui->tabWidget->addTab(&zkwidget3, QIcon(":lib/Kafka.png").pixmap(iconSize), "172.16.8.157");
    } else if (cInfoStruct.connectType == DB_CONNECT_TYPE) {
        //ui->tabWidget->addTab(&zkwidget2, QIcon(":lib/db.png").pixmap(iconSize), "172.16.8.166");
    }
}

void MainWindow::rece_newSave(connnectInfoStruct& cInfoStruct) {
    if (cInfoStruct.connectType == SSH_CONNECT_TYPE) {
        on_toolButton_side_shell_clicked();
        smanagewidget->db->ssh_insertSSHInfo(cInfoStruct);
        smanagewidget->hcwidget->loadSSHinfo(cInfoStruct);
    } else if (cInfoStruct.connectType == WINDOWS_CONNECT_TYPE) {

    } else if (cInfoStruct.connectType == ZK_CONNECT_TYPE) {
        //on_toolButton_side_zookeeper_clicked();
        //zmanagewidget->newZKWidget(cInfoStruct);
    } else if (cInfoStruct.connectType == REDIS_CONNECT_TYPE) {
        //ui->tabWidget->addTab(&zkwidget4, QIcon(":lib/Redis.png").pixmap(iconSize), "172.16.8.153");
    } else if (cInfoStruct.connectType == KAFKA_CONNECT_TYPE) {
        //ui->tabWidget->addTab(&zkwidget3, QIcon(":lib/Kafka.png").pixmap(iconSize), "172.16.8.157");
    } else if (cInfoStruct.connectType == DB_CONNECT_TYPE) {
        //ui->tabWidget->addTab(&zkwidget2, QIcon(":lib/db.png").pixmap(iconSize), "172.16.8.166");
    }
}

void MainWindow::rece_windowsSetting() {
    //设置终端
    //切换至设置
    on_toolButton_side_setting_clicked();
    //跳转到终端
    stwidget->getTerminalSetting();
}

void MainWindow::on_newClose()
{
    //qDebug() << "删除";
    delete(ccwidget);
    ccwidget = nullptr;
}

void MainWindow::on_widget_welcome_body_widget2_newCreate_newTerminal_clicked()
{
    //新建终端
    int8_t connectType = 1;
    ccwidget = new createconnect(connectType);
    connect(ccwidget,SIGNAL(newCreate(connnectInfoStruct&)),this,SLOT(rece_newConnnect(connnectInfoStruct&)));
    connect(ccwidget,SIGNAL(newSave(connnectInfoStruct&)),this,SLOT(rece_newSave(connnectInfoStruct&)));
    ccwidget->show();
}

void MainWindow::rece_toolButton_fullScreen_sign()
{
    qDebug() << "isFullScreen = " <<isFullScreen;
    if (!isFullScreen) {
        setContentsMargins(0, 0, 0, 0);
        changeMainWindowTheme(false, 2);
        ui->toolButton_min->hide();
        ui->toolButton_max->hide();
        ui->toolButton_close->hide();
        this->showFullScreen();
        isFullScreen = true;
    } else {
        ui->toolButton_min->show();
        ui->toolButton_max->show();
        ui->toolButton_close->show();
        setContentsMargins(10, 10, 10, 10);
        
        if (showFlag) {
            setContentsMargins(0, 0, 0, 0);
            changeMainWindowTheme(false, 2);
            this->showMaximized();
        } else {
            changeMainWindowTheme(false, 1);
            this->showNormal();
        }
        isFullScreen = false;
    }

}


void MainWindow::rece_systemTrayMenu()
{
    //获取发送者
    QString toolName;
    QString actionText = qobject_cast<QAction*>(sender())->text();
    int8_t connectType = 0;
    //创建连接窗口
    if (actionText == "打开") {
        //打开
        this->showNormal();
    } else {
        //退出
        qApp->quit();
    }
}

void MainWindow::on_toolButton_zk_tool_clicked()
{
    //新建终端
    int8_t connectType = 3;
    ccwidget = new createconnect(connectType);
    connect(ccwidget,SIGNAL(newCreate(connnectInfoStruct&)),this,SLOT(rece_newConnnect(connnectInfoStruct&)));
    ccwidget->show();
}

void MainWindow::on_toolButton_side_theme_clicked()
{
    //修改主题
    if (this->windowState() == Qt::WindowNoState) {
        changeMainWindowTheme(true, 1);
    } else if (this->windowState() == Qt::WindowMaximized) {
        changeMainWindowTheme(true, 2);
    }
    return;
}

void MainWindow::on_toolButton_side_setting_clicked()
{
    //设置页面
    if (stwidget == NULL) {
        stwidget = new settingwidget(confInfo);
        stwidget->setObjectName("stwidget");
        ui->stackedWidget->addWidget(stwidget);
        stwidget->show();
        ui->stackedWidget->setCurrentIndex(ui->stackedWidget->count()-1);
    } else {
        int widgetCount = ui->stackedWidget->count();
        for (int i = 0; i < widgetCount; ++i) {
            // 获取索引处的widget
            QWidget *widget = ui->stackedWidget->widget(i);
            if (widget->objectName() == "stwidget") {
                ui->stackedWidget->setCurrentIndex(i);
            }
        }
    }
}

void MainWindow::on_toolButton_side_thrift_clicked()
{
    if (twidget == NULL) {
        twidget = new thriftwidget();
        twidget->setObjectName("twidget");
        ui->stackedWidget->addWidget(twidget);
        twidget->show();
        ui->stackedWidget->setCurrentIndex(ui->stackedWidget->count()-1);
        QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(this);
        ui->stackedWidget->setGraphicsEffect(eff);
        QPropertyAnimation *a = new QPropertyAnimation(eff,"opacity");
        a->setDuration(50);
        a->setStartValue(0);
        a->setEndValue(1);
        a->setEasingCurve(QEasingCurve::InBack);
        a->start(QPropertyAnimation::DeleteWhenStopped);
        connect(a, SIGNAL(finished()), this, SLOT(whenAnimationFinish()));
    } else {
        int widgetCount = ui->stackedWidget->count();
        for (int i = 0; i < widgetCount; ++i) {
            // 获取索引处的widget
            QWidget *widget = ui->stackedWidget->widget(i);
            if (widget->objectName() == "twidget") {
                if(ui->stackedWidget->currentIndex() != i) {
                    ui->stackedWidget->setCurrentIndex(i);
                    QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(this);
                    ui->stackedWidget->setGraphicsEffect(eff);
                    QPropertyAnimation *a = new QPropertyAnimation(eff,"opacity");
                    a->setDuration(200);
                    a->setStartValue(0);
                    a->setEndValue(1);
                    a->setEasingCurve(QEasingCurve::InBack);
                    a->start(QPropertyAnimation::DeleteWhenStopped);
                    connect(a, SIGNAL(finished()), this, SLOT(whenAnimationFinish()));
                }
                return;
            }
        }
    }
}

void MainWindow::on_toolButton_side_zookeeper_clicked()
{
    if (zmanagewidget == NULL) {
        zmanagewidget = new zookeepermanagewidget();
        zmanagewidget->setObjectName("zmanagewidget");
        ui->stackedWidget->addWidget(zmanagewidget);
        zmanagewidget->show();
        ui->stackedWidget->setCurrentIndex(ui->stackedWidget->count()-1);
        QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(this);
        ui->stackedWidget->setGraphicsEffect(eff);
        QPropertyAnimation *a = new QPropertyAnimation(eff,"opacity");
        a->setDuration(50);
        a->setStartValue(0);
        a->setEndValue(1);
        a->setEasingCurve(QEasingCurve::InBack);
        a->start(QPropertyAnimation::DeleteWhenStopped);
        connect(a, SIGNAL(finished()), this, SLOT(whenAnimationFinish()));
    } else {
        int widgetCount = ui->stackedWidget->count();
        for (int i = 0; i < widgetCount; ++i) {
            // 获取索引处的widget
            QWidget *widget = ui->stackedWidget->widget(i);
            if (widget->objectName() == "zmanagewidget") {
                if(ui->stackedWidget->currentIndex() != i) {
                    ui->stackedWidget->setCurrentIndex(i);
                    QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(this);
                    ui->stackedWidget->setGraphicsEffect(eff);
                    QPropertyAnimation *a = new QPropertyAnimation(eff,"opacity");
                    a->setDuration(200);
                    a->setStartValue(0);
                    a->setEndValue(1);
                    a->setEasingCurve(QEasingCurve::InBack);
                    a->start(QPropertyAnimation::DeleteWhenStopped);
                    connect(a, SIGNAL(finished()), this, SLOT(whenAnimationFinish()));
                }

                return;
            }
        }
    }
}

// void MainWindow::on_toolButton_side_github_clicked()
// {
//     QDesktopServices::openUrl(QUrl(QLatin1String("https://github.com/HuaGouFdog/Fdog-Kit")));
// }

// void MainWindow::on_toolButton_side_about_clicked()
// {
// //    awidget = new aboutwidget();
// //    QPoint globalPos = this->mapToGlobal(QPoint(0,0));//父窗口绝对坐标
// //    int x = globalPos.x() + (this->width() - awidget->width()) / 2;//x坐标
// //    int y = globalPos.y() + (this->height() - awidget->height()) / 2;//y坐标
// //    awidget->move(x, y);//窗口移动
// //    awidget->show();
// }

void MainWindow::on_toolButton_side_home_clicked()
{
    if(ui->stackedWidget->currentIndex() != 0) {
        ui->stackedWidget->setCurrentIndex(0);
    }
    QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(this);
    ui->stackedWidget->setGraphicsEffect(eff);
    QPropertyAnimation *a = new QPropertyAnimation(eff,"opacity");
    a->setDuration(50);
    a->setStartValue(0);
    a->setEndValue(1);
    a->setEasingCurve(QEasingCurve::InBack);
    a->start(QPropertyAnimation::DeleteWhenStopped);
    connect(a, SIGNAL(finished()), this, SLOT(whenAnimationFinish()));
}

void MainWindow::on_toolButton_side_shell_clicked()
{

    if (smanagewidget == nullptr) {
        smanagewidget = new sshwidgetmanagewidget(confInfo);
        smanagewidget->setObjectName("smanagewidget");
        ui->stackedWidget->addWidget(smanagewidget);
        smanagewidget->show();
        ui->stackedWidget->setCurrentIndex(ui->stackedWidget->count()-1);
        QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(this);
        ui->stackedWidget->setGraphicsEffect(eff);
        QPropertyAnimation *a = new QPropertyAnimation(eff,"opacity");
        a->setDuration(50);
        a->setStartValue(0);
        a->setEndValue(1);
        a->setEasingCurve(QEasingCurve::InBack);
        a->start(QPropertyAnimation::DeleteWhenStopped);
        connect(a, SIGNAL(finished()), this, SLOT(whenAnimationFinish()));
    } else {
        int widgetCount = ui->stackedWidget->count();
        for (int i = 0; i < widgetCount; ++i) {
            // 获取索引处的widget
            QWidget *widget = ui->stackedWidget->widget(i);
            if (widget->objectName() == "smanagewidget") {
                if(ui->stackedWidget->currentIndex() != i) {
                    ui->stackedWidget->setCurrentIndex(i);
                    QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(this);
                    ui->stackedWidget->setGraphicsEffect(eff);
                    QPropertyAnimation *a = new QPropertyAnimation(eff,"opacity");
                    a->setDuration(200);
                    a->setStartValue(0);
                    a->setEndValue(1);
                    a->setEasingCurve(QEasingCurve::InBack);
                    a->start(QPropertyAnimation::DeleteWhenStopped);
                    connect(a, SIGNAL(finished()), this, SLOT(whenAnimationFinish()));
                }

                return;
            }
        }
    }

    return;
}

void MainWindow::on_toolButton_side_tool_clicked()
{
    if (tswidget == NULL) {
        tswidget = new toolswidget();
        tswidget->setObjectName("tswidget");
        ui->stackedWidget->addWidget(tswidget);
        tswidget->show();
        ui->stackedWidget->setCurrentIndex(ui->stackedWidget->count()-1);
    } else {
        int widgetCount = ui->stackedWidget->count();
        for (int i = 0; i < widgetCount; ++i) {
            // 获取索引处的widget
            QWidget *widget = ui->stackedWidget->widget(i);
            if (widget->objectName() == "tswidget") {
                ui->stackedWidget->setCurrentIndex(i);
            }
        }
    }
}

void MainWindow::on_toolButton_side_qss_clicked()
{
    if (qsswidget == NULL) {
        qsswidget = new qss();
        qsswidget->setObjectName("qsswidget");
        ui->stackedWidget->addWidget(qsswidget);
        qsswidget->show();
        ui->stackedWidget->setCurrentIndex(ui->stackedWidget->count()-1);
    } else {
        int widgetCount = ui->stackedWidget->count();
        for (int i = 0; i < widgetCount; ++i) {
            // 获取索引处的widget
            QWidget *widget = ui->stackedWidget->widget(i);
            if (widget->objectName() == "qsswidget") {
                ui->stackedWidget->setCurrentIndex(i);
            }
        }
    }
}

void MainWindow::on_toolButton_side_mysql_clicked()
{
    // sqlhandle * db_ = new sqlhandle();
    // db_->sql_mysql_init();
}

void MainWindow::on_toolButton_newVersion_clicked()
{
    QString data = NewVersionData + "\n" + "下载地址：\n" + NewVersiondownLoad;
    QMessageBox::about(this, "发现新版本" + newVersion, data);
}

void MainWindow::whenAnimationFinish()
{
    ui->stackedWidget->setGraphicsEffect(0); // remove effect
}

void MainWindow::on_toolButton_more_clicked()
{
    QDesktopServices::openUrl(QUrl(QLatin1String("https://github.com/HuaGouFdog/Fdog-Kit")));
}

