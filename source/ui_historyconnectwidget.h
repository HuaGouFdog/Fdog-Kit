/********************************************************************************
** Form generated from reading UI file 'historyconnectwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTORYCONNECTWIDGET_H
#define UI_HISTORYCONNECTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_historyconnectwidget
{
public:
    QHBoxLayout *horizontalLayout_5;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout;
    QWidget *widget_search;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLineEdit *lineEdit_find;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *tableWidget_history;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QToolButton *toolButton_create;
    QToolButton *toolButton_menger;
    QToolButton *toolButton_clear;

    void setupUi(QWidget *historyconnectwidget)
    {
        if (historyconnectwidget->objectName().isEmpty())
            historyconnectwidget->setObjectName(QStringLiteral("historyconnectwidget"));
        historyconnectwidget->resize(942, 524);
        historyconnectwidget->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        horizontalLayout_5 = new QHBoxLayout(historyconnectwidget);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(50, 0, 50, -1);
        widget_2 = new QWidget(historyconnectwidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        verticalLayout = new QVBoxLayout(widget_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 0, -1, -1);
        widget_search = new QWidget(widget_2);
        widget_search->setObjectName(QStringLiteral("widget_search"));
        widget_search->setMinimumSize(QSize(0, 50));
        horizontalLayout_2 = new QHBoxLayout(widget_search);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 0, -1, -1);
        horizontalSpacer = new QSpacerItem(397, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        lineEdit_find = new QLineEdit(widget_search);
        lineEdit_find->setObjectName(QStringLiteral("lineEdit_find"));
        lineEdit_find->setMinimumSize(QSize(250, 30));
        lineEdit_find->setMaximumSize(QSize(5999, 30));
        QFont font;
        font.setFamily(QStringLiteral("OPPOSans"));
        font.setPointSize(10);
        font.setStyleStrategy(QFont::PreferAntialias);
        lineEdit_find->setFont(font);
        lineEdit_find->setStyleSheet(QLatin1String("QLineEdit{\n"
"color: rgb(231, 238, 244);\n"
"border-radius: 14px;\n"
"background-color: rgb(25, 25, 25, 155);\n"
"border: 0px solid rgba(255, 255, 255, 0);\n"
"border-radius: 10px;\n"
"padding-left:10px;\n"
"padding-right:10px;\n"
"}"));

        horizontalLayout_2->addWidget(lineEdit_find);


        verticalLayout->addWidget(widget_search);

        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setStyleSheet(QLatin1String("#widget_3{\n"
"background-color: rgb(10, 31, 57,100);\n"
"border-radius:15px;\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(widget_3);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(15, 9, 15, -1);
        tableWidget_history = new QTableWidget(widget_3);
        if (tableWidget_history->columnCount() < 6)
            tableWidget_history->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_history->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_history->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_history->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_history->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_history->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_history->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableWidget_history->setObjectName(QStringLiteral("tableWidget_history"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidget_history->sizePolicy().hasHeightForWidth());
        tableWidget_history->setSizePolicy(sizePolicy);
        tableWidget_history->setMinimumSize(QSize(0, 0));
        tableWidget_history->setMaximumSize(QSize(16777215, 16777215));
        QFont font1;
        font1.setFamily(QStringLiteral("OPPOSans B"));
        font1.setPointSize(10);
        font1.setStyleStrategy(QFont::PreferAntialias);
        tableWidget_history->setFont(font1);
        tableWidget_history->setFocusPolicy(Qt::NoFocus);
        tableWidget_history->setStyleSheet(QString::fromUtf8("QTableWidget{\n"
"	border:none;\n"
"	\n"
"	border-color: rgb(130, 201, 255);\n"
"	/*background-color: rgb(30, 45, 54);*/\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QTableWidget::item:hover{\n"
"	background-color: rgba(10, 31, 57,0);\n"
"}\n"
"QTableWidget::item:selected{\n"
"	\n"
"	\n"
"	color: rgb(22, 22, 22);\n"
"	background-color: rgb(72, 141, 193);\n"
"}\n"
"\n"
"QHeaderView::section,QTableCornerButton:section{\n"
"    padding:5px; \n"
"    margin:0px; \n"
"    height: 30px;\n"
"	font: 10pt \"OPPOSans B\";\n"
"	\n"
"	color: rgb(255, 255, 255);\n"
"    border:1px solid #242424;\n"
"    border-left-width:0px; \n"
"    border-right-width:0px; \n"
"    border-top-width:0px; \n"
"    border-bottom-width:0px;\n"
"	/*background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #646464,stop:1 #525252); */\n"
"	\n"
"	\n"
"	background-color: rgb(10, 31, 57,0);\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"    width: 10px;\n"
"	background-color: rgba(0, 41, 69, 0);\n"
"    margin: 0px,0px,0px,0px;\n"
"    padding-"
                        "top: 0px;		/*//\351\232\220\350\227\217\344\270\212\344\270\213\347\232\204\347\256\255\345\244\264*/\n"
"    padding-bottom: 0px;\n"
"}\n"
"QScrollBar::handle:vertical {\n"
"    width: 10px;\n"
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
"QScrollBar::up-arr"
                        "ow:vertical {\n"
"    border:none;\n"
"}"));
        tableWidget_history->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidget_history->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_history->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        tableWidget_history->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_history->setDragDropMode(QAbstractItemView::NoDragDrop);
        tableWidget_history->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget_history->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget_history->setTextElideMode(Qt::ElideMiddle);
        tableWidget_history->setShowGrid(false);
        tableWidget_history->setGridStyle(Qt::NoPen);
        tableWidget_history->setSortingEnabled(false);
        tableWidget_history->horizontalHeader()->setVisible(true);
        tableWidget_history->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget_history->horizontalHeader()->setDefaultSectionSize(120);
        tableWidget_history->horizontalHeader()->setHighlightSections(false);
        tableWidget_history->horizontalHeader()->setMinimumSectionSize(20);
        tableWidget_history->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget_history->horizontalHeader()->setStretchLastSection(true);
        tableWidget_history->verticalHeader()->setVisible(false);
        tableWidget_history->verticalHeader()->setDefaultSectionSize(30);
        tableWidget_history->verticalHeader()->setMinimumSectionSize(20);

        verticalLayout_2->addWidget(tableWidget_history);


        verticalLayout->addWidget(widget_3);

        widget = new QWidget(widget_2);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setStyleSheet(QStringLiteral(""));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(15);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 10, 0, 10);
        horizontalSpacer_3 = new QSpacerItem(395, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        toolButton_create = new QToolButton(widget);
        toolButton_create->setObjectName(QStringLiteral("toolButton_create"));
        toolButton_create->setMinimumSize(QSize(70, 30));
        toolButton_create->setMaximumSize(QSize(70, 30));
        toolButton_create->setFont(font1);
        toolButton_create->setStyleSheet(QLatin1String("QToolButton {\n"
"	color: rgb(26, 26, 26);\n"
"	background-color: rgb(113, 212, 219);\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QToolButton::menu-indicator { \n"
"	image: None;\n"
"}\n"
"\n"
" \n"
"QToolButton:hover {\n"
"	color: rgb(26, 26, 26);\n"
"	background-color: rgb(113, 212, 219);\n"
"}"));

        horizontalLayout->addWidget(toolButton_create);

        toolButton_menger = new QToolButton(widget);
        toolButton_menger->setObjectName(QStringLiteral("toolButton_menger"));
        toolButton_menger->setMinimumSize(QSize(70, 30));
        toolButton_menger->setMaximumSize(QSize(70, 30));
        toolButton_menger->setFont(font1);
        toolButton_menger->setStyleSheet(QLatin1String("QToolButton {\n"
"	color: rgb(26, 26, 26);\n"
"	background-color: rgb(113, 212, 219);\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QToolButton::menu-indicator { \n"
"	image: None;\n"
"}\n"
"\n"
" \n"
"QToolButton:hover {\n"
"	color: rgb(26, 26, 26);\n"
"	background-color: rgb(113, 212, 219);\n"
"}"));

        horizontalLayout->addWidget(toolButton_menger);

        toolButton_clear = new QToolButton(widget);
        toolButton_clear->setObjectName(QStringLiteral("toolButton_clear"));
        toolButton_clear->setMinimumSize(QSize(70, 30));
        toolButton_clear->setMaximumSize(QSize(70, 30));
        toolButton_clear->setFont(font1);
        toolButton_clear->setStyleSheet(QLatin1String("QToolButton {\n"
"	color: rgb(255, 255, 255);\n"
"	\n"
"	background-color: rgb(67, 67, 67);\n"
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
"	background-color: rgb(67, 67, 67);\n"
"}"));

        horizontalLayout->addWidget(toolButton_clear);


        verticalLayout->addWidget(widget);


        horizontalLayout_5->addWidget(widget_2);

        horizontalLayout_5->setStretch(0, 8);

        retranslateUi(historyconnectwidget);

        QMetaObject::connectSlotsByName(historyconnectwidget);
    } // setupUi

    void retranslateUi(QWidget *historyconnectwidget)
    {
        historyconnectwidget->setWindowTitle(QApplication::translate("historyconnectwidget", "Form", nullptr));
        lineEdit_find->setPlaceholderText(QApplication::translate("historyconnectwidget", "\346\220\234\347\264\242\350\277\236\346\216\245", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_history->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("historyconnectwidget", "\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_history->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("historyconnectwidget", "\344\270\273\346\234\272", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_history->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("historyconnectwidget", "\347\224\250\346\210\267\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_history->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("historyconnectwidget", "\345\210\206\347\273\204", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_history->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("historyconnectwidget", "\345\244\207\346\263\250", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_history->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("historyconnectwidget", "\346\234\200\350\277\221\350\277\236\346\216\245", nullptr));
        toolButton_create->setText(QApplication::translate("historyconnectwidget", "\346\226\260\345\273\272", nullptr));
        toolButton_menger->setText(QApplication::translate("historyconnectwidget", "\347\256\241\347\220\206", nullptr));
        toolButton_clear->setText(QApplication::translate("historyconnectwidget", "\346\270\205\347\251\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class historyconnectwidget: public Ui_historyconnectwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORYCONNECTWIDGET_H
