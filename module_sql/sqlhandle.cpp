#pragma execution_character_set("utf-8")
#include "sqlhandle.h"

#include <QDebug>

sqlhandle::sqlhandle()
{
    ssh_init();
}

sqlhandle::~sqlhandle()
{
    database.close();
}

void sqlhandle::ssh_init()
{
    if (QSqlDatabase::contains("qt_sql_default_connection"))
    {
        database = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        // 建立和SQlite数据库的连接
        database = QSqlDatabase::addDatabase("QSQLITE");
        // 设置数据库文件的名字
        database.setDatabaseName("DB_SSHINFO.db");
    }

    if (!database.open())
    {
        qDebug() << "Error: Failed to connect database." << database.lastError();
    }
    else
    {
        qDebug() << "数据库已经打开";
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
        qDebug() << "Error: Fail to create table. " << sqlQuery.lastError();
    }
    else
    {     qDebug() << "Table created!";
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
