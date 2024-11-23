#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "module_zookeeper/zookeepermanagewidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    zookeepermanagewidget * zkWidget = new zookeepermanagewidget(this);
    ui->centralWidget->layout()->addWidget(zkWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}
