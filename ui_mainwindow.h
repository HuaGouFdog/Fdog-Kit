/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QWidget *widget_title;
    QHBoxLayout *horizontalLayout;
    QLabel *label_icon;
    QLabel *label_title;
    QSpacerItem *horizontalSpacer;
    QToolButton *toolButton_min;
    QToolButton *toolButton_max;
    QToolButton *toolButton_close;
    QWidget *widget_line;
    QVBoxLayout *verticalLayout_3;
    QFrame *line;
    QWidget *widget_tool;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *toolButton_newCreate;
    QToolButton *toolButton_tool;
    QToolButton *toolButton_setting;
    QToolButton *toolButton_about;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_line_2;
    QVBoxLayout *verticalLayout_5;
    QFrame *line_2;
    QWidget *widget_body;
    QVBoxLayout *verticalLayout_2;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_4;
    QTabWidget *tabWidget;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_6;
    QWidget *widget;
    QWidget *page_3;
    QVBoxLayout *verticalLayout_7;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_13;
    QWidget *widget_11;
    QVBoxLayout *verticalLayout_9;
    QWidget *widget_welcome_body;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *widget_welcome_body_horizontalSpacer_left;
    QWidget *widget_welcome_body_widget;
    QHBoxLayout *horizontalLayout_4;
    QWidget *widget_welcome_body_widget2;
    QVBoxLayout *verticalLayout_8;
    QSpacerItem *widget_welcome_body_widget2_verticalSpacer_top;
    QWidget *widget_welcome_body_widget2_info;
    QVBoxLayout *verticalLayout_11;
    QWidget *widget_welcome_body_widget2_info_widget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *widget_welcome_body_widget2_info_widget_icon;
    QLabel *widget_welcome_body_widget2_info_text;
    QWidget *widget_welcome_body_widget2_newCreate;
    QVBoxLayout *verticalLayout_10;
    QToolButton *widget_welcome_body_widget2_newCreate_newTerminal;
    QToolButton *widget_welcome_body_widget2_newCreate_newTool;
    QToolButton *widget_welcome_body_widget2_newCreate_setting;
    QWidget *widget_welcome_body_widget2_nearestConnectionInfo;
    QVBoxLayout *verticalLayout_16;
    QToolButton *widget_welcome_body_widget2_nearestConnectionInfo_nearest;
    QWidget *widget_welcome_body_widget2_nearestConnectionInfo_list;
    QVBoxLayout *verticalLayout_17;
    QToolButton *toolButton_20;
    QToolButton *toolButton_21;
    QToolButton *toolButton_25;
    QToolButton *widget_welcome_body_widget2_nearestConnectionInfo_more;
    QSpacerItem *widget_welcome_body_widget2_verticalSpacer_bottom;
    QSpacerItem *widget_welcome_body_horizontalSpacer_right;
    QWidget *widget_welcome_bottom;
    QHBoxLayout *horizontalLayout_6;
    QToolButton *widget_welcome_bottom_toolButton_github;
    QSpacerItem *widget_welcome_bottom_horizontalSpacer_left;
    QCheckBox *widget_welcome_bottom_showWelcome;
    QSpacerItem *widget_welcome_page_bottom_horizontalSpacer_right;
    QLabel *widget_welcome_page_bottom_label_version;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1067, 650);
        MainWindow->setMinimumSize(QSize(0, 0));
        QFont font;
        font.setFamily(QStringLiteral("Cascadia Mono"));
        font.setPointSize(10);
        font.setStyleStrategy(QFont::PreferAntialias);
        MainWindow->setFont(font);
        MainWindow->setCursor(QCursor(Qt::ArrowCursor));
        QIcon icon;
        icon.addFile(QStringLiteral(":/lib/wicon_46.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QLatin1String("QMainWindow,QWidget#centralWidget {\n"
"background-color: rgb(67, 77, 88);\n"
"border-radius:6px;\n"
"}"));
        MainWindow->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QLatin1String("background-color: rgb(67, 77, 88);\n"
"color: rgb(255, 255, 255);"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(6, 6, 6, 6);
        widget_title = new QWidget(centralWidget);
        widget_title->setObjectName(QStringLiteral("widget_title"));
        widget_title->setMinimumSize(QSize(0, 22));
        widget_title->setMaximumSize(QSize(16777215, 24));
        widget_title->setStyleSheet(QLatin1String("background-color: rgb(67, 77, 88);\n"
"color: rgb(255, 255, 255);"));
        horizontalLayout = new QHBoxLayout(widget_title);
        horizontalLayout->setSpacing(4);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 1, 0, 2);
        label_icon = new QLabel(widget_title);
        label_icon->setObjectName(QStringLiteral("label_icon"));
        label_icon->setMinimumSize(QSize(20, 20));
        label_icon->setMaximumSize(QSize(20, 20));
        label_icon->setStyleSheet(QStringLiteral("border-image: url(:/lib/wicon_46.png);"));

        horizontalLayout->addWidget(label_icon);

        label_title = new QLabel(widget_title);
        label_title->setObjectName(QStringLiteral("label_title"));
        QFont font1;
        font1.setFamily(QStringLiteral("OPPOSans B"));
        font1.setPointSize(10);
        font1.setStyleStrategy(QFont::PreferAntialias);
        label_title->setFont(font1);
        label_title->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(label_title);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        toolButton_min = new QToolButton(widget_title);
        toolButton_min->setObjectName(QStringLiteral("toolButton_min"));
        toolButton_min->setMinimumSize(QSize(20, 20));
        toolButton_min->setMaximumSize(QSize(20, 20));
        QFont font2;
        font2.setPointSize(10);
        font2.setStyleStrategy(QFont::PreferAntialias);
        toolButton_min->setFont(font2);
        toolButton_min->setStyleSheet(QLatin1String("QToolButton {\n"
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
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/lib/icon-minus3.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_min->setIcon(icon1);
        toolButton_min->setIconSize(QSize(19, 19));

        horizontalLayout->addWidget(toolButton_min);

        toolButton_max = new QToolButton(widget_title);
        toolButton_max->setObjectName(QStringLiteral("toolButton_max"));
        toolButton_max->setMinimumSize(QSize(20, 20));
        toolButton_max->setMaximumSize(QSize(20, 20));
        toolButton_max->setFont(font2);
        toolButton_max->setStyleSheet(QLatin1String("QToolButton {\n"
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
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/lib/Icon_max3.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_max->setIcon(icon2);
        toolButton_max->setIconSize(QSize(16, 16));
        toolButton_max->setCheckable(false);
        toolButton_max->setAutoRepeat(false);
        toolButton_max->setAutoExclusive(false);
        toolButton_max->setAutoRaise(false);

        horizontalLayout->addWidget(toolButton_max);

        toolButton_close = new QToolButton(widget_title);
        toolButton_close->setObjectName(QStringLiteral("toolButton_close"));
        toolButton_close->setMinimumSize(QSize(20, 20));
        toolButton_close->setMaximumSize(QSize(20, 20));
        toolButton_close->setFont(font2);
        toolButton_close->setStyleSheet(QLatin1String("QToolButton {\n"
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
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/lib/icon-close8.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_close->setIcon(icon3);
        toolButton_close->setIconSize(QSize(13, 13));
        toolButton_close->setCheckable(false);

        horizontalLayout->addWidget(toolButton_close);


        verticalLayout->addWidget(widget_title);

        widget_line = new QWidget(centralWidget);
        widget_line->setObjectName(QStringLiteral("widget_line"));
        widget_line->setMinimumSize(QSize(0, 2));
        widget_line->setMaximumSize(QSize(16777215, 2));
        verticalLayout_3 = new QVBoxLayout(widget_line);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        line = new QFrame(widget_line);
        line->setObjectName(QStringLiteral("line"));
        line->setMinimumSize(QSize(0, 2));
        line->setMaximumSize(QSize(16777215, 2));
        line->setStyleSheet(QStringLiteral("background-color: rgb(108, 117, 125, 65);"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line);


        verticalLayout->addWidget(widget_line);

        widget_tool = new QWidget(centralWidget);
        widget_tool->setObjectName(QStringLiteral("widget_tool"));
        horizontalLayout_2 = new QHBoxLayout(widget_tool);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        toolButton_newCreate = new QToolButton(widget_tool);
        toolButton_newCreate->setObjectName(QStringLiteral("toolButton_newCreate"));
        toolButton_newCreate->setMinimumSize(QSize(0, 20));
        toolButton_newCreate->setMaximumSize(QSize(55, 16777215));
        toolButton_newCreate->setFont(font1);
        toolButton_newCreate->setStyleSheet(QLatin1String("QToolButton {\n"
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
        toolButton_newCreate->setIconSize(QSize(16, 16));
        toolButton_newCreate->setPopupMode(QToolButton::InstantPopup);
        toolButton_newCreate->setToolButtonStyle(Qt::ToolButtonTextOnly);

        horizontalLayout_2->addWidget(toolButton_newCreate);

        toolButton_tool = new QToolButton(widget_tool);
        toolButton_tool->setObjectName(QStringLiteral("toolButton_tool"));
        toolButton_tool->setMinimumSize(QSize(0, 20));
        toolButton_tool->setMaximumSize(QSize(55, 16777215));
        toolButton_tool->setFont(font1);
        toolButton_tool->setStyleSheet(QLatin1String("QToolButton {\n"
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
        toolButton_tool->setIconSize(QSize(14, 14));
        toolButton_tool->setPopupMode(QToolButton::InstantPopup);
        toolButton_tool->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_2->addWidget(toolButton_tool);

        toolButton_setting = new QToolButton(widget_tool);
        toolButton_setting->setObjectName(QStringLiteral("toolButton_setting"));
        toolButton_setting->setMinimumSize(QSize(0, 20));
        toolButton_setting->setMaximumSize(QSize(55, 16777215));
        toolButton_setting->setFont(font1);
        toolButton_setting->setStyleSheet(QLatin1String("QToolButton {\n"
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
        toolButton_setting->setIconSize(QSize(14, 14));
        toolButton_setting->setPopupMode(QToolButton::InstantPopup);
        toolButton_setting->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_2->addWidget(toolButton_setting);

        toolButton_about = new QToolButton(widget_tool);
        toolButton_about->setObjectName(QStringLiteral("toolButton_about"));
        toolButton_about->setMinimumSize(QSize(0, 20));
        toolButton_about->setMaximumSize(QSize(55, 16777215));
        toolButton_about->setFont(font1);
        toolButton_about->setStyleSheet(QLatin1String("QToolButton {\n"
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
        toolButton_about->setIconSize(QSize(13, 14));
        toolButton_about->setPopupMode(QToolButton::InstantPopup);
        toolButton_about->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_2->addWidget(toolButton_about);

        horizontalSpacer_2 = new QSpacerItem(50, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget_tool);

        widget_line_2 = new QWidget(centralWidget);
        widget_line_2->setObjectName(QStringLiteral("widget_line_2"));
        widget_line_2->setMinimumSize(QSize(0, 2));
        widget_line_2->setMaximumSize(QSize(16777215, 3));
        verticalLayout_5 = new QVBoxLayout(widget_line_2);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        line_2 = new QFrame(widget_line_2);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setMinimumSize(QSize(0, 2));
        line_2->setMaximumSize(QSize(16777215, 2));
        line_2->setStyleSheet(QStringLiteral("background-color: rgb(108, 117, 125, 65);"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line_2);


        verticalLayout->addWidget(widget_line_2);

        widget_body = new QWidget(centralWidget);
        widget_body->setObjectName(QStringLiteral("widget_body"));
        widget_body->setStyleSheet(QStringLiteral("background-color: rgb(67, 77, 88);"));
        verticalLayout_2 = new QVBoxLayout(widget_body);
        verticalLayout_2->setSpacing(5);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(widget_body);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setStyleSheet(QLatin1String("background-color: rgb(67, 77, 88);\n"
"color: rgb(255, 255, 255);"));
        stackedWidget->setLineWidth(1);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        page->setStyleSheet(QLatin1String("background-color: rgb(67, 77, 88);\n"
"color: rgb(255, 255, 255);"));
        verticalLayout_4 = new QVBoxLayout(page);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(page);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        QFont font3;
        font3.setFamily(QStringLiteral("OPPOSans B"));
        font3.setPointSize(11);
        font3.setStyleStrategy(QFont::PreferAntialias);
        tabWidget->setFont(font3);
        tabWidget->setStyleSheet(QString::fromUtf8("\n"
" QTabWidget::tab-bar {\n"
"         left:0px;       \n"
"}\n"
"	\n"
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
"	border-top-left-radius: 5px;    /*\350\256\276\347\275\256tab\347\232\204\350\276\271\346\241\206\347\232\204\345\234\206\350"
                        "\247\222\357\274\210\345\267\246\344\270\212\345\234\206\350\247\222\357\274\211*/\n"
"	border-top-right-radius: 5px;    /*\350\256\276\347\275\256tab\347\232\204\350\276\271\346\241\206\347\232\204\345\234\206\350\247\222\357\274\210\345\217\263\344\270\212\345\234\206\350\247\222\357\274\211*/\n"
"	/*width:120px;*/\n"
"	padding: 2px;\n"
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
"/*\350\256\276\347\275\256TabWidget\347\232"
                        "\204\350\276\271\346\241\206\347\232\204\346\240\267\345\274\217*/\n"
"QTabWidget::pane {\n"
"    border: 0px solid rgb(108, 117, 125, 65);\n"
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
        tabWidget->setTabsClosable(true);
        tabWidget->setMovable(true);

        verticalLayout_4->addWidget(tabWidget);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        verticalLayout_6 = new QVBoxLayout(page_2);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(page_2);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setStyleSheet(QStringLiteral(""));

        verticalLayout_6->addWidget(widget);

        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        page_3->setStyleSheet(QStringLiteral(""));
        verticalLayout_7 = new QVBoxLayout(page_3);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(page_3);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setStyleSheet(QStringLiteral(""));
        verticalLayout_13 = new QVBoxLayout(widget_2);
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setContentsMargins(11, 11, 11, 11);
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        verticalLayout_13->setContentsMargins(9, 3, 9, 3);
        widget_11 = new QWidget(widget_2);
        widget_11->setObjectName(QStringLiteral("widget_11"));
        verticalLayout_9 = new QVBoxLayout(widget_11);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        widget_welcome_body = new QWidget(widget_11);
        widget_welcome_body->setObjectName(QStringLiteral("widget_welcome_body"));
        horizontalLayout_5 = new QHBoxLayout(widget_welcome_body);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        widget_welcome_body_horizontalSpacer_left = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(widget_welcome_body_horizontalSpacer_left);

        widget_welcome_body_widget = new QWidget(widget_welcome_body);
        widget_welcome_body_widget->setObjectName(QStringLiteral("widget_welcome_body_widget"));
        horizontalLayout_4 = new QHBoxLayout(widget_welcome_body_widget);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        widget_welcome_body_widget2 = new QWidget(widget_welcome_body_widget);
        widget_welcome_body_widget2->setObjectName(QStringLiteral("widget_welcome_body_widget2"));
        widget_welcome_body_widget2->setLayoutDirection(Qt::LeftToRight);
        verticalLayout_8 = new QVBoxLayout(widget_welcome_body_widget2);
        verticalLayout_8->setSpacing(30);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        widget_welcome_body_widget2_verticalSpacer_top = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(widget_welcome_body_widget2_verticalSpacer_top);

        widget_welcome_body_widget2_info = new QWidget(widget_welcome_body_widget2);
        widget_welcome_body_widget2_info->setObjectName(QStringLiteral("widget_welcome_body_widget2_info"));
        widget_welcome_body_widget2_info->setMinimumSize(QSize(0, 130));
        widget_welcome_body_widget2_info->setMaximumSize(QSize(16777215, 130));
        verticalLayout_11 = new QVBoxLayout(widget_welcome_body_widget2_info);
        verticalLayout_11->setSpacing(0);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        widget_welcome_body_widget2_info_widget = new QWidget(widget_welcome_body_widget2_info);
        widget_welcome_body_widget2_info_widget->setObjectName(QStringLiteral("widget_welcome_body_widget2_info_widget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(48);
        sizePolicy1.setVerticalStretch(48);
        sizePolicy1.setHeightForWidth(widget_welcome_body_widget2_info_widget->sizePolicy().hasHeightForWidth());
        widget_welcome_body_widget2_info_widget->setSizePolicy(sizePolicy1);
        widget_welcome_body_widget2_info_widget->setMinimumSize(QSize(64, 64));
        widget_welcome_body_widget2_info_widget->setMaximumSize(QSize(16777215, 64));
        horizontalLayout_3 = new QHBoxLayout(widget_welcome_body_widget2_info_widget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        widget_welcome_body_widget2_info_widget_icon = new QLabel(widget_welcome_body_widget2_info_widget);
        widget_welcome_body_widget2_info_widget_icon->setObjectName(QStringLiteral("widget_welcome_body_widget2_info_widget_icon"));
        widget_welcome_body_widget2_info_widget_icon->setMinimumSize(QSize(64, 64));
        widget_welcome_body_widget2_info_widget_icon->setMaximumSize(QSize(64, 64));
        QFont font4;
        font4.setFamily(QStringLiteral("OPPOSans B"));
        font4.setPointSize(20);
        font4.setStyleStrategy(QFont::PreferAntialias);
        widget_welcome_body_widget2_info_widget_icon->setFont(font4);
        widget_welcome_body_widget2_info_widget_icon->setStyleSheet(QStringLiteral("border-image: url(:/lib/wicon_64.png);"));

        horizontalLayout_3->addWidget(widget_welcome_body_widget2_info_widget_icon);


        verticalLayout_11->addWidget(widget_welcome_body_widget2_info_widget);

        widget_welcome_body_widget2_info_text = new QLabel(widget_welcome_body_widget2_info);
        widget_welcome_body_widget2_info_text->setObjectName(QStringLiteral("widget_welcome_body_widget2_info_text"));
        widget_welcome_body_widget2_info_text->setMinimumSize(QSize(0, 45));
        widget_welcome_body_widget2_info_text->setMaximumSize(QSize(16777215, 45));
        QFont font5;
        font5.setFamily(QStringLiteral("OPPOSans B"));
        font5.setPointSize(20);
        font5.setBold(false);
        font5.setItalic(false);
        font5.setWeight(50);
        font5.setStyleStrategy(QFont::PreferAntialias);
        widget_welcome_body_widget2_info_text->setFont(font5);
        widget_welcome_body_widget2_info_text->setStyleSheet(QLatin1String("color: qlineargradient(spread:pad, x1:0.789318, y1:0.358, x2:1, y2:1, stop:0 rgba(0, 213, 205, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgb(242, 245, 255);"));
        widget_welcome_body_widget2_info_text->setAlignment(Qt::AlignCenter);

        verticalLayout_11->addWidget(widget_welcome_body_widget2_info_text);


        verticalLayout_8->addWidget(widget_welcome_body_widget2_info);

        widget_welcome_body_widget2_newCreate = new QWidget(widget_welcome_body_widget2);
        widget_welcome_body_widget2_newCreate->setObjectName(QStringLiteral("widget_welcome_body_widget2_newCreate"));
        widget_welcome_body_widget2_newCreate->setMinimumSize(QSize(250, 120));
        widget_welcome_body_widget2_newCreate->setMaximumSize(QSize(250, 120));
        widget_welcome_body_widget2_newCreate->setStyleSheet(QLatin1String("background-color: rgba(217, 236, 237, 10);\n"
"border-radius: 10px;"));
        verticalLayout_10 = new QVBoxLayout(widget_welcome_body_widget2_newCreate);
        verticalLayout_10->setSpacing(3);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(15, 10, 15, 10);
        widget_welcome_body_widget2_newCreate_newTerminal = new QToolButton(widget_welcome_body_widget2_newCreate);
        widget_welcome_body_widget2_newCreate_newTerminal->setObjectName(QStringLiteral("widget_welcome_body_widget2_newCreate_newTerminal"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(50);
        sizePolicy2.setVerticalStretch(50);
        sizePolicy2.setHeightForWidth(widget_welcome_body_widget2_newCreate_newTerminal->sizePolicy().hasHeightForWidth());
        widget_welcome_body_widget2_newCreate_newTerminal->setSizePolicy(sizePolicy2);
        widget_welcome_body_widget2_newCreate_newTerminal->setMinimumSize(QSize(0, 30));
        widget_welcome_body_widget2_newCreate_newTerminal->setFont(font1);
        widget_welcome_body_widget2_newCreate_newTerminal->setLayoutDirection(Qt::LeftToRight);
        widget_welcome_body_widget2_newCreate_newTerminal->setStyleSheet(QLatin1String("QToolButton {\n"
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
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/lib/add3.png"), QSize(), QIcon::Normal, QIcon::Off);
        widget_welcome_body_widget2_newCreate_newTerminal->setIcon(icon4);
        widget_welcome_body_widget2_newCreate_newTerminal->setIconSize(QSize(20, 20));
        widget_welcome_body_widget2_newCreate_newTerminal->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout_10->addWidget(widget_welcome_body_widget2_newCreate_newTerminal);

        widget_welcome_body_widget2_newCreate_newTool = new QToolButton(widget_welcome_body_widget2_newCreate);
        widget_welcome_body_widget2_newCreate_newTool->setObjectName(QStringLiteral("widget_welcome_body_widget2_newCreate_newTool"));
        sizePolicy2.setHeightForWidth(widget_welcome_body_widget2_newCreate_newTool->sizePolicy().hasHeightForWidth());
        widget_welcome_body_widget2_newCreate_newTool->setSizePolicy(sizePolicy2);
        widget_welcome_body_widget2_newCreate_newTool->setMinimumSize(QSize(0, 30));
        widget_welcome_body_widget2_newCreate_newTool->setFont(font1);
        widget_welcome_body_widget2_newCreate_newTool->setLayoutDirection(Qt::LeftToRight);
        widget_welcome_body_widget2_newCreate_newTool->setStyleSheet(QLatin1String("QToolButton {\n"
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
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/lib/tool2.png"), QSize(), QIcon::Normal, QIcon::Off);
        widget_welcome_body_widget2_newCreate_newTool->setIcon(icon5);
        widget_welcome_body_widget2_newCreate_newTool->setIconSize(QSize(20, 20));
        widget_welcome_body_widget2_newCreate_newTool->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout_10->addWidget(widget_welcome_body_widget2_newCreate_newTool);

        widget_welcome_body_widget2_newCreate_setting = new QToolButton(widget_welcome_body_widget2_newCreate);
        widget_welcome_body_widget2_newCreate_setting->setObjectName(QStringLiteral("widget_welcome_body_widget2_newCreate_setting"));
        sizePolicy2.setHeightForWidth(widget_welcome_body_widget2_newCreate_setting->sizePolicy().hasHeightForWidth());
        widget_welcome_body_widget2_newCreate_setting->setSizePolicy(sizePolicy2);
        widget_welcome_body_widget2_newCreate_setting->setMinimumSize(QSize(0, 30));
        widget_welcome_body_widget2_newCreate_setting->setFont(font1);
        widget_welcome_body_widget2_newCreate_setting->setStyleSheet(QLatin1String("QToolButton {\n"
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
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/lib/setiing2.png"), QSize(), QIcon::Normal, QIcon::Off);
        widget_welcome_body_widget2_newCreate_setting->setIcon(icon6);
        widget_welcome_body_widget2_newCreate_setting->setIconSize(QSize(20, 20));
        widget_welcome_body_widget2_newCreate_setting->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout_10->addWidget(widget_welcome_body_widget2_newCreate_setting);


        verticalLayout_8->addWidget(widget_welcome_body_widget2_newCreate);

        widget_welcome_body_widget2_nearestConnectionInfo = new QWidget(widget_welcome_body_widget2);
        widget_welcome_body_widget2_nearestConnectionInfo->setObjectName(QStringLiteral("widget_welcome_body_widget2_nearestConnectionInfo"));
        widget_welcome_body_widget2_nearestConnectionInfo->setMinimumSize(QSize(250, 0));
        widget_welcome_body_widget2_nearestConnectionInfo->setMaximumSize(QSize(250, 16777215));
        widget_welcome_body_widget2_nearestConnectionInfo->setStyleSheet(QStringLiteral(""));
        verticalLayout_16 = new QVBoxLayout(widget_welcome_body_widget2_nearestConnectionInfo);
        verticalLayout_16->setSpacing(3);
        verticalLayout_16->setContentsMargins(11, 11, 11, 11);
        verticalLayout_16->setObjectName(QStringLiteral("verticalLayout_16"));
        verticalLayout_16->setContentsMargins(0, 0, 0, 0);
        widget_welcome_body_widget2_nearestConnectionInfo_nearest = new QToolButton(widget_welcome_body_widget2_nearestConnectionInfo);
        widget_welcome_body_widget2_nearestConnectionInfo_nearest->setObjectName(QStringLiteral("widget_welcome_body_widget2_nearestConnectionInfo_nearest"));
        sizePolicy2.setHeightForWidth(widget_welcome_body_widget2_nearestConnectionInfo_nearest->sizePolicy().hasHeightForWidth());
        widget_welcome_body_widget2_nearestConnectionInfo_nearest->setSizePolicy(sizePolicy2);
        widget_welcome_body_widget2_nearestConnectionInfo_nearest->setFont(font1);
        widget_welcome_body_widget2_nearestConnectionInfo_nearest->setLayoutDirection(Qt::LeftToRight);
        widget_welcome_body_widget2_nearestConnectionInfo_nearest->setStyleSheet(QLatin1String("QToolButton {\n"
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
        widget_welcome_body_widget2_nearestConnectionInfo_nearest->setIconSize(QSize(20, 20));
        widget_welcome_body_widget2_nearestConnectionInfo_nearest->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout_16->addWidget(widget_welcome_body_widget2_nearestConnectionInfo_nearest);

        widget_welcome_body_widget2_nearestConnectionInfo_list = new QWidget(widget_welcome_body_widget2_nearestConnectionInfo);
        widget_welcome_body_widget2_nearestConnectionInfo_list->setObjectName(QStringLiteral("widget_welcome_body_widget2_nearestConnectionInfo_list"));
        widget_welcome_body_widget2_nearestConnectionInfo_list->setStyleSheet(QLatin1String("background-color: rgba(217, 236, 237, 10);\n"
"border-radius: 10px;\n"
"color: rgb(217, 236, 237);"));
        verticalLayout_17 = new QVBoxLayout(widget_welcome_body_widget2_nearestConnectionInfo_list);
        verticalLayout_17->setSpacing(6);
        verticalLayout_17->setContentsMargins(11, 11, 11, 11);
        verticalLayout_17->setObjectName(QStringLiteral("verticalLayout_17"));
        toolButton_20 = new QToolButton(widget_welcome_body_widget2_nearestConnectionInfo_list);
        toolButton_20->setObjectName(QStringLiteral("toolButton_20"));
        sizePolicy2.setHeightForWidth(toolButton_20->sizePolicy().hasHeightForWidth());
        toolButton_20->setSizePolicy(sizePolicy2);
        toolButton_20->setFont(font1);
        toolButton_20->setLayoutDirection(Qt::LeftToRight);
        toolButton_20->setStyleSheet(QLatin1String("QToolButton {\n"
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
        toolButton_20->setIconSize(QSize(20, 20));
        toolButton_20->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout_17->addWidget(toolButton_20);

        toolButton_21 = new QToolButton(widget_welcome_body_widget2_nearestConnectionInfo_list);
        toolButton_21->setObjectName(QStringLiteral("toolButton_21"));
        sizePolicy2.setHeightForWidth(toolButton_21->sizePolicy().hasHeightForWidth());
        toolButton_21->setSizePolicy(sizePolicy2);
        toolButton_21->setFont(font1);
        toolButton_21->setLayoutDirection(Qt::LeftToRight);
        toolButton_21->setStyleSheet(QLatin1String("QToolButton {\n"
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
        toolButton_21->setIconSize(QSize(20, 20));
        toolButton_21->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout_17->addWidget(toolButton_21);

        toolButton_25 = new QToolButton(widget_welcome_body_widget2_nearestConnectionInfo_list);
        toolButton_25->setObjectName(QStringLiteral("toolButton_25"));
        sizePolicy2.setHeightForWidth(toolButton_25->sizePolicy().hasHeightForWidth());
        toolButton_25->setSizePolicy(sizePolicy2);
        toolButton_25->setFont(font1);
        toolButton_25->setLayoutDirection(Qt::LeftToRight);
        toolButton_25->setStyleSheet(QLatin1String("QToolButton {\n"
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
        toolButton_25->setIconSize(QSize(20, 20));
        toolButton_25->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout_17->addWidget(toolButton_25);


        verticalLayout_16->addWidget(widget_welcome_body_widget2_nearestConnectionInfo_list);

        widget_welcome_body_widget2_nearestConnectionInfo_more = new QToolButton(widget_welcome_body_widget2_nearestConnectionInfo);
        widget_welcome_body_widget2_nearestConnectionInfo_more->setObjectName(QStringLiteral("widget_welcome_body_widget2_nearestConnectionInfo_more"));
        sizePolicy2.setHeightForWidth(widget_welcome_body_widget2_nearestConnectionInfo_more->sizePolicy().hasHeightForWidth());
        widget_welcome_body_widget2_nearestConnectionInfo_more->setSizePolicy(sizePolicy2);
        widget_welcome_body_widget2_nearestConnectionInfo_more->setFont(font1);
        widget_welcome_body_widget2_nearestConnectionInfo_more->setLayoutDirection(Qt::LeftToRight);
        widget_welcome_body_widget2_nearestConnectionInfo_more->setStyleSheet(QLatin1String("QToolButton {\n"
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
        widget_welcome_body_widget2_nearestConnectionInfo_more->setIconSize(QSize(20, 20));
        widget_welcome_body_widget2_nearestConnectionInfo_more->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout_16->addWidget(widget_welcome_body_widget2_nearestConnectionInfo_more);


        verticalLayout_8->addWidget(widget_welcome_body_widget2_nearestConnectionInfo);

        widget_welcome_body_widget2_verticalSpacer_bottom = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(widget_welcome_body_widget2_verticalSpacer_bottom);


        horizontalLayout_4->addWidget(widget_welcome_body_widget2);


        horizontalLayout_5->addWidget(widget_welcome_body_widget);

        widget_welcome_body_horizontalSpacer_right = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(widget_welcome_body_horizontalSpacer_right);


        verticalLayout_9->addWidget(widget_welcome_body);

        widget_welcome_bottom = new QWidget(widget_11);
        widget_welcome_bottom->setObjectName(QStringLiteral("widget_welcome_bottom"));
        widget_welcome_bottom->setMinimumSize(QSize(0, 20));
        widget_welcome_bottom->setMaximumSize(QSize(16777215, 20));
        horizontalLayout_6 = new QHBoxLayout(widget_welcome_bottom);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        widget_welcome_bottom_toolButton_github = new QToolButton(widget_welcome_bottom);
        widget_welcome_bottom_toolButton_github->setObjectName(QStringLiteral("widget_welcome_bottom_toolButton_github"));
        sizePolicy2.setHeightForWidth(widget_welcome_bottom_toolButton_github->sizePolicy().hasHeightForWidth());
        widget_welcome_bottom_toolButton_github->setSizePolicy(sizePolicy2);
        widget_welcome_bottom_toolButton_github->setFont(font1);
        widget_welcome_bottom_toolButton_github->setLayoutDirection(Qt::LeftToRight);
        widget_welcome_bottom_toolButton_github->setStyleSheet(QLatin1String("QToolButton {\n"
"	color: rgb(242, 245, 255);\n"
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
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/lib/github.png"), QSize(), QIcon::Normal, QIcon::Off);
        widget_welcome_bottom_toolButton_github->setIcon(icon7);
        widget_welcome_bottom_toolButton_github->setIconSize(QSize(20, 20));
        widget_welcome_bottom_toolButton_github->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_6->addWidget(widget_welcome_bottom_toolButton_github);

        widget_welcome_bottom_horizontalSpacer_left = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(widget_welcome_bottom_horizontalSpacer_left);

        widget_welcome_bottom_showWelcome = new QCheckBox(widget_welcome_bottom);
        widget_welcome_bottom_showWelcome->setObjectName(QStringLiteral("widget_welcome_bottom_showWelcome"));
        widget_welcome_bottom_showWelcome->setFont(font1);
        widget_welcome_bottom_showWelcome->setChecked(true);

        horizontalLayout_6->addWidget(widget_welcome_bottom_showWelcome);

        widget_welcome_page_bottom_horizontalSpacer_right = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(widget_welcome_page_bottom_horizontalSpacer_right);

        widget_welcome_page_bottom_label_version = new QLabel(widget_welcome_bottom);
        widget_welcome_page_bottom_label_version->setObjectName(QStringLiteral("widget_welcome_page_bottom_label_version"));
        widget_welcome_page_bottom_label_version->setFont(font1);
        widget_welcome_page_bottom_label_version->setStyleSheet(QLatin1String("color: qlineargradient(spread:pad, x1:0.789318, y1:0.358, x2:1, y2:1, stop:0 rgba(0, 213, 205, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgb(242, 245, 255);"));
        widget_welcome_page_bottom_label_version->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(widget_welcome_page_bottom_label_version);


        verticalLayout_9->addWidget(widget_welcome_bottom);


        verticalLayout_13->addWidget(widget_11);


        verticalLayout_7->addWidget(widget_2);

        stackedWidget->addWidget(page_3);

        verticalLayout_2->addWidget(stackedWidget);


        verticalLayout->addWidget(widget_body);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(2);
        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Fdog-Kit", nullptr));
        label_icon->setText(QString());
        label_title->setText(QApplication::translate("MainWindow", "Fdog-Kit", nullptr));
        toolButton_min->setText(QString());
        toolButton_max->setText(QString());
        toolButton_close->setText(QString());
        toolButton_newCreate->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272(&N)", nullptr));
        toolButton_tool->setText(QApplication::translate("MainWindow", "\345\267\245\345\205\267(&T)", nullptr));
        toolButton_setting->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256(&S)", nullptr));
        toolButton_about->setText(QApplication::translate("MainWindow", "\345\270\256\345\212\251(&H)", nullptr));
        widget_welcome_body_widget2_info_widget_icon->setText(QString());
        widget_welcome_body_widget2_info_text->setText(QApplication::translate("MainWindow", "Fdog-kit", nullptr));
        widget_welcome_body_widget2_newCreate_newTerminal->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\347\273\210\347\253\257", nullptr));
        widget_welcome_body_widget2_newCreate_newTool->setText(QApplication::translate("MainWindow", "\345\267\245\345\205\267", nullptr));
        widget_welcome_body_widget2_newCreate_setting->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256", nullptr));
        widget_welcome_body_widget2_nearestConnectionInfo_nearest->setText(QApplication::translate("MainWindow", "\346\234\200\350\277\221\350\277\236\346\216\245\357\274\232", nullptr));
        toolButton_20->setText(QApplication::translate("MainWindow", "172.16.8.156", nullptr));
        toolButton_21->setText(QApplication::translate("MainWindow", "172.16.8.156", nullptr));
        toolButton_25->setText(QApplication::translate("MainWindow", "172.16.8.156", nullptr));
        widget_welcome_body_widget2_nearestConnectionInfo_more->setText(QApplication::translate("MainWindow", "\346\233\264\345\244\232", nullptr));
        widget_welcome_bottom_toolButton_github->setText(QApplication::translate("MainWindow", "GitHub", nullptr));
        widget_welcome_bottom_showWelcome->setText(QApplication::translate("MainWindow", "\345\220\257\345\212\250\346\227\266\346\230\276\347\244\272\346\254\242\350\277\216\351\241\265", nullptr));
        widget_welcome_page_bottom_label_version->setText(QApplication::translate("MainWindow", "Version\357\274\2321.0.0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
