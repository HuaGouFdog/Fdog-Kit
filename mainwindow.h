#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "zookeeperwidget.h"
#include "createconnect.h"
#include "sshwidget.h"
#include "toolswidget.h"
#include <QGraphicsDropShadowEffect>
#include <QVector>
#include <QRect>


#define STRETCH_RECT_HEIGHT 10       // 拉伸小矩形的高度;
#define STRETCH_RECT_WIDTH 10        // 拉伸小矩形的宽度;

enum WindowStretchRectState
{
    NO_SELECT = 0,              // 鼠标未进入下方矩形区域;
    LEFT_TOP_RECT,              // 鼠标在左上角区域;
    TOP_BORDER,                 // 鼠标在上边框区域;
    RIGHT_TOP_RECT,             // 鼠标在右上角区域;
    RIGHT_BORDER,               // 鼠标在右边框区域;
    RIGHT_BOTTOM_RECT,          // 鼠标在右下角区域;
    BOTTOM_BORDER,              // 鼠标在下边框区域;
    LEFT_BOTTOM_RECT,           // 鼠标在左下角区域;
    LEFT_BORDER                 // 鼠标在左边框区域;
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void calculateCurrentStrechRect();

    WindowStretchRectState getCurrentStretchState(QPoint cursorPos);
    void updateMouseStyle(WindowStretchRectState stretchState);
    void updateWindowSize();
    void setSupportStretch(bool isSupportStretch);

    void mousePressEvent(QMouseEvent *event);    //鼠标点击
    void mouseMoveEvent(QMouseEvent *event);     //鼠标移动
    void mouseReleaseEvent(QMouseEvent *event);  //鼠标释放
    void mouseDoubleClickEvent(QMouseEvent *event); //鼠标双击
    void showEvent(QShowEvent *event);

    void newConnectZk(QString name, QString host, QString port);

private slots:
    void on_toolButton_close_clicked();

    void on_toolButton_min_clicked();

    void on_toolButton_max_clicked();

    void on_tabWidget_tabCloseRequested(int index);

    void on_newCreate();

    void on_newTool();

    void on_newConnnect(connnectInfoStruct& cInfoStruct);
    void on_newClose();

    void on_widget_welcome_body_widget2_newCreate_newTerminal_clicked();

    void on_widget_welcome_body_widget2_newCreate_newTool_clicked();

private:
    Ui::MainWindow *ui;

    QRect m_leftTopRect;
    QRect m_leftBottomRect;
    QRect m_rightTopRect;
    QRect m_rightBottomRect;
    QRect m_topBorderRect;
    QRect m_rightBorderRect;
    QRect m_bottomBorderRect;
    QRect m_leftBorderRect;



    QGraphicsDropShadowEffect * defaultShadow;
    QPoint last;            //窗口拖动用变量
    QPoint m_startPoint;
    QPoint m_endPoint;
    bool showFlag = false; //窗口显示标志位 默认false 正常显示
    bool isPressedWidget;

    QMenu * men;    //新建菜单栏
    QAction * ssh;  //ssh连接
    QAction * zk;   //zk连接
    QAction * kafka; //kafka连接
    QAction * redis; //redis连接
    QAction * db;    //database连接

    QMenu * men_tool;    //工具菜单栏
    QAction * timestamp; //时间戳
    QAction * scale;     //进制
    QAction * url;       //url


    WindowStretchRectState m_stretchRectState;
    bool m_isMousePressed;
    QRect m_windowRectBeforeStretch;
    bool m_isSupportStretch;
    createconnect *ccwidget =nullptr; //创建连接窗口
    toolswidget * tswidget = nullptr; //创建工具窗口
    QVector<zookeeperwidget*> zkWidgetList;
    QVector<sshwidget*> sshWidgetList;
};

#endif // MAINWINDOW_H
