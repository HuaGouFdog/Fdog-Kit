#ifndef ZOOKEEPERHANDLE_H
#define ZOOKEEPERHANDLE_H

#include <QObject>
//#include <QWidget>
#include "zookeeper.h"
#include <QTreeWidgetItem>
#include <QThread>
#include "createconnect.h"
#include <QDebug>
#include <QRunnable>
Q_DECLARE_METATYPE(String_vector);
Q_DECLARE_METATYPE(Stat);
Q_DECLARE_METATYPE(QTreeWidgetItem*);
Q_DECLARE_METATYPE(QVector<int>);
Q_DECLARE_METATYPE(QVector<QString>);

#define ZK_MAX_CONNECT_TIMES 5 //连接最大尝试次数
static bool g_connected = false;  // 是否连接上zk

void watcher2(zhandle_t *zh, int type, int state, const char *path, void *watcherCtx);
void NodeWatcher(zhandle_t *zh, int type, int state, const char *path, void *watcherCtx);

class ZkRunnable : public QObject, public QRunnable {
    Q_OBJECT
public:
    ZkRunnable(QObject * obj_ = NULL, zhandle_t *zh_ = NULL, QString path_ = "", QTreeWidgetItem *item_ = NULL) {
        obj = obj_;
        zh = zh_;
        path = path_;
        item = item_;
    }
    void run() override {
        //qDebug() << "Running in thread: " << QThread::currentThread() << " path = " << path;
        String_vector children;
        int rc = zoo_wget_children(zh, path.toStdString().c_str(), watcher2, obj, &children);
        QVector<int> childrenList;
        QVector<QString> dataList;
        if (rc != ZOK) {
            return;
        }

        for (int i = 0; i < children.count; ++i) {
            QString children_path;
            if (path != "/") {
                children_path = QString::fromStdString(path.toStdString() + "/" + children.data[i]);

            } else {
                children_path = QString::fromStdString(path.toStdString() + children.data[i]);
            }
            //qDebug() << "getChildren children_path = " << children_path;

            QString data;
            childrenList.push_back(children.count);
            dataList.push_back(data);
        }

        QVariant varValue = QVariant::fromValue(children);
        int code = 0;
        QString message;

        QMetaObject::invokeMethod(obj,"rece_getChildren",Qt::QueuedConnection, Q_ARG(int,code), Q_ARG(QString,message),
                                  Q_ARG(QString,path), Q_ARG(QVariant, varValue), Q_ARG(QVector<QString>,dataList),
                                  Q_ARG(QVector<int>, childrenList), Q_ARG(QTreeWidgetItem*, item));
        return;
    }

    QObject * obj;
    zhandle_t *zh;
    QString path;
    QTreeWidgetItem *item;
};



class zookeeperhandle : public QObject
{
    Q_OBJECT
public:
    explicit zookeeperhandle(QObject *parent);

    explicit zookeeperhandle(QObject * obj_ = NULL, zhandle_t *zh_ = NULL);

signals:
    //只是触发
    //void sendAllChildren(QString path, const QVariant varValue, QTreeWidgetItem *item);
    void send_getChildren(int code, QString message, QString path, const QVariant varValue, QVector<QString> dataList, QVector<int> childrenList, QTreeWidgetItem *item);
    void send_init(bool connected,int code, QString message, QString path, const QVariant varValue, QString data);
    void send_getNodeInfo_2(int code, QString message, QVariant varValue, QString data, QString path);
    void send_createNode(int code, QString message, QString path, QVariant varValue, QString data, QTreeWidgetItem *item);
    void send_deleteNode(int code, QString message, QTreeWidgetItem *item);


public slots:
    void init(QString rootPath, QString host, QString port);
    //void getAllChildren();
    void getChildren(QString path, QTreeWidgetItem *item);
    int getNodeInfo(Stat &stat, QString &data, QString &path);
    void getNodeInfo_2(QString path);
    void createNode(QString nodePath, QString nodeData, QTreeWidgetItem *item);
    void deleteNode(QString path, QTreeWidgetItem *item);
public:
    QString host;
    QString port;
    zhandle_t *zh;
    QObject * obj;
    //QString path;
    //QTreeWidgetItem *item;
};




class NodeWorker : public QObject
{
    Q_OBJECT

public:
    explicit NodeWorker(const std::string& path, zhandle_t* zh, QObject* parent = nullptr)
        : QObject(parent), path_(path), zh_(zh)
    {
    }

public slots:
    void process()
    {
        qDebug() << "开始获取节点";
        std::vector<std::string> nodes;
        getChildrenRecursive(zh_, path_, nodes);

        // 发送节点列表信号
        //emit nodesReady(nodes);
    }

signals:
    void nodesReady(const std::vector<std::string>& nodes);

private:
    void getChildrenRecursive(zhandle_t* zh, const std::string& path, std::vector<std::string>& nodes)
    {

        qDebug() << "getChildrenRecursive path = " << QString::fromStdString(path);
        struct String_vector childNodes;
        int ret = zoo_get_children(zh, path.c_str(), 0, &childNodes);
        if (ret != ZOK) {
            qDebug() << "Failed to get children nodes for path";
            return;
        }

        for (int i = 0; i < childNodes.count; ++i) {
            std::string path2 = path;
            qDebug() << "childPath = " << childNodes.count;
            //std::string childPath = path + "/" + childNodes.data[i];
            //nodes.push_back(childPath);
            //getChildrenRecursive(zh, childPath, nodes);
        }

        // 释放子节点列表资源
        //deallocate_String_vector(&childNodes);
    }

    std::string path_;
    zhandle_t* zh_;
};

class NodeWorkerThread : public QThread
{
    Q_OBJECT

public:
    explicit NodeWorkerThread(const std::string& path, zhandle_t* zh, QObject* parent = nullptr)
        : QThread(parent), path_(path), zh_(zh)
    {
    }

    void run() override
    {
        NodeWorker worker(path_, zh_);
        connect(&worker, &NodeWorker::nodesReady, this, &NodeWorkerThread::handleNodesReady);
        worker.process();
    }

signals:
    void nodesReady(const std::vector<std::string>& nodes);

private slots:
    void handleNodesReady(const std::vector<std::string>& nodes)
    {
        emit nodesReady(nodes);
    }

private:
    std::string path_;
    zhandle_t* zh_;
};
#endif // ZOOKEEPERHANDER_H
