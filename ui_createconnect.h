/********************************************************************************
** Form generated from reading UI file 'createconnect.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATECONNECT_H
#define UI_CREATECONNECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_createconnect
{
public:
    QPushButton *pushButton_close;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_name;
    QLineEdit *lineEdit_host;
    QLabel *label_port;
    QLineEdit *lineEdit_port;
    QLabel *label_host;
    QLineEdit *lineEdit_name;
    QPushButton *pushButton_connect;

    void setupUi(QWidget *createconnect)
    {
        if (createconnect->objectName().isEmpty())
            createconnect->setObjectName(QStringLiteral("createconnect"));
        createconnect->resize(341, 202);
        QFont font;
        font.setFamily(QStringLiteral("OPPOSans B"));
        font.setPointSize(10);
        createconnect->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/lib/wicon_46.png"), QSize(), QIcon::Normal, QIcon::Off);
        createconnect->setWindowIcon(icon);
        pushButton_close = new QPushButton(createconnect);
        pushButton_close->setObjectName(QStringLiteral("pushButton_close"));
        pushButton_close->setGeometry(QRect(200, 150, 81, 31));
        pushButton_close->setFont(font);
        gridLayoutWidget = new QWidget(createconnect);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(60, 20, 221, 101));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_name = new QLabel(gridLayoutWidget);
        label_name->setObjectName(QStringLiteral("label_name"));
        QFont font1;
        font1.setPointSize(10);
        label_name->setFont(font1);

        gridLayout->addWidget(label_name, 0, 0, 1, 1);

        lineEdit_host = new QLineEdit(gridLayoutWidget);
        lineEdit_host->setObjectName(QStringLiteral("lineEdit_host"));
        lineEdit_host->setMinimumSize(QSize(0, 30));
        lineEdit_host->setFont(font);

        gridLayout->addWidget(lineEdit_host, 1, 1, 1, 1);

        label_port = new QLabel(gridLayoutWidget);
        label_port->setObjectName(QStringLiteral("label_port"));
        label_port->setFont(font);

        gridLayout->addWidget(label_port, 2, 0, 1, 1);

        lineEdit_port = new QLineEdit(gridLayoutWidget);
        lineEdit_port->setObjectName(QStringLiteral("lineEdit_port"));
        lineEdit_port->setMinimumSize(QSize(0, 30));
        lineEdit_port->setFont(font);

        gridLayout->addWidget(lineEdit_port, 2, 1, 1, 1);

        label_host = new QLabel(gridLayoutWidget);
        label_host->setObjectName(QStringLiteral("label_host"));
        label_host->setFont(font);

        gridLayout->addWidget(label_host, 1, 0, 1, 1);

        lineEdit_name = new QLineEdit(gridLayoutWidget);
        lineEdit_name->setObjectName(QStringLiteral("lineEdit_name"));
        lineEdit_name->setMinimumSize(QSize(0, 30));
        QFont font2;
        font2.setFamily(QStringLiteral("OPPOSans B"));
        lineEdit_name->setFont(font2);

        gridLayout->addWidget(lineEdit_name, 0, 1, 1, 1);

        pushButton_connect = new QPushButton(createconnect);
        pushButton_connect->setObjectName(QStringLiteral("pushButton_connect"));
        pushButton_connect->setGeometry(QRect(100, 150, 81, 31));
        pushButton_connect->setFont(font);

        retranslateUi(createconnect);

        QMetaObject::connectSlotsByName(createconnect);
    } // setupUi

    void retranslateUi(QWidget *createconnect)
    {
        createconnect->setWindowTitle(QApplication::translate("createconnect", "\346\226\260\345\273\272\350\277\236\346\216\245", nullptr));
        pushButton_close->setText(QApplication::translate("createconnect", "\345\217\226\346\266\210", nullptr));
        label_name->setText(QApplication::translate("createconnect", "\345\220\215\347\247\260\357\274\232", nullptr));
        lineEdit_host->setText(QApplication::translate("createconnect", "172.16.8.153", nullptr));
        label_port->setText(QApplication::translate("createconnect", "\347\253\257\345\217\243\357\274\232", nullptr));
        lineEdit_port->setText(QApplication::translate("createconnect", "11100", nullptr));
        label_host->setText(QApplication::translate("createconnect", "\344\270\273\346\234\272\357\274\232", nullptr));
        lineEdit_name->setText(QApplication::translate("createconnect", "172.16.8.153", nullptr));
        pushButton_connect->setText(QApplication::translate("createconnect", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class createconnect: public Ui_createconnect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATECONNECT_H
