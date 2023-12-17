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
#pragma comment(lib, "ws2_32.lib")

ItemWidget::ItemWidget(QTreeWidget *parent) : QTreeWidgetItem(parent, 1)
{
    init();
    parent->setItemWidget(this, 0, widgetParamName);
    parent->setItemWidget(this, 1, widgetParamType);
    parent->setItemWidget(this, 2, lineEditParamValue);
    parent->setItemWidget(this, 3, widgetParamDescribe);
}

ItemWidget::ItemWidget(QTreeWidgetItem *parent): QTreeWidgetItem(parent, 1)
{
    init();
    treeWidget()->setItemWidget(this, 0, widgetParamName);
    treeWidget()->setItemWidget(this, 1, widgetParamType);
    treeWidget()->setItemWidget(this, 2, lineEditParamValue);
    treeWidget()->setItemWidget(this, 3, widgetParamDescribe);
}

void ItemWidget::init()
{
    comboBoxBase = new QComboBox();
    comboBoxBase->addItem("bool");
    comboBoxBase->addItem("btye");
    comboBoxBase->addItem("i16");
    comboBoxBase->addItem("i32");
    comboBoxBase->addItem("i64");
    comboBoxBase->addItem("double");
    comboBoxBase->addItem("string");
    comboBoxBase->addItem("struct");
    comboBoxBase->addItem("map");
    comboBoxBase->addItem("set");
    comboBoxBase->addItem("list");
    comboBoxBase->setCurrentIndex(0);
    comboBoxBase->setMinimumWidth(80);
    comboBoxBase->setMaximumWidth(80);

    comboBoxKey = new QComboBox();
    comboBoxKey->addItem("bool");
    comboBoxKey->addItem("btye");
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
    comboBoxKey->setMinimumWidth(80);
    comboBoxKey->setMaximumWidth(80);
    comboBoxKey->hide();

    comboBoxValue = new QComboBox();
    comboBoxValue->addItem("bool");
    comboBoxValue->addItem("btye");
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
    comboBoxValue->setMinimumWidth(80);
    comboBoxValue->setMaximumWidth(80);

    comboBoxValue->hide();

    lineEditParamName = new QLineEdit();
    lineEditParamName->setPlaceholderText("参数名");
    lineEditParamValue = new QLineEdit();
    lineEditParamValue->setPlaceholderText("参数值");
    connect(lineEditParamValue,&QLineEdit::textChanged,[=]{
        emit send_onTextChanged(lineEditParamValue->text(), this);
    });

    lineEditParamDescribe = new QLineEdit();
    lineEditParamDescribe->setPlaceholderText("参数描述");
    lineEditParamDescribe->setMinimumWidth(80);
    deleteButton = new QToolButton();
    deleteButton->setIcon(QIcon(":lib/delete.png"));
    deleteButton->setIconSize(QSize(20, 20));

    connect(deleteButton,&QToolButton::clicked,[=]{
        emit send_buttonClicked(this);
    });
    checkBox = new QCheckBox("");
    checkBox->setChecked(true);

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

    layoutParamDescribe = new QHBoxLayout();
    layoutParamDescribe->setContentsMargins(0, 0, 0, 0);
    layoutParamDescribe->addWidget(lineEditParamDescribe);
    layoutParamDescribe->addWidget(deleteButton);
    widgetParamDescribe = new QWidget();
    widgetParamDescribe->setLayout(layoutParamDescribe);

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
    ui->treeWidget->setColumnCount(4);
    // 设置第一列的宽度为 100 像素
    ui->treeWidget->setColumnWidth(0, 100);

    // 设置第三列的宽度为 150 像素
    ui->treeWidget->setColumnWidth(1, 100);

    // 设置第四列的宽度为 150 像素
    ui->treeWidget->setColumnWidth(2, 100);

    // 计算第五列的宽度，使其占满剩余空间
    int lastColumnWidth = ui->treeWidget->viewport()->width() - 100 - 100 - 100;
    ui->treeWidget->setColumnWidth(3, lastColumnWidth);

    // 创建一个树节点
    ItemWidget* item = new ItemWidget(ui->treeWidget);
    connect(item, SIGNAL(send_buttonClicked(QTreeWidgetItem*)), this, SLOT(rece_deleteItem(QTreeWidgetItem*)));
    connect(item, SIGNAL(send_onTextChanged(QString, QTreeWidgetItem*)), this, SLOT(rece_TextChanged(QString, QTreeWidgetItem*)));

    item->setText(0, "");

    // 创建一个按钮控件
    // button->setMaximumWidth(50);
    // button2->setMaximumWidth(50);
    // button3->setMaximumWidth(50);
     // 添加树节点到树控件中
     ui->treeWidget->addTopLevelItem(item);
//     for(int i = 0; i <= 2; i++) {
//         ItemWidget* item2 = new ItemWidget(ui->treeWidget);
//         ui->treeWidget->addTopLevelItem(item2);
//     }
//     ItemWidget* item3 = new ItemWidget(ui->treeWidget);
//     ItemWidget* item4 = new ItemWidget(ui->treeWidget);
     //     ItemWidget* item5 = new ItemWidget(ui->treeWidget);
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
            lastValue = lastValue.leftJustified(8, '0');
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
        std::array<uint32_t, 8> receivedDataArray{0};
        qint64 bytesReceived = clientSocket->read(reinterpret_cast<char*>(receivedDataArray.data()),
                                                  receivedDataArray.size() * sizeof(uint32_t));

        // 将数据转换为主机字节序
        ui->textEdit->clear();
        for (uint32_t data : receivedDataArray) {
            //qDebug() << "接收数据" << data;
            data = qFromBigEndian(data);
            //qDebug() << "转换后后" << data;
            std::stringstream stream;
            stream << std::hex << std::setw(8) << std::setfill('0') << data;
            qDebug() << QString::fromStdString(stream.str());
            ui->textEdit->append(QString::fromStdString(stream.str()));
        }
        clientSocket->close();
    });
    qDebug() << "ui->lineEdit_port->text() = " << ui->lineEdit_port->text() << " ui->lineEdit_port->text().toInt() = " << ui->lineEdit_port->text().toInt();
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

    //    std::array<uint32_t, 11> dataArray = {0x80010001, 0x0000000b, 0x796f7572, 0x4d657468, 0x6f643200, \
    //                                            0x0000000a, 0x00010000, 0x00000000, 0x00080800, 0x02000000, 0x09000000};

    for (uint32_t& data : dataArray) {
        data = qToBigEndian(data);
        qDebug() << data;
    }
    qDebug() << "发送数据1";
    //connect(clientSocket,SIGNAL(readyRead()),this,SLOT(read_data()));
    qint64 bytesSent = clientSocket->write(reinterpret_cast<char*>(dataArray.data()), dataArray.size() * sizeof(uint32_t));
    if (bytesSent != dataArray.size() * sizeof(uint32_t)) {
        qDebug() << "发送数据失败";
        //clientSocket.close();
        return ;
    }
    qDebug() << "发送数据2";
}


void thriftwidget::on_toolButton_clicked()
{
    dataList.clear();
    dataList.resize(0);
    string2stringList("80010001");
    //方法名
    //qDebug() << "方法名" << ui->lineEdit_funcName->text();
    //方法名长度 四个字节固定表示
    int funcLen = ui->lineEdit_funcName->text().length();
    QString hexString = QString("%1").arg(funcLen, 8, 16, QLatin1Char('0'));
    qDebug() << "=====1";
    string2stringList(hexString);
    qDebug() << "=====2";
    //qDebug() << hexString; // 打印16进制字符串

    QByteArray byteArray = ui->lineEdit_funcName->text().toUtf8(); // 将字符串转换为字节数组
    QString hexString2 = byteArray.toHex(); // 将字节数组转换为十六进制字符串
    string2stringList(hexString2);
    string2stringList("00000000");
    // 按照4字节分割字符串
//    QStringList hexBytes;
//    for (int i = 0; i < hexString2.size(); i += 8) {
//        QString byte = hexString2.mid(i, 8);
//        hexBytes.append(byte);
//    }

//    // 打印每个4字节的十六进制字符串
//    for (const QString& byte : hexBytes) {
//        qDebug() << byte;
//    }

    for(int i = 0; i < ui->treeWidget->topLevelItemCount(); i++) {
        ItemWidget * item = dynamic_cast<ItemWidget*>(ui->treeWidget->topLevelItem(i));
           qDebug() << "参数类型为" << item->comboBoxBase->currentText() << " 参数值为" << item->lineEditParamValue->text();
           if (item->comboBoxBase->currentText() == "i64") {
               QString type = QString("%1").arg(THRIFT_I64_TYPE, 2, 16, QLatin1Char('0'));
               string2stringList(type);
               qDebug() << "type = " << type;
               QString type2 = QString("%1").arg(i+1, 4, 16, QLatin1Char('0'));
               string2stringList(type2);
               qDebug() << "type2 = " << type2;
               int value = item->lineEditParamValue->text().toInt();
               QString hexString3 = QString("%1").arg(value, 16, 16, QLatin1Char('0'));
               string2stringList(hexString3);
               qDebug() << "hexString3 = " << hexString3;
           } else if (item->comboBoxBase->currentText() == "i32") {
               QString type = QString("%1").arg(THRIFT_I32_TYPE, 2, 16, QLatin1Char('0'));
               string2stringList(type);
               QString type2 = QString("%1").arg(i+1, 4, 16, QLatin1Char('0'));
               string2stringList(type2);
               int value = item->lineEditParamValue->text().toInt();
               QString hexString3 = QString("%1").arg(value, 8, 16, QLatin1Char('0'));
               string2stringList(hexString3);
           }
    }
    QVector<uint32_t> a = string2Uint32List(dataList);
    qDebug() << "dataList = " << dataList;
    sendThriftRequest(a);
    //qDebug() << "a = " << a;
//    uint32_t a = 0x80010001;
//    QString c = "0x80010001";
//    uint32_t d = c.toUInt(nullptr, 16);
//    qDebug() << "a = " << a;
//    qDebug() << "d = " << d;
    return;
}

void thriftwidget::on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    ItemWidget* items = new ItemWidget(item);
    connect(items, SIGNAL(send_buttonClicked(QTreeWidgetItem*)), this, SLOT(rece_deleteItem(QTreeWidgetItem*)));
    connect(items, SIGNAL(send_onTextChanged(QString, QTreeWidgetItem*)), this, SLOT(rece_TextChanged(QString, QTreeWidgetItem*)));
}

void thriftwidget::read_data()
{
    qDebug() << "收到数据";
}

void thriftwidget::on_toolButton_2_clicked()
{
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

void thriftwidget::rece_TextChanged(QString data, QTreeWidgetItem * item)
{
    qDebug() << "修改";
    int count = ui->treeWidget->topLevelItemCount() - 1;
    int index = ui->treeWidget->indexOfTopLevelItem(item);
    qDebug() << "count" << count;
    qDebug() << "index" << index;
    if (index >= count) {
        ItemWidget* items = new ItemWidget(ui->treeWidget);
        connect(items, SIGNAL(send_buttonClicked(QTreeWidgetItem*)), this, SLOT(rece_deleteItem(QTreeWidgetItem*)));
        connect(items, SIGNAL(send_onTextChanged(QString, QTreeWidgetItem*)), this, SLOT(rece_TextChanged(QString, QTreeWidgetItem*)));
    } else if (data == "") {
        //删除gai
    }

}
