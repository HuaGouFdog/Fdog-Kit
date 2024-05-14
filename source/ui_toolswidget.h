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
    QToolButton *toolButton_2;
    QToolButton *toolButton_11;
    QToolButton *toolButton_7;
    QToolButton *toolButton_10;
    QToolButton *toolButton_6;
    QToolButton *toolButton_13;
    QToolButton *toolButton_12;
    QToolButton *toolButton;
    QToolButton *toolButton_18;
    QToolButton *toolButton_20;
    QToolButton *toolButton_14;
    QToolButton *toolButton_21;
    QToolButton *toolButton_15;
    QToolButton *toolButton_9;
    QToolButton *toolButton_17;
    QToolButton *toolButton_8;
    QToolButton *toolButton_19;
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
    QWidget *page_json;
    QHBoxLayout *horizontalLayout_2;
    QSplitter *splitter;
    QPlainTextEdit *plainTextEdit_json_source;
    QTextEdit *textEdit_json_target;
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
        toolswidget->resize(974, 631);
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
        scrollAreaWidgetContents->setGeometry(QRect(0, -246, 166, 782));
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
        toolButton_2 = new QToolButton(scrollAreaWidgetContents);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolButton_2->sizePolicy().hasHeightForWidth());
        toolButton_2->setSizePolicy(sizePolicy);
        toolButton_2->setMinimumSize(QSize(0, 40));
        toolButton_2->setMaximumSize(QSize(16777215, 40));
        QFont font1;
        font1.setFamily(QStringLiteral("OPPOSans B"));
        font1.setPointSize(10);
        toolButton_2->setFont(font1);
        toolButton_2->setStyleSheet(QStringLiteral(""));
        QIcon icon;
        icon.addFile(QStringLiteral(":/lib/json (2).png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon);
        toolButton_2->setIconSize(QSize(22, 22));
        toolButton_2->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout->addWidget(toolButton_2);

        toolButton_11 = new QToolButton(scrollAreaWidgetContents);
        toolButton_11->setObjectName(QStringLiteral("toolButton_11"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(toolButton_11->sizePolicy().hasHeightForWidth());
        toolButton_11->setSizePolicy(sizePolicy1);
        toolButton_11->setMinimumSize(QSize(0, 40));
        toolButton_11->setMaximumSize(QSize(16777215, 40));
        toolButton_11->setFont(font1);
        toolButton_11->setStyleSheet(QStringLiteral(""));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/lib/note.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_11->setIcon(icon1);
        toolButton_11->setIconSize(QSize(22, 22));
        toolButton_11->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout->addWidget(toolButton_11);

        toolButton_7 = new QToolButton(scrollAreaWidgetContents);
        toolButton_7->setObjectName(QStringLiteral("toolButton_7"));
        sizePolicy1.setHeightForWidth(toolButton_7->sizePolicy().hasHeightForWidth());
        toolButton_7->setSizePolicy(sizePolicy1);
        toolButton_7->setMinimumSize(QSize(0, 40));
        toolButton_7->setMaximumSize(QSize(16777215, 40));
        toolButton_7->setFont(font1);
        toolButton_7->setStyleSheet(QStringLiteral(""));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/lib/calculator.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_7->setIcon(icon2);
        toolButton_7->setIconSize(QSize(22, 22));
        toolButton_7->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout->addWidget(toolButton_7);

        toolButton_10 = new QToolButton(scrollAreaWidgetContents);
        toolButton_10->setObjectName(QStringLiteral("toolButton_10"));
        sizePolicy1.setHeightForWidth(toolButton_10->sizePolicy().hasHeightForWidth());
        toolButton_10->setSizePolicy(sizePolicy1);
        toolButton_10->setMinimumSize(QSize(0, 40));
        toolButton_10->setMaximumSize(QSize(16777215, 40));
        toolButton_10->setFont(font1);
        toolButton_10->setStyleSheet(QStringLiteral(""));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/lib/timestamp.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_10->setIcon(icon3);
        toolButton_10->setIconSize(QSize(22, 22));
        toolButton_10->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout->addWidget(toolButton_10);

        toolButton_6 = new QToolButton(scrollAreaWidgetContents);
        toolButton_6->setObjectName(QStringLiteral("toolButton_6"));
        sizePolicy1.setHeightForWidth(toolButton_6->sizePolicy().hasHeightForWidth());
        toolButton_6->setSizePolicy(sizePolicy1);
        toolButton_6->setMinimumSize(QSize(0, 40));
        toolButton_6->setMaximumSize(QSize(16777215, 40));
        toolButton_6->setFont(font1);
        toolButton_6->setStyleSheet(QStringLiteral(""));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/lib/Binary.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_6->setIcon(icon4);
        toolButton_6->setIconSize(QSize(22, 22));
        toolButton_6->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout->addWidget(toolButton_6);

        toolButton_13 = new QToolButton(scrollAreaWidgetContents);
        toolButton_13->setObjectName(QStringLiteral("toolButton_13"));
        sizePolicy1.setHeightForWidth(toolButton_13->sizePolicy().hasHeightForWidth());
        toolButton_13->setSizePolicy(sizePolicy1);
        toolButton_13->setMinimumSize(QSize(0, 40));
        toolButton_13->setMaximumSize(QSize(16777215, 40));
        toolButton_13->setFont(font1);
        toolButton_13->setStyleSheet(QStringLiteral(""));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/lib/URL.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_13->setIcon(icon5);
        toolButton_13->setIconSize(QSize(22, 22));
        toolButton_13->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout->addWidget(toolButton_13);

        toolButton_12 = new QToolButton(scrollAreaWidgetContents);
        toolButton_12->setObjectName(QStringLiteral("toolButton_12"));
        sizePolicy1.setHeightForWidth(toolButton_12->sizePolicy().hasHeightForWidth());
        toolButton_12->setSizePolicy(sizePolicy1);
        toolButton_12->setMinimumSize(QSize(0, 40));
        toolButton_12->setMaximumSize(QSize(16777215, 40));
        toolButton_12->setFont(font1);
        toolButton_12->setStyleSheet(QStringLiteral(""));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/lib/MD5.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_12->setIcon(icon6);
        toolButton_12->setIconSize(QSize(22, 22));
        toolButton_12->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout->addWidget(toolButton_12);

        toolButton = new QToolButton(scrollAreaWidgetContents);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        sizePolicy1.setHeightForWidth(toolButton->sizePolicy().hasHeightForWidth());
        toolButton->setSizePolicy(sizePolicy1);
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

        toolButton_18 = new QToolButton(scrollAreaWidgetContents);
        toolButton_18->setObjectName(QStringLiteral("toolButton_18"));
        sizePolicy1.setHeightForWidth(toolButton_18->sizePolicy().hasHeightForWidth());
        toolButton_18->setSizePolicy(sizePolicy1);
        toolButton_18->setMinimumSize(QSize(0, 40));
        toolButton_18->setMaximumSize(QSize(16777215, 40));
        toolButton_18->setFont(font1);
        toolButton_18->setStyleSheet(QStringLiteral(""));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/lib/powershell.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_18->setIcon(icon8);
        toolButton_18->setIconSize(QSize(22, 22));
        toolButton_18->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout->addWidget(toolButton_18);

        toolButton_20 = new QToolButton(scrollAreaWidgetContents);
        toolButton_20->setObjectName(QStringLiteral("toolButton_20"));
        sizePolicy1.setHeightForWidth(toolButton_20->sizePolicy().hasHeightForWidth());
        toolButton_20->setSizePolicy(sizePolicy1);
        toolButton_20->setMinimumSize(QSize(0, 40));
        toolButton_20->setMaximumSize(QSize(16777215, 40));
        toolButton_20->setFont(font1);
        toolButton_20->setStyleSheet(QStringLiteral(""));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/lib/qssmaihua.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_20->setIcon(icon9);
        toolButton_20->setIconSize(QSize(22, 22));
        toolButton_20->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout->addWidget(toolButton_20);

        toolButton_14 = new QToolButton(scrollAreaWidgetContents);
        toolButton_14->setObjectName(QStringLiteral("toolButton_14"));
        sizePolicy1.setHeightForWidth(toolButton_14->sizePolicy().hasHeightForWidth());
        toolButton_14->setSizePolicy(sizePolicy1);
        toolButton_14->setMinimumSize(QSize(0, 40));
        toolButton_14->setMaximumSize(QSize(16777215, 40));
        toolButton_14->setFont(font1);
        toolButton_14->setStyleSheet(QStringLiteral(""));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/lib/mysql.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_14->setIcon(icon10);
        toolButton_14->setIconSize(QSize(22, 22));
        toolButton_14->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout->addWidget(toolButton_14);

        toolButton_21 = new QToolButton(scrollAreaWidgetContents);
        toolButton_21->setObjectName(QStringLiteral("toolButton_21"));
        sizePolicy1.setHeightForWidth(toolButton_21->sizePolicy().hasHeightForWidth());
        toolButton_21->setSizePolicy(sizePolicy1);
        toolButton_21->setMinimumSize(QSize(0, 40));
        toolButton_21->setMaximumSize(QSize(16777215, 40));
        toolButton_21->setFont(font1);
        toolButton_21->setStyleSheet(QStringLiteral(""));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/lib/linux.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_21->setIcon(icon11);
        toolButton_21->setIconSize(QSize(22, 22));
        toolButton_21->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout->addWidget(toolButton_21);

        toolButton_15 = new QToolButton(scrollAreaWidgetContents);
        toolButton_15->setObjectName(QStringLiteral("toolButton_15"));
        sizePolicy1.setHeightForWidth(toolButton_15->sizePolicy().hasHeightForWidth());
        toolButton_15->setSizePolicy(sizePolicy1);
        toolButton_15->setMinimumSize(QSize(0, 40));
        toolButton_15->setMaximumSize(QSize(16777215, 40));
        toolButton_15->setFont(font1);
        toolButton_15->setStyleSheet(QStringLiteral(""));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/lib/regular.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_15->setIcon(icon12);
        toolButton_15->setIconSize(QSize(22, 22));
        toolButton_15->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout->addWidget(toolButton_15);

        toolButton_9 = new QToolButton(scrollAreaWidgetContents);
        toolButton_9->setObjectName(QStringLiteral("toolButton_9"));
        sizePolicy1.setHeightForWidth(toolButton_9->sizePolicy().hasHeightForWidth());
        toolButton_9->setSizePolicy(sizePolicy1);
        toolButton_9->setMinimumSize(QSize(0, 40));
        toolButton_9->setMaximumSize(QSize(16777215, 40));
        toolButton_9->setFont(font1);
        toolButton_9->setStyleSheet(QStringLiteral(""));
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/lib/XML-Local-hover.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_9->setIcon(icon13);
        toolButton_9->setIconSize(QSize(22, 22));
        toolButton_9->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout->addWidget(toolButton_9);

        toolButton_17 = new QToolButton(scrollAreaWidgetContents);
        toolButton_17->setObjectName(QStringLiteral("toolButton_17"));
        sizePolicy1.setHeightForWidth(toolButton_17->sizePolicy().hasHeightForWidth());
        toolButton_17->setSizePolicy(sizePolicy1);
        toolButton_17->setMinimumSize(QSize(0, 40));
        toolButton_17->setMaximumSize(QSize(16777215, 40));
        toolButton_17->setFont(font1);
        toolButton_17->setStyleSheet(QStringLiteral(""));
        QIcon icon14;
        icon14.addFile(QStringLiteral(":/lib/Thrift5.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_17->setIcon(icon14);
        toolButton_17->setIconSize(QSize(22, 22));
        toolButton_17->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout->addWidget(toolButton_17);

        toolButton_8 = new QToolButton(scrollAreaWidgetContents);
        toolButton_8->setObjectName(QStringLiteral("toolButton_8"));
        sizePolicy1.setHeightForWidth(toolButton_8->sizePolicy().hasHeightForWidth());
        toolButton_8->setSizePolicy(sizePolicy1);
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

        toolButton_19 = new QToolButton(scrollAreaWidgetContents);
        toolButton_19->setObjectName(QStringLiteral("toolButton_19"));
        sizePolicy1.setHeightForWidth(toolButton_19->sizePolicy().hasHeightForWidth());
        toolButton_19->setSizePolicy(sizePolicy1);
        toolButton_19->setMinimumSize(QSize(0, 40));
        toolButton_19->setMaximumSize(QSize(16777215, 40));
        toolButton_19->setFont(font1);
        toolButton_19->setStyleSheet(QStringLiteral(""));
        toolButton_19->setIcon(icon12);
        toolButton_19->setIconSize(QSize(22, 22));
        toolButton_19->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout->addWidget(toolButton_19);

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
        QFont font3;
        font3.setFamily(QStringLiteral("Cascadia Code SemiBold"));
        font3.setPointSize(11);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(50);
        plainTextEdit_json_source->setFont(font3);
        plainTextEdit_json_source->setStyleSheet(QLatin1String("QPlainTextEdit{\n"
"color: rgb(38, 38, 38);\n"
"border-radius: 14px;\n"
"	background-color: rgb(255, 255, 255);\n"
"border: 0px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding:5px;\n"
"}"));
        splitter->addWidget(plainTextEdit_json_source);
        textEdit_json_target = new QTextEdit(splitter);
        textEdit_json_target->setObjectName(QStringLiteral("textEdit_json_target"));
        textEdit_json_target->setFont(font3);
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
        page_xml = new QWidget();
        page_xml->setObjectName(QStringLiteral("page_xml"));
        horizontalLayout_3 = new QHBoxLayout(page_xml);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        splitter_2 = new QSplitter(page_xml);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        textEdit_xml_source = new QTextEdit(splitter_2);
        textEdit_xml_source->setObjectName(QStringLiteral("textEdit_xml_source"));
        QFont font4;
        font4.setFamily(QStringLiteral("OPPOSans"));
        font4.setPointSize(12);
        font4.setStyleStrategy(QFont::PreferAntialias);
        textEdit_xml_source->setFont(font4);
        splitter_2->addWidget(textEdit_xml_source);
        textEdit_xml_target = new QTextEdit(splitter_2);
        textEdit_xml_target->setObjectName(QStringLiteral("textEdit_xml_target"));
        textEdit_xml_target->setFont(font4);
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
        textEdit_diff_source->setFont(font4);
        splitter_3->addWidget(textEdit_diff_source);
        textEdit_diff_target = new QTextEdit(splitter_3);
        textEdit_diff_target->setObjectName(QStringLiteral("textEdit_diff_target"));
        textEdit_diff_target->setFont(font4);
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
        toolButton_2->setText(QApplication::translate("toolswidget", " JSON\346\240\274\345\274\217\345\214\226", nullptr));
        toolButton_11->setText(QApplication::translate("toolswidget", " \344\276\277\347\255\276", nullptr));
        toolButton_7->setText(QApplication::translate("toolswidget", " \350\256\241\347\256\227\345\231\250", nullptr));
        toolButton_10->setText(QApplication::translate("toolswidget", " \346\227\266\351\227\264\346\210\263", nullptr));
        toolButton_6->setText(QApplication::translate("toolswidget", " \350\277\233\345\210\266\350\275\254\346\215\242", nullptr));
        toolButton_13->setText(QApplication::translate("toolswidget", " URL\347\274\226\347\240\201", nullptr));
        toolButton_12->setText(QApplication::translate("toolswidget", " MD5\345\212\240\345\257\206", nullptr));
        toolButton->setText(QApplication::translate("toolswidget", " XML\346\240\274\345\274\217\345\214\226", nullptr));
        toolButton_18->setText(QApplication::translate("toolswidget", " SSH\350\277\236\346\216\245", nullptr));
        toolButton_20->setText(QApplication::translate("toolswidget", " Qt\346\216\247\344\273\266\347\276\216\345\214\226", nullptr));
        toolButton_14->setText(QApplication::translate("toolswidget", " \346\225\260\346\215\256\345\272\223\350\277\236\346\216\245", nullptr));
        toolButton_21->setText(QApplication::translate("toolswidget", " Linux\345\270\270\347\224\250\345\221\275\344\273\244", nullptr));
        toolButton_15->setText(QApplication::translate("toolswidget", " \346\255\243\345\210\231\350\241\250\350\276\276\345\274\217\351\252\214\350\257\201", nullptr));
        toolButton_9->setText(QApplication::translate("toolswidget", " \346\226\207\346\234\254\345\206\205\345\256\271\345\257\271\346\257\224", nullptr));
        toolButton_17->setText(QApplication::translate("toolswidget", " thrift\346\216\245\345\217\243\346\265\213\350\257\225", nullptr));
        toolButton_8->setText(QApplication::translate("toolswidget", " windows\350\277\234\347\250\213\350\277\236\346\216\245", nullptr));
        toolButton_19->setText(QApplication::translate("toolswidget", " \345\270\270\347\224\250\350\265\204\346\272\220\347\275\221\347\253\231", nullptr));
        toolButton_3->setText(QString());
        toolButton_4->setText(QString());
        label->setText(QApplication::translate("toolswidget", "JSON\346\240\274\345\274\217\345\214\226\345\267\245\345\205\267", nullptr));
        lineEdit_find->setPlaceholderText(QApplication::translate("toolswidget", "\346\220\234\347\264\242\345\267\245\345\205\267", nullptr));
        plainTextEdit_json_source->setPlainText(QString());
        textEdit_json_target->setHtml(QApplication::translate("toolswidget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Cascadia Code SemiBold'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'OPPOSans B'; font-size:15pt;\"><br /></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class toolswidget: public Ui_toolswidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLSWIDGET_H
