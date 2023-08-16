#ifndef ZOOKEEPERHANDLE_H
#define ZOOKEEPERHANDLE_H

#include <QObject>
//#include <QWidget>
#include "zookeeper.h"
#include <QTreeWidgetItem>
#include "createconnect.h"
Q_DECLARE_METATYPE(String_vector);
Q_DECLARE_METATYPE(Stat);
Q_DECLARE_METATYPE(QTreeWidgetItem*);
Q_DECLARE_METATYPE(QVector<int>);
Q_DECLARE_METATYPE(QVector<QString>);
#define ZK_MAX_CONNECT_TIMES 5 //连接最大尝试次数
static bool g_connected = false;  // 是否连接上zk

class zookeeperhandle : public QObject
{
    Q_OBJECT
public:
    explicit zookeeperhandle(QObject *parent);

    zookeeperhandle();


//    zhandle_t *getZh() const;
//    void setZh(zhandle_t *value);

//    QString getPath() const;
//    void setPath(const QString &value);

//    QTreeWidgetItem *getItem() const;
//    void setItem(QTreeWidgetItem *value);

signals:
    //只是触发
    //void sendAllChildren(QString path, const QVariant varValue, QTreeWidgetItem *item);
    void send_getChildren(QString path, const QVariant varValue, QVector<QString> dataList, QVector<int> childrenList, QTreeWidgetItem *item);
    void send_init(bool connected, QString path, const QVariant varValue, QString data);
    void send_getNodeInfo_2(QVariant varValue, QString data, QString path);

public slots:
    void init(QString rootPath, QString host, QString port);
    //void getAllChildren();
    void getChildren(QString path, QTreeWidgetItem *item);
    void getNodeInfo(Stat &stat, QString &data, QString &path);
    void getNodeInfo_2(QString path);
private:
    QString host;
    QString port;
    zhandle_t *zh;
    //QString path;
    //QTreeWidgetItem *item;
};

#endif // ZOOKEEPERHANDER_H
