/********************************************************************************
** Form generated from reading UI file 'zookeepermanagewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZOOKEEPERMANAGEWIDGET_H
#define UI_ZOOKEEPERMANAGEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_zookeepermanagewidget
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *widget_left;
    QVBoxLayout *verticalLayout_6;
    QWidget *widget_side_top;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_zk_icon;
    QToolButton *toolButton_newCreate;
    QLineEdit *lineEdit_find;
    QWidget *widget_side_body;
    QVBoxLayout *verticalLayout_3;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QWidget *widget_right;
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer_3;
    QLabel *label;
    QToolButton *toolButton;
    QSpacerItem *verticalSpacer_2;
    QWidget *page;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QWidget *verticalWidget;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *verticalSpacer_5;
    QWidget *horizontalWidget;
    QGridLayout *gridLayout;
    QLabel *label_port_zk;
    QLineEdit *lineEdit_port_zk_data;
    QLineEdit *lineEdit_remark_zk;
    QLabel *label_remark_zk;
    QLabel *label_host_zk;
    QLineEdit *lineEdit_host_zk_data;
    QLabel *label_timeout_zk;
    QLineEdit *lineEdit_timeout_zk;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QToolButton *toolButton_connect;
    QToolButton *toolButton_save;
    QToolButton *toolButton_close;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *zookeepermanagewidget)
    {
        if (zookeepermanagewidget->objectName().isEmpty())
            zookeepermanagewidget->setObjectName(QStringLiteral("zookeepermanagewidget"));
        zookeepermanagewidget->resize(853, 520);
        horizontalLayout = new QHBoxLayout(zookeepermanagewidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widget_left = new QWidget(zookeepermanagewidget);
        widget_left->setObjectName(QStringLiteral("widget_left"));
        widget_left->setMinimumSize(QSize(230, 0));
        widget_left->setMaximumSize(QSize(230, 16777215));
        QFont font;
        font.setFamily(QStringLiteral("OPPOSans B"));
        widget_left->setFont(font);
        widget_left->setStyleSheet(QString::fromUtf8("#widget_left{\n"
"border-image: url(:/lib/back2.png);\n"
"border-right:0px solid rgba(108, 117, 125, 65); \n"
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
"    subcontrol-origin: "
                        "margin;\n"
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
        verticalLayout_6 = new QVBoxLayout(widget_left);
        verticalLayout_6->setSpacing(10);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(25, 0, 25, 0);
        widget_side_top = new QWidget(widget_left);
        widget_side_top->setObjectName(QStringLiteral("widget_side_top"));
        widget_side_top->setMinimumSize(QSize(0, 70));
        widget_side_top->setMaximumSize(QSize(16777215, 70));
        horizontalLayout_4 = new QHBoxLayout(widget_side_top);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 5, 11, 5);
        label_zk_icon = new QLabel(widget_side_top);
        label_zk_icon->setObjectName(QStringLiteral("label_zk_icon"));
        label_zk_icon->setStyleSheet(QStringLiteral("image: url(:/lib/Zookeeper21.png);"));

        horizontalLayout_4->addWidget(label_zk_icon);

        toolButton_newCreate = new QToolButton(widget_side_top);
        toolButton_newCreate->setObjectName(QStringLiteral("toolButton_newCreate"));
        toolButton_newCreate->setMinimumSize(QSize(125, 30));
        QFont font1;
        font1.setFamily(QStringLiteral("OPPOSans B"));
        font1.setPointSize(10);
        font1.setStyleStrategy(QFont::PreferAntialias);
        toolButton_newCreate->setFont(font1);
        toolButton_newCreate->setStyleSheet(QLatin1String("QToolButton {\n"
"	color: rgb(255, 255, 255);\n"
"	\n"
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
        QIcon icon;
        icon.addFile(QStringLiteral(":/lib/Zookeeper2.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_newCreate->setIcon(icon);
        toolButton_newCreate->setToolButtonStyle(Qt::ToolButtonTextOnly);

        horizontalLayout_4->addWidget(toolButton_newCreate);


        verticalLayout_6->addWidget(widget_side_top);

        lineEdit_find = new QLineEdit(widget_left);
        lineEdit_find->setObjectName(QStringLiteral("lineEdit_find"));
        lineEdit_find->setMinimumSize(QSize(180, 30));
        lineEdit_find->setMaximumSize(QSize(200, 30));
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

        verticalLayout_6->addWidget(lineEdit_find);

        widget_side_body = new QWidget(widget_left);
        widget_side_body->setObjectName(QStringLiteral("widget_side_body"));
        verticalLayout_3 = new QVBoxLayout(widget_side_body);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(widget_side_body);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setStyleSheet(QString::fromUtf8("QScrollArea{\n"
"	border: none;\n"
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
"  "
                        "  height: 0px;\n"
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
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 180, 400));
        scrollAreaWidgetContents->setStyleSheet(QLatin1String("QToolButton {\n"
"	font: 10pt \"OPPOSans B\";\n"
"    qproperty-iconSize: 22px 22px;\n"
"	background-color: rgba(255, 255, 255, 20);\n"
"	border: none;\n"
"	border-radius:3px;\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QToolButton::menu-indicator { \n"
"	image: None;\n"
"}\n"
"\n"
"QToolButton:hover {\n"
"	border-radius:3px;\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgba(255, 255, 255, 50);\n"
"	border: none;\n"
"}\n"
"\n"
" \n"
"QToolButton:checked {\n"
"	border-radius:3px;\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(21, 21, 21);\n"
"	border: none;\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 309, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_3->addWidget(scrollArea);


        verticalLayout_6->addWidget(widget_side_body);


        horizontalLayout->addWidget(widget_left);

        widget_right = new QWidget(zookeepermanagewidget);
        widget_right->setObjectName(QStringLiteral("widget_right"));
        verticalLayout = new QVBoxLayout(widget_right);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(widget_right);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        verticalLayout_4 = new QVBoxLayout(page_2);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalSpacer_3 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_3);

        label = new QLabel(page_2);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 104));
        label->setStyleSheet(QStringLiteral("image: url(:/lib/icon500.png);"));

        verticalLayout_4->addWidget(label);

        toolButton = new QToolButton(page_2);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolButton->sizePolicy().hasHeightForWidth());
        toolButton->setSizePolicy(sizePolicy);
        QFont font3;
        font3.setFamily(QStringLiteral("OPPOSans B"));
        font3.setPointSize(12);
        font3.setUnderline(true);
        font3.setStyleStrategy(QFont::PreferAntialias);
        toolButton->setFont(font3);
        toolButton->setStyleSheet(QLatin1String("QToolButton {\n"
"	color: rgb(242, 245, 255, 50);\n"
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
"	color: rgb(242, 245, 255, 50);\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"	border: none;\n"
"}"));

        verticalLayout_4->addWidget(toolButton);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);

        verticalLayout_4->setStretch(0, 1);
        verticalLayout_4->setStretch(1, 1);
        verticalLayout_4->setStretch(2, 1);
        verticalLayout_4->setStretch(3, 4);
        stackedWidget->addWidget(page_2);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        horizontalLayout_3 = new QHBoxLayout(page);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        verticalWidget = new QWidget(page);
        verticalWidget->setObjectName(QStringLiteral("verticalWidget"));
        verticalWidget->setMaximumSize(QSize(350, 16777215));
        verticalLayout_5 = new QVBoxLayout(verticalWidget);
        verticalLayout_5->setSpacing(33);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_5);

        horizontalWidget = new QWidget(verticalWidget);
        horizontalWidget->setObjectName(QStringLiteral("horizontalWidget"));
        horizontalWidget->setMaximumSize(QSize(16777215, 230));
        gridLayout = new QGridLayout(horizontalWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(10);
        gridLayout->setVerticalSpacing(30);
        gridLayout->setContentsMargins(-1, 10, -1, 10);
        label_port_zk = new QLabel(horizontalWidget);
        label_port_zk->setObjectName(QStringLiteral("label_port_zk"));
        QFont font4;
        font4.setFamily(QStringLiteral("OPPOSans B"));
        font4.setPointSize(10);
        label_port_zk->setFont(font4);

        gridLayout->addWidget(label_port_zk, 1, 0, 1, 1);

        lineEdit_port_zk_data = new QLineEdit(horizontalWidget);
        lineEdit_port_zk_data->setObjectName(QStringLiteral("lineEdit_port_zk_data"));
        lineEdit_port_zk_data->setMinimumSize(QSize(0, 35));
        lineEdit_port_zk_data->setMaximumSize(QSize(300, 28));
        lineEdit_port_zk_data->setFont(font4);
        lineEdit_port_zk_data->setStyleSheet(QLatin1String("background-color: rgb(25, 25, 25, 155);\n"
"border-radius: 5px;\n"
"padding-left:10px;\n"
"padding-right:10px;"));

        gridLayout->addWidget(lineEdit_port_zk_data, 1, 1, 1, 1);

        lineEdit_remark_zk = new QLineEdit(horizontalWidget);
        lineEdit_remark_zk->setObjectName(QStringLiteral("lineEdit_remark_zk"));
        lineEdit_remark_zk->setMinimumSize(QSize(0, 35));
        lineEdit_remark_zk->setMaximumSize(QSize(300, 28));
        lineEdit_remark_zk->setFont(font4);
        lineEdit_remark_zk->setStyleSheet(QLatin1String("background-color: rgb(25, 25, 25, 155);\n"
"border-radius: 5px;\n"
"padding-left:10px;\n"
"padding-right:10px;"));

        gridLayout->addWidget(lineEdit_remark_zk, 3, 1, 1, 1);

        label_remark_zk = new QLabel(horizontalWidget);
        label_remark_zk->setObjectName(QStringLiteral("label_remark_zk"));
        label_remark_zk->setFont(font4);

        gridLayout->addWidget(label_remark_zk, 3, 0, 1, 1);

        label_host_zk = new QLabel(horizontalWidget);
        label_host_zk->setObjectName(QStringLiteral("label_host_zk"));
        label_host_zk->setFont(font4);

        gridLayout->addWidget(label_host_zk, 0, 0, 1, 1);

        lineEdit_host_zk_data = new QLineEdit(horizontalWidget);
        lineEdit_host_zk_data->setObjectName(QStringLiteral("lineEdit_host_zk_data"));
        lineEdit_host_zk_data->setMinimumSize(QSize(0, 35));
        lineEdit_host_zk_data->setMaximumSize(QSize(300, 28));
        lineEdit_host_zk_data->setFont(font4);
        lineEdit_host_zk_data->setStyleSheet(QLatin1String("background-color: rgb(25, 25, 25, 155);\n"
"border-radius: 5px;\n"
"padding-left:10px;\n"
"padding-right:10px;"));

        gridLayout->addWidget(lineEdit_host_zk_data, 0, 1, 1, 1);

        label_timeout_zk = new QLabel(horizontalWidget);
        label_timeout_zk->setObjectName(QStringLiteral("label_timeout_zk"));
        label_timeout_zk->setFont(font4);

        gridLayout->addWidget(label_timeout_zk, 2, 0, 1, 1);

        lineEdit_timeout_zk = new QLineEdit(horizontalWidget);
        lineEdit_timeout_zk->setObjectName(QStringLiteral("lineEdit_timeout_zk"));
        lineEdit_timeout_zk->setMinimumSize(QSize(0, 35));
        lineEdit_timeout_zk->setMaximumSize(QSize(300, 28));
        lineEdit_timeout_zk->setFont(font4);
        lineEdit_timeout_zk->setStyleSheet(QLatin1String("background-color: rgb(25, 25, 25, 155);\n"
"border-radius: 5px;\n"
"padding-left:10px;\n"
"padding-right:10px;"));

        gridLayout->addWidget(lineEdit_timeout_zk, 2, 1, 1, 1);


        verticalLayout_5->addWidget(horizontalWidget);

        widget_3 = new QWidget(verticalWidget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMaximumSize(QSize(16777215, 50));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setSpacing(10);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 2, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        toolButton_connect = new QToolButton(widget_3);
        toolButton_connect->setObjectName(QStringLiteral("toolButton_connect"));
        toolButton_connect->setMinimumSize(QSize(70, 28));
        toolButton_connect->setMaximumSize(QSize(70, 28));
        toolButton_connect->setFont(font1);
        toolButton_connect->setStyleSheet(QLatin1String("QToolButton {\n"
"	color: rgb(26, 26, 26);\n"
"	background-color: rgb(113, 212, 219);\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QToolButton::menu-indicator { \n"
"	image: None;\n"
"}\n"
"\n"
" \n"
"QToolButton:hover {\n"
"	color: rgb(26, 26, 26);\n"
"	background-color: rgb(113, 212, 219);\n"
"}"));

        horizontalLayout_2->addWidget(toolButton_connect);

        toolButton_save = new QToolButton(widget_3);
        toolButton_save->setObjectName(QStringLiteral("toolButton_save"));
        toolButton_save->setMinimumSize(QSize(70, 28));
        toolButton_save->setMaximumSize(QSize(70, 28));
        toolButton_save->setFont(font1);
        toolButton_save->setStyleSheet(QLatin1String("QToolButton {\n"
"	color: rgb(255, 255, 255);\n"
"	\n"
"	background-color: rgb(67, 67, 67);\n"
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
"	background-color: rgb(67, 67, 67);\n"
"}"));

        horizontalLayout_2->addWidget(toolButton_save);

        toolButton_close = new QToolButton(widget_3);
        toolButton_close->setObjectName(QStringLiteral("toolButton_close"));
        toolButton_close->setMinimumSize(QSize(70, 28));
        toolButton_close->setMaximumSize(QSize(70, 28));
        toolButton_close->setFont(font1);
        toolButton_close->setStyleSheet(QLatin1String("QToolButton {\n"
"	color: rgb(255, 255, 255);\n"
"	\n"
"	background-color: rgb(67, 67, 67);\n"
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
"	background-color: rgb(67, 67, 67);\n"
"}"));

        horizontalLayout_2->addWidget(toolButton_close);


        verticalLayout_5->addWidget(widget_3);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_4);

        verticalLayout_5->setStretch(0, 1);
        verticalLayout_5->setStretch(1, 1);
        verticalLayout_5->setStretch(2, 1);
        verticalLayout_5->setStretch(3, 5);

        horizontalLayout_3->addWidget(verticalWidget);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 8);
        horizontalLayout_3->setStretch(2, 1);
        stackedWidget->addWidget(page);

        verticalLayout->addWidget(stackedWidget);


        horizontalLayout->addWidget(widget_right);


        retranslateUi(zookeepermanagewidget);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(zookeepermanagewidget);
    } // setupUi

    void retranslateUi(QWidget *zookeepermanagewidget)
    {
        zookeepermanagewidget->setWindowTitle(QApplication::translate("zookeepermanagewidget", "Form", nullptr));
        label_zk_icon->setText(QString());
        toolButton_newCreate->setText(QApplication::translate("zookeepermanagewidget", "\346\226\260\345\273\272\350\277\236\346\216\245", nullptr));
        lineEdit_find->setPlaceholderText(QApplication::translate("zookeepermanagewidget", "\346\220\234\347\264\242\350\277\236\346\216\245", nullptr));
        label->setText(QString());
        toolButton->setText(QApplication::translate("zookeepermanagewidget", "https://github.com/HuaGouFdog/Fdog-Kit", nullptr));
        label_port_zk->setText(QApplication::translate("zookeepermanagewidget", "\347\253\257\345\217\243", nullptr));
        lineEdit_port_zk_data->setText(QApplication::translate("zookeepermanagewidget", "11100", nullptr));
        lineEdit_port_zk_data->setPlaceholderText(QApplication::translate("zookeepermanagewidget", "22", nullptr));
        lineEdit_remark_zk->setText(QString());
        lineEdit_remark_zk->setPlaceholderText(QApplication::translate("zookeepermanagewidget", "\346\265\213\350\257\225", nullptr));
        label_remark_zk->setText(QApplication::translate("zookeepermanagewidget", "\345\244\207\346\263\250", nullptr));
        label_host_zk->setText(QApplication::translate("zookeepermanagewidget", "\344\270\273\346\234\272", nullptr));
        lineEdit_host_zk_data->setText(QApplication::translate("zookeepermanagewidget", "172.16.8.153", nullptr));
        lineEdit_host_zk_data->setPlaceholderText(QApplication::translate("zookeepermanagewidget", "127.0.0.1", nullptr));
        label_timeout_zk->setText(QApplication::translate("zookeepermanagewidget", "\350\266\205\346\227\266\346\227\266\351\227\264", nullptr));
        lineEdit_timeout_zk->setText(QApplication::translate("zookeepermanagewidget", "5000", nullptr));
        lineEdit_timeout_zk->setPlaceholderText(QApplication::translate("zookeepermanagewidget", "22", nullptr));
        toolButton_connect->setText(QApplication::translate("zookeepermanagewidget", "\350\277\236\346\216\245", nullptr));
        toolButton_save->setText(QApplication::translate("zookeepermanagewidget", "\344\277\235\345\255\230", nullptr));
        toolButton_close->setText(QApplication::translate("zookeepermanagewidget", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class zookeepermanagewidget: public Ui_zookeepermanagewidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZOOKEEPERMANAGEWIDGET_H
