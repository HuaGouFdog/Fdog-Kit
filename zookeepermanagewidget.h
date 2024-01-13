#ifndef ZOOKEEPERMANAGEWIDGET_H
#define ZOOKEEPERMANAGEWIDGET_H

#include <QWidget>
#include "zookeeperwidget.h"
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

private:
    Ui::zookeepermanagewidget *ui;
};

#endif // ZOOKEEPERMANAGEWIDGET_H
