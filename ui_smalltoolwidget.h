/********************************************************************************
** Form generated from reading UI file 'smalltoolwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SMALLTOOLWIDGET_H
#define UI_SMALLTOOLWIDGET_H

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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_smalltoolwidget
{
public:
    QVBoxLayout *verticalLayout_6;
    QComboBox *comboBox;
    QStackedWidget *stackedWidget_2;
    QWidget *page_21;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_6;
    QLineEdit *lineEdit_hex;
    QLabel *label_7;
    QLineEdit *lineEdit_dec;
    QLabel *label_15;
    QLineEdit *lineEdit_oct;
    QLabel *label_8;
    QLineEdit *lineEdit_bin;
    QSpacerItem *verticalSpacer;
    QWidget *page_19;
    QVBoxLayout *verticalLayout;
    QWidget *gridWidget;
    QGridLayout *gridLayout;
    QToolButton *toolButton_4;
    QToolButton *toolButton_3;
    QToolButton *toolButton_8;
    QToolButton *toolButton_9;
    QToolButton *toolButton_10;
    QToolButton *toolButton_11;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QWidget *page_20;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QWidget *gridWidget1;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QToolButton *toolButton_7;
    QToolButton *toolButton_22;
    QLineEdit *lineEdit_now;
    QWidget *gridWidget_2;
    QGridLayout *gridLayout_3;
    QLabel *label_2;
    QLineEdit *lineEdit_timestamp_in;
    QLineEdit *lineEdit_date_out;
    QComboBox *comboBox_timestamp;
    QToolButton *toolButton;
    QWidget *gridWidget_3;
    QGridLayout *gridLayout_4;
    QLineEdit *lineEdit_timestamp_out;
    QLineEdit *lineEdit_date_in;
    QLabel *label_5;
    QComboBox *comboBox_date;
    QToolButton *toolButton_2;
    QSpacerItem *verticalSpacer_2;
    QWidget *page_22;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_9;
    QLineEdit *lineEdit_encode;
    QLineEdit *lineEdit_decode;
    QLabel *label_10;
    QWidget *horizontalWidget;
    QHBoxLayout *horizontalLayout;
    QToolButton *toolButton_decode;
    QToolButton *toolButton_encode;
    QSpacerItem *horizontalSpacer;
    QWidget *page_23;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_11;
    QLineEdit *lineEdit_11;
    QLabel *label_12;
    QLineEdit *lineEdit_12;
    QWidget *horizontalWidget1;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QToolButton *toolButton_5;
    QLabel *label_13;
    QLineEdit *lineEdit_13;

    void setupUi(QWidget *smalltoolwidget)
    {
        if (smalltoolwidget->objectName().isEmpty())
            smalltoolwidget->setObjectName(QStringLiteral("smalltoolwidget"));
        smalltoolwidget->resize(273, 535);
        verticalLayout_6 = new QVBoxLayout(smalltoolwidget);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        comboBox = new QComboBox(smalltoolwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QStringLiteral("comboBox"));
        QFont font;
        font.setFamily(QStringLiteral("OPPOSans B"));
        font.setPointSize(10);
        font.setStyleStrategy(QFont::PreferAntialias);
        comboBox->setFont(font);

        verticalLayout_6->addWidget(comboBox);

        stackedWidget_2 = new QStackedWidget(smalltoolwidget);
        stackedWidget_2->setObjectName(QStringLiteral("stackedWidget_2"));
        stackedWidget_2->setStyleSheet(QStringLiteral("background-color: rgb(207, 188, 255);"));
        page_21 = new QWidget();
        page_21->setObjectName(QStringLiteral("page_21"));
        verticalLayout_2 = new QVBoxLayout(page_21);
        verticalLayout_2->setSpacing(14);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_6 = new QLabel(page_21);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);

        verticalLayout_2->addWidget(label_6);

        lineEdit_hex = new QLineEdit(page_21);
        lineEdit_hex->setObjectName(QStringLiteral("lineEdit_hex"));
        lineEdit_hex->setMinimumSize(QSize(0, 32));
        lineEdit_hex->setMaximumSize(QSize(16777215, 32));
        lineEdit_hex->setFont(font);
        lineEdit_hex->setStyleSheet(QLatin1String("background-color: rgb(25, 25, 25, 155);\n"
"border: 1px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding-left:10px;\n"
"padding-right:10px;"));

        verticalLayout_2->addWidget(lineEdit_hex);

        label_7 = new QLabel(page_21);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);

        verticalLayout_2->addWidget(label_7);

        lineEdit_dec = new QLineEdit(page_21);
        lineEdit_dec->setObjectName(QStringLiteral("lineEdit_dec"));
        lineEdit_dec->setMinimumSize(QSize(0, 32));
        lineEdit_dec->setMaximumSize(QSize(16777215, 32));
        lineEdit_dec->setFont(font);
        lineEdit_dec->setStyleSheet(QLatin1String("background-color: rgb(25, 25, 25, 155);\n"
"border: 1px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding-left:10px;\n"
"padding-right:10px;"));

        verticalLayout_2->addWidget(lineEdit_dec);

        label_15 = new QLabel(page_21);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setFont(font);

        verticalLayout_2->addWidget(label_15);

        lineEdit_oct = new QLineEdit(page_21);
        lineEdit_oct->setObjectName(QStringLiteral("lineEdit_oct"));
        lineEdit_oct->setMinimumSize(QSize(0, 32));
        lineEdit_oct->setMaximumSize(QSize(16777215, 32));
        lineEdit_oct->setFont(font);
        lineEdit_oct->setStyleSheet(QLatin1String("background-color: rgb(25, 25, 25, 155);\n"
"border: 1px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding-left:10px;\n"
"padding-right:10px;"));

        verticalLayout_2->addWidget(lineEdit_oct);

        label_8 = new QLabel(page_21);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font);

        verticalLayout_2->addWidget(label_8);

        lineEdit_bin = new QLineEdit(page_21);
        lineEdit_bin->setObjectName(QStringLiteral("lineEdit_bin"));
        lineEdit_bin->setMinimumSize(QSize(0, 32));
        lineEdit_bin->setMaximumSize(QSize(16777215, 32));
        lineEdit_bin->setFont(font);
        lineEdit_bin->setStyleSheet(QLatin1String("background-color: rgb(25, 25, 25, 155);\n"
"border: 1px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding-left:10px;\n"
"padding-right:10px;"));

        verticalLayout_2->addWidget(lineEdit_bin);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        stackedWidget_2->addWidget(page_21);
        page_19 = new QWidget();
        page_19->setObjectName(QStringLiteral("page_19"));
        verticalLayout = new QVBoxLayout(page_19);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridWidget = new QWidget(page_19);
        gridWidget->setObjectName(QStringLiteral("gridWidget"));
        gridLayout = new QGridLayout(gridWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        toolButton_4 = new QToolButton(gridWidget);
        toolButton_4->setObjectName(QStringLiteral("toolButton_4"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolButton_4->sizePolicy().hasHeightForWidth());
        toolButton_4->setSizePolicy(sizePolicy);
        toolButton_4->setMinimumSize(QSize(0, 30));
        toolButton_4->setMaximumSize(QSize(16777215, 30));
        toolButton_4->setFont(font);
        toolButton_4->setStyleSheet(QLatin1String("QToolButton {\n"
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

        gridLayout->addWidget(toolButton_4, 1, 0, 1, 1);

        toolButton_3 = new QToolButton(gridWidget);
        toolButton_3->setObjectName(QStringLiteral("toolButton_3"));
        sizePolicy.setHeightForWidth(toolButton_3->sizePolicy().hasHeightForWidth());
        toolButton_3->setSizePolicy(sizePolicy);
        toolButton_3->setMinimumSize(QSize(0, 30));
        toolButton_3->setMaximumSize(QSize(16777215, 30));
        toolButton_3->setFont(font);
        toolButton_3->setStyleSheet(QLatin1String("QToolButton {\n"
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

        gridLayout->addWidget(toolButton_3, 2, 0, 1, 1);

        toolButton_8 = new QToolButton(gridWidget);
        toolButton_8->setObjectName(QStringLiteral("toolButton_8"));
        sizePolicy.setHeightForWidth(toolButton_8->sizePolicy().hasHeightForWidth());
        toolButton_8->setSizePolicy(sizePolicy);
        toolButton_8->setMinimumSize(QSize(0, 30));
        toolButton_8->setMaximumSize(QSize(16777215, 30));
        toolButton_8->setFont(font);
        toolButton_8->setStyleSheet(QLatin1String("QToolButton {\n"
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

        gridLayout->addWidget(toolButton_8, 0, 0, 1, 1);

        toolButton_9 = new QToolButton(gridWidget);
        toolButton_9->setObjectName(QStringLiteral("toolButton_9"));
        sizePolicy.setHeightForWidth(toolButton_9->sizePolicy().hasHeightForWidth());
        toolButton_9->setSizePolicy(sizePolicy);
        toolButton_9->setMinimumSize(QSize(0, 30));
        toolButton_9->setMaximumSize(QSize(16777215, 30));
        toolButton_9->setFont(font);
        toolButton_9->setStyleSheet(QLatin1String("QToolButton {\n"
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

        gridLayout->addWidget(toolButton_9, 0, 1, 1, 1);

        toolButton_10 = new QToolButton(gridWidget);
        toolButton_10->setObjectName(QStringLiteral("toolButton_10"));
        sizePolicy.setHeightForWidth(toolButton_10->sizePolicy().hasHeightForWidth());
        toolButton_10->setSizePolicy(sizePolicy);
        toolButton_10->setMinimumSize(QSize(0, 30));
        toolButton_10->setMaximumSize(QSize(16777215, 30));
        toolButton_10->setFont(font);
        toolButton_10->setStyleSheet(QLatin1String("QToolButton {\n"
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

        gridLayout->addWidget(toolButton_10, 1, 1, 1, 1);

        toolButton_11 = new QToolButton(gridWidget);
        toolButton_11->setObjectName(QStringLiteral("toolButton_11"));
        sizePolicy.setHeightForWidth(toolButton_11->sizePolicy().hasHeightForWidth());
        toolButton_11->setSizePolicy(sizePolicy);
        toolButton_11->setMinimumSize(QSize(0, 30));
        toolButton_11->setMaximumSize(QSize(16777215, 30));
        toolButton_11->setFont(font);
        toolButton_11->setStyleSheet(QLatin1String("QToolButton {\n"
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

        gridLayout->addWidget(toolButton_11, 2, 1, 1, 1);


        verticalLayout->addWidget(gridWidget);

        lineEdit_3 = new QLineEdit(page_19);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        sizePolicy.setHeightForWidth(lineEdit_3->sizePolicy().hasHeightForWidth());
        lineEdit_3->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(lineEdit_3);

        lineEdit_4 = new QLineEdit(page_19);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        sizePolicy.setHeightForWidth(lineEdit_4->sizePolicy().hasHeightForWidth());
        lineEdit_4->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(lineEdit_4);

        stackedWidget_2->addWidget(page_19);
        page_20 = new QWidget();
        page_20->setObjectName(QStringLiteral("page_20"));
        verticalLayout_3 = new QVBoxLayout(page_20);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_3 = new QLabel(page_20);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(200, 0));
        label_3->setMaximumSize(QSize(250, 30));
        label_3->setFont(font);

        verticalLayout_3->addWidget(label_3);

        gridWidget1 = new QWidget(page_20);
        gridWidget1->setObjectName(QStringLiteral("gridWidget1"));
        gridLayout_2 = new QGridLayout(gridWidget1);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label = new QLabel(gridWidget1);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 32));
        label->setMaximumSize(QSize(16777215, 32));
        label->setFont(font);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        toolButton_7 = new QToolButton(gridWidget1);
        toolButton_7->setObjectName(QStringLiteral("toolButton_7"));
        toolButton_7->setMinimumSize(QSize(70, 30));
        toolButton_7->setMaximumSize(QSize(70, 30));
        toolButton_7->setFont(font);
        toolButton_7->setStyleSheet(QLatin1String("QToolButton {\n"
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

        gridLayout_2->addWidget(toolButton_7, 2, 1, 1, 1);

        toolButton_22 = new QToolButton(gridWidget1);
        toolButton_22->setObjectName(QStringLiteral("toolButton_22"));
        toolButton_22->setMinimumSize(QSize(70, 30));
        toolButton_22->setMaximumSize(QSize(70, 30));
        toolButton_22->setFont(font);
        toolButton_22->setStyleSheet(QLatin1String("QToolButton {\n"
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

        gridLayout_2->addWidget(toolButton_22, 1, 1, 1, 1);

        lineEdit_now = new QLineEdit(gridWidget1);
        lineEdit_now->setObjectName(QStringLiteral("lineEdit_now"));
        lineEdit_now->setMinimumSize(QSize(160, 32));
        lineEdit_now->setMaximumSize(QSize(160, 32));
        lineEdit_now->setFont(font);
        lineEdit_now->setStyleSheet(QLatin1String("background-color: rgb(25, 25, 25, 155);\n"
"border: 1px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding-left:10px;\n"
"padding-right:10px;"));

        gridLayout_2->addWidget(lineEdit_now, 1, 0, 1, 1);


        verticalLayout_3->addWidget(gridWidget1);

        gridWidget_2 = new QWidget(page_20);
        gridWidget_2->setObjectName(QStringLiteral("gridWidget_2"));
        gridLayout_3 = new QGridLayout(gridWidget_2);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_2 = new QLabel(gridWidget_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(0, 32));
        label_2->setMaximumSize(QSize(16777215, 32));
        label_2->setFont(font);

        gridLayout_3->addWidget(label_2, 0, 0, 1, 1);

        lineEdit_timestamp_in = new QLineEdit(gridWidget_2);
        lineEdit_timestamp_in->setObjectName(QStringLiteral("lineEdit_timestamp_in"));
        lineEdit_timestamp_in->setMinimumSize(QSize(160, 32));
        lineEdit_timestamp_in->setMaximumSize(QSize(160, 32));
        lineEdit_timestamp_in->setFont(font);
        lineEdit_timestamp_in->setStyleSheet(QLatin1String("background-color: rgb(25, 25, 25, 155);\n"
"border: 1px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding-left:10px;\n"
"padding-right:10px;"));

        gridLayout_3->addWidget(lineEdit_timestamp_in, 1, 0, 1, 1);

        lineEdit_date_out = new QLineEdit(gridWidget_2);
        lineEdit_date_out->setObjectName(QStringLiteral("lineEdit_date_out"));
        lineEdit_date_out->setMinimumSize(QSize(160, 32));
        lineEdit_date_out->setMaximumSize(QSize(160, 32));
        lineEdit_date_out->setFont(font);
        lineEdit_date_out->setStyleSheet(QLatin1String("background-color: rgb(25, 25, 25, 155);\n"
"border: 1px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding-left:10px;\n"
"padding-right:10px;"));

        gridLayout_3->addWidget(lineEdit_date_out, 2, 0, 1, 1);

        comboBox_timestamp = new QComboBox(gridWidget_2);
        comboBox_timestamp->addItem(QString());
        comboBox_timestamp->addItem(QString());
        comboBox_timestamp->setObjectName(QStringLiteral("comboBox_timestamp"));
        comboBox_timestamp->setMinimumSize(QSize(70, 32));
        comboBox_timestamp->setMaximumSize(QSize(70, 32));
        comboBox_timestamp->setFont(font);
        comboBox_timestamp->setStyleSheet(QLatin1String("background-color: rgb(25, 25, 25, 155);\n"
"border: 1px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding-left:10px;\n"
"padding-right:10px;"));

        gridLayout_3->addWidget(comboBox_timestamp, 1, 1, 1, 1);

        toolButton = new QToolButton(gridWidget_2);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setMinimumSize(QSize(70, 32));
        toolButton->setMaximumSize(QSize(70, 32));
        toolButton->setFont(font);
        toolButton->setStyleSheet(QLatin1String("QToolButton {\n"
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

        gridLayout_3->addWidget(toolButton, 2, 1, 1, 1);


        verticalLayout_3->addWidget(gridWidget_2);

        gridWidget_3 = new QWidget(page_20);
        gridWidget_3->setObjectName(QStringLiteral("gridWidget_3"));
        gridLayout_4 = new QGridLayout(gridWidget_3);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        lineEdit_timestamp_out = new QLineEdit(gridWidget_3);
        lineEdit_timestamp_out->setObjectName(QStringLiteral("lineEdit_timestamp_out"));
        lineEdit_timestamp_out->setMinimumSize(QSize(160, 32));
        lineEdit_timestamp_out->setMaximumSize(QSize(160, 32));
        lineEdit_timestamp_out->setFont(font);
        lineEdit_timestamp_out->setStyleSheet(QLatin1String("background-color: rgb(25, 25, 25, 155);\n"
"border: 1px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding-left:10px;\n"
"padding-right:10px;"));

        gridLayout_4->addWidget(lineEdit_timestamp_out, 2, 0, 1, 1);

        lineEdit_date_in = new QLineEdit(gridWidget_3);
        lineEdit_date_in->setObjectName(QStringLiteral("lineEdit_date_in"));
        lineEdit_date_in->setMinimumSize(QSize(160, 32));
        lineEdit_date_in->setMaximumSize(QSize(160, 32));
        lineEdit_date_in->setFont(font);
        lineEdit_date_in->setStyleSheet(QLatin1String("background-color: rgb(25, 25, 25, 155);\n"
"border: 1px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding-left:10px;\n"
"padding-right:10px;"));

        gridLayout_4->addWidget(lineEdit_date_in, 1, 0, 1, 1);

        label_5 = new QLabel(gridWidget_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(0, 32));
        label_5->setMaximumSize(QSize(16777215, 32));
        label_5->setFont(font);

        gridLayout_4->addWidget(label_5, 0, 0, 1, 1);

        comboBox_date = new QComboBox(gridWidget_3);
        comboBox_date->addItem(QString());
        comboBox_date->addItem(QString());
        comboBox_date->setObjectName(QStringLiteral("comboBox_date"));
        comboBox_date->setMinimumSize(QSize(70, 32));
        comboBox_date->setMaximumSize(QSize(70, 32));
        comboBox_date->setFont(font);
        comboBox_date->setStyleSheet(QLatin1String("background-color: rgb(25, 25, 25, 155);\n"
"border: 1px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding-left:10px;\n"
"padding-right:10px;"));

        gridLayout_4->addWidget(comboBox_date, 1, 1, 1, 1);

        toolButton_2 = new QToolButton(gridWidget_3);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        toolButton_2->setMinimumSize(QSize(70, 32));
        toolButton_2->setMaximumSize(QSize(70, 32));
        toolButton_2->setFont(font);
        toolButton_2->setStyleSheet(QLatin1String("QToolButton {\n"
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

        gridLayout_4->addWidget(toolButton_2, 2, 1, 1, 1);


        verticalLayout_3->addWidget(gridWidget_3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        stackedWidget_2->addWidget(page_20);
        page_22 = new QWidget();
        page_22->setObjectName(QStringLiteral("page_22"));
        verticalLayout_4 = new QVBoxLayout(page_22);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_9 = new QLabel(page_22);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setMinimumSize(QSize(0, 20));
        label_9->setMaximumSize(QSize(16777215, 20));
        label_9->setFont(font);

        verticalLayout_4->addWidget(label_9);

        lineEdit_encode = new QLineEdit(page_22);
        lineEdit_encode->setObjectName(QStringLiteral("lineEdit_encode"));
        sizePolicy.setHeightForWidth(lineEdit_encode->sizePolicy().hasHeightForWidth());
        lineEdit_encode->setSizePolicy(sizePolicy);
        lineEdit_encode->setMinimumSize(QSize(0, 100));
        lineEdit_encode->setFont(font);

        verticalLayout_4->addWidget(lineEdit_encode);

        lineEdit_decode = new QLineEdit(page_22);
        lineEdit_decode->setObjectName(QStringLiteral("lineEdit_decode"));
        sizePolicy.setHeightForWidth(lineEdit_decode->sizePolicy().hasHeightForWidth());
        lineEdit_decode->setSizePolicy(sizePolicy);
        lineEdit_decode->setMinimumSize(QSize(0, 100));
        lineEdit_decode->setFont(font);

        verticalLayout_4->addWidget(lineEdit_decode);

        label_10 = new QLabel(page_22);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setMinimumSize(QSize(0, 20));
        label_10->setMaximumSize(QSize(16777215, 20));
        label_10->setFont(font);

        verticalLayout_4->addWidget(label_10);

        horizontalWidget = new QWidget(page_22);
        horizontalWidget->setObjectName(QStringLiteral("horizontalWidget"));
        horizontalLayout = new QHBoxLayout(horizontalWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        toolButton_decode = new QToolButton(horizontalWidget);
        toolButton_decode->setObjectName(QStringLiteral("toolButton_decode"));
        toolButton_decode->setMinimumSize(QSize(60, 30));
        toolButton_decode->setMaximumSize(QSize(60, 30));
        toolButton_decode->setFont(font);
        toolButton_decode->setStyleSheet(QLatin1String("QToolButton {\n"
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

        horizontalLayout->addWidget(toolButton_decode);

        toolButton_encode = new QToolButton(horizontalWidget);
        toolButton_encode->setObjectName(QStringLiteral("toolButton_encode"));
        toolButton_encode->setMinimumSize(QSize(60, 30));
        toolButton_encode->setMaximumSize(QSize(16777215, 30));
        toolButton_encode->setFont(font);
        toolButton_encode->setStyleSheet(QLatin1String("QToolButton {\n"
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

        horizontalLayout->addWidget(toolButton_encode);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_4->addWidget(horizontalWidget);

        stackedWidget_2->addWidget(page_22);
        page_23 = new QWidget();
        page_23->setObjectName(QStringLiteral("page_23"));
        verticalLayout_5 = new QVBoxLayout(page_23);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_11 = new QLabel(page_23);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setMinimumSize(QSize(0, 20));
        label_11->setMaximumSize(QSize(16777215, 20));
        label_11->setFont(font);

        verticalLayout_5->addWidget(label_11);

        lineEdit_11 = new QLineEdit(page_23);
        lineEdit_11->setObjectName(QStringLiteral("lineEdit_11"));
        sizePolicy.setHeightForWidth(lineEdit_11->sizePolicy().hasHeightForWidth());
        lineEdit_11->setSizePolicy(sizePolicy);
        lineEdit_11->setMinimumSize(QSize(0, 100));
        lineEdit_11->setFont(font);

        verticalLayout_5->addWidget(lineEdit_11);

        label_12 = new QLabel(page_23);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setMinimumSize(QSize(0, 20));
        label_12->setMaximumSize(QSize(16777215, 20));
        label_12->setFont(font);

        verticalLayout_5->addWidget(label_12);

        lineEdit_12 = new QLineEdit(page_23);
        lineEdit_12->setObjectName(QStringLiteral("lineEdit_12"));
        sizePolicy.setHeightForWidth(lineEdit_12->sizePolicy().hasHeightForWidth());
        lineEdit_12->setSizePolicy(sizePolicy);
        lineEdit_12->setMinimumSize(QSize(0, 50));
        lineEdit_12->setFont(font);

        verticalLayout_5->addWidget(lineEdit_12);

        horizontalWidget1 = new QWidget(page_23);
        horizontalWidget1->setObjectName(QStringLiteral("horizontalWidget1"));
        horizontalLayout_2 = new QHBoxLayout(horizontalWidget1);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        toolButton_5 = new QToolButton(horizontalWidget1);
        toolButton_5->setObjectName(QStringLiteral("toolButton_5"));
        toolButton_5->setMinimumSize(QSize(0, 30));
        toolButton_5->setMaximumSize(QSize(16777215, 30));
        toolButton_5->setFont(font);
        toolButton_5->setStyleSheet(QLatin1String("QToolButton {\n"
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

        horizontalLayout_2->addWidget(toolButton_5);


        verticalLayout_5->addWidget(horizontalWidget1);

        label_13 = new QLabel(page_23);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setMinimumSize(QSize(0, 20));
        label_13->setMaximumSize(QSize(16777215, 20));
        label_13->setFont(font);

        verticalLayout_5->addWidget(label_13);

        lineEdit_13 = new QLineEdit(page_23);
        lineEdit_13->setObjectName(QStringLiteral("lineEdit_13"));
        sizePolicy.setHeightForWidth(lineEdit_13->sizePolicy().hasHeightForWidth());
        lineEdit_13->setSizePolicy(sizePolicy);
        lineEdit_13->setMinimumSize(QSize(0, 100));
        lineEdit_13->setFont(font);

        verticalLayout_5->addWidget(lineEdit_13);

        stackedWidget_2->addWidget(page_23);

        verticalLayout_6->addWidget(stackedWidget_2);


        retranslateUi(smalltoolwidget);

        stackedWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(smalltoolwidget);
    } // setupUi

    void retranslateUi(QWidget *smalltoolwidget)
    {
        smalltoolwidget->setWindowTitle(QApplication::translate("smalltoolwidget", "Form", nullptr));
        comboBox->setItemText(0, QApplication::translate("smalltoolwidget", "\350\277\233\345\210\266\350\275\254\346\215\242", nullptr));
        comboBox->setItemText(1, QApplication::translate("smalltoolwidget", "\347\274\226\347\240\201\350\275\254\346\215\242", nullptr));
        comboBox->setItemText(2, QApplication::translate("smalltoolwidget", "\346\227\266\351\227\264\346\210\263\350\275\254\346\215\242", nullptr));
        comboBox->setItemText(3, QApplication::translate("smalltoolwidget", "URL\347\274\226\347\240\201\350\275\254\346\215\242", nullptr));
        comboBox->setItemText(4, QApplication::translate("smalltoolwidget", "\346\255\243\345\210\231\350\241\250\350\276\276\345\274\217", nullptr));

        label_6->setText(QApplication::translate("smalltoolwidget", "\345\215\201\345\205\255\350\277\233\345\210\266", nullptr));
        label_7->setText(QApplication::translate("smalltoolwidget", "\345\215\201\350\277\233\345\210\266", nullptr));
        label_15->setText(QApplication::translate("smalltoolwidget", "\345\205\253\350\277\233\345\210\266", nullptr));
        label_8->setText(QApplication::translate("smalltoolwidget", "\344\272\214\350\277\233\345\210\266", nullptr));
        toolButton_4->setText(QApplication::translate("smalltoolwidget", "\344\270\255\346\226\207\350\275\254Unicode", nullptr));
        toolButton_3->setText(QApplication::translate("smalltoolwidget", "Unicode\350\275\254\344\270\255\346\226\207", nullptr));
        toolButton_8->setText(QApplication::translate("smalltoolwidget", "Ascii\350\275\254Unicode", nullptr));
        toolButton_9->setText(QApplication::translate("smalltoolwidget", "Unicode\350\275\254Ascii", nullptr));
        toolButton_10->setText(QApplication::translate("smalltoolwidget", "\345\215\201\345\205\255\350\277\233\345\210\266\350\275\254Unicode", nullptr));
        toolButton_11->setText(QApplication::translate("smalltoolwidget", "\345\215\201\345\205\255\350\277\233\345\210\266\350\275\254\344\270\255\346\226\207", nullptr));
        label_3->setText(QApplication::translate("smalltoolwidget", "2023\345\271\26410\346\234\21016\346\227\245\346\230\237\346\234\237\346\227\24500\347\202\27136\345\210\206", nullptr));
        label->setText(QApplication::translate("smalltoolwidget", "\345\275\223\345\211\215\346\227\266\351\227\264\346\210\263:", nullptr));
        toolButton_7->setText(QApplication::translate("smalltoolwidget", "\345\201\234\346\255\242", nullptr));
        toolButton_22->setText(QApplication::translate("smalltoolwidget", "\345\244\215\345\210\266", nullptr));
        label_2->setText(QApplication::translate("smalltoolwidget", "\346\227\266\351\227\264\346\210\263\350\275\254\346\227\245\346\234\237", nullptr));
        lineEdit_timestamp_in->setText(QApplication::translate("smalltoolwidget", "1970-01-21 00:03:15", nullptr));
        lineEdit_date_out->setText(QString());
        comboBox_timestamp->setItemText(0, QApplication::translate("smalltoolwidget", "\347\247\222(s)", nullptr));
        comboBox_timestamp->setItemText(1, QApplication::translate("smalltoolwidget", "\346\257\253\347\247\222(ms)", nullptr));

        toolButton->setText(QApplication::translate("smalltoolwidget", "\350\275\254\346\215\242", nullptr));
        label_5->setText(QApplication::translate("smalltoolwidget", "\346\227\266\351\227\264\350\275\254\346\227\266\351\227\264\346\210\263", nullptr));
        comboBox_date->setItemText(0, QApplication::translate("smalltoolwidget", "\347\247\222(s)", nullptr));
        comboBox_date->setItemText(1, QApplication::translate("smalltoolwidget", "\346\257\253\347\247\222(ms)", nullptr));

        toolButton_2->setText(QApplication::translate("smalltoolwidget", "\350\275\254\346\215\242", nullptr));
        label_9->setText(QApplication::translate("smalltoolwidget", "URL:", nullptr));
        label_10->setText(QApplication::translate("smalltoolwidget", "\347\274\226\347\240\201\347\273\223\346\236\234:", nullptr));
        toolButton_decode->setText(QApplication::translate("smalltoolwidget", "\350\247\243\347\240\201", nullptr));
        toolButton_encode->setText(QApplication::translate("smalltoolwidget", "\347\274\226\347\240\201", nullptr));
        label_11->setText(QApplication::translate("smalltoolwidget", "\345\216\237\346\226\207\357\274\232", nullptr));
        label_12->setText(QApplication::translate("smalltoolwidget", "\346\255\243\345\210\231\350\241\250\350\276\276\345\274\217\357\274\232", nullptr));
        lineEdit_12->setText(QString());
        toolButton_5->setText(QApplication::translate("smalltoolwidget", "\345\274\200\345\247\213\345\214\271\351\205\215", nullptr));
        label_13->setText(QApplication::translate("smalltoolwidget", "\345\214\271\351\205\215\347\273\223\346\236\234\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class smalltoolwidget: public Ui_smalltoolwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SMALLTOOLWIDGET_H
