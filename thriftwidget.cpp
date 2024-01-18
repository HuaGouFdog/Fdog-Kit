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
#pragma comment(lib, "ws2_32.lib")

ItemWidget::ItemWidget(QTreeWidget *parent) : QTreeWidgetItem(parent, 1)
{
    init();
    parent->setItemWidget(this, 0, widgetParamName);
    parent->setItemWidget(this, 1, widgetParamType);
    parent->setItemWidget(this, 2, widgetParamValue);
    //parent->setItemWidget(this, 3, widgetParamDescribe);
}

ItemWidget::ItemWidget(QTreeWidgetItem *parent): QTreeWidgetItem(parent, 1)
{
    init();
    treeWidget()->setItemWidget(this, 0, widgetParamName);
    treeWidget()->setItemWidget(this, 1, widgetParamType);
    treeWidget()->setItemWidget(this, 2, widgetParamValue);
    //treeWidget()->setItemWidget(this, 3, widgetParamDescribe);
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
    comboBoxBase->setMinimumHeight(30);
    //comboBoxBase->setMaximumWidth(90);

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
    comboBoxKey->addItem("struct");
    comboBoxKey->addItem("map");
    comboBoxKey->addItem("set");
    comboBoxKey->addItem("list");
    comboBoxKey->setCurrentIndex(0);
    comboBoxKey->setMinimumHeight(30);
    //comboBoxKey->setMaximumWidth(90);
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
    comboBoxKey->setMinimumHeight(30);
    //comboBoxValue->setMaximumWidth(90);

    comboBoxValue->hide();

    comboBoxValue->setView(new QListView());  //必须设置

    connect(comboBoxValue, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),[=]{
        emit send_currentIndexChanged(comboBoxValue->currentText(), this);
    });

    //comboBoxValue->setStyleSheet("QComboBox QAbstractItemView::item{height:28px;font: 10pt \"OPPOSans B\";}");

    lineEditParamName = new QLineEdit();
    lineEditParamName->setPlaceholderText("参数名");
    lineEditParamValue = new QLineEdit();
    lineEditParamValue->setPlaceholderText("参数值");
    connect(lineEditParamValue,&QLineEdit::textChanged,[=]{
        emit send_onTextChanged(lineEditParamValue->text(), this);
    });

//    lineEditParamDescribe = new QLineEdit();
//    lineEditParamDescribe->setPlaceholderText("参数描述");
//    lineEditParamDescribe->setMinimumWidth(80);
    deleteButton = new QToolButton();
    deleteButton->setIcon(QIcon(":lib/delete.png"));
    deleteButton->setIconSize(QSize(20, 20));
    deleteButton->setMinimumWidth(30);
    connect(deleteButton,&QToolButton::clicked,[=]{
        emit send_buttonClicked(this);
    });
    checkBox = new QCheckBox("");
    checkBox->setChecked(false);

    moveButton = new QToolButton();
    moveButton->setIcon(QIcon(":lib/tuodong.png"));
    moveButton->setIconSize(QSize(20, 20));

    layoutParamName = new QHBoxLayout();
    layoutParamName->setContentsMargins(0, 0, 0, 0);
    layoutParamName->addWidget(checkBox);
    layoutParamName->addWidget(lineEditParamName);
    widgetParamName = new QWidget();
    widgetParamName->setLayout(layoutParamName);

    layoutParamType = new QHBoxLayout();
    layoutParamType->setContentsMargins(0, 0, 0, 0);
    layoutParamType->addWidget(comboBoxBase);
    layoutParamType->addWidget(comboBoxKey);
    layoutParamType->addWidget(comboBoxValue);
    widgetParamType = new QWidget();
    widgetParamType->setLayout(layoutParamType);

    layoutParamValue = new QHBoxLayout();
    layoutParamValue->setContentsMargins(0, 0, 0, 0);
    layoutParamValue->addWidget(lineEditParamValue);
    layoutParamValue->addWidget(deleteButton);
    widgetParamValue = new QWidget();
    widgetParamValue->setLayout(layoutParamValue);

    label = new QLabel("xxxxxxx");

}

ItemWidget::~ItemWidget()
{

}

thriftwidget::thriftwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::thriftwidget)
{
    ui->setupUi(this);
    //ui->treeWidget->setStyle(QStyleFactory::create("windows"));
    // comboBox->setCurrentIndex(0);
    // comboBox->setMaximumWidth(100);

    // 设置树的列数（如果需要多列）
    ui->treeWidget->setColumnCount(3);
    // 设置第一列的宽度为 100 像素
    ui->treeWidget->setColumnWidth(0, 120);

    // 设置第三列的宽度为 150 像素
    ui->treeWidget->setColumnWidth(1, 270);

    // 设置第四列的宽度为 150 像素
//    ui->treeWidget->setColumnWidth(2, 100);

    // 计算第五列的宽度，使其占满剩余空间
    int lastColumnWidth = ui->treeWidget->viewport()->width() - 120 - 270;
    ui->treeWidget->setColumnWidth(2, lastColumnWidth);

    QHeaderView* header = ui->treeWidget->header();

    // 设置所有列的大小调整模式为 Interactive
    header->setSectionResizeMode(QHeaderView::Interactive);

    // 设置默认的列高度为 30 像素
    header->setDefaultSectionSize(200);

    // 创建一个树节点
    ItemWidget* item = new ItemWidget(ui->treeWidget);
    connect(item, SIGNAL(send_buttonClicked(QTreeWidgetItem*)), this, SLOT(rece_deleteItem(QTreeWidgetItem*)));
    connect(item, SIGNAL(send_onTextChanged(QString, QTreeWidgetItem*)), this, SLOT(rece_TextChanged(QString, QTreeWidgetItem*)));
    connect(item, SIGNAL(send_currentIndexChanged(QString, QTreeWidgetItem*)), this, SLOT(rece_currentIndexChanged(QString, QTreeWidgetItem*)));

    item->setText(0, "");
    // 创建一个按钮控件
    // button->setMaximumWidth(50);
    // button2->setMaximumWidth(50);
    // button3->setMaximumWidth(50);
     // 添加树节点到树控件中
     ui->treeWidget->addTopLevelItem(item);

     QAction *action = new QAction(this);
     action->setIcon(QIcon(":/lib/soucuo.png"));
     ui->lineEdit_find->addAction(action,QLineEdit::LeadingPosition);

     ui->comboBox_protocol->setView(new QListView());
     ui->comboBox_transport->setView(new QListView());
     ui->comboBox_reqType->setView(new QListView());

     //设置水平滑动条
//     QHeaderView *pHeader=ui->treeWidget->header();
//     pHeader->setSectionResizeMode(QHeaderView::ResizeToContents);
//     pHeader->setStretchLastSection(false);

     ui->splitter->setStretchFactor(0, 5);  // 第一个子控件占 1/3 的显示空间
     ui->splitter->setStretchFactor(1, 3);  // 第二个子控件占 2/3 的显示空间

     ui->splitter_2->setStretchFactor(0, 2);  // 第一个子控件占 1/3 的显示空间
     ui->splitter_2->setStretchFactor(1, 1);  // 第二个子控件占 2/3 的显示空间

     ui->widget_thrift->hide();
}

void thriftwidget::sendData()
{
    QTcpSocket *clientSocket = new QTcpSocket(this);
    //收到数据，触发readyRead
      connect(clientSocket,&QTcpSocket::readyRead,[=]{
          //没有可读的数据就返回
          qDebug() << "接收到的数据（十六进制字符串）：";
          // 接收数据
          std::array<uint32_t, 8> receivedDataArray{0};
          qint64 bytesReceived = clientSocket->read(reinterpret_cast<char*>(receivedDataArray.data()),
                                                   receivedDataArray.size() * sizeof(uint32_t));

          // 将数据转换为主机字节序
          for (uint32_t data : receivedDataArray) {
              //qDebug() << "接收数据" << data;
              data = qFromBigEndian(data);
              //qDebug() << "转换后后" << data;
              std::stringstream stream;
              stream << std::hex << std::setw(8) << std::setfill('0') << data;
              qDebug() << QString::fromStdString(stream.str());
          }
          clientSocket->close();
      });
    clientSocket->connectToHost("172.16.8.154", 9090);
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

    std::array<uint32_t, 11> dataArray = {0x80010001, 0x0000000b, 0x796f7572, 0x4d657468, 0x6f643200, \
                                            0x0000000a, 0x00010000, 0x00000000, 0x00080800, 0x02000000, 0x09000000};

    for (uint32_t& data : dataArray) {
        data = qToBigEndian(data);
        qDebug() << data;
    }

    //connect(clientSocket,SIGNAL(readyRead()),this,SLOT(read_data()));
    qint64 bytesSent = clientSocket->write(reinterpret_cast<char*>(dataArray.data()), dataArray.size() * sizeof(uint32_t));
    if (bytesSent != dataArray.size() * sizeof(uint32_t)) {
        qDebug() << "发送数据失败";
        //clientSocket.close();
        return ;
    }
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
    //获取最后一个值，判断长度是否够8
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
            if (data.length() >= 8-len) {
                dataList.replace(dataList.size() - 1, lastValue + data.mid(0, 8-len));
                data = data.mid(8-len);
            } else {
                dataList.replace(dataList.size() - 1, lastValue + data);
                data = "";
            }
        } else {
            if (data.length() < 8) {
                dataList.append(data);
                data = "";
            } else {
                dataList.append(data.mid(0, 8));
                data = data.mid(8);
            }
        }
    }
}

void thriftwidget::sendThriftRequest(QVector<uint32_t> dataArray)
{
    QTcpSocket *clientSocket = new QTcpSocket(this);
    //收到数据，触发readyRead
    connect(clientSocket,&QTcpSocket::readyRead,[=]{
        //没有可读的数据就返回
        qDebug() << "接收到的数据（十六进制字符串）：";
        std::array<uint32_t, 20> receivedDataArray{0};
        qint64 bytesReceived = clientSocket->read(reinterpret_cast<char*>(receivedDataArray.data()),
                                                  receivedDataArray.size() * sizeof(uint32_t));
        // 将数据转换为主机字节序
        QStringList dataList2;
        QString dataTemp;
        for (uint32_t data : receivedDataArray) {
            data = qFromBigEndian(data);
            std::stringstream stream;
            stream << std::hex << std::setw(8) << std::setfill('0') << data;
            dataList2.append(QString::fromStdString(stream.str()));
            dataTemp = dataTemp + " " + QString::fromStdString(stream.str());
        }
        ui->textEdit->append(dataTemp);
        ui->textEdit->append("----------------------------------------------------------------------");
        if (dataList2[1] == "80010002") {
            //结果
            ui->label_req->setText("REPLY");
            ui->label_req->setStyleSheet("color: rgb(255, 255, 255);background-color: rgb(27, 161, 58);padding-left:5px;padding-right:5px;");
        } else if (dataList2[1] == "80010003") {
            //异常
            ui->label_req->setText("EXCEPTION");
            ui->label_req->setStyleSheet("color: rgb(255, 255, 255);background-color: rgb(181, 11, 11);padding-left:5px;padding-right:5px;");
        } else {
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
        if (baseType.contains(valueType)) {
            baseSerialize(sum + 1, valueType, item->lineEditParamValue->text());
        } else if (containerType.contains(valueType)) {
            containerSerialize(sum + 1, valueType, item->lineEditParamValue->text(), item->comboBoxKey->currentText(), item->comboBoxValue->currentText());
        } else if (valueType == "struct") {

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
        int value_i = value.toDouble();
        QString valueData = QString("%1").arg(value_i, mapSize.value(valueType), 16, QLatin1Char('0'));
        string2stringList(valueData);
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
        //设置值 获取数值型
        for (const QString &str : dataList) {
            QString strData = QString("%1").arg(str, mapSize.value(key_Type), QLatin1Char('0'));
            string2stringList(strData);
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
        QString lenData = QString("%1").arg(dataList.length(), 8, 16, QLatin1Char('0'));
        string2stringList(lenData);
        //设置元素值
        for (const QString &str : dataList) {
            //根据:获取key和value
            int index = str.indexOf(":");
            //设置key值
            QString strData = QString("%1").arg(str.mid(0, index), mapSize.value(key_Type), QLatin1Char('0'));
            string2stringList(strData);
            //设置value值
            QString strData2 = QString("%1").arg(str.mid(index+1), mapSize.value(value_Type), QLatin1Char('0'));
            string2stringList(strData2);
        }
    } else {
        qDebug() << "出错";
    }
}

void thriftwidget::structSerialize(int serialNumber, QString valueType, QString value)
{
    //组合结构体
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
                QString da = data.mid(first, end - first + 1);
                dataList.push_back(da);
            }
        }
    }
}


//void thriftwidget::objectSerialize()
//{

//}

//void thriftwidget::serialize(int serialNumber, QString valueType, QString value)
//{
//    //获取到类型
//    int objectType = 0;
//    switch (objectType) {
//        case OBJECT_BASE:
//        //基础类型
//        baseSerialize()
//        break;
//        case OBJECT_STRUCT:
        
//        //复杂类型
//        break;
//    }
    

    
//}

void thriftwidget::parseData()
{

}


void thriftwidget::on_toolButton_clicked()
{
    buildData();

    //请求数据
    QVector<uint32_t> a = string2Uint32List(dataList);
    ui->textEdit->clear();
    ui->textEdit->append("请求源数据：");
    QString dataTemp;
    for (const QString& value : dataList) {
        dataTemp = dataTemp + " " + value;  // 在控制台输出元素值
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
        if (ui->treeWidget->topLevelItemCount() > 2) {
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
    QTreeWidgetItem* parentItem;
    if (index == -1) {
        //不是顶层节点，向上查找
        parentItem = item->parent();
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
        connect(items, SIGNAL(send_onTextChanged(QString, QTreeWidgetItem*)), this, SLOT(rece_TextChanged(QString, QTreeWidgetItem*)));
        connect(items, SIGNAL(send_currentIndexChanged(QString, QTreeWidgetItem*)), this, SLOT(rece_currentIndexChanged(QString, QTreeWidgetItem*)));
    } else if (isChild && index >= count) {
        ItemWidget* items = new ItemWidget(parentItem);
        connect(items, SIGNAL(send_buttonClicked(QTreeWidgetItem*)), this, SLOT(rece_deleteItem(QTreeWidgetItem*)));
        connect(items, SIGNAL(send_onTextChanged(QString, QTreeWidgetItem*)), this, SLOT(rece_TextChanged(QString, QTreeWidgetItem*)));
        connect(items, SIGNAL(send_currentIndexChanged(QString, QTreeWidgetItem*)), this, SLOT(rece_currentIndexChanged(QString, QTreeWidgetItem*)));
    } else if (data == "") {
        //删除gai
    }

}

void thriftwidget::rece_currentIndexChanged(QString data, QTreeWidgetItem *item)
{
    
    ItemWidget * item_ = dynamic_cast<ItemWidget*>(item);
    qDebug() << "进入1 " << item_->comboBoxBase->currentText();
    qDebug() << "进入2 " << item_->comboBoxKey->currentText();
    if (item_->comboBoxBase->currentText() == "struct" || item_->comboBoxKey->currentText() == "struct") {
        qDebug() << "选择struct";
        ItemWidget* item2 = new ItemWidget(item);
        connect(item2, SIGNAL(send_buttonClicked(QTreeWidgetItem*)), this, SLOT(rece_deleteItem(QTreeWidgetItem*)));
        connect(item2, SIGNAL(send_onTextChanged(QString, QTreeWidgetItem*)), this, SLOT(rece_TextChanged(QString, QTreeWidgetItem*)));
        connect(item2, SIGNAL(send_currentIndexChanged(QString, QTreeWidgetItem*)), this, SLOT(rece_currentIndexChanged(QString, QTreeWidgetItem*)));
        item2->setText(0, "");

        // ItemWidget* items = new ItemWidget(ui->treeWidget);
        // connect(items, SIGNAL(send_buttonClicked(QTreeWidgetItem*)), this, SLOT(rece_deleteItem(QTreeWidgetItem*)));
        // connect(items, SIGNAL(send_onTextChanged(QString, QTreeWidgetItem*)), this, SLOT(rece_TextChanged(QString, QTreeWidgetItem*)));
        // connect(items, SIGNAL(send_currentIndexChanged(QString, QTreeWidgetItem*)), this, SLOT(rece_currentIndexChanged(QString, QTreeWidgetItem*)));
        item_->setExpanded(true);
    } else if (item_->comboBoxBase->currentText() == "map") {
        item_->comboBoxKey->show();
        item_->comboBoxValue->show();
    } else if (item_->comboBoxBase->currentText() == "set") {
        item_->comboBoxKey->show();
    } else if (item_->comboBoxBase->currentText() == "list") {
        item_->comboBoxKey->show();
    } else {
        item_->comboBoxKey->hide();
        item_->comboBoxValue->hide();
    }
}

void thriftwidget::on_comboBox_currentIndexChanged(const QString &arg1)
{

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
