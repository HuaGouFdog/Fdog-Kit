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
#include "utils.h"
#include <QFormLayout>
#include <QDesktopWidget>

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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);
    // QMainWindow透明显示，当设置主显示窗口的外边距时，防止外边距显示出来。
    this->setAttribute(Qt::WA_TranslucentBackground, true);

    setContentsMargins(10, 10, 10, 10);
    ui->toolButton_max->setIcon(QIcon(":lib/Icon_max4.png"));

    
    HWND hwnd = (HWND)this->winId();
    DWORD style = ::GetWindowLong(hwnd, GWL_STYLE);
    SetWindowLong(hwnd, GWL_STYLE, style | WS_MAXIMIZEBOX | WS_THICKFRAME | WS_CAPTION | CS_DBLCLKS);

    //this->setStyleSheet(getStyleFile(":qss/mainStyle.qss"));

    //设置无边框
    //setWindowFlag(Qt::FramelessWindowHint);
    //setWindowFlags(Qt::WindowMinMaxButtonsHint | Qt::FramelessWindowHint);
    //
    //设置内边距
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

    QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect();
    effect->setOffset(2, 0);          //设置向哪个方向产生阴影效果(dx,dy)，特别地，(0,0)代表向四周发散
    effect->setColor(QColor(25, 51, 81));       //设置阴影颜色，也可以setColor(QColor(220,220,220))
    effect->setBlurRadius(15);        //设定阴影的模糊半径，数值越大越模糊

    ui->widget_side->setGraphicsEffect(effect);


    // QGraphicsDropShadowEffect *effect2 = new QGraphicsDropShadowEffect();
    // effect2->setOffset(0, 0);          //设置向哪个方向产生阴影效果(dx,dy)，特别地，(0,0)代表向四周发散
    // effect2->setColor(QColor(30, 45, 54));       //设置阴影颜色，也可以setColor(QColor(220,220,220))
    // effect2->setBlurRadius(15);        //设定阴影的模糊半径，数值越大越模糊

    //ui->widget_body_left->setGraphicsEffect(effect2);



    isPressedWidget = false;
    m_isMousePressed = false;
    ui->splitter->setStretchFactor(0,20);
    ui->splitter->setStretchFactor(1,2);
    //快捷键 F11 全屏
    QShortcut *shortcut = new QShortcut(QKeySequence(Qt::Key_F11), this);
    connect(shortcut, SIGNAL(activated()), this, SLOT(rece_toolButton_fullScreen_sign()));

    men_tool = new QMenu(ui->toolButton_tool);
    //men_tool->setStyleSheet("QMenu{background-color: rgb(67, 77, 88); font: 10pt \"OPPOSans B\"; color: rgb(255, 255, 255); border:1px solid rgb(255, 255, 255,200);} "
    //                   "QMenu::item:selected {background-color: #0B0E11;}");
    men_tool->setWindowFlags(men_tool->windowFlags()  | Qt::FramelessWindowHint | Qt::NoDropShadowWindowHint);
    men_tool->setAttribute(Qt::WA_TranslucentBackground);
    QSize iconSize(30, 30); // 设置图标的大小
    // toolAssemble = new QAction(QIcon(":lib/toolBox.png"), "小工具");
    // men_tool->addAction(toolAssemble);
    // men_tool->addSeparator();
    // textDiff = new QAction(QIcon(":lib/XML-Local-hover.png"), "文本对比");
    // men_tool->addAction(textDiff);
    // men_tool->addSeparator();
    // xmlFormat = new QAction(QIcon(":lib/xml (2).png"), "XML格式化");
    // men_tool->addAction(xmlFormat);
    // men_tool->addSeparator();
    // jsonFormat = new QAction(QIcon(":lib/json (2).png"), "JSON格式化");
    // men_tool->addAction(jsonFormat);
    // men_tool->addSeparator();
    zkVisual = new QAction(QIcon(":lib/Zookeeper2.png").pixmap(iconSize), "zk可视化连接");
    men_tool->addAction(zkVisual);
    men_tool->addSeparator();
    textTest = new QAction(QIcon(":lib/Thrift5.png").pixmap(iconSize), "thrift接口测试");
    men_tool->addAction(textTest);
    men_tool->addSeparator();
    ui->toolButton_tool->setMenu(men_tool);
    //connect(toolAssemble, SIGNAL(triggered()), this, SLOT(on_newTool()));
    //connect(jsonFormat, SIGNAL(triggered()), this, SLOT(on_newTool()));
    //connect(xmlFormat, SIGNAL(triggered()), this, SLOT(on_newTool()));
    //connect(textDiff, SIGNAL(triggered()), this, SLOT(on_newTool()));
    //connect(textTest, SIGNAL(triggered()), this, SLOT(on_newTool()));
    //connect(zkVisual, SIGNAL(triggered()), this, SLOT(on_newTool()));
    ui->widget_line->hide();
    ui->stackedWidget->setCurrentIndex(2);

    FlowLayout *flowLayout = new FlowLayout(10, 15, 15);
    //flowLayout->addWidget(new QPushButton(tr("Short")));
    //flowLayout->addWidget(new QPushButton(tr("Longer")));
    //flowLayout->addWidget(new QPushButton(tr("Different text")));
    WidgetMouseFilter * wfFilter;
    wfFilter = new WidgetMouseFilter();

    ui->widget_9->installEventFilter(wfFilter);

    //flowLayout->addWidget(new QPushButton(tr("More text")));
    //flowLayout->addWidget(new QPushButton(tr("Even longer button text")));
    //flowLayout->setSpacing(50);
    //flowLayout->horizontalSpacing(10);
    //flowLayout->verticalSpacing(10);
    flowLayout->setSpacing(30);
    ui->widget_2->setLayout(flowLayout);

    ui->widget_4->layout()->addWidget(new parsingJsonTextEdit());

    //ui->widget_welcome_body_widget2->hide();

    //m_flowlayout = new FlowLayout;
    //m_flowlayout->setMargin(0);
    //m_flowlayout->setSpacing(10, 10);

    //for (int i =0; i < 10; i++) {

        //m_flowlayout->addWidget(new QPushButton(tr("Short")));
    //}
    //ui->widget->setLayout(m_flowlayout);


//    while (ui->wdgCard->layout()->count())
//    {
//        auto ptr = ui->wdgCard->layout()->itemAt(0)->widget();
//        ui->wdgCard->layout()->removeWidget(wdg);
//        wdg->deleteLater();
//    }


    ui->comboBox_tool->setView(new QListView());

    //暂时屏蔽
    ui->toolButton_newCreate->hide();
    ui->toolButton_manage->hide();
    ui->toolButton_plugIn->hide();
    ui->toolButton_setting->hide();
    ui->toolButton_tool->hide();
    ui->toolButton_about->hide();
    ui->widget_top_tool->hide();
    ui->toolButton_side_about->hide();
    ui->widget_25->hide();

    QAction *action = new QAction(this);
    action->setIcon(QIcon(":/lib/soucuo2.png"));

    ui->lineEdit_find->addAction(action,QLineEdit::LeadingPosition);
    //ui->widget_welcome_body_widget2_newCreate_newTool->hide();
    //ui->widget_welcome_body_widget2_newCreate_setting->hide();
    //ui->widget_welcome_body_widget2_info_text->hide();

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

    ui->widget_tool->hide();

    //设置系统托盘
    createSystemTray();
    //读取配置文件信息
    confInfo = new config();
    // 读取JSON文件
    confInfo->readSettingConf();

    //设置窗口样式
    setWindowsByConf();
    //confInfo->writeSettingConf();
    qRegisterAnimationInterpolator<QString>(mySheetStyle);

    //QToolButton *button1 = new QToolButton();
    //button1->setIcon(QIcon(":/lib/download.png"));
    // button1->setStyleSheet("QToolButton {\
    //                        color: rgb(255, 255, 255);\
    //                        background-color: rgb(94, 255, 210);\
    //                        border: none;}");
    
    //ui->tabWidget->setCornerWidget(button1, Qt::TopRightCorner);

    // QPushButton *b2 = new QPushButton(QString::fromStdWString(L"设置"));
    // b2->setObjectName("settingButton");
    // ui->tabWidget->setTabEnabled(0, false);
    // ui->tabWidget->tabBar()->setTabButton(0, QTabBar::RightSide, b2);
    setSupportStretch(true);
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
    if (m_stretchRectState == LEFT_BORDER)
    {
        //qDebug() << "更新窗口大小 this->geometry().width() = "<< this->geometry().width() << " delValue_X= " << delValue_X;
        if (this->geometry().width() <= m_windowMinWidth && delValue_X <= 0) {
            //qDebug() << "已经达到最小值 delValue_X=" << delValue_X;
            return;
        }
        QPoint topLeftPoint = windowRect.topLeft();
        topLeftPoint.setX(topLeftPoint.x() - delValue_X);
        windowRect.setBottomLeft(topLeftPoint);
        this->setGeometry(windowRect);
    }
    else if (m_stretchRectState == RIGHT_BORDER)
    {
        QPoint bottomRightPoint = windowRect.bottomRight();
        bottomRightPoint.setX(bottomRightPoint.x() - delValue_X);
        windowRect.setBottomRight(bottomRightPoint);
        this->setGeometry(windowRect);
    }
    else if (m_stretchRectState == TOP_BORDER)
    {
        if (this->geometry().height() <= m_windowMinHeight && delValue_Y <= 0) {
            //qDebug() << "已经达到最小值 delValue_Y=" << delValue_Y;
            return;
        }
        QPoint topLeftPoint = windowRect.topLeft();
        topLeftPoint.setY(topLeftPoint.y() - delValue_Y);
        windowRect.setTopLeft(topLeftPoint);
        this->setGeometry(windowRect);
    }
    else if (m_stretchRectState == BOTTOM_BORDER)
    {
        //qDebug() << "下边BOTTOM_BORDER";
        QPoint bottomRightPoint = windowRect.bottomRight();
        bottomRightPoint.setY(bottomRightPoint.y() - delValue_Y);
        windowRect.setBottomRight(bottomRightPoint);
        this->setGeometry(windowRect);
    }
    else if (m_stretchRectState == LEFT_TOP_RECT)
    {
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
    }
    else if (m_stretchRectState == RIGHT_TOP_RECT)
    {
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
    }
    else if (m_stretchRectState == RIGHT_BOTTOM_RECT)
    {
        QPoint bottomRightPoint = windowRect.bottomRight();
        bottomRightPoint.setX(bottomRightPoint.x() - delValue_X);
        bottomRightPoint.setY(bottomRightPoint.y() - delValue_Y);
        windowRect.setBottomRight(bottomRightPoint);
        this->setGeometry(windowRect);
    }
    else if (m_stretchRectState == LEFT_BOTTOM_RECT)
    {
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
        ui->widget_side->setStyleSheet("#widget_side { \
                                            color: rgb(255, 255, 255); \
                                            border-top-left-radius: 0px; \
                                            border-bottom-left-radius: 0px; \
                                            background-color: rgb(10, 31, 57); \
                                        }");
        ui->toolButton_close->setStyleSheet("QToolButton {\
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
        ui->widget_side->setStyleSheet("#widget_side { \
                                            color: rgb(255, 255, 255); \
                                            border-top-left-radius: 10px; \
                                            border-bottom-left-radius: 10px; \
                                            background-color: rgb(10, 31, 57); \
                                        }");
        ui->toolButton_close->setStyleSheet("QToolButton {\
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
        ui->toolButton_max->setIcon(QIcon(":lib/Icon_max4.png"));
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

void MainWindow::newConnectZk(QString name, QString host, QString port)
{

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
        //this->showNormal();
        ui->toolButton_min->hide();
        ui->toolButton_max->hide();
        ui->toolButton_close->hide();
        //this->showFullScreen();
        setWindowState(Qt::WindowFullScreen);
        isFullScreen = true;
    }

    if (confInfo->startCenter == 1) {
        QDesktopWidget dw;
        int deskWidth = dw.width();
        int deskHeight = dw.height();
        this->setGeometry(deskWidth/2 - 1100/2,deskHeight/2 - 750/2,1100,750);
        qDebug() << "居中显示";
    } else {
        this->setGeometry(confInfo->physicalDpiX(),confInfo->physicalDpiY(),1100,750);
        qDebug() << "不居中显示";
    }
}

void MainWindow::on_toolButton_close_clicked()
{
    //关闭
    //界面动画,窗口下坠
//    QPropertyAnimation* closeAnimation = new QPropertyAnimation(this,"geometry");
//    closeAnimation->setStartValue(geometry());
//    closeAnimation->setEndValue(QRect(geometry().x(),geometry().y()+height(),width(),0));
//    closeAnimation->setDuration(200);
//    closeAnimation->setEasingCurve(QEasingCurve::Linear);   //设置速度曲线

//    //界面动画,消失效果
//    QPropertyAnimation *WindowDisappear_animation = new QPropertyAnimation(this, "windowOpacity");
//    WindowDisappear_animation->setDuration(200);
//    WindowDisappear_animation->setStartValue(1);
//    WindowDisappear_animation->setEndValue(0);
//    WindowDisappear_animation->setEasingCurve(QEasingCurve::InCubic); // 使用缓动效果

//    //缩放
////    QPropertyAnimation *pScaleAnimation1 = new QPropertyAnimation(this, "geometry");
////    pScaleAnimation1->setDuration(100);
////    pScaleAnimation1->setStartValue(QRect(190, 230, 0, 0));
////    pScaleAnimation1->setEndValue(QRect(120, 160, 140, 140));

//    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
//    animation->setDuration(200); // 设置动画持续时间为1秒
//    animation->setStartValue(this->geometry());
//    animation->setEndValue(QRect(980, 1280, 0, 0)); // 缩小为原来的一半
//    animation->setEasingCurve(QEasingCurve::InCubic); // 使用缓动效果


//    /*

//QRect mRect；
//mRect = QGuiApplication::primaryScreen()->geometry();
//qDebug()<<"width:"<<mRect.width()<<"  height:"<<mRect.height();
//*/
//    //创建并行动画组
//    QParallelAnimationGroup *group = new QParallelAnimationGroup(this);
//    //group->addAnimation(closeAnimation);    //动画组添加移动动画
//    group->addAnimation(WindowDisappear_animation);         //动画组添加透明-显现动画
//    group->addAnimation(animation);         //动画组添加透明-显现动画
//    group->start(QAbstractAnimation::DeleteWhenStopped);    //动画组中的动画执行完毕后删除对象
//    connect(group, &QParallelAnimationGroup::finished, this, &MainWindow::closeWindow); //关闭动画完成后再退出软件
    this->close();
}

void MainWindow::closeWindow()
{
    this->close();
}

void MainWindow::on_toolButton_min_clicked()
{
//    //记录当前坐标
//    mWindow = this->rect();
//    //关闭
//    //界面动画,窗口下坠
//    QPropertyAnimation* closeAnimation = new QPropertyAnimation(this,"geometry");
//    closeAnimation->setStartValue(geometry());
//    closeAnimation->setEndValue(QRect(geometry().x(),geometry().y()+height(),width(),0));
//    closeAnimation->setDuration(200);
//    closeAnimation->setEasingCurve(QEasingCurve::Linear);   //设置速度曲线

//    //界面动画,消失效果
//    QPropertyAnimation *WindowDisappear_animation = new QPropertyAnimation(this, "windowOpacity");
//    WindowDisappear_animation->setDuration(200);
//    WindowDisappear_animation->setStartValue(1);
//    WindowDisappear_animation->setEndValue(0);
//    WindowDisappear_animation->setEasingCurve(QEasingCurve::InCubic); // 使用缓动效果

//    //缩放
////    QPropertyAnimation *pScaleAnimation1 = new QPropertyAnimation(this, "geometry");
////    pScaleAnimation1->setDuration(100);
////    pScaleAnimation1->setStartValue(QRect(190, 230, 0, 0));
////    pScaleAnimation1->setEndValue(QRect(120, 160, 140, 140));

//    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
//    animation->setDuration(200); // 设置动画持续时间为1秒
//    animation->setStartValue(this->geometry());
//    animation->setEndValue(QRect(980, 1280, 0, 0)); // 缩小为原来的一半
//    animation->setEasingCurve(QEasingCurve::InCubic); // 使用缓动效果


//    /*

//QRect mRect；
//mRect = QGuiApplication::primaryScreen()->geometry();
//qDebug()<<"width:"<<mRect.width()<<"  height:"<<mRect.height();
//*/
//    //创建并行动画组
//    QParallelAnimationGroup *group = new QParallelAnimationGroup(this);
//    //group->addAnimation(closeAnimation);    //动画组添加移动动画
//    group->addAnimation(WindowDisappear_animation);         //动画组添加透明-显现动画
//    group->addAnimation(animation);         //动画组添加透明-显现动画
//    group->start(QAbstractAnimation::DeleteWhenStopped);    //动画组中的动画执行完毕后删除对象
//    connect(group, &QParallelAnimationGroup::finished, this, &MainWindow::minWindow); //关闭动画完成后再退出软件
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
//    if (isMinimized()) {
//        showNormal();
//    } else {
//        show();
//    }
}

void MainWindow::on_toolButton_max_clicked()
{
    //qDebug() << "显示最大化";
    //最大化
    if (!showFlag) {
        //ui->centralWidget->setEnabled(false);
        setContentsMargins(0, 0, 0, 0);
        ui->centralWidget->setStyleSheet("#centralWidget {background-color: rgb(67, 67, 67);border-image: url(:/lib/back1.png);border-radius:0px;}");
        this->showMaximized();    
        this->setWindowState(Qt::WindowState::WindowMaximized);
        ui->widget_side->setStyleSheet("#widget_side { \
                                            color: rgb(255, 255, 255); \
                                            border-top-left-radius: 0px; \
                                            border-bottom-left-radius: 0px; \
                                            background-color: rgb(10, 31, 57); \
                                        }");
        ui->toolButton_close->setStyleSheet("QToolButton {\
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
        ui->toolButton_max->setIcon(QIcon(":lib/icon-copy.png"));
        //ui->centralWidget->setEnabled(true);
        isMaxShow = true;
        showFlag = true;
    } else {
        setContentsMargins(10, 10, 10, 10); //rgb(67, 77, 88)
        this->showNormal();
        this->setWindowState(Qt::WindowState::WindowNoState);
        ui->centralWidget->setStyleSheet("#centralWidget {background-color: rgb(67, 67, 67);border-image: url(:/lib/back1.png);border-radius:10px;}");
        ui->widget_side->setStyleSheet("#widget_side { \
                                            color: rgb(255, 255, 255); \
                                            border-top-left-radius: 10px; \
                                            border-bottom-left-radius: 10px; \
                                            background-color: rgb(10, 31, 57); \
                                        }");
        ui->toolButton_close->setStyleSheet("QToolButton {\
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
        ui->toolButton_max->setIcon(QIcon(":lib/Icon_max4.png"));

        isMaxShow = false;
        showFlag = false;
    }
}

void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    QString closeName = ui->tabWidget->tabText(index);
    ui->tabWidget->removeTab(index);
    //将页面释放，下次再生成 判断关闭页面类型
    //twidget
    qDebug() << "关闭页面" << closeName;
    if (closeName == "thrift接口测试") {
        delete twidget;
        twidget = NULL;
    } else if (closeName == "zookeeper") {
        delete zmanagewidget;
        zmanagewidget = NULL;
    } else {
        qDebug() << "关闭ssh页面";
        //delete sshWidgetList[0];
        //delete ui->tabWidget->currentWidget();
    }
    

    if(ui->tabWidget->count() == 0) {
        //创建快速连接
        int8_t connectType = 0;
        ui->stackedWidget->setCurrentIndex(2);
        //创建连接窗口
        hcwidget = new historyconnectwidget(connectType);
        //connect(hcwidget,SIGNAL(newCreate(connnectInfoStruct&)),this,SLOT(on_newConnnect(connnectInfoStruct&)));
        ui->tabWidget->addTab(hcwidget, "快速连接");
        ui->tabWidget->setCurrentIndex(ui->tabWidget->count()-1);
        ui->stackedWidget->setCurrentIndex(0);
        hcwidget->show();
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
        //获取发送者
        QString toolName;
        QString actionText = qobject_cast<QAction*>(sender())->text();
        int8_t connectType = 0;
        //创建连接窗口 
        QSize iconSize(20, 20); // 设置图标的大小
        qDebug() <<"工具：" << actionText;
        if (actionText == "小工具") {
            ui->widget_tool->show();
            ui->stackedWidget->setCurrentIndex(0);
            return;
            //ui->tabWidget->addTab(tswidget, QIcon(":lib/toolBox.png").pixmap(iconSize), toolName);
        } else if (actionText == "JSON格式化") {
            toolName = "JSON格式化";
            tswidget = new toolswidget(1);
            //内存泄漏 后面记得释放
            ui->tabWidget->addTab(tswidget, QIcon(":lib/json (2).png").pixmap(iconSize), toolName);
        } else if (actionText == "XML格式化") {
            toolName = "XML格式化";
            tswidget = new toolswidget(2);
            ui->tabWidget->addTab(tswidget, QIcon(":lib/xml (2).png").pixmap(iconSize), toolName);
        } else if (actionText == "文本对比") {
            toolName = "文本对比";
            tswidget = new toolswidget(3);
            ui->tabWidget->addTab(tswidget, QIcon(":lib/XML-Local-hover.png").pixmap(iconSize), toolName);
        } else if (actionText == "zk可视化连接") {
            toolName = "zookeeper";
            if(zmanagewidget == NULL) {
                zmanagewidget = new zookeepermanagewidget();
                ui->tabWidget->addTab(zmanagewidget, QIcon(":lib/Zookeeper2.png").pixmap(iconSize), toolName);
                ui->stackedWidget->setCurrentIndex(0);
                ui->tabWidget->setCurrentIndex(ui->tabWidget->count()-1);
            } else {
                //切换到zookeeper tabWidget
                int index = ui->tabWidget->indexOf(zmanagewidget);
                if (index != -1) {
                    ui->tabWidget->setCurrentIndex(index);
                }
            }
            return;
        } else if (actionText == "thrift接口测试") {
            if (twidget == NULL) {
                toolName = "thrift接口测试";
                twidget = new thriftwidget(this);
                ui->tabWidget->addTab(twidget, QIcon(":lib/Thrift5.png").pixmap(iconSize), toolName);
                ui->stackedWidget->setCurrentIndex(0);
                twidget->show();
                ui->tabWidget->setCurrentIndex(ui->tabWidget->count()-1);
            } else {
                int index = ui->tabWidget->indexOf(twidget);
                if (index != -1) {
                    ui->tabWidget->setCurrentIndex(index);
                }
            }
            return;
        } else {
            return;
        }
        ui->tabWidget->setCurrentIndex(ui->tabWidget->count()-1);
        tswidget->show();
        ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_newConnnect(connnectInfoStruct& cInfoStruct)
{
    //qDebug() << cInfoStruct.connectType;
    QSize iconSize(16, 16); // 设置图标的大小

    if (cInfoStruct.connectType == SSH_CONNECT_TYPE) {
        sshwidget * sshWidget = new sshwidget(cInfoStruct, confInfo);
        connect(sshWidget,SIGNAL(send_toolButton_toolkit_sign()),this,SLOT(on_widget_welcome_body_widget2_newCreate_newTool_clicked()));
        connect(sshWidget,SIGNAL(send_toolButton_fullScreen_sign()),this,SLOT(rece_toolButton_fullScreen_sign()));
        sshWidgetList.push_back(sshWidget);
        ui->tabWidget->addTab(sshWidget, QIcon(":lib/powershell.png").pixmap(iconSize), cInfoStruct.name);
    } else if (cInfoStruct.connectType == WINDOWS_CONNECT_TYPE) {

    } else if (cInfoStruct.connectType == ZK_CONNECT_TYPE) {
        if(zmanagewidget == NULL) {
            zmanagewidget = new zookeepermanagewidget(cInfoStruct);
            ui->tabWidget->addTab(zmanagewidget, QIcon(":lib/Zookeeper2.png").pixmap(iconSize), "zookeeper");
            ui->stackedWidget->setCurrentIndex(0);
        } else {
            //创建+连接
            zmanagewidget->newCreate(cInfoStruct);
        }
        //zookeeperwidget * zkWidget = new zookeeperwidget(cInfoStruct);
        //zkWidgetList.push_back(zkWidget);
        ui->tabWidget->addTab(zmanagewidget, QIcon(":lib/Zookeeper2.png").pixmap(iconSize), "zookeeper");
    } else if (cInfoStruct.connectType == REDIS_CONNECT_TYPE) {
        //ui->tabWidget->addTab(&zkwidget4, QIcon(":lib/Redis.png").pixmap(iconSize), "172.16.8.153");
    } else if (cInfoStruct.connectType == KAFKA_CONNECT_TYPE) {
        //ui->tabWidget->addTab(&zkwidget3, QIcon(":lib/Kafka.png").pixmap(iconSize), "172.16.8.157");
    } else if (cInfoStruct.connectType == DB_CONNECT_TYPE) {
        //ui->tabWidget->addTab(&zkwidget2, QIcon(":lib/db.png").pixmap(iconSize), "172.16.8.166");
    }

    ui->tabWidget->setCurrentIndex(ui->tabWidget->count()-1);
    ui->stackedWidget->setCurrentIndex(0);
    //ui->widget_line->show();
    //qDebug() << "on_newConnnect调用结束";
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
    connect(ccwidget,SIGNAL(newCreate(connnectInfoStruct&)),this,SLOT(on_newConnnect(connnectInfoStruct&)));
    ccwidget->show();
}

void MainWindow::on_widget_welcome_body_widget2_newCreate_newTool_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    //显示工具栏窗口
    if (!isShowToolKit) {
        ui->widget_tool->show();
        isShowToolKit = true;
    } else {
        ui->widget_tool->hide();
        isShowToolKit = false;
    }
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
    ui->widget_tool->hide();
    isShowToolKit = false;
}

void MainWindow::on_toolButton_newCreate_clicked()
{
//    if (ccwidget == nullptr) {
//        int8_t connectType = 0;
//        //创建连接窗口
//        ccwidget = new createconnect(connectType);
//        connect(ccwidget,SIGNAL(newCreate(connnectInfoStruct&)),this,SLOT(on_newConnnect(connnectInfoStruct&)));
//        connect(ccwidget,SIGNAL(newClose()),this,SLOT(on_newClose()));
//        ccwidget->show();
//    } else {
//        //不创建
//        ccwidget->setFocus();
//    }
    int8_t connectType = 0;
    ccwidget = new createconnect(connectType);
    connect(ccwidget,SIGNAL(newCreate(connnectInfoStruct&)),this,SLOT(on_newConnnect(connnectInfoStruct&)));
    QPoint globalPos = this->mapToGlobal(QPoint(0,0));//父窗口绝对坐标
    int x = globalPos.x() + (this->width() - ccwidget->width()) / 2;//x坐标
    int y = globalPos.y() + (this->height() - ccwidget->height()) / 2;//y坐标
    ccwidget->move(x, y);//窗口移动
    ccwidget->show();
}

//void MainWindow::on_toolButton_newCreate_2_clicked()
//{
//    //if (hcwidget == nullptr) {
//        int8_t connectType = 0;
//        //创建连接窗口
//        hcwidget = new historyconnectwidget(connectType);
//        //connect(hcwidget,SIGNAL(newCreate(connnectInfoStruct&)),this,SLOT(on_newConnnect(connnectInfoStruct&)));
//        ui->tabWidget->addTab(hcwidget, "快速连接");
//        ui->tabWidget->setCurrentIndex(ui->tabWidget->count()-1);
//        ui->stackedWidget->setCurrentIndex(0);
//        hcwidget->show();
////    } else {
////        //不创建
////        hcwidget->setFocus();
//        //    }
//}

void MainWindow::rece_toolButton_fullScreen_sign()
{
    qDebug() << "isFullScreen = " <<isFullScreen;
    if (!isFullScreen) {
        setContentsMargins(0, 0, 0, 0);
        ui->centralWidget->setStyleSheet("#centralWidget {border-image: url(:/lib/back1.png);border-radius:0px;}");
        ui->toolButton_max->setIcon(QIcon(":lib/icon-copy.png"));
        //this->showNormal();
        ui->toolButton_min->hide();
        ui->toolButton_max->hide();
        ui->toolButton_close->hide();
        this->showFullScreen();
        isFullScreen = true;
    } else {
        ui->toolButton_min->show();
        ui->toolButton_max->show();
        ui->toolButton_close->show();
        setContentsMargins(10, 10, 10, 10); //rgb(67, 77, 88)
        ui->centralWidget->setStyleSheet("#centralWidget {border-image: url(:/lib/back1.png);border-radius:10px;}");
        ui->toolButton_max->setIcon(QIcon(":lib/Icon_max4.png"));
        if (showFlag) {
            ui->centralWidget->setStyleSheet("#centralWidget {border-image: url(:/lib/back1.png);border-radius:0px;}");
            setContentsMargins(0, 0, 0, 0);
            ui->toolButton_max->setIcon(QIcon(":lib/icon-copy.png"));
            this->showMaximized();
        } else {
            this->showNormal();
        }
        isFullScreen = false;
    }

}

void MainWindow::on_toolButton_setting_clicked()
{
    if (stwidget == NULL) {
        stwidget = new settingwidget(confInfo);
        QSize iconSize(16, 16); // 设置图标的大小
        ui->tabWidget->addTab(stwidget, QIcon(":lib/setting4.png").pixmap(iconSize), "设置");
        ui->tabWidget->setCurrentIndex(ui->tabWidget->count()-1);
        ui->stackedWidget->setCurrentIndex(0);
        stwidget->show();
    } else {
        //从当前标签里面查找
        int index = ui->tabWidget->indexOf(stwidget);
        if (index != -1) {
            ui->tabWidget->setCurrentIndex(index);
        } else {
            //出错
        }
    }
}


void MainWindow::on_toolButton_about_clicked()
{
     awidget = new aboutwidget();
     QPoint globalPos = this->mapToGlobal(QPoint(0,0));//父窗口绝对坐标
     int x = globalPos.x() + (this->width() - awidget->width()) / 2;//x坐标
     int y = globalPos.y() + (this->height() - awidget->height()) / 2;//y坐标
     awidget->move(x, y);//窗口移动
     awidget->show();
}

// void MainWindow::on_widget_welcome_body_widget2_nearestConnectionInfo_more_clicked()
// {
//     int8_t connectType = 0;
//     //创建连接窗口
//     hcwidget = new historyconnectwidget(connectType);
//     //connect(hcwidget,SIGNAL(newCreate(connnectInfoStruct&)),this,SLOT(on_newConnnect(connnectInfoStruct&)));
//     ui->tabWidget->addTab(hcwidget, "快速连接");
//     ui->tabWidget->setCurrentIndex(ui->tabWidget->count()-1);
//     ui->stackedWidget->setCurrentIndex(0);
//     hcwidget->show();
// }

void MainWindow::on_toolButton_manage_clicked()
{
    int8_t connectType = 0;
    //创建连接窗口
    hcwidget = new historyconnectwidget(connectType);
    //connect(hcwidget,SIGNAL(newCreate(connnectInfoStruct&)),this,SLOT(on_newConnnect(connnectInfoStruct&)));
    ui->tabWidget->addTab(hcwidget, "快速连接");
    ui->tabWidget->setCurrentIndex(ui->tabWidget->count()-1);
    ui->stackedWidget->setCurrentIndex(0);
    hcwidget->show();
}

void MainWindow::on_tabWidget_customContextMenuRequested(const QPoint &pos)
{
    if (ui->tabWidget->currentIndex() == ui->tabWidget->tabBar()->tabAt(pos)) {
        //qDebug() << "标签";
        QMenu *menu = new QMenu(ui->tabWidget);
        menu->setWindowFlags(menu->windowFlags()  | Qt::FramelessWindowHint | Qt::NoDropShadowWindowHint);
        menu->setAttribute(Qt::WA_TranslucentBackground);
        QAction *pnew = new QAction("复制标签", ui->tabWidget);
        QAction *pnew1 = new QAction("关闭", ui->tabWidget);
        QAction *pnew2 = new QAction("关闭其他", ui->tabWidget);
        QAction *pnew3 = new QAction("关闭全部", ui->tabWidget);
        //connect (pnew,SIGNAL(triggered()),this,SLOT(rece_addCommond_sgin()));
        //connect (pnew1,SIGNAL(triggered()),this,SLOT(rece_mkdirFolder_sgin()));
        menu->addAction(pnew);
        menu->addSeparator();
        menu->addAction(pnew1);
        menu->addSeparator();
        menu->addAction(pnew2);
        menu->addSeparator();
        menu->addAction(pnew3);
        menu->move(cursor().pos());
        menu->show();
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

void MainWindow::on_toolButton_thrift_tool_clicked()
{
    QSize iconSize(20, 20); // 设置图标的大小
    if (twidget == NULL) {
        twidget = new thriftwidget(this);
        ui->tabWidget->addTab(twidget, QIcon(":lib/Thrift5.png").pixmap(iconSize), "thrift接口测试");
        ui->stackedWidget->setCurrentIndex(0);
        twidget->show();
        ui->tabWidget->setCurrentIndex(ui->tabWidget->count()-1);
    } else {
        int index = ui->tabWidget->indexOf(twidget);
        if (index != -1) {
            ui->tabWidget->setCurrentIndex(index);
        }
    }
}

void MainWindow::on_toolButton_zk_tool_clicked()
{
    //新建终端
    int8_t connectType = 3;
    ccwidget = new createconnect(connectType);
    connect(ccwidget,SIGNAL(newCreate(connnectInfoStruct&)),this,SLOT(on_newConnnect(connnectInfoStruct&)));
    ccwidget->show();
//    QSize iconSize(20, 20); // 设置图标的大小
//    if(zmanagewidget == NULL) {
//        zmanagewidget = new zookeepermanagewidget();
//        ui->tabWidget->addTab(zmanagewidget, QIcon(":lib/Zookeeper2.png").pixmap(iconSize), "zookeeper");
//        ui->stackedWidget->setCurrentIndex(0);
//        ui->tabWidget->setCurrentIndex(ui->tabWidget->count()-1);
//    } else {
//        //切换到zookeeper tabWidget
//        int index = ui->tabWidget->indexOf(zmanagewidget);
//        if (index != -1) {
//            ui->tabWidget->setCurrentIndex(index);
//        }
//    }
}

void MainWindow::on_toolButton_side_theme_clicked()
{
    return;
    //切换模式
    if (currentTheme == 0) {
        currentTheme = 1;
        QString styleSheet1 = "QToolButton { background-color: rgb(20, 30, 36);}";
        QString styleSheet2 = "QToolButton { background-color: rgb(84, 95, 255); }";

        // 创建动画对象
        QPropertyAnimation *animation = new QPropertyAnimation(ui->widget_side, "styleSheet");
        animation->setDuration(200); // 设置动画持续时间
        animation->setStartValue(styleSheet1); // 设置动画起始样式表
        animation->setEndValue(styleSheet2); // 设置动画结束样式表

        // 连接动画完成信号
        QObject::connect(animation, &QPropertyAnimation::finished, [&](){
            qDebug() << "Animation finished1.";
        });

        // 启动动画
        animation->start();
    } else {
        currentTheme = 0;
        QString styleSheet1 = "QToolButton { background-color: rgb(84, 95, 255);}";
        QString styleSheet2 = "QToolButton { background-color: rgb(20, 30, 36); }";

        // 创建动画对象
        QPropertyAnimation *animation = new QPropertyAnimation(ui->widget_side, "styleSheet");
        animation->setDuration(400); // 设置动画持续时间
        animation->setStartValue(styleSheet1); // 设置动画起始样式表
        animation->setEndValue(styleSheet2); // 设置动画结束样式表

        // 连接动画完成信号
        QObject::connect(animation, &QPropertyAnimation::finished, [&](){
            qDebug() << "Animation finished2.";
        });

        // 启动动画
        animation->start();
    }
    
    QString state;
    if (currentTheme == 0) {
        currentTheme = 1;
        //浅色qss
        state = "light";
        QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect(this);
        effect->setOffset(2, 0);          //设置向哪个方向产生阴影效果(dx,dy)，特别地，(0,0)代表向四周发散
        effect->setColor(QColor(0, 170, 255));       //设置阴影颜色，也可以setColor(QColor(220,220,220))
        effect->setBlurRadius(15);        //设定阴影的模糊半径，数值越大越模糊
        //ui->widget_side->setGraphicsEffect(effect);
    } else {
        //暗黑qss
        currentTheme = 0;
        state = "dark";
        QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect(this);
        effect->setOffset(2, 0);          //设置向哪个方向产生阴影效果(dx,dy)，特别地，(0,0)代表向四周发散
        effect->setColor(QColor(20, 30, 36));       //设置阴影颜色，也可以setColor(QColor(220,220,220))
        effect->setBlurRadius(15);        //设定阴影的模糊半径，数值越大越模糊
        //ui->widget_side->setGraphicsEffect(effect);
    }
    //改变子组件
    QList<QToolButton *> buttons = ui->widget_side->findChildren<QToolButton *>();
    for (QToolButton *button : buttons) {
        button->setProperty("state",state);
        button->style()->unpolish(button); //清除旧的样式
        button->style()->polish(button);   //更新为新的样式
    }
    ui->widget_side->setProperty("state",state);
    ui->widget_side->style()->unpolish(ui->widget_side); //清除旧的样式
    ui->widget_side->style()->polish(ui->widget_side);   //更新为新的样式

    ui->label_side_version->setProperty("state",state);
    ui->label_side_version->style()->unpolish(ui->label_side_version); //清除旧的样式
    ui->label_side_version->style()->polish(ui->label_side_version);   //更新为新的样式
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
    } else {
        int widgetCount = ui->stackedWidget->count();
        for (int i = 0; i < widgetCount; ++i) {
            // 获取索引处的widget
            QWidget *widget = ui->stackedWidget->widget(i);
            if (widget->objectName() == "twidget") {
                ui->stackedWidget->setCurrentIndex(i);
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
    } else {
        int widgetCount = ui->stackedWidget->count();
        for (int i = 0; i < widgetCount; ++i) {
            // 获取索引处的widget
            QWidget *widget = ui->stackedWidget->widget(i);
            if (widget->objectName() == "zmanagewidget") {
                ui->stackedWidget->setCurrentIndex(i);
            }
        }
    }

}

void MainWindow::on_toolButton_side_github_clicked()
{
    QDesktopServices::openUrl(QUrl(QLatin1String("https://github.com/HuaGouFdog/Fdog-Kit")));
}

void MainWindow::on_toolButton_side_about_clicked()
{
    awidget = new aboutwidget();
    QPoint globalPos = this->mapToGlobal(QPoint(0,0));//父窗口绝对坐标
    int x = globalPos.x() + (this->width() - awidget->width()) / 2;//x坐标
    int y = globalPos.y() + (this->height() - awidget->height()) / 2;//y坐标
    awidget->move(x, y);//窗口移动
    awidget->show();
}

void MainWindow::on_toolButton_side_home_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_toolButton_side_shell_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_toolButton_side_tool_clicked()
{
    //tswidget = new toolswidget(1);
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
