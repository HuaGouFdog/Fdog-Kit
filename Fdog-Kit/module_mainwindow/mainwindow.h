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
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRect>
#include <QVector>
#include <QToolButton>
#include <QSystemTrayIcon>
#include <QGraphicsDropShadowEffect>
#include "module_qss/qss.h"
#include "module_ssh/sshwidget.h"
#include "module_ssh/downloadwidget.h"
#include "module_ssh/historyconnectwidget.h"
#include "module_ssh/sshwidgetmanagewidget.h"
#include "module_tool/toolswidget.h"
#include "module_connect/createconnect.h"
#include "module_zookeeper/zookeeperwidget.h"
#include "module_zookeeper/zookeepermanagewidget.h"
#include "module_thrift/thriftwidget.h"
#include "module_database/databasewidget.h"
#include "module_setting/settingwidget.h"
#include "module_utils/config.h"
#include "module_utils/flowlayout.h"

//窗口拉伸范围
#define STRETCH_RECT_HEIGHT 10          //拉伸小矩形的高度
#define STRETCH_RECT_WIDTH  10          //拉伸小矩形的宽度

//窗口拉伸矩形状态
enum WindowStretchRectState
{
    NO_SELECT = 0,              // 鼠标未进入下方矩形区域
    LEFT_TOP_RECT,              // 鼠标在左上角区域
    TOP_BORDER,                 // 鼠标在上边框区域
    RIGHT_TOP_RECT,             // 鼠标在右上角区域
    RIGHT_BORDER,               // 鼠标在右边框区域
    RIGHT_BOTTOM_RECT,          // 鼠标在右下角区域
    BOTTOM_BORDER,              // 鼠标在下边框区域
    LEFT_BOTTOM_RECT,           // 鼠标在左下角区域
    LEFT_BORDER                 // 鼠标在左边框区域
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Ui::MainWindow *ui;

    QRect m_leftTopRect;        //左上
    QRect m_leftBottomRect;     //左下
    QRect m_rightTopRect;       //右上
    QRect m_rightBottomRect;    //右下
    QRect m_topBorderRect;      //上
    QRect m_rightBorderRect;    //右
    QRect m_bottomBorderRect;   //下
    QRect m_leftBorderRect;     //左

    QPoint m_last;                //窗口拖动使用
    QPoint m_startPoint;        //开始坐标
    QPoint m_endPoint;          //结束坐标

    WindowStretchRectState m_stretchRectState;       //当前鼠标状态
    QRect m_windowRectBeforeStretch;                 //保存下拉伸前的窗口位置及大小 

    qss * m_qsswidget = nullptr;                       //创建qss工具窗口
    createconnect * m_ccwidget = nullptr;               //创建连接窗口
    toolswidget * m_tswidget = nullptr;                //创建工具窗口           
    thriftwidget * m_twidget = nullptr;                //thrift测试工具窗口
    settingwidget * m_stwidget = nullptr;              //创建设置窗口
    historyconnectwidget * m_hcwidget = nullptr;       //ssh快速连接
    zookeepermanagewidget * m_zmanagewidget = nullptr; //zk窗口
    sshwidgetmanagewidget * m_smanagewidget = nullptr; //ssh管理窗口
    databasewidget * m_dbwidget = nullptr;             //db窗口

    QSystemTrayIcon* m_trayIcon;      //托盘图标
    config * m_confInfo = nullptr;    //配置信息

    int m_mode = 1; //默认暗黑模式
    bool m_isFullScreen = false;      //是否全屏
    bool m_isMaxShow = false;         //是否最大化显示
    bool m_isPressedTitle = false;   //鼠标按在标题栏上   
    bool m_isMousePressed = false;   //鼠标按下

    QString m_newVersion;             //新版本
    QString m_newVersionData;         //新版本更新内容
    QString m_newVersiondownLoad;     //新版本下载地址

    //QToolButton * m_unfoldButton = nullptr; //侧边栏折叠按钮
    QPropertyAnimation * m_propertyAnimation = nullptr; //侧边栏动画关
    QPropertyAnimation * m_propertyAnimation2 = nullptr; //侧边栏动画开

public:
    explicit MainWindow(QWidget *parent = 0);
    explicit MainWindow(config * confInfo, QWidget *parent = 0);
    ~MainWindow();

    //计算当前拉伸范围
    void calculateCurrentStrechRect();
    //获取窗口拉伸矩形状态
    WindowStretchRectState getCurrentStretchState(QPoint cursorPos);
    //更新鼠标样式
    void updateMouseStyle(WindowStretchRectState stretchState);
    //更新窗口位置
    void updateWindowSize();
    //鼠标点击
    void mousePressEvent(QMouseEvent *event);
    //鼠标移动
    void mouseMoveEvent(QMouseEvent *event);
    //鼠标释放     
    void mouseReleaseEvent(QMouseEvent *event);
    //鼠标双击 未使用
    void mouseDoubleClickEvent(QMouseEvent *event);
    //显示事件处理
    void showEvent(QShowEvent *event);
    //处理窗口样式
    void changeEvent(QEvent *event);
    //处理窗口样式
    bool nativeEvent(const QByteArray &eventType, void *message, long *result);
    //创建托盘显示
    void createSystemTray();
    //修改窗体圆角
    void changeMainWindowRadius(int windowsType = 1);
    //修改全局主题 windowsType 1 正常 2最大化
    void changeMainWindowTheme(bool isChange = false, int windowsType = 1);
    //根据配置文件设置启动窗口的样式
    void setWindowsByConf();
    //检测新版本
    void checkNewVersion();
    //判断版本
    bool isVersionGreater(const QString &version1, const QString &version2);

private slots:
    //主界面按钮
    void on_toolButton_side_home_clicked();
    //thrift按钮
    void on_toolButton_side_thrift_clicked();
    //zk按钮信号
    void on_toolButton_side_zookeeper_clicked();
    //终端按钮信号
    void on_toolButton_side_shell_clicked();
    //美化按钮信号
    void on_toolButton_side_qss_clicked();
    //数据库按钮信号
    void on_toolButton_side_mysql_clicked();
    //数据库新建窗口信号
    void rece_newCreateDatabase();
    //工具按钮信号
    void on_toolButton_side_tool_clicked();
    //主题按钮信号
    void on_toolButton_side_theme_clicked();
    //设置按钮信号
    void on_toolButton_side_setting_clicked();
    //新版本按钮信号 点击弹出新版本更新内容
    void on_toolButton_newVersion_clicked();
    //关闭按钮信号
    void on_toolButton_close_clicked();
    //最小化按钮信号
    void on_toolButton_min_clicked();
    //最大化按钮信号
    void on_toolButton_max_clicked();
    //主界面SSH连接信号
    void on_widget_welcome_body_widget2_newCreate_newTerminal_clicked();
    //主界面ZK连接信号
    void on_toolButton_zk_tool_clicked();
    //了解更多信号 跳转github
    void on_toolButton_more_clicked();

    //切换界面动画完成信号 移除GraphicsEffect
    void whenAnimationFinish();
    //切换界面动画完成信号 显示/隐藏侧边栏
    void whenAnimationFinish2();
    //切换界面动画完成信号 显示/隐藏侧边栏
    void whenAnimationFinish3();
    //全屏信号
    void rece_toolButton_fullScreen_sign();
    //创建连接信号
    void rece_newConnnect(connnectInfoStruct& cInfoStruct);
    //保存连接信号
    void rece_newSave(connnectInfoStruct& cInfoStruct);
    //跳转至设置信号
    void rece_windowsSetting();
    //托盘菜单
    void rece_systemTrayMenu();
    //处理托盘图标事件
    void trayIconActivated(QSystemTrayIcon::ActivationReason reason);
    //处理database连接
    void on_toolButton_db_tool_clicked();
    void on_toolButton_fold_clicked();
    void on_animationValueChanged(const QVariant &value);
    void on_toolButton_clicked();
    void updateTime();
    void on_toolButton_fold_2_clicked();
    //void on_toolButton_2_clicked();
};

#endif // MAINWINDOW_H
