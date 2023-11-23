#ifndef SETTINGWIDGET_H
#define SETTINGWIDGET_H

#include <QWidget>
#include "utils.h"

namespace Ui {
class settingwidget;
}

class settingwidget : public QWidget
{
    Q_OBJECT

public:
    explicit settingwidget(QWidget *parent = 0);
    ~settingwidget();

private slots:
    void on_Menu_clicked(int index);

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

};

#endif // SETTINGWIDGET_H
