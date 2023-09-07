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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_toolswidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QToolBox *toolBox;
    QWidget *page;
    QVBoxLayout *verticalLayout_5;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_timestamp_in;
    QLabel *label_2;
    QLineEdit *lineEdit_date_in;
    QLineEdit *lineEdit_date_out;
    QLabel *label;
    QLineEdit *lineEdit_now;
    QLineEdit *lineEdit_timestamp_out;
    QToolButton *toolButton;
    QComboBox *comboBox_timestamp;
    QToolButton *toolButton_2;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_3;
    QComboBox *comboBox_date;
    QToolButton *toolButton_7;
    QSpacerItem *verticalSpacer;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_4;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEdit_dec;
    QLabel *label_7;
    QLineEdit *lineEdit_bin;
    QLineEdit *lineEdit_hex;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_8;
    QLabel *label_15;
    QLineEdit *lineEdit_oct;
    QSpacerItem *verticalSpacer_2;
    QWidget *page_5;
    QVBoxLayout *verticalLayout_3;
    QWidget *gridWidget_3;
    QGridLayout *gridLayout_3;
    QLineEdit *lineEdit_decode;
    QLabel *label_10;
    QLabel *label_9;
    QLineEdit *lineEdit_encode;
    QWidget *horizontalWidget;
    QHBoxLayout *horizontalLayout;
    QToolButton *toolButton_decode;
    QToolButton *toolButton_encode;
    QSpacerItem *horizontalSpacer;
    QWidget *page_6;
    QHBoxLayout *horizontalLayout_2;
    QTextEdit *textEdit_json_source;
    QTextEdit *textEdit_json_target;
    QWidget *page_7;
    QHBoxLayout *horizontalLayout_3;
    QTextEdit *textEdit_xml_source;
    QTextEdit *textEdit_xml_target;
    QWidget *page_8;
    QHBoxLayout *horizontalLayout_4;
    QTextEdit *textEdit_5;
    QTextEdit *textEdit_6;
    QWidget *page_9;
    QWidget *page_10;
    QVBoxLayout *verticalLayout_6;
    QWidget *gridWidget_4;
    QGridLayout *gridLayout_4;
    QLineEdit *lineEdit_11;
    QLineEdit *lineEdit_13;
    QLabel *label_13;
    QLabel *label_11;
    QLabel *label_12;
    QLineEdit *lineEdit_12;
    QToolButton *toolButton_5;
    QWidget *page_11;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_14;
    QLineEdit *lineEdit_14;
    QComboBox *comboBox_4;
    QCheckBox *checkBox;
    QToolButton *toolButton_6;
    QSpacerItem *horizontalSpacer_2;
    QTextEdit *textEdit_7;

    void setupUi(QWidget *toolswidget)
    {
        if (toolswidget->objectName().isEmpty())
            toolswidget->setObjectName(QStringLiteral("toolswidget"));
        toolswidget->resize(892, 683);
        toolswidget->setStyleSheet(QLatin1String("background-color: rgb(67, 77, 88);\n"
"color: rgb(255, 255, 255);"));
        verticalLayout_2 = new QVBoxLayout(toolswidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        scrollArea = new QScrollArea(toolswidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 872, 663));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        toolBox = new QToolBox(scrollAreaWidgetContents);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        QFont font;
        font.setFamily(QStringLiteral("OPPOSans B"));
        font.setPointSize(10);
        font.setStyleStrategy(QFont::PreferAntialias);
        toolBox->setFont(font);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        page->setGeometry(QRect(0, 0, 854, 366));
        page->setMinimumSize(QSize(0, 96));
        page->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout_5 = new QVBoxLayout(page);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lineEdit_timestamp_in = new QLineEdit(page);
        lineEdit_timestamp_in->setObjectName(QStringLiteral("lineEdit_timestamp_in"));
        lineEdit_timestamp_in->setMinimumSize(QSize(170, 0));
        lineEdit_timestamp_in->setMaximumSize(QSize(170, 16777215));
        lineEdit_timestamp_in->setFont(font);

        gridLayout->addWidget(lineEdit_timestamp_in, 1, 1, 1, 1);

        label_2 = new QLabel(page);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEdit_date_in = new QLineEdit(page);
        lineEdit_date_in->setObjectName(QStringLiteral("lineEdit_date_in"));
        lineEdit_date_in->setMinimumSize(QSize(170, 0));
        lineEdit_date_in->setMaximumSize(QSize(170, 16777215));
        lineEdit_date_in->setFont(font);

        gridLayout->addWidget(lineEdit_date_in, 2, 1, 1, 1);

        lineEdit_date_out = new QLineEdit(page);
        lineEdit_date_out->setObjectName(QStringLiteral("lineEdit_date_out"));
        lineEdit_date_out->setMinimumSize(QSize(170, 0));
        lineEdit_date_out->setMaximumSize(QSize(170, 16777215));
        lineEdit_date_out->setFont(font);

        gridLayout->addWidget(lineEdit_date_out, 1, 4, 1, 1);

        label = new QLabel(page);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit_now = new QLineEdit(page);
        lineEdit_now->setObjectName(QStringLiteral("lineEdit_now"));
        lineEdit_now->setMinimumSize(QSize(170, 0));
        lineEdit_now->setMaximumSize(QSize(170, 16777215));
        lineEdit_now->setFont(font);

        gridLayout->addWidget(lineEdit_now, 0, 1, 1, 1);

        lineEdit_timestamp_out = new QLineEdit(page);
        lineEdit_timestamp_out->setObjectName(QStringLiteral("lineEdit_timestamp_out"));
        lineEdit_timestamp_out->setMinimumSize(QSize(170, 0));
        lineEdit_timestamp_out->setMaximumSize(QSize(170, 16777215));
        lineEdit_timestamp_out->setFont(font);

        gridLayout->addWidget(lineEdit_timestamp_out, 2, 4, 1, 1);

        toolButton = new QToolButton(page);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setMinimumSize(QSize(60, 0));
        toolButton->setMaximumSize(QSize(60, 16777215));
        toolButton->setFont(font);

        gridLayout->addWidget(toolButton, 1, 3, 1, 1);

        comboBox_timestamp = new QComboBox(page);
        comboBox_timestamp->addItem(QString());
        comboBox_timestamp->addItem(QString());
        comboBox_timestamp->setObjectName(QStringLiteral("comboBox_timestamp"));
        comboBox_timestamp->setMinimumSize(QSize(70, 0));
        comboBox_timestamp->setMaximumSize(QSize(70, 16777215));
        comboBox_timestamp->setFont(font);

        gridLayout->addWidget(comboBox_timestamp, 1, 2, 1, 1);

        toolButton_2 = new QToolButton(page);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        toolButton_2->setMinimumSize(QSize(60, 0));
        toolButton_2->setMaximumSize(QSize(60, 16777215));
        toolButton_2->setFont(font);

        gridLayout->addWidget(toolButton_2, 2, 3, 1, 1);

        label_5 = new QLabel(page);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 6, 1, 1);

        comboBox_date = new QComboBox(page);
        comboBox_date->addItem(QString());
        comboBox_date->addItem(QString());
        comboBox_date->setObjectName(QStringLiteral("comboBox_date"));
        comboBox_date->setMinimumSize(QSize(70, 0));
        comboBox_date->setMaximumSize(QSize(70, 16777215));
        comboBox_date->setFont(font);

        gridLayout->addWidget(comboBox_date, 2, 5, 1, 1);

        toolButton_7 = new QToolButton(page);
        toolButton_7->setObjectName(QStringLiteral("toolButton_7"));
        toolButton_7->setMinimumSize(QSize(60, 0));
        toolButton_7->setMaximumSize(QSize(60, 16777215));
        toolButton_7->setFont(font);

        gridLayout->addWidget(toolButton_7, 0, 3, 1, 1);


        verticalLayout_5->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);

        toolBox->addItem(page, QString::fromUtf8("1. \346\227\266\351\227\264\346\210\263\350\275\254\346\215\242"));
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        page_2->setGeometry(QRect(0, 0, 854, 366));
        verticalLayout_4 = new QVBoxLayout(page_2);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        lineEdit_dec = new QLineEdit(page_2);
        lineEdit_dec->setObjectName(QStringLiteral("lineEdit_dec"));
        lineEdit_dec->setFont(font);

        gridLayout_2->addWidget(lineEdit_dec, 2, 1, 1, 1);

        label_7 = new QLabel(page_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);

        gridLayout_2->addWidget(label_7, 2, 0, 1, 1);

        lineEdit_bin = new QLineEdit(page_2);
        lineEdit_bin->setObjectName(QStringLiteral("lineEdit_bin"));
        lineEdit_bin->setFont(font);

        gridLayout_2->addWidget(lineEdit_bin, 4, 1, 1, 1);

        lineEdit_hex = new QLineEdit(page_2);
        lineEdit_hex->setObjectName(QStringLiteral("lineEdit_hex"));
        lineEdit_hex->setFont(font);

        gridLayout_2->addWidget(lineEdit_hex, 0, 1, 1, 1);

        label_6 = new QLabel(page_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);

        gridLayout_2->addWidget(label_6, 0, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 2, 2, 1, 1);

        label_8 = new QLabel(page_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font);

        gridLayout_2->addWidget(label_8, 4, 0, 1, 1);

        label_15 = new QLabel(page_2);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setFont(font);

        gridLayout_2->addWidget(label_15, 3, 0, 1, 1);

        lineEdit_oct = new QLineEdit(page_2);
        lineEdit_oct->setObjectName(QStringLiteral("lineEdit_oct"));
        lineEdit_oct->setFont(font);

        gridLayout_2->addWidget(lineEdit_oct, 3, 1, 1, 1);


        verticalLayout_4->addLayout(gridLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);

        toolBox->addItem(page_2, QString::fromUtf8("2. \350\277\233\345\210\266\350\275\254\346\215\242"));
        page_5 = new QWidget();
        page_5->setObjectName(QStringLiteral("page_5"));
        page_5->setGeometry(QRect(0, 0, 854, 366));
        verticalLayout_3 = new QVBoxLayout(page_5);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        gridWidget_3 = new QWidget(page_5);
        gridWidget_3->setObjectName(QStringLiteral("gridWidget_3"));
        gridLayout_3 = new QGridLayout(gridWidget_3);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        lineEdit_decode = new QLineEdit(gridWidget_3);
        lineEdit_decode->setObjectName(QStringLiteral("lineEdit_decode"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_decode->sizePolicy().hasHeightForWidth());
        lineEdit_decode->setSizePolicy(sizePolicy);
        lineEdit_decode->setMinimumSize(QSize(0, 100));
        lineEdit_decode->setFont(font);

        gridLayout_3->addWidget(lineEdit_decode, 4, 0, 1, 1);

        label_10 = new QLabel(gridWidget_3);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setMinimumSize(QSize(0, 20));
        label_10->setMaximumSize(QSize(16777215, 20));
        label_10->setFont(font);

        gridLayout_3->addWidget(label_10, 2, 0, 1, 1);

        label_9 = new QLabel(gridWidget_3);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setMinimumSize(QSize(0, 20));
        label_9->setMaximumSize(QSize(16777215, 20));
        label_9->setFont(font);

        gridLayout_3->addWidget(label_9, 0, 0, 1, 1);

        lineEdit_encode = new QLineEdit(gridWidget_3);
        lineEdit_encode->setObjectName(QStringLiteral("lineEdit_encode"));
        sizePolicy.setHeightForWidth(lineEdit_encode->sizePolicy().hasHeightForWidth());
        lineEdit_encode->setSizePolicy(sizePolicy);
        lineEdit_encode->setMinimumSize(QSize(0, 100));
        lineEdit_encode->setFont(font);

        gridLayout_3->addWidget(lineEdit_encode, 1, 0, 1, 1);

        horizontalWidget = new QWidget(gridWidget_3);
        horizontalWidget->setObjectName(QStringLiteral("horizontalWidget"));
        horizontalWidget->setMinimumSize(QSize(0, 20));
        horizontalWidget->setMaximumSize(QSize(16777215, 20));
        horizontalLayout = new QHBoxLayout(horizontalWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        toolButton_decode = new QToolButton(horizontalWidget);
        toolButton_decode->setObjectName(QStringLiteral("toolButton_decode"));
        toolButton_decode->setFont(font);

        horizontalLayout->addWidget(toolButton_decode);

        toolButton_encode = new QToolButton(horizontalWidget);
        toolButton_encode->setObjectName(QStringLiteral("toolButton_encode"));
        toolButton_encode->setFont(font);

        horizontalLayout->addWidget(toolButton_encode);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout_3->addWidget(horizontalWidget, 3, 0, 1, 1);


        verticalLayout_3->addWidget(gridWidget_3);

        toolBox->addItem(page_5, QString::fromUtf8("3. URL\347\274\226\347\240\201\350\275\254\346\215\242"));
        page_6 = new QWidget();
        page_6->setObjectName(QStringLiteral("page_6"));
        page_6->setGeometry(QRect(0, 0, 854, 366));
        horizontalLayout_2 = new QHBoxLayout(page_6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        textEdit_json_source = new QTextEdit(page_6);
        textEdit_json_source->setObjectName(QStringLiteral("textEdit_json_source"));

        horizontalLayout_2->addWidget(textEdit_json_source);

        textEdit_json_target = new QTextEdit(page_6);
        textEdit_json_target->setObjectName(QStringLiteral("textEdit_json_target"));

        horizontalLayout_2->addWidget(textEdit_json_target);

        toolBox->addItem(page_6, QString::fromUtf8("4. JSON\346\240\274\345\274\217\345\214\226"));
        page_7 = new QWidget();
        page_7->setObjectName(QStringLiteral("page_7"));
        page_7->setGeometry(QRect(0, 0, 854, 366));
        horizontalLayout_3 = new QHBoxLayout(page_7);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        textEdit_xml_source = new QTextEdit(page_7);
        textEdit_xml_source->setObjectName(QStringLiteral("textEdit_xml_source"));

        horizontalLayout_3->addWidget(textEdit_xml_source);

        textEdit_xml_target = new QTextEdit(page_7);
        textEdit_xml_target->setObjectName(QStringLiteral("textEdit_xml_target"));

        horizontalLayout_3->addWidget(textEdit_xml_target);

        toolBox->addItem(page_7, QString::fromUtf8("5. XML\346\240\274\345\274\217\345\214\226"));
        page_8 = new QWidget();
        page_8->setObjectName(QStringLiteral("page_8"));
        page_8->setGeometry(QRect(0, 0, 854, 366));
        horizontalLayout_4 = new QHBoxLayout(page_8);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        textEdit_5 = new QTextEdit(page_8);
        textEdit_5->setObjectName(QStringLiteral("textEdit_5"));

        horizontalLayout_4->addWidget(textEdit_5);

        textEdit_6 = new QTextEdit(page_8);
        textEdit_6->setObjectName(QStringLiteral("textEdit_6"));

        horizontalLayout_4->addWidget(textEdit_6);

        toolBox->addItem(page_8, QString::fromUtf8("6. \346\226\207\346\234\254\345\257\271\346\257\224"));
        page_9 = new QWidget();
        page_9->setObjectName(QStringLiteral("page_9"));
        page_9->setGeometry(QRect(0, 0, 854, 366));
        toolBox->addItem(page_9, QString::fromUtf8("7. \345\270\270\347\224\250\345\221\275\344\273\244\346\237\245\350\257\242"));
        page_10 = new QWidget();
        page_10->setObjectName(QStringLiteral("page_10"));
        page_10->setGeometry(QRect(0, 0, 837, 376));
        verticalLayout_6 = new QVBoxLayout(page_10);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        gridWidget_4 = new QWidget(page_10);
        gridWidget_4->setObjectName(QStringLiteral("gridWidget_4"));
        gridLayout_4 = new QGridLayout(gridWidget_4);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        lineEdit_11 = new QLineEdit(gridWidget_4);
        lineEdit_11->setObjectName(QStringLiteral("lineEdit_11"));
        lineEdit_11->setMinimumSize(QSize(0, 100));
        lineEdit_11->setFont(font);

        gridLayout_4->addWidget(lineEdit_11, 1, 0, 1, 1);

        lineEdit_13 = new QLineEdit(gridWidget_4);
        lineEdit_13->setObjectName(QStringLiteral("lineEdit_13"));
        lineEdit_13->setMinimumSize(QSize(0, 100));
        lineEdit_13->setFont(font);

        gridLayout_4->addWidget(lineEdit_13, 5, 0, 1, 1);

        label_13 = new QLabel(gridWidget_4);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setMinimumSize(QSize(0, 20));
        label_13->setMaximumSize(QSize(16777215, 20));
        label_13->setFont(font);

        gridLayout_4->addWidget(label_13, 4, 0, 1, 1);

        label_11 = new QLabel(gridWidget_4);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setMinimumSize(QSize(0, 20));
        label_11->setMaximumSize(QSize(16777215, 20));
        label_11->setFont(font);

        gridLayout_4->addWidget(label_11, 0, 0, 1, 1);

        label_12 = new QLabel(gridWidget_4);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setMinimumSize(QSize(0, 20));
        label_12->setMaximumSize(QSize(16777215, 20));
        label_12->setFont(font);

        gridLayout_4->addWidget(label_12, 2, 0, 1, 1);

        lineEdit_12 = new QLineEdit(gridWidget_4);
        lineEdit_12->setObjectName(QStringLiteral("lineEdit_12"));
        lineEdit_12->setMinimumSize(QSize(0, 50));
        lineEdit_12->setFont(font);

        gridLayout_4->addWidget(lineEdit_12, 3, 0, 1, 1);

        toolButton_5 = new QToolButton(gridWidget_4);
        toolButton_5->setObjectName(QStringLiteral("toolButton_5"));
        toolButton_5->setFont(font);

        gridLayout_4->addWidget(toolButton_5, 3, 1, 1, 1);


        verticalLayout_6->addWidget(gridWidget_4);

        toolBox->addItem(page_10, QString::fromUtf8("8. \346\255\243\345\210\231\350\241\250\350\276\276\345\274\217\347\224\237\346\210\220"));
        page_11 = new QWidget();
        page_11->setObjectName(QStringLiteral("page_11"));
        page_11->setGeometry(QRect(0, 0, 854, 366));
        verticalLayout_7 = new QVBoxLayout(page_11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_14 = new QLabel(page_11);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setFont(font);

        horizontalLayout_5->addWidget(label_14);

        lineEdit_14 = new QLineEdit(page_11);
        lineEdit_14->setObjectName(QStringLiteral("lineEdit_14"));
        lineEdit_14->setFont(font);

        horizontalLayout_5->addWidget(lineEdit_14);

        comboBox_4 = new QComboBox(page_11);
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->setObjectName(QStringLiteral("comboBox_4"));

        horizontalLayout_5->addWidget(comboBox_4);

        checkBox = new QCheckBox(page_11);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setFont(font);

        horizontalLayout_5->addWidget(checkBox);

        toolButton_6 = new QToolButton(page_11);
        toolButton_6->setObjectName(QStringLiteral("toolButton_6"));

        horizontalLayout_5->addWidget(toolButton_6);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);


        verticalLayout_7->addLayout(horizontalLayout_5);

        textEdit_7 = new QTextEdit(page_11);
        textEdit_7->setObjectName(QStringLiteral("textEdit_7"));
        textEdit_7->setFont(font);

        verticalLayout_7->addWidget(textEdit_7);

        toolBox->addItem(page_11, QString::fromUtf8("9. thrift\346\212\223\345\214\205\345\210\206\346\236\220"));

        verticalLayout->addWidget(toolBox);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(scrollArea);


        retranslateUi(toolswidget);

        toolBox->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(toolswidget);
    } // setupUi

    void retranslateUi(QWidget *toolswidget)
    {
        toolswidget->setWindowTitle(QApplication::translate("toolswidget", "Form", nullptr));
        label_2->setText(QApplication::translate("toolswidget", "\346\227\266\351\227\264\346\210\263", nullptr));
        label->setText(QApplication::translate("toolswidget", "\347\216\260\345\234\250\357\274\232", nullptr));
        toolButton->setText(QApplication::translate("toolswidget", "\350\275\254\346\215\242", nullptr));
        comboBox_timestamp->setItemText(0, QApplication::translate("toolswidget", "\347\247\222(s)", nullptr));
        comboBox_timestamp->setItemText(1, QApplication::translate("toolswidget", "\346\257\253\347\247\222(ms)", nullptr));

        toolButton_2->setText(QApplication::translate("toolswidget", "\350\275\254\346\215\242", nullptr));
        label_5->setText(QApplication::translate("toolswidget", "\346\227\266\351\227\264", nullptr));
        comboBox_date->setItemText(0, QApplication::translate("toolswidget", "\347\247\222(s)", nullptr));
        comboBox_date->setItemText(1, QApplication::translate("toolswidget", "\346\257\253\347\247\222(ms)", nullptr));

        toolButton_7->setText(QApplication::translate("toolswidget", "\345\201\234\346\255\242", nullptr));
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("toolswidget", "1. \346\227\266\351\227\264\346\210\263\350\275\254\346\215\242", nullptr));
        label_7->setText(QApplication::translate("toolswidget", "\345\215\201\350\277\233\345\210\266\357\274\232", nullptr));
        label_6->setText(QApplication::translate("toolswidget", "\345\215\201\345\205\255\350\277\233\345\210\266\357\274\232", nullptr));
        label_8->setText(QApplication::translate("toolswidget", "\344\272\214\350\277\233\345\210\266\357\274\232", nullptr));
        label_15->setText(QApplication::translate("toolswidget", "\345\205\253\350\277\233\345\210\266\357\274\232", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_2), QApplication::translate("toolswidget", "2. \350\277\233\345\210\266\350\275\254\346\215\242", nullptr));
        label_10->setText(QApplication::translate("toolswidget", "\347\274\226\347\240\201\347\273\223\346\236\234:", nullptr));
        label_9->setText(QApplication::translate("toolswidget", "URL:", nullptr));
        toolButton_decode->setText(QApplication::translate("toolswidget", "\350\247\243\347\240\201", nullptr));
        toolButton_encode->setText(QApplication::translate("toolswidget", "\347\274\226\347\240\201", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_5), QApplication::translate("toolswidget", "3. URL\347\274\226\347\240\201\350\275\254\346\215\242", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_6), QApplication::translate("toolswidget", "4. JSON\346\240\274\345\274\217\345\214\226", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_7), QApplication::translate("toolswidget", "5. XML\346\240\274\345\274\217\345\214\226", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_8), QApplication::translate("toolswidget", "6. \346\226\207\346\234\254\345\257\271\346\257\224", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_9), QApplication::translate("toolswidget", "7. \345\270\270\347\224\250\345\221\275\344\273\244\346\237\245\350\257\242", nullptr));
        label_13->setText(QApplication::translate("toolswidget", "\345\214\271\351\205\215\347\273\223\346\236\234\357\274\232", nullptr));
        label_11->setText(QApplication::translate("toolswidget", "\345\216\237\346\226\207\357\274\232", nullptr));
        label_12->setText(QApplication::translate("toolswidget", "\346\255\243\345\210\231\350\241\250\350\276\276\345\274\217\357\274\232", nullptr));
        lineEdit_12->setText(QString());
        toolButton_5->setText(QApplication::translate("toolswidget", "\345\274\200\345\247\213\345\214\271\351\205\215", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_10), QApplication::translate("toolswidget", "8. \346\255\243\345\210\231\350\241\250\350\276\276\345\274\217\347\224\237\346\210\220", nullptr));
        label_14->setText(QApplication::translate("toolswidget", "\347\253\257\345\217\243\357\274\232", nullptr));
        comboBox_4->setItemText(0, QApplication::translate("toolswidget", "\344\270\200\346\254\241", nullptr));
        comboBox_4->setItemText(1, QApplication::translate("toolswidget", "\344\272\214\346\254\241", nullptr));
        comboBox_4->setItemText(2, QApplication::translate("toolswidget", "\344\270\211\346\254\241", nullptr));

        checkBox->setText(QApplication::translate("toolswidget", "\346\230\257\345\220\246\345\234\250\347\273\210\347\253\257\350\276\223\345\207\272\345\216\237\345\247\213\346\225\260\346\215\256", nullptr));
        toolButton_6->setText(QApplication::translate("toolswidget", "\345\274\200\345\247\213\346\212\223\345\214\205", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_11), QApplication::translate("toolswidget", "9. thrift\346\212\223\345\214\205\345\210\206\346\236\220", nullptr));
    } // retranslateUi

};

namespace Ui {
    class toolswidget: public Ui_toolswidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLSWIDGET_H
