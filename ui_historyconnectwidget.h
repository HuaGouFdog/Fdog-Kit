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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_historyconnectwidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QTableWidget *tableWidget_history;
    QWidget *horizontalWidget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QToolButton *toolButton_clear;

    void setupUi(QWidget *historyconnectwidget)
    {
        if (historyconnectwidget->objectName().isEmpty())
            historyconnectwidget->setObjectName(QStringLiteral("historyconnectwidget"));
        historyconnectwidget->resize(937, 587);
        historyconnectwidget->setStyleSheet(QLatin1String("background-color: rgb(30, 45, 54);\n"
"color: rgb(255, 255, 255);"));
        verticalLayout = new QVBoxLayout(historyconnectwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(historyconnectwidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        tableWidget_history = new QTableWidget(widget_2);
        if (tableWidget_history->columnCount() < 6)
            tableWidget_history->setColumnCount(6);
        QFont font;
        font.setFamily(QStringLiteral("OPPOSans B"));
        font.setPointSize(10);
        font.setStyleStrategy(QFont::PreferAntialias);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        __qtablewidgetitem->setFont(font);
        tableWidget_history->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        __qtablewidgetitem1->setFont(font);
        tableWidget_history->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        __qtablewidgetitem2->setFont(font);
        tableWidget_history->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        __qtablewidgetitem3->setFont(font);
        tableWidget_history->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        __qtablewidgetitem4->setFont(font);
        tableWidget_history->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        __qtablewidgetitem5->setFont(font);
        tableWidget_history->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        if (tableWidget_history->rowCount() < 13)
            tableWidget_history->setRowCount(13);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        __qtablewidgetitem6->setFont(font);
        tableWidget_history->setVerticalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_history->setVerticalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_history->setVerticalHeaderItem(2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_history->setVerticalHeaderItem(3, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_history->setVerticalHeaderItem(4, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget_history->setVerticalHeaderItem(5, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget_history->setVerticalHeaderItem(6, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget_history->setVerticalHeaderItem(7, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget_history->setVerticalHeaderItem(8, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget_history->setVerticalHeaderItem(9, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget_history->setVerticalHeaderItem(10, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget_history->setVerticalHeaderItem(11, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget_history->setVerticalHeaderItem(12, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget_history->setItem(0, 0, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget_history->setItem(0, 1, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget_history->setItem(0, 2, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget_history->setItem(0, 3, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget_history->setItem(0, 4, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget_history->setItem(1, 0, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget_history->setItem(1, 1, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget_history->setItem(1, 2, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget_history->setItem(1, 3, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget_history->setItem(1, 4, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableWidget_history->setItem(2, 0, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableWidget_history->setItem(2, 1, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        tableWidget_history->setItem(2, 2, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        tableWidget_history->setItem(2, 3, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        tableWidget_history->setItem(2, 4, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        tableWidget_history->setItem(3, 0, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        tableWidget_history->setItem(3, 1, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        tableWidget_history->setItem(3, 2, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        tableWidget_history->setItem(3, 3, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        tableWidget_history->setItem(3, 4, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        tableWidget_history->setItem(4, 0, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        tableWidget_history->setItem(4, 1, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        tableWidget_history->setItem(4, 2, __qtablewidgetitem41);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        tableWidget_history->setItem(4, 3, __qtablewidgetitem42);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        tableWidget_history->setItem(4, 4, __qtablewidgetitem43);
        QTableWidgetItem *__qtablewidgetitem44 = new QTableWidgetItem();
        tableWidget_history->setItem(5, 0, __qtablewidgetitem44);
        QTableWidgetItem *__qtablewidgetitem45 = new QTableWidgetItem();
        tableWidget_history->setItem(5, 1, __qtablewidgetitem45);
        QTableWidgetItem *__qtablewidgetitem46 = new QTableWidgetItem();
        __qtablewidgetitem46->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        tableWidget_history->setItem(5, 2, __qtablewidgetitem46);
        QTableWidgetItem *__qtablewidgetitem47 = new QTableWidgetItem();
        tableWidget_history->setItem(5, 3, __qtablewidgetitem47);
        QTableWidgetItem *__qtablewidgetitem48 = new QTableWidgetItem();
        tableWidget_history->setItem(5, 4, __qtablewidgetitem48);
        QTableWidgetItem *__qtablewidgetitem49 = new QTableWidgetItem();
        tableWidget_history->setItem(6, 0, __qtablewidgetitem49);
        QTableWidgetItem *__qtablewidgetitem50 = new QTableWidgetItem();
        tableWidget_history->setItem(6, 1, __qtablewidgetitem50);
        QTableWidgetItem *__qtablewidgetitem51 = new QTableWidgetItem();
        tableWidget_history->setItem(6, 2, __qtablewidgetitem51);
        QTableWidgetItem *__qtablewidgetitem52 = new QTableWidgetItem();
        tableWidget_history->setItem(6, 3, __qtablewidgetitem52);
        QTableWidgetItem *__qtablewidgetitem53 = new QTableWidgetItem();
        tableWidget_history->setItem(6, 4, __qtablewidgetitem53);
        QTableWidgetItem *__qtablewidgetitem54 = new QTableWidgetItem();
        tableWidget_history->setItem(7, 0, __qtablewidgetitem54);
        QTableWidgetItem *__qtablewidgetitem55 = new QTableWidgetItem();
        tableWidget_history->setItem(7, 1, __qtablewidgetitem55);
        QTableWidgetItem *__qtablewidgetitem56 = new QTableWidgetItem();
        tableWidget_history->setItem(7, 2, __qtablewidgetitem56);
        QTableWidgetItem *__qtablewidgetitem57 = new QTableWidgetItem();
        tableWidget_history->setItem(7, 3, __qtablewidgetitem57);
        QTableWidgetItem *__qtablewidgetitem58 = new QTableWidgetItem();
        tableWidget_history->setItem(7, 4, __qtablewidgetitem58);
        QTableWidgetItem *__qtablewidgetitem59 = new QTableWidgetItem();
        tableWidget_history->setItem(8, 0, __qtablewidgetitem59);
        QTableWidgetItem *__qtablewidgetitem60 = new QTableWidgetItem();
        tableWidget_history->setItem(8, 1, __qtablewidgetitem60);
        QTableWidgetItem *__qtablewidgetitem61 = new QTableWidgetItem();
        tableWidget_history->setItem(8, 2, __qtablewidgetitem61);
        QTableWidgetItem *__qtablewidgetitem62 = new QTableWidgetItem();
        tableWidget_history->setItem(8, 3, __qtablewidgetitem62);
        QTableWidgetItem *__qtablewidgetitem63 = new QTableWidgetItem();
        tableWidget_history->setItem(8, 4, __qtablewidgetitem63);
        QTableWidgetItem *__qtablewidgetitem64 = new QTableWidgetItem();
        tableWidget_history->setItem(9, 0, __qtablewidgetitem64);
        QTableWidgetItem *__qtablewidgetitem65 = new QTableWidgetItem();
        tableWidget_history->setItem(9, 1, __qtablewidgetitem65);
        QTableWidgetItem *__qtablewidgetitem66 = new QTableWidgetItem();
        tableWidget_history->setItem(9, 2, __qtablewidgetitem66);
        QTableWidgetItem *__qtablewidgetitem67 = new QTableWidgetItem();
        tableWidget_history->setItem(9, 3, __qtablewidgetitem67);
        QTableWidgetItem *__qtablewidgetitem68 = new QTableWidgetItem();
        tableWidget_history->setItem(9, 4, __qtablewidgetitem68);
        QTableWidgetItem *__qtablewidgetitem69 = new QTableWidgetItem();
        tableWidget_history->setItem(10, 0, __qtablewidgetitem69);
        QTableWidgetItem *__qtablewidgetitem70 = new QTableWidgetItem();
        tableWidget_history->setItem(10, 1, __qtablewidgetitem70);
        QTableWidgetItem *__qtablewidgetitem71 = new QTableWidgetItem();
        tableWidget_history->setItem(10, 2, __qtablewidgetitem71);
        QTableWidgetItem *__qtablewidgetitem72 = new QTableWidgetItem();
        tableWidget_history->setItem(10, 3, __qtablewidgetitem72);
        QTableWidgetItem *__qtablewidgetitem73 = new QTableWidgetItem();
        tableWidget_history->setItem(10, 4, __qtablewidgetitem73);
        QTableWidgetItem *__qtablewidgetitem74 = new QTableWidgetItem();
        tableWidget_history->setItem(11, 0, __qtablewidgetitem74);
        QTableWidgetItem *__qtablewidgetitem75 = new QTableWidgetItem();
        tableWidget_history->setItem(11, 1, __qtablewidgetitem75);
        QTableWidgetItem *__qtablewidgetitem76 = new QTableWidgetItem();
        tableWidget_history->setItem(11, 2, __qtablewidgetitem76);
        QTableWidgetItem *__qtablewidgetitem77 = new QTableWidgetItem();
        tableWidget_history->setItem(11, 3, __qtablewidgetitem77);
        QTableWidgetItem *__qtablewidgetitem78 = new QTableWidgetItem();
        tableWidget_history->setItem(11, 4, __qtablewidgetitem78);
        QTableWidgetItem *__qtablewidgetitem79 = new QTableWidgetItem();
        tableWidget_history->setItem(12, 0, __qtablewidgetitem79);
        QTableWidgetItem *__qtablewidgetitem80 = new QTableWidgetItem();
        tableWidget_history->setItem(12, 1, __qtablewidgetitem80);
        QTableWidgetItem *__qtablewidgetitem81 = new QTableWidgetItem();
        tableWidget_history->setItem(12, 2, __qtablewidgetitem81);
        QTableWidgetItem *__qtablewidgetitem82 = new QTableWidgetItem();
        tableWidget_history->setItem(12, 3, __qtablewidgetitem82);
        QTableWidgetItem *__qtablewidgetitem83 = new QTableWidgetItem();
        tableWidget_history->setItem(12, 4, __qtablewidgetitem83);
        tableWidget_history->setObjectName(QStringLiteral("tableWidget_history"));
        tableWidget_history->setMinimumSize(QSize(0, 0));
        tableWidget_history->setFont(font);
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
        tableWidget_history->horizontalHeader()->setDefaultSectionSize(160);
        tableWidget_history->horizontalHeader()->setHighlightSections(false);
        tableWidget_history->horizontalHeader()->setMinimumSectionSize(100);
        tableWidget_history->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget_history->horizontalHeader()->setStretchLastSection(true);
        tableWidget_history->verticalHeader()->setVisible(false);
        tableWidget_history->verticalHeader()->setDefaultSectionSize(30);
        tableWidget_history->verticalHeader()->setMinimumSectionSize(25);

        horizontalLayout->addWidget(tableWidget_history);

        horizontalLayout->setStretch(0, 20);

        verticalLayout->addWidget(widget_2);

        horizontalWidget = new QWidget(historyconnectwidget);
        horizontalWidget->setObjectName(QStringLiteral("horizontalWidget"));
        horizontalLayout_2 = new QHBoxLayout(horizontalWidget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        toolButton_clear = new QToolButton(horizontalWidget);
        toolButton_clear->setObjectName(QStringLiteral("toolButton_clear"));
        toolButton_clear->setMinimumSize(QSize(70, 30));
        toolButton_clear->setMaximumSize(QSize(70, 30));
        toolButton_clear->setFont(font);
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

        horizontalLayout_2->addWidget(toolButton_clear);


        verticalLayout->addWidget(horizontalWidget);


        retranslateUi(historyconnectwidget);

        QMetaObject::connectSlotsByName(historyconnectwidget);
    } // setupUi

    void retranslateUi(QWidget *historyconnectwidget)
    {
        historyconnectwidget->setWindowTitle(QApplication::translate("historyconnectwidget", "Form", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_history->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("historyconnectwidget", "\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_history->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("historyconnectwidget", "\344\270\273\346\234\272", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_history->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("historyconnectwidget", "\347\224\250\346\210\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_history->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("historyconnectwidget", "\345\210\206\347\273\204", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_history->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("historyconnectwidget", "\345\244\207\346\263\250", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_history->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("historyconnectwidget", "\346\223\215\344\275\234", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_history->verticalHeaderItem(0);
        ___qtablewidgetitem6->setText(QApplication::translate("historyconnectwidget", "\346\226\260\345\273\272\350\241\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_history->verticalHeaderItem(1);
        ___qtablewidgetitem7->setText(QApplication::translate("historyconnectwidget", "\346\226\260\345\273\272\350\241\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_history->verticalHeaderItem(2);
        ___qtablewidgetitem8->setText(QApplication::translate("historyconnectwidget", "\346\226\260\345\273\272\350\241\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_history->verticalHeaderItem(3);
        ___qtablewidgetitem9->setText(QApplication::translate("historyconnectwidget", "\346\226\260\345\273\272\350\241\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_history->verticalHeaderItem(4);
        ___qtablewidgetitem10->setText(QApplication::translate("historyconnectwidget", "\346\226\260\345\273\272\350\241\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_history->verticalHeaderItem(5);
        ___qtablewidgetitem11->setText(QApplication::translate("historyconnectwidget", "\346\226\260\345\273\272\350\241\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget_history->verticalHeaderItem(6);
        ___qtablewidgetitem12->setText(QApplication::translate("historyconnectwidget", "\346\226\260\345\273\272\350\241\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget_history->verticalHeaderItem(7);
        ___qtablewidgetitem13->setText(QApplication::translate("historyconnectwidget", "\346\226\260\345\273\272\350\241\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget_history->verticalHeaderItem(8);
        ___qtablewidgetitem14->setText(QApplication::translate("historyconnectwidget", "\346\226\260\345\273\272\350\241\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget_history->verticalHeaderItem(9);
        ___qtablewidgetitem15->setText(QApplication::translate("historyconnectwidget", "\346\226\260\345\273\272\350\241\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget_history->verticalHeaderItem(10);
        ___qtablewidgetitem16->setText(QApplication::translate("historyconnectwidget", "\346\226\260\345\273\272\350\241\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget_history->verticalHeaderItem(11);
        ___qtablewidgetitem17->setText(QApplication::translate("historyconnectwidget", "\346\226\260\345\273\272\350\241\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget_history->verticalHeaderItem(12);
        ___qtablewidgetitem18->setText(QApplication::translate("historyconnectwidget", "\346\226\260\345\273\272\350\241\214", nullptr));

        const bool __sortingEnabled = tableWidget_history->isSortingEnabled();
        tableWidget_history->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget_history->item(0, 0);
        ___qtablewidgetitem19->setText(QApplication::translate("historyconnectwidget", "\346\226\260\345\273\272\347\273\210\347\253\2571", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget_history->item(0, 1);
        ___qtablewidgetitem20->setText(QApplication::translate("historyconnectwidget", "172.16.8.159", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget_history->item(0, 2);
        ___qtablewidgetitem21->setText(QApplication::translate("historyconnectwidget", "root", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget_history->item(0, 3);
        ___qtablewidgetitem22->setText(QApplication::translate("historyconnectwidget", "\351\273\230\350\256\244", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget_history->item(0, 4);
        ___qtablewidgetitem23->setText(QApplication::translate("historyconnectwidget", "\351\273\230\350\256\244", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget_history->item(1, 0);
        ___qtablewidgetitem24->setText(QApplication::translate("historyconnectwidget", "\346\226\260\345\273\272\347\273\210\347\253\2571", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget_history->item(1, 1);
        ___qtablewidgetitem25->setText(QApplication::translate("historyconnectwidget", "172.16.8.159", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget_history->item(1, 2);
        ___qtablewidgetitem26->setText(QApplication::translate("historyconnectwidget", "root", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget_history->item(1, 3);
        ___qtablewidgetitem27->setText(QApplication::translate("historyconnectwidget", "\351\273\230\350\256\244", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget_history->item(1, 4);
        ___qtablewidgetitem28->setText(QApplication::translate("historyconnectwidget", "\345\244\247\350\213\217\346\211\223SDAS\345\244\247\350\213\217\346\211\223SDAS\345\244\247\350\213\217\346\211\223SDAS\345\244\247\350\213\217\346\211\223SDAS\345\244\247\350\213\217\346\211\223SDAS", nullptr));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidget_history->item(2, 0);
        ___qtablewidgetitem29->setText(QApplication::translate("historyconnectwidget", "\346\226\260\345\273\272\347\273\210\347\253\2572", nullptr));
        QTableWidgetItem *___qtablewidgetitem30 = tableWidget_history->item(2, 1);
        ___qtablewidgetitem30->setText(QApplication::translate("historyconnectwidget", "172.16.8.159", nullptr));
        QTableWidgetItem *___qtablewidgetitem31 = tableWidget_history->item(2, 2);
        ___qtablewidgetitem31->setText(QApplication::translate("historyconnectwidget", "root", nullptr));
        QTableWidgetItem *___qtablewidgetitem32 = tableWidget_history->item(2, 3);
        ___qtablewidgetitem32->setText(QApplication::translate("historyconnectwidget", "\351\273\230\350\256\244", nullptr));
        QTableWidgetItem *___qtablewidgetitem33 = tableWidget_history->item(2, 4);
        ___qtablewidgetitem33->setText(QApplication::translate("historyconnectwidget", "\345\244\247\350\213\217\346\211\223SDAS\345\244\247\350\213\217\346\211\223SDAS\345\244\247\350\213\217\346\211\223SDAS\345\244\247\350\213\217\346\211\223SDAS", nullptr));
        QTableWidgetItem *___qtablewidgetitem34 = tableWidget_history->item(3, 0);
        ___qtablewidgetitem34->setText(QApplication::translate("historyconnectwidget", "\346\226\260\345\273\272\347\273\210\347\253\2573", nullptr));
        QTableWidgetItem *___qtablewidgetitem35 = tableWidget_history->item(3, 1);
        ___qtablewidgetitem35->setText(QApplication::translate("historyconnectwidget", "172.16.8.159", nullptr));
        QTableWidgetItem *___qtablewidgetitem36 = tableWidget_history->item(3, 2);
        ___qtablewidgetitem36->setText(QApplication::translate("historyconnectwidget", "root", nullptr));
        QTableWidgetItem *___qtablewidgetitem37 = tableWidget_history->item(3, 3);
        ___qtablewidgetitem37->setText(QApplication::translate("historyconnectwidget", "\351\273\230\350\256\244", nullptr));
        QTableWidgetItem *___qtablewidgetitem38 = tableWidget_history->item(3, 4);
        ___qtablewidgetitem38->setText(QApplication::translate("historyconnectwidget", "\345\244\247\350\213\217\346\211\223SDAS", nullptr));
        QTableWidgetItem *___qtablewidgetitem39 = tableWidget_history->item(4, 0);
        ___qtablewidgetitem39->setText(QApplication::translate("historyconnectwidget", "\346\226\260\345\273\272\347\273\210\347\253\2574", nullptr));
        QTableWidgetItem *___qtablewidgetitem40 = tableWidget_history->item(4, 1);
        ___qtablewidgetitem40->setText(QApplication::translate("historyconnectwidget", "172.16.8.159", nullptr));
        QTableWidgetItem *___qtablewidgetitem41 = tableWidget_history->item(4, 2);
        ___qtablewidgetitem41->setText(QApplication::translate("historyconnectwidget", "root", nullptr));
        QTableWidgetItem *___qtablewidgetitem42 = tableWidget_history->item(4, 3);
        ___qtablewidgetitem42->setText(QApplication::translate("historyconnectwidget", "\351\273\230\350\256\244", nullptr));
        QTableWidgetItem *___qtablewidgetitem43 = tableWidget_history->item(4, 4);
        ___qtablewidgetitem43->setText(QApplication::translate("historyconnectwidget", "\345\244\247\350\213\217\346\211\223SDAS", nullptr));
        QTableWidgetItem *___qtablewidgetitem44 = tableWidget_history->item(5, 0);
        ___qtablewidgetitem44->setText(QApplication::translate("historyconnectwidget", "\346\226\260\345\273\272\347\273\210\347\253\2575", nullptr));
        QTableWidgetItem *___qtablewidgetitem45 = tableWidget_history->item(5, 1);
        ___qtablewidgetitem45->setText(QApplication::translate("historyconnectwidget", "172.16.8.159", nullptr));
        QTableWidgetItem *___qtablewidgetitem46 = tableWidget_history->item(5, 2);
        ___qtablewidgetitem46->setText(QApplication::translate("historyconnectwidget", "root", nullptr));
        QTableWidgetItem *___qtablewidgetitem47 = tableWidget_history->item(5, 3);
        ___qtablewidgetitem47->setText(QApplication::translate("historyconnectwidget", "\351\273\230\350\256\244", nullptr));
        QTableWidgetItem *___qtablewidgetitem48 = tableWidget_history->item(5, 4);
        ___qtablewidgetitem48->setText(QApplication::translate("historyconnectwidget", "\345\244\247\350\213\217\346\211\223SDAS\345\244\247\350\213\217\346\211\223SDAS\345\244\247\350\213\217\346\211\223SDAS\345\244\247\350\213\217\346\211\223SDAS", nullptr));
        QTableWidgetItem *___qtablewidgetitem49 = tableWidget_history->item(6, 0);
        ___qtablewidgetitem49->setText(QApplication::translate("historyconnectwidget", "\346\226\260\345\273\272\347\273\210\347\253\2575", nullptr));
        QTableWidgetItem *___qtablewidgetitem50 = tableWidget_history->item(6, 1);
        ___qtablewidgetitem50->setText(QApplication::translate("historyconnectwidget", "172.16.8.159", nullptr));
        QTableWidgetItem *___qtablewidgetitem51 = tableWidget_history->item(6, 2);
        ___qtablewidgetitem51->setText(QApplication::translate("historyconnectwidget", "root", nullptr));
        QTableWidgetItem *___qtablewidgetitem52 = tableWidget_history->item(6, 3);
        ___qtablewidgetitem52->setText(QApplication::translate("historyconnectwidget", "\351\273\230\350\256\244", nullptr));
        QTableWidgetItem *___qtablewidgetitem53 = tableWidget_history->item(6, 4);
        ___qtablewidgetitem53->setText(QApplication::translate("historyconnectwidget", "\345\244\247\350\213\217\346\211\223SDAS", nullptr));
        QTableWidgetItem *___qtablewidgetitem54 = tableWidget_history->item(7, 0);
        ___qtablewidgetitem54->setText(QApplication::translate("historyconnectwidget", "\346\226\260\345\273\272\347\273\210\347\253\2575", nullptr));
        QTableWidgetItem *___qtablewidgetitem55 = tableWidget_history->item(7, 1);
        ___qtablewidgetitem55->setText(QApplication::translate("historyconnectwidget", "172.16.8.159", nullptr));
        QTableWidgetItem *___qtablewidgetitem56 = tableWidget_history->item(7, 2);
        ___qtablewidgetitem56->setText(QApplication::translate("historyconnectwidget", "root", nullptr));
        QTableWidgetItem *___qtablewidgetitem57 = tableWidget_history->item(7, 3);
        ___qtablewidgetitem57->setText(QApplication::translate("historyconnectwidget", "\351\273\230\350\256\244", nullptr));
        QTableWidgetItem *___qtablewidgetitem58 = tableWidget_history->item(7, 4);
        ___qtablewidgetitem58->setText(QApplication::translate("historyconnectwidget", "\345\244\247\350\213\217\346\211\223SDAS", nullptr));
        QTableWidgetItem *___qtablewidgetitem59 = tableWidget_history->item(8, 0);
        ___qtablewidgetitem59->setText(QApplication::translate("historyconnectwidget", "\346\226\260\345\273\272\347\273\210\347\253\2575", nullptr));
        QTableWidgetItem *___qtablewidgetitem60 = tableWidget_history->item(8, 1);
        ___qtablewidgetitem60->setText(QApplication::translate("historyconnectwidget", "172.16.8.159", nullptr));
        QTableWidgetItem *___qtablewidgetitem61 = tableWidget_history->item(8, 2);
        ___qtablewidgetitem61->setText(QApplication::translate("historyconnectwidget", "root", nullptr));
        QTableWidgetItem *___qtablewidgetitem62 = tableWidget_history->item(8, 3);
        ___qtablewidgetitem62->setText(QApplication::translate("historyconnectwidget", "\351\273\230\350\256\244", nullptr));
        QTableWidgetItem *___qtablewidgetitem63 = tableWidget_history->item(8, 4);
        ___qtablewidgetitem63->setText(QApplication::translate("historyconnectwidget", "\345\244\247\350\213\217\346\211\223SDAS", nullptr));
        QTableWidgetItem *___qtablewidgetitem64 = tableWidget_history->item(9, 0);
        ___qtablewidgetitem64->setText(QApplication::translate("historyconnectwidget", "\346\226\260\345\273\272\347\273\210\347\253\2575", nullptr));
        QTableWidgetItem *___qtablewidgetitem65 = tableWidget_history->item(9, 1);
        ___qtablewidgetitem65->setText(QApplication::translate("historyconnectwidget", "172.16.8.159", nullptr));
        QTableWidgetItem *___qtablewidgetitem66 = tableWidget_history->item(9, 2);
        ___qtablewidgetitem66->setText(QApplication::translate("historyconnectwidget", "root", nullptr));
        QTableWidgetItem *___qtablewidgetitem67 = tableWidget_history->item(9, 3);
        ___qtablewidgetitem67->setText(QApplication::translate("historyconnectwidget", "\351\273\230\350\256\244", nullptr));
        QTableWidgetItem *___qtablewidgetitem68 = tableWidget_history->item(9, 4);
        ___qtablewidgetitem68->setText(QApplication::translate("historyconnectwidget", "\345\244\247\350\213\217\346\211\223SDAS", nullptr));
        QTableWidgetItem *___qtablewidgetitem69 = tableWidget_history->item(10, 0);
        ___qtablewidgetitem69->setText(QApplication::translate("historyconnectwidget", "\346\226\260\345\273\272\347\273\210\347\253\2575", nullptr));
        QTableWidgetItem *___qtablewidgetitem70 = tableWidget_history->item(10, 1);
        ___qtablewidgetitem70->setText(QApplication::translate("historyconnectwidget", "172.16.8.159", nullptr));
        QTableWidgetItem *___qtablewidgetitem71 = tableWidget_history->item(10, 2);
        ___qtablewidgetitem71->setText(QApplication::translate("historyconnectwidget", "root", nullptr));
        QTableWidgetItem *___qtablewidgetitem72 = tableWidget_history->item(10, 3);
        ___qtablewidgetitem72->setText(QApplication::translate("historyconnectwidget", "\351\273\230\350\256\244", nullptr));
        QTableWidgetItem *___qtablewidgetitem73 = tableWidget_history->item(10, 4);
        ___qtablewidgetitem73->setText(QApplication::translate("historyconnectwidget", "\345\244\247\350\213\217\346\211\223SDAS", nullptr));
        QTableWidgetItem *___qtablewidgetitem74 = tableWidget_history->item(11, 0);
        ___qtablewidgetitem74->setText(QApplication::translate("historyconnectwidget", "\346\226\260\345\273\272\347\273\210\347\253\2575", nullptr));
        QTableWidgetItem *___qtablewidgetitem75 = tableWidget_history->item(11, 1);
        ___qtablewidgetitem75->setText(QApplication::translate("historyconnectwidget", "172.16.8.159", nullptr));
        QTableWidgetItem *___qtablewidgetitem76 = tableWidget_history->item(11, 2);
        ___qtablewidgetitem76->setText(QApplication::translate("historyconnectwidget", "root", nullptr));
        QTableWidgetItem *___qtablewidgetitem77 = tableWidget_history->item(11, 3);
        ___qtablewidgetitem77->setText(QApplication::translate("historyconnectwidget", "\351\273\230\350\256\244", nullptr));
        QTableWidgetItem *___qtablewidgetitem78 = tableWidget_history->item(11, 4);
        ___qtablewidgetitem78->setText(QApplication::translate("historyconnectwidget", "\345\244\247\350\213\217\346\211\223SDAS", nullptr));
        QTableWidgetItem *___qtablewidgetitem79 = tableWidget_history->item(12, 0);
        ___qtablewidgetitem79->setText(QApplication::translate("historyconnectwidget", "\346\226\260\345\273\272\347\273\210\347\253\2575", nullptr));
        QTableWidgetItem *___qtablewidgetitem80 = tableWidget_history->item(12, 1);
        ___qtablewidgetitem80->setText(QApplication::translate("historyconnectwidget", "172.16.8.159", nullptr));
        QTableWidgetItem *___qtablewidgetitem81 = tableWidget_history->item(12, 2);
        ___qtablewidgetitem81->setText(QApplication::translate("historyconnectwidget", "root", nullptr));
        QTableWidgetItem *___qtablewidgetitem82 = tableWidget_history->item(12, 3);
        ___qtablewidgetitem82->setText(QApplication::translate("historyconnectwidget", "\351\273\230\350\256\244", nullptr));
        QTableWidgetItem *___qtablewidgetitem83 = tableWidget_history->item(12, 4);
        ___qtablewidgetitem83->setText(QApplication::translate("historyconnectwidget", "\345\244\247\350\213\217\346\211\223SDAS", nullptr));
        tableWidget_history->setSortingEnabled(__sortingEnabled);

        toolButton_clear->setText(QApplication::translate("historyconnectwidget", "\346\270\205\347\251\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class historyconnectwidget: public Ui_historyconnectwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORYCONNECTWIDGET_H
