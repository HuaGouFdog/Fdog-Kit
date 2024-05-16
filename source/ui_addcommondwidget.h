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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addcommondwidget
{
public:
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_body;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_name;
    QLabel *label_2;
    QTextEdit *textEdit_date;
    QLabel *label_3;
    QWidget *widget_param;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *toolButton_param1;
    QToolButton *toolButton_param2;
    QToolButton *toolButton_param3;
    QToolButton *toolButton_param4;
    QToolButton *toolButton_param5;
    QToolButton *toolButton_param6;
    QCheckBox *checkBox_enter;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QToolButton *toolButton_ok;
    QToolButton *toolButton_cancel;

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
        addcommondwidget->setStyleSheet(QLatin1String("\n"
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
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        widget_body = new QWidget(addcommondwidget);
        widget_body->setObjectName(QStringLiteral("widget_body"));
        widget_body->setStyleSheet(QLatin1String("#widget_body{\n"
"border-image: url(:/lib/back1.png);\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(widget_body);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, -1, -1, 9);
        widget = new QWidget(widget_body);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        horizontalLayout->addWidget(label);

        lineEdit_name = new QLineEdit(widget);
        lineEdit_name->setObjectName(QStringLiteral("lineEdit_name"));
        lineEdit_name->setMinimumSize(QSize(0, 30));
        lineEdit_name->setMaximumSize(QSize(16777215, 30));
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

        horizontalLayout->addWidget(lineEdit_name);


        verticalLayout_2->addWidget(widget);

        label_2 = new QLabel(widget_body);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        verticalLayout_2->addWidget(label_2);

        textEdit_date = new QTextEdit(widget_body);
        textEdit_date->setObjectName(QStringLiteral("textEdit_date"));
        textEdit_date->setStyleSheet(QLatin1String("QTextEdit{\n"
"color:#ced4da;\n"
"border-radius: 14px;\n"
"background-color: rgb(25, 25, 25, 155);\n"
"border: 0px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding-left:5px;\n"
"padding-right:5px;\n"
"}"));

        verticalLayout_2->addWidget(textEdit_date);

        label_3 = new QLabel(widget_body);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        verticalLayout_2->addWidget(label_3);

        widget_param = new QWidget(widget_body);
        widget_param->setObjectName(QStringLiteral("widget_param"));
        horizontalLayout_2 = new QHBoxLayout(widget_param);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        toolButton_param1 = new QToolButton(widget_param);
        toolButton_param1->setObjectName(QStringLiteral("toolButton_param1"));
        toolButton_param1->setMinimumSize(QSize(70, 30));
        toolButton_param1->setMaximumSize(QSize(70, 30));
        toolButton_param1->setFont(font);

        horizontalLayout_2->addWidget(toolButton_param1);

        toolButton_param2 = new QToolButton(widget_param);
        toolButton_param2->setObjectName(QStringLiteral("toolButton_param2"));
        toolButton_param2->setMinimumSize(QSize(70, 30));
        toolButton_param2->setMaximumSize(QSize(70, 30));
        toolButton_param2->setFont(font);

        horizontalLayout_2->addWidget(toolButton_param2);

        toolButton_param3 = new QToolButton(widget_param);
        toolButton_param3->setObjectName(QStringLiteral("toolButton_param3"));
        toolButton_param3->setMinimumSize(QSize(70, 30));
        toolButton_param3->setMaximumSize(QSize(70, 30));
        toolButton_param3->setFont(font);

        horizontalLayout_2->addWidget(toolButton_param3);

        toolButton_param4 = new QToolButton(widget_param);
        toolButton_param4->setObjectName(QStringLiteral("toolButton_param4"));
        toolButton_param4->setMinimumSize(QSize(70, 30));
        toolButton_param4->setMaximumSize(QSize(70, 30));
        toolButton_param4->setFont(font);

        horizontalLayout_2->addWidget(toolButton_param4);

        toolButton_param5 = new QToolButton(widget_param);
        toolButton_param5->setObjectName(QStringLiteral("toolButton_param5"));
        toolButton_param5->setMinimumSize(QSize(70, 30));
        toolButton_param5->setMaximumSize(QSize(70, 30));
        toolButton_param5->setFont(font);

        horizontalLayout_2->addWidget(toolButton_param5);

        toolButton_param6 = new QToolButton(widget_param);
        toolButton_param6->setObjectName(QStringLiteral("toolButton_param6"));
        toolButton_param6->setMinimumSize(QSize(70, 30));
        toolButton_param6->setMaximumSize(QSize(70, 30));
        toolButton_param6->setFont(font);

        horizontalLayout_2->addWidget(toolButton_param6);


        verticalLayout_2->addWidget(widget_param);

        checkBox_enter = new QCheckBox(widget_body);
        checkBox_enter->setObjectName(QStringLiteral("checkBox_enter"));
        checkBox_enter->setFont(font);
        checkBox_enter->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        checkBox_enter->setChecked(true);

        verticalLayout_2->addWidget(checkBox_enter);

        widget_3 = new QWidget(widget_body);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMaximumSize(QSize(16777215, 40));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(295, 19, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        toolButton_ok = new QToolButton(widget_3);
        toolButton_ok->setObjectName(QStringLiteral("toolButton_ok"));
        toolButton_ok->setMinimumSize(QSize(70, 30));
        toolButton_ok->setMaximumSize(QSize(70, 30));
        toolButton_ok->setFont(font);

        horizontalLayout_3->addWidget(toolButton_ok);

        toolButton_cancel = new QToolButton(widget_3);
        toolButton_cancel->setObjectName(QStringLiteral("toolButton_cancel"));
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

        horizontalLayout_3->addWidget(toolButton_cancel);


        verticalLayout_2->addWidget(widget_3);


        verticalLayout_3->addWidget(widget_body);


        retranslateUi(addcommondwidget);

        QMetaObject::connectSlotsByName(addcommondwidget);
    } // setupUi

    void retranslateUi(QWidget *addcommondwidget)
    {
        addcommondwidget->setWindowTitle(QApplication::translate("addcommondwidget", "\346\267\273\345\212\240\345\221\275\344\273\244", nullptr));
        label->setText(QApplication::translate("addcommondwidget", "\345\220\215\347\247\260\357\274\232", nullptr));
        lineEdit_name->setText(QString());
        label_2->setText(QApplication::translate("addcommondwidget", "\345\221\275\344\273\244\357\274\232", nullptr));
        label_3->setText(QApplication::translate("addcommondwidget", "\346\217\222\345\205\245\345\217\202\346\225\260\357\274\210\345\212\250\346\200\201\347\224\237\346\210\220\345\221\275\344\273\244\357\274\211", nullptr));
        toolButton_param1->setText(QApplication::translate("addcommondwidget", "\345\217\202\346\225\2601", nullptr));
        toolButton_param2->setText(QApplication::translate("addcommondwidget", "\345\217\202\346\225\2602", nullptr));
        toolButton_param3->setText(QApplication::translate("addcommondwidget", "\345\217\202\346\225\2603", nullptr));
        toolButton_param4->setText(QApplication::translate("addcommondwidget", "\345\217\202\346\225\2604", nullptr));
        toolButton_param5->setText(QApplication::translate("addcommondwidget", "\345\217\202\346\225\2605", nullptr));
        toolButton_param6->setText(QApplication::translate("addcommondwidget", "\345\217\202\346\225\2606", nullptr));
        checkBox_enter->setText(QApplication::translate("addcommondwidget", "\346\234\253\345\260\276\346\267\273\345\212\240\345\233\236\350\275\246\347\254\246", nullptr));
        toolButton_ok->setText(QApplication::translate("addcommondwidget", "\347\241\256\345\256\232", nullptr));
        toolButton_cancel->setText(QApplication::translate("addcommondwidget", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addcommondwidget: public Ui_addcommondwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCOMMONDWIDGET_H
