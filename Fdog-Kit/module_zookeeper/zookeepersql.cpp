#include "zookeepersql.h"

zookeepersql::zookeepersql()
{
    zookeeper_init();
}

zookeepersql::~zookeepersql()
{
    database_zk.close();
}

void zookeepersql::zookeeper_init()
{
    if (QSqlDatabase::contains("zk_info_sqlLite")) {
        database_zk = QSqlDatabase::database("zk_info_sqlLite");
        qDebug() << "zk_info_sqlLite已经存在";
    } else {
        // 建立和SQlite数据库的连接
        database_zk = QSqlDatabase::addDatabase("QSQLITE", "zk_info_sqlLite");
    }
    // 设置数据库文件的名字
    database_zk.setDatabaseName("DB_ZK_INFO.db");

    if (!database_zk.open()) {
        qDebug() << "DB_ZK_INFO.db打开失败" << database_zk.lastError();
    }

    // 用于执行sql语句的对象
    QSqlQuery sqlQuery(database_zk);
    // 构建创建数据库的sql语句字符串
    QString createSql = QString("CREATE TABLE TB_ZK_INFO (name TEXT NOT NULL, host TEXT NOT NULL, port TEXT NOT NULL)");

    sqlQuery.prepare(createSql);
    // 执行sql语句
    if(!sqlQuery.exec())
    {
        qDebug() << "DB_ZKINFO.db Error: Fail to create table. " << sqlQuery.lastError();
    } else {
        qDebug() << "DB_ZKINFO.db Table created!";
    }
}

QVector<zkInfoStruct> zookeepersql::zk_getAllZkInfo()
{
    QVector<zkInfoStruct> zkInfoStructList;
    QSqlQuery sqlQuery(database_zk);
    sqlQuery.exec("SELECT * FROM TB_ZK_INFO");
    if(!sqlQuery.exec()) {
        qDebug() << "Error: Fail to query table. " << sqlQuery.lastError();
    } else {
        while(sqlQuery.next())
        {
            zkInfoStruct zkInfo;
            zkInfo.name = sqlQuery.value(0).toString();
            zkInfo.host = sqlQuery.value(1).toString();
            zkInfo.port = sqlQuery.value(2).toString();
            zkInfoStructList.push_back(zkInfo);
        }
    }
    return zkInfoStructList;
}

void zookeepersql::zk_insertZkInfo(zkInfoStruct zkInfo)
{
    QSqlQuery sqlQuery(database_zk);
    sqlQuery.prepare("INSERT INTO TB_ZK_INFO VALUES(?, ?, ?)");
    sqlQuery.addBindValue(zkInfo.name);
    sqlQuery.addBindValue(zkInfo.host);
    sqlQuery.addBindValue(zkInfo.port);
    if(!sqlQuery.exec()) {
        qDebug() << "Error: Fail to insert data. " << sqlQuery.lastError();
    } else {
        // do something
    }
}

void zookeepersql::zk_updateZkInfo(zkInfoStruct zkInfo)
{

}

void zookeepersql::zk_deleteZkInfo(zkInfoStruct zkInfo)
{
    QSqlQuery sqlQuery(database_zk);
    sqlQuery.prepare("DELETE FROM TB_ZK_INFO WHERE host=?");
    sqlQuery.addBindValue(zkInfo.host);
    if(!sqlQuery.exec()) {
        qDebug() << "Error: Fail to DELETE table." << sqlQuery.lastError();
    } else {
        qDebug() << "updated data success!";
    }
}
