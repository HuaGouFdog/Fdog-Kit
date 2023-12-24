#ifndef ZOOKEEPERWIDGET_H
#define ZOOKEEPERWIDGET_H
#include <QWidget>
#include "createconnect.h"
#include "zookeeperhandle.h"
#include "zookeeper.h"
#include <QTreeWidgetItem>
#include <QMenu>
#include <QAction>
#include <QThread>
#include <QThreadPool>

namespace Ui {
class zookeeperwidget;
}

class zookeeperwidget : public QWidget
{
    Q_OBJECT

public:
    explicit zookeeperwidget(connnectInfoStruct& cInfoStruct, QWidget *parent = 0);
    ~zookeeperwidget();

    void init(QString host, QString port);

    void getChildren(QString path, QTreeWidgetItem *item);

    void showNodeInfo(QString Data, QVariant varValue, QString path);

    void getNodeInfo(QString &path);

    void hideNodeInfoWidget(); //隐藏节点信息
    void showNodeInfoWidget(); //显示节点信息

    void hideCreateWidget();//隐藏创建节点控件
    void showCreateWidget();//显示创建节点控件

    void addNode(QString &path);
    void deleteNode(QString &path);
    void copyPath();
    void searchNode(QString name);

    //使用递归实现对查找到的项的父子索引项遍历且设置为可见
    void showParent(QTreeWidgetItem* pItem);
    //对当前的节点进行遍历查找且对遍历的节点进行显示和隐藏的设置
    void showSon(QTreeWidgetItem* pItem);
    //对整个树形索引控件的一级索引项进行遍历，并调用上述的函数实现对每个一级索引项下的索引项进行递归遍历设置
    void searchItem(QTreeWidgetItem* tableItem, const QString& strText);

    void showItem(const QString& strText);

    //展开/折叠所有节点
    void expandAllItems(QTreeWidget* treeWidget, bool isexpand, int sum);

    void expandItemAndChildren(QTreeWidgetItem* item, bool isexpand, int sum);

private slots:
    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);

    void on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column);

    void on_textEdit_data_textChanged();

    void on_treeWidget_customContextMenuRequested(const QPoint &pos);

    void on_nodeAction();

    void on_toolButton_saveData_clicked();

    void on_toolButton_createData_clicked();

    void on_toolButton_add_clicked();

    void on_toolButton_delete_clicked();

    void on_toolButton_refresh_clicked();

    void on_getAllChildren(QString path, const QVariant varValue, QTreeWidgetItem *item);

    void rece_init(bool connected, int code, QString message, QString path, const QVariant varValue, QString data);

    void rece_getChildren(int code, QString message, QString path, const QVariant varValue, QVector<QString> dataList, QVector<int> childrenList, QTreeWidgetItem *item);

    void rece_getNodeInfo_2(int code, QString message, QVariant varValue, QString data, QString path);

    void rece_createNode(int code, QString message, QString path, QVariant varValue, QString data, QTreeWidgetItem *item);

    void rece_deleteNode(int code, QString message, QTreeWidgetItem *item);

    void on_toolButton_copy_data_clicked();

    void on_lineEdit_search_textChanged(const QString &arg1);

    void on_toolButton_unfold_clicked();

    void on_lineEdit_search_returnPressed();

private:
    Ui::zookeeperwidget *ui;
    zhandle_t* zh; //zk连接句柄
    QTreeWidgetItem *topItem; //顶级item
    QTreeWidgetItem *parentItem; //父节点
    QString nodeData; //节点原数据
    QString nodeDataPath; //节点原数据对应的节点

    QMenu *popMenu;
    QAction * m_action_add;
    QAction * m_action_refresh;
    QAction * m_action_delete;
    QAction * m_action_copy;

    zookeeperhandle * zookhandle;
    zookeeperhandle * zookhandle2;
    zookeeperhandle * zookhandle3;
    zookeeperhandle * zookhandle4;
    zookeeperhandle * zookhandle5;

    QThread * thread;
    QThread * thread2;
    QThread * thread3;
    QThread * thread4;
    QThread * thread5;
    int threadSum = 1;
    bool isUnfold;
};

#endif // ZOOKEEPERWIDGET_H
