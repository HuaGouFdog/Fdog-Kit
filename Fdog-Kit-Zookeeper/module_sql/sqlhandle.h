#ifndef SQLHANDLE_H
#define SQLHANDLE_H

/*CREATE TABLE TB_SSHINFO (name TEXT NOT NULL, ip TEXT NOT NULL, password TEXT NOT NULL,\
                            ssh_group TEXT NOT NULL, remark TEXT NOT NULL, nearest_connection TEXT NOT NULL*/

#include <QVector>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include "module_utils/utils.h"
struct SSHINFO {
    QString name;
    QString ip;
    QString password;
    QString ssh_group;
    QString remark;
    QString nearest_connection;
};

struct sshKeyStruct {
    QString name;
    QString path;
    QString password;
};

class sqlhandle
{
public:
    sqlhandle();
    ~sqlhandle();


    void ssh_init();
    void ssh_key_init();
    void zookeeper_init();

    void sql_mysql_init();

    QVector<zkInfoStruct> zk_getAllZkInfo();
    void zk_insertZkInfo(zkInfoStruct zkInfo);
    void zk_updateZkInfo(zkInfoStruct zkInfo);
    void zk_deleteZkInfo(zkInfoStruct zkInfo);

    //缺prot
    QVector<connnectInfoStruct> ssh_getAllSSHInfo();
    connnectInfoStruct ssh_getSSHInfoByHost(QString host);

    connnectInfoStruct ssh_getSSHInfoByName(QString name);
    
    void ssh_insertSSHInfo(connnectInfoStruct cInfoStruct);

    void ssh_updateSSHInfo(connnectInfoStruct cInfoStruct);

    void ssh_deleteSSHInfo(connnectInfoStruct cInfoStruct);

    QVector<sshKeyStruct> sshKey_getAllSSHKeyInfo();

    sshKeyStruct sshKey_getSSHKeyInfoByName(QString text);

    void sshKey_insertsshKeyInfo(sshKeyStruct skeyStruct);

    void sshKey_updatesshKeyInfo(sshKeyStruct skeyStruct);

    void sshKey_deletesshKeyInfo(sshKeyStruct skeyStruct);

    QSqlDatabase database_ssh;
    QSqlDatabase database_zk;
};

#endif // SQLHANDLE_H
