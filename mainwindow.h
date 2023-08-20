#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "zookeeperwidget.h"
#include "createconnect.h"
#include "sshwidget.h"
#include <QGraphicsDropShadowEffect>
#include <QVector>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void mousePressEvent(QMouseEvent *event);    //鼠标点击
    void mouseMoveEvent(QMouseEvent *event);     //鼠标移动
    void mouseReleaseEvent(QMouseEvent *event);  //鼠标释放
    void mouseDoubleClickEvent(QMouseEvent *event); //鼠标双击

    void newConnectZk(QString name, QString host, QString port);

private slots:
    void on_toolButton_close_clicked();

    void on_toolButton_min_clicked();

    void on_toolButton_max_clicked();

    void on_tabWidget_tabCloseRequested(int index);

    void on_newCreate();

    void on_newConnnect(connnectInfoStruct& cInfoStruct);
    void on_newClose();

private:
    Ui::MainWindow *ui;

    QGraphicsDropShadowEffect * defaultShadow;
    QPoint last;            //窗口拖动用变量
    bool showFlag = false; //窗口显示标志位 默认false 正常显示
    bool isPressedWidget;

    QMenu * men;    //菜单栏
    QAction * ssh;  //ssh连接
    QAction * zk;   //zk连接
    QAction * kafka; //kafka连接
    QAction * redis; //redis连接
    QAction * db;    //database连接

    createconnect *ccwidget =nullptr; //创建连接窗口
    QVector<zookeeperwidget*> zkWidgetList;
    QVector<sshwidget*> sshWidgetList;
};

#endif // MAINWINDOW_H
