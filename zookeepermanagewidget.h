#ifndef ZOOKEEPERMANAGEWIDGET_H
#define ZOOKEEPERMANAGEWIDGET_H

#include <QWidget>
#include "zookeeperwidget.h"
#include <QButtonGroup>
#include <QMap>
namespace Ui {
class zookeepermanagewidget;
}

class zookeepermanagewidget : public QWidget
{
    Q_OBJECT

public:
    explicit zookeepermanagewidget(QWidget *parent = 0);//创建zk界面
    explicit zookeepermanagewidget(connnectInfoStruct& cInfoStruct, QWidget *parent = 0);//创建zk界面，并进行一个连接
    void newCreate(connnectInfoStruct& cInfoStruct);
    ~zookeepermanagewidget();

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
    
    int count; //连接总数
    int lastIndex;
    QMap<int,int> connectManager;
};

#endif // ZOOKEEPERMANAGEWIDGET_H
