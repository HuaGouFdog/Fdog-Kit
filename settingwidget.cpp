#include "settingwidget.h"
#include "ui_settingwidget.h"

settingwidget::settingwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::settingwidget)
{
    ui->setupUi(this);
}

settingwidget::~settingwidget()
{
    delete ui;
}
