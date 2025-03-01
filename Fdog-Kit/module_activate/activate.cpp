#include "activate.h"
#include "ui_activate.h"
#include "module_utils/utils.h"
#include<QGraphicsDropShadowEffect>
#include <QPropertyAnimation>
Activate::Activate(config * confInfo, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Activate)
{
    ui->setupUi(this);
    this->confInfo = confInfo;
    ui->label_5->hide();
    //ui->progressBar->hide();
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
    //ui->progressBar->setValue(0);
}
Activate::~Activate()
{
    delete ui;
}

void Activate::updateBarValue()
{
//    m_value++;
//    ui->progressBar->setValue(m_value);
//    if (m_value >= 100){
//        signalReceived = true;
//        m_timer->stop();
//        qDebug() <<  "关闭Activate";
//        this->close();
//    }
}

void Activate::on_toolButton_close_clicked()
{
    //关闭
    signalReceived = true;
    this->close();
}


void Activate::on_toolButton_run_clicked()
{
    // //读取配置文件信息
    // config * confInfo = new config();
    // // 读取JSON文件
    // confInfo->readSettingConf();
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
        ui->label_tips->hide();
        confInfo->isFirstStart = 0;
        confInfo->writeSettingConf();

        ui->label_tips->hide();
        ui->toolButton_run->hide();
        ui->toolButton_close->hide();
        ui->label_5->show();

        QPropertyAnimation * m_pos_animation = new QPropertyAnimation();
        m_pos_animation->setTargetObject(ui->widget_4);
        // 2.设置动画属性
        m_pos_animation->setPropertyName("pos");
        // 3.设置动画的起始值
        QPoint startPoint(-60, 0);
        m_pos_animation->setStartValue(startPoint);
        m_pos_animation->setEndValue(startPoint + QPoint(670, 0));
        // 4.设置动画的时间
        m_pos_animation->setDuration(2000);

        // 5.设置动画的缓和曲线
        m_pos_animation->setEasingCurve(QEasingCurve::Linear);

        // 6.设置动画的播放周期
        m_pos_animation->setLoopCount(3);

        connect(m_pos_animation, SIGNAL(finished()), this, SLOT(whenAnimationFinish()));

        m_pos_animation->start();
    }
}

void Activate::whenAnimationFinish() {
    signalReceived2 = true;
    signalReceived = true;
    this->close();
}

