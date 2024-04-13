#include "addcommondwidget.h"
#include "ui_addcommondwidget.h"

addcommondwidget::addcommondwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addcommondwidget)
{
    ui->setupUi(this);
    setWindowFlags(Qt::WindowCloseButtonHint);
}

addcommondwidget::~addcommondwidget()
{
    delete ui;
}
