#include "historycommondwidget.h"
#include "ui_historycommondwidget.h"

historycommondwidget::historycommondwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::historycommondwidget)
{
    ui->setupUi(this);
}

historycommondwidget::~historycommondwidget()
{
    delete ui;
}
