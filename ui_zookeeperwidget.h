/********************************************************************************
** Form generated from reading UI file 'zookeeperwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZOOKEEPERWIDGET_H
#define UI_ZOOKEEPERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_zookeeperwidget
{
public:
    QHBoxLayout *horizontalLayout_5;
    QWidget *widget_left;
    QVBoxLayout *verticalLayout_6;
    QWidget *widget_9;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *lineEdit_find;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label;
    QToolButton *toolButton_3;
    QWidget *widget_create_zk;
    QGridLayout *gridLayout_2;
    QLabel *label_host_zk;
    QLineEdit *lineEdit_host_zk_data;
    QLabel *label_port_zk;
    QLineEdit *lineEdit_port_zk_data;
    QToolButton *toolButton_save;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_8;
    QToolButton *toolButton_2;
    QToolButton *toolButton_4;
    QToolButton *toolButton_5;
    QToolButton *toolButton_6;
    QSpacerItem *verticalSpacer;
    QSplitter *splitter;
    QWidget *verticalWidget_1_l;
    QVBoxLayout *verticalLayout_9;
    QWidget *horizontalWidget_1_1_l;
    QHBoxLayout *horizontalLayout_2;
    QWidget *horizontalWidget_1_2_l;
    QHBoxLayout *horizontalLayout;
    QLabel *label_node;
    QLineEdit *lineEdit_node;
    QSpacerItem *horizontalSpacer;
    QToolButton *toolButton_add;
    QToolButton *toolButton__delete;
    QToolButton *toolButton_refresh;
    QToolButton *toolButton_unfold;
    QWidget *horizontalWidget_1_3_l;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEdit_search;
    QToolButton *toolButton;
    QWidget *verticalWidget_1_4_l;
    QVBoxLayout *verticalLayout_2;
    QTreeWidget *treeWidget;
    QWidget *verticalWidget_1_r;
    QVBoxLayout *verticalLayout;
    QWidget *gridWidget_1_1_r;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_pzxid;
    QLineEdit *lineEdit_mzxid;
    QLineEdit *lineEdit_aversion;
    QLineEdit *lineEdit_version;
    QLabel *label_aversion;
    QLineEdit *lineEdit_cversion;
    QLabel *label_cversion;
    QLabel *label_pzxid;
    QLabel *label_mzxid;
    QLabel *label_version;
    QLineEdit *lineEdit_czxid;
    QLabel *label_dataLength;
    QLabel *label_czxid;
    QLineEdit *lineEdit_dataLength;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_numChildren;
    QLabel *label_mtime;
    QLineEdit *lineEdit_mtime;
    QLineEdit *lineEdit_numChildren;
    QLabel *label_ctime;
    QLineEdit *lineEdit_ctime;
    QLabel *label_ephemeralOwner;
    QLineEdit *lineEdit_ephemeralOwner;
    QWidget *widget_1_2_r;
    QVBoxLayout *verticalLayout_7;
    QWidget *horizontalWidget_1_2_1_r;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_node_create;
    QLineEdit *lineEdit_node_create;
    QSpacerItem *horizontalSpacer_6;
    QWidget *horizontalWidget_1_2_2_r;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_node_type;
    QComboBox *comboBox_node_type;
    QSpacerItem *horizontalSpacer_4;
    QWidget *horizontalWidget_1_2_3_r;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_node_acl;
    QComboBox *comboBox_node_acl;
    QSpacerItem *horizontalSpacer_5;
    QWidget *horizontalWidget_1_2_4_r;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_data;
    QWidget *verticalWidget_1_2_5_r;
    QVBoxLayout *verticalLayout_5;
    QWidget *verticalWidget_1_2_5_2_r;
    QVBoxLayout *verticalLayout_4;
    QTextEdit *textEdit_data;
    QWidget *horizontalWidget_1_2_5_1r;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_data_type;
    QToolButton *toolButton_copy_data;
    QSpacerItem *horizontalSpacer_2;
    QToolButton *toolButton_createData;
    QToolButton *toolButton_saveData;

    void setupUi(QWidget *zookeeperwidget)
    {
        if (zookeeperwidget->objectName().isEmpty())
            zookeeperwidget->setObjectName(QStringLiteral("zookeeperwidget"));
        zookeeperwidget->resize(1141, 654);
        zookeeperwidget->setMinimumSize(QSize(0, 0));
        zookeeperwidget->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setFamily(QStringLiteral("OPPOSans"));
        font.setPointSize(10);
        zookeeperwidget->setFont(font);
        zookeeperwidget->setStyleSheet(QLatin1String("QLineEdit{\n"
"    border-style:outset\n"
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
"    /*margin-right: 10px;*/\n"
"}"));
        horizontalLayout_5 = new QHBoxLayout(zookeeperwidget);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        widget_left = new QWidget(zookeeperwidget);
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
        verticalLayout_6 = new QVBoxLayout(widget_left);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(9, 9, 9, 0);
        widget_9 = new QWidget(widget_left);
        widget_9->setObjectName(QStringLiteral("widget_9"));
        widget_9->setMaximumSize(QSize(16777215, 40));
        horizontalLayout_6 = new QHBoxLayout(widget_9);
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 5, 0, 5);
        lineEdit_find = new QLineEdit(widget_9);
        lineEdit_find->setObjectName(QStringLiteral("lineEdit_find"));
        lineEdit_find->setMinimumSize(QSize(0, 30));
        lineEdit_find->setMaximumSize(QSize(16777215, 30));
        QFont font2;
        font2.setFamily(QStringLiteral("OPPOSans B"));
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

        horizontalLayout_6->addWidget(lineEdit_find);


        verticalLayout_6->addWidget(widget_9);

        widget = new QWidget(widget_left);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMinimumSize(QSize(0, 20));
        horizontalLayout_11 = new QHBoxLayout(widget_2);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 2, 0, 2);
        label = new QLabel(widget_2);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font2);

        horizontalLayout_11->addWidget(label);

        toolButton_3 = new QToolButton(widget_2);
        toolButton_3->setObjectName(QStringLiteral("toolButton_3"));
        toolButton_3->setMinimumSize(QSize(0, 15));
        toolButton_3->setStyleSheet(QLatin1String("QToolButton {\n"
"	color: rgb(255, 255, 255);\n"
"	\n"
"	background-color: rgba(255, 255, 255, 0);\n"
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
"	background-color: rgba(255, 255, 255, 0);\n"
"}"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/lib/add1.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_3->setIcon(icon);
        toolButton_3->setIconSize(QSize(13, 13));

        horizontalLayout_11->addWidget(toolButton_3);


        verticalLayout_3->addWidget(widget_2);

        widget_create_zk = new QWidget(widget);
        widget_create_zk->setObjectName(QStringLiteral("widget_create_zk"));
        widget_create_zk->setMinimumSize(QSize(0, 110));
        widget_create_zk->setMaximumSize(QSize(16777215, 110));
        widget_create_zk->setStyleSheet(QLatin1String("#widget_create_zk{\n"
"border-top:2px solid rgba(108, 117, 125, 65); \n"
"border-bottom:2px solid rgba(108, 117, 125, 65); \n"
"}"));
        gridLayout_2 = new QGridLayout(widget_create_zk);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(9);
        gridLayout_2->setVerticalSpacing(4);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_host_zk = new QLabel(widget_create_zk);
        label_host_zk->setObjectName(QStringLiteral("label_host_zk"));
        QFont font3;
        font3.setFamily(QStringLiteral("OPPOSans B"));
        font3.setPointSize(10);
        label_host_zk->setFont(font3);

        gridLayout_2->addWidget(label_host_zk, 0, 0, 1, 1);

        lineEdit_host_zk_data = new QLineEdit(widget_create_zk);
        lineEdit_host_zk_data->setObjectName(QStringLiteral("lineEdit_host_zk_data"));
        lineEdit_host_zk_data->setMinimumSize(QSize(0, 28));
        lineEdit_host_zk_data->setMaximumSize(QSize(16777215, 28));
        lineEdit_host_zk_data->setFont(font3);
        lineEdit_host_zk_data->setStyleSheet(QLatin1String("background-color: rgb(25, 25, 25, 155);\n"
"border: 1px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding-left:10px;\n"
"padding-right:10px;"));

        gridLayout_2->addWidget(lineEdit_host_zk_data, 0, 1, 1, 2);

        label_port_zk = new QLabel(widget_create_zk);
        label_port_zk->setObjectName(QStringLiteral("label_port_zk"));
        label_port_zk->setFont(font3);

        gridLayout_2->addWidget(label_port_zk, 2, 0, 1, 1);

        lineEdit_port_zk_data = new QLineEdit(widget_create_zk);
        lineEdit_port_zk_data->setObjectName(QStringLiteral("lineEdit_port_zk_data"));
        lineEdit_port_zk_data->setMinimumSize(QSize(0, 28));
        lineEdit_port_zk_data->setMaximumSize(QSize(16777215, 28));
        lineEdit_port_zk_data->setFont(font3);
        lineEdit_port_zk_data->setStyleSheet(QLatin1String("background-color: rgb(25, 25, 25, 155);\n"
"border: 1px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding-left:10px;\n"
"padding-right:10px;"));

        gridLayout_2->addWidget(lineEdit_port_zk_data, 2, 1, 1, 2);

        toolButton_save = new QToolButton(widget_create_zk);
        toolButton_save->setObjectName(QStringLiteral("toolButton_save"));
        toolButton_save->setMinimumSize(QSize(50, 28));
        toolButton_save->setMaximumSize(QSize(50, 28));
        toolButton_save->setFont(font2);
        toolButton_save->setStyleSheet(QLatin1String("QToolButton {\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(255, 95, 95);\n"
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
"	background-color: rgb(255, 95, 95);\n"
"}"));

        gridLayout_2->addWidget(toolButton_save, 3, 2, 1, 1);


        verticalLayout_3->addWidget(widget_create_zk);

        scrollArea = new QScrollArea(widget);
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
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 182, 456));
        scrollAreaWidgetContents->setStyleSheet(QLatin1String("QToolButton {\n"
"	font: 10pt \"OPPOSans B\";\n"
"    qproperty-iconSize: 22px 22px;\n"
"	background-color: rgba(255, 255, 255, 50);\n"
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
"	background-color: rgb(21, 21, 21);\n"
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
        verticalLayout_8 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        toolButton_2 = new QToolButton(scrollAreaWidgetContents);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        toolButton_2->setMinimumSize(QSize(180, 30));
        toolButton_2->setFont(font2);
        toolButton_2->setStyleSheet(QStringLiteral(""));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/lib/node.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon1);
        toolButton_2->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout_8->addWidget(toolButton_2);

        toolButton_4 = new QToolButton(scrollAreaWidgetContents);
        toolButton_4->setObjectName(QStringLiteral("toolButton_4"));
        toolButton_4->setMinimumSize(QSize(180, 30));
        toolButton_4->setFont(font2);
        toolButton_4->setStyleSheet(QStringLiteral(""));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/lib/node2.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_4->setIcon(icon2);
        toolButton_4->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout_8->addWidget(toolButton_4);

        toolButton_5 = new QToolButton(scrollAreaWidgetContents);
        toolButton_5->setObjectName(QStringLiteral("toolButton_5"));
        toolButton_5->setMinimumSize(QSize(180, 30));
        toolButton_5->setFont(font2);
        toolButton_5->setStyleSheet(QStringLiteral(""));
        toolButton_5->setIcon(icon2);
        toolButton_5->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout_8->addWidget(toolButton_5);

        toolButton_6 = new QToolButton(scrollAreaWidgetContents);
        toolButton_6->setObjectName(QStringLiteral("toolButton_6"));
        toolButton_6->setMinimumSize(QSize(180, 30));
        toolButton_6->setMaximumSize(QSize(180, 16777215));
        toolButton_6->setFont(font2);
        toolButton_6->setStyleSheet(QStringLiteral(""));
        toolButton_6->setIcon(icon2);
        toolButton_6->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout_8->addWidget(toolButton_6);

        verticalSpacer = new QSpacerItem(20, 309, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_3->addWidget(scrollArea);


        verticalLayout_6->addWidget(widget);


        horizontalLayout_5->addWidget(widget_left);

        splitter = new QSplitter(zookeeperwidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        QFont font4;
        font4.setFamily(QStringLiteral("Arial"));
        font4.setPointSize(10);
        splitter->setFont(font4);
        splitter->setLineWidth(2);
        splitter->setOrientation(Qt::Horizontal);
        verticalWidget_1_l = new QWidget(splitter);
        verticalWidget_1_l->setObjectName(QStringLiteral("verticalWidget_1_l"));
        verticalWidget_1_l->setStyleSheet(QLatin1String("#verticalWidget_1_l{\n"
"background-color: rgb(30, 45, 54);\n"
"color: rgb(255, 255, 255);\n"
"border-right:2px solid rgba(108, 117, 125, 65); \n"
"}"));
        verticalLayout_9 = new QVBoxLayout(verticalWidget_1_l);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_9->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_9->setContentsMargins(-1, 9, 9, 9);
        horizontalWidget_1_1_l = new QWidget(verticalWidget_1_l);
        horizontalWidget_1_1_l->setObjectName(QStringLiteral("horizontalWidget_1_1_l"));
        QFont font5;
        font5.setPointSize(10);
        horizontalWidget_1_1_l->setFont(font5);
        horizontalLayout_2 = new QHBoxLayout(horizontalWidget_1_1_l);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);

        verticalLayout_9->addWidget(horizontalWidget_1_1_l);

        horizontalWidget_1_2_l = new QWidget(verticalWidget_1_l);
        horizontalWidget_1_2_l->setObjectName(QStringLiteral("horizontalWidget_1_2_l"));
        horizontalWidget_1_2_l->setMinimumSize(QSize(0, 22));
        horizontalLayout = new QHBoxLayout(horizontalWidget_1_2_l);
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_node = new QLabel(horizontalWidget_1_2_l);
        label_node->setObjectName(QStringLiteral("label_node"));
        label_node->setFont(font2);

        horizontalLayout->addWidget(label_node);

        lineEdit_node = new QLineEdit(horizontalWidget_1_2_l);
        lineEdit_node->setObjectName(QStringLiteral("lineEdit_node"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_node->sizePolicy().hasHeightForWidth());
        lineEdit_node->setSizePolicy(sizePolicy);
        lineEdit_node->setFont(font2);
        lineEdit_node->setReadOnly(true);

        horizontalLayout->addWidget(lineEdit_node);

        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        toolButton_add = new QToolButton(horizontalWidget_1_2_l);
        toolButton_add->setObjectName(QStringLiteral("toolButton_add"));
        toolButton_add->setMinimumSize(QSize(60, 30));
        toolButton_add->setMaximumSize(QSize(60, 30));
        toolButton_add->setFont(font2);
        toolButton_add->setStyleSheet(QLatin1String("QToolButton {\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(255, 95, 95);\n"
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
"	background-color: rgb(255, 95, 95);\n"
"}"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/lib/add2.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_add->setIcon(icon3);
        toolButton_add->setIconSize(QSize(12, 12));
        toolButton_add->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout->addWidget(toolButton_add);

        toolButton__delete = new QToolButton(horizontalWidget_1_2_l);
        toolButton__delete->setObjectName(QStringLiteral("toolButton__delete"));
        toolButton__delete->setMinimumSize(QSize(60, 30));
        toolButton__delete->setMaximumSize(QSize(60, 30));
        toolButton__delete->setFont(font2);
        toolButton__delete->setStyleSheet(QLatin1String("QToolButton {\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(255, 95, 95);\n"
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
"	background-color: rgb(255, 95, 95);\n"
"}"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/lib/delete2.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton__delete->setIcon(icon4);
        toolButton__delete->setIconSize(QSize(14, 14));
        toolButton__delete->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout->addWidget(toolButton__delete);

        toolButton_refresh = new QToolButton(horizontalWidget_1_2_l);
        toolButton_refresh->setObjectName(QStringLiteral("toolButton_refresh"));
        toolButton_refresh->setMinimumSize(QSize(60, 30));
        toolButton_refresh->setMaximumSize(QSize(60, 30));
        toolButton_refresh->setFont(font2);
        toolButton_refresh->setStyleSheet(QLatin1String("QToolButton {\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(255, 95, 95);\n"
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
"	background-color: rgb(255, 95, 95);\n"
"}"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/lib/update2.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_refresh->setIcon(icon5);
        toolButton_refresh->setIconSize(QSize(14, 14));
        toolButton_refresh->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout->addWidget(toolButton_refresh);

        toolButton_unfold = new QToolButton(horizontalWidget_1_2_l);
        toolButton_unfold->setObjectName(QStringLiteral("toolButton_unfold"));
        toolButton_unfold->setMinimumSize(QSize(85, 28));
        toolButton_unfold->setMaximumSize(QSize(85, 28));
        toolButton_unfold->setFont(font2);
        toolButton_unfold->setStyleSheet(QLatin1String("QToolButton {\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(255, 95, 95);\n"
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
"	background-color: rgb(255, 95, 95);\n"
"}"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/lib/zhedie.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_unfold->setIcon(icon6);
        toolButton_unfold->setIconSize(QSize(18, 18));
        toolButton_unfold->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout->addWidget(toolButton_unfold);


        verticalLayout_9->addWidget(horizontalWidget_1_2_l);

        horizontalWidget_1_3_l = new QWidget(verticalWidget_1_l);
        horizontalWidget_1_3_l->setObjectName(QStringLiteral("horizontalWidget_1_3_l"));
        horizontalWidget_1_3_l->setMinimumSize(QSize(0, 32));
        horizontalWidget_1_3_l->setStyleSheet(QLatin1String("#horizontalWidget_1_3_l{\n"
"color: rgb(231, 238, 244);\n"
"border-radius: 14px;\n"
"background-color: rgb(25, 25, 25, 155);\n"
"border: 0px solid rgba(255, 255, 255, 0);\n"
"border-radius: 15px;\n"
"padding-left:10px;\n"
"padding-right:10px;\n"
"}"));
        horizontalLayout_3 = new QHBoxLayout(horizontalWidget_1_3_l);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(5, 0, 5, 0);
        lineEdit_search = new QLineEdit(horizontalWidget_1_3_l);
        lineEdit_search->setObjectName(QStringLiteral("lineEdit_search"));
        lineEdit_search->setMinimumSize(QSize(0, 27));
        lineEdit_search->setFont(font3);
        lineEdit_search->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout_3->addWidget(lineEdit_search);

        toolButton = new QToolButton(horizontalWidget_1_3_l);
        toolButton->setObjectName(QStringLiteral("toolButton"));
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
"}\n"
"QToolButton::checked{\n"
"	color: rgb(255, 255, 255);\n"
"	border-radius: 2px;\n"
"	border: 1px solid rgba(255, 255, 255, 80);\n"
"}"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/lib/daxiao.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon7);
        toolButton->setCheckable(true);
        toolButton->setChecked(false);

        horizontalLayout_3->addWidget(toolButton);


        verticalLayout_9->addWidget(horizontalWidget_1_3_l);

        verticalWidget_1_4_l = new QWidget(verticalWidget_1_l);
        verticalWidget_1_4_l->setObjectName(QStringLiteral("verticalWidget_1_4_l"));
        verticalLayout_2 = new QVBoxLayout(verticalWidget_1_4_l);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 1, 0, 1);
        treeWidget = new QTreeWidget(verticalWidget_1_4_l);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setFont(font3);
        treeWidget->setContextMenuPolicy(Qt::CustomContextMenu);
        treeWidget->setStyleSheet(QString::fromUtf8("QToolTip{\n"
"	\n"
"	color: rgb(43, 43, 43);\n"
"    font-size:12px;\n"
"	width:1024;\n"
"	height:40;\n"
"}\n"
"\n"
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
"QTreeWidget::branch:closed:has-ch"
                        "ildren:has-siblings {\n"
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
"QScrollBar:vertical{\n"
"    width: 12px;\n"
"	\n"
"	background-color: rgb(67, 77, 88);\n"
"    margin: 0px,0px,0px,0px;\n"
"    padding-top: 0px;		/*//\351\232\220\350\227\217\344\270\212\344\270\213\347\232\204\347\256\255\345\244\264*/\n"
"    padding-bottom: 0px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    width: 12px;\n"
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
"    background-col"
                        "or: rgba(255, 255, 255, 0);\n"
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
"}\n"
"\n"
"\n"
"QScrollBar::horizontal{\n"
"    height: 12px;\n"
"	background-color: rgb(67, 77, 88);\n"
"	margin: 0px,0px,0px,0px;\n"
"    padding-top: 0px;		/*//\351\232\220\350\227\217\344\270\212\344\270\213\347\232\204\347\256\255\345\244\264*/\n"
"    padding-bottom: 0px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal {\n"
"    height: 12px;\n"
"	background-color: rgb(239, 239, 239);\n"
"    /*\346\273\232\345\212\250\346\235\241\344\270\244\347\253\257\345\217\230\346\210\220\346\244\255\345\234\206 */\n"
"    border-radius: 2px;\n"
"  "
                        "  min-height: 0;\n"
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
"    pa"
                        "dding: 5px 25px 5px 25px;\n"
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
        treeWidget->setLineWidth(1);
        treeWidget->setMidLineWidth(0);
        treeWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        treeWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        treeWidget->setAutoScrollMargin(20);
        treeWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
        treeWidget->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        treeWidget->setIndentation(20);
        treeWidget->setUniformRowHeights(true);
        treeWidget->setAllColumnsShowFocus(false);
        treeWidget->setWordWrap(false);
        treeWidget->header()->setVisible(false);
        treeWidget->header()->setCascadingSectionResizes(false);
        treeWidget->header()->setDefaultSectionSize(100);
        treeWidget->header()->setHighlightSections(false);
        treeWidget->header()->setMinimumSectionSize(30);
        treeWidget->header()->setProperty("showSortIndicator", QVariant(false));
        treeWidget->header()->setStretchLastSection(true);

        verticalLayout_2->addWidget(treeWidget);


        verticalLayout_9->addWidget(verticalWidget_1_4_l);

        splitter->addWidget(verticalWidget_1_l);
        verticalWidget_1_r = new QWidget(splitter);
        verticalWidget_1_r->setObjectName(QStringLiteral("verticalWidget_1_r"));
        verticalWidget_1_r->setMaximumSize(QSize(333, 99999));
        verticalWidget_1_r->setFont(font5);
        verticalWidget_1_r->setStyleSheet(QLatin1String("background-color: rgb(30, 45, 54);\n"
"color: rgb(255, 255, 255);"));
        verticalLayout = new QVBoxLayout(verticalWidget_1_r);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 9, 0, 19);
        gridWidget_1_1_r = new QWidget(verticalWidget_1_r);
        gridWidget_1_1_r->setObjectName(QStringLiteral("gridWidget_1_1_r"));
        gridWidget_1_1_r->setMinimumSize(QSize(0, 300));
        gridWidget_1_1_r->setMaximumSize(QSize(16777215, 300));
        gridLayout = new QGridLayout(gridWidget_1_1_r);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(9);
        gridLayout->setVerticalSpacing(15);
        gridLayout->setContentsMargins(9, 0, 9, 0);
        lineEdit_pzxid = new QLineEdit(gridWidget_1_1_r);
        lineEdit_pzxid->setObjectName(QStringLiteral("lineEdit_pzxid"));
        lineEdit_pzxid->setMinimumSize(QSize(60, 0));
        lineEdit_pzxid->setMaximumSize(QSize(60, 16777215));
        lineEdit_pzxid->setFont(font2);
        lineEdit_pzxid->setReadOnly(true);

        gridLayout->addWidget(lineEdit_pzxid, 4, 1, 1, 1);

        lineEdit_mzxid = new QLineEdit(gridWidget_1_1_r);
        lineEdit_mzxid->setObjectName(QStringLiteral("lineEdit_mzxid"));
        lineEdit_mzxid->setMinimumSize(QSize(60, 0));
        lineEdit_mzxid->setMaximumSize(QSize(60, 16777215));
        lineEdit_mzxid->setFont(font2);
        lineEdit_mzxid->setReadOnly(true);

        gridLayout->addWidget(lineEdit_mzxid, 3, 1, 1, 1);

        lineEdit_aversion = new QLineEdit(gridWidget_1_1_r);
        lineEdit_aversion->setObjectName(QStringLiteral("lineEdit_aversion"));
        lineEdit_aversion->setMinimumSize(QSize(60, 0));
        lineEdit_aversion->setMaximumSize(QSize(60, 16777215));
        lineEdit_aversion->setFont(font2);
        lineEdit_aversion->setReadOnly(true);

        gridLayout->addWidget(lineEdit_aversion, 6, 1, 1, 1);

        lineEdit_version = new QLineEdit(gridWidget_1_1_r);
        lineEdit_version->setObjectName(QStringLiteral("lineEdit_version"));
        lineEdit_version->setMinimumSize(QSize(60, 0));
        lineEdit_version->setMaximumSize(QSize(60, 16777215));
        lineEdit_version->setFont(font2);
        lineEdit_version->setReadOnly(true);

        gridLayout->addWidget(lineEdit_version, 5, 1, 1, 1);

        label_aversion = new QLabel(gridWidget_1_1_r);
        label_aversion->setObjectName(QStringLiteral("label_aversion"));
        label_aversion->setFont(font2);

        gridLayout->addWidget(label_aversion, 6, 0, 1, 1);

        lineEdit_cversion = new QLineEdit(gridWidget_1_1_r);
        lineEdit_cversion->setObjectName(QStringLiteral("lineEdit_cversion"));
        lineEdit_cversion->setMinimumSize(QSize(60, 0));
        lineEdit_cversion->setMaximumSize(QSize(60, 16777215));
        lineEdit_cversion->setFont(font2);
        lineEdit_cversion->setReadOnly(true);

        gridLayout->addWidget(lineEdit_cversion, 7, 1, 1, 1);

        label_cversion = new QLabel(gridWidget_1_1_r);
        label_cversion->setObjectName(QStringLiteral("label_cversion"));
        label_cversion->setFont(font2);

        gridLayout->addWidget(label_cversion, 7, 0, 1, 1);

        label_pzxid = new QLabel(gridWidget_1_1_r);
        label_pzxid->setObjectName(QStringLiteral("label_pzxid"));
        label_pzxid->setFont(font2);

        gridLayout->addWidget(label_pzxid, 4, 0, 1, 1);

        label_mzxid = new QLabel(gridWidget_1_1_r);
        label_mzxid->setObjectName(QStringLiteral("label_mzxid"));
        label_mzxid->setFont(font2);

        gridLayout->addWidget(label_mzxid, 3, 0, 1, 1);

        label_version = new QLabel(gridWidget_1_1_r);
        label_version->setObjectName(QStringLiteral("label_version"));
        label_version->setFont(font2);

        gridLayout->addWidget(label_version, 5, 0, 1, 1);

        lineEdit_czxid = new QLineEdit(gridWidget_1_1_r);
        lineEdit_czxid->setObjectName(QStringLiteral("lineEdit_czxid"));
        lineEdit_czxid->setMinimumSize(QSize(60, 0));
        lineEdit_czxid->setMaximumSize(QSize(60, 16777215));
        lineEdit_czxid->setFont(font2);
        lineEdit_czxid->setReadOnly(true);

        gridLayout->addWidget(lineEdit_czxid, 2, 1, 1, 1);

        label_dataLength = new QLabel(gridWidget_1_1_r);
        label_dataLength->setObjectName(QStringLiteral("label_dataLength"));
        label_dataLength->setFont(font2);

        gridLayout->addWidget(label_dataLength, 8, 0, 1, 1);

        label_czxid = new QLabel(gridWidget_1_1_r);
        label_czxid->setObjectName(QStringLiteral("label_czxid"));
        label_czxid->setFont(font2);

        gridLayout->addWidget(label_czxid, 2, 0, 1, 1);

        lineEdit_dataLength = new QLineEdit(gridWidget_1_1_r);
        lineEdit_dataLength->setObjectName(QStringLiteral("lineEdit_dataLength"));
        lineEdit_dataLength->setMinimumSize(QSize(60, 0));
        lineEdit_dataLength->setMaximumSize(QSize(60, 16777215));
        lineEdit_dataLength->setFont(font2);
        lineEdit_dataLength->setReadOnly(true);

        gridLayout->addWidget(lineEdit_dataLength, 8, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 5, 2, 1, 1);

        label_numChildren = new QLabel(gridWidget_1_1_r);
        label_numChildren->setObjectName(QStringLiteral("label_numChildren"));
        label_numChildren->setFont(font2);

        gridLayout->addWidget(label_numChildren, 13, 0, 1, 1);

        label_mtime = new QLabel(gridWidget_1_1_r);
        label_mtime->setObjectName(QStringLiteral("label_mtime"));
        label_mtime->setFont(font2);

        gridLayout->addWidget(label_mtime, 12, 0, 1, 1);

        lineEdit_mtime = new QLineEdit(gridWidget_1_1_r);
        lineEdit_mtime->setObjectName(QStringLiteral("lineEdit_mtime"));
        lineEdit_mtime->setMinimumSize(QSize(155, 0));
        lineEdit_mtime->setMaximumSize(QSize(155, 16777215));
        lineEdit_mtime->setFont(font2);
        lineEdit_mtime->setReadOnly(true);

        gridLayout->addWidget(lineEdit_mtime, 12, 1, 1, 1);

        lineEdit_numChildren = new QLineEdit(gridWidget_1_1_r);
        lineEdit_numChildren->setObjectName(QStringLiteral("lineEdit_numChildren"));
        lineEdit_numChildren->setMinimumSize(QSize(60, 0));
        lineEdit_numChildren->setMaximumSize(QSize(60, 16777215));
        lineEdit_numChildren->setFont(font2);
        lineEdit_numChildren->setReadOnly(true);

        gridLayout->addWidget(lineEdit_numChildren, 13, 1, 1, 1);

        label_ctime = new QLabel(gridWidget_1_1_r);
        label_ctime->setObjectName(QStringLiteral("label_ctime"));
        label_ctime->setFont(font2);

        gridLayout->addWidget(label_ctime, 11, 0, 1, 1);

        lineEdit_ctime = new QLineEdit(gridWidget_1_1_r);
        lineEdit_ctime->setObjectName(QStringLiteral("lineEdit_ctime"));
        lineEdit_ctime->setMinimumSize(QSize(155, 0));
        lineEdit_ctime->setMaximumSize(QSize(155, 16777215));
        lineEdit_ctime->setFont(font2);
        lineEdit_ctime->setReadOnly(true);

        gridLayout->addWidget(lineEdit_ctime, 11, 1, 1, 1);

        label_ephemeralOwner = new QLabel(gridWidget_1_1_r);
        label_ephemeralOwner->setObjectName(QStringLiteral("label_ephemeralOwner"));
        label_ephemeralOwner->setFont(font2);

        gridLayout->addWidget(label_ephemeralOwner, 14, 0, 1, 1);

        lineEdit_ephemeralOwner = new QLineEdit(gridWidget_1_1_r);
        lineEdit_ephemeralOwner->setObjectName(QStringLiteral("lineEdit_ephemeralOwner"));
        lineEdit_ephemeralOwner->setMinimumSize(QSize(155, 0));
        lineEdit_ephemeralOwner->setMaximumSize(QSize(60, 16777215));
        lineEdit_ephemeralOwner->setFont(font2);
        lineEdit_ephemeralOwner->setReadOnly(true);

        gridLayout->addWidget(lineEdit_ephemeralOwner, 14, 1, 1, 1);


        verticalLayout->addWidget(gridWidget_1_1_r);

        widget_1_2_r = new QWidget(verticalWidget_1_r);
        widget_1_2_r->setObjectName(QStringLiteral("widget_1_2_r"));
        widget_1_2_r->setMinimumSize(QSize(0, 0));
        widget_1_2_r->setMaximumSize(QSize(16777215, 55561));
        verticalLayout_7 = new QVBoxLayout(widget_1_2_r);
        verticalLayout_7->setSpacing(5);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(9, 5, 9, 0);
        horizontalWidget_1_2_1_r = new QWidget(widget_1_2_r);
        horizontalWidget_1_2_1_r->setObjectName(QStringLiteral("horizontalWidget_1_2_1_r"));
        horizontalWidget_1_2_1_r->setMinimumSize(QSize(0, 35));
        horizontalWidget_1_2_1_r->setMaximumSize(QSize(16777215, 35));
        horizontalLayout_7 = new QHBoxLayout(horizontalWidget_1_2_1_r);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_node_create = new QLabel(horizontalWidget_1_2_1_r);
        label_node_create->setObjectName(QStringLiteral("label_node_create"));
        label_node_create->setMinimumSize(QSize(100, 0));
        label_node_create->setMaximumSize(QSize(100, 16777215));
        label_node_create->setFont(font2);

        horizontalLayout_7->addWidget(label_node_create);

        lineEdit_node_create = new QLineEdit(horizontalWidget_1_2_1_r);
        lineEdit_node_create->setObjectName(QStringLiteral("lineEdit_node_create"));
        lineEdit_node_create->setMinimumSize(QSize(200, 28));
        lineEdit_node_create->setMaximumSize(QSize(200, 16777215));
        lineEdit_node_create->setFont(font2);
        lineEdit_node_create->setStyleSheet(QLatin1String("QLineEdit{\n"
"color:#ced4da;\n"
"border-radius: 14px;\n"
"background-color: rgb(25, 25, 25, 155);\n"
"border: 0px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding-left:10px;\n"
"padding-right:10px;\n"
"}"));

        horizontalLayout_7->addWidget(lineEdit_node_create);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_6);


        verticalLayout_7->addWidget(horizontalWidget_1_2_1_r);

        horizontalWidget_1_2_2_r = new QWidget(widget_1_2_r);
        horizontalWidget_1_2_2_r->setObjectName(QStringLiteral("horizontalWidget_1_2_2_r"));
        horizontalWidget_1_2_2_r->setMinimumSize(QSize(0, 35));
        horizontalWidget_1_2_2_r->setMaximumSize(QSize(16777215, 35));
        horizontalLayout_8 = new QHBoxLayout(horizontalWidget_1_2_2_r);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        label_node_type = new QLabel(horizontalWidget_1_2_2_r);
        label_node_type->setObjectName(QStringLiteral("label_node_type"));
        label_node_type->setMinimumSize(QSize(100, 0));
        label_node_type->setMaximumSize(QSize(100, 16777215));
        label_node_type->setFont(font2);

        horizontalLayout_8->addWidget(label_node_type);

        comboBox_node_type = new QComboBox(horizontalWidget_1_2_2_r);
        comboBox_node_type->addItem(QString());
        comboBox_node_type->addItem(QString());
        comboBox_node_type->addItem(QString());
        comboBox_node_type->addItem(QString());
        comboBox_node_type->setObjectName(QStringLiteral("comboBox_node_type"));
        comboBox_node_type->setMinimumSize(QSize(200, 28));
        comboBox_node_type->setMaximumSize(QSize(200, 16777215));
        comboBox_node_type->setFont(font2);
        comboBox_node_type->setStyleSheet(QLatin1String("QComboBox{\n"
"	color:#ffffff;\n"
"	border:1px solid #8a8a8a;\n"
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

        horizontalLayout_8->addWidget(comboBox_node_type);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_4);


        verticalLayout_7->addWidget(horizontalWidget_1_2_2_r);

        horizontalWidget_1_2_3_r = new QWidget(widget_1_2_r);
        horizontalWidget_1_2_3_r->setObjectName(QStringLiteral("horizontalWidget_1_2_3_r"));
        horizontalWidget_1_2_3_r->setMinimumSize(QSize(0, 35));
        horizontalWidget_1_2_3_r->setMaximumSize(QSize(16777215, 35));
        horizontalLayout_9 = new QHBoxLayout(horizontalWidget_1_2_3_r);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        label_node_acl = new QLabel(horizontalWidget_1_2_3_r);
        label_node_acl->setObjectName(QStringLiteral("label_node_acl"));
        label_node_acl->setMinimumSize(QSize(100, 0));
        label_node_acl->setMaximumSize(QSize(100, 16777215));
        label_node_acl->setFont(font2);

        horizontalLayout_9->addWidget(label_node_acl);

        comboBox_node_acl = new QComboBox(horizontalWidget_1_2_3_r);
        comboBox_node_acl->addItem(QString());
        comboBox_node_acl->addItem(QString());
        comboBox_node_acl->addItem(QString());
        comboBox_node_acl->addItem(QString());
        comboBox_node_acl->setObjectName(QStringLiteral("comboBox_node_acl"));
        comboBox_node_acl->setMinimumSize(QSize(200, 28));
        comboBox_node_acl->setMaximumSize(QSize(200, 16777215));
        comboBox_node_acl->setFont(font2);
        comboBox_node_acl->setStyleSheet(QLatin1String("QComboBox{\n"
"	color:#ffffff;\n"
"	border:1px solid #8a8a8a;\n"
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

        horizontalLayout_9->addWidget(comboBox_node_acl);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_5);


        verticalLayout_7->addWidget(horizontalWidget_1_2_3_r);

        horizontalWidget_1_2_4_r = new QWidget(widget_1_2_r);
        horizontalWidget_1_2_4_r->setObjectName(QStringLiteral("horizontalWidget_1_2_4_r"));
        horizontalWidget_1_2_4_r->setMinimumSize(QSize(0, 40));
        horizontalWidget_1_2_4_r->setMaximumSize(QSize(16777215, 40));
        horizontalLayout_10 = new QHBoxLayout(horizontalWidget_1_2_4_r);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 15, 0, 0);
        label_data = new QLabel(horizontalWidget_1_2_4_r);
        label_data->setObjectName(QStringLiteral("label_data"));
        label_data->setMaximumSize(QSize(16777215, 77));
        label_data->setFont(font2);

        horizontalLayout_10->addWidget(label_data);


        verticalLayout_7->addWidget(horizontalWidget_1_2_4_r);

        verticalWidget_1_2_5_r = new QWidget(widget_1_2_r);
        verticalWidget_1_2_5_r->setObjectName(QStringLiteral("verticalWidget_1_2_5_r"));
        verticalLayout_5 = new QVBoxLayout(verticalWidget_1_2_5_r);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalWidget_1_2_5_2_r = new QWidget(verticalWidget_1_2_5_r);
        verticalWidget_1_2_5_2_r->setObjectName(QStringLiteral("verticalWidget_1_2_5_2_r"));
        verticalWidget_1_2_5_2_r->setFont(font3);
        verticalWidget_1_2_5_2_r->setStyleSheet(QStringLiteral(""));
        verticalLayout_4 = new QVBoxLayout(verticalWidget_1_2_5_2_r);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(2, 0, 2, 0);
        textEdit_data = new QTextEdit(verticalWidget_1_2_5_2_r);
        textEdit_data->setObjectName(QStringLiteral("textEdit_data"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(10);
        sizePolicy1.setHeightForWidth(textEdit_data->sizePolicy().hasHeightForWidth());
        textEdit_data->setSizePolicy(sizePolicy1);
        textEdit_data->setMinimumSize(QSize(0, 0));
        textEdit_data->setFont(font2);
        textEdit_data->setStyleSheet(QLatin1String("\n"
"	border: 1px solid rgb(197, 197, 197);\n"
"	border-radius: 0px;"));

        verticalLayout_4->addWidget(textEdit_data);


        verticalLayout_5->addWidget(verticalWidget_1_2_5_2_r);

        horizontalWidget_1_2_5_1r = new QWidget(verticalWidget_1_2_5_r);
        horizontalWidget_1_2_5_1r->setObjectName(QStringLiteral("horizontalWidget_1_2_5_1r"));
        horizontalWidget_1_2_5_1r->setMaximumSize(QSize(16777215, 40));
        horizontalWidget_1_2_5_1r->setStyleSheet(QStringLiteral(""));
        horizontalLayout_4 = new QHBoxLayout(horizontalWidget_1_2_5_1r);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(5, 6, 5, 0);
        label_data_type = new QLabel(horizontalWidget_1_2_5_1r);
        label_data_type->setObjectName(QStringLiteral("label_data_type"));
        label_data_type->setFont(font2);
        label_data_type->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout_4->addWidget(label_data_type);

        toolButton_copy_data = new QToolButton(horizontalWidget_1_2_5_1r);
        toolButton_copy_data->setObjectName(QStringLiteral("toolButton_copy_data"));
        QFont font6;
        font6.setPointSize(10);
        font6.setStyleStrategy(QFont::PreferAntialias);
        toolButton_copy_data->setFont(font6);
        toolButton_copy_data->setStyleSheet(QLatin1String("QToolButton {\n"
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
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/lib/copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_copy_data->setIcon(icon8);
        toolButton_copy_data->setIconSize(QSize(15, 15));

        horizontalLayout_4->addWidget(toolButton_copy_data);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        toolButton_createData = new QToolButton(horizontalWidget_1_2_5_1r);
        toolButton_createData->setObjectName(QStringLiteral("toolButton_createData"));
        toolButton_createData->setMinimumSize(QSize(60, 28));
        toolButton_createData->setMaximumSize(QSize(60, 28));
        toolButton_createData->setFont(font2);
        toolButton_createData->setStyleSheet(QLatin1String("QToolButton {\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(255, 95, 95);\n"
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
"	background-color: rgb(255, 95, 95);\n"
"}"));
        toolButton_createData->setIconSize(QSize(14, 14));
        toolButton_createData->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_4->addWidget(toolButton_createData);

        toolButton_saveData = new QToolButton(horizontalWidget_1_2_5_1r);
        toolButton_saveData->setObjectName(QStringLiteral("toolButton_saveData"));
        toolButton_saveData->setMinimumSize(QSize(60, 28));
        toolButton_saveData->setMaximumSize(QSize(60, 28));
        toolButton_saveData->setFont(font2);
        toolButton_saveData->setStyleSheet(QLatin1String("QToolButton {\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(255, 95, 95);\n"
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
"	background-color: rgb(255, 95, 95);\n"
"}"));
        toolButton_saveData->setIconSize(QSize(14, 14));
        toolButton_saveData->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_4->addWidget(toolButton_saveData);


        verticalLayout_5->addWidget(horizontalWidget_1_2_5_1r);


        verticalLayout_7->addWidget(verticalWidget_1_2_5_r);


        verticalLayout->addWidget(widget_1_2_r);

        splitter->addWidget(verticalWidget_1_r);

        horizontalLayout_5->addWidget(splitter);


        retranslateUi(zookeeperwidget);

        QMetaObject::connectSlotsByName(zookeeperwidget);
    } // setupUi

    void retranslateUi(QWidget *zookeeperwidget)
    {
        zookeeperwidget->setWindowTitle(QApplication::translate("zookeeperwidget", "Form", nullptr));
        lineEdit_find->setPlaceholderText(QApplication::translate("zookeeperwidget", "\346\220\234\347\264\242\350\277\236\346\216\245", nullptr));
        label->setText(QApplication::translate("zookeeperwidget", "\345\277\253\351\200\237\350\277\236\346\216\245", nullptr));
        toolButton_3->setText(QString());
        label_host_zk->setText(QApplication::translate("zookeeperwidget", "\344\270\273\346\234\272", nullptr));
        lineEdit_host_zk_data->setText(QApplication::translate("zookeeperwidget", "172.16.8.153", nullptr));
        lineEdit_host_zk_data->setPlaceholderText(QApplication::translate("zookeeperwidget", "127.0.0.1", nullptr));
        label_port_zk->setText(QApplication::translate("zookeeperwidget", "\347\253\257\345\217\243", nullptr));
        lineEdit_port_zk_data->setText(QApplication::translate("zookeeperwidget", "11100", nullptr));
        lineEdit_port_zk_data->setPlaceholderText(QApplication::translate("zookeeperwidget", "22", nullptr));
        toolButton_save->setText(QApplication::translate("zookeeperwidget", "\344\277\235\345\255\230", nullptr));
        toolButton_2->setText(QApplication::translate("zookeeperwidget", "172.16.8.153:11100", nullptr));
        toolButton_4->setText(QApplication::translate("zookeeperwidget", "172.16.8.156:11100", nullptr));
        toolButton_5->setText(QApplication::translate("zookeeperwidget", "172.16.8.159:11100", nullptr));
        toolButton_6->setText(QApplication::translate("zookeeperwidget", "172.16.18.153:11100", nullptr));
        label_node->setText(QApplication::translate("zookeeperwidget", "\350\212\202\347\202\271\357\274\232", nullptr));
        lineEdit_node->setText(QApplication::translate("zookeeperwidget", "/", nullptr));
        toolButton_add->setText(QApplication::translate("zookeeperwidget", "\346\267\273\345\212\240", nullptr));
        toolButton__delete->setText(QApplication::translate("zookeeperwidget", "\345\210\240\351\231\244", nullptr));
        toolButton_refresh->setText(QApplication::translate("zookeeperwidget", "\345\210\267\346\226\260", nullptr));
        toolButton_unfold->setText(QApplication::translate("zookeeperwidget", "\345\205\250\351\203\250\345\261\225\345\274\200", nullptr));
        lineEdit_search->setPlaceholderText(QApplication::translate("zookeeperwidget", "\346\220\234\347\264\242", nullptr));
        toolButton->setText(QString());
        lineEdit_pzxid->setText(QApplication::translate("zookeeperwidget", "0", nullptr));
        lineEdit_mzxid->setText(QApplication::translate("zookeeperwidget", "0", nullptr));
        lineEdit_aversion->setText(QApplication::translate("zookeeperwidget", "0", nullptr));
        lineEdit_version->setText(QApplication::translate("zookeeperwidget", "0", nullptr));
        label_aversion->setText(QApplication::translate("zookeeperwidget", "aversion\357\274\232", nullptr));
        lineEdit_cversion->setText(QApplication::translate("zookeeperwidget", "0", nullptr));
        label_cversion->setText(QApplication::translate("zookeeperwidget", "cversion\357\274\232", nullptr));
        label_pzxid->setText(QApplication::translate("zookeeperwidget", "pzxid\357\274\232", nullptr));
        label_mzxid->setText(QApplication::translate("zookeeperwidget", "mzxid\357\274\232", nullptr));
        label_version->setText(QApplication::translate("zookeeperwidget", "version\357\274\232", nullptr));
        lineEdit_czxid->setText(QApplication::translate("zookeeperwidget", "0", nullptr));
        label_dataLength->setText(QApplication::translate("zookeeperwidget", "dataLength\357\274\232", nullptr));
        label_czxid->setText(QApplication::translate("zookeeperwidget", "czxid\357\274\232", nullptr));
        lineEdit_dataLength->setText(QApplication::translate("zookeeperwidget", "0", nullptr));
        label_numChildren->setText(QApplication::translate("zookeeperwidget", "numChildren\357\274\232", nullptr));
        label_mtime->setText(QApplication::translate("zookeeperwidget", "mtime\357\274\232", nullptr));
        lineEdit_mtime->setText(QApplication::translate("zookeeperwidget", "0", nullptr));
        lineEdit_numChildren->setText(QApplication::translate("zookeeperwidget", "0", nullptr));
        label_ctime->setText(QApplication::translate("zookeeperwidget", "ctime\357\274\232", nullptr));
        lineEdit_ctime->setText(QApplication::translate("zookeeperwidget", "0", nullptr));
        label_ephemeralOwner->setText(QApplication::translate("zookeeperwidget", "ephemeralOwner\357\274\232", nullptr));
        lineEdit_ephemeralOwner->setText(QApplication::translate("zookeeperwidget", "0", nullptr));
        label_node_create->setText(QApplication::translate("zookeeperwidget", "createNode\357\274\232", nullptr));
        label_node_type->setText(QApplication::translate("zookeeperwidget", "nodeType\357\274\232", nullptr));
        comboBox_node_type->setItemText(0, QApplication::translate("zookeeperwidget", "\346\214\201\344\271\205\350\212\202\347\202\271", nullptr));
        comboBox_node_type->setItemText(1, QApplication::translate("zookeeperwidget", "\344\270\264\346\227\266\350\212\202\347\202\271", nullptr));
        comboBox_node_type->setItemText(2, QApplication::translate("zookeeperwidget", "\346\214\201\344\271\205\346\234\211\345\272\217\350\212\202\347\202\271", nullptr));
        comboBox_node_type->setItemText(3, QApplication::translate("zookeeperwidget", "\344\270\264\346\227\266\346\234\211\345\272\217\350\212\202\347\202\271", nullptr));

        label_node_acl->setText(QApplication::translate("zookeeperwidget", "nodeACL\357\274\232", nullptr));
        comboBox_node_acl->setItemText(0, QApplication::translate("zookeeperwidget", "ZOO_CREATOR_ALL_ACL", nullptr));
        comboBox_node_acl->setItemText(1, QApplication::translate("zookeeperwidget", "ZOO_OPEN_ACL_UNSAFE", nullptr));
        comboBox_node_acl->setItemText(2, QApplication::translate("zookeeperwidget", "ZOO_READ_ACL_UNSAFE", nullptr));
        comboBox_node_acl->setItemText(3, QApplication::translate("zookeeperwidget", "ZOO_READ_ACL", nullptr));

        label_data->setText(QApplication::translate("zookeeperwidget", "\350\212\202\347\202\271\346\225\260\346\215\256:", nullptr));
        textEdit_data->setHtml(QApplication::translate("zookeeperwidget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'OPPOSans B'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Cascadia Mono';\"><br /></p></body></html>", nullptr));
        label_data_type->setText(QApplication::translate("zookeeperwidget", "\346\225\260\346\215\256\347\261\273\345\236\213\357\274\232json", nullptr));
        toolButton_copy_data->setText(QString());
        toolButton_createData->setText(QApplication::translate("zookeeperwidget", "\345\210\233\345\273\272", nullptr));
        toolButton_saveData->setText(QApplication::translate("zookeeperwidget", "\344\277\256\346\224\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class zookeeperwidget: public Ui_zookeeperwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZOOKEEPERWIDGET_H
