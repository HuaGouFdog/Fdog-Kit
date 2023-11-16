#include "downloadwidget.h"
#include "ui_downloadwidget.h"
#include <QStackedLayout>
downloadwidget::downloadwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::downloadwidget)
{
    ui->setupUi(this);

//    QAction *action = new QAction(this);
//    action->setIcon(QIcon(":/lib/soucuo.png")); //action,QLineEdit::LeadingPosition
//    ui->progressBar->addAction(action);

    QStackedLayout * Layout = new QStackedLayout;
    Layout->setStackingMode(QStackedLayout::StackAll);
    Layout->setContentsMargins(0,0,0,0);
    Layout->addWidget(ui->progressBar);
    Layout->addWidget(ui->widget_4);

    ui->widget_5->setLayout(Layout);
}

downloadwidget::~downloadwidget()
{
    delete ui;
}
