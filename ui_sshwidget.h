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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
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
    QWidget *widget_26;
    QVBoxLayout *verticalLayout_6;
    QSplitter *splitter_2;
    QWidget *widget_29;
    QHBoxLayout *horizontalLayout_19;
    QSplitter *splitter_3;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_8;
    QWidget *widget_10;
    QTextEdit *textEdit;
    QTextEdit *textEdit_6;
    QWidget *horizontalWidget;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *lineEdit;
    QToolButton *toolButton_12;
    QToolButton *toolButton_11;
    QToolButton *toolButton_9;
    QToolButton *toolButton_10;
    QSpacerItem *horizontalSpacer_3;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_12;
    QTextEdit *textEdit_3;
    QTextBrowser *textBrowser;
    QVBoxLayout *verticalLayout_13;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QWidget *widget_9;
    QTextEdit *textEdit_4;
    QTextEdit *textEdit_5;
    QPushButton *pushButton;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_7;
    QSplitter *splitter_4;
    QWidget *widget_27;
    QVBoxLayout *verticalLayout_9;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_4;
    QTabWidget *tabWidget;
    QWidget *tab;
    QToolButton *toolButton_3;
    QToolButton *toolButton_4;
    QToolButton *toolButton_5;
    QToolButton *toolButton_6;
    QToolButton *toolButton_7;
    QToolButton *toolButton_8;
    QWidget *tab_2;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QLabel *label_2;
    QToolButton *toolButton_2;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_28;
    QVBoxLayout *verticalLayout_10;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_11;
    QTextEdit *textEdit_2;

    void setupUi(QWidget *sshwidget)
    {
        if (sshwidget->objectName().isEmpty())
            sshwidget->setObjectName(QStringLiteral("sshwidget"));
        sshwidget->resize(1391, 699);
        sshwidget->setStyleSheet(QLatin1String("background-color: rgb(67, 77, 88);\n"
"color: rgb(255, 255, 255);"));
        sshwidget->setLocale(QLocale(QLocale::English, QLocale::Kenya));
        verticalLayout_5 = new QVBoxLayout(sshwidget);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        splitter_1 = new QSplitter(sshwidget);
        splitter_1->setObjectName(QStringLiteral("splitter_1"));
        splitter_1->setOrientation(Qt::Horizontal);
        widget = new QWidget(splitter_1);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(165, 0));
        widget->setMaximumSize(QSize(165, 16777215));
        QFont font;
        font.setFamily(QStringLiteral("OPPOSans B"));
        font.setPointSize(10);
        font.setStyleStrategy(QFont::PreferAntialias);
        widget->setFont(font);
        widget->setStyleSheet(QStringLiteral(""));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(5, 0, 0, 9);
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
        splitter_2->setHandleWidth(0);
        widget_29 = new QWidget(splitter_2);
        widget_29->setObjectName(QStringLiteral("widget_29"));
        widget_29->setMinimumSize(QSize(0, 414));
        widget_29->setStyleSheet(QStringLiteral(""));
        horizontalLayout_19 = new QHBoxLayout(widget_29);
        horizontalLayout_19->setSpacing(0);
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        horizontalLayout_19->setContentsMargins(0, 0, 0, 0);
        splitter_3 = new QSplitter(widget_29);
        splitter_3->setObjectName(QStringLiteral("splitter_3"));
        splitter_3->setOrientation(Qt::Horizontal);
        splitter_3->setHandleWidth(0);
        widget_2 = new QWidget(splitter_3);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setStyleSheet(QStringLiteral(""));
        verticalLayout_8 = new QVBoxLayout(widget_2);
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        widget_10 = new QWidget(widget_2);
        widget_10->setObjectName(QStringLiteral("widget_10"));
        textEdit = new QTextEdit(widget_10);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setEnabled(true);
        textEdit->setGeometry(QRect(9, 10, 350, 300));
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
        font3.setStyleStrategy(QFont::PreferAntialias);
        textEdit->setFont(font3);
        textEdit->setStyleSheet(QString::fromUtf8("QTextEdit{\n"
"	background-color: rgb(0, 41, 69);\n"
"	font: 12pt \"Cascadia Mono,OPPOSans B\";\n"
"	border: none;\n"
"	padding-top:0px;\n"
"    padding-bottom:0px;\n"
"	padding-left:0px;\n"
"    padding-right:0px;\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"    width: 9px;\n"
"	background-color: rgb(0, 41, 69);\n"
"    margin: 0px,0px,0px,0px;\n"
"    padding-top: 0px;		/*//\351\232\220\350\227\217\344\270\212\344\270\213\347\232\204\347\256\255\345\244\264*/\n"
"    padding-bottom: 0px;\n"
"}\n"
"QScrollBar::handle:vertical {\n"
"    width: 9px;\n"
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
"	"
                        "border: none;\n"
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
        textEdit->setTextInteractionFlags(Qt::TextEditable|Qt::TextSelectableByKeyboard);
        textEdit_6 = new QTextEdit(widget_10);
        textEdit_6->setObjectName(QStringLiteral("textEdit_6"));
        textEdit_6->setEnabled(true);
        textEdit_6->setGeometry(QRect(370, 10, 350, 300));
        sizePolicy.setHeightForWidth(textEdit_6->sizePolicy().hasHeightForWidth());
        textEdit_6->setSizePolicy(sizePolicy);
        textEdit_6->setMaximumSize(QSize(16777215, 5555555));
        textEdit_6->setFont(font3);
        textEdit_6->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        textEdit_6->setStyleSheet(QString::fromUtf8("QTextEdit{\n"
"	background-color: rgb(0, 41, 169, 0);\n"
"	font: 12pt \"Cascadia Mono,OPPOSans B\";\n"
"	border: none;\n"
"	padding-top:0px;\n"
"    padding-bottom:0px;\n"
"	padding-left:0px;\n"
"    padding-right:0px;\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"    width: 9px;\n"
"	background-color: rgb(0, 41, 69);\n"
"    margin: 0px,0px,0px,0px;\n"
"    padding-top: 0px;		/*//\351\232\220\350\227\217\344\270\212\344\270\213\347\232\204\347\256\255\345\244\264*/\n"
"    padding-bottom: 0px;\n"
"}\n"
"QScrollBar::handle:vertical {\n"
"    width: 9px;\n"
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
""
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
        textEdit_6->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        textEdit_6->setReadOnly(true);
        textEdit_6->setTextInteractionFlags(Qt::TextSelectableByMouse);

        verticalLayout_8->addWidget(widget_10);

        horizontalWidget = new QWidget(widget_2);
        horizontalWidget->setObjectName(QStringLiteral("horizontalWidget"));
        horizontalWidget->setMinimumSize(QSize(0, 30));
        horizontalWidget->setMaximumSize(QSize(16777215, 30));
        horizontalWidget->setStyleSheet(QStringLiteral("background-color: rgb(0, 41, 69);"));
        horizontalLayout_6 = new QHBoxLayout(horizontalWidget);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);

        lineEdit = new QLineEdit(horizontalWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout_6->addWidget(lineEdit);

        toolButton_12 = new QToolButton(horizontalWidget);
        toolButton_12->setObjectName(QStringLiteral("toolButton_12"));
        toolButton_12->setFont(font);
        toolButton_12->setStyleSheet(QLatin1String("QToolButton {\n"
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

        horizontalLayout_6->addWidget(toolButton_12);

        toolButton_11 = new QToolButton(horizontalWidget);
        toolButton_11->setObjectName(QStringLiteral("toolButton_11"));
        toolButton_11->setFont(font);
        toolButton_11->setStyleSheet(QLatin1String("QToolButton {\n"
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

        horizontalLayout_6->addWidget(toolButton_11);

        toolButton_9 = new QToolButton(horizontalWidget);
        toolButton_9->setObjectName(QStringLiteral("toolButton_9"));
        toolButton_9->setFont(font);
        toolButton_9->setStyleSheet(QLatin1String("QToolButton {\n"
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

        horizontalLayout_6->addWidget(toolButton_9);

        toolButton_10 = new QToolButton(horizontalWidget);
        toolButton_10->setObjectName(QStringLiteral("toolButton_10"));
        toolButton_10->setFont(font);
        toolButton_10->setStyleSheet(QLatin1String("QToolButton {\n"
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

        horizontalLayout_6->addWidget(toolButton_10);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);


        verticalLayout_8->addWidget(horizontalWidget);

        verticalLayout_8->setStretch(0, 5);
        verticalLayout_8->setStretch(1, 1);
        splitter_3->addWidget(widget_2);
        widget_4 = new QWidget(splitter_3);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setStyleSheet(QStringLiteral(""));
        verticalLayout_12 = new QVBoxLayout(widget_4);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        textEdit_3 = new QTextEdit(widget_4);
        textEdit_3->setObjectName(QStringLiteral("textEdit_3"));
        textEdit_3->setMaximumSize(QSize(16777215, 20));

        verticalLayout_12->addWidget(textEdit_3);

        textBrowser = new QTextBrowser(widget_4);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setMaximumSize(QSize(16777215, 20));

        verticalLayout_12->addWidget(textBrowser);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        pushButton_2 = new QPushButton(widget_4);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout_13->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(widget_4);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout_13->addWidget(pushButton_3);


        verticalLayout_12->addLayout(verticalLayout_13);

        widget_9 = new QWidget(widget_4);
        widget_9->setObjectName(QStringLiteral("widget_9"));
        widget_9->setMinimumSize(QSize(0, 163));
        widget_9->setStyleSheet(QStringLiteral("background-color: rgb(0, 170, 127);"));
        textEdit_4 = new QTextEdit(widget_9);
        textEdit_4->setObjectName(QStringLiteral("textEdit_4"));
        textEdit_4->setGeometry(QRect(20, 10, 350, 141));
        textEdit_4->setReadOnly(false);
        textEdit_5 = new QTextEdit(widget_9);
        textEdit_5->setObjectName(QStringLiteral("textEdit_5"));
        textEdit_5->setGeometry(QRect(20, 10, 350, 121));
        textEdit_5->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);"));
        textEdit_5->setReadOnly(true);

        verticalLayout_12->addWidget(widget_9);

        pushButton = new QPushButton(widget_4);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_12->addWidget(pushButton);

        splitter_3->addWidget(widget_4);

        horizontalLayout_19->addWidget(splitter_3);

        splitter_2->addWidget(widget_29);
        widget_3 = new QWidget(splitter_2);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMinimumSize(QSize(0, 186));
        widget_3->setStyleSheet(QStringLiteral(""));
        verticalLayout_7 = new QVBoxLayout(widget_3);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 5, 9);
        splitter_4 = new QSplitter(widget_3);
        splitter_4->setObjectName(QStringLiteral("splitter_4"));
        splitter_4->setOrientation(Qt::Horizontal);
        splitter_4->setHandleWidth(5);
        widget_27 = new QWidget(splitter_4);
        widget_27->setObjectName(QStringLiteral("widget_27"));
        widget_27->setMinimumSize(QSize(9, 11));
        widget_27->setStyleSheet(QStringLiteral(""));
        verticalLayout_9 = new QVBoxLayout(widget_27);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(widget_27);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setFont(font);
        groupBox->setStyleSheet(QLatin1String("QToolButton {\n"
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
        verticalLayout_4 = new QVBoxLayout(groupBox);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(3, 3, 3, 3);
        tabWidget = new QTabWidget(groupBox);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setFont(font);
        tabWidget->setStyleSheet(QString::fromUtf8("\n"
" QTabWidget::tab-bar {\n"
"         left:0px;       \n"
"}\n"
"\n"
"/*\350\256\276\347\275\256TabWidget\344\270\255tab_1\347\232\204\346\240\267\345\274\217*/\n"
"#tab_1.QWidget{\n"
"	background-color: rgb(108, 117, 125, 65);\n"
"}\n"
" \n"
"/*\350\256\276\347\275\256TabWidget\344\270\255tab_2\347\232\204\346\240\267\345\274\217*/\n"
"#tab_2.QWidget{\n"
"	background-color: rgb(108, 117, 125, 65);\n"
"}\n"
" \n"
"/*\350\256\276\347\275\256TabWidget\344\270\255QTabBar\347\232\204\346\240\267\345\274\217*/\n"
"QTabBar::tab{\n"
"    background-color: rgb(108, 117, 125, 65);\n"
"	/*font-family:Consolas; */   /*\350\256\276\347\275\256tab\344\270\255\347\232\204\346\226\207\346\234\254\347\232\204\345\255\227\344\275\223*/\n"
"	font-size:10pt;\n"
"	color:#ced4da;    /*\350\256\276\347\275\256tab\344\270\255\347\232\204\346\226\207\346\234\254\347\232\204\351\242\234\350\211\262*/\n"
"	border-top-left-radius: 1px;    /*\350\256\276\347\275\256tab\347\232\204\350\276\271\346\241\206\347\232\204\345\234\206\350\247"
                        "\222\357\274\210\345\267\246\344\270\212\345\234\206\350\247\222\357\274\211*/\n"
"	border-top-right-radius: 1px;    /*\350\256\276\347\275\256tab\347\232\204\350\276\271\346\241\206\347\232\204\345\234\206\350\247\222\357\274\210\345\217\263\344\270\212\345\234\206\350\247\222\357\274\211*/\n"
"\n"
"	padding: 1px;\n"
"	margin-right:0px;\n"
"	margin-left: 0px;\n"
"}\n"
" \n"
"/*\350\256\276\347\275\256TabWidget\344\270\255QTabBar\347\232\204tab\350\242\253\351\200\211\344\270\255\346\227\266\347\232\204\346\240\267\345\274\217*/\n"
"QTabBar::tab:selected{\n"
"	background-color: #0B0E11;\n"
"}\n"
" \n"
"/*\350\256\276\347\275\256TabWidget\344\270\255\351\274\240\346\240\207\346\202\254\346\265\256\345\234\250QTabBar\347\232\204tab\344\270\212\357\274\214\344\275\206\346\234\252\351\200\211\344\270\255\350\257\245Tab\347\232\204\346\240\267\345\274\217*/\n"
"QTabBar::tab:hover:!selected {\n"
"	background-color: rgb(100, 117, 125, 125);\n"
"}\n"
" \n"
"/*\350\256\276\347\275\256TabWidget\347\232\204\350\276\271\346"
                        "\241\206\347\232\204\346\240\267\345\274\217*/\n"
"QTabWidget::pane {\n"
"    border: 2px solid rgb(108, 117, 125, 65);\n"
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
"    background-color: #0b0e11;\n"
"}\n"
" \n"
"QTabBar QToolButton:hover {\n"
"	background-color: #161a1e; \n"
"}"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        toolButton_3 = new QToolButton(tab);
        toolButton_3->setObjectName(QStringLiteral("toolButton_3"));
        toolButton_3->setGeometry(QRect(10, 10, 41, 21));
        toolButton_3->setFont(font);
        toolButton_4 = new QToolButton(tab);
        toolButton_4->setObjectName(QStringLiteral("toolButton_4"));
        toolButton_4->setGeometry(QRect(50, 10, 41, 21));
        toolButton_4->setFont(font);
        toolButton_5 = new QToolButton(tab);
        toolButton_5->setObjectName(QStringLiteral("toolButton_5"));
        toolButton_5->setGeometry(QRect(90, 10, 41, 21));
        toolButton_5->setFont(font);
        toolButton_6 = new QToolButton(tab);
        toolButton_6->setObjectName(QStringLiteral("toolButton_6"));
        toolButton_6->setGeometry(QRect(130, 10, 41, 21));
        toolButton_6->setFont(font);
        toolButton_7 = new QToolButton(tab);
        toolButton_7->setObjectName(QStringLiteral("toolButton_7"));
        toolButton_7->setGeometry(QRect(200, 10, 61, 21));
        toolButton_7->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/lib/setting.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_7->setIcon(icon);
        toolButton_7->setIconSize(QSize(16, 16));
        toolButton_7->setPopupMode(QToolButton::DelayedPopup);
        toolButton_7->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toolButton_8 = new QToolButton(tab);
        toolButton_8->setObjectName(QStringLiteral("toolButton_8"));
        toolButton_8->setGeometry(QRect(170, 10, 41, 21));
        toolButton_8->setFont(font);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());

        verticalLayout_4->addWidget(tabWidget);

        widget_8 = new QWidget(groupBox);
        widget_8->setObjectName(QStringLiteral("widget_8"));
        widget_8->setMinimumSize(QSize(0, 18));
        horizontalLayout_5 = new QHBoxLayout(widget_8);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(9, 0, 9, 0);
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


        verticalLayout_4->addWidget(widget_8);


        verticalLayout_9->addWidget(groupBox);

        splitter_4->addWidget(widget_27);
        widget_28 = new QWidget(splitter_4);
        widget_28->setObjectName(QStringLiteral("widget_28"));
        widget_28->setStyleSheet(QStringLiteral(""));
        verticalLayout_10 = new QVBoxLayout(widget_28);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        groupBox_2 = new QGroupBox(widget_28);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setFont(font);
        groupBox_2->setStyleSheet(QStringLiteral(""));
        verticalLayout_11 = new QVBoxLayout(groupBox_2);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        verticalLayout_11->setContentsMargins(3, 3, 3, 3);
        textEdit_2 = new QTextEdit(groupBox_2);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setFont(font);
        textEdit_2->setStyleSheet(QLatin1String("border-radius: 10px;\n"
"border: 2px solid rgba(255, 255, 255, 0);"));

        verticalLayout_11->addWidget(textEdit_2);


        verticalLayout_10->addWidget(groupBox_2);

        splitter_4->addWidget(widget_28);

        verticalLayout_7->addWidget(splitter_4);

        splitter_2->addWidget(widget_3);

        verticalLayout_6->addWidget(splitter_2);

        splitter_1->addWidget(widget_26);

        verticalLayout_5->addWidget(splitter_1);


        retranslateUi(sshwidget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(sshwidget);
    } // setupUi

    void retranslateUi(QWidget *sshwidget)
    {
        sshwidget->setWindowTitle(QApplication::translate("sshwidget", "Form", nullptr));
        label_serverTitle->setText(QApplication::translate("sshwidget", "\346\234\215\345\212\241\345\231\250\344\277\241\346\201\257\357\274\232", nullptr));
        label_ip->setText(QApplication::translate("sshwidget", "IP\357\274\232", nullptr));
        toolButton->setText(QApplication::translate("sshwidget", "\345\244\215\345\210\266", nullptr));
        label_time->setText(QApplication::translate("sshwidget", "\347\263\273\347\273\237\346\227\266\351\227\264\357\274\232", nullptr));
        label_runTime->setText(QApplication::translate("sshwidget", "\350\277\220\350\241\214\346\227\266\351\227\264\357\274\232", nullptr));
        label_loginCount->setText(QApplication::translate("sshwidget", "\347\273\210\347\253\257\350\277\236\346\216\245\357\274\232", nullptr));
        label_architecture->setText(QApplication::translate("sshwidget", "\347\241\254\344\273\266\346\236\266\346\236\204\357\274\232", nullptr));
        label_systemType->setText(QApplication::translate("sshwidget", "\347\263\273\347\273\237\347\261\273\345\236\213\357\274\232", nullptr));
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
        textEdit_6->setHtml(QApplication::translate("sshwidget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Cascadia Mono,OPPOSans B'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        toolButton_12->setText(QApplication::translate("sshwidget", "\344\270\212\344\274\240", nullptr));
        toolButton_11->setText(QApplication::translate("sshwidget", "\346\237\245\346\211\276", nullptr));
        toolButton_9->setText(QApplication::translate("sshwidget", "\345\216\206\345\217\262", nullptr));
        toolButton_10->setText(QApplication::translate("sshwidget", "\345\267\245\345\205\267\351\233\206", nullptr));
        textEdit_3->setHtml(QApplication::translate("sshwidget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">&lt;!DOCTYPE HTML PUBLIC &quot;-//W3C//DTD HTML 4.0//EN&quot; &quot;http://www.w3.org/TR/REC-html40/strict.dtd&quot;&gt;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">p, li { white-space: pre-wrap; }</p>\n"
"<p style=\" margin-top:0"
                        "px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;&quot;&gt;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;dasdadfsdafddffs&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;&lt;!DOCTYPE HTML PUBLIC &quot;-//W3C//DTD HTML 4.0//EN&quot; &quot;http://www.w3.org/TR/REC-html40/strict.dtd&quot;&gt;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-ind"
                        "ent:0; text-indent:0px;\">p, li { white-space: pre-wrap; }</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;&quot;&gt;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;dasdadfsdafddffs&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;&lt;!DOCTYPE HTML PUBLIC &quot;-//W3C//DTD HTML 4.0//EN&quot; &quot;http://www.w3.org/TR/REC-html40/strict.dtd&quot;&gt;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;</p>\n"
"<p s"
                        "tyle=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">p, li { white-space: pre-wrap; }</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;&quot;&gt;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;dasdadfsdafddffs&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</p></body></html>", nullptr));
        pushButton_2->setText(QApplication::translate("sshwidget", "PushButton", nullptr));
        pushButton_3->setText(QApplication::translate("sshwidget", "PushButton", nullptr));
        textEdit_4->setHtml(QApplication::translate("sshwidget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\350\277\231\346\230\257\344\270\200\346\256\265\345\217\257\351\200\211\344\270\255\344\275\206\346\227\240\351\234\200\347\247\273\345\212\250\345\205\211\346\240\207\347\232\204\346\226\207\346\234\254\343\200\202\350\277\231\346\230\257\344\270\200\346\256\265\345\217\257\351\200\211\344\270\255\344\275\206\346\227\240\351\234\200\347\247\273\345\212\250\345\205\211\346\240\207\347\232\204\346\226\207\346\234\254\343\200\202\350\277\231\346\230\257\344\270\200\346\256\265\345\217\257\351\200\211\344\270\255\344\275\206\346\227\240\351\234\200\347\247\273\345\212"
                        "\250\345\205\211\346\240\207\347\232\204\346\226\207\346\234\254\343\200\202\350\277\231\346\230\257\344\270\200\346\256\265\345\217\257\351\200\211\344\270\255\344\275\206\346\227\240\351\234\200\347\247\273\345\212\250\345\205\211\346\240\207\347\232\204\346\226\207\346\234\254\343\200\202\350\277\231\346\230\257\344\270\200\346\256\265\345\217\257\351\200\211\344\270\255\344\275\206\346\227\240\351\234\200\347\247\273\345\212\250\345\205\211\346\240\207\347\232\204\346\226\207\346\234\254\343\200\202\350\277\231\346\230\257\344\270\200\346\256\265\345\217\257\351\200\211\344\270\255\344\275\206\346\227\240\351\234\200\347\247\273\345\212\250\345\205\211\346\240\207\347\232\204\346\226\207\346\234\254\343\200\202\350\277\231\346\230\257\344\270\200\346\256\265\345\217\257\351\200\211\344\270\255\344\275\206\346\227\240\351\234\200\347\247\273\345\212\250\345\205\211\346\240\207\347\232\204\346\226\207\346\234\254\343\200\202\350\277\231\346\230\257\344\270\200\346\256\265\345\217\257\351\200\211\344\270\255\344"
                        "\275\206\346\227\240\351\234\200\347\247\273\345\212\250\345\205\211\346\240\207\347\232\204\346\226\207\346\234\254\343\200\202\350\277\231\346\230\257\344\270\200\346\256\265\345\217\257\351\200\211\344\270\255\344\275\206\346\227\240\351\234\200\347\247\273\345\212\250\345\205\211\346\240\207\347\232\204\346\226\207\346\234\254\343\200\202\350\277\231\346\230\257\344\270\200\346\256\265\345\217\257\351\200\211\344\270\255\344\275\206\346\227\240\351\234\200\347\247\273\345\212\250\345\205\211\346\240\207\347\232\204\346\226\207\346\234\254\343\200\202\350\277\231\346\230\257\344\270\200\346\256\265\345\217\257\351\200\211\344\270\255\344\275\206\346\227\240\351\234\200\347\247\273\345\212\250\345\205\211\346\240\207\347\232\204\346\226\207\346\234\254\343\200\202\350\277\231\346\230\257\344\270\200\346\256\265\345\217\257\351\200\211\344\270\255\344\275\206\346\227\240\351\234\200\347\247\273\345\212\250\345\205\211\346\240\207\347\232\204\346\226\207\346\234\254\343\200\202\350\277\231\346\230\257\344\270\200"
                        "\346\256\265\345\217\257\351\200\211\344\270\255\344\275\206\346\227\240\351\234\200\347\247\273\345\212\250\345\205\211\346\240\207\347\232\204\346\226\207\346\234\254\343\200\202\350\277\231\346\230\257\344\270\200\346\256\265\345\217\257\351\200\211\344\270\255\344\275\206\346\227\240\351\234\200\347\247\273\345\212\250\345\205\211\346\240\207\347\232\204\346\226\207\346\234\254\343\200\202\350\277\231\346\230\257\344\270\200\346\256\265\345\217\257\351\200\211\344\270\255\344\275\206\346\227\240\351\234\200\347\247\273\345\212\250\345\205\211\346\240\207\347\232\204\346\226\207\346\234\254\343\200\202\350\277\231\346\230\257\344\270\200\346\256\265\345\217\257\351\200\211\344\270\255\344\275\206\346\227\240\351\234\200\347\247\273\345\212\250\345\205\211\346\240\207\347\232\204\346\226\207\346\234\254\343\200\202\350\277\231\346\230\257\344\270\200\346\256\265\345\217\257\351\200\211\344\270\255\344\275\206\346\227\240\351\234\200\347\247\273\345\212\250\345\205\211\346\240\207\347\232\204\346\226\207\346\234"
                        "\254\343\200\202\350\277\231\346\230\257\344\270\200\346\256\265\345\217\257\351\200\211\344\270\255\344\275\206\346\227\240\351\234\200\347\247\273\345\212\250\345\205\211\346\240\207\347\232\204\346\226\207\346\234\254\343\200\202\350\277\231\346\230\257\344\270\200\346\256\265\345\217\257\351\200\211\344\270\255\344\275\206\346\227\240\351\234\200\347\247\273\345\212\250\345\205\211\346\240\207\347\232\204\346\226\207\346\234\254\343\200\202\350\277\231\346\230\257\344\270\200\346\256\265\345\217\257\351\200\211\344\270\255\344\275\206\346\227\240\351\234\200\347\247\273\345\212\250\345\205\211\346\240\207\347\232\204\346\226\207\346\234\254\343\200\202</p></body></html>", nullptr));
        textEdit_5->setHtml(QApplication::translate("sshwidget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\350\277\231\346\230\257\344\270\200\346\256\265\345\217\257\351\200\211\344\270\255\344\275\206\346\227\240\351\234\200\347\247\273\345\212\250\345\205\211\346\240\207\347\232\204\346\226\207\346\234\254\343\200\202\350\277\231\346\230\257\344\270\200\346\256\265\345\217\257\351\200\211\344\270\255\344\275\206\346\227\240\351\234\200\347\247\273\345\212\250\345\205\211\346\240\207\347\232\204\346\226\207\346\234\254\343\200\202\350\277\231\346\230\257\344\270\200\346\256\265\345\217\257\351\200\211\344\270\255\344\275\206\346\227\240\351\234\200\347\247\273\345\212"
                        "\250\345\205\211\346\240\207\347\232\204\346\226\207\346\234\254\343\200\202\350\277\231\346\230\257\344\270\200\346\256\265\345\217\257\351\200\211\344\270\255\344\275\206\346\227\240\351\234\200\347\247\273\345\212\250\345\205\211\346\240\207\347\232\204\346\226\207\346\234\254\343\200\202\350\277\231\346\230\257\344\270\200\346\256\265\345\217\257\351\200\211\344\270\255\344\275\206\346\227\240\351\234\200\347\247\273\345\212\250\345\205\211\346\240\207\347\232\204\346\226\207\346\234\254\343\200\202\350\277\231\346\230\257\344\270\200\346\256\265\345\217\257\351\200\211\344\270\255\344\275\206\346\227\240\351\234\200\347\247\273\345\212\250\345\205\211\346\240\207\347\232\204\346\226\207\346\234\254\343\200\202\350\277\231\346\230\257\344\270\200\346\256\265\345\217\257\351\200\211\344\270\255\344\275\206\346\227\240\351\234\200\347\247\273\345\212\250\345\205\211\346\240\207\347\232\204\346\226\207\346\234\254\343\200\202\350\277\231\346\230\257\344\270\200\346\256\265\345\217\257\351\200\211\344\270\255\344"
                        "\275\206\346\227\240\351\234\200\347\247\273\345\212\250\345\205\211\346\240\207\347\232\204\346\226\207\346\234\254\343\200\202\350\277\231\346\230\257\344\270\200\346\256\265\345\217\257\351\200\211\344\270\255\344\275\206\346\227\240\351\234\200\347\247\273\345\212\250\345\205\211\346\240\207\347\232\204\346\226\207\346\234\254\343\200\202\350\277\231\346\230\257\344\270\200\346\256\265\345\217\257\351\200\211\344\270\255\344\275\206\346\227\240\351\234\200\347\247\273\345\212\250\345\205\211\346\240\207\347\232\204\346\226\207\346\234\254\343\200\202\350\277\231\346\230\257\344\270\200\346\256\265\345\217\257\351\200\211\344\270\255\344\275\206\346\227\240\351\234\200\347\247\273\345\212\250\345\205\211\346\240\207\347\232\204\346\226\207\346\234\254\343\200\202\350\277\231\346\230\257\344\270\200\346\256\265\345\217\257\351\200\211\344\270\255\344\275\206\346\227\240\351\234\200\347\247\273\345\212\250\345\205\211\346\240\207\347\232\204\346\226\207\346\234\254\343\200\202\350\277\231\346\230\257\344\270\200"
                        "\346\256\265\345\217\257\351\200\211\344\270\255\344\275\206\346\227\240\351\234\200\347\247\273\345\212\250\345\205\211\346\240\207\347\232\204\346\226\207\346\234\254\343\200\202\350\277\231\346\230\257\344\270\200\346\256\265\345\217\257\351\200\211\344\270\255\344\275\206\346\227\240\351\234\200\347\247\273\345\212\250\345\205\211\346\240\207\347\232\204\346\226\207\346\234\254\343\200\202\350\277\231\346\230\257\344\270\200\346\256\265\345\217\257\351\200\211\344\270\255\344\275\206\346\227\240\351\234\200\347\247\273\345\212\250\345\205\211\346\240\207\347\232\204\346\226\207\346\234\254\343\200\202\350\277\231\346\230\257\344\270\200\346\256\265\345\217\257\351\200\211\344\270\255\344\275\206\346\227\240\351\234\200\347\247\273\345\212\250\345\205\211\346\240\207\347\232\204\346\226\207\346\234\254\343\200\202\350\277\231\346\230\257\344\270\200\346\256\265\345\217\257\351\200\211\344\270\255\344\275\206\346\227\240\351\234\200\347\247\273\345\212\250\345\205\211\346\240\207\347\232\204\346\226\207\346\234"
                        "\254\343\200\202\350\277\231\346\230\257\344\270\200\346\256\265\345\217\257\351\200\211\344\270\255\344\275\206\346\227\240\351\234\200\347\247\273\345\212\250\345\205\211\346\240\207\347\232\204\346\226\207\346\234\254\343\200\202\350\277\231\346\230\257\344\270\200\346\256\265\345\217\257\351\200\211\344\270\255\344\275\206\346\227\240\351\234\200\347\247\273\345\212\250\345\205\211\346\240\207\347\232\204\346\226\207\346\234\254\343\200\202\350\277\231\346\230\257\344\270\200\346\256\265\345\217\257\351\200\211\344\270\255\344\275\206\346\227\240\351\234\200\347\247\273\345\212\250\345\205\211\346\240\207\347\232\204\346\226\207\346\234\254\343\200\202</p></body></html>", nullptr));
        pushButton->setText(QApplication::translate("sshwidget", "PushButton", nullptr));
        groupBox->setTitle(QApplication::translate("sshwidget", "\345\221\275\344\273\244", nullptr));
        toolButton_3->setText(QApplication::translate("sshwidget", "\350\277\230\345\216\237", nullptr));
        toolButton_4->setText(QApplication::translate("sshwidget", "\346\212\223\345\214\205", nullptr));
        toolButton_5->setText(QApplication::translate("sshwidget", "\346\212\223\345\214\205", nullptr));
        toolButton_6->setText(QApplication::translate("sshwidget", "\346\212\223\345\214\205", nullptr));
        toolButton_7->setText(QApplication::translate("sshwidget", "\346\212\223\345\214\205", nullptr));
        toolButton_8->setText(QApplication::translate("sshwidget", "\346\212\223\345\214\205", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("sshwidget", "\351\273\230\350\256\244\345\210\206\347\261\273", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("sshwidget", "minic", nullptr));
        label->setText(QApplication::translate("sshwidget", "\346\211\247\350\241\214\345\244\207\344\273\275", nullptr));
        label_2->setText(QApplication::translate("sshwidget", "/data/linkdood/im/bin/databack/databak -c /data/linkdood/im/bin/databack/ -t s -p /data/backup/ -l a -e /java", nullptr));
        toolButton_2->setText(QApplication::translate("sshwidget", "\347\274\226\350\276\221", nullptr));
        groupBox_2->setTitle(QApplication::translate("sshwidget", "\345\221\275\344\273\244\347\274\226\350\276\221\345\231\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class sshwidget: public Ui_sshwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SSHWIDGET_H
