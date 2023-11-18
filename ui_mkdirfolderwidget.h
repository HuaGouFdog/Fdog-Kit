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
    QLineEdit *lineEdit;
    QToolButton *toolButton;
    QToolButton *toolButton_2;

    void setupUi(QWidget *mkdirfolderwidget)
    {
        if (mkdirfolderwidget->objectName().isEmpty())
            mkdirfolderwidget->setObjectName(QStringLiteral("mkdirfolderwidget"));
        mkdirfolderwidget->resize(252, 104);
        QFont font;
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
        QFont font1;
        font1.setFamily(QStringLiteral("OPPOSans R"));
        font1.setPointSize(10);
        font1.setStyleStrategy(QFont::PreferAntialias);
        label->setFont(font1);
        lineEdit = new QLineEdit(mkdirfolderwidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(60, 10, 171, 31));
        lineEdit->setFont(font1);
        toolButton = new QToolButton(mkdirfolderwidget);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(90, 60, 61, 31));
        toolButton->setFont(font1);
        toolButton_2 = new QToolButton(mkdirfolderwidget);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        toolButton_2->setGeometry(QRect(170, 60, 61, 31));
        toolButton_2->setFont(font1);

        retranslateUi(mkdirfolderwidget);

        QMetaObject::connectSlotsByName(mkdirfolderwidget);
    } // setupUi

    void retranslateUi(QWidget *mkdirfolderwidget)
    {
        mkdirfolderwidget->setWindowTitle(QApplication::translate("mkdirfolderwidget", "\345\210\233\345\273\272\345\210\206\347\261\273", nullptr));
        label->setText(QApplication::translate("mkdirfolderwidget", "\345\220\215\347\247\260\357\274\232", nullptr));
        toolButton->setText(QApplication::translate("mkdirfolderwidget", "\347\241\256\345\256\232", nullptr));
        toolButton_2->setText(QApplication::translate("mkdirfolderwidget", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mkdirfolderwidget: public Ui_mkdirfolderwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MKDIRFOLDERWIDGET_H
