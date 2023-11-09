#include "colormatch.h"
#include "ui_colormatch.h"

colormatch::colormatch(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::colormatch)
{
    ui->setupUi(this);
}

colormatch::~colormatch()
{
    delete ui;
}
