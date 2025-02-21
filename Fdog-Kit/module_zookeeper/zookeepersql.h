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

#ifndef ZOOKEEPERSQL_H
#define ZOOKEEPERSQL_H
#include <QVector>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include "module_utils/utils.h"

class zookeepersql {

public:
    QSqlDatabase m_zkdb;

    zookeepersql();
    ~zookeepersql();
    void zookeeper_init();

    QVector<zkInfoStruct> zk_getAllZkInfo();
    void zk_insertZkInfo(zkInfoStruct zkInfo);
    void zk_deleteZkInfo(zkInfoStruct zkInfo);

};

#endif // ZOOKEEPERSQL_H
