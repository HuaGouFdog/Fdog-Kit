/********************************************************************************
** Form generated from reading UI file 'findwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDWIDGET_H
#define UI_FINDWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_findwidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *horizontalWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEdit_search;
    QLabel *label_conut;
    QToolButton *toolButton_up;
    QToolButton *toolButton_down;
    QToolButton *toolButton_close;

    void setupUi(QWidget *findwidget)
    {
        if (findwidget->objectName().isEmpty())
            findwidget->setObjectName(QStringLiteral("findwidget"));
        findwidget->resize(260, 35);
        findwidget->setMinimumSize(QSize(260, 35));
        findwidget->setMaximumSize(QSize(260, 35));
        QFont font;
        font.setFamily(QStringLiteral("OPPOSans B"));
        font.setPointSize(10);
        font.setStyleStrategy(QFont::PreferAntialias);
        findwidget->setFont(font);
        findwidget->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(findwidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(3, 0, 0, 2);
        horizontalWidget = new QWidget(findwidget);
        horizontalWidget->setObjectName(QStringLiteral("horizontalWidget"));
        horizontalWidget->setMinimumSize(QSize(0, 28));
        horizontalWidget->setMaximumSize(QSize(16777215, 25));
        horizontalLayout = new QHBoxLayout(horizontalWidget);
        horizontalLayout->setSpacing(3);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 10, 0);
        widget_4 = new QWidget(horizontalWidget);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setMinimumSize(QSize(53, 25));
        widget_4->setMaximumSize(QSize(16777215, 25));
        widget_4->setStyleSheet(QLatin1String("#widget_4{\n"
"background-color: rgba(144, 144, 144, 150);\n"
"border: 0px solid rgba(255, 255, 255, 0);\n"
"border-radius: 8px;\n"
"}\n"
"\n"
""));
        horizontalLayout_3 = new QHBoxLayout(widget_4);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(4, 0, 4, 0);
        lineEdit_search = new QLineEdit(widget_4);
        lineEdit_search->setObjectName(QStringLiteral("lineEdit_search"));
        lineEdit_search->setMinimumSize(QSize(140, 25));
        lineEdit_search->setMaximumSize(QSize(140, 25));
        lineEdit_search->setFont(font);
        lineEdit_search->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"border: 0px solid rgba(255, 255, 255, 0);"));

        horizontalLayout_3->addWidget(lineEdit_search);

        label_conut = new QLabel(widget_4);
        label_conut->setObjectName(QStringLiteral("label_conut"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_conut->sizePolicy().hasHeightForWidth());
        label_conut->setSizePolicy(sizePolicy);
        label_conut->setMinimumSize(QSize(30, 25));
        label_conut->setMaximumSize(QSize(1555555, 25));
        label_conut->setFont(font);
        label_conut->setStyleSheet(QLatin1String("\n"
"border: 1px solid rgba(255, 255, 255, 0);\n"
"\n"
""));

        horizontalLayout_3->addWidget(label_conut);


        horizontalLayout->addWidget(widget_4);

        toolButton_up = new QToolButton(horizontalWidget);
        toolButton_up->setObjectName(QStringLiteral("toolButton_up"));
        toolButton_up->setMinimumSize(QSize(22, 20));
        toolButton_up->setMaximumSize(QSize(22, 25));
        toolButton_up->setStyleSheet(QLatin1String("QToolButton {\n"
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
        icon.addFile(QStringLiteral(":/lib/down.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_up->setIcon(icon);
        toolButton_up->setIconSize(QSize(25, 25));

        horizontalLayout->addWidget(toolButton_up);

        toolButton_down = new QToolButton(horizontalWidget);
        toolButton_down->setObjectName(QStringLiteral("toolButton_down"));
        toolButton_down->setMinimumSize(QSize(22, 25));
        toolButton_down->setMaximumSize(QSize(22, 25));
        toolButton_down->setStyleSheet(QLatin1String("QToolButton {\n"
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
        icon1.addFile(QStringLiteral(":/lib/up.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_down->setIcon(icon1);
        toolButton_down->setIconSize(QSize(25, 25));

        horizontalLayout->addWidget(toolButton_down);

        toolButton_close = new QToolButton(horizontalWidget);
        toolButton_close->setObjectName(QStringLiteral("toolButton_close"));
        toolButton_close->setMinimumSize(QSize(22, 25));
        toolButton_close->setMaximumSize(QSize(22, 25));
        toolButton_close->setStyleSheet(QLatin1String("QToolButton {\n"
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
        icon2.addFile(QStringLiteral(":/lib/icon-close4.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_close->setIcon(icon2);
        toolButton_close->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(toolButton_close);


        verticalLayout->addWidget(horizontalWidget);


        retranslateUi(findwidget);

        QMetaObject::connectSlotsByName(findwidget);
    } // setupUi

    void retranslateUi(QWidget *findwidget)
    {
        findwidget->setWindowTitle(QApplication::translate("findwidget", "Form", nullptr));
        lineEdit_search->setPlaceholderText(QApplication::translate("findwidget", "\346\220\234\347\264\242", nullptr));
        label_conut->setText(QApplication::translate("findwidget", "0/0", nullptr));
        toolButton_up->setText(QString());
        toolButton_down->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class findwidget: public Ui_findwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDWIDGET_H
