#include "activate.h"
#include "ui_activate.h"
#include "module_utils/utils.h"
#include<QGraphicsDropShadowEffect>
Activate::Activate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Activate)
{
    ui->setupUi(this);
    ui->progressBar->hide();
    ui->label_tips->hide();
    //Qt::WindowFlags flags = this->windowFlags();
    //this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint); //Qt::WindowStaysOnTopHint
    return;
    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, &Activate::updateBarValue);
    m_timer->start(10);
    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
    //设置边框阴影
    QGraphicsDropShadowEffect* shadow = new QGraphicsDropShadowEffect(this);
    shadow->setOffset(0, 0);
    shadow->setColor(QColor(0, 0, 0, 60));
    shadow->setBlurRadius(10);
    //ui->Activate->setGraphicsEffect(shadow);
    m_value = 0;
    ui->progressBar->setValue(0);
}
Activate::~Activate()
{
    delete ui;  
}

void Activate::updateBarValue()
{
    m_value++;
    ui->progressBar->setValue(m_value);
    if (m_value >= 100){
        signalReceived = true;
        m_timer->stop();
        qDebug() <<  "关闭Activate";
        this->close();
    }
}

void Activate::on_toolButton_close_clicked()
{
    //关闭
    signalReceived = true;
    this->close();
}


void Activate::on_toolButton_run_clicked()
{
    //读取配置文件信息
    config * confInfo = new config();
    // 读取JSON文件
    confInfo->readSettingConf();
    int sum = 0;
    if (ui->checkBox_auto->isChecked()) {
        confInfo->autoPackage = 1;
        sum++;
    }
    if (ui->checkBox_thrift->isChecked()) {
        confInfo->thrift = 1;
        sum++;
    }
    if (ui->checkBox_zk->isChecked()) {
        confInfo->zookeeper = 1;
        sum++;
    }
    if (ui->checkBox_shell->isChecked()) {
        confInfo->shell = 1;
        sum++;
    }
    if (ui->checkBox_db->isChecked()) {
        confInfo->db = 1;
        sum++;
    }
    if (ui->checkBox_qss->isChecked()) {
        confInfo->qss = 1;
        sum++;
    }
    if (ui->checkBox_tool->isChecked()) {
        confInfo->tool = 1;
        sum++;
    }
    if (ui->checkBox_extend->isChecked()) {
        confInfo->extend = 1;
        sum++;
    }

    if (ui->checkBox_tool->isChecked()) {
        confInfo->autoPackage = 1;
        sum++;
    }

    if(sum <= 0) {
        //没有选择，给出提示
        ui->label_tips->show();
    } else {
        confInfo->isFirstStart = 3;
        confInfo->writeSettingConf();
        confInfo->readSettingConf();
        qDebug() << "isFirstStart 2 = " << confInfo->isFirstStart;
        // signalReceived2 = true;
        // signalReceived = true;
        // this->close();
    }
}

