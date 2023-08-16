#pragma execution_character_set("utf-8")
#include "zookeeperwidget.h"
#include "zookeeperhandle.h"
#include "ui_zookeeperwidget.h"
#include <QDateTime>
#include <QString>
#include <QDebug>
#include <QJsonParseError>
#include <QMenu>
#include <QClipboard>
#include <QTest>
zookeeperwidget::zookeeperwidget(connnectInfoStruct& cInfoStruct, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::zookeeperwidget)
{
    ui->setupUi(this);
    hideCreateWidget();
    //隐藏修改按钮
    zh = nullptr;
    ui->toolButton_saveData->hide();
    init(cInfoStruct.host, cInfoStruct.port);
}

zookeeperwidget::~zookeeperwidget()
{
    delete ui;
}

void zookeeperwidget::init(QString host, QString port)
{
    QString rootPath = "/";

    thread = new QThread();
    zookhandle = new zookeeperhandle();

    //zookhandle->setZh(zh);
    //zookhandle->setPath(nodePath);
    //zookhandle->setItem(topItem);
    // 将对象移动到线程中
    zookhandle->moveToThread(thread);

    //初始化连接
    connect(zookhandle,SIGNAL(send_init(bool,QString,QVariant, QString)),this,
                            SLOT(rece_init(bool,QString,QVariant, QString)));

    connect(zookhandle,SIGNAL(send_getChildren(QString, QVariant, QVector<QString>, QVector<int>, QTreeWidgetItem*)),this,
                            SLOT(rece_getChildren(QString,QVariant,QVector<QString>, QVector<int>,QTreeWidgetItem*)));

    connect(zookhandle,SIGNAL(send_getNodeInfo_2(QVariant,QString,QString)),this,
                            SLOT(rece_getNodeInfo_2(QVariant,QString,QString)));
    thread->start();
    QMetaObject::invokeMethod(zookhandle,"init",Qt::QueuedConnection, Q_ARG(QString, rootPath), Q_ARG(QString,host), Q_ARG(QString,port));

}

void zookeeperwidget::rece_init(bool connected, QString path, const QVariant varValue, QString data)
{
    //将数据回写ui
    Stat stat = varValue.value<Stat>();
    ui->lineEdit_node->setText(path);
    //ui显示数据
    showNodeInfo(data, stat, path);

    topItem = new QTreeWidgetItem(ui->treeWidget);
    ui->treeWidget->addTopLevelItem(topItem);
    topItem->setText(0, path);
    qDebug() << "rece_init";
    //判断是否有子节点
    if (stat.numChildren > 0) {
        //获取子节点
        getChildren(path, topItem);
    }
}

void zookeeperwidget::getChildren(QString path, QTreeWidgetItem *item)
{
    QMetaObject::invokeMethod(zookhandle,"getChildren",Qt::QueuedConnection, Q_ARG(QString,path), Q_ARG(QTreeWidgetItem*, item));
}

void zookeeperwidget::rece_getChildren(QString path, const QVariant varValue, QVector<QString> dataList, QVector<int> childrenList, QTreeWidgetItem *item)
{
    String_vector children = varValue.value<String_vector>();
    for (int i = 0; i < children.count; ++i) {
           qDebug() << "children.data[i] = " << children.data[i];
        QTreeWidgetItem *item2 = new QTreeWidgetItem(item);
        QString children_path;
        if (path != "/") {
            children_path = QString::fromStdString(path.toStdString() + "/" + children.data[i]);

        } else {
            children_path = QString::fromStdString(path.toStdString() + children.data[i]);
        }
        item2->setText(0, children_path);
        //如果有数据，显示绿点，无数据，显示灰点
        if (dataList[i].length() > 0) {
            item2->setIcon(0, QIcon(":lib/node.png"));
        } else {
            item2->setIcon(0, QIcon(":lib/node2.png"));
        }

        //如果有子节点继续请求
        if (childrenList[i] > 0) {
            qDebug() << "getChildren children.data[i] = " << children_path;
            //getChildren(children_path, item2);
        }
    }
}

void zookeeperwidget::getNodeInfo(QString &path)
{
    qDebug() << "getNodeInfo 1";
    QMetaObject::invokeMethod(zookhandle,"getNodeInfo_2",Qt::QueuedConnection, Q_ARG(QString,path));
}

void zookeeperwidget::rece_getNodeInfo_2(QVariant varValue, QString data, QString path)
{
    Stat stat = varValue.value<Stat>();
    qDebug() << "rece_getNodeInfo_2 数据 = " << data;
    showNodeInfo(data, stat, path);
}

void zookeeperwidget::showNodeInfo(QString data, Stat stat, QString path)
{
    // 获取节点的创建时间（以毫秒为单位）
    long long createTime = stat.ctime;
    QDateTime dateTime;
    dateTime = QDateTime::fromMSecsSinceEpoch(stat.ctime); // 将时间戳设置为QDateTime对象的秒数
    QString dateString = dateTime.toString("yyyy-MM-dd"); // 将日期部分格式化为字符串
    QString timeString = dateTime.toString("hh:mm:ss"); // 将时间部分格式化为字符串

    dateTime = QDateTime::fromMSecsSinceEpoch(stat.mtime); // 将时间戳设置为QDateTime对象的秒数
    QString dateString2 = dateTime.toString("yyyy-MM-dd"); // 将日期部分格式化为字符串
    QString timeString2 = dateTime.toString("hh:mm:ss"); // 将时间部分格式化为字符串

    ui->lineEdit_czxid->setText(QString::number(stat.czxid));
    ui->lineEdit_mzxid->setText(QString::number(stat.mzxid));
    ui->lineEdit_ctime->setText(dateString + " " + timeString);
    ui->lineEdit_mtime->setText(dateString2 + " " + timeString2);
    ui->lineEdit_version->setText(QString::number(stat.version));
    ui->lineEdit_cversion->setText(QString::number(stat.cversion));
    ui->lineEdit_aversion->setText(QString::number(stat.aversion));
    ui->lineEdit_ephemeralOwner->setText(QString::number(stat.ephemeralOwner));
    ui->lineEdit_dataLength->setText(QString::number(stat.dataLength));
    ui->lineEdit_numChildren->setText(QString::number(stat.numChildren));
    ui->lineEdit_pzxid->setText(QString::number(stat.pzxid));

    ui->textEdit_data->clear();
    // 尝试解析 JSON 数据
    QJsonParseError error;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(data.toUtf8(), &error);
    if (error.error == QJsonParseError::NoError && !jsonDoc.isNull()) {
        // 格式化为可读的字符串
        QString formattedJson = jsonDoc.toJson(QJsonDocument::Indented);
        ui->textEdit_data->insertPlainText(formattedJson);
        nodeData = formattedJson;
        nodeDataPath = path;
        ui->toolButton_saveData->setEnabled(false);
        ui->label_data_type->setText("数据类型：json");
    } else {
        ui->textEdit_data->insertPlainText(data.toUtf8());
        nodeData = data.toUtf8();
        nodeDataPath = path;
        ui->toolButton_saveData->setEnabled(false);
        ui->label_data_type->setText("数据类型：value");
    }
}


//void zookeeperwidget::getAllChildren(zhandle_t* zh, std::string path, QTreeWidgetItem * item, int x, int y) {
//    //添加顶层节点
//    //item->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable);
//    struct String_vector children;
//    int rc = zoo_get_children(zh, path.c_str(), 0, &children);
//    if (rc == ZOK) {
//        for (int i = 0; i < children.count; ++i) {
//            QTreeWidgetItem *item2 = new QTreeWidgetItem(item);
//            QString p2;
//            if (path != "/") {
//                p2 = QString::fromStdString(path + "/" + children.data[i]);

//            } else {
//                p2 = QString::fromStdString(path + children.data[i]);
//            }
//            item2->setText(0, p2);
//            int32_t childrentNum = getNodeInfo(p2);
//            if (childrentNum > 0) {
//                item2->setIcon(0, QIcon(":lib/node.png"));
//            } else {
//                item2->setIcon(0, QIcon(":lib/node2.png"));
//            }
//        }
//    } else {
//        return;
//    }
//}

void zookeeperwidget::hideNodeInfoWidget()
{
    ui->gridWidget_1_1_r->hide();
}

void zookeeperwidget::showNodeInfoWidget()
{
    ui->gridWidget_1_1_r->show();
}

void zookeeperwidget::hideCreateWidget()
{
    ui->horizontalWidget_1_2_1_r->hide();
    ui->horizontalWidget_1_2_2_r->hide();
    ui->horizontalWidget_1_2_3_r->hide();
    ui->verticalWidget_1_2_6_r->hide();
    ui->toolButton_createData->hide();
    ui->toolButton_saveData->hide();
}

void zookeeperwidget::showCreateWidget()
{
    ui->horizontalWidget_1_2_1_r->show();
    ui->horizontalWidget_1_2_2_r->show();
    ui->horizontalWidget_1_2_3_r->show();
    ui->verticalWidget_1_2_6_r->show();
    ui->toolButton_createData->show();
    ui->toolButton_saveData->hide();
}

//int32_t zookeeperwidget::getNodeInfo(QString &path)
//{
//    // 获取节点的stat信息
//    struct Stat stat;
//    int rc = zoo_exists(zh, path.toStdString().c_str(), 0, &stat);
//    if (rc != ZOK) {
//        qDebug() << "Error: Failed to get node stat";
//        zookeeper_close(zh);
//        //return 1;
//    }

//    // 获取节点的创建时间（以毫秒为单位）
//    long long createTime = stat.ctime;

//    ui->lineEdit_czxid->setText(QString::number(stat.czxid));
//    ui->lineEdit_mzxid->setText(QString::number(stat.mzxid));

//    QDateTime dateTime;
//    dateTime = QDateTime::fromMSecsSinceEpoch(stat.ctime); // 将时间戳设置为QDateTime对象的秒数
//    QString dateString = dateTime.toString("yyyy-MM-dd"); // 将日期部分格式化为字符串
//    QString timeString = dateTime.toString("hh:mm:ss"); // 将时间部分格式化为字符串

//    dateTime = QDateTime::fromMSecsSinceEpoch(stat.mtime); // 将时间戳设置为QDateTime对象的秒数
//    QString dateString2 = dateTime.toString("yyyy-MM-dd"); // 将日期部分格式化为字符串
//    QString timeString2 = dateTime.toString("hh:mm:ss"); // 将时间部分格式化为字符串

//    ui->lineEdit_ctime->setText(dateString + " " + timeString);
//    ui->lineEdit_mtime->setText(dateString2 + " " + timeString2);
//    ui->lineEdit_version->setText(QString::number(stat.version));
//    ui->lineEdit_cversion->setText(QString::number(stat.cversion));
//    ui->lineEdit_aversion->setText(QString::number(stat.aversion));
//    ui->lineEdit_ephemeralOwner->setText(QString::number(stat.ephemeralOwner));
//    ui->lineEdit_dataLength->setText(QString::number(stat.dataLength));
//    ui->lineEdit_numChildren->setText(QString::number(stat.numChildren));
//    ui->lineEdit_pzxid->setText(QString::number(stat.pzxid));
//    return stat.numChildren;
//}

//void zookeeperwidget::getNodeData(QString &path)
//{
//    char buffer[1024]  = {0}; //不写0 会乱码
//    int buffer_len = sizeof(buffer);
//    struct Stat stat;
//    int rc = zoo_get(zh, path.toStdString().c_str(), 0, buffer, &buffer_len, &stat);
//    if (rc == ZOK) {
//        QString str = QString::fromUtf8(buffer);
//        qDebug() << "str = " << str;
//        //qDebug() << "char = " << buffer;
//        // 尝试解析 JSON 数据
//        QJsonParseError error;
//        QJsonDocument jsonDoc = QJsonDocument::fromJson(str.toUtf8(), &error);
//        if (error.error == QJsonParseError::NoError && !jsonDoc.isNull()) {
//            // 格式化为可读的字符串
//            QString formattedJson = jsonDoc.toJson(QJsonDocument::Indented);
//            //qDebug() << formattedJson;
//            ui->textEdit_data->clear();
//            ui->textEdit_data->insertPlainText(formattedJson);
//            nodeData = formattedJson;
//            nodeDataPath = path;
//            ui->toolButton_saveData->setEnabled(false);
//        } else {
//            ui->textEdit_data->clear();
//            ui->textEdit_data->insertPlainText(str.toUtf8());
//            nodeData = str.toUtf8();
//            nodeDataPath = path;
//            ui->toolButton_saveData->setEnabled(false);
//        }

//    } else if (rc == ZNONODE) {
//        qDebug() << "Node does not exist";
//        fprintf(stderr, "Node does not exist\n");
//    } else {
//        qDebug() << "Failed to get node data" << zerror(rc);
//    }
//}

void zookeeperwidget::addNode(QString &path)
{
    parentItem = ui->treeWidget->currentItem();
    if (parentItem->text(0) == "/") {
        ui->lineEdit_node_create->setText(parentItem->text(0) + "newNode");
    } else {
        ui->lineEdit_node_create->setText(parentItem->text(0) + "/newNode");
    }

    ui->lineEdit_node_create->setFocus();
    showCreateWidget();
    hideNodeInfoWidget();
}

void zookeeperwidget::deleteNode(QString &path)
{
    QTreeWidgetItem *item = ui->treeWidget->currentItem();
    QTreeWidgetItem *parentItem = item->parent();

    int ret = zoo_delete(zh, item->text(0).toStdString().c_str(), -1);
    if (ret != ZOK) {
        qDebug() << "Failed to delete node. Error";
    } else {
        qDebug() << "Node deleted successfully.";
    }

    // 从父节点中删除子节点
    parentItem->removeChild(item);
    // 释放子节点的内存
    delete item;

    qDebug() << "delete";
}

void zookeeperwidget::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
    ui->lineEdit_node->setText(item->text(column));
    QString path = item->text(column);
    getNodeInfo(path);
    //单击
//    ui->lineEdit_node->setText(item->text(column));
//    if (item->childCount() <= 0) {
//        getAllChildren(zh, item->text(column).toStdString().c_str(), item);
//    }
//    ui->lineEdit_node->setText(item->text(column));
//    qDebug() << item->text(column);
//    getNodeInfo(item->text(column));
//    getNodeData(item->text(column));
}

void zookeeperwidget::on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    //双击
//    ui->lineEdit_node->setText(item->text(column));
//    item->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
//    if (item->childCount() <= 0) {
//        getAllChildren(zh, item->text(column).toStdString().c_str(), item);
//    }
}

void zookeeperwidget::on_textEdit_data_textChanged()
{
    qDebug() << "nodeData = " << nodeData << "& nodeDataPath = " << nodeDataPath;
    if (nodeData != ui->textEdit_data->toPlainText() && nodeDataPath == ui->treeWidget->currentItem()->text(0)) {
        qDebug() << "显示修改按钮";
        ui->toolButton_saveData->show();
        ui->toolButton_saveData->setEnabled(true);
    } else {
        ui->toolButton_saveData->hide();
        ui->toolButton_saveData->setEnabled(false);
    }
}

void zookeeperwidget::on_treeWidget_customContextMenuRequested(const QPoint &pos)
{
    m_action_add = new QAction("添加", this);
    m_action_refresh = new QAction("刷新", this);
    m_action_delete = new QAction("删除", this);
    m_action_copy = new QAction("复制", this);

    m_action_add->setIconVisibleInMenu(false);
    m_action_refresh->setIconVisibleInMenu(false);
    m_action_delete->setIconVisibleInMenu(false);
    m_action_copy->setIconVisibleInMenu(false);

    //定义右键弹出菜单
    popMenu = new QMenu(this);
    popMenu->addAction(m_action_add);
    popMenu->addAction(m_action_refresh);
    popMenu->addAction(m_action_delete);
    popMenu->addAction(m_action_copy);

    connect(m_action_add, SIGNAL(triggered()), this, SLOT(on_nodeAction()));
    connect(m_action_refresh, SIGNAL(triggered()), this, SLOT(on_nodeAction()));
    connect(m_action_delete, SIGNAL(triggered()), this, SLOT(on_nodeAction()));
    connect(m_action_copy, SIGNAL(triggered()), this, SLOT(on_nodeAction()));
    popMenu->exec(QCursor::pos());//弹出右键菜单，菜单位置为光标位置
}

void zookeeperwidget::on_nodeAction()
{
    QString actionText = qobject_cast<QAction*>(sender())->text();
    QString node = ui->treeWidget->currentItem()->text(0);
    if (actionText == "添加") {
        //addNode(node);
    } else if (actionText == "刷新") {
        //getNodeInfo(node);
        //getNodeData(node);
    } else if (actionText == "删除") {
        //deleteNode(node);
    } else if (actionText == "复制") {
        QTreeWidgetItem *item = ui->treeWidget->currentItem();
        QClipboard *clipboard = QApplication::clipboard();
        clipboard->setText(item->text(0));
    }
}

void zookeeperwidget::on_toolButton_saveData_clicked()
{
    std::string path = ui->treeWidget->currentItem()->text(0).toStdString();
    //修改节点数据
    std::string data = ui->textEdit_data->toPlainText().toStdString();
    int data_len = strlen(data.c_str());
    int ret = zoo_set(zh, path.c_str(), data.c_str(), data_len, -1);
    if (ret != ZOK) {
        qDebug() <<"Failed to set node data. Error";
    } else {
        qDebug() <<"Node data set successfully.";
        ui->toolButton_saveData->hide();
    }
}

void zookeeperwidget::on_toolButton_createData_clicked()
{
    //拿到刚才创建的值
    QTreeWidgetItem *item = new QTreeWidgetItem(parentItem);
    item->setText(0,ui->lineEdit_node_create ->text());
    ui->treeWidget->setCurrentItem(item);

    std::string nodePath_children = item->text(0).toStdString();
    std::string nodeData_children = ui->textEdit_data->toPlainText().toStdString();
    int nodeDataLen = strlen(nodeData_children.c_str());
    // 创建节点
    int rc = zoo_create(zh, nodePath_children.c_str(), nodeData_children.c_str(), nodeDataLen, &ZOO_OPEN_ACL_UNSAFE, 0, NULL, 0);
    if (rc == ZOK) {
        qDebug() << "add " << item->text(0) << " success";
    } else {
        qDebug() << "zoo_create rc = " << rc;
    }

    //隐藏创建控件
    hideCreateWidget();
    showNodeInfoWidget();
}

void zookeeperwidget::on_toolButton_add_clicked()
{
    QString node = ui->treeWidget->currentItem()->text(0);
    addNode(node);
}

void zookeeperwidget::on_toolButton__delete_clicked()
{
    QString node = ui->treeWidget->currentItem()->text(0);
    deleteNode(node);
}

void zookeeperwidget::on_toolButton_refresh_clicked()
{
    QString node = ui->treeWidget->currentItem()->text(0);
    getNodeInfo(node);
    //getNodeData(node);
}

void zookeeperwidget::on_getAllChildren(QString path, const QVariant varValue, QTreeWidgetItem *item)
{
    String_vector children = varValue.value<String_vector>();
    for (int i = 0; i < children.count; ++i) {
           qDebug() << "children.data[i] = " << children.data[i];
//        QTreeWidgetItem *item2 = new QTreeWidgetItem(item);
//        QString children_path;
//        if (path != "/") {
//            children_path = QString::fromStdString(path.toStdString() + "/" + children.data[i]);

//        } else {
//            children_path = QString::fromStdString(path.toStdString() + children.data[i]);
//        }
//        item2->setText(0, children_path);
//        int32_t childrentNum = getNodeInfo(children_path);
//        if (childrentNum > 0) {
//            item2->setIcon(0, QIcon(":lib/node.png"));
//        } else {
//            item2->setIcon(0, QIcon(":lib/node2.png"));
//        }
    }
}
