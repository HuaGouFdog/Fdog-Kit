/********************************************************************************
** Form generated from reading UI file 'toolswidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOOLSWIDGET_H
#define UI_TOOLSWIDGET_H

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
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_toolswidget
{
public:
    QHBoxLayout *horizontalLayout_4;
    QWidget *widget_left;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QToolButton *toolButton_md5;
    QToolButton *toolButton_json;
    QToolButton *toolButton_timestamp;
    QToolButton *toolButton_conversion;
    QToolButton *toolButton_url;
    QToolButton *toolButton_7;
    QToolButton *toolButton_20;
    QToolButton *toolButton;
    QToolButton *toolButton_11;
    QToolButton *toolButton_21;
    QToolButton *toolButton_15;
    QToolButton *toolButton_19;
    QToolButton *toolButton_9;
    QToolButton *toolButton_17;
    QToolButton *toolButton_14;
    QToolButton *toolButton_18;
    QToolButton *toolButton_8;
    QSpacerItem *verticalSpacer;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_5;
    QToolButton *toolButton_3;
    QToolButton *toolButton_4;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QLineEdit *lineEdit_find;
    QStackedWidget *stackedWidget;
    QWidget *page_md5;
    QPlainTextEdit *plainTextEdit_data;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_7;
    QToolButton *toolButton_encipher;
    QToolButton *toolButton_clear;
    QWidget *gridWidget;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QLabel *label_3;
    QPlainTextEdit *plainTextEdit_16Lower;
    QPlainTextEdit *plainTextEdit_16;
    QLabel *label_6;
    QToolButton *toolButton_12;
    QToolButton *toolButton_13;
    QToolButton *toolButton_10;
    QLabel *label_5;
    QToolButton *toolButton_6;
    QPlainTextEdit *plainTextEdit_32Lower;
    QPlainTextEdit *plainTextEdit_32;
    QLabel *label_7;
    QToolButton *toolButton_32Lower_10;
    QToolButton *toolButton_32_10;
    QToolButton *toolButton_16Lower_10;
    QToolButton *toolButton_16_10;
    QWidget *page_json;
    QHBoxLayout *horizontalLayout_2;
    QSplitter *splitter;
    QPlainTextEdit *plainTextEdit_json_source;
    QTextEdit *textEdit_json_target;
    QWidget *page_3;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QToolButton *toolButton_25;
    QTextEdit *textEdit;
    QWidget *page_2;
    QLineEdit *lineEdit_now_timestamp;
    QComboBox *comboBox_time2date;
    QLineEdit *lineEdit_date2time_in;
    QLineEdit *lineEdit_date2time_out;
    QLineEdit *lineEdit_time2date_in;
    QToolButton *toolButton_timestamp_copy;
    QLineEdit *lineEdit_time2date_out;
    QToolButton *toolButton_date2time;
    QComboBox *comboBox_date2time;
    QLabel *label_now_timestamp;
    QLabel *label_time2date;
    QLabel *label_date2time;
    QToolButton *toolButton_time2date;
    QWidget *page;
    QLabel *label_hex;
    QLineEdit *lineEdit_hex;
    QLineEdit *lineEdit_oct;
    QLineEdit *lineEdit_bin;
    QLabel *label_dec;
    QLineEdit *lineEdit_dec;
    QLabel *label_oct;
    QLabel *label_bin;
    QWidget *page_xml;
    QHBoxLayout *horizontalLayout_3;
    QSplitter *splitter_2;
    QTextEdit *textEdit_xml_source;
    QTextEdit *textEdit_xml_target;
    QWidget *page_diff;
    QHBoxLayout *horizontalLayout;
    QSplitter *splitter_3;
    QTextEdit *textEdit_diff_source;
    QTextEdit *textEdit_diff_target;

    void setupUi(QWidget *toolswidget)
    {
        if (toolswidget->objectName().isEmpty())
            toolswidget->setObjectName(QStringLiteral("toolswidget"));
        toolswidget->resize(1040, 631);
        toolswidget->setStyleSheet(QLatin1String("/*background-color: rgb(61, 93, 111);*/\n"
"color: rgb(255, 255, 255);"));
        horizontalLayout_4 = new QHBoxLayout(toolswidget);
        horizontalLayout_4->setSpacing(10);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 9, 0);
        widget_left = new QWidget(toolswidget);
        widget_left->setObjectName(QStringLiteral("widget_left"));
        widget_left->setMinimumSize(QSize(230, 0));
        widget_left->setMaximumSize(QSize(230, 16777215));
        widget_left->setStyleSheet(QString::fromUtf8("#widget_left{\n"
"border-image: url(:/lib/back2.png);\n"
"border-right:0px solid rgba(108, 117, 125, 65); \n"
"}\n"
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
"}\n"
"\n"
"\n"
"QScrollBar::horizontal{\n"
"    height: 8px;\n"
"	background-color: rgb(67, 77, 88);\n"
"	margin: 0px,0px,0px,0px;\n"
"    padding-top: 0px;		/*//\351\232\220\350\227\217\344\270\212\344\270\213\347\232\204\347\256\255\345\244\264*/\n"
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
"    backgr"
                        "ound-color: rgba(255, 255, 255, 0);\n"
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
"}"));
        verticalLayout_3 = new QVBoxLayout(widget_left);
        verticalLayout_3->setSpacing(30);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(25, 22, 25, 15);
        label_2 = new QLabel(widget_left);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font;
        font.setFamily(QStringLiteral("OPPOSans B"));
        font.setPointSize(15);
        label_2->setFont(font);

        verticalLayout_3->addWidget(label_2);

        scrollArea = new QScrollArea(widget_left);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 166, 782));
        scrollAreaWidgetContents->setCursor(QCursor(Qt::PointingHandCursor));
        scrollAreaWidgetContents->setStyleSheet(QLatin1String("QToolButton {\n"
"    qproperty-iconSize: 22px 22px;\n"
"	padding-left: 0px;\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"	border: none;\n"
"	border-radius:5px;\n"
"	color: rgb(255, 255, 255);\n"
"	text-align: center;\n"
"}\n"
"\n"
"QToolButton::menu-indicator { \n"
"	image: None;\n"
"}\n"
"\n"
"QToolButton:hover {\n"
"	border-radius:5px;\n"
"	color: rgb(255, 255, 255);\n"
"	\n"
"	background-color: rgb(20, 30, 36);\n"
"	border: none;\n"
"}\n"
" \n"
"QToolButton:checked {\n"
"	border-radius:5px;\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(20, 30, 36);\n"
"	border: none;\n"
"}"));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        toolButton_md5 = new QToolButton(scrollAreaWidgetContents);
        toolButton_md5->setObjectName(QStringLiteral("toolButton_md5"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolButton_md5->sizePolicy().hasHeightForWidth());
        toolButton_md5->setSizePolicy(sizePolicy);
        toolButton_md5->setMinimumSize(QSize(0, 40));
        toolButton_md5->setMaximumSize(QSize(16777215, 40));
        QFont font1;
        font1.setFamily(QStringLiteral("OPPOSans B"));
        font1.setPointSize(10);
        toolButton_md5->setFont(font1);
        toolButton_md5->setStyleSheet(QStringLiteral(""));
        QIcon icon;
        icon.addFile(QStringLiteral(":/lib/MD5.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_md5->setIcon(icon);
        toolButton_md5->setIconSize(QSize(22, 22));
        toolButton_md5->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout->addWidget(toolButton_md5);

        toolButton_json = new QToolButton(scrollAreaWidgetContents);
        toolButton_json->setObjectName(QStringLiteral("toolButton_json"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(toolButton_json->sizePolicy().hasHeightForWidth());
        toolButton_json->setSizePolicy(sizePolicy1);
        toolButton_json->setMinimumSize(QSize(0, 40));
        toolButton_json->setMaximumSize(QSize(16777215, 40));
        toolButton_json->setFont(font1);
        toolButton_json->setStyleSheet(QStringLiteral(""));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/lib/json (2).png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_json->setIcon(icon1);
        toolButton_json->setIconSize(QSize(22, 22));
        toolButton_json->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout->addWidget(toolButton_json);

        toolButton_timestamp = new QToolButton(scrollAreaWidgetContents);
        toolButton_timestamp->setObjectName(QStringLiteral("toolButton_timestamp"));
        sizePolicy.setHeightForWidth(toolButton_timestamp->sizePolicy().hasHeightForWidth());
        toolButton_timestamp->setSizePolicy(sizePolicy);
        toolButton_timestamp->setMinimumSize(QSize(0, 40));
        toolButton_timestamp->setMaximumSize(QSize(16777215, 40));
        toolButton_timestamp->setFont(font1);
        toolButton_timestamp->setStyleSheet(QStringLiteral(""));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/lib/timestamp.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_timestamp->setIcon(icon2);
        toolButton_timestamp->setIconSize(QSize(22, 22));
        toolButton_timestamp->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout->addWidget(toolButton_timestamp);

        toolButton_conversion = new QToolButton(scrollAreaWidgetContents);
        toolButton_conversion->setObjectName(QStringLiteral("toolButton_conversion"));
        sizePolicy.setHeightForWidth(toolButton_conversion->sizePolicy().hasHeightForWidth());
        toolButton_conversion->setSizePolicy(sizePolicy);
        toolButton_conversion->setMinimumSize(QSize(0, 40));
        toolButton_conversion->setMaximumSize(QSize(16777215, 40));
        toolButton_conversion->setFont(font1);
        toolButton_conversion->setStyleSheet(QStringLiteral(""));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/lib/Binary.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_conversion->setIcon(icon3);
        toolButton_conversion->setIconSize(QSize(22, 22));
        toolButton_conversion->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout->addWidget(toolButton_conversion);

        toolButton_url = new QToolButton(scrollAreaWidgetContents);
        toolButton_url->setObjectName(QStringLiteral("toolButton_url"));
        sizePolicy.setHeightForWidth(toolButton_url->sizePolicy().hasHeightForWidth());
        toolButton_url->setSizePolicy(sizePolicy);
        toolButton_url->setMinimumSize(QSize(0, 40));
        toolButton_url->setMaximumSize(QSize(16777215, 40));
        toolButton_url->setFont(font1);
        toolButton_url->setStyleSheet(QStringLiteral(""));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/lib/URL.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_url->setIcon(icon4);
        toolButton_url->setIconSize(QSize(22, 22));
        toolButton_url->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout->addWidget(toolButton_url);

        toolButton_7 = new QToolButton(scrollAreaWidgetContents);
        toolButton_7->setObjectName(QStringLiteral("toolButton_7"));
        sizePolicy.setHeightForWidth(toolButton_7->sizePolicy().hasHeightForWidth());
        toolButton_7->setSizePolicy(sizePolicy);
        toolButton_7->setMinimumSize(QSize(0, 40));
        toolButton_7->setMaximumSize(QSize(16777215, 40));
        toolButton_7->setFont(font1);
        toolButton_7->setStyleSheet(QStringLiteral(""));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/lib/calculator.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_7->setIcon(icon5);
        toolButton_7->setIconSize(QSize(22, 22));
        toolButton_7->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout->addWidget(toolButton_7);

        toolButton_20 = new QToolButton(scrollAreaWidgetContents);
        toolButton_20->setObjectName(QStringLiteral("toolButton_20"));
        sizePolicy.setHeightForWidth(toolButton_20->sizePolicy().hasHeightForWidth());
        toolButton_20->setSizePolicy(sizePolicy);
        toolButton_20->setMinimumSize(QSize(0, 40));
        toolButton_20->setMaximumSize(QSize(16777215, 40));
        toolButton_20->setFont(font1);
        toolButton_20->setStyleSheet(QStringLiteral(""));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/lib/qssmaihua.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_20->setIcon(icon6);
        toolButton_20->setIconSize(QSize(22, 22));
        toolButton_20->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout->addWidget(toolButton_20);

        toolButton = new QToolButton(scrollAreaWidgetContents);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        sizePolicy.setHeightForWidth(toolButton->sizePolicy().hasHeightForWidth());
        toolButton->setSizePolicy(sizePolicy);
        toolButton->setMinimumSize(QSize(0, 40));
        toolButton->setMaximumSize(QSize(16777215, 40));
        toolButton->setFont(font1);
        toolButton->setStyleSheet(QStringLiteral(""));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/lib/xml (2).png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon7);
        toolButton->setIconSize(QSize(22, 22));
        toolButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout->addWidget(toolButton);

        toolButton_11 = new QToolButton(scrollAreaWidgetContents);
        toolButton_11->setObjectName(QStringLiteral("toolButton_11"));
        sizePolicy.setHeightForWidth(toolButton_11->sizePolicy().hasHeightForWidth());
        toolButton_11->setSizePolicy(sizePolicy);
        toolButton_11->setMinimumSize(QSize(0, 40));
        toolButton_11->setMaximumSize(QSize(16777215, 40));
        toolButton_11->setFont(font1);
        toolButton_11->setStyleSheet(QStringLiteral(""));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/lib/note.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_11->setIcon(icon8);
        toolButton_11->setIconSize(QSize(22, 22));
        toolButton_11->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout->addWidget(toolButton_11);

        toolButton_21 = new QToolButton(scrollAreaWidgetContents);
        toolButton_21->setObjectName(QStringLiteral("toolButton_21"));
        sizePolicy.setHeightForWidth(toolButton_21->sizePolicy().hasHeightForWidth());
        toolButton_21->setSizePolicy(sizePolicy);
        toolButton_21->setMinimumSize(QSize(0, 40));
        toolButton_21->setMaximumSize(QSize(16777215, 40));
        toolButton_21->setFont(font1);
        toolButton_21->setStyleSheet(QStringLiteral(""));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/lib/linux.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_21->setIcon(icon9);
        toolButton_21->setIconSize(QSize(22, 22));
        toolButton_21->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout->addWidget(toolButton_21);

        toolButton_15 = new QToolButton(scrollAreaWidgetContents);
        toolButton_15->setObjectName(QStringLiteral("toolButton_15"));
        sizePolicy.setHeightForWidth(toolButton_15->sizePolicy().hasHeightForWidth());
        toolButton_15->setSizePolicy(sizePolicy);
        toolButton_15->setMinimumSize(QSize(0, 40));
        toolButton_15->setMaximumSize(QSize(16777215, 40));
        toolButton_15->setFont(font1);
        toolButton_15->setStyleSheet(QStringLiteral(""));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/lib/regular.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_15->setIcon(icon10);
        toolButton_15->setIconSize(QSize(22, 22));
        toolButton_15->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout->addWidget(toolButton_15);

        toolButton_19 = new QToolButton(scrollAreaWidgetContents);
        toolButton_19->setObjectName(QStringLiteral("toolButton_19"));
        sizePolicy.setHeightForWidth(toolButton_19->sizePolicy().hasHeightForWidth());
        toolButton_19->setSizePolicy(sizePolicy);
        toolButton_19->setMinimumSize(QSize(0, 40));
        toolButton_19->setMaximumSize(QSize(16777215, 40));
        toolButton_19->setFont(font1);
        toolButton_19->setStyleSheet(QStringLiteral(""));
        toolButton_19->setIcon(icon10);
        toolButton_19->setIconSize(QSize(22, 22));
        toolButton_19->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout->addWidget(toolButton_19);

        toolButton_9 = new QToolButton(scrollAreaWidgetContents);
        toolButton_9->setObjectName(QStringLiteral("toolButton_9"));
        sizePolicy.setHeightForWidth(toolButton_9->sizePolicy().hasHeightForWidth());
        toolButton_9->setSizePolicy(sizePolicy);
        toolButton_9->setMinimumSize(QSize(0, 40));
        toolButton_9->setMaximumSize(QSize(16777215, 40));
        toolButton_9->setFont(font1);
        toolButton_9->setStyleSheet(QStringLiteral(""));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/lib/XML-Local-hover.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_9->setIcon(icon11);
        toolButton_9->setIconSize(QSize(22, 22));
        toolButton_9->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout->addWidget(toolButton_9);

        toolButton_17 = new QToolButton(scrollAreaWidgetContents);
        toolButton_17->setObjectName(QStringLiteral("toolButton_17"));
        sizePolicy.setHeightForWidth(toolButton_17->sizePolicy().hasHeightForWidth());
        toolButton_17->setSizePolicy(sizePolicy);
        toolButton_17->setMinimumSize(QSize(0, 40));
        toolButton_17->setMaximumSize(QSize(16777215, 40));
        toolButton_17->setFont(font1);
        toolButton_17->setStyleSheet(QStringLiteral(""));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/lib/Thrift5.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_17->setIcon(icon12);
        toolButton_17->setIconSize(QSize(22, 22));
        toolButton_17->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout->addWidget(toolButton_17);

        toolButton_14 = new QToolButton(scrollAreaWidgetContents);
        toolButton_14->setObjectName(QStringLiteral("toolButton_14"));
        sizePolicy.setHeightForWidth(toolButton_14->sizePolicy().hasHeightForWidth());
        toolButton_14->setSizePolicy(sizePolicy);
        toolButton_14->setMinimumSize(QSize(0, 40));
        toolButton_14->setMaximumSize(QSize(16777215, 40));
        toolButton_14->setFont(font1);
        toolButton_14->setStyleSheet(QStringLiteral(""));
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/lib/mysql.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_14->setIcon(icon13);
        toolButton_14->setIconSize(QSize(22, 22));
        toolButton_14->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout->addWidget(toolButton_14);

        toolButton_18 = new QToolButton(scrollAreaWidgetContents);
        toolButton_18->setObjectName(QStringLiteral("toolButton_18"));
        sizePolicy.setHeightForWidth(toolButton_18->sizePolicy().hasHeightForWidth());
        toolButton_18->setSizePolicy(sizePolicy);
        toolButton_18->setMinimumSize(QSize(0, 40));
        toolButton_18->setMaximumSize(QSize(16777215, 40));
        toolButton_18->setFont(font1);
        toolButton_18->setStyleSheet(QStringLiteral(""));
        QIcon icon14;
        icon14.addFile(QStringLiteral(":/lib/powershell.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_18->setIcon(icon14);
        toolButton_18->setIconSize(QSize(22, 22));
        toolButton_18->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout->addWidget(toolButton_18);

        toolButton_8 = new QToolButton(scrollAreaWidgetContents);
        toolButton_8->setObjectName(QStringLiteral("toolButton_8"));
        sizePolicy.setHeightForWidth(toolButton_8->sizePolicy().hasHeightForWidth());
        toolButton_8->setSizePolicy(sizePolicy);
        toolButton_8->setMinimumSize(QSize(0, 40));
        toolButton_8->setMaximumSize(QSize(16777215, 40));
        toolButton_8->setFont(font1);
        toolButton_8->setStyleSheet(QStringLiteral(""));
        QIcon icon15;
        icon15.addFile(QStringLiteral(":/lib/windows.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_8->setIcon(icon15);
        toolButton_8->setIconSize(QSize(22, 22));
        toolButton_8->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout->addWidget(toolButton_8);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_3->addWidget(scrollArea);


        horizontalLayout_4->addWidget(widget_left);

        widget_2 = new QWidget(toolswidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setStyleSheet(QStringLiteral(""));
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setSpacing(30);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, 0, 9, 9);
        widget = new QWidget(widget_2);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(0, 50));
        widget->setMaximumSize(QSize(16777215, 50));
        widget->setStyleSheet(QLatin1String("QToolButton {\n"
"    qproperty-iconSize: 22px 22px;\n"
"	/*padding-left: 15px;*/\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"	border: none;\n"
"	border-radius:0px;\n"
"	color: rgb(255, 255, 255);\n"
"	text-align: center;\n"
"}\n"
"\n"
"QToolButton::menu-indicator { \n"
"	image: None;\n"
"}\n"
"\n"
"QToolButton:hover {\n"
"	border-radius:0px;\n"
"	color: rgb(255, 255, 255);\n"
"	\n"
"	background-color: rgba(20, 30, 36,0);\n"
"	border: none;\n"
"}\n"
" \n"
"QToolButton:checked {\n"
"	border-radius:0px;\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgba(20, 30, 36,0);\n"
"	border: none;\n"
"}"));
        horizontalLayout_5 = new QHBoxLayout(widget);
        horizontalLayout_5->setSpacing(11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(1, 9, 0, 2);
        toolButton_3 = new QToolButton(widget);
        toolButton_3->setObjectName(QStringLiteral("toolButton_3"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(toolButton_3->sizePolicy().hasHeightForWidth());
        toolButton_3->setSizePolicy(sizePolicy2);
        toolButton_3->setMinimumSize(QSize(20, 20));
        toolButton_3->setMaximumSize(QSize(20, 20));
        QIcon icon16;
        icon16.addFile(QStringLiteral(":/lib/left1.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_3->setIcon(icon16);
        toolButton_3->setIconSize(QSize(22, 22));

        horizontalLayout_5->addWidget(toolButton_3);

        toolButton_4 = new QToolButton(widget);
        toolButton_4->setObjectName(QStringLiteral("toolButton_4"));
        toolButton_4->setMinimumSize(QSize(20, 20));
        toolButton_4->setMaximumSize(QSize(20, 20));
        toolButton_4->setStyleSheet(QStringLiteral(""));
        QIcon icon17;
        icon17.addFile(QStringLiteral(":/lib/right1.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_4->setIcon(icon17);
        toolButton_4->setIconSize(QSize(22, 22));

        horizontalLayout_5->addWidget(toolButton_4);

        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        QFont font2;
        font2.setFamily(QStringLiteral("OPPOSans B"));
        font2.setPointSize(12);
        label->setFont(font2);

        horizontalLayout_5->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        lineEdit_find = new QLineEdit(widget);
        lineEdit_find->setObjectName(QStringLiteral("lineEdit_find"));
        lineEdit_find->setMinimumSize(QSize(300, 35));
        lineEdit_find->setMaximumSize(QSize(700, 16777215));
        lineEdit_find->setFont(font1);
        lineEdit_find->setStyleSheet(QLatin1String("QLineEdit{\n"
"color: rgb(231, 238, 244);\n"
"border-radius: 14px;\n"
"background-color: rgb(25, 25, 25, 255);\n"
"border: 0px solid rgba(255, 255, 255, 0);\n"
"border-radius: 10px;\n"
"padding-left:10px;\n"
"padding-right:10px;\n"
"}"));

        horizontalLayout_5->addWidget(lineEdit_find);


        verticalLayout_2->addWidget(widget);

        stackedWidget = new QStackedWidget(widget_2);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setStyleSheet(QString::fromUtf8("QScrollBar:vertical{\n"
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
"QScrollBar::sub-line:vertical {\n"
"    border: none;\n"
"    height: 0px;\n"
"    subcontrol-posit"
                        "ion: top;\n"
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
        page_md5 = new QWidget();
        page_md5->setObjectName(QStringLiteral("page_md5"));
        page_md5->setStyleSheet(QLatin1String("QPlainTextEdit{\n"
"color: rgb(38, 38, 38);\n"
"border-radius: 14px;\n"
"	background-color: rgb(255, 255, 255);\n"
"border: 0px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding:5px;\n"
"}"));
        plainTextEdit_data = new QPlainTextEdit(page_md5);
        plainTextEdit_data->setObjectName(QStringLiteral("plainTextEdit_data"));
        plainTextEdit_data->setGeometry(QRect(10, 10, 320, 311));
        plainTextEdit_data->setMinimumSize(QSize(320, 0));
        plainTextEdit_data->setMaximumSize(QSize(320, 16777215));
        QFont font3;
        font3.setFamily(QStringLiteral("OPPOSans"));
        font3.setPointSize(10);
        font3.setStyleStrategy(QFont::PreferAntialias);
        plainTextEdit_data->setFont(font3);
        widget_5 = new QWidget(page_md5);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setGeometry(QRect(10, 340, 321, 30));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(widget_5->sizePolicy().hasHeightForWidth());
        widget_5->setSizePolicy(sizePolicy3);
        widget_5->setMinimumSize(QSize(0, 30));
        widget_5->setMaximumSize(QSize(16777215, 30));
        horizontalLayout_7 = new QHBoxLayout(widget_5);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        toolButton_encipher = new QToolButton(widget_5);
        toolButton_encipher->setObjectName(QStringLiteral("toolButton_encipher"));
        toolButton_encipher->setMinimumSize(QSize(100, 30));
        toolButton_encipher->setMaximumSize(QSize(200, 30));
        toolButton_encipher->setFont(font1);

        horizontalLayout_7->addWidget(toolButton_encipher);

        toolButton_clear = new QToolButton(widget_5);
        toolButton_clear->setObjectName(QStringLiteral("toolButton_clear"));
        toolButton_clear->setMinimumSize(QSize(100, 30));
        toolButton_clear->setMaximumSize(QSize(200, 30));
        toolButton_clear->setFont(font1);

        horizontalLayout_7->addWidget(toolButton_clear);

        gridWidget = new QWidget(page_md5);
        gridWidget->setObjectName(QStringLiteral("gridWidget"));
        gridWidget->setGeometry(QRect(380, 10, 371, 311));
        sizePolicy3.setHeightForWidth(gridWidget->sizePolicy().hasHeightForWidth());
        gridWidget->setSizePolicy(sizePolicy3);
        gridWidget->setMinimumSize(QSize(0, 200));
        gridWidget->setMaximumSize(QSize(16777215, 16777215));
        gridWidget->setFont(font1);
        gridLayout = new QGridLayout(gridWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(20);
        gridLayout->setVerticalSpacing(6);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(gridWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(60, 0));
        label_4->setMaximumSize(QSize(60, 16777215));
        QFont font4;
        font4.setFamily(QStringLiteral("OPPOSans B"));
        font4.setPointSize(10);
        font4.setStyleStrategy(QFont::PreferAntialias);
        label_4->setFont(font4);
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout->addWidget(label_4, 5, 0, 1, 1);

        label_3 = new QLabel(gridWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(60, 0));
        label_3->setMaximumSize(QSize(60, 16777215));
        label_3->setFont(font4);
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        plainTextEdit_16Lower = new QPlainTextEdit(gridWidget);
        plainTextEdit_16Lower->setObjectName(QStringLiteral("plainTextEdit_16Lower"));
        plainTextEdit_16Lower->setMinimumSize(QSize(0, 70));
        plainTextEdit_16Lower->setMaximumSize(QSize(450, 70));
        plainTextEdit_16Lower->setFont(font1);
        plainTextEdit_16Lower->setReadOnly(true);

        gridLayout->addWidget(plainTextEdit_16Lower, 0, 1, 1, 1);

        plainTextEdit_16 = new QPlainTextEdit(gridWidget);
        plainTextEdit_16->setObjectName(QStringLiteral("plainTextEdit_16"));
        plainTextEdit_16->setMinimumSize(QSize(0, 70));
        plainTextEdit_16->setMaximumSize(QSize(450, 70));
        plainTextEdit_16->setFont(font1);
        plainTextEdit_16->setReadOnly(true);

        gridLayout->addWidget(plainTextEdit_16, 1, 1, 1, 1);

        label_6 = new QLabel(gridWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(60, 0));
        label_6->setMaximumSize(QSize(60, 16777215));
        label_6->setFont(font4);
        label_6->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout->addWidget(label_6, 0, 0, 1, 1);

        toolButton_12 = new QToolButton(gridWidget);
        toolButton_12->setObjectName(QStringLiteral("toolButton_12"));
        toolButton_12->setMinimumSize(QSize(60, 30));
        toolButton_12->setMaximumSize(QSize(60, 30));
        toolButton_12->setFont(font1);

        gridLayout->addWidget(toolButton_12, 3, 2, 1, 1);

        toolButton_13 = new QToolButton(gridWidget);
        toolButton_13->setObjectName(QStringLiteral("toolButton_13"));
        toolButton_13->setMinimumSize(QSize(60, 30));
        toolButton_13->setMaximumSize(QSize(60, 30));
        toolButton_13->setFont(font1);

        gridLayout->addWidget(toolButton_13, 5, 2, 1, 1);

        toolButton_10 = new QToolButton(gridWidget);
        toolButton_10->setObjectName(QStringLiteral("toolButton_10"));
        toolButton_10->setMinimumSize(QSize(60, 30));
        toolButton_10->setMaximumSize(QSize(60, 30));
        toolButton_10->setFont(font1);

        gridLayout->addWidget(toolButton_10, 1, 2, 1, 1);

        label_5 = new QLabel(gridWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(60, 0));
        label_5->setMaximumSize(QSize(60, 16777215));
        label_5->setFont(font4);
        label_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout->addWidget(label_5, 1, 0, 1, 1);

        toolButton_6 = new QToolButton(gridWidget);
        toolButton_6->setObjectName(QStringLiteral("toolButton_6"));
        toolButton_6->setMinimumSize(QSize(60, 30));
        toolButton_6->setMaximumSize(QSize(60, 30));
        toolButton_6->setFont(font1);

        gridLayout->addWidget(toolButton_6, 0, 2, 1, 1);

        plainTextEdit_32Lower = new QPlainTextEdit(gridWidget);
        plainTextEdit_32Lower->setObjectName(QStringLiteral("plainTextEdit_32Lower"));
        plainTextEdit_32Lower->setMinimumSize(QSize(0, 70));
        plainTextEdit_32Lower->setMaximumSize(QSize(450, 70));
        plainTextEdit_32Lower->setFont(font1);
        plainTextEdit_32Lower->setReadOnly(true);

        gridLayout->addWidget(plainTextEdit_32Lower, 3, 1, 1, 1);

        plainTextEdit_32 = new QPlainTextEdit(gridWidget);
        plainTextEdit_32->setObjectName(QStringLiteral("plainTextEdit_32"));
        plainTextEdit_32->setMinimumSize(QSize(0, 70));
        plainTextEdit_32->setMaximumSize(QSize(450, 70));
        plainTextEdit_32->setFont(font1);
        plainTextEdit_32->setReadOnly(true);

        gridLayout->addWidget(plainTextEdit_32, 5, 1, 1, 1);

        label_7 = new QLabel(page_md5);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 400, 50, 30));
        label_7->setMinimumSize(QSize(50, 0));
        label_7->setMaximumSize(QSize(50, 16777215));
        label_7->setFont(font4);
        toolButton_32Lower_10 = new QToolButton(page_md5);
        toolButton_32Lower_10->setObjectName(QStringLiteral("toolButton_32Lower_10"));
        toolButton_32Lower_10->setGeometry(QRect(10, 440, 138, 30));
        toolButton_32Lower_10->setMinimumSize(QSize(100, 30));
        toolButton_32Lower_10->setMaximumSize(QSize(200, 30));
        toolButton_32Lower_10->setFont(font1);
        toolButton_32_10 = new QToolButton(page_md5);
        toolButton_32_10->setObjectName(QStringLiteral("toolButton_32_10"));
        toolButton_32_10->setGeometry(QRect(160, 440, 138, 30));
        toolButton_32_10->setMinimumSize(QSize(100, 30));
        toolButton_32_10->setMaximumSize(QSize(200, 30));
        toolButton_32_10->setFont(font1);
        toolButton_16Lower_10 = new QToolButton(page_md5);
        toolButton_16Lower_10->setObjectName(QStringLiteral("toolButton_16Lower_10"));
        toolButton_16Lower_10->setGeometry(QRect(310, 440, 138, 30));
        toolButton_16Lower_10->setMinimumSize(QSize(100, 30));
        toolButton_16Lower_10->setMaximumSize(QSize(200, 30));
        toolButton_16Lower_10->setFont(font1);
        toolButton_16_10 = new QToolButton(page_md5);
        toolButton_16_10->setObjectName(QStringLiteral("toolButton_16_10"));
        toolButton_16_10->setGeometry(QRect(460, 440, 138, 30));
        toolButton_16_10->setMinimumSize(QSize(100, 30));
        toolButton_16_10->setMaximumSize(QSize(200, 30));
        toolButton_16_10->setFont(font1);
        stackedWidget->addWidget(page_md5);
        page_json = new QWidget();
        page_json->setObjectName(QStringLiteral("page_json"));
        horizontalLayout_2 = new QHBoxLayout(page_json);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 8);
        splitter = new QSplitter(page_json);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setFrameShadow(QFrame::Plain);
        splitter->setLineWidth(5);
        splitter->setOrientation(Qt::Horizontal);
        splitter->setHandleWidth(20);
        plainTextEdit_json_source = new QPlainTextEdit(splitter);
        plainTextEdit_json_source->setObjectName(QStringLiteral("plainTextEdit_json_source"));
        QFont font5;
        font5.setFamily(QStringLiteral("Cascadia Code SemiBold"));
        font5.setPointSize(11);
        font5.setBold(false);
        font5.setItalic(false);
        font5.setWeight(50);
        plainTextEdit_json_source->setFont(font5);
        plainTextEdit_json_source->setStyleSheet(QLatin1String("QPlainTextEdit{\n"
"color: rgb(38, 38, 38);\n"
"border-radius: 14px;\n"
"background-color: rgb(255, 255, 255);\n"
"border: 0px solid rgba(255, 255, 255, 0);\n"
"\n"
"border-radius: 5px;\n"
"padding:5px;\n"
"}"));
        splitter->addWidget(plainTextEdit_json_source);
        textEdit_json_target = new QTextEdit(splitter);
        textEdit_json_target->setObjectName(QStringLiteral("textEdit_json_target"));
        textEdit_json_target->setFont(font5);
        textEdit_json_target->setStyleSheet(QLatin1String("QTextEdit{\n"
"color: rgb(56, 56, 56);\n"
"\n"
"border-radius: 14px;\n"
"	background-color: rgb(255, 255, 255);\n"
"border: 0px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding:5px;\n"
"}"));
        splitter->addWidget(textEdit_json_target);

        horizontalLayout_2->addWidget(splitter);

        stackedWidget->addWidget(page_json);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        verticalLayout_4 = new QVBoxLayout(page_3);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        widget_3 = new QWidget(page_3);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMinimumSize(QSize(0, 100));
        widget_3->setMaximumSize(QSize(16777215, 100));
        horizontalLayout_6 = new QHBoxLayout(widget_3);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        lineEdit = new QLineEdit(widget_3);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(0, 80));
        lineEdit->setMaximumSize(QSize(16777215, 80));
        lineEdit->setStyleSheet(QStringLiteral("background-color: rgb(113, 108, 255);"));

        horizontalLayout_6->addWidget(lineEdit);

        lineEdit_2 = new QLineEdit(widget_3);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setMinimumSize(QSize(0, 80));
        lineEdit_2->setStyleSheet(QStringLiteral("background-color: rgb(113, 108, 255);"));

        horizontalLayout_6->addWidget(lineEdit_2);

        toolButton_25 = new QToolButton(widget_3);
        toolButton_25->setObjectName(QStringLiteral("toolButton_25"));
        toolButton_25->setMinimumSize(QSize(0, 50));
        toolButton_25->setMaximumSize(QSize(16777215, 50));

        horizontalLayout_6->addWidget(toolButton_25);


        verticalLayout_4->addWidget(widget_3);

        textEdit = new QTextEdit(page_3);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        QFont font6;
        font6.setFamily(QStringLiteral("Cascadia Code SemiBold"));
        font6.setPointSize(10);
        textEdit->setFont(font6);
        textEdit->setStyleSheet(QStringLiteral("background-color: rgb(113, 108, 255);"));
        textEdit->setLineWrapMode(QTextEdit::WidgetWidth);
        textEdit->setLineWrapColumnOrWidth(50);

        verticalLayout_4->addWidget(textEdit);

        stackedWidget->addWidget(page_3);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        lineEdit_now_timestamp = new QLineEdit(page_2);
        lineEdit_now_timestamp->setObjectName(QStringLiteral("lineEdit_now_timestamp"));
        lineEdit_now_timestamp->setGeometry(QRect(10, 40, 165, 32));
        lineEdit_now_timestamp->setMinimumSize(QSize(165, 32));
        lineEdit_now_timestamp->setMaximumSize(QSize(165, 32));
        lineEdit_now_timestamp->setFont(font4);
        lineEdit_now_timestamp->setStyleSheet(QLatin1String("background-color: rgb(25, 25, 25, 155);\n"
"border: 1px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding-left:5px;\n"
"/*padding-right:10px;*/"));
        lineEdit_now_timestamp->setReadOnly(true);
        comboBox_time2date = new QComboBox(page_2);
        comboBox_time2date->addItem(QString());
        comboBox_time2date->addItem(QString());
        comboBox_time2date->setObjectName(QStringLiteral("comboBox_time2date"));
        comboBox_time2date->setGeometry(QRect(200, 120, 80, 32));
        comboBox_time2date->setMinimumSize(QSize(80, 32));
        comboBox_time2date->setMaximumSize(QSize(60, 32));
        comboBox_time2date->setFont(font4);
        comboBox_time2date->setStyleSheet(QLatin1String("QComboBox{ \n"
"border:0px solid gray;  \n"
"border-radius:5px;  \n"
"/*padding: 5px; */\n"
"/*min-width:4em;*/\n"
"}\n"
"\n"
"QComboBox::drop-down{\n"
"subcontrol-origin:padding; \n"
"subcontrol-position:top right; \n"
"width:20px; \n"
"/*border-left-width:1px;*/\n"
"border-left-color:darkgray;\n"
"border-left-style:solid; \n"
"border-top-right-radius:3px; \n"
"border-bottom-right-radius:3px;\n"
"}\n"
"QComboBox QAbstractItemView{\n"
"border: 2px solid #4E6D8C;\n"
"}\n"
"QComboBox::down-arrow{\n"
"border-image: url(:/lib/up.png);\n"
"    width:20px;\n"
"	height:20px;\n"
"\n"
"}\n"
""));
        lineEdit_date2time_in = new QLineEdit(page_2);
        lineEdit_date2time_in->setObjectName(QStringLiteral("lineEdit_date2time_in"));
        lineEdit_date2time_in->setGeometry(QRect(10, 190, 170, 32));
        lineEdit_date2time_in->setMinimumSize(QSize(170, 32));
        lineEdit_date2time_in->setMaximumSize(QSize(170, 32));
        lineEdit_date2time_in->setFont(font4);
        lineEdit_date2time_in->setStyleSheet(QLatin1String("background-color: rgb(25, 25, 25, 155);\n"
"border: 1px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding-left:5px;\n"
"/*padding-right:10px;*/"));
        lineEdit_date2time_out = new QLineEdit(page_2);
        lineEdit_date2time_out->setObjectName(QStringLiteral("lineEdit_date2time_out"));
        lineEdit_date2time_out->setGeometry(QRect(390, 190, 170, 32));
        lineEdit_date2time_out->setMinimumSize(QSize(170, 32));
        lineEdit_date2time_out->setMaximumSize(QSize(170, 32));
        lineEdit_date2time_out->setFont(font4);
        lineEdit_date2time_out->setStyleSheet(QLatin1String("background-color: rgb(25, 25, 25, 155);\n"
"border: 1px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding-left:5px;\n"
"/*padding-right:10px;*/"));
        lineEdit_time2date_in = new QLineEdit(page_2);
        lineEdit_time2date_in->setObjectName(QStringLiteral("lineEdit_time2date_in"));
        lineEdit_time2date_in->setGeometry(QRect(10, 120, 170, 32));
        lineEdit_time2date_in->setMinimumSize(QSize(170, 32));
        lineEdit_time2date_in->setMaximumSize(QSize(170, 32));
        lineEdit_time2date_in->setFont(font4);
        lineEdit_time2date_in->setStyleSheet(QLatin1String("background-color: rgb(25, 25, 25, 155);\n"
"border: 1px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding-left:5px;\n"
"/*padding-right:10px;*/"));
        toolButton_timestamp_copy = new QToolButton(page_2);
        toolButton_timestamp_copy->setObjectName(QStringLiteral("toolButton_timestamp_copy"));
        toolButton_timestamp_copy->setGeometry(QRect(200, 40, 80, 30));
        toolButton_timestamp_copy->setMinimumSize(QSize(80, 30));
        toolButton_timestamp_copy->setMaximumSize(QSize(80, 30));
        toolButton_timestamp_copy->setFont(font4);
        toolButton_timestamp_copy->setStyleSheet(QLatin1String("QToolButton {\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(7, 143, 255);\n"
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
"	background-color: rgb(7, 143, 255);\n"
"}"));
        lineEdit_time2date_out = new QLineEdit(page_2);
        lineEdit_time2date_out->setObjectName(QStringLiteral("lineEdit_time2date_out"));
        lineEdit_time2date_out->setGeometry(QRect(390, 120, 170, 32));
        lineEdit_time2date_out->setMinimumSize(QSize(170, 32));
        lineEdit_time2date_out->setMaximumSize(QSize(170, 32));
        lineEdit_time2date_out->setFont(font4);
        lineEdit_time2date_out->setStyleSheet(QLatin1String("background-color: rgb(25, 25, 25, 155);\n"
"border: 1px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding-left:5px;\n"
"/*padding-right:10px;*/"));
        toolButton_date2time = new QToolButton(page_2);
        toolButton_date2time->setObjectName(QStringLiteral("toolButton_date2time"));
        toolButton_date2time->setGeometry(QRect(290, 190, 80, 32));
        toolButton_date2time->setMinimumSize(QSize(80, 32));
        toolButton_date2time->setMaximumSize(QSize(80, 32));
        toolButton_date2time->setFont(font4);
        toolButton_date2time->setStyleSheet(QLatin1String("QToolButton {\n"
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
        comboBox_date2time = new QComboBox(page_2);
        comboBox_date2time->addItem(QString());
        comboBox_date2time->addItem(QString());
        comboBox_date2time->setObjectName(QStringLiteral("comboBox_date2time"));
        comboBox_date2time->setGeometry(QRect(200, 190, 80, 32));
        comboBox_date2time->setMinimumSize(QSize(80, 32));
        comboBox_date2time->setMaximumSize(QSize(60, 32));
        comboBox_date2time->setFont(font4);
        comboBox_date2time->setStyleSheet(QLatin1String("QComboBox{ \n"
"border:0px solid gray;  \n"
"border-radius:5px;  \n"
"/*padding: 5px; */\n"
"/*min-width:4em;*/\n"
"}\n"
"\n"
"QComboBox::drop-down{\n"
"subcontrol-origin:padding; \n"
"subcontrol-position:top right; \n"
"width:20px; \n"
"/*border-left-width:1px;*/\n"
"border-left-color:darkgray;\n"
"border-left-style:solid; \n"
"border-top-right-radius:3px; \n"
"border-bottom-right-radius:3px;\n"
"}\n"
"QComboBox QAbstractItemView{\n"
"border: 2px solid #4E6D8C;\n"
"}\n"
"QComboBox::down-arrow{\n"
"border-image: url(:/lib/up.png);\n"
"    width:20px;\n"
"	height:20px;\n"
"\n"
"}\n"
""));
        label_now_timestamp = new QLabel(page_2);
        label_now_timestamp->setObjectName(QStringLiteral("label_now_timestamp"));
        label_now_timestamp->setGeometry(QRect(10, 8, 165, 32));
        label_now_timestamp->setMinimumSize(QSize(0, 32));
        label_now_timestamp->setMaximumSize(QSize(16777215, 32));
        label_now_timestamp->setFont(font4);
        label_time2date = new QLabel(page_2);
        label_time2date->setObjectName(QStringLiteral("label_time2date"));
        label_time2date->setGeometry(QRect(10, 88, 165, 32));
        label_time2date->setMinimumSize(QSize(0, 32));
        label_time2date->setMaximumSize(QSize(16777215, 32));
        label_time2date->setFont(font4);
        label_date2time = new QLabel(page_2);
        label_date2time->setObjectName(QStringLiteral("label_date2time"));
        label_date2time->setGeometry(QRect(10, 160, 165, 32));
        label_date2time->setMinimumSize(QSize(0, 32));
        label_date2time->setMaximumSize(QSize(16777215, 32));
        label_date2time->setFont(font4);
        toolButton_time2date = new QToolButton(page_2);
        toolButton_time2date->setObjectName(QStringLiteral("toolButton_time2date"));
        toolButton_time2date->setGeometry(QRect(290, 120, 80, 32));
        toolButton_time2date->setMinimumSize(QSize(80, 32));
        toolButton_time2date->setMaximumSize(QSize(80, 32));
        toolButton_time2date->setFont(font4);
        toolButton_time2date->setStyleSheet(QLatin1String("QToolButton {\n"
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
        stackedWidget->addWidget(page_2);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        label_hex = new QLabel(page);
        label_hex->setObjectName(QStringLiteral("label_hex"));
        label_hex->setGeometry(QRect(10, 66, 845, 17));
        label_hex->setFont(font4);
        lineEdit_hex = new QLineEdit(page);
        lineEdit_hex->setObjectName(QStringLiteral("lineEdit_hex"));
        lineEdit_hex->setGeometry(QRect(20, 90, 621, 32));
        lineEdit_hex->setMinimumSize(QSize(0, 32));
        lineEdit_hex->setMaximumSize(QSize(16777215, 32));
        lineEdit_hex->setFont(font4);
        lineEdit_hex->setStyleSheet(QLatin1String("background-color: rgb(25, 25, 25, 155);\n"
"border: 1px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding-left:10px;\n"
"padding-right:10px;"));
        lineEdit_oct = new QLineEdit(page);
        lineEdit_oct->setObjectName(QStringLiteral("lineEdit_oct"));
        lineEdit_oct->setGeometry(QRect(10, 280, 631, 32));
        lineEdit_oct->setMinimumSize(QSize(0, 32));
        lineEdit_oct->setMaximumSize(QSize(16777215, 32));
        lineEdit_oct->setFont(font4);
        lineEdit_oct->setStyleSheet(QLatin1String("background-color: rgb(25, 25, 25, 155);\n"
"border: 1px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding-left:10px;\n"
"padding-right:10px;"));
        lineEdit_bin = new QLineEdit(page);
        lineEdit_bin->setObjectName(QStringLiteral("lineEdit_bin"));
        lineEdit_bin->setGeometry(QRect(10, 370, 581, 32));
        lineEdit_bin->setMinimumSize(QSize(0, 32));
        lineEdit_bin->setMaximumSize(QSize(16777215, 32));
        lineEdit_bin->setFont(font4);
        lineEdit_bin->setStyleSheet(QLatin1String("background-color: rgb(25, 25, 25, 155);\n"
"border: 1px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding-left:10px;\n"
"padding-right:10px;"));
        label_dec = new QLabel(page);
        label_dec->setObjectName(QStringLiteral("label_dec"));
        label_dec->setGeometry(QRect(10, 154, 845, 17));
        label_dec->setFont(font4);
        lineEdit_dec = new QLineEdit(page);
        lineEdit_dec->setObjectName(QStringLiteral("lineEdit_dec"));
        lineEdit_dec->setGeometry(QRect(10, 190, 631, 32));
        lineEdit_dec->setMinimumSize(QSize(0, 32));
        lineEdit_dec->setMaximumSize(QSize(16777215, 32));
        lineEdit_dec->setFont(font4);
        lineEdit_dec->setStyleSheet(QLatin1String("background-color: rgb(25, 25, 25, 155);\n"
"border: 1px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding-left:10px;\n"
"padding-right:10px;"));
        label_oct = new QLabel(page);
        label_oct->setObjectName(QStringLiteral("label_oct"));
        label_oct->setGeometry(QRect(10, 242, 845, 17));
        label_oct->setFont(font4);
        label_bin = new QLabel(page);
        label_bin->setObjectName(QStringLiteral("label_bin"));
        label_bin->setGeometry(QRect(10, 330, 845, 17));
        label_bin->setFont(font4);
        stackedWidget->addWidget(page);
        page_xml = new QWidget();
        page_xml->setObjectName(QStringLiteral("page_xml"));
        horizontalLayout_3 = new QHBoxLayout(page_xml);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        splitter_2 = new QSplitter(page_xml);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        textEdit_xml_source = new QTextEdit(splitter_2);
        textEdit_xml_source->setObjectName(QStringLiteral("textEdit_xml_source"));
        QFont font7;
        font7.setFamily(QStringLiteral("OPPOSans"));
        font7.setPointSize(12);
        font7.setStyleStrategy(QFont::PreferAntialias);
        textEdit_xml_source->setFont(font7);
        splitter_2->addWidget(textEdit_xml_source);
        textEdit_xml_target = new QTextEdit(splitter_2);
        textEdit_xml_target->setObjectName(QStringLiteral("textEdit_xml_target"));
        textEdit_xml_target->setFont(font7);
        splitter_2->addWidget(textEdit_xml_target);

        horizontalLayout_3->addWidget(splitter_2);

        stackedWidget->addWidget(page_xml);
        page_diff = new QWidget();
        page_diff->setObjectName(QStringLiteral("page_diff"));
        horizontalLayout = new QHBoxLayout(page_diff);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        splitter_3 = new QSplitter(page_diff);
        splitter_3->setObjectName(QStringLiteral("splitter_3"));
        splitter_3->setOrientation(Qt::Horizontal);
        textEdit_diff_source = new QTextEdit(splitter_3);
        textEdit_diff_source->setObjectName(QStringLiteral("textEdit_diff_source"));
        textEdit_diff_source->setFont(font7);
        splitter_3->addWidget(textEdit_diff_source);
        textEdit_diff_target = new QTextEdit(splitter_3);
        textEdit_diff_target->setObjectName(QStringLiteral("textEdit_diff_target"));
        textEdit_diff_target->setFont(font7);
        splitter_3->addWidget(textEdit_diff_target);

        horizontalLayout->addWidget(splitter_3);

        stackedWidget->addWidget(page_diff);

        verticalLayout_2->addWidget(stackedWidget);


        horizontalLayout_4->addWidget(widget_2);

        widget_2->raise();
        widget_left->raise();

        retranslateUi(toolswidget);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(toolswidget);
    } // setupUi

    void retranslateUi(QWidget *toolswidget)
    {
        toolswidget->setWindowTitle(QApplication::translate("toolswidget", "Form", nullptr));
        label_2->setText(QApplication::translate("toolswidget", "\345\267\245\345\205\267\347\256\261", nullptr));
        toolButton_md5->setText(QApplication::translate("toolswidget", " MD5\345\212\240\345\257\206", nullptr));
        toolButton_json->setText(QApplication::translate("toolswidget", " JSON\346\240\274\345\274\217\345\214\226", nullptr));
        toolButton_timestamp->setText(QApplication::translate("toolswidget", " \346\227\266\351\227\264\346\210\263", nullptr));
        toolButton_conversion->setText(QApplication::translate("toolswidget", " \350\277\233\345\210\266\350\275\254\346\215\242", nullptr));
        toolButton_url->setText(QApplication::translate("toolswidget", " URL\347\274\226\347\240\201", nullptr));
        toolButton_7->setText(QApplication::translate("toolswidget", " \350\256\241\347\256\227\345\231\250", nullptr));
        toolButton_20->setText(QApplication::translate("toolswidget", " Qt\346\216\247\344\273\266\347\276\216\345\214\226", nullptr));
        toolButton->setText(QApplication::translate("toolswidget", " XML\346\240\274\345\274\217\345\214\226", nullptr));
        toolButton_11->setText(QApplication::translate("toolswidget", " \344\276\277\347\255\276", nullptr));
        toolButton_21->setText(QApplication::translate("toolswidget", " Linux\345\270\270\347\224\250\345\221\275\344\273\244", nullptr));
        toolButton_15->setText(QApplication::translate("toolswidget", " \346\255\243\345\210\231\350\241\250\350\276\276\345\274\217\351\252\214\350\257\201", nullptr));
        toolButton_19->setText(QApplication::translate("toolswidget", " \345\270\270\347\224\250\350\265\204\346\272\220\347\275\221\347\253\231", nullptr));
        toolButton_9->setText(QApplication::translate("toolswidget", " \346\226\207\346\234\254\345\206\205\345\256\271\345\257\271\346\257\224", nullptr));
        toolButton_17->setText(QApplication::translate("toolswidget", " thrift\346\216\245\345\217\243\346\265\213\350\257\225", nullptr));
        toolButton_14->setText(QApplication::translate("toolswidget", " \346\225\260\346\215\256\345\272\223\350\277\236\346\216\245", nullptr));
        toolButton_18->setText(QApplication::translate("toolswidget", " SSH\350\277\236\346\216\245", nullptr));
        toolButton_8->setText(QApplication::translate("toolswidget", " windows\350\277\234\347\250\213\350\277\236\346\216\245", nullptr));
        toolButton_3->setText(QString());
        toolButton_4->setText(QString());
        label->setText(QApplication::translate("toolswidget", "MD5\345\212\240\345\257\206", nullptr));
        lineEdit_find->setPlaceholderText(QApplication::translate("toolswidget", "\346\220\234\347\264\242\345\267\245\345\205\267", nullptr));
        toolButton_encipher->setText(QApplication::translate("toolswidget", "\345\212\240\345\257\206", nullptr));
        toolButton_clear->setText(QApplication::translate("toolswidget", "\346\270\205\347\251\272", nullptr));
        label_4->setText(QApplication::translate("toolswidget", "32\344\275\215\345\244\247\345\206\231\357\274\232", nullptr));
        label_3->setText(QApplication::translate("toolswidget", "32\344\275\215\345\260\217\345\206\231\357\274\232", nullptr));
        plainTextEdit_16Lower->setPlainText(QString());
        label_6->setText(QApplication::translate("toolswidget", "16\344\275\215\345\260\217\345\206\231\357\274\232", nullptr));
        toolButton_12->setText(QApplication::translate("toolswidget", "\345\244\215\345\210\266", nullptr));
        toolButton_13->setText(QApplication::translate("toolswidget", "\345\244\215\345\210\266", nullptr));
        toolButton_10->setText(QApplication::translate("toolswidget", "\345\244\215\345\210\266", nullptr));
        label_5->setText(QApplication::translate("toolswidget", "16\344\275\215\345\244\247\345\206\231\357\274\232", nullptr));
        toolButton_6->setText(QApplication::translate("toolswidget", "\345\244\215\345\210\266", nullptr));
        label_7->setText(QApplication::translate("toolswidget", "\346\211\251\345\261\225\357\274\232", nullptr));
        toolButton_32Lower_10->setText(QApplication::translate("toolswidget", "\350\216\267\345\217\22632\344\275\215\345\260\217\345\206\231\345\211\21510\344\275\215", nullptr));
        toolButton_32_10->setText(QApplication::translate("toolswidget", "\350\216\267\345\217\22632\344\275\215\345\244\247\345\206\231\345\211\21510\344\275\215", nullptr));
        toolButton_16Lower_10->setText(QApplication::translate("toolswidget", "\350\216\267\345\217\22616\344\275\215\345\244\247\345\206\231\345\211\21510\344\275\215", nullptr));
        toolButton_16_10->setText(QApplication::translate("toolswidget", "\350\216\267\345\217\22616\344\275\215\345\244\247\345\206\231\345\211\21510\344\275\215", nullptr));
        plainTextEdit_json_source->setPlainText(QString());
        textEdit_json_target->setHtml(QApplication::translate("toolswidget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Cascadia Code SemiBold'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        toolButton_25->setText(QApplication::translate("toolswidget", "...", nullptr));
        textEdit->setHtml(QApplication::translate("toolswidget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Cascadia Code SemiBold'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Arial';\"><br /></p></body></html>", nullptr));
        comboBox_time2date->setItemText(0, QApplication::translate("toolswidget", "\347\247\222", nullptr));
        comboBox_time2date->setItemText(1, QApplication::translate("toolswidget", "\346\257\253\347\247\222", nullptr));

        lineEdit_time2date_in->setText(QString());
        toolButton_timestamp_copy->setText(QApplication::translate("toolswidget", "\345\244\215\345\210\266", nullptr));
        lineEdit_time2date_out->setText(QString());
        toolButton_date2time->setText(QApplication::translate("toolswidget", "\350\275\254\346\215\242", nullptr));
        comboBox_date2time->setItemText(0, QApplication::translate("toolswidget", "\347\247\222", nullptr));
        comboBox_date2time->setItemText(1, QApplication::translate("toolswidget", "\346\257\253\347\247\222", nullptr));

        label_now_timestamp->setText(QApplication::translate("toolswidget", "\345\275\223\345\211\215\346\227\266\351\227\264\346\210\263:", nullptr));
        label_time2date->setText(QApplication::translate("toolswidget", "\346\227\266\351\227\264\346\210\263\350\275\254\346\227\245\346\234\237", nullptr));
        label_date2time->setText(QApplication::translate("toolswidget", "\346\227\266\351\227\264\350\275\254\346\227\266\351\227\264\346\210\263", nullptr));
        toolButton_time2date->setText(QApplication::translate("toolswidget", "\350\275\254\346\215\242", nullptr));
        label_hex->setText(QApplication::translate("toolswidget", "\345\215\201\345\205\255\350\277\233\345\210\266", nullptr));
        label_dec->setText(QApplication::translate("toolswidget", "\345\215\201\350\277\233\345\210\266", nullptr));
        label_oct->setText(QApplication::translate("toolswidget", "\345\205\253\350\277\233\345\210\266", nullptr));
        label_bin->setText(QApplication::translate("toolswidget", "\344\272\214\350\277\233\345\210\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class toolswidget: public Ui_toolswidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLSWIDGET_H
