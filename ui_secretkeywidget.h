/********************************************************************************
** Form generated from reading UI file 'secretkeywidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECRETKEYWIDGET_H
#define UI_SECRETKEYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_secretkeywidget
{
public:
    QTableWidget *tableWidget;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;
    QToolButton *toolButton_4;
    QToolButton *toolButton_5;

    void setupUi(QWidget *secretkeywidget)
    {
        if (secretkeywidget->objectName().isEmpty())
            secretkeywidget->setObjectName(QStringLiteral("secretkeywidget"));
        secretkeywidget->resize(429, 286);
        secretkeywidget->setStyleSheet(QLatin1String("background-color: rgb(30, 45, 54);\n"
"color: rgb(255, 255, 255);"));
        tableWidget = new QTableWidget(secretkeywidget);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        if (tableWidget->rowCount() < 5)
            tableWidget->setRowCount(5);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem7);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(20, 20, 301, 211));
        QFont font;
        font.setFamily(QStringLiteral("OPPOSans B"));
        font.setPointSize(10);
        font.setStyleStrategy(QFont::PreferAntialias);
        tableWidget->setFont(font);
        tableWidget->setStyleSheet(QLatin1String("QTableWidget::item:hover{\n"
"	background-color:rgb(92,188,227,200)\n"
"}\n"
"QTableWidget::item:selected{background-color:#1B89A1}\n"
"QHeaderView::section,QTableCornerButton:section{\n"
"    padding:3px; \n"
"    margin:0px; \n"
"    color:#DCDCDC;  \n"
"    border:1px solid #242424;\n"
"    border-left-width:0px; \n"
"    border-right-width:1px; \n"
"    border-top-width:0px; \n"
"    border-bottom-width:1px;\n"
"	background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #646464,stop:1 #525252); \n"
"}\n"
"QTableWidget{\n"
"	border:none;\n"
"	background-color: rgb(30, 45, 54);\n"
"	color: rgb(255, 255, 255);\n"
"}"));
        tableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget->verticalHeader()->setStretchLastSection(false);
        toolButton = new QToolButton(secretkeywidget);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(340, 40, 70, 30));
        toolButton->setMinimumSize(QSize(70, 30));
        toolButton->setMaximumSize(QSize(70, 30));
        toolButton->setFont(font);
        toolButton->setStyleSheet(QLatin1String("QToolButton {\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(255, 95, 95);\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QToolButton::menu-indicator { \n"
"	image: None;\n"
"}\n"
"\n"
" \n"
"QToolButton:hover {\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(255, 95, 95);\n"
"}"));
        toolButton_2 = new QToolButton(secretkeywidget);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        toolButton_2->setGeometry(QRect(340, 90, 70, 30));
        toolButton_2->setMinimumSize(QSize(70, 30));
        toolButton_2->setMaximumSize(QSize(70, 30));
        toolButton_2->setFont(font);
        toolButton_2->setStyleSheet(QLatin1String("QToolButton {\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(255, 95, 95);\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QToolButton::menu-indicator { \n"
"	image: None;\n"
"}\n"
"\n"
" \n"
"QToolButton:hover {\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(255, 95, 95);\n"
"}"));
        toolButton_3 = new QToolButton(secretkeywidget);
        toolButton_3->setObjectName(QStringLiteral("toolButton_3"));
        toolButton_3->setGeometry(QRect(340, 140, 70, 30));
        toolButton_3->setMinimumSize(QSize(70, 30));
        toolButton_3->setMaximumSize(QSize(70, 30));
        toolButton_3->setFont(font);
        toolButton_3->setStyleSheet(QLatin1String("QToolButton {\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(255, 95, 95);\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QToolButton::menu-indicator { \n"
"	image: None;\n"
"}\n"
"\n"
" \n"
"QToolButton:hover {\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(255, 95, 95);\n"
"}"));
        toolButton_4 = new QToolButton(secretkeywidget);
        toolButton_4->setObjectName(QStringLiteral("toolButton_4"));
        toolButton_4->setGeometry(QRect(250, 240, 70, 30));
        toolButton_4->setMinimumSize(QSize(70, 30));
        toolButton_4->setMaximumSize(QSize(70, 30));
        toolButton_4->setFont(font);
        toolButton_4->setStyleSheet(QLatin1String("QToolButton {\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(255, 95, 95);\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QToolButton::menu-indicator { \n"
"	image: None;\n"
"}\n"
"\n"
" \n"
"QToolButton:hover {\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(255, 95, 95);\n"
"}"));
        toolButton_5 = new QToolButton(secretkeywidget);
        toolButton_5->setObjectName(QStringLiteral("toolButton_5"));
        toolButton_5->setGeometry(QRect(340, 240, 70, 30));
        toolButton_5->setMinimumSize(QSize(70, 30));
        toolButton_5->setMaximumSize(QSize(70, 30));
        toolButton_5->setFont(font);
        toolButton_5->setStyleSheet(QLatin1String("QToolButton {\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(255, 95, 95);\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QToolButton::menu-indicator { \n"
"	image: None;\n"
"}\n"
"\n"
" \n"
"QToolButton:hover {\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(255, 95, 95);\n"
"}"));

        retranslateUi(secretkeywidget);

        QMetaObject::connectSlotsByName(secretkeywidget);
    } // setupUi

    void retranslateUi(QWidget *secretkeywidget)
    {
        secretkeywidget->setWindowTitle(QApplication::translate("secretkeywidget", "Form", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("secretkeywidget", "\346\230\265\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("secretkeywidget", "\347\261\273\345\236\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("secretkeywidget", "\351\225\277\345\272\246", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("secretkeywidget", "\346\226\260\345\273\272\350\241\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem4->setText(QApplication::translate("secretkeywidget", "\346\226\260\345\273\272\350\241\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem5->setText(QApplication::translate("secretkeywidget", "\346\226\260\345\273\272\350\241\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem6->setText(QApplication::translate("secretkeywidget", "\346\226\260\345\273\272\350\241\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem7->setText(QApplication::translate("secretkeywidget", "\346\226\260\345\273\272\350\241\214", nullptr));
        toolButton->setText(QApplication::translate("secretkeywidget", "\345\257\274\345\205\245", nullptr));
        toolButton_2->setText(QApplication::translate("secretkeywidget", "\347\274\226\350\276\221", nullptr));
        toolButton_3->setText(QApplication::translate("secretkeywidget", "\345\210\240\351\231\244", nullptr));
        toolButton_4->setText(QApplication::translate("secretkeywidget", "\347\241\256\345\256\232", nullptr));
        toolButton_5->setText(QApplication::translate("secretkeywidget", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class secretkeywidget: public Ui_secretkeywidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECRETKEYWIDGET_H
