/*
   Copyright 2023 花狗Fdog(张旭)
   
   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#pragma execution_character_set("utf-8")
#include "zookeeperhandle.h"
#include <QTest>
#include <QMetaType>
#include <QJsonParseError>

void initWatcher(zhandle_t *zh, int type, int state, const char *path, void *watcherCtx) {
    qDebug() << "initWatcher ... type = " << type;
    if (type ==ZOO_SESSION_EVENT) {
        if (state == ZOO_CONNECTED_STATE) {
            int * connectState = (int *)watcherCtx;
            *connectState = ZOO_CONNECTED_STATE;
            qDebug() << "connectState success";
        } else if (state == ZOO_AUTH_FAILED_STATE) {
            qDebug() << "connectState ZOO_AUTH_FAILED_STATE";
        } else if (state == ZOO_EXPIRED_SESSION_STATE) {
            qDebug() << "connectState ZOO_EXPIRED_SESSION_STATE";
        } else if (state == ZOO_CONNECTING_STATE) {
            qDebug() << "connectState ZOO_CONNECTING_STATE";
        } else if (state == ZOO_ASSOCIATING_STATE) {
            qDebug() << "connectState ZOO_ASSOCIATING_STATE";
        }
    } else {
        qDebug() << "其他事件" << path;
    }
}

void nodeWatcher(zhandle_t *zh, int type, int state, const char *path, void *watcherCtx) {
    QObject * obj_ = (QObject*)watcherCtx;
    QString path_str(path);
    QString message;
    if (type == ZOO_CHILD_EVENT) {
        qDebug() << "子节点发生变化" << path;
        //再次监听
        String_vector children;
        int rc = zoo_wget_children(zh, path, nodeWatcher, obj_, &children);
        QVariant varValue = QVariant::fromValue(children);
        QString message;
        if (rc != ZOK) {
            //处理两个工具分别添加子节点后，递归删除异常问题
            QMetaObject::invokeMethod(obj_,"rece_delete_event",Qt::QueuedConnection, Q_ARG(int, 0), Q_ARG(QString,message), Q_ARG(QString,path_str));
            return;
        }
        QMetaObject::invokeMethod(obj_,"rece_children_event",Qt::QueuedConnection, Q_ARG(int, rc), Q_ARG(QString,message),
                                        Q_ARG(QString,path_str), Q_ARG(QVariant, varValue));

    } else if (type == ZOO_CHANGED_EVENT) {
        qDebug() << "节点数据发生变化" << path;
        Stat stat;
        char buffer[1024*6]  = {0}; //不写0 会乱码
        int buffer_len = sizeof(buffer);
        int rc = zoo_wget(zh, path, nodeWatcher, obj_, buffer, &buffer_len, &stat);
        if (rc == ZOK) {
            qDebug() << "zoo_wget error rc = " << rc;
        } 
        QString message;
        QMetaObject::invokeMethod(obj_,"rece_chanage_event",Qt::QueuedConnection, Q_ARG(int,rc), Q_ARG(QString,message), Q_ARG(QString,path_str));
    } else if (type == ZOO_DELETED_EVENT) {
        qDebug() << "节点被删除" << path;
        QMetaObject::invokeMethod(obj_,"rece_delete_event",Qt::QueuedConnection, Q_ARG(int,0), Q_ARG(QString,message), Q_ARG(QString,path_str));
    } else if (type == ZOO_CREATED_EVENT) {
        qDebug() << "节点被创建" << path;
    } else {
        qDebug() << "其他事件" << path;
    }
}

zookeeperhandle::zookeeperhandle(QObject *parent) : QObject(parent) {
    qRegisterMetaType<QVector<int>>("QVector<int>&");
    qRegisterMetaType<QVector<QString>>("QVector<QString>&");
}

zookeeperhandle::zookeeperhandle(QObject * obj_, zhandle_t *zh_) :zh(zh_), obj(obj_) {
    qRegisterMetaType<QVector<int>>("QVector<int>&");
    qRegisterMetaType<QVector<QString>>("QVector<QString>&");
}

zookeeperhandle::~zookeeperhandle() {
    if (this->zh != nullptr)
    {
        qDebug() << "释放连接";
        zookeeper_close(this->zh); // 关闭句柄
        this->zh = nullptr
    }
}

void zookeeperhandle::init(QString rootPath, QString host_, QString port_, int timeout) {
    QString message;
    std::string host = host_.toStdString() + ":" + port_.toStdString();
    zoo_set_debug_level(ZOO_LOG_LEVEL_ERROR);
    connectState = -1;
    if (timeout == 0) {
        timeout = 5000;
    }
    zh = zookeeper_init(host.c_str(), initWatcher, timeout, 0, &connectState, 0);
    QElapsedTimer timer;
    timer.start();
    while(1) {
        QTest::qSleep(100);
        qint64 elapsedMilliseconds = timer.elapsed();
        if (elapsedMilliseconds > timeout) {
            break;
        } else if (connectState == ZOO_CONNECTED_STATE) {
            break;
        }
    }
    
    int code = 0;
    int childrenCount;
    if (connectState != ZOO_CONNECTED_STATE) {
        zookeeper_close(zh);
        zh = nullptr;
        qDebug() << "connect ZooKeeper fail";
        QString message;
        code = -1;
        emit send_init(connectState, code, message, rootPath, 0);
        return;
    }
    getChildren(code, childrenCount, rootPath);
    emit send_init(connectState, code, message, rootPath, childrenCount);
    return;
}

void zookeeperhandle::getChildren(int &code, int &count, QString path) {
    String_vector children;
    int rc = zoo_get_children(zh, path.toStdString().c_str(), nullptr, &children);
    if (rc == ZOK) {
        code = rc;
        count = children.count;
    }
    return;
}

void zookeeperhandle::getSingleChildren(QString path, void * obj_) {
    String_vector children;
    int rc = zoo_wget_children(zh, path.toStdString().c_str(), nodeWatcher, obj_, &children);
    if (rc == ZOK) {
    }
    return;
}

void zookeeperhandle::setNodeData(QString nodePath, QString nodeData) {
    QString message;
    std::string path = nodePath.toStdString();
    std::string data = nodeData.toStdString();
    int data_len = strlen(data.c_str());
    int ret = zoo_set(zh, path.c_str(), data.c_str(), data_len, -1);
    emit send_setNodeData(ret, message);
    return;
}

void zookeeperhandle::getNodeInfo(QString path) {
    QString message;
    Stat stat;
    QString data;
    //不初始化会乱码
    char buffer[4096*10]  = {0};
    int buffer_len = sizeof(buffer);
    int rc = zoo_wget(zh, path.toStdString().c_str(), nodeWatcher, obj, buffer, &buffer_len, &stat);
    if (rc == ZOK) {
        data = QString::fromUtf8(buffer);
    } 
    QVariant varValue = QVariant::fromValue(stat);
    emit send_getNodeInfo(rc, message, varValue, data, path);
    return;
}

void zookeeperhandle::createNode(QString nodePath, QString nodeData, QTreeWidgetItem *item) {
    QString data;
    QString message;
    QVariant varValue;
    int nodeDataLen = strlen(nodeData.toStdString().c_str());
    Stat stat;
    int rc = zoo_create(zh, nodePath.toStdString().c_str(), nodeData.toStdString().c_str(), nodeDataLen, &ZOO_OPEN_ACL_UNSAFE, 0, nullptr, 0);
    String_vector children;
    rc = zoo_wget_children(zh, nodePath.toStdString().c_str(), nodeWatcher, obj, &children);
    varValue = QVariant::fromValue(stat);
    emit send_createNode(rc, message, nodePath, varValue, data, item);
    return;
}

void zookeeperhandle::deleteNode(QString path, QTreeWidgetItem *item) {
    QString message;
    int ret = zoo_delete(zh, path.toStdString().c_str(), -1);
    emit send_deleteNode(ret, message, item);
    return;
}
