#include "toolswidget.h"
#include "ui_toolswidget.h"
#include <QTimer>
#include <QDateTime>
#include <QDebug>
#include <QUrl>
toolswidget::toolswidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::toolswidget)
{
    ui->setupUi(this);
    ui->toolBox->setCurrentIndex(2);
    qDebug() << "1";
    // 创建定时器
    QTimer * timer = new QTimer();

    // 设置定时器的间隔为1000毫秒（1秒）
    timer->setInterval(1000);

    // 连接定时器的timeout()信号到槽函数
    connect(timer,SIGNAL(timeout()), this,
                            SLOT(rece_showtimestamp()));
    // 启动定时器
    timer->start();
    qDebug() << "2";
}

toolswidget::~toolswidget()
{
    delete ui;
}

void toolswidget::rece_showtimestamp()
{
    //qDebug() << "rece_showtimestamp";
    // 获取当前时间
    QDateTime currentTime = QDateTime::currentDateTime();

    // 将时间转换为时间戳（秒数）
    qint64 timestamp = currentTime.toSecsSinceEpoch();

    // 将时间戳转换为字符串
    QString timestampStr = QString::number(timestamp);

    // 在标签上显示时间戳
    ui->lineEdit_now->setText(timestampStr);
}

void toolswidget::on_toolButton_clicked()
{
    QString in = ui->lineEdit_timestamp_in->text();
    qint64 timestamp = in.toLongLong();
    if (ui->comboBox_timestamp->currentIndex() == 0) {
        //秒
        QDateTime dateTime = QDateTime::fromSecsSinceEpoch(timestamp);

        // 将 QDateTime 对象格式化为日期字符串
        QString dateString = dateTime.toString("yyyy-MM-dd hh:mm:ss");
        ui->lineEdit_date_out->setText(dateString);
    } else {
        //毫秒
        QDateTime dateTime = QDateTime::fromMSecsSinceEpoch(timestamp);
        QString dateString = dateTime.toString("yyyy-MM-dd hh:mm:ss");
        ui->lineEdit_date_out->setText(dateString);
    }
}

void toolswidget::on_toolButton_2_clicked()
{
    QString in = ui->lineEdit_date_in->text();
    if (ui->comboBox_date->currentIndex() == 0) {
        //秒
        QDateTime dateTime = QDateTime::fromString(in, "yyyy-MM-dd hh:mm:ss");
        qint64 secondsTimestamp = dateTime.toSecsSinceEpoch();
        ui->lineEdit_timestamp_out->setText(QString::number(secondsTimestamp));
    } else {
        //毫秒
        QDateTime dateTime = QDateTime::fromString(in, "yyyy-MM-dd hh:mm:ss");
        qint64 millisecondsTimestamp = dateTime.toMSecsSinceEpoch();
        ui->lineEdit_timestamp_out->setText(QString::number(millisecondsTimestamp));
    }
}

void toolswidget::on_lineEdit_hex_textChanged(const QString &arg1)
{
    if (ui->lineEdit_hex->hasFocus()) {
        bool ok;
        qint64 decimalValue = arg1.toLongLong(&ok, 16);
        if (ok) {
            ui->lineEdit_dec->setText(QString::number(decimalValue));
        }

        qint64 binaryValue = arg1.toLongLong(&ok, 16);
        if (ok) {
            QString binaryString = QString::number(binaryValue, 2);
            ui->lineEdit_bin->setText(binaryString);
        }

        qint64 octalValue = arg1.toLongLong(&ok, 16);
        if (ok) {
            QString octalString = QString::number(octalValue, 8);
            ui->lineEdit_oct->setText(octalString);
        }
    }
}

void toolswidget::on_lineEdit_dec_textChanged(const QString &arg1)
{
    if (ui->lineEdit_dec->hasFocus()) {
        qint64 decimalValue = arg1.toLongLong();
        QString binaryString = QString::number(decimalValue, 2);
        QString octalString = QString::number(decimalValue, 8);
        QString hexadecimalString = QString::number(decimalValue, 16);
        ui->lineEdit_hex->setText(hexadecimalString);
        ui->lineEdit_oct->setText(octalString);
        ui->lineEdit_bin->setText(binaryString);
    }
}

void toolswidget::on_lineEdit_oct_textChanged(const QString &arg1)
{
    if (ui->lineEdit_oct->hasFocus()) {
        bool ok;
        qint64 decimalValue = arg1.toLongLong(&ok, 8);
        if (ok) {
            ui->lineEdit_dec->setText(QString::number(decimalValue));
        }

        qint64 binaryValue = arg1.toLongLong(&ok, 8);
        if (ok) {
            QString binaryString = QString::number(binaryValue, 2);
            ui->lineEdit_bin->setText(binaryString);
        }

        qint64 heximalValue = arg1.toLongLong(&ok, 8);
        if (ok) {
            QString octalString = QString::number(heximalValue, 16);
            ui->lineEdit_hex->setText(octalString);
        }
    }
}

void toolswidget::on_lineEdit_bin_textChanged(const QString &arg1)
{
    if (ui->lineEdit_bin->hasFocus()) {
        bool ok;
        qint64 binaryValue = arg1.toLongLong(&ok, 2);
        if (ok) {
            ui->lineEdit_dec->setText(QString::number(binaryValue));
        }

        qint64 heximalValue = arg1.toLongLong(&ok, 2);
        if (ok) {
            QString hexString = QString::number(heximalValue, 16);
            ui->lineEdit_hex->setText(hexString);
        }

        qint64 octalValue = arg1.toLongLong(&ok, 2);
        if (ok) {
            QString octalString = QString::number(octalValue, 8);
            ui->lineEdit_oct->setText(octalString);
        }
    }
}

void toolswidget::on_toolButton_decode_clicked()
{
    //解码
    QString url = ui->lineEdit_encode->text();
    QString decodedUrl = QUrl::fromPercentEncoding(url.toUtf8());
    ui->lineEdit_decode->setText(decodedUrl);
}

void toolswidget::on_toolButton_encode_clicked()
{
    //编码
    QString url = ui->lineEdit_decode->text();
    QString encodedUrl = QUrl::toPercentEncoding(url);
    ui->lineEdit_encode->setText(encodedUrl);

}
