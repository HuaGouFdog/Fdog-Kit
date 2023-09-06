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
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_4;
    QLabel *label_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QComboBox *comboBox;
    QToolButton *toolButton;
    QLabel *label_5;
    QLineEdit *lineEdit_3;
    QComboBox *comboBox_3;
    QToolButton *toolButton_2;
    QLineEdit *lineEdit_5;
    QSpacerItem *verticalSpacer;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_4;
    QGridLayout *gridLayout_2;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_8;
    QSpacerItem *verticalSpacer_2;
    QWidget *page_5;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout_3;
    QLineEdit *lineEdit_10;
    QLabel *label_10;
    QLabel *label_9;
    QLineEdit *lineEdit_9;
    QWidget *horizontalWidget;
    QHBoxLayout *horizontalLayout;
    QToolButton *toolButton_4;
    QToolButton *toolButton_3;
    QSpacerItem *horizontalSpacer;
    QWidget *page_6;
    QHBoxLayout *horizontalLayout_2;
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;
    QWidget *page_7;
    QHBoxLayout *horizontalLayout_3;
    QTextEdit *textEdit_3;
    QTextEdit *textEdit_4;
    QWidget *page_8;
    QHBoxLayout *horizontalLayout_4;
    QTextEdit *textEdit_5;
    QTextEdit *textEdit_6;
    QWidget *page_9;
    QWidget *page_10;
    QVBoxLayout *verticalLayout_6;
    QGridLayout *gridLayout_4;
    QLineEdit *lineEdit_11;
    QLineEdit *lineEdit_13;
    QLabel *label_13;
    QLabel *label_11;
    QLabel *label_12;
    QLineEdit *lineEdit_12;
    QToolButton *toolButton_5;
    QWidget *page_11;
    QTextEdit *textEdit_7;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_14;
    QLineEdit *lineEdit_14;
    QComboBox *comboBox_4;
    QCheckBox *checkBox;
    QToolButton *toolButton_6;
    QSpacerItem *horizontalSpacer_2;

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
        lineEdit_2 = new QLineEdit(page);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setFont(font);

        gridLayout->addWidget(lineEdit_2, 1, 1, 1, 1);

        lineEdit_4 = new QLineEdit(page);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setFont(font);

        gridLayout->addWidget(lineEdit_4, 1, 4, 1, 1);

        label_2 = new QLabel(page);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label = new QLabel(page);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit = new QLineEdit(page);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setFont(font);

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        comboBox = new QComboBox(page);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setMinimumSize(QSize(60, 0));
        comboBox->setMaximumSize(QSize(60, 16777215));
        comboBox->setFont(font);

        gridLayout->addWidget(comboBox, 1, 2, 1, 1);

        toolButton = new QToolButton(page);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setMinimumSize(QSize(60, 0));
        toolButton->setMaximumSize(QSize(60, 16777215));
        toolButton->setFont(font);

        gridLayout->addWidget(toolButton, 1, 3, 1, 1);

        label_5 = new QLabel(page);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        lineEdit_3 = new QLineEdit(page);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setFont(font);

        gridLayout->addWidget(lineEdit_3, 2, 1, 1, 1);

        comboBox_3 = new QComboBox(page);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));
        comboBox_3->setMinimumSize(QSize(60, 0));
        comboBox_3->setMaximumSize(QSize(60, 16777215));
        comboBox_3->setFont(font);

        gridLayout->addWidget(comboBox_3, 2, 2, 1, 1);

        toolButton_2 = new QToolButton(page);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        toolButton_2->setMinimumSize(QSize(60, 0));
        toolButton_2->setMaximumSize(QSize(60, 16777215));
        toolButton_2->setFont(font);

        gridLayout->addWidget(toolButton_2, 2, 3, 1, 1);

        lineEdit_5 = new QLineEdit(page);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setFont(font);

        gridLayout->addWidget(lineEdit_5, 2, 4, 1, 1);


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
        label_6 = new QLabel(page_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);

        gridLayout_2->addWidget(label_6, 0, 0, 1, 1);

        label_7 = new QLabel(page_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);

        gridLayout_2->addWidget(label_7, 1, 0, 1, 1);

        label_8 = new QLabel(page_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font);

        gridLayout_2->addWidget(label_8, 2, 0, 1, 1);

        lineEdit_6 = new QLineEdit(page_2);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setFont(font);

        gridLayout_2->addWidget(lineEdit_6, 0, 1, 1, 1);

        lineEdit_7 = new QLineEdit(page_2);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));
        lineEdit_7->setFont(font);

        gridLayout_2->addWidget(lineEdit_7, 1, 1, 1, 1);

        lineEdit_8 = new QLineEdit(page_2);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));
        lineEdit_8->setFont(font);

        gridLayout_2->addWidget(lineEdit_8, 2, 1, 1, 1);


        verticalLayout_4->addLayout(gridLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);

        toolBox->addItem(page_2, QString::fromUtf8("2. \350\277\233\345\210\266\350\275\254\346\215\242"));
        page_5 = new QWidget();
        page_5->setObjectName(QStringLiteral("page_5"));
        verticalLayout_3 = new QVBoxLayout(page_5);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        lineEdit_10 = new QLineEdit(page_5);
        lineEdit_10->setObjectName(QStringLiteral("lineEdit_10"));
        lineEdit_10->setMinimumSize(QSize(0, 100));
        lineEdit_10->setFont(font);

        gridLayout_3->addWidget(lineEdit_10, 4, 0, 1, 1);

        label_10 = new QLabel(page_5);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setMinimumSize(QSize(0, 20));
        label_10->setMaximumSize(QSize(16777215, 20));
        label_10->setFont(font);

        gridLayout_3->addWidget(label_10, 2, 0, 1, 1);

        label_9 = new QLabel(page_5);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setMinimumSize(QSize(0, 20));
        label_9->setMaximumSize(QSize(16777215, 20));
        label_9->setFont(font);

        gridLayout_3->addWidget(label_9, 0, 0, 1, 1);

        lineEdit_9 = new QLineEdit(page_5);
        lineEdit_9->setObjectName(QStringLiteral("lineEdit_9"));
        lineEdit_9->setMinimumSize(QSize(0, 100));
        lineEdit_9->setFont(font);

        gridLayout_3->addWidget(lineEdit_9, 1, 0, 1, 1);

        horizontalWidget = new QWidget(page_5);
        horizontalWidget->setObjectName(QStringLiteral("horizontalWidget"));
        horizontalWidget->setMinimumSize(QSize(0, 20));
        horizontalWidget->setMaximumSize(QSize(16777215, 20));
        horizontalLayout = new QHBoxLayout(horizontalWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        toolButton_4 = new QToolButton(horizontalWidget);
        toolButton_4->setObjectName(QStringLiteral("toolButton_4"));
        toolButton_4->setFont(font);

        horizontalLayout->addWidget(toolButton_4);

        toolButton_3 = new QToolButton(horizontalWidget);
        toolButton_3->setObjectName(QStringLiteral("toolButton_3"));
        toolButton_3->setFont(font);

        horizontalLayout->addWidget(toolButton_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout_3->addWidget(horizontalWidget, 3, 0, 1, 1);


        verticalLayout_3->addLayout(gridLayout_3);

        toolBox->addItem(page_5, QString::fromUtf8("3. URL\347\274\226\347\240\201\350\275\254\346\215\242"));
        page_6 = new QWidget();
        page_6->setObjectName(QStringLiteral("page_6"));
        horizontalLayout_2 = new QHBoxLayout(page_6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        textEdit = new QTextEdit(page_6);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        horizontalLayout_2->addWidget(textEdit);

        textEdit_2 = new QTextEdit(page_6);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));

        horizontalLayout_2->addWidget(textEdit_2);

        toolBox->addItem(page_6, QString::fromUtf8("4. JSON\346\240\274\345\274\217\345\214\226"));
        page_7 = new QWidget();
        page_7->setObjectName(QStringLiteral("page_7"));
        horizontalLayout_3 = new QHBoxLayout(page_7);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        textEdit_3 = new QTextEdit(page_7);
        textEdit_3->setObjectName(QStringLiteral("textEdit_3"));

        horizontalLayout_3->addWidget(textEdit_3);

        textEdit_4 = new QTextEdit(page_7);
        textEdit_4->setObjectName(QStringLiteral("textEdit_4"));

        horizontalLayout_3->addWidget(textEdit_4);

        toolBox->addItem(page_7, QString::fromUtf8("5. XML\346\240\274\345\274\217\345\214\226"));
        page_8 = new QWidget();
        page_8->setObjectName(QStringLiteral("page_8"));
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
        toolBox->addItem(page_9, QString::fromUtf8("7. \345\270\270\347\224\250\345\221\275\344\273\244\346\237\245\350\257\242"));
        page_10 = new QWidget();
        page_10->setObjectName(QStringLiteral("page_10"));
        verticalLayout_6 = new QVBoxLayout(page_10);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        lineEdit_11 = new QLineEdit(page_10);
        lineEdit_11->setObjectName(QStringLiteral("lineEdit_11"));
        lineEdit_11->setMinimumSize(QSize(0, 100));
        lineEdit_11->setFont(font);

        gridLayout_4->addWidget(lineEdit_11, 1, 0, 1, 1);

        lineEdit_13 = new QLineEdit(page_10);
        lineEdit_13->setObjectName(QStringLiteral("lineEdit_13"));
        lineEdit_13->setMinimumSize(QSize(0, 100));
        lineEdit_13->setFont(font);

        gridLayout_4->addWidget(lineEdit_13, 5, 0, 1, 1);

        label_13 = new QLabel(page_10);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setMinimumSize(QSize(0, 20));
        label_13->setMaximumSize(QSize(16777215, 20));
        label_13->setFont(font);

        gridLayout_4->addWidget(label_13, 4, 0, 1, 1);

        label_11 = new QLabel(page_10);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setMinimumSize(QSize(0, 20));
        label_11->setMaximumSize(QSize(16777215, 20));
        label_11->setFont(font);

        gridLayout_4->addWidget(label_11, 0, 0, 1, 1);

        label_12 = new QLabel(page_10);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setMinimumSize(QSize(0, 20));
        label_12->setMaximumSize(QSize(16777215, 20));
        label_12->setFont(font);

        gridLayout_4->addWidget(label_12, 2, 0, 1, 1);

        lineEdit_12 = new QLineEdit(page_10);
        lineEdit_12->setObjectName(QStringLiteral("lineEdit_12"));
        lineEdit_12->setMinimumSize(QSize(0, 50));
        lineEdit_12->setFont(font);

        gridLayout_4->addWidget(lineEdit_12, 3, 0, 1, 1);

        toolButton_5 = new QToolButton(page_10);
        toolButton_5->setObjectName(QStringLiteral("toolButton_5"));
        toolButton_5->setFont(font);

        gridLayout_4->addWidget(toolButton_5, 3, 1, 1, 1);


        verticalLayout_6->addLayout(gridLayout_4);

        toolBox->addItem(page_10, QString::fromUtf8("8. \346\255\243\345\210\231\350\241\250\350\276\276\345\274\217\347\224\237\346\210\220"));
        page_11 = new QWidget();
        page_11->setObjectName(QStringLiteral("page_11"));
        textEdit_7 = new QTextEdit(page_11);
        textEdit_7->setObjectName(QStringLiteral("textEdit_7"));
        textEdit_7->setGeometry(QRect(0, 70, 851, 291));
        textEdit_7->setFont(font);
        horizontalLayoutWidget = new QWidget(page_11);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 851, 51));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_14 = new QLabel(horizontalLayoutWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setFont(font);

        horizontalLayout_5->addWidget(label_14);

        lineEdit_14 = new QLineEdit(horizontalLayoutWidget);
        lineEdit_14->setObjectName(QStringLiteral("lineEdit_14"));
        lineEdit_14->setFont(font);

        horizontalLayout_5->addWidget(lineEdit_14);

        comboBox_4 = new QComboBox(horizontalLayoutWidget);
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->setObjectName(QStringLiteral("comboBox_4"));

        horizontalLayout_5->addWidget(comboBox_4);

        checkBox = new QCheckBox(horizontalLayoutWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setFont(font);

        horizontalLayout_5->addWidget(checkBox);

        toolButton_6 = new QToolButton(horizontalLayoutWidget);
        toolButton_6->setObjectName(QStringLiteral("toolButton_6"));

        horizontalLayout_5->addWidget(toolButton_6);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        toolBox->addItem(page_11, QString::fromUtf8("9. thrift\346\212\223\345\214\205\345\210\206\346\236\220"));

        verticalLayout->addWidget(toolBox);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(scrollArea);


        retranslateUi(toolswidget);

        toolBox->setCurrentIndex(8);


        QMetaObject::connectSlotsByName(toolswidget);
    } // setupUi

    void retranslateUi(QWidget *toolswidget)
    {
        toolswidget->setWindowTitle(QApplication::translate("toolswidget", "Form", nullptr));
        label_2->setText(QApplication::translate("toolswidget", "\346\227\266\351\227\264\346\210\263", nullptr));
        label->setText(QApplication::translate("toolswidget", "\347\216\260\345\234\250\357\274\232", nullptr));
        comboBox->setItemText(0, QApplication::translate("toolswidget", "\347\247\222(s)", nullptr));
        comboBox->setItemText(1, QApplication::translate("toolswidget", "\346\257\253\347\247\222(ms)", nullptr));

        toolButton->setText(QApplication::translate("toolswidget", "\350\275\254\346\215\242", nullptr));
        label_5->setText(QApplication::translate("toolswidget", "\346\227\266\351\227\264", nullptr));
        comboBox_3->setItemText(0, QApplication::translate("toolswidget", "\347\247\222(s)", nullptr));
        comboBox_3->setItemText(1, QApplication::translate("toolswidget", "\346\257\253\347\247\222(ms)", nullptr));

        toolButton_2->setText(QApplication::translate("toolswidget", "\350\275\254\346\215\242", nullptr));
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("toolswidget", "1. \346\227\266\351\227\264\346\210\263\350\275\254\346\215\242", nullptr));
        label_6->setText(QApplication::translate("toolswidget", "\344\272\214\350\277\233\345\210\266", nullptr));
        label_7->setText(QApplication::translate("toolswidget", "\345\205\253\350\277\233\345\210\266", nullptr));
        label_8->setText(QApplication::translate("toolswidget", "\345\215\201\345\205\255\350\277\233\345\210\266", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_2), QApplication::translate("toolswidget", "2. \350\277\233\345\210\266\350\275\254\346\215\242", nullptr));
        label_10->setText(QApplication::translate("toolswidget", "\347\274\226\347\240\201\347\273\223\346\236\234:", nullptr));
        label_9->setText(QApplication::translate("toolswidget", "URL:", nullptr));
        toolButton_4->setText(QApplication::translate("toolswidget", "\350\247\243\347\240\201", nullptr));
        toolButton_3->setText(QApplication::translate("toolswidget", "\347\274\226\347\240\201", nullptr));
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
