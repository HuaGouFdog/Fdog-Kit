#pragma execution_character_set("utf-8")
#include "secretkeywidget.h"
#include "ui_secretkeywidget.h"

secretkeywidget::secretkeywidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::secretkeywidget)
{
    ui->setupUi(this);
    setWindowFlags(Qt::WindowCloseButtonHint);
    ui->tableWidget->horizontalHeader()->setVisible(true);
    ui->tableWidget->verticalHeader()->setVisible(false);

   //ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents); //列自动缩放
   //ui->tableWidget->setColumnWidth(5, 20);
}

secretkeywidget::~secretkeywidget()
{
    delete ui;
}

void secretkeywidget::on_toolButton_input_clicked()
{
    kwidget = new keywidget();
    kwidget->show();
}
