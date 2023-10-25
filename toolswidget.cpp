#include "toolswidget.h"
#include "ui_toolswidget.h"
#include <QTimer>
#include <QDateTime>
#include <QDebug>
#include <QUrl>
toolswidget::toolswidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::toolswidget)
{
    ui->setupUi(this);
}

toolswidget::~toolswidget()
{
    delete ui;
}
