#pragma execution_character_set("utf-8")
#include "findwidget.h"
#include "ui_findwidget.h"
#include <QDebug>
#include <QAction>
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

QString findwidget::gitSearchText()
{
    return ui->lineEdit_search->text();
}

void findwidget::on_toolButton_close_clicked()
{
    this->hide();
}

void findwidget::on_lineEdit_search_textChanged(const QString &arg1)
{
    emit send_searchTextChanged(arg1);
}

void findwidget::rece_searchTextNumbers(int sn, int sum) {
    qDebug() << "搜索到" << sum << "个";
    QString data = QString::number(sn) + "/" + QString::number(sum);
    ui->label_conut->setText(data);
}
