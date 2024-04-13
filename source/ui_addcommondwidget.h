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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addcommondwidget
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QPlainTextEdit *plainTextEdit;
    QLabel *label_3;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;
    QToolButton *toolButton_4;
    QToolButton *toolButton_5;
    QToolButton *toolButton_6;
    QCheckBox *checkBox;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QToolButton *toolButton_7;
    QToolButton *toolButton_8;

    void setupUi(QWidget *addcommondwidget)
    {
        if (addcommondwidget->objectName().isEmpty())
            addcommondwidget->setObjectName(QStringLiteral("addcommondwidget"));
        addcommondwidget->resize(488, 401);
        addcommondwidget->setMinimumSize(QSize(488, 401));
        addcommondwidget->setMaximumSize(QSize(488, 401));
        QFont font;
        font.setFamily(QStringLiteral("OPPOSans B"));
        font.setPointSize(10);
        font.setStyleStrategy(QFont::PreferAntialias);
        addcommondwidget->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/lib/icon9.png"), QSize(), QIcon::Normal, QIcon::Off);
        addcommondwidget->setWindowIcon(icon);
        addcommondwidget->setStyleSheet(QLatin1String("#addcommondwidget{\n"
"background-color: rgb(30, 45, 54);\n"
"color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QLabel {\n"
"color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QToolButton {\n"
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
        verticalLayout_3 = new QVBoxLayout(addcommondwidget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, -1, -1, 0);
        widget = new QWidget(addcommondwidget);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(0, 30));
        lineEdit->setMaximumSize(QSize(16777215, 30));
        lineEdit->setFont(font);
        lineEdit->setStyleSheet(QLatin1String("QLineEdit{\n"
"color:#ced4da;\n"
"border-radius: 14px;\n"
"background-color: rgb(25, 25, 25, 155);\n"
"border: 0px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding-left:10px;\n"
"padding-right:10px;\n"
"}"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout_2->addWidget(widget);

        label_2 = new QLabel(addcommondwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        verticalLayout_2->addWidget(label_2);

        plainTextEdit = new QPlainTextEdit(addcommondwidget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setFont(font);
        plainTextEdit->setStyleSheet(QLatin1String("QPlainTextEdit{\n"
"color:#ced4da;\n"
"border-radius: 14px;\n"
"background-color: rgb(25, 25, 25, 155);\n"
"border: 0px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding-left:10px;\n"
"padding-right:10px;\n"
"}"));
        plainTextEdit->setOverwriteMode(false);
        plainTextEdit->setBackgroundVisible(false);
        plainTextEdit->setCenterOnScroll(false);

        verticalLayout_2->addWidget(plainTextEdit);

        label_3 = new QLabel(addcommondwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        verticalLayout_2->addWidget(label_3);

        widget_2 = new QWidget(addcommondwidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        toolButton = new QToolButton(widget_2);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setMinimumSize(QSize(70, 30));
        toolButton->setMaximumSize(QSize(70, 30));
        toolButton->setFont(font);

        horizontalLayout_2->addWidget(toolButton);

        toolButton_2 = new QToolButton(widget_2);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        toolButton_2->setMinimumSize(QSize(70, 30));
        toolButton_2->setMaximumSize(QSize(70, 30));
        toolButton_2->setFont(font);

        horizontalLayout_2->addWidget(toolButton_2);

        toolButton_3 = new QToolButton(widget_2);
        toolButton_3->setObjectName(QStringLiteral("toolButton_3"));
        toolButton_3->setMinimumSize(QSize(70, 30));
        toolButton_3->setMaximumSize(QSize(70, 30));
        toolButton_3->setFont(font);

        horizontalLayout_2->addWidget(toolButton_3);

        toolButton_4 = new QToolButton(widget_2);
        toolButton_4->setObjectName(QStringLiteral("toolButton_4"));
        toolButton_4->setMinimumSize(QSize(70, 30));
        toolButton_4->setMaximumSize(QSize(70, 30));
        toolButton_4->setFont(font);

        horizontalLayout_2->addWidget(toolButton_4);

        toolButton_5 = new QToolButton(widget_2);
        toolButton_5->setObjectName(QStringLiteral("toolButton_5"));
        toolButton_5->setMinimumSize(QSize(70, 30));
        toolButton_5->setMaximumSize(QSize(70, 30));
        toolButton_5->setFont(font);

        horizontalLayout_2->addWidget(toolButton_5);

        toolButton_6 = new QToolButton(widget_2);
        toolButton_6->setObjectName(QStringLiteral("toolButton_6"));
        toolButton_6->setMinimumSize(QSize(70, 30));
        toolButton_6->setMaximumSize(QSize(70, 30));
        toolButton_6->setFont(font);

        horizontalLayout_2->addWidget(toolButton_6);


        verticalLayout_2->addWidget(widget_2);

        checkBox = new QCheckBox(addcommondwidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setFont(font);
        checkBox->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        checkBox->setChecked(true);

        verticalLayout_2->addWidget(checkBox);

        widget_3 = new QWidget(addcommondwidget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMaximumSize(QSize(16777215, 40));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(295, 19, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        toolButton_7 = new QToolButton(widget_3);
        toolButton_7->setObjectName(QStringLiteral("toolButton_7"));
        toolButton_7->setMinimumSize(QSize(70, 30));
        toolButton_7->setMaximumSize(QSize(70, 30));
        toolButton_7->setFont(font);

        horizontalLayout_3->addWidget(toolButton_7);

        toolButton_8 = new QToolButton(widget_3);
        toolButton_8->setObjectName(QStringLiteral("toolButton_8"));
        toolButton_8->setMinimumSize(QSize(70, 30));
        toolButton_8->setMaximumSize(QSize(70, 30));
        toolButton_8->setFont(font);
        toolButton_8->setStyleSheet(QLatin1String("QToolButton {\n"
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

        horizontalLayout_3->addWidget(toolButton_8);


        verticalLayout_2->addWidget(widget_3);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(addcommondwidget);

        QMetaObject::connectSlotsByName(addcommondwidget);
    } // setupUi

    void retranslateUi(QWidget *addcommondwidget)
    {
        addcommondwidget->setWindowTitle(QApplication::translate("addcommondwidget", "\346\267\273\345\212\240\345\221\275\344\273\244", nullptr));
        label->setText(QApplication::translate("addcommondwidget", "\345\220\215\347\247\260\357\274\232", nullptr));
        label_2->setText(QApplication::translate("addcommondwidget", "\345\221\275\344\273\244\357\274\232", nullptr));
        plainTextEdit->setPlainText(QString());
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
