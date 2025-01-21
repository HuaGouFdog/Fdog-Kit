#ifndef SSHSQL_H
#define SSHSQL_H

#include <QVector>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include "module_utils/utils.h"

class sshsql
{
public:
    sshsql();
    ~sshsql();
    void ssh_init();

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
};

#endif // SSHSQL_H
