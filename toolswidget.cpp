#include "toolswidget.h"
#include "ui_toolswidget.h"

toolswidget::toolswidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::toolswidget)
{
    ui->setupUi(this);
    ui->toolBox->setCurrentIndex(2);
}

toolswidget::~toolswidget()
{
    delete ui;
}
