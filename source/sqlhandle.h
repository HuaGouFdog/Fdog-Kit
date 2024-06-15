#ifndef SQLHANDLE_H
#define SQLHANDLE_H

/*CREATE TABLE TB_SSHINFO (name TEXT NOT NULL, ip TEXT NOT NULL, password TEXT NOT NULL,\
                            ssh_group TEXT NOT NULL, remark TEXT NOT NULL, nearest_connection TEXT NOT NULL*/

#include <QVector>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

#include "createconnect.h"

struct SSHINFO {
    QString name;
    QString ip;
    QString password;
    QString ssh_group;
    QString remark;
    QString nearest_connection;
};

class sqlhandle
{
public:
    sqlhandle();
    ~sqlhandle();


    void ssh_init();

    QVector<connnectInfoStruct> ssh_getAllSSHInfo();

    connnectInfoStruct  ssh_getSSHInfoByHost(QString host);
    
    void ssh_insertSSHInfo(connnectInfoStruct cInfoStruct);

    void ssh_updateSSHInfo(connnectInfoStruct cInfoStruct);

    void ssh_deleteSSHInfo(connnectInfoStruct cInfoStruct);

    QSqlDatabase database;
};

#endif // SQLHANDLE_H
