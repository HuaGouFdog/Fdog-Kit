#include "mkdirfolderwidget.h"
#include "ui_mkdirfolderwidget.h"

mkdirfolderwidget::mkdirfolderwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mkdirfolderwidget)
{
    ui->setupUi(this);
    setWindowFlags(Qt::WindowCloseButtonHint);
}

mkdirfolderwidget::~mkdirfolderwidget()
{
    delete ui;
}
