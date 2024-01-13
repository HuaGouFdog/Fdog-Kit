#pragma execution_character_set("utf-8")
#include "zookeepermanagewidget.h"
#include "ui_zookeepermanagewidget.h"

zookeepermanagewidget::zookeepermanagewidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::zookeepermanagewidget)
{
    ui->setupUi(this);
    //只是创建一个界面
    zookeeperwidget * zkWidget = new zookeeperwidget();
    ui->stackedWidget->addWidget(zkWidget);
}

zookeepermanagewidget::zookeepermanagewidget(connnectInfoStruct &cInfoStruct, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::zookeepermanagewidget)
{
    ui->setupUi(this);
    //只是创建一个界面
    zookeeperwidget * zkWidget = new zookeeperwidget(cInfoStruct);
    ui->stackedWidget->addWidget(zkWidget);
    ui->stackedWidget->setCurrentIndex(ui->stackedWidget->count()-1);
}

void zookeepermanagewidget::newCreate(connnectInfoStruct &cInfoStruct)
{
    zookeeperwidget * zkWidget = new zookeeperwidget(cInfoStruct);
    ui->stackedWidget->addWidget(zkWidget);
    ui->stackedWidget->setCurrentIndex(ui->stackedWidget->count()-1);
}

zookeepermanagewidget::~zookeepermanagewidget()
{
    delete ui;
}

void zookeepermanagewidget::on_toolButton_newCreate_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void zookeepermanagewidget::on_toolButton_save_clicked()
{
    //创建连接
    QString data = ui->lineEdit_host_zk_data->text() + ":" + ui->lineEdit_port_zk_data->text();
    QToolButton * qbutton = new QToolButton(this);
    qbutton->setIcon(QIcon(":lib/node2.png"));
    qbutton->setText(data);
    qbutton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    qbutton->setMinimumHeight(50);
    qbutton->setMinimumWidth(180);
    QVBoxLayout *layout = (QVBoxLayout *)ui->scrollAreaWidgetContents->layout();
    layout->insertWidget(layout->count()-1, qbutton);
    ui->stackedWidget->setCurrentIndex(1);
}

void zookeepermanagewidget::on_toolButton_close_clicked()
{
    //
}
