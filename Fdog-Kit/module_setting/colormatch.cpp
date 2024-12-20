#include "colormatch.h"
#include "ui_colormatch.h"

colormatch::colormatch(QString matchName, QStringList colorData, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::colormatch)
{
    ui->setupUi(this);
    ui->label_name->setText(matchName);
    ui->label_color_black->setStyleSheet(QString("background-color: %1;").arg(colorData[0]));
    ui->label_color_brightBlack->setStyleSheet(QString("background-color: %1;").arg(colorData[1]));
    ui->label_color_red->setStyleSheet(QString("background-color: %1;").arg(colorData[2]));
    ui->label_color_brightRed->setStyleSheet(QString("background-color: %1;").arg(colorData[3]));
    ui->label_color_green->setStyleSheet(QString("background-color: %1;").arg(colorData[4]));
    ui->label_color_brightGreen->setStyleSheet(QString("background-color: %1;").arg(colorData[5]));
    ui->label_color_yellow->setStyleSheet(QString("background-color: %1;").arg(colorData[6]));
    ui->label_color_brightYellow->setStyleSheet(QString("background-color: %1;").arg(colorData[7]));
    ui->label_color_blue->setStyleSheet(QString("background-color: %1;").arg(colorData[8]));
    ui->label_color_brightBlue->setStyleSheet(QString("background-color: %1;").arg(colorData[9]));
    ui->label_color_purple->setStyleSheet(QString("background-color: %1;").arg(colorData[10]));
    ui->label_color_brightPurple->setStyleSheet(QString("background-color: %1;").arg(colorData[11]));
    ui->label_color_cyan->setStyleSheet(QString("background-color: %1;").arg(colorData[12]));
    ui->label_color_brightCyan->setStyleSheet(QString("background-color: %1;").arg(colorData[13]));
    ui->label_color_white->setStyleSheet(QString("background-color: %1;").arg(colorData[14]));
    ui->label_color_brightWhite->setStyleSheet(QString("background-color: %1;").arg(colorData[15]));
    ui->horizontalWidget_24->setStyleSheet(QString("background-color: %1;border-radius:5px;").arg(colorData[16]));
}

colormatch::~colormatch()
{
    delete ui;
}
