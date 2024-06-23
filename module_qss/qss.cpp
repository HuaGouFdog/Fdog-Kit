#include "qss.h"
#include "ui_qss.h"

qss::qss(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::qss)
{
    ui->setupUi(this);
}

qss::~qss()
{
    delete ui;
}
