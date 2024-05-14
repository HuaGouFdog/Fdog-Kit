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
#include <QtWidgets/QLabel>
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
    QLabel *label;
    QTableWidget *tableWidget_history;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QToolButton *toolButton_clear_3;
    QToolButton *toolButton_clear;

    void setupUi(QWidget *historyconnectwidget)
    {
        if (historyconnectwidget->objectName().isEmpty())
            historyconnectwidget->setObjectName(QStringLiteral("historyconnectwidget"));
        historyconnectwidget->resize(942, 524);
        historyconnectwidget->setStyleSheet(QLatin1String("background-color: rgb(30, 45, 54);\n"
"color: rgb(255, 255, 255);"));
        horizontalLayout_5 = new QHBoxLayout(historyconnectwidget);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        widget_2 = new QWidget(historyconnectwidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        verticalLayout = new QVBoxLayout(widget_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(20, 20, 20, 20);
        label = new QLabel(widget_2);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 30));
        QFont font;
        font.setFamily(QStringLiteral("OPPOSans B"));
        font.setPointSize(12);
        font.setStyleStrategy(QFont::PreferAntialias);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral(""));

        verticalLayout->addWidget(label);

        tableWidget_history = new QTableWidget(widget_2);
        if (tableWidget_history->columnCount() < 3)
            tableWidget_history->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_history->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_history->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_history->setHorizontalHeaderItem(2, __qtablewidgetitem2);
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
        tableWidget_history->setStyleSheet(QString::fromUtf8("QTableWidget::item:hover{\n"
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
"	/*background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #646464,stop:1 #525252); */\n"
"	\n"
"	background-color: rgb(47, 71, 85);\n"
"}\n"
"QTableWidget{\n"
"	border:none;\n"
"	\n"
"	border-color: rgb(130, 201, 255);\n"
"	background-color: rgb(30, 45, 54);\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"    width: 10px;\n"
"	background-color: rgba(0, 41, 69, 0);\n"
"    margin: 0px,0px,0px,0px;\n"
"    padding-top: 0px;		/*//\351\232\220\350\227\217\344\270\212\344\270\213\347\232\204\347\256\255\345"
                        "\244\264*/\n"
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
"QScrollBar::up-arrow:vertical {\n"
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

        verticalLayout->addWidget(tableWidget_history);

        widget = new QWidget(widget_2);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(395, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        toolButton_clear_3 = new QToolButton(widget);
        toolButton_clear_3->setObjectName(QStringLiteral("toolButton_clear_3"));
        toolButton_clear_3->setMinimumSize(QSize(70, 30));
        toolButton_clear_3->setMaximumSize(QSize(70, 30));
        toolButton_clear_3->setFont(font1);
        toolButton_clear_3->setStyleSheet(QLatin1String("QToolButton {\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(7, 143, 255);\n"
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
"	background-color: rgb(7, 143, 255);\n"
"}"));

        horizontalLayout->addWidget(toolButton_clear_3);

        toolButton_clear = new QToolButton(widget);
        toolButton_clear->setObjectName(QStringLiteral("toolButton_clear"));
        toolButton_clear->setMinimumSize(QSize(70, 30));
        toolButton_clear->setMaximumSize(QSize(70, 30));
        toolButton_clear->setFont(font1);
        toolButton_clear->setStyleSheet(QLatin1String("QToolButton {\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(7, 143, 255);\n"
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
"	background-color: rgb(7, 143, 255);\n"
"}"));

        horizontalLayout->addWidget(toolButton_clear);


        verticalLayout->addWidget(widget);

        verticalLayout->setStretch(1, 30);

        horizontalLayout_5->addWidget(widget_2);

        horizontalLayout_5->setStretch(0, 8);

        retranslateUi(historyconnectwidget);

        QMetaObject::connectSlotsByName(historyconnectwidget);
    } // setupUi

    void retranslateUi(QWidget *historyconnectwidget)
    {
        historyconnectwidget->setWindowTitle(QApplication::translate("historyconnectwidget", "Form", nullptr));
        label->setText(QApplication::translate("historyconnectwidget", "\345\277\253\351\200\237\350\277\236\346\216\245", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_history->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("historyconnectwidget", "\346\226\260\345\273\272\345\210\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_history->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("historyconnectwidget", "\346\226\260\345\273\272\345\210\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_history->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("historyconnectwidget", "\346\226\260\345\273\272\345\210\227", nullptr));
        toolButton_clear_3->setText(QApplication::translate("historyconnectwidget", "\347\256\241\347\220\206", nullptr));
        toolButton_clear->setText(QApplication::translate("historyconnectwidget", "\346\270\205\347\251\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class historyconnectwidget: public Ui_historyconnectwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORYCONNECTWIDGET_H
