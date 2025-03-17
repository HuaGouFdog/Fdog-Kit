#pragma execution_character_set("utf-8")
#include <QDateTime>
#include "thriftwidget.h"
#include "ui_thriftwidget.h"
#include <QPushButton>
#include <QStyleFactory>
#include <array>
#include <QProcess>
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
#include <QGraphicsDropShadowEffect>
#include <QFontDatabase>
#include <QClipboard>
#include <QMimeData>
#include <QCompleter>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QNetworkConfiguration>
#include <QNetworkConfigurationManager>
#include <QNetworkSession>
#include <QSslCipher>
#include <QSslEllipticCurve>
//#include <QtWidgets/QApplication>
//#include <QtCharts>
#include "module_utils/utils.h"
#include <numeric>
#include <QValueAxis>
#include <QProcess>
#pragma comment(lib, "ws2_32.lib")


void writeDataArrayToFile(const QVector<uint32_t>& dataArray, const QString& filePath) {
    // 打开文件以写入二进制数据
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly)) {
        qDebug() << "无法打开文件进行写入:" << file.errorString();
        return;
    }

    // 将 dataArray 转换为 char*
    QByteArray data;
    data.append(reinterpret_cast<const char*>(&dataArray), sizeof(uint32_t));

    // 写入数据到文件
    qint64 bytesWritten = file.write(data.constData(), data.size());
    if (bytesWritten != data.size()) {
        qDebug() << "写入文件失败:" << file.errorString();
    } else {
        qDebug() << "数据已成功写入文件:" << filePath;
    }

    // 关闭文件
    file.close();
}

void writeQByteArrayToFile(const QByteArray& dataArray, const QString& filePath) {
    // 打开文件以写入二进制数据
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly)) {
        qDebug() << "无法打开文件进行写入:" << file.errorString();
        return;
    }

    // // 将 dataArray 转换为 char*
    // QByteArray data;
    // data.append(reinterpret_cast<const char*>(&dataArray), sizeof(uint32_t));

    // 写入数据到文件
    file.write(dataArray);
    //qint64 bytesWritten =
//    if (bytesWritten != data.size()) {
//        qDebug() << "写入文件失败:" << file.errorString();
//    } else {
//        qDebug() << "数据已成功写入文件:" << filePath;
//    }
    qDebug() << "数据已成功写入文件:" << filePath;

    // 关闭文件
    file.close();

    /*
    QDir dir;
    dir.mkpath("thriftConfig");
    */
}


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
    {THRIFT_FUNC_NAME, new QColor(221,101,71)},
    {THRIFT_SN, new QColor(82,222,217)},
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
    {THRIFT_VALUE, new QColor(170, 255, 255)},
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
    comboBoxBase = new NoWheelQComboBox();
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

    comboBoxKey = new NoWheelQComboBox();
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

    comboBoxValue = new NoWheelQComboBox();
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
    lineEditParamValue->setPlaceholderText("value");
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
    layoutParamValue->setContentsMargins(0, 0, 10, 0);
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


    layoutParamValue->addWidget(valueLabel);
    layoutParamValue->addWidget(classLabel);
    layoutParamValue->addWidget(keyLabel);
    layoutParamValue->addWidget(lineEditParamValue);
    layoutParamValue->addWidget(addColumnButton);
    layoutParamValue->addWidget(deleteButton);
    widgetParamValue = new QWidget();
    widgetParamValue->setLayout(layoutParamValue);

    label = new QLabel("xxxxxxx");

    keyLabel->hide();
    valueLabel->show();
    classLabel->hide();

    //this->setMouseTracking(true);
    // 这里对子控件也进行了设置，是因为如果不对子控件设置，当鼠标移动到子控件上时，不会发送mouseMoveEvent事件，也就获取不到当前鼠标位置，无法判断鼠标状态及显示样式了。
//    QList<QWidget*> widgetList = this->findChildren<QWidget*>();
//    for(int i = 0; i < widgetList.length(); i ++) {
//        widgetList[i]->setMouseTracking(true);
//    }
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

    if (item_->mastLabel->isHidden()) {
        this->mastLabel->hide();
    } else {
        this->mastLabel->show();
    }

    if (item_->checkBox->isHidden()) {
        this->checkBox->hide();
    } else {
        this->checkBox->show();
    }

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
    qDebug()<< "sn2 = " << QString::number(item_p->childCount());
    this->lineEditParamSN->setText(QString::number(item_p->childCount()));
    this->lineEditParamName->setText(item_->lineEditParamName->text());
    this->lineEditParamValue->setText(item_->lineEditParamValue->text());

    if (item_->lineEditParamValue->isReadOnly()) {
        this->lineEditParamValue->setReadOnly(true);
    }

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

void ItemWidget::setParamSN(int str)
{
    lineEditParamSN->setText(QString::number(str));
}

void ItemWidget::setParamName(QString str)
{
    lineEditParamName->setText(str);
}

void ItemWidget::setParamType(QString str)
{
    lineEditParamValue->setText(str);
}

void ItemWidget::setParamValue(thriftwidget * p, int sn, QString name, QString type, QString typeSign)
{
    isAuto = false;
    setExpanded(true);
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
        checkBox->setChecked(false);
    }

    lineEditParamSN->setText(QString::number(sn));
    lineEditParamName->setText(name);
    //暂时只考虑一层
    if (type.startsWith("map")) {
        //复杂类型
        comboBoxBase->setCurrentText("map");
        //qDebug() << "怀疑";
        int index_s =  type.indexOf("map<");
        int index_e =  type.indexOf(">", index_s + 4);
        QString type_s = type.mid(index_s + 4, index_e - index_s - 4);
        //qDebug() << "map type_s = " << type_s;
        //目前只支持基础类型作为key
        QString key = type_s.split(",", QString::SkipEmptyParts)[0].replace(" ", "");
        //qDebug() << "map key = " << key;

        QString value = type_s.split(",", QString::SkipEmptyParts)[1].replace(" ", "");
        //qDebug() << "map value = " << value;
        if (baseType.contains(key)) {
            //基础类型
            comboBoxKey->setCurrentText(key);
            comboBoxKey->show();
            //qDebug() << "基础类型";
        } else {
            qDebug() << "出错";
        }

        if (baseType.contains(value)) {
            //基础类型
            comboBoxValue->setCurrentText(value);
            //qDebug() << "基础类型";
            comboBoxValue->show();
        } else {
            //复杂类型
            //qDebug() << "进入" << "setParamValue_interior_map";
            setParamValue_interior_map(p, value);
        }


    } else if (type.startsWith("set")) {
        //复杂类型
        comboBoxBase->setCurrentText("set");
        //获取 先这样写,默认就一成，里面要么基础类型，要么结构体
        int index_s =  type.indexOf("set<");
        int index_e =  type.indexOf(">", index_s + 4);
        QString type_s = type.mid(index_s + 4, index_e - index_s - 4);
        //qDebug() << "set type_s = " << type_s;
        if (baseType.contains(type_s)) {
            //基础类型
            comboBoxValue->setCurrentText(type_s);
            comboBoxValue->show();
            //qDebug() << "基础类型";
        } else {
            //复杂类型
            setParamValue_interior(p, type_s);
        }

    } else if (type.startsWith("list")) {
        //复杂类型
        comboBoxBase->setCurrentText("list");
        //获取list里面的值
        int index_s =  type.indexOf("list<");
        int index_e =  type.indexOf(">", index_s + 5);
        QString type_s = type.mid(index_s + 5, index_e - index_s - 5);
        //qDebug() << "list type_s = " << type_s;
        if (baseType.contains(type_s)) {
            //基础类型
            comboBoxValue->setCurrentText(type_s);
            comboBoxValue->show();
            //qDebug() << "基础类型";

        } else {
            //复杂类型
            setParamValue_interior(p, type_s);
        }

    } else if (baseType.contains(type)) {
        //基础类型
        //qDebug() << "设置基础类型";
        comboBoxBase->setCurrentText(type);
        //匹配预制数据
        if (preDataMap.contains(name) && preDataMap[name] != "${}") {
            lineEditParamValue->setText(preDataMap[name]);
            if (typeSign == "optional") {
                checkBox->setChecked(true);
            }
        } else if(preDataMap.contains(name)) {
            //不存在呢？
            lineEditParamValue->setText(preDataMapV[name].at(0));
            if (typeSign == "optional") {
                checkBox->setChecked(true);
            }
            lineEditParamValue->setToolTip("该值存在多个预制值，压测模式中，将按照顺序使用预测值");
            QAction *action = new QAction(this);
            action->setIcon(QIcon(":/lib/testParam.svg"));
            lineEditParamValue->addAction(action,QLineEdit::TrailingPosition);
        }

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

        int index_ = type.lastIndexOf(".");
        if (index_ != -1) {
            type = type.mid(index_ + 1);
        }

        if (structParamMap.value(type).size() > 0) {
            QMap<int, structInfo> temp = structParamMap.value(type);
            for (const auto &key : temp.keys()) {
                ItemWidget* items = thriftwidget::createAndGetNode(p, this);
                items->setParamValue(p, key,
                    temp[key].paramName,
                    temp[key].paramType,
                    temp[key].typeSign);
            }
        }
    }
    isAuto = true;
}

void ItemWidget::setParamValue_interior(thriftwidget * p, QString type_s) {
    isAuto = false;
    comboBoxValue->setCurrentText("struct");
    //qDebug() << "复杂类型";
    //创建子节点
    keyLabel->hide();
    valueLabel->hide();
    classLabel->hide();
    addNode->show();
    comboBoxValue->show();

    lineEditParamValue->setReadOnly(true);
    lineEditParamValue->setPlaceholderText("");
    lineEditParamValue->setText(type_s);
    ItemWidget* items = thriftwidget::createAndGetNode(p, this);
    items->lineEditParamValue->setText(type_s);
    
    items->comboBoxBase->setCurrentText("struct");
    items->keyLabel->hide();
    items->valueLabel->hide();
    items->classLabel->show();
    //items->lineEditParamName->setText(name);
    items->lineEditParamValue->setReadOnly(true);
    items->lineEditParamValue->setPlaceholderText("");
    items->lineEditParamSN->setText("1");
    items->checkBox->setChecked(true);
    items->setExpanded(true);
    isAuto = true;
    //这里还有问题，只能处理单层数据
    //遍历创建节点
    int index_ = type_s.lastIndexOf(".");
    if (index_ != -1) {
        type_s = type_s.mid(index_ + 1);
    }
    
    if (structParamMap.value(type_s).size() > 0) {
        QMap<int, structInfo> temp = structParamMap.value(type_s);
        for (const auto &key : temp.keys()) {
            ItemWidget* item_1 = thriftwidget::createAndGetNode(p, items);
            item_1->setParamValue(p, key,
                temp[key].paramName,
                temp[key].paramType,
                temp[key].typeSign);
        }
    }
}

void ItemWidget::setParamValue_interior_map(thriftwidget * p, QString type_s) {
    isAuto = false;
    comboBoxValue->setCurrentText("struct");
    comboBoxKey->show();
    comboBoxValue->show();
    //qDebug() << "复杂类型";
    //创建子节点
    keyLabel->hide();
    valueLabel->hide();
    classLabel->hide();
    addNode->show();
    lineEditParamValue->setReadOnly(true);
    //lineEditParamValue->setPlaceholderText("key");
    lineEditParamValue->setText(type_s);
    ItemWidget* items = thriftwidget::createAndGetNode(p, this);
    //items->lineEditParamValue->setText(type_s);
    items->comboBoxBase->setCurrentText("struct");
    items->keyLabel->show();
    items->valueLabel->hide();
    items->classLabel->hide();
    //items->lineEditParamName->setText(name);
    //items->lineEditParamValue->setReadOnly(true);
    items->lineEditParamValue->setPlaceholderText("key");
    items->lineEditParamSN->setText("1");
    items->checkBox->setChecked(true);
    
    items->setExpanded(true);
    isAuto = true;

    //这里还有问题，只能处理单层数据
    //遍历创建节点
    int index_ = type_s.lastIndexOf(".");
    if (index_ != -1) {
        type_s = type_s.mid(index_ + 1);
    }
    
    if (structParamMap.value(type_s).size() > 0) {
        QMap<int, structInfo> temp = structParamMap.value(type_s);
        for (const auto &key : temp.keys()) {
            ItemWidget* item_1 = thriftwidget::createAndGetNode(p, items);
            item_1->setParamValue(p, key,
                temp[key].paramName,
                temp[key].paramType,
                temp[key].typeSign);
        }
    }
}


thriftwidget::thriftwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::thriftwidget)
{
    ui->setupUi(this);

    qRegisterMetaType<ServerInfoStruct>("ServerInfoStruct&");
    //ui->treeWidget->setStyle(QStyleFactory::create("windows"));
    // 设置树的列数（如果需要多列）
    ui->treeWidget->setColumnCount(4);
    // 设置第一列的宽度为 100 像素
    ui->treeWidget->setColumnWidth(0, 150);

    // 设置第三列的宽度为 150 像素
    ui->treeWidget->setColumnWidth(1, 100);

    // 设置第三列的宽度为 150 像素
    ui->treeWidget->setColumnWidth(2, 350);


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
        qDebug()<< "sn3 = " << QString::number(index + 1);
        item->lineEditParamSN->setText(QString::number(index + 1));
        //qDebug() << "Index of item in treeWidget: " << index;
    } else {
        //qDebug() << "Item is not a top-level item in treeWidget.";
    }

    item->setText(0, "");
     // 添加树节点到树控件中
    ui->treeWidget->addTopLevelItem(item);
    int fontId = QFontDatabase::addApplicationFont(":fonts/Cascadia-Code-Regular-2.ttf");
    QStringList fontFamilies = QFontDatabase::applicationFontFamilies(fontId);
    if (fontFamilies.size() > 0)
    {
        qDebug()<<"family"<<QFontDatabase::applicationFontFamilies(fontId) << " fontFamilies[0] = " << fontFamilies[0];
        QFont font;
        font.setFamily(fontFamilies[0]);
        // // 设置控件字体
        ui->textEdit->setFont(font);
    } else {
        qDebug() << "fonts/Cascadia-Code-Regular-2.ttf错误";
    }
    //ui->treeWidget->setStyle(QStyleFactory::create("fusion"));

    ui->horizontalWidget_schedule->hide();
    ui->tabWidget_test->hide();

    QAction *action = new QAction(this);
    action->setIcon(QIcon(":/lib/soucuo.png"));
    ui->lineEdit_find->addAction(action,QLineEdit::LeadingPosition);

    ui->comboBox_protocol->setView(new QListView());
    ui->comboBox_transport->setView(new QListView());
    ui->comboBox_reqType->setView(new QListView());
    ui->comboBox_testType->setView(new QListView());
    ui->comboBox_port->setView(new QListView());

    ui->splitter->setStretchFactor(0, 6);  // 第一个子控件占 1/3 的显示空间
    ui->splitter->setStretchFactor(1, 1);  // 第二个子控件占 2/3 的显示空间

    ui->splitter_2->setStretchFactor(0, 2);  // 第一个子控件占 1/3 的显示空间
    ui->splitter_2->setStretchFactor(1, 1);  // 第二个子控件占 2/3 的显示空间

    ui->splitter_3->setStretchFactor(0, 1);  // 第一个子控件占 1/3 的显示空间
    ui->splitter_3->setStretchFactor(1, 10);  // 第二个子控件占 2/3 的显示空间

    ui->textEdit_info->hide();
    ui->label_req->hide();
    //ui->lineEdit_port->hide();

    ui->textEdit->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->textEdit_info->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->textEdit_data->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->plainTextEdit_edit->setContextMenuPolicy(Qt::CustomContextMenu);

    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget_mode->setCurrentIndex(0);
    ui->toolButton_return->hide();
    //ui->widget_property->hide();

    ui->treeWidget_api->hide();
    //ui->widget_left->hide();

//    ui->splitter_response->setStretchFactor(0,10);
//    ui->splitter_response->setStretchFactor(1,80);
    ui->lineEdit_funcName->installEventFilter(new EnglishOnlyFilter);
    //设置不可选
    //ui->comboBox_testType->setItemData(1, false, Qt::UserRole - 1);

    ui->toolButton_inportFile->setToolTip("导入thrift文件后，可自动生成接口参数");

    // QGraphicsDropShadowEffect *effect14 = new QGraphicsDropShadowEffect(this);
    // effect14->setOffset(1, 1);          //设置向哪个方向产生阴影效果(dx,dy)，特别地，(0,0)代表向四周发散
    // effect14->setColor(QColor(25, 25, 25));       //设置阴影颜色，也可以setColor(QColor(220,220,220))
    // effect14->setBlurRadius(10);        //设定阴影的模糊半径，数值越大越模糊
    // ui->widget_thrift_api->setGraphicsEffect(effect14);

   QGraphicsDropShadowEffect *effect15 = new QGraphicsDropShadowEffect(this);
   effect15->setOffset(1, 1);          //设置向哪个方向产生阴影效果(dx,dy)，特别地，(0,0)代表向四周发散
   effect15->setColor(QColor(25, 25, 25));       //设置阴影颜色，也可以setColor(QColor(220,220,220))
   effect15->setBlurRadius(10);        //设定阴影的模糊半径，数值越大越模糊
   //ui->widget_test->setGraphicsEffect(effect15);

    // QGraphicsDropShadowEffect *effect16 = new QGraphicsDropShadowEffect(this);
    // effect16->setOffset(1, 1);          //设置向哪个方向产生阴影效果(dx,dy)，特别地，(0,0)代表向四周发散
    // effect16->setColor(QColor(25, 25, 25));       //设置阴影颜色，也可以setColor(QColor(220,220,220))
    // effect16->setBlurRadius(10);        //设定阴影的模糊半径，数值越大越模糊
    // ui->widget_paramAll->setGraphicsEffect(effect16);




    //获取当前cpu支持线程数
    ui->lineEdit_thread_cpu->setText(getCpuInfo("wmic cpu get NumberOfLogicalProcessors"));
    ui->stackedWidget_2->setCurrentIndex(0);

    QChart *chart = new QChart();
    //chart->legend()->hide(); // 隐藏图例
    chart->legend()->hide();
    chart->createDefaultAxes();
    chart->setTitle("接口压测数据图");
    chartView = new QChartView(this);
    chartView->setChart(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    //chartView->resize(QSize(500,500));
    ui->widget_charts->layout()->addWidget(chartView);

    //ui->splitter_5->setStretchFactor(0,40);
    //ui->splitter_5->setStretchFactor(1,1);
    ui->toolButton_returnTest->hide();
    ui->toolButton_propertyTest->hide();
    ui->toolButton_capturePackage->hide();
    ui->toolButton_inportpcap->hide();

    buildChart1();
    buildChart2();
    buildChart3();
    buildChartP();

//    QDirModel *model = new QDirModel(this);
//    QCompleter *completer = new QCompleter(this);
//    completer->setModel(model);
//    ui->lineEdit_dir->setCompleter(completer);

    //读取预制数据
    readPreData();

    //读取thrift文件
    //E:/ProjectA/doc
    QStringList fileList = {"E:/ProjectA/doc/vrv-IN-thrift/aphead.thrift", "E:/ProjectA/doc/vrv-IN-thrift/vrv-only/ap.thrift"};
    handleThriftFile(fileList);
    ui->treeWidget_api->show();
    setSupportStretch(this, true);
    
    TreeWidgetFilter *filter = new TreeWidgetFilter(this);
    connect(filter,SIGNAL(send_updateMouseStyle()),this,SLOT(rece_updateMouseStyle()));
    ui->treeWidget->setMouseTracking(true);
    ui->treeWidget->installEventFilter(filter);


    db = new sshsql();
    cInfoStructList = db->ssh_getAllSSHInfo();
    qDebug() << "sshinfo size = " << cInfoStructList.length();
    for (const auto& cInfo : cInfoStructList) {
        ui->comboBox_ssh->addItem(cInfo.host);
        if (cInfo.host == ui->lineEdit_host->text()) {
            // 找到匹配的元素，可以在这里进行处理
            qDebug() << "找到匹配的 host: " << cInfo.host;
            // 例如，打印其他成员变量
            qDebug() << "用户名: " << cInfo.userName;
            qDebug() << "端口: " << cInfo.port;
            // 如果只需要找到一个匹配项，可以在这里 break
            cInfoStruct = cInfo;
            ui->comboBox_ssh->setCurrentText(cInfo.host);
        }
    }

}

QString thriftwidget::getCpuInfo(const QString &cmd)
{
    QProcess p;        //启动外部程序
    p.start(cmd);      //一体式启动，不分离，主程序退出则启动程序退出,使用close关闭
    //p.startDetached(cmd)  //分离式启动，主程序退出后，外部程序继续运行
    p.waitForFinished(-1);  //超时等待，设置为-1，直到执行完成
    QString result = QString::fromLocal8Bit(p.readAllStandardOutput());//读取运行结果
    QStringList list = cmd.split(" ");  //将cmd按空格拆分
    result = result.remove(list.last(), Qt::CaseInsensitive);//删除cmd序列中最后一个元素
    result = result.replace("\r", "");  //删除\r
    result = result.replace("\n", "");  //删除\n
    result = result.simplified();       //移除字符串两端的空白字符
    /*
        查询CPU型号getInfo("wmic cpu get Name");
        查询CPU核心数getInfo("wmic cpu get NumberOfCores");
        查询CPU线程数getInfo("wmic cpu get NumberOfLogicalProcessors");
        查询CPU处理器标识符getInfo("wmic cpu get processorid");
        查询主板序列号getInfo("wmic baseboard get serialnumber");
        查询BIOS序列号getInfo("wmic bios get serialnumber");
        查询主板唯一标识符getInfo("wmic csproduct get uuid");
        查询硬盘标识符getInfo("wmic diskdrive get serialnumber");
     */
    p.close();
    return result;
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

uint16_t thriftwidget::string2Uint16(QString data)
{
    return data.toUInt(nullptr, 16);
}

QVector<uint32_t> thriftwidget::string2Uint32List(QVector<QString> & data)
{
    //qDebug() << "最后一个值 = " << last2Value_;
    QString lastValue = "";
    if (data.length() > 1) {
        lastValue = data.last();
        if (lastValue.length() < 8) {
            //补位一定要
            lastValue = lastValue.leftJustified(8, '0');
            //qDebug() << "最后小于8" << " data = " << data << " data.size() - 1 = " << data.size() - 1 << " lastValue = " << lastValue;
            data.replace(data.size() - 1, lastValue);
            //qDebug() << "改完" << data;
        }
    }
    QVector<uint32_t> return_;
    for (const auto& value : data) {
        return_.append(string2Uint32("0x" + value));
    }
    return return_;
}

QVector<uint16_t> thriftwidget::string2Uint16List(QVector<QString> &data)
{
    //每个成员里面有4字节的数据，分两半
    QString lastValue = "";
    if (data.length() > 1) {
        lastValue = data.last();
        if (lastValue.length() < 4) {
            //补位一定要
            lastValue = lastValue.leftJustified(4, '0');
            //qDebug() << "最后小于4" << " data = " << data << " data.size() - 1 = " << data.size() - 1 << " lastValue = " << lastValue;
            data.replace(data.size() - 1, lastValue);
            //qDebug() << "改完" << data;
        }
    }
    QVector<uint16_t> return_;
    for (const auto& value : data) {
        return_.append(string2Uint16("0x" + value));
    }
    return return_;
}

QVector<uint8_t> thriftwidget::string2Uint8List(QVector<QString> & data) {
    //不补位
    QVector<uint8_t> return_;
    for (auto value : data) {
        while(value.length()) {
            if (value.length() > 2) {
                return_.append(string2Uint16("0x" + value.mid(0,2)));
                value = value.mid(2);
            } else {
                return_.append(string2Uint16("0x" + value));
                break;
            }
        }
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

void thriftwidget::sendThriftRequest(QVector<uint8_t> dataArray, QElapsedTimer* timer)
{
    //qDebug()<< "进入接口时间 " << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
    ui->stackedWidget->setCurrentIndex(1);
    QTcpSocket *clientSocket = new QTcpSocket(this);

//    QNetworkConfigurationManager manager2;
//    QNetworkConfiguration config = manager2.defaultConfiguration();
//    config.setConnectTimeout(1000);
//    QSharedPointer<QNetworkSession> spNetworkSession(new QNetworkSession(config));
//    clientSocket->setProperty("_q_networksession", QVariant::fromValue(spNetworkSession));

    connect(clientSocket,QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),[=](QAbstractSocket::SocketError socketError){
        qDebug() << "发生错误" << socketError;
        ui->stackedWidget->setCurrentIndex(2);
        ui->toolButton_return->show();
    });

    connect(clientSocket,&QTcpSocket::stateChanged,[=]{
        //qDebug() << "状态改变" << clientSocket->state();
    });

//    &QComboBox::activated
//    static_cast<void (QComboBox::*)(int)>(&QComboBox::activated)
    connect(clientSocket,&QTcpSocket::disconnected,[=]{
        //qDebug() << "断开连接";
    });

    connect(clientSocket,&QTcpSocket::connected,[=]{
        //qDebug() << "已连接";
    });

    //收到数据，触发readyRead

     connect(clientSocket, &QTcpSocket::readyRead,[=]{
        //qDebug() << "接收数据时间：" << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        //没有可读的数据就返回
        //qDebug() << "接收到的数据（十六进制字符串）:";
        // int64_t needRead_ = clientSocket->bytesAvailable();
        // qDebug() << "=====缓冲区还剩数据 = " << needRead_;
        // std::array<uint32_t, 5000> receivedDataArray{0};
        // qint64 bytesReceived = clientSocket->read(reinterpret_cast<char*>(receivedDataArray.data()),
        //                                           receivedDataArray.size() * sizeof(uint32_t));
        int64_t needRead_ = clientSocket->bytesAvailable();
        //qDebug() << "=====缓冲区还剩数据 = " << needRead_ << "  thread ID:" << QThread::currentThreadId();
        QVector<uint32_t> receivedDataArray(needRead_/4 + 1);
        qint64 bytesReceived = clientSocket->read(reinterpret_cast<char*>(receivedDataArray.data()), receivedDataArray.size() * sizeof(uint32_t));
        //qDebug() << "bytesReceived = " << bytesReceived;
        int64_t readNum = clientSocket->bytesAvailable();
        //qDebug() << "本次读取剩数据 = " << readNum;
        int sum2 = 0;
        int a = (needRead_ - readNum)%4; // 36 / 4  = 9
        //qDebug() << "数据求余 = " << a;
        for (const auto& elem : receivedDataArray) {
            // uint32_t data = qFromBigEndian(elem);
            // std::stringstream stream;
            // //每次读取一个字节
            // stream << std::hex << std::setw(8) << std::setfill('0') << data;
            // qDebug() << " elem = " << elem << "十六进制为 = " << QString::fromStdString(stream.str());
            if (sum2++ == (needRead_ - readNum)/4) {
                //只有最后一个可能存在不对齐的情况，多读取一个，少一位
                //qDebug() << "循环 needRead_ - readNum = " << needRead_ - readNum << " sum2 = " << sum2 << " 余数 = " << a;
                //qDebug() << "达到缓存长度 receivedData 长度 = " << receivedData.length() << " elem = " << QString::fromStdString(stream.str());
                if (a != 0) {
                    receivedData.push_back(elem);
                }
                break;
            }
            receivedData.push_back(elem);
        }
        //qDebug() << "receivedData = " << receivedData;
        
        if (isFirstRead) {
            isFirstRead = false;
            //获取数据长度
            uint32_t data = qFromBigEndian(receivedDataArray[0]);
            std::stringstream stream;
            //每次读取一个字节
            stream << std::hex << std::setw(8) << std::setfill('0') << data;
            QString data_ = QString::fromStdString(stream.str());
            int countLength = 4 + strtol(data_.toStdString().c_str(), nullptr, 16);
            needRead = countLength;
            //qDebug() << "首次读取，数据总长度为 " << countLength;
            //qDebug() << "本次缓冲区数据为 " << needRead_ << "本地读取缓冲区后剩余" << readNum;
            needRead = needRead - (needRead_ - readNum);
            //qDebug() << "协议剩余数据 = " << needRead;
            if (needRead == 0) {
                //结束本次读取
                isFirstRead = true;
                needRead = 0;
                //qDebug() << "数据读取完毕";
                //qDebug() << "receivedData 长度 = " << receivedData.length();
                handleBinData();
                receivedData.clear();
                //clientSocket->close();
                count = count -1;
                qint64 elapsedMilliseconds = timer->elapsed();
                elapsedMillisecondsAll = elapsedMillisecondsAll + elapsedMilliseconds;
                qDebug() << "调用完毕, 响应时间：" << QString::number(elapsedMilliseconds) << "ms" << ", 当前时间：" << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
                if (!isTestModle) {
                    ui->label_time->setText("响应时间：" + QString::number(elapsedMilliseconds) + "ms");
                }
                return;
            }
            //qDebug() << "等待下次读取";
        } else {
            //qDebug() << "再次读取剩余数据";
            //qDebug() << "本次缓冲区数据为 " << needRead_ << "本地读取缓冲区后剩余" << readNum;
            needRead = needRead - (needRead_ - readNum);
            //qDebug() << "协议剩余数据 = " << needRead;
            if (needRead == 0) {
                //结束本次读取
                isFirstRead = true;
                needRead = 0;
                //qDebug() << "数据读取完毕";
                //qDebug() << "receivedData 长度 = " << receivedData.length();
                handleBinData();
                receivedData.clear();
                //clientSocket->close();
            }
        }
        count = count -1;
        qint64 elapsedMilliseconds = timer->elapsed();
        elapsedMillisecondsAll = elapsedMillisecondsAll + elapsedMilliseconds;
        qDebug() << "调用完毕, 响应时间：" << QString::number(elapsedMilliseconds) << "ms" << ", 当前时间：" << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        if (!isTestModle) {
            ui->label_time->setText("响应时间：" + QString::number(elapsedMilliseconds) + "ms");
        }
        return;
    });
    QString port_str = ui->comboBox_port->currentText();
    int index_s = port_str.indexOf("(");
    int index_e = port_str.indexOf(")");
    int port = port_str.mid(index_s + 1, index_e - index_s - 1).toInt();
    if (index_s == -1 && index_e == -1) {
        port = port_str.toInt();
    }
    //qDebug() << "host = " << ui->lineEdit_host->text() << " port = " << port;
    clientSocket->connectToHost(ui->lineEdit_host->text(), port);
    if (!clientSocket->waitForConnected(2000)) {
        QAbstractSocket::SocketError error = clientSocket->error();
        if (error == QAbstractSocket::SocketTimeoutError || QAbstractSocket::NetworkError == error) {
            qDebug() << "连接超时，无法连接服务器";
            ui->stackedWidget->setCurrentIndex(2);
            ui->toolButton_return->show();
        } else {
            qDebug() << "发生错误，无法连接到服务器" << "  thread ID:" << QThread::currentThreadId();
        }
        return ;
    }

    // 检查设备是否打开并处于可读写状态
    if (!clientSocket->isOpen()) {
        // 打开设备
        if (!clientSocket->open(QIODevice::ReadWrite)) {
            //qDebug() << "无法打开设备";
            return ;
        }
    }

    for (uint8_t& data : dataArray) {
        data = qToBigEndian(data);
        //dataTest.append(reinterpret_cast<const char*>(&data), sizeof(uint32_t));
    }

    timer->start();
    //qDebug()<< "1进入接口时间 " << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
    //删除最后一段
    // if (dataArray.back() == 0) {
    //     qDebug() << "删除0";
    //     dataArray.pop_back();
    // }
    qint64 bytesSent = clientSocket->write(reinterpret_cast<char*>(dataArray.data()), dataArray.size() * sizeof(uint8_t));
    qDebug()<< "进入 bytesSent = " << bytesSent;
    qDebug()<< "进入 dataArray = " << dataArray;
    if (bytesSent != dataArray.size() * sizeof(uint8_t)) {
        qDebug() << "发送数据失败";
        //clientSocket.close();
        return ;
    }
    //qDebug() << "1数据写完时间：" << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
}

void thriftwidget::sendHttpRequest(QVector<uint8_t> dataArray, QElapsedTimer *timer)
{
    QNetworkAccessManager manager;

    qDebug() << manager.supportedSchemes();
    ui->stackedWidget->setCurrentIndex(1);
    QString port_str = ui->comboBox_port->currentText();
    int index_s = port_str.indexOf("(");
    int index_e = port_str.indexOf(")");
    int port = port_str.mid(index_s + 1, index_e - index_s - 1).toInt();
    if (index_s == -1 && index_e == -1) {
        port = port_str.toInt();
    }
    //qDebug() << "host = " << ui->lineEdit_host->text() << " port = " << port << " 路由=" << ui->lineEdit_route->text();

    QString urlData = "https://";

    QUrl url(urlData + ui->lineEdit_host->text() + ":" + QString::number(port) + ui->lineEdit_route->text());

    bool bSupp = QSslSocket::supportsSsl();
    auto buildVersion = QSslSocket::sslLibraryBuildVersionString();
    QString version = QSslSocket::sslLibraryVersionString();
    //qInfo() << bSupp << buildVersion << version ;
    QSslConfiguration sslConfig = QSslConfiguration::defaultConfiguration();

    //qDebug() << "默认配置" << sslConfig.peerVerifyMode();
    sslConfig.setPeerVerifyMode(QSslSocket::VerifyNone);
    //qDebug() << "现在配置" << sslConfig.peerVerifyMode();

    sslConfig.setProtocol(QSsl::SslProtocol::AnyProtocol);
    QSslConfiguration::setDefaultConfiguration(sslConfig);

    QNetworkRequest request;
    request.setSslConfiguration(sslConfig);
    request.setUrl(url);
    //request.setRawHeader("Host", "192.168.85.205:10669");
    //qDebug() << "字节数组 = " << dataArray;
    //qDebug() << "长度" << dataArray.size() * sizeof(uint32_t);
    //request.setHeader(QNetworkRequest::ContentLengthHeader, QString::number(10));
    request.setHeader(QNetworkRequest::UserAgentHeader, "vrv/1.0.0-dev pc_w");
    //request.setRawHeader("Accept", "vrv imsdk");
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-thrift");
    //request.setHeader(QNetworkRequest::ContentTypeHeader, "vrv imdsk");
    //request.setRawHeader("Userversion", "2");
    //request.setRawHeader("Accept-Encoding", "gzip");

    QString hexString;
    for (const QString& value : dataList) {
        //qDebug() << "value = " << value;
        hexString = hexString + value;  // 在控制台输出元素值
    }
    hexString = hexString.mid(8);
    QByteArray byteArray2 = QByteArray::fromHex(hexString.toUtf8());
    // qDebug() << "原始十六进制字符串:" << hexString;
    // qDebug() << "转换后的字节数组:" << byteArray2;
    // qDebug() << "转换后的字符串:" << QString(byteArray2);

    //writeQByteArrayToFile(byteArray2, "thriftConfig\\binTest.bin");

    QNetworkReply* reply = manager.post(request, byteArray2);

    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    // 检查错误
    if (reply->error() != QNetworkReply::NoError) {
        qDebug() << "请求失败:" << reply->errorString();
        ui->stackedWidget->setCurrentIndex(2);
    } else {
        qDebug() << "请求成功";
        QByteArray responseData = reply->readAll();
        QString hexString = responseData.toHex();
        //qDebug() << "响应:" << hexString;
        handleHexData(ui->textEdit_data, ui->textEdit, hexString);
        ui->stackedWidget->setCurrentIndex(0);
        //解析数据
    }

    // 清理
    reply->deleteLater();
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
        //qDebug() << "参数类型为" << item->comboBoxBase->currentText() << " 参数值为" << item->lineEditParamValue->text();
        if (item->checkBox->isChecked()) {
            sum++;
        } else {
            continue;
        }
        QString valueType = item->comboBoxBase->currentText();
        //qDebug() << "valueType = " << valueType;
        if (baseType.contains(valueType)) {
            baseSerialize(sum + 1, valueType, item->lineEditParamValue->text());
        } else if (containerType.contains(valueType)) {
            containerSerialize(sum + 1, valueType, item->lineEditParamValue->text(), item->comboBoxKey->currentText(), item->comboBoxValue->currentText());
        } else if (valueType == "struct") {
            //
            //qDebug() << "struct类型";
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
   //qDebug() << "serialNumber = " << serialNumber << " valueType = " << valueType << " value = " << value;
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
    //qDebug() << "containerSerialize value = " << value;
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
                    //qDebug() << "key = " << str;
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
                    //qDebug() << "key = " << str;
                    // QString strData = QString("%1").arg(str, mapSize.value(key_Type), QLatin1Char('0'));
                    // string2stringList(strData);

                    int64_t value_i = str.toULongLong();
                    //qDebug() << "int64 = " << value;
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

void thriftwidget::assembleTBinaryMessage(int buildType, int num)
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
        //qDebug() << " buildType =" << buildType << " value = " << value << " toolTip = " << item->lineEditParamValue->toolTip();
        if (buildType == 1 && item->lineEditParamValue->toolTip() == "该值存在多个预制值，压测模式中，将按照顺序使用预测值") {
            value = preDataMapV[item->lineEditParamName->text()].at(num%preDataMapV[item->lineEditParamName->text()].size());
            //qDebug() << "压测模式，检测到" << item->lineEditParamName->text() << "该值存在多个预制值，将按照顺序使用预测值 " << value;
        }
        //ui->plainTextEdit_testData->appendPlainText(item->lineEditParamName->text() + " : " +value);
        //lineEditParamValue->toolTip()
        QString SN = item->lineEditParamSN->text();
        //qDebug() << "SN = " << SN;
        if (SN == "") {
            qDebug() << "参数名" << value << "获取sn失败，默认+1";
            SN = QString::number(i + 1);
        }

        //设置类型和序号
        //这里的序号不能依靠遍历值，要依靠sn的值
        writeTBinaryTypeAndSerialNumber(valueType, SN.toInt());
        if (baseType.contains(valueType)) {
            //构建基础类型
            writeTBinaryBaseMessage(valueType, value);
        } else if (containerType.contains(valueType)) {
            //构建集合类型
            qDebug() << "list类型";
            writeTBinaryCollectionMessage(valueType, value, item, item->comboBoxKey->currentText(), item->comboBoxValue->currentText());
        } else {
            //构建struct
            writeTBinaryStructMessage(valueType, item, buildType, num);
        }
    }
    //写入结束,添加结束符号
    writeTBinaryEndMessage();

    //协议层
    if (ui->comboBox_protocol->currentText() == TBinaryProtocol_) {
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
    //如果成员是结构体 value是空值
    if (valueType == "set" || valueType == "list") {
        qDebug() << "writeTBinaryCollectionMessage 构建" << valueType;
        //设置类型
        writeTBinaryTypeMessage(paramValueType);
        if (baseType.contains(paramValueType)) {
            //value为基础类型
            //设置元素个数
            QStringList dataList;
            qDebug() << " value = " << value;
            writeTBinaryKeySize(dataList, value);
            qDebug() << " dataList = " << dataList;
            for (const QString &str : dataList) {
                writeTBinaryBaseMessage(paramValueType, str);
            }
        } else if (containerType.contains(paramValueType)) {
            //value为集合 暂时不考虑
            for (const QString &str : dataList) {
                writeTBinaryCollectionMessage(paramValueType, str, item, item->comboBoxKey->currentText(), item->comboBoxValue->currentText());
            }
        } else {

            qDebug() << "writeTBinaryCollectionMessage list / set";
            //value为struct 需要读取子节点数据
            int childCount = item->childCount();

            QString lenData = QString("%1").arg(childCount, 8, 16, QLatin1Char('0'));
            qDebug() << "writeTBinaryKeySize = " << childCount << " lenData = " << lenData;
            string2stringList(lenData);

            qDebug() << "结构体成员数量 = " << childCount;
            for (int j = 0; j < childCount; ++j) {
                ItemWidget *item_temp = dynamic_cast<ItemWidget*>(item->child(j));
                //构建结构体
                writeTBinaryStructMessage(paramValueType, item_temp);
            }
        }
    } else if (valueType == "map") {
        //设置key类型
        writeTBinaryTypeMessage(paramKeyType);
        //设置value类型
        writeTBinaryTypeMessage(paramValueType);

        qDebug() << "map dataList = " << dataList;
        if (baseType.contains(paramKeyType)) {
            if (baseType.contains(paramValueType)) {
                //基础类型
                //设置元素个数
                QStringList dataList;
                writeTBinaryValueSize(dataList, value);
                            //设置元素值
                for (const QString &str : dataList) {
                    int index = str.indexOf(":");
                    //设置key值
                    qDebug() << "key = " << str.mid(0, index);
                    qDebug() << "value = " << str.mid(index+1);
                    writeTBinaryBaseMessage(paramKeyType, str.mid(0, index));
                    writeTBinaryBaseMessage(paramValueType, str.mid(index+1));
                }
            } else if (containerType.contains(paramValueType)) {
                //暂时不考虑
            } else {
                int childCount = item->childCount();
                QString lenData = QString("%1").arg(childCount, 8, 16, QLatin1Char('0'));
                qDebug() << "writeTBinaryKeySize = " << childCount << " lenData = " << lenData;
                string2stringList(lenData);
                qDebug() << "结构体成员数量 = " << childCount;
                for (int j = 0; j < childCount; ++j) {
                ItemWidget *item_temp = dynamic_cast<ItemWidget*>(item->child(j));
                //构建结构体
                qDebug() << "map key = " << item->lineEditParamValue->text();
                qDebug() << "map key = " << paramKeyType;
                writeTBinaryBaseMessage(paramKeyType, item->lineEditParamValue->text());
                writeTBinaryStructMessage(paramValueType, item_temp);
            }
            }

        } else {
            qDebug() << "出错";
            //key如果不是基础类型，不支持
        }
    } else {
        qDebug() << "出错";
    }
}

void thriftwidget::writeTBinaryStructMessage(QString valueType, ItemWidget *item, int buildType, int num)
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
        QString SN = itemChild->lineEditParamSN->text();
        //qDebug() << " buildType =" << buildType << " value = " << value_ << " toolTip = " << itemChild->lineEditParamValue->toolTip();
        if (buildType == 1 && itemChild->lineEditParamValue->toolTip() == "该值存在多个预制值，压测模式中，将按照顺序使用预测值") {
            value_ = preDataMapV[itemChild->lineEditParamName->text()].at(num%preDataMapV[itemChild->lineEditParamName->text()].size());
            //qDebug() << "压测模式，检测到" << itemChild->lineEditParamName->text() << "该值存在多个预制值，将按照顺序使用预测值 " << value_;
        }
        //ui->plainTextEdit_testData->appendPlainText(itemChild->lineEditParamName->text() + " : " +value_);
        //qDebug() << "SN = " << SN;
        if (SN == "") {
            qDebug() << "参数名" << value_ << "获取sn失败，默认+1";
            SN = QString::number(serialNumber + 1);
        }
        writeTBinaryTypeAndSerialNumber(valueType_, SN.toInt());
        if (baseType.contains(valueType_)) {
            writeTBinaryBaseMessage(valueType_, value_);
        } else if (containerType.contains(valueType_)) {
            //集合
            writeTBinaryCollectionMessage(valueType_, value_, itemChild, itemChild->comboBoxKey->currentText(), itemChild->comboBoxValue->currentText());
        } else {
            //struct
            writeTBinaryStructMessage(valueType_, itemChild, buildType, num);
        }
   }
    //写入结束,添加结束符号
    writeTBinaryEndMessage();
}

void thriftwidget::writeTBinaryEndMessage()
{
    //qDebug() << "写入结尾符";
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
    //qDebug() << "writeTBinarySizeMessage data = " << data << " Length = " << data.length()/2;
    //qDebug() << "dataLength = " << dataLength;
    dataList.insert(0, dataLength);
    //qDebug() << "原始数据" << dataList;
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
    //qDebug() << "writeTBinaryKeySize = " << dataList.length() << " lenData = " << lenData;
    string2stringList(lenData);
}

void thriftwidget::writeTBinaryValueSize(QStringList &dataList, QString value)
{
    QString data = value;//.mid(1, value.length() - 2);
    //qDebug() << "writeTBinaryValueSize data = " << data;
    dataList = data.split(",");
    //map2List(dataList, data);
    QString lenData = QString("%1").arg(dataList.length(), 8, 16, QLatin1Char('0'));
    string2stringList(lenData);
}

void thriftwidget::handleMessage(QTextEdit * textEdit_data, QString &data)
{
    //处理数据的时候要考虑请求的函数入参可能不止一个，但返回肯定是一个。
    QString label_headers;
    QString temp;
    //数据长度
    //如果是http，不取长度
    QString message_len;
    QString headers_data_length;
    if (ui->comboBox_transport->currentText() == THTTPSTransport_) {
        //什么都不做
    } else {
        //这块有问题，但是刚好不影响，前两个字节是tcp的，刚好是0000
        message_len = data.mid(0, 8);
        temp = temp + addColorHtml(message_len, sourceColorMap[THRIFT_MESSAGE_LENGTH]);
        headers_data_length = QString::number(strtol(message_len.toStdString().c_str(), nullptr, 16));
        label_headers = label_headers + "数据长度:" + headers_data_length + "   ";
        data = data.mid(8);
    }
    //qDebug() << "需要处理的数据 = " << data;
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
    //label_headers = label_headers + "方法长度:" + headers_func_length + "   ";
    temp = temp + addColorHtml(func_len, sourceColorMap[THRIFT_FUNC_LENGTH]);
    bool ok;
    int len = func_len.toInt(&ok, 16) * 2;
    data = data.mid(8);
    //需要转换为长度单位
    //方法名
    QString fun_name = data.mid(0, len);
    temp = temp + addColorHtml(fun_name, sourceColorMap[THRIFT_FUNC_NAME]);
    //qDebug() << "方法名 = " << hexToString(fun_name);
    label_headers = label_headers + "接口名:" + hexToString(textEdit_data,fun_name) + "   ";
    data = data.mid(len);
    //流水号
    QString func_sn = data.mid(0, 8);
    temp = temp + addColorHtml(func_sn, sourceColorMap[THRIFT_SN]);
    data = data.mid(8);
    QString headers_data_sn = QString::number(strtol(func_sn.toStdString().c_str(), nullptr, 16));
    //qDebug() << "流水号 = " << headers_data_sn;
    //label_headers = label_headers + "流水号:" + headers_data_sn + "   ";

    QString paramType;
    if (type_data == "80010001") {
        for(int i = 0; i < funcParamInMap.value(hexToString(textEdit_data,fun_name)).size(); i++) {
            paramType = paramType + funcParamInMap.value(hexToString(textEdit_data,fun_name)).value(i + 1).paramType + " "; 
        }
    } else if (type_data == "80010002"){
        paramType = funcParamInMap.value(hexToString(textEdit_data,fun_name)).value(1).paramType;
    }

    label_headers = label_headers + "入参类型:" + paramType +  "  返回值类型:" + funcParamOutMap.value(hexToString(textEdit_data,fun_name)).value(1).paramType + "   ";
    ui->label_time->clear();
    ui->label_headers->setText(label_headers);

    QStringList paramTypeList;
    if (type_data == "80010001") {
        for(int i = 0; i < funcParamInMap.value(hexToString(textEdit_data,fun_name)).size(); i++) {
            if (baseType.contains(funcParamInMap.value(hexToString(textEdit_data,fun_name)).value(i + 1).paramType)) {
                paramTypeList.push_back(funcParamInMap.value(hexToString(textEdit_data,fun_name)).value(i + 1).paramName); 
            } else {
                paramTypeList.push_back(funcParamInMap.value(hexToString(textEdit_data,fun_name)).value(i + 1).paramType); 
            }
        }
    }
    //数据
    //编号两位数  序号4位数 数据
    //data = temp + data;
    //for(int i = 0; i < = 500; i++) {
    //qDebug() << "数据= " << data;
    if (type_data == "80010001" || type_data == "80010002") {
        if (type_data == "80010001") {
            textEdit_data->append(addColorBracketsHtml(getRetract() + "{"));
        }
        int sum = 0;
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
            //qDebug() << "handleMessage isEnd = " << isEnd;
            if (value_type == "02") {
                //bool
                temp = temp + handleBool(textEdit_data, data, isEnd, paramTypeList[sum]);
            } else if (value_type == "03") {
                //byte
                //qDebug() << "走这里1";
                temp = temp + handleByte(textEdit_data,data, isEnd, paramTypeList[sum]);
            } else if (value_type == "04") {
                //double
                temp = temp + handleDouble(textEdit_data,data, isEnd, paramTypeList[sum]);
            } else if (value_type == "06") {
                //i16
                temp = temp + handleI16(textEdit_data,data, isEnd, paramTypeList[sum]);
            } else if (value_type == "08") {
                //i32
                temp = temp + handleI32(textEdit_data,data, isEnd, paramTypeList[sum]);
            } else if (value_type == "0a") {
                //i64
                temp = temp + handleI64(textEdit_data,data, isEnd, paramTypeList[sum]);
            } else if (value_type == "0b") {
                //string
                temp = temp + handleString(textEdit_data,data, isEnd, paramTypeList[sum]);
            } else if (value_type == "0c") {
                //struct
                //qDebug() << "进入struct";
                
                if (type_data == "80010001") {
                    temp = temp + handleStruct(textEdit_data,data, isEnd, paramTypeList[sum],
                        funcParamInMap.value(hexToString(textEdit_data, fun_name)).value(sum + 1).paramName);
                } else {
                    temp = temp + handleStruct(textEdit_data,data, isEnd, funcParamOutMap.value(hexToString(textEdit_data, fun_name)).value(1).paramType,
                    funcParamOutMap.value(hexToString(textEdit_data, fun_name)).value(1).paramName);
                }
                //固定1
                //记得处理请求结束
                break;
            } else if (value_type == "0d") {
                //map
                textEdit_data->append(addColorBracketsHtml("{\"map\":"));
                if (type_data == "80010001") {
                    temp = temp + handleMap(textEdit_data, data, isEnd, paramTypeList[sum],
                        funcParamInMap.value(hexToString(textEdit_data, fun_name)).value(sum + 1).paramName);
                } else {
                    temp = temp + handleMap(textEdit_data, data, isEnd, funcParamOutMap.value(hexToString(textEdit_data, fun_name)).value(1).paramType,
                        funcParamOutMap.value(hexToString(textEdit_data, fun_name)).value(1).paramName);
                }
                textEdit_data->append(addColorBracketsHtml("}"));
            } else if (value_type == "0e") {
                //set
                textEdit_data->append(addColorBracketsHtml("{\"set\":"));
                if (type_data == "80010001") {
                    temp = temp + handleList(textEdit_data, data, isEnd, paramTypeList[sum],
                        funcParamInMap.value(hexToString(textEdit_data, fun_name)).value(sum + 1).paramName);
                } else {
                    temp = temp + handleList(textEdit_data, data, isEnd, funcParamOutMap.value(hexToString(textEdit_data, fun_name)).value(1).paramType,
                    funcParamOutMap.value(hexToString(textEdit_data, fun_name)).value(1).paramName);
                }

                textEdit_data->append(addColorBracketsHtml("}"));
            } else if (value_type == "0f") {
                //list
                textEdit_data->append(addColorBracketsHtml("{\"list\":"));
                if (type_data == "80010001") {
                    temp = temp + handleList(textEdit_data, data, isEnd, paramTypeList[sum],
                        funcParamInMap.value(hexToString(textEdit_data, fun_name)).value(sum + 1).paramName);
                } else {
                    temp = temp + handleList(textEdit_data, data, isEnd, funcParamOutMap.value(hexToString(textEdit_data, fun_name)).value(1).paramType,
                    funcParamOutMap.value(hexToString(textEdit_data, fun_name)).value(1).paramName);
                }
                textEdit_data->append(addColorBracketsHtml("}"));
            }
            sum++;
        }
        if (type_data == "80010001") {
            textEdit_data->append(addColorBracketsHtml(getRetract() + "}"));
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
                temp = temp + handleString(textEdit_data, data, isEnd, THRIFT_EXCEPTION);

            } else if (value_type == "08") {
                //qDebug() << "剩下数据" << data;
                temp = temp + handleI32(textEdit_data, data, isEnd, THRIFT_EXCEPTION);
            }
        }
    }
    data = temp + data;
    //qDebug() << "异常数据 = " << data;
}

QString thriftwidget::addColorHtml(QString str, QColor *fontCrl)
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
    QColor *fontCrl = new QColor(255, 255, 255);
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
    QColor *fontCrl = new QColor(255, 255, 255);
    QByteArray array;
    array.append(fontCrl->red());
    array.append(fontCrl->green());
    array.append(fontCrl->blue());
    QString strC(array.toHex());
    str.replace(" ","&nbsp;");
    return QString("<span style=\" color:#%1;opacity: 1;\">%2</span>").arg(strC).arg(str);
}


QString thriftwidget::handleBool(QTextEdit * textEdit_data, QString &str, QString isEnd, QString paramName, bool isHandEnd, bool isLastEnd)
{
    QString value = str.mid(0, 2);
    str = str.mid(2);
    isEnd = str.mid(0,2);
    QString end = ",";
    if (isEnd == "00" && isHandEnd) {
        end = "";
    }

    if (isLastEnd) {
        end = "";
    }
    if (paramName == "fdog_list" || paramName == "fdog_set") {
        textEdit_data->append(addColorValueNumHtml(hexToLongNumber(textEdit_data, value)) + end);
    } else if (paramName != "") {
        qDebug() << "paramName1";
        textEdit_data->append(addColorFieldHtml(getRetract() + "\"" + paramName+ "\"") + " : " + addColorValueNumHtml(hexToLongNumber(textEdit_data, value)) + end);
    } else {
        qDebug() << "paramName2";
        textEdit_data->append(addColorFieldHtml(getRetract() + "\"bool\"") + " : " + addColorValueNumHtml(hexToLongNumber(textEdit_data, value)) + end);
    }
    return addColorHtml(value, sourceColorMap[THRIFT_VALUE]);
}

QString thriftwidget::handleByte(QTextEdit * textEdit_data, QString &str, QString isEnd, QString paramName, bool isHandEnd, bool isLastEnd)
{
    QString value = str.mid(0, 2);
    str = str.mid(2);
    //qDebug() << "handleByte getRetract()  = " << getRetract() ;
    isEnd = str.mid(0,2);
    QString end = ",";
    if (isEnd == "00" && isHandEnd) {
        end = "";
    }

    if (isLastEnd) {
        end = "";
    }
    if (paramName == "fdog_list" || paramName == "fdog_set") {
        textEdit_data->append(addColorValueNumHtml(hexToLongNumber(textEdit_data, value)) + end);
    } else if (paramName != "") {
        //qDebug() << "paramName1";
        textEdit_data->append(addColorFieldHtml(getRetract() + "\"" + paramName+ "\"") + " : " + addColorValueNumHtml(hexToLongNumber(textEdit_data, value)) + end);
    } else {
        //qDebug() << "paramName2";
        textEdit_data->append(addColorFieldHtml(getRetract() + "\"byte\"") + " : " + addColorValueNumHtml(hexToLongNumber(textEdit_data, value)) + end);
    }
    return addColorHtml(value, sourceColorMap[THRIFT_VALUE]);
}

QString thriftwidget::handleDouble(QTextEdit * textEdit_data, QString &str, QString isEnd, QString paramName, bool isHandEnd, bool isLastEnd)
{
    //这个没处理
    QString value = str.mid(0, 16);
    str = str.mid(16);
    isEnd = str.mid(0,2);
    return addColorHtml(value, sourceColorMap[THRIFT_VALUE]);
}

QString thriftwidget::handleI16(QTextEdit * textEdit_data, QString &str, QString isEnd, QString paramName, bool isHandEnd, bool isLastEnd)
{
    QString value = str.mid(0, 4);
    str = str.mid(4);
    isEnd = str.mid(0,2);
    QString end = ",";
    if (isEnd == "00" && isHandEnd) {
        end = "";
    }

    if (isLastEnd) {
        end = "";
    }
    if (paramName == "fdog_list" || paramName == "fdog_set") {
        textEdit_data->append(addColorValueNumHtml(hexToLongNumber(textEdit_data, value)) + end);
    } else if (paramName != "") {
        //qDebug() << "paramName1";
        textEdit_data->append(addColorFieldHtml(getRetract() + "\"" + paramName+ "\"") + " : " + addColorValueNumHtml(hexToLongNumber(textEdit_data, value)) + end);
    } else {
        //qDebug() << "paramName2";
        textEdit_data->append(addColorFieldHtml(getRetract() + "\"i16\"") + " : " + addColorValueNumHtml(hexToLongNumber(textEdit_data, value)) + end);
    }

    return addColorHtml(value, sourceColorMap[THRIFT_VALUE]);
}

QString thriftwidget::handleI32(QTextEdit * textEdit_data, QString &str, QString isEnd, QString resType, QString paramName, bool isHandEnd, bool isLastEnd)
{
    QString value = str.mid(0, 8);
    str = str.mid(8);
    isEnd = str.mid(0,2);
    QString end = ",";
    if (isEnd == "00" && isHandEnd) {
        end = "";
    }
    if (isLastEnd) {
        end = "";
    }

    if (resType == THRIFT_REPLY) {
        if (paramName == "fdog_list" || paramName == "fdog_set") {
            textEdit_data->append(addColorValueNumHtml(hexToLongNumber(textEdit_data, value)) + end);
        } else if (paramName != "") {
            //qDebug() << "paramName1";
            textEdit_data->append(addColorFieldHtml(getRetract() + "\"" + paramName + "\"") + " : " + addColorValueNumHtml(hexToLongNumber(textEdit_data, value)) + end);
        } else {
            //qDebug() << "paramName2";
            textEdit_data->append(addColorFieldHtml(getRetract() + "\"i32\"") + " : " + addColorValueNumHtml(hexToLongNumber(textEdit_data, value)) + end);
        }

    } else if (resType == THRIFT_EXCEPTION) {
        QString excType = hexToLongNumber(textEdit_data, value);
        textEdit_data->append(addColorFieldHtml(getRetract() + "Exception Type") + " : " + addColorValueNumHtml(ExceptionType.value(excType) + " (" + excType + ")"));
    }
    return addColorHtml(value, sourceColorMap[THRIFT_VALUE]);
}

QString thriftwidget::handleI64(QTextEdit * textEdit_data, QString &str, QString isEnd, QString paramName, bool isHandEnd, bool isLastEnd)
{
    QString value = str.mid(0, 16);
    str = str.mid(16);
    QString end = ",";
    isEnd = str.mid(0,2);
    if (isEnd == "00" && isHandEnd) {
        end = "";
    }

    if (isLastEnd) {
        end = "";
    }
    //qDebug() << "end =" << end << " isEnd = " << isEnd;
    if (paramName == "fdog_list" || paramName == "fdog_set") {
            textEdit_data->append(addColorValueNumHtml(hexToLongNumber(textEdit_data, value)) + end);
    } else if (paramName != "") {
        //qDebug() << "paramName1";
        textEdit_data->append(addColorFieldHtml(getRetract() + "\"" + paramName+ "\"") + " : " + addColorValueNumHtml(hexToLongNumber(textEdit_data, value)) + end);
    } else {
        //qDebug() << "paramName2";
        textEdit_data->append(addColorFieldHtml(getRetract() + "\"i64\"") + " : " + addColorValueNumHtml(hexToLongNumber(textEdit_data, value)) + end);
    }

    return addColorHtml(value, sourceColorMap[THRIFT_VALUE]);
}




QString thriftwidget::handleString(QTextEdit * textEdit_data, QString &str, QString isEnd, QString resType, QString paramName, bool isHandEnd, bool isLastEnd)
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
    //qDebug() << "handleString isEnd = " << isEnd;
    QString end = ",";
    if (isEnd == "00" && isHandEnd) {
        end = "";
    }

    if (isLastEnd) {
        end = "";
    }

    //{"verifiedInfo":{"region":"CN"},"commInfo":{"authority":0,"manager":0}}  这个格式化会出问题，需要转移

    if (resType == THRIFT_REPLY) {
        if (paramName == "fdog_list" || paramName == "fdog_set") {
            textEdit_data->append(addColorValueStrHtml("\"" + hexToString(textEdit_data, value2) + "\"") + end);
        } else if (paramName != "") {
            //qDebug() << "paramName1";
            textEdit_data->append(addColorFieldHtml(getRetract() + "\"" + paramName + "\"") + " : " + addColorValueStrHtml("\"" + hexToString(textEdit_data, value2) + "\"") + end);
        } else {
            //qDebug() << "paramName2";
            textEdit_data->append(addColorFieldHtml(getRetract() + "\"string\"") + " : " + addColorValueStrHtml("\"" + hexToString(textEdit_data, value2) + "\"") + end);
        }

        temp = temp + addColorHtml(value2, sourceColorMap[THRIFT_VALUE]);
    } else if (resType == THRIFT_EXCEPTION) {
        textEdit_data->append(addColorFieldHtml(getRetract() + "Exception Message") + " : " + addColorValueStrHtml("\"" + hexToString(textEdit_data, value2) + "\""));
        temp = temp + addColorHtml(value2, sourceColorMap[THRIFT_VALUE]);
    }
    return temp;
}

QString thriftwidget::handleStruct(QTextEdit * textEdit_data, QString &str, QString isEnd, QString outType, QString outParam, bool isHandEnd)
{
    qDebug() << " outType = " << outType;
    if (outType.contains(".")) {
        int index = outType.lastIndexOf(".");
        outType = outType.mid(index + 1);
        //qDebug() << "发现非本文件结构体，删除前缀后=" << outType;
    }
    if (outParam == "fdog_list" || outParam == "fdog_set") {
        textEdit_data->append(addColorBracketsHtml(getRetract() + "{"));
    } else if (outParam == "") {
        textEdit_data->append(addColorBracketsHtml(getRetract() + "{"));
    } else {
        textEdit_data->append(addColorFieldHtml(getRetract() + "\"" + outParam + "\"")  + addColorBracketsHtml(":{"));
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
            textEdit_data->append("struct类型数据结束------------");
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
                textEdit_data->append(addColorBracketsHtml(getRetract() + "}"));
            } else {
                if (retractNum == 0) {
                    textEdit_data->append(addColorBracketsHtml(getRetract() + "}"));
                } else {
                    textEdit_data->append(addColorBracketsHtml(getRetract() + "},"));
                }

            }

            break;
        }
        temp = temp + addColorHtml(value_type, sourceColorMap[sourceTypeMap[value_type]]);

        //读取序号
        QString value_sn = str.mid(0, 4);
        //需要转
        bool ok; // 用于标识转换是否成功
        //qDebug() << "outParam = " << outParam << " hexToLongNumber(value_sn) = " << hexToLongNumber(value_sn) << " value_sn = " << value_sn;
        //qDebug() << "outType = " << outType <<  " value_sn.toInt() = " << value_sn.toInt(&ok, 16);
        QString paramName_ = structParamMap.value(outType).value(value_sn.toInt(&ok, 16)).paramName;
        QString paramType_ = structParamMap.value(outType).value(value_sn.toInt(&ok, 16)).paramType;

        str = str.mid(4);
        temp = temp + addColorHtml(value_sn, sourceColorMap[THRIFT_VALUE_SN]);

        int type_ = 0;

        QString isEnd = str.mid(0, 2);
        //qDebug()<< "paramName_ = " << paramName_ << " isEnd = " << isEnd;
        if (value_type == "02") {
            //bool
            type_ = THRIFT_BOOL;
            temp = temp + handleBool(textEdit_data, str, isEnd, paramName_);
        } else if (value_type == "03") {
            //byte
            type_ = THRIFT_BYTE;
            temp = temp + handleByte(textEdit_data, str, isEnd, paramName_);
        } else if (value_type == "04") {
            //double
            type_ = THRIFT_DOUBLE;
            temp = temp + handleDouble(textEdit_data, str, isEnd, paramName_);
        } else if (value_type == "06") {
            //i16
            type_ = THRIFT_I16;
            temp = temp + handleI16(textEdit_data, str, isEnd, paramName_);
        } else if (value_type == "08") {
            //i32
            type_ = THRIFT_I32;
            temp = temp + handleI32(textEdit_data, str, isEnd, THRIFT_REPLY, paramName_);

        } else if (value_type == "0a") {
            //i64
            type_ = THRIFT_I32;
            //qDebug() << "0a isEnd = "<< isEnd << " paramName_ = " << paramName_;
            temp = temp + handleI64(textEdit_data, str, isEnd, paramName_);
        } else if (value_type == "0b") {
            //string
            type_ = THRIFT_STRING;
            temp = temp + handleString(textEdit_data, str, isEnd, THRIFT_REPLY, paramName_);
        } else if (value_type == "0c") {
            //struct
            type_ = THRIFT_STRUCT;
            temp = temp + handleStruct(textEdit_data, str, isEnd, paramType_, paramName_);
        } else if (value_type == "0d") {
            //map
            temp = temp + handleMap(textEdit_data, str, isEnd, paramType_, paramName_);
            type_ = THRIFT_MAP;
        } else if (value_type == "0e") {
            //set
            type_ = THRIFT_SET;
            temp = temp + handleSet(textEdit_data, str, isEnd, paramType_, paramName_);
        } else if (value_type == "0f") {
            //list
            type_ = THRIFT_LIST;
            qDebug()<< "走到这里0f";
            //内部处理类型吧
            temp = temp + handleList(textEdit_data, str, isEnd, paramType_, paramName_);
            //break;
        }
        sum++;
    }
    return temp;
}

QString thriftwidget::handleMap(QTextEdit * textEdit_data, QString &str, QString isEnd, QString outType, QString outParam, bool isHandEnd)
{
    qDebug() << "走这里handleMap isEnd = " << isEnd;
    qDebug() << "outType =" << outType;
    int index_s = outType.indexOf("<");
    int index_e = outType.lastIndexOf(">");
    QString paramType_s = outType.mid(index_s + 1, index_e - index_s - 1);
    qDebug() << "paramType_s =" << paramType_s;
    QStringList dataList = paramType_s.split(",");
    qDebug() << "key = " << dataList[0];
    qDebug() << "value = " << dataList[1];
    if (outParam == "fdog_list" || outParam == "fdog_set") {
        textEdit_data->append(addColorBracketsHtml(getRetract() + "["));
    } else if (outParam == "") {
        textEdit_data->append(addColorBracketsHtml(getRetract() + "["));
    } else {
        textEdit_data->append(addColorFieldHtml(getRetract() + "\"" + outParam + "\"") + addColorBracketsHtml(":["));
    }
    retractNum++;
    //值类型2
    QString temp;
    QString key_type = str.mid(0, 2);
    qDebug() << " handleList value_type key = " << key_type;
    str = str.mid(2);
    temp = temp + addColorHtml(key_type, sourceColorMap[sourceTypeMap[key_type]]);
    QString value_type = str.mid(0, 2);
    qDebug() << " handleList value_type value = " << value_type;
    temp = temp + addColorHtml(value_type, sourceColorMap[sourceTypeMap[value_type]]);
    str = str.mid(2);

    //值长度 8
    QString value_len = str.mid(0, 8);
    str = str.mid(8);
    temp = temp + addColorHtml(value_len, sourceColorMap[THRIFT_MESSAGE_LENGTH]);
    //值 需要判断是否是基础类型
    // QString value3 = str.mid(0, 8);
    // str = str.mid(8);
    bool ok;
    int len = value_len.toInt(&ok, 16);
    qDebug() << "map len = " << len;
    for(int i = 1; i <= len; i++) {
        //处理key_value
        textEdit_data->append(addColorBracketsHtml(getRetract() + "{"));
        handleMap_key(textEdit_data, str, isEnd, key_type, temp, false);
        handleMap_value(textEdit_data, str, isEnd, value_type, temp, true);
        if (i != len) {
            textEdit_data->append(addColorBracketsHtml(getRetract() + "}") + ",");
        } else {
            textEdit_data->append(addColorBracketsHtml(getRetract() + "}"));
        }
    }
    retractNum--;
    isEnd = str.mid(0, 2);
    if (isEnd == "00") {
        textEdit_data->append(addColorBracketsHtml(getRetract() + "]"));
    } else {
        textEdit_data->append(addColorBracketsHtml(getRetract() + "],"));
    }
    return temp;
}

void thriftwidget::handleMap_key(QTextEdit * textEdit_data, QString &str, QString isEnd, QString value_type, QString & temp, bool isHandEnd) {
        QString paramName = "";
        if (value_type == "02") {
            //bool
            temp = temp + handleBool(textEdit_data, str, isEnd, paramName, isHandEnd);
        } else if (value_type == "03") {
            //byte
            qDebug() << "走这里3";
            temp = temp + handleByte(textEdit_data, str, isEnd, paramName, isHandEnd);
        } else if (value_type == "04") {
            //double
            temp = temp + handleDouble(textEdit_data, str, isEnd, paramName, isHandEnd);
        } else if (value_type == "06") {
            //i16
            temp = temp + handleI16(textEdit_data, str, isEnd, paramName, isHandEnd);
        } else if (value_type == "08") {
            //i32
            temp = temp + handleI32(textEdit_data, str, isEnd, THRIFT_REPLY, paramName, isHandEnd);
        } else if (value_type == "0a") {
            //i64
            temp = temp + handleI64(textEdit_data, str, isEnd, paramName, isHandEnd);
        } else if (value_type == "0b") {
            //string
            temp = temp + handleString(textEdit_data, str, isEnd, THRIFT_REPLY, paramName, isHandEnd);
        }
}

void thriftwidget::handleMap_value(QTextEdit * textEdit_data, QString &str, QString isEnd, QString value_type, QString & temp, bool isHandEnd) {
        QString paramName = "";
        if (value_type == "02") {
            //bool
            temp = temp + handleBool(textEdit_data, str, isEnd, paramName, isHandEnd);
        } else if (value_type == "03") {
            //byte
            qDebug() << "走这里3";
            temp = temp + handleByte(textEdit_data, str, isEnd, paramName, isHandEnd);
        } else if (value_type == "04") {
            //double
            temp = temp + handleDouble(textEdit_data, str, isEnd, paramName, isHandEnd);
        } else if (value_type == "06") {
            //i16
            temp = temp + handleI16(textEdit_data, str, isEnd, paramName, isHandEnd);
        } else if (value_type == "08") {
            //i32
            temp = temp + handleI32(textEdit_data, str, isEnd, THRIFT_REPLY, paramName, isHandEnd);
        } else if (value_type == "0a") {
            //i64
            temp = temp + handleI64(textEdit_data, str, isEnd, paramName, isHandEnd);
        } else if (value_type == "0b") {
            //string
            temp = temp + handleString(textEdit_data, str, isEnd, THRIFT_REPLY, paramName, isHandEnd);
        } else if (value_type == "0c") {
            temp = temp + handleStruct(textEdit_data, str, isEnd, value_type, paramName);
        } else if (value_type == "0d") {
            temp = temp + handleMap(textEdit_data, str, isEnd, value_type, paramName);
        } else if (value_type == "0e") {
            temp = temp + handleSet(textEdit_data, str, isEnd, value_type, paramName);
        } else if (value_type == "0f") {
            temp = temp + handleList(textEdit_data, str, isEnd, value_type, paramName);
        }
}

QString thriftwidget::handleSet(QTextEdit * textEdit_data, QString &str, QString isEnd, QString outType, QString outParam, bool isHandEnd)
{
    //和list处理一致
    qDebug() << "outType =" << outType;
    int index_s = outType.indexOf("<");
    int index_e = outType.lastIndexOf(">");
    QString paramType_s = outType.mid(index_s + 1, index_e - index_s - 1);
    qDebug() << "paramType_s =" << paramType_s;
    if (outParam == "fdog_list" || outParam == "fdog_set") {
        textEdit_data->append(addColorBracketsHtml(getRetract() + "["));
    } else if (outParam == "") {
        textEdit_data->append(addColorBracketsHtml(getRetract() + "["));
    } else {
        textEdit_data->append(addColorFieldHtml(getRetract() + "\"" + outParam + "\"") + addColorBracketsHtml(":["));
    }
    retractNum++;
    //值类型 2
    QString temp;
    QString value_type = str.mid(0, 2);
    qDebug() << " handleSet value_type = " << value_type;
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
        QString paramName = "fdog_set"; //structParamMap.value(paramType_s).value(QString::number(i)).paramName;
        QString paramType = paramType_s; //structParamMap.value(paramType_s).value(QString::number(i)).paramType;
        qDebug() << " paramName  = " << paramName << " paramType = " << paramType;
        if (value_type == "02") {
            //bool
            temp = temp + handleBool(textEdit_data, str, isEnd, paramName, true, (len - i == 0));
        } else if (value_type == "03") {
            //byte
            qDebug() << "走这里3";
            temp = temp + handleByte(textEdit_data, str, isEnd, paramName, true, (len - i == 0));
        } else if (value_type == "04") {
            //double
            temp = temp + handleDouble(textEdit_data, str, isEnd, paramName, true, (len - i == 0));
        } else if (value_type == "06") {
            //i16
            temp = temp + handleI16(textEdit_data, str, isEnd, paramName, true, (len - i == 0));
        } else if (value_type == "08") {
            //i32
            temp = temp + handleI32(textEdit_data, str, isEnd, THRIFT_REPLY, paramName, true, (len - i == 0));
        } else if (value_type == "0a") {
            //i64
            temp = temp + handleI64(textEdit_data, str, isEnd, paramName, true, (len - i == 0));
        } else if (value_type == "0b") {
            //string
            temp = temp + handleString(textEdit_data, str, isEnd, THRIFT_REPLY, paramName, true, (len - i == 0));
        } else if (value_type == "0c") {
            temp = temp + handleStruct(textEdit_data, str, isEnd, paramType, paramName);
        } else if (value_type == "0d") {
            temp = temp + handleMap(textEdit_data, str, isEnd, paramType, paramName);
        } else if (value_type == "0e") {
            temp = temp + handleSet(textEdit_data, str, isEnd, paramType, paramName);
        } else if (value_type == "0f") {
            temp = temp + handleList(textEdit_data, str, isEnd, paramType, paramName);
        }
    }
    retractNum--;
    isEnd = str.mid(0, 2);
    if (isEnd == "00") {
        textEdit_data->append(addColorBracketsHtml(getRetract() + "]"));
    } else {
        textEdit_data->append(addColorBracketsHtml(getRetract() + "],"));
    }
    return temp;
}

QString thriftwidget::handleList(QTextEdit * textEdit_data, QString &str, QString isEnd, QString outType, QString outParam, bool isHandEnd)
{
    qDebug() << "outType =" << outType;
    int index_s = outType.indexOf("<");
    int index_e = outType.lastIndexOf(">");
    QString paramType_s = outType.mid(index_s + 1, index_e - index_s - 1);
    qDebug() << "paramType_s =" << paramType_s;
    if (outParam == "fdog_list" || outParam == "fdog_set") {
        textEdit_data->append(addColorBracketsHtml(getRetract() + "["));
    } else if (outParam == "") {
        textEdit_data->append(addColorBracketsHtml(getRetract() + "["));
    } else {
        textEdit_data->append(addColorFieldHtml(getRetract() + "\"" + outParam + "\"") + addColorBracketsHtml(":["));
    }
    retractNum++;
    //值类型 2
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
        QString paramName = "fdog_list"; //structParamMap.value(paramType_s).value(QString::number(i)).paramName;
        QString paramType = paramType_s; //structParamMap.value(paramType_s).value(QString::number(i)).paramType;
        qDebug() << " paramName  = " << paramName << " paramType = " << paramType;
        if (value_type == "02") {
            //bool
            temp = temp + handleBool(textEdit_data, str, isEnd, paramName, true, (len - i == 0));
        } else if (value_type == "03") {
            //byte
            qDebug() << "走这里3";
            temp = temp + handleByte(textEdit_data, str, isEnd, paramName, true, (len - i == 0));
        } else if (value_type == "04") {
            //double
            temp = temp + handleDouble(textEdit_data, str, isEnd, paramName, true, (len - i == 0));
        } else if (value_type == "06") {
            //i16
            temp = temp + handleI16(textEdit_data, str, isEnd, paramName, true, (len - i == 0));
        } else if (value_type == "08") {
            //i32
            temp = temp + handleI32(textEdit_data, str, isEnd, THRIFT_REPLY, paramName, true, (len - i == 0));
        } else if (value_type == "0a") {
            //i64
            temp = temp + handleI64(textEdit_data, str, isEnd, paramName, true, (len - i == 0));
        } else if (value_type == "0b") {
            //string
            temp = temp + handleString(textEdit_data, str, isEnd, THRIFT_REPLY, paramName, true, (len - i == 0));
        } else if (value_type == "0c") {
            temp = temp + handleStruct(textEdit_data, str, isEnd, paramType, paramName);
        } else if (value_type == "0d") {
            temp = temp + handleMap(textEdit_data, str, isEnd, paramType, paramName);
        } else if (value_type == "0e") {
            temp = temp + handleSet(textEdit_data, str, isEnd, paramType, paramName);
        } else if (value_type == "0f") {
            temp = temp + handleList(textEdit_data, str, isEnd, paramType, paramName);
        }
    }
    retractNum--;
    isEnd = str.mid(0, 2);
    if (isEnd == "00") {
        textEdit_data->append(addColorBracketsHtml(getRetract() + "]"));
    } else {
        textEdit_data->append(addColorBracketsHtml(getRetract() + "],"));
    }
    return temp;
    //return addColorHtml(value, sourceColorMap[sourceTypeMap["00"]]);
}

QString thriftwidget::handleEnd(QTextEdit * textEdit_data, QString &str)
{
    QString value = str.mid(0, 2);
    str = str.mid(2);
    return addColorHtml(value, sourceColorMap[sourceTypeMap["00"]]);
}

QString thriftwidget::hexToString(QTextEdit * textEdit_data, QString &hex)
{
    QByteArray byteArray = QByteArray::fromHex(hex.toLatin1());
    QString return_ = QString(byteArray);
    //将字符串中的"替换为\"
    return_.replace("\"", "\\\"");
    return return_;
}

QString thriftwidget::hexToLongNumber(QTextEdit * textEdit_data, QString &hex)
{   
    //qDebug() << "hex = " << hex << " 对应数据" << strtoll(hex.toStdString().c_str(), nullptr, 16);
    return QString::number(strtoll(hex.toStdString().c_str(), nullptr, 16));
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
        retract = retract + "    ";
    }
    return retract;
}

void thriftwidget::deleteComments(char *buf, int n)
{
    char *p, *end, c;

    p = buf;
    end = buf + n;

    char *pos1 = NULL, *pos2 = NULL;
    bool flag1 = false, flag2 = false;// "   and   '
    int flag3 = 0, flag4 = 0, flag5 = 0;// for /*...     //...      */

    while( p < end)
    {
        c = *p;
        //qDebug()  << "new char: " << c <<endl;
        switch(c)
        {
        case '"':
        {
            if (flag3 == 0)
                flag1 = (flag1 == true)?false:true;
            p ++;
        } break;
        case '\'':
        {
            if (flag3 == 0)
                flag2 = (flag2 == true)?false:true;
            p ++;
        } break;
        case '/':
        {
            p ++;
            if (*p == '/' && (flag3 == 0))    // ..... //....
            {
                p ++;
                //qDebug() << "in // " << endl;
                //qDebug()  << "1 falg3: " << flag3 << "  flag5: " << flag5 << "  flag1: " << flag1 << "  flag2: " << flag2 << endl;
                if (!flag1 && !flag2 && (flag5 == 0) && (flag4 == 0) && (flag3 == 0))
                {
                    //flag4 ++;
                    // deal with //...:delete char until '\n'
                    //qDebug()  << "deal with // ..." << endl;

                    *(p-1) = ' ';
                    *(p-2) = ' ';
                    while (*p != '\n')
                    {
                        //qDebug()  << "dealing : " << *p << "   ";
                        *p = ' ';
                        p ++;
                    }
                }

            }
            else if ( *p == '*' && !flag1 && !flag2 && (flag3 == 0))    // ....  /*.....
            {
                p ++;
                flag3 ++;
                //qDebug()  << "2 falg3: " << flag3 << "  flag5: " << flag5 << "  flag1: " << flag1 << "  flag2: " << flag2 << endl;
                if (!flag1 && !flag2 && (flag4 == 0) && (flag3 == 1))
                {
                    pos1 = p;// delete from pos1
                }
            }
        }break;
        case '*':
        {
            p ++;
            if (*p == '/' && !flag1 && !flag2)  // .... */...
            {
                flag5 ++;
                //qDebug()  << "3 falg3: " << flag3 << "  flag5: " << flag5 << "  flag1: " << flag1 << "  flag2: " << flag2 << endl;
                if(!flag1 && !flag2 && (flag3 != 0) && (flag5 != 0))
                {
                    flag3 = 0;
                    flag5 --;
                    pos2 = p - 2;
                    //qDebug()  << "deal with  \/* .. *\/" << endl;
                    // deal wtih /*... */... : delete from pos1 to pos2
                    char *pos = pos1;
                    *(pos - 1) = ' ';
                    *(pos - 2) = ' ';
                    *(pos2 + 1) = ' ';
                    *(pos2 + 2) = ' ';

                    do {
                        //qDebug()  << "dealing: " <<  *pos << endl;
                        *pos = ' ';
                        pos ++;
                    } while(pos != pos2 + 1);
                }
            }
        } break;
        default:
            p ++;
            break;
        }
    }
}

void thriftwidget::handleComments(QString &fileContent) {
    qDebug() << "原数据1 = " << fileContent;
    fileContent.replace("\t", "");
    QRegularExpression re("[\u4e00-\u9fa5]+");
    fileContent.replace(re, "  ");
    qDebug() << "原数据2 = " << fileContent;

    //删除thrift include头
    while (fileContent.contains("include")) {
        int index_s = fileContent.indexOf("include");
        //查找\n
        int index_e = fileContent.indexOf("\n", index_s + 7);
        //qDebug() << "删除一次include = " << fileContent.mid(index_s, index_e + 1);
        //删除头
        fileContent.remove(index_s, index_e + 1);
    }

    //删除thrift namespace头
    while (fileContent.contains("namespace")) {
        int index_s = fileContent.indexOf("namespace");
        //查找\n
        int index_e = fileContent.indexOf("\n", index_s + 9 + 1);
        //删除头
        //qDebug() << "删除一次namespace = " << fileContent.mid(index_s, index_e + 1);
        fileContent.remove(index_s, index_e);

    }

    //处理多的空格
    while(fileContent.contains("  ")) {
        fileContent.replace("  ", " ");
    }
    //删除注释
    char *charArray = strdup(fileContent.toUtf8().constData());
    //qDebug() << " fileContent.length() =" << fileContent.length();
    deleteComments(charArray, fileContent.length());
    fileContent = QString::fromUtf8(charArray);
    qDebug() << "原数据3 = " << fileContent;
    free(charArray);
    return;
}

void thriftwidget::handleExtraSpace(QString &func, QString type) {
    int sum1 = 0;
    while (func.mid(sum1).contains(type)) {
        //qDebug() << "list 有空格";
        int sum = 0;
        int index_left_map = func.indexOf(type, sum1);
        if (index_left_map != -1) {
            sum++;
        }
        //这里有问题 func长度是实时变化的
        for (int i = index_left_map + type.length(); i < func.length(); i++) {
            //qDebug() << "char = " << func[i];
            if (func[i] == "<") {
                sum++;
            } else if (func[i] == ">") {
                sum--;
            } else if (func[i] == " ") {
                //qDebug() << "list 有空格 移除空格";
                //qDebug() << "char2 = " << func[i+1];
                func.remove(i, 1);
                i = i -1;
            }
            if (sum == 0) {
                sum1 = i;
                break;
            }
        }
    }
    return ;
}

QString thriftwidget::getServerInterface(QString &fileContent) {
    QString funcServerName;

    QString fileContent_temp;
    QString fileContent_return;
    //查找server
    int index = fileContent.contains("service");
    if (index) {
        int index2 = fileContent.indexOf("service");

        fileContent_temp = fileContent.mid(index2);

        int index3 = fileContent_temp.indexOf("{");
        funcServerName = fileContent_temp.mid(0, index3).split(" ", QString::SkipEmptyParts)[1];
        qDebug() << "所属服务 " << funcServerName;
        QTreeWidgetItem *parentItem = new QTreeWidgetItem(ui->treeWidget_api);
        QIcon icon2(":/lib/server.png");
        parentItem->setText(0, funcServerName);
        parentItem->setIcon(0, icon2);
        parentItem->setExpanded(true);
        fileContent_temp = fileContent_temp.mid(index3 + 1);
        int index4 = fileContent_temp.indexOf("}");

        fileContent_temp = fileContent_temp.mid(0, index4);

        //获取结构体部分
        fileContent_return = fileContent.mid(0, index2); //获取结构体部分 其实这就可以 暂时不考虑service后面还有struct

        //fileContent.replace(" ","");
        //qDebug() << " fileContent_temp = " << fileContent_temp;
        //处理多的空格
        while(fileContent_temp.contains(" void ")) {
            fileContent_temp.replace(" void ", "  ");
        }

        while(fileContent_temp.contains("  ")) {
            fileContent_temp.replace("  ", " ");
        }
        //qDebug() << " fileContent_temp = " << fileContent_temp;
        QStringList list = fileContent_temp.split("\n", QString::SkipEmptyParts);
        //接口长度不能小于3
        //qDebug() << "list = " << list;
        //开始循环解析接口部分
        for (int i = 0; i < list.length(); i++) {
            if (list[i].length() <= 3) {
                continue;
            }

            if (containsChinese(list[i].trimmed())) {
                continue;
            }

            QString func = list[i].trimmed();
            //qDebug() << " func = " << func;

            if (func.contains("map<")) {
                handleExtraSpace(func, "map<");
            }

            if (func.contains("list<")) {
                handleExtraSpace(func, "list<");
            }

            if (func.contains("set<")) {
                handleExtraSpace(func, "set<");
            }

            int index5 = func.indexOf(" ");
            QString funcParam_outparam = func.mid(0, index5);
            QString funcName1 =func.mid(index5).trimmed();

            int index6 = funcName1.indexOf("(");
            QString funcName = funcName1.mid(0, index6).replace(" ", "");

            //qDebug() << "加载接口 " << funcName;

            QString funcParam_inparam = funcName1.mid(index6 + 1);
            int index7 = funcParam_inparam.indexOf(")");
            funcParam_inparam = funcParam_inparam.mid(0, index7);

            bool isok = false;
            funcParamOutMap.insert(funcName, getFuncOutParams(funcParam_outparam));
            if (funcParam_inparam != "") {
                funcParamInMap.insert(funcName, getFuncInParams(funcParam_inparam, isok));
            } else {
                isok = true;
            }

            if (!isok) {
                funcParamInMap.remove(funcName);
                funcParamOutMap.remove(funcName);
                //提醒一下前端
                ui->label_time->setText(funcName + " 接口格式存在问题，解析失败，跳过该接口");
                qDebug() << "加载接口失败 " << funcName;
                continue;
            }

            // 创建一个QIcon对象并设置图标
            QIcon icon1(":/lib/api.png"); // 设置您的图标路径

            QTreeWidgetItem *childItem1 = new QTreeWidgetItem(parentItem);
            //添加函数接口
            childItem1->setText(0, funcName); //funcServerName
            childItem1->setIcon(0, icon1);
            //暂时使用这种  复杂场景用QAbstractItemModel
            dataSource.append(funcServerName + "." + funcName);
        }

        QCompleter *completer = new QCompleter(dataSource, this);

        QAbstractItemView* view = completer->popup();
        view->setItemDelegate(new ComboBoxDelegate());//设置行高
        // completer->popup()->setStyleSheet("QListView{background-color: #FFFFFF;"
        //                                         "color: #353637;"
        //                                         "selection-background-color: #3A72D8;"
        //                                         "selection-color: white;"
        //                                         "show-decoration-selected: 1;"
        //                                         "font-size: 14pt;");
        completer->popup()->setStyleSheet("QScrollBar::handle:horizontal {\
                                                height: 8px;\
                                                background-color: rgb(239, 239, 239);\
                                                /*滚动条两端变成椭圆 */\
                                                border-radius: 2px;\
                                                min-height: 0;\
                                            }\
                                            QScrollBar::sub-page:horizontal {\
                                                background-color: rgba(255, 255, 255, 0);\
                                            }\
                                            QScrollBar::add-page:horizontal \
                                            {\
                                                background-color: rgba(255, 255, 255, 0);\
                                            }\
                                            QScrollBar::add-line:horizontal {\
                                                border: none;\
                                                height: 0px;\
                                                subcontrol-position: bottom;\
                                                subcontrol-origin: margin;\
                                            }\
                                            QScrollBar::sub-line:horizontal {\
                                                border: none;\
                                                height: 0px;\
                                                subcontrol-position: top;\
                                                subcontrol-origin: margin;\
                                            }\
                                            QScrollBar::down-arrow:horizontal {\
                                                border:none;\
                                            }\
                                            QScrollBar::up-arrow:horizontal {\
                                                border:none;\
                                            }");



        completer->setCaseSensitivity(Qt::CaseInsensitive); //大小写不敏感
        completer->setFilterMode(Qt::MatchContains); //内容匹配
        connect(completer,SIGNAL(activated(const QString)),this,SLOT(rece_activated(const QString)));
        connect(completer,SIGNAL(highlighted(const QString)),this,SLOT(rece_highlighted(const QString)));
        ui->lineEdit_find->setCompleter(completer);

    } else {
        fileContent_return = fileContent;
    }

    return fileContent_return;
}

void thriftwidget::getStructInfo(QString &fileContent) {
    while(true) {
        if (fileContent.contains("struct")) {
            //获取结构体名
            int index_struct = fileContent.indexOf("struct");
            int index_s = fileContent.indexOf("{");
            //把中间空格删掉
            for(int i = index_struct + 7; i < index_s; i++) {
                if (fileContent[i] == " ") {
                    fileContent.remove(i, 1);
                }
            }
            index_s = fileContent.indexOf("{");
            QString structName = fileContent.mid(index_struct + 7, index_s - index_struct - 7);

            int index_e = fileContent.indexOf("}");
            QString data = fileContent.mid(index_s + 1, index_e - index_s - 1);
            fileContent = fileContent.mid(index_e + 1);
            structParamMap.insert(structName, getStructParams(data));
            //qDebug() << "加载实体 " << structName;
        } else {
            break;
        }
    }
    return;
}

bool thriftwidget::containsChinese(QString str) {
    for (int i = 0; i < str.length(); ++i)
    {
        QChar c = str.at(i);
        if (c >= 0x4E00 && c <= 0x9FFF)
        {
            // 当前字符是中文
            return true;
        }
    }
    // 没有发现中文字符
    return false;
}

QMap<int, paramInfo> thriftwidget::getFuncInParams(QString data, bool & isok)
{
    //四种解析
    //1: SessionTicket st, 2: i64 userID
    //1:ThesaurusPage pageParam
    //1:i64 ct,2:i64 userID
    //1: SessionTicket st ,2: byte reqType
    isok = true;

    QMap<int, paramInfo> paramsMap_;

    //先判断是一个参数，还是多个参数
    //qDebug() << "getFuncInParams = " << data;
    if (!data.contains(",")) {
        //一个参数
        int index = data.indexOf(":");
        data = data.mid(0, index + 1) + " " + data.mid(index + 1);
        //qDebug() << "data = " << data;
    }

    //先处理:
    //qDebug() << "=========";
    while(data.contains("  ")){
        data.replace("  ", " ");
    }

    while(data.contains(" :")){
        data.replace(" :", ":");
    }
    while(data.contains(": ")){
        data.replace(": ", ":");
    }

    if (!data.contains(":")) {
        qDebug() << "错误";
        isok = false;
        return paramsMap_;
    }
    
    while(data.contains(";")){
        data.replace(";", ",");
    }

    int a =0;
    bool isMap = false;

    while(data.contains(":")){
        //1:SessionTicket st, 2: SettingList settingList 3: list<i64> targetUserIDList  这种也是正常的
        //可能将2: SettingList settingList 3: list<i64> targetUserIDList解析成一个参数
        //这种解析失败，进行提示，不做这种解析，

        //qDebug() << "while data.length() = " << data.length();
        int sum = 0;
        for(int i = data.length() -1; i >= 0; i--) {
            if (data[i] == ":") {
                sum++;
            }
            if (sum != 0 && (data[i] == "," || i == 0)) {
                if (data[i] == ",") {
                    if (-1 == data.mid(i + 1).indexOf(":")) {
                        qDebug() << "跳过";
                        continue;
                    }
                    
                }
                //获取
                int temp = 0;
                if (i == 0) {
                    temp = 0;
                } else {
                    temp = 1;
                }
                QString param1 = data.mid(i + temp);
                //qDebug() << "param1 = " << param1;

                data = data.mid(0, i + temp); //删除逗号
                //qDebug() << "剩下 = " << data;
                int index = param1.indexOf(":");
                QString sn = param1.mid(0, index).replace(" ", "").replace(",", "");; //防止有逗号
                param1 = param1.mid(index + 1);
                //qDebug() << "结果 param1 = " << param1;
                QStringList Params = param1.split(" ", QString::SkipEmptyParts); //类型和名字必然有空格
                if (Params.length() == 2) {
                    QString paramType = Params[0];
                    QString paramName = Params[1].replace(",", ""); //防止有逗号;
                    if (paramName == Params[1]) {
                        QString paramName = Params[1].replace(" ,", ""); //防止有逗号;
                    }
                    paramsMap_.insert(sn.toInt(), {paramType, paramName, "opt-in, req-out"});
                    //qDebug() << " sn = " << sn << " paramType = " << paramType << " paramName" << paramName;
                } else if (Params.length() == 3 && Params[2] == ",") {
                    QString paramType = Params[0];
                    QString paramName = Params[2].replace(",", ""); //防止有逗号;
                    paramsMap_.insert(sn.toInt(), {paramType, paramName, "opt-in, req-out"});
                    //qDebug() << " sn = " << sn << " paramType = " << paramType << " paramName" << paramName;
                } else {
                    qDebug() << "错误";
                    isok = false;
                }
                continue;
            }
        }
    }

    return paramsMap_;
}

QMap<int, paramInfo> thriftwidget::getFuncOutParams(QString data)
{
    //qDebug() << "getFuncOutParams1 data =" << data;
    QMap<int, paramInfo> paramsMap_;
    //只可能有一个返回值，判断是不是基础类型
    if (data.startsWith("map")) {
        //复杂类型
        qDebug() << "map类型";
        paramsMap_.insert(1, {data, "", "opt-in, req-out"});
    } else if (data.startsWith("set")) {
        //复杂类型
        qDebug() << "set类型";
        paramsMap_.insert(1, {data, "", "opt-in, req-out"});
    } else if (data.startsWith("list")) {
        //复杂类型
        qDebug() << "list类型";
        paramsMap_.insert(1, {data, "", "opt-in, req-out"});
        //qDebug() << "getFuncOutParams2 data =" << data;
        //获取list成员类型
    } else if (baseType.contains(data)) {
        qDebug() << "基础类型";
        //基础类型
    } else {
        //struct
        paramsMap_.insert(1, {data, "", "opt-in, req-out"});
        //qDebug() << "getFuncOutParams2 data =" << data;
    }

    return paramsMap_;
}

QMap<int, structInfo> thriftwidget::getStructParams(QString data)
{
    QMap<int, structInfo> paramsStructMap_;
    //按照\n分割，排空
    QStringList list = data.split("\n", QString::SkipEmptyParts);
    //qDebug() << "list = " << list;
    for (int i = 0; i < list.length(); i++) {
        QString str = list[i];
        //分割序号，类型，名字
        //查找:
        int index = str.indexOf(":");
        QString sn = str.mid(0, index).replace(" ", "");
        QStringList a = str.mid(index + 1).split(" ", QString::SkipEmptyParts);
        if (a.length() == 2) {
            QString type = a[0].replace(";", "");
            QString name = a[1].replace(";", "").replace(",", "");
            //qDebug() << "sn = " << sn << " type = " << type << " name =" << name;
            paramsStructMap_.insert(sn.toInt(), {type, name, "opt-in, req-out"});
        } else if (a.length() == 3) {
            if (a[0] == "optional") {
                //qDebug() << "选传";
            } else if (a[0] == "required") {
                //qDebug() << "提示";
            }
            QString type = a[1].replace(";", "");
            QString name = a[2].replace(";", "");
            //qDebug() << "sn = " << sn << " type = " << type << " name = " << name;
            paramsStructMap_.insert(sn.toInt(), {type, name, a[0]});
        }
    }
    return paramsStructMap_;
}

ItemWidget* thriftwidget::createAndGetNode(thriftwidget * p)
{
    //qDebug() << "createAndGetNode 创建1";
    ItemWidget* items = new ItemWidget();
    items->mastLabel->hide();
    connect(items, SIGNAL(send_buttonClicked(QTreeWidgetItem*)), p, SLOT(rece_deleteItem(QTreeWidgetItem*)));
    connect(items, SIGNAL(send_buttonClicked_add(QTreeWidgetItem*)), p, SLOT(rece_addItem(QTreeWidgetItem*)));
    connect(items, SIGNAL(send_buttonClicked_add_column(QTreeWidgetItem*)), p, SLOT(rece_addColumn(QTreeWidgetItem*)));
    connect(items, SIGNAL(send_onTextChanged(QString, QTreeWidgetItem*)), p, SLOT(rece_TextChanged(QString, QTreeWidgetItem*)));
    connect(items, SIGNAL(send_currentIndexChanged(QString, QTreeWidgetItem*)), p, SLOT(rece_currentIndexChanged(QString, QTreeWidgetItem*)));
    return items;
}

void thriftwidget::handleBinData() {
        // 将数据转换为主机字节序
        QStringList dataList2;
        QString dataTemp; //输出
        QString dataTemp_2;
        //int countLength = -1; //设置数据长度，到达后不再读取 加上开头长度数据
        int nowLength = 0; //设置数据长度，到达后不再读取
        ui->stackedWidget->setCurrentIndex(0);
        int sum = 0;
        int sum_2 =0;
        for (uint32_t data : receivedData) {
            data = qFromBigEndian(data);
            std::stringstream stream;
            //每次读取一个字节
            stream << std::hex << std::setw(8) << std::setfill('0') << data;
            sum_2++;
            dataList2.append(QString::fromStdString(stream.str()));
            QString temp2 = QString::fromStdString(stream.str());
            dataTemp_2 = dataTemp_2 + temp2; //染色用
            dataTemp = dataTemp + temp2 + "  ";
            // if (countLength == -1) {
            //     //读取头获取数据长度
            //     countLength = 4 + strtol(dataList2[0].toStdString().c_str(), nullptr, 16);
            //     //qDebug() << "countLength = " << countLength - 4;
            // }
            nowLength = nowLength + 4;
            //qDebug() << "nowLength + 4 = " << nowLength;

            sum++;
            //每8个段进行下一步
            if (sum == 8) {
                sum = 0;
                if (!isTestModle) {
                    ui->textEdit->append(dataTemp);
                }
                //qDebug() << "dataTemp = " << dataTemp;
                dataTemp = "";
            }

        }
        ui->textEdit->append(dataTemp);
        if (!isTestModle) {
            ui->textEdit->append("------------------------------------------------------------------------------");
            //对数据进行染色
            handleMessage(ui->textEdit_data, dataTemp_2);
            //将数据更加细致格式化，如果勾选了的话
            if (ui->checkBox_show_json->isChecked()) {
                QString needToJsonData = ui->textEdit_data->toPlainText();
                ui->textEdit_data->clear();
                if (ui->checkBox_super->isChecked()) {
                    utils_parsingJsonInfo(ui->textEdit_data, needToJsonData, true);
                } else {
                    utils_parsingJsonInfo(ui->textEdit_data, needToJsonData);
                }
                
            }
            ui->textEdit->append("染色数据(颜色信息可查看thrift协议报文说明):");
            ui->textEdit->append(dataTemp_2);
            ui->textEdit->append("------------------------------------------------------------------------------");
        }
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
}

void thriftwidget::handleHexData(QTextEdit * textEdit_data, QTextEdit * textEdit_data2, QString& data)
{
    qDebug() << "handleHexData data = " << data;
    //解析https请求返回的数据
    int sum = 0;
    QString dataTemp;
    for (int i = 0; i < data.length(); i+=8) {
        sum++;
        dataTemp = dataTemp + data.mid(i, 8) + "  ";
        if (sum == 8) {
            sum = 0;
            if (!isTestModle) {
                textEdit_data2->append(dataTemp);
            }
            dataTemp = "";
        }
    }
    
    textEdit_data2->append("------------------------------------------------------------------------------");
    //对数据进行染色
    handleMessage(textEdit_data, data);
    //json格式化
    //将数据更加细致格式化，如果勾选了的话
    if (ui->checkBox_show_json->isChecked()) {
        QString needToJsonData = textEdit_data->toPlainText();
        textEdit_data->clear();
        if (ui->checkBox_super->isChecked()) {
            utils_parsingJsonInfo(textEdit_data, needToJsonData, true);
        } else {
            utils_parsingJsonInfo(textEdit_data, needToJsonData);
        }
    }

    textEdit_data2->append("染色数据(颜色信息可查看thrift协议报文说明):");
    textEdit_data2->append(data);
    textEdit_data2->append("------------------------------------------------------------------------------");
}

void thriftwidget::readPreData()
{
    //固定读取thriftConfig/preData.txt
    // 定义文件名
    QString fileName = "thriftConfig\\preData.txt";
    // 创建文件对象
    QFile file(fileName);
 
    // 打开文件，并且以只读方式进行读取
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        // 读取文件内容
        QByteArray fileData = file.readAll();
        // 关闭文件
        file.close();
        // 输出读取的文件内容
        //qDebug() << "读取的文件内容:" << fileData;
        QStringList preDataList = QString(fileData).split("\n");
        //qDebug() << "读取的文件内容:" << preDataList;
        for (int i = 0; i < preDataList.size(); i++) {
            int index = preDataList.at(i).indexOf(":");
            QString key = preDataList.at(i).mid(0, index);
            QString value = preDataList.at(i).mid(index + 1);
            if("${" == value.mid(0, 2)){
                readPreDataVector(key, value.mid(2,value.length()-3));
                preDataMap.insert(key, "${}");
            } else {
                preDataMap.insert(key, value);
            }
            
            //qDebug() << "key = " << key << " value = " << value;
        }
    } else {
        // 如果文件打开失败，则输出错误信息
        qDebug() << "打开文件失败!";
    }
}

void thriftwidget::readPreDataVector(QString key, QString path)
{
    qDebug() << "path = " << path;
    QString fileName = path;
    // 创建文件对象
    QFile file(fileName);
 
    // 打开文件，并且以只读方式进行读取
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        // 读取文件内容
        QByteArray fileData = file.readAll();
        // 关闭文件
        file.close();
        // 输出读取的文件内容
        //qDebug() << "读取的文件内容:" << fileData;
        QStringList preDataList = QString(fileData).split("\n");
        //qDebug() << "读取的文件内容:" << preDataList;
        QVector<QString> v;
        for (int i = 0; i < preDataList.size(); i++) {
            v.push_back(preDataList[i]);
        }
        qDebug() << "v = " << v;
        preDataMapV.insert(key, v);

    } else {
        // 如果文件打开失败，则输出错误信息
        qDebug() << "打开文件失败!";
    }
}

void thriftwidget::handleThriftFile(QStringList fileList) {
    for (int i = 0; i < fileList.length(); i++) {
        QString selectedFile = fileList[i];
        QFile file(selectedFile);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            //中文乱码问题
            in.setCodec("UTF-8");
            QString fileContent = in.readAll();
            file.close();

            //处理注释
            handleComments(fileContent);
            //查找server接口 并处理入参出参
            QString fileContent_s = getServerInterface(fileContent);
            //查找struct
            getStructInfo(fileContent_s);

        } else {
            qDebug() << "Failed to open file:" << file.errorString();
        }
    }
}

QVector<int> thriftwidget::distributeRequests(int totalRequests, int numThreads)
{
    QVector<int> threadTasks;
    
    // 1. 计算平均值
    int averageTasks = totalRequests / numThreads;

    // 2. 假设首项比平均值稍大，例如多 10%
    int a1 = static_cast<int>(averageTasks * 1.1);

    // 3. 根据等差数列和公式计算公差 d
    double d = static_cast<double>(2 * (totalRequests - numThreads * a1)) / (numThreads * (numThreads - 1));

    // 4. 分配任务
    int remainingRequests = totalRequests;  // 剩余任务数，用于校验和调整
    for (int i = 0; i < numThreads; ++i) {
        int tasks = static_cast<int>(std::round(a1 + i * d));  // 当前线程任务数
        if (tasks < 0) tasks = 0;  // 防止出现负值

        threadTasks.append(tasks);
        remainingRequests -= tasks;
    }

    // 5. 校验任务总数是否与 totalRequests 相符，调整最后一个线程的任务数
    if (remainingRequests != 0) {
        threadTasks.last() += remainingRequests;  // 将多余的任务加到最后一个线程
    }

    return threadTasks;
}

void thriftwidget::buildChart1() {
    for (int i = 0; i < 50; ++i) {
        data_cpu.append(0);
    }
    //创建曲线图
    // 创建 Qt Charts
    chart_cpu = new QChart();
    //series_cpu = new QSplineSeries();
    series_cpu2 = new QLineSeries();
    areaSeries_cpu = new QAreaSeries(series_cpu2);
    areaSeries_cpu->setName("");
    areaSeries_cpu->setBrush(QBrush(QColor(51, 240, 242, 100)));
    areaSeries_cpu->setPen(QPen(QColor(51, 240, 242, 255)));

    chart_cpu->addSeries(areaSeries_cpu);
    // X 轴 (时间点)
    axisX_cpu = new QValueAxis();
    axisX_cpu->setRange(0, maxPoints);
    axisX_cpu->setLabelFormat("%d");
    axisX_cpu->setTitleText("");
    axisX_cpu->setTickCount(20); // 增加主刻度数量
    chart_cpu->addAxis(axisX_cpu, Qt::AlignBottom);
    //series_cpu->attachAxis(axisX_cpu);
    areaSeries_cpu->attachAxis(axisX_cpu);
    axisX_cpu->setLabelsVisible(false); // 隐藏 X 轴上的刻度值
    // Y 轴 (CPU 使用率)
    axisY_cpu = new QValueAxis();
    axisY_cpu->setRange(0, 100);
    axisY_cpu->setLabelFormat("%d%%");
    axisY_cpu->setTitleText("");
    chart_cpu->addAxis(axisY_cpu, Qt::AlignLeft);
    //series_cpu->attachAxis(axisY_cpu);
    areaSeries_cpu->attachAxis(axisY_cpu);
    axisY_cpu->setLabelsVisible(false); // 隐藏 X 轴上的刻度值

    // 设置网格线颜色
    QPen gridPen(QColor(255, 255, 255, 50));  // 设为红色
    gridPen.setWidth(0);    // 设为1像素宽
    axisX_cpu->setGridLinePen(gridPen);
    axisY_cpu->setGridLinePen(gridPen);

    //设置背景区域圆角角度
    chart_cpu->setBackgroundRoundness(0);
    //设置内边界边距
    chart_cpu->setMargins(QMargins(0, 0, 0, 0));
    //设置外边界边距
    chart_cpu->layout()->setContentsMargins(0, 0, 0, 0);
    chart_cpu->legend()->setAlignment(Qt::AlignBottom);
    chart_cpu->legend()->setVisible(true);
    chart_cpu->legend()->hide();
    chart_cpu->removeAxis(axisX_cpu);
    chart_cpu->removeAxis(axisY_cpu);


    axisX_cpu->setLineVisible(false);
    axisX_cpu->setLabelsVisible(false);
    axisX_cpu->setGridLineVisible(false);

    axisY_cpu->setLineVisible(false);
    axisY_cpu->setLabelsVisible(false);
    axisY_cpu->setGridLineVisible(false);
    // 设置图表背景颜色为透明
    chart_cpu->setBackgroundVisible(false);
    // 设定 Chart 视图
    chartView_cpu = new QChartView(chart_cpu);
    chartView_cpu->setRenderHint(QPainter::Antialiasing);
    chartView_cpu->setStyleSheet("background: transparent;");
    ui->widget_chart1->layout()->addWidget(chartView_cpu);
}

void thriftwidget::updateChart1(int value) {
    ui->label_cpu->setText("CPU使用率(" + QString::number(value) + "%)");
    data_cpu.append(value);
    
    if (data_cpu.size() > maxPoints)
    data_cpu.remove(0);

    // 更新曲线数据 1秒2个    1分钟120个  5分钟600个
    series_cpu2 ->clear();
    for (int i = 0; i < data_cpu.size(); ++i) {
        series_cpu2->append(i, data_cpu[i]);
        //lowerSeries->append(i, 0);
    }
    //qDebug() << "value1 = " << data_cpu;
    //qDebug() << "value2 = " << series_cpu2;

    axisX_cpu->setRange(0, data_cpu.size());
}

void thriftwidget::buildChart2() {
    for (int i = 0; i < 50; ++i) {
        data_mem.append(0);
    }
    //创建曲线图
    chart_mem = new QChart();
    series_mem = new QLineSeries();
    areaSeries_mem = new QAreaSeries(series_mem);
    areaSeries_mem->setName("");
    areaSeries_mem->setBrush(QBrush(QColor(51, 240, 242, 100)));
    areaSeries_mem->setPen(QPen(QColor(51, 240, 242, 255)));

    chart_mem->addSeries(areaSeries_mem);
    // X 轴 (时间点)
    axisX_mem = new QValueAxis();
    axisX_mem->setRange(0, maxPoints);
    axisX_mem->setLabelFormat("%d");
    axisX_mem->setTitleText("");
    axisX_mem->setTickCount(20); // 增加主刻度数量
    chart_mem->addAxis(axisX_mem, Qt::AlignBottom);
    areaSeries_mem->attachAxis(axisX_mem);
    axisX_mem->setLabelsVisible(false); // 隐藏 X 轴上的刻度值
    // Y 轴 (CPU 使用率)
    axisY_mem = new QValueAxis();
    axisY_mem->setRange(0, 100);
    axisY_mem->setLabelFormat("%d%%");
    axisY_mem->setTitleText("");
    chart_mem->addAxis(axisY_mem, Qt::AlignLeft);
    areaSeries_mem->attachAxis(axisY_mem);
    axisY_mem->setLabelsVisible(false); // 隐藏 X 轴上的刻度值

    // 设置网格线颜色
    QPen gridPen(QColor(255, 255, 255, 50));  // 设为红色
    gridPen.setWidth(0);    // 设为1像素宽
    axisX_mem->setGridLinePen(gridPen);
    axisY_mem->setGridLinePen(gridPen);

    //设置背景区域圆角角度
    chart_mem->setBackgroundRoundness(0);
    //设置内边界边距
    chart_mem->setMargins(QMargins(0, 0, 0, 0));
    //设置外边界边距
    chart_mem->layout()->setContentsMargins(0, 0, 0, 0);
    chart_mem->legend()->setAlignment(Qt::AlignBottom);
    chart_mem->legend()->setVisible(true);
    chart_mem->legend()->hide();
    chart_mem->removeAxis(axisX_mem);
    chart_mem->removeAxis(axisY_mem);


    axisX_mem->setLineVisible(false);
    axisX_mem->setLabelsVisible(false);
    axisX_mem->setGridLineVisible(false);

    axisY_mem->setLineVisible(false);
    axisY_mem->setLabelsVisible(false);
    axisY_mem->setGridLineVisible(false);
    // 设置图表背景颜色为透明
    chart_mem->setBackgroundVisible(false);
    // 设定 Chart 视图
    chartView_mem = new QChartView(chart_mem);
    chartView_mem->setRenderHint(QPainter::Antialiasing);
    chartView_mem->setStyleSheet("background: transparent;");
    ui->widget_chart2->layout()->addWidget(chartView_mem);
}

void thriftwidget::updateChart2(int value) {
    ui->label_mem->setText("内存使用率(" + QString::number(value) + "%)");
    data_mem.append(value);
    
    if (data_mem.size() > maxPoints)
    data_mem.remove(0);

    // 更新曲线数据 1秒2个    1分钟120个  5分钟600个
    series_mem ->clear();
    for (int i = 0; i < data_mem.size(); ++i) {
        series_mem->append(i, data_mem[i]);
    }
    //qDebug() << "value1 = " << data_mem;
    //qDebug() << "value2 = " << series_mem;

    axisX_mem->setRange(0, data_mem.size());
}

void thriftwidget::buildChart3() {
    for (int i = 0; i < 50; ++i) {
        data_io.append(0);
    }
    //创建曲线图
    chart_io = new QChart();
    series_io = new QLineSeries();
    areaSeries_io = new QAreaSeries(series_io);
    areaSeries_io->setName("");
    areaSeries_io->setBrush(QBrush(QColor(51, 240, 242, 100)));
    areaSeries_io->setPen(QPen(QColor(51, 240, 242, 255)));

    chart_io->addSeries(areaSeries_io);
    // X 轴 (时间点)
    axisX_io = new QValueAxis();
    axisX_io->setRange(0, maxPoints);
    axisX_io->setLabelFormat("%d");
    axisX_io->setTitleText("");
    axisX_io->setTickCount(20); // 增加主刻度数量
    chart_io->addAxis(axisX_io, Qt::AlignBottom);
    areaSeries_io->attachAxis(axisX_io);
    axisX_io->setLabelsVisible(false); // 隐藏 X 轴上的刻度值
    // Y 轴 (CPU 使用率)
    axisY_io = new QValueAxis();
    axisY_io->setRange(0, 100);
    axisY_io->setLabelFormat("%d%%");
    axisY_io->setTitleText("");
    chart_io->addAxis(axisY_io, Qt::AlignLeft);
    areaSeries_io->attachAxis(axisY_io);
    axisY_io->setLabelsVisible(false); // 隐藏 X 轴上的刻度值

    // 设置网格线颜色
    QPen gridPen(QColor(255, 255, 255, 50));  // 设为红色
    gridPen.setWidth(0);    // 设为1像素宽
    axisX_io->setGridLinePen(gridPen);
    axisY_io->setGridLinePen(gridPen);

    //设置背景区域圆角角度
    chart_io->setBackgroundRoundness(0);
    //设置内边界边距
    chart_io->setMargins(QMargins(0, 0, 0, 0));
    //设置外边界边距
    chart_io->layout()->setContentsMargins(0, 0, 0, 0);
    chart_io->legend()->setAlignment(Qt::AlignBottom);
    chart_io->legend()->setVisible(true);
    chart_io->legend()->hide();
    chart_io->removeAxis(axisX_io);
    chart_io->removeAxis(axisY_io);


    axisX_io->setLineVisible(false);
    axisX_io->setLabelsVisible(false);
    axisX_io->setGridLineVisible(false);

    axisY_io->setLineVisible(false);
    axisY_io->setLabelsVisible(false);
    axisY_io->setGridLineVisible(false);
    // 设置图表背景颜色为透明
    chart_io->setBackgroundVisible(false);
    // 设定 Chart 视图
    chartView_io = new QChartView(chart_io);
    chartView_io->setRenderHint(QPainter::Antialiasing);
    chartView_io->setStyleSheet("background: transparent;");
    ui->widget_chart3->layout()->addWidget(chartView_io);
}

void thriftwidget::updateChart3(int value) {
    ui->label_io->setText("磁盘使用率(" + QString::number(value) + "%)");
    data_io.append(value);
    
    if (data_io.size() > maxPoints)
    data_io.remove(0);

    // 更新曲线数据 1秒2个    1分钟120个  5分钟600个
    series_io ->clear();
    for (int i = 0; i < data_io.size(); ++i) {
        series_io->append(i, data_io[i]);
    }
    //qDebug() << "value1 = " << data_io;
    //qDebug() << "value2 = " << series_io;

    axisX_io->setRange(0, data_io.size());
}

void thriftwidget::buildChartP() {
    for (int i = 0; i < 50; ++i) {
        data_p1.append(0);
        data_p2.append(0);
        data_p3.append(0);
        data_p4.append(0);
    }
    //创建曲线图
    chart_p = new QChart();
    series_p1 = new QLineSeries();
    series_p2 = new QLineSeries();
    series_p3 = new QLineSeries();
    series_p4 = new QLineSeries();
    areaSeries_p1 = new QAreaSeries(series_p1);
    areaSeries_p1->setName("");
    areaSeries_p1->setBrush(QBrush(QColor(51, 240, 242, 100)));
    areaSeries_p1->setPen(QPen(QColor(51, 240, 242, 255)));

    chart_p->addSeries(areaSeries_p1);
    // X 轴 (时间点)
    axisX_p = new QValueAxis();
    axisX_p->setRange(0, maxPointsP);
    axisX_p->setLabelFormat("%d");
    axisX_p->setTitleText("");
    axisX_p->setTickCount(20); // 增加主刻度数量
    chart_p->addAxis(axisX_p, Qt::AlignBottom);
    areaSeries_p1->attachAxis(axisX_p);
    axisX_p->setLabelsVisible(false); // 隐藏 X 轴上的刻度值
    // Y 轴 (CPU 使用率)
    axisY_p = new QValueAxis();
    axisY_p->setRange(0, 200);
    axisY_p->setLabelFormat("%d%%");
    axisY_p->setTitleText("");
    chart_p->addAxis(axisY_p, Qt::AlignLeft);
    areaSeries_p1->attachAxis(axisY_p);
    axisY_p->setLabelsVisible(false); // 隐藏 X 轴上的刻度值

    // 设置网格线颜色
    QPen gridPen(QColor(255, 255, 255, 50));  // 设为红色
    gridPen.setWidth(0);    // 设为1像素宽
    axisX_p->setGridLinePen(gridPen);
    axisY_p->setGridLinePen(gridPen);

    //设置背景区域圆角角度
    chart_p->setBackgroundRoundness(0);
    //设置内边界边距
    chart_p->setMargins(QMargins(0, 0, 0, 0));
    //设置外边界边距
    chart_p->layout()->setContentsMargins(0, 0, 0, 0);
    chart_p->legend()->setAlignment(Qt::AlignBottom);
    chart_p->legend()->setVisible(true);
    chart_p->legend()->hide();
    chart_p->removeAxis(axisX_p);
    chart_p->removeAxis(axisY_p);


    axisX_p->setLineVisible(false);
    axisX_p->setLabelsVisible(false);
    axisX_p->setGridLineVisible(false);

    axisY_p->setLineVisible(false);
    axisY_p->setLabelsVisible(false);
    axisY_p->setGridLineVisible(false);
    // 设置图表背景颜色为透明
    chart_p->setBackgroundVisible(false);
    // 设定 Chart 视图
    chartView_p = new QChartView(chart_p);
    chartView_p->setRenderHint(QPainter::Antialiasing);
    chartView_p->setStyleSheet("background: transparent;");
    ui->widget_chart4->layout()->addWidget(chartView_p);
}

void thriftwidget::updateChartP(int value1, int value2) {
    data_p1.append(value1);
    
    if (data_p1.size() > maxPointsP)
    data_p1.remove(0);

    // 更新曲线数据 1秒2个    1分钟120个  5分钟600个
    series_p1 ->clear();
    for (int i = 0; i < data_p1.size(); ++i) {
        series_p1->append(i, data_p1[i]);
    }
    //qDebug() << "value1 = " << data_p1;
    //qDebug() << "value2 = " << series_io;

    axisX_p->setRange(0, data_p1.size());
}

ItemWidget* thriftwidget::createAndGetNode(thriftwidget * p, QTreeWidget *parent)
{
    //qDebug() << "createAndGetNode 创建2";
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
    //qDebug() << "createAndGetNode 创建3";
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
    isCreateNode = true;
    isAddNode = true;
    ItemWidget * item_ = dynamic_cast<ItemWidget*>(item);
    int count = item_->childCount();
    ItemWidget* items = createAndGetNode(this, item_);
    items->setExpanded(true);
    //复制成员，这里先只考虑struct
    //获取item_的struct类型
    QString struct_type = dynamic_cast<ItemWidget*>(item_->child(0))->lineEditParamValue->text();
    //判断一下集合类型是set，list，map
    //qDebug() << "上层类型：" << dynamic_cast<ItemWidget*>(item_)->comboBoxBase->currentText();
    //qDebug()<< "sn = " << QString::number(count + 1);
    items->lineEditParamSN->setText(QString::number(count + 1));
    items->lineEditParamValue->setText(struct_type);
    items->lineEditParamValue->setReadOnly(true);
    items->comboBoxBase->setCurrentIndex(dynamic_cast<ItemWidget*>(item_->child(0))->comboBoxBase->currentIndex());
    items->checkBox->setChecked(true);
    //qDebug() << "struct type = " << struct_type;
    QString struct_type2 = item_->lineEditParamValue->text();
    //qDebug() << "struct type2 = " << struct_type2;
    if (dynamic_cast<ItemWidget*>(item_)->comboBoxBase->currentText() == "set") {
        qDebug() << "set类型";
        items->keyLabel->hide();
        items->valueLabel->hide();
        items->classLabel->show();
        items->lineEditParamValue->setPlaceholderText("value");
    } else if (dynamic_cast<ItemWidget*>(item_)->comboBoxBase->currentText() == "list") {
        qDebug() << "list类型";
        items->keyLabel->hide();
        items->valueLabel->hide();
        items->classLabel->show();
        items->lineEditParamValue->setPlaceholderText("value");
    } else if (dynamic_cast<ItemWidget*>(item_)->comboBoxBase->currentText() == "map") {
        qDebug() << "map类型";
        items->keyLabel->show();
        items->valueLabel->hide();
        items->classLabel->hide();
        items->lineEditParamValue->setPlaceholderText("key");
    }
    if (struct_type2 == "") {
        items->copyItem(this, items, dynamic_cast<ItemWidget*>(item_->child(0)));
    } else {
        int index_ = struct_type2.lastIndexOf(".");
        if (index_ != -1) {
            struct_type2 = struct_type2.mid(index_ + 1);
        }
        if (structParamMap.value(struct_type2).size() > 0) {
            QMap<int, structInfo> temp = structParamMap.value(struct_type2);
            for (const auto &key : temp.keys()) {
                ItemWidget* item_1 = thriftwidget::createAndGetNode(this, items);
                item_1->setParamValue(this, key,
                    temp[key].paramName,
                    temp[key].paramType,
                    temp[key].typeSign);
            }
        }
    }

    ItemWidget* items2 = new ItemWidget(item_);
    delete items2;
    qDebug() << "items->valueLabel hide = " << items->valueLabel->isHidden();
    qDebug() << "items->classLabel hide = " << items->classLabel->isHidden();
//    items->keyLabel->hide();
//    items->valueLabel->hide();
//    items->classLabel->show();
    qDebug() << "items->valueLabel hide = " << items->valueLabel->isHidden();
    qDebug() << "items->classLabel hide = " << items->classLabel->isHidden();

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
            //qDebug() << "找到上层";
            count = parentItem->childCount() - 1;
            index = parentItem->indexOfChild(item_);
            isChild = true;
        }
    }
    //qDebug() << "rece_TextChanged = " << isCreateNode;
    if (!isCreateNode && !isChild && index >= count) {
        //顶层
        ItemWidget* items = createAndGetNode(this, ui->treeWidget);
        int index = ui->treeWidget->indexOfTopLevelItem(items);
        qDebug()<< "sn4 = " << QString::number(index + 1);
        items->lineEditParamSN->setText(QString::number(index + 1));
        //刷新用
        ItemWidget* items2 = new ItemWidget(ui->treeWidget);
        delete items2;
    } else if (!isCreateNode && isChild && index >= count) {
        //子节点
        ItemWidget* items = createAndGetNode(this, parentItem);
        int index = parentItem->indexOfChild(items);
        qDebug()<< "sn5 = " << QString::number(index + 1);
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
        item_->lineEditParamValue->setPlaceholderText("value");
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
            qDebug() << "进入创建子节点";
            item2->comboBoxBase->setCurrentText("struct");
            item2->keyLabel->show();
            item2->valueLabel->hide();
            item2->classLabel->hide();

            item2->lineEditParamValue->setPlaceholderText("key");
            item2->lineEditParamValue->setReadOnly(false);
        }

    } else if (item_->comboBoxBase->currentText() == "set" || item_->comboBoxBase->currentText() == "list") {
        item_->lineEditParamValue->setReadOnly(false);
        item_->lineEditParamValue->setPlaceholderText("value");
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
        qDebug()<< "sn6 = " << QString::number(index + 1);
        item2->lineEditParamSN->setText(QString::number(index + 1));

        item2->setText(0, "");
        item_->setExpanded(true);

        //向下创建同级节点 有问题，不一定是顶节点
        ItemWidget* items = createAndGetNode(this, ui->treeWidget);
        //设置序号
        int index2 = ui->treeWidget->indexOfTopLevelItem(items);
        qDebug()<< "sn7 = " << QString::number(index2 + 1);
        items->lineEditParamSN->setText(QString::number(index2 + 1));

        ItemWidget* items2 = new ItemWidget(ui->treeWidget);
        delete items2;
        item_->lineEditParamValue->setReadOnly(true);
        item_->lineEditParamValue->setPlaceholderText("");

    } else {
        item_->lineEditParamValue->setReadOnly(false);
        item_->lineEditParamValue->setPlaceholderText("value");
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

    if (isCreateNode == true) {
        isCreateNode = false;
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
        ui->toolButton_test->setIcon(QIcon(":lib/grey.svg"));
        ui->toolButton_test->setText("测试地址(不可访问，若开启了VPN，关闭后再试)");
        clientSocket->close();
    } else {
        qDebug() << "服务器可用";
        ui->toolButton_test->setIcon(QIcon(":lib/green.svg"));
        ui->toolButton_test->setText("测试地址(可访问)");
        clientSocket->close();
    }
    return;
}

void thriftwidget::on_toolButton_show_thrift_info_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->toolButton_return->hide();
    ui->tabWidget_response->setCurrentIndex(1);
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
    QAction *copy = new QAction("复制", ui->textEdit);
    //QAction *paste = new QAction("粘贴", ui->textEdit);
    QAction *all = new QAction("选择全部", ui->textEdit);
    connect (copy,SIGNAL(triggered()),this,SLOT(rece_textEditCopy()));
    //connect (paste,SIGNAL(triggered()),this,SLOT(rece_textEditPaste()));
    menu->addAction(copy);
    menu->addSeparator();
//    menu->addAction(paste);
//    menu->addSeparator();
    menu->addAction(all);
    menu->move(cursor().pos());
    menu->show();
}

void thriftwidget::rece_textEditCopy()
{
    QString copyData = ui->textEdit->textCursor().selectedText();
    copyData.replace(QChar(0xA0), ' ');
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(copyData);
    QTextCursor cursor = ui->textEdit->textCursor();
    ui->textEdit->setTextCursor(cursor);
    ui->textEdit->setFocus();
}

void thriftwidget::rece_textEditPaste()
{
    QClipboard *clipboard = QGuiApplication::clipboard();
    const QMimeData *mimeData = clipboard->mimeData();

    if (mimeData->hasText()) {
        QString clipboardText = mimeData->text();
        QTextCursor cursor = ui->textEdit->textCursor();
        cursor.insertText(clipboardText);  // 插入剪贴板文本
    }
}

void thriftwidget::rece_textEditAll()
{

}

void thriftwidget::on_comboBox_testType_currentIndexChanged(int index)
{
    if (index == 0) {
        //基础测试
        //ui->widget_property->hide();
        ui->toolButton_request->show();
        ui->toolButton_save->show();
        ui->stackedWidget_mode->setCurrentIndex(0);
        ui->horizontalWidget_schedule->hide();
        ui->tabWidget_test->hide();
        ui->toolButton_propertyTest->hide();
        ui->stackedWidget_2->setCurrentIndex(0);
        ui->toolButton_capturePackage->hide();
        ui->toolButton_inportpcap->hide();
        ui->toolButton_save->show();
        ui->toolButton_request->show();
    } else if (index == 1) {
        //压测
        //ui->widget_property->show();
        ui->toolButton_request->hide();
        ui->toolButton_save->hide();
        ui->toolButton_propertyTest->show();
        if (ui->tabWidget_2->currentIndex() == 0) {
            ui->stackedWidget_2->setCurrentIndex(0);
        } else {
            ui->stackedWidget_2->setCurrentIndex(3);
        }
        ui->stackedWidget_mode->setCurrentIndex(1);
        ui->toolButton_capturePackage->hide();
        ui->toolButton_inportpcap->hide();
        ui->toolButton_save->hide();
        ui->toolButton_request->hide();
        ui->toolButton_propertyTest->hide();
    } else if (index == 2) {
        //抓包分析
        //ui->widget_property->show();
        ui->toolButton_request->hide();
        ui->toolButton_save->hide();
        ui->toolButton_propertyTest->show();
        ui->stackedWidget_mode->setCurrentIndex(1);
        ui->stackedWidget_2->setCurrentIndex(2);
        ui->toolButton_capturePackage->show();
        ui->toolButton_inportpcap->show();
        ui->toolButton_save->hide();
        ui->toolButton_request->hide();
        ui->toolButton_propertyTest->hide();
        ui->stackedWidget_mode->setCurrentIndex(0);
    }
}

void thriftwidget::on_toolButton_request_clicked()
{
    ui->label_req->hide();
    ui->label_req->setText("EXCEPTION");
    ui->label_req->setStyleSheet("color: rgb(255, 255, 255);background-color: rgb(181, 11, 11);padding-left:5px;padding-right:5px;");
    elapsedMillisecondsAll = 0;
    isTestModle = false;
    assembleTBinaryMessage();

    QVector<uint8_t> sendData8 = string2Uint8List(dataList);
    //qDebug() << "数据=" << sendData;
    ui->textEdit->clear();
    ui->textEdit_data->clear();
    ui->textEdit->append("请求源数据：");

    qDebug() << "请求源数据：" << dataList;

    QString dataTemp = "";
    int sum = 0;
    QVector<QString> dataListTemp = dataList;
    if (ui->comboBox_transport->currentText() == THTTPSTransport_) {
        dataTemp = dataTemp.mid(8);
        dataListTemp.remove(0);
    }
    for (const QString& value : dataListTemp) {
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
    //qDebug() << "dataList = " << dataList;
    //qDebug() << "sendData = " << sendData;
    QElapsedTimer * timer  = new QElapsedTimer();
    //timer->start();
    retractNum = 0;

    ui->label_time->setText("");

    //判断传输协议
    if (ui->comboBox_transport->currentText() == TFramedTransport_) {
        sendThriftRequest(sendData8, timer);
    } else if (ui->comboBox_transport->currentText() == THTTPSTransport_) {
        sendHttpRequest(sendData8, timer);
    }
    
    //qint64 elapsedMilliseconds = timer->elapsed();
    //ui->label_time->setText("响应时间：" + QString::number(elapsedMilliseconds) + "ms");
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
    //定义右键弹出菜单
    QMenu *menu = new QMenu(ui->textEdit);
    menu->setWindowFlags(menu->windowFlags()  | Qt::FramelessWindowHint | Qt::NoDropShadowWindowHint);
    menu->setAttribute(Qt::WA_TranslucentBackground);
    QAction *copy = new QAction("复制", ui->textEdit_data);
    //QAction *paste = new QAction("粘贴", ui->textEdit_data);
    QAction *all = new QAction("选择全部", ui->textEdit_data);
    connect (copy,SIGNAL(triggered()),this,SLOT(rece_textEdit_dataCopy()));
    //connect (pnew1,SIGNAL(triggered()),this,SLOT(rece_mkdirFolder_sgin()));
    menu->addAction(copy);
    menu->addSeparator();
//    menu->addAction(paste);
//    menu->addSeparator();
    menu->addAction(all);
    menu->move(cursor().pos());
    menu->show();
}

void thriftwidget::rece_textEdit_dataCopy()
{
    QString copyData = ui->textEdit_data->textCursor().selectedText();
    copyData.replace(QChar(0xA0), ' ');
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(copyData);
    QTextCursor cursor = ui->textEdit_data->textCursor();
    ui->textEdit_data->setTextCursor(cursor);
    ui->textEdit_data->setFocus();
}

void thriftwidget::rece_textEdit_dataPaste()
{

}

void thriftwidget::rece_textEdit_dataAll()
{

}

void thriftwidget::on_toolButton_inportFile_clicked()
{
    //解析thrift文件
    // 创建文件对话框
    QFileDialog dialog;

    // 设置文件过滤器
    dialog.setNameFilter("Thrift Files (*.thrift)");

    // 设置只能选择文件
    dialog.setFileMode(QFileDialog::ExistingFiles);

    dialog.setDirectory("E:/ProjectA/doc");
    // 打开文件对话框
    if (dialog.exec()) {
        // 获取所选文件的路径
        QStringList fileList = dialog.selectedFiles();
        //解析
        handleThriftFile(fileList);
    }
    ui->treeWidget_api->show();
}

void thriftwidget::on_treeWidget_api_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous)
{
    //获取接口服务名，尝试匹配端口
    if (!current->parent()) {
        return;
    }
    QTreeWidgetItem * parent = current->parent();
    QString port_ = parent->text(0);
    int index_port = port_.indexOf("Service");
    port_ = port_.mid(0, index_port);
    //尝试匹配
    port_ = port_.toLower();
    int itemCount = ui->comboBox_port->count();
    for(int i =0; i < itemCount; i++) {
       QString com_port = ui->comboBox_port->itemText(i).toLower();
       //qDebug() << " com_port = " << com_port << " port_ = " << port_;
       if (com_port.contains(port_)) {
           ui->comboBox_port->setCurrentIndex(i);
           break;
       }
    }
    int index = current->text(0).indexOf(":");
    if (index == 0) {
        index = current->text(0).length();
    }
    QString funcName2 = current->text(0).mid(0, index - 1);
    qDebug() << "funcName2 = " << funcName2;
    ui->lineEdit_funcName->setText(funcName2);
    ui->treeWidget->clear();
    //循环获取参数
    if (funcParamInMap.value(funcName2).size() > 0) {
        QMap<int, paramInfo> temp = funcParamInMap.value(funcName2);
        for (const auto &key : temp.keys()) {
            ItemWidget* items = createAndGetNode(this, ui->treeWidget);
            items->setParamValue(this, key,
                        temp[key].paramName,
                        temp[key].paramType,
                        temp[key].typeSign);
        }
    }
    //setSupportStretch(this, true);
}

void thriftwidget::on_plainTextEdit_edit_customContextMenuRequested(const QPoint &pos)
{
    //定义右键弹出菜单
    QMenu *menu = new QMenu(ui->textEdit);
    menu->setWindowFlags(menu->windowFlags()  | Qt::FramelessWindowHint | Qt::NoDropShadowWindowHint);
    menu->setAttribute(Qt::WA_TranslucentBackground);
    QAction *copy = new QAction("复制", ui->plainTextEdit_edit);
    QAction *paste = new QAction("粘贴", ui->plainTextEdit_edit);
    QAction *all = new QAction("选择全部", ui->plainTextEdit_edit);
    connect (copy,SIGNAL(triggered()),this,SLOT(rece_plainTextEdit_editCopy()));
    connect (paste,SIGNAL(triggered()),this,SLOT(rece_plainTextEdit_editPaste()));
    menu->addAction(copy);
    menu->addSeparator();
    menu->addAction(paste);
    menu->addSeparator();
    menu->addAction(all);
    menu->move(cursor().pos());
    menu->show();
}

void thriftwidget::rece_plainTextEdit_editCopy()
{
    QString copyData = ui->plainTextEdit_edit->textCursor().selectedText();
    copyData.replace(QChar(0xA0), ' ');
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(copyData);
    QTextCursor cursor = ui->plainTextEdit_edit->textCursor();
    ui->plainTextEdit_edit->setTextCursor(cursor);
    ui->plainTextEdit_edit->setFocus();
}

void thriftwidget::rece_plainTextEdit_editPaste()
{
    QClipboard *clipboard = QGuiApplication::clipboard();
    const QMimeData *mimeData = clipboard->mimeData();

    if (mimeData->hasText()) {
        QString clipboardText = mimeData->text();
        QTextCursor cursor = ui->plainTextEdit_edit->textCursor();
        cursor.insertText(clipboardText);  // 插入剪贴板文本
    }
}

void thriftwidget::rece_plainTextEdit_editAll()
{

}

void thriftwidget::on_toolButton_doc_switch_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
    ui->toolButton_returnTest->show();
    // if (ui->toolButton_doc_switch->text() == "切换到报告") {
    //     //切换到报告
    //     ui->toolButton_doc_switch->setText("切换到参数");
    //     ui->stackedWidget_2->setCurrentIndex(1);
    // } else {
    //     //切换到参数
    //     ui->toolButton_doc_switch->setText("切换到报告");
    //     ui->stackedWidget_2->setCurrentIndex(0);
    // }
}


void thriftwidget::rece_activated(const QString &text)
{
    int index = text.indexOf("Service.");
    QString funcName2 = text.mid(index + 8);
    qDebug() << "选中接口 " << funcName2;
    qDebug() << "选中服务 " << text.mid(0, index + 7);

    //设置接口选中
    int topLevelItemCount = ui->treeWidget_api->topLevelItemCount();
    for (int i = 0; i < topLevelItemCount; ++i) {
        QTreeWidgetItem *parentItem = ui->treeWidget_api->topLevelItem(i);
        //qDebug() << "parentItem = " << parentItem->text(0);
        if (parentItem->text(0) == text.mid(0, index + 7)) {
            int childCount = parentItem->childCount();
            for (int j = 0; j < childCount; ++j) {
                QTreeWidgetItem *childItem = parentItem->child(j);
                //qDebug() << "childItem = " << childItem->text(0);
                if (childItem->text(0) == funcName2) {
                    ui->treeWidget_api->setCurrentItem(childItem);
                    ui->treeWidget_api->expandItem(parentItem);
                    //qDebug() << "找到";
                    //on_treeWidget_api_currentItemChanged(childItem, nullptr);
                    return;
                }
            }
        }
    }
}

void thriftwidget::rece_highlighted(const QString &text)
{
    //选择
    qDebug() << "rece_highlighted = " << text;
}


void TestRunnable::batchSendThriftRequest(QTcpSocket * clientSocket, QVector<uint8_t> dataArray, RequestResults * rr, QString host, int port, int connectTimeOut, int requestTimeOut)
{
    QElapsedTimer* timer = new QElapsedTimer();
    if (clientSocket == nullptr) {
        qDebug() << "clientSocket is null";
        return;
    }
    //记录开始创建连接时间
    qint64 elapsedMillisecondsWrite = 0;
    timer->start();
    //状态改变信号
    connect(clientSocket,&QTcpSocket::stateChanged,[=]{
        //qDebug() << "状态改变" << clientSocket->state();
        if(clientSocket->state() == QAbstractSocket::UnconnectedState) {
            //qDebug() << "连接状态2" << clientSocket->state() << "  thread ID:" << QThread::currentThreadId();
            clientSocket->deleteLater();
            //isok = true;
        }
    });

    // connect(clientSocket,&QTcpSocket::disconnected,[=]{
    //     //qDebug() << "断开连接";
    // });

    // connect(clientSocket,&QTcpSocket::connected,[=]{
    //     //qDebug() << "已连接";
    // });

    connect(clientSocket,QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),[=]{
        QAbstractSocket::SocketError error = clientSocket->error();
        if (error == QAbstractSocket::SocketTimeoutError || QAbstractSocket::NetworkError == error) {
            return;
        }
        //失败+1
        rr->setFailCount(1);
        //记录请求时间
        qint64 elapsedMilliseconds = timer->elapsed();
        rr->setResults(elapsedMilliseconds);
        //记录结束时间
        rr->setEndTime(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz"));
        qDebug() << "发生错误" << clientSocket->error() << "  thread ID:" << QThread::currentThreadId();
        count_ = count_ - 1;
        if (count_ == 0) {
            isok = true;
            //qDebug() << "count_ = " << count_;
        }
        clientSocket->disconnectFromHost();
        //clientSocket->deleteLater();
        return;
    });

    //qDebug() << "host = " << host << " port = " << port << " connectTimeOut = " << connectTimeOut;
    clientSocket->connectToHost(host, port);
    if (!clientSocket->waitForConnected(connectTimeOut)) {
        QAbstractSocket::SocketError error = clientSocket->error();
        if (error == QAbstractSocket::SocketTimeoutError || QAbstractSocket::NetworkError == error) {
            qDebug() << "连接超时，无法连接服务器";
            //失败+1
            rr->setFailCount(1);
            //记录请求时间
            qint64 elapsedMilliseconds = timer->elapsed();
            rr->setResults(elapsedMilliseconds);
            //记录结束时间
            rr->setEndTime(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz"));
        } else {
            qDebug() << "发生错误，无法连接到服务器" << "  thread ID:" << QThread::currentThreadId();
        }
        return ;
    }

    // 检查设备是否打开并处于可读写状态
    if (!clientSocket->isOpen()) {
        // 打开设备
        if (!clientSocket->open(QIODevice::ReadWrite)) {
            qDebug() << "无法打开设备"  << "  thread ID:" << QThread::currentThreadId();
            return;
        }
    }

    //记录连接耗时
    qint64 elapsedMillisecondsConnect = timer->elapsed();
    rr->setConnectTime(elapsedMillisecondsConnect);
    //qDebug() << "连接准备完成时间：" << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz") << " 耗时：" << QString::number(timer->elapsed())<< "  thread ID:" << QThread::currentThreadId();

    //服务器响应
    connect(clientSocket,&QTcpSocket::readyRead,[=]{
        //记录等待时间
        qint64 elapsedMillisecondsWait = timer->elapsed();
        rr->setWaitTimeList(elapsedMillisecondsWait - elapsedMillisecondsWrite);

        //qDebug() << "接收数据开始：" << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz") << " 耗时：" << QString::number(timer->elapsed())<< "  thread ID:" << QThread::currentThreadId();
        if (clientSocket->state() != QAbstractSocket::ConnectedState) {
            qDebug() << "连接异常" << clientSocket->state();
            return;
        }
        int64_t needRead_ = clientSocket->bytesAvailable();
        //qDebug() << "=====缓冲区还剩数据 = " << needRead_ << "  thread ID:" << QThread::currentThreadId();
        //qDebug() << "地址 = " << clientSocket << " & = " << &clientSocket;
        QVector<uint32_t> receivedDataArray(needRead_/4 + 1);
        qint64 bytesReceived = clientSocket->read(reinterpret_cast<char*>(receivedDataArray.data()), receivedDataArray.size() * sizeof(uint32_t));
        //记录数据量
        rr->setTotalData(bytesReceived);
        int64_t readNum = clientSocket->bytesAvailable();
        //qDebug() << "本次读取剩数据 = " << readNum << "  thread ID:" << QThread::currentThreadId();

        int sum2 = 0;
        int surplus = (needRead_ - readNum) % 4;
        for (const auto& elem : receivedDataArray) {
            //不会有这种情况
            if (sum2++ == (needRead_ - readNum) / 4 && surplus != 0) {
                receivedData.push_back(elem);
                break;
            }
            receivedData.push_back(elem);
        }

    if (isFirstRead) {
        isFirstRead = false;
        //获取数据长度
        uint32_t data = qFromBigEndian(receivedDataArray[0]);
        std::stringstream stream;
        //每次读取一个字节
        stream << std::hex << std::setw(8) << std::setfill('0') << data;
        QString data_ = QString::fromStdString(stream.str());
        int countLength = 4 + strtol(data_.toStdString().c_str(), nullptr, 16);
        needRead = countLength;
        needRead = needRead - (needRead_ - readNum);
        if (needRead == 0) {
                if(clientSocket) {
                    //qDebug() << "连接状态" << clientSocket->state();
                    clientSocket->disconnectFromHost();
                }
                isFirstRead = true;
                needRead = 0;
                receivedData.clear();
                qint64 elapsedMilliseconds = timer->elapsed();
                elapsedMillisecondsAll = elapsedMillisecondsAll + elapsedMilliseconds;
                //qDebug() << "调用完毕, 响应时间：" << QString::number(elapsedMilliseconds) << "ms" << ", 当前时间：" << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
                //记录请求时间
                rr->setResults(elapsedMilliseconds - elapsedMillisecondsConnect);
                //记录结束时间
                rr->setEndTime(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz"));
                count_ = count_ - 1;
                //qDebug() << "数据接收完毕：" << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz") << " 耗时：" << QString::number(timer->elapsed())<< "  thread ID:" << QThread::currentThreadId();
                if (count_ == 0) {
                    isok = true;
                    //qDebug() << "count_ = " << count_;
                }
                rr->setSuccessCount(1);
                rr->setReadTimeList(elapsedMilliseconds - elapsedMillisecondsWait);
                return;
        }
    } else {
        needRead = needRead - (needRead_ - readNum);
        if (needRead == 0) {
                //结束本次读取
                isFirstRead = true;
                needRead = 0;
                receivedData.clear();
                if(clientSocket) {
                    qDebug() << "连接状态" << clientSocket->state();
                    clientSocket->disconnectFromHost();
                }
                qint64 elapsedMilliseconds = timer->elapsed();
                elapsedMillisecondsAll = elapsedMillisecondsAll + elapsedMilliseconds;
                //qDebug() << "调用完毕, 响应时间：" << QString::number(elapsedMilliseconds) << "ms" << ", 当前时间：" << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
                //记录请求时间
                rr->setResults(elapsedMilliseconds - elapsedMillisecondsConnect);
                //记录结束时间
                rr->setEndTime(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz"));
                count_ = count_ - 1;
                //qDebug() << "数据接收完毕：" << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz") << " 耗时：" << QString::number(timer->elapsed())<< "  thread ID:" << QThread::currentThreadId();
                if (count_ == 0) {
                    isok = true;
                    //qDebug() << "count_ = " << count_;
                }
                rr->setSuccessCount(1);
                //记录读取时间
                rr->setReadTimeList(elapsedMilliseconds - elapsedMillisecondsWait);
                return;
        }
    }
        return;
    });


    // for (uint8_t& data : dataArray) {
    //     data = qToBigEndian(data);
    // }
    //记录开始写入时间
    //rr->setRequestTime(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz"));

    qint64 bytesSent = clientSocket->write(reinterpret_cast<char*>(dataArray.data()), dataArray.size() * sizeof(uint8_t));
    if (bytesSent != dataArray.size() * sizeof(uint8_t)) {
        qDebug() << "发送数据异常";
        return;
    }
    clientSocket->flush(); 

    //记录写入耗时
    elapsedMillisecondsWrite = timer->elapsed();
    //qDebug() << " 1= " << elapsedMillisecondsWrite << " 2 = " << elapsedMillisecondsConnect;
    rr->setWriteTimList(elapsedMillisecondsWrite - elapsedMillisecondsConnect);

    //qDebug() << "数据写完时间：" << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz") << " 耗时：" << QString::number(timer->elapsed())<< "  thread ID:" << QThread::currentThreadId();
    //qDebug() << "100次调用完毕：" << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz") << " 耗时：" << QString::number(timer->elapsed())<< "  thread ID:" << QThread::currentThreadId();
}

void thriftwidget::on_toolButton_propertyTest_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);


    ui->label_startTime->setText("开始时间：");
    ui->label_endTime->setText("结束时间：");
    ui->label_totalRequests_2->setText("总请求：");
    ui->label_totalTime_2->setText("总耗时：");
    ui->label_averageRespond_2->setText("平均响应时间：");
    ui->label_networkDelay_2->setText("平均连接耗时：");
    ui->label_requestsPerSecond_2->setText("每秒请求数：");
    ui->label_allData_2->setText("总接收数据：");
    ui->label_fail_2->setText("失败数：");
    ui->label_errorRate_2->setText("错误率：");

    ui->horizontalWidget_schedule->show();
    ui->widget_6->hide();
    ui->tabWidget_test->hide();
    threadpool.setMaxThreadCount(ui->lineEdit_thread->text().toInt());
    isTestModle = true;
    ui->textEdit->clear();
    ui->textEdit_data->clear();
    int64_t loopNum = ui->lineEdit_times->text().toLongLong();
    count = loopNum;
    retractNum = 0;
    elapsedMillisecondsAll = 0;
    RequestResults * rr = new RequestResults();
    rr->setCount(count);

//    if (ui->checkBox->isChecked()) {
//        rr->isN = true;
//    } else {
//        rr->isN = false;
//    }
    QElapsedTimer timer2;
    timer2.start();

    QString port_str = ui->comboBox_port->currentText();
    int index_s = port_str.indexOf("(");
    int index_e = port_str.indexOf(")");
    int port = port_str.mid(index_s + 1, index_e - index_s - 1).toInt();
    if (index_s == -1 && index_e == -1) {
        port = port_str.toInt();
    }
    int connectTimeOut =  ui->lineEdit_connectTimeOut->text().toInt();
    int requestTimeOut =  ui->lineEdit_requestTimeOut->text().toInt();
    ui->plainTextEdit_testData->clear();
    QVector<QVector<uint8_t>> sendData8S;
    //QElapsedTimer * timer;
    TestRunnable * m_pRunnable;

    double divisor = 0.1f;
    int runThreadNum = ui->lineEdit_thread->text().toInt();

    //准备压测数据
    QVector<int> threadTasks = distributeRequests(loopNum, runThreadNum);
    //准备压测数据
    for (int i = 0; i < loopNum; i++) {
        //ui->plainTextEdit_testData->appendPlainText("");
        //ui->plainTextEdit_testData->appendPlainText("==========================第" + QString::number(i+1) + "次请求入参==========================");
        assembleTBinaryMessage(1, i);
        //转换大小字节序
        QVector<uint8_t> dataListTemp = string2Uint8List(dataList);
        for (uint8_t& data : dataListTemp) {
            data = qToBigEndian(data);
        }
        //所有请求的数据
        sendData8S.push_back(dataListTemp);
    }

    //记录开始调用使用
    if (rr->startTime == "") {
        rr->setStartTime(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz"));
        qDebug() << "开始时间：" << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
    }

    for (int i = 0; i < runThreadNum; i++) {
        m_pRunnable = new TestRunnable(this, sendData8S, rr, ui->lineEdit_host->text(), port, connectTimeOut, requestTimeOut, threadTasks.at(i));
        threadpool.start(m_pRunnable);
    }
}

void thriftwidget::rece_propertyTestDone(RequestResults * rr)
{
    //ui->label_schedule->setText("执行进度：0%");
    ui->progressBar->setValue(0);
    qDebug() << "开始时间：" <<rr->startTime;
    qDebug() << "结束时间：" <<rr->endTime;
    qDebug() << "失败数：" <<rr->failCount;
    qDebug() << "成功数：" <<rr->totalTimes - rr->failCount;
    qDebug() << "请求数：" <<rr->Results.size();
    qDebug() << "连接数：" <<rr->connectTime.size();

    //qDebug() << "错误率："

    ui->lineEdit_totalRequests->setText(QString::number(rr->totalTimes)); //总执行次数
    QDateTime startTime = QDateTime::fromString(rr->startTime, "yyyy-MM-dd hh:mm:ss.zzz");
    QDateTime endTime = QDateTime::fromString(rr->endTime, "yyyy-MM-dd hh:mm:ss.zzz");
    // 计算两个时间点之间的毫秒差
    QString cpus = ui->lineEdit_thread->text();
    int32_t sum2 = std::accumulate(rr->connectTime.begin(), rr->connectTime.end(), 0);
    qint64 millisecondsDiff = startTime.msecsTo(endTime);
    double secondsDiff = millisecondsDiff / 1000.0;
    QString formattedSeconds = QString::number(secondsDiff, 'f', 3);
    ui->lineEdit_totalTime->setText(formattedSeconds);
    int32_t maxValue = *std::max_element(rr->Results.begin(), rr->Results.end());
    ui->lineEdit_maxRespond->setText(QString::number(maxValue));
    int32_t minValue = *std::min_element(rr->Results.begin(), rr->Results.end());
    ui->lineEdit_minRespond->setText(QString::number(minValue));
    int32_t sum = std::accumulate(rr->Results.begin(), rr->Results.end(), 0);
    ui->lineEdit_averageRespond->setText(QString::number(sum / rr->Results.size()));
    ui->lineEdit_allData->setText(QString::number(static_cast<double>(rr->totalData) / 1024.0, 'f', 4));

    ui->lineEdit_success->setText(QString::number(rr->successCount));
    ui->lineEdit_fail->setText(QString::number(rr->failCount));

    ui->lineEdit_errorRate->setText(QString::number((static_cast<double>(rr->failCount))/rr->totalTimes*100) + "%");
    //int32_t sum2 = std::accumulate(rr->connectTime.begin(), rr->connectTime.end(), 0);
    ui->lineEdit_networkDelay->setText(QString::number(sum2 / rr->connectTime.size()));
    ui->lineEdit_requestsPerSecond->setText(QString::number(static_cast<int64_t>(rr->totalTimes /secondsDiff)));
    ui->lineEdit_requestsPerSecondData->setText(QString::number(static_cast<int64_t>(rr->totalData / secondsDiff)));
    ui->lineEdit_ms10->setText(QString::number(rr->ms10));
    ui->lineEdit_ms25->setText(QString::number(rr->ms25));
    ui->lineEdit_ms50->setText(QString::number(rr->ms50));
    ui->lineEdit_ms75->setText(QString::number(rr->ms75));
    ui->lineEdit_ms90->setText(QString::number(rr->ms90));
    ui->lineEdit_ms95->setText(QString::number(rr->ms95));


    ui->label_startTime->setText("开始时间：" + rr->startTime.mid(0, rr->startTime.length()- 4));
    ui->label_endTime->setText("结束时间：" + rr->endTime.mid(0, rr->endTime.length()- 4));
    ui->label_totalRequests_2->setText("总请求：" + QString::number(rr->totalTimes) + "次");
    ui->label_totalTime_2->setText("总耗时：" + formattedSeconds + "s");
    ui->label_averageRespond_2->setText("平均响应耗时：" + QString::number(sum / rr->Results.size()) + "ms");
    ui->label_networkDelay_2->setText("平均连接耗时：" + QString::number(sum2 / rr->connectTime.size()) + "ms");
    ui->label_requestsPerSecond_2->setText("每秒请求数：" + QString::number(static_cast<int64_t>(rr->totalTimes /secondsDiff)) + "TPS");
    ui->label_allData_2->setText("总接收数据：" + QString::number(static_cast<int64_t>(rr->totalData / secondsDiff))  + "k");
    ui->label_fail_2->setText("失败数：" + QString::number(rr->failCount) + "次");
    ui->label_errorRate_2->setText("错误率：" + QString::number((static_cast<double>(rr->failCount))/rr->totalTimes*100) + "%");

    int32_t sumwriteTimeList = std::accumulate(rr->writeTimList.begin(), rr->writeTimList.end(), 0);
    qDebug() << "rr->writeTimList = " << rr->writeTimList;
    qDebug() << "平均写入耗时 = " << sumwriteTimeList/rr->writeTimList.size() << "ms";
    ui->lineEdit_writeTime->setText(QString::number(sumwriteTimeList/rr->writeTimList.size()));
    int32_t sumreadTimeList = std::accumulate(rr->readTimeList.begin(), rr->readTimeList.end(), 0);
    qDebug() << "rr->readTimeList = " << rr->readTimeList;
    ui->lineEdit_readTime->setText(QString::number(sumreadTimeList/rr->readTimeList.size()));
    int32_t sumwaitTimeList = std::accumulate(rr->waitTimeList.begin(), rr->waitTimeList.end(), 0);
    qDebug() << "rr->waitTimeList = " << rr->waitTimeList;
    ui->lineEdit_waitTime->setText(QString::number(sumwaitTimeList/rr->waitTimeList.size()));

    while (QLayoutItem* item = ui->widget_charts->layout()->takeAt(0)) {
        if (QWidget* widget = item->widget()) {
            widget->deleteLater(); // 删除控件，并在事件循环结束时删除
        } else {
            delete item->layout(); // 递归删除子布局
        }
        delete item; // 删除布局项
    }
    // 创建一个图表对象
    QSplineSeries *lineSeries2 = new QSplineSeries(); //创建折线系列
    int bc = 1;
    if (rr->Results.size() > 0 && rr->Results.size() < 1000) {
        bc = 2;
    } else if (rr->Results.size() > 1000 && rr->Results.size() < 5000) {
        bc = 5;
    } else if (rr->Results.size() > 5000) {
        bc = 10;
    } 
    for(int64_t i=0; i< rr->Results.size(); i+=bc)
    {
        lineSeries2->append(i,rr->Results[i]);
    }
    lineSeries2->setName("平均响应时间");   //设置系列名称


    QSplineSeries *lineSeries3 = new QSplineSeries(); //创建折线系列
    for(int64_t i=0; i< rr->waitTimeList.size(); i+=bc)
    {
        lineSeries3->append(i,rr->waitTimeList[i]);
    }
    lineSeries3->setName("平均等待时间");   //设置系列名称

    QChart *chart = new QChart();
    //设置背景区域圆角角度
    chart->setBackgroundRoundness(10);
    //设置内边界边距
    chart->setMargins(QMargins(10, 10, 10, 10));
    //设置外边界边距
    chart->layout()->setContentsMargins(0, 0, 0, 0);
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->legend()->setVisible(true);
    // 将数据系列添加到图表中
    //chart->addSeries(lineSeries);
    chart->addSeries(lineSeries2);
    chart->addSeries(lineSeries3);
    //chart->legend()->hide();

    QValueAxis *axisX = new QValueAxis; //X 轴
    axisX->setRange(1, rr->totalTimes); //设置坐标轴范围
    axisX->setLabelFormat("%d"); //标签格式
    axisX->setTickCount(10); //主分隔个数
    axisX->setMinorTickCount(8);
    axisX->setTitleText("请求次数"); //标题
    axisX->setGridLineVisible(true);

    QValueAxis *axisY = new QValueAxis; //Y 轴
    axisY->setRange(0, maxValue + 20);
    axisY->setLabelFormat("%d"); //标签格式
    axisY->setTickCount(10);
    axisY->setMinorTickCount(8);
    axisY->setTitleText("时间");
    axisY->setGridLineVisible(true);

    chart->setTitle(ui->lineEdit_funcName->text() + "接口压测数据图");
    chartView = new QChartView(this);
    chartView->setChart(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->chart()->setAxisX(axisX, lineSeries2);
    chartView->chart()->setAxisY(axisY, lineSeries2);
    //chartView->resize(QSize(500,500));
    ui->widget_charts->layout()->addWidget(chartView);
    ui->tabWidget_test->show();
    ui->widget_6->show();
    delete rr;
}


void thriftwidget::rece_propertyTestSchedule(int value) {
    qDebug() << "value = " << value;
    //ui->label_schedule->setText("执行进度：" + QString::number(value)  + "%");
    ui->progressBar->setValue(value);
}

void RequestResults::setEndTime(const QString &value)
{
    mutex.lock();
    endTime = value;
    mutex.unlock();
}

void RequestResults::setResults(const int32_t value)
{
    mutex.lock();
    Results.push_back(value);
    //qDebug() << "setResults " << value << "time " << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz") << "  thread ID:" << QThread::currentThreadId();
    //成功次数
    //successCount = successCount + 1;
    mutex.unlock();
}

void RequestResults::setConnectTime(const int32_t value)
{
    mutex.lock();
    connectTime.push_back(value);
    mutex.unlock();
}

void RequestResults::setCount(int value)
{
    mutex.lock();
    count = value;
    totalTimes = value;
    mutex.unlock();
}

void RequestResults::decrease(int value)
{
    count = count - value;
    qDebug() << "完成" << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz") 
                                    << "  thread ID:" << QThread::currentThreadId() 
                                    << "  count = " << count ;
}

void RequestResults::setRequestTime(const QString &value) {
    mutex.lock();
    requestTime = value;
    mutex.unlock();
}

void RequestResults::setSectionData()
{
    double runSum = static_cast<double>(totalTimes) - count; //已经执行次数
    if (runSum > (static_cast<double>(totalTimes) * 0.10) && ms10 == -1) {
        int32_t sum = std::accumulate(Results.begin(), Results.end(), 0);
        ms10 = static_cast<double>(sum) / Results.size();
    } else if (runSum > (static_cast<double>(totalTimes) * 0.25) && ms25 == -1) {
        int32_t sum = std::accumulate(Results.begin(), Results.end(), 0);
        ms25 = static_cast<double>(sum) / Results.size();
    } else if (runSum > (static_cast<double>(totalTimes) * 0.50) && ms50 == -1) {
        int32_t sum = std::accumulate(Results.begin(), Results.end(), 0);
        ms50 = static_cast<double>(sum) / Results.size();
    } else if (runSum > (static_cast<double>(totalTimes) * 0.75) && ms75 == -1) {
        int32_t sum = std::accumulate(Results.begin(), Results.end(), 0);
        ms75 = static_cast<double>(sum) / Results.size();
    } else if (runSum > (static_cast<double>(totalTimes) * 0.90) && ms90 == -1) {
        int32_t sum = std::accumulate(Results.begin(), Results.end(), 0);
        ms90 = static_cast<double>(sum) / Results.size();
    } else if (runSum > (static_cast<double>(totalTimes) * 0.95) && ms95 == -1) {
        int32_t sum = std::accumulate(Results.begin(), Results.end(), 0);
        ms95 = static_cast<double>(sum) / Results.size();
    }
}

void RequestResults::setFailCount(int newFailCount)
{
    mutex.lock();
    failCount = failCount + newFailCount;
    mutex.unlock();
}

void RequestResults::setTotalData(qint64 newTotalData)
{
    mutex.lock();
    totalData = totalData + newTotalData;
    mutex.unlock();
}

void RequestResults::setSuccessCount(int newSuccessCount)
{
    mutex.lock();
    successCount = successCount + newSuccessCount;
    mutex.unlock();
}

void RequestResults::setWriteTimList(const int32_t value)
{
    mutex.lock();
    writeTimList.push_back(value);
    mutex.unlock();
}

void RequestResults::setReadTimeList(const int32_t value)
{
    mutex.lock();
    readTimeList.push_back(value);
    mutex.unlock();
}

void RequestResults::setWaitTimeList(const int32_t value)
{
    mutex.lock();
    waitTimeList.push_back(value);
    mutex.unlock();
}

void RequestResults::setStartTime(const QString &value)
{
    mutex.lock();
    startTime = value;
    mutex.unlock();
}

void thriftwidget::on_toolButton_return_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->toolButton_return->hide();
}


void thriftwidget::on_checkBox_show_source_clicked()
{
    if (ui->checkBox_show_source->isChecked()) {
        ui->widget_binShow->show();
    } else {
        ui->widget_binShow->hide();
    }
}


void thriftwidget::on_toolButton_export_clicked()
{
    //生成二进制数据
    assembleTBinaryMessage();
    //写入文件
    QString hexString;
    for (const QString& value : dataList) {
        hexString = hexString + value;
    }
    hexString = hexString.mid(8);
    QByteArray byteArray2 = QByteArray::fromHex(hexString.toUtf8());
    writeQByteArrayToFile(byteArray2, "thriftConfig\\binTest.bin");
}


void thriftwidget::on_toolButton_returnTest_clicked()
{
    //返回压测
    ui->stackedWidget_2->setCurrentIndex(1);
    ui->toolButton_returnTest->hide();
}


void thriftwidget::on_toolButton_preData_clicked()
{
    //预制数据管理
    preData = new prefabricatedata();
    preData->show();
}


void thriftwidget::rece_updateMouseStyle() {
    //设置为箭头
    setCursor(Qt::ArrowCursor);
}

void thriftwidget::on_toolButton_capturePackage_clicked()
{
    //抓包，调用ssh模块，查看服务器是否有连接
    db = new sshsql();
    connnectInfoStruct cInfoStruct;
    QVector<connnectInfoStruct> cInfoStructList = db->ssh_getAllSSHInfo();
    qDebug() << "sshinfo size = " << cInfoStructList.length();
    bool isFind = false;
    for (const auto& cInfo : cInfoStructList) {
        if (cInfo.host == ui->lineEdit_host->text()) {
            // 找到匹配的元素，可以在这里进行处理
            qDebug() << "找到匹配的 host: " << cInfo.host;
            // 例如，打印其他成员变量
            qDebug() << "用户名: " << cInfo.userName;
            qDebug() << "端口: " << cInfo.port;
            isFind = true;
            // 如果只需要找到一个匹配项，可以在这里 break
            cInfoStruct = cInfo;
            break;
        }

    }
    if (isFind) {
        qDebug() << "找到匹配的服务器信息";
        //连接服务器
        threadExec = new QThread();
        sshExec = new sshHandleExec();
        sshExec->moveToThread(threadExec);
        connect(sshExec, SIGNAL(send_execCommand(QString)),this,
                SLOT(rece_execCommand(QString)));
        connect(sshExec,SIGNAL(send_init(bool)),this,
                SLOT(rece_ssh_exec_init(bool)));
        threadExec->start();

        QString host = cInfoStruct.host;
        QString port = cInfoStruct.port;
        QString username = cInfoStruct.userName;
        QString password = cInfoStruct.password;

        QMetaObject::invokeMethod(sshExec,"init", Qt::QueuedConnection, Q_ARG(int, 2), Q_ARG(QString, host), Q_ARG(QString,port), 
                                Q_ARG(QString,username), Q_ARG(QString,password), Q_ARG(QString,"tcpdump --version 2>&1"));
        //确定tcpdump
        //开始抓包
        //调用ssh模块
    } else {
        //未找到
        qDebug() << "未找到匹配的服务器信息";
    }
}

void thriftwidget::rece_execCommand(QString data)
{
    qDebug() << "rece_execCommand = " << data;
    if (data.contains("tcpdump version")) {
        //进行下一步
        //获取数据
        QMetaObject::invokeMethod(sshExec,"commondExec", Q_ARG(QString,"./capture.sh &"));
    } else {

    }
}

void thriftwidget::rece_ssh_exec_init(bool isok)
{
    qDebug() << "rece_ssh_exec_init = " << isok;
    if (!isok) {
        ui->toolButton_5->setEnabled(true);
    }
    
}

// 打印数据的十六进制格式
void thriftwidget::printHex(const QByteArray &data, int number) {
    // 使用 QByteArray::toHex() 将数据转为十六进制格式，并输出
    QString hexString = QString(data.toHex());
    int count = 0;
    QString data_;
    QString data2_;
    for (int i = 0; i < hexString.length(); i += 2) {
        data_ = data_ + hexString.mid(i, 2) + " ";
        count++;
        if (count == 8) {
            data_ = data_ + "  ";
        }
        if (count > 16) {
            ui->plainTextEdit_4->appendPlainText(data_);
            count = 0;
            data2_ = data2_ + data_ + "\n";
            data_ = "";
        }
    }
    ui->plainTextEdit_4->appendPlainText(data_); // 输出每 2 个字符作为一个字节
    dumpData[number] = data2_ + data_;
}


void thriftwidget::parseSLLHeader(const QByteArray &data, int &offset) {
    if (data.size() < 16) return;
    //& 0xFF 是将 data[1] 的低 8 位保留下来。0xFF 是一个掩码，它的二进制形式是 11111111，表示只保留 data[1] 的低 8 位
    //(data[0] << 8) | (data[1] & 0xFF) 的作用是将 data[0] 和 data[1] 这两个字节合并成一个 16 位的整数。
    quint16 packetType = (data[0] << 8) | (data[1] & 0xFF);
    quint16 protocolType = (data[14] << 8) | (data[15] & 0xFF);
    offset = 16; // SLL 头部占 16 字节

    //0000   00 00 03 04 00 06 00 00 00 00 00 00 00 00 08 00


    //qDebug() << "\n--- SLL 头部 ---";
    //qDebug() << "Packet Type:" << packetType;
    //qDebug() << "Protocol Type:" << QString("0x%1").arg(protocolType, 4, 16, QChar('0'));
}

void thriftwidget::parseIPv4Header(const QByteArray &data, int &offset, quint8 &protocol, int &ipHeaderLen, TableEntry& entry) {
    if (data.size() < offset + 20) return;
    //将 data[offset] 右移 4 位，相当于丢弃低 4 位，同时让高 4 位移动到低 4 位的位置
    //data[1]      = 0b10110100       // 0xB4
    //data[1] >> 4 = 0b00001011  // 0x0B
    //通过 & 0xF，可以确保只保留 data[1] 右移后剩下的低 4 位，而高位被清零
    quint8 version = (data[offset] >> 4) & 0xF;
    ipHeaderLen = (data[offset] & 0x0F) * 4;  // IHL 指定 IP 头部长度
    protocol = data[offset + 9]; // 协议字段
    QString srcIP = QString("%1.%2.%3.%4")
                        .arg((quint8)data[offset + 12])
                        .arg((quint8)data[offset + 13])
                        .arg((quint8)data[offset + 14])
                        .arg((quint8)data[offset + 15]);
    QString dstIP = QString("%1.%2.%3.%4")
                        .arg((quint8)data[offset + 16])
                        .arg((quint8)data[offset + 17])
                        .arg((quint8)data[offset + 18])
                        .arg((quint8)data[offset + 19]);
    // 0x45  16进制   01000101              4 对应 0100

    //0000   45 00 00 34 33 16 40 00 40 06 09 ab 7f 00 00 01
    //0010   7f 00 00 02
    entry.request = srcIP;
    entry.target = dstIP;
    //qDebug() << "\n--- IPv4 头部 ---";
    //qDebug() << "Version:" << version;
    //qDebug() << "Protocol:" << protocol;
    //qDebug() << "Source IP:" << srcIP;
    //qDebug() << "Destination IP:" << dstIP;
    
    offset += ipHeaderLen; // 移动偏移量到 TCP 头部
}

QString thriftwidget::parseTCPHeader(const QByteArray &data, int &offset, int number, TableEntry &entry) {
    if (data.size() < offset + 20) return "";
    quint16 srcPort = (data[offset] << 8) | (data[offset + 1] & 0xFF);
    quint16 dstPort = (data[offset + 2] << 8) | (data[offset + 3] & 0xFF);
    quint8 tcpHeaderLen = ((data[offset + 12] >> 4) & 0xF) * 4; // TCP 头部长度

    // 获取 TCP Flags (低 6 位)
    quint8 flags = data[offset + 13] & 0x3F;


    //0000   94 10 0f bf af 84 07 e1 00 00 00 00 80 02 aa aa
    //0010   fe 29 00 00 02 04 ff d7 01 01 04 02 01 03 03 07

    entry.request = entry.request + ":" + QString::number(srcPort);
    entry.target = entry.target + ":" + QString::number(dstPort);

    //qDebug() << "\n--- TCP 头部 ---";
    //qDebug() << "Source Port:" << srcPort;
    //qDebug() << "Destination Port:" << dstPort;

    // 解析并输出各个 TCP Flag
    QString a;
    QString b;
    ((flags & 0x02) ? a = "Yes" : a = "No");
    if (a == "Yes") {
        b = b + "SYN ";
    }
    ((flags & 0x10) ? a = "Yes" : a = "No");
    if (a == "Yes") {
        b = b + "ACK ";
    }
    ((flags & 0x01) ? a = "Yes" : a = "No");
    if (a == "Yes") {
        b = b + "FIN ";
    }
    ((flags & 0x04) ? a = "Yes" : a = "No");
    if (a == "Yes") {
        b = b + "RST ";
    }
    ((flags & 0x08) ? a = "Yes" : a = "No");
    if (a == "Yes") {
        b = b + "PSH ";
    }
    ((flags & 0x20) ? a = "Yes" : a = "No");
    if (a == "Yes") {
        b = b + "URG ";
    }
    entry.flag = b;         // 标志
    entry.index = number;   // 序号


    QString line = "-------------------------";
    ui->plainTextEdit_4->appendPlainText(line + QString::number(number) + line);
    //qDebug() << "TCP Data:" << data.mid(offset + tcpHeaderLen).toHex(' ');
    printHex(data.mid(offset + tcpHeaderLen), number);
    ui->plainTextEdit_4->appendPlainText("--------------------------------------------------");
    offset += tcpHeaderLen; // 移动到 TCP 数据部分
    return b + "  " + QString::number(srcPort) + "->" + QString::number(dstPort);
}


void thriftwidget::on_toolButton_inportpcap_clicked()
{
    qDebug() <<"加载文件";
    ui->stackedWidget_2->setCurrentIndex(2);
    ui->tableWidget_func->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    ui->tableWidget_func->verticalHeader()->setHidden(true);

    // 设置选择行为为整行选中
    ui->tableWidget_func->setSelectionBehavior(QAbstractItemView::SelectRows);

    // 设置选择模式为单选
    ui->tableWidget_func->setSelectionMode(QAbstractItemView::SingleSelection);

    ui->tableWidget_func->setColumnWidth(0, 70);  
    ui->tableWidget_func->setColumnWidth(1, 250);
    ui->tableWidget_func->setColumnWidth(2, 100);
    ui->tableWidget_func->setColumnWidth(3, 200); 
    ui->tableWidget_func->setColumnWidth(4, 200); 
    //ui->tableWidget_func->resizeColumnsToContents();  // 根据内容调整列宽
    //ui->tableWidget_func->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); // 自动填充
    ui->tableWidget_func->horizontalHeader()->setStretchLastSection(true); // 让最后一列占满剩余空间


    QString filePath = "C:/Users/张旭/Desktop/fsdownload/minic-20250219-1441.pcap";  // 你的 pcap 文件
    QFile file(filePath);

    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "无法打开 pcap 文件:" << file.errorString();
        return;
    }

    qDebug() <<"加载文件2";
    PcapHeader pcapHeader;
    file.read(reinterpret_cast<char*>(&pcapHeader), sizeof(PcapHeader));

    int number = 1;
    while (!file.atEnd()) {
        PcapPacketHeader packetHeader;
        if (file.read(reinterpret_cast<char*>(&packetHeader), sizeof(PcapPacketHeader)) < sizeof(PcapPacketHeader)) break;
        QByteArray packetData = file.read(packetHeader.incl_len);

        QDateTime timestamp = QDateTime::fromSecsSinceEpoch(packetHeader.ts_sec);
        QString formattedTime = timestamp.toString("yyyy-MM-dd HH:mm:ss");
        TableEntry entry;
        int offset = 0;
        parseSLLHeader(packetData, offset);
        

        quint8 protocol;
        int ipHeaderLen;
        parseIPv4Header(packetData, offset, protocol, ipHeaderLen, entry);

        if (protocol == 6) { // TCP
            QString data_ = parseTCPHeader(packetData, offset, number++, entry);
            entry.time = formattedTime + "." + QString::number(packetHeader.ts_usec);      // 时间
            //尝试解析函数
            QString x = dumpData[number-1];
            x.replace(" ","");
            x.replace("\n","");
            entry.info = "TCP交互";  // 信息
            //获取消息长度
            QString message_len = x.mid(0, 8);
            QString headers_data_length = QString::number(strtol(message_len.toStdString().c_str(), nullptr, 16));
            //消息类型
            QString type_data = x.mid(8, 8);
            if (type_data == "80010001") {
                entry.info = "CALL";
            } else if (type_data == "80010002") {
                entry.info = "REPLY";
            } else if (type_data == "80010003") {
                entry.info = "EXCEPTION";
            } else if (type_data == "80010004") {
                entry.info = "ONEWAY";
            } else {
                entry.info = "TCP";
            }
            //方法长度名
            QString func_len = x.mid(16, 8);
            QString headers_func_length = QString::number(strtol(func_len.toStdString().c_str(), nullptr, 16));
            bool ok;
            int len = func_len.toInt(&ok, 16) * 2;
            //需要转换为长度单位
            //方法名
            QString fun_name = x.mid(24, len);
            if (entry.info != "TCP") {
                entry.info = entry.info + "  " + hexToString(nullptr,fun_name); + "  " + headers_data_length;
            }
            
        }
        tableData.append(entry);
    }

    file.close();
    qDebug() <<"tableData.size() = " << tableData.size();
    for (int i = 0; i < tableData.size(); ++i) {
        // if (tableData[i].info == "TCP") {
        //     continue;
        // }
        ui->tableWidget_func->insertRow(i);
        ui->tableWidget_func->setItem(i, 0, new QTableWidgetItem(QString::number(tableData[i].index)));
        ui->tableWidget_func->setItem(i, 1, new QTableWidgetItem(tableData[i].time));
        ui->tableWidget_func->setItem(i, 2, new QTableWidgetItem(tableData[i].flag));
        ui->tableWidget_func->setItem(i, 3, new QTableWidgetItem(tableData[i].request));
        ui->tableWidget_func->setItem(i, 4, new QTableWidgetItem(tableData[i].target));
        ui->tableWidget_func->setItem(i, 5, new QTableWidgetItem(tableData[i].info));
    }

/*
    // 读取 pcap 全局头
    PcapFileHeader fileHeader;
    if (file.read(reinterpret_cast<char*>(&fileHeader), sizeof(PcapFileHeader)) != sizeof(PcapFileHeader)) {
        qDebug() << "读取 pcap 头部失败";
        return;
    }
    qDebug() << "成功打开 pcap 文件:" << filePath;
    qDebug() << "文件标识: 0x" << QString::number(fileHeader.magic, 16);
    qDebug() << "版本: " << fileHeader.versionMajor << "." << fileHeader.versionMinor;
    qDebug() << "最大捕获长度: " << fileHeader.snapLen << " 字节";
    qDebug() << "链路类型: " << fileHeader.linkType;
    // 读取并显示数据包
    int packetCount = 0;
    while (!file.atEnd()) {
        PcapPacketHeader packetHeader;
        if (file.read(reinterpret_cast<char*>(&packetHeader), sizeof(PcapPacketHeader)) != sizeof(PcapPacketHeader)) {
            qDebug() << "读取数据包头失败";
            break;
        }

        QByteArray packetData = file.read(packetHeader.capLen);
        if (packetData.size() != static_cast<int>(packetHeader.capLen)) {
            qDebug() << "读取数据包内容失败";
            break;
        }


        QString dataPack = "数据包 " + QString::number(++packetCount) + "，时间戳: " + formattedTime
                  + "." + QString::number(packetHeader.tsUsec) + "，长度: " + QString::number(packetHeader.capLen) + " 字节";

        ui->listWidget_func->addItem(dataPack);
        ui->plainTextEdit_4->appendPlainText(dataPack);

        printHex(packetData); // 以十六进制输出数据包内容
        ui->plainTextEdit_4->appendPlainText("--------------------------------------------------------------------------------------------------");
    }
*/
    qDebug() << "文件读取完成！";
    file.close();
}

void thriftwidget::on_tableWidget_func_itemClicked(QTableWidgetItem *item)
{

}


void thriftwidget::on_tableWidget_func_itemSelectionChanged()
{
    QList<QTableWidgetItem *> selectedItems = ui->tableWidget_func->selectedItems();
    if (!selectedItems.isEmpty()) {
        int row = selectedItems.first()->row(); // 获取选中的第一行的索引
        QString firstColumnValue = ui->tableWidget_func->item(row, 0)->text(); // 获取第一列（序号）的值
        ui->textEdit_2->clear();
        ui->textEdit_3->clear();
        int number = firstColumnValue.toInt();
        //ui->textEdit_2->append(dumpData[number]);
        qDebug() << "选中行的序号:" << firstColumnValue;

        //尝试解析数据
        QString data = dumpData[number];
        data.replace(" ","");
        data.replace("\n","");
        handleHexData(ui->textEdit_2, ui->textEdit_3, data);
    }
}


void thriftwidget::on_checkBox_show_json_stateChanged(int arg1)
{
    qDebug() << "状态变化" << arg1;
}


void thriftwidget::on_checkBox_super_stateChanged(int arg1)
{
    qDebug() << "状态变化" << arg1;
}


void thriftwidget::on_tabWidget_2_currentChanged(int index)
{
    if (index == 0) {
        ui->stackedWidget_2->setCurrentIndex(0);
    } else {
        ui->stackedWidget_2->setCurrentIndex(3);
    }
    
}


void thriftwidget::on_horizontalSlider_sliderMoved(int position)
{

}


void thriftwidget::on_horizontalSlider_valueChanged(int value)
{
    ui->widget_18->valueChanged(value);
}

void thriftwidget::rece_getServerInfo(ServerInfoStruct serverInfo) {
    //qDebug() << "rece_getServerInfo";
    // ui->label_ip->setText(serverInfo.ip);
    // ui->label_load->setText(serverInfo.load);
    // ui->label_runTime->setText(serverInfo.runTime);
    // ui->label_loginCount->setText(serverInfo.loginCount);
    // ui->label_architecture->setText(serverInfo.architecture);
    // ui->label_cpuInfo->setText(serverInfo.cpuInfo);

    // ui->progressBar_mem->setFormat("%p%   " + serverInfo.memUse);
    // ui->progressBar_swap->setFormat("%p%   " + serverInfo.swapUse);
    //qDebug() << "rece_getServerInfo cpuUseRate " << serverInfo.cpuUseRate;
    //qDebug() << "rece_getServerInfo 1 " << serverInfo.memUseRate;
    //qDebug() << "rece_getServerInfo 2 " << serverInfo.memUseRate.toInt();
    ui->label_23->setText(serverInfo.memM);
    ui->label_21->setText(serverInfo.cpuInfo);
    ui->label_19->setText(serverInfo.runTime);
    ui->widget_17->valueChanged(serverInfo.cpuUseRate.toInt());
    ui->widget_18->valueChanged(serverInfo.diskUseRate.toInt());
    ui->widget_19->valueChanged(serverInfo.memUseRate.toInt());
    ui->widget_20->valueChanged(serverInfo.swapUseRate.toInt());
    ui->label_46->setText(serverInfo.load);
    updateChart1(serverInfo.cpuUseRate.toInt());
    updateChart2(serverInfo.memUseRate.toInt());
    updateChart3(serverInfo.diskUseRate.toInt());
    updateChartP(serverInfo.progress1Cpu.toInt(), serverInfo.progress2Cpu.toInt());
}

void thriftwidget::on_toolButton_5_clicked() {
    if (cInfoStruct.host != "") {
        ui->toolButton_5->setEnabled(false);
        threadExec = new QThread();
        sshExec = new sshHandleExec();
        sshExec->moveToThread(threadExec);
        connect(sshExec, SIGNAL(send_getServerInfo(ServerInfoStruct)),this,
                SLOT(rece_getServerInfo(ServerInfoStruct)));
        connect(sshExec,SIGNAL(send_init(bool)),this,
                SLOT(rece_ssh_exec_init(bool)));
        threadExec->start();
    
            QString host = cInfoStruct.host;
            QString port = cInfoStruct.port;
            QString username = cInfoStruct.userName;
            QString password = cInfoStruct.password;
            QMetaObject::invokeMethod(sshExec,"init", Qt::QueuedConnection, Q_ARG(int, 1), Q_ARG(QString, host), Q_ARG(QString,port), 
                                    Q_ARG(QString,username), Q_ARG(QString,password), Q_ARG(QString,""));
    }

}


void thriftwidget::on_toolButton_6_clicked() {
    ui->toolButton_6->setEnabled(false);
    ui->plainTextEdit_5->clear();
    connect(&process, &QProcess::readyReadStandardOutput, this, &thriftwidget::onReadyReadOutput);
    connect(&process, &QProcess::readyReadStandardError, this, &thriftwidget::onReadyReadError);
    //组装命令
    QString command = "wsl ";
    command = command + ui->lineEdit_scriptPath->text() + "/main" + " -s " + 
                    ui->lineEdit_host_2->text() + ":" + ui->lineEdit_port_2->text() + "/" + ui->lineEdit_route_2->text() +
                    " -p " + ui->lineEdit_password->text() + " -u " + ui->lineEdit_scriptPath->text() + 
                    "/account.txt" + " -n " + ui->lineEdit_loginNum->text();
    
    if (ui->comboBox_type->currentIndex() == 0) {
        //登录
        command = command + " -t 2";
    } else if (ui->comboBox_type->currentIndex() == 1) {
        //初始化验证
        command = command + " -t 1";
    } else if (ui->comboBox_type->currentIndex() == 2) {
        //单聊
        command = command + " -t 3";
    } else if (ui->comboBox_type->currentIndex() == 3) {
        //群聊
        command = command + " -t 4";
        //群聊
        if (ui->comboBox_groupNum->currentIndex() == 0) {
            //50
            command = command + " -g 50";
        } else if (ui->comboBox_groupNum->currentIndex() == 1) {
            //100
            command = command + " -g 100";
        } else if (ui->comboBox_groupNum->currentIndex() == 2) {
            //300
            command = command + " -g 300";
        } else if (ui->comboBox_groupNum->currentIndex() == 3) {
            //500
            command = command + " -g 500";
        } else if (ui->comboBox_groupNum->currentIndex() == 4) {
            //1000
            command = command + " -g 1000";
        }
    }

    if (ui->comboBox_nullRequest->currentIndex() == 0) {
        //不发送
        command = command + " -e 2";
    } else if (ui->comboBox_nullRequest->currentIndex() == 1) {
        //发送并打印推送消息
        command = command + " -e 3";
    } else if (ui->comboBox_nullRequest->currentIndex() == 2) {
        //发送但不打印推送消息
        command = command + " -e 1";
    }

    if (ui->comboBox_connectionDetection->currentIndex() == 0) {
        //检测
        command = command + " -l 1";
    } else if (ui->comboBox_connectionDetection->currentIndex() == 1) {
        //不检测
        command = command + " -l 2";
    }

    
    ui->plainTextEdit_5->appendPlainText("执行命令：" + command);
    
    //"/mnt/e/ProjectA/avalanche/buildData/main -s 172.16.8.154:10669/ap -p 7c22a66ce0de9d5202a79ed522b737e8 -t 3 -u /mnt/e/ProjectA/avalanche/buildData/account.txt  -n 50";
    process.start(command); // 运行 WSL 命令
}

void thriftwidget::onReadyReadOutput()
{
    QString output = process.readAllStandardOutput();
    output.chop(1);
    if (output == "") return;
    ui->plainTextEdit_5->appendPlainText(output);
    //qDebug() << "WSL Output:" << output;
}

void thriftwidget::onReadyReadError()
{
    QString errorOutput = process.readAllStandardError();
    errorOutput.chop(1);
    if (errorOutput == "") return;
    ui->plainTextEdit_5->appendPlainText(errorOutput);
    //qDebug() << "WSL Error:" << errorOutput;
}


void thriftwidget::on_toolButton_7_clicked()
{
    
    QProcess process;
    QString command = QString("wsl bash -c \"pgrep main\"");

    process.start(command);
    process.waitForFinished();

    QString output = process.readAllStandardOutput().trimmed(); // 读取进程 ID
    if (output.isEmpty()) {
        qDebug() << "未找到进程：" << "main";
        ui->toolButton_6->setEnabled(true);
        return;
    }

    qDebug() << "找到进程：" << "main " << ", PID:" << output;

    // 终止进程
    QStringList pids = output.split("\n"); // 可能有多个进程
    for (const QString &pid : pids) {
        QString killCommand = QString("wsl bash -c \"kill -9 %1\"").arg(pid);
        QProcess::execute(killCommand);
        qDebug() << "已杀死进程：" << pid;
    }
    ui->plainTextEdit_5->appendPlainText("关闭服务");
    //关闭服务
    ui->toolButton_6->setEnabled(true);
    return;
}


void thriftwidget::on_lineEdit_host_textChanged(const QString &arg1)
{
    QString arg = arg1;
    ui->lineEdit_host_2->setText(arg1);
}


void thriftwidget::on_comboBox_port_currentIndexChanged(const QString &arg1)
{
    QString port_str = ui->comboBox_port->currentText();
    int index_s = port_str.indexOf("(");
    int index_e = port_str.indexOf(")");
    int port = port_str.mid(index_s + 1, index_e - index_s - 1).toInt();
    if (index_s == -1 && index_e == -1) {
        port = port_str.toInt();
    }
    ui->lineEdit_port_2->setText(QString::number(port));
}


void thriftwidget::on_toolButton_8_clicked()
{
    if (sshExec != NULL) {
        delete sshExec;
        sshExec = NULL;
    }
    ui->label_23->setText("0MIB");
    ui->label_21->setText("0/0");
    ui->label_19->setText("0天");
    ui->widget_17->valueChanged(0);
    ui->widget_18->valueChanged(0);
    ui->widget_19->valueChanged(0);
    ui->widget_20->valueChanged(0);
    ui->label_46->setText("0.00, 0.00, 0.00");
    ui->toolButton_5->setEnabled(true);
}

