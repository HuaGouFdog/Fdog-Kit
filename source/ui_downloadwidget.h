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
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_downloadwidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QToolButton *toolButton_file;
    QWidget *widget_body;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QToolButton *toolButton_file_open;
    QToolButton *toolButton_file_setting;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *downloadwidget)
    {
        if (downloadwidget->objectName().isEmpty())
            downloadwidget->setObjectName(QStringLiteral("downloadwidget"));
        downloadwidget->resize(280, 330);
        downloadwidget->setMinimumSize(QSize(280, 0));
        downloadwidget->setMaximumSize(QSize(280, 16777215));
        downloadwidget->setStyleSheet(QStringLiteral("color: rgb(45, 45, 45);"));
        verticalLayout = new QVBoxLayout(downloadwidget);
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 3, 0, 0);
        widget_2 = new QWidget(downloadwidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMinimumSize(QSize(0, 28));
        horizontalLayout_3 = new QHBoxLayout(widget_2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 5, 0);
        horizontalSpacer_2 = new QSpacerItem(244, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        toolButton_file = new QToolButton(widget_2);
        toolButton_file->setObjectName(QStringLiteral("toolButton_file"));
        toolButton_file->setMinimumSize(QSize(22, 25));
        toolButton_file->setMaximumSize(QSize(22, 25));
        toolButton_file->setStyleSheet(QLatin1String("QToolButton {\n"
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
        icon.addFile(QStringLiteral(":/lib/download.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_file->setIcon(icon);
        toolButton_file->setIconSize(QSize(22, 22));

        horizontalLayout_3->addWidget(toolButton_file);


        verticalLayout->addWidget(widget_2);

        widget_body = new QWidget(downloadwidget);
        widget_body->setObjectName(QStringLiteral("widget_body"));
        widget_body->setStyleSheet(QLatin1String("#widget_body{\n"
"background-color: rgb(255, 255, 255);\n"
"/*padding:5px;*/\n"
"border-radius:6px;\n"
"	border: 2px solid;\n"
"	border-color: rgba(126, 126, 126, 50);\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(widget_body);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(5, 2, 5, 5);
        widget_3 = new QWidget(widget_body);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(5, 5, 0, 5);
        label_2 = new QLabel(widget_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font;
        font.setFamily(QStringLiteral("OPPOSans B"));
        font.setPointSize(10);
        font.setStyleStrategy(QFont::PreferAntialias);
        label_2->setFont(font);
        label_2->setLayoutDirection(Qt::LeftToRight);
        label_2->setStyleSheet(QStringLiteral(""));
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_2->setWordWrap(true);

        horizontalLayout_2->addWidget(label_2);

        toolButton_file_open = new QToolButton(widget_3);
        toolButton_file_open->setObjectName(QStringLiteral("toolButton_file_open"));
        toolButton_file_open->setMinimumSize(QSize(22, 25));
        toolButton_file_open->setMaximumSize(QSize(22, 25));
        toolButton_file_open->setStyleSheet(QLatin1String("QToolButton {\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(255, 255, 255);\n"
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
"	background-color: rgb(255, 255, 255);\n"
"	border: none;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/lib/file.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_file_open->setIcon(icon1);
        toolButton_file_open->setIconSize(QSize(20, 20));

        horizontalLayout_2->addWidget(toolButton_file_open);

        toolButton_file_setting = new QToolButton(widget_3);
        toolButton_file_setting->setObjectName(QStringLiteral("toolButton_file_setting"));
        toolButton_file_setting->setMinimumSize(QSize(22, 25));
        toolButton_file_setting->setMaximumSize(QSize(22, 25));
        toolButton_file_setting->setStyleSheet(QLatin1String("QToolButton {\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(255, 255, 255);\n"
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
"	background-color: rgb(255, 255, 255);\n"
"	border: none;\n"
"}"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/lib/setting3.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_file_setting->setIcon(icon2);
        toolButton_file_setting->setIconSize(QSize(20, 20));

        horizontalLayout_2->addWidget(toolButton_file_setting);


        verticalLayout_2->addWidget(widget_3);

        scrollArea = new QScrollArea(widget_body);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setMinimumSize(QSize(0, 0));
        scrollArea->setStyleSheet(QLatin1String("#scrollArea{\n"
"	border: 1px solid;\n"
"	border-color: rgba(126, 126, 126, 50);\n"
"	background-color: rgba(29, 29, 29, 50);\n"
"}\n"
""));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 268, 236));
        scrollAreaWidgetContents->setMinimumSize(QSize(0, 0));
        scrollAreaWidgetContents->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 150);"));
        verticalLayout_3 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 233, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(scrollArea);


        verticalLayout->addWidget(widget_body);


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
