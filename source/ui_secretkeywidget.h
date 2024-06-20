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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_secretkeywidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QToolButton *toolButton_cancel;
    QToolButton *toolButton_ok;
    QTableWidget *tableWidget;
    QToolButton *toolButton_edit;
    QToolButton *toolButton_input;
    QToolButton *toolButton_delete;

    void setupUi(QWidget *secretkeywidget)
    {
        if (secretkeywidget->objectName().isEmpty())
            secretkeywidget->setObjectName(QStringLiteral("secretkeywidget"));
        secretkeywidget->resize(418, 281);
        QIcon icon;
        icon.addFile(QStringLiteral(":/lib/wicon_46.png"), QSize(), QIcon::Normal, QIcon::Off);
        secretkeywidget->setWindowIcon(icon);
        secretkeywidget->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(secretkeywidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(secretkeywidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setStyleSheet(QLatin1String("#widget{\n"
"border-image: url(:/lib/back1.png);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        toolButton_cancel = new QToolButton(widget);
        toolButton_cancel->setObjectName(QStringLiteral("toolButton_cancel"));
        toolButton_cancel->setGeometry(QRect(330, 230, 70, 30));
        toolButton_cancel->setMinimumSize(QSize(70, 30));
        toolButton_cancel->setMaximumSize(QSize(70, 30));
        QFont font;
        font.setFamily(QStringLiteral("OPPOSans B"));
        font.setPointSize(10);
        font.setStyleStrategy(QFont::PreferAntialias);
        toolButton_cancel->setFont(font);
        toolButton_cancel->setStyleSheet(QLatin1String("QToolButton {\n"
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
        toolButton_ok = new QToolButton(widget);
        toolButton_ok->setObjectName(QStringLiteral("toolButton_ok"));
        toolButton_ok->setGeometry(QRect(240, 230, 70, 30));
        toolButton_ok->setMinimumSize(QSize(70, 30));
        toolButton_ok->setMaximumSize(QSize(70, 30));
        toolButton_ok->setFont(font);
        toolButton_ok->setStyleSheet(QLatin1String("QToolButton {\n"
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
        tableWidget = new QTableWidget(widget);
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
        tableWidget->setGeometry(QRect(10, 10, 301, 201));
        tableWidget->setFont(font);
        tableWidget->setFocusPolicy(Qt::NoFocus);
        tableWidget->setStyleSheet(QString::fromUtf8("QTableWidget::item:hover{\n"
"	background-color:rgba(92,188,227,0)\n"
"}\n"
"QTableWidget::item:selected{\n"
"	background-color:#1B89A1\n"
"}\n"
"\n"
"QHeaderView::section,QTableCornerButton:section{\n"
"    padding:5px; \n"
"    margin:0px; \n"
"    \n"
"	font: 10pt \"OPPOSans B\";\n"
"	color: rgb(255, 255, 255);\n"
"    border:1px solid #242424;\n"
"    border-left-width:0px; \n"
"    border-right-width:0px; \n"
"    border-top-width:0px; \n"
"    border-bottom-width:0px;\n"
"	background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #646464,stop:1 #525252); \n"
"}\n"
"QTableWidget{\n"
"	border:none;\n"
"	background-color: rgb(30, 45, 54);\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"    width: 10px;\n"
"	background-color: rgba(0, 41, 69, 0);\n"
"    margin: 0px,0px,0px,0px;\n"
"    padding-top: 0px;		/*//\351\232\220\350\227\217\344\270\212\344\270\213\347\232\204\347\256\255\345\244\264*/\n"
"    padding-bottom: 0px;\n"
"}\n"
"QScrollBar::handle:vertical {\n"
"    width: "
                        "10px;\n"
"	\n"
"	background-color: rgb(239, 239, 239);\n"
"    /*\346\273\232\345\212\250\346\235\241\344\270\244\347\253\257\345\217\230\346\210\220\346\244\255\345\234\206 */\n"
"    border-radius: 2px;\n"
"    min-height: 0;\n"
"}\n"
"\n"
"QScrollBar::sub-page:vertical {\n"
"    \n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}\n"
"QScrollBar::add-page:vertical \n"
"{\n"
"    background-color: rgba(255, 255, 255, 0);\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical {\n"
"	border: none;\n"
"    height: 0px;\n"
"    subcontrol-position: bottom;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"QScrollBar::sub-line:vertical {\n"
"    border: none;\n"
"    height: 0px;\n"
"    subcontrol-position: top;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::down-arrow:vertical {\n"
"    border:none;\n"
"}\n"
"QScrollBar::up-arrow:vertical {\n"
"    border:none;\n"
"}"));
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setHorizontalScrollMode(QAbstractItemView::ScrollPerItem);
        tableWidget->setShowGrid(false);
        tableWidget->setGridStyle(Qt::NoPen);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget->horizontalHeader()->setHighlightSections(false);
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setHighlightSections(true);
        tableWidget->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget->verticalHeader()->setStretchLastSection(false);
        toolButton_edit = new QToolButton(widget);
        toolButton_edit->setObjectName(QStringLiteral("toolButton_edit"));
        toolButton_edit->setGeometry(QRect(330, 80, 70, 30));
        toolButton_edit->setMinimumSize(QSize(70, 30));
        toolButton_edit->setMaximumSize(QSize(70, 30));
        toolButton_edit->setFont(font);
        toolButton_edit->setStyleSheet(QLatin1String("QToolButton {\n"
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
        toolButton_input = new QToolButton(widget);
        toolButton_input->setObjectName(QStringLiteral("toolButton_input"));
        toolButton_input->setGeometry(QRect(330, 30, 70, 30));
        toolButton_input->setMinimumSize(QSize(70, 30));
        toolButton_input->setMaximumSize(QSize(70, 30));
        toolButton_input->setFont(font);
        toolButton_input->setStyleSheet(QLatin1String("QToolButton {\n"
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
        toolButton_delete = new QToolButton(widget);
        toolButton_delete->setObjectName(QStringLiteral("toolButton_delete"));
        toolButton_delete->setGeometry(QRect(330, 130, 70, 30));
        toolButton_delete->setMinimumSize(QSize(70, 30));
        toolButton_delete->setMaximumSize(QSize(70, 30));
        toolButton_delete->setFont(font);
        toolButton_delete->setStyleSheet(QLatin1String("QToolButton {\n"
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

        verticalLayout->addWidget(widget);


        retranslateUi(secretkeywidget);

        QMetaObject::connectSlotsByName(secretkeywidget);
    } // setupUi

    void retranslateUi(QWidget *secretkeywidget)
    {
        secretkeywidget->setWindowTitle(QApplication::translate("secretkeywidget", "\351\200\211\346\213\251\345\257\206\351\222\245", nullptr));
        toolButton_cancel->setText(QApplication::translate("secretkeywidget", "\345\217\226\346\266\210", nullptr));
        toolButton_ok->setText(QApplication::translate("secretkeywidget", "\347\241\256\345\256\232", nullptr));
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
        toolButton_edit->setText(QApplication::translate("secretkeywidget", "\347\274\226\350\276\221", nullptr));
        toolButton_input->setText(QApplication::translate("secretkeywidget", "\345\257\274\345\205\245", nullptr));
        toolButton_delete->setText(QApplication::translate("secretkeywidget", "\345\210\240\351\231\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class secretkeywidget: public Ui_secretkeywidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECRETKEYWIDGET_H
