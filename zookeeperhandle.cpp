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

zookeeperhandle::zookeeperhandle()
{
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

void zookeeperhandle::getChildren(QString path, QTreeWidgetItem *item)
{
    String_vector children;
    int rc = zoo_get_children(zh, path.toStdString().c_str(), 0, &children);
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
        qDebug() << "getChildren children_path = " << children_path;
        //QString path = children.data[i];
        Stat stat;
        QString data;
        getNodeInfo(stat, data, children_path);
        childrenList.push_back(stat.numChildren);
        dataList.push_back(data);
    }

    QVariant varValue = QVariant::fromValue(children);
    emit send_getChildren(path, varValue, dataList, childrenList, item);
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

void zookeeperhandle::getNodeInfo(Stat &stat, QString &data, QString &path)
{
    // 获取节点的信息
    char buffer[1024]  = {0}; //不写0 会乱码
    int buffer_len = sizeof(buffer);
    int rc = zoo_get(zh, path.toStdString().c_str(), 0, buffer, &buffer_len, &stat);
    if (rc == ZOK) {
        data = QString::fromUtf8(buffer);
        qDebug() << "str = " << data;
    } else if (rc == ZNONODE) {
        qDebug() << "Node does not exist";
    }
    return;
}

void zookeeperhandle::getNodeInfo_2(QString path)
{
    qDebug() << "返回数据1";
    Stat stat;
    QString data;
    getNodeInfo(stat, data, path);
    QVariant varValue = QVariant::fromValue(stat);
    qDebug() << "返回数据2";
    emit send_getNodeInfo_2(varValue, data, path);
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
    }
}

void zookeeperhandle::init(QString rootPath, QString host_, QString port_)
{
    qDebug() << "connect ZooKeeper 1";
    int count = 0;
    //ZooKeeper服务器的地址和端口
    std::string host = host_.toStdString() + ":" + port_.toStdString();
    //连接超时时间（毫秒）
    int timeout = 3000;
    do {
        count++;
        // 创建ZooKeeper句柄
        zh = zookeeper_init(host.c_str(), watcher, timeout, nullptr, nullptr, 0);
        QTest::qSleep(100);
    } while(!g_connected && count < ZK_MAX_CONNECT_TIMES);

    //QString rootPath = "/";
    if (!g_connected) {
        qDebug() << "connect ZooKeeper fail";
        //退出
        Stat stat;
        QString Data;
        QVariant varValue = QVariant::fromValue(stat);
        emit send_init(g_connected, rootPath, varValue, Data);
        return;
    }

    Stat stat;
    QString Data;
    getNodeInfo(stat, Data, rootPath);

    //返回给主界面
    qDebug() << "connect ZooKeeper 2";
    QVariant varValue = QVariant::fromValue(stat);
    emit send_init(g_connected, rootPath, varValue, Data);
    return;
}

