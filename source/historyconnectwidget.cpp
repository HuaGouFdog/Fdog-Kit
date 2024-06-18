#pragma execution_character_set("utf-8")
#include "historyconnectwidget.h"
#include "ui_historyconnectwidget.h"
#include <QDebug>
#include <QToolButton>
#include <QIcon>
#include "utils.h"
historyconnectwidget::historyconnectwidget(int8_t connectType, QVector<connnectInfoStruct> cInfoStructList, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::historyconnectwidget)
{
    ui->setupUi(this);
    setSupportStretch(this, true);
     //ui->tableWidget_history->horizontalHeader()->setVisible(true);
     //ui->tableWidget_history->verticalHeader()->setVisible(false);

    //设置初始表格行列都为0
        ui->tableWidget_history->setRowCount(cInfoStructList.length()); //设置行数为20
        ui->tableWidget_history->setColumnCount(7); //设置列数为5
        ui->tableWidget_history->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        //ui->tableWidget_history->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents); //列自动缩放
        ui->tableWidget_history->setHorizontalHeaderLabels(QStringList() << "                              名称                              "
                                                           << "                              主机                              "
                                                           << "                             用户名                             "
                                                           << "                            最近连接                            " 
                                                           << "         分组           "
                                                           << "         备注           "
                                                           << "         操作           " );
        ui->tableWidget_history->horizontalHeader()->setDefaultAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        
        

        for (int row = 0; row < cInfoStructList.length(); ++row) {
            for (int col = 0; col < 7; ++col) {
                QString headerData;
                if (col == 0) {
                    QLabel * label = new QLabel();
                    label->setFixedSize(50,30);
                    QPixmap icon(":/lib/diann3.png");
                     QPixmap scaledIcon = icon.scaled(50, 16, Qt::KeepAspectRatio);
                    label->setPixmap(scaledIcon);
                    headerData = cInfoStructList.at(row).name;
                    label->setStyleSheet("background-color: rgba(0, 214, 103, 0);");
                ui->tableWidget_history->setCellWidget(row, 0, label);
                } else if (col == 1) {
                    headerData = cInfoStructList.at(row).host;
                } else if (col == 2) {
                    headerData = cInfoStructList.at(row).userName;
                } else if (col == 3) {
                    qDebug() << "nearest_connection = " << cInfoStructList.at(row).nearest_connection;
                    headerData = cInfoStructList.at(row).nearest_connection;
                } else if (col == 4) {
                    headerData = cInfoStructList.at(row).group;
                } else if (col == 5) {
                    headerData = cInfoStructList.at(row).remark;
                } else if (col == 6) {
                    QWidget *widget;
                    QHBoxLayout *hLayout;
                    hLayout = new QHBoxLayout();  
                    widget = new QWidget(ui->tableWidget_history);  
//                    QToolButton* button_connect = new QToolButton();
//                    button_connect->setText("连接");
//                    button_connect->setFixedSize(50,20);
//                    hLayout->addWidget(button_connect);
//                    hLayout->setAlignment(button_connect, Qt::AlignCenter);
                    QSpacerItem * sparcer_item = new QSpacerItem(0,160,QSizePolicy::Expanding,QSizePolicy::Minimum);
                    hLayout->addItem(sparcer_item);
                    QToolButton* button_edit = new QToolButton();
                    button_edit->setText("修改");
                    button_edit->setFixedSize(50,20);
                    hLayout->addWidget(button_edit);
                    hLayout->setAlignment(button_edit, Qt::AlignCenter);

                    QToolButton* button_delete = new QToolButton();
                    button_delete->setText("删除");
                    button_delete->setFixedSize(50,20);
                    hLayout->addWidget(button_delete);
                    hLayout->setAlignment(button_delete, Qt::AlignCenter);

                    QSpacerItem * sparcer_item2 = new QSpacerItem(0,160,QSizePolicy::Expanding,QSizePolicy::Minimum);
                    hLayout->addItem(sparcer_item2);

                    hLayout->setMargin(0);

                    widget->setLayout(hLayout);  
                    //widget->setFixedSize(120,30);
                    ui->tableWidget_history->setCellWidget(row, 6, widget);
                } /*else if (col == 5) {
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
    qDebug() << "双击1";
    connnectInfoStruct cInfo;
    cInfo.name = ui->tableWidget_history->item(currentRow, 0)->text();
    cInfo.host = ui->tableWidget_history->item(currentRow, 1)->text();
    cInfo.userName = ui->tableWidget_history->item(currentRow, 2)->text();
    cInfo.port = "22";
    //cInfo.password = ui->tableWidget_history->item(currentRow, 2)->text();
    //cInfo.group = ui->tableWidget_history->item(currentRow, 3)->text();
    //cInfo.remark = ui->tableWidget_history->item(currentRow, 4)->text();
    //cInfo.nearest_connection = ui->tableWidget_history->item(currentRow, 5)->text();
    qDebug() << "双击2";
    emit send_fastConnection(cInfo);
    // qDebug() << ui->tableWidget_history->item(currentRow,0)->text();
    // qDebug() << ui->tableWidget_history->item(currentRow,1)->text();
    // qDebug() << ui->tableWidget_history->item(currentRow,2)->text();
}

void historyconnectwidget::on_tableWidget_history_currentItemChanged(QTableWidgetItem *current, QTableWidgetItem *previous)
{
    qDebug() << "单击";
}
