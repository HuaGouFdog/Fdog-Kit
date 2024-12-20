#pragma execution_character_set("utf-8")
#include "addcommondwidget.h"
#include "ui_addcommondwidget.h"

addcommondwidget::addcommondwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addcommondwidget)
{
    ui->setupUi(this);
    setWindowFlags(Qt::WindowCloseButtonHint);
    isEdit = false;
}

addcommondwidget::addcommondwidget(QString name, QString data, bool isLineFeed) :
    ui(new Ui::addcommondwidget)
{
    ui->setupUi(this);
    setWindowFlags(Qt::WindowCloseButtonHint);
    ui->lineEdit_name->setText(name);
    ui->textEdit_date->append(data);
    ui->checkBox_enter->setChecked(isLineFeed);
    isEdit = true;
}

addcommondwidget::~addcommondwidget()
{
    delete ui;
}

void addcommondwidget::on_toolButton_param1_clicked()
{
    ui->textEdit_date->append("[p#1 参数名]");
}

void addcommondwidget::on_toolButton_param2_clicked()
{
    ui->textEdit_date->append("[p#2 参数名]");
}

void addcommondwidget::on_toolButton_param3_clicked()
{
    ui->textEdit_date->append("[p#3 参数名]");
}

void addcommondwidget::on_toolButton_param4_clicked()
{
    ui->textEdit_date->append("[p#4 参数名]");
}

void addcommondwidget::on_toolButton_param5_clicked()
{
    ui->textEdit_date->append("[p#5 参数名]");
}

void addcommondwidget::on_toolButton_param6_clicked()
{
    ui->textEdit_date->append("[p#6 参数名]");
}

void addcommondwidget::on_toolButton_cancel_clicked()
{
    this->close();
}

void addcommondwidget::on_toolButton_ok_clicked()
{
    if (isEdit) {
        emit send_addCommond(ui->lineEdit_name->text(), ui->textEdit_date->toPlainText(), ui->lineEdit_name->text(), ui->checkBox_enter->isChecked());
    } else {
        emit send_addCommond(ui->lineEdit_name->text(), ui->textEdit_date->toPlainText(), "", ui->checkBox_enter->isChecked());
    }
    
    this->hide();
}
