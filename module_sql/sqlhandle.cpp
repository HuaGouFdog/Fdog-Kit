#pragma execution_character_set("utf-8")
#include "sqlhandle.h"

#include <QDebug>

sqlhandle::sqlhandle()
{
    zookeeper_init();
    ssh_init();
    ssh_key_init();
}

sqlhandle::~sqlhandle()
{
    database_ssh.close();
    database_zk.close();
}

void sqlhandle::ssh_init()
{
    if (QSqlDatabase::contains("qt_sql_default_connection_ssh")) {
        database_ssh = QSqlDatabase::database("qt_sql_default_connection_ssh");
        qDebug() << "走1";
    } else {
        // 建立和SQlite数据库的连接
        database_ssh = QSqlDatabase::addDatabase("QSQLITE");
        // 设置数据库文件的名字
        database_ssh.setDatabaseName("DB_SSHINFO.db");
        qDebug() << "走2";
    }

    if (!database_ssh.open()) {
        qDebug() << "DB_SSHINFO.db Error: Failed to connect database." << database_ssh.lastError();
    } else {
        qDebug() << "DB_SSHINFO.db 数据库已经打开";
        // do something
    }

    // 用于执行sql语句的对象
    QSqlQuery sqlQuery;
    // 构建创建数据库的sql语句字符串
    QString createSql = QString("CREATE TABLE TB_SSHINFO (name TEXT NOT NULL, ip TEXT NOT NULL, user_name TEXT NOT NULL, password TEXT NOT NULL,\
                            ssh_group TEXT NOT NULL, remark TEXT NOT NULL, nearest_connection TEXT NOT NULL)");

    sqlQuery.prepare(createSql);
    // 执行sql语句
    if(!sqlQuery.exec())
    {
        qDebug() << "DB_SSHINFO.db Error: Fail to create table. " << sqlQuery.lastError();
    } else {
        qDebug() << "DB_SSHINFO.db Table created!";
    }
}

void sqlhandle::ssh_key_init()
{
    //创建密钥表
    if (QSqlDatabase::contains("qt_sql_default_connection_ssh")) {
        database_ssh = QSqlDatabase::database("qt_sql_default_connection_ssh");
        qDebug() << "走1";
    } else {
        // 建立和SQlite数据库的连接
        database_ssh = QSqlDatabase::addDatabase("QSQLITE");
        // 设置数据库文件的名字
        database_ssh.setDatabaseName("DB_SSHINFO.db");
        qDebug() << "走2";
    }

    if (!database_ssh.open()) {
        qDebug() << "DB_SSHINFO.db Error: Failed to connect database." << database_ssh.lastError();
    } else {
        qDebug() << "DB_SSHINFO.db 数据库已经打开";
        // do something
    }

    // 用于执行sql语句的对象
    QSqlQuery sqlQuery;
    // 构建创建数据库的sql语句字符串
    QString createSql = QString("CREATE TABLE TB_SSHKEYINFO (name TEXT NOT NULL, path TEXT NOT NULL, password TEXT NOT NULL)");

    sqlQuery.prepare(createSql);
    // 执行sql语句
    if(!sqlQuery.exec())
    {
        qDebug() << "DB_SSHINFO.db Error: Fail to create table. " << sqlQuery.lastError();
    } else {
        qDebug() << "DB_SSHINFO.db Table created!";
    }
}

void sqlhandle::zookeeper_init()
{
    if (QSqlDatabase::contains("qt_sql_default_connection_zk")) {
        database_zk = QSqlDatabase::database("qt_sql_default_connection_zk");
        qDebug() << "走3";
    } else {
        // 建立和SQlite数据库的连接
        database_zk = QSqlDatabase::addDatabase("QSQLITE");
        // 设置数据库文件的名字
        database_zk.setDatabaseName("DB_ZKINFO.db");
        qDebug() << "走4";
    }

    if (!database_zk.open()) {
        qDebug() << "Error: Failed to connect database." << database_zk.lastError();
    } else {
        qDebug() << "DB_ZKINFO.db数据库已经打开";
        // do something
    }

    // 用于执行sql语句的对象
    QSqlQuery sqlQuery;
    // 构建创建数据库的sql语句字符串
    QString createSql = QString("CREATE TABLE TB_ZKINFO (name TEXT NOT NULL, host TEXT NOT NULL, port TEXT NOT NULL)");

    sqlQuery.prepare(createSql);
    // 执行sql语句
    if(!sqlQuery.exec())
    {
        qDebug() << "DB_ZKINFO.db Error: Fail to create table. " << sqlQuery.lastError();
    } else {
        qDebug() << "DB_ZKINFO.db Table created!";
    }
}

QVector<zkInfoStruct> sqlhandle::zk_getAllZkInfo()
{
    QVector<zkInfoStruct> zkInfoStructList;
    QSqlQuery sqlQuery;
    sqlQuery.exec("SELECT * FROM TB_ZKINFO");
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

void sqlhandle::zk_insertZkInfo(zkInfoStruct zkInfo)
{
    QSqlQuery sqlQuery;
    sqlQuery.prepare("INSERT INTO TB_ZKINFO VALUES(?, ?, ?)");
    sqlQuery.addBindValue(zkInfo.name);
    sqlQuery.addBindValue(zkInfo.host);
    sqlQuery.addBindValue(zkInfo.port);
    if(!sqlQuery.exec()) {
        qDebug() << "Error: Fail to insert data. " << sqlQuery.lastError();
    } else {
        // do something
    }
}

void sqlhandle::zk_updateZkInfo(zkInfoStruct zkInfo)
{

}

void sqlhandle::zk_deleteZkInfo(zkInfoStruct zkInfo)
{
    QSqlQuery sqlQuery;
    sqlQuery.prepare("DELETE TB_ZKINFO WHERE host=?");
    sqlQuery.addBindValue(zkInfo.host);
    if(!sqlQuery.exec()) {
        qDebug() << "Error: Fail to DELETE table." << sqlQuery.lastError();
    } else {
        qDebug() << "updated data success!";
    }
}

QVector<connnectInfoStruct> sqlhandle::ssh_getAllSSHInfo()
{
    QVector<connnectInfoStruct> cInfoStructList;
    QSqlQuery sqlQuery;
    sqlQuery.exec("SELECT * FROM TB_SSHINFO");
    if(!sqlQuery.exec()) {
        qDebug() << "Error: Fail to query table. " << sqlQuery.lastError();
    } else {
        while(sqlQuery.next())
        {
            connnectInfoStruct cInfoStruct;
            cInfoStruct.name = sqlQuery.value(0).toString();
            cInfoStruct.host = sqlQuery.value(1).toString();
            cInfoStruct.userName = sqlQuery.value(2).toString();
            cInfoStruct.password = sqlQuery.value(3).toString();
            cInfoStruct.group= sqlQuery.value(4).toString();
            cInfoStruct.remark= sqlQuery.value(5).toString();
            cInfoStruct.nearest_connection= sqlQuery.value(6).toString();
            cInfoStructList.push_back(cInfoStruct);
        }
    }
    return cInfoStructList;
}

connnectInfoStruct sqlhandle::ssh_getSSHInfoByHost(QString host) {
    qDebug() << "ssh_getSSHInfoByHost host = " << host;
    connnectInfoStruct cInfoStruct;
    QSqlQuery sqlQuery;
    sqlQuery.prepare("SELECT * FROM TB_SSHINFO where ip = ?");
    sqlQuery.addBindValue(host);
    sqlQuery.exec();
    if(!sqlQuery.exec()) {
        qDebug() << "Error: Fail to query table. " << sqlQuery.lastError();
    } else {
        while(sqlQuery.next())
        {
            cInfoStruct.name = sqlQuery.value(0).toString();
            cInfoStruct.host = sqlQuery.value(1).toString();
            cInfoStruct.userName = sqlQuery.value(2).toString();
            cInfoStruct.password = sqlQuery.value(3).toString();
            cInfoStruct.group= sqlQuery.value(4).toString();
            cInfoStruct.remark= sqlQuery.value(5).toString();
            cInfoStruct.nearest_connection= sqlQuery.value(6).toString();
            qDebug() << "ssh_getSSHInfoByHost host = " << cInfoStruct.host << " password = " << cInfoStruct.password;
        }
    }
    return cInfoStruct;
}

void sqlhandle::ssh_insertSSHInfo(connnectInfoStruct cInfoStruct)
{
    QSqlQuery sqlQuery;
    sqlQuery.prepare("INSERT INTO TB_SSHINFO VALUES(?, ?, ?, ?, ?, ?, ?)");
    sqlQuery.addBindValue(cInfoStruct.name);
    sqlQuery.addBindValue(cInfoStruct.host);
    sqlQuery.addBindValue(cInfoStruct.userName);
    sqlQuery.addBindValue(cInfoStruct.password);
    sqlQuery.addBindValue(cInfoStruct.group);
    sqlQuery.addBindValue(cInfoStruct.remark);
    sqlQuery.addBindValue(cInfoStruct.nearest_connection);
    if(!sqlQuery.exec()) {
        qDebug() << "Error: Fail to insert data. " << sqlQuery.lastError();
    } else {
        // do something
    }
}

void sqlhandle::ssh_updateSSHInfo(connnectInfoStruct cInfoStruct)
{
    QSqlQuery sqlQuery;
    sqlQuery.prepare("UPDATE TB_SSHINFO SET name=?, ip=?, user_name=?, password=?, ssh_group=?, remark=?, nearest_connection=? WHERE ip=?");
    sqlQuery.addBindValue(cInfoStruct.name);
    sqlQuery.addBindValue(cInfoStruct.host);
    sqlQuery.addBindValue(cInfoStruct.userName);
    sqlQuery.addBindValue(cInfoStruct.password);
    sqlQuery.addBindValue(cInfoStruct.group);
    sqlQuery.addBindValue(cInfoStruct.remark);
    sqlQuery.addBindValue(cInfoStruct.nearest_connection);
    sqlQuery.addBindValue(cInfoStruct.host);
    if(!sqlQuery.exec()) {
        qDebug() << "Error: Fail to UPDATE table." << sqlQuery.lastError();
    } else {
        qDebug() << "updated data success!";
    }
}

void sqlhandle::ssh_deleteSSHInfo(connnectInfoStruct cInfoStruct)
{
    QSqlQuery sqlQuery;
    sqlQuery.prepare("DELETE TB_SSHINFO WHERE ip=?");
    sqlQuery.addBindValue(cInfoStruct.host);
    if(!sqlQuery.exec()) {
        qDebug() << "Error: Fail to DELETE table." << sqlQuery.lastError();
    } else {
        qDebug() << "updated data success!";
    }
}

QVector<sshKeyStruct> sqlhandle::sshKey_getAllSSHKeyInfo()
{
    QVector<sshKeyStruct> sKeyStructList;
    QSqlQuery sqlQuery;
    sqlQuery.exec("SELECT * FROM TB_SSHKEYINFO");
    if(!sqlQuery.exec()) {
        qDebug() << "Error: Fail to query table. " << sqlQuery.lastError();
    } else {
        while(sqlQuery.next())
        {
            sshKeyStruct skeyInfo;
            skeyInfo.name = sqlQuery.value(0).toString();
            skeyInfo.path = sqlQuery.value(1).toString();
            skeyInfo.password = sqlQuery.value(2).toString();
            sKeyStructList.push_back(skeyInfo);
        }
    }
    return sKeyStructList;
}

void sqlhandle::sshKey_insertsshKeyInfo(sshKeyStruct skeyStruct)
{
    QSqlQuery sqlQuery;
    sqlQuery.prepare("INSERT INTO TB_SSHKEYINFO VALUES(?, ?, ?)");
    sqlQuery.addBindValue(skeyStruct.name);
    sqlQuery.addBindValue(skeyStruct.path);
    sqlQuery.addBindValue(skeyStruct.password);
    if(!sqlQuery.exec()) {
        qDebug() << "Error: Fail to insert data. " << sqlQuery.lastError();
    } else {
        // do something
    }
}

void sqlhandle::sshKey_updatesshKeyInfo(sshKeyStruct skeyStruct)
{

}

void sqlhandle::sshKey_deletesshKeyInfo(sshKeyStruct skeyStruct)
{

}
