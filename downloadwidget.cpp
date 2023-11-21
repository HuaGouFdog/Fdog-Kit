#pragma execution_character_set("utf-8")
#include "downloadwidget.h"
#include "ui_downloadwidget.h"
#include <QStackedLayout>
#include <QDebug>
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
    //ui->widget_body->hide();
    //this->setFixedSize(280,25);
}

void downloadwidget::createNewFile(QString filePath, QString fileName, int fileType, int64_t fileSize)
{
    qDebug() << "fwidget createNewFile start";
    fwidget = new fileProgressWidget(filePath, fileName, fileType, fileSize, ui->widget);
    QVBoxLayout * vLayout = qobject_cast<QVBoxLayout*>(ui->widget->layout());
    vLayout->insertWidget(0, fwidget->widget);
    qDebug() << "fwidget createNewFile end";
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
        ui->widget_body->show();
        this->setFixedSize(280,330);
    } else {
        ui->widget_body->hide();
        this->setFixedSize(280,25);
    }
}

fileProgressWidget::fileProgressWidget(QString filePath, QString fileName, int fileType, int64_t fileSize, QWidget *parent):
    QWidget(parent), filePath(filePath), fileName(fileName), fileType(fileType), fileSize(fileSize)
{
    //初始化进度条
    widget = new QWidget(parent);
    widgetFileFata = new QWidget();
    qDebug() << "fileProgressWidget 0";
    widgetDatProgreessBarData = new QWidget();
    progressBar = new QProgressBar();
    labelName = new QLabel();
    labelName->setMinimumHeight(20);
    labelName->setStyleSheet("background-color: rgba(255, 255, 255, 0);color: rgb(45, 45, 45);font: 9pt \"OPPOSans B\";");
    labelIcon = new QLabel();
    labelData = new QLabel();
    qDebug() << "fileProgressWidget 1";
    labelData->setStyleSheet("background-color: rgba(255, 255, 255, 0);color: rgb(45, 45, 45);font: 9pt \"OPPOSans B\";");
    progressBar->setMaximumHeight(18);
    progressBar->setMaximumWidth(260);
    //progressBar->setFixedSize(280,25);
    horizontalSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding);
    progressBar->setMaximum(fileSize);
    progressBar->setValue(0);
    qDebug() << "fileProgressWidget 2";
    progressBar->setStyleSheet("QProgressBar {\
                               border: 1px solid;\
                               border-color: rgb(91, 91, 91);\
                               border-radius: 0px; \
                               text-align: right; \
                               font: 9pt \"OPPOSans B\";\
                               color: rgba(0, 0, 0, 200);\
                           }\
                           QProgressBar:chunk{\
                               font: 9pt \"OPPOSans B\";\
                               border-radius:0px;\
                               text-align: right; \
                               background-color: rgb(180, 220, 255);\
                           }");

    labelName->setText(fileName);
    if (fileType == 1) {
        //上传
        labelIcon->setStyleSheet("image: url(:/lib/peixu.png);");
    } else {
        //下载
        labelIcon->setStyleSheet("image: url(:/lib/peixu2.png);");
    }
    labelIcon->setFixedSize(12,12);
    //labelData->setText("534M");
    qDebug() << "fileProgressWidget 3";
    hLayout = new QHBoxLayout(); //水平
    hLayout->addWidget(labelIcon);
    hLayout->addItem(horizontalSpacer);
    //hLayout->addWidget(labelData);
    hLayout->setContentsMargins(3, 1, 3, 1);
    hLayout->setSpacing(0);
    widgetFileFata->setLayout(hLayout);
    widgetFileFata->setMaximumHeight(20);
    widgetFileFata->setMaximumWidth(260);
    sLayout = new QStackedLayout;
    sLayout->setStackingMode(QStackedLayout::StackAll);
    sLayout->setContentsMargins(3, 1, 3, 1);
    sLayout->setSpacing(0);
    sLayout->addWidget(progressBar);
    sLayout->addWidget(widgetFileFata);
    widgetDatProgreessBarData->setLayout(sLayout);
    qDebug() << "fileProgressWidget 4";
    vLayout = new QVBoxLayout(); //垂直
    vLayout->addWidget(labelName);
    vLayout->addWidget(widgetDatProgreessBarData);
    vLayout->setContentsMargins(3, 1, 3, 1);
    vLayout->setSpacing(0);
    widget->setLayout(vLayout);
    widget->setFixedSize(280,40);
    widget->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    qDebug() << "fileProgressWidget 5";
}

void fileProgressWidget::rece_file_progress_sgin(int64_t sumSize, int64_t fileSize, bool status)
{
    //更新文件进度
    qDebug() << "sum =" << sumSize << " filesize = " << fileSize;
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
