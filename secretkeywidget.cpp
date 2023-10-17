#include "secretkeywidget.h"
#include "ui_secretkeywidget.h"

secretkeywidget::secretkeywidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::secretkeywidget)
{
    ui->setupUi(this);
}

secretkeywidget::~secretkeywidget()
{
    delete ui;
}
