#pragma execution_character_set("utf-8")
#include "qss.h"
#include "ui_qss.h"
#include<QMenu>
qss::qss(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::qss)
{
    ui->setupUi(this);
    QMenu * menu2 = new QMenu;
    menu2->addAction("演示1");
    menu2->addAction("演示2");
    ui->toolButton_test_2->setMenu(menu2);

    QMenu * menu3 = new QMenu;
    menu3->addAction("演示1");
    menu3->addAction("演示2");
    ui->toolButton_test_3->setMenu(menu3);

    QMenu * menu4 = new QMenu;
    menu4->addAction("演示1");
    menu4->addAction("演示2");
    ui->toolButton_test_4->setMenu(menu4);
}

qss::~qss()
{
    delete ui;
}

void qss::on_listWidget_status_currentRowChanged(int currentRow)
{
    ui->stackedWidget_status->setCurrentIndex(currentRow);
}

void qss::on_listWidget_module_currentRowChanged(int currentRow)
{
    ui->stackedWidget_module->setCurrentIndex(currentRow);
}

void qss::on_toolButton_button_pre1_clicked()
{
    ui->toolButton_test_1->setStyleSheet("QToolButton {\
                                             color: rgb(255, 255, 255);\
                                             background-color: rgb(67, 67, 67);\
                                             border-radius: 5px;\
                                         }\
                                         QToolButton:hover {\
                                             color: rgb(240, 240, 240);\
                                             background-color: rgb(67, 67, 67);\
                                         }\
                                         QToolButton:pressed {\
                                             color: rgb(191, 191, 191);\
                                             background-color: rgb(67, 67, 67);\
                                         }");
    ui->textEdit_button->clear();
    ui->textEdit_button->append(ui->toolButton_test_1->styleSheet());
}

void qss::on_toolButton_button_pre2_clicked()
{

    ui->toolButton_test_1->setStyleSheet("QToolButton {\
                                         color: rgb(255, 255, 255);\
                                         background-color: rgb(250, 118, 0);\
                                         border-radius: 5px;\
                                     }\
                                     QToolButton:hover {\
                                         color: rgb(255, 255, 255);\
                                         background-color: rgb(250, 118, 0);\
                                     }\
                                     QToolButton:pressed {\
                                         padding-left:2px; \
                                         padding-top:2px; \
                                         color: rgb(191, 191, 191);\
                                         background-color: rgb(250, 118, 0);\
                                     }");
ui->textEdit_button->clear();
ui->textEdit_button->append(ui->toolButton_test_1->styleSheet());
}

void qss::on_toolButton_button_pre3_clicked()
{
    ui->toolButton_test_1->setStyleSheet("QToolButton {\
                                         color: rgb(255, 255, 255);\
                                         background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:0.733682, stop:0 rgba(30, 45, 54, 157), stop:1 rgba(37, 56, 67, 255));\
                                         border-radius: 5px;\
                                     }\
                                     QToolButton:hover {\
                                         color: rgb(191, 191, 191);\
                                         background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:0.733682, stop:0 rgba(30, 45, 54, 180), stop:1 rgba(37, 56, 67, 255));\
                                     }\
                                     QToolButton:pressed {\
                                         padding-left:2px; \
                                         padding-top:2px; \
                                         color: rgb(191, 191, 191);\
                                         background-color: rgb(67, 67, 67);\
                                     }");
    ui->textEdit_button->clear();
    ui->textEdit_button->append(ui->toolButton_test_1->styleSheet());
}

void qss::on_toolButton_button_pre4_clicked()
{
    ui->toolButton_test_1->setStyleSheet("QToolButton {\
                                         color: rgb(255, 255, 255);\
                                         background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:0.733682, stop:0 rgba(30, 45, 54, 157), stop:1 rgba(37, 56, 67, 255));\
                                         border-top-left-radius: 10px;\
                                         border-top-right-radius: 10px;\
                                     }\
                                     QToolButton:hover {\
                                         color: rgb(191, 191, 191);\
                                         background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:0.733682, stop:0 rgba(30, 45, 54, 180), stop:1 rgba(37, 56, 67, 255));\
                                     }\
                                     QToolButton:pressed {\
                                         padding-left:2px; \
                                         padding-top:2px; \
                                         color: rgb(191, 191, 191);\
                                         background-color: rgb(67, 67, 67);\
                                     }");
    ui->textEdit_button->clear();
    ui->textEdit_button->append(ui->toolButton_test_1->styleSheet());
}

void qss::on_pushButton_save_clicked()
{
    ui->toolButton_test_1->setStyleSheet(ui->textEdit_button->toPlainText());
}

void qss::on_listWidget_moduleList_currentRowChanged(int currentRow)
{
    ui->stackedWidget->setCurrentIndex(currentRow);
}
