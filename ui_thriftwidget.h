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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
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
    QWidget *widget_7;
    QVBoxLayout *verticalLayout;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_host;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label;
    QLineEdit *lineEdit_port;
    QSpacerItem *horizontalSpacer_4;
    QToolButton *toolButton_test;
    QSpacerItem *horizontalSpacer_2;
    QWidget *horizontalWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLineEdit *lineEdit_funcName;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer_8;
    QToolButton *toolButton;
    QSplitter *splitter_2;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_3;
    QSplitter *splitter;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_12;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer;
    QToolButton *toolButton_show_thrift_info;
    QTreeWidget *treeWidget;
    QWidget *widget_thrift;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget_11;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QTextEdit *textEdit_2;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_6;
    QWidget *widget_5;
    QVBoxLayout *verticalLayout_7;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_5;
    QTextEdit *textEdit;
    QWidget *widget_10;
    QHBoxLayout *horizontalLayout_6;
    QCheckBox *checkBox_2;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_time;
    QSpacerItem *horizontalSpacer_6;

    void setupUi(QWidget *thriftwidget)
    {
        if (thriftwidget->objectName().isEmpty())
            thriftwidget->setObjectName(QStringLiteral("thriftwidget"));
        thriftwidget->resize(1137, 640);
        QFont font;
        font.setFamily(QStringLiteral("OPPOSans B"));
        font.setPointSize(10);
        font.setStyleStrategy(QFont::PreferAntialias);
        thriftwidget->setFont(font);
        thriftwidget->setStyleSheet(QStringLiteral("color: rgb(86, 86, 86);"));
        horizontalLayout_4 = new QHBoxLayout(thriftwidget);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        widget_left = new QWidget(thriftwidget);
        widget_left->setObjectName(QStringLiteral("widget_left"));
        widget_left->setMinimumSize(QSize(200, 0));
        widget_left->setMaximumSize(QSize(200, 16777215));
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
"border-radius: 15px;\n"
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
"	width:80px;\n"
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
"	/*backgr"
                        "ound-color: rgb(100, 117, 125, 125);*/\n"
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
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/lib/file2.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab_2, icon1, QString());

        verticalLayout_5->addWidget(tabWidget);


        horizontalLayout_4->addWidget(widget_left);

        widget_7 = new QWidget(thriftwidget);
        widget_7->setObjectName(QStringLiteral("widget_7"));
        widget_7->setStyleSheet(QString::fromUtf8("QComboBox{\n"
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
"	background-color: rgb(239, 239, 239);"
                        "\n"
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
        verticalLayout = new QVBoxLayout(widget_7);
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(9, 7, 9, 0);
        widget_6 = new QWidget(widget_7);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        widget_6->setMaximumSize(QSize(16777215, 33));
        widget_6->setStyleSheet(QStringLiteral("color:#ced4da;"));
        horizontalLayout_2 = new QHBoxLayout(widget_6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(9, 3, 0, 0);
        label_2 = new QLabel(widget_6);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(40, 16777215));
        label_2->setFont(font);

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
        toolButton_test->setFont(font2);
        toolButton_test->setStyleSheet(QLatin1String("QToolButton {\n"
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
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/lib/node2.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_test->setIcon(icon2);
        toolButton_test->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_2->addWidget(toolButton_test);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget_6);

        horizontalWidget = new QWidget(widget_7);
        horizontalWidget->setObjectName(QStringLiteral("horizontalWidget"));
        horizontalWidget->setMaximumSize(QSize(16777215, 33));
        horizontalWidget->setStyleSheet(QStringLiteral("color:#ced4da;"));
        horizontalLayout = new QHBoxLayout(horizontalWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, 0, 0);
        label_3 = new QLabel(horizontalWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(40, 16777215));
        label_3->setFont(font);

        horizontalLayout->addWidget(label_3);

        lineEdit_funcName = new QLineEdit(horizontalWidget);
        lineEdit_funcName->setObjectName(QStringLiteral("lineEdit_funcName"));
        lineEdit_funcName->setMinimumSize(QSize(0, 30));
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

        comboBox = new QComboBox(horizontalWidget);
        comboBox->addItem(QString());
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setMinimumSize(QSize(150, 30));
        comboBox->setFont(font);
        comboBox->setStyleSheet(QLatin1String("QComboBox{\n"
"	color:#ffffff;\n"
"	border:0px solid #8a8a8a;\n"
"	color: rgb(138, 138, 138);\n"
"	border-radius:5px;\n"
"	background:transparent;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView::item\n"
"{\n"
"height:28px;\n"
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
""));

        horizontalLayout->addWidget(comboBox);

        horizontalSpacer_8 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        toolButton = new QToolButton(horizontalWidget);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setMinimumSize(QSize(90, 30));
        toolButton->setFont(font2);
        toolButton->setStyleSheet(QLatin1String("QToolButton {\n"
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

        horizontalLayout->addWidget(toolButton);


        verticalLayout->addWidget(horizontalWidget);

        splitter_2 = new QSplitter(widget_7);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Vertical);
        splitter_2->setHandleWidth(0);
        widget_4 = new QWidget(splitter_2);
        widget_4->setObjectName(QStringLiteral("widget_4"));
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
        widget->setStyleSheet(QLatin1String("QComboBox{\n"
"font: 10pt \"OPPOSans B\";\n"
"}\n"
"\n"
"QComboBox QAbstractItemView{\n"
"font: 10pt \"OPPOSans B\";\n"
"}\n"
"\n"
"QComboBox QAbstractItemView::item{\n"
"\n"
"height:30px; \n"
"width:50px;\n"
"\n"
"}"));
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
        label_4 = new QLabel(widget_12);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(0, 30));
        label_4->setMaximumSize(QSize(16777215, 30));
        label_4->setFont(font);
        label_4->setStyleSheet(QLatin1String("background-color: rgb(54, 81, 97);\n"
"color: rgb(255, 255, 255);\n"
"padding-left:2px;\n"
"padding-right:10px;"));

        horizontalLayout_8->addWidget(label_4);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer);

        toolButton_show_thrift_info = new QToolButton(widget_12);
        toolButton_show_thrift_info->setObjectName(QStringLiteral("toolButton_show_thrift_info"));
        toolButton_show_thrift_info->setMinimumSize(QSize(30, 30));
        toolButton_show_thrift_info->setMaximumSize(QSize(30, 30));
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
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/lib/wenhao.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_show_thrift_info->setIcon(icon3);
        toolButton_show_thrift_info->setIconSize(QSize(18, 18));
        toolButton_show_thrift_info->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_8->addWidget(toolButton_show_thrift_info);


        verticalLayout_2->addWidget(widget_12);

        treeWidget = new QTreeWidget(widget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setFont(2, font);
        __qtreewidgetitem->setFont(1, font);
        __qtreewidgetitem->setFont(0, font);
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setFont(font);
        treeWidget->setStyleSheet(QLatin1String("QLineEdit{\n"
"font: 10pt \"OPPOSans B\";\n"
"color:#ced4da;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border: 1px solid rgba(255, 255, 255, 0);\n"
"border-radius: 0px;\n"
"padding-left:0px;\n"
"padding-right:0px;\n"
"}\n"
"\n"
"QToolButton {\n"
"	background-color: rgba(255, 255, 255,0);\n"
"	border: none;\n"
"}\n"
"\n"
"QTreeWidget {\n"
"	border:2px solid rgb(54, 81, 97);\n"
"	\n"
"	color: rgb(0, 0, 0);\n"
"}\n"
"\n"
"QTreeWidget#treeWidget {\n"
"	border: 0px solid #D3D6DD;\n"
"	outline: none;\n"
"}\n"
"QTreeWidget::item {\n"
"	height: 28px;\n"
"	color: rgb(255, 255, 255);\n"
"	border: 1px;\n"
"	outline: 0px;\n"
"}\n"
"\n"
"QTreeWidget::item:hover {\n"
"	border: 0px;\n"
"	outline: 0px;\n"
"    color: rgb(255, 255, 255);\n"
"	background-color: rgba(209, 209, 209, 20);\n"
"}\n"
"QTreeWidget::item:selected{\n"
"    border: 0px;\n"
"	outline: 0px;\n"
"    color: #45B2FF;\n"
"	background-color: rgba(209, 209, 209, 20);\n"
"}\n"
"QTreeWidget::item:selected:active{\n"
"    border: 0px;\n"
"	outline: 0px;\n"
""
                        "    color: #45B2FF;\n"
"}\n"
" \n"
"QTreeWidget::item:selected:!active {\n"
"    border: 0px;\n"
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
        widget_thrift = new QWidget(splitter);
        widget_thrift->setObjectName(QStringLiteral("widget_thrift"));
        widget_thrift->setStyleSheet(QStringLiteral("background-color: rgb(54, 81, 97);"));
        verticalLayout_4 = new QVBoxLayout(widget_thrift);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        widget_11 = new QWidget(widget_thrift);
        widget_11->setObjectName(QStringLiteral("widget_11"));
        widget_11->setMinimumSize(QSize(0, 28));
        widget_11->setMaximumSize(QSize(16777215, 28));
        horizontalLayout_7 = new QHBoxLayout(widget_11);
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(widget_11);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(0, 28));
        label_6->setMaximumSize(QSize(16777215, 28));
        label_6->setFont(font);
        label_6->setStyleSheet(QLatin1String("background-color: rgb(54, 81, 97);\n"
"color: rgb(255, 255, 255);\n"
"padding-left:2px;\n"
"padding-right:10px;"));

        horizontalLayout_7->addWidget(label_6);


        verticalLayout_4->addWidget(widget_11);

        textEdit_2 = new QTextEdit(widget_thrift);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setFont(font);
        textEdit_2->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        textEdit_2->setStyleSheet(QLatin1String("QTextEdit{\n"
"color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 0px;\n"
"border:2px solid rgb(54, 81, 97);\n"
"}"));
        textEdit_2->setReadOnly(true);

        verticalLayout_4->addWidget(textEdit_2);

        splitter->addWidget(widget_thrift);

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
        QFont font3;
        font3.setStyleStrategy(QFont::PreferDefault);
        widget_5->setFont(font3);
        verticalLayout_7 = new QVBoxLayout(widget_5);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        widget_8 = new QWidget(widget_5);
        widget_8->setObjectName(QStringLiteral("widget_8"));
        widget_8->setStyleSheet(QStringLiteral("background-color: rgb(54, 81, 97);"));
        horizontalLayout_5 = new QHBoxLayout(widget_8);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(widget_8);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMinimumSize(QSize(0, 30));
        label_7->setMaximumSize(QSize(16777215, 30));
        label_7->setFont(font);
        label_7->setStyleSheet(QLatin1String("background-color: rgb(54, 81, 97);\n"
"color: rgb(255, 255, 255);\n"
"padding-left:2px;\n"
"padding-right:10px;"));

        horizontalLayout_5->addWidget(label_7);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);


        verticalLayout_7->addWidget(widget_8);

        textEdit = new QTextEdit(widget_5);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setFont(font);
        textEdit->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        textEdit->setStyleSheet(QLatin1String("QTextEdit{\n"
"color: rgb(80, 80, 80);\n"
"background-color: rgb(255, 255, 255);\n"
"border: 1px solid rgba(255, 255, 255, 0);\n"
"border-radius: 0px;\n"
"padding-left:10px;\n"
"padding-right:10px;\n"
"}"));
        textEdit->setReadOnly(true);

        verticalLayout_7->addWidget(textEdit);

        widget_10 = new QWidget(widget_5);
        widget_10->setObjectName(QStringLiteral("widget_10"));
        widget_10->setMinimumSize(QSize(0, 28));
        widget_10->setFont(font);
        widget_10->setStyleSheet(QStringLiteral("background-color: rgb(54, 81, 97);"));
        horizontalLayout_6 = new QHBoxLayout(widget_10);
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        checkBox_2 = new QCheckBox(widget_10);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setMaximumSize(QSize(16777215, 20));
        checkBox_2->setFont(font);
        checkBox_2->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        checkBox_2->setChecked(true);

        horizontalLayout_6->addWidget(checkBox_2);

        horizontalSpacer_7 = new QSpacerItem(300, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

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

        verticalLayout->addWidget(splitter_2);


        horizontalLayout_4->addWidget(widget_7);


        retranslateUi(thriftwidget);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(thriftwidget);
    } // setupUi

    void retranslateUi(QWidget *thriftwidget)
    {
        thriftwidget->setWindowTitle(QApplication::translate("thriftwidget", "Form", nullptr));
        lineEdit_find->setPlaceholderText(QApplication::translate("thriftwidget", "\346\220\234\347\264\242API", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("thriftwidget", "\345\216\206\345\217\262\350\256\260\345\275\225", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("thriftwidget", "\346\216\245\345\217\243\345\210\227\350\241\250", nullptr));
        label_2->setText(QApplication::translate("thriftwidget", "\344\270\273\346\234\272", nullptr));
        lineEdit_host->setText(QApplication::translate("thriftwidget", "172.16.8.154", nullptr));
        lineEdit_host->setPlaceholderText(QApplication::translate("thriftwidget", "172.16.8.154", nullptr));
        label->setText(QApplication::translate("thriftwidget", "\347\253\257\345\217\243", nullptr));
        lineEdit_port->setText(QApplication::translate("thriftwidget", "9090", nullptr));
        lineEdit_port->setPlaceholderText(QApplication::translate("thriftwidget", "9090", nullptr));
        toolButton_test->setText(QApplication::translate("thriftwidget", "\346\265\213\350\257\225\345\234\260\345\235\200", nullptr));
        label_3->setText(QApplication::translate("thriftwidget", "\346\216\245\345\217\243", nullptr));
        lineEdit_funcName->setText(QApplication::translate("thriftwidget", "yourMethod2", nullptr));
        lineEdit_funcName->setPlaceholderText(QApplication::translate("thriftwidget", "yourMethod2", nullptr));
        comboBox->setItemText(0, QApplication::translate("thriftwidget", "TBinaryProtocol", nullptr));

        toolButton->setText(QApplication::translate("thriftwidget", "\350\257\267\346\261\202\346\216\245\345\217\243", nullptr));
        label_4->setText(QApplication::translate("thriftwidget", "\345\205\245\345\217\202", nullptr));
        toolButton_show_thrift_info->setText(QString());
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(2, QApplication::translate("thriftwidget", "\345\217\202\346\225\260\345\200\274", nullptr));
        ___qtreewidgetitem->setText(1, QApplication::translate("thriftwidget", "\345\217\202\346\225\260\347\261\273\345\236\213", nullptr));
        ___qtreewidgetitem->setText(0, QApplication::translate("thriftwidget", "\345\217\202\346\225\260\345\220\215", nullptr));
        label_6->setText(QString());
        textEdit_2->setHtml(QApplication::translate("thriftwidget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'OPPOSans B'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#505050;\"> thrift\345\215\217\350\256\256\345\200\274\350\257\264\346\230\216</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; color:#505050;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#505050;\">\344\270\200. \346\266\210\346\201\257\347\261\273\345\236\213\357\274\2104\345\255\227\350\212\202\357\274\211\357\274\232"
                        "</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#505050;\">    1. CALL\357\274\21080010001\357\274\211\357\274\214\350\260\203\347\224\250\346\226\271\346\263\225\357\274\214\345\271\266\345\270\214\346\234\233\350\216\267\345\217\226\350\277\224\345\233\236\346\266\210\346\201\257</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#505050;\">    2. REPLY\357\274\21080010002\357\274\211\357\274\214\346\235\245\350\207\252\346\234\215\345\212\241\347\253\257\350\277\224\345\233\236\347\232\204\346\266\210\346\201\257</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#505050;\">    3. EXCEPTION\357\274\21080010003\357\274\211\357\274\214\346\234\215\345\212\241\345\231\250\345\244\204\347\220\206"
                        "\350\257\267\346\261\202\346\227\266\345\207\272\347\216\260\345\274\202\345\270\270</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#505050;\">    4. ONEWAY\357\274\21080010004\357\274\211\357\274\214\345\215\225\345\220\221\350\257\267\346\261\202\357\274\214\344\270\215\351\234\200\350\246\201\350\277\224\345\233\236\346\225\260\346\215\256</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; color:#505050;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#505050;\">\344\272\214. \346\226\271\346\263\225\345\220\215\351\225\277\345\272\246\357\274\2104\345\255\227\350\212\202\357\274\211</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px"
                        "; margin-right:0px; -qt-block-indent:0; text-indent:0px; color:#505050;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#505050;\">\344\270\211. \346\226\271\346\263\225\345\220\215\357\274\210\344\270\215\345\233\272\345\256\232\345\255\227\350\212\202\357\274\214\346\240\271\346\215\256\346\226\271\346\263\225\345\220\215\351\225\277\345\272\246\350\216\267\345\217\226\357\274\211</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; color:#505050;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#505050;\">\345\233\233. \346\265\201\346\260\264\345\217\267\357\274\2104\345\255\227\350\212\202\357\274\211</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0p"
                        "x; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; color:#505050;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#505050;\">\344\272\224. \345\237\272\347\241\200\346\225\260\346\215\256\347\261\273\345\236\213\357\274\214\347\261\273\345\236\213\357\274\2101\345\255\227\350\212\202\357\274\211\357\274\214\346\225\260\346\215\256\345\272\217\345\217\267\357\274\2102\345\255\227\350\212\202\357\274\211\357\274\214\346\225\260\346\215\256\345\200\274\357\274\210\346\240\271\346\215\256\346\225\260\346\215\256\347\261\273\345\236\213\350\200\214\345\256\232\357\274\211</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#505050;\">    1. bool\347\261\273\345\236\213\357\274\214\347\261\273\345\236\2132\357\274\214\345\200\274\344\270\2721\344\270\252\345\255\227\350\212\202</s"
                        "pan></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#505050;\">    2. byte\347\261\273\345\236\213\357\274\214\347\261\273\345\236\2133\357\274\214\345\200\274\344\270\2721\344\270\252\345\255\227\350\212\202</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#505050;\">    3. i16\347\261\273\345\236\213\357\274\214\347\261\273\345\236\2136\357\274\214\345\200\274\344\270\2722\344\270\252\345\255\227\350\212\202</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#505050;\">    3. i32\347\261\273\345\236\213\357\274\214\347\261\273\345\236\2138\357\274\214\345\200\274\344\270\2724\344\270\252\345\255\227\350\212\202</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-r"
                        "ight:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#505050;\">    4. i64\347\261\273\345\236\213\357\274\214\347\261\273\345\236\21310\357\274\214\345\200\274\344\270\2728\344\270\252\345\255\227\350\212\202</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#505050;\">    5. double\347\261\273\345\236\213\357\274\214\347\261\273\345\236\2134\357\274\214\345\200\274\344\270\2728\344\270\252\345\255\227\350\212\202</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; color:#505050;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#505050;\">\345\205\255. \345\244\215\346\235\202\346\225\260\346\215\256\347\261\273\345\236\213\357\274\214\347\261\273\345\236\213\357\274\2101\345"
                        "\255\227\350\212\202\357\274\211\357\274\214\346\225\260\346\215\256\345\272\217\345\217\267\357\274\2102\345\255\227\350\212\202\357\274\211</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#505050;\">    1. string\347\261\273\345\236\213\357\274\214\347\261\273\345\236\21311\357\274\214\345\272\217\345\217\267\345\220\216\346\234\211\344\270\200\344\270\252\345\233\233\345\255\227\350\212\202\347\232\204\346\225\260\346\215\256\351\225\277\345\272\246\357\274\214\346\225\260\346\215\256\347\232\204\345\200\274\346\240\271\346\215\256\351\225\277\345\272\246\350\216\267\345\217\226</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#505050;\">    2. struct\347\261\273\345\236\213\357\274\214\347\261\273\345\236\21312\357\274\214\346\214\211\347\205\247\346\255\243\345\270\270\350\247\243\346\236\220"
                        "\357\274\214\351\201\207\345\210\26000\350\241\250\347\244\272\347\273\223\346\235\237struct</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#505050;\">    3. map\347\261\273\345\236\213\357\274\214\347\261\273\345\236\21313\357\274\214\345\272\217\345\217\267\345\220\216\347\254\254\344\270\200\344\270\252\345\255\227\350\212\202\344\270\272\351\224\256\347\261\273\345\236\213\357\274\214\347\254\254\344\272\214\344\270\252\345\255\227\350\212\202\344\270\272\345\200\274\347\261\273\345\236\213\357\274\214\344\270\200\344\270\252\345\233\233\345\255\227\350\212\202\347\232\204\346\225\260\346\215\256\351\225\277\345\272\246\357\274\214\346\225\260\346\215\256\347\232\204\345\200\274\346\240\271\346\215\256\351\225\277\345\272\246\350\216\267\345\217\226</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" "
                        "color:#505050;\">    4. set\347\261\273\345\236\213\357\274\214\347\261\273\345\236\21314\357\274\214\345\272\217\345\217\267\345\220\216\347\254\254\344\270\200\344\270\252\345\255\227\350\212\202\344\270\272\345\200\274\347\261\273\345\236\213\357\274\214\344\270\200\344\270\252\345\233\233\345\255\227\350\212\202\347\232\204\346\225\260\346\215\256\351\225\277\345\272\246\357\274\214\346\225\260\346\215\256\347\232\204\345\200\274\346\240\271\346\215\256\351\225\277\345\272\246\350\216\267\345\217\226</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#505050;\">    5. list\347\261\273\345\236\213\357\274\214\347\261\273\345\236\21315\357\274\214\345\272\217\345\217\267\345\220\216\347\254\254\344\270\200\344\270\252\345\255\227\350\212\202\344\270\272\345\200\274\347\261\273\345\236\213\357\274\214\344\270\200\344\270\252\345\233\233\345\255\227\350\212\202\347\232\204\346\225\260\346\215\256\351\225\277"
                        "\345\272\246\357\274\214\346\225\260\346\215\256\347\232\204\345\200\274\346\240\271\346\215\256\351\225\277\345\272\246\350\216\267\345\217\226</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; color:#505050;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#505050;\">--------------------------------------------------------</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#505050;\">\344\273\245 i32 yourMethod(1: i32 param) \346\216\245\345\217\243\344\270\272\344\276\213</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; color:#505050;\"><br /></p>\n"
"<p style=\" margin-top:0px; m"
                        "argin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#505050;\">\350\257\267\346\261\202\345\216\237\346\225\260\346\215\256\344\270\272\357\274\232</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#ff0000;\">80 01 00 01</span> <span style=\" color:#3a9d33;\">00 00 00 0a</span> <span style=\" color:#3e58ff;\">79 6f 75 72 4d 65 74 68 6f 64</span> <span style=\" color:#c23134;\">00 00 00 00</span> <span style=\" color:#408876;\">08</span> <span style=\" color:#7c5390;\">00 01</span> <span style=\" color:#8f6f55;\">00 00 00 01</span> <span style=\" color:#a10000;\">00</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-in"
                        "dent:0px;\"><span style=\" color:#505050;\">80 01 00 01 \350\241\250\347\244\272CALL\350\260\203\347\224\250\346\226\271\346\263\225\357\274\214\345\271\266\346\234\237\346\234\233\350\277\224\345\233\236\345\200\274</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; color:#505050;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#505050;\">00 00 00 0a \350\241\250\347\244\272\346\226\271\346\263\225\345\220\215\351\225\277\345\272\246\344\270\27210</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; color:#505050;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#505050;\">79 6f 75 "
                        "72 4d 65 74 68 6f 64 \344\270\272\346\226\271\346\263\225\345\220\215</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; color:#505050;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#505050;\">00 00 00 00 \350\241\250\347\244\272\346\265\201\346\260\264\345\217\267</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; color:#505050;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#505050;\">08 \350\241\250\347\244\272\346\225\260\346\215\256\347\261\273\345\236\213\344\270\272i32</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px;"
                        " margin-right:0px; -qt-block-indent:0; text-indent:0px; color:#505050;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#505050;\">00 01 \350\241\250\347\244\272\345\272\217\345\217\267\344\270\2721</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; color:#505050;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#505050;\">00 00 00 01 \350\241\250\347\244\272\345\200\274\344\270\2721</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; color:#505050;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\""
                        "><span style=\" color:#505050;\">00 \350\241\250\347\244\272\347\273\223\346\235\237</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; color:#505050;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#505050;\">--------------------------------------------------------</span></p></body></html>", nullptr));
        label_7->setText(QApplication::translate("thriftwidget", "\350\257\267\346\261\202\347\273\223\346\236\234", nullptr));
        checkBox_2->setText(QApplication::translate("thriftwidget", "\346\230\276\347\244\272\350\257\267\346\261\202\346\272\220\346\225\260\346\215\256/\347\273\223\346\236\234\346\272\220\346\225\260\346\215\256", nullptr));
        label_time->setText(QApplication::translate("thriftwidget", "\345\223\215\345\272\224\346\227\266\351\227\264\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class thriftwidget: public Ui_thriftwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THRIFTWIDGET_H
