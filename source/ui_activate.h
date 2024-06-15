/********************************************************************************
** Form generated from reading UI file 'activate.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACTIVATE_H
#define UI_ACTIVATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Activate
{
public:
    QVBoxLayout *verticalLayout;
    QProgressBar *progressBar;

    void setupUi(QWidget *Activate)
    {
        if (Activate->objectName().isEmpty())
            Activate->setObjectName(QStringLiteral("Activate"));
        Activate->resize(309, 154);
        Activate->setStyleSheet(QLatin1String("#Activate_widget{\n"
"background-color:rgb(56,58,89);\n"
"color:rgb(220,220,220);\n"
"border-radius:10px;\n"
"}\n"
"QProgressBar{\n"
"background-color:rgb(98,114,164);\n"
"color:rgb(200,200,200);\n"
"border-style:none;\n"
"border-radius:10px;\n"
"text-align:center;\n"
"}\n"
"QProgressBar::chunk{\n"
"border-radius:10px;\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0.511364, x2:1, y2:0.523, stop:0 rgba(254, 121, 199, 255), stop:1 rgba(170, 85, 255, 255));\n"
"}"));
        verticalLayout = new QVBoxLayout(Activate);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        progressBar = new QProgressBar(Activate);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setMinimumSize(QSize(0, 30));
        progressBar->setMaximumSize(QSize(16777215, 30));
        QFont font;
        font.setFamily(QStringLiteral("OPPOSans B"));
        font.setPointSize(10);
        progressBar->setFont(font);
        progressBar->setValue(24);

        verticalLayout->addWidget(progressBar);


        retranslateUi(Activate);

        QMetaObject::connectSlotsByName(Activate);
    } // setupUi

    void retranslateUi(QWidget *Activate)
    {
        Activate->setWindowTitle(QApplication::translate("Activate", "Form", nullptr));
        progressBar->setFormat(QApplication::translate("Activate", "Fdog-Kit \345\212\240\350\275\275\344\270\255...        %p%", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Activate: public Ui_Activate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACTIVATE_H
