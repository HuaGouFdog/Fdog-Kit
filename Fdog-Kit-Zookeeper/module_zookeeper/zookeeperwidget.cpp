#pragma execution_character_set("utf-8")
#include <QDateTime>
#include <QString>
#include <QDebug>
#include <QJsonParseError>
#include <QMenu>
#include <QClipboard>
#include <QTest>
#include <QToolTip>
#include <QStyleFactory>
#include <QThreadPool>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include "zookeeperwidget.h"
#include "zookeeperhandle.h"
#include "zookeepertipswidget.h"
#include "ui_zookeeperwidget.h"
#include "module_utils/utils.h"
zookeeperwidget::zookeeperwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::zookeeperwidget), isUnfold(false)
{
    ui->setupUi(this);
    setSupportStretch(this, true);
    hideButton();
    hideCreateWidget(); //隐藏修改按钮
    

    ui->textEdit_data->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    threadpool.setMaxThreadCount(16);

    //设置水平滑动条
    QHeaderView *pHeader=ui->treeWidget->header();
    pHeader->setSectionResizeMode(QHeaderView::ResizeToContents);
    //pHeader->setStretchLastSection(false);

    ui->splitter->setStretchFactor(0, 5);
    ui->splitter->setStretchFactor(1, 1);
}

zookeeperwidget::zookeeperwidget(connnectInfoStruct& cInfoStruct, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::zookeeperwidget), isUnfold(false)
{
    ui->setupUi(this);  
    setMouseTracking(true);
    //QAction *action = new QAction(this);
    //action->setIcon(QIcon(":/lib/soucuo.png"));
    //ui->lineEdit_find->addAction(action,QLineEdit::LeadingPosition);
    //QAction *action2 = new QAction(this);
    //action2->setIcon(QIcon(":/lib/soucuo.png"));
    //ui->lineEdit_search->addAction(action2,QLineEdit::LeadingPosition);

    hideButton();
    hideCreateWidget(); //隐藏修改按钮
    

    ui->textEdit_data->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    threadpool.setMaxThreadCount(16);
    buttonSid = cInfoStruct.buttonSid;
    init(cInfoStruct.host, cInfoStruct.port, cInfoStruct.timeout);

    //设置水平滑动条
    QHeaderView *pHeader=ui->treeWidget->header();
    pHeader->setSectionResizeMode(QHeaderView::ResizeToContents);
    //pHeader->setStretchLastSection(false);

    //ui->scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    ui->splitter->setStretchFactor(0, 5);
    ui->splitter->setStretchFactor(1, 1);
}

zookeeperwidget::~zookeeperwidget()
{
    delete ui;
    threadpool.clear(); //停止所有线程调用
    delete zookhandle;

}

void zookeeperwidget::init(QString host, QString port, int timeout)
{
    qDebug() << "初始化";
    QString rootPath = "/";
    zookhandle = new zookeeperhandle(this, NULL);
    //初始化连接
    connect(zookhandle,SIGNAL(send_init(int,int,QString,QString,int)),this, SLOT(rece_init(int,int,QString,QString,int)));
    connect(zookhandle,SIGNAL(send_getChildren(int,QString,QString,QVariant,QTreeWidgetItem*)),this, SLOT(rece_getChildren(int,QString,QString,QVariant,QTreeWidgetItem*)));
    connect(zookhandle,SIGNAL(send_getNodeInfo(int,QString,QVariant,QString,QString)),this, SLOT(rece_getNodeInfo(int,QString,QVariant,QString,QString)));
    connect(zookhandle,SIGNAL(send_createNode(int,QString,QString,QVariant,QString,QTreeWidgetItem*)),this, SLOT(rece_createNode(int,QString,QString,QVariant,QString,QTreeWidgetItem*)));
    connect(zookhandle,SIGNAL(send_deleteNode(int,QString,QTreeWidgetItem*)),this, SLOT(rece_deleteNode(int,QString,QTreeWidgetItem*)));
    connect(zookhandle,SIGNAL(send_setNodeData(int,QString)),this, SLOT(rece_setNodeData(int,QString)));

    thread = new QThread();
    // 将对象移动到线程中
    zookhandle->moveToThread(thread);
    thread->start();
    QMetaObject::invokeMethod(zookhandle,"init",Qt::QueuedConnection, Q_ARG(QString, rootPath), Q_ARG(QString,host), Q_ARG(QString,port),Q_ARG(int, timeout));
}

void zookeeperwidget::rece_init(int connectState, int code, QString message, QString path, int count)
{
    if (connectState != ZOO_CONNECTED_STATE && code != ZOK) {
        showMessage("连接失败", true);
        emit send_init(buttonSid, code);
    } else {
        showMessage("连接成功", true);
        emit send_init(buttonSid, code);
        ui->lineEdit_node->setText(path);
        QTreeWidgetItem *topItem = new QTreeWidgetItem(ui->treeWidget);
        ui->treeWidget->addTopLevelItem(topItem);
        topItem->setText(0, path);
        topItem->setToolTip(0, path);
        qDebug() << "rece_init numChildren count= " << count;
        if (count > 0) {
            getChildren(path, topItem);
        }
    }
}

void zookeeperwidget::getChildren(QString path, QTreeWidgetItem *item)
{

    //qDebug() << "Main Thread ID:" << QThread::currentThreadId();
    ZkRunnable * m_pRunnable = new ZkRunnable(this, zookhandle->zh, path, item);
    threadpool.start(m_pRunnable);
}


void zookeeperwidget::rece_getChildren(int code, QString message, QString path, const QVariant varValue, QTreeWidgetItem *item)
{

    if (code != ZOK) {
        //调用失败
    } else {
        String_vector children = varValue.value<String_vector>();
        for (int i = 0; i < children.count; ++i) {
            //获取父节点信息

            QTreeWidgetItem *itemChild = new QTreeWidgetItem(item);
            QString children_path;
            if (path != "/") {
                //children_path = QString::fromStdString(path.toStdString() + "/" + children.data[i]);
                children_path = children.data[i];
            } else {
                //children_path = QString::fromStdString(path.toStdString() + children.data[i]);
                children_path = children.data[i];
            }
            itemChild->setText(0, children_path);
            itemChild->setToolTip(0, children_path);
            //qDebug() << "path = " << path;
            
            getParentNode(item, children_path);
            //qDebug() << "children_path = " << children_path;
            ZkRunnable * m_pRunnable = new ZkRunnable(this, zookhandle->zh, children_path, itemChild);
            threadpool.start(m_pRunnable);
        }
        isUnfold = true;
        //qDebug() << "这里调用展开节点";
        expandAllItemsOne(ui->treeWidget, isUnfold, 0);
    }
}

void zookeeperwidget::getNodeInfo(QString &path)
{
    QMetaObject::invokeMethod(zookhandle,"getNodeInfo",Qt::QueuedConnection, Q_ARG(QString,path));
}

void zookeeperwidget::rece_getNodeInfo(int code, QString message, QVariant varValue, QString data, QString path)
{
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
    nodeData = "";
    nodeDataPath = "";
    if (data.length() <= 0) {
        ui->label_data_type->setText("数据类型：NULL");
        ui->toolButton_copy_data->hide();
        nodeDataPath = path;
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
        //utils_parsingJsonInfo(ui->textEdit_data, data);
        ui->label_data_type->setText("数据类型：json");
    } else {
        ui->textEdit_data->insertPlainText(data.toUtf8());
        nodeData = data.toUtf8();
        nodeDataPath = path;
        ui->toolButton_saveData->setEnabled(false);
        ui->label_data_type->setText("数据类型：value");
    }
}

void zookeeperwidget::rece_setNodeData(int code, QString message)
{

    if (code != ZOK) {
        qDebug() <<"Failed to set node data. Error";
    } else {
        qDebug() <<"Node data set successfully.";
        ui->toolButton_saveData->hide();
        showMessage("更新数据成功", true);
    }
}

void zookeeperwidget::addNode(QString &path)
{
    ui->textEdit_data->clear();
    //QString rootPath = ui->treeWidget->currentItem()->text(0);
    if ( path == "/") {
        ui->lineEdit_node_create->setText(path + "newNode");
    } else {
        ui->lineEdit_node_create->setText(path + "/newNode");
    }
    ui->lineEdit_node_create->setFocus();
    //当前状态是创建
    isCreate = true;

    showCreateWidget();
    hideNodeInfoWidget();
}

void zookeeperwidget::rece_createNode(int code, QString message, QString path, QVariant varValue, QString data, QTreeWidgetItem *item)
{
    if (code == 0) {
        showMessage("创建节点成功", true);
        //成功获取数据，创建子节点
        //QTreeWidgetItem *item_children = new QTreeWidgetItem(item);
        //item_children->setText(0, path);
//        if (data.length() > 0) {
//            item_children->setIcon(0, QIcon(":lib/green.svg"));
//        } else {
//            item_children->setIcon(0, QIcon(":lib/node2.png"));
//        }
        //ui->treeWidget->setCurrentItem(item_children);
        //显示数据
        //showNodeInfo(data, varValue, path);

        hideCreateWidget();
        showNodeInfoWidget();

    } else {
        //创建失败
        showMessage("创建节点失败", false);
    }
    isCreate = false;
}

void zookeeperwidget::deleteNode(QString &path)
{
    //qDebug() << "delete节点" << path;
    //先删除zk，再处理本地
    QTreeWidgetItem* item = ui->treeWidget->currentItem();
    //循环删除
    deleteTreeNode(item);
    //显示父节点数据
    // QTreeWidgetItem *parent = ui->treeWidget->currentItem();
    // QString path2;
    // getParentNode(parent, path2);
    // getNodeInfo(path2);
    qDebug() << "deleteNode调用完成" << path;
}

void zookeeperwidget::rece_deleteNode(int code, QString message, QTreeWidgetItem *item)
{
    qDebug() << "调用rece_deleteNode";
    if (code == ZOK) {
        showMessage("删除节点成功", true);
        //deleteTreeItem(item);
    } else {
        qDebug() << "删除失败";
    }
}

void zookeeperwidget::copyPath()
{
    QTreeWidgetItem *item = ui->treeWidget->currentItem();
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(item->text(0));
}

void zookeeperwidget::showParent(QTreeWidgetItem *pItem)
{

    //pItem->setExpanded(true);
    if (pItem != nullptr) {
        QTreeWidgetItem* pTreeParentItem = pItem->parent();
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
                if (pTreeItem->text(0).contains(strText, ui->toolButton_sensitive->isChecked()?Qt::CaseSensitive:Qt::CaseInsensitive)) {
                    //pTreeItem->setHidden(false);
                    //pTreeItem->setExpanded(true);

                    QString url;
                    getParentNode(pTreeItem, url);
                    //ui->lineEdit_node->setText(item->text(column));
                    //qDebug() << "找到path2 = " << url;
                    ui->listWidget->addItem(url);
                    ui->stackedWidget->setCurrentIndex(1);
                    showSon(pTreeItem);
                    showParent(pTreeItem);
                } else {
                    //pTreeItem->setHidden(true);//不匹配则隐藏
                }
                searchItem(pTreeItem, strText);//递归遍历
            }
        }
    }
}

void zookeeperwidget::showItem(const QString &strText)
{
    for (int i = 0; i < ui->treeWidget->topLevelItemCount(); ++i) {
        if (ui->treeWidget->topLevelItem(i)->text(0).contains(strText, ui->toolButton_sensitive->isChecked()?Qt::CaseSensitive:Qt::CaseInsensitive)) {
            //ui->treeWidget->topLevelItem(i)->setHidden(false);
            qDebug() << "找到path1 = " << ui->treeWidget->topLevelItem(i)->text(0);
            ui->stackedWidget->setCurrentIndex(1);
        }else {
            //ui->treeWidget->topLevelItem(i)->setHidden(true);
        }
        searchItem(ui->treeWidget->topLevelItem(i), strText);
    }
}

void zookeeperwidget::expandAllItems(QTreeWidget *treeWidget, bool isexpand, int sum)
{
    qDebug() << "expandAllItems 调用展开节点";
    int topLevelItemCount = treeWidget->topLevelItemCount();
    for (int i = 0; i < topLevelItemCount; ++i) {
        QTreeWidgetItem* item = treeWidget->topLevelItem(i);
        expandItemAndChildren(item, isexpand, sum);
    }
}

void zookeeperwidget::expandItemAndChildren(QTreeWidgetItem *item, bool isexpand, int sum)
{
    sum++;
    item->setExpanded(isexpand);
    int childCount = item->childCount();
   for (int i = 0; i < childCount; ++i) {
       QTreeWidgetItem* childItem = item->child(i);
       expandItemAndChildren(childItem, isexpand, sum);
   }
}

void zookeeperwidget::expandAllItemsOne(QTreeWidget *treeWidget, bool isexpand, int sum)
{
    if (isFirst) {
        qDebug() << "expandAllItemsOne 调用展开节点";
        int topLevelItemCount = treeWidget->topLevelItemCount();
        for (int i = 0; i < topLevelItemCount; ++i) {
            QTreeWidgetItem* item = treeWidget->topLevelItem(i);
            expandItemAndChildrenOne(item, isexpand, sum);
        }
        isFirst = false;
    }

}

void zookeeperwidget::expandItemAndChildrenOne(QTreeWidgetItem *item, bool isexpand, int sum)
{
    if (sum >= 1) {
        return;
    }
    sum++;
    item->setExpanded(isexpand);
    int childCount = item->childCount();
   for (int i = 0; i < childCount; ++i) {
       QTreeWidgetItem* childItem = item->child(i);
       expandItemAndChildrenOne(childItem, isexpand, sum);
   }
}

void zookeeperwidget::expandSelectItems(QTreeWidget *treeWidget, QString& path, QString& pathAll)
{
    //展开选中节点
   for (int i = 0; i < ui->treeWidget->topLevelItemCount(); ++i) {
       if (ui->treeWidget->topLevelItem(i)->text(0).contains(path, ui->toolButton_sensitive->isChecked()?Qt::CaseSensitive:Qt::CaseInsensitive)) {
           qDebug() << "找到path1 = " << ui->treeWidget->topLevelItem(i)->text(0);
           //顶层，什么都不做，选中就行
       }
       expandSelectItems_s(ui->treeWidget->topLevelItem(i), path, pathAll);
   }
}

void zookeeperwidget::expandSelectItems_s(QTreeWidgetItem *tableItem, const QString &path, QString& pathAll)
{
    //防止野指针的问题
    if (tableItem != nullptr) {
        for (int i = 0; i < tableItem->childCount(); ++i) {
            QTreeWidgetItem* pTreeItem = tableItem->child(i);
            if (pTreeItem != nullptr) {
                //如何索引项字段部分匹配于输入框字段则设置该项及其父子项显示且展开
                if (pTreeItem->text(0).contains(path, ui->toolButton_sensitive->isChecked()?Qt::CaseSensitive:Qt::CaseInsensitive)) {
                    //节点名会重复，还要判断前面的
                    QString url;
                    getParentNode(pTreeItem, url);
                    if (url == pathAll) {
                        qDebug() << "找到path4 = " << path << " 完整路径：" << pathAll;
                        ui->treeWidget->setCurrentItem(pTreeItem);
                        on_treeWidget_itemClicked(pTreeItem, 0);
                        showParent2(pTreeItem);
                        return;
                    }
                } else {
                    //qDebug() << "找不到" << pTreeItem->text(0);
                }
                expandSelectItems_s(pTreeItem, path, pathAll);//递归遍历
            }
        }
    }
}

void zookeeperwidget::showParent2(QTreeWidgetItem *pItem)
{
    if (pItem != nullptr) {
        QTreeWidgetItem* pTreeParentItem = pItem->parent();
        if (pTreeParentItem != nullptr) {
            pTreeParentItem->setHidden(false);  //将该父级索引项设置为显示
            pItem->setExpanded(true);
            qDebug() << "展开" << pTreeParentItem->text(0);
            showParent2(pTreeParentItem);//直接传入处理过的节点
            //避免传入该节点后递归后跳转到祖父节点
        } else {
             qDebug() << "到达顶层";
        }
    }
}

void zookeeperwidget::deleteTreeNode(QTreeWidgetItem* item)
{

    if (!item) {
        return;
    }
    // 递归删除子节点
    // while (item->childCount() > 0) {
    //     qDebug() << "item->childCount() " << item->childCount() << " item->child(0) =" << item->child(0)->text(0);
    //     deleteTreeNode(item->child(0));
    // }
    int count = item->childCount();
    for (int i = 0; i < count; i++){
        qDebug() << "item->childCount() " << item->childCount() << " item->child(i) =" << item->child(i)->text(0);
        deleteTreeNode(item->child(i));
    }

    QString path;
    getParentNode(item, path);
    qDebug() << "调用deleteNode删除节点 " << path;
    // QTreeWidgetItem* parent = NULL;
    // parent= item->parent();
    // if (parent != NULL) {
    //     parent->removeChild(item);
    //     ui->treeWidget->setCurrentItem(parent);
    // } else {
    //     delete item;
    // }
    
    QMetaObject::invokeMethod(zookhandle,"deleteNode",Qt::QueuedConnection, Q_ARG(QString,path), Q_ARG(QTreeWidgetItem*, item));
}

void zookeeperwidget::deleteTreeItem(QTreeWidgetItem *item)
{
    if (!item) {
        return;
    }
    // 递归删除子节点
    while (item->childCount() > 0) {
        deleteTreeItem(item->child(0));
    }
    QString path = item->text(0);
    // 从父节点中移除该子节点
    QTreeWidgetItem* parent = NULL;
    parent= item->parent();
    if (parent != NULL) {
        parent->removeChild(item);
        ui->treeWidget->setCurrentItem(parent);
        //显示父节点数据
        getNodeInfo(parent->text(0));
    } else {
        delete item;
    }
}

void zookeeperwidget::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
    ui->toolButton_have_data->setIcon(QIcon(":lib/grey.svg"));
    QString url;// = item->text(column);
    getParentNode(item, url);
    //ui->lineEdit_node->setText(item->text(column));
    if (ui->checkBox_auto_url->isChecked()) {
        //QString url = item->text(column);
        QString decodedUrl = QUrl::fromPercentEncoding(url.toUtf8());
        ui->lineEdit_node->setText(decodedUrl);
    } else {
        ui->lineEdit_node->setText(url);
    }
    QString path = url;
    qDebug() << "on_treeWidget_itemClicked path = " << path;
    getNodeInfo(path);
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
    qDebug() << "nodeData = " << nodeData << ", nodeDataPath = " << nodeDataPath;
    QTreeWidgetItem * currentItem = ui->treeWidget->currentItem();
    if (currentItem == NULL) {
        //说明没有点过节点，不加判断会崩溃
    } else if (!isCreate) {
        QString path;
        getParentNode(currentItem, path);
        qDebug() << "当前数据1=" << ui->textEdit_data->toPlainText() << "  当前数据2=" << path;
        if (nodeData != ui->textEdit_data->toPlainText() && nodeDataPath == path) {
            qDebug() << "显示修改按钮";
            ui->toolButton_saveData->show();
            ui->toolButton_saveData->setEnabled(true);
        } else {
            ui->toolButton_saveData->hide();
            ui->toolButton_saveData->setEnabled(false);
        }
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
    popMenu->setWindowFlags(popMenu->windowFlags()  | Qt::FramelessWindowHint | Qt::NoDropShadowWindowHint);
    popMenu->setAttribute(Qt::WA_TranslucentBackground);
    popMenu->addAction(m_action_add);
    //popMenu->addSeparator();
    popMenu->addAction(m_action_copy);
    //popMenu->addSeparator();
    //popMenu->addAction(m_action_refresh);
    popMenu->addAction(m_action_delete);

    connect(m_action_add, SIGNAL(triggered()), this, SLOT(on_nodeAction()));
    //connect(m_action_refresh, SIGNAL(triggered()), this, SLOT(on_nodeAction()));
    connect(m_action_delete, SIGNAL(triggered()), this, SLOT(on_nodeAction()));
    connect(m_action_copy, SIGNAL(triggered()), this, SLOT(on_nodeAction()));
    popMenu->exec(QCursor::pos());//弹出右键菜单，菜单位置为光标位置
}

void zookeeperwidget::on_nodeAction()
{
    QString actionText = qobject_cast<QAction*>(sender())->text();
    QString node;
    getParentNode(ui->treeWidget->currentItem(), node);
    //qDebug() << "node = " << node;
    if (actionText == "添加") {
        addNode(node);
    } else if (actionText == "删除") {
        deleteNode(node);
    } else if (actionText == "复制") {
        copyPath();
    }
}

void zookeeperwidget::on_toolButton_saveData_clicked()
{
    QString nodePath;
    getParentNode(ui->treeWidget->currentItem(), nodePath);
    QString nodeData = ui->textEdit_data->toPlainText();
    QMetaObject::invokeMethod(zookhandle,"setNodeData",Qt::QueuedConnection, Q_ARG(QString, nodePath), Q_ARG(QString, nodeData));
}

void zookeeperwidget::on_toolButton_createData_clicked()
{
    QTreeWidgetItem* item = ui->treeWidget->currentItem();

    QString nodePath = ui->lineEdit_node_create->text();
    QString nodeData = ui->textEdit_data->toPlainText();
    qDebug() << "addNode " << nodePath;
    QMetaObject::invokeMethod(zookhandle,"createNode",Qt::QueuedConnection, Q_ARG(QString,nodePath), Q_ARG(QString,nodeData), Q_ARG(QTreeWidgetItem*, item));
}


void zookeeperwidget::on_toolButton_add_clicked()
{
    QString node = ui->treeWidget->currentItem()->text(0);
    addNode(node);
}

// void zookeeperwidget::on_toolButton_delete_clicked()
// {
//     QString node = ui->treeWidget->currentItem()->text(0);
//     deleteNode(node);
// }

void zookeeperwidget::on_toolButton_refresh_clicked()
{
    QString node = ui->treeWidget->currentItem()->text(0);
    getNodeInfo(node);
}

void zookeeperwidget::on_toolButton_copy_data_clicked()
{
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(ui->textEdit_data->toPlainText());
    showMessage("复制成功", true);
}

void zookeeperwidget::on_lineEdit_search_textChanged(const QString &arg1)
{
    ui->listWidget->clear();
    ui->stackedWidget->setCurrentIndex(0);
    if (arg1 != "") {
        showItem(arg1);
        //expandAllItems(ui->treeWidget, true, 0);
    } else {
        isUnfold = false;
        //expandAllItems(ui->treeWidget, false, 0);
        expandAllItemsOne(ui->treeWidget, true, 0);
    }
}

void zookeeperwidget::on_toolButton_unfold_clicked()
{
    isUnfold = false;
    ui->toolButton_unfold->setText("全部折叠");
    expandAllItems(ui->treeWidget, isUnfold, 0);
}

void zookeeperwidget::on_lineEdit_search_returnPressed()
{
    //回车也重新获取
    if(ui->lineEdit_search->text() == "") {
    isUnfold = false;
    expandAllItems(ui->treeWidget, false, 0);
    expandAllItemsOne(ui->treeWidget, true, 0);
    } else {
        showItem(ui->lineEdit_search->text());
        expandAllItems(ui->treeWidget, true, 0);
    }

}

void zookeeperwidget::rece_children_event(int code, QString message, QString path, const QVariant varValue)
{
    //孩子节点数据发生变化
    QStringList pathList = path.split("/");
    //遍历treewidget 查找 path 的子节点，有没有没存在的
    //获取节点层级
    QString path2 = pathList.at(pathList.length()-1);
    if (path == "/") {
        path2 = path;
    }
    qDebug() << "rece_children_event 接收到数据" << path << "最后面分级path = " << path2;
    QList<QTreeWidgetItem*> items = ui->treeWidget->findItems(path2, Qt::MatchExactly|Qt::MatchRecursive, 0);
    for(int i =0; i < items.length(); i++) {
        QString path_;
        getParentNode(items[i], path_);
        if (path_ == path) {
            qDebug() << "找到" << path2 << ", 对应父节点" << path_;
            QTreeWidgetItem * item = items[i];
            String_vector children = varValue.value<String_vector>();
            for (int i = 0; i < children.count; ++i) {
                QString children_path;
                children_path = children.data[i];
                QString path3 = children_path;
                getParentNode(item, path3);
                qDebug() << "rece_children_event path = " << path << ", children_path = " << children_path << ", path3 = " << path3;
                //下面这种不对，只需要查看子节点是否存在
                //不能简单查找子节点，只要父节点不一样就可以创建
                QList<QTreeWidgetItem*> items_c = ui->treeWidget->findItems(children_path, Qt::MatchExactly|Qt::MatchRecursive, 0);
                if (items_c.isEmpty()) {
                    qDebug() << "未找到，创建这个值" << children_path;
                    QTreeWidgetItem *itemChild = new QTreeWidgetItem(item);
                    itemChild->setText(0, children_path);
                    itemChild->setToolTip(0, children_path);
                    QMetaObject::invokeMethod(zookhandle,"getSingleChildren",Qt::QueuedConnection, Q_ARG(QString,path3),Q_ARG(void*,this));
                } else {
                    bool isok = true;
                    for(int i =0; i < items_c.length(); i++) {
                        QString path_;
                        getParentNode(items_c[i], path_);
                        if (path_ == path3) {
                            //qDebug() << "已经存在" << children_path << " path3 = " << path3;
                            isok = false;
                            break;
                        }
                    }
                     if(isok) {
                            qDebug() << "未找到，创建这个值" << children_path << " path3 = " << path3 << " path_ = " << path_;
                            QTreeWidgetItem *itemChild = new QTreeWidgetItem(item);
                            itemChild->setText(0, children_path);
                            itemChild->setToolTip(0, children_path);
                            QMetaObject::invokeMethod(zookhandle,"getSingleChildren",Qt::QueuedConnection, Q_ARG(QString,path3),Q_ARG(void*,this));
                        }
                }

            }
        } else {
            qDebug() << "只是子节点相同，过滤";
        }
    }
    if (items.isEmpty()) {
        qDebug() << "项为空 (节点可能被删除，正常)";
    }



    // if (!items.isEmpty()) {
    //     QTreeWidgetItem * item = items.first();
    //     String_vector children = varValue.value<String_vector>();
    //     for (int i = 0; i < children.count; ++i) {
    //         QString children_path;
    //         children_path = children.data[i];
    //         QString path3 = children_path;
    //         getParentNode(item, path3);
    //         qDebug() << "rece_children_event path = " << path << ", children_path = " << children_path;
    //         //不能简单查找子节点，只要父节点不一样就可以创建
    //         QList<QTreeWidgetItem*> items_c = ui->treeWidget->findItems(children_path, Qt::MatchExactly|Qt::MatchRecursive, 0);
    //         if (items_c.isEmpty()) {
    //             qDebug() << "未找到，创建这个值" << children_path;
    //             QTreeWidgetItem *itemChild = new QTreeWidgetItem(item);
    //             itemChild->setText(0, children_path);
    //             itemChild->setToolTip(0, children_path);
    //             QMetaObject::invokeMethod(zookhandle,"getSingleChildren",Qt::QueuedConnection, Q_ARG(QString,path3),Q_ARG(void*,this));
    //         }
    //     }
    // } else{
    //     qDebug() << "项为空 (节点可能被删除，正常)";
    // }
}

void zookeeperwidget::rece_create_event(QString path)
{
    //节点被创建
}

void zookeeperwidget::rece_delete_event(int code, QString message, QString path)
{
    //节点被删除
    QStringList pathList = path.split("/");
    //遍历treewidget 查找 path 的子节点，有没有没存在的
    //获取节点层级
    QString path2 = pathList.at(pathList.length()-1);
    if (path == "/") {
        path2 = path;
    }
    qDebug() << "删除事件，删除" << path << ", 最后面分级path = " << path2;

    QList<QTreeWidgetItem*> items = ui->treeWidget->findItems(path2, Qt::MatchExactly|Qt::MatchRecursive, 0);
    //这里有问题，不能简单判path2，还要看前面path是否与被删除一致
    if (!items.isEmpty()) {
        for(int i =0; i < items.length(); i++) {
            QString path_;
            getParentNode(items[i], path_);
            if (path_ == path) {
                qDebug() << "删除" << path2 << ", 对应父节点" << path_;
                QTreeWidgetItem* parent = NULL;
                parent= items[i]->parent();
                if (parent != NULL) {
                    parent->removeChild(items[i]);
                    ui->treeWidget->setCurrentItem(parent);
                    //显示父节点数据
                    getNodeInfo(parent->text(i));
                } else {
                    delete items[i];
                }
            } else {
                qDebug() << "只是子节点相同，过滤" << path_;
            }
        }
    }
}

void zookeeperwidget::rece_chanage_event(int code, QString message, QString path)
{
    qDebug() << "节点变化" << path;
    //节点数据被改变
    //判断当前数据变化的节点是否属于当前展示节点，若不是，则忽略
    QString path_;
    getParentNode(ui->treeWidget->currentItem(), path_);
    ui->treeWidget->currentItem()->text(0);
    qDebug() << "节点变化" << path << " "<<  path_;
    if (path_ == path && ui->checkBox_auto->isChecked()) {
        //获取节点信息
        getNodeInfo(path);
        ui->toolButton_have_data->setIcon(QIcon(":lib/grey.svg"));
    } else {
        ui->toolButton_have_data->setIcon(QIcon(":lib/green.svg"));
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
    ui->toolButton_cancel->hide();
}

void zookeeperwidget::showCreateWidget()
{
    ui->horizontalWidget_1_2_1_r->show();
    ui->horizontalWidget_1_2_2_r->show();
    ui->horizontalWidget_1_2_3_r->show();
    ui->toolButton_createData->show();
    ui->toolButton_saveData->hide();
    ui->toolButton_cancel->show();
    setSupportStretch(this, true);
}

//void zookeeperwidget::hideCreateZkWidget()
//{
//    ui->widget_create_zk->hide();
//}

//void zookeeperwidget::showCreateZkWidget()
//{
//    ui->widget_create_zk->show();
//}

void zookeeperwidget::hideButton()
{
    //ui->toolButton_add->hide();
    //ui->toolButton__delete->hide();
    //ui->toolButton_refresh->hide();
}

void zookeeperwidget::showMessage(QString message, bool isSuccess)
{
    if (tipwidget == nullptr) {
        tipwidget = new zookeepertipswidget(ui->treeWidget, message, isSuccess);
    } else {
        return;
    }
    //QPoint globalPos = ui->treeWidget->mapToGlobal(QPoint(0,0));//父窗口绝对坐标
    int x = (ui->treeWidget->width() - tipwidget->width()) / 2;     //x坐标
    int y = ui->treeWidget->height() - tipwidget->height() - 10;         //y坐标
    tipwidget->move(x, y);//窗口移动
    tipwidget->show();
    QPropertyAnimation *pAnimation = new QPropertyAnimation(tipwidget, "windowOpacity");
    QObject::connect(pAnimation, &QPropertyAnimation::finished, [=]()
    {
        tipwidget->close();
        tipwidget = nullptr;
    });
    pAnimation->setDuration(1500);
    pAnimation->setStartValue(1);
    pAnimation->setEndValue(0);
    pAnimation->setEasingCurve(QEasingCurve::InOutQuad);
    pAnimation->start(QAbstractAnimation::DeleteWhenStopped);
}

void zookeeperwidget::getParentNode(QTreeWidgetItem *item, QString &data) {
    QTreeWidgetItem *item_p = NULL;
    item_p = item->parent();
    if (item_p != NULL) {
        //qDebug() << "有父节点" << data;
        if (data == "") {
            data = item->text(0);
        } else {
            data = item->text(0) + "/" + data;
        }
        getParentNode(item_p, data);

    } else {
        if (data == "") {
            data = item->text(0);
        } else {
            data = "/"+ data;
        }
    }
    return;
}

// void zookeeperwidget::on_toolButton_6_clicked()
// {
//     zookeepertipswidget * a = new zookeepertipswidget(NULL, "1", true);
//     QPoint globalPos = ui->treeWidget->mapToGlobal(QPoint(0,0));//父窗口绝对坐标
//     int x = globalPos.x() + (ui->treeWidget->width() - a->width()) / 2;//x坐标
//     int y = globalPos.y() + ui->treeWidget->height() - a->height() - 20;//y坐标
//     a->move(x, y);//窗口移动
//     a->show();
//     QPropertyAnimation *pAnimation = new QPropertyAnimation(a, "windowOpacity");

//     QObject::connect(pAnimation, &QPropertyAnimation::finished, [=]()
//     {
//         a->close();
//     });
//     pAnimation->setDuration(2000);
//     pAnimation->setStartValue(1);
//     pAnimation->setEndValue(0);
//     pAnimation->setEasingCurve(QEasingCurve::InOutQuad);
//     pAnimation->start(QAbstractAnimation::DeleteWhenStopped);
// }

void zookeeperwidget::on_treeWidget_itemEntered(QTreeWidgetItem *item, int column)
{
//    if (item->toolTip(column).isEmpty()){
//        return; // 如果该项没有设置Tooltip，则不显示
//    }
//    QToolTip::showText(QCursor::pos(), item->toolTip(column));
}

//void zookeeperwidget::on_toolButton_3_clicked()
//{
//    showCreateZkWidget();
//}

//void zookeeperwidget::on_toolButton_save_clicked()
//{
//    //创建信息
//    QString data = ui->lineEdit_host_zk_data->text() + ":" + ui->lineEdit_port_zk_data->text();
//    QToolButton * qbutton = new QToolButton(this);
//    qbutton->setIcon(QIcon(":lib/node2.png"));
//    qbutton->setText(data);
//    qbutton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
//    qbutton->setMinimumHeight(30);
//    qbutton->setMinimumWidth(180);
//    QVBoxLayout *layout = (QVBoxLayout *)ui->scrollAreaWidgetContents->layout();
//    layout->insertWidget(layout->count()-1, qbutton);
//}

void zookeeperwidget::on_checkBox_auto_url_clicked()
{
    if (ui->checkBox_auto_url->isChecked()) {
        QString url = ui->lineEdit_node->text();
        QString decodedUrl = QUrl::fromPercentEncoding(url.toUtf8());
        ui->lineEdit_node->setText(decodedUrl);
    }
}

void zookeeperwidget::on_toolButton_clear_clicked()
{
    ui->lineEdit_search->clear();
}

void zookeeperwidget::on_toolButton_sensitive_clicked()
{

}

void zookeeperwidget::on_toolButton_cancel_clicked()
{
    //取消
    showNodeInfoWidget();
    hideCreateWidget();
}

void zookeeperwidget::on_textEdit_data_customContextMenuRequested(const QPoint &pos)
{
    //菜单请求
    m_action_text_undo = new QAction("撤销", this);
    m_action_text_redo = new QAction("重做", this);
    m_action_text_copy = new QAction("复制", this);
    m_action_text_paste = new QAction("粘贴", this);
    m_action_text_delete = new QAction("删除", this);
    m_action_text_allSelect = new QAction("全部选中", this);

    m_action_text_undo->setIconVisibleInMenu(false);
    m_action_text_redo->setIconVisibleInMenu(false);
    m_action_text_copy->setIconVisibleInMenu(false);
    m_action_text_paste->setIconVisibleInMenu(false);
    m_action_text_delete->setIconVisibleInMenu(false);
    m_action_text_allSelect->setIconVisibleInMenu(false);

    //定义右键弹出菜单
    textMenu = new QMenu(this);
    textMenu->setWindowFlags(textMenu->windowFlags()  | Qt::FramelessWindowHint | Qt::NoDropShadowWindowHint);
    textMenu->setAttribute(Qt::WA_TranslucentBackground);
    textMenu->addAction(m_action_text_undo);
    textMenu->addAction(m_action_text_redo);
    textMenu->addAction(m_action_text_copy);
    textMenu->addAction(m_action_text_paste);
    textMenu->addAction(m_action_text_delete);
    textMenu->addAction(m_action_text_allSelect);
    textMenu->exec(QCursor::pos());//弹出右键菜单，菜单位置为光标位置
}

void zookeeperwidget::resizeEvent(QResizeEvent *event)
{
    if (tipwidget != nullptr) {
        int x = (ui->treeWidget->width() - tipwidget->width()) / 2;     //x坐标
        int y = ui->treeWidget->height() - tipwidget->height() - 10;    //y坐标
        tipwidget->move(x, y);//窗口移动
        tipwidget->show();
    }

}

void zookeeperwidget::on_toolButton_copy_node_clicked()
{
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(ui->lineEdit_node->text());
    showMessage("复制成功", true);
}

void zookeeperwidget::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    int index = item->text().lastIndexOf("/");
    //对选中内容进行定位
    qDebug() << "选中数据为" << item->text().mid(index + 1);
    expandSelectItems(ui->treeWidget, item->text().mid(index + 1), item->text());
    ui->stackedWidget->setCurrentIndex(0);
}
