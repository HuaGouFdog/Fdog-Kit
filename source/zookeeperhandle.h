#ifndef ZOOKEEPERHANDLE_H
#define ZOOKEEPERHANDLE_H

#include <QObject>
#include <QThread>
#include <QDebug>
#include <QRunnable>
#include <QTreeWidgetItem>
#include "zookeeper.h"
#include "createconnect.h"

#define ZK_MAX_CONNECT_TIMES 5 //连接最大尝试次数

Q_DECLARE_METATYPE(String_vector);
Q_DECLARE_METATYPE(Stat);
Q_DECLARE_METATYPE(QTreeWidgetItem*);
Q_DECLARE_METATYPE(QVector<int>);
Q_DECLARE_METATYPE(QVector<QString>);

//处理zk初始化事件
void initWatcher(zhandle_t *zh, int type, int state, const char *path, void *watcherCtx);
//处理节点事件
void nodeWatcher(zhandle_t *zh, int type, int state, const char *path, void *watcherCtx);


class ZkRunnable : public QObject, public QRunnable {
    Q_OBJECT
public:
    ZkRunnable(QObject * obj_ = NULL, zhandle_t *zh_ = NULL, QString path_ = "", QTreeWidgetItem *item_ = NULL) {
        obj = obj_;
        zh = zh_;
        path = path_;
        item = item_;
    }

    ~ZkRunnable() {
        //不需要释放
    }

    void run() override {
        String_vector children;
        int rc = zoo_wget_children(zh, path.toStdString().c_str(), nodeWatcher, obj, &children);
        QVariant varValue = QVariant::fromValue(children);
        QString message;
        if (rc != ZOK) {
            QMetaObject::invokeMethod(obj,"rece_getChildren",Qt::QueuedConnection, Q_ARG(int,rc), Q_ARG(QString,message),
                                        Q_ARG(QString,path), Q_ARG(QVariant, varValue), Q_ARG(QTreeWidgetItem*, item));
            return;
        }
//        for (int i = 0; i < children.count; ++i) {
//            QString children_path;
//            if (path != "/") {
//                children_path = QString::fromStdString(path.toStdString() + "/" + children.data[i]);
//            } else {
//                children_path = QString::fromStdString(path.toStdString() + children.data[i]);
//            }
//        }
        QMetaObject::invokeMethod(obj,"rece_getChildren",Qt::QueuedConnection, Q_ARG(int,rc), Q_ARG(QString,message),
                                    Q_ARG(QString,path), Q_ARG(QVariant, varValue), Q_ARG(QTreeWidgetItem*, item));
        return;
    }

public:
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
    void send_init(int connectState,int code, QString message, QString path, int count);
    void send_getChildren(int code, QString message, QString path, const QVariant varValue, QTreeWidgetItem *item);
    void send_setNodeData(int code, QString message);
    void send_getNodeInfo(int code, QString message, QVariant varValue, QString data, QString path);
    void send_createNode(int code, QString message, QString path, QVariant varValue, QString data, QTreeWidgetItem *item);
    void send_deleteNode(int code, QString message, QTreeWidgetItem *item);

public slots:
    void init(QString rootPath, QString host, QString port, int timeout);
    void getChildren(int &code, int &count, QString path); //获取节点太费时，使用线程池获取节点，只有获取根节点时才走这里
    void getSingleChildren(QString path, void * obj_);
    void setNodeData(QString nodePath, QString nodeData);
    void getNodeInfo(QString path);
    void createNode(QString nodePath, QString nodeData, QTreeWidgetItem *item);
    void deleteNode(QString path, QTreeWidgetItem *item);

public:
    QString host;
    QString port;
    zhandle_t *zh;
    QObject * obj;
    int connectState;  // 是否连接上zk
};

#endif // ZOOKEEPERHANDLE_H
