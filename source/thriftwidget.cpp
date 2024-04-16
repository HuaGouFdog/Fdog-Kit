#pragma execution_character_set("utf-8")
#include "thriftwidget.h"
#include "ui_thriftwidget.h"
#include <QPushButton>
#include <QStyleFactory>
#include <array>
#include <sstream>
#include <iomanip>
#include <QTcpSocket>
#include <QtEndian>
#include <QDebug>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <WinSock2.h>
#include <QListView>
#include <QElapsedTimer>
#include <QMenu>
#include <QFileDialog>
#include <cstdlib>
#pragma comment(lib, "ws2_32.lib")


static bool isAuto = true;

#define THRIFT_MESSAGE_LENGTH               1001
#define THRIFT_MESSAGE_TYPE_CALL            1002
#define THRIFT_MESSAGE_TYPE_REPLY           1003
#define THRIFT_MESSAGE_TYPE_EXCEPTION       1004
#define THRIFT_MESSAGE_TYPE_ONEWAY          1005
#define THRIFT_FUNC_LENGTH                  1006
#define THRIFT_FUNC_NAME                    1007
#define THRIFT_SN                           1008
#define THRIFT_BOOL                         1009           
#define THRIFT_BYTE                         1010
#define THRIFT_I16                          1011
#define THRIFT_I32                          1012
#define THRIFT_I64                          1013
#define THRIFT_DOUBLE                       1014
#define THRIFT_STRING                       1015
#define THRIFT_STRUCT                       1016
#define THRIFT_MAP                          1017
#define THRIFT_SET                          1018
#define THRIFT_LIST                         1019
#define THRIFT_END                          1020
#define THRIFT_START                        1021
#define THRIFT_VALUE                        1022
#define THRIFT_VALUE_SN                     1023
QMap<QString, int> sourceTypeMap {
    {"02", THRIFT_BOOL},
    {"03", THRIFT_BYTE},
    {"06", THRIFT_I16},
    {"08", THRIFT_I32},
    {"0a", THRIFT_I64},
    {"04", THRIFT_DOUBLE},
    {"0b", THRIFT_STRING},
    {"0c", THRIFT_STRUCT},
    {"0d", THRIFT_MAP},
    {"0e", THRIFT_SET},
    {"0f", THRIFT_LIST},
    {"00", THRIFT_END},
    {"00", THRIFT_START},
};

QMap<int, QColor *> sourceColorMap {
    {THRIFT_MESSAGE_LENGTH, new QColor(255,115,115)}, 
    {THRIFT_MESSAGE_TYPE_CALL, new QColor(255, 170, 0)}, 
    {THRIFT_MESSAGE_TYPE_REPLY, new QColor(255, 170, 0)},
    {THRIFT_MESSAGE_TYPE_EXCEPTION, new QColor(255, 170, 0)}, 
    {THRIFT_MESSAGE_TYPE_ONEWAY, new QColor(255, 170, 0)},
    {THRIFT_FUNC_LENGTH, new QColor(255,170,130)}, 
    {THRIFT_FUNC_NAME, new QColor(80,80,80)},
    {THRIFT_SN, new QColor(85,0,130)}, 
    {THRIFT_BOOL, new QColor(0,85,0)},
    {THRIFT_BYTE, new QColor(80,10,10)}, 
    {THRIFT_I16, new QColor(0,170,255)}, 
    {THRIFT_I32, new QColor(255,0,255)}, 
    {THRIFT_I64, new QColor(0,160,150)}, 
    {THRIFT_DOUBLE, new QColor(0,0,130)}, 
    {THRIFT_STRING, new QColor(170,170,0)}, 
    {THRIFT_STRUCT, new QColor(0,85,255)}, 
    {THRIFT_MAP, new QColor(85,0,255)}, 
    {THRIFT_SET, new QColor(255,115,0)}, 
    {THRIFT_LIST, new QColor(85,170,130)}, 
    {THRIFT_END, new QColor(0,0,0)},
    {THRIFT_START, new QColor(0,0,0)},
    {THRIFT_VALUE, new QColor(255, 0, 0)},
    {THRIFT_VALUE_SN, new QColor(0, 170, 0)},
};


ItemWidget::ItemWidget(QTreeWidget *parent) : QTreeWidgetItem(parent, 1)
{
    //qDebug() << "走ItemWidget(QTreeWidget *parent)";
    init();
    
    parent->setItemWidget(this, 0, widgetParamSN);
    parent->setItemWidget(this, 1, widgetParamName);
    parent->setItemWidget(this, 2, widgetParamType);
    parent->setItemWidget(this, 3, widgetParamValue);
}

ItemWidget::ItemWidget(QTreeWidgetItem *parent): QTreeWidgetItem(parent, 1)
{
    //qDebug() << "走ItemWidget(QTreeWidgetItem *parent)";
    init();
    treeWidget()->setItemWidget(this, 0, widgetParamSN);
    treeWidget()->setItemWidget(this, 1, widgetParamName);
    treeWidget()->setItemWidget(this, 2, widgetParamType);
    treeWidget()->setItemWidget(this, 3, widgetParamValue);
}

ItemWidget::ItemWidget(): QTreeWidgetItem()
{
    init();
    //qDebug() << "走ItemWidget()";
}

void ItemWidget::init()
{
    comboBoxBase = new QComboBox();
    comboBoxBase->addItem("i64");
    comboBoxBase->addItem("string");
    comboBoxBase->addItem("byte");
    comboBoxBase->addItem("i32");
    comboBoxBase->addItem("struct");
    comboBoxBase->addItem("bool");
    comboBoxBase->addItem("i16");
    comboBoxBase->addItem("double");
    comboBoxBase->addItem("map");
    comboBoxBase->addItem("set");
    comboBoxBase->addItem("list");
    comboBoxBase->setCurrentIndex(0);
    comboBoxBase->setMinimumHeight(29);
    comboBoxBase->setMinimumWidth(50);
    comboBoxBase->setView(new QListView());  //必须设置

    connect(comboBoxBase, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),[=]{
        emit send_currentIndexChanged(comboBoxBase->currentText(), this);
    });

    comboBoxKey = new QComboBox();
    comboBoxKey->addItem("i64");
    comboBoxKey->addItem("string");
    comboBoxKey->addItem("byte");
    comboBoxKey->addItem("i32");
    comboBoxKey->addItem("bool");
    comboBoxKey->addItem("i16");
    comboBoxKey->addItem("double");
    //comboBoxKey->addItem("struct");
    //comboBoxKey->addItem("map");
    //comboBoxKey->addItem("set");
    //comboBoxKey->addItem("list");
    comboBoxKey->setCurrentIndex(0);
    comboBoxKey->setMinimumHeight(29);
    comboBoxKey->setMinimumWidth(50);
    comboBoxKey->hide();

    comboBoxKey->setView(new QListView());  //必须设置

    connect(comboBoxKey, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),[=]{
        emit send_currentIndexChanged(comboBoxKey->currentText(), this);
    });

    comboBoxValue = new QComboBox();
    comboBoxValue->addItem("i64");
    comboBoxValue->addItem("string");
    comboBoxValue->addItem("byte");
    comboBoxValue->addItem("i32");
    comboBoxValue->addItem("struct");
    comboBoxValue->addItem("bool");
    comboBoxValue->addItem("i16");
    comboBoxValue->addItem("double");
    comboBoxValue->addItem("map");
    comboBoxValue->addItem("set");
    comboBoxValue->addItem("list");
    comboBoxValue->setCurrentIndex(0);
    comboBoxValue->setMinimumHeight(29);
    comboBoxValue->setMinimumWidth(50);
    comboBoxValue->hide();

    comboBoxValue->setView(new QListView());  //必须设置

    connect(comboBoxValue, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),[=]{
        emit send_currentIndexChanged(comboBoxValue->currentText(), this);
    });

    lineEditParamSN = new QLineEdit();
    lineEditParamSN->setPlaceholderText("0");
    lineEditParamSN->setMinimumHeight(29);
    //lineEditParamSN->setMaximumWidth(50);

    lineEditParamName = new QLineEdit();
    lineEditParamName->setPlaceholderText("参数名");
    lineEditParamName->setMinimumHeight(29);

    lineEditParamValue = new QLineEdit();
    lineEditParamValue->setPlaceholderText("参数值");
    lineEditParamValue->setMinimumHeight(29);
    connect(lineEditParamValue,&QLineEdit::textChanged,[=]{
        emit send_onTextChanged(lineEditParamValue->text(), this);
    });


    addColumnButton = new QToolButton();
    addColumnButton->setIcon(QIcon(":lib/add3.png"));
    addColumnButton->setIconSize(QSize(20, 20));
    addColumnButton->setMinimumWidth(30);
    addColumnButton->setToolTip("添加新列");
        connect(addColumnButton,&QToolButton::clicked,[=]{
        emit send_buttonClicked_add_column(this);
    });

    deleteButton = new QToolButton();
    deleteButton->setIcon(QIcon(":lib/delete.png"));
    deleteButton->setIconSize(QSize(20, 20));
    deleteButton->setMinimumWidth(30);
    deleteButton->setToolTip("删除当前列");
    connect(deleteButton,&QToolButton::clicked,[=]{
        emit send_buttonClicked(this);
    });

    mastLabel = new QLabel();
    mastLabel->setStyleSheet("QLabel {image: url(:/lib/mast.png);}");
    mastLabel->setToolTip("必选字段");
    mastLabel->setMinimumWidth(16);
    checkBox = new QCheckBox("");
    checkBox->setChecked(false);
    checkBox->setToolTip("勾选参数参与请求");
    checkBox->setMinimumWidth(22);
    checkBox->setMaximumWidth(22);
    checkBox->setMinimumHeight(22);
    checkBox->setMaximumHeight(22);

    checkBox->setStyleSheet("QCheckBox::indicator{\
                width:16px;\
                height:16px;\
           }\
            QCheckBox::indicator::unchecked{\
                image:url(:/lib/gouxuan2.png);\
            }\
            QCheckBox::indicator::checked{\
                image:url(:/lib/gouxuan.png);\
            }");

    moveButton = new QToolButton();
    moveButton->setIcon(QIcon(":lib/tuodong.png"));
    moveButton->setIconSize(QSize(20, 20));

    addNode = new QToolButton();
    addNode->setText("");
    addNode->setToolTip("将根据已有的struct格式快速生成");
    connect(addNode,&QToolButton::clicked,[=]{
        //qDebug() << "触发信号";
        emit send_buttonClicked_add(this);
    });
    addNode->setStyleSheet("QToolButton {\
                           font: 10pt \"OPPOSans B\";\
                           color: rgb(255, 255, 255);\
                           image: url(:/lib/addM2.png);\
                           border-radius: 0px;\
                       }\
                       QToolButton::menu-indicator { \
                           image: None;\
                       }\
                       QToolButton:hover {\
                           color: rgb(255, 255, 255);\
                           image: url(:/lib/addM2.png);\
                       }");
    addNode->setMinimumHeight(20);
    addNode->setMinimumWidth(70);
    addNode->hide();


    layoutParamSN = new QHBoxLayout();
    layoutParamSN->setContentsMargins(0, 0, 0, 0);
    layoutParamSN->addWidget(mastLabel);
    layoutParamSN->addWidget(checkBox);
    layoutParamSN->addWidget(lineEditParamSN);
    widgetParamSN = new QWidget();
    widgetParamSN->setLayout(layoutParamSN);
    //widgetParamSN->setStyleSheet("background-color: rgb(255, 80, 95);");

    layoutParamName = new QHBoxLayout();
    layoutParamName->setContentsMargins(0, 0, 0, 0);
    //layoutParamName->addWidget(checkBox);
    layoutParamName->addWidget(lineEditParamName);
    widgetParamName = new QWidget();
    widgetParamName->setLayout(layoutParamName);
    

    layoutParamType = new QHBoxLayout();
    layoutParamType->setContentsMargins(0, 0, 0, 0);
    layoutParamType->setSpacing(0);
    layoutParamType->addWidget(comboBoxBase);
    layoutParamType->addWidget(comboBoxKey);
    layoutParamType->addWidget(comboBoxValue);
    layoutParamType->addWidget(addNode);
    widgetParamType = new QWidget();
    widgetParamType->setLayout(layoutParamType);

    layoutParamValue = new QHBoxLayout();
    layoutParamValue->setContentsMargins(0, 0, 0, 0);
    keyLabel = new QLabel();
    keyLabel->setAlignment(Qt::AlignCenter);
    keyLabel->setText("");
    //keyLabel->setStyleSheet("font-weight: bold; margin-left: 10px; font: 8pt \"OPPOSans B\";color: rgb(255, 255, 255);background-color: rgb(0, 234, 93);border-radius: 3px;");
    keyLabel->setStyleSheet("image: url(:/lib/purpleres.png);");
    keyLabel->setMinimumWidth(70);
    keyLabel->setMaximumWidth(70);
    keyLabel->setMaximumHeight(17);


    valueLabel = new QLabel();
    valueLabel->setAlignment(Qt::AlignCenter);
    valueLabel->setText("");
    valueLabel->setStyleSheet("font-weight: bold; margin-left: 10px; font: 8pt \"OPPOSans B\";color: rgb(255, 255, 255);background-color: rgb(255, 80, 95);border-radius: 3px;");
    valueLabel->setStyleSheet("image: url(:/lib/redres.png);");
    valueLabel->setMinimumWidth(70);
    valueLabel->setMaximumWidth(70);
    //valueLabel->setMinimumHeight(30);
    valueLabel->setMaximumHeight(17);

    classLabel = new QLabel();
    classLabel->setAlignment(Qt::AlignCenter);
    classLabel->setText("");
    //classLabel->setStyleSheet("font-weight: bold; margin-left: 10px; font: 8pt \"OPPOSans B\";color: rgb(255, 255, 255);background-color: rgb(7, 143, 255);border-radius: 3px;");
    classLabel->setStyleSheet("image: url(:/lib/blueres.png);");
    classLabel->setMinimumWidth(70);
    classLabel->setMaximumWidth(70);
    classLabel->setMaximumHeight(17);


    layoutParamValue->addWidget(keyLabel);
    layoutParamValue->addWidget(valueLabel);
    layoutParamValue->addWidget(classLabel);
    layoutParamValue->addWidget(lineEditParamValue);
    layoutParamValue->addWidget(addColumnButton);
    layoutParamValue->addWidget(deleteButton);
    widgetParamValue = new QWidget();
    widgetParamValue->setLayout(layoutParamValue);

    label = new QLabel("xxxxxxx");

    keyLabel->hide();
    valueLabel->show();
    classLabel->hide();
    //qDebug() << "走init()";
}

void ItemWidget::init2()
{
    treeWidget()->setItemWidget(this, 0, widgetParamSN);
    treeWidget()->setItemWidget(this, 1, widgetParamName);
    treeWidget()->setItemWidget(this, 2, widgetParamType);
    treeWidget()->setItemWidget(this, 3, widgetParamValue);
}

void ItemWidget::init3()
{

}

ItemWidget::~ItemWidget()
{

}

void ItemWidget::copyItem(thriftwidget * p, ItemWidget *item_p, ItemWidget *item_)
{


    //将item_的格式复制到自身 传进来的是一个struct
    this->comboBoxBase->setCurrentIndex(item_->comboBoxBase->currentIndex());
    if (item_->checkBox->isChecked()) {
        this->checkBox->setChecked(true);
    }

    this->keyLabel->hide();
    this->valueLabel->hide();
    this->classLabel->hide();
    if (!item_->keyLabel->isHidden()) {
        this->keyLabel->show();
    }
    if (!item_->valueLabel->isHidden()) {
        this->valueLabel->show();
    }
    if (!item_->classLabel->isHidden()) {
        this->classLabel->show();
    }
    //this->lineEditParamValue->setPlaceholderText("key");
    //this->lineEditParamValue->setReadOnly(false);
    this->setExpanded(true);
    //然后判断item_下面是否有子节点
    if (item_->childCount() > 0) {
        for(int i = 0; i < item_->childCount(); i++) {
            //创建子节点
            ItemWidget* items = p->createAndGetNode(p, this);
            //复制子节点数据
            ItemWidget* item_c = dynamic_cast<ItemWidget*>(item_->child(i));
            items->comboBoxBase->setCurrentIndex(item_c->comboBoxBase->currentIndex());
            if (item_c->checkBox->isChecked()) {
                items->checkBox->setChecked(true);
            }
        }
    }
}

void ItemWidget::setParamSN(QString str)
{
    lineEditParamSN->setText(str);
}

void ItemWidget::setParamName(QString str)
{
    lineEditParamName->setText(str);
}

void ItemWidget::setParamType(QString str)
{
    lineEditParamValue->setText(str);
}

void ItemWidget::setParamValue(thriftwidget * p, QString sn, QString name, QString type, QString typeSign)
{
    //判断typeSign
    //qDebug() << "type =" << type << " name = " << name << " typeSign = " << typeSign;
    if (typeSign == "opt-in, req-out") {
        //必选
        mastLabel->show();
        checkBox->hide();
        checkBox->setChecked(true);
    } else if (typeSign == "optional") {
        //可选
        mastLabel->hide();
        checkBox->show();
        checkBox->setChecked(true);
    }

    lineEditParamSN->setText(sn);
    lineEditParamName->setText(name);
    if (baseType.contains(type)) {
        //基础类型
        comboBoxBase->setCurrentText(type);
    } else if (type.startsWith("map")) {
        //复杂类型

    } else if (type.startsWith("set")) {
        //复杂类型

    } else if (type.startsWith("list")) {
        //复杂类型

    } else {
        //qDebug() << "设置struct1";
        isAuto = false;
        comboBoxBase->setCurrentText("struct");
        
        //qDebug() << "设置struct2";
        lineEditParamName->setText(name);
        lineEditParamValue->setText(type);
        isAuto = true;
        comboBoxKey->hide();
        comboBoxValue->hide();

        keyLabel->hide();
        valueLabel->hide();
        classLabel->show();

        setExpanded(true);
        lineEditParamValue->setReadOnly(true);
        lineEditParamValue->setPlaceholderText("");

        //根据name添加子节点
        //查找对应的数据
        //qDebug() << "点击的结构体类型：" << type;
        for(int i = 1; i <= structParamMap.value(type).size() ;i++)
        {
            //qDebug() << "对应结构体数据type<<" << structParamMap.value(type)[QString::number(i)].paramType;
            //qDebug() << "对应结构体数据name<<" << structParamMap.value(type)[QString::number(i)].paramName;
            ItemWidget* items = thriftwidget::createAndGetNode(p, this);
            items->setParamValue(p, QString::number(i),
                structParamMap.value(type)[QString::number(i)].paramName,
                structParamMap.value(type)[QString::number(i)].paramType,
                structParamMap.value(type)[QString::number(i)].typeSign);
        }
        
    }
    //lineEditParamValue->setText(type);
}

thriftwidget::thriftwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::thriftwidget)
{
    ui->setupUi(this);
    //ui->treeWidget->setStyle(QStyleFactory::create("windows"));
    // 设置树的列数（如果需要多列）
    ui->treeWidget->setColumnCount(4);
    // 设置第一列的宽度为 100 像素
    ui->treeWidget->setColumnWidth(0, 120);

    // 设置第三列的宽度为 150 像素
    ui->treeWidget->setColumnWidth(1, 150);

    // 设置第三列的宽度为 150 像素
    ui->treeWidget->setColumnWidth(2, 200);

    // 计算第五列的宽度，使其占满剩余空间
    //int lastColumnWidth = ui->treeWidget->viewport()->width() - 420;
    //ui->treeWidget->setColumnWidth(3, lastColumnWidth);

    QHeaderView* header = ui->treeWidget->header();

    // 设置所有列的大小调整模式为 Interactive
    header->setSectionResizeMode(QHeaderView::Interactive);

    // 设置默认的列高度为 30 像素
    //header->setDefaultSectionSize(200);
    //ui->treeWidget->header()->resizeSection(1, 150);
    // 创建一个树节点
    ItemWidget* item = createAndGetNode(this, ui->treeWidget);
    //隐藏必选字段
    item->mastLabel->hide();
    //获取当前节点的位置索引，显示序号
    int index = ui->treeWidget->indexOfTopLevelItem(item);
    if (index != -1) {
        item->lineEditParamSN->setText(QString::number(index + 1));
        //qDebug() << "Index of item in treeWidget: " << index;
    } else {
        //qDebug() << "Item is not a top-level item in treeWidget.";
    }

    item->setText(0, "");
     // 添加树节点到树控件中
    ui->treeWidget->addTopLevelItem(item);

    QAction *action = new QAction(this);
    action->setIcon(QIcon(":/lib/soucuo.png"));
    ui->lineEdit_find->addAction(action,QLineEdit::LeadingPosition);

    ui->comboBox_protocol->setView(new QListView());
    ui->comboBox_transport->setView(new QListView());
    ui->comboBox_reqType->setView(new QListView());
    ui->comboBox_testType->setView(new QListView());
    ui->comboBox_port->setView(new QListView());

    ui->splitter->setStretchFactor(0, 5);  // 第一个子控件占 1/3 的显示空间
    ui->splitter->setStretchFactor(1, 3);  // 第二个子控件占 2/3 的显示空间

    ui->splitter_2->setStretchFactor(0, 2);  // 第一个子控件占 1/3 的显示空间
    ui->splitter_2->setStretchFactor(1, 1);  // 第二个子控件占 2/3 的显示空间

    ui->textEdit_info->hide();
    ui->label_req->hide();
    ui->lineEdit_port->hide();

    ui->textEdit->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->textEdit_info->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->textEdit_data->setContextMenuPolicy(Qt::CustomContextMenu);

    ui->stackedWidget->setCurrentIndex(0);

    ui->widget_property->hide();
    //ui->widget_left->hide();

//    ui->splitter_response->setStretchFactor(0,10);
//    ui->splitter_response->setStretchFactor(1,80);
    ui->lineEdit_funcName->installEventFilter(new EnglishOnlyFilter);
    ui->comboBox_testType->setItemData(1, false, Qt::UserRole - 1);

    ui->toolButton_inportFile->setToolTip("导入thrift文件后，可自动生成接口参数");
}

QString thriftwidget::getType(int index)
{
    return "";
}

QString thriftwidget::getType(QString data)
{
    if (data == "i32") {

    } else if (data == "i64") {

    }
    return "";
}

QString thriftwidget::getValue(QString data)
{
    return "";
}

thriftwidget::~thriftwidget()
{
    delete ui;
}

uint32_t thriftwidget::string2Uint32(QString data)
{
    return data.toUInt(nullptr, 16);
}

QVector<uint32_t> thriftwidget::string2Uint32List(QVector<QString> & data)
{
    qDebug() << "最后一个值 = " << last2Value_;
    QString lastValue = "";
    if (data.length() > 1) {
        lastValue = data.last();
        if (lastValue.length() < 8) {
            //补位一定要
            lastValue = lastValue.leftJustified(8, '0');
            qDebug() << "最后小于8" << " data = " << data << " data.size() - 1 = " << data.size() - 1 << " lastValue = " << lastValue;
            data.replace(data.size() - 1, lastValue);
            qDebug() << "改完" << data;
        }
    }
    QVector<uint32_t> return_;
    for (const auto& value : data) {
        return_.append(string2Uint32("0x" + value));
    }
    return return_;
}

void thriftwidget::string2stringList(QString data)
{
    last2Value_ = lastValue_;
    lastValue_ = data;
    //获取最后一个值，判断长度是否够8 //32
    while(1) {
        if (data.length() == 0) {
            break;
        }
        QString lastValue = "";
        if (dataList.length() > 1) {
            lastValue = dataList.last();
        } else {
            dataList.append(lastValue);
        }
        int len = lastValue.length();
        if (len < 8) {
            //qDebug() << "lastValue = " << lastValue <<  " & len = " << len << " & data.length() = " << data.length() << "& 8-len = " << 8-len;
            if (data.length() >= 8-len) {
                dataList.replace(dataList.size() - 1, lastValue + data.mid(0, 8-len));
                //qDebug() << "string2stringList1 value = " << lastValue + data.mid(0, 8-len);
                data = data.mid(8-len);
            } else {
                dataList.replace(dataList.size() - 1, lastValue + data);
                //qDebug() << "string2stringList2 value = " << lastValue + data;
                data = "";
            }
        } else {
            if (data.length() < 8) {
                dataList.append(data);
                //qDebug() << "string2stringList3 value = " << data;
                data = "";
            } else {
                dataList.append(data.mid(0, 8));
                //qDebug() << "string2stringList4 value = " << data.mid(0, 8);
                data = data.mid(8);
            }
        }
    }
}

void thriftwidget::sendThriftRequest(QVector<uint32_t> dataArray)
{
    ui->stackedWidget->setCurrentIndex(1);
    QTcpSocket *clientSocket = new QTcpSocket(this);

    connect(clientSocket,QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),[=]{
        qDebug() << "发生错误";
        ui->stackedWidget->setCurrentIndex(2);
    });

//    connect(clientSocket,&QTcpSocket::stateChanged,[=]{
//        qDebug() << "状态改变";
//    });

    //&QComboBox::activated
    //static_cast<void (QComboBox::*)(int)>(&QComboBox::activated)
//    connect(clientSocket,&QTcpSocket::disconnected,[=]{
//        qDebug() << "断开连接";
//    });

//    connect(clientSocket,&QTcpSocket::connected,[=]{
//        qDebug() << "已连接";
//    });

    //收到数据，触发readyRead

    connect(clientSocket,&QTcpSocket::readyRead,[=]{
        //没有可读的数据就返回
        //qDebug() << "接收到的数据（十六进制字符串）:";
        std::array<uint32_t, 2000> receivedDataArray{0};
        qint64 bytesReceived = clientSocket->read(reinterpret_cast<char*>(receivedDataArray.data()),
                                                  receivedDataArray.size() * sizeof(uint32_t));
        // 将数据转换为主机字节序
        QStringList dataList2;
        QString dataTemp; //输出
        QString dataTemp_2;
        int countLength = -1; //设置数据长度，到达后不再读取 加上开头长度数据
        int nowLength = 0; //设置数据长度，到达后不再读取
        ui->stackedWidget->setCurrentIndex(0);
        int sum = 0;
        int sum_2 =0; 
        for (uint32_t data : receivedDataArray) {
            data = qFromBigEndian(data);
            std::stringstream stream;
            //每次读取一个字节
            stream << std::hex << std::setw(8) << std::setfill('0') << data;
            sum_2++;
            dataList2.append(QString::fromStdString(stream.str()));
            QString temp2 = QString::fromStdString(stream.str());
            dataTemp_2 = dataTemp_2 + temp2;
            dataTemp = dataTemp + temp2 + "  ";
            // if (sum_2 == 4) {
            //     dataTemp = dataTemp + temp2 + "  ";
            //     sum_2 = 0;
            //     qDebug() << "dataTemp1 = " << dataTemp;
            // } else {
            //     dataTemp = dataTemp + temp2;
            //     qDebug() << "dataTemp2 = " << dataTemp;
            // }
            
            if (countLength == -1) {
                //读取头获取数据长度
                countLength = 4 + strtol(dataList2[0].toStdString().c_str(), nullptr, 16);
                //qDebug() << "countLength = " << countLength - 4;
            }
            nowLength = nowLength + 4;
            //qDebug() << "nowLength + 4 = " << nowLength;

            sum++;
            //每8个段进行下一步
            if (sum == 8) {
                sum = 0;
                ui->textEdit->append(dataTemp);
                //qDebug() << "dataTemp = " << dataTemp;
                dataTemp = "";
            }

            if (nowLength > countLength) {
                qDebug() << "超过有效数据长度 = " << nowLength - countLength;
                dataTemp_2 = dataTemp_2.mid(0, dataTemp_2.length()-4);
                //打印剩余dataTemp
                dataTemp = dataTemp.mid(0, dataTemp.length()-6);
                ui->textEdit->append(dataTemp);
                ui->stackedWidget->setCurrentIndex(0);
                qDebug() << "===============1";
                break;
            }
        }
        ui->textEdit->append("------------------------------------------------------------------------------");
        //对数据进行染色
        qDebug() << "===============2";
        handleMessage(dataTemp_2);
        ui->textEdit->append("染色数据(颜色信息可查看thrift协议报文说明):");
        ui->textEdit->append(dataTemp_2);
        ui->textEdit->append("------------------------------------------------------------------------------");
        if (dataList2[1] == "80010002") {
            //结果
            ui->label_req->show();
            ui->label_req->setText("REPLY");
            ui->label_req->setStyleSheet("color: rgb(255, 255, 255);background-color: rgb(27, 161, 58);padding-left:5px;padding-right:5px;");
        } else if (dataList2[1] == "80010003") {
            //异常
            ui->label_req->show();
            ui->label_req->setText("EXCEPTION");
            ui->label_req->setStyleSheet("color: rgb(255, 255, 255);background-color: rgb(181, 11, 11);padding-left:5px;padding-right:5px;");
        } else {
            ui->label_req->hide();
            ui->label_req->setText("");
        }
        clientSocket->close();
    });
    QString port_str = ui->comboBox_port->currentText();
    int index_s = port_str.indexOf("(");
    int index_e = port_str.indexOf(")");
    int port = port_str.mid(index_s + 1, index_e - index_s - 1).toInt();
    clientSocket->connectToHost(ui->lineEdit_host->text(), port);
        if (!clientSocket->waitForConnected()) {
            qDebug() << "无法连接到服务器";
            return ;
        }

        // 检查设备是否打开并处于可读写状态
        if (!clientSocket->isOpen()) {
            // 打开设备
            if (!clientSocket->open(QIODevice::ReadWrite)) {
                qDebug() << "无法打开设备";
                return ;
            }
        }
    for (uint32_t& data : dataArray) {
        data = qToBigEndian(data);
        qDebug() << data;
    }

    qint64 bytesSent = clientSocket->write(reinterpret_cast<char*>(dataArray.data()), dataArray.size() * sizeof(uint32_t));
    if (bytesSent != dataArray.size() * sizeof(uint32_t)) {
        qDebug() << "发送数据失败";
        //clientSocket.close();
        return ;
    }
    ui->label_req->hide();
    ui->label_req->setText("EXCEPTION");
    ui->label_req->setStyleSheet("color: rgb(255, 255, 255);background-color: rgb(181, 11, 11);padding-left:5px;padding-right:5px;");
}

void thriftwidget::buildData()
{
    dataList.clear();
    dataList.resize(0);
    //设置请求类型
    QString reqType = ui->comboBox_reqType->currentText();
    string2stringList(mapReqType.value(reqType));
    //添加接口长度
    int funcLen = ui->lineEdit_funcName->text().length();
    QString funcLenData = QString("%1").arg(funcLen, 8, 16, QLatin1Char('0'));
    string2stringList(funcLenData);
    //添加接口名
    QByteArray byteArray = ui->lineEdit_funcName->text().toUtf8(); // 将字符串转换为字节数组
    QString funcNameData = byteArray.toHex(); // 将字节数组转换为十六进制字符串
    string2stringList(funcNameData);
    //添加流水号
    string2stringList("00000000");
    int sum = -1;
    for(int i = 0; i < ui->treeWidget->topLevelItemCount(); i++) {
        ItemWidget * item = dynamic_cast<ItemWidget*>(ui->treeWidget->topLevelItem(i));
        qDebug() << "参数类型为" << item->comboBoxBase->currentText() << " 参数值为" << item->lineEditParamValue->text();
        if (item->checkBox->isChecked()) {
            sum++;
        } else {
            continue;
        }
        QString valueType = item->comboBoxBase->currentText();
        qDebug() << "valueType = " << valueType;
        if (baseType.contains(valueType)) {
            baseSerialize(sum + 1, valueType, item->lineEditParamValue->text());
        } else if (containerType.contains(valueType)) {
            containerSerialize(sum + 1, valueType, item->lineEditParamValue->text(), item->comboBoxKey->currentText(), item->comboBoxValue->currentText());
        } else if (valueType == "struct") {
            //
            qDebug() << "struct类型";
            structSerialize(sum + 1, valueType, item);
        } else {

        }
    }
    //添加结束符号
    QString stop = QString("%1").arg(0, 2, 16, QLatin1Char('0'));
    dataList.append(stop);

    //TFramedTransport需要设置数据长度
    if (ui->comboBox_transport->currentText() == TFramedTransport_) {
        QString data;
        for (const QString& value : dataList) {
            data = data + value;
        }
        QString dataLength = QString("%1").arg(data.length()/2, 8, 16, QLatin1Char('0'));
        dataList.insert(0, dataLength);
    }
}

void thriftwidget::baseSerialize(int serialNumber, QString valueType, QString value)
{
   qDebug() << "serialNumber = " << serialNumber << " valueType = " << valueType << " value = " << value;
   //设置类型
   QString type = QString("%1").arg(mapType.value(valueType), 2, 16, QLatin1Char('0'));
   string2stringList(type);
   //设置序号
   QString serialNumberStr = QString("%1").arg(serialNumber, 4, 16, QLatin1Char('0'));
   string2stringList(serialNumberStr);

   if (valueType == "bool" || valueType == "byte" || valueType == "i16" ||
        valueType == "i32") {
       //设置值16个长度 8个长度为4个字节  1字节 = 2长度
       int value_i = value.toInt();
       QString valueData = QString("%1").arg(value_i, mapSize.value(valueType), 16, QLatin1Char('0'));
       string2stringList(valueData);
   } else if (valueType == "i64") { 
        int64_t value_i = value.toULongLong();
        //qDebug() << "int64 = " << value;
        QString valueData = QString("%1").arg(value_i, mapSize.value(valueType), 16, QLatin1Char('0'));
        string2stringList(valueData);
   } else if (valueType == "double") {
        //这里要处理
       double d = value.toDouble();//4334.55;
       qulonglong d_long = *(qulonglong*)&d;
       QString d_hex = QString("%1").arg(d_long, mapSize.value(valueType), 16, QLatin1Char('0'));
       //转换
       QString reversedString;
       while (d_hex.length()!=0) {
          //qDebug() << "reversedString = " << d_hex.mid(d_hex.length()-2);
          reversedString = reversedString + d_hex.mid(d_hex.length()-2);
          d_hex = d_hex.mid(0, d_hex.length()-2);
       }
       string2stringList(reversedString);
   } else if (valueType == "string") {
       //设置字符串长度
       int len = value.length();
       QString lenData = QString("%1").arg(len, 8, 16, QLatin1Char('0'));
       string2stringList(lenData);
       //设置字符串值
       QByteArray byteArray = value.toUtf8(); // 将字符串转换为字节数组
       QString valueData = byteArray.toHex(); // 将字节数组转换为十六进制字符串
       string2stringList(valueData);
   } else {
        qDebug() << "出错";
   }
}

void thriftwidget::containerSerialize(int serialNumber, QString valueType, QString value, QString keyType_, QString valyeType_)
{
    qDebug() << "containerSerialize value = " << value;
    //设置类型
    QString type = QString("%1").arg(mapType.value(valueType), 2, 16, QLatin1Char('0'));
    string2stringList(type);
    //设置序号
    QString serialNumberStr = QString("%1").arg(serialNumber, 4, 16, QLatin1Char('0'));
    string2stringList(serialNumberStr);
    if (valueType == "set" || valueType == "list") {
        //获取value类型
        QString key_Type = keyType_;
        //设置value类型
        QString type2 = QString("%1").arg(mapType.value(key_Type), 2, 16, QLatin1Char('0'));
        string2stringList(type2);
        //设置元素个数
        QString data = value.mid(1, value.length() - 2);
        QStringList dataList = data.split(",");
        QString lenData = QString("%1").arg(dataList.length(), 8, 16, QLatin1Char('0'));
        string2stringList(lenData);
        //暂时分三种情况1. key为基础类型，value为基础类型 2. key为基础类型，value为集合类型 3. key为基础类型，value为复杂类型
        if (baseType.contains(key_Type)) {
            //key为基础类型
            if (keyType_ == "string") {
                for (const QString &str : dataList) {
                    qDebug() << "key = " << str;
                    //设置字符串长度
                    int len = str.length();
                    QString lenData = QString("%1").arg(len, 8, 16, QLatin1Char('0'));
                    string2stringList(lenData);
                    //设置字符串值
                    QByteArray byteArray = str.toUtf8(); // 将字符串转换为字节数组
                    QString valueData = byteArray.toHex(); // 将字节数组转换为十六进制字符串
                    string2stringList(valueData);
                }
            } else {
                //设置值 获取数值型
                for (const QString &str : dataList) {
                    qDebug() << "key = " << str;
                    // QString strData = QString("%1").arg(str, mapSize.value(key_Type), QLatin1Char('0'));
                    // string2stringList(strData);

                    int64_t value_i = str.toULongLong();
                    qDebug() << "int64 = " << value;
                    QString valueData = QString("%1").arg(value_i, mapSize.value(valueType), 16, QLatin1Char('0'));
                    string2stringList(valueData);
                }
            }
        } else if (containerType.contains(key_Type)) {
            //key为复杂类型暂不考虑
        } else {
            
        }
    } else if (valueType == "map") {
        //获取key类型
        QString key_Type = keyType_;
        //设置key类型
        QString type2 = QString("%1").arg(mapType.value(key_Type), 2, 16, QLatin1Char('0'));
        string2stringList(type2);
        //获取value类型
        QString value_Type = valyeType_;
        //设置value类型
        QString type3 = QString("%1").arg(mapType.value(value_Type), 2, 16, QLatin1Char('0'));
        string2stringList(type3);
        //设置元素个数
        QString data = value.mid(1, value.length() - 2);
        QStringList dataList;
        map2List(dataList, data);
        qDebug() << "map dataList = " << dataList;
        QString lenData = QString("%1").arg(dataList.length(), 8, 16, QLatin1Char('0'));
        string2stringList(lenData);
        if (baseType.contains(key_Type)) {
            //设置元素值
            for (const QString &str : dataList) {
                int index = str.indexOf(":");
                //设置key值
                QString strData = QString("%1").arg(str.mid(0, index), mapSize.value(key_Type), QLatin1Char('0'));
                string2stringList(strData);
                if (baseType.contains(value_Type)) {
                    if (value_Type == "string") {
                        //设置字符串长度
                        int len = str.mid(index+1).length();
                        QString lenData = QString("%1").arg(len, 8, 16, QLatin1Char('0'));
                        string2stringList(lenData);
                        //设置字符串值
                        QByteArray byteArray = str.mid(index+1).toUtf8(); // 将字符串转换为字节数组
                        QString valueData = byteArray.toHex(); // 将字节数组转换为十六进制字符串
                        string2stringList(valueData);
                    } else {
                        //设置value值
                        QString strData2 = QString("%1").arg(str.mid(index+1), mapSize.value(value_Type), QLatin1Char('0'));
                        string2stringList(strData2);
                    }
                } else if (containerType.contains(value_Type)) {

                } else {

                }
            }
        } else {

        }
    } else {
        qDebug() << "出错";
    }
}

void thriftwidget::structSerialize(int serialNumber, QString valueType, ItemWidget * item)
{
   //设置类型
   QString type = QString("%1").arg(mapType.value(valueType), 2, 16, QLatin1Char('0'));
   string2stringList(type);
   //设置序号
   QString serialNumberStr = QString("%1").arg(serialNumber, 4, 16, QLatin1Char('0'));
   string2stringList(serialNumberStr);
   //遍历item，获取所有子节点，暂时不考虑孙节点
   int sum = -1;
   for(int i = 0; i < item->childCount(); i++) {
        ItemWidget * itemChild = dynamic_cast<ItemWidget*>(item->child(i));
        if (itemChild->checkBox->isChecked()) {
            sum++;
        } else {
            continue;
        }
        //暂不考虑孙节点
        valueType = itemChild->comboBoxBase->currentText();
        QString value = itemChild->lineEditParamValue->text();
        //qDebug() << "struct 参数类型为" << valueType << " 参数值为" << value;
        //设置类型 设置序号
        //设置类型
        QString type = QString("%1").arg(mapType.value(valueType), 2, 16, QLatin1Char('0'));
        string2stringList(type);
        //设置序号
        QString serialNumberStr = QString("%1").arg(i+1, 4, 16, QLatin1Char('0'));
        string2stringList(serialNumberStr);

        if (valueType == "bool" || valueType == "byte" || valueType == "i16" ||
                valueType == "i32") {
            //设置值16个长度 8个长度为4个字节  1字节 = 2长度
            int value_i = value.toInt();
            QString valueData = QString("%1").arg(value_i, mapSize.value(valueType), 16, QLatin1Char('0'));
            string2stringList(valueData);
        } else if (valueType == "i64") {
                int64_t value_i = value.toULongLong();
                //qDebug() << "int64 = " << value;
                QString valueData = QString("%1").arg(value_i, mapSize.value(valueType), 16, QLatin1Char('0'));
                string2stringList(valueData);
        } else if (valueType == "double") {
                //这里要处理
            double d = value.toDouble();
            qulonglong d_long = *(qulonglong*)&d;
            QString d_hex = QString("%1").arg(d_long, mapSize.value(valueType), 16, QLatin1Char('0'));
            //转换
            QString reversedString;
            while (d_hex.length()!=0) {
                //qDebug() << "reversedString = " << d_hex.mid(d_hex.length()-2);
                reversedString = reversedString + d_hex.mid(d_hex.length()-2);
                d_hex = d_hex.mid(0, d_hex.length()-2);
            }
            string2stringList(reversedString);
        } else if (valueType == "string") {
            //字母包括数字这样写没问题，但是如果是文字就占3个而不是一个
            //设置字符串长度
            int len = value.length();
            if (value.contains(QRegExp("[\\x4e00-\\x9fff]+"))) {
                //应该判断包含多少个汉字，然后*2
                int count = 0;
                for (QChar c : value) {
                    if (c >= QChar(0x4e00) && c <= QChar(0x9fff)) {
                        count++;
                    }
                }
                len = len + count*2;
            }
            //qDebug() << "len长度为" << len;
            QString lenData = QString("%1").arg(len, 8, 16, QLatin1Char('0'));
            string2stringList(lenData);
            //设置字符串值
            QByteArray byteArray = value.toUtf8(); // 将字符串转换为字节数组
            QString valueData = byteArray.toHex(); // 将字节数组转换为十六进制字符串
            string2stringList(valueData);
        } else {
                qDebug() << "出错";
        }

   }

    //添加结束符号
    QString stop = QString("%1").arg(0, 2, 16, QLatin1Char('0'));
    string2stringList(stop);
    //dataList.append(stop);
}

void thriftwidget::map2List(QStringList &dataList, QString data)
{

    // int sum = 0;
    // int first = 0;
    // int end = 0;
    // int len = data.length();
    // for (int i = 0; i <= len; i++) {
    //     if (data[i] == '{') {
    //         sum++;
    //         if (sum == 1) {
    //             first = i;
    //         }
    //     }
    //     if (data[i] == '}') {
    //         sum--;
    //         if (sum == 0) {
    //             end = i;
    //             QString da = data.mid(first+1, end - first - 1);
    //             dataList.push_back(da);
    //         }
    //     }
    // }
}

void thriftwidget::cleanMessage()
{
    dataList.clear();
    dataList.resize(0);
}

void thriftwidget::assembleTBinaryMessage()
{
    //清除老数据
    cleanMessage();
    //添加数据头 serialNumber为流水号 默认00000000
    writeTBinaryHeadMessage("00000000");
    //遍历节点写入数据
    for(int i = 0; i < ui->treeWidget->topLevelItemCount(); i++) {
        ItemWidget * item = dynamic_cast<ItemWidget*>(ui->treeWidget->topLevelItem(i));
        if (!item->checkBox->isChecked()) {
            //未勾选跳过
            continue;
        }
        QString valueType = item->comboBoxBase->currentText();
        QString value = item->lineEditParamValue->text();
        //设置类型和序号
        writeTBinaryTypeAndSerialNumber(valueType, i + 1);
        if (baseType.contains(valueType)) {
            //构建基础类型
            writeTBinaryBaseMessage(valueType, value);
        } else if (containerType.contains(valueType)) {
            //构建集合类型
            writeTBinaryCollectionMessage(valueType, value, item, item->comboBoxKey->currentText(), item->comboBoxValue->currentText());
        } else {
            //构建struct
            writeTBinaryStructMessage(valueType, item);
        }
    }
    //写入结束,添加结束符号
    writeTBinaryEndMessage();

    if (ui->comboBox_transport->currentText() == TFramedTransport_) {
        writeTBinarySizeMessage();
    }
}

void thriftwidget::writeTBinaryHeadMessage(QString serialNumber)
{
    //设置请求类型
    QString reqType = ui->comboBox_reqType->currentText();
    string2stringList(mapReqType.value(reqType));
    //添加接口长度
    int funcLen = ui->lineEdit_funcName->text().length();
    QString funcLenData = QString("%1").arg(funcLen, 8, 16, QLatin1Char('0'));
    string2stringList(funcLenData);
    //添加接口名
    QByteArray byteArray = ui->lineEdit_funcName->text().toUtf8(); // 将字符串转换为字节数组
    QString funcNameData = byteArray.toHex(); // 将字节数组转换为十六进制字符串
    string2stringList(funcNameData);
    //添加流水号
    string2stringList(serialNumber);
}

void thriftwidget::writeTBinaryTypeAndSerialNumber(QString valueType, int serialNumber)
{
    //设置参数类型
    QString type = QString("%1").arg(mapType.value(valueType), 2, 16, QLatin1Char('0'));
    string2stringList(type);
    //设置参数序号
    QString serialNumberStr = QString("%1").arg(serialNumber, 4, 16, QLatin1Char('0'));
    string2stringList(serialNumberStr);
    //qDebug() << "writeTBinaryTypeAndSerialNumber type = " << type << " & serialNumberStr = " << serialNumberStr;
}

void thriftwidget::writeTBinaryBaseMessage(QString valueType, QString value)
{
    //qDebug() << "writeTBinaryBaseMessage valueType = " << valueType << " & value = " << valueType;
    if (valueType == "bool" || valueType == "byte" || valueType == "i16" || valueType == "i32") {
        writeTBinaryFormatData(value.toInt(), valueType);
    } else if (valueType == "i64") { 
        writeTBinaryFormatData(value.toULongLong(), valueType);
    } else if (valueType == "double") {
        writeTBinaryFormatData(value.toDouble(), valueType);
    } else if (valueType == "string") {
        writeTBinaryFormatData(value, valueType);
    } else {
        qDebug() << "出错";
    }
}

void thriftwidget::writeTBinaryCollectionMessage(QString valueType, QString value, ItemWidget *item, QString paramKeyType, QString paramValueType)
{
    if (valueType == "set" || valueType == "list") {
        //qDebug() << "writeTBinaryCollectionMessage 构建" << valueType;
        //设置类型
        writeTBinaryTypeMessage(paramValueType);
        //设置元素个数
        QStringList dataList;
        //qDebug() << " value = " << value;
        writeTBinaryKeySize(dataList, value);
        //qDebug() << " dataList = " << dataList;
        if (baseType.contains(paramValueType)) {
            //key为基础类型
            for (const QString &str : dataList) {
                writeTBinaryBaseMessage(paramValueType, str);
            }
        } else if (containerType.contains(paramValueType)) {
            //key为集合
            for (const QString &str : dataList) {
                writeTBinaryCollectionMessage(paramValueType, str, item, item->comboBoxKey->currentText(), item->comboBoxValue->currentText());
            }
        } else {
            //key为struct
            for (const QString &str : dataList) {
                if (item->childCount() > 0) {
                    writeTBinaryStructMessage(paramValueType, item);
                }
            }
        }
    } else if (valueType == "map") {
        //设置key类型
        writeTBinaryTypeMessage(paramKeyType);
        //设置value类型
        writeTBinaryTypeMessage(paramValueType);
        //设置元素个数
        QStringList dataList;
        writeTBinaryValueSize(dataList, value);
        qDebug() << "map dataList = " << dataList;
        if (baseType.contains(paramKeyType)) {
            //设置元素值
            for (const QString &str : dataList) {
                int index = str.indexOf(":");
                //设置key值
                qDebug() << "key = " << str.mid(0, index);
                qDebug() << "value = " << str.mid(index+1);
                writeTBinaryBaseMessage(paramKeyType, str.mid(0, index));
                if (baseType.contains(paramValueType)) {
                    writeTBinaryBaseMessage(paramValueType, str.mid(index+1));
                } else if (containerType.contains(paramValueType)) {
                    //集合
                    writeTBinaryCollectionMessage(paramValueType, str.mid(index+1), item, item->comboBoxKey->currentText(), item->comboBoxValue->currentText());
                } else {
                    //struct
                    writeTBinaryStructMessage(paramValueType, item);
                }
            }
        } else {
            //key如果不是基础类型，不支持
        }
    } else {
        qDebug() << "出错";
    }
}

void thriftwidget::writeTBinaryStructMessage(QString valueType, ItemWidget *item)
{
    //遍历item
   for(int serialNumber = 0; serialNumber < item->childCount(); serialNumber++) {
        ItemWidget * itemChild = dynamic_cast<ItemWidget*>(item->child(serialNumber));
        if (!itemChild->checkBox->isChecked()) {
            //未勾选跳过
            continue;
        }
        //设置类型和序号
        QString valueType_ = itemChild->comboBoxBase->currentText();
        QString value_ = itemChild->lineEditParamValue->text();
        writeTBinaryTypeAndSerialNumber(valueType_, serialNumber + 1);
        if (baseType.contains(valueType_)) {
            writeTBinaryBaseMessage(valueType_, value_);
        } else if (containerType.contains(valueType_)) {
            //集合
            writeTBinaryCollectionMessage(valueType_, value_, itemChild, itemChild->comboBoxKey->currentText(), itemChild->comboBoxValue->currentText());
        } else {
            //struct
            writeTBinaryStructMessage(valueType_, itemChild);
        }
   }
    //写入结束,添加结束符号
    writeTBinaryEndMessage();
}

void thriftwidget::writeTBinaryEndMessage()
{
    qDebug() << "写入结尾符";
    QString stop = QString("%1").arg(0, 2, 16, QLatin1Char('0'));
    //dataList.append(stop);
    string2stringList(stop);
}

void thriftwidget::writeTBinarySizeMessage()
{

    QString data;
    for (const QString& value : dataList) {
        data = data + value;
    }
    QString dataLength = QString("%1").arg(data.length()/2, 8, 16, QLatin1Char('0'));
    qDebug() << "writeTBinarySizeMessage data = " << data << " Length = " << data.length()/2;
    qDebug() << "dataLength = " << dataLength;
    dataList.insert(0, dataLength);
}

void thriftwidget::writeTBinaryTypeMessage(QString type_)
{
    QString type = QString("%1").arg(mapType.value(type_), 2, 16, QLatin1Char('0'));
    string2stringList(type);
}

void thriftwidget::writeTBinaryKeySize(QStringList &dataList, QString value)
{
    QString data = value;//.mid(0, value.length() - 2);
    dataList = data.split(",");
    QString lenData = QString("%1").arg(dataList.length(), 8, 16, QLatin1Char('0'));
    qDebug() << "writeTBinaryKeySize = " << dataList.length() << " lenData = " << lenData;
    string2stringList(lenData);
}

void thriftwidget::writeTBinaryValueSize(QStringList &dataList, QString value)
{
    QString data = value;//.mid(1, value.length() - 2);
    qDebug() << "writeTBinaryValueSize data = " << data;
    dataList = data.split(",");
    //map2List(dataList, data);
    QString lenData = QString("%1").arg(dataList.length(), 8, 16, QLatin1Char('0'));
    string2stringList(lenData);
}

void thriftwidget::handleMessage(QString &data)
{
    QString label_headers;
    QString temp;
    //数据长度
    QString message_len = data.mid(0, 8);
    temp = temp + addColorHtml(message_len, sourceColorMap[THRIFT_MESSAGE_LENGTH]);
    data = data.mid(8);
    
    QString headers_data_length = QString::number(strtol(message_len.toStdString().c_str(), nullptr, 16));
    label_headers = label_headers + "数据长度:" + headers_data_length + "   ";
    //qDebug() << "数据长度 = " << headers_data_length;
    //消息类型
    QString type_data = data.mid(0, 8);
    if (type_data == "80010001") {
        //qDebug() << "消息类型 = " << "CALL";
        temp = temp + addColorHtml(data.mid(0, 8), sourceColorMap[THRIFT_MESSAGE_TYPE_CALL]);
    } else if (type_data == "80010002") {
        //qDebug() << "消息类型 = " << "REPLY";
        label_headers = label_headers + "消息类型:REPLY" + "   ";
        temp = temp + addColorHtml(data.mid(0, 8), sourceColorMap[THRIFT_MESSAGE_TYPE_REPLY]);
    } else if (type_data == "80010003") {
        //qDebug() << "消息类型 = " << "EXCEPTION";
        temp = temp + addColorHtml(data.mid(0, 8), sourceColorMap[THRIFT_MESSAGE_TYPE_EXCEPTION]);
    } else if (type_data == "80010004") {
        //qDebug() << "消息类型 = " << "ONEWAY";
        temp = temp + addColorHtml(data.mid(0, 8), sourceColorMap[THRIFT_MESSAGE_TYPE_ONEWAY]);
    }
    data = data.mid(8);
    //方法长度名
    QString func_len = data.mid(0, 8);
    QString headers_func_length = QString::number(strtol(func_len.toStdString().c_str(), nullptr, 16));
    //qDebug() << "方法长度 = " << headers_func_length;
    label_headers = label_headers + "方法长度:" + headers_func_length + "   ";
    temp = temp + addColorHtml(func_len, sourceColorMap[THRIFT_FUNC_LENGTH]);
    bool ok;
    int len = func_len.toInt(&ok, 16) * 2;
    data = data.mid(8);
    //需要转换为长度单位
    //方法名
    QString fun_name = data.mid(0, len);
    temp = temp + addColorHtml(fun_name, sourceColorMap[THRIFT_FUNC_NAME]);
    //qDebug() << "方法名 = " << hexToString(fun_name);
    label_headers = label_headers + "方法名称:" + hexToString(fun_name) + "   ";
    data = data.mid(len);
    //流水号
    QString func_sn = data.mid(0, 8);
    temp = temp + addColorHtml(func_sn, sourceColorMap[THRIFT_SN]);
    data = data.mid(8);
    QString headers_data_sn = QString::number(strtol(func_sn.toStdString().c_str(), nullptr, 16));
    //qDebug() << "流水号 = " << headers_data_sn;
    label_headers = label_headers + "流水号:" + headers_data_sn + "   ";
    

    label_headers = label_headers + "返回值类型:" + funcParamOutMap.value(hexToString(fun_name)).value("1").paramType + "   ";
    ui->label_headers->setText(label_headers);
    //数据
    //编号两位数  序号4位数 数据
    //data = temp + data;
    //for(int i = 0; i < = 500; i++) {
    //qDebug() << "数据= " << data;
    if (type_data == "80010002") {
        while (true) {

            if (data.length() <= 0) {
                break;
            }

            //获取类型
            QString value_type = data.mid(0, 2);
            temp = temp + addColorHtml(value_type, sourceColorMap[sourceTypeMap[value_type]]);
            data = data.mid(2);

            //获取编号
            QString value_sn = data.mid(0, 4);
            temp = temp + addColorHtml(value_sn, sourceColorMap[THRIFT_VALUE_SN]);
            data = data.mid(4);
            
            // if (value_type == "00") {
            //     qDebug() << "结尾符";
            //     break;
            // } else 
            QString isEnd = data.mid(0, 2);
            qDebug() << "handleMessage isEnd = " << isEnd; 
            if (value_type == "02") {
                //bool
                temp = temp + handleBool(data, isEnd);
            } else if (value_type == "03") {
                //byte
                qDebug() << "走这里1";
                temp = temp + handleByte(data, isEnd);
            } else if (value_type == "04") {
                //double
                temp = temp + handleDouble(data, isEnd);
            } else if (value_type == "06") {
                //i16
                temp = temp + handleI16(data, isEnd);
            } else if (value_type == "08") {
                //i32
                temp = temp + handleI32(data, isEnd);
            } else if (value_type == "0a") {
                //i64
                temp = temp + handleI64(data, isEnd);
            } else if (value_type == "0b") {
                //string
                temp = temp + handleString(data, isEnd);
            } else if (value_type == "0c") {
                //struct
                qDebug() << "进入struct";
                temp = temp + handleStruct(data, isEnd, funcParamOutMap.value(hexToString(fun_name)).value("1").paramType,
                    funcParamOutMap.value(hexToString(fun_name)).value("1").paramName);
                //固定1
                //记得处理请求结束
                break;
            } else if (value_type == "0d") {
                //map
                temp = temp + handleMap(data, isEnd);
            } else if (value_type == "0e") {
                //set
                temp = temp + handleSet(data, isEnd);
            } else if (value_type == "0f") {
                //list
                temp = temp + handleList(data, isEnd);
            }
        }
    } else if (type_data == "80010003") {
        //读取异常数据
        for (int i = 0; i < 2; i++) {
            QString value_type = data.mid(0, 2);
            temp = temp + addColorHtml(value_type, sourceColorMap[sourceTypeMap[value_type]]);
            data = data.mid(2);

            QString value_sn = data.mid(0, 4);
            temp = temp + addColorHtml(value_sn, sourceColorMap[THRIFT_VALUE_SN]);
            data = data.mid(4);

            QString isEnd = data.mid(0, 2);
            if (value_type == "0b") {
                temp = temp + handleString(data, isEnd, THRIFT_EXCEPTION);

            } else if (value_type == "08") {
                //qDebug() << "剩下数据" << data;
                temp = temp + handleI32(data, isEnd, THRIFT_EXCEPTION);
            }
        }
    }
    data = temp + data;
    //qDebug() << "异常数据 = " << data;
}

QString thriftwidget::addColorHtml(QString &str, QColor *fontCrl)
{
    QByteArray array;
    array.append(fontCrl->red());
    array.append(fontCrl->green());
    array.append(fontCrl->blue());
    QString strC(array.toHex());
    return QString("<span style=\" color:#%1;opacity: 1;\">%2</span>").arg(strC).arg(str);
}


QString thriftwidget::addColorFieldHtml(QString str)
{
    //qDebug() << "addColorFieldHtml str = " << str;
    QColor *fontCrl = new QColor(150, 40, 140);
    QByteArray array;
    array.append(fontCrl->red());
    array.append(fontCrl->green());
    array.append(fontCrl->blue());
    QString strC(array.toHex());
    str.replace(" ","&nbsp;");
    return QString("<span style=\" color:#%1;opacity: 1;\">%2</span>").arg(strC).arg(str);
}


QString thriftwidget::addColorValueNumHtml(QString str)
{
    QColor *fontCrl = new QColor(0, 160, 255);
    QByteArray array;
    array.append(fontCrl->red());
    array.append(fontCrl->green());
    array.append(fontCrl->blue());
    QString strC(array.toHex());
    return QString("<span style=\" color:#%1;opacity: 1;\">%2</span>").arg(strC).arg(str);
}

QString thriftwidget::addColorValueStrHtml(QString str)
{
    QColor *fontCrl = new QColor(0, 180, 0);
    QByteArray array;
    array.append(fontCrl->red());
    array.append(fontCrl->green());
    array.append(fontCrl->blue());
    QString strC(array.toHex());
    return QString("<span style=\" color:#%1;opacity: 1;\">%2</span>").arg(strC).arg(str);
}

QString thriftwidget::addColorBracketsHtml(QString str)
{
    QColor *fontCrl = new QColor(35, 35, 35);
    QByteArray array;
    array.append(fontCrl->red());
    array.append(fontCrl->green());
    array.append(fontCrl->blue());
    QString strC(array.toHex());
    str.replace(" ","&nbsp;");
    return QString("<span style=\" color:#%1;opacity: 1;\">%2</span>").arg(strC).arg(str);
}


QString thriftwidget::handleBool(QString &str, QString isEnd, QString paramName)
{
    QString value = str.mid(0, 2);
    str = str.mid(2);
    isEnd = str.mid(0,2);
    QString end = ",";
    if (isEnd == "00") {
        end = "";
    }
    if (paramName != "") {
        qDebug() << "paramName1";
        ui->textEdit_data->append(addColorFieldHtml(getRetract() + "\"" + paramName+ "\"") + " : " + addColorValueNumHtml(hexToLongNumber(value)) + end);
    } else {
        qDebug() << "paramName2";
        ui->textEdit_data->append(addColorFieldHtml(getRetract() + "bool") + " : " + addColorValueNumHtml(hexToLongNumber(value)) + end);
    }
    return addColorHtml(value, sourceColorMap[THRIFT_VALUE]);
}

QString thriftwidget::handleByte(QString &str, QString isEnd, QString paramName)
{
    QString value = str.mid(0, 2);
    str = str.mid(2);
    //qDebug() << "handleByte getRetract()  = " << getRetract() ;
    isEnd = str.mid(0,2);
    QString end = ",";
    if (isEnd == "00") {
        end = "";
    }
    if (paramName != "") {
        qDebug() << "paramName1";
        ui->textEdit_data->append(addColorFieldHtml(getRetract() + "\"" + paramName+ "\"") + " : " + addColorValueNumHtml(hexToLongNumber(value)) + end);
    } else {
        qDebug() << "paramName2";
        ui->textEdit_data->append(addColorFieldHtml(getRetract() + "byte") + " : " + addColorValueNumHtml(hexToLongNumber(value)) + end);
    }
    return addColorHtml(value, sourceColorMap[THRIFT_VALUE]);
}

QString thriftwidget::handleDouble(QString &str, QString isEnd, QString paramName)
{
    QString value = str.mid(0, 16);
    str = str.mid(16);
    isEnd = str.mid(0,2);
    return addColorHtml(value, sourceColorMap[THRIFT_VALUE]);
}

QString thriftwidget::handleI16(QString &str, QString isEnd, QString paramName)
{
    QString value = str.mid(0, 4);
    str = str.mid(4);
    isEnd = str.mid(0,2);
    QString end = ",";
    if (isEnd == "00") {
        end = "";
    }
    if (paramName != "") {
        qDebug() << "paramName1";
        ui->textEdit_data->append(addColorFieldHtml(getRetract() + "\"" + paramName+ "\"") + " : " + addColorValueNumHtml(hexToLongNumber(value)) + end);
    } else {
        qDebug() << "paramName2";
        ui->textEdit_data->append(addColorFieldHtml(getRetract() + "i16") + " : " + addColorValueNumHtml(hexToLongNumber(value)) + end);
    }
    
    return addColorHtml(value, sourceColorMap[THRIFT_VALUE]);
}

QString thriftwidget::handleI32(QString &str, QString isEnd, QString resType, QString paramName)
{
    QString value = str.mid(0, 8);
    str = str.mid(8);
    isEnd = str.mid(0,2);
    QString end = ",";
    if (isEnd == "00") {
        end = "";
    }
    if (resType == THRIFT_REPLY) {
        if (paramName != "") {
            qDebug() << "paramName1";
            ui->textEdit_data->append(addColorFieldHtml(getRetract() + "\"" + paramName + "\"") + " : " + addColorValueNumHtml(hexToLongNumber(value)) + end);
        } else {
            qDebug() << "paramName2";
            ui->textEdit_data->append(addColorFieldHtml(getRetract() + "i32") + " : " + addColorValueNumHtml(hexToLongNumber(value)) + end);
        }
        
    } else if (resType == THRIFT_EXCEPTION) {
        QString excType = hexToLongNumber(value);
        ui->textEdit_data->append(addColorFieldHtml(getRetract() + "Exception Type") + " : " + addColorValueNumHtml(ExceptionType.value(excType) + " (" + excType + ")"));
    }
    return addColorHtml(value, sourceColorMap[THRIFT_VALUE]);
}

QString thriftwidget::handleI64(QString &str, QString isEnd, QString paramName)
{
    QString value = str.mid(0, 16);
    str = str.mid(16);
    QString end = ",";
    isEnd = str.mid(0,2);
    if (isEnd == "00") {
        end = "";
    }
    if (paramName != "") {
        qDebug() << "paramName1";
        ui->textEdit_data->append(addColorFieldHtml(getRetract() + "\"" + paramName+ "\"") + " : " + addColorValueNumHtml(hexToLongNumber(value)) + end);
    } else {
        qDebug() << "paramName2";
        ui->textEdit_data->append(addColorFieldHtml(getRetract() + "i64") + " : " + addColorValueNumHtml(hexToLongNumber(value)) + end);
    }
    
    return addColorHtml(value, sourceColorMap[THRIFT_VALUE]);
}

QString thriftwidget::handleString(QString &str, QString isEnd, QString resType, QString paramName)
{
    //长度
    QString value = str.mid(0, 8);
    str = str.mid(8);
    QString temp = "";
    temp = temp + addColorHtml(value, sourceColorMap[THRIFT_MESSAGE_LENGTH]);
    //值
    bool ok;
    int len = value.toInt(&ok, 16) * 2;
    QString value2 = str.mid(0, len);
    str = str.mid(len);
    isEnd = str.mid(0,2);
    QString end = ",";
    if (isEnd == "00") {
        end = "";
    }
    if (resType == THRIFT_REPLY) {
        if (paramName != "") {
            qDebug() << "paramName1";
            ui->textEdit_data->append(addColorFieldHtml(getRetract() + "\"" + paramName + "\"") + " : " + addColorValueStrHtml("\"" + hexToString(value2) + "\"") + end);
        } else {
            qDebug() << "paramName2";
            ui->textEdit_data->append(addColorFieldHtml(getRetract() + "string") + " : " + addColorValueStrHtml("\"" + hexToString(value2) + "\"") + end);
        }
        
        temp = temp + addColorHtml(value2, sourceColorMap[THRIFT_VALUE]);
    } else if (resType == THRIFT_EXCEPTION) {
        ui->textEdit_data->append(addColorFieldHtml(getRetract() + "Exception Message") + " : " + addColorValueStrHtml("\"" + hexToString(value2) + "\""));
        temp = temp + addColorHtml(value2, sourceColorMap[THRIFT_VALUE]);
    }
    return temp;
}

QString thriftwidget::handleStruct(QString &str, QString isEnd, QString outType, QString outParam)
{
    if (outParam == "") {
        ui->textEdit_data->append(addColorBracketsHtml(getRetract() + "{"));
    } else {
        ui->textEdit_data->append(addColorFieldHtml(getRetract() + "\"" + outParam + "\"")  + addColorBracketsHtml(":{"));
    }
    
    retractNum++;
    //读取编号 序号 数据
    QString temp = "";
    int sum = 0;
    while (true) {
        //读取类型编号
        // if (sum == 4) {
        //     break;
        // }
        if (str== "") {
            ui->textEdit_data->append("struct类型数据结束------------");
            break;
        }
        QString value_type = str.mid(0, 2);
        str = str.mid(2);
        //qDebug() << "value_type = " << value_type;
        if (value_type == "00") {
            // QString value_sn = str.mid(0, 4);
            // str = str.mid(4);
            temp = temp + addColorHtml(value_type, sourceColorMap[THRIFT_END]);
            //qDebug() << "结尾符2";
            retractNum--;
            isEnd = str.mid(0, 2);
            if (isEnd == "00") {
                ui->textEdit_data->append(addColorBracketsHtml(getRetract() + "}"));
            } else {
                ui->textEdit_data->append(addColorBracketsHtml(getRetract() + "},"));
            }
            
            break;
        } 
        temp = temp + addColorHtml(value_type, sourceColorMap[sourceTypeMap[value_type]]);

        //读取序号
        QString value_sn = str.mid(0, 4);
        //需要转
        qDebug() << "outParam = " << outParam << " hexToLongNumber(value_sn) = " << hexToLongNumber(value_sn) << " value_sn = " << value_sn;
        QString paramName_ = structParamMap.value(outType).value(hexToLongNumber(value_sn)).paramName;
        QString paramType_ = structParamMap.value(outType).value(hexToLongNumber(value_sn)).paramType;
        
        str = str.mid(4);
        temp = temp + addColorHtml(value_sn, sourceColorMap[THRIFT_VALUE_SN]);

        int type_ = 0;

        QString isEnd = str.mid(0, 2);
        qDebug()<< "paramName_ = " << paramName_ << " isEnd = " << isEnd;
        if (value_type == "02") {
            //bool
            type_ = THRIFT_BOOL;
            temp = temp + handleBool(str, isEnd, paramName_);
        } else if (value_type == "03") {
            //byte
            type_ = THRIFT_BYTE;
            temp = temp + handleByte(str, isEnd, paramName_);
        } else if (value_type == "04") {
            //double
            type_ = THRIFT_DOUBLE;
            temp = temp + handleDouble(str, isEnd, paramName_);
        } else if (value_type == "06") {
            //i16
            type_ = THRIFT_I16;
            temp = temp + handleI16(str, isEnd, paramName_);
        } else if (value_type == "08") {
            //i32
            type_ = THRIFT_I32;
            temp = temp + handleI32(str, isEnd, THRIFT_REPLY, paramName_);
            
        } else if (value_type == "0a") {
            //i64
            type_ = THRIFT_I32;
            qDebug() << "0a isEnd = "<< isEnd << " paramName_ = " << paramName_;
            temp = temp + handleI64(str, isEnd, paramName_);
        } else if (value_type == "0b") {
            //string
            type_ = THRIFT_STRING;
            temp = temp + handleString(str, isEnd, THRIFT_REPLY, paramName_);
        } else if (value_type == "0c") {
            //struct
            type_ = THRIFT_STRUCT;
            temp = temp + handleStruct(str, isEnd, paramType_, paramName_);
        } else if (value_type == "0d") {
            //map
            type_ = THRIFT_MAP;
        } else if (value_type == "0e") {
            //set
            type_ = THRIFT_SET;
        } else if (value_type == "0f") {
            //list
            type_ = THRIFT_LIST;
            qDebug()<< "走到这里0f";
            //内部处理类型吧
            temp = temp + handleList(str, isEnd, paramType_, paramName_);
            //break;
        }
        sum++;
    }
    return temp;
}

QString thriftwidget::handleMap(QString &str, QString isEnd, QString outType, QString paramName)
{
    return "";
}

QString thriftwidget::handleSet(QString &str, QString isEnd, QString outType, QString paramName)
{
    //值类型
    QString value = str.mid(0, 2);
    str = str.mid(2);

    return addColorHtml(value, sourceColorMap[sourceTypeMap["00"]]);
}

QString thriftwidget::handleList(QString &str, QString isEnd, QString outType, QString outParam)
{
    qDebug() << "outType =" << outType;
    int index_s = outType.indexOf("<");
    int index_e = outType.lastIndexOf(">");
    QString paramType_s = outType.mid(index_s + 1, index_e - index_s - 1);
    qDebug() << "paramType_s =" << paramType_s;
    if (outParam == "") {
        ui->textEdit_data->append(addColorBracketsHtml(getRetract() + "["));
    } else {
        ui->textEdit_data->append(addColorFieldHtml(getRetract() + "\"" + outParam + "\"") + addColorBracketsHtml(":["));
    }
    retractNum++;
    //值类型 4
    QString temp;
    QString value_type = str.mid(0, 2);
    qDebug() << " handleList value_type = " << value_type;
    str = str.mid(2);
    temp = temp + addColorHtml(value_type, sourceColorMap[sourceTypeMap[value_type]]);
    //值长度 8
    QString value_len = str.mid(0, 8);
    str = str.mid(8);
    temp = temp + addColorHtml(value_len, sourceColorMap[THRIFT_MESSAGE_LENGTH]);
    //值 需要判断是否是基础类型
    // QString value3 = str.mid(0, 8);
    // str = str.mid(8);
    bool ok;
    int len = value_len.toInt(&ok, 16);
    qDebug() << "list len = " << len;
    //QString isEnd = str.mid(0, 2);

    for(int i = 1; i <= len; i++) {
        QString paramName = ""; //structParamMap.value(paramType_s).value(QString::number(i)).paramName;
        QString paramType = paramType_s; //structParamMap.value(paramType_s).value(QString::number(i)).paramType;
        qDebug() << " paramName  = " << paramName << " paramType = " << paramType;
        if (value_type == "02") {
            //bool
            temp = temp + handleBool(str, isEnd, paramName);
        } else if (value_type == "03") {
            //byte
            qDebug() << "走这里3";
            temp = temp + handleByte(str, isEnd, paramName);
        } else if (value_type == "04") {
            //double
            temp = temp + handleDouble(str, isEnd, paramName);
        } else if (value_type == "06") {
            //i16
            temp = temp + handleI16(str, isEnd, paramName);
        } else if (value_type == "08") {
            //i32
            temp = temp + handleI32(str, isEnd, THRIFT_REPLY, paramName);
        } else if (value_type == "0a") {
            //i64
            temp = temp + handleI64(str, isEnd, paramName);
        } else if (value_type == "0b") {
            //string
            temp = temp + handleString(str, isEnd, THRIFT_REPLY, paramName);
        } else if (value_type == "0c") {
            temp = temp + handleStruct(str, isEnd, paramType, paramName);
        } else if (value_type == "0d") {

        } else if (value_type == "0e") {
            
        } else if (value_type == "0f") {
            temp = temp + handleList(str, isEnd, paramType, paramName);
        }
    }
    retractNum--;
    isEnd = str.mid(0, 2);
    if (isEnd == "00") {
        ui->textEdit_data->append(addColorBracketsHtml(getRetract() + "]"));
    } else {
        ui->textEdit_data->append(addColorBracketsHtml(getRetract() + "],"));
    }
    return temp;
    //return addColorHtml(value, sourceColorMap[sourceTypeMap["00"]]);
}

QString thriftwidget::handleEnd(QString &str)
{
    QString value = str.mid(0, 2);
    str = str.mid(2);
    return addColorHtml(value, sourceColorMap[sourceTypeMap["00"]]);
}

QString thriftwidget::hexToString(QString &hex)
{
    QByteArray byteArray = QByteArray::fromHex(hex.toLatin1());
    return QString(byteArray);
}

QString thriftwidget::hexToLongNumber(QString &hex)
{
    return QString::number(strtol(hex.toStdString().c_str(), nullptr, 16));
}

void thriftwidget::removeLastComma(QString &str)
{
    int lastCommaIndex = str.lastIndexOf(',');

    if (lastCommaIndex != -1) { // 如果找到了逗号
        // 删除最后一个逗号及其之后的内容
        str.remove(lastCommaIndex, str.length() - lastCommaIndex);
        //qDebug() << "删除最后一个逗号后的字符串：" << str;
    } else {
        //qDebug() << "字符串中没有逗号。";
    }
}

QString thriftwidget::getRetract()
{
    QString retract;
    for(int i = 0; i < retractNum; i++) {
        retract = retract + "  ";
    }
    return retract;
}


QMap<QString, paramInfo> thriftwidget::getFuncInParams(QString data)
{
    //三种解析
    //1: SessionTicket st, 2: i64 userID
    //1:ThesaurusPage pageParam
    //1:i64 ct,2:i64 userID
    QMap<QString, paramInfo> paramsMap_;
    //先判断是一个参数，还是多个参数
    if (!data.contains(",")) {
        //一个参数
        int index = data.indexOf(":");
        data = data.mid(0, index + 1) + " " + data.mid(index + 1);
        qDebug() << "data = " << data;
    }
    QStringList funcParams = data.split(",");
    for(int i =0; i < funcParams.length(); i++) {
        int index = funcParams[i].indexOf(":");
        funcParams[i] = funcParams[i].mid(0, index + 1) + " " + funcParams[i].mid(index + 1);
        QStringList Params = funcParams[i].split(" ", QString::SkipEmptyParts);
        if (Params.length() == 3) {
            int index = Params[0].indexOf(":");
            QString sn = Params[0].mid(0, index);
            QString paramType = Params[1];
            QString paramName = Params[2];
            paramsMap_.insert(sn, {paramType, paramName, "opt-in, req-out"});
            qDebug() << " sn = " << sn << " paramType = " << paramType << " paramName" << paramName;
        } else {
            qDebug() << "错误";
        }
    }
    return paramsMap_;
}

QMap<QString, paramInfo> thriftwidget::getFuncOutParams(QString data)
{
    QMap<QString, paramInfo> paramsMap_;
    //只可能有一个返回值，判断是不是基础类型
    if (baseType.contains(data)) {
        //基础类型
    } else if (data.startsWith("map")) {
        //复杂类型

    } else if (data.startsWith("set")) {
        //复杂类型

    } else if (data.startsWith("list")) {
        //复杂类型

    } else {
        //struct
        paramsMap_.insert("1", {data, "", "opt-in, req-out"});
    }
    
    return paramsMap_;
}

QMap<QString, structInfo> thriftwidget::getStructParams(QString data)
{
    QMap<QString, structInfo> paramsStructMap_;
    //按照\n分割，排空
    QStringList list = data.split("\n", QString::SkipEmptyParts);
    qDebug() << "list = " << list;
    for (int i = 0; i < list.length(); i++) {
        QString str = list[i];
        //分割序号，类型，名字
        //查找:
        int index = str.indexOf(":");
        QString sn = str.mid(0, index).replace(" ", "");
        QStringList a = str.mid(index + 1).split(" ", QString::SkipEmptyParts);
        if (a.length() == 2) {
            QString type = a[0].replace(";", "");
            QString name = a[1].replace(";", "");
            qDebug() << "sn = " << sn << " type = " << type << " name =" << name;
            paramsStructMap_.insert(sn, {type, name, "opt-in, req-out"});
        } else if (a.length() == 3) {
            if (a[0] == "optional") {
                qDebug() << "选传";
            } else if (a[0] == "required") {
                qDebug() << "提示";
            }
            QString type = a[1].replace(";", "");
            QString name = a[2].replace(";", "");
            qDebug() << "sn = " << sn << " type = " << type << " name = " << name;
            paramsStructMap_.insert(sn, {type, name, a[0]});
        }
    }
    return paramsStructMap_;
}

ItemWidget* thriftwidget::createAndGetNode(thriftwidget * p)
{
    ItemWidget* items = new ItemWidget();
    items->mastLabel->hide();
    connect(items, SIGNAL(send_buttonClicked(QTreeWidgetItem*)), p, SLOT(rece_deleteItem(QTreeWidgetItem*)));
    connect(items, SIGNAL(send_buttonClicked_add(QTreeWidgetItem*)), p, SLOT(rece_addItem(QTreeWidgetItem*)));
    connect(items, SIGNAL(send_buttonClicked_add_column(QTreeWidgetItem*)), p, SLOT(rece_addColumn(QTreeWidgetItem*)));
    connect(items, SIGNAL(send_onTextChanged(QString, QTreeWidgetItem*)), p, SLOT(rece_TextChanged(QString, QTreeWidgetItem*)));
    connect(items, SIGNAL(send_currentIndexChanged(QString, QTreeWidgetItem*)), p, SLOT(rece_currentIndexChanged(QString, QTreeWidgetItem*)));
    return items;
}

ItemWidget* thriftwidget::createAndGetNode(thriftwidget * p, QTreeWidget *parent)
{
    //qDebug() << "调一次";
    ItemWidget* items = new ItemWidget(parent);
    items->mastLabel->hide();
    connect(items, SIGNAL(send_buttonClicked(QTreeWidgetItem*)), p, SLOT(rece_deleteItem(QTreeWidgetItem*)));
    connect(items, SIGNAL(send_buttonClicked_add(QTreeWidgetItem*)), p, SLOT(rece_addItem(QTreeWidgetItem*)));
    connect(items, SIGNAL(send_buttonClicked_add_column(QTreeWidgetItem*)), p, SLOT(rece_addColumn(QTreeWidgetItem*)));
    connect(items, SIGNAL(send_onTextChanged(QString, QTreeWidgetItem*)), p, SLOT(rece_TextChanged(QString, QTreeWidgetItem*)));
    connect(items, SIGNAL(send_currentIndexChanged(QString, QTreeWidgetItem*)), p, SLOT(rece_currentIndexChanged(QString, QTreeWidgetItem*)));
    return items;
}

ItemWidget* thriftwidget::createAndGetNode(thriftwidget * p, QTreeWidgetItem *parent)
{
    ItemWidget* items = new ItemWidget(parent);
    items->mastLabel->hide();
    connect(items, SIGNAL(send_buttonClicked(QTreeWidgetItem*)), p, SLOT(rece_deleteItem(QTreeWidgetItem*)));
    connect(items, SIGNAL(send_buttonClicked_add(QTreeWidgetItem*)), p, SLOT(rece_addItem(QTreeWidgetItem*)));
    connect(items, SIGNAL(send_buttonClicked_add_column(QTreeWidgetItem*)), p, SLOT(rece_addColumn(QTreeWidgetItem*)));
    connect(items, SIGNAL(send_onTextChanged(QString, QTreeWidgetItem*)), p, SLOT(rece_TextChanged(QString, QTreeWidgetItem*)));
    connect(items, SIGNAL(send_currentIndexChanged(QString, QTreeWidgetItem*)), p, SLOT(rece_currentIndexChanged(QString, QTreeWidgetItem*)));
    return items;
}

void thriftwidget::on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    ItemWidget* items = createAndGetNode(this, item);
}

void thriftwidget::read_data()
{
    qDebug() << "收到数据";
}

void thriftwidget::rece_deleteItem(QTreeWidgetItem *item)
{
    qDebug() << "删除";
    QTreeWidgetItem* parent = item->parent();
    if (NULL==parent) {
        if (ui->treeWidget->topLevelItemCount() > 1) {
            int index = ui->treeWidget->indexOfTopLevelItem(item);
            ui->treeWidget->takeTopLevelItem(index);
            delete item;
        }
    } else {
        parent->removeChild(item);
        // 释放子节点的内存
        delete item;
    }

}

void thriftwidget::rece_addItem(QTreeWidgetItem *item)
{
    //qDebug() << "进入添加元素";
    //复制倒数第一个结构体
    //查找最后一个结构体
    isAddNode = true;
    ItemWidget * item_ = dynamic_cast<ItemWidget*>(item);
    int count = item_->childCount();
    ItemWidget* items = createAndGetNode(this, item_);

    //qDebug() << typeid(this).name();
    //qDebug() << "进入添加元素2";
    items->copyItem(this, items, dynamic_cast<ItemWidget*>(item_->child(0)));
    //qDebug() << "进入添加元素3";
    ItemWidget* items2 = new ItemWidget(item_);
    //qDebug() << "进入添加元素4";
    delete items2;
    //复制数据
    //首先child() 是struct
    

}

void thriftwidget::rece_addColumn(QTreeWidgetItem * item)
{
    //添加一列 获取item父节点 获取item所在位置 下一个位置插入新位置
    ItemWidget * item_ = dynamic_cast<ItemWidget*>(item);

    ItemWidget * item_parent = dynamic_cast<ItemWidget*>(item->parent());
    if (item_parent != NULL) {
        ItemWidget* items = createAndGetNode(this);
        item_parent->insertChild(item_parent->indexOfChild(item_) + 1, items);
        items->init2();
        ItemWidget* items2 = new ItemWidget(item_parent);
        delete items2;
    } else {
        //没有父节点
        ItemWidget* items = createAndGetNode(this); //ui->treeWidget
        int index = ui->treeWidget->indexOfTopLevelItem(item);
        ui->treeWidget->insertTopLevelItem(index + 1, items);
        //item_parent->insertChild(item_parent->indexOfChild(item_) + 1, items);
        items->init2();
        ItemWidget* items2 = new ItemWidget(ui->treeWidget);
        delete items2;
    }
}

void thriftwidget::rece_TextChanged(QString data, QTreeWidgetItem * item)
{
    if (!isAuto) {return;}
    ItemWidget * item_ = dynamic_cast<ItemWidget*>(item);
    if (data.length() > 0) {
        item_->checkBox->setChecked(true);
    } else {
        item_->checkBox->setChecked(false);
    }
    int count = ui->treeWidget->topLevelItemCount() - 1;
    int index = ui->treeWidget->indexOfTopLevelItem(item);
    bool isChild = false;
    ItemWidget * parentItem;
    if (index == -1) {
        //不是顶层节点，向上查找
        parentItem = dynamic_cast<ItemWidget*>(item->parent());
        if (parentItem) {
            qDebug() << "找到上层";
            count = parentItem->childCount() - 1;
            index = parentItem->indexOfChild(item_);
            isChild = true;
        }
    }

    if (!isChild && index >= count) {
        //顶层
        ItemWidget* items = createAndGetNode(this, ui->treeWidget);
        int index = ui->treeWidget->indexOfTopLevelItem(items);
        items->lineEditParamSN->setText(QString::number(index + 1));
        //刷新用
        ItemWidget* items2 = new ItemWidget(ui->treeWidget);
        delete items2;
    } else if (isChild && index >= count) {
        //子节点
        ItemWidget* items = createAndGetNode(this, parentItem);
        int index = parentItem->indexOfChild(items);
        items->lineEditParamSN->setText(QString::number(index + 1));
        //刷新用
        ItemWidget* items2 = new ItemWidget(parentItem);
        delete items2;
    } else if (data == "") {
        //删除gai
    }


    //获取当前焦点
    //QWidget *previousFocusedWidget = this->focusWidget();
//    ui->treeWidget->hide();
//    ui->treeWidget->show();
//    ui->treeWidget->style()->polish(ui->treeWidget);
    //previousFocusedWidget->setFocus();
}

void thriftwidget::rece_currentIndexChanged(QString data, QTreeWidgetItem *item)
{
    if (!isAuto) {return;}

    ItemWidget * item_ = dynamic_cast<ItemWidget*>(item);
    if (item_->comboBoxBase->currentText() == "map") {
        item_->lineEditParamValue->setReadOnly(false);
        item_->lineEditParamValue->setPlaceholderText("参数值");
        item_->comboBoxKey->show();
        item_->comboBoxValue->show();
        ui->treeWidget->header()->resizeSection(2, 450);  // 设置第三列宽度为500
        if (item_->comboBoxValue->currentText() == "struct") {
            //添加子节点
            item_->addNode->show();
            item_->keyLabel->hide();
            item_->valueLabel->hide();
            item_->classLabel->hide();
            item_->setExpanded(true);
            item_->lineEditParamValue->setReadOnly(true);
            item_->lineEditParamValue->setPlaceholderText("");
            ItemWidget* item2 = createAndGetNode(this, item_);
            //item2->setText(0, "");
            //子节点应为struct
            qDebug() << "走这里";
            item2->comboBoxBase->setCurrentText("struct");
            item2->keyLabel->show();
            item2->valueLabel->hide();
            item2->classLabel->hide();

            item2->lineEditParamValue->setPlaceholderText("key");
            item2->lineEditParamValue->setReadOnly(false);
        }

    } else if (item_->comboBoxBase->currentText() == "set" || item_->comboBoxBase->currentText() == "list") {
        item_->lineEditParamValue->setReadOnly(false);
        item_->lineEditParamValue->setPlaceholderText("参数值");
        item_->comboBoxKey->hide();
        item_->comboBoxValue->show();
        ui->treeWidget->header()->resizeSection(1, 300);  // 设置第二列宽度为500
        qDebug() << "创建1" << item_->comboBoxKey->currentText();
        if (item_->comboBoxValue->currentText() == "struct") {
            qDebug() << "创建2";
            //添加子节点
            ItemWidget* item2 = createAndGetNode(this, item_);
            item2->setText(0, "");
            //子节点应为struct
            item_->addNode->show();
            item_->keyLabel->hide();
            item_->valueLabel->hide();
            item_->classLabel->hide();
            item2->comboBoxBase->setCurrentText("struct");
            item2->keyLabel->hide();
            item2->valueLabel->hide();
            item2->classLabel->show();
            item_->setExpanded(true);

            item_->lineEditParamValue->setReadOnly(true);
            item_->lineEditParamValue->setPlaceholderText("");
            //item_->lineEditParamValue->hide();
            //item2->lineEditParamValue->hide();
        }
    } else if (item_->comboBoxBase->currentText() == "struct" && isAddNode != true) {
        //创建子节点
        item_->comboBoxKey->hide();
        item_->comboBoxValue->hide();

        item_->keyLabel->hide();
        item_->valueLabel->hide();
        item_->classLabel->show();

        item_->checkBox->setChecked(true);
        ItemWidget* item2 = createAndGetNode(this, item);

        int index = item->indexOfChild(item2);
        item2->lineEditParamSN->setText(QString::number(index + 1));

        item2->setText(0, "");
        item_->setExpanded(true);

        //向下创建同级节点 有问题，不一定是顶节点
        ItemWidget* items = createAndGetNode(this, ui->treeWidget);
        //设置序号
        int index2 = ui->treeWidget->indexOfTopLevelItem(items);
        items->lineEditParamSN->setText(QString::number(index2 + 1));

        ItemWidget* items2 = new ItemWidget(ui->treeWidget);
        delete items2;
        item_->lineEditParamValue->setReadOnly(true);
        item_->lineEditParamValue->setPlaceholderText("");

    } else {
        item_->lineEditParamValue->setReadOnly(false);
        item_->lineEditParamValue->setPlaceholderText("参数值");
        item_->comboBoxKey->hide();
        item_->comboBoxValue->hide();
        item_->keyLabel->hide();
        item_->valueLabel->show();
        item_->classLabel->hide();
        //ui->treeWidget->header()->resizeSection(1, 150);  // 设置第二列宽度为500
    }

    if (item_->comboBoxBase->currentText() != "struct" &&
            ((item_->comboBoxBase->currentText() == "list" || item_->comboBoxBase->currentText() == "set")
            && item_->comboBoxKey->currentText() != "struct") &&
            (item_->comboBoxBase->currentText() == "map" && item_->comboBoxKey->currentText() != "struct")) {
        //删除下面所有节点
        int childCount = item_->childCount();
        for (int i = childCount - 1; i >= 0; --i) {
            ItemWidget* childItem = dynamic_cast<ItemWidget*>(item_->takeChild(i));
            delete childItem;
        }
    }

    if (isAddNode == true) {
        isAddNode = false;
    }
}

void thriftwidget::on_toolButton_test_clicked()
{
    QTcpSocket *clientSocket = new QTcpSocket(this);
    QString port_str = ui->comboBox_port->currentText();
    int index_s = port_str.indexOf("(");
    int index_e = port_str.indexOf(")");
    int port = port_str.mid(index_s + 1, index_e - index_s - 1).toInt();
    clientSocket->connectToHost(ui->lineEdit_host->text(), port);
    if (!clientSocket->waitForConnected(500)) {
        qDebug() << "无法连接到服务器";
        ui->toolButton_test->setIcon(QIcon(":lib/node2.png"));
        ui->toolButton_test->setText("测试地址(不可访问，若开启了VPN，关闭后再试)");
        clientSocket->close();
    } else {
        qDebug() << "服务器可用";
        ui->toolButton_test->setIcon(QIcon(":lib/node.png"));
        ui->toolButton_test->setText("测试地址(可访问)");
        clientSocket->close();
    }
    return;
}

void thriftwidget::on_toolButton_show_thrift_info_clicked()
{
    if(ui->textEdit_info->isHidden()) {
        ui->textEdit_info->show();
        //ui->toolButton_show_thrift_info->setText("关闭thrift协议说明");
    } else {
        ui->textEdit_info->hide();
        //ui->toolButton_show_thrift_info->setText("查看thrift协议说明");
    }
}

void thriftwidget::on_textEdit_customContextMenuRequested(const QPoint &pos)
{
    //定义右键弹出菜单
    QMenu *menu = new QMenu(ui->textEdit);
    menu->setWindowFlags(menu->windowFlags()  | Qt::FramelessWindowHint | Qt::NoDropShadowWindowHint);
    menu->setAttribute(Qt::WA_TranslucentBackground);
    QAction *copy1 = new QAction("复制", ui->textEdit);
    QAction *all1 = new QAction("选择全部", ui->textEdit);
    //connect (pnew,SIGNAL(triggered()),this,SLOT(rece_addCommond_sgin()));
    //connect (pnew1,SIGNAL(triggered()),this,SLOT(rece_mkdirFolder_sgin()));
    menu->addAction(copy1);
    menu->addSeparator();
    menu->addAction(all1);
    menu->move(cursor().pos());
    menu->show();
}

void thriftwidget::on_comboBox_testType_currentIndexChanged(int index)
{
    if (index == 0) {
        //基础测试
        ui->widget_property->hide();
        ui->toolButton_request->show();
        ui->toolButton_save->show();
    } else {
        //性能测试
        ui->widget_property->show();
        ui->toolButton_request->hide();
        ui->toolButton_save->hide();
    }
}

void thriftwidget::on_toolButton_request_clicked()
{
    assembleTBinaryMessage();
    //请求数据
    QVector<uint32_t> sendData = string2Uint32List(dataList);
    ui->textEdit->clear();
    //ui->textEdit_headers->clear();
    ui->textEdit_data->clear();
    ui->textEdit->append("请求源数据：");
    QString dataTemp = "";
    int sum = 0;
    for (const QString& value : dataList) {
        //qDebug() << "value = " << value;
        dataTemp = dataTemp + value + "  ";  // 在控制台输出元素值
        //qDebug() << "dataTemp1 = " << dataTemp;
        sum++;
        //每8个段进行下一步
        if (sum == 8) {
            sum = 0;
            //qDebug() << "dataTemp2 = " << dataTemp;
            ui->textEdit->append(dataTemp);
            dataTemp = "";
        }
    }
    //打印剩下数据
    ui->textEdit->append(dataTemp);
    ui->textEdit->append("------------------------------------------------------------------------------");
    ui->textEdit->append("请求结果数据：");
    qDebug() << "dataList = " << dataList;
    qDebug() << "sendData = " << sendData;
    QElapsedTimer timer;
    timer.start();
    retractNum = 0;
    sendThriftRequest(sendData);
    qint64 elapsedMilliseconds = timer.elapsed();
    ui->label_time->setText("响应时间：" + QString::number(elapsedMilliseconds) + "ms");
    return;
}

void thriftwidget::on_toolButton_request_param_clicked()
{
    //入参折叠
    if (isToolButton_request_param_checked) {
        //隐藏
        ui->treeWidget->hide();
    } else {
        //显示
        ui->treeWidget->show();
    }
}

void thriftwidget::on_toolButton_response_clicked()
{
    //请求响应折叠
    if (isToolButton_response_checked) {
        ui->tabWidget_response->hide();
    } else {
        ui->tabWidget_response->show();
    }
}

void thriftwidget::on_toolButton_report_clicked()
{
    //性能报告折叠
    if (isToolButton_report_checked) {

    } else {

    }
}

void thriftwidget::on_checkBox_show_source_stateChanged(int arg1)
{
    // if (ui->checkBox_show_source->isChecked()) {
    //     ui->tab_source->show();
    // } else {
    //     ui->tab_source->hide();
    // }
}

void thriftwidget::on_textEdit_data_customContextMenuRequested(const QPoint &pos)
{
    QMenu *menu = new QMenu(ui->textEdit_data);
    menu->setWindowFlags(menu->windowFlags()  | Qt::FramelessWindowHint | Qt::NoDropShadowWindowHint);
    menu->setAttribute(Qt::WA_TranslucentBackground);
    QAction *copy1 = new QAction("复制", ui->textEdit_data);
    QAction *all1 = new QAction("选择全部", ui->textEdit_data);
    //connect (pnew,SIGNAL(triggered()),this,SLOT(rece_addCommond_sgin()));
    //connect (pnew1,SIGNAL(triggered()),this,SLOT(rece_mkdirFolder_sgin()));
    menu->addAction(copy1);
    menu->addSeparator();
    menu->addAction(all1);
    menu->move(cursor().pos());
    menu->show();
}

void thriftwidget::on_toolButton_inportFile_clicked()
{
    //解析thrift文件
    // 创建文件对话框
    QFileDialog dialog;
    
    // 设置文件过滤器
    dialog.setNameFilter("Thrift Files (*.thrift)");
    
    // 设置只能选择文件
    dialog.setFileMode(QFileDialog::ExistingFile);
    
    // 打开文件对话框
    if (dialog.exec()) {
        // 获取所选文件的路径
        QString selectedFile = dialog.selectedFiles().first();
        // 处理所选文件
        // 在这里你可以做你想做的事情，比如读取文件内容等等
        // 读取文件内容
        //这里应该添加一个最近路径
        QFile file(selectedFile);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            QString fileContent = in.readAll();
            QString fileContent2;
            QString fileContent3;
            QString funcServer;
            qDebug() << "File content:" << fileContent;
            fileContent.replace("\t", "");
            file.close();

            //查找server
            int index = fileContent.contains("service");
            if (index) {
                int index2 = fileContent.indexOf("service");


                fileContent2 = fileContent.mid(index2);

                int index3 = fileContent2.indexOf("{");
                funcServer = fileContent2.mid(0, index3).split(" ", QString::SkipEmptyParts)[1];
                qDebug() << "所属服务 = " << funcServer;
                fileContent2 = fileContent2.mid(index3 + 1);
                int index4 = fileContent2.indexOf("}");

                fileContent2 = fileContent2.mid(0, index4);

                //获取结构体部分
                fileContent3 = fileContent.mid(0, index2); //获取结构体部分 其实这就可以 暂时不考虑service后面还有struct

                //fileContent.replace(" ","");
                QStringList list = fileContent2.split("\n", QString::SkipEmptyParts);

                //开始循环解析接口部分
                for (int i = 0; i < list.length(); i++) {
                    //qDebug() << "接口部分：" << list[i];
                    QString func = list[i].trimmed();
                    int index5 = func.indexOf(" ");
                    QString funcParam = func.mid(0, index5);
                    QString funcName1 =func.mid(index5).trimmed();
                    qDebug() << "funcParam1 " << funcParam;
                    qDebug() << "funcName1 " << funcName1;

                    int index6 = funcName1.indexOf("(");
                    QString funcName = funcName1.mid(0, index6);
                    //qDebug() << "funcName " << funcName;
                    QString funcParam2 = funcName1.mid(index6 + 1);
                    int index7 = funcParam2.indexOf(")");
                    funcParam2 = funcParam2.mid(0, index7);
                    qDebug() << "funcParam2 " << funcParam2;
                    funcParamInMap.insert(funcName, getFuncInParams(funcParam2));
                    funcParamOutMap.insert(funcName, getFuncOutParams(funcParam));
                    QStringList funcP = funcParam2.split(",");

                    for(int i =0; i < funcP.length(); i++) {
                        qDebug() << "参数为" << funcP[i].split(" ", QString::SkipEmptyParts);
                    }

                    QListWidgetItem *item1 = new QListWidgetItem(funcName + " : " + funcServer);
                    // 创建一个QIcon对象并设置图标
                    QIcon icon1(":/lib/api.png"); // 设置您的图标路径
                    // 为项设置图标
                    item1->setIcon(icon1);
                    // 将项添加到列表中
                    ui->listWidget->addItem(item1);
                    //ui->listWidget->addItem(funcName);
                }

            }

            //查找struct
            //找struct关键字
            //找{}确定一个，再找下一个。直到没有
            while(true) {
                if (fileContent3.contains("struct")) {
                    //获取结构体名
                    int index_ = fileContent3.indexOf("struct");
                    int index = fileContent3.indexOf("{");

                    QString structName = fileContent3.mid(index_ + 7, index - index_ - 7 - 1);

                    int index2 = fileContent3.indexOf("}");
                    QString data = fileContent3.mid(index + 1, index2 - index - 1);
                    fileContent3 = fileContent3.mid(index2 + 1);
                    //data.replace("\n"," ");
                    qDebug() << "获取的struct name = " << structName << " data = " << data;
                    structParamMap.insert(structName, getStructParams(data));
                } else {
                    break; 
                }
            }

        } else {
            qDebug() << "Failed to open file:" << file.errorString();
        }
    }
}

void thriftwidget::on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    int index = current->text().indexOf(":");
    if (index == 0) {
        index = current->text().length();
    }
    QString funcName2 = current->text().mid(0, index - 1);
    qDebug() << "funcName2 = " << funcName2;
    ui->lineEdit_funcName->setText(funcName2);
    ui->treeWidget->clear();
    //循环获取参数
    for(int i =1; i <= funcParamInMap.value(funcName2).size(); i++) {
        //QMap<QString, paramInfo>
        qDebug() << " sn = " << i
                << " paramType = " << funcParamInMap.value(funcName2).value(QString::number(i)).paramType
                << " paramName" << funcParamInMap.value(funcName2).value(QString::number(i)).paramName;
        

        ItemWidget* items = createAndGetNode(this, ui->treeWidget);
        items->setParamValue(this, QString::number(i),
            funcParamInMap.value(funcName2).value(QString::number(i)).paramName,
            funcParamInMap.value(funcName2).value(QString::number(i)).paramType,
            funcParamInMap.value(funcName2).value(QString::number(i)).typeSign);

    }
}

