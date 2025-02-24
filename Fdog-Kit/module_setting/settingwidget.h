﻿#ifndef SETTINGWIDGET_H
#define SETTINGWIDGET_H

#include <QWidget>
#include "module_utils/utils.h"
#include "module_utils/config.h"

namespace Ui {
class settingwidget;
}

class settingwidget : public QWidget
{
    Q_OBJECT

public:
    explicit settingwidget(config * confInfo_, QWidget *parent = 0);
    ~settingwidget();

    void getTerminalSetting();

    //发送弹窗提示
    void showMessage(QString message, bool isSuccess = true); //显示操作信息

private slots:
    void on_Menu_clicked(int index);

    void on_toolButton_save_clicked();

    void on_toolButton_recover_clicked();

    void whenAnimationFinish();

private:
    Ui::settingwidget *ui;
    //启动模块
    AnimatedCheckBox * selfStart;   //自启动
    AnimatedCheckBox * trayDisplay; //托盘显示
    AnimatedCheckBox * startCenter; //居中启动

    //外观模块
    AnimatedCheckBox * topDisplay; //顶层显示

    //终端板块
    AnimatedCheckBox * infoDisplay;         //工具栏-服务器信息显示
    AnimatedCheckBox * historyDisplay;      //工具栏-历史显示
    AnimatedCheckBox * commandDisplay;      //工具栏-命令显示
    AnimatedCheckBox * conectStatsDisplay;  //工具栏-连接属性显示

    config * confInfo;

    QButtonGroup * m_buttonGroup;
    QFMessageBox * tipwidget = nullptr;
};

#endif // SETTINGWIDGET_H
