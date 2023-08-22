/********************************************************************************
** Form generated from reading UI file 'sshwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SSHWIDGET_H
#define UI_SSHWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_sshwidget
{
public:
    QVBoxLayout *verticalLayout_5;
    QSplitter *splitter_1;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_server_info;
    QHBoxLayout *horizontalLayout_22;
    QLabel *label_25;
    QWidget *widget_ip_info;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QToolButton *toolButton;
    QWidget *widget_run_info;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_2;
    QWidget *verticalWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_11;
    QLabel *label_8;
    QLabel *label_10;
    QWidget *widget_25;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_4;
    QWidget *widget_cpu_info;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_3;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_6;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_7;
    QWidget *widget_swap_info;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_17;
    QWidget *widget_18;
    QHBoxLayout *horizontalLayout_11;
    QWidget *widget_19;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_18;
    QWidget *widget_20;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_19;
    QWidget *widget_mem_info;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_14;
    QWidget *widget_14;
    QHBoxLayout *horizontalLayout_8;
    QWidget *widget_15;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_15;
    QWidget *widget_16;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_16;
    QWidget *widget_22;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *tableWidget;
    QWidget *widget_23;
    QGridLayout *gridLayout;
    QLabel *label_23;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_28;
    QLabel *label_29;
    QLabel *label_30;
    QLabel *label_31;
    QSpacerItem *verticalSpacer;
    QWidget *widget_26;
    QVBoxLayout *verticalLayout_6;
    QSplitter *splitter_2;
    QWidget *widget_29;
    QHBoxLayout *horizontalLayout_19;
    QSplitter *splitter_3;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_8;
    QTextEdit *textEdit;
    QWidget *widget_4;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_7;
    QSplitter *splitter_4;
    QWidget *widget_27;
    QGroupBox *groupBox;
    QWidget *widget_28;
    QGroupBox *groupBox_2;

    void setupUi(QWidget *sshwidget)
    {
        if (sshwidget->objectName().isEmpty())
            sshwidget->setObjectName(QStringLiteral("sshwidget"));
        sshwidget->resize(1216, 612);
        verticalLayout_5 = new QVBoxLayout(sshwidget);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        splitter_1 = new QSplitter(sshwidget);
        splitter_1->setObjectName(QStringLiteral("splitter_1"));
        splitter_1->setOrientation(Qt::Horizontal);
        widget = new QWidget(splitter_1);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(175, 0));
        widget->setMaximumSize(QSize(175, 16777215));
        QFont font;
        font.setFamily(QStringLiteral("OPPOSans B"));
        font.setPointSize(10);
        font.setStyleStrategy(QFont::PreferAntialias);
        widget->setFont(font);
        widget->setStyleSheet(QStringLiteral(""));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(9, -1, 9, -1);
        widget_server_info = new QWidget(widget);
        widget_server_info->setObjectName(QStringLiteral("widget_server_info"));
        widget_server_info->setMinimumSize(QSize(0, 20));
        widget_server_info->setMaximumSize(QSize(16777215, 20));
        horizontalLayout_22 = new QHBoxLayout(widget_server_info);
        horizontalLayout_22->setSpacing(0);
        horizontalLayout_22->setObjectName(QStringLiteral("horizontalLayout_22"));
        horizontalLayout_22->setContentsMargins(0, 0, 0, 0);
        label_25 = new QLabel(widget_server_info);
        label_25->setObjectName(QStringLiteral("label_25"));
        QFont font1;
        font1.setFamily(QStringLiteral("OPPOSans B"));
        font1.setPointSize(9);
        font1.setStyleStrategy(QFont::PreferAntialias);
        label_25->setFont(font1);

        horizontalLayout_22->addWidget(label_25);


        verticalLayout_3->addWidget(widget_server_info);

        widget_ip_info = new QWidget(widget);
        widget_ip_info->setObjectName(QStringLiteral("widget_ip_info"));
        widget_ip_info->setMinimumSize(QSize(0, 20));
        widget_ip_info->setMaximumSize(QSize(16777215, 20));
        horizontalLayout_4 = new QHBoxLayout(widget_ip_info);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget_ip_info);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font1);

        horizontalLayout_4->addWidget(label);

        toolButton = new QToolButton(widget_ip_info);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setFont(font1);
        toolButton->setStyleSheet(QLatin1String("QToolButton {\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"	border: none;\n"
"}\n"
"\n"
"QToolButton::menu-indicator { \n"
"	image: None;\n"
"}\n"
"\n"
" \n"
"QToolButton:hover {\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"	border: none;\n"
"}"));

        horizontalLayout_4->addWidget(toolButton);


        verticalLayout_3->addWidget(widget_ip_info);

        widget_run_info = new QWidget(widget);
        widget_run_info->setObjectName(QStringLiteral("widget_run_info"));
        widget_run_info->setMinimumSize(QSize(0, 20));
        widget_run_info->setMaximumSize(QSize(16777215, 20));
        QFont font2;
        font2.setFamily(QStringLiteral("OPPOSans B"));
        font2.setPointSize(10);
        widget_run_info->setFont(font2);
        horizontalLayout_17 = new QHBoxLayout(widget_run_info);
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        horizontalLayout_17->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget_run_info);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font1);

        horizontalLayout_17->addWidget(label_2);


        verticalLayout_3->addWidget(widget_run_info);

        verticalWidget = new QWidget(widget);
        verticalWidget->setObjectName(QStringLiteral("verticalWidget"));
        verticalWidget->setMinimumSize(QSize(0, 60));
        verticalWidget->setMaximumSize(QSize(16777215, 60));
        verticalLayout = new QVBoxLayout(verticalWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_11 = new QLabel(verticalWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setFont(font1);

        verticalLayout->addWidget(label_11);

        label_8 = new QLabel(verticalWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font1);

        verticalLayout->addWidget(label_8);

        label_10 = new QLabel(verticalWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font1);

        verticalLayout->addWidget(label_10);


        verticalLayout_3->addWidget(verticalWidget);

        widget_25 = new QWidget(widget);
        widget_25->setObjectName(QStringLiteral("widget_25"));
        widget_25->setMinimumSize(QSize(0, 20));
        widget_25->setMaximumSize(QSize(16777215, 20));
        horizontalLayout_18 = new QHBoxLayout(widget_25);
        horizontalLayout_18->setSpacing(0);
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        horizontalLayout_18->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(widget_25);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font1);

        horizontalLayout_18->addWidget(label_4);


        verticalLayout_3->addWidget(widget_25);

        widget_cpu_info = new QWidget(widget);
        widget_cpu_info->setObjectName(QStringLiteral("widget_cpu_info"));
        widget_cpu_info->setMinimumSize(QSize(0, 20));
        widget_cpu_info->setMaximumSize(QSize(16777215, 20));
        widget_cpu_info->setStyleSheet(QStringLiteral(""));
        horizontalLayout_14 = new QHBoxLayout(widget_cpu_info);
        horizontalLayout_14->setSpacing(0);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        horizontalLayout_14->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget_cpu_info);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);

        horizontalLayout_14->addWidget(label_3);

        widget_5 = new QWidget(widget_cpu_info);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setMinimumSize(QSize(125, 0));
        widget_5->setMaximumSize(QSize(16777215, 16));
        widget_5->setStyleSheet(QStringLiteral("background-color: rgb(99, 94, 68);"));
        horizontalLayout = new QHBoxLayout(widget_5);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widget_6 = new QWidget(widget_5);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        widget_6->setMaximumSize(QSize(74, 16777215));
        widget_6->setStyleSheet(QStringLiteral("background-color: rgb(0, 255, 0);"));
        horizontalLayout_2 = new QHBoxLayout(widget_6);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(widget_6);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font1);
        label_6->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_2->addWidget(label_6);


        horizontalLayout->addWidget(widget_6);

        widget_7 = new QWidget(widget_5);
        widget_7->setObjectName(QStringLiteral("widget_7"));
        widget_7->setFont(font);
        widget_7->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        horizontalLayout_3 = new QHBoxLayout(widget_7);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(widget_7);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font1);
        label_7->setLayoutDirection(Qt::LeftToRight);
        label_7->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_7);


        horizontalLayout->addWidget(widget_7);


        horizontalLayout_14->addWidget(widget_5);


        verticalLayout_3->addWidget(widget_cpu_info);

        widget_swap_info = new QWidget(widget);
        widget_swap_info->setObjectName(QStringLiteral("widget_swap_info"));
        widget_swap_info->setMinimumSize(QSize(0, 20));
        widget_swap_info->setMaximumSize(QSize(16777215, 20));
        horizontalLayout_16 = new QHBoxLayout(widget_swap_info);
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        horizontalLayout_16->setContentsMargins(0, 0, 0, 0);
        label_17 = new QLabel(widget_swap_info);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setFont(font1);

        horizontalLayout_16->addWidget(label_17);

        widget_18 = new QWidget(widget_swap_info);
        widget_18->setObjectName(QStringLiteral("widget_18"));
        widget_18->setMinimumSize(QSize(125, 0));
        widget_18->setMaximumSize(QSize(16777215, 16));
        widget_18->setStyleSheet(QStringLiteral("background-color: rgb(99, 94, 68);"));
        horizontalLayout_11 = new QHBoxLayout(widget_18);
        horizontalLayout_11->setSpacing(0);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        widget_19 = new QWidget(widget_18);
        widget_19->setObjectName(QStringLiteral("widget_19"));
        widget_19->setMaximumSize(QSize(74, 16777215));
        widget_19->setStyleSheet(QStringLiteral("background-color: rgb(253, 210, 174);"));
        horizontalLayout_12 = new QHBoxLayout(widget_19);
        horizontalLayout_12->setSpacing(0);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        label_18 = new QLabel(widget_19);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setFont(font1);
        label_18->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_12->addWidget(label_18);


        horizontalLayout_11->addWidget(widget_19);

        widget_20 = new QWidget(widget_18);
        widget_20->setObjectName(QStringLiteral("widget_20"));
        widget_20->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        horizontalLayout_13 = new QHBoxLayout(widget_20);
        horizontalLayout_13->setSpacing(0);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(0, 0, 0, 0);
        label_19 = new QLabel(widget_20);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setFont(font1);
        label_19->setLayoutDirection(Qt::LeftToRight);
        label_19->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        label_19->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_13->addWidget(label_19);


        horizontalLayout_11->addWidget(widget_20);


        horizontalLayout_16->addWidget(widget_18);


        verticalLayout_3->addWidget(widget_swap_info);

        widget_mem_info = new QWidget(widget);
        widget_mem_info->setObjectName(QStringLiteral("widget_mem_info"));
        widget_mem_info->setMinimumSize(QSize(0, 20));
        widget_mem_info->setMaximumSize(QSize(16777215, 20));
        horizontalLayout_15 = new QHBoxLayout(widget_mem_info);
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        horizontalLayout_15->setContentsMargins(0, 0, 0, 0);
        label_14 = new QLabel(widget_mem_info);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setFont(font1);

        horizontalLayout_15->addWidget(label_14);

        widget_14 = new QWidget(widget_mem_info);
        widget_14->setObjectName(QStringLiteral("widget_14"));
        widget_14->setMinimumSize(QSize(125, 0));
        widget_14->setMaximumSize(QSize(16777215, 16));
        widget_14->setStyleSheet(QStringLiteral("background-color: rgb(99, 94, 68);"));
        horizontalLayout_8 = new QHBoxLayout(widget_14);
        horizontalLayout_8->setSpacing(0);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        widget_15 = new QWidget(widget_14);
        widget_15->setObjectName(QStringLiteral("widget_15"));
        widget_15->setMaximumSize(QSize(74, 16777215));
        widget_15->setStyleSheet(QStringLiteral("background-color: rgb(253, 210, 174);"));
        horizontalLayout_9 = new QHBoxLayout(widget_15);
        horizontalLayout_9->setSpacing(0);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        label_15 = new QLabel(widget_15);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setFont(font1);
        label_15->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_9->addWidget(label_15);


        horizontalLayout_8->addWidget(widget_15);

        widget_16 = new QWidget(widget_14);
        widget_16->setObjectName(QStringLiteral("widget_16"));
        widget_16->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        horizontalLayout_10 = new QHBoxLayout(widget_16);
        horizontalLayout_10->setSpacing(0);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        label_16 = new QLabel(widget_16);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setFont(font1);
        label_16->setLayoutDirection(Qt::LeftToRight);
        label_16->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        label_16->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_10->addWidget(label_16);


        horizontalLayout_8->addWidget(widget_16);


        horizontalLayout_15->addWidget(widget_14);


        verticalLayout_3->addWidget(widget_mem_info);

        widget_22 = new QWidget(widget);
        widget_22->setObjectName(QStringLiteral("widget_22"));
        widget_22->setMinimumSize(QSize(0, 120));
        widget_22->setMaximumSize(QSize(16777215, 120));
        verticalLayout_2 = new QVBoxLayout(widget_22);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        tableWidget = new QTableWidget(widget_22);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        if (tableWidget->rowCount() < 4)
            tableWidget->setRowCount(4);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setItem(0, 0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setItem(0, 1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setItem(0, 2, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setItem(1, 0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setItem(1, 1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setItem(1, 2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setItem(2, 0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setItem(2, 1, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setItem(2, 2, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setItem(3, 0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setItem(3, 1, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setItem(3, 2, __qtablewidgetitem14);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setMaximumSize(QSize(16777215, 16777215));
        tableWidget->setFont(font1);
        tableWidget->setStyleSheet(QStringLiteral("QHeaderView::section{background-color:transparent;}"));
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setAutoScrollMargin(16);
        tableWidget->setDragEnabled(false);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setShowGrid(false);
        tableWidget->setGridStyle(Qt::NoPen);
        tableWidget->setRowCount(4);
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(true);
        tableWidget->horizontalHeader()->setDefaultSectionSize(57);
        tableWidget->horizontalHeader()->setHighlightSections(false);
        tableWidget->horizontalHeader()->setMinimumSectionSize(25);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setDefaultSectionSize(23);
        tableWidget->verticalHeader()->setHighlightSections(true);
        tableWidget->verticalHeader()->setMinimumSectionSize(25);
        tableWidget->verticalHeader()->setProperty("showSortIndicator", QVariant(false));

        verticalLayout_2->addWidget(tableWidget);


        verticalLayout_3->addWidget(widget_22);

        widget_23 = new QWidget(widget);
        widget_23->setObjectName(QStringLiteral("widget_23"));
        gridLayout = new QGridLayout(widget_23);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setVerticalSpacing(6);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_23 = new QLabel(widget_23);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setFont(font1);

        gridLayout->addWidget(label_23, 3, 0, 1, 1);

        label_20 = new QLabel(widget_23);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setFont(font1);

        gridLayout->addWidget(label_20, 0, 0, 1, 1);

        label_21 = new QLabel(widget_23);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setFont(font1);

        gridLayout->addWidget(label_21, 1, 0, 1, 1);

        label_22 = new QLabel(widget_23);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setFont(font1);

        gridLayout->addWidget(label_22, 2, 0, 1, 1);

        label_28 = new QLabel(widget_23);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setFont(font1);

        gridLayout->addWidget(label_28, 0, 1, 1, 1);

        label_29 = new QLabel(widget_23);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setFont(font1);

        gridLayout->addWidget(label_29, 1, 1, 1, 1);

        label_30 = new QLabel(widget_23);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setFont(font1);

        gridLayout->addWidget(label_30, 2, 1, 1, 1);

        label_31 = new QLabel(widget_23);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setFont(font1);

        gridLayout->addWidget(label_31, 3, 1, 1, 1);


        verticalLayout_3->addWidget(widget_23);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        splitter_1->addWidget(widget);
        widget_26 = new QWidget(splitter_1);
        widget_26->setObjectName(QStringLiteral("widget_26"));
        verticalLayout_6 = new QVBoxLayout(widget_26);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        splitter_2 = new QSplitter(widget_26);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Vertical);
        widget_29 = new QWidget(splitter_2);
        widget_29->setObjectName(QStringLiteral("widget_29"));
        widget_29->setStyleSheet(QStringLiteral("background-color: rgb(175, 255, 246);"));
        horizontalLayout_19 = new QHBoxLayout(widget_29);
        horizontalLayout_19->setSpacing(0);
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        horizontalLayout_19->setContentsMargins(0, 0, 0, 0);
        splitter_3 = new QSplitter(widget_29);
        splitter_3->setObjectName(QStringLiteral("splitter_3"));
        splitter_3->setOrientation(Qt::Horizontal);
        widget_2 = new QWidget(splitter_3);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setStyleSheet(QStringLiteral(""));
        verticalLayout_8 = new QVBoxLayout(widget_2);
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        textEdit = new QTextEdit(widget_2);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy);
        textEdit->setMaximumSize(QSize(16777215, 5555555));
        QFont font3;
        font3.setFamily(QStringLiteral("Cascadia Mono,OPPOSans B"));
        font3.setPointSize(12);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(50);
        textEdit->setFont(font3);
        textEdit->setStyleSheet(QLatin1String("background-color: rgb(0, 41, 69);\n"
"font: 12pt \"Cascadia Mono,OPPOSans B\";\n"
"border: none;\n"
""));
        textEdit->setReadOnly(false);
        textEdit->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse|Qt::TextBrowserInteraction|Qt::TextEditable|Qt::TextEditorInteraction|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        verticalLayout_8->addWidget(textEdit);

        splitter_3->addWidget(widget_2);
        widget_4 = new QWidget(splitter_3);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setStyleSheet(QStringLiteral("background-color: rgb(208, 255, 171);"));
        pushButton = new QPushButton(widget_4);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(60, 180, 75, 23));
        lineEdit = new QLineEdit(widget_4);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(40, 240, 201, 171));
        splitter_3->addWidget(widget_4);

        horizontalLayout_19->addWidget(splitter_3);

        splitter_2->addWidget(widget_29);
        widget_3 = new QWidget(splitter_2);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setStyleSheet(QStringLiteral("background-color: rgb(234, 255, 128);"));
        verticalLayout_7 = new QVBoxLayout(widget_3);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        splitter_4 = new QSplitter(widget_3);
        splitter_4->setObjectName(QStringLiteral("splitter_4"));
        splitter_4->setOrientation(Qt::Horizontal);
        widget_27 = new QWidget(splitter_4);
        widget_27->setObjectName(QStringLiteral("widget_27"));
        widget_27->setMinimumSize(QSize(9, 11));
        widget_27->setStyleSheet(QStringLiteral("background-color: rgb(171, 255, 243);"));
        groupBox = new QGroupBox(widget_27);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 0, 461, 331));
        groupBox->setFont(font);
        splitter_4->addWidget(widget_27);
        widget_28 = new QWidget(splitter_4);
        widget_28->setObjectName(QStringLiteral("widget_28"));
        widget_28->setStyleSheet(QStringLiteral("background-color: rgb(153, 194, 255);"));
        groupBox_2 = new QGroupBox(widget_28);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 0, 461, 331));
        groupBox_2->setFont(font);
        splitter_4->addWidget(widget_28);

        verticalLayout_7->addWidget(splitter_4);

        splitter_2->addWidget(widget_3);

        verticalLayout_6->addWidget(splitter_2);

        splitter_1->addWidget(widget_26);

        verticalLayout_5->addWidget(splitter_1);


        retranslateUi(sshwidget);

        QMetaObject::connectSlotsByName(sshwidget);
    } // setupUi

    void retranslateUi(QWidget *sshwidget)
    {
        sshwidget->setWindowTitle(QApplication::translate("sshwidget", "Form", nullptr));
        label_25->setText(QApplication::translate("sshwidget", "\346\234\215\345\212\241\345\231\250\344\277\241\346\201\257\357\274\232", nullptr));
        label->setText(QApplication::translate("sshwidget", "IP\357\274\232172.16.8.154", nullptr));
        toolButton->setText(QApplication::translate("sshwidget", "\345\244\215\345\210\266", nullptr));
        label_2->setText(QApplication::translate("sshwidget", "\350\277\220\350\241\214\346\227\266\351\227\264 20\345\244\251", nullptr));
        label_11->setText(QApplication::translate("sshwidget", "\347\241\254\344\273\266\346\236\266\346\236\204", nullptr));
        label_8->setText(QApplication::translate("sshwidget", "\347\263\273\347\273\237\347\261\273\345\236\213", nullptr));
        label_10->setText(QApplication::translate("sshwidget", "\346\223\215\344\275\234\347\263\273\347\273\237\345\220\215\347\247\260", nullptr));
        label_4->setText(QApplication::translate("sshwidget", "\347\273\210\347\253\257\347\231\273\345\275\225\346\225\260", nullptr));
        label_3->setText(QApplication::translate("sshwidget", "CPU", nullptr));
        label_6->setText(QApplication::translate("sshwidget", " 29%", nullptr));
        label_7->setText(QApplication::translate("sshwidget", "32G/110.1G ", nullptr));
        label_17->setText(QApplication::translate("sshwidget", "\344\272\244\346\215\242", nullptr));
        label_18->setText(QApplication::translate("sshwidget", " 29%", nullptr));
        label_19->setText(QApplication::translate("sshwidget", "32G/110.1G ", nullptr));
        label_14->setText(QApplication::translate("sshwidget", "\345\206\205\345\255\230", nullptr));
        label_15->setText(QApplication::translate("sshwidget", " 29%", nullptr));
        label_16->setText(QApplication::translate("sshwidget", "32G/110.1G ", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("sshwidget", "\345\206\205\345\255\230", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("sshwidget", "CPU", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("sshwidget", "\345\221\275\344\273\244", nullptr));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->item(0, 0);
        ___qtablewidgetitem3->setText(QApplication::translate("sshwidget", "231", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->item(0, 1);
        ___qtablewidgetitem4->setText(QApplication::translate("sshwidget", "321", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->item(0, 2);
        ___qtablewidgetitem5->setText(QApplication::translate("sshwidget", "321", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->item(1, 0);
        ___qtablewidgetitem6->setText(QApplication::translate("sshwidget", "321", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->item(1, 1);
        ___qtablewidgetitem7->setText(QApplication::translate("sshwidget", "321", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->item(1, 2);
        ___qtablewidgetitem8->setText(QApplication::translate("sshwidget", "321", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->item(2, 0);
        ___qtablewidgetitem9->setText(QApplication::translate("sshwidget", "321", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->item(2, 1);
        ___qtablewidgetitem10->setText(QApplication::translate("sshwidget", "321", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->item(2, 2);
        ___qtablewidgetitem11->setText(QApplication::translate("sshwidget", "321", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->item(3, 0);
        ___qtablewidgetitem12->setText(QApplication::translate("sshwidget", "321", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->item(3, 1);
        ___qtablewidgetitem13->setText(QApplication::translate("sshwidget", "321", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->item(3, 2);
        ___qtablewidgetitem14->setText(QApplication::translate("sshwidget", "321", nullptr));
        tableWidget->setSortingEnabled(__sortingEnabled);

        label_23->setText(QApplication::translate("sshwidget", "\350\267\257\345\276\204", nullptr));
        label_20->setText(QApplication::translate("sshwidget", "\350\267\257\345\276\204", nullptr));
        label_21->setText(QApplication::translate("sshwidget", "\350\267\257\345\276\204", nullptr));
        label_22->setText(QApplication::translate("sshwidget", "\350\267\257\345\276\204", nullptr));
        label_28->setText(QApplication::translate("sshwidget", "\345\217\257\347\224\250/\345\244\247\345\260\217", nullptr));
        label_29->setText(QApplication::translate("sshwidget", "\345\217\257\347\224\250\345\244\247\345\260\217", nullptr));
        label_30->setText(QApplication::translate("sshwidget", "\345\217\257\347\224\250\345\244\247\345\260\217", nullptr));
        label_31->setText(QApplication::translate("sshwidget", "\345\217\257\347\224\250\345\244\247\345\260\217", nullptr));
        textEdit->setHtml(QApplication::translate("sshwidget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Cascadia Mono,OPPOSans B'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Cascadia Mono,OPPOSans R';\"><br /></p></body></html>", nullptr));
        pushButton->setText(QApplication::translate("sshwidget", "PushButton", nullptr));
        groupBox->setTitle(QApplication::translate("sshwidget", "\345\221\275\344\273\244", nullptr));
        groupBox_2->setTitle(QApplication::translate("sshwidget", "\345\221\275\344\273\244\347\274\226\350\276\221\345\231\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class sshwidget: public Ui_sshwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SSHWIDGET_H
