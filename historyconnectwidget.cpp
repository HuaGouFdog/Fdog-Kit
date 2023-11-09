#pragma execution_character_set("utf-8")
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
     //ui->tableWidget_history->horizontalHeader()->setVisible(true);
     //ui->tableWidget_history->verticalHeader()->setVisible(false);

    //设置初始表格行列都为0
        ui->tableWidget_history->setRowCount(20); //设置行数为20
        ui->tableWidget_history->setColumnCount(4); //设置列数为5
        ui->tableWidget_history->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents); //列自动缩放
        ui->tableWidget_history->setHorizontalHeaderLabels(QStringList() << "          名称          "
                                                           << "          主机          "
                                                           << "          分组          "
                                                           << "      备注      ");
        ui->tableWidget_history->horizontalHeader()->setDefaultAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        for (int row = 0; row < 20; ++row) {
            for (int col = 0; col < 4; ++col) {
                QString headerData;
                if (col == 0) {
                    QLabel * label = new QLabel();
                    label->setFixedSize(30,30);
                    QPixmap icon(":/lib/diann3.png");
                     QPixmap scaledIcon = icon.scaled(16, 16, Qt::KeepAspectRatio);
                    label->setPixmap(scaledIcon);
                    headerData = QString("终端连接%1").arg(row);
                    label->setStyleSheet("background-color: rgba(0, 214, 103, 0);");
                ui->tableWidget_history->setCellWidget(row, 0, label);
                } else if (col == 1) {
                    headerData = QString("172.16.8.%1").arg(row);
                } else if (col == 2) {
                    headerData = QString("默认%1").arg(row);
                } else if (col == 3) {
                    headerData = QString("默认%1").arg(row);
                } /*else if (col == 4) {
                    headerData = QString("");

                } else if (col == 5) {
                    headerData = QString("");
                    QToolButton* button = new QToolButton();
                    button->setText("连接");
                    //button->setIcon(QIcon((":lib/setting.png")));
                    button->setStyleSheet("QToolButton {\
                                          color: rgb(255, 255, 255);\
                                          background-color: rgb(7, 143, 255);\
                                          border-radius: 5px;\
                                      }\
                                      QToolButton::menu-indicator { \
                                          image: None;\
                                      }\
                                      QToolButton:hover {\
                                          color: rgb(255, 255, 255);\
                                          background-color: rgb(7, 143, 255);\
                                      }");
                    button->setFixedSize(50,20);
                    ui->tableWidget_history->setCellWidget(row, 5, button);
                }*/
                QTableWidgetItem *item = new QTableWidgetItem(headerData);
                ui->tableWidget_history->setItem(row, col, item);
                item->setTextAlignment(Qt::AlignCenter); // 设置对齐方式为居中
            }
        }

        //int count =0;
        //for(int i = 1;i<20;i++) {

//            //注意setRowCount里面的函数不是追加，而是总数，很多人最开始都把这个函数以为是总数，造成程序经常崩溃
//            ui->tableWidget_history->setRowCount(ui->tableWidget_history->rowCount()+1);
//            for(int j = 1;j<ui->tableWidget_history->columnCount(); j++)
//            {
//                if(i == 1)
//                {
//                    ui->tableWidget_history->setColumnCount(ui->tableWidget_history->columnCount()+1);
//                    range = worksheet->querySubObject("Cells(int,int)",i,j); //获取cell的值
//                    strVal = range->dynamicCall("Value2()").toString();
//                    header<<strVal;
//                    //设置表格头
//                }
//                else
//                {
//                    probar->setValue(++count);
//                    range = worksheet->querySubObject("Cells(int,int)",i,j); //获取cell的值
//                    strVal = range->dynamicCall("Value2()").toString();
//                    ui->tableWidget->setItem(i-2,j-1,new QTableWidgetItem(strVal));
//                }
//            }
//            if(i == 1)
//            {
//                ui->tableWidget->setHorizontalHeaderLabels(header);
//            }
       // }
//        ui->tableWidget->setRowCount(ui->tableWidget->rowCount()-1);
//        }



     //创建20个连接
     //for (int i=0; i<10; i++) {
         //QToolButton* button = new QToolButton();
         //button->setIcon(QIcon((":lib/setting.png")));
//         button->setStyleSheet("QToolButton {\
//                               color: rgb(255, 255, 255);\
//                               background-color: rgba(0, 214, 103, 0);\
//                               border-radius: 5px;\
//                           }\
//                           QToolButton::menu-indicator { \
//                               image: None;\
//                           }\
//                           QToolButton:hover {\
//                               color: rgb(255, 255, 255);\
//                               background-color: rgba(0, 214, 103, 0);\
//                           }");
         //button->setFixedSize(25,25);
         //ui->tableWidget_history->setCellWidget(i, 4, button);
     //}
    //ui->tableWidget_history->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents); //列自动缩放
    //ui->tableWidget_history->setColumnWidth(5, 20);
    //ui->tableWidget_history->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //ui->tableWidget_history->horizontalHeader()->setDefaultAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

//    for (int row = 0; row < ui->tableWidget_history->rowCount(); ++row) {
//        QTableWidgetItem *item = ui->tableWidget_history->item(row, 1); // 获取第二列的项
//        item->setTextAlignment(Qt::AlignRight); // 设置对齐方式为居中
//    }

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
