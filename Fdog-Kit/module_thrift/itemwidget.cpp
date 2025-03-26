#include "itemwidget.h"
#include "thriftwidget.h"
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
                image:url(:/module_thrift/images/light/check6-light.png);\
            }\
            QCheckBox::indicator::checked{\
                image:url(:/module_thrift/images/light/check5-light.png);\
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
    p->isAuto = false;
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
        if (p->baseType.contains(key)) {
            //基础类型
            comboBoxKey->setCurrentText(key);
            comboBoxKey->show();
            //qDebug() << "基础类型";
        } else {
            qDebug() << "出错";
        }

        if (p->baseType.contains(value)) {
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
        if (p->baseType.contains(type_s)) {
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
        if (p->baseType.contains(type_s)) {
            //基础类型
            comboBoxValue->setCurrentText(type_s);
            comboBoxValue->show();
            //qDebug() << "基础类型";

        } else {
            //复杂类型
            setParamValue_interior(p, type_s);
        }

    } else if (p->baseType.contains(type)) {
        //基础类型
        //qDebug() << "设置基础类型";
        comboBoxBase->setCurrentText(type);
        //匹配预制数据
        if (p->preDataMap.contains(name) && p->preDataMap[name] != "${}") {
            lineEditParamValue->setText(p->preDataMap[name]);
            if (typeSign == "optional") {
                checkBox->setChecked(true);
            }
        } else if(p->preDataMap.contains(name)) {
            //不存在呢？
            lineEditParamValue->setText(p->preDataMapV[name].at(0));
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
        p->isAuto = false;
        comboBoxBase->setCurrentText("struct");

        //qDebug() << "设置struct2";
        lineEditParamName->setText(name);
        lineEditParamValue->setText(type);
        p->isAuto = true;
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

        if (p->structParamMap.value(type).size() > 0) {
            QMap<int, structInfo> temp = p->structParamMap.value(type);
            for (const auto &key : temp.keys()) {
                ItemWidget* items = thriftwidget::createAndGetNode(p, this);
                items->setParamValue(p, key,
                    temp[key].paramName,
                    temp[key].paramType,
                    temp[key].typeSign);
            }
        }
    }
    p->isAuto = true;
}

void ItemWidget::setParamValue_interior(thriftwidget * p, QString type_s) {
    p->isAuto = false;
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
    p->isAuto = true;
    //这里还有问题，只能处理单层数据
    //遍历创建节点
    int index_ = type_s.lastIndexOf(".");
    if (index_ != -1) {
        type_s = type_s.mid(index_ + 1);
    }

    if (p->structParamMap.value(type_s).size() > 0) {
        QMap<int, structInfo> temp = p->structParamMap.value(type_s);
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
    p->isAuto = false;
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
    p->isAuto = true;

    //这里还有问题，只能处理单层数据
    //遍历创建节点
    int index_ = type_s.lastIndexOf(".");
    if (index_ != -1) {
        type_s = type_s.mid(index_ + 1);
    }

    if (p->structParamMap.value(type_s).size() > 0) {
        QMap<int, structInfo> temp = p->structParamMap.value(type_s);
        for (const auto &key : temp.keys()) {
            ItemWidget* item_1 = thriftwidget::createAndGetNode(p, items);
            item_1->setParamValue(p, key,
                temp[key].paramName,
                temp[key].paramType,
                temp[key].typeSign);
        }
    }
}
