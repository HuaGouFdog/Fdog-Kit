#pragma execution_character_set("utf-8")
#include "databasewidget.h"
#include "ui_databasewidget.h"

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

databasewidget::databasewidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::databasewidget)
{
    ui->setupUi(this);


        qDebug() << QSysInfo::WordSize;


    QSqlDatabase database = QSqlDatabase::addDatabase("QMYSQL");
    database.setDatabaseName("IM_BADWORD");
    database.setHostName("127.0.0.1");
    database.setPort(3306);
    database.setUserName("test");
    database.setPassword("test");

    if (!database.open()) {
        qDebug() << "db打开失败" << database.lastError();
    }

    QSqlQuery sqlQuery(database);
    sqlQuery.prepare("show databases");
    //sqlQuery.addBindValue(host);
    sqlQuery.exec();
    if(!sqlQuery.exec()) {
        qDebug() << "Error: Fail to query table. " << sqlQuery.lastError();
    } else {
        while(sqlQuery.next())
        {
            QTreeWidgetItem *parentItem = new QTreeWidgetItem(ui->treeWidget_db);
            //QIcon icon2(":/lib/server.png");
            parentItem->setText(0, sqlQuery.value(0).toString());

            QSqlQuery sqlQuery(database);
            sqlQuery.prepare("show tables");
            //sqlQuery.addBindValue(host);
            sqlQuery.exec();
            if(!sqlQuery.exec()) {
                qDebug() << "Error: Fail to query table. " << sqlQuery.lastError();
            } else {
                while(sqlQuery.next())
                {
                    QTreeWidgetItem *parentItem2 = new QTreeWidgetItem(parentItem);
                    //QIcon icon2(":/lib/server.png");
                    parentItem2->setText(0, sqlQuery.value(0).toString());
                }
            }

        }
    }
}

databasewidget::~databasewidget()
{
    delete ui;
}
