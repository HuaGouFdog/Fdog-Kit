#ifndef ZOOKEEPERSQL_H
#define ZOOKEEPERSQL_H
#include <QVector>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include "module_utils/utils.h"

class zookeepersql
{
public:
    zookeepersql();
    ~zookeepersql();
    void zookeeper_init();

    QVector<zkInfoStruct> zk_getAllZkInfo();
    void zk_insertZkInfo(zkInfoStruct zkInfo);
    void zk_updateZkInfo(zkInfoStruct zkInfo);
    void zk_deleteZkInfo(zkInfoStruct zkInfo);

    QSqlDatabase database_zk;
};

#endif // ZOOKEEPERSQL_H
