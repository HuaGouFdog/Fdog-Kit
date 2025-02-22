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

#ifndef ZOOKEEPERHANDLE_H
#define ZOOKEEPERHANDLE_H

#include <QObject>
#include <QThread>
#include <QDebug>
#include <QRunnable>
#include <QTreeWidgetItem>
#include "zookeeper.h"

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
    QString m_path;
    zhandle_t *m_zh;
    QObject * m_obj;
    QTreeWidgetItem *m_item;

public:
    ZkRunnable(QObject * obj, zhandle_t *zh, QString path, QTreeWidgetItem *item)
        :m_obj(obj),m_zh(zh),m_path(path),m_item(item) {}
    ~ZkRunnable() {
        //不需要释放，由上层管理
    }
    void run() override {
        if (m_zh == nullptr) {
            qDebug("m_zh is null");
            return;
        }
        String_vector children;
        int rc = zoo_wget_children(m_zh, m_path.toStdString().c_str(), nodeWatcher, m_obj, &children);
        QVariant varValue = QVariant::fromValue(children);
        QString message;
        if (rc != ZOK) {
            QMetaObject::invokeMethod(m_obj,"rece_getChildren",Qt::QueuedConnection, Q_ARG(int, rc), Q_ARG(QString, message),
                                        Q_ARG(QString, m_path), Q_ARG(QVariant, varValue), Q_ARG(QTreeWidgetItem*, m_item));
            return;
        }
        QMetaObject::invokeMethod(m_obj,"rece_getChildren",Qt::QueuedConnection, Q_ARG(int, rc), Q_ARG(QString, message),
                                    Q_ARG(QString, m_path), Q_ARG(QVariant, varValue), Q_ARG(QTreeWidgetItem*, m_item));
        return;
    }
};

class zookeeperhandle : public QObject
{
    Q_OBJECT

public:
    QString host;
    QString port;
    int connectState;  // 是否连接上zk
    zhandle_t *zh;
    QObject * obj;

public:
    explicit zookeeperhandle(QObject *parent);
    explicit zookeeperhandle(QObject * obj_ = nullptr, zhandle_t *zh_ = nullptr);
    ~zookeeperhandle();

signals:
    void send_init(int connectState,int code, QString message, QString path, int count);
    void send_getChildren(int code, QString message, QString path, const QVariant varValue, QTreeWidgetItem *item);
    void send_setNodeData(int code, QString message);
    void send_getNodeInfo(int code, QString message, QVariant varValue, QString data, QString path);
    void send_createNode(int code, QString message, QString path, QVariant varValue, QString data, QTreeWidgetItem *item);
    void send_deleteNode(int code, QString message, QTreeWidgetItem *item);

public slots:
    void init(QString rootPath, QString host, QString port, int timeout);
    //获取大量节点耗时严重，获取根节点调用该接口，其他节点使用线程池获取
    void getChildren(int &code, int &count, QString path);
    void getSingleChildren(QString path, void * obj_);
    void setNodeData(QString nodePath, QString nodeData);
    void getNodeInfo(QString path);
    void createNode(QString nodePath, QString nodeData, QTreeWidgetItem *item);
    void deleteNode(QString path, QTreeWidgetItem *item);
};

#endif // ZOOKEEPERHANDLE_H
