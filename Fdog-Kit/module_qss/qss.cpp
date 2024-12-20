#pragma execution_character_set("utf-8")
#include "qss.h"
#include "ui_qss.h"
#include<QMenu>
#include "module_utils/utils.h"
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

    menu_test = new QMenu(ui->toolButton);
    menu_test->addAction("演示1");
    menu_test->addAction("演示2");
    menu_test->addAction("演示3");
    menu_test->addAction("演示4");
    ui->toolButton->setMenu(menu_test);

    menu_test->setWindowFlags(menu_test->windowFlags()  | Qt::FramelessWindowHint | Qt::NoDropShadowWindowHint);
    menu_test->setAttribute(Qt::WA_TranslucentBackground);

    setSupportStretch(this, true);
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

void qss::on_listWidget_currentRowChanged(int currentRow)
{
    ui->stackedWidget_select->setCurrentIndex(currentRow);
}

void qss::on_listWidget_qss_currentRowChanged(int currentRow)
{
    ui->stackedWidget_qss->setCurrentIndex(currentRow);
}

void qss::on_listWidget_status_2_currentRowChanged(int currentRow)
{
    ui->stackedWidget_status_2->setCurrentIndex(currentRow);
}

void qss::on_toolButton_table_pre1_clicked()
{
    ui->label->setStyleSheet("QLabel {\
                                             color: rgb(255, 255, 255);\
                                             background-color: rgb(67, 67, 67);\
                                             border-radius: 5px;\
                                         }\
                                         QLabel:hover {\
                                             color: rgb(240, 240, 240);\
                                             background-color: rgb(67, 67, 67);\
                                         }");
    ui->textEdit_lable->clear();
    ui->textEdit_lable->append(ui->label->styleSheet());
}

void qss::on_pushButton_save_2_clicked()
{
    ui->label->setStyleSheet(ui->textEdit_lable->toPlainText());
}

void qss::on_toolButton_table_pre2_clicked()
{
    ui->label->setStyleSheet("QLabel {\
                                         color: rgb(255, 255, 255);\
                                         background-color: rgb(250, 118, 0);\
                                         border-radius: 5px;\
                                     }\
                                     QLabel:hover {\
                                         color: rgb(255, 255, 255);\
                                         background-color: rgb(250, 118, 0);\
                                     }");
    ui->textEdit_lable->clear();
    ui->textEdit_lable->append(ui->label->styleSheet());
}

void qss::on_toolButton_table_pre3_clicked()
{
    ui->label->setStyleSheet("QLabel {\
                                         color: rgb(255, 255, 255);\
                                         background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:0.733682, stop:0 rgba(30, 45, 54, 157), stop:1 rgba(37, 56, 67, 255));\
                                         border-radius: 5px;\
                                     }\
                                     QLabel:hover {\
                                         color: rgb(191, 191, 191);\
                                         background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:0.733682, stop:0 rgba(30, 45, 54, 180), stop:1 rgba(37, 56, 67, 255));\
                                     }");
ui->textEdit_lable->clear();
ui->textEdit_lable->append(ui->label->styleSheet());
}

void qss::on_toolButton_table_pre4_clicked()
{
    ui->label->setStyleSheet("QLabel {\
                                         color: rgb(255, 255, 255);\
                                         background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:0.733682, stop:0 rgba(30, 45, 54, 157), stop:1 rgba(37, 56, 67, 255));\
                                         border-top-left-radius: 10px;\
                                         border-top-right-radius: 10px;\
                                     }\
                                     QLabel:hover {\
                                         color: rgb(191, 191, 191);\
                                         background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:0.733682, stop:0 rgba(30, 45, 54, 180), stop:1 rgba(37, 56, 67, 255));\
                                     }");
ui->textEdit_lable->clear();
ui->textEdit_lable->append(ui->label->styleSheet());
}

void qss::on_toolButton_slider_pre1_clicked()
{
    ui->horizontalSlider->setStyleSheet("    QSlider::groove:horizontal {\
                                        border: 0px solid #bbb;\
                                        }\
                                        QSlider::sub-page:horizontal {\
                                        background: #1e2d36;\
                                        margin-top:7px;\
                                        margin-bottom:7px;\
                                        }\
                                        QSlider::add-page:horizontal {\
                                        background: rgb(255,255, 255);\
                                        border: 0px solid #777;\
                                        margin-top:7px;\
                                        margin-bottom:7px;\
                                        }\
                                        QSlider::handle:horizontal {\
                                        background: #19252d;\
                                        border: 0px solid rgba(102,102,102,102);\
                                        width: 10px;\
                                        }");

    ui->textEdit_slider->clear();
    ui->textEdit_slider->append(ui->horizontalSlider->styleSheet());
}

void qss::on_toolButton_slider_pre2_clicked()
{
    ui->horizontalSlider->setStyleSheet("QSlider::groove:horizontal {\
                                        border: 0px solid #bbb;\
                                      }\
                                      QSlider::sub-page:horizontal {\
                                        background: rgb(255,255,0);\
                                        margin-top: 7px;\
                                        margin-bottom: 7px;\
                                        border-radius: 2px; \
                                      }\
                                      QSlider::add-page:horizontal {\
                                      background-color: rgb(255, 255, 255);\
                                        border: 0px solid #777; \
                                        border-radius: 2px; \
                                        margin-top: 7px; \
                                        margin-bottom: 7px; \
                                      }\
                                      QSlider::handle:horizontal { \
                                        background: rgb(255,255,255); \
                                        border: 1px solid rgba(102,102,102,102); \
                                        width: 8px; \
                                        height: 8px;\
                                        border-radius: 5px; \
                                        margin-top: 2px; \
                                        margin-bottom: 2px; \
                                      }");
     ui->textEdit_slider->clear();
     ui->textEdit_slider->append(ui->horizontalSlider->styleSheet());
}

void qss::on_toolButton_slider_pre3_clicked()
{
    ui->horizontalSlider->setStyleSheet("QSlider::groove:horizontal {\
                                        border: 0px solid #bbb;\
                                        }\
                                        QSlider::sub-page:horizontal {\
                                        background-color: qlineargradient(spread:pad, x1:1, y1:0.114, x2:0.301091, y2:0.113, stop:0.0511364 rgba(255, 58, 215, 255), stop:1 rgba(71, 112, 255, 255));\
                                        border-radius: 5px;\
                                        margin-top:5px;\
                                        margin-bottom:5px;\
                                        }\
                                        QSlider::add-page:horizontal {\
                                        background-color: rgb(255, 255, 255);\
                                        border: 0px solid #777;\
                                        border-radius: 5px;\
                                        margin-top:5px;\
                                        margin-bottom:5px;\
                                        }\
                                        QSlider::handle:horizontal {\
                                        background-color: qlineargradient(spread:pad, x1:1, y1:0.114, x2:0.301091, y2:0.113, stop:0.0511364 rgba(255, 58, 215, 255), stop:1 rgba(71, 112, 255, 255));\
                                        border: 0px solid rgba(102,102,102,102);\
                                        border-radius: 10px;\
                                        width: 22px;\
                                        }");
    ui->textEdit_slider->clear();
    ui->textEdit_slider->append(ui->horizontalSlider->styleSheet());
}

void qss::on_toolButton_slider_pre4_clicked()
{
    ui->horizontalSlider->setStyleSheet("QSlider::groove:horizontal {\
                                        border: 0px solid #bbb;\
                                      }\
                                      QSlider::sub-page:horizontal {\
                                      background-color: rgb(0, 170, 255);\
                                        margin-top: 7px;\
                                        margin-bottom: 7px;\
                                        border-radius: 2px; \
                                      }\
                                      QSlider::add-page:horizontal {\
                                      background-color: rgb(255, 255, 255);\
                                        border: 0px solid #777; \
                                        border-radius: 2px; \
                                        margin-top: 7px; \
                                        margin-bottom: 7px; \
                                      }\
                                      QSlider::handle:horizontal { \
                                        background: rgb(255,255,255); \
                                        border: 2px solid rgb(70, 166, 255);\
                                        width: 12px; \
                                        height: 10px; \
                                        border-radius: 7px; \
                                        margin-top: 3px; \
                                        margin-bottom: 3px; \
                                      }");
    ui->textEdit_slider->clear();
    ui->textEdit_slider->append(ui->horizontalSlider->styleSheet());
}

void qss::on_pushButton_save_3_clicked()
{
    ui->horizontalSlider->setStyleSheet(ui->textEdit_slider->toPlainText());
}

void qss::on_toolButton_customContextMenuRequested(const QPoint &pos)
{

}

void qss::on_toolButton_menu_pre1_clicked()
{
    menu_test->setStyleSheet("QMenu {\
                             background-color:rgb(253,253,254);\
                             /*padding:5px;*/\
                             padding: 3px 0px 3px 0px;\
                             border-radius:6px;\
                             border:2px solid rgb(108, 117, 125, 65); \
                             }\
                             QMenu::item {\
                                 font-size: 10pt;\
                                 font: 10pt \"OPPOSans B\";\
                                 color: rgb(63, 63, 63);\
                                 background-color:rgb(253,253,254);\
                                 padding: 5px 25px 5px 25px;\
                                 /*margin: 2px 2px 2px 2px;*/\
                             }\
                             QMenu::item:selected {\
                                color: rgb(255, 255, 255);\
                                background-color: rgb(0, 170, 255);\
                                border-radius:6px;\
                             }\
                             QMenu::icon:checked {\
                                 background: rgb(253,253,254);\
                                 position: absolute;\
                                 top: 1px;\
                                 right: 1px;\
                                 bottom: 1px;\
                                 left: 1px;\
                             }\
                             QMenu::icon:checked:selected {\
                                 background-color : rgb(236,236,237);\
                                 background-image: url(:/space_selected.png);\
                             }\
                             QMenu::separator {\
                                 height: 2px;\
                                 background: rgb(235,235,236);\
                                 /*margin-left: 10px;*/\
                                 /*margin-right: 10px;*/\
                             }");
    ui->textEdit_menu->clear();
    ui->textEdit_menu->append(menu_test->styleSheet());
}

void qss::on_toolButton_menu_pre2_clicked()
{
    menu_test->setStyleSheet("QMenu {    \
                             background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\
                             stop:0 rgba(255, 255, 255, 240),\
                             stop:0.2 rgba(255, 255, 255, 200),\
                             stop:0.6 rgba(255, 255, 255, 160),\
                             stop:1 rgba(255, 255, 255, 120));\
                             qproperty-effect: blur(30px);\
                             border-radius: 5px;\
                             padding:4px;\
                             margin:4px; \
                         } \
                         QMenu::item:selected {\
                             color: rgb(255, 255, 255);\
                             background-color: rgb(0, 170, 255);\
                             border-radius: 3px;\
                         }\
                        ");
     ui->textEdit_menu->clear();
     ui->textEdit_menu->append(menu_test->styleSheet());
}

void qss::on_toolButton_menu_pre3_clicked()
{

}

void qss::on_toolButton_menu_pre4_clicked()
{

}

void qss::on_pushButton_save_4_clicked()
{
    menu_test->setStyleSheet(ui->textEdit_menu->toPlainText());
}

void qss::on_listWidget_status_3_currentRowChanged(int currentRow)
{
    ui->stackedWidget_status_3->setCurrentIndex(currentRow);
}

void qss::on_listWidget_module_3_currentRowChanged(int currentRow)
{
    ui->stackedWidget_module_3->setCurrentIndex(currentRow);
}
