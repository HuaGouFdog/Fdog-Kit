#pragma execution_character_set("utf-8")
#include "sshsql.h"
#include <QDebug>
sshsql::sshsql()
{
    ssh_init();
}

sshsql::~sshsql()
{
   database_ssh.close();
}

void sshsql::ssh_init()
{
     if (QSqlDatabase::contains("ssh_info_sqlLite")) {
         database_ssh = QSqlDatabase::database("ssh_info_sqlLite");
         qDebug() << "ssh_info_sqlLite已经存在";
     } else {
        // 建立和SQlite数据库的连接
        database_ssh = QSqlDatabase::addDatabase("QSQLITE", "ssh_info_sqlLite");
        // 设置数据库文件的名字
        qDebug() << "ssh_info_sqlLite不存在，创建库DB_SSH_INFO.db";
    }
    database_ssh.setDatabaseName("DB_SSH_INFO.db");

    if (!database_ssh.open()) {
        qDebug() << "DB_SSH_INFO.db打开失败 " << database_ssh.lastError();
    } else {
        //qDebug() << "DB_SSH_INFO.db 数据库已经打开";
        // do something
    }

    // 用于执行sql语句的对象
    QSqlQuery sqlQuery(database_ssh);
    // 构建创建数据库的sql语句字符串
    QString createSql = QString("CREATE TABLE TB_SSH_INFO (name TEXT NOT NULL, ip TEXT NOT NULL,  port TEXT NOT NULL, connectType TEXT NOT NULL, userName TEXT NOT NULL, password TEXT NOT NULL,\
                            sshGroup TEXT NOT NULL, remark TEXT NOT NULL, nearestConnection TEXT NOT NULL)");

    sqlQuery.prepare(createSql);
    // 执行sql语句
    if(!sqlQuery.exec())
    {
        qDebug() << "DB_SSH_INFO.db Error: Fail to create table. " << sqlQuery.lastError();
    } else {
        qDebug() << "DB_SSH_INFO.db Table created!";
    }

    // 用于执行sql语句的对象
    QSqlQuery sqlQuery2(database_ssh);
    // 构建创建数据库的sql语句字符串
    QString createSql2 = QString("CREATE TABLE TB_SSH_KEY_INFO (name TEXT NOT NULL, path TEXT NOT NULL, password TEXT NOT NULL)");

    sqlQuery2.prepare(createSql2);
    // 执行sql语句
    if(!sqlQuery2.exec())
    {
        qDebug() << "DB_SSH_KEY_INFO.db Error: Fail to create table. " << sqlQuery2.lastError();
    } else {
        qDebug() << "DB_SSH_KEY_INFO.db Table created!";
    }
}

QVector<connnectInfoStruct> sshsql::ssh_getAllSSHInfo()
{
    QVector<connnectInfoStruct> cInfoStructList;
    QSqlQuery sqlQuery(database_ssh);
    sqlQuery.exec("SELECT * FROM TB_SSH_INFO");
    if(!sqlQuery.exec()) {
        qDebug() << "Error: Fail to query table. " << sqlQuery.lastError();
    } else {
        while(sqlQuery.next())
        {
            connnectInfoStruct cInfoStruct;
            cInfoStruct.name = sqlQuery.value(0).toString();
            cInfoStruct.host = sqlQuery.value(1).toString();
            cInfoStruct.port = sqlQuery.value(2).toString();
            cInfoStruct.sshType = sqlQuery.value(3).toString();
            cInfoStruct.userName = sqlQuery.value(4).toString();
            cInfoStruct.password = sqlQuery.value(5).toString();
            cInfoStruct.group= sqlQuery.value(6).toString();
            cInfoStruct.remark= sqlQuery.value(7).toString();
            cInfoStruct.nearest_connection= sqlQuery.value(8).toString();
            cInfoStructList.push_back(cInfoStruct);
        }
    }
    return cInfoStructList;
}

connnectInfoStruct sshsql::ssh_getSSHInfoByHost(QString host) {
    qDebug() << "ssh_getSSHInfoByHost host = " << host;
    connnectInfoStruct cInfoStruct;
    QSqlQuery sqlQuery(database_ssh);
    sqlQuery.prepare("SELECT * FROM TB_SSH_INFO where ip = ?");
    sqlQuery.addBindValue(host);
    sqlQuery.exec();
    if(!sqlQuery.exec()) {
        qDebug() << "Error: Fail to query table. " << sqlQuery.lastError();
    } else {
        while(sqlQuery.next())
        {
            cInfoStruct.name = sqlQuery.value(0).toString();
            cInfoStruct.host = sqlQuery.value(1).toString();
            cInfoStruct.port = sqlQuery.value(2).toString();
            cInfoStruct.sshType = sqlQuery.value(3).toString();
            cInfoStruct.userName = sqlQuery.value(4).toString();
            cInfoStruct.password = sqlQuery.value(5).toString();
            cInfoStruct.group= sqlQuery.value(6).toString();
            cInfoStruct.remark= sqlQuery.value(7).toString();
            cInfoStruct.nearest_connection= sqlQuery.value(8).toString();
            qDebug() << "ssh_getSSHInfoByHost host = " << cInfoStruct.host << " password = " << cInfoStruct.password;
        }
    }
    return cInfoStruct;
}

connnectInfoStruct sshsql::ssh_getSSHInfoByName(QString name) {
    qDebug() << "ssh_getSSHInfoByHost name = " << name;
    connnectInfoStruct cInfoStruct;
    QSqlQuery sqlQuery(database_ssh);
    sqlQuery.prepare("SELECT * FROM TB_SSH_INFO where name = ?");
    sqlQuery.addBindValue(name);
    sqlQuery.exec();
    if(!sqlQuery.exec()) {
        qDebug() << "Error: Fail to query table. " << sqlQuery.lastError();
    } else {
        while(sqlQuery.next())
        {
            cInfoStruct.name = sqlQuery.value(0).toString();
            cInfoStruct.host = sqlQuery.value(1).toString();
            cInfoStruct.port = sqlQuery.value(2).toString();
            cInfoStruct.sshType = sqlQuery.value(3).toString();
            cInfoStruct.userName = sqlQuery.value(4).toString();
            cInfoStruct.password = sqlQuery.value(5).toString();
            cInfoStruct.group= sqlQuery.value(6).toString();
            cInfoStruct.remark= sqlQuery.value(7).toString();
            cInfoStruct.nearest_connection= sqlQuery.value(8).toString();
            qDebug() << "ssh_getSSHInfoByHost host = " << cInfoStruct.host << " password = " << cInfoStruct.password;
        }
    }
    return cInfoStruct;
}

void sshsql::ssh_insertSSHInfo(connnectInfoStruct cInfoStruct)
{
    QSqlQuery sqlQuery(database_ssh);
    sqlQuery.prepare("INSERT INTO TB_SSH_INFO VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?)");
    sqlQuery.addBindValue(cInfoStruct.name);
    sqlQuery.addBindValue(cInfoStruct.host);
    sqlQuery.addBindValue(cInfoStruct.port);
    sqlQuery.addBindValue(cInfoStruct.sshType);
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

void sshsql::ssh_updateSSHInfo(connnectInfoStruct cInfoStruct)
{
    QSqlQuery sqlQuery(database_ssh);
    sqlQuery.prepare("UPDATE TB_SSH_INFO SET name=?, ip=?, port=?, connectType=?, userName=?, password=?, sshGroup=?, remark=?, nearestConnection=? WHERE ip=?");
    sqlQuery.addBindValue(cInfoStruct.name);
    sqlQuery.addBindValue(cInfoStruct.host);
    sqlQuery.addBindValue(cInfoStruct.port);
    sqlQuery.addBindValue(cInfoStruct.connectType);
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

void sshsql::ssh_deleteSSHInfo(connnectInfoStruct cInfoStruct)
{
    QSqlQuery sqlQuery(database_ssh);
    sqlQuery.prepare("DELETE FROM TB_SSH_INFO WHERE ip=?");
    sqlQuery.addBindValue(cInfoStruct.host);
    if(!sqlQuery.exec()) {
        qDebug() << "Error: Fail to DELETE table." << sqlQuery.lastError();
    } else {
        qDebug() << "updated data success!";
    }
}

QVector<sshKeyStruct> sshsql::sshKey_getAllSSHKeyInfo()
{
    QVector<sshKeyStruct> sKeyStructList;
    QSqlQuery sqlQuery(database_ssh);
    sqlQuery.exec("SELECT * FROM TB_SSH_KEY_INFO");
    if(!sqlQuery.exec()) {
        qDebug() << "Error: Fail to query table. " << sqlQuery.lastError();
    } else {
        while(sqlQuery.next()) {
            sshKeyStruct skeyInfo;
            skeyInfo.name = sqlQuery.value(0).toString();
            skeyInfo.path = sqlQuery.value(1).toString();
            skeyInfo.password = sqlQuery.value(2).toString();
            sKeyStructList.push_back(skeyInfo);
        }
    }
    qDebug() << "成功";
    return sKeyStructList;
}

sshKeyStruct sshsql::sshKey_getSSHKeyInfoByName(QString text)
{
    qDebug() << "name = " << text;
    sshKeyStruct skeyInfo;
    QSqlQuery sqlQuery(database_ssh);
    QString selectSql = "SELECT * FROM TB_SSH_KEY_INFO WHERE name = \"" + text + "\"";
    sqlQuery.exec(selectSql);
    if(!sqlQuery.exec()) {
        qDebug() << "Error: Fail to query table. " << sqlQuery.lastError();
    } else {
        while(sqlQuery.next()) {
            skeyInfo.name = sqlQuery.value(0).toString();
            skeyInfo.path = sqlQuery.value(1).toString();
            skeyInfo.password = sqlQuery.value(2).toString();
        }
    }
    return skeyInfo;
}

void sshsql::sshKey_insertsshKeyInfo(sshKeyStruct skeyStruct)
{
    QSqlQuery sqlQuery(database_ssh);
    sqlQuery.prepare("INSERT INTO TB_SSH_KEY_INFO VALUES(?, ?, ?)");
    sqlQuery.addBindValue(skeyStruct.name);
    sqlQuery.addBindValue(skeyStruct.path);
    sqlQuery.addBindValue(skeyStruct.password);
    if(!sqlQuery.exec()) {
        qDebug() << "Error: Fail to insert data. " << sqlQuery.lastError();
    } else {
        // do something
    }
}

void sshsql::sshKey_updatesshKeyInfo(sshKeyStruct skeyStruct)
{

}

void sshsql::sshKey_deletesshKeyInfo(sshKeyStruct skeyStruct)
{

}