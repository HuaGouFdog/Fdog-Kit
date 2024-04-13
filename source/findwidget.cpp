#pragma execution_character_set("utf-8")
#include "findwidget.h"
#include "ui_findwidget.h"

findwidget::findwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::findwidget)
{
    ui->setupUi(this);
    //this->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    //ui->horizontalWidget->setAttribute(Qt::WA_TransparentForMouseEvents, true);
//    ui->label->setFixedSize(30,30);
//    QPixmap icon(":/lib/soucuo.png");
//    QPixmap scaledIcon = icon.scaled(16, 16, Qt::KeepAspectRatio);
//    ui->label->setPixmap(scaledIcon);

    QAction *action = new QAction(this);
    action->setIcon(QIcon(":/lib/soucuo.png"));
    ui->lineEdit_search->addAction(action,QLineEdit::LeadingPosition);
}

void findwidget::setFindText(QString data)
{
    ui->lineEdit_search->setText(data);
}

findwidget::~findwidget()
{
    delete ui;
}

void findwidget::on_toolButton_close_clicked()
{
    this->hide();
}
