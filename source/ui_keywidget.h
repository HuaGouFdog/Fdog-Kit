/********************************************************************************
** Form generated from reading UI file 'keywidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KEYWIDGET_H
#define UI_KEYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_keywidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QToolButton *toolButton_cancel;
    QWidget *gridWidget;
    QGridLayout *gridLayout;
    QLabel *label_key_pssword;
    QLineEdit *lineEdit_key;
    QLineEdit *lineEdit_key_pssword;
    QLabel *label_name;
    QLabel *label_key;
    QLineEdit *lineEdit_name;
    QToolButton *toolButton_browse;
    QToolButton *toolButton_ok;

    void setupUi(QWidget *keywidget)
    {
        if (keywidget->objectName().isEmpty())
            keywidget->setObjectName(QStringLiteral("keywidget"));
        keywidget->resize(348, 221);
        QFont font;
        font.setFamily(QStringLiteral("OPPOSans B"));
        font.setPointSize(10);
        font.setStyleStrategy(QFont::PreferAntialias);
        keywidget->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/lib/wicon_46.png"), QSize(), QIcon::Normal, QIcon::Off);
        keywidget->setWindowIcon(icon);
        keywidget->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(keywidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(keywidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setStyleSheet(QLatin1String("#widget{\n"
"	border-image: url(:/lib/back1.png);\n"
"	background-color: rgb(30, 45, 54);\n"
"	color: rgb(255, 255, 255);\n"
"}"));
        toolButton_cancel = new QToolButton(widget);
        toolButton_cancel->setObjectName(QStringLiteral("toolButton_cancel"));
        toolButton_cancel->setGeometry(QRect(260, 170, 70, 30));
        toolButton_cancel->setMinimumSize(QSize(70, 30));
        toolButton_cancel->setMaximumSize(QSize(70, 30));
        toolButton_cancel->setFont(font);
        toolButton_cancel->setStyleSheet(QLatin1String("QToolButton {\n"
"	color: rgb(255, 255, 255);\n"
"	\n"
"	background-color: rgb(67, 67, 67);\n"
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
"	background-color: rgb(67, 67, 67);\n"
"}"));
        gridWidget = new QWidget(widget);
        gridWidget->setObjectName(QStringLiteral("gridWidget"));
        gridWidget->setGeometry(QRect(10, 10, 331, 141));
        gridWidget->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        gridLayout = new QGridLayout(gridWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(12);
        gridLayout->setVerticalSpacing(6);
        label_key_pssword = new QLabel(gridWidget);
        label_key_pssword->setObjectName(QStringLiteral("label_key_pssword"));
        QFont font1;
        font1.setFamily(QStringLiteral("OPPOSans B"));
        font1.setPointSize(10);
        label_key_pssword->setFont(font1);

        gridLayout->addWidget(label_key_pssword, 2, 0, 1, 1);

        lineEdit_key = new QLineEdit(gridWidget);
        lineEdit_key->setObjectName(QStringLiteral("lineEdit_key"));
        lineEdit_key->setMinimumSize(QSize(0, 30));
        lineEdit_key->setMaximumSize(QSize(16777215, 30));
        lineEdit_key->setStyleSheet(QLatin1String("background-color: rgb(25, 25, 25, 155);\n"
"border: 1px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding-left:10px;\n"
"padding-right:10px;"));

        gridLayout->addWidget(lineEdit_key, 1, 1, 1, 1);

        lineEdit_key_pssword = new QLineEdit(gridWidget);
        lineEdit_key_pssword->setObjectName(QStringLiteral("lineEdit_key_pssword"));
        lineEdit_key_pssword->setMinimumSize(QSize(0, 30));
        lineEdit_key_pssword->setMaximumSize(QSize(16777215, 30));
        lineEdit_key_pssword->setStyleSheet(QLatin1String("background-color: rgb(25, 25, 25, 155);\n"
"border: 1px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding-left:10px;\n"
"padding-right:10px;"));
        lineEdit_key_pssword->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(lineEdit_key_pssword, 2, 1, 1, 1);

        label_name = new QLabel(gridWidget);
        label_name->setObjectName(QStringLiteral("label_name"));
        label_name->setFont(font1);

        gridLayout->addWidget(label_name, 0, 0, 1, 1);

        label_key = new QLabel(gridWidget);
        label_key->setObjectName(QStringLiteral("label_key"));
        label_key->setFont(font1);

        gridLayout->addWidget(label_key, 1, 0, 1, 1);

        lineEdit_name = new QLineEdit(gridWidget);
        lineEdit_name->setObjectName(QStringLiteral("lineEdit_name"));
        lineEdit_name->setMinimumSize(QSize(0, 30));
        lineEdit_name->setMaximumSize(QSize(16777215, 30));
        lineEdit_name->setStyleSheet(QLatin1String("background-color: rgb(25, 25, 25, 155);\n"
"border: 1px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding-left:10px;\n"
"padding-right:10px;"));

        gridLayout->addWidget(lineEdit_name, 0, 1, 1, 1);

        toolButton_browse = new QToolButton(gridWidget);
        toolButton_browse->setObjectName(QStringLiteral("toolButton_browse"));
        toolButton_browse->setMinimumSize(QSize(70, 30));
        toolButton_browse->setMaximumSize(QSize(70, 30));
        toolButton_browse->setFont(font1);
        toolButton_browse->setStyleSheet(QLatin1String("QToolButton {\n"
"	color: rgb(26, 26, 26);\n"
"	background-color: rgb(113, 212, 219);\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QToolButton::menu-indicator { \n"
"	image: None;\n"
"}\n"
"\n"
" \n"
"QToolButton:hover {\n"
"	color: rgb(26, 26, 26);\n"
"	background-color: rgb(113, 212, 219);\n"
"}"));

        gridLayout->addWidget(toolButton_browse, 1, 2, 1, 1);

        toolButton_ok = new QToolButton(widget);
        toolButton_ok->setObjectName(QStringLiteral("toolButton_ok"));
        toolButton_ok->setGeometry(QRect(170, 170, 70, 30));
        toolButton_ok->setMinimumSize(QSize(70, 30));
        toolButton_ok->setMaximumSize(QSize(70, 30));
        toolButton_ok->setFont(font);
        toolButton_ok->setStyleSheet(QLatin1String("QToolButton {\n"
"	color: rgb(26, 26, 26);\n"
"	background-color: rgb(113, 212, 219);\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QToolButton::menu-indicator { \n"
"	image: None;\n"
"}\n"
"\n"
" \n"
"QToolButton:hover {\n"
"	color: rgb(26, 26, 26);\n"
"	background-color: rgb(113, 212, 219);\n"
"}"));

        verticalLayout->addWidget(widget);


        retranslateUi(keywidget);

        QMetaObject::connectSlotsByName(keywidget);
    } // setupUi

    void retranslateUi(QWidget *keywidget)
    {
        keywidget->setWindowTitle(QApplication::translate("keywidget", "\345\257\274\345\205\245\347\247\201\351\222\245", nullptr));
        toolButton_cancel->setText(QApplication::translate("keywidget", "\345\217\226\346\266\210", nullptr));
        label_key_pssword->setText(QApplication::translate("keywidget", "\347\247\201\351\222\245\345\257\206\347\240\201\357\274\232", nullptr));
        label_name->setText(QApplication::translate("keywidget", "\345\220\215\347\247\260\357\274\232", nullptr));
        label_key->setText(QApplication::translate("keywidget", "\347\247\201\351\222\245\357\274\232", nullptr));
        toolButton_browse->setText(QApplication::translate("keywidget", "\346\265\217\350\247\210", nullptr));
        toolButton_ok->setText(QApplication::translate("keywidget", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class keywidget: public Ui_keywidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KEYWIDGET_H
