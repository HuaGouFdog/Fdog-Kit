#pragma execution_character_set("utf-8")
#include "keywidget.h"
#include "ui_keywidget.h"
#include <QDebug>
#include <QDir>
#include <QFileDialog>
keywidget::keywidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::keywidget)
{
    ui->setupUi(this);
    setWindowFlags(Qt::WindowCloseButtonHint);
    //打开数据库
    db_ = new sqlhandle();
}

keywidget::~keywidget()
{
    delete ui;
}

void keywidget::on_toolButton_browse_clicked()
{
    QString curPath=QDir::currentPath();  //初始化目录
    QString dlgTitle="选择密钥";   //对话框标题
    QString filter = "所有文件(*.*);;文本文件(*.txt);;图片文件(*.jpg *.gif)";   //文件过滤器
    QString fileName = QFileDialog::getOpenFileName(this,dlgTitle,curPath,filter);  //getOpenFileNames返回选择文件的带路径的完整文件名
    path = fileName;
    //截取文路径后面的文件名
    int index = fileName.lastIndexOf("/");
    fileName = fileName.mid(index + 1);
    qDebug() << "上传文件 文件名" << fileName;
    ui->lineEdit_key->setText(fileName);
}

void keywidget::on_toolButton_cancel_clicked()
{
    //取消
    this->close();
}

void keywidget::on_toolButton_ok_clicked()
{
    //确认
    //写入数据库
    //name path password
    sshKeyStruct skeyStruct;
    skeyStruct.name = ui->lineEdit_name->text();
    skeyStruct.path = path;
    skeyStruct.password = ui->lineEdit_key_pssword->text();

    db_->sshKey_insertsshKeyInfo(skeyStruct);
    //通知更新
    emit send_addsshKey(skeyStruct);
    this->close();

}
