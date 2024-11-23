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
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        toolButton_min_2 = new QToolButton(widget_title);
        toolButton_min_2->setObjectName(QStringLiteral("toolButton_min_2"));
        toolButton_min_2->setMinimumSize(QSize(40, 29));
        toolButton_min_2->setMaximumSize(QSize(40, 29));
        QFont font;
        font.setPointSize(10);
        font.setStyleStrategy(QFont::PreferAntialias);
        toolButton_min_2->setFont(font);
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
        QIcon icon;
        icon.addFile(QStringLiteral(":/lib/icon-minus3.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_min_2->setIcon(icon);
        toolButton_min_2->setIconSize(QSize(13, 13));

        horizontalLayout_2->addWidget(toolButton_min_2);

        toolButton_max_2 = new QToolButton(widget_title);
        toolButton_max_2->setObjectName(QStringLiteral("toolButton_max_2"));
        toolButton_max_2->setMinimumSize(QSize(40, 29));
        toolButton_max_2->setMaximumSize(QSize(40, 29));
        toolButton_max_2->setFont(font);
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
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/lib/Icon_max4.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_max_2->setIcon(icon1);
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
        toolButton_close_2->setFont(font);
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
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/lib/icon-close8.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_close_2->setIcon(icon2);
        toolButton_close_2->setIconSize(QSize(11, 11));
        toolButton_close_2->setCheckable(false);

        horizontalLayout_2->addWidget(toolButton_close_2);


        verticalLayout->addWidget(widget_title);

        widget_body = new QWidget(centralWidget);
        widget_body->setObjectName(QStringLiteral("widget_body"));
        verticalLayout_2 = new QVBoxLayout(widget_body);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));

        verticalLayout->addWidget(widget_body);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Fdog-Kit-Zookeeper", nullptr));
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
