/********************************************************************************
** Form generated from reading UI file 'sshwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SSHWIDGET_H
#define UI_SSHWIDGET_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_sshwidget
{
public:
    QHBoxLayout *horizontalLayout_19;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_server_info;
    QHBoxLayout *horizontalLayout_22;
    QLabel *label_serverTitle;
    QWidget *widget_ip_info;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_ip;
    QToolButton *toolButton;
    QWidget *widget_30;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label_time;
    QWidget *widget_run_info;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_runTime;
    QWidget *widget_25;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_loginCount;
    QWidget *verticalWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_architecture;
    QLabel *label_systemType;
    QWidget *widget_cpu_info;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_3;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_cpuUseRate;
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
    QLabel *label_memUseRate;
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
    QLabel *label_swapUseRate;
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
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_21;
    QWidget *widget_26;
    QVBoxLayout *verticalLayout_6;
    QSplitter *splitter_2;
    QWidget *widget_29;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_14;
    QWidget *widget_10;
    QVBoxLayout *verticalLayout_5;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_8;
    QWidget *widget_9;
    QTextEdit *textEdit;
    QWidget *widget_toolbar;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_toolbar_s;
    QHBoxLayout *horizontalLayout_6;
    QToolButton *toolButton_info;
    QToolButton *toolButton_find;
    QToolButton *toolButton_history;
    QToolButton *toolButton_upload;
    QToolButton *toolButton_toolkit;
    QToolButton *toolButton_command;
    QToolButton *toolButton_conectStats;
    QToolButton *toolButton_fullScreen;
    QSpacerItem *horizontalSpacer_3;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_7;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *gridWidget;
    QGridLayout *gridLayout_2;
    QToolButton *toolButton_3;
    QToolButton *toolButton_4;
    QToolButton *toolButton_6;
    QToolButton *toolButton_5;
    QToolButton *toolButton_8;
    QToolButton *toolButton_7;
    QWidget *tab_2;
    QWidget *tab_3;
    QTextEdit *textEdit_2;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QHBoxLayout *horizontalLayout_23;
    QTextEdit *textEdit_3;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QLabel *label_2;
    QToolButton *toolButton_2;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *sshwidget)
    {
        if (sshwidget->objectName().isEmpty())
            sshwidget->setObjectName(QStringLiteral("sshwidget"));
        sshwidget->resize(1391, 699);
        sshwidget->setStyleSheet(QStringLiteral("background-color: rgb(30, 45, 54);"));
        sshwidget->setLocale(QLocale(QLocale::English, QLocale::Kenya));
        horizontalLayout_19 = new QHBoxLayout(sshwidget);
        horizontalLayout_19->setSpacing(0);
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        horizontalLayout_19->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(sshwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(170, 0));
        widget->setMaximumSize(QSize(170, 16777215));
        QFont font;
        font.setFamily(QStringLiteral("OPPOSans B"));
        font.setPointSize(10);
        font.setStyleStrategy(QFont::PreferAntialias);
        widget->setFont(font);
        widget->setStyleSheet(QLatin1String("#widget{\n"
"border-right:2px solid rgb(108, 117, 125, 65); \n"
"}"));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(7, 10, 7, 5);
        widget_server_info = new QWidget(widget);
        widget_server_info->setObjectName(QStringLiteral("widget_server_info"));
        widget_server_info->setMinimumSize(QSize(0, 20));
        widget_server_info->setMaximumSize(QSize(16777215, 20));
        horizontalLayout_22 = new QHBoxLayout(widget_server_info);
        horizontalLayout_22->setSpacing(0);
        horizontalLayout_22->setObjectName(QStringLiteral("horizontalLayout_22"));
        horizontalLayout_22->setContentsMargins(0, 0, 0, 0);
        label_serverTitle = new QLabel(widget_server_info);
        label_serverTitle->setObjectName(QStringLiteral("label_serverTitle"));
        QFont font1;
        font1.setFamily(QStringLiteral("OPPOSans B"));
        font1.setPointSize(9);
        font1.setStyleStrategy(QFont::PreferAntialias);
        label_serverTitle->setFont(font1);

        horizontalLayout_22->addWidget(label_serverTitle);


        verticalLayout_3->addWidget(widget_server_info);

        widget_ip_info = new QWidget(widget);
        widget_ip_info->setObjectName(QStringLiteral("widget_ip_info"));
        widget_ip_info->setMinimumSize(QSize(0, 20));
        widget_ip_info->setMaximumSize(QSize(16777215, 20));
        horizontalLayout_4 = new QHBoxLayout(widget_ip_info);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_ip = new QLabel(widget_ip_info);
        label_ip->setObjectName(QStringLiteral("label_ip"));
        label_ip->setFont(font1);

        horizontalLayout_4->addWidget(label_ip);

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

        widget_30 = new QWidget(widget);
        widget_30->setObjectName(QStringLiteral("widget_30"));
        widget_30->setMinimumSize(QSize(0, 20));
        widget_30->setMaximumSize(QSize(16777215, 20));
        horizontalLayout_20 = new QHBoxLayout(widget_30);
        horizontalLayout_20->setSpacing(0);
        horizontalLayout_20->setObjectName(QStringLiteral("horizontalLayout_20"));
        horizontalLayout_20->setContentsMargins(0, 0, 0, 0);
        label_time = new QLabel(widget_30);
        label_time->setObjectName(QStringLiteral("label_time"));
        label_time->setFont(font1);

        horizontalLayout_20->addWidget(label_time);


        verticalLayout_3->addWidget(widget_30);

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
        label_runTime = new QLabel(widget_run_info);
        label_runTime->setObjectName(QStringLiteral("label_runTime"));
        label_runTime->setFont(font1);

        horizontalLayout_17->addWidget(label_runTime);


        verticalLayout_3->addWidget(widget_run_info);

        widget_25 = new QWidget(widget);
        widget_25->setObjectName(QStringLiteral("widget_25"));
        widget_25->setMinimumSize(QSize(0, 20));
        widget_25->setMaximumSize(QSize(16777215, 20));
        horizontalLayout_18 = new QHBoxLayout(widget_25);
        horizontalLayout_18->setSpacing(0);
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        horizontalLayout_18->setContentsMargins(0, 0, 0, 0);
        label_loginCount = new QLabel(widget_25);
        label_loginCount->setObjectName(QStringLiteral("label_loginCount"));
        label_loginCount->setFont(font1);

        horizontalLayout_18->addWidget(label_loginCount);


        verticalLayout_3->addWidget(widget_25);

        verticalWidget = new QWidget(widget);
        verticalWidget->setObjectName(QStringLiteral("verticalWidget"));
        verticalWidget->setMinimumSize(QSize(0, 40));
        verticalWidget->setMaximumSize(QSize(16777215, 40));
        verticalLayout = new QVBoxLayout(verticalWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_architecture = new QLabel(verticalWidget);
        label_architecture->setObjectName(QStringLiteral("label_architecture"));
        label_architecture->setFont(font1);

        verticalLayout->addWidget(label_architecture);

        label_systemType = new QLabel(verticalWidget);
        label_systemType->setObjectName(QStringLiteral("label_systemType"));
        label_systemType->setFont(font1);

        verticalLayout->addWidget(label_systemType);


        verticalLayout_3->addWidget(verticalWidget);

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
        widget_5->setMaximumSize(QSize(16777215, 12));
        widget_5->setStyleSheet(QStringLiteral("background-color: rgb(99, 94, 68);"));
        horizontalLayout = new QHBoxLayout(widget_5);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widget_6 = new QWidget(widget_5);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        widget_6->setMaximumSize(QSize(60, 12));
        widget_6->setStyleSheet(QStringLiteral("background-color: rgb(0, 255, 0);"));
        horizontalLayout_2 = new QHBoxLayout(widget_6);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_cpuUseRate = new QLabel(widget_6);
        label_cpuUseRate->setObjectName(QStringLiteral("label_cpuUseRate"));
        label_cpuUseRate->setMaximumSize(QSize(16777215, 16777215));
        label_cpuUseRate->setFont(font1);
        label_cpuUseRate->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_2->addWidget(label_cpuUseRate);


        horizontalLayout->addWidget(widget_6);

        widget_7 = new QWidget(widget_5);
        widget_7->setObjectName(QStringLiteral("widget_7"));
        widget_7->setMaximumSize(QSize(16777215, 12));
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
        widget_18->setMaximumSize(QSize(16777215, 12));
        widget_18->setStyleSheet(QStringLiteral("background-color: rgb(99, 94, 68);"));
        horizontalLayout_11 = new QHBoxLayout(widget_18);
        horizontalLayout_11->setSpacing(0);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        widget_19 = new QWidget(widget_18);
        widget_19->setObjectName(QStringLiteral("widget_19"));
        widget_19->setMaximumSize(QSize(74, 12));
        widget_19->setStyleSheet(QStringLiteral("background-color: rgb(253, 210, 174);"));
        horizontalLayout_12 = new QHBoxLayout(widget_19);
        horizontalLayout_12->setSpacing(0);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        label_memUseRate = new QLabel(widget_19);
        label_memUseRate->setObjectName(QStringLiteral("label_memUseRate"));
        label_memUseRate->setFont(font1);
        label_memUseRate->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_12->addWidget(label_memUseRate);


        horizontalLayout_11->addWidget(widget_19);

        widget_20 = new QWidget(widget_18);
        widget_20->setObjectName(QStringLiteral("widget_20"));
        widget_20->setMaximumSize(QSize(16777215, 12));
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
        widget_14->setMaximumSize(QSize(125, 12));
        widget_14->setStyleSheet(QStringLiteral("background-color: rgb(99, 94, 68);"));
        horizontalLayout_8 = new QHBoxLayout(widget_14);
        horizontalLayout_8->setSpacing(0);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        widget_15 = new QWidget(widget_14);
        widget_15->setObjectName(QStringLiteral("widget_15"));
        widget_15->setMaximumSize(QSize(74, 12));
        widget_15->setStyleSheet(QStringLiteral("background-color: rgb(253, 210, 174);"));
        horizontalLayout_9 = new QHBoxLayout(widget_15);
        horizontalLayout_9->setSpacing(0);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        label_swapUseRate = new QLabel(widget_15);
        label_swapUseRate->setObjectName(QStringLiteral("label_swapUseRate"));
        label_swapUseRate->setFont(font1);
        label_swapUseRate->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_9->addWidget(label_swapUseRate);


        horizontalLayout_8->addWidget(widget_15);

        widget_16 = new QWidget(widget_14);
        widget_16->setObjectName(QStringLiteral("widget_16"));
        widget_16->setMaximumSize(QSize(16777215, 12));
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
        widget_22->setMinimumSize(QSize(0, 90));
        widget_22->setMaximumSize(QSize(16777215, 90));
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

        widget_4 = new QWidget(widget);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setMinimumSize(QSize(0, 33));
        horizontalLayout_21 = new QHBoxLayout(widget_4);
        horizontalLayout_21->setObjectName(QStringLiteral("horizontalLayout_21"));

        verticalLayout_3->addWidget(widget_4);


        horizontalLayout_19->addWidget(widget);

        widget_26 = new QWidget(sshwidget);
        widget_26->setObjectName(QStringLiteral("widget_26"));
        verticalLayout_6 = new QVBoxLayout(widget_26);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        splitter_2 = new QSplitter(widget_26);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Vertical);
        splitter_2->setHandleWidth(0);
        widget_29 = new QWidget(splitter_2);
        widget_29->setObjectName(QStringLiteral("widget_29"));
        widget_29->setMinimumSize(QSize(0, 0));
        widget_29->setStyleSheet(QStringLiteral(""));
        verticalLayout_4 = new QVBoxLayout(widget_29);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(widget_29);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setStyleSheet(QStringLiteral(""));
        verticalLayout_14 = new QVBoxLayout(widget_2);
        verticalLayout_14->setSpacing(0);
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        verticalLayout_14->setContentsMargins(0, 0, 0, 0);
        widget_10 = new QWidget(widget_2);
        widget_10->setObjectName(QStringLiteral("widget_10"));
        verticalLayout_5 = new QVBoxLayout(widget_10);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(widget_10);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setMinimumSize(QSize(0, 0));
        scrollArea->setStyleSheet(QStringLiteral("border:0px solid #838486;  "));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1221, 373));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy);
        scrollAreaWidgetContents->setMinimumSize(QSize(0, 0));
        scrollAreaWidgetContents->setMaximumSize(QSize(16777215, 1080));
        scrollAreaWidgetContents->setStyleSheet(QLatin1String("border-color: rgba(255, 255, 255, 0);\n"
"background:transparent;"));
        verticalLayout_8 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        widget_9 = new QWidget(scrollAreaWidgetContents);
        widget_9->setObjectName(QStringLiteral("widget_9"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget_9->sizePolicy().hasHeightForWidth());
        widget_9->setSizePolicy(sizePolicy1);
        textEdit = new QTextEdit(widget_9);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setEnabled(true);
        textEdit->setGeometry(QRect(10, 20, 151, 161));
        sizePolicy1.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy1);
        textEdit->setMaximumSize(QSize(16777215, 5555555));
        QFont font3;
        font3.setFamily(QStringLiteral("Cascadia Mono,OPPOSans B"));
        font3.setPointSize(12);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(50);
        font3.setStyleStrategy(QFont::PreferAntialias);
        textEdit->setFont(font3);
        textEdit->setStyleSheet(QString::fromUtf8("QTextEdit{\n"
"	background-color: rgba(0, 41, 69, 0);\n"
"	font: 12pt \"Cascadia Mono,OPPOSans B\";\n"
"	border: none;\n"
"	padding-top:0px;\n"
"    padding-bottom:0px;\n"
"	padding-left:0px;\n"
"    padding-right:0px;\n"
"color: rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
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
"    background-color: rgba(25"
                        "5, 255, 255, 0);\n"
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
        textEdit->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        textEdit->setReadOnly(false);
        textEdit->setTextInteractionFlags(Qt::TextEditorInteraction);

        verticalLayout_8->addWidget(widget_9);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_5->addWidget(scrollArea);


        verticalLayout_14->addWidget(widget_10);

        widget_toolbar = new QWidget(widget_2);
        widget_toolbar->setObjectName(QStringLiteral("widget_toolbar"));
        widget_toolbar->setMinimumSize(QSize(0, 40));
        widget_toolbar->setMaximumSize(QSize(16777215, 40));
        widget_toolbar->setStyleSheet(QLatin1String("#widget_toolbar{\n"
"background-color: rgb(30, 45, 54);\n"
"border-bottom:2px solid rgb(108, 117, 125, 65); \n"
"}\n"
""));
        horizontalLayout_7 = new QHBoxLayout(widget_toolbar);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 9);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_2);

        widget_toolbar_s = new QWidget(widget_toolbar);
        widget_toolbar_s->setObjectName(QStringLiteral("widget_toolbar_s"));
        widget_toolbar_s->setMinimumSize(QSize(450, 30));
        widget_toolbar_s->setMaximumSize(QSize(450, 30));
        widget_toolbar_s->setStyleSheet(QLatin1String("background-color: rgba(11, 11, 11,150);\n"
"border-radius: 10px;"));
        horizontalLayout_6 = new QHBoxLayout(widget_toolbar_s);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        toolButton_info = new QToolButton(widget_toolbar_s);
        toolButton_info->setObjectName(QStringLiteral("toolButton_info"));
        toolButton_info->setFont(font);
        toolButton_info->setStyleSheet(QLatin1String("QToolButton {\n"
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

        horizontalLayout_6->addWidget(toolButton_info);

        toolButton_find = new QToolButton(widget_toolbar_s);
        toolButton_find->setObjectName(QStringLiteral("toolButton_find"));
        toolButton_find->setFont(font);
        toolButton_find->setStyleSheet(QLatin1String("QToolButton {\n"
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

        horizontalLayout_6->addWidget(toolButton_find);

        toolButton_history = new QToolButton(widget_toolbar_s);
        toolButton_history->setObjectName(QStringLiteral("toolButton_history"));
        toolButton_history->setFont(font);
        toolButton_history->setStyleSheet(QLatin1String("QToolButton {\n"
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

        horizontalLayout_6->addWidget(toolButton_history);

        toolButton_upload = new QToolButton(widget_toolbar_s);
        toolButton_upload->setObjectName(QStringLiteral("toolButton_upload"));
        toolButton_upload->setFont(font);
        toolButton_upload->setStyleSheet(QLatin1String("QToolButton {\n"
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

        horizontalLayout_6->addWidget(toolButton_upload);

        toolButton_toolkit = new QToolButton(widget_toolbar_s);
        toolButton_toolkit->setObjectName(QStringLiteral("toolButton_toolkit"));
        toolButton_toolkit->setFont(font);
        toolButton_toolkit->setStyleSheet(QLatin1String("QToolButton {\n"
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

        horizontalLayout_6->addWidget(toolButton_toolkit);

        toolButton_command = new QToolButton(widget_toolbar_s);
        toolButton_command->setObjectName(QStringLiteral("toolButton_command"));
        toolButton_command->setFont(font);
        toolButton_command->setStyleSheet(QLatin1String("QToolButton {\n"
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

        horizontalLayout_6->addWidget(toolButton_command);

        toolButton_conectStats = new QToolButton(widget_toolbar_s);
        toolButton_conectStats->setObjectName(QStringLiteral("toolButton_conectStats"));
        toolButton_conectStats->setFont(font);
        toolButton_conectStats->setStyleSheet(QLatin1String("QToolButton {\n"
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

        horizontalLayout_6->addWidget(toolButton_conectStats);

        toolButton_fullScreen = new QToolButton(widget_toolbar_s);
        toolButton_fullScreen->setObjectName(QStringLiteral("toolButton_fullScreen"));
        toolButton_fullScreen->setFont(font);
        toolButton_fullScreen->setStyleSheet(QLatin1String("QToolButton {\n"
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

        horizontalLayout_6->addWidget(toolButton_fullScreen);


        horizontalLayout_7->addWidget(widget_toolbar_s);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_3);


        verticalLayout_14->addWidget(widget_toolbar);


        verticalLayout_4->addWidget(widget_2);

        splitter_2->addWidget(widget_29);
        widget_3 = new QWidget(splitter_2);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMinimumSize(QSize(0, 0));
        widget_3->setStyleSheet(QLatin1String("#widget_3 {\n"
"	background-color: rgba(11, 11, 11,0);\n"
"	border-radius: 10px;\n"
"}\n"
""));
        verticalLayout_7 = new QVBoxLayout(widget_3);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(5, 5, 5, 5);
        tabWidget = new QTabWidget(widget_3);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setFont(font);
        tabWidget->setStyleSheet(QString::fromUtf8("\n"
" QTabWidget::tab-bar {\n"
"         left:0px;       \n"
"}\n"
"	\n"
" \n"
"/*\350\256\276\347\275\256TabWidget\344\270\255QTabBar\347\232\204\346\240\267\345\274\217*/\n"
"QTabBar::tab{\n"
"    background-color: rgba(11, 11, 11,150);\n"
"	/*font-family:Consolas; */   /*\350\256\276\347\275\256tab\344\270\255\347\232\204\346\226\207\346\234\254\347\232\204\345\255\227\344\275\223*/\n"
"	font-size:10pt;\n"
"	color:#ced4da;    /*\350\256\276\347\275\256tab\344\270\255\347\232\204\346\226\207\346\234\254\347\232\204\351\242\234\350\211\262*/\n"
"	border-top-left-radius: 5px;    /*\350\256\276\347\275\256tab\347\232\204\350\276\271\346\241\206\347\232\204\345\234\206\350\247\222\357\274\210\345\267\246\344\270\212\345\234\206\350\247\222\357\274\211*/\n"
"	border-top-right-radius: 5px;    /*\350\256\276\347\275\256tab\347\232\204\350\276\271\346\241\206\347\232\204\345\234\206\350\247\222\357\274\210\345\217\263\344\270\212\345\234\206\350\247\222\357\274\211*/\n"
"	/*width:120px;*/\n"
"	padding: 4px;\n"
"	mar"
                        "gin-right:0px;\n"
"	margin-left: 0px;\n"
"}\n"
" \n"
"/*\350\256\276\347\275\256TabWidget\344\270\255QTabBar\347\232\204tab\350\242\253\351\200\211\344\270\255\346\227\266\347\232\204\346\240\267\345\274\217*/\n"
"QTabBar::tab:selected{\n"
"	/*background-color: #0B0E11;*/\n"
"    /*background-color: rgb(100, 117, 125, 255);*/\n"
"	\n"
"	background-color: rgb(15, 15, 15);\n"
"    /*border-left: 2px solid rgb(255, 255, 255);*/\n"
"    /*border-right: 2px solid rgb(255, 255, 255);*/\n"
"}\n"
" \n"
"/*\350\256\276\347\275\256TabWidget\344\270\255\351\274\240\346\240\207\346\202\254\346\265\256\345\234\250QTabBar\347\232\204tab\344\270\212\357\274\214\344\275\206\346\234\252\351\200\211\344\270\255\350\257\245Tab\347\232\204\346\240\267\345\274\217*/\n"
"QTabBar::tab:hover:!selected {\n"
"	background-color: rgb(100, 117, 125, 255);\n"
"}\n"
" \n"
"/*\350\256\276\347\275\256TabWidget\347\232\204\350\276\271\346\241\206\347\232\204\346\240\267\345\274\217*/\n"
"QTabWidget::pane {\n"
"    border-top:2px solid rgba(11,"
                        " 11, 11,0);\n"
"}\n"
" \n"
"\n"
"QTabBar::close-button{ \n"
"	/*border-image: url(:lib/Kafka.png);*/\n"
"}\n"
"QTabBar::close-button:hover{\n"
"	/*border-image: url(:/Resources/image/close_hover.png);*/\n"
"}\n"
"\n"
"\n"
"/*\345\275\223\346\211\223\345\274\200\345\244\232\344\270\252tab\357\274\214\345\217\263\344\276\247\345\207\272\347\216\260\357\274\214\347\202\271\345\207\273\345\220\216\357\274\214\345\217\257\344\273\245\345\220\221\345\211\215\345\220\221\345\220\216\347\232\204\346\214\211\351\222\256\347\232\204\346\240\267\345\274\217*/\n"
"QTabBar QToolButton {\n"
"    border: none;\n"
"	color: rgb(255, 206, 6);\n"
"    background-color: rgba(100, 117, 125, 0);\n"
"}\n"
" \n"
"QTabBar QToolButton:hover {\n"
"	background-color: rgba(100, 117, 125, 0);\n"
"}"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridWidget = new QWidget(tab);
        gridWidget->setObjectName(QStringLiteral("gridWidget"));
        gridWidget->setGeometry(QRect(-1, -1, 301, 31));
        gridWidget->setStyleSheet(QLatin1String("QToolButton {\n"
"	\n"
"	color: rgb(217, 236, 237);\n"
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
        gridLayout_2 = new QGridLayout(gridWidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        toolButton_3 = new QToolButton(gridWidget);
        toolButton_3->setObjectName(QStringLiteral("toolButton_3"));
        toolButton_3->setFont(font);

        gridLayout_2->addWidget(toolButton_3, 0, 0, 1, 1);

        toolButton_4 = new QToolButton(gridWidget);
        toolButton_4->setObjectName(QStringLiteral("toolButton_4"));
        toolButton_4->setFont(font);

        gridLayout_2->addWidget(toolButton_4, 0, 1, 1, 1);

        toolButton_6 = new QToolButton(gridWidget);
        toolButton_6->setObjectName(QStringLiteral("toolButton_6"));
        toolButton_6->setFont(font);

        gridLayout_2->addWidget(toolButton_6, 0, 3, 1, 1);

        toolButton_5 = new QToolButton(gridWidget);
        toolButton_5->setObjectName(QStringLiteral("toolButton_5"));
        toolButton_5->setFont(font);

        gridLayout_2->addWidget(toolButton_5, 0, 2, 1, 1);

        toolButton_8 = new QToolButton(gridWidget);
        toolButton_8->setObjectName(QStringLiteral("toolButton_8"));
        toolButton_8->setFont(font);

        gridLayout_2->addWidget(toolButton_8, 0, 4, 1, 1);

        toolButton_7 = new QToolButton(gridWidget);
        toolButton_7->setObjectName(QStringLiteral("toolButton_7"));
        toolButton_7->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/lib/setting.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_7->setIcon(icon);
        toolButton_7->setIconSize(QSize(16, 16));
        toolButton_7->setPopupMode(QToolButton::DelayedPopup);
        toolButton_7->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        gridLayout_2->addWidget(toolButton_7, 0, 5, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        textEdit_2 = new QTextEdit(tab_3);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(10, 10, 561, 211));
        textEdit_2->setReadOnly(true);
        scrollArea_2 = new QScrollArea(tab_3);
        scrollArea_2->setObjectName(QStringLiteral("scrollArea_2"));
        scrollArea_2->setGeometry(QRect(580, 160, 461, 61));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 500, 89));
        scrollAreaWidgetContents_2->setMinimumSize(QSize(500, 0));
        horizontalLayout_23 = new QHBoxLayout(scrollAreaWidgetContents_2);
        horizontalLayout_23->setObjectName(QStringLiteral("horizontalLayout_23"));
        textEdit_3 = new QTextEdit(scrollAreaWidgetContents_2);
        textEdit_3->setObjectName(QStringLiteral("textEdit_3"));

        horizontalLayout_23->addWidget(textEdit_3);

        scrollArea_2->setWidget(scrollAreaWidgetContents_2);
        lineEdit = new QLineEdit(tab_3);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(610, 20, 221, 31));
        pushButton = new QPushButton(tab_3);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(850, 20, 75, 31));
        tabWidget->addTab(tab_3, QString());

        verticalLayout_7->addWidget(tabWidget);

        widget_8 = new QWidget(widget_3);
        widget_8->setObjectName(QStringLiteral("widget_8"));
        widget_8->setMinimumSize(QSize(0, 20));
        widget_8->setMaximumSize(QSize(16777215, 18));
        widget_8->setFont(font);
        widget_8->setStyleSheet(QStringLiteral(""));
        horizontalLayout_5 = new QHBoxLayout(widget_8);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget_8);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);
        label->setStyleSheet(QLatin1String("background-color: rgb(80, 130, 120);\n"
"color: rgb(255, 255, 255);"));
        label->setLineWidth(1);
        label->setMargin(3);
        label->setIndent(0);

        horizontalLayout_5->addWidget(label);

        label_2 = new QLabel(widget_8);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);
        label_2->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_2->setMargin(2);

        horizontalLayout_5->addWidget(label_2);

        toolButton_2 = new QToolButton(widget_8);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        toolButton_2->setMinimumSize(QSize(0, 0));
        toolButton_2->setFont(font);
        toolButton_2->setStyleSheet(QLatin1String("QToolButton {\n"
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

        horizontalLayout_5->addWidget(toolButton_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);


        verticalLayout_7->addWidget(widget_8);

        splitter_2->addWidget(widget_3);

        verticalLayout_6->addWidget(splitter_2);


        horizontalLayout_19->addWidget(widget_26);


        retranslateUi(sshwidget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(sshwidget);
    } // setupUi

    void retranslateUi(QWidget *sshwidget)
    {
        sshwidget->setWindowTitle(QApplication::translate("sshwidget", "Form", nullptr));
        label_serverTitle->setText(QApplication::translate("sshwidget", "\346\234\215\345\212\241\345\231\250\344\277\241\346\201\257", nullptr));
        label_ip->setText(QApplication::translate("sshwidget", "IP", nullptr));
        toolButton->setText(QApplication::translate("sshwidget", "\345\244\215\345\210\266", nullptr));
        label_time->setText(QApplication::translate("sshwidget", "\347\263\273\347\273\237\346\227\266\351\227\264", nullptr));
        label_runTime->setText(QApplication::translate("sshwidget", "\350\277\220\350\241\214\346\227\266\351\227\264", nullptr));
        label_loginCount->setText(QApplication::translate("sshwidget", "\347\273\210\347\253\257\350\277\236\346\216\245", nullptr));
        label_architecture->setText(QApplication::translate("sshwidget", "\347\241\254\344\273\266\346\236\266\346\236\204", nullptr));
        label_systemType->setText(QApplication::translate("sshwidget", "\347\263\273\347\273\237\347\261\273\345\236\213", nullptr));
        label_3->setText(QApplication::translate("sshwidget", "CPU", nullptr));
        label_cpuUseRate->setText(QApplication::translate("sshwidget", " 29%", nullptr));
        label_7->setText(QApplication::translate("sshwidget", "32G/110.1G ", nullptr));
        label_17->setText(QApplication::translate("sshwidget", "\344\272\244\346\215\242", nullptr));
        label_memUseRate->setText(QApplication::translate("sshwidget", " 29%", nullptr));
        label_19->setText(QApplication::translate("sshwidget", "32G/110.1G ", nullptr));
        label_14->setText(QApplication::translate("sshwidget", "\345\206\205\345\255\230", nullptr));
        label_swapUseRate->setText(QApplication::translate("sshwidget", " 29%", nullptr));
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
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        toolButton_info->setText(QApplication::translate("sshwidget", "\344\277\241\346\201\257", nullptr));
        toolButton_find->setText(QApplication::translate("sshwidget", "\346\237\245\346\211\276", nullptr));
        toolButton_history->setText(QApplication::translate("sshwidget", "\345\216\206\345\217\262", nullptr));
        toolButton_upload->setText(QApplication::translate("sshwidget", "\344\270\212\344\274\240", nullptr));
        toolButton_toolkit->setText(QApplication::translate("sshwidget", "\345\267\245\345\205\267\351\233\206", nullptr));
        toolButton_command->setText(QApplication::translate("sshwidget", "\345\221\275\344\273\244", nullptr));
        toolButton_conectStats->setText(QApplication::translate("sshwidget", "\345\261\236\346\200\247", nullptr));
        toolButton_fullScreen->setText(QApplication::translate("sshwidget", "\345\205\250\345\261\217", nullptr));
        toolButton_3->setText(QApplication::translate("sshwidget", "\350\277\230\345\216\237", nullptr));
        toolButton_4->setText(QApplication::translate("sshwidget", "\346\212\223\345\214\205", nullptr));
        toolButton_6->setText(QApplication::translate("sshwidget", "\346\212\223\345\214\205", nullptr));
        toolButton_5->setText(QApplication::translate("sshwidget", "\346\212\223\345\214\205", nullptr));
        toolButton_8->setText(QApplication::translate("sshwidget", "\346\212\223\345\214\205", nullptr));
        toolButton_7->setText(QApplication::translate("sshwidget", "\346\212\223\345\214\205", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("sshwidget", "\351\273\230\350\256\244\345\210\206\347\261\273", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("sshwidget", "minic", nullptr));
        textEdit_2->setHtml(QApplication::translate("sshwidget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">454545456</p></body></html>", nullptr));
        textEdit_3->setHtml(QApplication::translate("sshwidget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">111111111111111</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">111111111111111111111111111111111111111111111</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">111111111111111</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">111111111111111111111111111111</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; mar"
                        "gin-right:0px; -qt-block-indent:0; text-indent:0px;\">111111111111111</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">111111111111111</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">111111111111111111111111111111111111111111111111111111111111</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">111111111111111</p></body></html>", nullptr));
        pushButton->setText(QApplication::translate("sshwidget", "PushButton", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("sshwidget", "11111111111111111111111111", nullptr));
        label->setText(QApplication::translate("sshwidget", "\346\211\247\350\241\214\345\244\207\344\273\275", nullptr));
        label_2->setText(QApplication::translate("sshwidget", "/data/linkdood/im/bin/databack/databak -c ", nullptr));
        toolButton_2->setText(QApplication::translate("sshwidget", "\347\274\226\350\276\221", nullptr));
    } // retranslateUi

};

namespace Ui {
    class sshwidget: public Ui_sshwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SSHWIDGET_H
