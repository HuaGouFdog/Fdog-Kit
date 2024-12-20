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

void mkdirfolderwidget::on_toolButton_cancel_clicked()
{
    this->close();
}

void mkdirfolderwidget::on_toolButton_ok_clicked()
{
    emit send_mkdirFolder(ui->lineEdit_name->text());
    this->hide();
}
