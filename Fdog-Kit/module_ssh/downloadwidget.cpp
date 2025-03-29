#pragma execution_character_set("utf-8")
#include "downloadwidget.h"
#include "ui_downloadwidget.h"
#include <QStackedLayout>
#include <QDebug>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include <QDesktopServices>
#include <QUrl>
downloadwidget::downloadwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::downloadwidget)
{
    ui->setupUi(this);

//    QAction *action = new QAction(this);
//    action->setIcon(QIcon(":/lib/soucuo.png")); //action,QLineEdit::LeadingPosition
//    ui->progressBar->addAction(action);

//    QStackedLayout * Layout = new QStackedLayout;
//    Layout->setStackingMode(QStackedLayout::StackAll);
//    Layout->setContentsMargins(0,0,0,0);
//    Layout->addWidget(ui->progressBar);
//    Layout->addWidget(ui->widget_4);

//    ui->widget_5->setLayout(Layout);

//    fileProgressWidget * fwidget = new fileProgressWidget("", "cppcheck-2.10.tar.gz", 2, 100, ui->widget);
//    fileProgressWidget * fwidget2 = new fileProgressWidget("", "cppcheck-2.10.tar.gz2", 2, 100, ui->widget);
//    fileProgressWidget * fwidget3 = new fileProgressWidget("", "cppcheck-2.10.tar.gz3", 2, 100, ui->widget);
//    fileProgressWidget * fwidget4 = new fileProgressWidget("", "cppcheck-2.10.tar.gz4", 2, 100, ui->widget);

//    QVBoxLayout * vLayout = qobject_cast<QVBoxLayout*>(ui->widget->layout());
//    vLayout->insertWidget(0, fwidget->widget);
//    vLayout->insertWidget(0, fwidget2->widget);
//    vLayout->insertWidget(0, fwidget3->widget);
//    vLayout->insertWidget(0, fwidget4->widget);
    //ui->widget->layout()->
//    ui->widget->layout()->addWidget(fwidget->widget);
//    ui->widget->layout()->addWidget(fwidget2->widget);
//    ui->widget->layout()->addWidget(fwidget3->widget);
//    ui->widget->layout()->addWidget(fwidget4->widget);
    //ui->widget->setLayout(vLayout);
    //默认只显示下载图标
    ui->widget_body->hide();
    this->setFixedSize(280,25);
}

void downloadwidget::createNewFile(QString filePath, QString fileName, int fileType, int64_t fileSize)
{
    fwidget = new fileProgressWidget(filePath, fileName, fileType, fileSize, ui->scrollAreaWidgetContents);
    QVBoxLayout * vLayout = qobject_cast<QVBoxLayout*>(ui->scrollAreaWidgetContents->layout());
    vLayout->insertWidget(0, fwidget->widgetf);
}

void downloadwidget::updateFileProgress(int64_t sumSize, int64_t fileSize, bool status)
{
    fwidget->rece_file_progress_sgin(sumSize, fileSize, status);
}

downloadwidget::~downloadwidget()
{
    delete ui;
}

void downloadwidget::on_toolButton_file_clicked()
{
    if (ui->widget_body->isHidden()) {
        qDebug() << "点我1";
        ui->widget_body->show();
        this->setFixedSize(280,330);
//        QGraphicsOpacityEffect *pButtonOpacity = new QGraphicsOpacityEffect(ui->widget_body);
//        pButtonOpacity->setOpacity(0);
//        ui->widget_body->setGraphicsEffect(pButtonOpacity);
//        QPropertyAnimation *opacityAnimation = new QPropertyAnimation(pButtonOpacity, "opacity", this);
//        opacityAnimation->setDuration(200); // 设置动画持续时间
//        opacityAnimation->setStartValue(0); // 设置起始透明度为0
//        opacityAnimation->setEndValue(1); // 设置结束透明度为1
//        opacityAnimation->start();
    } else {
        qDebug() << "点我2";
        ui->widget_body->hide();
        this->setFixedSize(280,25);
//        QGraphicsOpacityEffect *pButtonOpacity = new QGraphicsOpacityEffect(this);
//        pButtonOpacity->setOpacity(1);
//        ui->widget_body->setGraphicsEffect(pButtonOpacity);
//        QPropertyAnimation *opacityAnimation = new QPropertyAnimation(pButtonOpacity, "opacity");
//        opacityAnimation->setDuration(3000); // 设置动画持续时间
//        opacityAnimation->setStartValue(1); // 设置起始透明度为0
//        opacityAnimation->setEndValue(0); // 设置结束透明度为1
//        opacityAnimation->start();
//        QObject::connect(opacityAnimation, &QPropertyAnimation::finished, [=]()
//        {
//            qDebug() << "点击";
//            ui->widget_body->hide();
//            this->setFixedSize(280,25);
//        });
    }
}

fileProgressWidget::fileProgressWidget(QString filePath, QString fileName, int fileType, int64_t fileSize, QWidget *parent):
    QWidget(parent), filePath(filePath), fileName(fileName), fileType(fileType), fileSize(fileSize)
{
    //初始化进度条
    widgetf = new QWidget(parent);
    widgetFileFata = new QWidget();
    widgetDatProgreessBarData = new QWidget();
    progressBar = new QProgressBar();
    labelName = new QLabel();
    labelName->setMinimumHeight(20);
    labelName->setStyleSheet("background-color: rgba(255, 255, 255, 0);color: rgb(30, 30, 30);font: 9pt \"OPPOSans B\";");
    labelIcon = new QLabel();
    labelData = new QLabel();
    labelData->setStyleSheet("background-color: rgba(255, 255, 255, 0);color: rgb(30, 30, 30);font: 9pt \"OPPOSans B\";");
    progressBar->setMaximumHeight(18);
    progressBar->setMaximumWidth(265);
    //progressBar->setFixedSize(280,25);
    horizontalSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding);
    progressBar->setMaximum(fileSize);
    progressBar->setValue(0);
    progressBar->setStyleSheet("QProgressBar {\
                               border: 1px solid;\
                               border-color: rgba(35, 39, 46, 200);\
                               border-radius: 0px; \
                               text-align: right; \
                               font: 9pt \"OPPOSans B\";\
                               color:rgb(35, 39, 46);\
                           }\
                           QProgressBar:chunk{\
                               font: 9pt \"OPPOSans B\";\
                               border-radius:0px;\
                               text-align: right; \
                               background-color:rgb(48, 150, 245);\
                           }");
    labelName->setText(fileName);
    if (fileType == 1) {
        //上传
        labelIcon->setStyleSheet("image: url(:/lib/peixu.png);background-color: rgba(255, 255, 255, 0);");
    } else {
        //下载
        labelIcon->setStyleSheet("image: url(:/lib/peixu2.png);background-color: rgba(255, 255, 255, 0);");
    }
    labelIcon->setFixedSize(18,12);
    hLayout = new QHBoxLayout(); //水平
    hLayout->addWidget(labelIcon);
    hLayout->addItem(horizontalSpacer);
    //hLayout->addWidget(labelData);
    hLayout->setContentsMargins(0, 0, 0, 0);
    hLayout->setSpacing(0);
    widgetFileFata->setLayout(hLayout);
    widgetFileFata->setMaximumHeight(20);
    widgetFileFata->setMaximumWidth(268);
    sLayout = new QStackedLayout;
    sLayout->setStackingMode(QStackedLayout::StackAll);
    sLayout->setContentsMargins(0, 0, 0, 0);
    sLayout->setSpacing(0);
    sLayout->addWidget(progressBar);
    sLayout->addWidget(widgetFileFata);
    widgetDatProgreessBarData->setLayout(sLayout);
    widgetDatProgreessBarData->setStyleSheet("#widgetDatProgreessBarData{background-color: rgba(255, 255, 255, 0)}");
    vLayout = new QVBoxLayout(); //垂直
    vLayout->addWidget(labelName);
    vLayout->addWidget(widgetDatProgreessBarData);
    vLayout->setContentsMargins(3, 0, 3, 0);
    vLayout->setSpacing(0);
    widgetf->setLayout(vLayout);
    widgetf->setFixedSize(268,40);
    widgetf->setStyleSheet("#widgetf{background-color: rgba(255, 255, 255, 0); border-top: 1px solid;  border-color: rgba(126, 126, 126, 250);}");
}

void fileProgressWidget::rece_file_progress_sgin(int64_t sumSize, int64_t fileSize, bool status)
{
    //更新文件进度
    //qDebug() << "sum =" << sumSize << " filesize = " << fileSize;
    //计算大小
    double count_m = (double)fileSize / (double)1024 / (double)1024;
    double count_g = 0.0;
    QString countStr = "";
    if (count_m >= 1024) {
        count_g = count_m / 1024;
        countStr = QString::number(count_g, 'f', 1) + "G";
    } else {
        countStr = QString::number(count_m, 'f', 1) + "M";
    }

    double sum_m = (double)sumSize / (double)1024 / (double)1024;
    double sum_g = 0.0;
    QString sumStr = "";
    if (sum_m >= 1024) {
        sum_g = count_m / 1024;
        sumStr = QString::number(sum_g, 'f', 1) + "G";
    } else {
        sumStr = QString::number(sum_m, 'f', 1) + "M";
    }
    progressBar->setFormat("%p%   " + sumStr + "/" + countStr + " ");
    progressBar->setMaximum(fileSize);
    progressBar->setValue(sumSize);

    if (sumSize == fileSize) {
        progressBar->setFormat("已完成 ");
    }
}

void downloadwidget::on_toolButton_file_open_clicked()
{
    //打开文件
    QDesktopServices::openUrl(QUrl("file:C:/Users/张旭/Desktop/fsdownload", QUrl::TolerantMode));
}

void downloadwidget::on_toolButton_file_setting_clicked()
{
    //设置
    emit send_setting();
}
