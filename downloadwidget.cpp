#include "downloadwidget.h"
#include "ui_downloadwidget.h"
#include <QStackedLayout>
downloadwidget::downloadwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::downloadwidget)
{
    ui->setupUi(this);

//    QAction *action = new QAction(this);
//    action->setIcon(QIcon(":/lib/soucuo.png")); //action,QLineEdit::LeadingPosition
//    ui->progressBar->addAction(action);

    QStackedLayout * Layout = new QStackedLayout;
    Layout->setStackingMode(QStackedLayout::StackAll);
    Layout->setContentsMargins(0,0,0,0);
    Layout->addWidget(ui->progressBar);
    Layout->addWidget(ui->widget_4);

    ui->widget_5->setLayout(Layout);

    //默认只显示下载图标
    ui->widget_body->hide();
    this->setFixedSize(280,25);
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
