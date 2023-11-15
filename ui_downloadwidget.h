/********************************************************************************
** Form generated from reading UI file 'downloadwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOWNLOADWIDGET_H
#define UI_DOWNLOADWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_downloadwidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QToolButton *toolButton_file_3;
    QToolButton *toolButton_file_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_8;
    QLineEdit *lineEdit_9;

    void setupUi(QWidget *downloadwidget)
    {
        if (downloadwidget->objectName().isEmpty())
            downloadwidget->setObjectName(QStringLiteral("downloadwidget"));
        downloadwidget->resize(280, 323);
        downloadwidget->setMinimumSize(QSize(280, 0));
        downloadwidget->setMaximumSize(QSize(280, 16777215));
        downloadwidget->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);"));
        verticalLayout = new QVBoxLayout(downloadwidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(3, 3, 3, 3);
        widget_2 = new QWidget(downloadwidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setStyleSheet(QLatin1String("#widget_2{\n"
"	\n"
"	background-color: rgb(138, 138, 138);\n"
"	border-radius: 5px;\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(5, 0, 5, 5);
        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setStyleSheet(QStringLiteral("background-color: rgba(125, 125, 125, 0);"));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(5, 5, 5, 5);
        label_2 = new QLabel(widget_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font;
        font.setFamily(QStringLiteral("OPPOSans B"));
        font.setPointSize(10);
        font.setStyleStrategy(QFont::PreferAntialias);
        label_2->setFont(font);
        label_2->setLayoutDirection(Qt::LeftToRight);
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_2->setWordWrap(true);

        horizontalLayout_2->addWidget(label_2);

        toolButton_file_3 = new QToolButton(widget_3);
        toolButton_file_3->setObjectName(QStringLiteral("toolButton_file_3"));
        toolButton_file_3->setMinimumSize(QSize(22, 25));
        toolButton_file_3->setMaximumSize(QSize(22, 25));
        toolButton_file_3->setStyleSheet(QLatin1String("QToolButton {\n"
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
        QIcon icon;
        icon.addFile(QStringLiteral(":/lib/file.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_file_3->setIcon(icon);
        toolButton_file_3->setIconSize(QSize(20, 20));

        horizontalLayout_2->addWidget(toolButton_file_3);

        toolButton_file_2 = new QToolButton(widget_3);
        toolButton_file_2->setObjectName(QStringLiteral("toolButton_file_2"));
        toolButton_file_2->setMinimumSize(QSize(22, 25));
        toolButton_file_2->setMaximumSize(QSize(22, 25));
        toolButton_file_2->setStyleSheet(QLatin1String("QToolButton {\n"
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
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/lib/setting2.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_file_2->setIcon(icon1);
        toolButton_file_2->setIconSize(QSize(20, 20));

        horizontalLayout_2->addWidget(toolButton_file_2);


        verticalLayout_2->addWidget(widget_3);

        scrollArea = new QScrollArea(widget_2);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 262, 266));
        lineEdit = new QLineEdit(scrollAreaWidgetContents);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(0, 0, 261, 20));
        lineEdit_2 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(0, 30, 261, 20));
        lineEdit_3 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(0, 60, 261, 20));
        lineEdit_4 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(0, 90, 261, 20));
        lineEdit_5 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(0, 120, 261, 20));
        lineEdit_6 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(0, 150, 261, 20));
        lineEdit_7 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(0, 180, 261, 20));
        lineEdit_8 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));
        lineEdit_8->setGeometry(QRect(0, 210, 261, 20));
        lineEdit_9 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_9->setObjectName(QStringLiteral("lineEdit_9"));
        lineEdit_9->setGeometry(QRect(0, 240, 261, 20));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(scrollArea);


        verticalLayout->addWidget(widget_2);


        retranslateUi(downloadwidget);

        QMetaObject::connectSlotsByName(downloadwidget);
    } // setupUi

    void retranslateUi(QWidget *downloadwidget)
    {
        downloadwidget->setWindowTitle(QApplication::translate("downloadwidget", "Form", nullptr));
        label_2->setText(QApplication::translate("downloadwidget", "\345\275\223\345\211\215\344\270\213\350\275\275\350\267\257\345\276\204\357\274\232 C:\\Users\\\345\274\240\346\227\255\\Desktop\\fsdownload", nullptr));
    } // retranslateUi

};

namespace Ui {
    class downloadwidget: public Ui_downloadwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOWNLOADWIDGET_H
