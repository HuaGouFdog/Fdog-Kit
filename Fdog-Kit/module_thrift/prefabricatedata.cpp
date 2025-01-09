#pragma execution_character_set("utf-8")
#include "prefabricatedata.h"
#include "ui_prefabricatedata.h"
#include <QFile>
#include <QDebug>
prefabricatedata::prefabricatedata(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::prefabricatedata)
{
    ui->setupUi(this);
    openPreFile();
}

prefabricatedata::~prefabricatedata()
{
    delete ui;
}

void prefabricatedata::openPreFile() {
    //读取
    QString fileName = "thriftConfig\\preData.txt";
    // 创建文件对象
    QFile file(fileName);
    // 打开文件，并且以只读方式进行读取
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QByteArray fileData = file.readAll();
        file.close();
        ui->textEdit->setText(QString(fileData));
    } else {
        // 如果文件打开失败，则输出错误信息
        qDebug() << "打开文件失败!";
    }
}
void prefabricatedata::writePreFile() {
    // 获取 textEdit 中的文本
    QString text = ui->textEdit->toPlainText();
    // 文件路径
    QString filePath = "thriftConfig\\preData.txt";
    // 打开文件进行写入
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "文件写入失败";
        return;
    }
    // 创建 QTextStream 对象进行写入
    QTextStream out(&file);
    out << text;
    // 关闭文件
    file.close();
}

void prefabricatedata::on_toolButton_recover_clicked()
{
    this->close();
}


void prefabricatedata::on_toolButton_save_clicked()
{
    writePreFile();
    this->close();
}

