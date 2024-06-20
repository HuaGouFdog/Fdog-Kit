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
    qDebug() << "上传文件 文件名" << fileName;

}

void keywidget::on_toolButton_cancel_clicked()
{
    //取消
    this->close();
}

void keywidget::on_toolButton_ok_clicked()
{
    //确认
    this->hide();
}
