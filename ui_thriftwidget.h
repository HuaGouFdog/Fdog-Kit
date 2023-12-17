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
    QLineEdit *lineEdit;
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
    QToolButton *toolButton_2;
    QSpacerItem *horizontalSpacer_2;
    QWidget *horizontalWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QComboBox *comboBox;
    QLineEdit *lineEdit_funcName;
    QToolButton *toolButton;
    QSpacerItem *horizontalSpacer;
    QSplitter *splitter_2;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_3;
    QSplitter *splitter;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_4;
    QTreeWidget *treeWidget;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_6;
    QTreeWidget *treeWidget_2;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_7;
    QWidget *widget_5;
    QVBoxLayout *verticalLayout_7;
    QTextEdit *textEdit;

    void setupUi(QWidget *thriftwidget)
    {
        if (thriftwidget->objectName().isEmpty())
            thriftwidget->setObjectName(QStringLiteral("thriftwidget"));
        thriftwidget->resize(944, 640);
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
        lineEdit = new QLineEdit(widget_9);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(0, 30));
        lineEdit->setMaximumSize(QSize(16777215, 30));
        lineEdit->setFont(font);
        lineEdit->setStyleSheet(QLatin1String("QLineEdit{\n"
"color:#ced4da;\n"
"border-radius: 14px;\n"
"background-color: rgb(25, 25, 25, 155);\n"
"border: 0px solid rgba(255, 255, 255, 0);\n"
"border-radius: 15px;\n"
"padding-left:10px;\n"
"padding-right:10px;\n"
"}"));

        verticalLayout_3->addWidget(lineEdit);


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
        horizontalLayout_2->setContentsMargins(9, 3, 9, 0);
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

        toolButton_2 = new QToolButton(widget_6);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        toolButton_2->setMinimumSize(QSize(68, 30));
        QFont font2;
        font2.setFamily(QStringLiteral("OPPOSans"));
        font2.setPointSize(10);
        font2.setStyleStrategy(QFont::PreferAntialias);
        toolButton_2->setFont(font2);
        toolButton_2->setStyleSheet(QLatin1String("QToolButton {\n"
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
        icon2.addFile(QStringLiteral(":/lib/node.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon2);
        toolButton_2->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_2->addWidget(toolButton_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget_6);

        horizontalWidget = new QWidget(widget_7);
        horizontalWidget->setObjectName(QStringLiteral("horizontalWidget"));
        horizontalWidget->setMaximumSize(QSize(16777215, 33));
        horizontalWidget->setStyleSheet(QStringLiteral("color:#ced4da;"));
        horizontalLayout = new QHBoxLayout(horizontalWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, -1, 0);
        label_3 = new QLabel(horizontalWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(40, 16777215));
        label_3->setFont(font);

        horizontalLayout->addWidget(label_3);

        comboBox = new QComboBox(horizontalWidget);
        comboBox->addItem(QString());
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setMinimumSize(QSize(150, 30));
        comboBox->setFont(font);
        comboBox->setStyleSheet(QLatin1String("QComboBox{\n"
"	color:#ffffff;\n"
"	border:1px solid #8a8a8a;\n"
"	color: rgb(138, 138, 138);\n"
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
"}"));

        horizontalLayout->addWidget(comboBox);

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

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addWidget(horizontalWidget);

        splitter_2 = new QSplitter(widget_7);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Vertical);
        widget_4 = new QWidget(splitter_2);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        horizontalLayout_3 = new QHBoxLayout(widget_4);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        splitter = new QSplitter(widget_4);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        splitter->setHandleWidth(1);
        widget = new QWidget(splitter);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(0, 30));
        label_4->setMaximumSize(QSize(16777215, 30));
        label_4->setFont(font);
        label_4->setStyleSheet(QLatin1String("background-color: rgb(54, 81, 97);\n"
"color: rgb(255, 255, 255);\n"
"padding-left:2px;\n"
"padding-right:10px;"));

        verticalLayout_2->addWidget(label_4);

        treeWidget = new QTreeWidget(widget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setFont(3, font);
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
"	border:0px solid #242424;\n"
"	\n"
"	color: rgb(0, 0, 0);\n"
"}\n"
"\n"
"QComboBox{\n"
"font: 10pt \"OPPOSans B\";\n"
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
        widget_3 = new QWidget(splitter);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        verticalLayout_4 = new QVBoxLayout(widget_3);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(widget_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(0, 30));
        label_6->setMaximumSize(QSize(16777215, 30));
        label_6->setFont(font);
        label_6->setStyleSheet(QLatin1String("background-color: rgb(54, 81, 97);\n"
"color: rgb(255, 255, 255);\n"
"padding-left:2px;\n"
"padding-right:10px;"));

        verticalLayout_4->addWidget(label_6);

        treeWidget_2 = new QTreeWidget(widget_3);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem();
        __qtreewidgetitem1->setFont(3, font);
        __qtreewidgetitem1->setFont(2, font);
        __qtreewidgetitem1->setFont(1, font);
        __qtreewidgetitem1->setFont(0, font);
        treeWidget_2->setHeaderItem(__qtreewidgetitem1);
        treeWidget_2->setObjectName(QStringLiteral("treeWidget_2"));
        treeWidget_2->setFont(font);
        treeWidget_2->setStyleSheet(QLatin1String("QLineEdit{\n"
"color: rgb(0, 0, 0);\n"
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
"	border:0px solid #242424;\n"
"}\n"
""));
        treeWidget_2->setIndentation(20);
        treeWidget_2->setUniformRowHeights(true);
        treeWidget_2->setSortingEnabled(false);
        treeWidget_2->setAnimated(false);
        treeWidget_2->header()->setVisible(true);
        treeWidget_2->header()->setDefaultSectionSize(100);
        treeWidget_2->header()->setMinimumSectionSize(20);
        treeWidget_2->header()->setStretchLastSection(true);

        verticalLayout_4->addWidget(treeWidget_2);

        splitter->addWidget(widget_3);

        horizontalLayout_3->addWidget(splitter);

        splitter_2->addWidget(widget_4);
        widget_2 = new QWidget(splitter_2);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        verticalLayout_6 = new QVBoxLayout(widget_2);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(widget_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMinimumSize(QSize(0, 30));
        label_7->setMaximumSize(QSize(16777215, 30));
        label_7->setFont(font);
        label_7->setStyleSheet(QLatin1String("background-color: rgb(54, 81, 97);\n"
"color: rgb(255, 255, 255);\n"
"padding-left:2px;\n"
"padding-right:10px;"));

        verticalLayout_6->addWidget(label_7);

        widget_5 = new QWidget(widget_2);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setMinimumSize(QSize(0, 100));
        QFont font3;
        font3.setStyleStrategy(QFont::PreferDefault);
        widget_5->setFont(font3);
        verticalLayout_7 = new QVBoxLayout(widget_5);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        textEdit = new QTextEdit(widget_5);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setFont(font);
        textEdit->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        textEdit->setStyleSheet(QLatin1String("QTextEdit{\n"
"color: rgb(0, 0, 0);\n"
"	background-color: rgb(255, 255, 255);\n"
"border: 1px solid rgba(255, 255, 255, 0);\n"
"border-radius: 0px;\n"
"padding-left:10px;\n"
"padding-right:10px;\n"
"}"));

        verticalLayout_7->addWidget(textEdit);


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
        lineEdit->setPlaceholderText(QApplication::translate("thriftwidget", "\346\220\234\347\264\242API", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("thriftwidget", "\345\216\206\345\217\262\350\256\260\345\275\225", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("thriftwidget", "\346\216\245\345\217\243\345\210\227\350\241\250", nullptr));
        label_2->setText(QApplication::translate("thriftwidget", "\344\270\273\346\234\272", nullptr));
        lineEdit_host->setText(QApplication::translate("thriftwidget", "172.16.8.154", nullptr));
        lineEdit_host->setPlaceholderText(QApplication::translate("thriftwidget", "172.16.8.154", nullptr));
        label->setText(QApplication::translate("thriftwidget", "\347\253\257\345\217\243", nullptr));
        lineEdit_port->setText(QApplication::translate("thriftwidget", "9090", nullptr));
        lineEdit_port->setPlaceholderText(QApplication::translate("thriftwidget", "9090", nullptr));
        toolButton_2->setText(QApplication::translate("thriftwidget", "\346\265\213\350\257\225\345\234\260\345\235\200\345\217\257\350\276\276", nullptr));
        label_3->setText(QApplication::translate("thriftwidget", "\346\216\245\345\217\243", nullptr));
        comboBox->setItemText(0, QApplication::translate("thriftwidget", "TBinaryProtocol", nullptr));

        lineEdit_funcName->setText(QApplication::translate("thriftwidget", "yourMethod2", nullptr));
        lineEdit_funcName->setPlaceholderText(QApplication::translate("thriftwidget", "yourMethod2", nullptr));
        toolButton->setText(QApplication::translate("thriftwidget", "\350\257\267\346\261\202\346\216\245\345\217\243", nullptr));
        label_4->setText(QApplication::translate("thriftwidget", "\345\205\245\345\217\202", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(3, QApplication::translate("thriftwidget", "\345\217\202\346\225\260\346\217\217\350\277\260", nullptr));
        ___qtreewidgetitem->setText(2, QApplication::translate("thriftwidget", "\345\217\202\346\225\260\345\200\274", nullptr));
        ___qtreewidgetitem->setText(1, QApplication::translate("thriftwidget", "\345\217\202\346\225\260\347\261\273\345\236\213", nullptr));
        ___qtreewidgetitem->setText(0, QApplication::translate("thriftwidget", "\345\217\202\346\225\260\345\220\215", nullptr));
        label_6->setText(QApplication::translate("thriftwidget", "\345\207\272\345\217\202", nullptr));
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidget_2->headerItem();
        ___qtreewidgetitem1->setText(3, QApplication::translate("thriftwidget", "\345\217\202\346\225\260\346\217\217\350\277\260", nullptr));
        ___qtreewidgetitem1->setText(2, QApplication::translate("thriftwidget", "\345\217\202\346\225\260\345\200\274", nullptr));
        ___qtreewidgetitem1->setText(1, QApplication::translate("thriftwidget", "\345\217\202\346\225\260\347\261\273\345\236\213", nullptr));
        ___qtreewidgetitem1->setText(0, QApplication::translate("thriftwidget", "\345\217\202\346\225\260\345\220\215", nullptr));
        label_7->setText(QApplication::translate("thriftwidget", "\350\257\267\346\261\202\347\273\223\346\236\234", nullptr));
    } // retranslateUi

};

namespace Ui {
    class thriftwidget: public Ui_thriftwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THRIFTWIDGET_H
