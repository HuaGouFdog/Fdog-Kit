#ifndef ZOOKEEPERMANAGEWIDGET_H
#define ZOOKEEPERMANAGEWIDGET_H

#include <QWidget>
#include "zookeeperwidget.h"
#include <QButtonGroup>
#include <QMap>
//#include "module_sql/sqlhandle.h"
#include "zookeepersql.h"
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

public:
    explicit zookeepermanagewidget(QWidget *parent = 0);//创建zk界面
    explicit zookeepermanagewidget(connnectInfoStruct& cInfoStruct, QWidget *parent = 0);//创建zk界面，并进行一个连接
    void newZKWidget(connnectInfoStruct& cInfoStruct);
    ~zookeepermanagewidget();


    //切换全局主题
    void changeMainWindowTheme(bool isChange = false, int windowsType = 1);

    //切换圆角
    void changeMainWindowRadius(int windowsType = 1);

private slots:
    void on_toolButton_newCreate_clicked();

    void on_toolButton_save_clicked();

    void on_toolButton_close_clicked();

    void on_toolButton_clicked();

    void on_toolButton_connect_clicked();

    void rece_buttonClicked(int index);

    void rece_init(int buttonSid, int code);

private:
    Ui::zookeepermanagewidget *ui;
    QButtonGroup * m_buttonGroup;

    QMenu *zktoolMenu;
    
    int count = 0; //连接总数
    int lastIndex;
    QMap<int,int> connectManager;

    //操作数据库

    zookeepersql * db;

    QMap<void *, zkStatusStruct> zkStatusInfoMap;

    int mode = 1;


};

#endif // ZOOKEEPERMANAGEWIDGET_H
