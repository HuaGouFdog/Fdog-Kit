/********************************************************************************
** Form generated from reading UI file 'qss.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QSS_H
#define UI_QSS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_qss
{
public:

    void setupUi(QWidget *qss)
    {
        if (qss->objectName().isEmpty())
            qss->setObjectName(QStringLiteral("qss"));
        qss->resize(823, 558);

        retranslateUi(qss);

        QMetaObject::connectSlotsByName(qss);
    } // setupUi

    void retranslateUi(QWidget *qss)
    {
        qss->setWindowTitle(QApplication::translate("qss", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class qss: public Ui_qss {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QSS_H
