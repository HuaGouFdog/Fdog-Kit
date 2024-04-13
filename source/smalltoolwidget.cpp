#include "smalltoolwidget.h"
#include "ui_smalltoolwidget.h"

smalltoolwidget::smalltoolwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::smalltoolwidget)
{
    ui->setupUi(this);
}

smalltoolwidget::~smalltoolwidget()
{
    delete ui;
}
