/********************************************************************************
** Form generated from reading UI file 'thriftwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THRIFTWIDGET_H
#define UI_THRIFTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_thriftwidget
{
public:
    QHBoxLayout *horizontalLayout_4;
    QWidget *widget_left;
    QVBoxLayout *verticalLayout_5;
    QWidget *widget_9;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *lineEdit_find;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_12;
    QToolButton *toolButton_inportFile;
    QListWidget *listWidget;
    QWidget *widget_right;
    QVBoxLayout *verticalLayout;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_14;
    QComboBox *comboBox_testType;
    QSpacerItem *horizontalSpacer_16;
    QLabel *label_2;
    QLineEdit *lineEdit_host;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label;
    QLineEdit *lineEdit_port;
    QSpacerItem *horizontalSpacer_4;
    QToolButton *toolButton_test;
    QSpacerItem *horizontalSpacer_2;
    QWidget *horizontalWidget_2;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_5;
    QComboBox *comboBox_transport;
    QSpacerItem *horizontalSpacer_10;
    QLabel *label_8;
    QComboBox *comboBox_protocol;
    QSpacerItem *horizontalSpacer_11;
    QLabel *label_9;
    QComboBox *comboBox_reqType;
    QSpacerItem *horizontalSpacer_9;
    QWidget *horizontalWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLineEdit *lineEdit_funcName;
    QSpacerItem *horizontalSpacer_8;
    QToolButton *toolButton_request;
    QSpacerItem *horizontalSpacer_27;
    QToolButton *toolButton_save;
    QSpacerItem *horizontalSpacer_22;
    QWidget *widget_property;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_15;
    QLineEdit *lineEdit_port_2;
    QSpacerItem *horizontalSpacer_17;
    QLabel *label_16;
    QLineEdit *lineEdit_port_3;
    QSpacerItem *horizontalSpacer_18;
    QLabel *label_17;
    QCheckBox *checkBox;
    QLineEdit *lineEdit_port_4;
    QSpacerItem *horizontalSpacer_19;
    QLabel *label_18;
    QLineEdit *lineEdit_port_5;
    QSpacerItem *horizontalSpacer_21;
    QToolButton *toolButton_5;
    QSpacerItem *horizontalSpacer_26;
    QToolButton *toolButton_save_2;
    QSpacerItem *horizontalSpacer_28;
    QToolButton *toolButton_switch;
    QSpacerItem *horizontalSpacer_25;
    QSpacerItem *horizontalSpacer_20;
    QStackedWidget *stackedWidget_2;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_11;
    QSplitter *splitter_2;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_3;
    QSplitter *splitter;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_12;
    QHBoxLayout *horizontalLayout_8;
    QToolButton *toolButton_request_param;
    QCheckBox *checkBox_3;
    QSpacerItem *horizontalSpacer;
    QTreeWidget *treeWidget;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_6;
    QWidget *widget_5;
    QVBoxLayout *verticalLayout_7;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_5;
    QToolButton *toolButton_response;
    QCheckBox *checkBox_show_source;
    QToolButton *toolButton_show_thrift_info;
    QSpacerItem *horizontalSpacer_5;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_4;
    QTabWidget *tabWidget_response;
    QWidget *tab_source;
    QHBoxLayout *horizontalLayout_12;
    QTextEdit *textEdit_info;
    QTextEdit *textEdit;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_headers;
    QTextEdit *textEdit_data;
    QWidget *page_request;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer_15;
    QWidget *widget_13;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_12;
    QLabel *label_13;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_14;
    QWidget *page_error;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_12;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_10;
    QLabel *label_11;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_13;
    QWidget *widget_10;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_req;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_time;
    QSpacerItem *horizontalSpacer_6;
    QWidget *page_3;

    void setupUi(QWidget *thriftwidget)
    {
        if (thriftwidget->objectName().isEmpty())
            thriftwidget->setObjectName(QStringLiteral("thriftwidget"));
        thriftwidget->resize(1379, 701);
        QFont font;
        font.setFamily(QStringLiteral("OPPOSans B"));
        font.setPointSize(10);
        font.setStyleStrategy(QFont::PreferAntialias);
        thriftwidget->setFont(font);
        thriftwidget->setStyleSheet(QLatin1String("QToolTip {\n"
"color:#ced4da;\n"
"background-color: rgb(108, 117, 125, 65);\n"
"border-radius: 2px;\n"
"}\n"
"\n"
"QMenu {\n"
"\n"
"background-color:rgb(253,253,254);\n"
"/*padding:5px;*/\n"
"padding: 5px 0px 5px 0px;\n"
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
"    /*margin-left:"
                        " 10px;*/\n"
"    /*margin-right: 10px;*/\n"
"}"));
        horizontalLayout_4 = new QHBoxLayout(thriftwidget);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        widget_left = new QWidget(thriftwidget);
        widget_left->setObjectName(QStringLiteral("widget_left"));
        widget_left->setMinimumSize(QSize(250, 0));
        widget_left->setMaximumSize(QSize(250, 16777215));
        QFont font1;
        font1.setFamily(QStringLiteral("OPPOSans B"));
        widget_left->setFont(font1);
        widget_left->setStyleSheet(QString::fromUtf8("#widget_left{\n"
"border-right:2px solid rgba(108, 117, 125, 65); \n"
"}\n"
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
"QScrollBar::sub-line:v"
                        "ertical {\n"
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
        verticalLayout_5 = new QVBoxLayout(widget_left);
        verticalLayout_5->setSpacing(9);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(10, 5, 10, 0);
        widget_9 = new QWidget(widget_left);
        widget_9->setObjectName(QStringLiteral("widget_9"));
        verticalLayout_3 = new QVBoxLayout(widget_9);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 5, 0, 5);
        lineEdit_find = new QLineEdit(widget_9);
        lineEdit_find->setObjectName(QStringLiteral("lineEdit_find"));
        lineEdit_find->setMinimumSize(QSize(0, 30));
        lineEdit_find->setMaximumSize(QSize(16777215, 30));
        QFont font2;
        font2.setFamily(QStringLiteral("OPPOSans"));
        font2.setPointSize(10);
        font2.setStyleStrategy(QFont::PreferAntialias);
        lineEdit_find->setFont(font2);
        lineEdit_find->setStyleSheet(QLatin1String("QLineEdit{\n"
"color: rgb(231, 238, 244);\n"
"border-radius: 14px;\n"
"background-color: rgb(25, 25, 25, 155);\n"
"border: 0px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding-left:10px;\n"
"padding-right:10px;\n"
"}"));

        verticalLayout_3->addWidget(lineEdit_find);


        verticalLayout_5->addWidget(widget_9);

        tabWidget = new QTabWidget(widget_left);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setFont(font);
        tabWidget->setStyleSheet(QString::fromUtf8("\n"
" QTabWidget::tab-bar {\n"
"         left:0px;       \n"
"}\n"
"	\n"
"\n"
"/*\350\256\276\347\275\256TabWidget\344\270\255tab_1\347\232\204\346\240\267\345\274\217*/\n"
"#tab_1.QWidget{\n"
"	background-color: rgb(108, 117, 125, 0);\n"
"}\n"
" \n"
"/*\350\256\276\347\275\256TabWidget\344\270\255tab_2\347\232\204\346\240\267\345\274\217*/\n"
"#tab_2.QWidget{\n"
"	background-color: rgb(108, 117, 125, 0);\n"
"}\n"
" \n"
"/*\350\256\276\347\275\256TabWidget\344\270\255QTabBar\347\232\204\346\240\267\345\274\217*/\n"
"QTabBar::tab{\n"
"    background-color: rgb(108, 117, 125, 0);\n"
"	/*font-family:Consolas; */   /*\350\256\276\347\275\256tab\344\270\255\347\232\204\346\226\207\346\234\254\347\232\204\345\255\227\344\275\223*/\n"
"	font-size:10pt;\n"
"	color:#ced4da;    /*\350\256\276\347\275\256tab\344\270\255\347\232\204\346\226\207\346\234\254\347\232\204\351\242\234\350\211\262*/\n"
"	border-top-left-radius: 5px;    /*\350\256\276\347\275\256tab\347\232\204\350\276\271\346\241\206\347\232\204\345\234\206\350"
                        "\247\222\357\274\210\345\267\246\344\270\212\345\234\206\350\247\222\357\274\211*/\n"
"	border-top-right-radius: 5px;    /*\350\256\276\347\275\256tab\347\232\204\350\276\271\346\241\206\347\232\204\345\234\206\350\247\222\357\274\210\345\217\263\344\270\212\345\234\206\350\247\222\357\274\211*/\n"
"	width:105px;\n"
"	padding: 4px;\n"
"	margin-right:0px;\n"
"	margin-left: 0px;\n"
"}\n"
" \n"
"/*\350\256\276\347\275\256TabWidget\344\270\255QTabBar\347\232\204tab\350\242\253\351\200\211\344\270\255\346\227\266\347\232\204\346\240\267\345\274\217*/\n"
"QTabBar::tab:selected{\n"
"	/*background-color: #0B0E11;*/\n"
"	background-color: rgb(108, 117, 125, 0);\n"
"	border-bottom: 2px solid rgb(54, 81, 97)\n"
"}\n"
" \n"
"/*\350\256\276\347\275\256TabWidget\344\270\255\351\274\240\346\240\207\346\202\254\346\265\256\345\234\250QTabBar\347\232\204tab\344\270\212\357\274\214\344\275\206\346\234\252\351\200\211\344\270\255\350\257\245Tab\347\232\204\346\240\267\345\274\217*/\n"
"QTabBar::tab:hover:!selected {\n"
"	/*backg"
                        "round-color: rgb(100, 117, 125, 125);*/\n"
"}\n"
" \n"
"/*\350\256\276\347\275\256TabWidget\347\232\204\350\276\271\346\241\206\347\232\204\346\240\267\345\274\217*/\n"
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
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/lib/history2.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab, icon, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_12 = new QVBoxLayout(tab_2);
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        verticalLayout_12->setContentsMargins(0, 6, 0, 9);
        toolButton_inportFile = new QToolButton(tab_2);
        toolButton_inportFile->setObjectName(QStringLiteral("toolButton_inportFile"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolButton_inportFile->sizePolicy().hasHeightForWidth());
        toolButton_inportFile->setSizePolicy(sizePolicy);
        toolButton_inportFile->setMinimumSize(QSize(180, 28));
        toolButton_inportFile->setMaximumSize(QSize(16777215, 28));
        toolButton_inportFile->setFont(font);
        toolButton_inportFile->setStyleSheet(QLatin1String("QToolButton {\n"
"	color: rgb(255, 255, 255);\n"
"	padding-left:26px;\n"
"	\n"
"	background-color: rgb(20, 20, 20);\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QToolButton::menu-indicator { \n"
"	image: None;\n"
"}\n"
" \n"
"QToolButton:hover {\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(20, 20, 20);\n"
"}"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/lib/inport.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_inportFile->setIcon(icon1);
        toolButton_inportFile->setIconSize(QSize(13, 13));
        toolButton_inportFile->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout_12->addWidget(toolButton_inportFile);

        listWidget = new QListWidget(tab_2);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setFont(font);
        listWidget->setStyleSheet(QString::fromUtf8("QListWidget{\n"
"border: 1px solid rgba(212, 212, 212, 80);\n"
"border-radius: 2px;\n"
"padding:5px;\n"
"}\n"
"\n"
"QListWidget::item {\n"
"    height: 25px; /* \350\256\276\347\275\256\350\241\214\351\253\230\344\270\27250\345\203\217\347\264\240 */\n"
"}"));

        verticalLayout_12->addWidget(listWidget);

        QIcon icon2;
        icon2.addFile(QStringLiteral(":/lib/file2.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab_2, icon2, QString());

        verticalLayout_5->addWidget(tabWidget);


        horizontalLayout_4->addWidget(widget_left);

        widget_right = new QWidget(thriftwidget);
        widget_right->setObjectName(QStringLiteral("widget_right"));
        widget_right->setStyleSheet(QString::fromUtf8("\n"
"QComboBox{\n"
"	color:#ffffff;\n"
"	border:1px solid #1e2d36;\n"
"	border-radius:3px;\n"
"	background:transparent;\n"
"}\n"
"QComboBox:disabled{\n"
"	border:1px solid gray;\n"
"	color:gray;\n"
"}\n"
"\n"
"QComboBox::drop-down{\n"
"	background:transparent;\n"
"}\n"
"QComboBox::down-arrow{\n"
"	border-image: url(:/lib/up.png);\n"
"    width:20px;\n"
"	height:20px;\n"
"}\n"
"\n"
"\n"
"QComboBox::down-arrow:enabled{\n"
"	color:#52DCFE;\n"
"}\n"
"QComboBox QAbstractItemView{\n"
"	outline:0px solid gray;\n"
"	border:1px solid #1e2d36;\n"
"	color:#ffffff;\n"
"	background-color:#1e2d36;\n"
"	selection-background-color:#52DCFE;\n"
"}\n"
"\n"
"QScrollBar:vertical{\n"
"    width: 12px;\n"
"	background-color: rgba(0, 41, 69, 0);\n"
"    margin: 0px,0px,0px,0px;\n"
"    padding-top: 0px;		/*//\351\232\220\350\227\217\344\270\212\344\270\213\347\232\204\347\256\255\345\244\264*/\n"
"    padding-bottom: 0px;\n"
"}\n"
"\n"
"\n"
"QScrollBar::handle:vertical{\n"
"    width: 12px;\n"
"	\n"
"	background-color: rgb(239, 239, "
                        "239);\n"
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
"\n"
"QScrollBar::up-arrow:vertical {\n"
"    border:none;\n"
"}"));
        verticalLayout = new QVBoxLayout(widget_right);
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 7, 0, 0);
        widget_6 = new QWidget(widget_right);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        widget_6->setMaximumSize(QSize(16777215, 33));
        widget_6->setStyleSheet(QLatin1String("\n"
"\n"
"QComboBox{\n"
"	color:#ffffff;\n"
"	border:0px solid #8a8a8a;\n"
"	color: rgb(138, 138, 138);\n"
"	border-radius:5px;\n"
"	background-color: rgb(25, 25, 25, 155);\n"
"	padding-left:10px;\n"
"	\n"
"	font: 10pt \"OPPOSans B\";\n"
"}\n"
"\n"
"QComboBox QAbstractItemView::item\n"
"{\n"
"	height:28px;\n"
"	font: 10pt \"OPPOSans B\";\n"
"}\n"
"\n"
"QComboBox:disabled{\n"
"	border:1px solid gray;\n"
"	color:gray;\n"
"}\n"
"\n"
"QComboBox::drop-down{\n"
"	background:transparent;\n"
"}\n"
"QComboBox::down-arrow{\n"
"	image: url(:/lib/tree_open.png);\n"
"    width:20px;\n"
"	height:20px;\n"
"	margin-right: 10px;\n"
"}\n"
"\n"
"\n"
"QComboBox::down-arrow:enabled{\n"
"	color:#52DCFE;\n"
"}\n"
"QComboBox QAbstractItemView{\n"
"	font: 10pt \"OPPOSans B\";\n"
"	outline:0px solid gray;\n"
"	border:1px solid #1e2d36;\n"
"	color:#ffffff;\n"
"	background-color:#1e2d36;\n"
"	selection-background-color:#52DCFE;\n"
"}\n"
"\n"
""));
        horizontalLayout_2 = new QHBoxLayout(widget_6);
        horizontalLayout_2->setSpacing(5);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(9, 3, 0, 0);
        label_14 = new QLabel(widget_6);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setMinimumSize(QSize(55, 0));
        label_14->setMaximumSize(QSize(55, 16777215));
        label_14->setFont(font);
        label_14->setStyleSheet(QStringLiteral("color:#ced4da;"));

        horizontalLayout_2->addWidget(label_14);

        comboBox_testType = new QComboBox(widget_6);
        comboBox_testType->addItem(QString());
        comboBox_testType->addItem(QString());
        comboBox_testType->setObjectName(QStringLiteral("comboBox_testType"));
        comboBox_testType->setMinimumSize(QSize(100, 30));
        comboBox_testType->setFont(font);
        comboBox_testType->setStyleSheet(QStringLiteral("color:#ced4da;"));

        horizontalLayout_2->addWidget(comboBox_testType);

        horizontalSpacer_16 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_16);

        label_2 = new QLabel(widget_6);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(40, 0));
        label_2->setMaximumSize(QSize(40, 16777215));
        label_2->setFont(font);
        label_2->setStyleSheet(QStringLiteral("color:#ced4da;"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_host = new QLineEdit(widget_6);
        lineEdit_host->setObjectName(QStringLiteral("lineEdit_host"));
        lineEdit_host->setMinimumSize(QSize(0, 30));
        lineEdit_host->setMaximumSize(QSize(500, 16777215));
        lineEdit_host->setFont(font);
        lineEdit_host->setStyleSheet(QLatin1String("QLineEdit{\n"
"color:#ced4da;\n"
"border-radius: 14px;\n"
"background-color: rgb(25, 25, 25, 155);\n"
"border: 0px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding-left:10px;\n"
"padding-right:10px;\n"
"}"));

        horizontalLayout_2->addWidget(lineEdit_host);

        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        label = new QLabel(widget_6);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(40, 16777215));
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("color:#ced4da;"));

        horizontalLayout_2->addWidget(label);

        lineEdit_port = new QLineEdit(widget_6);
        lineEdit_port->setObjectName(QStringLiteral("lineEdit_port"));
        lineEdit_port->setMinimumSize(QSize(0, 30));
        lineEdit_port->setMaximumSize(QSize(100, 16777215));
        lineEdit_port->setFont(font);
        lineEdit_port->setStyleSheet(QLatin1String("QLineEdit{\n"
"color:#ced4da;\n"
"border-radius: 14px;\n"
"background-color: rgb(25, 25, 25, 155);\n"
"border: 0px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding-left:10px;\n"
"padding-right:10px;\n"
"}"));

        horizontalLayout_2->addWidget(lineEdit_port);

        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        toolButton_test = new QToolButton(widget_6);
        toolButton_test->setObjectName(QStringLiteral("toolButton_test"));
        toolButton_test->setMinimumSize(QSize(68, 30));
        QFont font3;
        font3.setFamily(QStringLiteral("OPPOSans B"));
        font3.setPointSize(10);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(50);
        toolButton_test->setFont(font3);
        toolButton_test->setStyleSheet(QLatin1String("QToolButton {\n"
"	font: 10pt \"OPPOSans B\";\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(250, 118, 0);\n"
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
"	background-color: rgb(250, 118, 0);\n"
"}"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/lib/node2.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_test->setIcon(icon3);
        toolButton_test->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_2->addWidget(toolButton_test);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget_6);

        horizontalWidget_2 = new QWidget(widget_right);
        horizontalWidget_2->setObjectName(QStringLiteral("horizontalWidget_2"));
        horizontalWidget_2->setMaximumSize(QSize(16777215, 33));
        horizontalWidget_2->setStyleSheet(QLatin1String("QComboBox{\n"
"	color:#ffffff;\n"
"	border:0px solid #8a8a8a;\n"
"	color: rgb(138, 138, 138);\n"
"	border-radius:5px;\n"
"	background-color: rgb(25, 25, 25, 155);\n"
"	padding-left:10px;\n"
"	\n"
"	font: 10pt \"OPPOSans B\";\n"
"}\n"
"\n"
"QComboBox QAbstractItemView::item\n"
"{\n"
"	height:28px;\n"
"	font: 10pt \"OPPOSans B\";\n"
"}\n"
"\n"
"QComboBox:disabled{\n"
"	border:1px solid gray;\n"
"	color:gray;\n"
"}\n"
"\n"
"QComboBox::drop-down{\n"
"	background:transparent;\n"
"}\n"
"QComboBox::down-arrow{\n"
"	image: url(:/lib/tree_open.png);\n"
"    width:20px;\n"
"	height:20px;\n"
"	margin-right: 10px;\n"
"}\n"
"\n"
"\n"
"QComboBox::down-arrow:enabled{\n"
"	color:#52DCFE;\n"
"}\n"
"QComboBox QAbstractItemView{\n"
"	font: 10pt \"OPPOSans B\";\n"
"	outline:0px solid gray;\n"
"	border:1px solid #1e2d36;\n"
"	color:#ffffff;\n"
"	background-color:#1e2d36;\n"
"	selection-background-color:#52DCFE;\n"
"}\n"
"\n"
""));
        horizontalLayout_9 = new QHBoxLayout(horizontalWidget_2);
        horizontalLayout_9->setSpacing(5);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(9, 0, 0, 0);
        label_5 = new QLabel(horizontalWidget_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(55, 0));
        label_5->setMaximumSize(QSize(55, 16777215));
        label_5->setFont(font);
        label_5->setStyleSheet(QStringLiteral("color:#ced4da;"));

        horizontalLayout_9->addWidget(label_5);

        comboBox_transport = new QComboBox(horizontalWidget_2);
        comboBox_transport->addItem(QString());
        comboBox_transport->addItem(QString());
        comboBox_transport->setObjectName(QStringLiteral("comboBox_transport"));
        comboBox_transport->setMinimumSize(QSize(170, 30));
        comboBox_transport->setFont(font);
        comboBox_transport->setStyleSheet(QStringLiteral("color:#ced4da;"));

        horizontalLayout_9->addWidget(comboBox_transport);

        horizontalSpacer_10 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_10);

        label_8 = new QLabel(horizontalWidget_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setMaximumSize(QSize(40, 16777215));
        label_8->setFont(font);
        label_8->setStyleSheet(QStringLiteral("color:#ced4da;"));

        horizontalLayout_9->addWidget(label_8);

        comboBox_protocol = new QComboBox(horizontalWidget_2);
        comboBox_protocol->addItem(QString());
        comboBox_protocol->setObjectName(QStringLiteral("comboBox_protocol"));
        comboBox_protocol->setMinimumSize(QSize(160, 30));
        comboBox_protocol->setFont(font);
        comboBox_protocol->setStyleSheet(QStringLiteral("color:#ced4da;"));

        horizontalLayout_9->addWidget(comboBox_protocol);

        horizontalSpacer_11 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_11);

        label_9 = new QLabel(horizontalWidget_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setMaximumSize(QSize(555555, 16777215));
        label_9->setFont(font);
        label_9->setStyleSheet(QStringLiteral("color:#ced4da;"));

        horizontalLayout_9->addWidget(label_9);

        comboBox_reqType = new QComboBox(horizontalWidget_2);
        comboBox_reqType->addItem(QString());
        comboBox_reqType->addItem(QString());
        comboBox_reqType->setObjectName(QStringLiteral("comboBox_reqType"));
        comboBox_reqType->setMinimumSize(QSize(110, 30));
        comboBox_reqType->setFont(font);
        comboBox_reqType->setStyleSheet(QStringLiteral("color:#ced4da;"));

        horizontalLayout_9->addWidget(comboBox_reqType);

        horizontalSpacer_9 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_9);


        verticalLayout->addWidget(horizontalWidget_2);

        horizontalWidget = new QWidget(widget_right);
        horizontalWidget->setObjectName(QStringLiteral("horizontalWidget"));
        horizontalWidget->setMaximumSize(QSize(16777215, 30));
        horizontalWidget->setStyleSheet(QStringLiteral("color:#ced4da;"));
        horizontalLayout = new QHBoxLayout(horizontalWidget);
        horizontalLayout->setSpacing(5);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(9, 0, 10, 0);
        label_3 = new QLabel(horizontalWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(55, 0));
        label_3->setMaximumSize(QSize(55, 16777215));
        label_3->setFont(font);

        horizontalLayout->addWidget(label_3);

        lineEdit_funcName = new QLineEdit(horizontalWidget);
        lineEdit_funcName->setObjectName(QStringLiteral("lineEdit_funcName"));
        lineEdit_funcName->setMinimumSize(QSize(400, 30));
        lineEdit_funcName->setMaximumSize(QSize(1111111, 16777215));
        lineEdit_funcName->setFont(font);
        lineEdit_funcName->setStyleSheet(QLatin1String("QLineEdit{\n"
"color:#ced4da;\n"
"border-radius: 14px;\n"
"background-color: rgb(25, 25, 25, 155);\n"
"border: 0px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding-left:10px;\n"
"padding-right:10px;\n"
"}"));

        horizontalLayout->addWidget(lineEdit_funcName);

        horizontalSpacer_8 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        toolButton_request = new QToolButton(horizontalWidget);
        toolButton_request->setObjectName(QStringLiteral("toolButton_request"));
        toolButton_request->setMinimumSize(QSize(90, 30));
        toolButton_request->setFont(font2);
        toolButton_request->setStyleSheet(QLatin1String("QToolButton {\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(250, 118, 0);\n"
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
"	background-color: rgb(250, 118, 0);\n"
"}"));

        horizontalLayout->addWidget(toolButton_request);

        horizontalSpacer_27 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_27);

        toolButton_save = new QToolButton(horizontalWidget);
        toolButton_save->setObjectName(QStringLiteral("toolButton_save"));
        toolButton_save->setMinimumSize(QSize(90, 30));
        toolButton_save->setFont(font2);
        toolButton_save->setStyleSheet(QLatin1String("QToolButton {\n"
"	color: rgb(255, 255, 255);\n"
"	\n"
"	background-color: rgb(0, 170, 0);\n"
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
"	background-color: rgb(0, 170, 0);\n"
"}"));

        horizontalLayout->addWidget(toolButton_save);

        horizontalSpacer_22 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_22);


        verticalLayout->addWidget(horizontalWidget);

        widget_property = new QWidget(widget_right);
        widget_property->setObjectName(QStringLiteral("widget_property"));
        widget_property->setMinimumSize(QSize(0, 30));
        horizontalLayout_13 = new QHBoxLayout(widget_property);
        horizontalLayout_13->setSpacing(5);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(9, 0, 0, 0);
        label_15 = new QLabel(widget_property);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setMinimumSize(QSize(55, 0));
        label_15->setMaximumSize(QSize(55, 16777215));
        label_15->setFont(font);
        label_15->setStyleSheet(QStringLiteral("color:#ced4da;"));

        horizontalLayout_13->addWidget(label_15);

        lineEdit_port_2 = new QLineEdit(widget_property);
        lineEdit_port_2->setObjectName(QStringLiteral("lineEdit_port_2"));
        lineEdit_port_2->setMinimumSize(QSize(70, 30));
        lineEdit_port_2->setMaximumSize(QSize(70, 16777215));
        lineEdit_port_2->setFont(font);
        lineEdit_port_2->setStyleSheet(QLatin1String("QLineEdit{\n"
"color:#ced4da;\n"
"border-radius: 14px;\n"
"background-color: rgb(25, 25, 25, 155);\n"
"border: 0px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding-left:10px;\n"
"padding-right:10px;\n"
"}"));

        horizontalLayout_13->addWidget(lineEdit_port_2);

        horizontalSpacer_17 = new QSpacerItem(17, 27, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_17);

        label_16 = new QLabel(widget_property);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setMinimumSize(QSize(55, 0));
        label_16->setMaximumSize(QSize(55, 16777215));
        label_16->setFont(font);
        label_16->setStyleSheet(QStringLiteral("color:#ced4da;"));

        horizontalLayout_13->addWidget(label_16);

        lineEdit_port_3 = new QLineEdit(widget_property);
        lineEdit_port_3->setObjectName(QStringLiteral("lineEdit_port_3"));
        lineEdit_port_3->setMinimumSize(QSize(70, 30));
        lineEdit_port_3->setMaximumSize(QSize(70, 16777215));
        lineEdit_port_3->setFont(font);
        lineEdit_port_3->setStyleSheet(QLatin1String("QLineEdit{\n"
"color:#ced4da;\n"
"border-radius: 14px;\n"
"background-color: rgb(25, 25, 25, 155);\n"
"border: 0px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding-left:10px;\n"
"padding-right:10px;\n"
"}"));

        horizontalLayout_13->addWidget(lineEdit_port_3);

        horizontalSpacer_18 = new QSpacerItem(17, 27, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_18);

        label_17 = new QLabel(widget_property);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setMinimumSize(QSize(55, 0));
        label_17->setMaximumSize(QSize(55, 16777215));
        label_17->setFont(font);
        label_17->setStyleSheet(QStringLiteral("color:#ced4da;"));

        horizontalLayout_13->addWidget(label_17);

        checkBox = new QCheckBox(widget_property);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setMinimumSize(QSize(55, 20));
        checkBox->setMaximumSize(QSize(55, 20));
        QFont font4;
        font4.setFamily(QStringLiteral("OPPOSans B"));
        font4.setPointSize(10);
        checkBox->setFont(font4);
        checkBox->setStyleSheet(QStringLiteral("color:#ced4da;"));

        horizontalLayout_13->addWidget(checkBox);

        lineEdit_port_4 = new QLineEdit(widget_property);
        lineEdit_port_4->setObjectName(QStringLiteral("lineEdit_port_4"));
        lineEdit_port_4->setMinimumSize(QSize(70, 30));
        lineEdit_port_4->setMaximumSize(QSize(70, 16777215));
        lineEdit_port_4->setFont(font);
        lineEdit_port_4->setStyleSheet(QLatin1String("QLineEdit{\n"
"color:#ced4da;\n"
"border-radius: 14px;\n"
"background-color: rgb(25, 25, 25, 155);\n"
"border: 0px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding-left:10px;\n"
"padding-right:10px;\n"
"}"));

        horizontalLayout_13->addWidget(lineEdit_port_4);

        horizontalSpacer_19 = new QSpacerItem(17, 27, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_19);

        label_18 = new QLabel(widget_property);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setMinimumSize(QSize(55, 0));
        label_18->setMaximumSize(QSize(55, 16777215));
        label_18->setFont(font);
        label_18->setStyleSheet(QStringLiteral("color:#ced4da;"));

        horizontalLayout_13->addWidget(label_18);

        lineEdit_port_5 = new QLineEdit(widget_property);
        lineEdit_port_5->setObjectName(QStringLiteral("lineEdit_port_5"));
        lineEdit_port_5->setMinimumSize(QSize(70, 30));
        lineEdit_port_5->setMaximumSize(QSize(70, 16777215));
        lineEdit_port_5->setFont(font);
        lineEdit_port_5->setStyleSheet(QLatin1String("QLineEdit{\n"
"color:#ced4da;\n"
"border-radius: 14px;\n"
"background-color: rgb(25, 25, 25, 155);\n"
"border: 0px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding-left:10px;\n"
"padding-right:10px;\n"
"}"));

        horizontalLayout_13->addWidget(lineEdit_port_5);

        horizontalSpacer_21 = new QSpacerItem(17, 27, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_21);

        toolButton_5 = new QToolButton(widget_property);
        toolButton_5->setObjectName(QStringLiteral("toolButton_5"));
        toolButton_5->setMinimumSize(QSize(70, 30));
        toolButton_5->setMaximumSize(QSize(70, 16777215));
        toolButton_5->setFont(font2);
        toolButton_5->setStyleSheet(QLatin1String("QToolButton {\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(250, 118, 0);\n"
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
"	background-color: rgb(250, 118, 0);\n"
"}"));

        horizontalLayout_13->addWidget(toolButton_5);

        horizontalSpacer_26 = new QSpacerItem(17, 27, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_26);

        toolButton_save_2 = new QToolButton(widget_property);
        toolButton_save_2->setObjectName(QStringLiteral("toolButton_save_2"));
        toolButton_save_2->setMinimumSize(QSize(70, 30));
        toolButton_save_2->setMaximumSize(QSize(70, 16777215));
        toolButton_save_2->setFont(font2);
        toolButton_save_2->setStyleSheet(QLatin1String("QToolButton {\n"
"	color: rgb(255, 255, 255);\n"
"	\n"
"	background-color: rgb(0, 170, 0);\n"
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
"	background-color: rgb(0, 170, 0);\n"
"}"));

        horizontalLayout_13->addWidget(toolButton_save_2);

        horizontalSpacer_28 = new QSpacerItem(17, 27, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_28);

        toolButton_switch = new QToolButton(widget_property);
        toolButton_switch->setObjectName(QStringLiteral("toolButton_switch"));
        toolButton_switch->setMinimumSize(QSize(100, 30));
        toolButton_switch->setMaximumSize(QSize(100, 16777215));
        toolButton_switch->setFont(font2);
        toolButton_switch->setStyleSheet(QLatin1String("QToolButton {\n"
"	color: rgb(255, 255, 255);\n"
"	\n"
"	background-color: rgb(0, 170, 0);\n"
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
"	background-color: rgb(0, 170, 0);\n"
"}"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/lib/tree_open.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_switch->setIcon(icon4);
        toolButton_switch->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_13->addWidget(toolButton_switch);

        horizontalSpacer_25 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_25);

        horizontalSpacer_20 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_20);


        verticalLayout->addWidget(widget_property);

        stackedWidget_2 = new QStackedWidget(widget_right);
        stackedWidget_2->setObjectName(QStringLiteral("stackedWidget_2"));
        stackedWidget_2->setMinimumSize(QSize(0, 315));
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        verticalLayout_11 = new QVBoxLayout(page_2);
        verticalLayout_11->setSpacing(0);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        verticalLayout_11->setContentsMargins(0, 0, 0, 0);
        splitter_2 = new QSplitter(page_2);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Vertical);
        splitter_2->setHandleWidth(0);
        widget_4 = new QWidget(splitter_2);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setStyleSheet(QLatin1String("QComboBox{\n"
"	font: 10pt \"OPPOSans B\";\n"
"	color:#ffffff;\n"
"	color: rgb(138, 138, 138);\n"
"	background:transparent;\n"
"	border-radius: 0px;\n"
"}\n"
"\n"
"QComboBox::focus {\n"
"border: 1px solid rgb(255, 104, 17);\n"
"}\n"
"\n"
"QComboBox::hover {\n"
"border: 1px solid rgb(255, 104, 17);\n"
"}\n"
"\n"
"\n"
"QComboBox QAbstractItemView{\n"
"	font: 10pt \"OPPOSans B\";\n"
"	color:#ffffff;\n"
"	border:0px solid #8a8a8a;\n"
"	color: rgb(138, 138, 138);\n"
"	border-radius:0px;\n"
"	background:transparent;\n"
"    outline:0px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView::item\n"
"{\n"
"	height:28px;\n"
"}\n"
"QComboBox:disabled{\n"
"	border:1px solid gray;\n"
"	color:gray;\n"
"}\n"
"\n"
"QComboBox::drop-down{\n"
"	background:transparent;\n"
"}\n"
"QComboBox::down-arrow{\n"
"	image: url(:/lib/tree_open.png);\n"
"    width:20px;\n"
"	height:20px;\n"
"    margin-right: 20px;\n"
"}\n"
"\n"
"\n"
"QComboBox::down-arrow:enabled{\n"
"	color:#52DCFE;\n"
"}\n"
"QComboBox QAbstractItemView{\n"
"	outline:0px solid gray"
                        ";\n"
"	border:1px solid #1e2d36;\n"
"	color:#ffffff;\n"
"	background-color:#1e2d36;\n"
"	selection-background-color:#52DCFE;\n"
"}\n"
"\n"
"QToolButton {\n"
"	font: 10pt \"OPPOSans B\";\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(250, 118, 0);\n"
"	border-radius: 5px;\n"
"}\n"
"QToolButton::menu-indicator { \n"
"	image: None;\n"
"}\n"
"QToolButton:hover {\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(250, 118, 0);\n"
"}\n"
""));
        horizontalLayout_3 = new QHBoxLayout(widget_4);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        splitter = new QSplitter(widget_4);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        splitter->setHandleWidth(0);
        widget = new QWidget(splitter);
        widget->setObjectName(QStringLiteral("widget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        widget->setStyleSheet(QStringLiteral(""));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_12 = new QWidget(widget);
        widget_12->setObjectName(QStringLiteral("widget_12"));
        widget_12->setMinimumSize(QSize(0, 30));
        widget_12->setStyleSheet(QStringLiteral("background-color: rgb(54, 81, 97);"));
        horizontalLayout_8 = new QHBoxLayout(widget_12);
        horizontalLayout_8->setSpacing(0);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        toolButton_request_param = new QToolButton(widget_12);
        toolButton_request_param->setObjectName(QStringLiteral("toolButton_request_param"));
        toolButton_request_param->setMinimumSize(QSize(70, 25));
        toolButton_request_param->setMaximumSize(QSize(70, 25));
        toolButton_request_param->setFont(font3);
        toolButton_request_param->setIcon(icon4);
        toolButton_request_param->setIconSize(QSize(20, 20));
        toolButton_request_param->setCheckable(false);
        toolButton_request_param->setChecked(false);
        toolButton_request_param->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_8->addWidget(toolButton_request_param);

        checkBox_3 = new QCheckBox(widget_12);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));
        checkBox_3->setMaximumSize(QSize(16777215, 20));
        checkBox_3->setFont(font);
        checkBox_3->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        checkBox_3->setChecked(true);

        horizontalLayout_8->addWidget(checkBox_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer);


        verticalLayout_2->addWidget(widget_12);

        treeWidget = new QTreeWidget(widget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setFont(3, font);
        __qtreewidgetitem->setFont(2, font);
        __qtreewidgetitem->setFont(1, font);
        __qtreewidgetitem->setFont(0, font4);
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setFont(font);
        treeWidget->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"font: 10pt \"OPPOSans B\";\n"
"color:#ced4da;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border-radius: 0px;\n"
"padding-left:0px;\n"
"padding-right:0px;\n"
"\n"
"}\n"
"\n"
"\n"
"QLineEdit::focus {\n"
"border: 1px solid rgb(255, 104, 17);\n"
"}\n"
"\n"
"QLineEdit::hover {\n"
"border: 1px solid rgb(255, 104, 17);\n"
"}\n"
"\n"
"QToolButton {\n"
"	background-color: rgba(255, 255, 255,0);\n"
"	border: none;\n"
"}\n"
"\n"
"QTreeWidget {\n"
"	border:2px solid rgb(54, 81, 97);\n"
"	color: rgb(0, 0, 0);\n"
"	\n"
"	font: 10pt \"OPPOSans B\";\n"
"	\n"
"}\n"
"\n"
"QHeaderView {\n"
"font: 10pt \"OPPOSans B\";\n"
"color: rgb(56, 56, 56);\n"
"background-color: rgb(54, 81, 97);\n"
"}\n"
"\n"
"QTreeWidget#treeWidget {\n"
"	border: 0px solid #D3D6DD;\n"
"	outline: none;\n"
"}\n"
"QTreeWidget::item {\n"
"\n"
"	height: 28px;\n"
"	color: rgb(255, 255, 255);\n"
"	outline: 0px;\n"
"	border-bottom: 1px solid rgba(197, 197, 197, 50);\n"
"}\n"
"\n"
"QTreeWidget::item:hover {\n"
"	outline: 0px;\n"
"    color: rgb"
                        "(255, 255, 255);\n"
"	background-color: rgba(209, 209, 209, 20);\n"
"}\n"
"QTreeWidget::item:selected{\n"
"	outline: 0px;\n"
"    color: #45B2FF;\n"
"	background-color: rgba(209, 209, 209, 20);\n"
"}\n"
"QTreeWidget::item:selected:active{\n"
"	outline: 0px;\n"
"    color: #45B2FF;\n"
"}\n"
" \n"
"QTreeWidget::item:selected:!active {\n"
"	outline: 0px;\n"
"    color: #45B2FF;\n"
"}\n"
"QTreeWidget::branch {\n"
"	height: 28px;\n"
"	width: 28px;\n"
"}\n"
"QTreeWidget::branch:closed:has-children:!has-siblings,\n"
"QTreeWidget::branch:closed:has-children:has-siblings {\n"
"	border-image: none;\n"
"    image: url(:/lib/tree_close.png);\n"
"}\n"
" \n"
"QTreeWidget::branch:open:has-children:!has-siblings,\n"
"QTreeWidget::branch:open:has-children:has-siblings  {\n"
"	border-image: none;\n"
"    image: url(:/lib/tree_open.png);\n"
"}\n"
"\n"
"\n"
"QScrollBar::horizontal{\n"
"    height: 8px;\n"
"	background-color: rgb(67, 77, 88);\n"
"	margin: 0px,0px,0px,0px;\n"
"    padding-top: 0px;		/*//\351\232\220\350\227\217\344"
                        "\270\212\344\270\213\347\232\204\347\256\255\345\244\264*/\n"
"    padding-bottom: 0px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal {\n"
"    height: 8px;\n"
"	background-color: rgb(239, 239, 239);\n"
"    /*\346\273\232\345\212\250\346\235\241\344\270\244\347\253\257\345\217\230\346\210\220\346\244\255\345\234\206 */\n"
"    border-radius: 2px;\n"
"    min-height: 0;\n"
"}\n"
"\n"
"QScrollBar::sub-page:horizontal {\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}\n"
"QScrollBar::add-page:horizontal \n"
"{\n"
"    background-color: rgba(255, 255, 255, 0);\n"
"}\n"
"\n"
"QScrollBar::add-line:horizontal {\n"
"	border: none;\n"
"    height: 0px;\n"
"    subcontrol-position: bottom;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"QScrollBar::sub-line:horizontal {\n"
"    border: none;\n"
"    height: 0px;\n"
"    subcontrol-position: top;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::down-arrow:horizontal {\n"
"    border:none;\n"
"}\n"
"QScrollBar::up-arrow:horizontal {\n"
"    border:none;\n"
""
                        "}\n"
"\n"
"QToolTip {\n"
"color:#ced4da;\n"
"background-color: rgb(108, 117, 125, 65);\n"
"border-radius: 2px;\n"
"}"));
        treeWidget->setIndentation(20);
        treeWidget->setUniformRowHeights(true);
        treeWidget->setSortingEnabled(false);
        treeWidget->setAnimated(false);
        treeWidget->header()->setVisible(true);
        treeWidget->header()->setDefaultSectionSize(100);
        treeWidget->header()->setMinimumSectionSize(20);
        treeWidget->header()->setStretchLastSection(true);

        verticalLayout_2->addWidget(treeWidget);

        splitter->addWidget(widget);

        horizontalLayout_3->addWidget(splitter);

        splitter_2->addWidget(widget_4);
        widget_2 = new QWidget(splitter_2);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        verticalLayout_6 = new QVBoxLayout(widget_2);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        widget_5 = new QWidget(widget_2);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setMinimumSize(QSize(0, 100));
        QFont font5;
        font5.setStyleStrategy(QFont::PreferDefault);
        widget_5->setFont(font5);
        verticalLayout_7 = new QVBoxLayout(widget_5);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        widget_8 = new QWidget(widget_5);
        widget_8->setObjectName(QStringLiteral("widget_8"));
        widget_8->setMinimumSize(QSize(0, 30));
        widget_8->setMaximumSize(QSize(16777215, 30));
        widget_8->setFont(font4);
        widget_8->setStyleSheet(QStringLiteral("background-color: rgb(54, 81, 97);"));
        horizontalLayout_5 = new QHBoxLayout(widget_8);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        toolButton_response = new QToolButton(widget_8);
        toolButton_response->setObjectName(QStringLiteral("toolButton_response"));
        toolButton_response->setMinimumSize(QSize(70, 0));
        toolButton_response->setMaximumSize(QSize(70, 16777215));
        toolButton_response->setStyleSheet(QLatin1String("\n"
"QToolButton {\n"
"	font: 10pt \"OPPOSans B\";\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"	border-radius: 5px;\n"
"}"));
        toolButton_response->setIcon(icon4);
        toolButton_response->setIconSize(QSize(20, 20));
        toolButton_response->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_5->addWidget(toolButton_response);

        checkBox_show_source = new QCheckBox(widget_8);
        checkBox_show_source->setObjectName(QStringLiteral("checkBox_show_source"));
        checkBox_show_source->setMaximumSize(QSize(16777215, 30));
        checkBox_show_source->setFont(font);
        checkBox_show_source->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        checkBox_show_source->setChecked(true);

        horizontalLayout_5->addWidget(checkBox_show_source);

        toolButton_show_thrift_info = new QToolButton(widget_8);
        toolButton_show_thrift_info->setObjectName(QStringLiteral("toolButton_show_thrift_info"));
        toolButton_show_thrift_info->setMinimumSize(QSize(150, 30));
        toolButton_show_thrift_info->setMaximumSize(QSize(150, 30));
        toolButton_show_thrift_info->setFont(font);
        toolButton_show_thrift_info->setStyleSheet(QLatin1String("QToolButton {\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(54, 81, 97);\n"
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
"	background-color: rgb(54, 81, 97);\n"
"}"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/lib/wenhao.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_show_thrift_info->setIcon(icon5);
        toolButton_show_thrift_info->setIconSize(QSize(18, 18));
        toolButton_show_thrift_info->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_5->addWidget(toolButton_show_thrift_info);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);


        verticalLayout_7->addWidget(widget_8);

        stackedWidget = new QStackedWidget(widget_5);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setMinimumSize(QSize(0, 200));
        stackedWidget->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(79, 79, 79);"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        verticalLayout_4 = new QVBoxLayout(page);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        tabWidget_response = new QTabWidget(page);
        tabWidget_response->setObjectName(QStringLiteral("tabWidget_response"));
        QFont font6;
        font6.setFamily(QStringLiteral("OPPOSans B"));
        font6.setPointSize(10);
        font6.setBold(false);
        font6.setUnderline(false);
        font6.setWeight(50);
        tabWidget_response->setFont(font6);
        tabWidget_response->setStyleSheet(QString::fromUtf8("\n"
"\n"
"/*\350\256\276\347\275\256TabWidget\344\270\255tab_1\347\232\204\346\240\267\345\274\217*/\n"
"#tab_1.QWidget{\n"
"	background-color: rgb(108, 117, 125, 65);\n"
"}\n"
" \n"
"/*\350\256\276\347\275\256TabWidget\344\270\255tab_2\347\232\204\346\240\267\345\274\217*/\n"
"#tab_11.QWidget{\n"
"	background-color: rgb(108, 117, 125, 65);\n"
"}\n"
" \n"
"/*\350\256\276\347\275\256TabWidget\344\270\255QTabBar\347\232\204\346\240\267\345\274\217*/\n"
"QTabBar::tab{\n"
"    \n"
"	background-color: rgb(255, 255, 255);\n"
"	\n"
"	/*background-color: rgb(54, 81, 97);*/\n"
"	/*font-family:Consolas; */   /*\350\256\276\347\275\256tab\344\270\255\347\232\204\346\226\207\346\234\254\347\232\204\345\255\227\344\275\223*/\n"
"	font-size:10pt;\n"
"	\n"
"	\n"
"	\n"
"	color: rgb(56, 56, 56);\n"
"	border-top-left-radius: 0px;    /*\350\256\276\347\275\256tab\347\232\204\350\276\271\346\241\206\347\232\204\345\234\206\350\247\222\357\274\210\345\267\246\344\270\212\345\234\206\350\247\222\357\274\211*/\n"
"	border-top-right-"
                        "radius: 0px;    /*\350\256\276\347\275\256tab\347\232\204\350\276\271\346\241\206\347\232\204\345\234\206\350\247\222\357\274\210\345\217\263\344\270\212\345\234\206\350\247\222\357\274\211*/\n"
"	width:70px;\n"
"	padding: 5px;\n"
"	/*margin-right:0px;\n"
"	margin-left: 0px;*/\n"
"}\n"
" \n"
"/*\350\256\276\347\275\256TabWidget\344\270\255QTabBar\347\232\204tab\350\242\253\351\200\211\344\270\255\346\227\266\347\232\204\346\240\267\345\274\217*/\n"
"QTabBar::tab:selected{\n"
"	/*background-color: rgb(15, 15, 15);*/\n"
"	/*border-top:3px solid rgb(108, 117, 125, 65); */\n"
"	border-bottom:2px solid rgb(0, 170, 255); \n"
"	color: rgb(0, 170, 255);\n"
"}\n"
" \n"
"/*\350\256\276\347\275\256TabWidget\344\270\255\351\274\240\346\240\207\346\202\254\346\265\256\345\234\250QTabBar\347\232\204tab\344\270\212\357\274\214\344\275\206\346\234\252\351\200\211\344\270\255\350\257\245Tab\347\232\204\346\240\267\345\274\217*/\n"
"QTabBar::tab:hover:!selected {\n"
"	/*border-bottom:2px solid rgb(0, 170, 255); */\n"
"	color: r"
                        "gb(0, 170, 255);\n"
"}\n"
" \n"
"/*\350\256\276\347\275\256TabWidget\347\232\204\350\276\271\346\241\206\347\232\204\346\240\267\345\274\217*/\n"
"QTabWidget::pane {\n"
"    border-top:0px solid rgb(108, 117, 125, 65); \n"
"}\n"
" \n"
"\n"
"QTabBar::close-button{ \n"
"	\n"
"	border-image: url(:/lib/icon-close4.png);\n"
"}\n"
"\n"
"QTabBar::close-button:selected{\n"
"	border-image: url(:/lib/icon-close4.png);\n"
"}\n"
"\n"
"\n"
"QTabBar::close-button:hover{\n"
"	border-image: url(:/lib/icon-close42.png);\n"
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
"QTabBar QToolButton:"
                        "hover {\n"
"	background-color: rgba(100, 117, 125, 0);\n"
"}"));
        tab_source = new QWidget();
        tab_source->setObjectName(QStringLiteral("tab_source"));
        tab_source->setFont(font);
        horizontalLayout_12 = new QHBoxLayout(tab_source);
        horizontalLayout_12->setSpacing(0);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(9, 9, 9, 9);
        textEdit_info = new QTextEdit(tab_source);
        textEdit_info->setObjectName(QStringLiteral("textEdit_info"));
        textEdit_info->setMinimumSize(QSize(400, 0));
        textEdit_info->setMaximumSize(QSize(400, 16777215));
        textEdit_info->setFont(font);
        textEdit_info->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        textEdit_info->setStyleSheet(QLatin1String("border: 1px solid rgba(199, 199, 199, 80);\n"
"border-radius: 2px;"));
        textEdit_info->setFrameShape(QFrame::Box);
        textEdit_info->setReadOnly(true);
        textEdit_info->setCursorWidth(2);

        horizontalLayout_12->addWidget(textEdit_info);

        textEdit = new QTextEdit(tab_source);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        QFont font7;
        font7.setFamily(QStringLiteral("Cascadia Code"));
        font7.setPointSize(11);
        font7.setStyleStrategy(QFont::PreferAntialias);
        textEdit->setFont(font7);
        textEdit->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        textEdit->setStyleSheet(QLatin1String("border: 1px solid rgba(199, 199, 199, 80);\n"
"border-radius: 2px;"));
        textEdit->setFrameShape(QFrame::Box);
        textEdit->setReadOnly(true);

        horizontalLayout_12->addWidget(textEdit);

        tabWidget_response->addTab(tab_source, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        verticalLayout_8 = new QVBoxLayout(tab_3);
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        label_headers = new QLabel(tab_3);
        label_headers->setObjectName(QStringLiteral("label_headers"));
        label_headers->setMinimumSize(QSize(0, 30));
        label_headers->setMaximumSize(QSize(16777215, 30));
        label_headers->setFont(font);

        verticalLayout_8->addWidget(label_headers);

        textEdit_data = new QTextEdit(tab_3);
        textEdit_data->setObjectName(QStringLiteral("textEdit_data"));
        textEdit_data->setFont(font);
        textEdit_data->setStyleSheet(QLatin1String("border: 1px solid rgba(199, 199, 199, 80);\n"
"border-radius: 2px;"));
        textEdit_data->setFrameShape(QFrame::Box);
        textEdit_data->setReadOnly(true);

        verticalLayout_8->addWidget(textEdit_data);

        tabWidget_response->addTab(tab_3, QString());

        verticalLayout_4->addWidget(tabWidget_response);

        stackedWidget->addWidget(page);
        page_request = new QWidget();
        page_request->setObjectName(QStringLiteral("page_request"));
        page_request->setStyleSheet(QStringLiteral("background-color: rgb(239, 239, 239);"));
        horizontalLayout_11 = new QHBoxLayout(page_request);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalSpacer_15 = new QSpacerItem(351, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_15);

        widget_13 = new QWidget(page_request);
        widget_13->setObjectName(QStringLiteral("widget_13"));
        widget_13->setMinimumSize(QSize(0, 0));
        widget_13->setMaximumSize(QSize(5555555, 16777215));
        verticalLayout_10 = new QVBoxLayout(widget_13);
        verticalLayout_10->setSpacing(0);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        label_12 = new QLabel(widget_13);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setMinimumSize(QSize(200, 200));
        label_12->setMaximumSize(QSize(200, 200));
        label_12->setStyleSheet(QStringLiteral("border-image: url(:/lib/ping2.png);"));

        verticalLayout_10->addWidget(label_12);

        label_13 = new QLabel(widget_13);
        label_13->setObjectName(QStringLiteral("label_13"));
        QFont font8;
        font8.setFamily(QStringLiteral("OPPOSans B"));
        font8.setPointSize(11);
        label_13->setFont(font8);
        label_13->setStyleSheet(QStringLiteral("color: rgb(106, 106, 106);"));
        label_13->setAlignment(Qt::AlignCenter);

        verticalLayout_10->addWidget(label_13);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_10->addItem(verticalSpacer_2);


        horizontalLayout_11->addWidget(widget_13);

        horizontalSpacer_14 = new QSpacerItem(350, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_14);

        stackedWidget->addWidget(page_request);
        page_error = new QWidget();
        page_error->setObjectName(QStringLiteral("page_error"));
        page_error->setStyleSheet(QStringLiteral("background-color: rgb(239, 239, 239);"));
        horizontalLayout_10 = new QHBoxLayout(page_error);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_12);

        widget_3 = new QWidget(page_error);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMinimumSize(QSize(0, 0));
        widget_3->setMaximumSize(QSize(5555555, 16777215));
        verticalLayout_9 = new QVBoxLayout(widget_3);
        verticalLayout_9->setSpacing(0);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(widget_3);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setMinimumSize(QSize(200, 200));
        label_10->setMaximumSize(QSize(200, 200));
        label_10->setStyleSheet(QStringLiteral("border-image: url(:/lib/error2.png);"));

        verticalLayout_9->addWidget(label_10);

        label_11 = new QLabel(widget_3);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setFont(font8);
        label_11->setStyleSheet(QStringLiteral("color: rgb(106, 106, 106);"));
        label_11->setAlignment(Qt::AlignCenter);

        verticalLayout_9->addWidget(label_11);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer);


        horizontalLayout_10->addWidget(widget_3);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_13);

        stackedWidget->addWidget(page_error);

        verticalLayout_7->addWidget(stackedWidget);

        widget_10 = new QWidget(widget_5);
        widget_10->setObjectName(QStringLiteral("widget_10"));
        widget_10->setMinimumSize(QSize(0, 25));
        widget_10->setFont(font);
        widget_10->setStyleSheet(QStringLiteral("background-color: rgb(54, 81, 97);"));
        horizontalLayout_6 = new QHBoxLayout(widget_10);
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(3, 3, 0, 3);
        label_req = new QLabel(widget_10);
        label_req->setObjectName(QStringLiteral("label_req"));
        label_req->setFont(font);
        label_req->setStyleSheet(QStringLiteral(""));

        horizontalLayout_6->addWidget(label_req);

        horizontalSpacer_7 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_7);

        label_time = new QLabel(widget_10);
        label_time->setObjectName(QStringLiteral("label_time"));
        label_time->setMinimumSize(QSize(0, 0));
        label_time->setMaximumSize(QSize(16777215, 20));
        label_time->setFont(font);
        label_time->setStyleSheet(QLatin1String("background-color: rgb(54, 81, 97);\n"
"color: rgb(255, 255, 255);\n"
"padding-left:2px;\n"
"padding-right:10px;"));

        horizontalLayout_6->addWidget(label_time);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);


        verticalLayout_7->addWidget(widget_10);


        verticalLayout_6->addWidget(widget_5);

        splitter_2->addWidget(widget_2);

        verticalLayout_11->addWidget(splitter_2);

        stackedWidget_2->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        stackedWidget_2->addWidget(page_3);

        verticalLayout->addWidget(stackedWidget_2);


        horizontalLayout_4->addWidget(widget_right);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 10);

        retranslateUi(thriftwidget);

        tabWidget->setCurrentIndex(1);
        stackedWidget_2->setCurrentIndex(0);
        stackedWidget->setCurrentIndex(0);
        tabWidget_response->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(thriftwidget);
    } // setupUi

    void retranslateUi(QWidget *thriftwidget)
    {
        thriftwidget->setWindowTitle(QApplication::translate("thriftwidget", "Form", nullptr));
        lineEdit_find->setPlaceholderText(QApplication::translate("thriftwidget", "\346\220\234\347\264\242API", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("thriftwidget", "\345\216\206\345\217\262\350\256\260\345\275\225", nullptr));
        toolButton_inportFile->setText(QApplication::translate("thriftwidget", "\345\257\274\345\205\245thrift\346\226\207\344\273\266", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("thriftwidget", "\346\216\245\345\217\243\345\210\227\350\241\250", nullptr));
        label_14->setText(QApplication::translate("thriftwidget", "\346\265\213\350\257\225\347\261\273\345\236\213", nullptr));
        comboBox_testType->setItemText(0, QApplication::translate("thriftwidget", "\345\237\272\347\241\200\346\265\213\350\257\225", nullptr));
        comboBox_testType->setItemText(1, QApplication::translate("thriftwidget", "\346\200\247\350\203\275\346\265\213\350\257\225", nullptr));

        label_2->setText(QApplication::translate("thriftwidget", "\344\270\273\346\234\272", nullptr));
        lineEdit_host->setText(QApplication::translate("thriftwidget", "172.16.8.154", nullptr));
        lineEdit_host->setPlaceholderText(QApplication::translate("thriftwidget", "172.16.8.154", nullptr));
        label->setText(QApplication::translate("thriftwidget", "\347\253\257\345\217\243", nullptr));
        lineEdit_port->setText(QApplication::translate("thriftwidget", "11040", nullptr));
        lineEdit_port->setPlaceholderText(QApplication::translate("thriftwidget", "9090", nullptr));
        toolButton_test->setText(QApplication::translate("thriftwidget", "\346\265\213\350\257\225\345\234\260\345\235\200", nullptr));
        label_5->setText(QApplication::translate("thriftwidget", "\344\274\240\350\276\223\345\261\202", nullptr));
        comboBox_transport->setItemText(0, QApplication::translate("thriftwidget", "TFramedTransport", nullptr));
        comboBox_transport->setItemText(1, QApplication::translate("thriftwidget", "TBufferedTransport", nullptr));

        label_8->setText(QApplication::translate("thriftwidget", "\345\215\217\350\256\256\345\261\202", nullptr));
        comboBox_protocol->setItemText(0, QApplication::translate("thriftwidget", "TBinaryProtocol", nullptr));

        label_9->setText(QApplication::translate("thriftwidget", "\350\257\267\346\261\202\347\261\273\345\236\213", nullptr));
        comboBox_reqType->setItemText(0, QApplication::translate("thriftwidget", "CALL", nullptr));
        comboBox_reqType->setItemText(1, QApplication::translate("thriftwidget", "ONEWAY", nullptr));

        label_3->setText(QApplication::translate("thriftwidget", "\346\216\245\345\217\243", nullptr));
        lineEdit_funcName->setText(QApplication::translate("thriftwidget", "getBadword", nullptr));
        lineEdit_funcName->setPlaceholderText(QApplication::translate("thriftwidget", "yourMethod2", nullptr));
        toolButton_request->setText(QApplication::translate("thriftwidget", "\350\257\267\346\261\202\346\216\245\345\217\243", nullptr));
        toolButton_save->setText(QApplication::translate("thriftwidget", "\344\277\235\345\255\230", nullptr));
        label_15->setText(QApplication::translate("thriftwidget", "\347\272\277\347\250\213\346\225\260", nullptr));
        lineEdit_port_2->setText(QString());
        lineEdit_port_2->setPlaceholderText(QApplication::translate("thriftwidget", "10", nullptr));
        label_16->setText(QApplication::translate("thriftwidget", "\345\220\257\345\212\250\346\227\266\351\227\264", nullptr));
        lineEdit_port_3->setText(QString());
        lineEdit_port_3->setPlaceholderText(QApplication::translate("thriftwidget", "1", nullptr));
        label_17->setText(QApplication::translate("thriftwidget", "\345\276\252\347\216\257\346\254\241\346\225\260", nullptr));
        checkBox->setText(QApplication::translate("thriftwidget", "\346\260\270\350\277\234", nullptr));
        lineEdit_port_4->setText(QString());
        lineEdit_port_4->setPlaceholderText(QApplication::translate("thriftwidget", "1", nullptr));
        label_18->setText(QApplication::translate("thriftwidget", "\345\201\234\346\255\242\346\227\266\351\227\264", nullptr));
        lineEdit_port_5->setText(QString());
        lineEdit_port_5->setPlaceholderText(QApplication::translate("thriftwidget", "10", nullptr));
        toolButton_5->setText(QApplication::translate("thriftwidget", "\345\274\200\345\247\213\346\265\213\350\257\225", nullptr));
        toolButton_save_2->setText(QApplication::translate("thriftwidget", "\344\277\235\345\255\230\346\265\213\350\257\225", nullptr));
        toolButton_switch->setText(QApplication::translate("thriftwidget", "\345\210\207\346\215\242\345\210\260\346\212\245\345\221\212", nullptr));
        toolButton_request_param->setText(QApplication::translate("thriftwidget", "\345\205\245\345\217\202", nullptr));
        checkBox_3->setText(QApplication::translate("thriftwidget", "\346\240\271\346\215\256\346\225\260\346\215\256\347\261\273\345\236\213\347\224\237\346\210\220\346\265\213\350\257\225\346\225\260\346\215\256", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(3, QApplication::translate("thriftwidget", "\345\217\202\346\225\260\345\200\274", nullptr));
        ___qtreewidgetitem->setText(2, QApplication::translate("thriftwidget", "\345\217\202\346\225\260\347\261\273\345\236\213", nullptr));
        ___qtreewidgetitem->setText(1, QApplication::translate("thriftwidget", "\345\217\202\346\225\260\345\220\215", nullptr));
        ___qtreewidgetitem->setText(0, QApplication::translate("thriftwidget", "\345\272\217\345\217\267", nullptr));
        toolButton_response->setText(QApplication::translate("thriftwidget", "\350\257\267\346\261\202", nullptr));
        checkBox_show_source->setText(QApplication::translate("thriftwidget", "\346\230\276\347\244\272\350\257\267\346\261\202\346\272\220\346\225\260\346\215\256/\347\273\223\346\236\234\346\272\220\346\225\260\346\215\256", nullptr));
        toolButton_show_thrift_info->setText(QApplication::translate("thriftwidget", "thrift\345\215\217\350\256\256\346\212\245\346\226\207\350\257\264\346\230\216", nullptr));
        textEdit_info->setHtml(QApplication::translate("thriftwidget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'OPPOSans B'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#505050;\"> thrift\345\215\217\350\256\256\346\212\245\346\226\207\350\257\264\346\230\216</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; color:#505050;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#505050;\">\344\270\200. </span><span style=\" color:#ff7373;\">\343\200\220\350\241\250\347\244\272\351\242\234\350\211\262"
                        "\343\200\221</span><span style=\" color:#505050;\">\346\266\210\346\201\257\351\225\277\345\272\246/string\351\225\277\345\272\246</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; color:#505050;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#505050;\">\344\272\214. </span><span style=\" color:#ffaa00;\">\343\200\220\350\241\250\347\244\272\351\242\234\350\211\262\343\200\221</span><span style=\" color:#505050;\">\346\266\210\346\201\257\347\261\273\345\236\213</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#505050;\">CALL\357\274\21080010001\357\274\211\357\274\214\350\260\203\347\224\250\346\226\271\346\263\225\357\274\214\345\271\266\345\270\214\346\234\233\350\216\267\345\217\226\350"
                        "\277\224\345\233\236\346\266\210\343\200\202	</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#505050;\">REPLY\357\274\21080010002\357\274\211\357\274\214\346\235\245\350\207\252\346\234\215\345\212\241\347\253\257\350\277\224\345\233\236\347\232\204\346\266\210\346\201\257\343\200\202	</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#505050;\">EXCEPTION\357\274\21080010003\357\274\211\357\274\214\346\234\215\345\212\241\345\231\250\345\244\204\347\220\206\350\257\267\346\261\202\346\227\266\345\207\272\347\216\260\345\274\202\345\270\270\343\200\202	</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#505050;\">ONEWAY\357\274\21080010004\357\274\211\357\274\214\345\215\225\345\220\221\350\257"
                        "\267\346\261\202\357\274\214\344\270\215\351\234\200\350\246\201\350\277\224\345\233\236\346\225\260\346\215\256\343\200\202</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; color:#505050;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#505050;\">\344\270\211.</span><span style=\" color:#ffaa82;\">\343\200\220\350\241\250\347\244\272\351\242\234\350\211\262\343\200\221</span><span style=\" color:#505050;\">\346\226\271\346\263\225\345\220\215\351\225\277\345\272\246</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; color:#505050;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color"
                        ":#505050;\">\345\233\233.\343\200\220\350\241\250\347\244\272\351\242\234\350\211\262\343\200\221\346\226\271\346\263\225\345\220\215</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; color:#505050;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#505050;\">\344\272\224.</span><span style=\" color:#55007f;\">\343\200\220\350\241\250\347\244\272\351\242\234\350\211\262\343\200\221</span><span style=\" color:#505050;\">\346\265\201\346\260\264\345\217\267</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; color:#505050;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#505050;\">\345"
                        "\205\255. \346\225\260\346\215\256\347\261\273\345\236\213</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#005500;\">\343\200\220\350\241\250\347\244\272\351\242\234\350\211\262\343\200\221</span><span style=\" color:#505050;\">bool\347\261\273\345\236\213\357\274\210\347\261\273\345\236\2132\357\274\211   </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#500a0a;\">\343\200\220\350\241\250\347\244\272\351\242\234\350\211\262\343\200\221</span><span style=\" color:#505050;\">byte\347\261\273\345\236\213\357\274\210\347\261\273\345\236\2133\357\274\211</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#000082;\">\343\200\220\350\241\250\347\244\272\351\242\234\350\211\262\343\200\221</span><s"
                        "pan style=\" color:#505050;\">double\347\261\273\345\236\213\357\274\210\347\261\273\345\236\2134\357\274\211	</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#00aaff;\">\343\200\220\350\241\250\347\244\272\351\242\234\350\211\262\343\200\221</span><span style=\" color:#505050;\">i16\347\261\273\345\236\213\357\274\210\347\261\273\345\236\2136\357\274\211      </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#ff00ff;\">\343\200\220\350\241\250\347\244\272\351\242\234\350\211\262\343\200\221</span><span style=\" color:#505050;\">i32\347\261\273\345\236\213\357\274\210\347\261\273\345\236\2138\357\274\211</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#00a096;\">\343\200\220\350\241\250\347"
                        "\244\272\351\242\234\350\211\262\343\200\221</span><span style=\" color:#505050;\">i64\347\261\273\345\236\213\357\274\210\347\261\273\345\236\21310\357\274\211    </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#aaaa00;\">\343\200\220\350\241\250\347\244\272\351\242\234\350\211\262\343\200\221</span><span style=\" color:#505050;\">string\347\261\273\345\236\213\357\274\210\347\261\273\345\236\21311\357\274\211</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#0055ff;\">\343\200\220\350\241\250\347\244\272\351\242\234\350\211\262\343\200\221</span><span style=\" color:#505050;\">struct\347\261\273\345\236\213\357\274\210\347\261\273\345\236\21312\357\274\211</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><spa"
                        "n style=\" color:#5500ff;\">\343\200\220\350\241\250\347\244\272\351\242\234\350\211\262\343\200\221</span><span style=\" color:#505050;\">map\347\261\273\345\236\213\357\274\210\347\261\273\345\236\21313\357\274\211  </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#ff7300;\">\343\200\220\350\241\250\347\244\272\351\242\234\350\211\262\343\200\221</span><span style=\" color:#505050;\">set\347\261\273\345\236\213\357\274\210\347\261\273\345\236\21314\357\274\211</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#55aa82;\">\343\200\220\350\241\250\347\244\272\351\242\234\350\211\262\343\200\221</span><span style=\" color:#505050;\">list\347\261\273\345\236\213\357\274\210\347\261\273\345\236\21315\357\274\211</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; marg"
                        "in-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; color:#505050;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#505050;\">\344\270\203. \345\205\266\344\273\226</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#00aa00;\">\343\200\220\350\241\250\347\244\272\351\242\234\350\211\262\343\200\221</span><span style=\" color:#505050;\">\345\255\227\346\256\265\345\272\217\345\217\267</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#000000;\">\343\200\220\350\241\250\347\244\272\351\242\234\350\211\262\343\200\221</span><span style=\" color:#505050;\">\347\273\223\346\235\237\347\254\246\357\274\21000\357\274\211</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; m"
                        "argin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#ff0000;\">\343\200\220\350\241\250\347\244\272\351\242\234\350\211\262\343\200\221</span><span style=\" color:#505050;\">\345\200\274</span></p></body></html>", nullptr));
        textEdit->setHtml(QApplication::translate("thriftwidget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Cascadia Code'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Courier New'; font-size:12pt;\"><br /></p></body></html>", nullptr));
        tabWidget_response->setTabText(tabWidget_response->indexOf(tab_source), QApplication::translate("thriftwidget", "Source", nullptr));
        label_headers->setText(QString());
        textEdit_data->setHtml(QApplication::translate("thriftwidget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'OPPOSans B'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        tabWidget_response->setTabText(tabWidget_response->indexOf(tab_3), QApplication::translate("thriftwidget", "Data", nullptr));
        label_12->setText(QString());
        label_13->setText(QApplication::translate("thriftwidget", "\346\216\245\345\217\243\350\257\267\346\261\202\344\270\255", nullptr));
        label_10->setText(QString());
        label_11->setText(QApplication::translate("thriftwidget", "\346\216\245\345\217\243\350\257\267\346\261\202\345\274\202\345\270\270", nullptr));
        label_req->setText(QString());
        label_time->setText(QApplication::translate("thriftwidget", "\345\223\215\345\272\224\346\227\266\351\227\264\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class thriftwidget: public Ui_thriftwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THRIFTWIDGET_H
