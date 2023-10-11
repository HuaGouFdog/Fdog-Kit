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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
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
    QWidget *widget_9;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_4;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_4;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_8;
    QSpacerItem *verticalSpacer_2;
    QWidget *widget_6;
    QVBoxLayout *verticalLayout_11;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_12;
    QLabel *label_15;
    QWidget *widget_5;
    QVBoxLayout *verticalLayout_10;
    QToolButton *toolButton;
    QToolButton *toolButton_4;
    QToolButton *toolButton_2;
    QSpacerItem *verticalSpacer;
    QWidget *widget_8;
    QVBoxLayout *verticalLayout_12;
    QWidget *widget_12;
    QToolButton *toolButton_3;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_3;
    QWidget *widget_10;
    QHBoxLayout *horizontalLayout_6;
    QToolButton *toolButton_5;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_16;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(836, 540);
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
        toolButton_min->setMinimumSize(QSize(0, 0));
        toolButton_min->setMaximumSize(QSize(16777215, 16777215));
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
        icon1.addFile(QStringLiteral(":/lib/icon-minus.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_min->setIcon(icon1);
        toolButton_min->setIconSize(QSize(16, 16));

        horizontalLayout->addWidget(toolButton_min);

        toolButton_max = new QToolButton(widget_title);
        toolButton_max->setObjectName(QStringLiteral("toolButton_max"));
        toolButton_max->setMinimumSize(QSize(0, 0));
        toolButton_max->setMaximumSize(QSize(16777215, 16777215));
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
        icon2.addFile(QStringLiteral(":/lib/Icon_max2.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon2.addFile(QStringLiteral(":/lib/icon-copy.png"), QSize(), QIcon::Active, QIcon::Off);
        toolButton_max->setIcon(icon2);
        toolButton_max->setIconSize(QSize(15, 15));
        toolButton_max->setCheckable(false);

        horizontalLayout->addWidget(toolButton_max);

        toolButton_close = new QToolButton(widget_title);
        toolButton_close->setObjectName(QStringLiteral("toolButton_close"));
        toolButton_close->setMinimumSize(QSize(0, 0));
        toolButton_close->setMaximumSize(QSize(16777215, 16777215));
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
        icon3.addFile(QStringLiteral(":/lib/icon-close.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_close->setIcon(icon3);
        toolButton_close->setIconSize(QSize(17, 17));
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
        verticalLayout_7 = new QVBoxLayout(page_3);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(page_3);
        widget_2->setObjectName(QStringLiteral("widget_2"));
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
        widget_9 = new QWidget(widget_11);
        widget_9->setObjectName(QStringLiteral("widget_9"));
        horizontalLayout_5 = new QHBoxLayout(widget_9);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

        widget_4 = new QWidget(widget_9);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        horizontalLayout_4 = new QHBoxLayout(widget_4);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        widget_3 = new QWidget(widget_4);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        verticalLayout_8 = new QVBoxLayout(widget_3);
        verticalLayout_8->setSpacing(30);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalSpacer_2 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer_2);

        widget_6 = new QWidget(widget_3);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        widget_6->setMinimumSize(QSize(0, 130));
        widget_6->setMaximumSize(QSize(16777215, 130));
        verticalLayout_11 = new QVBoxLayout(widget_6);
        verticalLayout_11->setSpacing(0);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        widget_7 = new QWidget(widget_6);
        widget_7->setObjectName(QStringLiteral("widget_7"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(48);
        sizePolicy1.setVerticalStretch(48);
        sizePolicy1.setHeightForWidth(widget_7->sizePolicy().hasHeightForWidth());
        widget_7->setSizePolicy(sizePolicy1);
        widget_7->setMinimumSize(QSize(64, 64));
        widget_7->setMaximumSize(QSize(16777215, 64));
        horizontalLayout_3 = new QHBoxLayout(widget_7);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_12 = new QLabel(widget_7);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setMinimumSize(QSize(64, 64));
        label_12->setMaximumSize(QSize(64, 64));
        QFont font4;
        font4.setFamily(QStringLiteral("OPPOSans B"));
        font4.setPointSize(20);
        font4.setStyleStrategy(QFont::PreferAntialias);
        label_12->setFont(font4);
        label_12->setStyleSheet(QStringLiteral("border-image: url(:/lib/wicon_64.png);"));

        horizontalLayout_3->addWidget(label_12);


        verticalLayout_11->addWidget(widget_7);

        label_15 = new QLabel(widget_6);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setMinimumSize(QSize(0, 45));
        label_15->setMaximumSize(QSize(16777215, 45));
        QFont font5;
        font5.setFamily(QStringLiteral("OPPOSans B"));
        font5.setPointSize(20);
        font5.setBold(false);
        font5.setItalic(false);
        font5.setWeight(50);
        font5.setStyleStrategy(QFont::PreferAntialias);
        label_15->setFont(font5);
        label_15->setStyleSheet(QLatin1String("color: qlineargradient(spread:pad, x1:0.789318, y1:0.358, x2:1, y2:1, stop:0 rgba(0, 213, 205, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgb(242, 245, 255);"));
        label_15->setAlignment(Qt::AlignCenter);

        verticalLayout_11->addWidget(label_15);


        verticalLayout_8->addWidget(widget_6);

        widget_5 = new QWidget(widget_3);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setMinimumSize(QSize(250, 120));
        widget_5->setMaximumSize(QSize(250, 120));
        widget_5->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 10);\n"
"border-radius: 10px;"));
        verticalLayout_10 = new QVBoxLayout(widget_5);
        verticalLayout_10->setSpacing(3);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(15, 10, 15, 10);
        toolButton = new QToolButton(widget_5);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(50);
        sizePolicy2.setVerticalStretch(50);
        sizePolicy2.setHeightForWidth(toolButton->sizePolicy().hasHeightForWidth());
        toolButton->setSizePolicy(sizePolicy2);
        toolButton->setMinimumSize(QSize(0, 30));
        toolButton->setFont(font1);
        toolButton->setLayoutDirection(Qt::LeftToRight);
        toolButton->setStyleSheet(QLatin1String("QToolButton {\n"
"	\n"
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
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/lib/add3.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon4);
        toolButton->setIconSize(QSize(20, 20));
        toolButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout_10->addWidget(toolButton);

        toolButton_4 = new QToolButton(widget_5);
        toolButton_4->setObjectName(QStringLiteral("toolButton_4"));
        sizePolicy2.setHeightForWidth(toolButton_4->sizePolicy().hasHeightForWidth());
        toolButton_4->setSizePolicy(sizePolicy2);
        toolButton_4->setMinimumSize(QSize(0, 30));
        toolButton_4->setFont(font1);
        toolButton_4->setLayoutDirection(Qt::LeftToRight);
        toolButton_4->setStyleSheet(QLatin1String("QToolButton {\n"
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
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/lib/tool2.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_4->setIcon(icon5);
        toolButton_4->setIconSize(QSize(20, 20));
        toolButton_4->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout_10->addWidget(toolButton_4);

        toolButton_2 = new QToolButton(widget_5);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        sizePolicy2.setHeightForWidth(toolButton_2->sizePolicy().hasHeightForWidth());
        toolButton_2->setSizePolicy(sizePolicy2);
        toolButton_2->setMinimumSize(QSize(0, 30));
        toolButton_2->setFont(font1);
        toolButton_2->setStyleSheet(QLatin1String("QToolButton {\n"
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
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/lib/setiing2.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon6);
        toolButton_2->setIconSize(QSize(20, 20));
        toolButton_2->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout_10->addWidget(toolButton_2);


        verticalLayout_8->addWidget(widget_5);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer);


        horizontalLayout_4->addWidget(widget_3);

        widget_8 = new QWidget(widget_4);
        widget_8->setObjectName(QStringLiteral("widget_8"));
        widget_8->setMinimumSize(QSize(200, 0));
        widget_8->setMaximumSize(QSize(200, 16777215));
        widget_8->setStyleSheet(QStringLiteral(""));
        verticalLayout_12 = new QVBoxLayout(widget_8);
        verticalLayout_12->setSpacing(10);
        verticalLayout_12->setContentsMargins(11, 11, 11, 11);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        verticalLayout_12->setContentsMargins(20, 20, 20, 20);
        widget_12 = new QWidget(widget_8);
        widget_12->setObjectName(QStringLiteral("widget_12"));
        widget_12->setStyleSheet(QLatin1String("background-color: rgba(132, 132, 132, 30);\n"
"border-radius: 10px;"));
        toolButton_3 = new QToolButton(widget_12);
        toolButton_3->setObjectName(QStringLiteral("toolButton_3"));
        toolButton_3->setGeometry(QRect(10, 70, 87, 23));
        sizePolicy2.setHeightForWidth(toolButton_3->sizePolicy().hasHeightForWidth());
        toolButton_3->setSizePolicy(sizePolicy2);
        toolButton_3->setFont(font1);
        toolButton_3->setLayoutDirection(Qt::LeftToRight);
        toolButton_3->setStyleSheet(QLatin1String("QToolButton {\n"
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
        toolButton_3->setIcon(icon4);
        toolButton_3->setIconSize(QSize(20, 20));
        toolButton_3->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        pushButton = new QPushButton(widget_12);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(40, 210, 75, 23));

        verticalLayout_12->addWidget(widget_12);


        horizontalLayout_4->addWidget(widget_8);


        horizontalLayout_5->addWidget(widget_4);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        verticalLayout_9->addWidget(widget_9);

        widget_10 = new QWidget(widget_11);
        widget_10->setObjectName(QStringLiteral("widget_10"));
        widget_10->setMinimumSize(QSize(0, 20));
        widget_10->setMaximumSize(QSize(16777215, 20));
        horizontalLayout_6 = new QHBoxLayout(widget_10);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        toolButton_5 = new QToolButton(widget_10);
        toolButton_5->setObjectName(QStringLiteral("toolButton_5"));
        sizePolicy2.setHeightForWidth(toolButton_5->sizePolicy().hasHeightForWidth());
        toolButton_5->setSizePolicy(sizePolicy2);
        toolButton_5->setFont(font1);
        toolButton_5->setLayoutDirection(Qt::LeftToRight);
        toolButton_5->setStyleSheet(QLatin1String("QToolButton {\n"
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
        toolButton_5->setIcon(icon7);
        toolButton_5->setIconSize(QSize(20, 20));
        toolButton_5->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_6->addWidget(toolButton_5);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_5);

        label_16 = new QLabel(widget_10);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setFont(font1);
        label_16->setStyleSheet(QLatin1String("color: qlineargradient(spread:pad, x1:0.789318, y1:0.358, x2:1, y2:1, stop:0 rgba(0, 213, 205, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgb(242, 245, 255);"));
        label_16->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label_16);


        verticalLayout_9->addWidget(widget_10);


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
        label_12->setText(QString());
        label_15->setText(QApplication::translate("MainWindow", "Fdog-kit", nullptr));
        toolButton->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240\347\273\210\347\253\257", nullptr));
        toolButton_4->setText(QApplication::translate("MainWindow", "\345\267\245\345\205\267", nullptr));
        toolButton_2->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256", nullptr));
        toolButton_3->setText(QApplication::translate("MainWindow", "\345\216\206\345\217\262\350\277\236\346\216\245", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        toolButton_5->setText(QApplication::translate("MainWindow", "GitHub", nullptr));
        label_16->setText(QApplication::translate("MainWindow", "Version\357\274\2321.0.0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
