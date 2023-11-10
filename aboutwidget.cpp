#include "aboutwidget.h"
#include "ui_aboutwidget.h"

aboutwidget::aboutwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::aboutwidget)
{
    ui->setupUi(this);
    //只显示关闭按钮
    setWindowFlags(Qt::WindowCloseButtonHint);
}

aboutwidget::~aboutwidget()
{
    delete ui;
}
