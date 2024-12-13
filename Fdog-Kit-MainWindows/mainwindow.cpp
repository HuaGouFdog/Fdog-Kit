#pragma execution_character_set("utf-8")
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "module_zookeeper/zookeepermanagewidget.h"
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
#include <QFormLayout>
#include <QDesktopWidget>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);
    // QMainWindow透明显示，当设置主显示窗口的外边距时，防止外边距显示出来。
    this->setAttribute(Qt::WA_TranslucentBackground, true);

    setContentsMargins(10, 10, 10, 10);
    ui->toolButton_max_2->setIcon(QIcon(":lib/Icon_max4.png"));

    //设置阴影效果
    defaultShadow = new QGraphicsDropShadowEffect();
    //模糊半径
    defaultShadow->setBlurRadius(15);
    //颜色值
    defaultShadow->setColor(QColor(0, 0, 0));
    //横纵偏移量
    defaultShadow->setOffset(0, 0);
    //不要直接给this，会报UpdateLayeredWindowIndirect failed
    ui->centralWidget->setGraphicsEffect(defaultShadow);

    HWND hwnd = (HWND)this->winId();
    DWORD style = ::GetWindowLong(hwnd, GWL_STYLE);
    SetWindowLong(hwnd, GWL_STYLE, style | WS_MAXIMIZEBOX | WS_THICKFRAME | WS_CAPTION | CS_DBLCLKS);


    //快捷键 F11 全屏
    QShortcut *shortcut = new QShortcut(QKeySequence(Qt::Key_F11), this);
    connect(shortcut, SIGNAL(activated()), this, SLOT(rece_toolButton_fullScreen_sign()));

    setSupportStretch(true);
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
    if(ui->widget_title->underMouse() && !showFlag) {
        setContentsMargins(0, 0, 0, 0);
        ui->centralWidget->setStyleSheet("#centralWidget {border-image: url(:/lib/back1.png);border-radius:0px;}");
        ui->toolButton_close_2->setStyleSheet("QToolButton {\
                                                color: rgb(255, 255, 255);\
                                                border-top-right-radius: 0px;\
                                                background-color: rgba(94, 255, 210, 0);\
                                                border: none;\
                                            }\
                                            QToolButton::menu-indicator { \
                                                image: None;\
                                            }\
                                            QToolButton:hover {\
                                                color: rgb(255, 255, 255);\
                                                background-color: rgb(200, 0, 0);\
                                                border: none;\
                                            }");
        setWindowState(Qt::WindowMaximized);
        showFlag = true;
    } else if (ui->widget_title->underMouse() && showFlag) {
        setContentsMargins(10, 10, 10, 10);
        ui->centralWidget->setStyleSheet("#centralWidget {border-image: url(:/lib/back1.png);border-radius:10px;}");
        ui->toolButton_close_2->setStyleSheet("QToolButton {\
                                                color: rgb(255, 255, 255);\
                                                border-top-right-radius: 9px;\
                                                background-color: rgba(94, 255, 210, 0);\
                                                border: none;\
                                            }\
                                            QToolButton::menu-indicator { \
                                                image: None;\
                                            }\
                                            QToolButton:hover {\
                                                color: rgb(255, 255, 255);\
                                                background-color: rgb(200, 0, 0);\
                                                border: none;\
                                            }");
        ui->toolButton_max_2->setIcon(QIcon(":lib/Icon_max4.png"));
        this->showNormal();
        showFlag = false;
    }
}

// void MainWindow::resizeEvent(QResizeEvent *event)
// {
//     qDebug() << "resizeEvent 被调用";
//     //QTextEdit::resizeEvent(event);
// }

void MainWindow::showEvent(QShowEvent *event)
{
    qDebug() << "showEvent 被调用";
    calculateCurrentStrechRect();
    //return MainWindow::showEvent(event);
}

bool MainWindow::nativeEvent(const QByteArray &eventType, void *message, long *result)
{
    MSG* msg = (MSG*)message;
    switch (msg->message) {
    //没有这一段，将不会显示窗口
    case WM_NCCALCSIZE:
        return true;

    //最大化是填充屏幕
    case WM_GETMINMAXINFO:
    {
        if (::IsZoomed(msg->hwnd)) {
            // 最大化时会超出屏幕，所以填充边框间距
            RECT frame = { 0, 0, 0, 0 };
            AdjustWindowRectEx(&frame, WS_OVERLAPPEDWINDOW, FALSE, 0);
            frame.left = abs(frame.left);
            frame.top = abs(frame.bottom);
            this->setContentsMargins(frame.left, frame.top, frame.right, frame.bottom);
        }
        *result = ::DefWindowProc(msg->hwnd, msg->message, msg->wParam, msg->lParam);
        return true;
    }
        break;
    }
    return QMainWindow::nativeEvent(eventType, message, result);
}

void MainWindow::createSystemTray()
{
    // 创建系统托盘图标
    trayIcon = new QSystemTrayIcon(QIcon(":lib/icon9.png"), this);
    trayIcon->setToolTip("Fdog-Kit");
    trayIcon->show();

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

}

void MainWindow::on_toolButton_close_2_clicked()
{
    this->close();
}

void MainWindow::on_toolButton_min_2_clicked()
{
    this->showMinimized();
}

void MainWindow::on_toolButton_max_2_clicked()
{
    //qDebug() << "显示最大化";
    //最大化
    if (!showFlag) {
        //ui->centralWidget->setEnabled(false);
        setContentsMargins(0, 0, 0, 0);
        this->setWindowState(Qt::WindowState::WindowMaximized);
        ui->centralWidget->setStyleSheet("#centralWidget {background-color: rgb(67, 67, 67);border-image: url(:/lib/back1.png);border-radius:0px;}");
        ui->toolButton_close_2->setStyleSheet("QToolButton {\
                                                color: rgb(255, 255, 255);\
                                                border-top-right-radius: 0px;\
                                                background-color: rgba(94, 255, 210, 0);\
                                                border: none;\
                                            }\
                                            QToolButton::menu-indicator { \
                                                image: None;\
                                            }\
                                            QToolButton:hover {\
                                                color: rgb(255, 255, 255);\
                                                background-color: rgb(200, 0, 0);\
                                                border: none;\
                                            }");
        ui->toolButton_max_2->setIcon(QIcon(":lib/icon-copy.png"));
        //this->showMaximized();
        //ui->centralWidget->setEnabled(true);
        isMaxShow = true;
        showFlag = true;
    } else {
        setContentsMargins(10, 10, 10, 10); //rgb(67, 77, 88)
        this->showNormal();
        this->setWindowState(Qt::WindowState::WindowNoState);
        ui->centralWidget->setStyleSheet("#centralWidget {background-color: rgb(67, 67, 67);border-image: url(:/lib/back1.png);border-radius:10px;}");
        ui->toolButton_close_2->setStyleSheet("QToolButton {\
                                                color: rgb(255, 255, 255);\
                                                border-top-right-radius: 9px;\
                                                background-color: rgba(94, 255, 210, 0);\
                                                border: none;\
                                            }\
                                            QToolButton::menu-indicator { \
                                                image: None;\
                                            }\
                                            QToolButton:hover {\
                                                color: rgb(255, 255, 255);\
                                                background-color: rgb(200, 0, 0);\
                                                border: none;\
                                            }");
        ui->toolButton_max_2->setIcon(QIcon(":lib/Icon_max4.png"));

        isMaxShow = false;
        showFlag = false;
        }
        }

void MainWindow::closeWindow()
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

void MainWindow::rece_toolButton_fullScreen_sign()
{
    qDebug() << "isFullScreen = " <<isFullScreen;
    if (!isFullScreen) {
        setContentsMargins(0, 0, 0, 0);
        ui->centralWidget->setStyleSheet("#centralWidget {border-image: url(:/lib/back1.png);border-radius:0px;}");
        ui->toolButton_max_2->setIcon(QIcon(":lib/icon-copy.png"));
        //this->showNormal();
        ui->toolButton_min_2->hide();
        ui->toolButton_max_2->hide();
        ui->toolButton_close_2->hide();
        this->showFullScreen();
        isFullScreen = true;
    } else {
        ui->toolButton_min_2->show();
        ui->toolButton_max_2->show();
        ui->toolButton_close_2->show();
        setContentsMargins(10, 10, 10, 10); //rgb(67, 77, 88)
        ui->centralWidget->setStyleSheet("#centralWidget {border-image: url(:/lib/back1.png);border-radius:10px;}");
        ui->toolButton_max_2->setIcon(QIcon(":lib/Icon_max4.png"));
        if (showFlag) {
            ui->centralWidget->setStyleSheet("#centralWidget {border-image: url(:/lib/back1.png);border-radius:0px;}");
            setContentsMargins(0, 0, 0, 0);
            ui->toolButton_max_2->setIcon(QIcon(":lib/icon-copy.png"));
            this->showMaximized();
        } else {
            this->showNormal();
        }
        isFullScreen = false;
    }

}




MainWindow::~MainWindow()
{
    delete ui;
}
