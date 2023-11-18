/********************************************************************************
** Form generated from reading UI file 'addcommondwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCOMMONDWIDGET_H
#define UI_ADDCOMMONDWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addcommondwidget
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QPlainTextEdit *plainTextEdit;
    QLabel *label_3;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;
    QToolButton *toolButton_4;
    QToolButton *toolButton_5;
    QToolButton *toolButton_6;
    QCheckBox *checkBox;
    QToolButton *toolButton_7;
    QToolButton *toolButton_8;

    void setupUi(QWidget *addcommondwidget)
    {
        if (addcommondwidget->objectName().isEmpty())
            addcommondwidget->setObjectName(QStringLiteral("addcommondwidget"));
        addcommondwidget->resize(444, 361);
        QFont font;
        font.setFamily(QStringLiteral("OPPOSans B"));
        font.setPointSize(10);
        font.setStyleStrategy(QFont::PreferAntialias);
        addcommondwidget->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/lib/icon9.png"), QSize(), QIcon::Normal, QIcon::Off);
        addcommondwidget->setWindowIcon(icon);
        addcommondwidget->setStyleSheet(QLatin1String("background-color: rgb(30, 45, 54);\n"
"color: rgb(255, 255, 255);"));
        label = new QLabel(addcommondwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 51, 31));
        label->setFont(font);
        lineEdit = new QLineEdit(addcommondwidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(70, 10, 271, 31));
        lineEdit->setFont(font);
        label_2 = new QLabel(addcommondwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 50, 51, 31));
        label_2->setFont(font);
        plainTextEdit = new QPlainTextEdit(addcommondwidget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(10, 80, 421, 131));
        plainTextEdit->setFont(font);
        plainTextEdit->setOverwriteMode(false);
        plainTextEdit->setBackgroundVisible(false);
        plainTextEdit->setCenterOnScroll(false);
        label_3 = new QLabel(addcommondwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 220, 151, 31));
        label_3->setFont(font);
        toolButton = new QToolButton(addcommondwidget);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(10, 250, 51, 31));
        toolButton->setFont(font);
        toolButton_2 = new QToolButton(addcommondwidget);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        toolButton_2->setGeometry(QRect(80, 250, 51, 31));
        toolButton_2->setFont(font);
        toolButton_3 = new QToolButton(addcommondwidget);
        toolButton_3->setObjectName(QStringLiteral("toolButton_3"));
        toolButton_3->setGeometry(QRect(140, 250, 51, 31));
        toolButton_3->setFont(font);
        toolButton_4 = new QToolButton(addcommondwidget);
        toolButton_4->setObjectName(QStringLiteral("toolButton_4"));
        toolButton_4->setGeometry(QRect(200, 250, 51, 31));
        toolButton_4->setFont(font);
        toolButton_5 = new QToolButton(addcommondwidget);
        toolButton_5->setObjectName(QStringLiteral("toolButton_5"));
        toolButton_5->setGeometry(QRect(270, 250, 51, 31));
        toolButton_5->setFont(font);
        toolButton_6 = new QToolButton(addcommondwidget);
        toolButton_6->setObjectName(QStringLiteral("toolButton_6"));
        toolButton_6->setGeometry(QRect(340, 250, 51, 31));
        toolButton_6->setFont(font);
        checkBox = new QCheckBox(addcommondwidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(10, 290, 141, 31));
        checkBox->setFont(font);
        checkBox->setChecked(true);
        toolButton_7 = new QToolButton(addcommondwidget);
        toolButton_7->setObjectName(QStringLiteral("toolButton_7"));
        toolButton_7->setGeometry(QRect(280, 320, 71, 31));
        toolButton_7->setFont(font);
        toolButton_8 = new QToolButton(addcommondwidget);
        toolButton_8->setObjectName(QStringLiteral("toolButton_8"));
        toolButton_8->setGeometry(QRect(360, 320, 71, 31));
        toolButton_8->setFont(font);

        retranslateUi(addcommondwidget);

        QMetaObject::connectSlotsByName(addcommondwidget);
    } // setupUi

    void retranslateUi(QWidget *addcommondwidget)
    {
        addcommondwidget->setWindowTitle(QApplication::translate("addcommondwidget", "\346\267\273\345\212\240\345\221\275\344\273\244", nullptr));
        label->setText(QApplication::translate("addcommondwidget", "\345\220\215\347\247\260\357\274\232", nullptr));
        label_2->setText(QApplication::translate("addcommondwidget", "\345\221\275\344\273\244\357\274\232", nullptr));
        plainTextEdit->setPlainText(QApplication::translate("addcommondwidget", "312312312312\n"
"312312312\n"
"312\n"
"3123\n"
"123\n"
"1232", nullptr));
        label_3->setText(QApplication::translate("addcommondwidget", "\346\217\222\345\205\245\345\217\202\346\225\260\357\274\210\345\212\250\346\200\201\347\224\237\346\210\220\345\221\275\344\273\244\357\274\211", nullptr));
        toolButton->setText(QApplication::translate("addcommondwidget", "\345\217\202\346\225\2601", nullptr));
        toolButton_2->setText(QApplication::translate("addcommondwidget", "\345\217\202\346\225\2602", nullptr));
        toolButton_3->setText(QApplication::translate("addcommondwidget", "\345\217\202\346\225\2603", nullptr));
        toolButton_4->setText(QApplication::translate("addcommondwidget", "\345\217\202\346\225\2604", nullptr));
        toolButton_5->setText(QApplication::translate("addcommondwidget", "\345\217\202\346\225\2605", nullptr));
        toolButton_6->setText(QApplication::translate("addcommondwidget", "\345\217\202\346\225\2606", nullptr));
        checkBox->setText(QApplication::translate("addcommondwidget", "\346\234\253\345\260\276\346\267\273\345\212\240\345\233\236\350\275\246\347\254\246", nullptr));
        toolButton_7->setText(QApplication::translate("addcommondwidget", "\347\241\256\345\256\232", nullptr));
        toolButton_8->setText(QApplication::translate("addcommondwidget", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addcommondwidget: public Ui_addcommondwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCOMMONDWIDGET_H
