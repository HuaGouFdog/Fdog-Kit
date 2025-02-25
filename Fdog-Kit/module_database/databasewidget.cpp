#pragma execution_character_set("utf-8")
#include "databasewidget.h"
#include "ui_databasewidget.h"

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include <QDebug>
#include <QAction>
#include <QSqlRecord>
#include <QSqlField>
#include <QLabel>
#include <QPropertyAnimation>
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

    //ui->label->setStyleSheet("background-color: red;"); // 设置颜色
    //ui->label->setGeometry(0, 150, 100, 50); // 初始位置 (x=0, y=150)，宽 100，高 50

    // 创建动画对象
    m_pos_animation = new QPropertyAnimation();
    // animation.setDuration(2000);  // 动画时长 2 秒
    // animation.setStartValue(QRect(500, 500, 100, 50));   // 起始位置
    // animation.setEndValue(QRect(500, 500, 100, 50));   // 终点位置
    // animation.setEasingCurve(QEasingCurve::OutBounce); // 让动画有弹性


        // // 1. 设置动画应用对象
        // m_pos_animation->setTargetObject(ui->widget_3);
        // // 2.设置动画属性
        // m_pos_animation->setPropertyName("pos");
        // // 3.设置动画的起始值
        // QPoint startPoint(-300, 100);
        // m_pos_animation->setStartValue(startPoint);
        // m_pos_animation->setEndValue(startPoint + QPoint(1000, 0));
        // // 4.设置动画的时间
        // m_pos_animation->setDuration(3000);
    
        // // 5.设置动画的缓和曲线
        // m_pos_animation->setEasingCurve(QEasingCurve::InQuart);
    
        // // 6.设置动画的播放周期
        // m_pos_animation->setLoopCount(1);


    QSqlDatabase database = QSqlDatabase::addDatabase("QMYSQL");
    // database.setDatabaseName("IM_BADWORD");
    // database.setHostName("127.0.0.1");
    // database.setPort(3306);
    // database.setUserName("test");
    // database.setPassword("test");


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
    database.setDatabaseName("IM_BADWORD");
    database.setHostName(cInfoStruct.host);
    database.setPort(cInfoStruct.port.toInt());
    database.setUserName(cInfoStruct.userName);
    database.setPassword(cInfoStruct.password);


    if (!database.open()) {
        qDebug() << "db打开失败" << database.lastError();
        return;
    }
    qDebug() << "触发7";
    QTreeWidgetItem *parentItem = new QTreeWidgetItem(ui->treeWidget_db);
    QIcon icon2(":/module_database/images/dark/server.png");
    parentItem->setIcon(0, icon2);
    parentItem->setText(0, "172.16.8.154");

    QSqlQuery sqlQuery(database);
    sqlQuery.prepare("show databases");
    //sqlQuery.addBindValue(host);
    if(!sqlQuery.exec()) {
        qDebug() << "Error: Fail to query table. " << sqlQuery.lastError();
    } else {
        while(sqlQuery.next())
        {
            QTreeWidgetItem *parentItem2 = new QTreeWidgetItem(parentItem);
            QIcon icon2(":/module_database/images/dark/base.png");
            parentItem2->setIcon(0, icon2);
            parentItem2->setText(0, sqlQuery.value(0).toString());
        }
    }
    parentItem->setExpanded(true);
}

void databasewidget::on_treeWidget_db_itemClicked(QTreeWidgetItem *item, int column)
{
    //单击
    if (item->parent() && !item->parent()->parent()) {
        qDebug() << "这是一个一级节点 库";
        if (item->childCount() > 0) {
            qDebug() << "item 已经有子节点，跳过进一步操作";
            return;
        }
        QString dataBaseName = item->text(0);
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
                QIcon icon2(":/module_database/images/dark/table.png");
                parentItem->setIcon(0, icon2);
                parentItem->setText(0, sqlQuery.value(0).toString());
            }
        }
        
    } else if (!item->parent()) {
        QString tableName = item->text(0);
        qDebug() << "这是主机" << tableName;
    } else if(item->parent() && item->parent()->parent() && !item->parent()->parent()->parent()){
        QString tableName = item->text(0);
        QSqlQuery sqlQuery(database);
        QString db  = item->parent()->text(0);
        qDebug() << "这是一个二级节点，一个表" << tableName << "  他的库是" << item->parent()->text(0);
        QString a = "SHOW COLUMNS FROM " +  tableName + " FROM " + db;
        qDebug() << a;
        //sqlQuery.prepare("SHOW COLUMNS FROM " +  tableName + " FROM " + db);
        sqlQuery.prepare(a);
        if(!sqlQuery.exec()) {
            qDebug() << "Error: Fail to query table. " << sqlQuery.lastError();
        } else {
            if (item->childCount() > 0) {
                qDebug() << "item 已经有子节点，跳过进一步操作";
                return;
            }
            // 获取记录信息
            QSqlRecord record = sqlQuery.record();
            // 获取字段数量
            int fieldCount = record.count();
            qDebug() << "字段数量:" << fieldCount;

            QStringList a;
            // for (int i = 0; i < fieldCount; ++i) {
            //     // 获取字段名称
            //     QTreeWidgetItem *parentItem = new QTreeWidgetItem(item);
            //     QIcon icon2(":/module_database/images/dark/field.png");
            //     parentItem->setIcon(0, icon2);
            //     parentItem->setText(0, record.fieldName(i));
            //     //a.push_back(record.fieldName(i));
            //     //qDebug() << "字段" << i << ":" << fieldName;
            // }

            while(sqlQuery.next())
            {   
                QTreeWidgetItem *parentItem = new QTreeWidgetItem(item);
                QIcon icon2(":/module_database/images/dark/field.png");
                parentItem->setIcon(0, icon2);
                parentItem->setText(0, sqlQuery.value(0).toString());
            }
            return;

            ui->tableWidget->horizontalHeader()->setVisible(true);
            ui->tableWidget->verticalHeader()->setVisible(false);

            ui->tableWidget->setColumnCount(fieldCount); //设置列数为2
            ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
            ui->tableWidget->setHorizontalHeaderLabels(a);
            //auto delegate = new HoveredRowItemDelegate(ui->tableWidget);
            //ui->tableWidget->setItemDelegate(delegate);
            //ui->tableWidget->horizontalHeader()->setDefaultAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

            int rowCount = 0;
            while(sqlQuery.next())
            {   
                ui->tableWidget->insertRow(rowCount);
                for (int i = 0; i < fieldCount; ++i) {
                    QString fieldValue = sqlQuery.value(i).toString();
                        // 将字段值插入到 QTableWidget 中
                        //qDebug() << "字段" << i << ":" << fieldValue;
                    ui->tableWidget->setItem(rowCount, i, new QTableWidgetItem(fieldValue));
                }
                rowCount++;
            }
        }
        qDebug() << "打印建表";
        QSqlQuery sqlQuery2(database);
        QString cc = "BADWORD";
        sqlQuery2.prepare("select * from IM_BADWORD.BADWORD");
        if(!sqlQuery2.exec()) {
            qDebug() << "Error: Fail to query table. " << sqlQuery2.lastError();
        } else {
            // 获取记录信息
            QSqlRecord record2 = sqlQuery2.record();
            // 获取字段数量
            int fieldCount = record2.count();
            qDebug() << "字段数量:" << fieldCount;

            QStringList a;
            for (int i = 0; i < fieldCount; ++i) {
                // 获取字段名称
                a.push_back(record2.fieldName(i));
                //qDebug() << "字段" << i << ":" << fieldName;
            }

            ui->tableWidget_2->horizontalHeader()->setVisible(true);
            ui->tableWidget_2->verticalHeader()->setVisible(false);

            ui->tableWidget_2->setColumnCount(fieldCount); //设置列数为2
            ui->tableWidget_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
            ui->tableWidget_2->setHorizontalHeaderLabels(a);

            //auto delegate = new HoveredRowItemDelegate(ui->tableWidget_2);
            //ui->tableWidget_2->setItemDelegate(delegate);
            //ui->tableWidget_2->horizontalHeader()->setDefaultAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            int rowCount = 0;
            while(sqlQuery2.next())
            {   
                ui->tableWidget_2->insertRow(rowCount);
                for (int i = 0; i < fieldCount; ++i) {
                    QString fieldValue = sqlQuery2.value(i).toString();
                        // 将字段值插入到 QTableWidget 中
                        //qDebug() << "字段" << i << ":" << fieldValue;
                    ui->tableWidget_2->setItem(rowCount, i, new QTableWidgetItem(fieldValue));
                }
                rowCount++;
            }
        }


        QSqlQuery sqlQuery3(database);
        sqlQuery3.prepare("SHOW CREATE TABLE IM_BADWORD.BADWORD");
        if(!sqlQuery3.exec()) {
            qDebug() << "Error: Fail to query table. " << sqlQuery3.lastError();
        } else {
            while(sqlQuery3.next())
            {   
                qDebug() << "数据";
            }
            qDebug() << "结束";
        }
    } else {
        qDebug() << "这是一个字段";
    }
}


void databasewidget::on_treeWidget_db_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    qDebug() << "双击";
    //双击展开
    item->setExpanded(item->isExpanded());
}


void databasewidget::on_toolButton_clicked()
{
    // 显示窗口并启动动画
    m_pos_animation->start();
}

