#ifndef ITEMWIDGET_H
#define ITEMWIDGET_H

#include <QObject>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QComboBox>
#include <QLabel>
#include <QToolButton>
#include <QHBoxLayout>
#include <QWidget>
#include <QWheelEvent>
#include <QCheckBox>
#include <QListView>
#include <QLineEdit>
#include <QDebug>
#include <QAction>
#include "variable.h"

class thriftwidget;

class NoWheelQComboBox : public QComboBox { 
    public:
        using QComboBox::QComboBox; 
    protected:
        void wheelEvent(QWheelEvent* event) override { event->ignore(); }
    
        void mousePressEvent(QMouseEvent *event) override {
            // 获取下拉箭头的区域
            QRect arrowRect = view()->geometry();  // 直接获取下拉列表区域
            arrowRect.moveTopLeft(this->rect().topRight() - QPoint(arrowRect.width(), 0));
    
            if (arrowRect.contains(event->pos())) {
                // 只有点击箭头区域才会弹出
                QComboBox::mousePressEvent(event);
            } else {
                event->ignore();  // 忽略点击，不弹出菜单
            }
        }
};

class ItemWidget :public QObject, public QTreeWidgetItem {
     Q_OBJECT
 public:
     explicit ItemWidget(QTreeWidget *parent);
     explicit ItemWidget(QTreeWidgetItem *parent);
     explicit ItemWidget();
     void init();
     void init2();
     void init3();
     ~ItemWidget();
      NoWheelQComboBox* comboBoxBase;    //基础
      NoWheelQComboBox* comboBoxKey;     //key
      NoWheelQComboBox* comboBoxValue;   //value

      
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

      void setParamSN(int str);
      void setParamName(QString str);
      void setParamType(QString str);
      void setParamValue(thriftwidget * p, int sn, QString name, QString type, QString typeSign);

      //处理list set
      void setParamValue_interior(thriftwidget * p, QString type_s);
      //处理map
      void setParamValue_interior_map(thriftwidget * p, QString type_s);
signals:
      void send_buttonClicked(QTreeWidgetItem * item);
      void send_onTextChanged(QString data, QTreeWidgetItem * item);
      void send_currentIndexChanged(QString data, QTreeWidgetItem * item);
      void send_buttonClicked_add(QTreeWidgetItem * t1);
      void send_buttonClicked_add_column(QTreeWidgetItem * t1);
 };

#endif // ITEMWIDGET_H
