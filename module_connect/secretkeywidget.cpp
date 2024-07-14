#pragma execution_character_set("utf-8")
#include "secretkeywidget.h"
#include "ui_secretkeywidget.h"


secretkeywidget::secretkeywidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::secretkeywidget)
{
    ui->setupUi(this);
    setWindowFlags(Qt::WindowCloseButtonHint);
    ui->tableWidget->horizontalHeader()->setVisible(true);
    ui->tableWidget->verticalHeader()->setVisible(false);

   //ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents); //列自动缩放
   //ui->tableWidget->setColumnWidth(5, 20);
}

secretkeywidget::~secretkeywidget()
{
    delete ui;
}

void secretkeywidget::on_toolButton_input_clicked()
{
    kwidget = new keywidget();
    connect(kwidget,SIGNAL(send_addsshKey(sshKeyStruct &)),this,SLOT(rece_addsshKey(sshKeyStruct &)));
    kwidget->show();
}

void secretkeywidget::rece_addsshKey(sshKeyStruct &skeyStruct)
{
     //添加
     ui->tableWidget->setRowCount(ui->tableWidget->rowCount() + 1);
     ui->tableWidget->setColumnCount(3); //设置列数为5
     ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
     //ui->tableWidget_history->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents); //列自动缩放
     ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "名称" << "类型" << "长度");
     ui->tableWidget->horizontalHeader()->setDefaultAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

     QTableWidgetItem *item1 = new QTableWidgetItem(skeyStruct.name);
     ui->tableWidget->setItem(0, 0, item1);
     item1->setTextAlignment(Qt::AlignCenter); // 设置对齐方式为居中
     int index = skeyStruct.path.lastIndexOf("/");
     QString fileName = skeyStruct.path.mid(index + 1);
     QTableWidgetItem *item2 = new QTableWidgetItem(fileName);
     ui->tableWidget->setItem(0, 1, item2);
     item2->setTextAlignment(Qt::AlignCenter); // 设置对齐方式为居中

     QTableWidgetItem *item3 = new QTableWidgetItem(skeyStruct.password);
     ui->tableWidget->setItem(0, 2, item3);
     item3->setTextAlignment(Qt::AlignCenter); // 设置对齐方式为居中


//     for (int row = 0; row < cInfoStructList.length(); ++row) {
//         for (int col = 0; col < 7; ++col) {
//             QString headerData;
//             if (col == 0) {
//                 QLabel * label = new QLabel();
//                 label->setFixedSize(50,30);
//                 QPixmap icon(":/lib/diann3.png");
//                  QPixmap scaledIcon = icon.scaled(50, 16, Qt::KeepAspectRatio);
//                 label->setPixmap(scaledIcon);
//                 headerData = cInfoStructList.at(row).name;
//                 label->setStyleSheet("background-color: rgba(0, 214, 103, 0);");
//             ui->tableWidget_history->setCellWidget(row, 0, label);
//             } else if (col == 1) {
//                 headerData = cInfoStructList.at(row).host;
//             } else if (col == 2) {
//                 headerData = cInfoStructList.at(row).userName;
//             }

//             QTableWidgetItem *item = new QTableWidgetItem(headerData);
//             ui->tableWidget_history->setItem(row, col, item);
//             item->setTextAlignment(Qt::AlignCenter); // 设置对齐方式为居中
//         }
//     }


}

void secretkeywidget::on_toolButton_cancel_clicked()
{
    this->close();
}

void secretkeywidget::on_toolButton_ok_clicked()
{
    //确定
    this->close();
}
