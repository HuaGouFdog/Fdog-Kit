#pragma execution_character_set("utf-8")
#include "zookeepertipswidget.h"
#include "ui_zookeepertipswidget.h"

zookeepertipswidget::zookeepertipswidget(QWidget *parent, QString message, bool isSuccess) :
    QWidget(parent),
    ui(new Ui::zookeepertipswidget)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Popup | Qt::FramelessWindowHint | Qt::NoDropShadowWindowHint);
    if (isSuccess) {
        ui->label_icon->setStyleSheet("image: url(:/lib/node.png);");
    } else {
        ui->label_icon->setStyleSheet("image: url(:/lib/node2.png);");
    }
    ui->label_message->setText(message);
}

zookeepertipswidget::~zookeepertipswidget()
{
    delete ui;
}
