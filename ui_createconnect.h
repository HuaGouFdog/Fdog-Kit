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
#include <QtWidgets/QHBoxLayout>
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
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_ssh_connect;
    QPushButton *pushButton_ssh_close;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLabel *label_ssh_name;
    QLabel *label_ssh_user;
    QLabel *label_ssh_func;
    QLabel *label_ssh_port;
    QLineEdit *lineEdit_ssh_name;
    QLabel *label_ssh_host;
    QLineEdit *lineEdit_ssh_host;
    QLineEdit *lineEdit_ssh_port;
    QComboBox *comboBox_ssh_func;
    QLabel *label_ssh_password;
    QLineEdit *lineEdit_ssh_user;
    QLineEdit *lineEdit_ssh_password;
    QWidget *page_2;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_zk_name;
    QLineEdit *lineEdit_zk_host;
    QLabel *label_zk_port;
    QLabel *label_zk_host;
    QLineEdit *lineEdit_zk_name;
    QLineEdit *lineEdit_zk_port;
    QWidget *horizontalWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_zk_connect;
    QPushButton *pushButton_zk_close;

    void setupUi(QWidget *createconnect)
    {
        if (createconnect->objectName().isEmpty())
            createconnect->setObjectName(QStringLiteral("createconnect"));
        createconnect->resize(352, 241);
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
        widget = new QWidget(page);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(200, 190, 120, 40));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(1, 1, 1, 1);
        pushButton_ssh_connect = new QPushButton(widget);
        pushButton_ssh_connect->setObjectName(QStringLiteral("pushButton_ssh_connect"));
        QFont font1;
        font1.setFamily(QStringLiteral("OPPOSans B"));
        font1.setPointSize(10);
        font1.setStyleStrategy(QFont::PreferAntialias);
        pushButton_ssh_connect->setFont(font1);

        horizontalLayout_2->addWidget(pushButton_ssh_connect);

        pushButton_ssh_close = new QPushButton(widget);
        pushButton_ssh_close->setObjectName(QStringLiteral("pushButton_ssh_close"));
        pushButton_ssh_close->setFont(font1);

        horizontalLayout_2->addWidget(pushButton_ssh_close);

        gridLayoutWidget_2 = new QWidget(page);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(20, 10, 281, 171));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_ssh_name = new QLabel(gridLayoutWidget_2);
        label_ssh_name->setObjectName(QStringLiteral("label_ssh_name"));
        label_ssh_name->setFont(font1);

        gridLayout_2->addWidget(label_ssh_name, 0, 0, 1, 1);

        label_ssh_user = new QLabel(gridLayoutWidget_2);
        label_ssh_user->setObjectName(QStringLiteral("label_ssh_user"));
        label_ssh_user->setFont(font1);

        gridLayout_2->addWidget(label_ssh_user, 3, 0, 1, 1);

        label_ssh_func = new QLabel(gridLayoutWidget_2);
        label_ssh_func->setObjectName(QStringLiteral("label_ssh_func"));
        label_ssh_func->setFont(font1);

        gridLayout_2->addWidget(label_ssh_func, 2, 0, 1, 1);

        label_ssh_port = new QLabel(gridLayoutWidget_2);
        label_ssh_port->setObjectName(QStringLiteral("label_ssh_port"));
        label_ssh_port->setFont(font1);

        gridLayout_2->addWidget(label_ssh_port, 1, 2, 1, 1);

        lineEdit_ssh_name = new QLineEdit(gridLayoutWidget_2);
        lineEdit_ssh_name->setObjectName(QStringLiteral("lineEdit_ssh_name"));
        lineEdit_ssh_name->setFont(font1);

        gridLayout_2->addWidget(lineEdit_ssh_name, 0, 1, 1, 1);

        label_ssh_host = new QLabel(gridLayoutWidget_2);
        label_ssh_host->setObjectName(QStringLiteral("label_ssh_host"));
        label_ssh_host->setFont(font1);

        gridLayout_2->addWidget(label_ssh_host, 1, 0, 1, 1);

        lineEdit_ssh_host = new QLineEdit(gridLayoutWidget_2);
        lineEdit_ssh_host->setObjectName(QStringLiteral("lineEdit_ssh_host"));
        lineEdit_ssh_host->setFont(font1);

        gridLayout_2->addWidget(lineEdit_ssh_host, 1, 1, 1, 1);

        lineEdit_ssh_port = new QLineEdit(gridLayoutWidget_2);
        lineEdit_ssh_port->setObjectName(QStringLiteral("lineEdit_ssh_port"));
        lineEdit_ssh_port->setFont(font1);

        gridLayout_2->addWidget(lineEdit_ssh_port, 1, 3, 1, 1);

        comboBox_ssh_func = new QComboBox(gridLayoutWidget_2);
        comboBox_ssh_func->addItem(QString());
        comboBox_ssh_func->addItem(QString());
        comboBox_ssh_func->setObjectName(QStringLiteral("comboBox_ssh_func"));
        comboBox_ssh_func->setFont(font1);

        gridLayout_2->addWidget(comboBox_ssh_func, 2, 1, 1, 2);

        label_ssh_password = new QLabel(gridLayoutWidget_2);
        label_ssh_password->setObjectName(QStringLiteral("label_ssh_password"));
        label_ssh_password->setFont(font1);

        gridLayout_2->addWidget(label_ssh_password, 4, 0, 1, 1);

        lineEdit_ssh_user = new QLineEdit(gridLayoutWidget_2);
        lineEdit_ssh_user->setObjectName(QStringLiteral("lineEdit_ssh_user"));
        lineEdit_ssh_user->setFont(font1);

        gridLayout_2->addWidget(lineEdit_ssh_user, 3, 1, 1, 2);

        lineEdit_ssh_password = new QLineEdit(gridLayoutWidget_2);
        lineEdit_ssh_password->setObjectName(QStringLiteral("lineEdit_ssh_password"));
        lineEdit_ssh_password->setFont(font1);

        gridLayout_2->addWidget(lineEdit_ssh_password, 4, 1, 1, 2);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        gridLayoutWidget = new QWidget(page_2);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(50, 30, 221, 104));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_zk_name = new QLabel(gridLayoutWidget);
        label_zk_name->setObjectName(QStringLiteral("label_zk_name"));
        label_zk_name->setFont(font);

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

        horizontalWidget = new QWidget(page_2);
        horizontalWidget->setObjectName(QStringLiteral("horizontalWidget"));
        horizontalWidget->setGeometry(QRect(200, 190, 120, 40));
        horizontalLayout = new QHBoxLayout(horizontalWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_zk_connect = new QPushButton(horizontalWidget);
        pushButton_zk_connect->setObjectName(QStringLiteral("pushButton_zk_connect"));
        pushButton_zk_connect->setFont(font);

        horizontalLayout->addWidget(pushButton_zk_connect);

        pushButton_zk_close = new QPushButton(horizontalWidget);
        pushButton_zk_close->setObjectName(QStringLiteral("pushButton_zk_close"));
        pushButton_zk_close->setFont(font);

        horizontalLayout->addWidget(pushButton_zk_close);

        stackedWidget->addWidget(page_2);

        verticalLayout->addWidget(stackedWidget);


        retranslateUi(createconnect);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(createconnect);
    } // setupUi

    void retranslateUi(QWidget *createconnect)
    {
        createconnect->setWindowTitle(QApplication::translate("createconnect", "\346\226\260\345\273\272\350\277\236\346\216\245", nullptr));
        pushButton_ssh_connect->setText(QApplication::translate("createconnect", "\350\277\236\346\216\245", nullptr));
        pushButton_ssh_close->setText(QApplication::translate("createconnect", "\345\217\226\346\266\210", nullptr));
        label_ssh_name->setText(QApplication::translate("createconnect", "\345\220\215\347\247\260\357\274\232", nullptr));
        label_ssh_user->setText(QApplication::translate("createconnect", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        label_ssh_func->setText(QApplication::translate("createconnect", "\346\226\271\346\263\225\357\274\232", nullptr));
        label_ssh_port->setText(QApplication::translate("createconnect", "\347\253\257\345\217\243\357\274\232", nullptr));
        lineEdit_ssh_name->setText(QApplication::translate("createconnect", "1111", nullptr));
        label_ssh_host->setText(QApplication::translate("createconnect", "\344\270\273\346\234\272\357\274\232", nullptr));
        lineEdit_ssh_host->setText(QApplication::translate("createconnect", "172.16.8.154", nullptr));
        lineEdit_ssh_port->setText(QApplication::translate("createconnect", "22", nullptr));
        comboBox_ssh_func->setItemText(0, QApplication::translate("createconnect", "\345\257\206\347\240\201", nullptr));
        comboBox_ssh_func->setItemText(1, QApplication::translate("createconnect", "\345\205\254\351\222\245", nullptr));

        label_ssh_password->setText(QApplication::translate("createconnect", "\345\257\206\347\240\201\357\274\232", nullptr));
        lineEdit_ssh_user->setText(QApplication::translate("createconnect", "root", nullptr));
        lineEdit_ssh_password->setText(QApplication::translate("createconnect", "Linkdood@123456", nullptr));
        label_zk_name->setText(QApplication::translate("createconnect", "\345\220\215\347\247\260\357\274\232", nullptr));
        lineEdit_zk_host->setText(QApplication::translate("createconnect", "172.16.8.153", nullptr));
        label_zk_port->setText(QApplication::translate("createconnect", "\347\253\257\345\217\243\357\274\232", nullptr));
        label_zk_host->setText(QApplication::translate("createconnect", "\344\270\273\346\234\272\357\274\232", nullptr));
        lineEdit_zk_name->setText(QApplication::translate("createconnect", "172.16.8.153", nullptr));
        lineEdit_zk_port->setText(QApplication::translate("createconnect", "11100", nullptr));
        pushButton_zk_connect->setText(QApplication::translate("createconnect", "\347\241\256\345\256\232", nullptr));
        pushButton_zk_close->setText(QApplication::translate("createconnect", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class createconnect: public Ui_createconnect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATECONNECT_H
