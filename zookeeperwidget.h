#ifndef ZOOKEEPERWIDGET_H
#define ZOOKEEPERWIDGET_H
#include <QMenu>
#include <QWidget>
#include <QAction>
#include <QThread>
#include <QThreadPool>
#include <QTreeWidgetItem>
#include "zookeeper.h"
#include "createconnect.h"
#include "zookeeperhandle.h"


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

    void getNodeInfo(QString &path);

    void showNodeInfo(QString Data, QVariant varValue, QString path);

    void addNode(QString &path);
    void deleteNode(QString &path);
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

    void expandAllItemsOne(QTreeWidget* treeWidget, bool isexpand, int sum);
    void expandItemAndChildrenOne(QTreeWidgetItem* item, bool isexpand, int sum);

    void deleteTreeNode (QTreeWidgetItem* item);
    void deleteTreeItem (QTreeWidgetItem* item);

    void copyPath();

    void hideNodeInfoWidget(); //隐藏节点信息
    void showNodeInfoWidget(); //显示节点信息

    void hideCreateWidget();//隐藏创建节点控件
    void showCreateWidget();//显示创建节点控件

    void hideCreateZkWidget();
    void showCreateZkWidget();
    void hideButton();

    void showMessage(QString message, bool isSuccess = true); //显示操作信息
    
private slots:
    void rece_init(int connectState, int code, QString message, QString path, int count);

    void rece_getChildren(int code, QString message, QString path, const QVariant varValue, QTreeWidgetItem *item);

//    void rece_getSingleChildren(int code, QString message, QString path, const QVariant varValue);

    void rece_getNodeInfo(int code, QString message, QVariant varValue, QString data, QString path);

    void rece_setNodeData(int code, QString message);

    void rece_createNode(int code, QString message, QString path, QVariant varValue, QString data, QTreeWidgetItem *item);

    void rece_deleteNode(int code, QString message, QTreeWidgetItem *item);

    void rece_children_event(int code, QString message, QString path, const QVariant varValue);

    void rece_create_event(QString path);

    void rece_delete_event(int code, QString message, QString path);

    void rece_chanage_event(int code, QString message, QString path);

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

    void on_toolButton_copy_data_clicked();

    void on_lineEdit_search_textChanged(const QString &arg1);

    void on_toolButton_unfold_clicked();

    void on_lineEdit_search_returnPressed();

    void on_toolButton_6_clicked();

    void on_treeWidget_itemEntered(QTreeWidgetItem *item, int column);

    void on_toolButton_3_clicked();

    void on_toolButton_save_clicked();

    void on_toolButton_close_clicked();

private:
    Ui::zookeeperwidget *ui;

    bool isUnfold; //是否折叠

    QMenu *popMenu;
    QAction * m_action_add;
    QAction * m_action_refresh;
    QAction * m_action_delete;
    QAction * m_action_copy;

    QThread * thread;
    QThreadPool threadpool;
    zookeeperhandle * zookhandle;

    QString nodeData;     //节点原数据
    QString nodeDataPath; //节点原数据对应的节点

};

#endif // ZOOKEEPERWIDGET_H
