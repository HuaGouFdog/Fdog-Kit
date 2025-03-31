#pragma execution_character_set("utf-8")
#include "historycommondwidget.h"
#include "ui_historycommondwidget.h"
#include <QDebug>
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

void historycommondwidget::addCommand(QString command)
{
    ui->listWidget->addItem(command);
}

void historycommondwidget::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    qDebug() << "选中命令 = " << item->text();
    //双击发送信号
    emit send_commond(item->text());
}

