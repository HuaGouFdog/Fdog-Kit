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

#include "zookeepersql.h"

zookeepersql::zookeepersql() {
    zookeeper_init();
}

zookeepersql::~zookeepersql() {
    m_zkdb.close();
}

void zookeepersql::zookeeper_init()
{
    if (QSqlDatabase::contains("zk_info_sqlLite")) {
        m_zkdb = QSqlDatabase::database("zk_info_sqlLite");
        qDebug() << "zk_info_sqlLite已经存在";
    } else {
        // 建立和SQlite数据库的连接
        m_zkdb = QSqlDatabase::addDatabase("QSQLITE", "zk_info_sqlLite");
    }
    // 设置数据库文件的名字
    m_zkdb.setDatabaseName("DB_ZK_INFO.db");

    if (!m_zkdb.open()) {
        qDebug() << "DB_ZK_INFO.db打开失败" << m_zkdb.lastError();
    }

    // 用于执行sql语句的对象
    QSqlQuery sqlQuery(m_zkdb);
    // 构建创建数据库的sql语句字符串
    QString createSql = QString("CREATE TABLE TB_ZK_INFO (name TEXT NOT NULL, host TEXT NOT NULL, port TEXT NOT NULL)");

    sqlQuery.prepare(createSql);
    // 执行sql语句
    if(!sqlQuery.exec()) {
        qDebug() << "DB_ZKINFO.db Error: Fail to create table. " << sqlQuery.lastError();
    } else {
        qDebug() << "DB_ZKINFO.db Table created!";
    }
}

QVector<zkInfoStruct> zookeepersql::zk_getAllZkInfo() {
    QVector<zkInfoStruct> zkInfoStructList;
    QSqlQuery sqlQuery(m_zkdb);
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

void zookeepersql::zk_insertZkInfo(zkInfoStruct zkInfo) {
    QSqlQuery sqlQuery(m_zkdb);
    sqlQuery.prepare("INSERT INTO TB_ZK_INFO VALUES(?, ?, ?)");
    sqlQuery.addBindValue(zkInfo.name);
    sqlQuery.addBindValue(zkInfo.host);
    sqlQuery.addBindValue(zkInfo.port);
    if(!sqlQuery.exec()) {
        qDebug() << "Error: Fail to insert data. " << sqlQuery.lastError();
    }
}

void zookeepersql::zk_deleteZkInfo(zkInfoStruct zkInfo) {
    QSqlQuery sqlQuery(m_zkdb);
    sqlQuery.prepare("DELETE FROM TB_ZK_INFO WHERE host=?");
    sqlQuery.addBindValue(zkInfo.host);
    if(!sqlQuery.exec()) {
        qDebug() << "Error: Fail to DELETE table." << sqlQuery.lastError();
    }
}
