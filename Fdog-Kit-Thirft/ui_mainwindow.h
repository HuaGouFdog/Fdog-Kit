/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QWidget *widget_title;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *toolButton;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QToolButton *toolButton_min_2;
    QToolButton *toolButton_max_2;
    QToolButton *toolButton_close_2;
    QWidget *widget_body;
    QVBoxLayout *verticalLayout_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1030, 709);
        QFont font;
        font.setPointSize(8);
        MainWindow->setFont(font);
        MainWindow->setStyleSheet(QLatin1String("QMainWindow,QWidget#centralWidget {\n"
"background-color: rgb(67, 67, 67);\n"
"border-radius:10px;\n"
"}"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QLatin1String("#centralWidget {\n"
"border-image: url(:/lib/back1.png);\n"
"border-radius:10px;\n"
"}"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_title = new QWidget(centralWidget);
        widget_title->setObjectName(QStringLiteral("widget_title"));
        widget_title->setMinimumSize(QSize(0, 30));
        widget_title->setMaximumSize(QSize(16777215, 30));
        widget_title->setStyleSheet(QLatin1String("background-color: rgba(30, 45, 54, 0);\n"
"color: rgb(255, 255, 255);\n"
""));
        horizontalLayout_2 = new QHBoxLayout(widget_title);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        toolButton = new QToolButton(widget_title);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setMinimumSize(QSize(40, 30));
        toolButton->setMaximumSize(QSize(40, 30));
        toolButton->setStyleSheet(QLatin1String("QToolButton {\n"
"	color: rgb(255, 255, 255);\n"
"	\n"
"	background-color: rgba(94, 255, 210, 0);\n"
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
"\n"
"	\n"
"	background-color: rgb(23, 35, 42);\n"
"	border: none;\n"
"}"));
        QIcon icon;
        icon.addFile(QStringLiteral("lib/icon9.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);
        toolButton->setIconSize(QSize(22, 22));

        horizontalLayout_2->addWidget(toolButton);

        label = new QLabel(widget_title);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(120, 0));
        QFont font1;
        font1.setFamily(QStringLiteral("OPPOSans B"));
        font1.setPointSize(10);
        label->setFont(font1);
        label->setStyleSheet(QStringLiteral(""));

        horizontalLayout_2->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        toolButton_min_2 = new QToolButton(widget_title);
        toolButton_min_2->setObjectName(QStringLiteral("toolButton_min_2"));
        toolButton_min_2->setMinimumSize(QSize(40, 29));
        toolButton_min_2->setMaximumSize(QSize(40, 29));
        QFont font2;
        font2.setPointSize(10);
        font2.setStyleStrategy(QFont::PreferAntialias);
        toolButton_min_2->setFont(font2);
        toolButton_min_2->setStyleSheet(QLatin1String("QToolButton {\n"
"	color: rgb(255, 255, 255);\n"
"	\n"
"	background-color: rgba(94, 255, 210, 0);\n"
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
"\n"
"	\n"
"	background-color: rgb(23, 35, 42);\n"
"	border: none;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/lib/icon-minus3.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_min_2->setIcon(icon1);
        toolButton_min_2->setIconSize(QSize(13, 13));

        horizontalLayout_2->addWidget(toolButton_min_2);

        toolButton_max_2 = new QToolButton(widget_title);
        toolButton_max_2->setObjectName(QStringLiteral("toolButton_max_2"));
        toolButton_max_2->setMinimumSize(QSize(40, 29));
        toolButton_max_2->setMaximumSize(QSize(40, 29));
        toolButton_max_2->setFont(font2);
        toolButton_max_2->setStyleSheet(QLatin1String("QToolButton {\n"
"	color: rgb(255, 255, 255);\n"
"	\n"
"	background-color: rgba(94, 255, 210, 0);\n"
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
"	background-color: rgb(23, 35, 42);\n"
"	border: none;\n"
"}"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/lib/Icon_max4.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_max_2->setIcon(icon2);
        toolButton_max_2->setIconSize(QSize(11, 11));
        toolButton_max_2->setCheckable(false);
        toolButton_max_2->setAutoRepeat(false);
        toolButton_max_2->setAutoExclusive(false);
        toolButton_max_2->setAutoRaise(false);

        horizontalLayout_2->addWidget(toolButton_max_2);

        toolButton_close_2 = new QToolButton(widget_title);
        toolButton_close_2->setObjectName(QStringLiteral("toolButton_close_2"));
        toolButton_close_2->setMinimumSize(QSize(40, 29));
        toolButton_close_2->setMaximumSize(QSize(40, 29));
        toolButton_close_2->setFont(font2);
        toolButton_close_2->setStyleSheet(QLatin1String("QToolButton {\n"
"	color: rgb(255, 255, 255);\n"
"	border-top-right-radius: 9px;\n"
"	background-color: rgba(94, 255, 210, 0);\n"
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
"	\n"
"	background-color: rgb(200, 0, 0);\n"
"	border: none;\n"
"}"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/lib/icon-close8.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_close_2->setIcon(icon3);
        toolButton_close_2->setIconSize(QSize(11, 11));
        toolButton_close_2->setCheckable(false);

        horizontalLayout_2->addWidget(toolButton_close_2);


        verticalLayout->addWidget(widget_title);

        widget_body = new QWidget(centralWidget);
        widget_body->setObjectName(QStringLiteral("widget_body"));
        widget_body->setStyleSheet(QStringLiteral(""));
        verticalLayout_2 = new QVBoxLayout(widget_body);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);

        verticalLayout->addWidget(widget_body);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Fdog-zookeeper", nullptr));
        toolButton->setText(QString());
        label->setText(QApplication::translate("MainWindow", "thrift\346\216\245\345\217\243\350\260\203\347\224\250\345\267\245\345\205\267", nullptr));
        toolButton_min_2->setText(QString());
        toolButton_max_2->setText(QString());
        toolButton_close_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
