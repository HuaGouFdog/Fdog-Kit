#include "createconnect.h"
#include "ui_createconnect.h"

createconnect::createconnect(int8_t connectType, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::createconnect)
{
    ui->setupUi(this);
    this->connectType = connectType;
}

createconnect::~createconnect()
{
    delete ui;
}

void createconnect::on_pushButton_connect_clicked()
{
    //创建选择的连接信息
    connnectInfoStruct cInfo;
    cInfo.connectType = this->connectType;
    cInfo.name = ui->lineEdit_name->text();
    cInfo.host = ui->lineEdit_host->text();
    cInfo.port = ui->lineEdit_port->text();
    emit newCreate(cInfo);
    this->close();
}

void createconnect::on_pushButton_close_clicked()
{
    emit newClose();
    this->close();
}
