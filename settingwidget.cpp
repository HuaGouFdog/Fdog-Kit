#include "settingwidget.h"
#include "ui_settingwidget.h"
#include "utils.h"
#include "colormatch.h"
settingwidget::settingwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::settingwidget)
{
    ui->setupUi(this);
    AnimatedCheckBox * cb = new AnimatedCheckBox(this);

    ui->verticalLayout_8->addWidget(cb);
    cb->show();

    AnimatedCheckBox * cb2 = new AnimatedCheckBox(this);

    ui->verticalLayout_9->addWidget(cb2);
    cb2->show();

    AnimatedCheckBox * cb3 = new AnimatedCheckBox(this);

    ui->verticalLayout_14->addWidget(cb3);
    cb3->show();

    colormatch * cm = new colormatch(this);
    ui->verticalWidget_16->layout()->addWidget(cm);
    cm->show();

    colormatch * cm2 = new colormatch(this);
    ui->verticalWidget_17->layout()->addWidget(cm2);
    cm2->show();

    colormatch * cm3 = new colormatch(this);
    ui->verticalWidget_18->layout()->addWidget(cm3);
    cm3->show();

    colormatch * cm4 = new colormatch(this);
    ui->verticalWidget_19->layout()->addWidget(cm4);
    cm4->show();

}

settingwidget::~settingwidget()
{
    delete ui;
}

void settingwidget::on_toolButton_clicked()
{
    ui->stackedWidget->setCurrentIndex((ui->stackedWidget->currentIndex() + 1)%7);
}
