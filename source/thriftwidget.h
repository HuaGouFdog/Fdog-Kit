#ifndef THRIFTWIDGET_H
#define THRIFTWIDGET_H

#include <QWidget>
#include <QTreeWidgetItem>
#include <QComboBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QTreeWidget>
#include <QToolButton>
#include <QLabel>
#include <QCheckBox>
#include <QKeyEvent>
#include <QDebug>
#include <QListWidgetItem>

//请求类型
#define THRIFT_CALL        "80010001"
#define THRIFT_REPLY       "80010002"
#define THRIFT_EXCEPTION   "80010003"
#define THRIFT_ONEWAY      "80010004"

//字段类型编号两个字节
#define THRIFT_BOOL_TYPE   2
#define THRIFT_BYTE_TYPE   3
#define THRIFT_I16_TYPE    6
#define THRIFT_I32_TYPE    8
#define THRIFT_I64_TYPE    10
#define THRIFT_DOUBLE_TYPE 4
#define THRIFT_STRING_TYPE 11
#define THRIFT_STRUCT_TYPE 12
#define THRIFT_MAP_TYPE    13
#define THRIFT_SET_TYPE    14
#define THRIFT_LIST_TYPE   15

//字段类型占用长度  1字节数=2个长度
#define THRIFT_BOOL_SIZE        2
#define THRIFT_BYTE_SIZE        2
#define THRIFT_I16_SIZE         4
#define THRIFT_I32_SIZE         8
#define THRIFT_I64_SIZE         16
#define THRIFT_DOUBLE_SIZE      16
#define THRIFT_STRING_SIZE      0
#define THRIFT_STRUCT_SIZE      0
#define THRIFT_MAP_SIZE         0
#define THRIFT_SET_SIZE         0
#define THRIFT_LIST_SIZE        0

#define TFramedTransport_   "TFramedTransport"
#define TBufferedTransport_ "TFramedTransport"

#define TBinaryProtocol_ "TBinaryProtocol"

static QMap<QString, QString> mapReqType = {{"CALL", THRIFT_CALL}, {"ONEWAY", THRIFT_ONEWAY}};

static QMap<QString, QString> ExceptionType = {{"1", "Unknown Method"}};


static QMap<QString, int> mapType = {{"bool", THRIFT_BOOL_TYPE}, {"byte", THRIFT_BYTE_TYPE}, {"i16", THRIFT_I16_TYPE}, {"i32", THRIFT_I32_TYPE},
                {"i64", THRIFT_I64_TYPE}, {"double", THRIFT_DOUBLE_TYPE}, {"string", THRIFT_STRING_TYPE}, {"struct", THRIFT_STRUCT_TYPE}, 
                {"map", THRIFT_MAP_TYPE}, {"set", THRIFT_SET_TYPE}, {"list", THRIFT_LIST_TYPE}};

static QMap<QString, int> mapSize = {{"bool", THRIFT_BOOL_SIZE}, {"byte", THRIFT_BYTE_SIZE}, {"i16", THRIFT_I16_SIZE}, {"i32", THRIFT_I32_SIZE},
                {"i64", THRIFT_I64_SIZE}, {"double", THRIFT_DOUBLE_SIZE}, {"string", THRIFT_STRING_SIZE}, {"struct", THRIFT_STRUCT_SIZE}, 
                {"map", THRIFT_MAP_SIZE}, {"set", THRIFT_SET_SIZE}, {"list", THRIFT_LIST_SIZE}};

static QSet<QString> baseType = {"bool", "byte", "i16", "i32", "i64", "double", "string"};
static QSet<QString> containerType = {"map", "set", "list"};

struct paramInfo {
    QString paramType; //参数类型
    QString paramName; //参数名
    QString typeSign;   //描述符 1 opt-in, req-out 默认 1 required 2 optional  这个是必opt-in, req-out
};

struct structInfo {
    QString paramType;  //参数类型
    QString paramName;  //参数名
    QString typeSign;   //描述符 1 opt-in, req-out 默认 1 required 2 optional
};

//QMap<QString, paramInfo> paramsMap;

static QMap<QString, QMap<QString, paramInfo>> funcParamInMap;

static QMap<QString, QMap<QString, paramInfo>> funcParamOutMap;

//第一个参数是结构体名，map里面string是序号
static QMap<QString, QMap<QString, structInfo>> structParamMap;

namespace Ui {
class thriftwidget;
}

class thriftwidget;

class EnglishOnlyFilter : public QObject
{
    Q_OBJECT
protected:
    bool eventFilter(QObject *obj, QEvent *event) override
    {
        if (event->type() == QEvent::InputMethodQuery) {
            QInputMethodQueryEvent *queryEvent = static_cast<QInputMethodQueryEvent*>(event);
            if (queryEvent->queries() & Qt::ImEnabled) {
                // 如果输入法激活，表示正在进行中文输入，则忽略此事件
                return true;
            }
        } else if (event->type() == QEvent::KeyPress) {
            QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
            QString text = keyEvent->text();
            //qDebug() << "text =" << text;
            // 检查输入的文本是否为英文字符（A-Z、a-z）或数字（0-9）
            if (!text.isEmpty() && !(text >= "A" && text <= "Z") && !(text >= "a" && text <= "z")
                    && !(text >= "0" && text <= "9") && !(keyEvent->key() == Qt::Key_Backspace)
                    && !(text == "\u0001") && !(text == "\u0003") && !(text == "\u0016") && !(text == "\u001A")) {
                return true; // 忽略非英文字符和数字
            }
        } else if (event->type() == QEvent::InputMethod) {
            // 对于输入法事件，获取输入的文本
            QInputMethodEvent *inputMethodEvent = static_cast<QInputMethodEvent*>(event);
            QString text = inputMethodEvent->commitString();
            // 检查输入的文本是否为英文字符（A-Z、a-z）或数字（0-9）
            if (!text.isEmpty()) {
                bool containsNonEnglishOrDigit = false;
                for (const QChar &ch : text) {
                    if (!(ch >= 'A' && ch <= 'Z') && !(ch >= 'a' && ch <= 'z')
                            && !(ch >= '0' && ch <= '9')) {
                        containsNonEnglishOrDigit = true;
                        break;
                    }
                }
                if (containsNonEnglishOrDigit) {
                    return true; // 忽略非英文字符和数字
                }
            }
        }
        return QObject::eventFilter(obj, event);
    }
};


class ItemWidget :public QObject ,public QTreeWidgetItem
 {
     Q_OBJECT
 public:
     explicit ItemWidget(QTreeWidget *parent);
     explicit ItemWidget(QTreeWidgetItem *parent);
     explicit ItemWidget();
     void init();
     void init2();
     void init3();
     ~ItemWidget();
      QComboBox* comboBoxBase;    //基础
      QComboBox* comboBoxKey;     //key
      QComboBox* comboBoxValue;   //value

      
      QLineEdit* lineEditParamSN;       //参数序号
      QLineEdit* lineEditParamName;       //参数名
      QLineEdit* lineEditParamValue;      //参数值
      //QLineEdit* lineEditParamDescribe;   //参数描述

      QToolButton* deleteButton;          //删除按钮
      QToolButton* moveButton;            //删除按钮
      QToolButton* addNode;               //添加元素
      QToolButton* addColumnButton;       //添加列

      QLabel * keyLabel;    //key元素
      QLabel * valueLabel;  //value元素
      QLabel * classLabel;  //类元素
      QLabel * mastLabel;   //必选标记

      QHBoxLayout* layoutParamSN;
      QWidget* widgetParamSN;
      QHBoxLayout* layoutParamName;
      QWidget* widgetParamName;
      QHBoxLayout* layoutParamType;
      QWidget* widgetParamType;
      QHBoxLayout* layoutParamValue;
      QWidget* widgetParamValue;

      QLabel* label;
      QCheckBox* checkBox;

      

      void copyItem(thriftwidget * p, ItemWidget * item_p, ItemWidget * item_);

      void setParamSN(QString str);
      void setParamName(QString str);
      void setParamType(QString str);
      void setParamValue(thriftwidget * p, QString sn, QString name, QString type, QString typeSign);


signals:
      void send_buttonClicked(QTreeWidgetItem * item);
      void send_onTextChanged(QString data, QTreeWidgetItem * item);
      void send_currentIndexChanged(QString data, QTreeWidgetItem * item);
      void send_buttonClicked_add(QTreeWidgetItem * t1);
      void send_buttonClicked_add_column(QTreeWidgetItem * t1);
 };

enum ObjectType {
	OBJECT_BASE = 1,
	OBJECT_STRUCT,
	OBJECT_LIST,
	OBJECT_SET,
    OBJECT_MAP,
};

class thriftwidget : public QWidget
{
    Q_OBJECT

public:
    bool isAddNode = false;
    bool isToolButton_request_param_checked = true; //入参
    bool isToolButton_response_checked = true;      //响应
    bool isToolButton_report_checked = false;       //性能报告
    int  retractNum = 0;

    explicit thriftwidget(QWidget *parent = 0);
    void ceateItem();
    QString getType(int index);
    QString getType(QString data);
    QString getValue(QString data);
    ~thriftwidget();



    uint32_t string2Uint32(QString data);  //将四字节字符串转为需要发送的uint32
    QVector<uint32_t> string2Uint32List(QVector<QString> & data);
    void string2stringList(QString data);
    void sendThriftRequest(QVector<uint32_t> dataArray);

    //组装数据
    void buildData();

    void baseSerialize(int serialNumber, QString valueType, QString value);
    void containerSerialize(int serialNumber, QString valueType, QString value, QString keyType_, QString valyeType_ = "");
    void structSerialize(int serialNumber, QString valueType, ItemWidget * item);

    void map2List(QStringList &dataList, QString data);

    //清空消息
    void cleanMessage();

    //组装二进制协议消息
    void assembleTBinaryMessage();

    //设置二进制请求类型，接口长度，接口名，流水号
    void writeTBinaryHeadMessage(QString serialNumber = "00000000");

    //设置类型序号
    void writeTBinaryTypeAndSerialNumber(QString valueType, int serialNumber);

    //组装基础类型数据
    void writeTBinaryBaseMessage(QString valueType, QString value);

    //组装集合类型数据
    void writeTBinaryCollectionMessage(QString valueType, QString value, ItemWidget *item, QString paramKeyType, QString paramValueType);

    //组装结构体数据
    void writeTBinaryStructMessage(QString valueType, ItemWidget * item);

    //写入结束
    void writeTBinaryEndMessage();

    //数据头写入数据长度
    void writeTBinarySizeMessage();

    //写入类型
    void writeTBinaryTypeMessage(QString type_);

    //写入元素数量
    void writeTBinaryKeySize(QStringList &dataList, QString value);

    //写入元素数量2
    void writeTBinaryValueSize(QStringList &dataList, QString value);

    //写入数据
    template<class T>
    void writeTBinaryFormatData(T value, QString valueType) {
       QString fromatData = QString("%1").arg(value, mapSize.value(valueType), 16, QLatin1Char('0'));
       qDebug() << "writeTBinaryFormatData fromatData =" << fromatData;
       string2stringList(fromatData);
    }

    template<>
    void writeTBinaryFormatData(double value, QString valueType) {
        qulonglong d_long = *(qulonglong*)&value;
        QString fromatData = QString("%1").arg(d_long, mapSize.value(valueType), 16, QLatin1Char('0'));
        QString reversedString;
        while (fromatData.length()!=0) {
            reversedString = reversedString + fromatData.mid(fromatData.length()-2);
            fromatData = fromatData.mid(0, fromatData.length()-2);
        }
        string2stringList(reversedString);
    }

    template<>
    void writeTBinaryFormatData(QString value, QString valueType) {
        //注意中文占三个
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
        QString lenData = QString("%1").arg(len, mapSize.value("i32"), 16, QLatin1Char('0'));
        string2stringList(lenData);
        QString valueData = value.toUtf8().toHex();
        string2stringList(valueData);
    }

    void handleMessage(QString &data);

    //添加颜色
    QString addColorHtml(QString &str, QColor *fontCrl);

    //添加字段颜色
    QString addColorFieldHtml(QString str);

    //添加字段 数值颜色
    QString addColorValueNumHtml(QString str);
    //添加字段 字符串颜色
    QString addColorValueStrHtml(QString str);
    //添加括号颜色
    QString addColorBracketsHtml(QString str);

    QString handleBool(QString &str, QString isEnd, QString paramName = "");

    QString handleByte(QString &str, QString isEnd, QString paramName = "");

    QString handleDouble(QString &str, QString isEnd, QString paramName = "");

    QString handleI16(QString &str, QString isEnd, QString paramName = "");

    QString handleI32(QString &str, QString isEnd, QString resType = THRIFT_REPLY, QString paramName = "");

    QString handleI64(QString &str, QString isEnd, QString paramName = "");

    QString handleString(QString &str, QString isEnd, QString resType = THRIFT_REPLY, QString paramName = "");

    QString handleStruct(QString &str, QString isEnd, QString outType = "", QString outParam = "");

    QString handleMap(QString &str, QString isEnd, QString outType = "", QString paramName = "");

    QString handleSet(QString &str, QString isEnd, QString outType = "", QString paramName = "");

    QString handleList(QString &str, QString isEnd, QString outType = "", QString paramName = "");
    
    QString handleEnd(QString &str);

    QString hexToString(QString& hex);

    QString hexToLongNumber(QString& hex);

    void removeLastComma(QString &str); //移除最后的逗号

    QString getRetract(); //获取缩进

    

    //获取入参
    QMap<QString, paramInfo> getFuncInParams(QString data);

    //获取出参
    QMap<QString, paramInfo> getFuncOutParams(QString data);

    //获取结构体信息
    QMap<QString, structInfo> getStructParams(QString data);
    
    //创建节点
    static ItemWidget* createAndGetNode(thriftwidget * p);
    static ItemWidget* createAndGetNode(thriftwidget * p, QTreeWidget *parent);
    static ItemWidget* createAndGetNode(thriftwidget * p, QTreeWidgetItem *parent);

private slots:
    void on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column);
    void read_data();
    void rece_deleteItem(QTreeWidgetItem * item);
    void rece_addItem(QTreeWidgetItem * item);
    void rece_addColumn(QTreeWidgetItem * item);
    void rece_TextChanged(QString data, QTreeWidgetItem * item);
    void rece_currentIndexChanged(QString data, QTreeWidgetItem * item);

    void on_toolButton_test_clicked();

    void on_toolButton_show_thrift_info_clicked();

    void on_textEdit_customContextMenuRequested(const QPoint &pos);

    void on_comboBox_testType_currentIndexChanged(int index);

    void on_toolButton_request_clicked();

    void on_toolButton_request_param_clicked();

    void on_toolButton_response_clicked();

    void on_toolButton_report_clicked();

    void on_checkBox_show_source_stateChanged(int arg1);

    void on_textEdit_data_customContextMenuRequested(const QPoint &pos);

    void on_toolButton_inportFile_clicked();

    void on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_treeWidget_api_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous);

private:
    QVector<QString> dataList;
    QString lastValue_;
    QString last2Value_;
    Ui::thriftwidget *ui;
};

#endif // THRIFTWIDGET_H
