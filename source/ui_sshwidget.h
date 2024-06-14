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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTabWidget>
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
    QLabel *label_infoTip;
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
    QHBoxLayout *horizontalLayout_8;
    QWidget *widget_9;
    QPlainTextEdit *plainTextEdit;
    QScrollBar *verticalScrollBar;
    QWidget *widget_toolbar;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_toolbar_s;
    QHBoxLayout *horizontalLayout_6;
    QToolButton *toolButton_info;
    QToolButton *toolButton_find;
    QToolButton *toolButton_command;
    QToolButton *toolButton_history;
    QToolButton *toolButton_upload;
    QToolButton *toolButton_conectStats;
    QToolButton *toolButton_toolkit;
    QToolButton *toolButton_fullScreen;
    QSpacerItem *horizontalSpacer_3;
    QWidget *widget_bottom;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_7;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_3;
    QWidget *tab_3;
    QWidget *tab_4;
    QWidget *tab_5;
    QVBoxLayout *verticalLayout_9;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_command;
    QLabel *label_edit;
    QToolButton *toolButton_edit;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_4;

    void setupUi(QWidget *sshwidget)
    {
        if (sshwidget->objectName().isEmpty())
            sshwidget->setObjectName(QStringLiteral("sshwidget"));
        sshwidget->resize(1391, 699);
        sshwidget->setStyleSheet(QStringLiteral(""));
        sshwidget->setLocale(QLocale(QLocale::English, QLocale::Kenya));
        horizontalLayout_19 = new QHBoxLayout(sshwidget);
        horizontalLayout_19->setSpacing(0);
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        horizontalLayout_19->setContentsMargins(0, 0, 0, 10);
        widget = new QWidget(sshwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(150, 0));
        widget->setMaximumSize(QSize(150, 16777215));
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
        verticalLayout_3->setContentsMargins(3, 10, 3, 5);
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
        progressBar_cpu->setMinimumSize(QSize(140, 18));
        progressBar_cpu->setMaximumSize(QSize(140, 18));
        progressBar_cpu->setFont(font1);
        progressBar_cpu->setStyleSheet(QLatin1String("QProgressBar {\n"
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
        progressBar_cpu->setValue(0);
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
        progressBar_disk->setMinimumSize(QSize(140, 18));
        progressBar_disk->setMaximumSize(QSize(140, 18));
        QFont font3;
        font3.setFamily(QStringLiteral("OPPOSans B"));
        font3.setPointSize(9);
        progressBar_disk->setFont(font3);
        progressBar_disk->setLayoutDirection(Qt::LeftToRight);
        progressBar_disk->setStyleSheet(QLatin1String("QProgressBar {\n"
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
        progressBar_mem->setMinimumSize(QSize(140, 18));
        progressBar_mem->setMaximumSize(QSize(140, 18));
        progressBar_mem->setFont(font3);
        progressBar_mem->setLayoutDirection(Qt::LeftToRight);
        progressBar_mem->setStyleSheet(QLatin1String("QProgressBar {\n"
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
        progressBar_swap->setMinimumSize(QSize(140, 18));
        progressBar_swap->setMaximumSize(QSize(140, 18));
        progressBar_swap->setFont(font3);
        progressBar_swap->setLayoutDirection(Qt::LeftToRight);
        progressBar_swap->setStyleSheet(QLatin1String("QProgressBar {\n"
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
        progressBar_swap->setValue(0);
        progressBar_swap->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        progressBar_swap->setInvertedAppearance(false);
        progressBar_swap->setTextDirection(QProgressBar::TopToBottom);

        verticalLayout->addWidget(progressBar_swap);


        verticalLayout_3->addWidget(widget_swap_info);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        label_infoTip = new QLabel(widget);
        label_infoTip->setObjectName(QStringLiteral("label_infoTip"));
        label_infoTip->setFont(font);
        label_infoTip->setStyleSheet(QStringLiteral("color: rgba(223, 223, 223, 150);"));
        label_infoTip->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_infoTip);


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
        verticalLayout_5->setContentsMargins(0, 0, 12, 0);
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
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1229, 349));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy);
        scrollAreaWidgetContents->setMinimumSize(QSize(0, 0));
        scrollAreaWidgetContents->setMaximumSize(QSize(16777215, 1080));
        scrollAreaWidgetContents->setStyleSheet(QLatin1String("border-color: rgba(255, 255, 255, 0);\n"
"background:transparent;"));
        horizontalLayout_8 = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout_8->setSpacing(0);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        widget_9 = new QWidget(scrollAreaWidgetContents);
        widget_9->setObjectName(QStringLiteral("widget_9"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget_9->sizePolicy().hasHeightForWidth());
        widget_9->setSizePolicy(sizePolicy1);
        widget_9->setStyleSheet(QLatin1String("QMenu {\n"
"background-color: rgb(255, 255, 255);\n"
"padding:10px;\n"
"margin:10px;\n"
"/*padding: 3px 0px 3px 0px;*/\n"
"border-radius:6px;\n"
"border:0px solid rgb(108, 117, 125, 65); \n"
"	\n"
"}\n"
"QMenu::item {\n"
"	font-size: 10pt;\n"
"	font: 10pt \"OPPOSans B\";\n"
"	\n"
"	\n"
"	color: rgb(59, 59, 59);\n"
"    background-color: rgb(255, 255, 255);\n"
"    /*padding: 5px 25px 5px 25px;*/\n"
"    /*margin-left: 10px;*/\n"
"    /*margin-right: 10px;*/\n"
"}\n"
"QMenu::item:selected {\n"
"	background-color: rgba(167, 167, 167, 200);\n"
"	border-radius:6px;\n"
"\n"
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
"    height: 1px;\n"
"    background: rgb(80, 80, 80,200);\n"
"    /*margin-left: 10px;*/\n"
"    /*margi"
                        "n-right: 10px;*/\n"
"}"));
        plainTextEdit = new QPlainTextEdit(widget_9);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setEnabled(true);
        plainTextEdit->setGeometry(QRect(410, 30, 371, 91));
        sizePolicy1.setHeightForWidth(plainTextEdit->sizePolicy().hasHeightForWidth());
        plainTextEdit->setSizePolicy(sizePolicy1);
        plainTextEdit->setMaximumSize(QSize(16777215, 5555555));
        QFont font4;
        font4.setFamily(QStringLiteral("Cascadia Mono,OPPOSans B"));
        font4.setPointSize(12);
        font4.setBold(false);
        font4.setItalic(false);
        font4.setWeight(50);
        font4.setStyleStrategy(QFont::PreferAntialias);
        plainTextEdit->setFont(font4);
        plainTextEdit->setStyleSheet(QString::fromUtf8("QPlainTextEdit{\n"
"	/*background-color: rgba(0, 41, 69, 0);*/\n"
"	font: 12pt \"Cascadia Mono,OPPOSans B\";\n"
"	border: none;\n"
"	padding-top:0px;\n"
"    padding-bottom:0px;\n"
"	padding-left:0px;\n"
"    padding-right:0px;\n"
"	border-radius: 0px;\n"
"    color: rgba(0,0,0,0);\n"
"}\n"
"\n"
"QPlainTextEdit::cursor {\n"
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
"	background-color: rgba(255, 255, 255,"
                        " 0);\n"
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
        plainTextEdit->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        plainTextEdit->setLineWidth(1);

        horizontalLayout_8->addWidget(widget_9);

        verticalScrollBar = new QScrollBar(scrollAreaWidgetContents);
        verticalScrollBar->setObjectName(QStringLiteral("verticalScrollBar"));
        QFont font5;
        font5.setStyleStrategy(QFont::PreferAntialias);
        verticalScrollBar->setFont(font5);
        verticalScrollBar->setStyleSheet(QString::fromUtf8("QScrollBar:vertical{\n"
"    width: 10px;\n"
"	/*background-color: rgba(0, 41, 69, 0);*/\n"
"	\n"
"	\n"
"	background-color: rgb(57, 91, 121);\n"
"    margin: 0px,0px,0px,0px;\n"
"    padding-top: 0px;		/*//\351\232\220\350\227\217\344\270\212\344\270\213\347\232\204\347\256\255\345\244\264*/\n"
"    padding-bottom: 0px;\n"
"}\n"
"\n"
"\n"
"QScrollBar::handle:vertical{\n"
"    width: 10px;\n"
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
"    border: "
                        "none;\n"
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
        verticalScrollBar->setMaximum(5000);
        verticalScrollBar->setSingleStep(1);
        verticalScrollBar->setOrientation(Qt::Vertical);

        horizontalLayout_8->addWidget(verticalScrollBar);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_5->addWidget(scrollArea);


        verticalLayout_14->addWidget(widget_10);

        widget_toolbar = new QWidget(widget_2);
        widget_toolbar->setObjectName(QStringLiteral("widget_toolbar"));
        widget_toolbar->setMinimumSize(QSize(0, 40));
        widget_toolbar->setMaximumSize(QSize(16777215, 40));
        widget_toolbar->setStyleSheet(QLatin1String("#widget_toolbar{\n"
"/*background-color: rgb(30, 45, 54);*/\n"
"border-bottom:0px solid rgb(108, 117, 125, 65); \n"
"}\n"
""));
        horizontalLayout_7 = new QHBoxLayout(widget_toolbar);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 10);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_2);

        widget_toolbar_s = new QWidget(widget_toolbar);
        widget_toolbar_s->setObjectName(QStringLiteral("widget_toolbar_s"));
        widget_toolbar_s->setMinimumSize(QSize(0, 30));
        widget_toolbar_s->setMaximumSize(QSize(450, 30));
        widget_toolbar_s->setStyleSheet(QLatin1String("background-color: rgba(10, 31, 57, 200);\n"
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
        widget_bottom->setStyleSheet(QLatin1String("/*#widget_bottom {\n"
"	\n"
"	background-color: rgb(10, 31, 57);\n"
"	border-radius: 10px;\n"
"}*/\n"
"QToolButton {\n"
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
"    t"
                        "op: 1px;\n"
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
        horizontalLayout_2 = new QHBoxLayout(widget_bottom);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_3 = new QWidget(widget_bottom);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setStyleSheet(QLatin1String("#widget_3 {\n"
"	background-color: rgba(10, 31, 57, 200);\n"
"	border-radius: 10px;\n"
"}\n"
""));
        verticalLayout_7 = new QVBoxLayout(widget_3);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(10, 5, 10, 0);
        tabWidget = new QTabWidget(widget_3);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setFont(font);
        tabWidget->setContextMenuPolicy(Qt::CustomContextMenu);
        tabWidget->setStyleSheet(QString::fromUtf8("\n"
"QTabWidget::tab-bar {\n"
"         left:0px;  \n"
"     \n"
"}\n"
"\n"
"	\n"
" \n"
"/*\350\256\276\347\275\256TabWidget\344\270\255QTabBar\347\232\204\346\240\267\345\274\217*/\n"
"QTabBar::tab{\n"
"    /*background-color: rgba(11, 11, 11,150);*/\n"
"	\n"
"	\n"
"	background-color: rgb(10, 31, 57);\n"
"	/*font-family:Consolas; */   /*\350\256\276\347\275\256tab\344\270\255\347\232\204\346\226\207\346\234\254\347\232\204\345\255\227\344\275\223*/\n"
"	font-size:10pt;\n"
"	color:#ced4da;    /*\350\256\276\347\275\256tab\344\270\255\347\232\204\346\226\207\346\234\254\347\232\204\351\242\234\350\211\262*/\n"
"	border-top-left-radius: 2px;    /*\350\256\276\347\275\256tab\347\232\204\350\276\271\346\241\206\347\232\204\345\234\206\350\247\222\357\274\210\345\267\246\344\270\212\345\234\206\350\247\222\357\274\211*/\n"
"	border-top-right-radius: 2px;    /*\350\256\276\347\275\256tab\347\232\204\350\276\271\346\241\206\347\232\204\345\234\206\350\247\222\357\274\210\345\217\263\344\270\212\345\234\206\350\247\222"
                        "\357\274\211*/\n"
"	/*width:120px;*/\n"
"	padding-left: 5px;\n"
"	padding-right: 5px;\n"
"	height:25;\n"
"	/*margin-right:5px;\n"
"	margin-left: 5px;*/\n"
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
"/*\350\256\276\347\275\256TabWidget\347\232\204"
                        "\350\276\271\346\241\206\347\232\204\346\240\267\345\274\217*/\n"
"QTabWidget::pane {\n"
"   border-top:2px solid rgb(108, 117, 125, 65); \n"
"   border-bottom:1px solid rgb(108, 117, 125, 65); \n"
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
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        horizontalLayout_3 = new QHBoxLayout(tab_2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        verticalLayout_9 = new QVBoxLayout(tab_5);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        tabWidget->addTab(tab_5, QString());

        verticalLayout_7->addWidget(tabWidget);

        widget_8 = new QWidget(widget_3);
        widget_8->setObjectName(QStringLiteral("widget_8"));
        widget_8->setMinimumSize(QSize(0, 30));
        widget_8->setMaximumSize(QSize(16777215, 30));
        widget_8->setFont(font);
        widget_8->setStyleSheet(QLatin1String("#widget_8 {\n"
"	border-bottom-left-radius: 10px;\n"
"	border-bottom-right-radius: 10px;\n"
"}\n"
""));
        horizontalLayout_5 = new QHBoxLayout(widget_8);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(10, 5, 10, 5);
        label_command = new QLabel(widget_8);
        label_command->setObjectName(QStringLiteral("label_command"));
        label_command->setFont(font);
        label_command->setStyleSheet(QLatin1String("background-color: rgb(80, 130, 120);\n"
"color: rgb(255, 255, 255);\n"
"border-radius: 2px;"));
        label_command->setLineWidth(1);
        label_command->setMargin(3);
        label_command->setIndent(0);

        horizontalLayout_5->addWidget(label_command);

        label_edit = new QLabel(widget_8);
        label_edit->setObjectName(QStringLiteral("label_edit"));
        label_edit->setFont(font);
        label_edit->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_edit->setMargin(2);

        horizontalLayout_5->addWidget(label_edit);

        toolButton_edit = new QToolButton(widget_8);
        toolButton_edit->setObjectName(QStringLiteral("toolButton_edit"));
        toolButton_edit->setMinimumSize(QSize(0, 0));
        toolButton_edit->setFont(font);
        toolButton_edit->setStyleSheet(QLatin1String("QToolButton {\n"
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

        horizontalLayout_5->addWidget(toolButton_edit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);


        verticalLayout_7->addWidget(widget_8);


        horizontalLayout_2->addWidget(widget_3);

        widget_4 = new QWidget(widget_bottom);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setMinimumSize(QSize(10, 0));
        widget_4->setMaximumSize(QSize(10, 16777215));
        widget_4->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);"));

        horizontalLayout_2->addWidget(widget_4);

        splitter_2->addWidget(widget_bottom);

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
        label_infoTip->setText(QApplication::translate("sshwidget", "\345\217\257\345\234\250\350\256\276\347\275\256\344\270\255\345\205\263\351\227\255\346\230\276\347\244\272", nullptr));
        toolButton_info->setText(QApplication::translate("sshwidget", "\344\277\241\346\201\257", nullptr));
        toolButton_find->setText(QApplication::translate("sshwidget", "\346\237\245\346\211\276", nullptr));
        toolButton_command->setText(QApplication::translate("sshwidget", "\345\277\253\346\215\267\345\221\275\344\273\244", nullptr));
        toolButton_history->setText(QApplication::translate("sshwidget", "\345\216\206\345\217\262", nullptr));
        toolButton_upload->setText(QApplication::translate("sshwidget", "\344\270\212\344\274\240", nullptr));
        toolButton_conectStats->setText(QApplication::translate("sshwidget", "\345\261\236\346\200\247", nullptr));
        toolButton_toolkit->setText(QApplication::translate("sshwidget", "\345\267\245\345\205\267\351\233\206", nullptr));
        toolButton_fullScreen->setText(QApplication::translate("sshwidget", "\345\205\250\345\261\217", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("sshwidget", " \351\273\230\350\256\244\345\210\206\347\261\273 ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("sshwidget", " minic ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("sshwidget", " java ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("sshwidget", " \346\211\223\345\214\205 ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("sshwidget", "\351\241\265", nullptr));
        label_command->setText(QApplication::translate("sshwidget", "\346\211\247\350\241\214\345\244\207\344\273\275", nullptr));
        label_edit->setText(QApplication::translate("sshwidget", "/data/linkdood/im/bin/databack/databak -c ", nullptr));
        toolButton_edit->setText(QApplication::translate("sshwidget", "\347\274\226\350\276\221", nullptr));
    } // retranslateUi

};

namespace Ui {
    class sshwidget: public Ui_sshwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SSHWIDGET_H
