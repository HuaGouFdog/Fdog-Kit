#pragma execution_character_set("utf-8")
#include "zookeeperhandle.h"
#include <QTest>
#include <QMetaType>
#include <QJsonParseError>


zookeeperhandle::zookeeperhandle(QObject *parent) : QObject(parent)
{
    qRegisterMetaType<QVector<int>>("QVector<int>&");
    qRegisterMetaType<QVector<QString>>("QVector<QString>&");
}

zookeeperhandle::zookeeperhandle(QObject * obj_, zhandle_t *zh_)
{
    this->zh = zh_;
    this->obj = obj_;
    qRegisterMetaType<QVector<int>>("QVector<int>&");
    qRegisterMetaType<QVector<QString>>("QVector<QString>&");
}

//void zookeeperhandle::getAllChildren()
//{
//    String_vector children;
//    int rc = zoo_get_children(zh, path.toStdString().c_str(), 0, &children);
//    if (rc == ZOK) {
//        QVariant varValue = QVariant::fromValue(children);
//        emit sendAllChildren(path, varValue, item);
//    } else {

//    }
//    return;
//}

void zookeeperhandle::getChildren(int &code, int &count, QString path)
{
    qDebug() << "获取" << path;
    String_vector children;
    int rc = zoo_wget_children(zh, path.toStdString().c_str(), watcher2, 0, &children);
    if (rc == ZOK) {
        code = rc;
        count = children.count;
        qDebug() << "孩子数为" << count;
    } else {
        qDebug() << "rc = " << rc;
    }
//    QVector<int> childrenList;
//    QVector<QString> dataList;
//    if (rc != ZOK) {
//        return;
//    }

//    for (int i = 0; i < children.count; ++i) {
//        QString children_path;
//        if (path != "/") {
//            children_path = QString::fromStdString(path.toStdString() + "/" + children.data[i]);

//        } else {
//            children_path = QString::fromStdString(path.toStdString() + children.data[i]);
//        }

//        Stat stat;
//        QString data;
//        //getNodeInfo(stat, data, children_path);
//        childrenList.push_back(children.count);
//        dataList.push_back(data);
//    }

//    QVariant varValue = QVariant::fromValue(children);
//    int code = 0;
//    QString message;
//    emit send_getChildren(code, message, path, varValue, dataList, childrenList, item);
    return;
}

//zhandle_t *zookeeperhandle::getZh() const
//{
//    return zh;
//}

//void zookeeperhandle::setZh(zhandle_t *value)
//{
//    zh = value;
//}

//QString zookeeperhandle::getPath() const
//{
//    return path;
//}

//void zookeeperhandle::setPath(const QString &value)
//{
//    path = value;
//}

//QTreeWidgetItem *zookeeperhandle::getItem() const
//{
//    return item;
//}

//void zookeeperhandle::setItem(QTreeWidgetItem *value)
//{
//    item = value;
//}

void zookeeperhandle::getNodeInfo(QString path)
{
    qDebug() << "getNodeInfo" << path << " Thread ID:" << QThread::currentThreadId();
    QString message;
    Stat stat;
    QString data;
    char buffer[1024]  = {0}; //不写0 会乱码
    int buffer_len = sizeof(buffer);
    int rc = zoo_get(zh, path.toStdString().c_str(), 0, buffer, &buffer_len, &stat);
    QVariant varValue = QVariant::fromValue(stat);
    emit send_getNodeInfo(rc, message, varValue, data, path);
    return;
}

void zookeeperhandle::createNode(QString nodePath, QString nodeData, QTreeWidgetItem *item)
{
    int code = 0;
    QString data;
    QString message;
    QVariant varValue;
    int nodeDataLen = strlen(nodeData.toStdString().c_str());
    // 创建节点
    //qDebug() << "node = " << nodePath;
    Stat stat;
    int rc = zoo_create(zh, nodePath.toStdString().c_str(), nodeData.toStdString().c_str(), nodeDataLen, &ZOO_OPEN_ACL_UNSAFE, 0, NULL, 0);
//    if (rc != ZOK) {
//        code = -1;
//        emit send_createNode(code, message, nodePath, varValue, data, item);
//        qDebug() << "add " << nodePath << " fail rc = " << rc;
//        return;
//    }
//    rc = getNodeInfo(nodePath);
//    if (rc != ZOK) {
//        code = -2;
//        emit send_createNode(code, message, nodePath, varValue, data, item);
//    }
    varValue = QVariant::fromValue(stat);
    emit send_createNode(rc, message, nodePath, varValue, data, item);
    return;
}

void zookeeperhandle::setNodeData(QString nodePath, QString nodeData)
{
    QString message;
    std::string path = nodePath.toStdString();
    //修改节点数据
    std::string data = nodeData.toStdString();
    int data_len = strlen(data.c_str());
    int ret = zoo_set(zh, path.c_str(), data.c_str(), data_len, -1);
    emit send_setNodeData(ret, message);
    return;
}

void zookeeperhandle::deleteNode(QString path, QTreeWidgetItem *item)
{
    QString message;
    int ret = zoo_delete(zh, path.toStdString().c_str(), -1);
//    if (ret != ZOK) {
//        qDebug() << "Failed to delete node. Error";
//    }
    emit send_deleteNode(ret, message, item);
    return;
}

void watcher(zhandle_t *zh, int type, int state, const char *path, void *watcherCtx)
{
    qDebug() << "watcher ...";
    //监听事件回调函数
    if (type ==ZOO_SESSION_EVENT) {
        if (state == ZOO_CONNECTED_STATE) {
          g_connected = true;
          qDebug() << "g_connected success";
        } else if (state == ZOO_AUTH_FAILED_STATE) {
        } else if (state == ZOO_EXPIRED_SESSION_STATE) {
        } else if (state == ZOO_CONNECTING_STATE) {
        } else if (state == ZOO_ASSOCIATING_STATE) {
        }
    } else {
        qDebug() << "其他事件";
        // 其他类型的事件
        // 在这里处理其他类型的事件
    }
}


void zookeeperhandle::init(QString rootPath, QString host_, QString port_)
{
    int count = 0;
    //ZooKeeper服务器的地址和端口
    std::string host = host_.toStdString() + ":" + port_.toStdString();
    //连接超时时间（毫秒）
    int timeout = 3000;
    do {
        count++;
        // 创建ZooKeeper句柄
        zh = zookeeper_init(host.c_str(), watcher, timeout, 0, obj, 0);
        QTest::qSleep(100);
    } while(!g_connected && count < ZK_MAX_CONNECT_TIMES);

    //QString rootPath = "/";
    if (!g_connected) {
        qDebug() << "connect ZooKeeper fail";
        //退出
        //Stat stat;
        //QString Data;
        //QVariant varValue = QVariant::fromValue(stat);
        int code;
        QString message;
        emit send_init(g_connected, code, message, rootPath, 0);
        return;
    }
    int code;
    int childrenCount;
    QString message;
    getChildren(code, childrenCount, rootPath);

    //返回给主界面
    //QVariant varValue = QVariant::fromValue(stat);
    emit send_init(g_connected, code, message, rootPath, childrenCount);
    return;
}


void watcher2(zhandle_t *zh, int type, int state, const char *path, void *watcherCtx)
{
    {
        qDebug() << "watcher2 ...";
        //监听事件回调函数
        if (type == ZOO_CHILD_EVENT) {
            // 子节点发生变化
            // 在这里处理子节点变化的逻辑
            qDebug() << "子节点发生变化" << path;
            QString path_str(path);
            QObject * obj_ = (QObject*)watcherCtx;
            QMetaObject::invokeMethod(obj_,"rece_children_event",Qt::QueuedConnection, Q_ARG(QString, path_str));

        } else if (type == ZOO_CHANGED_EVENT) {
            qDebug() << "节点数据发生变化";
            // 节点数据发生变化
            // 在这里处理节点数据变化的逻辑
        } else if (type == ZOO_DELETED_EVENT) {
            // 节点被删除
            // 在这里处理节点被删除的逻辑
            qDebug() << "节点被删除";
        } else if (type == ZOO_CREATED_EVENT) {
            qDebug() << "节点被创建";
            // 节点被创建
            // 在这里处理节点被创建的逻辑
        } else {
            qDebug() << "其他事件";
            // 其他类型的事件
            // 在这里处理其他类型的事件
        }
    }
}

void NodeWatcher(zhandle_t *zh, int type, int state, const char *path, void *watcherCtx)
{
        qDebug() << "NodeWatcher ";
        if (type == ZOO_CHILD_EVENT) {
            // 子节点发生变化
            // 在这里处理子节点变化的逻辑
            qDebug() << "子节点发生变化" << path;
            QString path_str(path);
            //QMetaObject::invokeMethod(zookeeperhandle::obj,"rece_getChildren",Qt::QueuedConnection, Q_ARG(QString, path_str));
        } else if (type == ZOO_CHANGED_EVENT) {
            qDebug() << "节点数据发生变化";
            // 节点数据发生变化
            // 在这里处理节点数据变化的逻辑
        } else if (type == ZOO_DELETED_EVENT) {
            // 节点被删除
            // 在这里处理节点被删除的逻辑
            qDebug() << "节点被删除";
        } else if (type == ZOO_CREATED_EVENT) {
            qDebug() << "节点被创建";
            // 节点被创建
            // 在这里处理节点被创建的逻辑
        } else {
            qDebug() << "其他事件";
            // 其他类型的事件
            // 在这里处理其他类型的事件
        }
}
