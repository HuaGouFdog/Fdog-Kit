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
    signalReceived = true;
    signalReceived2 = true;
    this->close();
}

