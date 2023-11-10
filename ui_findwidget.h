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
#include <QtWidgets/QSpacerItem>
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
    QSpacerItem *horizontalSpacer;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;

    void setupUi(QWidget *findwidget)
    {
        if (findwidget->objectName().isEmpty())
            findwidget->setObjectName(QStringLiteral("findwidget"));
        findwidget->resize(502, 30);
        findwidget->setMinimumSize(QSize(245, 30));
        findwidget->setMaximumSize(QSize(16777215, 30));
        findwidget->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);"));
        verticalLayout = new QVBoxLayout(findwidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 5, 10, 0);
        horizontalWidget = new QWidget(findwidget);
        horizontalWidget->setObjectName(QStringLiteral("horizontalWidget"));
        horizontalWidget->setMinimumSize(QSize(0, 24));
        horizontalWidget->setMaximumSize(QSize(16777215, 25));
        horizontalLayout = new QHBoxLayout(horizontalWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        lineEdit = new QLineEdit(horizontalWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(150, 25));
        lineEdit->setMaximumSize(QSize(150, 25));
        QFont font;
        font.setFamily(QStringLiteral("OPPOSans B"));
        font.setPointSize(10);
        font.setStyleStrategy(QFont::PreferAntialias);
        lineEdit->setFont(font);
        lineEdit->setStyleSheet(QLatin1String("background-color: rgb(25, 25, 25, 155);\n"
"border: 1px solid rgba(255, 255, 255, 0);"));

        horizontalLayout->addWidget(lineEdit);

        label_2 = new QLabel(horizontalWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setFont(font);
        label_2->setStyleSheet(QLatin1String("background-color: rgb(25, 25, 25, 155);\n"
"border: 1px solid rgba(255, 255, 255, 0);\n"
"border-right-radius: 5px;"));

        horizontalLayout->addWidget(label_2);

        toolButton = new QToolButton(horizontalWidget);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setMinimumSize(QSize(22, 20));
        toolButton->setMaximumSize(QSize(22, 25));
        toolButton->setStyleSheet(QLatin1String("QToolButton {\n"
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
        toolButton->setIcon(icon);
        toolButton->setIconSize(QSize(25, 25));

        horizontalLayout->addWidget(toolButton);

        toolButton_2 = new QToolButton(horizontalWidget);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        toolButton_2->setMinimumSize(QSize(22, 25));
        toolButton_2->setMaximumSize(QSize(22, 25));
        toolButton_2->setStyleSheet(QLatin1String("QToolButton {\n"
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
        toolButton_2->setIcon(icon1);
        toolButton_2->setIconSize(QSize(25, 25));

        horizontalLayout->addWidget(toolButton_2);

        toolButton_3 = new QToolButton(horizontalWidget);
        toolButton_3->setObjectName(QStringLiteral("toolButton_3"));
        toolButton_3->setMinimumSize(QSize(22, 25));
        toolButton_3->setMaximumSize(QSize(22, 25));
        toolButton_3->setStyleSheet(QLatin1String("QToolButton {\n"
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
        toolButton_3->setIcon(icon2);
        toolButton_3->setIconSize(QSize(25, 25));

        horizontalLayout->addWidget(toolButton_3);


        verticalLayout->addWidget(horizontalWidget);


        retranslateUi(findwidget);

        QMetaObject::connectSlotsByName(findwidget);
    } // setupUi

    void retranslateUi(QWidget *findwidget)
    {
        findwidget->setWindowTitle(QApplication::translate("findwidget", "Form", nullptr));
        lineEdit->setPlaceholderText(QApplication::translate("findwidget", "\346\220\234\347\264\242", nullptr));
        label_2->setText(QApplication::translate("findwidget", "0/0", nullptr));
        toolButton->setText(QString());
        toolButton_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class findwidget: public Ui_findwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDWIDGET_H
