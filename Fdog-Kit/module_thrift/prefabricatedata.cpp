#pragma execution_character_set("utf-8")
#include "prefabricatedata.h"
#include "ui_prefabricatedata.h"
#include <QFile>
#include <QTextCodec>
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
        
        QString encoding = detectEncoding(fileData);
        QTextStream in;
        if (encoding == "UTF-8") {
            in.setCodec(QTextCodec::codecForName("UTF-8"));
        } else if (encoding == "GBK") {
            in.setCodec(QTextCodec::codecForName("GBK"));
        }

        // 将 QByteArray 转换为 QString
        QString fileDataStr = in.codec()->toUnicode(fileData);
        ui->textEdit->setText(fileDataStr);
    } else {
        // 如果文件打开失败，则输出错误信息
        qDebug() << "打开文件失败!";
    }
}

void prefabricatedata::openPreFile2()
{
    QString fileName = "thriftConfig\\ap-20250102-1710.pcap";
    // 创建文件对象
    QFile file(fileName);
    // 打开文件，并且以只读方式进行读取
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QByteArray fileData = file.readAll();
        file.close();
        //qDebug() << "数据 = " << QString(fileData);
        //ui->textEdit->setText(QString(fileData));
        // 打印16进制内容
        printHex(fileData);
    } else {
        // 如果文件打开失败，则输出错误信息
        qDebug() << "打开文件失败!";
    }
}

void prefabricatedata::printHex(const QByteArray &data)
{
    QString a;
    for (int i = 0; i < data.size(); i++) {
        if (i % 16 == 0) {
            qDebug() << a;
            a = "";
            if (i > 0) {
                qDebug() << "";
            }
            qDebug() << QString("%1:").arg(i, 4, 16, QChar('0'));
        }
        a =a + QString("%1").arg(static_cast<unsigned char>(data[i]), 2, 16, QChar('0')).toUpper();
    }
    if (data.size() % 16 != 0) {
        qDebug() << "";
    }
    qDebug() << a;
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

QString prefabricatedata::detectEncoding(const QByteArray &data) {
    if (data.startsWith("\xEF\xBB\xBF")) {
        return "UTF-8";
    } else {
        // 这里可以添加更多的检测逻辑
        // 例如，检查一些常见的 GBK 字符
        return "GBK";
    }
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

