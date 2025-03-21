﻿#ifndef ZOOKEEPERWIDGET_H
#define ZOOKEEPERWIDGET_H
#include <QMenu>
#include <QWidget>
#include <QAction>
#include <QThread>
#include <QThreadPool>
#include <QTreeWidgetItem>
#include <QListWidgetItem>
#include "zookeeper.h"
#include "module_utils/utils.h"
#include "module_zookeeper/zookeeperhandle.h"

namespace Ui {
class zookeeperwidget;
}

class zookeeperwidget : public QWidget
{
    Q_OBJECT
private:
    Ui::zookeeperwidget *ui;

    bool isUnfold; //是否折叠

    QMenu *popMenu;
    QAction * m_action_add;
    QAction * m_action_refresh;
    QAction * m_action_delete;
    QAction * m_action_copy;

    QMenu *textMenu;
    //QAction * m_action_text_undo;
    //QAction * m_action_text_redo;
    QAction * m_action_text_copy;
    QAction * m_action_text_paste;
    QAction * m_action_text_delete;
    //QAction * m_action_text_allSelect;

    QMenu *editTextMenu;
    QAction * m_action_editText_copy;
    QAction * m_action_editText_paste;
    QAction * m_action_editText_delete;
    //QAction * m_action_editText_allSelect;

    QThread * thread;
    QThreadPool threadpool;
    zookeeperhandle * zookhandle;

    QString nodeData;     //节点原数据
    QString nodeDataPath; //节点原数据对应的节点

    int8_t buttonSid;

    bool isFirst = true;
    bool isCreate = false; //区分创建和修改

    QFMessageBox * tipwidget = nullptr;

public:
    explicit zookeeperwidget(QWidget *parent = 0);
    explicit zookeeperwidget(connnectInfoStruct& cInfoStruct, QWidget *parent = 0);
    ~zookeeperwidget();

    void init(QString host, QString port, int timeout);

    void getChildren(QString path, QTreeWidgetItem *item);

    void getNodeInfo(QString path);

    void showNodeInfo(QString Data, QVariant varValue, QString path);

    void addNode(QString &path);
    void deleteNode(QString &path);
    //void searchNode(QString name);

    //展开选中节点
    void expandSelectItems(QTreeWidget* treeWidget, QString path, QString pathAll);
    void expandSelectItems_s(QTreeWidgetItem* Item, const QString path, QString pathAll);
    void showParent2(QTreeWidgetItem* pItem);

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

    //发送弹窗提示
    void showMessage(QString message, bool isSuccess = true); //显示操作信息

    void getParentNode(QTreeWidgetItem *item, QString &data);
signals:
    void send_init(int buttonSid, int code);
private slots:
    void rece_init(int connectState, int code, QString message, QString path, int count);

    void rece_getChildren(int code, QString message, QString path, const QVariant varValue, QTreeWidgetItem *item);

    void rece_getNodeInfo(int code, QString message, QVariant varValue, QString data, QString path);

    void rece_setNodeData(int code, QString message);

    void rece_createNode(int code, QString message, QString path, QVariant varValue, QString data, QTreeWidgetItem *item);

    void rece_deleteNode(int code, QString message, QTreeWidgetItem *item);

    void rece_children_event(int code, QString message, QString path, const QVariant varValue);

    void rece_delete_event(int code, QString message, QString path);

    void rece_chanage_event(int code, QString message, QString path);

    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);

    void on_textEdit_data_textChanged();

    void on_treeWidget_customContextMenuRequested(const QPoint &pos);

    void on_nodeAction();

    void on_toolButton_saveData_clicked();

    void on_toolButton_createData_clicked();

    void on_toolButton_add_clicked();

    void on_toolButton_refresh_clicked();

    void on_toolButton_copy_data_clicked();

    void on_lineEdit_search_textChanged(const QString &arg1);

    void on_toolButton_unfold_clicked();

    void on_lineEdit_search_returnPressed();

    void on_checkBox_auto_url_clicked();

    void on_toolButton_clear_clicked();

    void on_toolButton_cancel_clicked();

    void on_textEdit_data_customContextMenuRequested(const QPoint &pos);

    void on_toolButton_copy_node_clicked();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_textEdit_data_edit_customContextMenuRequested(const QPoint &pos);

    void rece_text_copy_sgin();
    void rece_text_paste_sgin();
    void rece_text_delete_sgin();

    void rece_editText_copy_sgin();
    void rece_editText_paste_sgin();
    void rece_editText_delete_sgin();

protected:
    void resizeEvent(QResizeEvent *event) override;
};

#endif // ZOOKEEPERWIDGET_H
