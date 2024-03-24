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
#include <cstdlib>
#pragma comment(lib, "ws2_32.lib")

ItemWidget::ItemWidget(QTreeWidget *parent) : QTreeWidgetItem(parent, 1)
{
    qDebug() << "走1";
    init();
    parent->setItemWidget(this, 0, widgetParamName);
    parent->setItemWidget(this, 1, widgetParamType);
    parent->setItemWidget(this, 2, widgetParamValue);
    qDebug() << "走11";
}

ItemWidget::ItemWidget(QTreeWidgetItem *parent): QTreeWidgetItem(parent, 1)
{
    qDebug() << "走2";
    init();
    treeWidget()->setItemWidget(this, 0, widgetParamName);
    treeWidget()->setItemWidget(this, 1, widgetParamType);
    treeWidget()->setItemWidget(this, 2, widgetParamValue);
}

ItemWidget::ItemWidget(): QTreeWidgetItem()
{
    init();
    qDebug() << "走333333";
}

void ItemWidget::init()
{
    comboBoxBase = new QComboBox();
    comboBoxBase->addItem("bool");
    comboBoxBase->addItem("byte");
    comboBoxBase->addItem("i16");
    comboBoxBase->addItem("i32");
    comboBoxBase->addItem("i64");
    comboBoxBase->addItem("double");
    comboBoxBase->addItem("string");
    comboBoxBase->addItem("struct");
    comboBoxBase->addItem("map");
    comboBoxBase->addItem("set");
    comboBoxBase->addItem("list");
    comboBoxBase->setCurrentIndex(3);
    comboBoxBase->setMinimumHeight(29);
    comboBoxBase->setView(new QListView());  //必须设置

    connect(comboBoxBase, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),[=]{
        emit send_currentIndexChanged(comboBoxBase->currentText(), this);
    });

    comboBoxKey = new QComboBox();
    comboBoxKey->addItem("bool");
    comboBoxKey->addItem("byte");
    comboBoxKey->addItem("i16");
    comboBoxKey->addItem("i32");
    comboBoxKey->addItem("i64");
    comboBoxKey->addItem("double");
    comboBoxKey->addItem("string");
    //comboBoxKey->addItem("struct");
    //comboBoxKey->addItem("map");
    //comboBoxKey->addItem("set");
    //comboBoxKey->addItem("list");
    comboBoxKey->setCurrentIndex(0);
    comboBoxKey->setMinimumHeight(29);
    comboBoxKey->hide();

    comboBoxKey->setView(new QListView());  //必须设置

    connect(comboBoxKey, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),[=]{
        emit send_currentIndexChanged(comboBoxKey->currentText(), this);
    });

    comboBoxValue = new QComboBox();
    comboBoxValue->addItem("bool");
    comboBoxValue->addItem("byte");
    comboBoxValue->addItem("i16");
    comboBoxValue->addItem("i32");
    comboBoxValue->addItem("i64");
    comboBoxValue->addItem("double");
    comboBoxValue->addItem("string");
    comboBoxValue->addItem("struct");
    comboBoxValue->addItem("map");
    comboBoxValue->addItem("set");
    comboBoxValue->addItem("list");
    comboBoxValue->setCurrentIndex(0);
    comboBoxValue->setMinimumHeight(29);
    comboBoxValue->hide();

    comboBoxValue->setView(new QListView());  //必须设置

    connect(comboBoxValue, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),[=]{
        emit send_currentIndexChanged(comboBoxValue->currentText(), this);
    });

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

    checkBox = new QCheckBox("");
    checkBox->setChecked(false);
    checkBox->setMinimumHeight(30);
    checkBox->setToolTip("勾选参数参与请求");

    moveButton = new QToolButton();
    moveButton->setIcon(QIcon(":lib/tuodong.png"));
    moveButton->setIconSize(QSize(20, 20));

    qDebug() << "走这里22";
    addNode = new QToolButton();
    addNode->setText("添加元素");
    addNode->setToolTip("将根据已有的struct格式快速生成");
    connect(addNode,&QToolButton::clicked,[=]{
        qDebug() << "触发信号";
        emit send_buttonClicked_add(this);
    });
    addNode->setStyleSheet("QToolButton {\
                           font: 10pt \"OPPOSans B\";\
                           color: rgb(255, 255, 255);\
                           background-color: rgb(250, 118, 0);\
                           border-radius: 0px;\
                       }\
                       QToolButton::menu-indicator { \
                           image: None;\
                       }\
                       QToolButton:hover {\
                           color: rgb(255, 255, 255);\
                           background-color: rgb(250, 118, 0);\
                       }");
    addNode->setMinimumHeight(29);
    addNode->hide();
    layoutParamName = new QHBoxLayout();
    layoutParamName->setContentsMargins(0, 0, 0, 0);
    layoutParamName->addWidget(checkBox);
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
    layoutParamValue->setContentsMargins(5, 0, 0, 0);
    keyLabel = new QLabel();
    keyLabel->setAlignment(Qt::AlignCenter);
    keyLabel->setText("KEY");
    keyLabel->setStyleSheet("font: 8pt \"OPPOSans B\";color: rgb(255, 255, 255);background-color: rgb(0, 234, 93);border-radius: 3px;");
    keyLabel->setMinimumWidth(34);
    keyLabel->setMaximumWidth(34);
    keyLabel->setMaximumHeight(15);


    valueLabel = new QLabel();
    valueLabel->setAlignment(Qt::AlignCenter);
    valueLabel->setText("VALUE");
    valueLabel->setStyleSheet("font: 8pt \"OPPOSans B\";color: rgb(255, 255, 255);background-color: rgb(255, 80, 95);border-radius: 3px;");
    valueLabel->setMinimumWidth(50);
    valueLabel->setMaximumWidth(50);
    valueLabel->setMaximumHeight(15);

    classLabel = new QLabel();
    classLabel->setAlignment(Qt::AlignCenter);
    classLabel->setText("OBJECT");
    classLabel->setStyleSheet("font: 8pt \"OPPOSans B\";color: rgb(255, 255, 255);background-color: rgb(7, 143, 255);border-radius: 3px;");
    classLabel->setMinimumWidth(55);
    classLabel->setMaximumWidth(55);
    classLabel->setMaximumHeight(15);


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
    qDebug() << "走这里233";
}

void ItemWidget::init2()
{
    treeWidget()->setItemWidget(this, 0, widgetParamName);
    treeWidget()->setItemWidget(this, 1, widgetParamType);
    treeWidget()->setItemWidget(this, 2, widgetParamValue);
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
            ItemWidget* items = new ItemWidget(this);
            connect(items, SIGNAL(send_buttonClicked(QTreeWidgetItem*)), p, SLOT(rece_deleteItem(QTreeWidgetItem*)));
            connect(items, SIGNAL(send_buttonClicked_add(QTreeWidgetItem*)), p, SLOT(rece_addItem(QTreeWidgetItem*)));
            connect(items, SIGNAL(send_buttonClicked_add_column(QTreeWidgetItem*)), p, SLOT(rece_addColumn(QTreeWidgetItem*)));
            connect(items, SIGNAL(send_onTextChanged(QString, QTreeWidgetItem*)), p, SLOT(rece_TextChanged(QString, QTreeWidgetItem*)));
            connect(items, SIGNAL(send_currentIndexChanged(QString, QTreeWidgetItem*)), p, SLOT(rece_currentIndexChanged(QString, QTreeWidgetItem*)));
            //复制子节点数据
            ItemWidget* item_c = dynamic_cast<ItemWidget*>(item_->child(i));
            items->comboBoxBase->setCurrentIndex(item_c->comboBoxBase->currentIndex());
            if (item_c->checkBox->isChecked()) {
                items->checkBox->setChecked(true);
            }
        }
    }
}

thriftwidget::thriftwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::thriftwidget)
{
    ui->setupUi(this);

    // 设置树的列数（如果需要多列）
    ui->treeWidget->setColumnCount(3);
    // 设置第一列的宽度为 100 像素
    ui->treeWidget->setColumnWidth(0, 120);

    // 设置第三列的宽度为 150 像素
    ui->treeWidget->setColumnWidth(1, 150);

    // 计算第五列的宽度，使其占满剩余空间
    int lastColumnWidth = ui->treeWidget->viewport()->width() - 120 - 150;
    ui->treeWidget->setColumnWidth(2, lastColumnWidth);

    QHeaderView* header = ui->treeWidget->header();

    // 设置所有列的大小调整模式为 Interactive
    header->setSectionResizeMode(QHeaderView::Interactive);

    // 设置默认的列高度为 30 像素
    header->setDefaultSectionSize(200);
    ui->treeWidget->header()->resizeSection(1, 150);
    // 创建一个树节点
    ItemWidget* item = new ItemWidget(ui->treeWidget);
    connect(item, SIGNAL(send_buttonClicked(QTreeWidgetItem*)), this, SLOT(rece_deleteItem(QTreeWidgetItem*)));
    connect(item, SIGNAL(send_buttonClicked_add(QTreeWidgetItem*)), this, SLOT(rece_addItem(QTreeWidgetItem*)));
    connect(item, SIGNAL(send_buttonClicked_add_column(QTreeWidgetItem*)), this, SLOT(rece_addColumn(QTreeWidgetItem*)));
    connect(item, SIGNAL(send_onTextChanged(QString, QTreeWidgetItem*)), this, SLOT(rece_TextChanged(QString, QTreeWidgetItem*)));
    connect(item, SIGNAL(send_currentIndexChanged(QString, QTreeWidgetItem*)), this, SLOT(rece_currentIndexChanged(QString, QTreeWidgetItem*)));

    item->setText(0, "");
     // 添加树节点到树控件中
     ui->treeWidget->addTopLevelItem(item);

     QAction *action = new QAction(this);
     action->setIcon(QIcon(":/lib/soucuo.png"));
     ui->lineEdit_find->addAction(action,QLineEdit::LeadingPosition);

     ui->comboBox_protocol->setView(new QListView());
     ui->comboBox_transport->setView(new QListView());
     ui->comboBox_reqType->setView(new QListView());

     ui->splitter->setStretchFactor(0, 5);  // 第一个子控件占 1/3 的显示空间
     ui->splitter->setStretchFactor(1, 3);  // 第二个子控件占 2/3 的显示空间

     ui->splitter_2->setStretchFactor(0, 2);  // 第一个子控件占 1/3 的显示空间
     ui->splitter_2->setStretchFactor(1, 1);  // 第二个子控件占 2/3 的显示空间

     ui->widget_thrift->hide();
     ui->label_req->hide();

     ui->textEdit->setContextMenuPolicy(Qt::CustomContextMenu);

     ui->stackedWidget->setCurrentIndex(0);
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
    QString lastValue = "";
    if (dataList.length() > 1) {
        lastValue = dataList.last();
        if (lastValue.length() < 8) {
            //lastValue = lastValue.leftJustified(8, '0');
            dataList.replace(dataList.size() - 1, lastValue);
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
            qDebug() << "lastValue = " << lastValue <<  " & len = " << len << " & data.length() = " << data.length() << "& 8-len = " << 8-len;
            if (data.length() >= 8-len) {
                dataList.replace(dataList.size() - 1, lastValue + data.mid(0, 8-len));
                qDebug() << "string2stringList1 value = " << lastValue + data.mid(0, 8-len);
                data = data.mid(8-len);
            } else {
                dataList.replace(dataList.size() - 1, lastValue + data);
                qDebug() << "string2stringList2 value = " << lastValue + data;
                data = "";
            }
        } else {
            if (data.length() < 8) {
                dataList.append(data);
                qDebug() << "string2stringList3 value = " << data;
                data = "";
            } else {
                dataList.append(data.mid(0, 8));
                qDebug() << "string2stringList4 value = " << data.mid(0, 8);
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
        qDebug() << "接收到的数据（十六进制字符串）:";
        std::array<uint32_t, 2000> receivedDataArray{0};
        qint64 bytesReceived = clientSocket->read(reinterpret_cast<char*>(receivedDataArray.data()),
                                                  receivedDataArray.size() * sizeof(uint32_t));
        // 将数据转换为主机字节序
        QStringList dataList2;
        QString dataTemp;
        int countLength = -1; //设置数据长度，到达后不再读取 加上开头长度数据
        int nowLength = 0; //设置数据长度，到达后不再读取
        for (uint32_t data : receivedDataArray) {
            data = qFromBigEndian(data);
            std::stringstream stream;
            stream << std::hex << std::setw(8) << std::setfill('0') << data;
            dataList2.append(QString::fromStdString(stream.str()));
            dataTemp = dataTemp + " " + QString::fromStdString(stream.str());
            if (countLength == -1) {
                countLength = 4 + strtol(dataList2[0].toStdString().c_str(), nullptr, 16);
                qDebug() << "countLength = " << countLength;
            }
            nowLength = nowLength + 4;
            if (nowLength > countLength) {
                qDebug() << "超过有效数据长度";
                ui->stackedWidget->setCurrentIndex(0);
                break;
            }
        }
        ui->textEdit->append(dataTemp);
        ui->textEdit->append("----------------------------------------------------------------------");
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
    //qDebug() << "ui->lineEdit_host->text() = " << ui->lineEdit_host->text() << " ui->lineEdit_port->text().toInt() = " << ui->lineEdit_port->text().toInt();
    clientSocket->connectToHost(ui->lineEdit_host->text(), ui->lineEdit_port->text().toInt());
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
        qDebug() << "int64 = " << value;
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
          qDebug() << "reversedString = " << d_hex.mid(d_hex.length()-2);
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
        qDebug() << "struct 参数类型为" << valueType << " 参数值为" << value;
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
                qDebug() << "int64 = " << value;
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
                qDebug() << "reversedString = " << d_hex.mid(d_hex.length()-2);
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
            qDebug() << "len长度为" << len;
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
    int sum = 0;
    int first = 0;
    int end = 0;
    int len = data.length();
    for (int i = 0; i <= len; i++) {
        if (data[i] == '{') {
            sum++;
            if (sum == 1) {
                first = i;
            }
        }
        if (data[i] == '}') {
            sum--;
            if (sum == 0) {
                end = i;
                QString da = data.mid(first+1, end - first - 1);
                dataList.push_back(da);
            }
        }
    }
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
    qDebug() << "writeTBinaryTypeAndSerialNumber type = " << type << " & serialNumberStr = " << serialNumberStr;
}

void thriftwidget::writeTBinaryBaseMessage(QString valueType, QString value)
{
    qDebug() << "writeTBinaryBaseMessage valueType = " << valueType << " & value = " << valueType;
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
        //设置key类型
        writeTBinaryTypeMessage(paramValueType);
        //设置元素个数
        QStringList dataList;
        writeTBinaryKeySize(dataList, value);

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

        if (baseType.contains(paramKeyType)) {
            //设置元素值
            for (const QString &str : dataList) {
                int index = str.indexOf(":");
                //设置key值
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
    dataList.insert(0, dataLength);
}

void thriftwidget::writeTBinaryTypeMessage(QString type_)
{
    QString type = QString("%1").arg(mapType.value(type_), 2, 16, QLatin1Char('0'));
    string2stringList(type);
}

void thriftwidget::writeTBinaryKeySize(QStringList &dataList, QString value)
{
    QString data = value.mid(1, value.length() - 2);
    dataList = data.split(",");
    QString lenData = QString("%1").arg(dataList.length(), 8, 16, QLatin1Char('0'));
    string2stringList(lenData);
}

void thriftwidget::writeTBinaryValueSize(QStringList &dataList, QString value)
{
    QString data = value.mid(1, value.length() - 2);
    map2List(dataList, data);
    QString lenData = QString("%1").arg(dataList.length(), 8, 16, QLatin1Char('0'));
    string2stringList(lenData);
}




void thriftwidget::parseData()
{

}


void thriftwidget::on_toolButton_clicked()
{
    //buildData();
    assembleTBinaryMessage();
    //请求数据
    QVector<uint32_t> a = string2Uint32List(dataList);
    ui->textEdit->clear();
    ui->textEdit->append("请求源数据：");
    QString dataTemp = "";
    for (const QString& value : dataList) {
        dataTemp = dataTemp + value + " ";  // 在控制台输出元素值
    }
    ui->textEdit->append(dataTemp);
    ui->textEdit->append("----------------------------------------------------------------------");
    ui->textEdit->append("请求结果数据：");
    qDebug() << "dataList = " << dataList;
    QElapsedTimer timer;
    timer.start();
    sendThriftRequest(a);
    qint64 elapsedMilliseconds = timer.elapsed();
    ui->label_time->setText("响应时间：" + QString::number(elapsedMilliseconds) + "ms");
    return;
}

void thriftwidget::on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    ItemWidget* items = new ItemWidget(item);
    connect(items, SIGNAL(send_buttonClicked(QTreeWidgetItem*)), this, SLOT(rece_deleteItem(QTreeWidgetItem*)));
    connect(items, SIGNAL(send_buttonClicked_add(QTreeWidgetItem*)), this, SLOT(rece_addItem(QTreeWidgetItem*)));
    connect(items, SIGNAL(send_buttonClicked_add_column(QTreeWidgetItem*)), this, SLOT(rece_addColumn(QTreeWidgetItem*)));
    connect(items, SIGNAL(send_onTextChanged(QString, QTreeWidgetItem*)), this, SLOT(rece_TextChanged(QString, QTreeWidgetItem*)));
    connect(items, SIGNAL(send_currentIndexChanged(QString, QTreeWidgetItem*)), this, SLOT(rece_currentIndexChanged(QString, QTreeWidgetItem*)));

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
    qDebug() << "进入添加元素";
    //复制倒数第一个结构体
    //查找最后一个结构体
    isAddNode = true;
    ItemWidget * item_ = dynamic_cast<ItemWidget*>(item);
    int count = item_->childCount();
    ItemWidget* items = new ItemWidget(item_);

    qDebug() << typeid(this).name();
    connect(items, SIGNAL(send_buttonClicked(QTreeWidgetItem*)), this, SLOT(rece_deleteItem(QTreeWidgetItem*)));
    connect(items, SIGNAL(send_buttonClicked_add(QTreeWidgetItem*)), this, SLOT(rece_addItem(QTreeWidgetItem*)));
    connect(items, SIGNAL(send_buttonClicked_add_column(QTreeWidgetItem*)), this, SLOT(rece_addColumn(QTreeWidgetItem*)));
    connect(items, SIGNAL(send_onTextChanged(QString, QTreeWidgetItem*)), this, SLOT(rece_TextChanged(QString, QTreeWidgetItem*)));
    connect(items, SIGNAL(send_currentIndexChanged(QString, QTreeWidgetItem*)), this, SLOT(rece_currentIndexChanged(QString, QTreeWidgetItem*)));
    qDebug() << "进入添加元素2";
    items->copyItem(this, items, dynamic_cast<ItemWidget*>(item_->child(0)));
    qDebug() << "进入添加元素3";
    ItemWidget* items2 = new ItemWidget(item_);
    qDebug() << "进入添加元素4";
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
        ItemWidget* items = new ItemWidget();
        item_parent->insertChild(item_parent->indexOfChild(item_) + 1, items);
        items->init2();
        connect(items, SIGNAL(send_buttonClicked(QTreeWidgetItem*)), this, SLOT(rece_deleteItem(QTreeWidgetItem*)));
        connect(items, SIGNAL(send_buttonClicked_add(QTreeWidgetItem*)), this, SLOT(rece_addItem(QTreeWidgetItem*)));
        connect(items, SIGNAL(send_buttonClicked_add_column(QTreeWidgetItem*)), this, SLOT(rece_addColumn(QTreeWidgetItem*)));
        connect(items, SIGNAL(send_onTextChanged(QString, QTreeWidgetItem*)), this, SLOT(rece_TextChanged(QString, QTreeWidgetItem*)));
        connect(items, SIGNAL(send_currentIndexChanged(QString, QTreeWidgetItem*)), this, SLOT(rece_currentIndexChanged(QString, QTreeWidgetItem*)));
        ItemWidget* items2 = new ItemWidget(item_parent);
        delete items2;
    } else {
        //没有父节点
        ItemWidget* items = new ItemWidget(); //ui->treeWidget
        int index = ui->treeWidget->indexOfTopLevelItem(item);
        ui->treeWidget->insertTopLevelItem(index + 1, items);
        //item_parent->insertChild(item_parent->indexOfChild(item_) + 1, items);
        items->init2();
        //qDebug() << "2 item_parent->indexOfChild(item_) + 1 = " << item_parent->indexOfChild(item_) + 1;
        connect(items, SIGNAL(send_buttonClicked(QTreeWidgetItem*)), this, SLOT(rece_deleteItem(QTreeWidgetItem*)));
        connect(items, SIGNAL(send_buttonClicked_add(QTreeWidgetItem*)), this, SLOT(rece_addItem(QTreeWidgetItem*)));
        connect(items, SIGNAL(send_buttonClicked_add_column(QTreeWidgetItem*)), this, SLOT(rece_addColumn(QTreeWidgetItem*)));
        connect(items, SIGNAL(send_onTextChanged(QString, QTreeWidgetItem*)), this, SLOT(rece_TextChanged(QString, QTreeWidgetItem*)));
        connect(items, SIGNAL(send_currentIndexChanged(QString, QTreeWidgetItem*)), this, SLOT(rece_currentIndexChanged(QString, QTreeWidgetItem*)));
        ItemWidget* items2 = new ItemWidget(ui->treeWidget);
        delete items2;
    }
}

void thriftwidget::rece_TextChanged(QString data, QTreeWidgetItem * item)
{
    qDebug() << "修改";
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
    qDebug() << "count" << count;
    qDebug() << "index" << index;
    if (!isChild && index >= count) {
        ItemWidget* items = new ItemWidget(ui->treeWidget);
        connect(items, SIGNAL(send_buttonClicked(QTreeWidgetItem*)), this, SLOT(rece_deleteItem(QTreeWidgetItem*)));
        connect(items, SIGNAL(send_buttonClicked_add(QTreeWidgetItem*)), this, SLOT(rece_addItem(QTreeWidgetItem*)));
        connect(items, SIGNAL(send_buttonClicked_add_column(QTreeWidgetItem*)), this, SLOT(rece_addColumn(QTreeWidgetItem*)));
        connect(items, SIGNAL(send_onTextChanged(QString, QTreeWidgetItem*)), this, SLOT(rece_TextChanged(QString, QTreeWidgetItem*)));
        connect(items, SIGNAL(send_currentIndexChanged(QString, QTreeWidgetItem*)), this, SLOT(rece_currentIndexChanged(QString, QTreeWidgetItem*)));
        ItemWidget* items2 = new ItemWidget(ui->treeWidget);
        delete items2;
    } else if (isChild && index >= count) {
        ItemWidget* items = new ItemWidget(parentItem);
        connect(items, SIGNAL(send_buttonClicked(QTreeWidgetItem*)), this, SLOT(rece_deleteItem(QTreeWidgetItem*)));
        connect(items, SIGNAL(send_buttonClicked_add(QTreeWidgetItem*)), this, SLOT(rece_addItem(QTreeWidgetItem*)));
        connect(items, SIGNAL(send_buttonClicked_add_column(QTreeWidgetItem*)), this, SLOT(rece_addColumn(QTreeWidgetItem*)));
        connect(items, SIGNAL(send_onTextChanged(QString, QTreeWidgetItem*)), this, SLOT(rece_TextChanged(QString, QTreeWidgetItem*)));
        connect(items, SIGNAL(send_currentIndexChanged(QString, QTreeWidgetItem*)), this, SLOT(rece_currentIndexChanged(QString, QTreeWidgetItem*)));
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
    
    ItemWidget * item_ = dynamic_cast<ItemWidget*>(item);
    if (item_->comboBoxBase->currentText() == "map") {
        item_->lineEditParamValue->setReadOnly(false);
        item_->lineEditParamValue->setPlaceholderText("参数值");
        item_->comboBoxKey->show();
        item_->comboBoxValue->show();
        ui->treeWidget->header()->resizeSection(1, 450);  // 设置第二列宽度为500
        if (item_->comboBoxValue->currentText() == "struct") {
            //添加子节点
            item_->addNode->show();
            item_->keyLabel->hide();
            item_->valueLabel->hide();
            item_->classLabel->hide();
            item_->setExpanded(true);
            item_->lineEditParamValue->setReadOnly(true);
            item_->lineEditParamValue->setPlaceholderText("");
            ItemWidget* item2 = new ItemWidget(item_);
            connect(item2, SIGNAL(send_buttonClicked(QTreeWidgetItem*)), this, SLOT(rece_deleteItem(QTreeWidgetItem*)));
            connect(item2, SIGNAL(send_buttonClicked_add(QTreeWidgetItem*)), this, SLOT(rece_addItem(QTreeWidgetItem*)));
            connect(item2, SIGNAL(send_buttonClicked_add_column(QTreeWidgetItem*)), this, SLOT(rece_addColumn(QTreeWidgetItem*)));
            connect(item2, SIGNAL(send_onTextChanged(QString, QTreeWidgetItem*)), this, SLOT(rece_TextChanged(QString, QTreeWidgetItem*)));
            connect(item2, SIGNAL(send_currentIndexChanged(QString, QTreeWidgetItem*)), this, SLOT(rece_currentIndexChanged(QString, QTreeWidgetItem*)));
            //item2->setText(0, "");
            //子节点应为struct
            qDebug() << "走这里";
            item2->comboBoxBase->setCurrentIndex(7);
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
            ItemWidget* item2 = new ItemWidget(item_);
            connect(item2, SIGNAL(send_buttonClicked(QTreeWidgetItem*)), this, SLOT(rece_deleteItem(QTreeWidgetItem*)));
            connect(item2, SIGNAL(send_buttonClicked_add(QTreeWidgetItem*)), this, SLOT(rece_addItem(QTreeWidgetItem*)));
            connect(item2, SIGNAL(send_buttonClicked_add_column(QTreeWidgetItem*)), this, SLOT(rece_addColumn(QTreeWidgetItem*)));
            connect(item2, SIGNAL(send_onTextChanged(QString, QTreeWidgetItem*)), this, SLOT(rece_TextChanged(QString, QTreeWidgetItem*)));
            connect(item2, SIGNAL(send_currentIndexChanged(QString, QTreeWidgetItem*)), this, SLOT(rece_currentIndexChanged(QString, QTreeWidgetItem*)));
            item2->setText(0, "");
            //子节点应为struct
            item_->addNode->show();
            item_->keyLabel->hide();
            item_->valueLabel->hide();
            item_->classLabel->hide();
            item2->comboBoxBase->setCurrentIndex(7);
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
        ItemWidget* item2 = new ItemWidget(item);
        connect(item2, SIGNAL(send_buttonClicked(QTreeWidgetItem*)), this, SLOT(rece_deleteItem(QTreeWidgetItem*)));
        connect(item2, SIGNAL(send_buttonClicked_add(QTreeWidgetItem*)), this, SLOT(rece_addItem(QTreeWidgetItem*)));
        connect(item2, SIGNAL(send_buttonClicked_add_column(QTreeWidgetItem*)), this, SLOT(rece_addColumn(QTreeWidgetItem*)));
        connect(item2, SIGNAL(send_onTextChanged(QString, QTreeWidgetItem*)), this, SLOT(rece_TextChanged(QString, QTreeWidgetItem*)));
        connect(item2, SIGNAL(send_currentIndexChanged(QString, QTreeWidgetItem*)), this, SLOT(rece_currentIndexChanged(QString, QTreeWidgetItem*)));
        item2->setText(0, "");
        item_->setExpanded(true);
        //向下创建同级节点
        ItemWidget* items = new ItemWidget(ui->treeWidget);
        connect(items, SIGNAL(send_buttonClicked(QTreeWidgetItem*)), this, SLOT(rece_deleteItem(QTreeWidgetItem*)));
        connect(items, SIGNAL(send_buttonClicked_add(QTreeWidgetItem*)), this, SLOT(rece_addItem(QTreeWidgetItem*)));
        connect(items, SIGNAL(send_buttonClicked_add_column(QTreeWidgetItem*)), this, SLOT(rece_addColumn(QTreeWidgetItem*)));
        connect(items, SIGNAL(send_onTextChanged(QString, QTreeWidgetItem*)), this, SLOT(rece_TextChanged(QString, QTreeWidgetItem*)));
        connect(items, SIGNAL(send_currentIndexChanged(QString, QTreeWidgetItem*)), this, SLOT(rece_currentIndexChanged(QString, QTreeWidgetItem*)));
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
    clientSocket->connectToHost(ui->lineEdit_host->text(), ui->lineEdit_port->text().toInt());
    if (!clientSocket->waitForConnected(500)) {
        qDebug() << "无法连接到服务器";
        ui->toolButton_test->setIcon(QIcon(":lib/node2.png"));
        ui->toolButton_test->setText("测试地址(不可访问)");
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
    if(ui->widget_thrift->isHidden()) {
        ui->widget_thrift->show();
        //ui->toolButton_show_thrift_info->setText("关闭thrift协议说明");
    } else {
        ui->widget_thrift->hide();
        //ui->toolButton_show_thrift_info->setText("查看thrift协议说明");
    }
}

void thriftwidget::on_textEdit_customContextMenuRequested(const QPoint &pos)
{
    //定义右键弹出菜单
    QMenu *menu = new QMenu(ui->textEdit);
    menu->setWindowFlags(menu->windowFlags()  | Qt::FramelessWindowHint | Qt::NoDropShadowWindowHint);
    menu->setAttribute(Qt::WA_TranslucentBackground);
    QAction *pnew = new QAction("复制", ui->textEdit);
    QAction *pnew1 = new QAction("选择全部", ui->textEdit);
    //connect (pnew,SIGNAL(triggered()),this,SLOT(rece_addCommond_sgin()));
    //connect (pnew1,SIGNAL(triggered()),this,SLOT(rece_mkdirFolder_sgin()));
    menu->addAction(pnew);
    menu->addSeparator();
    menu->addAction(pnew1);
    menu->move(cursor().pos());
    menu->show();
}
