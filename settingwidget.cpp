#include "settingwidget.h"
#include "ui_settingwidget.h"
#include "utils.h"
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
}

settingwidget::~settingwidget()
{
    delete ui;
}

void settingwidget::on_toolButton_clicked()
{
    ui->stackedWidget->setCurrentIndex((ui->stackedWidget->currentIndex() + 1)%7);
}
