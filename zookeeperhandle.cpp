﻿#pragma execution_character_set("utf-8")
#include "zookeeperhandle.h"
#include <QTest>
#include <QMetaType>
#include <QJsonParseError>

void initWatcher(zhandle_t *zh, int type, int state, const char *path, void *watcherCtx)
{
    qDebug() << "initWatcher ...";
    //监听事件回调函数
    if (type ==ZOO_SESSION_EVENT) {
        if (state == ZOO_CONNECTED_STATE) {
          int * connectState = (int *)watcherCtx;
          *connectState = ZOO_CONNECTED_STATE;
          qDebug() << "connectState success";
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

void nodeWatcher(zhandle_t *zh, int type, int state, const char *path, void *watcherCtx)
{
    //监听事件回调函数
    QObject * obj_ = (QObject*)watcherCtx;
    QString path_str(path);
    QString message;
    if (type == ZOO_CHILD_EVENT) {
        // 子节点发生变化
        qDebug() << "子节点发生变化" << path;
        //再次监听
        String_vector children;
        int rc = zoo_wget_children(zh, path, nodeWatcher, obj_, &children);
        QVariant varValue = QVariant::fromValue(children);
        QString message;
        if (rc != ZOK) {
            qDebug() << "出错" << rc << " " << path;
            QMetaObject::invokeMethod(obj_,"rece_delete_event",Qt::QueuedConnection, Q_ARG(int,0), Q_ARG(QString,message), Q_ARG(QString,path_str));
            return;
        }
        QMetaObject::invokeMethod(obj_,"rece_children_event",Qt::QueuedConnection, Q_ARG(int,rc), Q_ARG(QString,message),
                                        Q_ARG(QString,path_str), Q_ARG(QVariant, varValue));

    } else if (type == ZOO_CHANGED_EVENT) {
        qDebug() << "节点数据发生变化" << path;
        // 节点数据发生变化
        // 在这里处理节点数据变化的逻辑
    } else if (type == ZOO_DELETED_EVENT) {
        // 节点被删除
        // 在这里处理节点被删除的逻辑
        qDebug() << "节点被删除1" << path;
        QMetaObject::invokeMethod(obj_,"rece_delete_event",Qt::QueuedConnection, Q_ARG(int,0), Q_ARG(QString,message), Q_ARG(QString,path_str));
    } else if (type == ZOO_CREATED_EVENT) {
        qDebug() << "节点被创建" << path;
        // 节点被创建
        // 在这里处理节点被创建的逻辑
    } else {
        qDebug() << "其他事件";
        // 其他类型的事件
        // 在这里处理其他类型的事件
    }
    //QMetaObject::invokeMethod(obj_,"rece_children_event",Qt::QueuedConnection, Q_ARG(QString, path_str));
}

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

void zookeeperhandle::init(QString rootPath, QString host_, QString port_)
{
    int count = 0;
    QString message;
    std::string host = host_.toStdString() + ":" + port_.toStdString();
    //连接超时时间（毫秒）
    int timeout = 3000;
    do {
        count++;
        // 创建ZooKeeper句柄
        zh = zookeeper_init(host.c_str(), initWatcher, timeout, 0, &connectState, 0);
        QTest::qSleep(100);
    } while(!connectState && count < ZK_MAX_CONNECT_TIMES);

    int code = 0;
    int childrenCount;
    if (connectState != ZOO_CONNECTED_STATE) {
        qDebug() << "connect ZooKeeper fail";
        QString message;
        emit send_init(connectState, code, message, rootPath, 0);
        return;
    } else {
        getChildren(code, childrenCount, rootPath);
    }
    emit send_init(connectState, code, message, rootPath, childrenCount);
    return;
}

void zookeeperhandle::getChildren(int &code, int &count, QString path)
{
    String_vector children;
    int rc = zoo_get_children(zh, path.toStdString().c_str(), NULL, &children);
    if (rc == ZOK) {
        code = rc;
        count = children.count;
    }
    return;
}

void zookeeperhandle::getSingleChildren(QString path, void * obj_)
{
    qDebug() << "getSingleChildren 对" << path << "监听";
    String_vector children;
    int rc = zoo_wget_children(zh, path.toStdString().c_str(), nodeWatcher, obj_, &children);
    if (rc == ZOK) {
    }
    return;
}

void zookeeperhandle::setNodeData(QString nodePath, QString nodeData)
{
    QString message;
    std::string path = nodePath.toStdString();
    std::string data = nodeData.toStdString();
    int data_len = strlen(data.c_str());
    int ret = zoo_set(zh, path.c_str(), data.c_str(), data_len, -1);
    emit send_setNodeData(ret, message);
    return;
}

void zookeeperhandle::getNodeInfo(QString path)
{
    QString message;
    Stat stat;
    QString data;
    char buffer[1024]  = {0}; //不写0 会乱码
    int buffer_len = sizeof(buffer);
    int rc = zoo_get(zh, path.toStdString().c_str(), 0, buffer, &buffer_len, &stat);
    if (rc == ZOK) {
        data = QString::fromUtf8(buffer);
    } 
    QVariant varValue = QVariant::fromValue(stat);
    emit send_getNodeInfo(rc, message, varValue, data, path);
    return;
}

void zookeeperhandle::createNode(QString nodePath, QString nodeData, QTreeWidgetItem *item)
{
    QString data;
    QString message;
    QVariant varValue;
    int nodeDataLen = strlen(nodeData.toStdString().c_str());
    Stat stat;
    int rc = zoo_create(zh, nodePath.toStdString().c_str(), nodeData.toStdString().c_str(), nodeDataLen, &ZOO_OPEN_ACL_UNSAFE, 0, NULL, 0);
    String_vector children;
    rc = zoo_wget_children(zh, nodePath.toStdString().c_str(), nodeWatcher, obj, &children);
    varValue = QVariant::fromValue(stat);
    emit send_createNode(rc, message, nodePath, varValue, data, item);
    return;
}

void zookeeperhandle::deleteNode(QString path, QTreeWidgetItem *item)
{
    QString message;
    int ret = zoo_delete(zh, path.toStdString().c_str(), -1);
    qDebug() << "删除成功，开始调槽函数" << path;
    emit send_deleteNode(ret, message, item);
    return;
}
