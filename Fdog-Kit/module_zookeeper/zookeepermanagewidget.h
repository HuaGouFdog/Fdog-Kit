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

#ifndef ZOOKEEPERMANAGEWIDGET_H
#define ZOOKEEPERMANAGEWIDGET_H
#include <QMap>
#include <QWidget>
#include <QButtonGroup>
#include "zookeepersql.h"
#include "zookeeperwidget.h"

struct zkStatusStruct{
    int status_;  //0 成功 1 连接中 2 关闭 3 失败
    zookeeperwidget * zkWidget_;
};

namespace Ui {
class zookeepermanagewidget;
}

class zookeepermanagewidget : public QWidget
{
    Q_OBJECT
private:
    Ui::zookeepermanagewidget *ui;

    int mode = 1;                                   //默认暗黑主题
    int count = 0;                                  //连接总数
    QButtonGroup * m_buttonGroup = nullptr;         //按钮组
    zookeepersql * db = nullptr;                    //操作数据库
    QMap<int,int> connectManager;                   //暂时是保存连接信息
    QMap<void *, zkStatusStruct> zkStatusInfoMap;   //管理连接信息
    
public:
    //创建zk界面 但不创建连接
    explicit zookeepermanagewidget(QWidget *parent = 0);
    //创建zk界面，创建一个连接
    explicit zookeepermanagewidget(connnectInfoStruct& cInfoStruct, QWidget *parent = 0);
    ~zookeepermanagewidget();
    
    //初始化数据库信息
    void initDBInfo();
    //新建连接
    void newZKWidget(connnectInfoStruct& cInfoStruct);
    //创建按钮
    void createButton(QString text, bool isConnect = false, bool isChecked = false, zookeeperwidget * zkWidget = nullptr);
    //切换全局主题
    void changeMainWindowTheme(bool isChange = false, int windowsType = 1);
    //切换圆角
    void changeMainWindowRadius(int windowsType = 1);

private slots:
    //新建连接按钮信号
    void on_toolButton_newCreate_clicked();
    //连接按钮信号 调用newZKWidget
    void on_toolButton_connect_clicked();
    //保存连接信号
    void on_toolButton_save_clicked();
    //取消信号 切回zk欢迎界面
    void on_toolButton_close_clicked();
    //zk欢迎界面点击跳转
    void on_toolButton_clicked();
    //初始化结果
    void rece_init(int buttonSid, int code);
    //按钮点击
    void rece_buttonClicked(int index);
};

#endif // ZOOKEEPERMANAGEWIDGET_H
