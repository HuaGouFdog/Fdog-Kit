#pragma execution_character_set("utf-8")
#include "databasewidget.h"
#include "ui_databasewidget.h"

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include <QDebug>
#include <QAction>

databasewidget::databasewidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::databasewidget)
{
    ui->setupUi(this);
    qDebug() << "创建1";
    QAction *action = new QAction(this);
    action->setIcon(QIcon(":/lib/soucuo.png"));
    ui->lineEdit_find->addAction(action,QLineEdit::LeadingPosition);
    qDebug() << "创建2";
    return;


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

databasewidget::databasewidget(connnectInfoStruct &cInfoStruct, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::databasewidget)
{
    ui->setupUi(this);
    qDebug() << "创建3";
    QAction *action = new QAction(this);
    action->setIcon(QIcon(":/lib/soucuo.png"));
    ui->lineEdit_find->addAction(action,QLineEdit::LeadingPosition);
    
    //创建db连接
    newDBWidget(cInfoStruct);
    //全局捕捉mouseMoveEvent事件
    setSupportStretch(this, true);
    qDebug() << "创建4";
}

databasewidget::~databasewidget()
{
    qDebug() << "调用databasewidget析构";
    database.close();
    delete ui;
}

void databasewidget::initDBInfo()
{

}

void databasewidget::newDBWidget(connnectInfoStruct &cInfoStruct)
{
    qDebug() << "触发6";
    database = QSqlDatabase::addDatabase("QMYSQL");
    // database.setDatabaseName("IM_BADWORD");
    // database.setHostName(cInfoStruct.host);
    // database.setPort(cInfoStruct.port.toInt());
    // database.setUserName(cInfoStruct.userName);
    // database.setPassword(cInfoStruct.password);



    if (!database.open()) {
        qDebug() << "db打开失败" << database.lastError();
        return;
    }
    qDebug() << "触发7";
    QTreeWidgetItem *parentItem = new QTreeWidgetItem(ui->treeWidget_db);
    parentItem->setText(0, "172.16.8.154");

    QSqlQuery sqlQuery(database);
    sqlQuery.prepare("show databases");
    //sqlQuery.addBindValue(host);
    sqlQuery.exec();
    if(!sqlQuery.exec()) {
        qDebug() << "Error: Fail to query table. " << sqlQuery.lastError();
    } else {
        while(sqlQuery.next())
        {
            QTreeWidgetItem *parentItem2 = new QTreeWidgetItem(parentItem);
            parentItem2->setText(0, sqlQuery.value(0).toString());
        }
    }
    parentItem->setExpanded(true);
}

void databasewidget::on_treeWidget_db_itemClicked(QTreeWidgetItem *item, int column)
{
    //单击
    if (item->parent() && !item->parent()->parent()) {
        qDebug() << "这是一个一级节点";
        if (item->childCount() > 0) {
            qDebug() << "item 已经有子节点，跳过进一步操作";
            return;
        }

        QString dataBaseName = item->text(0);
        qDebug() << "点击库 " << dataBaseName;
        QSqlQuery sqlQuery(database);
        sqlQuery.prepare("use " + dataBaseName);
        sqlQuery.exec();
        sqlQuery.prepare("show tables");
        sqlQuery.exec();
        if(!sqlQuery.exec()) {
            qDebug() << "Error: Fail to query table. " << sqlQuery.lastError();
        } else {
            while(sqlQuery.next())
            {
                QTreeWidgetItem *parentItem = new QTreeWidgetItem(item);
                parentItem->setText(0, sqlQuery.value(0).toString());
            }
        }
        
    } else if (!item->parent()) {
        QString tableName = item->text(0);
        qDebug() << "这是主机" << tableName;
    } else {
        QString tableName = item->text(0);
        qDebug() << "这是一个表" << tableName;
    }
}


void databasewidget::on_treeWidget_db_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    qDebug() << "双击";
    //双击展开
    item->setExpanded(item->isExpanded());
}

