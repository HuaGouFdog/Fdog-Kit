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

//请求类型
#define THRIFT_CALL        0x80010001
#define THRIFT_REPLY       0x80010002
#define THRIFT_EXCEPTION   0x80010003
#define THRIFT_ONEWAY      0x80010004

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

//字段类型占用字节数
#define THRIFT_BOOL_SIZE        1
#define THRIFT_BYTE_SIZE        1
#define THRIFT_I16_SIZE         2
#define THRIFT_I32_SIZE         4
#define THRIFT_I64_SIZE         8
#define THRIFT_DOUBLE_SIZE      8
#define THRIFT_STRING_SIZE      4
#define THRIFT_STRUCT_SIZE      0
#define THRIFT_MAP_SIZE         0
#define THRIFT_SET_SIZE         0
#define THRIFT_LIST_SIZE        0

namespace Ui {
class thriftwidget;
}

 class ItemWidget :public QObject ,public QTreeWidgetItem
 {
     Q_OBJECT
 public:
     explicit ItemWidget(QTreeWidget *parent = 0);
     explicit ItemWidget(QTreeWidgetItem *parent = 0);
     void init();
     ~ItemWidget();
      QComboBox* comboBoxBase;    //基础
      QComboBox* comboBoxKey;     //key
      QComboBox* comboBoxValue;   //value

      QLineEdit* lineEditParamName;       //参数名
      QLineEdit* lineEditParamValue;      //参数值
      QLineEdit* lineEditParamDescribe;   //参数描述

      QToolButton* deleteButton;          //删除按钮
      QToolButton* moveButton;          //删除按钮

      QHBoxLayout* layoutParamName;
      QWidget* widgetParamName;
      QHBoxLayout* layoutParamType;
      QWidget* widgetParamType;
      QHBoxLayout* layoutParamDescribe;
      QWidget* widgetParamDescribe;

      QLabel* label;
      QCheckBox* checkBox;

signals:
      void send_buttonClicked(QTreeWidgetItem * item);
      void send_onTextChanged(QString data, QTreeWidgetItem * item);
 };

class thriftwidget : public QWidget
{
    Q_OBJECT

public:
    explicit thriftwidget(QWidget *parent = 0);
    void ceateItem();
    void sendData();
    QString getType(int index);
    QString getType(QString data);
    QString getValue(QString data);
    ~thriftwidget();

    uint32_t string2Uint32(QString data);  //将四字节字符串转为需要发送的uint32
    QVector<uint32_t> string2Uint32List(QVector<QString> & data);
    void string2stringList(QString data);
    void sendThriftRequest(QVector<uint32_t> dataArray);

    //QVector<ItemWidget*> ItemWidgetList;
private slots:
    void on_toolButton_clicked();
    void on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column);
    void read_data();
    void on_toolButton_2_clicked();

    void rece_deleteItem(QTreeWidgetItem * item);
    void rece_TextChanged(QString data, QTreeWidgetItem * item);
private:
    QVector<QString> dataList;
    Ui::thriftwidget *ui;
};

#endif // THRIFTWIDGET_H
