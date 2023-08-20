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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_createconnect
{
public:
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *label_ssh_password;
    QComboBox *comboBox_ssh_func;
    QLabel *label_ssh_name;
    QPushButton *pushButton_ssh_connect;
    QLineEdit *lineEdit_ssh_name;
    QLabel *label_ssh_user;
    QLineEdit *lineEdit_ssh_port;
    QPushButton *pushButton_ssh_close;
    QLabel *label_ssh_port;
    QLineEdit *lineEdit_ssh_host;
    QLineEdit *lineEdit_ssh_user;
    QLineEdit *lineEdit_ssh_password;
    QLabel *label_ssh_func;
    QLabel *label_ssh_host;
    QWidget *page_2;
    QPushButton *pushButton_zk_close;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_zk_name;
    QLineEdit *lineEdit_zk_host;
    QLabel *label_zk_port;
    QLabel *label_zk_host;
    QLineEdit *lineEdit_zk_name;
    QLineEdit *lineEdit_zk_port;
    QPushButton *pushButton_zk_connect;

    void setupUi(QWidget *createconnect)
    {
        if (createconnect->objectName().isEmpty())
            createconnect->setObjectName(QStringLiteral("createconnect"));
        createconnect->resize(391, 266);
        QFont font;
        font.setFamily(QStringLiteral("OPPOSans B"));
        font.setPointSize(10);
        createconnect->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/lib/wicon_46.png"), QSize(), QIcon::Normal, QIcon::Off);
        createconnect->setWindowIcon(icon);
        createconnect->setStyleSheet(QLatin1String("background-color: rgb(67, 77, 88);\n"
"color: rgb(255, 255, 255);"));
        verticalLayout = new QVBoxLayout(createconnect);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        stackedWidget = new QStackedWidget(createconnect);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        label_ssh_password = new QLabel(page);
        label_ssh_password->setObjectName(QStringLiteral("label_ssh_password"));
        label_ssh_password->setGeometry(QRect(30, 180, 51, 20));
        comboBox_ssh_func = new QComboBox(page);
        comboBox_ssh_func->addItem(QString());
        comboBox_ssh_func->addItem(QString());
        comboBox_ssh_func->setObjectName(QStringLiteral("comboBox_ssh_func"));
        comboBox_ssh_func->setGeometry(QRect(90, 110, 161, 21));
        label_ssh_name = new QLabel(page);
        label_ssh_name->setObjectName(QStringLiteral("label_ssh_name"));
        label_ssh_name->setGeometry(QRect(30, 30, 54, 12));
        pushButton_ssh_connect = new QPushButton(page);
        pushButton_ssh_connect->setObjectName(QStringLiteral("pushButton_ssh_connect"));
        pushButton_ssh_connect->setGeometry(QRect(170, 210, 75, 23));
        lineEdit_ssh_name = new QLineEdit(page);
        lineEdit_ssh_name->setObjectName(QStringLiteral("lineEdit_ssh_name"));
        lineEdit_ssh_name->setGeometry(QRect(90, 30, 113, 20));
        label_ssh_user = new QLabel(page);
        label_ssh_user->setObjectName(QStringLiteral("label_ssh_user"));
        label_ssh_user->setGeometry(QRect(30, 150, 51, 20));
        lineEdit_ssh_port = new QLineEdit(page);
        lineEdit_ssh_port->setObjectName(QStringLiteral("lineEdit_ssh_port"));
        lineEdit_ssh_port->setGeometry(QRect(260, 60, 61, 20));
        pushButton_ssh_close = new QPushButton(page);
        pushButton_ssh_close->setObjectName(QStringLiteral("pushButton_ssh_close"));
        pushButton_ssh_close->setGeometry(QRect(260, 210, 75, 23));
        label_ssh_port = new QLabel(page);
        label_ssh_port->setObjectName(QStringLiteral("label_ssh_port"));
        label_ssh_port->setGeometry(QRect(220, 60, 41, 20));
        lineEdit_ssh_host = new QLineEdit(page);
        lineEdit_ssh_host->setObjectName(QStringLiteral("lineEdit_ssh_host"));
        lineEdit_ssh_host->setGeometry(QRect(90, 60, 113, 20));
        lineEdit_ssh_user = new QLineEdit(page);
        lineEdit_ssh_user->setObjectName(QStringLiteral("lineEdit_ssh_user"));
        lineEdit_ssh_user->setGeometry(QRect(90, 150, 161, 21));
        lineEdit_ssh_password = new QLineEdit(page);
        lineEdit_ssh_password->setObjectName(QStringLiteral("lineEdit_ssh_password"));
        lineEdit_ssh_password->setGeometry(QRect(90, 180, 171, 21));
        label_ssh_func = new QLabel(page);
        label_ssh_func->setObjectName(QStringLiteral("label_ssh_func"));
        label_ssh_func->setGeometry(QRect(30, 110, 51, 20));
        label_ssh_host = new QLabel(page);
        label_ssh_host->setObjectName(QStringLiteral("label_ssh_host"));
        label_ssh_host->setGeometry(QRect(30, 60, 41, 16));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        pushButton_zk_close = new QPushButton(page_2);
        pushButton_zk_close->setObjectName(QStringLiteral("pushButton_zk_close"));
        pushButton_zk_close->setGeometry(QRect(180, 150, 81, 31));
        pushButton_zk_close->setFont(font);
        gridLayoutWidget = new QWidget(page_2);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(40, 20, 221, 104));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_zk_name = new QLabel(gridLayoutWidget);
        label_zk_name->setObjectName(QStringLiteral("label_zk_name"));
        QFont font1;
        font1.setPointSize(10);
        label_zk_name->setFont(font1);

        gridLayout->addWidget(label_zk_name, 0, 0, 1, 1);

        lineEdit_zk_host = new QLineEdit(gridLayoutWidget);
        lineEdit_zk_host->setObjectName(QStringLiteral("lineEdit_zk_host"));
        lineEdit_zk_host->setMinimumSize(QSize(0, 30));
        lineEdit_zk_host->setFont(font);

        gridLayout->addWidget(lineEdit_zk_host, 1, 1, 1, 1);

        label_zk_port = new QLabel(gridLayoutWidget);
        label_zk_port->setObjectName(QStringLiteral("label_zk_port"));
        label_zk_port->setFont(font);

        gridLayout->addWidget(label_zk_port, 2, 0, 1, 1);

        label_zk_host = new QLabel(gridLayoutWidget);
        label_zk_host->setObjectName(QStringLiteral("label_zk_host"));
        label_zk_host->setFont(font);

        gridLayout->addWidget(label_zk_host, 1, 0, 1, 1);

        lineEdit_zk_name = new QLineEdit(gridLayoutWidget);
        lineEdit_zk_name->setObjectName(QStringLiteral("lineEdit_zk_name"));
        lineEdit_zk_name->setMinimumSize(QSize(0, 30));
        QFont font2;
        font2.setFamily(QStringLiteral("OPPOSans B"));
        lineEdit_zk_name->setFont(font2);

        gridLayout->addWidget(lineEdit_zk_name, 0, 1, 1, 1);

        lineEdit_zk_port = new QLineEdit(gridLayoutWidget);
        lineEdit_zk_port->setObjectName(QStringLiteral("lineEdit_zk_port"));
        lineEdit_zk_port->setMinimumSize(QSize(0, 30));
        lineEdit_zk_port->setFont(font);

        gridLayout->addWidget(lineEdit_zk_port, 2, 1, 1, 1);

        pushButton_zk_connect = new QPushButton(page_2);
        pushButton_zk_connect->setObjectName(QStringLiteral("pushButton_zk_connect"));
        pushButton_zk_connect->setGeometry(QRect(80, 150, 81, 31));
        pushButton_zk_connect->setFont(font);
        stackedWidget->addWidget(page_2);

        verticalLayout->addWidget(stackedWidget);


        retranslateUi(createconnect);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(createconnect);
    } // setupUi

    void retranslateUi(QWidget *createconnect)
    {
        createconnect->setWindowTitle(QApplication::translate("createconnect", "\346\226\260\345\273\272\350\277\236\346\216\245", nullptr));
        label_ssh_password->setText(QApplication::translate("createconnect", "\345\257\206\347\240\201\357\274\232", nullptr));
        comboBox_ssh_func->setItemText(0, QApplication::translate("createconnect", "\345\257\206\347\240\201", nullptr));
        comboBox_ssh_func->setItemText(1, QApplication::translate("createconnect", "\345\205\254\351\222\245", nullptr));

        label_ssh_name->setText(QApplication::translate("createconnect", "\345\220\215\347\247\260\357\274\232", nullptr));
        pushButton_ssh_connect->setText(QApplication::translate("createconnect", "\350\277\236\346\216\245", nullptr));
        lineEdit_ssh_name->setText(QApplication::translate("createconnect", "1111", nullptr));
        label_ssh_user->setText(QApplication::translate("createconnect", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        pushButton_ssh_close->setText(QApplication::translate("createconnect", "\345\217\226\346\266\210", nullptr));
        label_ssh_port->setText(QApplication::translate("createconnect", "\347\253\257\345\217\243\357\274\232", nullptr));
        lineEdit_ssh_host->setText(QApplication::translate("createconnect", "172.16.8.154", nullptr));
        lineEdit_ssh_user->setText(QApplication::translate("createconnect", "root", nullptr));
        lineEdit_ssh_password->setText(QApplication::translate("createconnect", "Linkdood@123456", nullptr));
        label_ssh_func->setText(QApplication::translate("createconnect", "\346\226\271\346\263\225\357\274\232", nullptr));
        label_ssh_host->setText(QApplication::translate("createconnect", "\344\270\273\346\234\272\357\274\232", nullptr));
        pushButton_zk_close->setText(QApplication::translate("createconnect", "\345\217\226\346\266\210", nullptr));
        label_zk_name->setText(QApplication::translate("createconnect", "\345\220\215\347\247\260\357\274\232", nullptr));
        lineEdit_zk_host->setText(QApplication::translate("createconnect", "172.16.8.153", nullptr));
        label_zk_port->setText(QApplication::translate("createconnect", "\347\253\257\345\217\243\357\274\232", nullptr));
        label_zk_host->setText(QApplication::translate("createconnect", "\344\270\273\346\234\272\357\274\232", nullptr));
        lineEdit_zk_name->setText(QApplication::translate("createconnect", "172.16.8.153", nullptr));
        lineEdit_zk_port->setText(QApplication::translate("createconnect", "11100", nullptr));
        pushButton_zk_connect->setText(QApplication::translate("createconnect", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class createconnect: public Ui_createconnect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATECONNECT_H
