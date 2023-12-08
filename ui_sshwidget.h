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
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTabWidget>
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
    QWidget *widget_run_info;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_runTime;
    QWidget *widget_25;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_loginCount;
    QWidget *widget_27;
    QHBoxLayout *horizontalLayout_24;
    QLabel *label_architecture;
    QWidget *verticalWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_cpuInfo;
    QWidget *widget_31;
    QHBoxLayout *horizontalLayout_26;
    QLabel *label_load;
    QSpacerItem *verticalSpacer_2;
    QWidget *widget_cpu_info;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_cpu;
    QProgressBar *progressBar_cpu;
    QWidget *widget_mem_info_2;
    QVBoxLayout *verticalLayout_11;
    QLabel *label_disk;
    QProgressBar *progressBar_disk;
    QWidget *widget_mem_info;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_mem;
    QProgressBar *progressBar_mem;
    QWidget *widget_swap_info;
    QVBoxLayout *verticalLayout;
    QLabel *label_swap;
    QProgressBar *progressBar_swap;
    QSpacerItem *verticalSpacer;
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
    QWidget *widget_bottom;
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
    QWidget *tab_4;
    QProgressBar *progressBar_swap_2;
    QProgressBar *progressBar_cpu_2;
    QLabel *label_swap_2;
    QLabel *label_cpu_2;
    QProgressBar *progressBar_mem_2;
    QLabel *label_disk_2;
    QLabel *label_mem_2;
    QProgressBar *progressBar_disk_2;
    QProgressBar *progressBar;
    QTextEdit *textEdit_4;
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
        widget->setMinimumSize(QSize(145, 0));
        widget->setMaximumSize(QSize(145, 16777215));
        QFont font;
        font.setFamily(QStringLiteral("OPPOSans B"));
        font.setPointSize(10);
        font.setStyleStrategy(QFont::PreferAntialias);
        widget->setFont(font);
        widget->setStyleSheet(QLatin1String("#widget{\n"
"border-right:2px solid rgba(108, 117, 125, 65); \n"
"}\n"
"\n"
"QLabel{\n"
"color: rgb(255, 255, 255);\n"
"}"));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setSpacing(7);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(3, 10, 7, 5);
        widget_server_info = new QWidget(widget);
        widget_server_info->setObjectName(QStringLiteral("widget_server_info"));
        widget_server_info->setMinimumSize(QSize(0, 30));
        widget_server_info->setMaximumSize(QSize(16777215, 30));
        horizontalLayout_22 = new QHBoxLayout(widget_server_info);
        horizontalLayout_22->setSpacing(0);
        horizontalLayout_22->setObjectName(QStringLiteral("horizontalLayout_22"));
        horizontalLayout_22->setContentsMargins(0, 0, 0, 0);
        label_serverTitle = new QLabel(widget_server_info);
        label_serverTitle->setObjectName(QStringLiteral("label_serverTitle"));
        label_serverTitle->setMinimumSize(QSize(0, 20));
        label_serverTitle->setMaximumSize(QSize(16777215, 20));
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
        label_ip->setMinimumSize(QSize(0, 20));
        label_ip->setMaximumSize(QSize(16777215, 20));
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
        label_runTime->setMinimumSize(QSize(0, 20));
        label_runTime->setMaximumSize(QSize(16777215, 20));
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
        label_loginCount->setMinimumSize(QSize(0, 20));
        label_loginCount->setMaximumSize(QSize(16777215, 20));
        label_loginCount->setFont(font1);

        horizontalLayout_18->addWidget(label_loginCount);


        verticalLayout_3->addWidget(widget_25);

        widget_27 = new QWidget(widget);
        widget_27->setObjectName(QStringLiteral("widget_27"));
        widget_27->setMinimumSize(QSize(0, 20));
        widget_27->setMaximumSize(QSize(16777215, 20));
        horizontalLayout_24 = new QHBoxLayout(widget_27);
        horizontalLayout_24->setSpacing(0);
        horizontalLayout_24->setObjectName(QStringLiteral("horizontalLayout_24"));
        horizontalLayout_24->setContentsMargins(0, 0, 0, 0);
        label_architecture = new QLabel(widget_27);
        label_architecture->setObjectName(QStringLiteral("label_architecture"));
        label_architecture->setMinimumSize(QSize(0, 20));
        label_architecture->setMaximumSize(QSize(16777215, 20));
        label_architecture->setFont(font1);

        horizontalLayout_24->addWidget(label_architecture);


        verticalLayout_3->addWidget(widget_27);

        verticalWidget = new QWidget(widget);
        verticalWidget->setObjectName(QStringLiteral("verticalWidget"));
        verticalWidget->setMinimumSize(QSize(0, 20));
        verticalWidget->setMaximumSize(QSize(16777215, 20));
        horizontalLayout = new QHBoxLayout(verticalWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_cpuInfo = new QLabel(verticalWidget);
        label_cpuInfo->setObjectName(QStringLiteral("label_cpuInfo"));
        label_cpuInfo->setMinimumSize(QSize(0, 20));
        label_cpuInfo->setMaximumSize(QSize(16777215, 20));
        label_cpuInfo->setFont(font1);

        horizontalLayout->addWidget(label_cpuInfo);


        verticalLayout_3->addWidget(verticalWidget);

        widget_31 = new QWidget(widget);
        widget_31->setObjectName(QStringLiteral("widget_31"));
        widget_31->setMinimumSize(QSize(0, 20));
        widget_31->setMaximumSize(QSize(16777215, 20));
        horizontalLayout_26 = new QHBoxLayout(widget_31);
        horizontalLayout_26->setSpacing(0);
        horizontalLayout_26->setObjectName(QStringLiteral("horizontalLayout_26"));
        horizontalLayout_26->setContentsMargins(0, 0, 0, 0);
        label_load = new QLabel(widget_31);
        label_load->setObjectName(QStringLiteral("label_load"));
        label_load->setMinimumSize(QSize(0, 20));
        label_load->setMaximumSize(QSize(16777215, 20));
        label_load->setFont(font1);

        horizontalLayout_26->addWidget(label_load);


        verticalLayout_3->addWidget(widget_31);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_3->addItem(verticalSpacer_2);

        widget_cpu_info = new QWidget(widget);
        widget_cpu_info->setObjectName(QStringLiteral("widget_cpu_info"));
        widget_cpu_info->setMinimumSize(QSize(0, 40));
        widget_cpu_info->setMaximumSize(QSize(16777215, 40));
        widget_cpu_info->setStyleSheet(QStringLiteral(""));
        verticalLayout_10 = new QVBoxLayout(widget_cpu_info);
        verticalLayout_10->setSpacing(0);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        label_cpu = new QLabel(widget_cpu_info);
        label_cpu->setObjectName(QStringLiteral("label_cpu"));
        label_cpu->setFont(font1);

        verticalLayout_10->addWidget(label_cpu);

        progressBar_cpu = new QProgressBar(widget_cpu_info);
        progressBar_cpu->setObjectName(QStringLiteral("progressBar_cpu"));
        progressBar_cpu->setMinimumSize(QSize(130, 18));
        progressBar_cpu->setMaximumSize(QSize(130, 18));
        progressBar_cpu->setFont(font1);
        progressBar_cpu->setStyleSheet(QLatin1String("QProgressBar {\n"
"	border: 1px solid;\n"
"	\n"
"	\n"
"	border-color: rgb(91, 91, 91);\n"
"	border-radius: 2px; \n"
"	\n"
"	\n"
"	/*border-image: url(:/lib/jianbian1.png);*/\n"
"	background-color: #FFFFFF;\n"
"	text-align:right;\n"
"	color: rgba(0, 0, 0, 200);\n"
"}\n"
"\n"
"QProgressBar:chunk{\n"
"	border-radius:2px;\n"
"	\n"
"	\n"
"	\n"
"	background-color: rgb(87, 255, 92);\n"
"	/*background-color: #FFFFFF;*/\n"
"}"));
        progressBar_cpu->setValue(25);
        progressBar_cpu->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        progressBar_cpu->setInvertedAppearance(false);

        verticalLayout_10->addWidget(progressBar_cpu);


        verticalLayout_3->addWidget(widget_cpu_info);

        widget_mem_info_2 = new QWidget(widget);
        widget_mem_info_2->setObjectName(QStringLiteral("widget_mem_info_2"));
        widget_mem_info_2->setMinimumSize(QSize(0, 40));
        widget_mem_info_2->setMaximumSize(QSize(16777215, 40));
        verticalLayout_11 = new QVBoxLayout(widget_mem_info_2);
        verticalLayout_11->setSpacing(0);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        verticalLayout_11->setContentsMargins(0, 0, 0, 0);
        label_disk = new QLabel(widget_mem_info_2);
        label_disk->setObjectName(QStringLiteral("label_disk"));
        label_disk->setFont(font1);

        verticalLayout_11->addWidget(label_disk);

        progressBar_disk = new QProgressBar(widget_mem_info_2);
        progressBar_disk->setObjectName(QStringLiteral("progressBar_disk"));
        progressBar_disk->setMinimumSize(QSize(130, 18));
        progressBar_disk->setMaximumSize(QSize(130, 18));
        QFont font3;
        font3.setFamily(QStringLiteral("OPPOSans B"));
        font3.setPointSize(9);
        progressBar_disk->setFont(font3);
        progressBar_disk->setLayoutDirection(Qt::LeftToRight);
        progressBar_disk->setStyleSheet(QLatin1String("QProgressBar {\n"
"	border: 1px solid;\n"
"	\n"
"	\n"
"	border-color: rgb(91, 91, 91);\n"
"	border-radius: 2px; \n"
"	\n"
"	\n"
"	/*border-image: url(:/lib/jianbian1.png);*/\n"
"	background-color: #FFFFFF;\n"
"	text-align:right;\n"
"	color: rgba(0, 0, 0, 200);\n"
"}\n"
"\n"
"QProgressBar:chunk{\n"
"	border-radius:2px;\n"
"	\n"
"	\n"
"	\n"
"	background-color: rgb(87, 255, 92);\n"
"	/*background-color: #FFFFFF;*/\n"
"}"));
        progressBar_disk->setValue(0);
        progressBar_disk->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        progressBar_disk->setInvertedAppearance(false);

        verticalLayout_11->addWidget(progressBar_disk);


        verticalLayout_3->addWidget(widget_mem_info_2);

        widget_mem_info = new QWidget(widget);
        widget_mem_info->setObjectName(QStringLiteral("widget_mem_info"));
        widget_mem_info->setMinimumSize(QSize(0, 40));
        widget_mem_info->setMaximumSize(QSize(16777215, 40));
        verticalLayout_2 = new QVBoxLayout(widget_mem_info);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_mem = new QLabel(widget_mem_info);
        label_mem->setObjectName(QStringLiteral("label_mem"));
        label_mem->setFont(font1);

        verticalLayout_2->addWidget(label_mem);

        progressBar_mem = new QProgressBar(widget_mem_info);
        progressBar_mem->setObjectName(QStringLiteral("progressBar_mem"));
        progressBar_mem->setMinimumSize(QSize(130, 18));
        progressBar_mem->setMaximumSize(QSize(130, 18));
        progressBar_mem->setFont(font3);
        progressBar_mem->setLayoutDirection(Qt::LeftToRight);
        progressBar_mem->setStyleSheet(QLatin1String("QProgressBar {\n"
"	border: 1px solid;\n"
"	\n"
"	\n"
"	border-color: rgb(91, 91, 91);\n"
"	border-radius: 2px; \n"
"	\n"
"	\n"
"	/*border-image: url(:/lib/jianbian1.png);*/\n"
"	background-color: #FFFFFF;\n"
"	text-align:right;\n"
"	color: rgba(0, 0, 0, 200);\n"
"}\n"
"\n"
"QProgressBar:chunk{\n"
"	border-radius:2px;\n"
"	\n"
"	\n"
"	\n"
"	background-color: rgb(87, 255, 92);\n"
"	/*background-color: #FFFFFF;*/\n"
"}"));
        progressBar_mem->setValue(0);
        progressBar_mem->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        progressBar_mem->setInvertedAppearance(false);

        verticalLayout_2->addWidget(progressBar_mem);


        verticalLayout_3->addWidget(widget_mem_info);

        widget_swap_info = new QWidget(widget);
        widget_swap_info->setObjectName(QStringLiteral("widget_swap_info"));
        widget_swap_info->setMinimumSize(QSize(0, 40));
        widget_swap_info->setMaximumSize(QSize(16777215, 40));
        verticalLayout = new QVBoxLayout(widget_swap_info);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_swap = new QLabel(widget_swap_info);
        label_swap->setObjectName(QStringLiteral("label_swap"));
        label_swap->setFont(font1);

        verticalLayout->addWidget(label_swap);

        progressBar_swap = new QProgressBar(widget_swap_info);
        progressBar_swap->setObjectName(QStringLiteral("progressBar_swap"));
        progressBar_swap->setMinimumSize(QSize(130, 18));
        progressBar_swap->setMaximumSize(QSize(130, 18));
        progressBar_swap->setFont(font3);
        progressBar_swap->setLayoutDirection(Qt::LeftToRight);
        progressBar_swap->setStyleSheet(QLatin1String("QProgressBar {\n"
"	border: 1px solid;\n"
"	\n"
"	\n"
"	border-color: rgb(91, 91, 91);\n"
"	border-radius: 2px; \n"
"	\n"
"	\n"
"	/*border-image: url(:/lib/jianbian1.png);*/\n"
"	background-color: #FFFFFF;\n"
"	text-align:right;\n"
"	color: rgba(0, 0, 0, 200);\n"
"}\n"
"\n"
"QProgressBar:chunk{\n"
"	border-radius:2px;\n"
"	\n"
"	\n"
"	\n"
"	background-color: rgb(87, 255, 92);\n"
"	/*background-color: #FFFFFF;*/\n"
"}"));
        progressBar_swap->setValue(0);
        progressBar_swap->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        progressBar_swap->setInvertedAppearance(false);
        progressBar_swap->setTextDirection(QProgressBar::TopToBottom);

        verticalLayout->addWidget(progressBar_swap);


        verticalLayout_3->addWidget(widget_swap_info);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


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
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1246, 359));
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
        widget_9->setStyleSheet(QLatin1String("QMenu {\n"
"\n"
"background-color:rgb(253,253,254);\n"
"/*padding:5px;*/\n"
"padding: 3px 0px 3px 0px;\n"
"border-radius:6px;\n"
"border:2px solid rgb(108, 117, 125, 65); \n"
"}\n"
"QMenu::item {\n"
"	font-size: 10pt;\n"
"	\n"
"	font: 10pt \"OPPOSans B\";\n"
"	\n"
"	color: rgb(63, 63, 63);\n"
"    background-color:rgb(253,253,254);\n"
"    padding: 5px 25px 5px 25px;\n"
"    /*margin: 2px 2px 2px 2px;*/\n"
"}\n"
"QMenu::item:selected {\n"
"    background-color : rgb(236,236,237);\n"
"}\n"
"QMenu::icon:checked {\n"
"    background: rgb(253,253,254);\n"
"    position: absolute;\n"
"    top: 1px;\n"
"    right: 1px;\n"
"    bottom: 1px;\n"
"    left: 1px;\n"
"}\n"
"QMenu::icon:checked:selected {\n"
"    background-color : rgb(236,236,237);\n"
"    background-image: url(:/space_selected.png);\n"
"}\n"
"QMenu::separator {\n"
"    height: 2px;\n"
"    background: rgb(235,235,236);\n"
"    /*margin-left: 10px;*/\n"
"    /*margin-right: 10px;*/\n"
"}"));
        textEdit = new QTextEdit(widget_9);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setEnabled(true);
        textEdit->setGeometry(QRect(620, 30, 451, 301));
        sizePolicy1.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy1);
        textEdit->setMaximumSize(QSize(16777215, 5555555));
        QFont font4;
        font4.setFamily(QStringLiteral("Cascadia Mono,OPPOSans B"));
        font4.setPointSize(12);
        font4.setBold(false);
        font4.setItalic(false);
        font4.setWeight(50);
        font4.setStyleStrategy(QFont::PreferAntialias);
        textEdit->setFont(font4);
        textEdit->setStyleSheet(QString::fromUtf8("QTextEdit{\n"
"	background-color: rgba(0, 41, 69, 0);\n"
"	font: 12pt \"Cascadia Mono,OPPOSans B\";\n"
"	border: none;\n"
"	padding-top:0px;\n"
"    padding-bottom:0px;\n"
"	padding-left:0px;\n"
"    padding-right:0px;\n"
"color: rgba(255, 255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"}\n"
"\n"
"QTextEdit::cursor {\n"
"     background-color: red;\n"
"}\n"
"\n"
"QScrollBar:vertical{\n"
"    width: 10px;\n"
"	background-color: rgba(0, 41, 69, 0);\n"
"    margin: 0px,0px,0px,0px;\n"
"    padding-top: 0px;		/*//\351\232\220\350\227\217\344\270\212\344\270\213\347\232\204\347\256\255\345\244\264*/\n"
"    padding-bottom: 0px;\n"
"}\n"
"\n"
"\n"
"QScrollBar::handle:vertical{\n"
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
""
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
"\n"
"QScrollBar::up-arrow:vertical {\n"
"    border:none;\n"
"}"));
        textEdit->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        textEdit->setLineWidth(1);
        textEdit->setLineWrapMode(QTextEdit::NoWrap);
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
        widget_toolbar_s->setMinimumSize(QSize(0, 30));
        widget_toolbar_s->setMaximumSize(QSize(450, 30));
        widget_toolbar_s->setStyleSheet(QLatin1String("background-color: rgba(11, 11, 11,150);\n"
"border-radius: 10px;"));
        horizontalLayout_6 = new QHBoxLayout(widget_toolbar_s);
        horizontalLayout_6->setSpacing(10);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(10, 0, 10, 0);
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
        widget_bottom = new QWidget(splitter_2);
        widget_bottom->setObjectName(QStringLiteral("widget_bottom"));
        widget_bottom->setMinimumSize(QSize(0, 0));
        widget_bottom->setStyleSheet(QLatin1String("#widget_bottom {\n"
"	background-color: rgba(11, 11, 11,0);\n"
"	border-radius: 10px;\n"
"}\n"
"\n"
"QMenu {\n"
"\n"
"background-color:rgb(253,253,254);\n"
"/*padding:5px;*/\n"
"padding: 3px 0px 3px 0px;\n"
"border-radius:6px;\n"
"border:2px solid rgb(108, 117, 125, 65); \n"
"}\n"
"QMenu::item {\n"
"	font-size: 10pt;\n"
"	\n"
"	font: 10pt \"OPPOSans B\";\n"
"	\n"
"	color: rgb(63, 63, 63);\n"
"    background-color:rgb(253,253,254);\n"
"    padding: 5px 25px 5px 25px;\n"
"    /*margin: 2px 2px 2px 2px;*/\n"
"}\n"
"QMenu::item:selected {\n"
"    background-color : rgb(236,236,237);\n"
"}\n"
"QMenu::icon:checked {\n"
"    background: rgb(253,253,254);\n"
"    position: absolute;\n"
"    top: 1px;\n"
"    right: 1px;\n"
"    bottom: 1px;\n"
"    left: 1px;\n"
"}\n"
"QMenu::icon:checked:selected {\n"
"    background-color : rgb(236,236,237);\n"
"    background-image: url(:/space_selected.png);\n"
"}\n"
"QMenu::separator {\n"
"    height: 2px;\n"
"    background: rgb(235,235,236);\n"
"    /*margin-left: 10px;*/\n"
" "
                        "   /*margin-right: 10px;*/\n"
"}"));
        verticalLayout_7 = new QVBoxLayout(widget_bottom);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(5, 5, 5, 5);
        tabWidget = new QTabWidget(widget_bottom);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setFont(font);
        tabWidget->setContextMenuPolicy(Qt::CustomContextMenu);
        tabWidget->setStyleSheet(QString::fromUtf8("\n"
" QTabWidget::tab-bar {\n"
"         left:0px;       \n"
"}\n"
"	\n"
" \n"
"/*\350\256\276\347\275\256TabWidget\344\270\255QTabBar\347\232\204\346\240\267\345\274\217*/\n"
"QTabBar::tab{\n"
"    /*background-color: rgba(11, 11, 11,150);*/\n"
"	background-color: rgb(30, 45, 54);\n"
"	/*font-family:Consolas; */   /*\350\256\276\347\275\256tab\344\270\255\347\232\204\346\226\207\346\234\254\347\232\204\345\255\227\344\275\223*/\n"
"	font-size:10pt;\n"
"	color:#ced4da;    /*\350\256\276\347\275\256tab\344\270\255\347\232\204\346\226\207\346\234\254\347\232\204\351\242\234\350\211\262*/\n"
"	border-top-left-radius: 2px;    /*\350\256\276\347\275\256tab\347\232\204\350\276\271\346\241\206\347\232\204\345\234\206\350\247\222\357\274\210\345\267\246\344\270\212\345\234\206\350\247\222\357\274\211*/\n"
"	border-top-right-radius: 2px;    /*\350\256\276\347\275\256tab\347\232\204\350\276\271\346\241\206\347\232\204\345\234\206\350\247\222\357\274\210\345\217\263\344\270\212\345\234\206\350\247\222\357\274\211*/\n"
"	"
                        "/*width:120px;*/\n"
"	padding: 4px;\n"
"	margin-right:3px;\n"
"	margin-left: 0px;\n"
"	\n"
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
"	/*background-color: rgb(100, 117, 125, 255);*/\n"
"}\n"
" \n"
"/*\350\256\276\347\275\256TabWidget\347\232\204\350\276\271\346\241\206\347\232\204\346\240\267\345\274\217*/\n"
"QT"
                        "abWidget::pane {\n"
"   border:2px solid rgb(108, 117, 125, 65); \n"
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
        tabWidget->setTabShape(QTabWidget::Rounded);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridWidget = new QWidget(tab);
        gridWidget->setObjectName(QStringLiteral("gridWidget"));
        gridWidget->setGeometry(QRect(-1, -1, 301, 41));
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
        textEdit_2->setReadOnly(false);
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
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        progressBar_swap_2 = new QProgressBar(tab_4);
        progressBar_swap_2->setObjectName(QStringLiteral("progressBar_swap_2"));
        progressBar_swap_2->setGeometry(QRect(30, 200, 120, 14));
        progressBar_swap_2->setMinimumSize(QSize(120, 14));
        progressBar_swap_2->setMaximumSize(QSize(120, 14));
        progressBar_swap_2->setFont(font3);
        progressBar_swap_2->setStyleSheet(QLatin1String("QProgressBar {\n"
"	border: 0px solid;\n"
"	\n"
"	border-color: rgb(180, 180, 180);\n"
"	border-radius: 2px; \n"
"	background-color: #FFFFFF; \n"
"	text-align:center; \n"
"	color: rgba(0, 0, 0, 200);\n"
"}\n"
"\n"
"QProgressBar:chunk{\n"
"	border-radius:2px;\n"
"	\n"
"	background-color: rgb(0, 255, 0);\n"
"}"));
        progressBar_swap_2->setValue(0);
        progressBar_swap_2->setTextDirection(QProgressBar::TopToBottom);
        progressBar_cpu_2 = new QProgressBar(tab_4);
        progressBar_cpu_2->setObjectName(QStringLiteral("progressBar_cpu_2"));
        progressBar_cpu_2->setGeometry(QRect(30, 50, 120, 14));
        progressBar_cpu_2->setMinimumSize(QSize(120, 14));
        progressBar_cpu_2->setMaximumSize(QSize(120, 14));
        progressBar_cpu_2->setFont(font1);
        progressBar_cpu_2->setStyleSheet(QLatin1String("QProgressBar {\n"
"	border: 0px solid;\n"
"	\n"
"	border-color: rgb(180, 180, 180);\n"
"	border-radius: 2px; \n"
"	background-color: #FFFFFF; \n"
"	text-align:right; \n"
"	color: rgba(0, 0, 0, 200);\n"
"}\n"
"\n"
"QProgressBar:chunk{\n"
"	border-radius:2px;\n"
"	\n"
"	background-color: rgb(0, 255, 0);\n"
"}"));
        progressBar_cpu_2->setValue(29);
        progressBar_cpu_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        progressBar_cpu_2->setOrientation(Qt::Horizontal);
        progressBar_cpu_2->setTextDirection(QProgressBar::TopToBottom);
        label_swap_2 = new QLabel(tab_4);
        label_swap_2->setObjectName(QStringLiteral("label_swap_2"));
        label_swap_2->setGeometry(QRect(30, 170, 30, 20));
        label_swap_2->setFont(font1);
        label_cpu_2 = new QLabel(tab_4);
        label_cpu_2->setObjectName(QStringLiteral("label_cpu_2"));
        label_cpu_2->setGeometry(QRect(30, 20, 30, 20));
        label_cpu_2->setFont(font1);
        progressBar_mem_2 = new QProgressBar(tab_4);
        progressBar_mem_2->setObjectName(QStringLiteral("progressBar_mem_2"));
        progressBar_mem_2->setGeometry(QRect(30, 150, 120, 14));
        progressBar_mem_2->setMinimumSize(QSize(120, 14));
        progressBar_mem_2->setMaximumSize(QSize(120, 14));
        progressBar_mem_2->setFont(font3);
        progressBar_mem_2->setStyleSheet(QLatin1String("QProgressBar {\n"
"	border: 0px solid;\n"
"	\n"
"	border-color: rgb(180, 180, 180);\n"
"	border-radius: 2px; \n"
"	background-color: #FFFFFF; \n"
"	text-align:center; \n"
"	color: rgba(0, 0, 0, 200);\n"
"}\n"
"\n"
"QProgressBar:chunk{\n"
"	border-radius:2px;\n"
"	\n"
"	background-color: rgb(0, 255, 0);\n"
"}"));
        progressBar_mem_2->setValue(0);
        label_disk_2 = new QLabel(tab_4);
        label_disk_2->setObjectName(QStringLiteral("label_disk_2"));
        label_disk_2->setGeometry(QRect(30, 70, 30, 20));
        label_disk_2->setFont(font1);
        label_mem_2 = new QLabel(tab_4);
        label_mem_2->setObjectName(QStringLiteral("label_mem_2"));
        label_mem_2->setGeometry(QRect(30, 120, 30, 20));
        label_mem_2->setFont(font1);
        progressBar_disk_2 = new QProgressBar(tab_4);
        progressBar_disk_2->setObjectName(QStringLiteral("progressBar_disk_2"));
        progressBar_disk_2->setGeometry(QRect(30, 100, 120, 14));
        progressBar_disk_2->setMinimumSize(QSize(120, 14));
        progressBar_disk_2->setMaximumSize(QSize(120, 14));
        progressBar_disk_2->setFont(font3);
        progressBar_disk_2->setStyleSheet(QLatin1String("QProgressBar {\n"
"	border: 0px solid;\n"
"	\n"
"	border-color: rgb(180, 180, 180);\n"
"	border-radius: 2px; \n"
"	background-color: #FFFFFF; \n"
"	text-align:center; \n"
"	color: rgba(0, 0, 0, 200);\n"
"}\n"
"\n"
"QProgressBar:chunk{\n"
"	border-radius:2px;\n"
"	\n"
"	background-color: rgb(0, 255, 0);\n"
"}"));
        progressBar_disk_2->setValue(0);
        progressBar = new QProgressBar(tab_4);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(190, 70, 121, 23));
        progressBar->setFont(font);
        progressBar->setMaximum(100);
        progressBar->setValue(0);
        progressBar->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        progressBar->setInvertedAppearance(false);
        textEdit_4 = new QTextEdit(tab_4);
        textEdit_4->setObjectName(QStringLiteral("textEdit_4"));
        textEdit_4->setGeometry(QRect(630, 10, 471, 211));
        textEdit_4->setFont(font);
        tabWidget->addTab(tab_4, QString());

        verticalLayout_7->addWidget(tabWidget);

        widget_8 = new QWidget(widget_bottom);
        widget_8->setObjectName(QStringLiteral("widget_8"));
        widget_8->setMinimumSize(QSize(0, 25));
        widget_8->setMaximumSize(QSize(16777215, 25));
        widget_8->setFont(font);
        widget_8->setStyleSheet(QStringLiteral(""));
        horizontalLayout_5 = new QHBoxLayout(widget_8);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(2, 5, 2, 0);
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

        splitter_2->addWidget(widget_bottom);

        verticalLayout_6->addWidget(splitter_2);


        horizontalLayout_19->addWidget(widget_26);


        retranslateUi(sshwidget);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(sshwidget);
    } // setupUi

    void retranslateUi(QWidget *sshwidget)
    {
        sshwidget->setWindowTitle(QApplication::translate("sshwidget", "Form", nullptr));
        label_serverTitle->setText(QApplication::translate("sshwidget", "\346\234\215\345\212\241\345\231\250\344\277\241\346\201\257", nullptr));
        label_ip->setText(QApplication::translate("sshwidget", "IP -", nullptr));
        toolButton->setText(QApplication::translate("sshwidget", "\345\244\215\345\210\266", nullptr));
        label_runTime->setText(QApplication::translate("sshwidget", "\350\277\220\350\241\214 -", nullptr));
        label_loginCount->setText(QApplication::translate("sshwidget", "\347\273\210\347\253\257\347\224\250\346\210\267 -", nullptr));
        label_architecture->setText(QApplication::translate("sshwidget", "\347\263\273\347\273\237\346\236\266\346\236\204 -", nullptr));
        label_cpuInfo->setText(QApplication::translate("sshwidget", "cpu\344\277\241\346\201\257 -", nullptr));
        label_load->setText(QApplication::translate("sshwidget", "\350\264\237\350\275\275 -", nullptr));
        label_cpu->setText(QApplication::translate("sshwidget", "cpu", nullptr));
        progressBar_cpu->setFormat(QApplication::translate("sshwidget", "%p% ", nullptr));
        label_disk->setText(QApplication::translate("sshwidget", "io", nullptr));
        progressBar_disk->setFormat(QApplication::translate("sshwidget", "%p% ", nullptr));
        label_mem->setText(QApplication::translate("sshwidget", "\345\206\205\345\255\230", nullptr));
        progressBar_mem->setFormat(QApplication::translate("sshwidget", "%p% ", nullptr));
        label_swap->setText(QApplication::translate("sshwidget", "\344\272\244\346\215\242", nullptr));
        progressBar_swap->setFormat(QApplication::translate("sshwidget", "%p% ", nullptr));
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
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Cascadia Mono,OPPOSans B'; font-size:12pt;\">1\\\\b1</span></p></body></html>", nullptr));
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
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("sshwidget", "java", nullptr));
        progressBar_swap_2->setFormat(QApplication::translate("sshwidget", "%p%", nullptr));
        progressBar_cpu_2->setFormat(QApplication::translate("sshwidget", "%p%", nullptr));
        label_swap_2->setText(QApplication::translate("sshwidget", "\344\272\244\346\215\242", nullptr));
        label_cpu_2->setText(QApplication::translate("sshwidget", "cpu", nullptr));
        progressBar_mem_2->setFormat(QApplication::translate("sshwidget", "%p%", nullptr));
        label_disk_2->setText(QApplication::translate("sshwidget", "\347\243\201\347\233\230", nullptr));
        label_mem_2->setText(QApplication::translate("sshwidget", "\345\206\205\345\255\230", nullptr));
        progressBar_disk_2->setFormat(QApplication::translate("sshwidget", "%p%", nullptr));
        textEdit_4->setHtml(QApplication::translate("sshwidget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'OPPOSans B'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#ff0000;\">123.tar.gz111111111111111111111111</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#ff0000;\">ew</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#ff0000;\">ewq</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color"
                        ":#ff0000;\">eq</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#ff0000;\">ewq</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#ff0000;\">ewq</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#ff0000;\">ew</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#ff0000;\">qe</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#ff0000;\">qe</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" co"
                        "lor:#ff0000;\">qe</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#ff0000;\">wqe</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#ff0000;\">q</span></p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("sshwidget", "\346\211\223\345\214\205", nullptr));
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
