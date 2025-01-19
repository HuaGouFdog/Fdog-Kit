#pragma execution_character_set("utf-8")
#include "zookeepermanagewidget.h"
#include "ui_zookeepermanagewidget.h"
#include <QDesktopServices>
#include <QUrl>
#include <QGraphicsDropShadowEffect>
#include "module_utils/utils.h"

zookeepermanagewidget::zookeepermanagewidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::zookeepermanagewidget)
{
    ui->setupUi(this);
    setSupportStretch(this, true);
    lastIndex = 0;
    count = 0;
    m_buttonGroup = new QButtonGroup(this);
    m_buttonGroup->setExclusive(true);
    connect(m_buttonGroup, SIGNAL(buttonClicked(int)), this, SLOT(rece_buttonClicked(int)));
    QAction *action = new QAction(this);
    action->setIcon(QIcon(":/lib/soucuo.png"));

    // QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect(this);
    // effect->setOffset(2, 0);          //设置向哪个方向产生阴影效果(dx,dy)，特别地，(0,0)代表向四周发散
    // effect->setColor(QColor(25, 51, 81));       //设置阴影颜色，也可以setColor(QColor(220,220,220))
    // effect->setBlurRadius(20);        //设定阴影的模糊半径，数值越大越模糊
    // ui->widget_left->setGraphicsEffect(effect);

    //打开数据库
    db_ = new sqlhandle();
    QVector<zkInfoStruct> zkInfoList =  db_->zk_getAllZkInfo();
    for (int i = 0; i <zkInfoList.length();i++) {
        QString data = zkInfoList[i].host + ":" + zkInfoList[i].port;
        QToolButton * qbutton = new QToolButton(this);
        qbutton->setIcon(QIcon(":lib/grey.svg"));
        qbutton->setText(data);
        qbutton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        qbutton->setMinimumHeight(40);
        qbutton->setMinimumWidth(180);
        qbutton->setMaximumWidth(180);
        qbutton->setCheckable(true);
        m_buttonGroup->addButton(qbutton, count++);
        QVBoxLayout *layout = (QVBoxLayout *)ui->scrollAreaWidgetContents->layout();
        layout->insertWidget(layout->count()-1, qbutton);
        QMenu *menu = new QMenu(qbutton);
        menu->setWindowFlags(menu->windowFlags()  | Qt::FramelessWindowHint | Qt::NoDropShadowWindowHint);
        menu->setAttribute(Qt::WA_TranslucentBackground);
        QAction *againAction = new QAction(tr("重连"), qbutton);
        QAction *closeAction = new QAction(tr("关闭"), qbutton);
        QAction *clearAction = new QAction(tr("删除"), qbutton);
        
        // 将菜单与按钮关联
        //menu->addAction(againAction);
        menu->addAction(closeAction);
        menu->addAction(clearAction);
        qbutton->setContextMenuPolicy(Qt::CustomContextMenu);
        qbutton->setMenu(menu);
        QObject::connect(againAction, &QAction::triggered, this, [=](){
            qDebug("重连被点击");
            QToolButton* button_ =qobject_cast<QToolButton*>(sender()->parent());
            QStringList dataList;
            if (button_ != NULL) {
                dataList = button_->text().split(":");
                qDebug() << "text = " << dataList;
            }
        });

        QObject::connect(closeAction, &QAction::triggered, this, [=](){
            qDebug("关闭被点击");
            QToolButton* button_ =qobject_cast<QToolButton*>(sender()->parent());
            QStringList dataList;
            if (button_ != NULL) {
                dataList = button_->text().split(":");
                qDebug() << "text = " << dataList;
            }
            qDebug("关闭被点击, 删除zkWidget, 关闭zk连接");
            //删除zkWidget, 关闭zk连接
            //delete zkWidget;
            qDebug("关闭被点击, 删除zkWidget, 关闭zk连接2");
            ui->stackedWidget->setCurrentIndex(0);
            zkStatusInfoMap[qbutton].status_ = 2;
            if (zkStatusInfoMap[qbutton].zkWidget_ != nullptr) {
                delete zkStatusInfoMap[qbutton].zkWidget_;
                zkStatusInfoMap[qbutton].zkWidget_ =nullptr;
            }
            qbutton->setIcon(QIcon(":lib/grey.svg"));//灰色
        });

        QObject::connect(clearAction, &QAction::triggered, this, [=](){
            qDebug("删除被点击");
            QToolButton* button_ =qobject_cast<QToolButton*>(sender()->parent());
            QStringList dataList;
            if (button_ != NULL) {
                dataList = button_->text().split(":");
                qDebug() << "text = " << dataList;
            }

            zkInfoStruct zkInfo;
            zkInfo.host = dataList[0];
            zkInfo.port = dataList[1];
            db_->zk_deleteZkInfo(zkInfo);

            ui->stackedWidget->setCurrentIndex(0);
            zkStatusInfoMap[qbutton].status_ = 2;

            if (zkStatusInfoMap[qbutton].zkWidget_ != nullptr) {
                delete zkStatusInfoMap[qbutton].zkWidget_;
                zkStatusInfoMap[qbutton].zkWidget_ =nullptr;
            }

            m_buttonGroup->removeButton(button_);
            delete(button_);
            //showMessage("删除", true);
        });

        QObject::connect(qbutton, &QToolButton::customContextMenuRequested, this, [=]()
        {
            qDebug() << "按钮被右击";
            menu->move(cursor().pos());
            menu->show();           //记录button对应的连接和状态
            //zkStatusInfoMap[qbutton].status_ = 1;
            //zkStatusInfoMap[qbutton].zkWidget_ =zkWidget;
            qDebug() << "记录状态";
        });
    }
}

zookeepermanagewidget::zookeepermanagewidget(connnectInfoStruct &cInfoStruct, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::zookeepermanagewidget)
{
    ui->setupUi(this);
    setSupportStretch(this, true);
    lastIndex = 0;
    count = 0;
    m_buttonGroup = new QButtonGroup(this);
    m_buttonGroup->setExclusive(true);
    connect(m_buttonGroup, SIGNAL(buttonClicked(int)), this, SLOT(rece_buttonClicked(int)));
    //保存
    QString data = cInfoStruct.host + ":" + cInfoStruct.port;
    QToolButton * qbutton = new QToolButton(this);
    qbutton->setIcon(QIcon(":lib/grey.svg"));
    qbutton->setText(data);
    qbutton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    qbutton->setMinimumHeight(50);
    qbutton->setMinimumWidth(180);
    qbutton->setMaximumWidth(180);
    qbutton->setCheckable(true);
    m_buttonGroup->addButton(qbutton, count++);
    QVBoxLayout *layout = (QVBoxLayout *)ui->scrollAreaWidgetContents->layout();
    layout->insertWidget(layout->count()-1, qbutton);
    //连接
    cInfoStruct.buttonSid = count-1;
    cInfoStruct.timeout = 5000;
    qbutton->setIcon(QIcon(":lib/yellow.svg"));//黄色
    zookeeperwidget * zkWidget = new zookeeperwidget(cInfoStruct);
    connect(zkWidget, SIGNAL(send_init(int, int)), this, SLOT(rece_init(int, int)));
    ui->stackedWidget->addWidget(zkWidget);
    connectManager.insert(count-1, ui->stackedWidget->count()-1);
    ui->stackedWidget->setCurrentIndex(ui->stackedWidget->count()-1);
    m_buttonGroup->button(count-1)->setChecked(true);
    //打开数据库
    db_ = new sqlhandle();
}

void zookeepermanagewidget::newCreate(connnectInfoStruct &cInfoStruct)
{
    //保存
    QString data = cInfoStruct.host + ":" + cInfoStruct.port;
    QToolButton * qbutton = new QToolButton(this);
    qbutton->setIcon(QIcon(":lib/grey.svg"));
    qbutton->setText(data);
    qbutton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    qbutton->setMinimumHeight(50);
    qbutton->setMinimumWidth(180);
    qbutton->setMaximumWidth(180);
    qbutton->setCheckable(true);
    m_buttonGroup->addButton(qbutton, count++);
    QVBoxLayout *layout = (QVBoxLayout *)ui->scrollAreaWidgetContents->layout();
    layout->insertWidget(layout->count()-1, qbutton);
    //连接
    cInfoStruct.buttonSid = count-1;
    cInfoStruct.timeout = 5000;
    qbutton->setIcon(QIcon(":lib/yellow.svg"));//黄色
    zookeeperwidget * zkWidget = new zookeeperwidget(cInfoStruct);
    connect(zkWidget, SIGNAL(send_init(int, int)), this, SLOT(rece_init(int, int)));
    ui->stackedWidget->addWidget(zkWidget);
    connectManager.insert(count-1, ui->stackedWidget->count()-1);
    ui->stackedWidget->setCurrentIndex(ui->stackedWidget->count()-1);
    m_buttonGroup->button(count-1)->setChecked(true);

    qDebug() << "走这里";
        QMenu *menu = new QMenu(qbutton);
        QAction *againAction = new QAction(tr("重连"), qbutton);
        QAction *closeAction = new QAction(tr("关闭"), qbutton);
        QAction *clearAction = new QAction(tr("删除"), qbutton);
        
        // 将菜单与按钮关联
        //menu->addAction(againAction);
        menu->addAction(closeAction);
        menu->addAction(clearAction);
        qbutton->setContextMenuPolicy(Qt::CustomContextMenu);
        qbutton->setMenu(menu);
        QObject::connect(againAction, &QAction::triggered, this, [=](){
            qDebug("重连被点击");
            QToolButton* button_ =qobject_cast<QToolButton*>(sender()->parent());
            QStringList dataList;
            if (button_ != NULL) {
                dataList = button_->text().split(":");
                qDebug() << "text = " << dataList;
            }
        });

        QObject::connect(closeAction, &QAction::triggered, this, [=](){
            qDebug("关闭被点击");
            QToolButton* button_ =qobject_cast<QToolButton*>(sender()->parent());
            QStringList dataList;
            if (button_ != NULL) {
                dataList = button_->text().split(":");
                qDebug() << "text = " << dataList;
            }
            //关闭zk连接
        });
        QObject::connect(clearAction, &QAction::triggered, this, [=](){
            qDebug("删除被点击");
            QToolButton* button_ =qobject_cast<QToolButton*>(sender()->parent());
            QStringList dataList;
            if (button_ != NULL) {
                dataList = button_->text().split(":");
                qDebug() << "text = " << dataList;
            }

            zkInfoStruct zkInfo;
            zkInfo.host = dataList[0];
            zkInfo.port = dataList[1];
            db_->zk_deleteZkInfo(zkInfo);

            delete zkWidget;
            ui->stackedWidget->setCurrentIndex(0);
            zkStatusInfoMap[qbutton].status_ = 2;
            zkStatusInfoMap[qbutton].zkWidget_ =nullptr;

            m_buttonGroup->removeButton(button_);
            delete(button_);
            //showMessage("删除", true);
        });
       QObject::connect(qbutton, &QToolButton::customContextMenuRequested, this, [=]()
       {
           qDebug() << "按钮被右击";
           menu->move(cursor().pos());
           menu->show();           //记录button对应的连接和状态
           zkStatusInfoMap[qbutton].status_ = 1;
           zkStatusInfoMap[qbutton].zkWidget_ =zkWidget;
           qDebug() << "记录状态";
       });
}

zookeepermanagewidget::~zookeepermanagewidget()
{
    delete ui;
}

void zookeepermanagewidget::on_toolButton_newCreate_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void zookeepermanagewidget::on_toolButton_save_clicked()
{
    //保存
    QString data = ui->lineEdit_host_zk_data->text() + ":" + ui->lineEdit_port_zk_data->text();
    QToolButton * qbutton = new QToolButton(this);
    qbutton->setIcon(QIcon(":lib/grey.svg"));
    qbutton->setText(data);
    qbutton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    qbutton->setMinimumHeight(50);
    qbutton->setMinimumWidth(180);
    qbutton->setMaximumWidth(180);
    qbutton->setCheckable(true);
    m_buttonGroup->addButton(qbutton, count++);
    QVBoxLayout *layout = (QVBoxLayout *)ui->scrollAreaWidgetContents->layout();
    layout->insertWidget(layout->count()-1, qbutton);
    ui->stackedWidget->setCurrentIndex(lastIndex);
}

void zookeepermanagewidget::on_toolButton_close_clicked()
{
    //取消
    ui->stackedWidget->setCurrentIndex(0);
}

void zookeepermanagewidget::on_toolButton_connect_clicked()
{
    //保存
    QString data = ui->lineEdit_host_zk_data->text() + ":" + ui->lineEdit_port_zk_data->text();
    QToolButton * qbutton = new QToolButton(this);
    qbutton->setIcon(QIcon(":lib/grey.svg"));
    qbutton->setText(data);
    qbutton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    qbutton->setMinimumHeight(50);
    qbutton->setMinimumWidth(180);
    qbutton->setMaximumWidth(180);
    qbutton->setCheckable(true);
    m_buttonGroup->addButton(qbutton, count++);
    QVBoxLayout *layout = (QVBoxLayout *)ui->scrollAreaWidgetContents->layout();
    layout->insertWidget(layout->count()-1, qbutton);
    //连接
    zkInfoStruct zkInfo;
    zkInfo.name = "测试";
    zkInfo.host = ui->lineEdit_host_zk_data->text();
    zkInfo.port = ui->lineEdit_port_zk_data->text();
    db_->zk_insertZkInfo(zkInfo);

    connnectInfoStruct cInfoStruct;
    cInfoStruct.host = ui->lineEdit_host_zk_data->text();
    cInfoStruct.port = ui->lineEdit_port_zk_data->text();
    cInfoStruct.buttonSid = count-1;
    cInfoStruct.timeout = 5000;
    qbutton->setIcon(QIcon(":lib/yellow.svg"));//黄色
    zookeeperwidget * zkWidget = new zookeeperwidget(cInfoStruct);
    connect(zkWidget, SIGNAL(send_init(int, int)), this, SLOT(rece_init(int, int)));
    ui->stackedWidget->addWidget(zkWidget);
    connectManager.insert(count-1, ui->stackedWidget->count()-1);
    ui->stackedWidget->setCurrentIndex(ui->stackedWidget->count()-1);
    m_buttonGroup->button(count-1)->setChecked(true);
    zkStatusInfoMap[qbutton].status_ = 1;
    zkStatusInfoMap[qbutton].zkWidget_ =zkWidget;

    qbutton->setContextMenuPolicy(Qt::CustomContextMenu);
    QMenu * menu = new QMenu(qbutton);
    menu->setWindowFlags(menu->windowFlags()  | Qt::FramelessWindowHint | Qt::NoDropShadowWindowHint);
    menu->setAttribute(Qt::WA_TranslucentBackground);
        QAction *againAction = new QAction(tr("重连"), qbutton);
        QAction *closeAction = new QAction(tr("关闭"), qbutton);
        QAction *clearAction = new QAction(tr("删除"), qbutton);
        
        // 将菜单与按钮关联
        ///menu->addAction(againAction);
        menu->addAction(closeAction);
        menu->addAction(clearAction);
        qbutton->setContextMenuPolicy(Qt::CustomContextMenu);
        qbutton->setMenu(menu);
        QObject::connect(againAction, &QAction::triggered, this, [=](){
            qDebug("重连被点击");
            QToolButton* button_ =qobject_cast<QToolButton*>(sender()->parent());
            QStringList dataList;
            if (button_ != NULL) {
                dataList = button_->text().split(":");
                qDebug() << "text = " << dataList;
            }
        });

        QObject::connect(closeAction, &QAction::triggered, this, [=](){
            qDebug("关闭被点击");
            QToolButton* button_ =qobject_cast<QToolButton*>(sender()->parent());
            QStringList dataList;
            if (button_ != NULL) {
                dataList = button_->text().split(":");
                qDebug() << "text = " << dataList;
            }
            qDebug("关闭被点击, 删除zkWidget, 关闭zk连接");
            //删除zkWidget, 关闭zk连接
            delete zkWidget;
            qDebug("关闭被点击, 删除zkWidget, 关闭zk连接2");
            ui->stackedWidget->setCurrentIndex(0);
            zkStatusInfoMap[qbutton].status_ = 2;
            zkStatusInfoMap[qbutton].zkWidget_ =nullptr;
            qbutton->setIcon(QIcon(":lib/grey.svg"));//灰色
        });

        QObject::connect(clearAction, &QAction::triggered, this, [=](){
            qDebug("删除被点击");
            QToolButton* button_ =qobject_cast<QToolButton*>(sender()->parent());
            QStringList dataList;
            if (button_ != NULL) {
                dataList = button_->text().split(":");
                qDebug() << "text = " << dataList;
            }

            zkInfoStruct zkInfo;
            zkInfo.host = dataList[0];
            zkInfo.port = dataList[1];
            db_->zk_deleteZkInfo(zkInfo);

            delete zkWidget;
            ui->stackedWidget->setCurrentIndex(0);
            zkStatusInfoMap[qbutton].status_ = 2;
            zkStatusInfoMap[qbutton].zkWidget_ =nullptr;
            m_buttonGroup->removeButton(button_);
            delete(button_);
            //showMessage("删除", true);
        });

       QObject::connect(qbutton, &QToolButton::customContextMenuRequested, this, [=]()
       {
           qDebug() << "按钮被右击";
           menu->move(cursor().pos());
           menu->show();           //记录button对应的连接和状态
           zkStatusInfoMap[qbutton].status_ = 2;
           zkStatusInfoMap[qbutton].zkWidget_ =zkWidget;
           qDebug() << "记录状态";
       });
}

void zookeepermanagewidget::rece_buttonClicked(int index)
{
    //被点击按钮 创建连接
    QString buttonText = m_buttonGroup->checkedButton()->text();
    int index2 = buttonText.indexOf(":");
    QString host = buttonText.mid(0, index2);
    QString port = buttonText.mid(index2+1);
    connnectInfoStruct cInfoStruct;
    cInfoStruct.host = host;
    cInfoStruct.port = port;
    cInfoStruct.buttonSid = index;
    cInfoStruct.timeout = 5000;
    qDebug() << "单击按钮 " << index;
    //只有0才是成功
    if (zkStatusInfoMap[m_buttonGroup->checkedButton()].status_ == 0) {
        int widgetCount = ui->stackedWidget->count();
        qDebug() << "widgetCount = " << widgetCount;
        for (int i = 0; i < widgetCount; ++i) {
            // 获取索引处的widget
            zookeeperwidget* widget =qobject_cast<zookeeperwidget*>(ui->stackedWidget->widget(i));
            if (widget) {
                if (widget == zkStatusInfoMap[m_buttonGroup->checkedButton()].zkWidget_) {
                    ui->stackedWidget->setCurrentIndex(i);
                    qDebug() << "找到对应widget "  << i <<  " = " << &widget;
                    return;
                }
            }
        }
        qDebug("找不到对应widget,进行创建");
    }
        //创建连接
        m_buttonGroup->checkedButton()->setIcon(QIcon(":lib/yellow.svg"));//黄色

        zookeeperwidget * zkWidget = new zookeeperwidget(cInfoStruct);
        connect(zkWidget, SIGNAL(send_init(int, int)), this, SLOT(rece_init(int, int)));

        ui->stackedWidget->addWidget(zkWidget);
        connectManager.insert(index, ui->stackedWidget->count()-1);
        ui->stackedWidget->setCurrentIndex(ui->stackedWidget->count()-1);
        zkStatusInfoMap[m_buttonGroup->checkedButton()].status_ = 1;
        zkStatusInfoMap[m_buttonGroup->checkedButton()].zkWidget_ =zkWidget;
        qDebug() << "记录状态 按钮 = " << m_buttonGroup->checkedButton();
}

void zookeepermanagewidget::rece_init(int buttonSid, int code)
{
    if (code == ZOK) {
        m_buttonGroup->button(buttonSid)->setIcon(QIcon(":lib/green.svg"));//绿色
        zkStatusInfoMap[m_buttonGroup->checkedButton()].status_ = 0;
    } else {
        m_buttonGroup->button(buttonSid)->setIcon(QIcon(":lib/grey.svg")); //灰色
        zkStatusInfoMap[m_buttonGroup->checkedButton()].status_ = 3;
        //移除
        connectManager.remove(buttonSid);
    }
}

void zookeepermanagewidget::on_toolButton_clicked()
{
    QDesktopServices::openUrl(QUrl(QLatin1String("https://github.com/HuaGouFdog/Fdog-Kit")));
}
