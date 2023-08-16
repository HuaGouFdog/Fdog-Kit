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

    void showNodeInfo(QString Data, Stat stat, QString path);

    void getNodeInfo(QString &path);

    void hideNodeInfoWidget(); //隐藏节点信息
    void showNodeInfoWidget(); //显示节点信息

    void hideCreateWidget();//隐藏创建节点控件
    void showCreateWidget();//显示创建节点控件

    //int32_t getNodeInfo(QString &path); //返回孩子数
    //void getNodeData(QString &path);
    void addNode(QString &path);
    void deleteNode(QString &path);

    void searchNode(QString name);

    //void getAllChildren(zhandle_t* zh, std::string path, QTreeWidgetItem * item, int x =0, int y = 0);
    //void watcher(zhandle_t *zh, int type, int state, const char *path, void *watcherCtx);

private slots:
    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);

    void on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column);

    void on_textEdit_data_textChanged();

    void on_treeWidget_customContextMenuRequested(const QPoint &pos);

    void on_nodeAction();

    void on_toolButton_saveData_clicked();

    void on_toolButton_createData_clicked();

    void on_toolButton_add_clicked();

    void on_toolButton__delete_clicked();

    void on_toolButton_refresh_clicked();

    void on_getAllChildren(QString path, const QVariant varValue, QTreeWidgetItem *item);

    void rece_init(bool connected, QString path, const QVariant varValue, QString data);

    void rece_getChildren(QString path, const QVariant varValue, QVector<QString> dataList, QVector<int> childrenList, QTreeWidgetItem *item);

    void rece_getNodeInfo_2(QVariant varValue, QString data, QString path);

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

    QThread * thread;
};

#endif // ZOOKEEPERWIDGET_H
