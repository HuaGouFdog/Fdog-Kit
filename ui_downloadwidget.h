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
#include <QtWidgets/QProgressBar>
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
    QToolButton *toolButton_file_3;
    QToolButton *toolButton_file_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QWidget *widget_5;
    QProgressBar *progressBar;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer;
    QLabel *label_4;

    void setupUi(QWidget *downloadwidget)
    {
        if (downloadwidget->objectName().isEmpty())
            downloadwidget->setObjectName(QStringLiteral("downloadwidget"));
        downloadwidget->resize(280, 330);
        downloadwidget->setMinimumSize(QSize(280, 0));
        downloadwidget->setMaximumSize(QSize(280, 16777215));
        downloadwidget->setStyleSheet(QStringLiteral(""));
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
"	border: 1px solid;\n"
"	\n"
"	\n"
"	border-color: rgb(255, 255, 255);\n"
"	\n"
"	background-color: rgb(30, 45, 54);\n"
"	border-radius: 5px;\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(widget_body);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(5, 0, 5, 5);
        widget_3 = new QWidget(widget_body);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setStyleSheet(QStringLiteral("background-color: rgba(125, 125, 125, 0);"));
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
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/lib/file.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_file_3->setIcon(icon1);
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
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/lib/setting2.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_file_2->setIcon(icon2);
        toolButton_file_2->setIconSize(QSize(20, 20));

        horizontalLayout_2->addWidget(toolButton_file_2);


        verticalLayout_2->addWidget(widget_3);

        scrollArea = new QScrollArea(widget_body);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setStyleSheet(QLatin1String("#scrollArea{\n"
"background-color: rgba(255, 255, 255, 0);\n"
"	border: 1px solid;\n"
"	\n"
"	border-color: rgb(255, 255, 255);\n"
"}\n"
""));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 268, 238));
        widget = new QWidget(scrollAreaWidgetContents);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 0, 251, 41));
        widget->setStyleSheet(QStringLiteral(""));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 20));
        label->setMaximumSize(QSize(16777215, 20));
        QFont font1;
        font1.setFamily(QStringLiteral("OPPOSans B"));
        font1.setPointSize(9);
        font1.setStyleStrategy(QFont::PreferAntialias);
        label->setFont(font1);
        label->setStyleSheet(QStringLiteral(""));

        verticalLayout_3->addWidget(label);

        widget_5 = new QWidget(widget);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setMinimumSize(QSize(0, 20));
        widget_5->setMaximumSize(QSize(16777215, 20));

        verticalLayout_3->addWidget(widget_5);

        progressBar = new QProgressBar(scrollAreaWidgetContents);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(10, 100, 241, 18));
        progressBar->setMinimumSize(QSize(0, 18));
        progressBar->setMaximumSize(QSize(16777215, 18));
        progressBar->setStyleSheet(QLatin1String("QProgressBar {\n"
"	border: 1px solid;\n"
"	border-color: rgb(91, 91, 91);\n"
"	border-radius: 0px; \n"
"	/*background-color: #FFFFFF; */\n"
"	text-align:center; \n"
"	color: rgba(0, 0, 0, 200);\n"
"}\n"
"\n"
"QProgressBar:chunk{\n"
"	border-radius:0px;\n"
"	background-color: rgb(180, 220, 255);\n"
"}"));
        progressBar->setValue(95);
        progressBar->setTextVisible(false);
        progressBar->setInvertedAppearance(false);
        progressBar->setTextDirection(QProgressBar::TopToBottom);
        widget_4 = new QWidget(scrollAreaWidgetContents);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setGeometry(QRect(10, 70, 241, 18));
        widget_4->setMinimumSize(QSize(0, 18));
        widget_4->setMaximumSize(QSize(16777215, 18));
        widget_4->setStyleSheet(QLatin1String("background-color: rgba(131, 185, 255, 0);\n"
"color: rgb(0, 0, 0);"));
        horizontalLayout = new QHBoxLayout(widget_4);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(3, 0, 3, 0);
        label_3 = new QLabel(widget_4);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(12, 12));
        label_3->setMaximumSize(QSize(12, 12));
        label_3->setStyleSheet(QStringLiteral("image: url(:/lib/peixu.png);"));

        horizontalLayout->addWidget(label_3);

        horizontalSpacer = new QSpacerItem(99, 15, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_4 = new QLabel(widget_4);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMaximumSize(QSize(16777215, 15));
        QFont font2;
        font2.setFamily(QStringLiteral("OPPOSans B"));
        font2.setPointSize(9);
        label_4->setFont(font2);
        label_4->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(label_4);

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
        label->setText(QApplication::translate("downloadwidget", "bison-2.5.1.tar.gz", nullptr));
        progressBar->setFormat(QApplication::translate("downloadwidget", "%p%", nullptr));
        label_3->setText(QString());
        label_4->setText(QApplication::translate("downloadwidget", "52.6% 456k/s  23M", nullptr));
    } // retranslateUi

};

namespace Ui {
    class downloadwidget: public Ui_downloadwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOWNLOADWIDGET_H
