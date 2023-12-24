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
#include <QStyleFactory>
#include <QThreadPool>
zookeeperwidget::zookeeperwidget(connnectInfoStruct& cInfoStruct, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::zookeeperwidget)
{
    ui->setupUi(this);
    hideCreateWidget();
    //隐藏修改按钮
    zh = nullptr;
    ui->toolButton_saveData->hide();
    isUnfold =false;
    ui->textEdit_data->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    //ui->treeWidget->setStyle((QStyleFactory::create("windows")));
    init(cInfoStruct.host, cInfoStruct.port);
    setMouseTracking(true);
}

zookeeperwidget::~zookeeperwidget()
{
    delete ui;
}

void zookeeperwidget::init(QString host, QString port)
{
    QString rootPath = "/";
    //ui->label_status->setText("程序会查找所有节点，根据节点数量，通常1分钟左右就搜索完毕");
    thread = new QThread();
    zookhandle = new zookeeperhandle();

    // 将对象移动到线程中
    zookhandle->moveToThread(thread);

    //初始化连接
    connect(zookhandle,SIGNAL(send_init(bool,int,QString,QString,QVariant,QString)),this,
                            SLOT(rece_init(bool,int,QString,QString,QVariant,QString)));

    connect(zookhandle,SIGNAL(send_getChildren(int,QString,QString,QVariant,QVector<QString>,QVector<int>,QTreeWidgetItem*)),this,
                            SLOT(rece_getChildren(int,QString,QString,QVariant,QVector<QString>,QVector<int>,QTreeWidgetItem*)));

    connect(zookhandle,SIGNAL(send_getNodeInfo_2(int,QString,QVariant,QString,QString)),this,
                            SLOT(rece_getNodeInfo_2(int,QString,QVariant,QString,QString)));

    connect(zookhandle,SIGNAL(send_createNode(int,QString,QString,QVariant,QString,QTreeWidgetItem*)),this,
                            SLOT(rece_createNode(int,QString,QString,QVariant,QString,QTreeWidgetItem*)));

    connect(zookhandle,SIGNAL(send_deleteNode(int,QString,QTreeWidgetItem*)),this,
                            SLOT(rece_deleteNode(int,QString,QTreeWidgetItem*)));
    thread->start();
    QMetaObject::invokeMethod(zookhandle,"init",Qt::QueuedConnection, Q_ARG(QString, rootPath), Q_ARG(QString,host), Q_ARG(QString,port));
}

void zookeeperwidget::rece_init(bool connected, int code, QString message, QString path, const QVariant varValue, QString data)
{
    //将数据回写ui
    thread2 = new QThread();
    zookhandle2 = new zookeeperhandle(zookhandle->zh);
    connect(zookhandle2,SIGNAL(send_getNodeInfo_2(int,QString,QVariant,QString,QString)),this,
                            SLOT(rece_getNodeInfo_2(int,QString,QVariant,QString,QString)));
    connect(zookhandle2,SIGNAL(send_getChildren(int,QString,QString,QVariant,QVector<QString>,QVector<int>,QTreeWidgetItem*)),this,
                            SLOT(rece_getChildren(int,QString,QString,QVariant,QVector<QString>,QVector<int>,QTreeWidgetItem*)));
    zookhandle2->moveToThread(thread2);
    thread2->start();

    thread3 = new QThread();
    zookhandle3 = new zookeeperhandle(zookhandle->zh);
    connect(zookhandle3,SIGNAL(send_getNodeInfo_2(int,QString,QVariant,QString,QString)),this,
                            SLOT(rece_getNodeInfo_2(int,QString,QVariant,QString,QString)));
    connect(zookhandle3,SIGNAL(send_getChildren(int,QString,QString,QVariant,QVector<QString>,QVector<int>,QTreeWidgetItem*)),this,
                            SLOT(rece_getChildren(int,QString,QString,QVariant,QVector<QString>,QVector<int>,QTreeWidgetItem*)));
    zookhandle3->moveToThread(thread3);
    thread3->start();

    thread4 = new QThread();
    zookhandle4 = new zookeeperhandle(zookhandle->zh);
    connect(zookhandle4,SIGNAL(send_getNodeInfo_2(int,QString,QVariant,QString,QString)),this,
                            SLOT(rece_getNodeInfo_2(int,QString,QVariant,QString,QString)));

    connect(zookhandle4,SIGNAL(send_getChildren(int,QString,QString,QVariant,QVector<QString>,QVector<int>,QTreeWidgetItem*)),this,
                            SLOT(rece_getChildren(int,QString,QString,QVariant,QVector<QString>,QVector<int>,QTreeWidgetItem*)));
    zookhandle4->moveToThread(thread4);
    thread4->start();

    thread5 = new QThread();
    zookhandle5 = new zookeeperhandle(zookhandle->zh);
    connect(zookhandle5,SIGNAL(send_getNodeInfo_2(int,QString,QVariant,QString,QString)),this,
                            SLOT(rece_getNodeInfo_2(int,QString,QVariant,QString,QString)));

    connect(zookhandle5,SIGNAL(send_getChildren(int,QString,QString,QVariant,QVector<QString>,QVector<int>,QTreeWidgetItem*)),this,
                            SLOT(rece_getChildren(int,QString,QString,QVariant,QVector<QString>,QVector<int>,QTreeWidgetItem*)));
    zookhandle5->moveToThread(thread5);
    thread5->start();

    ui->lineEdit_node->setText(path);
    //ui显示数据
    //showNodeInfo(data, varValue, path);
    Stat stat = varValue.value<Stat>();
    topItem = new QTreeWidgetItem(ui->treeWidget);
    ui->treeWidget->addTopLevelItem(topItem);
    topItem->setText(0, path);
    qDebug() << "rece_init stat.numChildren = " << stat.numChildren;
    //判断是否有子节点
    if (stat.numChildren > 0) {
        //获取子节点
        //auto pool = QThreadPool::globalInstance();
        //pool->setMaxThreadCount(8);					//设置最多8个线程
        //a->setAutoDelete(true);	//执行完后自动释放
        getChildren(path, topItem);
        //pool->start(a);
    }
}

void zookeeperwidget::getChildren(QString path, QTreeWidgetItem *item)
{
    qDebug() << "Main Thread ID:" << QThread::currentThreadId();
    if (threadSum %5 == 1) {
        qDebug() << "走1";
        QMetaObject::invokeMethod(zookhandle,"getChildren",Qt::QueuedConnection, Q_ARG(QString,path), Q_ARG(QTreeWidgetItem*, item));
    } else if (threadSum %5 == 2){
        qDebug() << "走2";
        QMetaObject::invokeMethod(zookhandle2,"getChildren",Qt::QueuedConnection, Q_ARG(QString,path), Q_ARG(QTreeWidgetItem*, item));
    } else if (threadSum %5 == 3){
        qDebug() << "走3";
        QMetaObject::invokeMethod(zookhandle3,"getChildren",Qt::QueuedConnection, Q_ARG(QString,path), Q_ARG(QTreeWidgetItem*, item));
    } else if (threadSum %5 == 4){
        qDebug() << "走4";
        QMetaObject::invokeMethod(zookhandle4,"getChildren",Qt::QueuedConnection, Q_ARG(QString,path), Q_ARG(QTreeWidgetItem*, item));
    } else if (threadSum %5 == 0){
        qDebug() << "走5";
        QMetaObject::invokeMethod(zookhandle5,"getChildren",Qt::QueuedConnection, Q_ARG(QString,path), Q_ARG(QTreeWidgetItem*, item));
    }
    qDebug() << "threadSum = " << threadSum;
    threadSum++;
    //QMetaObject::invokeMethod(zookhandle,"getChildren",Qt::QueuedConnection, Q_ARG(QString,path), Q_ARG(QTreeWidgetItem*, item));
}

void zookeeperwidget::rece_getChildren(int code, QString message, QString path, const QVariant varValue, QVector<QString> dataList, QVector<int> childrenList, QTreeWidgetItem *item)
{
    String_vector children = varValue.value<String_vector>();
    for (int i = 0; i < children.count; ++i) {
           //qDebug() << "children.data[i] = " << children.data[i];
        QTreeWidgetItem *item2 = new QTreeWidgetItem(item);
        QString children_path;
        if (path != "/") {
            children_path = QString::fromStdString(path.toStdString() + "/" + children.data[i]);

        } else {
            children_path = QString::fromStdString(path.toStdString() + children.data[i]);
        }
        item2->setText(0, children_path);
        //如果有数据，显示绿点，无数据，显示灰点
//        if (dataList[i].length() > 0) {
//            item2->setIcon(0, QIcon(":lib/node.png"));
//        } else {
//            item2->setIcon(0, QIcon(":lib/node2.png"));
//        }

        //如果有子节点继续请求
        if (childrenList[i] > 0) {
            //qDebug() << "getChildren children.data[i] = " << children_path;
            getChildren(children_path, item2);
        }
    }
    //展开
    isUnfold = true;
    ui->toolButton_unfold->setText("全部折叠");
    expandAllItems(ui->treeWidget, isUnfold, 0);
}

void zookeeperwidget::getNodeInfo(QString &path)
{
    QMetaObject::invokeMethod(zookhandle,"getNodeInfo_2",Qt::QueuedConnection, Q_ARG(QString,path));
}

void zookeeperwidget::rece_getNodeInfo_2(int code, QString message, QVariant varValue, QString data, QString path)
{
    //qDebug() << "rece_getNodeInfo_2 数据 = " << data;
    showNodeInfo(data, varValue, path);
}


void zookeeperwidget::showNodeInfo(QString data, QVariant varValue, QString path)
{
    Stat stat = varValue.value<Stat>();
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
    if (data.length() <= 0) {
        ui->label_data_type->setText("数据类型：NULL");
        ui->toolButton_copy_data->hide();
        return;
    }
    ui->toolButton_copy_data->show();
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

void zookeeperwidget::showNodeInfoWidget()
{
    ui->gridWidget_1_1_r->show();
}

void zookeeperwidget::hideNodeInfoWidget()
{
    ui->gridWidget_1_1_r->hide();
}

void zookeeperwidget::hideCreateWidget()
{
    ui->horizontalWidget_1_2_1_r->hide();
    ui->horizontalWidget_1_2_2_r->hide();
    ui->horizontalWidget_1_2_3_r->hide();
    ui->toolButton_createData->hide();
    ui->toolButton_saveData->hide();
}

void zookeeperwidget::showCreateWidget()
{
    ui->horizontalWidget_1_2_1_r->show();
    ui->horizontalWidget_1_2_2_r->show();
    ui->horizontalWidget_1_2_3_r->show();
    ui->toolButton_createData->show();
    ui->toolButton_saveData->hide();
}

void zookeeperwidget::addNode(QString &path)
{
    ui->textEdit_data->clear();
    QString rootPath = ui->treeWidget->currentItem()->text(0);
    if ( rootPath == "/") {
        ui->lineEdit_node_create->setText(rootPath + "newNode");
    } else {
        ui->lineEdit_node_create->setText(rootPath + "/newNode");
    }

    ui->lineEdit_node_create->setFocus();
    showCreateWidget();
    hideNodeInfoWidget();
}

void zookeeperwidget::deleteNode(QString &path)
{
    QTreeWidgetItem * item = ui->treeWidget->currentItem();
    QMetaObject::invokeMethod(zookhandle,"deleteNode",Qt::QueuedConnection, Q_ARG(QString,path), Q_ARG(QTreeWidgetItem*, item));
    //qDebug() << "delete";
}

void zookeeperwidget::copyPath()
{
    QTreeWidgetItem *item = ui->treeWidget->currentItem();
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(item->text(0));
}

void zookeeperwidget::showParent(QTreeWidgetItem *pItem)
{
    //判断当前节点是否存在
    if (pItem != nullptr) {
        QTreeWidgetItem* pTreeParentItem = pItem->parent(); //获取当前节点的父节点
        //判断父节点是否存在
        if (pTreeParentItem != nullptr) {
            pTreeParentItem->setHidden(false);  //将该父级索引项设置为显示
            showParent(pTreeParentItem);//直接传入处理过的节点
            //避免传入该节点后递归后跳转到祖父节点
        }
    }
}

void zookeeperwidget::showSon(QTreeWidgetItem *pItem)
{
    int iChild = pItem->childCount();  //获取该子节点的数目
    //遍历当前项的子节点并设置
    for (int i = 0; i < iChild; ++i) {
        pItem->child(i)->setHidden(false);
        showSon(pItem->child(i));//对当前 子项进行递归
    }
}

void zookeeperwidget::searchItem(QTreeWidgetItem *tableItem, const QString &strText)
{
    //防止野指针的问题
    if (tableItem != nullptr) {
        for (int i = 0; i < tableItem->childCount(); ++i) {
            QTreeWidgetItem* pTreeItem = tableItem->child(i);
            if (pTreeItem != nullptr) {
                //如何索引项字段部分匹配于输入框字段则设置该项及其父子项显示且展开
                if (pTreeItem->text(0).contains(strText)) {
                    pTreeItem->setHidden(false);
                    pTreeItem->setExpanded(true);
                    showSon(pTreeItem);
                    showParent(pTreeItem);
                } else {
                    pTreeItem->setHidden(true);//不匹配则隐藏
                    searchItem(pTreeItem, strText);//递归遍历
                }
            }
        }
    }
}

void zookeeperwidget::showItem(const QString &strText)
{
    for (int i = 0; i < ui->treeWidget->topLevelItemCount(); ++i) {
        if (ui->treeWidget->topLevelItem(i)->text(0).contains(strText)) {
            ui->treeWidget->topLevelItem(i)->setHidden(false);
        }else {
            ui->treeWidget->topLevelItem(i)->setHidden(true);
        }
        searchItem(ui->treeWidget->topLevelItem(i), strText);
    }
}

void zookeeperwidget::expandAllItems(QTreeWidget *treeWidget, bool isexpand, int sum)
{
    int topLevelItemCount = treeWidget->topLevelItemCount();
    for (int i = 0; i < topLevelItemCount; ++i) {
        QTreeWidgetItem* item = treeWidget->topLevelItem(i);
        expandItemAndChildren(item, isexpand, sum);
    }
}

void zookeeperwidget::expandItemAndChildren(QTreeWidgetItem *item, bool isexpand, int sum)
{
    if (sum >= 1) {
        return;
    }
    sum++;
    item->setExpanded(isexpand);
    int childCount = item->childCount();
//    for (int i = 0; i < childCount; ++i) {
//        QTreeWidgetItem* childItem = item->child(i);
//        expandItemAndChildren(childItem, isexpand, sum);
//    }
}

void zookeeperwidget::rece_deleteNode(int code, QString message, QTreeWidgetItem *item)
{
    if (code == 0) {
        QTreeWidgetItem *parentItem = item->parent();
        // 从父节点中删除子节点
        parentItem->removeChild(item);
        // 释放子节点的内存
        delete item;
        //指向当前父节点
        ui->treeWidget->setCurrentItem(parentItem);
        //显示父节点数据
        getNodeInfo(parentItem->text(0));
    }

}

void zookeeperwidget::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
    ui->lineEdit_node->setText(item->text(column));
    QString path = item->text(column);
    qDebug() << "获取节点信息";
    //getNodeInfo(path);
    QMetaObject::invokeMethod(zookhandle2,"getNodeInfo_2",Qt::QueuedConnection, Q_ARG(QString,path));
    //getChildren(path, item);
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
    //qDebug() << "nodeData = " << nodeData << "& nodeDataPath = " << nodeDataPath;
    if (nodeData != ui->textEdit_data->toPlainText() && nodeDataPath == ui->treeWidget->currentItem()->text(0)) {
        //qDebug() << "显示修改按钮";
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
        addNode(node);
    } else if (actionText == "刷新") {
        getNodeInfo(node);
    } else if (actionText == "删除") {
        deleteNode(node);
    } else if (actionText == "复制") {
        copyPath();
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
        //qDebug() <<"Failed to set node data. Error";
    } else {
        //qDebug() <<"Node data set successfully.";
        ui->toolButton_saveData->hide();
    }
}

void zookeeperwidget::on_toolButton_createData_clicked()
{
    QTreeWidgetItem* item = ui->treeWidget->currentItem();

    QString nodePath = ui->lineEdit_node_create->text();
    QString nodeData = ui->textEdit_data->toPlainText();

    QMetaObject::invokeMethod(zookhandle,"createNode",Qt::QueuedConnection, Q_ARG(QString,nodePath), Q_ARG(QString,nodeData), Q_ARG(QTreeWidgetItem*, item));

//    int nodeDataLen = strlen(nodeData_children.c_str());
//    // 创建节点
//    int rc = zoo_create(zh, nodePath_children.c_str(), nodeData_children.c_str(), nodeDataLen, &ZOO_OPEN_ACL_UNSAFE, 0, NULL, 0);
//    if (rc == ZOK) {
//        qDebug() << "add " << item->text(0) << " success";
//    } else {
//        qDebug() << "zoo_create rc = " << rc;
//    }

//    //隐藏创建控件
//    hideCreateWidget();
//    showNodeInfoWidget();
}

void zookeeperwidget::rece_createNode(int code, QString message, QString path, QVariant varValue, QString data, QTreeWidgetItem *item)
{
    if (code == 0) {
        //成功获取数据，创建子节点
        QTreeWidgetItem *item_children = new QTreeWidgetItem(item);
        item_children->setText(0, path);
        if (data.length() > 0) {
            item_children->setIcon(0, QIcon(":lib/node.png"));
        } else {
            item_children->setIcon(0, QIcon(":lib/node2.png"));
        }
        ui->treeWidget->setCurrentItem(item_children);
        //显示数据
        showNodeInfo(data, varValue, path);

        hideCreateWidget();
        showNodeInfoWidget();

    } else {
        //创建失败
    }
}


void zookeeperwidget::on_toolButton_add_clicked()
{
    QString node = ui->treeWidget->currentItem()->text(0);
    addNode(node);
}

void zookeeperwidget::on_toolButton_delete_clicked()
{
    QString node = ui->treeWidget->currentItem()->text(0);
    deleteNode(node);
}

void zookeeperwidget::on_toolButton_refresh_clicked()
{
    QString node = ui->treeWidget->currentItem()->text(0);
    getNodeInfo(node);
}

void zookeeperwidget::on_getAllChildren(QString path, const QVariant varValue, QTreeWidgetItem *item)
{
    String_vector children = varValue.value<String_vector>();
    for (int i = 0; i < children.count; ++i) {
           //qDebug() << "children.data[i] = " << children.data[i];
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

void zookeeperwidget::on_toolButton_copy_data_clicked()
{
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(ui->textEdit_data->toPlainText());
}

void zookeeperwidget::on_lineEdit_search_textChanged(const QString &arg1)
{
    showItem(arg1);
    expandAllItems(ui->treeWidget, true, 0);
}

void zookeeperwidget::on_toolButton_unfold_clicked()
{
    if (isUnfold) {
        //全部折叠
        isUnfold = false;
        ui->toolButton_unfold->setText("全部展开");
        expandAllItems(ui->treeWidget, isUnfold, 0);
    } else {
        //全部展开
        isUnfold = true;
        ui->toolButton_unfold->setText("全部折叠");
        expandAllItems(ui->treeWidget, isUnfold, 0);
    }
}

void zookeeperwidget::on_lineEdit_search_returnPressed()
{
    //回车也重新获取
    showItem(ui->lineEdit_search->text());
    expandAllItems(ui->treeWidget, true, 0);
}
