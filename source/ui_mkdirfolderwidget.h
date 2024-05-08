/********************************************************************************
** Form generated from reading UI file 'mkdirfolderwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MKDIRFOLDERWIDGET_H
#define UI_MKDIRFOLDERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mkdirfolderwidget
{
public:
    QLabel *label;
    QLineEdit *lineEdit_name;
    QToolButton *toolButton_ok;
    QToolButton *toolButton_cancel;

    void setupUi(QWidget *mkdirfolderwidget)
    {
        if (mkdirfolderwidget->objectName().isEmpty())
            mkdirfolderwidget->setObjectName(QStringLiteral("mkdirfolderwidget"));
        mkdirfolderwidget->resize(252, 104);
        QFont font;
        font.setFamily(QStringLiteral("OPPOSans B"));
        font.setPointSize(10);
        font.setStyleStrategy(QFont::PreferAntialias);
        mkdirfolderwidget->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/lib/icon9.png"), QSize(), QIcon::Normal, QIcon::Off);
        mkdirfolderwidget->setWindowIcon(icon);
        mkdirfolderwidget->setStyleSheet(QLatin1String("background-color: rgb(30, 45, 54);\n"
"color: rgb(255, 255, 255);"));
        label = new QLabel(mkdirfolderwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 54, 31));
        label->setFont(font);
        lineEdit_name = new QLineEdit(mkdirfolderwidget);
        lineEdit_name->setObjectName(QStringLiteral("lineEdit_name"));
        lineEdit_name->setGeometry(QRect(60, 10, 171, 31));
        lineEdit_name->setFont(font);
        lineEdit_name->setStyleSheet(QLatin1String("QLineEdit{\n"
"color:#ced4da;\n"
"border-radius: 14px;\n"
"background-color: rgb(25, 25, 25, 155);\n"
"border: 0px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding-left:10px;\n"
"padding-right:10px;\n"
"}"));
        toolButton_ok = new QToolButton(mkdirfolderwidget);
        toolButton_ok->setObjectName(QStringLiteral("toolButton_ok"));
        toolButton_ok->setGeometry(QRect(90, 60, 61, 30));
        toolButton_ok->setMinimumSize(QSize(0, 30));
        toolButton_ok->setMaximumSize(QSize(16777215, 30));
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
        toolButton_cancel = new QToolButton(mkdirfolderwidget);
        toolButton_cancel->setObjectName(QStringLiteral("toolButton_cancel"));
        toolButton_cancel->setGeometry(QRect(170, 60, 61, 31));
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

        retranslateUi(mkdirfolderwidget);

        QMetaObject::connectSlotsByName(mkdirfolderwidget);
    } // setupUi

    void retranslateUi(QWidget *mkdirfolderwidget)
    {
        mkdirfolderwidget->setWindowTitle(QApplication::translate("mkdirfolderwidget", "\345\210\233\345\273\272\345\210\206\347\261\273", nullptr));
        label->setText(QApplication::translate("mkdirfolderwidget", "\345\220\215\347\247\260\357\274\232", nullptr));
        toolButton_ok->setText(QApplication::translate("mkdirfolderwidget", "\347\241\256\345\256\232", nullptr));
        toolButton_cancel->setText(QApplication::translate("mkdirfolderwidget", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mkdirfolderwidget: public Ui_mkdirfolderwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MKDIRFOLDERWIDGET_H
