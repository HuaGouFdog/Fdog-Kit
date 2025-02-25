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
#include <QFormLayout>
#include <QDesktopWidget>
#include <QToolButton>
#include <QEventLoop>
#include <QTimer>
#include "windows.h"
#include "windowsx.h"
#include "module_utils/utils.h"
#include "module_smalltool/smalltoolwidget.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::MainWindow(config * m_confInfo, QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->label_side_icon_2->hide();

    m_unfoldButton = new QToolButton(this);
    m_unfoldButton->setStyleSheet("QToolButton {\
                     color: rgb(217, 236, 237);\
                     background-color: rgba(255, 60, 128, 0);\
                     border: none;\
                 }\
                 QToolButton::menu-indicator { \
                     image: None;\
                 }\
                 QToolButton:hover {\
                     color: rgb(197, 197, 197);\
                     border: none;\
                 }");
    m_unfoldButton->setIcon(QIcon(":/module_mainwindow/images/light/unfold-light.png"));
    m_unfoldButton->setGeometry(3, this->height()/2, 25, 100);
    m_unfoldButton->setIconSize(QSize(50, 50));
    m_unfoldButton->hide();
    connect(m_unfoldButton, &QPushButton::clicked, this, [=]() {
        qDebug() << "展开前 ui->widget_side->width() = " << ui->widget_side->width();
        ui->label_side_icon_2->hide();
        m_unfoldButton->hide();
        // m_propertyAnimation2 = new QPropertyAnimation(ui->widget_side,"geometry");
        // m_propertyAnimation2->setEasingCurve(QEasingCurve::InCubic);
        // m_propertyAnimation2->setDuration(300);
        // m_propertyAnimation2->setStartValue(QRect(ui->widget_side->geometry().x(),ui->widget_side->geometry().y(),0,ui->widget_side->height()));
        // m_propertyAnimation2->setEndValue(QRect(ui->widget_side->geometry().x(),ui->widget_side->geometry().y(),50,ui->widget_side->height()));
        // connect(m_propertyAnimation2, SIGNAL(finished()), this, SLOT(whenAnimationFinish3()));
        // qDebug() << "setFixedWidth ui->widget_side->height() = " << ui->widget_side->height();
        // qDebug() << "setFixedWidth ui->widget_side->width() = " << ui->widget_side->width();
        ui->widget_side->show();
        qDebug() << "ui->widget_side->height() = " << ui->widget_side->height();
        qDebug() << "ui->widget_side->width() = " << ui->widget_side->width();
        qDebug() << "显示边框";
        //m_propertyAnimation2->start(QAbstractAnimation::DeleteWhenStopped);
    });

    //main.cpp传进来的m_confInfo
    this->m_confInfo = m_confInfo;
    //根据配置文件判断要隐藏的功能
    if (m_confInfo->autoPackage == 0) { ui->toolButton_side_build->hide(); }
    if (m_confInfo->thrift == 0) { ui->toolButton_side_thrift->hide(); }
    if (m_confInfo->zookeeper == 0) { ui->toolButton_side_zookeeper->hide(); }
    if (m_confInfo->shell == 0) { ui->toolButton_side_shell->hide(); }
    if (m_confInfo->db == 0) { ui->toolButton_side_mysql->hide(); }
    if (m_confInfo->qss == 0) { ui->toolButton_side_qss->hide(); }
    if (m_confInfo->tool == 0) { ui->toolButton_side_tool->hide(); }
    if (m_confInfo->extend == 0) { ui->toolButton_side_plugIn->hide(); }

    //根据centralWidget背景设置阴影
    getGraphicsEffectUtils(ui->centralWidget, 0, 0, 20, QColor(35, 39, 46));

    // //设置全局样式表
    changeMainWindowTheme();

    // //设置无边框窗口相关属性
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint); //顶置 Qt::WindowStaysOnTopHint
    //QMainWindow透明显示，当设置主显示窗口的外边距时，防止外边距显示出来。
    setAttribute(Qt::WA_PaintOnScreen, false);
    setAttribute(Qt::WA_NoSystemBackground, false);
    this->setAttribute(Qt::WA_TranslucentBackground, true);
    // //设置内边距,用于显示阴影
    setContentsMargins(10, 10, 10, 10);

    // //窗口标题最小化，最大化，靠边停靠都在这里实现
    HWND hwnd = (HWND)this->winId();
    DWORD style = ::GetWindowLong(hwnd, GWL_STYLE);
    SetWindowLong(hwnd, GWL_STYLE, style | WS_MAXIMIZEBOX | WS_THICKFRAME | WS_CAPTION | CS_DBLCLKS);

    // const MARGINS rShadowMargin = { 1, 1, 1, 1 };
    // DwmExtendFrameIntoClientArea(hwnd, &rShadowMargin);

    //快捷键 F11 全屏
    QShortcut *shortcut = new QShortcut(QKeySequence(Qt::Key_F11), this);
    connect(shortcut, SIGNAL(activated()), this, SLOT(rece_toolButton_fullScreen_sign()));

    //界面归位,显示主界面
    ui->stackedWidget->setCurrentIndex(0);
    //设置窗口样式
    setWindowsByConf();
    //启动窗口鼠标跟随事件
    setSupportStretch(this, true);
    //隐藏新版本相关控件
    ui->toolButton_newVersion->setToolTip("");
    ui->toolButton_newVersion->setIcon(QIcon());
    ui->toolButton_newVersion->hide();

    //检测新版本
    //checkNewVersion();
    //设置系统托盘
    createSystemTray();
}

MainWindow::~MainWindow() {
    //需要释放指针
    delete ui;
}

void MainWindow::calculateCurrentStrechRect() {
    // 四个角的Rect;
    m_leftTopRect = QRect(0, 0, STRETCH_RECT_WIDTH, STRETCH_RECT_HEIGHT);
    m_leftBottomRect = QRect(0, this->height() - STRETCH_RECT_HEIGHT, STRETCH_RECT_WIDTH, STRETCH_RECT_WIDTH);
    m_rightTopRect = QRect(this->width() - STRETCH_RECT_WIDTH, 0, STRETCH_RECT_WIDTH, STRETCH_RECT_HEIGHT);
    m_rightBottomRect = QRect(this->width() - STRETCH_RECT_WIDTH, this->height() - STRETCH_RECT_HEIGHT, STRETCH_RECT_WIDTH, STRETCH_RECT_HEIGHT);
    // 四条边的Rect;
    m_topBorderRect = QRect(STRETCH_RECT_WIDTH, 0, this->width() - STRETCH_RECT_WIDTH * 2, STRETCH_RECT_HEIGHT);
    m_rightBorderRect = QRect(this->width() - STRETCH_RECT_WIDTH, STRETCH_RECT_HEIGHT, STRETCH_RECT_WIDTH, this->height() - STRETCH_RECT_HEIGHT * 2);
    m_bottomBorderRect = QRect(STRETCH_RECT_WIDTH, this->height() - STRETCH_RECT_HEIGHT, this->width() - STRETCH_RECT_WIDTH * 2, STRETCH_RECT_HEIGHT);
    m_leftBorderRect = QRect(0, STRETCH_RECT_HEIGHT, STRETCH_RECT_WIDTH, this->height() - STRETCH_RECT_HEIGHT * 2);
}

WindowStretchRectState MainWindow::getCurrentStretchState(QPoint cursorPos) {
    WindowStretchRectState stretchState;
    if (m_leftTopRect.contains(cursorPos)) { stretchState = LEFT_TOP_RECT; }
    else if (m_rightTopRect.contains(cursorPos)) { stretchState = RIGHT_TOP_RECT; }
    else if (m_rightBottomRect.contains(cursorPos)) { stretchState = RIGHT_BOTTOM_RECT; }
    else if (m_leftBottomRect.contains(cursorPos)) { stretchState = LEFT_BOTTOM_RECT; }
    else if (m_topBorderRect.contains(cursorPos)) { stretchState = TOP_BORDER; }
    else if (m_rightBorderRect.contains(cursorPos)) { stretchState = RIGHT_BORDER; }
    else if (m_bottomBorderRect.contains(cursorPos)) { stretchState = BOTTOM_BORDER; }
    else if (m_leftBorderRect.contains(cursorPos)) { stretchState = LEFT_BORDER; }
    else { stretchState = NO_SELECT; }
    return stretchState;
}

void MainWindow::updateMouseStyle(WindowStretchRectState stretchState) {
    if (m_isMaxShow) { return; }
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

void MainWindow::updateWindowSize() {
    if (m_isMaxShow) { return; }
    // 拉伸时要注意设置窗口最小值
    QRect windowRect = m_windowRectBeforeStretch;
    int delValue_X = m_startPoint.x() - m_endPoint.x();
    int delValue_Y = m_startPoint.y() - m_endPoint.y();
    int m_windowMinWidth = 600;
    int m_windowMinHeight = 600;
    if (m_stretchRectState == LEFT_BORDER) {
        if (this->geometry().width() <= m_windowMinWidth && delValue_X <= 0) {
            return;
        }
        QPoint bottomLeftPoint = windowRect.bottomLeft();
        bottomLeftPoint.setX(bottomLeftPoint.x() - delValue_X);
        windowRect.setBottomLeft(bottomLeftPoint);
        this->setGeometry(windowRect);
    } else if (m_stretchRectState == RIGHT_BORDER) {
        QPoint bottomRightPoint = windowRect.bottomRight();
        bottomRightPoint.setX(bottomRightPoint.x() - delValue_X);
        windowRect.setBottomRight(bottomRightPoint);
        this->setGeometry(windowRect);
    } else if (m_stretchRectState == TOP_BORDER) {
        if (this->geometry().height() <= m_windowMinHeight && delValue_Y <= 0) {
            return;
        }
        QPoint topLeftPoint = windowRect.topLeft();
        topLeftPoint.setY(topLeftPoint.y() - delValue_Y);
        windowRect.setTopLeft(topLeftPoint);
        this->setGeometry(windowRect);
    } else if (m_stretchRectState == BOTTOM_BORDER)  {
        QPoint bottomRightPoint = windowRect.bottomRight();
        bottomRightPoint.setY(bottomRightPoint.y() - delValue_Y);
        windowRect.setBottomRight(bottomRightPoint);
        this->setGeometry(windowRect);
    } else if (m_stretchRectState == LEFT_TOP_RECT) {
        if (this->geometry().width() - 3 <= m_windowMinWidth && delValue_X <= 0
                && this->geometry().height() -3 <= m_windowMinHeight && delValue_Y <= 0) {
            return;
        }
        int a = 0;
        if (this->geometry().width() - 3 <= m_windowMinWidth && delValue_X <= 0) {
            a = 1;
        }
        if (this->geometry().height() - 3 <= m_windowMinHeight && delValue_Y <= 0) {
            a = 2;
        }
        if (a == 0) {
            QPoint topLeftPoint = windowRect.topLeft();
            topLeftPoint.setX(topLeftPoint.x() - delValue_X);
            topLeftPoint.setY(topLeftPoint.y() - delValue_Y);
            windowRect.setTopLeft(topLeftPoint);
            this->setGeometry(windowRect);
        } else if (a == 1) {
            QPoint topLeftPoint = windowRect.topLeft();
            topLeftPoint.setX(this->geometry().x());
            topLeftPoint.setY(topLeftPoint.y() - delValue_Y);
            windowRect.setTopLeft(topLeftPoint);
            this->setGeometry(windowRect);
        } else if (a == 2) {
            QPoint topLeftPoint = windowRect.topLeft();
            topLeftPoint.setX(topLeftPoint.x() - delValue_X);
            topLeftPoint.setY(this->geometry().y());
            windowRect.setTopLeft(topLeftPoint);
            this->setGeometry(windowRect);
        }
    } else if (m_stretchRectState == RIGHT_TOP_RECT) {
        if (this->geometry().width() - 3 <= m_windowMinWidth && delValue_X <= 0
                && this->geometry().height() -3 <= m_windowMinHeight && delValue_Y <= 0) {
            return;
        }
        int a = 0;
        if (this->geometry().width() - 3 <= m_windowMinWidth && delValue_X <= 0) {
            a = 1;
        }
        if (this->geometry().height() - 3 <= m_windowMinHeight && delValue_Y <= 0) {
            a = 2;
        }
        if (a == 0) {
            QPoint topRightPoint = windowRect.topRight();
            topRightPoint.setX(topRightPoint.x() - delValue_X);
            topRightPoint.setY(topRightPoint.y() - delValue_Y);
            windowRect.setTopRight(topRightPoint);
            this->setGeometry(windowRect);
        } else if (a == 1) {
            QPoint topRightPoint = windowRect.topRight();
            topRightPoint.setX(this->geometry().x());
            topRightPoint.setY(topRightPoint.y() - delValue_Y);
            windowRect.setTopRight(topRightPoint);
            this->setGeometry(windowRect);
        } else if (a == 2) {
            QPoint topRightPoint = windowRect.topRight();
            topRightPoint.setX(topRightPoint.x() - delValue_X);
            topRightPoint.setY(this->geometry().y());
            windowRect.setTopRight(topRightPoint);
            this->setGeometry(windowRect);
        }
    } else if (m_stretchRectState == RIGHT_BOTTOM_RECT) {
        QPoint bottomRightPoint = windowRect.bottomRight();
        bottomRightPoint.setX(bottomRightPoint.x() - delValue_X);
        bottomRightPoint.setY(bottomRightPoint.y() - delValue_Y);
        windowRect.setBottomRight(bottomRightPoint);
        this->setGeometry(windowRect);
    } else if (m_stretchRectState == LEFT_BOTTOM_RECT) {
        if (this->geometry().width() - 3 <= m_windowMinWidth && delValue_X <= 0
                && this->geometry().height() -3 <= m_windowMinHeight && delValue_Y <= 0) {
            return;
        }
        int a = 0;
        if (this->geometry().width() - 3 <= m_windowMinWidth && delValue_X <= 0) {
            a = 1;
        }
        if (this->geometry().height() - 3 <= m_windowMinHeight && delValue_Y <= 0) {
            a = 2;
        }
        if (a == 0) {
            QPoint bottomLeftPoint = windowRect.bottomLeft();
            bottomLeftPoint.setX(bottomLeftPoint.x() - delValue_X);
            bottomLeftPoint.setY(bottomLeftPoint.y() - delValue_Y);
            windowRect.setBottomLeft(bottomLeftPoint);
            this->setGeometry(windowRect);
        } else if (a == 1) {
            QPoint bottomLeftPoint = windowRect.bottomLeft();
            bottomLeftPoint.setX(this->geometry().x());
            bottomLeftPoint.setY(bottomLeftPoint.y() - delValue_Y);
            windowRect.setBottomLeft(bottomLeftPoint);
            this->setGeometry(windowRect);
        } else if (a == 2) {
            QPoint bottomLeftPoint = windowRect.bottomLeft();
            bottomLeftPoint.setX(bottomLeftPoint.x() - delValue_X);
            bottomLeftPoint.setY(this->geometry().y());
            windowRect.setBottomLeft(bottomLeftPoint);
            this->setGeometry(windowRect);
        }
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event) {
    if (ui->widget_title2->underMouse() && !m_isMaxShow) {
        //qDebug() << "点击标题";
        m_isPressedTitle = true; // 当前鼠标按下的即是title而非界面上布局的其它控件
    }
    m_last = event->globalPos();
    // 当前鼠标进入了以上指定的8个区域，并且是左键按下时才开始进行窗口拉伸;
    if (m_stretchRectState != NO_SELECT && event->button() == Qt::LeftButton) {
        m_isMousePressed = true;
        // 记录下当前鼠标位置，为后面计算拉伸位置;
        m_startPoint = this->mapToGlobal(event->pos());
        // 保存下拉伸前的窗口位置及大小;
        m_windowRectBeforeStretch = this->geometry();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event) {
    if (m_isPressedTitle) {
        int dx = event->globalX() - m_last.x();
        int dy = event->globalY() - m_last.y();
        m_last = event->globalPos();
        move(x()+dx, y()+dy);
    }

    if (!m_isMousePressed) {
        QPoint cursorPos = event->pos();
        // 根据当前鼠标的位置显示不同的样式;
        m_stretchRectState = getCurrentStretchState(cursorPos);
        updateMouseStyle(m_stretchRectState);
    } else {
        // 如果当前鼠标左键已经按下，则记录下第二个点的位置，并更新窗口的大小;
        m_endPoint = this->mapToGlobal(event->pos());
        updateWindowSize();
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event) {
    m_isPressedTitle = false;
    // 鼠标松开后意味之窗口拉伸结束，置标志位，并且重新计算用于拉伸的8个区域Rect;
    m_isMousePressed = false;
    calculateCurrentStrechRect();
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *event) {

}

void MainWindow::showEvent(QShowEvent *event) {
    //qDebug() << "显示更新";
    //更新样式
    calculateCurrentStrechRect();
    // //防止假死
    setAttribute(Qt::WA_Mapped);
    QMainWindow::showEvent(event);
    //QSize oldSize = this->size();
    //resize(oldSize + QSize(-10, -10));
    //resize(oldSize);
}

void MainWindow::changeEvent(QEvent *event) {
    //用来更新窗口圆角
    if(QEvent::WindowStateChange == event->type())
    {
        //判断为窗口状态改变事件
        QWindowStateChangeEvent * stateEvent = dynamic_cast<QWindowStateChangeEvent*>(event);
        if(Q_NULLPTR != stateEvent)
        {
            if (this->windowState() == Qt::WindowNoState && stateEvent->oldState() == Qt::WindowMaximized) {
                changeMainWindowRadius(1);
            } else if (this->windowState() == Qt::WindowMaximized && stateEvent->oldState() == Qt::WindowNoState) {
                changeMainWindowRadius(2);
            }
        }
    }
}

bool MainWindow::nativeEvent(const QByteArray &eventType, void *message, long *result) {
    MSG* msg = (MSG*)message;
    //qDebug() << "msg->message = " << msg->message;
    switch (msg->message) {
        //没有这一段，将不会显示窗口
        case WM_NCCALCSIZE:
            return true;
        // case WM_MOUSEMOVE:
        // qDebug() << "msg->message = " << msg->message;
        //     return true;
        case WM_NCLBUTTONDBLCLK:
            if (!m_isMaxShow) {
                setContentsMargins(0, 0, 0, 0);
                this->setWindowState(Qt::WindowState::WindowMaximized);
                m_isMaxShow = true;
            } else {
                setContentsMargins(10, 10, 10, 10);
                this->setWindowState(Qt::WindowState::WindowNoState);
                m_isMaxShow = false;
            }
            return true;
        //最大化是填充屏幕
        case WM_NCHITTEST:
        {
            qreal ratio = 1.0;
            long x = GET_X_LPARAM(msg->lParam) / ratio;
            long y = GET_Y_LPARAM(msg->lParam) / ratio;
            QPoint pos = mapFromGlobal(QPoint(x, y));
            if (pos.y() > 10 && ui->widget_title2->rect().contains(pos)) {
                //实现窗口靠边停靠
                *result = HTCAPTION;
                return true;
            }
        }
        case WM_GETMINMAXINFO:
        {
            //IsZoomed确定窗口是否是最大化
            if (::IsZoomed(msg->hwnd)) {
                m_isMaxShow = true;
                // 最大化时会超出屏幕，所以填充边框间距
                RECT frame = { 0, 0, 0, 0 };
                AdjustWindowRectEx(&frame, WS_OVERLAPPEDWINDOW, FALSE, 0);
                frame.left = abs(frame.left);
                frame.top = abs(frame.bottom);
                this->setContentsMargins(frame.left, frame.top, frame.right, frame.bottom);
            } else {
                m_isMaxShow = false;
            }
            *result = ::DefWindowProc(msg->hwnd, msg->message, msg->wParam, msg->lParam);
            return true;
        }
    }
    return QMainWindow::nativeEvent(eventType, message, result);
}

void MainWindow::createSystemTray() {
    // 创建系统托盘图标
    m_trayIcon = new QSystemTrayIcon(QIcon(":lib/icon9.png"), this);
    m_trayIcon->setToolTip("Fdog-Kit");
    m_trayIcon->show();

    //右下角提示框
    //QString title = tr("欢迎使用Fdog-Kit");
    //QString text = tr("让一切变的简单");
    //m_trayIcon->showMessage(title, text, QSystemTrayIcon::Information, 5000);

    // 创建一个菜单
    QMenu* menu = new QMenu();
    menu->setWindowFlags(menu->windowFlags()  | Qt::FramelessWindowHint | Qt::NoDropShadowWindowHint);
    menu->setAttribute(Qt::WA_TranslucentBackground);
    QAction* openAction =  new QAction("打开主界面");
    QAction* closeAction = new QAction("退出");
    menu->addAction(openAction);
    menu->addAction(closeAction);
    menu->setStyleSheet(getStyleFile(":qss/menu.qss"));

    // 将菜单设置给系统托盘图标
    m_trayIcon->setContextMenu(menu);
    connect(openAction, SIGNAL(triggered()), this, SLOT(rece_systemTrayMenu()));
    connect(closeAction, SIGNAL(triggered()), this, SLOT(rece_systemTrayMenu()));
}

void MainWindow::changeMainWindowTheme(bool isChange, int windowsType) {
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
        qDebug() << "切换主题" << m_mode;
        m_mode = (m_mode + 1) % 3;
    }
    m_mode = DARK_THEME;
    //暂时使用DARK_THEME
    if (m_mode == DARK_THEME) {
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

        ui->widget_welcome_body_widget2_newCreate_newTerminal->setIcon(QIcon(":/module_mainwindow/images/light/terminal-light.png"));
        ui->toolButton_zk_tool->setIcon(QIcon(":/module_mainwindow/images/light/zookeeper-light.png"));
        ui->toolButton_db_tool->setIcon(QIcon(":/module_mainwindow/images/light/mysql-light.png"));
        //更新阴影颜色
        getGraphicsEffectUtils(ui->widget_side, 2, 0, 15);
    } else if (m_mode == LIGHT_THEME) {
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

        ui->widget_welcome_body_widget2_newCreate_newTerminal->setIcon(QIcon(":/module_mainwindow/images/dark/terminal-dark.png"));
        ui->toolButton_zk_tool->setIcon(QIcon(":/module_mainwindow/images/dark/zookeeper-dark.png"));
        ui->toolButton_db_tool->setIcon(QIcon(":/module_mainwindow/images/light/mysql-dark.png"));

        //更新阴影颜色
        getGraphicsEffectUtils(ui->widget_side, 2, 0, 15);
    } else if (m_mode == BLUE_THEME) {
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

        ui->widget_welcome_body_widget2_newCreate_newTerminal->setIcon(QIcon(":/module_mainwindow/images/light/terminal-light.png"));
        ui->toolButton_zk_tool->setIcon(QIcon(":/module_mainwindow/images/light/zookeeper-light.png"));
        ui->toolButton_db_tool->setIcon(QIcon(":/module_mainwindow/images/light/mysql-light.png"));
        //更新阴影颜色
        getGraphicsEffectUtils(ui->widget_side, 2, 0, 15);
    }

    if (m_zmanagewidget != NULL) {
        m_zmanagewidget->changeMainWindowTheme(isChange, windowsType);
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
    if (m_mode == DARK_THEME) {
        ui->centralWidget->setStyleSheet(getStyleFile(":/module_mainwindow/qss/centralWidget_dark.qss"));
        if (windowsType == 2) {
            ui->toolButton_max->setIcon(QIcon(":/module_mainwindow/images/light/normal-light.png"));
        } else {
            ui->toolButton_max->setIcon(QIcon(":/module_mainwindow/images/light/max-light.png"));
        }
    } else if (m_mode == LIGHT_THEME) {
        ui->centralWidget->setStyleSheet(getStyleFile(":/module_mainwindow/qss/centralWidget_light.qss"));
        if (windowsType == 2) {
            ui->toolButton_max->setIcon(QIcon(":/module_mainwindow/images/dark/normal-dark.png"));
        } else {
            ui->toolButton_max->setIcon(QIcon(":/module_mainwindow/images/dark/max-dark.png"));
        }
    } else if (m_mode == BLUE_THEME) {
        ui->centralWidget->setStyleSheet(getStyleFile(":/module_mainwindow/qss/centralWidget_blue.qss"));
        if (windowsType == 2) {
            ui->toolButton_max->setIcon(QIcon(":/module_mainwindow/images/light/normal-light.png"));
        } else {
            ui->toolButton_max->setIcon(QIcon(":/module_mainwindow/images/light/max-light.png"));
        }
    }
}

void MainWindow::setWindowsByConf() {
    if (m_confInfo->selfStart == 1) {

    } else if (m_confInfo->selfStart == 2) {

    }

    if (m_confInfo->startMode == 1) {
        //默认
        m_isMaxShow = false;
    } else if (m_confInfo->startMode == 2) {
        //最大化
        setContentsMargins(0, 0, 0, 0);
        ui->centralWidget->setStyleSheet("#centralWidget {border-image: url(:/lib/back1.png);border-radius:0px;}");
        ui->toolButton_max->setIcon(QIcon(":lib/icon-copy.png"));
        this->showMaximized();
        m_isMaxShow = true;
    } else if (m_confInfo->startMode == 3) {
        //全屏
        setContentsMargins(0, 0, 0, 0);
        ui->centralWidget->setStyleSheet("#centralWidget {border-image: url(:/lib/back1.png);border-radius:0px;}");
        ui->toolButton_max->setIcon(QIcon(":lib/icon-copy.png"));
        ui->toolButton_min->hide();
        ui->toolButton_max->hide();
        ui->toolButton_close->hide();
        setWindowState(Qt::WindowFullScreen);
        m_isFullScreen = true;
    }

    if (m_confInfo->startCenter == 1) {
        //居中显示
        QDesktopWidget dw;
        int deskWidth = dw.width();
        int deskHeight = dw.height();
        this->setGeometry(deskWidth/2 - m_confInfo->startPositionX/2, deskHeight/2 - m_confInfo->startPositionY/2, m_confInfo->startPositionX,m_confInfo->startPositionY);
    } else {
        //不居中显示
        this->setGeometry(m_confInfo->physicalDpiX(),m_confInfo->physicalDpiY(),m_confInfo->startPositionX,m_confInfo->startPositionY);
    }
}

void MainWindow::checkNewVersion() {
    //检测
    QSslConfiguration sslConfig = QSslConfiguration::defaultConfiguration();
    sslConfig.setPeerVerifyMode(QSslSocket::VerifyNone);
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
        QByteArray responseData = reply->readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);
        if (!jsonDoc.isNull()) {
            if (jsonDoc.isObject()) {
                QJsonObject jsonObj = jsonDoc.object();

                QString tagName = jsonObj.value("tag_name").toString();
                QString body = jsonObj.value("body").toString();
                m_newVersion = tagName;
                m_newVersionData = body;
                QJsonArray assetsArray = jsonObj.value("assets").toArray();
                for (const QJsonValue &assetValue : assetsArray) {
                    if (assetValue.isObject()) {
                        QJsonObject assetObj = assetValue.toObject();
                        QString browserDownloadUrl = assetObj.value("browser_download_url").toString();
                        m_newVersiondownLoad = browserDownloadUrl;
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
    if (isVersionGreater(m_newVersion, ui->label_side_version->text())) {
        ui->toolButton_newVersion->show();
        ui->toolButton_newVersion->setIcon(QIcon(":lib/node.png"));
        ui->toolButton_newVersion->setToolTip("当前有新版本，点击查看");
    } else {
        qDebug() << "没有新版本";
    }
}

bool MainWindow::isVersionGreater(const QString &version1, const QString &version2) {
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

void MainWindow::on_toolButton_side_home_clicked() {
    ui->label_title->setText("");
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

void MainWindow::on_toolButton_side_thrift_clicked() {
    ui->label_title->setText("thrift接口调用工具");
    if (m_twidget == NULL) {
        m_twidget = new thriftwidget();
        m_twidget->setObjectName("m_twidget");
        ui->stackedWidget->addWidget(m_twidget);
        m_twidget->show();
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
            QWidget *widget = ui->stackedWidget->widget(i);
            if (widget->objectName() == "m_twidget") {
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

void MainWindow::on_toolButton_side_zookeeper_clicked() {
    ui->label_title->setText("zookeeper可视化工具");
    if (m_zmanagewidget == NULL) {
        m_zmanagewidget = new zookeepermanagewidget();
        m_zmanagewidget->setObjectName("m_zmanagewidget");
        ui->stackedWidget->addWidget(m_zmanagewidget);
        m_zmanagewidget->show();
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
            QWidget *widget = ui->stackedWidget->widget(i);
            if (widget->objectName() == "m_zmanagewidget") {
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

void MainWindow::on_toolButton_side_shell_clicked() {
    ui->label_title->setText("终端工具");
    if (m_smanagewidget == nullptr) {
        m_smanagewidget = new sshwidgetmanagewidget(m_confInfo);
        m_smanagewidget->setObjectName("m_smanagewidget");
        ui->stackedWidget->addWidget(m_smanagewidget);
        m_smanagewidget->show();
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
            QWidget *widget = ui->stackedWidget->widget(i);
            if (widget->objectName() == "m_smanagewidget") {
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

void MainWindow::on_toolButton_side_qss_clicked() {
    ui->label_title->setText("qss美化组件工具");
    if (m_qsswidget == NULL) {
        m_qsswidget = new qss();
        m_qsswidget->setObjectName("m_qsswidget");
        ui->stackedWidget->addWidget(m_qsswidget);
        m_qsswidget->show();
        ui->stackedWidget->setCurrentIndex(ui->stackedWidget->count()-1);
    } else {
        int widgetCount = ui->stackedWidget->count();
        for (int i = 0; i < widgetCount; ++i) {
            QWidget *widget = ui->stackedWidget->widget(i);
            if (widget->objectName() == "m_qsswidget") {
                ui->stackedWidget->setCurrentIndex(i);
            }
        }
    }
}

void MainWindow::on_toolButton_side_mysql_clicked() {
    ui->label_title->setText("数据库工具");
    if (m_dbwidget == nullptr) {
        m_dbwidget = new databasewidget();
        m_dbwidget->setObjectName("m_dbwidget");
        ui->stackedWidget->addWidget(m_dbwidget);
        m_dbwidget->show();
        ui->stackedWidget->setCurrentIndex(ui->stackedWidget->count()-1);
        qDebug() << "触发4";
    } else {
        int widgetCount = ui->stackedWidget->count();
        for (int i = 0; i < widgetCount; ++i) {
            QWidget *widget = ui->stackedWidget->widget(i);
            if (widget->objectName() == "m_dbwidget") {
                ui->stackedWidget->setCurrentIndex(i);
            }
        }
    }

}

void MainWindow::on_toolButton_side_tool_clicked() {
    ui->label_title->setText("工具");
    if (m_tswidget == NULL) {
        m_tswidget = new toolswidget();
        m_tswidget->setObjectName("m_tswidget");
        ui->stackedWidget->addWidget(m_tswidget);
        m_tswidget->show();
        ui->stackedWidget->setCurrentIndex(ui->stackedWidget->count()-1);
    } else {
        int widgetCount = ui->stackedWidget->count();
        for (int i = 0; i < widgetCount; ++i) {
            QWidget *widget = ui->stackedWidget->widget(i);
            if (widget->objectName() == "m_tswidget") {
                ui->stackedWidget->setCurrentIndex(i);
            }
        }
    }
}

void MainWindow::on_toolButton_side_theme_clicked() {
    if (this->windowState() == Qt::WindowNoState) {
        changeMainWindowTheme(true, 1);
    } else if (this->windowState() == Qt::WindowMaximized) {
        changeMainWindowTheme(true, 2);
    }
    return;
}

void MainWindow::on_toolButton_side_setting_clicked() {
    if (m_stwidget == NULL) {
        m_stwidget = new settingwidget(m_confInfo);
        m_stwidget->setObjectName("m_stwidget");
        ui->stackedWidget->addWidget(m_stwidget);
        m_stwidget->show();
        ui->stackedWidget->setCurrentIndex(ui->stackedWidget->count()-1);
    } else {
        int widgetCount = ui->stackedWidget->count();
        for (int i = 0; i < widgetCount; ++i) {
            QWidget *widget = ui->stackedWidget->widget(i);
            if (widget->objectName() == "m_stwidget") {
                ui->stackedWidget->setCurrentIndex(i);
            }
        }
    }
}

void MainWindow::on_toolButton_newVersion_clicked() {
    QString data = m_newVersionData + "\n" + "下载地址：\n" + m_newVersiondownLoad;
    QMessageBox::about(this, "发现新版本" + m_newVersion, data);
}

void MainWindow::on_toolButton_close_clicked() {
    this->close();
}

void MainWindow::on_toolButton_min_clicked() {
    this->showMinimized();
}

void MainWindow::on_toolButton_max_clicked() {
    if (!m_isMaxShow) {
        setContentsMargins(0, 0, 0, 0);
        this->setWindowState(Qt::WindowState::WindowMaximized);
        m_isMaxShow = true;
    } else {
        setContentsMargins(10, 10, 10, 10);
        this->setWindowState(Qt::WindowState::WindowNoState);
        m_isMaxShow = false;
    }
}

void MainWindow::on_widget_welcome_body_widget2_newCreate_newTerminal_clicked() {
    int8_t connectType = 1;
    m_ccwidget = new createconnect(connectType);
    connect(m_ccwidget,SIGNAL(newCreate(connnectInfoStruct&)),this,SLOT(rece_newConnnect(connnectInfoStruct&)));
    connect(m_ccwidget,SIGNAL(newSave(connnectInfoStruct&)),this,SLOT(rece_newSave(connnectInfoStruct&)));
    m_ccwidget->show();
}

void MainWindow::on_toolButton_zk_tool_clicked() {
    int8_t connectType = 3;
    m_ccwidget = new createconnect(connectType);
    connect(m_ccwidget,SIGNAL(newCreate(connnectInfoStruct&)),this,SLOT(rece_newConnnect(connnectInfoStruct&)));
    m_ccwidget->show();
}

void MainWindow::on_toolButton_more_clicked() {
    QDesktopServices::openUrl(QUrl(QLatin1String("https://github.com/HuaGouFdog/Fdog-Kit")));
}

void MainWindow::whenAnimationFinish() {
    ui->stackedWidget->setGraphicsEffect(0); // remove effect
}

void MainWindow::whenAnimationFinish2() {
    qDebug() << "whenAnimationFinish2完成";
    //ui->widget_side->setFixedWidth(0);
    ui->widget_side->hide();
    QEventLoop loop;
    QTimer::singleShot(20, &loop, &QEventLoop::quit);
    loop.exec();
    ui->label_side_icon_2->show();
    m_unfoldButton->show();
}

void MainWindow::whenAnimationFinish3() {
    QEventLoop loop;
    QTimer::singleShot(20, &loop, &QEventLoop::quit);
    loop.exec();
    //ui->widget_side->setFixedWidth(50);
    qDebug() << "whenAnimationFinish3完成";
    qDebug() << "展开后 ui->widget_side->width() = " << ui->widget_side->width();

}

void MainWindow::rece_toolButton_fullScreen_sign() {
    if (!m_isFullScreen) {
        setContentsMargins(0, 0, 0, 0);
        changeMainWindowTheme(false, 2);
        ui->toolButton_min->hide();
        ui->toolButton_max->hide();
        ui->toolButton_close->hide();
        this->showFullScreen();
        m_isFullScreen = true;
    } else {
        ui->toolButton_min->show();
        ui->toolButton_max->show();
        ui->toolButton_close->show();
        setContentsMargins(10, 10, 10, 10);

        if (m_isMaxShow) {
            setContentsMargins(0, 0, 0, 0);
            changeMainWindowRadius(2);
            this->showMaximized();
        } else {
            changeMainWindowRadius(1);
            this->showNormal();
        }
        m_isFullScreen = false;
    }
}

void MainWindow::rece_newConnnect(connnectInfoStruct& cInfoStruct) {
    QSize iconSize(16, 16); // 设置图标的大小

    if (cInfoStruct.connectType == SSH_CONNECT_TYPE) {
        on_toolButton_side_shell_clicked();
        m_smanagewidget->newSSHWidget(cInfoStruct, m_confInfo);
        m_smanagewidget->db->ssh_insertSSHInfo(cInfoStruct);
        m_smanagewidget->hcwidget->loadSSHinfo(cInfoStruct);
    } else if (cInfoStruct.connectType == WINDOWS_CONNECT_TYPE) {

    } else if (cInfoStruct.connectType == ZK_CONNECT_TYPE) {
        on_toolButton_side_zookeeper_clicked();
        m_zmanagewidget->newZKWidget(cInfoStruct);
    } else if (cInfoStruct.connectType == DB_CONNECT_TYPE) {
        on_toolButton_side_mysql_clicked();
        qDebug() << "触发5";
        m_dbwidget->newDBWidget(cInfoStruct);
        //ui->tabWidget->addTab(&zkwidget2, QIcon(":lib/db.png").pixmap(iconSize), "172.16.8.166");
    } else if (cInfoStruct.connectType == REDIS_CONNECT_TYPE) {
        //ui->tabWidget->addTab(&zkwidget4, QIcon(":lib/Redis.png").pixmap(iconSize), "172.16.8.153");
    } else if (cInfoStruct.connectType == KAFKA_CONNECT_TYPE) {
        //ui->tabWidget->addTab(&zkwidget3, QIcon(":lib/Kafka.png").pixmap(iconSize), "172.16.8.157");
    }
}

void MainWindow::rece_newSave(connnectInfoStruct& cInfoStruct) {
    if (cInfoStruct.connectType == SSH_CONNECT_TYPE) {
        on_toolButton_side_shell_clicked();
        m_smanagewidget->db->ssh_insertSSHInfo(cInfoStruct);
        m_smanagewidget->hcwidget->loadSSHinfo(cInfoStruct);
    } else if (cInfoStruct.connectType == WINDOWS_CONNECT_TYPE) {

    } else if (cInfoStruct.connectType == ZK_CONNECT_TYPE) {
        //on_toolButton_side_zookeeper_clicked();
        //m_zmanagewidget->newZKWidget(cInfoStruct);
    } else if (cInfoStruct.connectType == REDIS_CONNECT_TYPE) {
        //ui->tabWidget->addTab(&zkwidget4, QIcon(":lib/Redis.png").pixmap(iconSize), "172.16.8.153");
    } else if (cInfoStruct.connectType == KAFKA_CONNECT_TYPE) {
        //ui->tabWidget->addTab(&zkwidget3, QIcon(":lib/Kafka.png").pixmap(iconSize), "172.16.8.157");
    } else if (cInfoStruct.connectType == DB_CONNECT_TYPE) {
        //ui->tabWidget->addTab(&zkwidget2, QIcon(":lib/db.png").pixmap(iconSize), "172.16.8.166");
    }
}

void MainWindow::rece_windowsSetting() {
    //切换至设置-终端
    on_toolButton_side_setting_clicked();
    //跳转到终端
    m_stwidget->getTerminalSetting();
}

void MainWindow::rece_systemTrayMenu() {
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

void MainWindow::trayIconActivated(QSystemTrayIcon::ActivationReason reason) {
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

void MainWindow::on_toolButton_db_tool_clicked() {
    int8_t connectType = 4;
    m_ccwidget = new createconnect(connectType);
    connect(m_ccwidget,SIGNAL(newCreate(connnectInfoStruct&)),this,SLOT(rece_newConnnect(connnectInfoStruct&)));
    m_ccwidget->show();
}


void MainWindow::on_toolButton_fold_clicked()
{
    // if (!ui->widget_side->isHidden()) {
    //     if (m_propertyAnimation) {
    //         delete m_propertyAnimation;
    //         m_propertyAnimation = nullptr; 
    //     }
    //     qDebug() << "当前 ui->widget_side->geometry() = " << ui->widget_side->geometry();
    //     m_propertyAnimation = new QPropertyAnimation(ui->widget_side,"geometry");
    //     m_propertyAnimation->setEasingCurve(QEasingCurve::InOutSine);
    //     m_propertyAnimation->setDuration(300);
    //     m_propertyAnimation->setStartValue(QRect(ui->widget_side->geometry().x(),ui->widget_side->geometry().y(),50,ui->widget_side->height()));
    //     m_propertyAnimation->setEndValue(QRect(ui->widget_side->geometry().x(),ui->widget_side->geometry().y(),0,ui->widget_side->height()));
    //     connect(m_propertyAnimation, &QPropertyAnimation::valueChanged, this, &MainWindow::on_animationValueChanged);
    //     connect(m_propertyAnimation, SIGNAL(finished()), this, SLOT(whenAnimationFinish2()));
    //     m_propertyAnimation->start();
    // }
    whenAnimationFinish2();
}

void MainWindow::on_animationValueChanged(const QVariant &value)
{
    QRect currentGeometry = value.toRect();
    qDebug() << "动画当前值: " << currentGeometry;
}

