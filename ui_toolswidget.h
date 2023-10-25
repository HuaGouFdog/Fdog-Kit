/********************************************************************************
** Form generated from reading UI file 'toolswidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOOLSWIDGET_H
#define UI_TOOLSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_toolswidget
{
public:
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QHBoxLayout *horizontalLayout_2;
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;
    QWidget *page_2;
    QHBoxLayout *horizontalLayout_3;
    QTextEdit *textEdit_3;
    QTextEdit *textEdit_4;
    QWidget *page_3;
    QHBoxLayout *horizontalLayout;
    QTextEdit *textEdit_5;
    QTextEdit *textEdit_6;

    void setupUi(QWidget *toolswidget)
    {
        if (toolswidget->objectName().isEmpty())
            toolswidget->setObjectName(QStringLiteral("toolswidget"));
        toolswidget->resize(974, 631);
        toolswidget->setStyleSheet(QLatin1String("background-color: rgb(30, 45, 54);\n"
"color: rgb(255, 255, 255);"));
        verticalLayout = new QVBoxLayout(toolswidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        stackedWidget = new QStackedWidget(toolswidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        horizontalLayout_2 = new QHBoxLayout(page);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        textEdit = new QTextEdit(page);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        horizontalLayout_2->addWidget(textEdit);

        textEdit_2 = new QTextEdit(page);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));

        horizontalLayout_2->addWidget(textEdit_2);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        horizontalLayout_3 = new QHBoxLayout(page_2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        textEdit_3 = new QTextEdit(page_2);
        textEdit_3->setObjectName(QStringLiteral("textEdit_3"));

        horizontalLayout_3->addWidget(textEdit_3);

        textEdit_4 = new QTextEdit(page_2);
        textEdit_4->setObjectName(QStringLiteral("textEdit_4"));

        horizontalLayout_3->addWidget(textEdit_4);

        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        horizontalLayout = new QHBoxLayout(page_3);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        textEdit_5 = new QTextEdit(page_3);
        textEdit_5->setObjectName(QStringLiteral("textEdit_5"));

        horizontalLayout->addWidget(textEdit_5);

        textEdit_6 = new QTextEdit(page_3);
        textEdit_6->setObjectName(QStringLiteral("textEdit_6"));

        horizontalLayout->addWidget(textEdit_6);

        stackedWidget->addWidget(page_3);

        verticalLayout->addWidget(stackedWidget);


        retranslateUi(toolswidget);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(toolswidget);
    } // setupUi

    void retranslateUi(QWidget *toolswidget)
    {
        toolswidget->setWindowTitle(QApplication::translate("toolswidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class toolswidget: public Ui_toolswidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLSWIDGET_H
