#include "historyconnectwidget.h"
#include "ui_historyconnectwidget.h"
#include <QDebug>
#include <QToolButton>
#include <QIcon>
historyconnectwidget::historyconnectwidget(int8_t connectType, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::historyconnectwidget)
{
    ui->setupUi(this);
     ui->tableWidget_history->horizontalHeader()->setVisible(true);
     ui->tableWidget_history->verticalHeader()->setVisible(false);

     //创建20个连接
     for (int i=0; i<10; i++) {
         QToolButton* button = new QToolButton();
         button->setIcon(QIcon((":lib/setting.png")));
         button->setStyleSheet("QToolButton {\
                               color: rgb(255, 255, 255);\
                               background-color: rgba(0, 214, 103, 0);\
                               border-radius: 5px;\
                           }\
                           QToolButton::menu-indicator { \
                               image: None;\
                           }\
                           QToolButton:hover {\
                               color: rgb(255, 255, 255);\
                               background-color: rgba(0, 214, 103, 0);\
                           }");
         button->setFixedSize(25,25);
         ui->tableWidget_history->setCellWidget(i, 5, button);
     }
    ui->tableWidget_history->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents); //列自动缩放
    ui->tableWidget_history->setColumnWidth(5, 20);
    //ui->tableWidget_history->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

}

historyconnectwidget::~historyconnectwidget()
{
    delete ui;
}

void historyconnectwidget::on_tableWidget_history_itemDoubleClicked(QTableWidgetItem *item)
{
    int currentRow = ui->tableWidget_history->currentIndex().row();
    qDebug() << ui->tableWidget_history->item(currentRow,0)->text();
    qDebug() << ui->tableWidget_history->item(currentRow,1)->text();
    qDebug() << ui->tableWidget_history->item(currentRow,2)->text();
}
