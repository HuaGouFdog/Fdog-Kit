#pragma execution_character_set("utf-8")
#include "zookeepertipswidget.h"
#include "ui_zookeepertipswidget.h"
#include "utils.h"
zookeepertipswidget::zookeepertipswidget(QWidget *parent, QString message, bool isSuccess) :
    QWidget(parent),
    ui(new Ui::zookeepertipswidget)
{
    ui->setupUi(this);
    setSupportStretch(this, true);
    setWindowFlags(Qt::FramelessWindowHint | Qt::NoDropShadowWindowHint);
    setFocusPolicy(Qt::NoFocus);
    this->setParent(parent);
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
