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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_createconnect
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *toolButton_ssh_connect;
    QToolButton *toolButton_ssh_close;
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
    QToolButton *toolButton_zk_connect;
    QToolButton *toolButton_zk_close;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QToolButton *toolButton_2;
    QToolButton *toolButton;
    QToolButton *toolButton_3;
    QSpacerItem *horizontalSpacer_3;
    QWidget *horizontalWidget_2;
    QHBoxLayout *horizontalLayout_6;
    QWidget *verticalWidget_3;
    QVBoxLayout *verticalLayout_3;
    QWidget *verticalWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_zk_port_2;
    QLineEdit *lineEdit_zk_port_2;
    QWidget *verticalWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_zk_port_3;
    QLineEdit *lineEdit_zk_port_3;
    QWidget *verticalWidget_5;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_zk_port_6;
    QLineEdit *lineEdit_zk_port_9;
    QWidget *horizontalWidget1;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_zk_port_4;
    QLineEdit *lineEdit_zk_port_4;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QWidget *verticalWidget_4;
    QVBoxLayout *verticalLayout_4;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLineEdit *lineEdit_zk_host_2;
    QLabel *label_zk_host_2;
    QLabel *label_zk_port_5;
    QLineEdit *lineEdit_zk_port_5;
    QLabel *label_zk_host_3;
    QLineEdit *lineEdit_zk_port_6;
    QTabWidget *tabWidget_2;
    QWidget *tab_5;
    QLineEdit *lineEdit_zk_port_7;
    QLabel *label_zk_host_4;
    QCheckBox *checkBox;
    QToolButton *toolButton_5;
    QWidget *tab_6;
    QLabel *label_zk_host_5;
    QLineEdit *lineEdit_zk_port_8;
    QToolButton *toolButton_4;
    QCheckBox *checkBox_2;
    QWidget *tab_7;
    QWidget *tab_2;
    QWidget *tab_3;

    void setupUi(QWidget *createconnect)
    {
        if (createconnect->objectName().isEmpty())
            createconnect->setObjectName(QStringLiteral("createconnect"));
        createconnect->resize(673, 475);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(createconnect->sizePolicy().hasHeightForWidth());
        createconnect->setSizePolicy(sizePolicy);
        createconnect->setMinimumSize(QSize(673, 475));
        createconnect->setMaximumSize(QSize(673, 475));
        QFont font;
        font.setFamily(QStringLiteral("OPPOSans B"));
        font.setPointSize(10);
        createconnect->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/lib/wicon_46.png"), QSize(), QIcon::Normal, QIcon::Off);
        createconnect->setWindowIcon(icon);
        createconnect->setStyleSheet(QLatin1String("background-color: rgb(30, 45, 54);\n"
"color: rgb(255, 255, 255);"));
        stackedWidget = new QStackedWidget(createconnect);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(50, 530, 331, 221));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        widget = new QWidget(page);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(200, 190, 120, 40));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(1, 1, 1, 1);
        toolButton_ssh_connect = new QToolButton(widget);
        toolButton_ssh_connect->setObjectName(QStringLiteral("toolButton_ssh_connect"));
        QFont font1;
        font1.setFamily(QStringLiteral("OPPOSans B"));
        font1.setPointSize(10);
        font1.setStyleStrategy(QFont::PreferAntialias);
        toolButton_ssh_connect->setFont(font1);
        toolButton_ssh_connect->setStyleSheet(QLatin1String("QToolButton {\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"	border: none;\n"
"}\n"
"\n"
"QToolButton::menu-indicator { \n"
"	image: None;\n"
"}\n"
"\n"
" \n"
"QToolButton:hover {\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"	border: none;\n"
"}"));

        horizontalLayout_2->addWidget(toolButton_ssh_connect);

        toolButton_ssh_close = new QToolButton(widget);
        toolButton_ssh_close->setObjectName(QStringLiteral("toolButton_ssh_close"));
        toolButton_ssh_close->setFont(font1);
        toolButton_ssh_close->setStyleSheet(QLatin1String("QToolButton {\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"	border: none;\n"
"}\n"
"\n"
"QToolButton::menu-indicator { \n"
"	image: None;\n"
"}\n"
"\n"
" \n"
"QToolButton:hover {\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"	border: none;\n"
"}"));

        horizontalLayout_2->addWidget(toolButton_ssh_close);

        gridLayoutWidget_2 = new QWidget(page);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(10, 0, 311, 201));
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
        lineEdit_ssh_name->setStyleSheet(QLatin1String("border: 1px solid rgba(255, 255, 255, 150);\n"
"border-radius: 5px;"));

        gridLayout_2->addWidget(lineEdit_ssh_name, 0, 1, 1, 1);

        label_ssh_host = new QLabel(gridLayoutWidget_2);
        label_ssh_host->setObjectName(QStringLiteral("label_ssh_host"));
        label_ssh_host->setFont(font1);

        gridLayout_2->addWidget(label_ssh_host, 1, 0, 1, 1);

        lineEdit_ssh_host = new QLineEdit(gridLayoutWidget_2);
        lineEdit_ssh_host->setObjectName(QStringLiteral("lineEdit_ssh_host"));
        lineEdit_ssh_host->setFont(font1);
        lineEdit_ssh_host->setStyleSheet(QLatin1String("border: 1px solid rgba(255, 255, 255, 150);\n"
"border-radius: 5px;"));

        gridLayout_2->addWidget(lineEdit_ssh_host, 1, 1, 1, 1);

        lineEdit_ssh_port = new QLineEdit(gridLayoutWidget_2);
        lineEdit_ssh_port->setObjectName(QStringLiteral("lineEdit_ssh_port"));
        lineEdit_ssh_port->setFont(font1);
        lineEdit_ssh_port->setStyleSheet(QLatin1String("border: 1px solid rgba(255, 255, 255, 150);\n"
"border-radius: 5px;"));

        gridLayout_2->addWidget(lineEdit_ssh_port, 1, 3, 1, 1);

        comboBox_ssh_func = new QComboBox(gridLayoutWidget_2);
        comboBox_ssh_func->addItem(QString());
        comboBox_ssh_func->addItem(QString());
        comboBox_ssh_func->setObjectName(QStringLiteral("comboBox_ssh_func"));
        comboBox_ssh_func->setFont(font1);
        comboBox_ssh_func->setStyleSheet(QLatin1String("border: 1px solid rgba(255, 255, 255, 150);\n"
"border-radius: 5px;"));

        gridLayout_2->addWidget(comboBox_ssh_func, 2, 1, 1, 2);

        label_ssh_password = new QLabel(gridLayoutWidget_2);
        label_ssh_password->setObjectName(QStringLiteral("label_ssh_password"));
        label_ssh_password->setFont(font1);

        gridLayout_2->addWidget(label_ssh_password, 4, 0, 1, 1);

        lineEdit_ssh_user = new QLineEdit(gridLayoutWidget_2);
        lineEdit_ssh_user->setObjectName(QStringLiteral("lineEdit_ssh_user"));
        lineEdit_ssh_user->setFont(font1);
        lineEdit_ssh_user->setStyleSheet(QLatin1String("border: 1px solid rgba(255, 255, 255, 150);\n"
"border-radius: 5px;"));

        gridLayout_2->addWidget(lineEdit_ssh_user, 3, 1, 1, 2);

        lineEdit_ssh_password = new QLineEdit(gridLayoutWidget_2);
        lineEdit_ssh_password->setObjectName(QStringLiteral("lineEdit_ssh_password"));
        lineEdit_ssh_password->setFont(font1);
        lineEdit_ssh_password->setStyleSheet(QLatin1String("border: 1px solid rgba(255, 255, 255, 150);\n"
"border-radius: 5px;"));

        gridLayout_2->addWidget(lineEdit_ssh_password, 4, 1, 1, 2);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        gridLayoutWidget = new QWidget(page_2);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(20, 10, 281, 171));
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
        lineEdit_zk_host->setStyleSheet(QLatin1String("border: 1px solid rgba(255, 255, 255, 150);\n"
"border-radius: 5px;"));

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
        lineEdit_zk_name->setStyleSheet(QLatin1String("border: 1px solid rgba(255, 255, 255, 150);\n"
"border-radius: 5px;"));

        gridLayout->addWidget(lineEdit_zk_name, 0, 1, 1, 1);

        lineEdit_zk_port = new QLineEdit(gridLayoutWidget);
        lineEdit_zk_port->setObjectName(QStringLiteral("lineEdit_zk_port"));
        lineEdit_zk_port->setMinimumSize(QSize(0, 30));
        lineEdit_zk_port->setFont(font);
        lineEdit_zk_port->setStyleSheet(QLatin1String("border: 1px solid rgba(255, 255, 255, 150);\n"
"border-radius: 5px;"));

        gridLayout->addWidget(lineEdit_zk_port, 2, 1, 1, 1);

        horizontalWidget = new QWidget(page_2);
        horizontalWidget->setObjectName(QStringLiteral("horizontalWidget"));
        horizontalWidget->setGeometry(QRect(200, 190, 120, 40));
        horizontalLayout = new QHBoxLayout(horizontalWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        toolButton_zk_connect = new QToolButton(horizontalWidget);
        toolButton_zk_connect->setObjectName(QStringLiteral("toolButton_zk_connect"));
        toolButton_zk_connect->setFont(font);
        toolButton_zk_connect->setStyleSheet(QLatin1String("QToolButton {\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"	border: none;\n"
"}\n"
"\n"
"QToolButton::menu-indicator { \n"
"	image: None;\n"
"}\n"
"\n"
" \n"
"QToolButton:hover {\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"	border: none;\n"
"}"));

        horizontalLayout->addWidget(toolButton_zk_connect);

        toolButton_zk_close = new QToolButton(horizontalWidget);
        toolButton_zk_close->setObjectName(QStringLiteral("toolButton_zk_close"));
        toolButton_zk_close->setFont(font);
        toolButton_zk_close->setStyleSheet(QLatin1String("QToolButton {\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"	border: none;\n"
"}\n"
"\n"
"QToolButton::menu-indicator { \n"
"	image: None;\n"
"}\n"
"\n"
" \n"
"QToolButton:hover {\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"	border: none;\n"
"}"));

        horizontalLayout->addWidget(toolButton_zk_close);

        stackedWidget->addWidget(page_2);
        widget_2 = new QWidget(createconnect);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(0, 390, 691, 81));
        widget_2->setStyleSheet(QLatin1String("background-color: rgb(30, 45, 54);\n"
"color: rgb(255, 255, 255);"));
        horizontalLayout_3 = new QHBoxLayout(widget_2);
        horizontalLayout_3->setSpacing(10);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(9, 20, 9, 3);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        toolButton_2 = new QToolButton(widget_2);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(toolButton_2->sizePolicy().hasHeightForWidth());
        toolButton_2->setSizePolicy(sizePolicy1);
        toolButton_2->setMinimumSize(QSize(60, 30));
        toolButton_2->setMaximumSize(QSize(60, 30));
        toolButton_2->setFont(font1);
        toolButton_2->setStyleSheet(QLatin1String("QToolButton {\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(0, 214, 103);\n"
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
"	background-color: rgb(0, 214, 103);\n"
"}"));

        horizontalLayout_3->addWidget(toolButton_2);

        toolButton = new QToolButton(widget_2);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        sizePolicy1.setHeightForWidth(toolButton->sizePolicy().hasHeightForWidth());
        toolButton->setSizePolicy(sizePolicy1);
        toolButton->setMinimumSize(QSize(60, 30));
        toolButton->setMaximumSize(QSize(60, 30));
        QFont font3;
        font3.setFamily(QStringLiteral("OPPOSans B"));
        font3.setPointSize(10);
        font3.setBold(false);
        font3.setWeight(50);
        font3.setStyleStrategy(QFont::PreferAntialias);
        toolButton->setFont(font3);
        toolButton->setStyleSheet(QLatin1String("QToolButton {\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(7, 143, 255);\n"
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
"	background-color: rgb(7, 143, 255);\n"
"}"));

        horizontalLayout_3->addWidget(toolButton);

        toolButton_3 = new QToolButton(widget_2);
        toolButton_3->setObjectName(QStringLiteral("toolButton_3"));
        sizePolicy1.setHeightForWidth(toolButton_3->sizePolicy().hasHeightForWidth());
        toolButton_3->setSizePolicy(sizePolicy1);
        toolButton_3->setMinimumSize(QSize(60, 30));
        toolButton_3->setMaximumSize(QSize(60, 30));
        toolButton_3->setFont(font1);
        toolButton_3->setStyleSheet(QLatin1String("QToolButton {\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(255, 95, 95);\n"
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
"	background-color: rgb(255, 95, 95);\n"
"}"));

        horizontalLayout_3->addWidget(toolButton_3);

        horizontalSpacer_3 = new QSpacerItem(30, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        horizontalWidget_2 = new QWidget(createconnect);
        horizontalWidget_2->setObjectName(QStringLiteral("horizontalWidget_2"));
        horizontalWidget_2->setGeometry(QRect(0, 0, 681, 391));
        horizontalLayout_6 = new QHBoxLayout(horizontalWidget_2);
        horizontalLayout_6->setSpacing(15);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(15, 20, 15, -1);
        verticalWidget_3 = new QWidget(horizontalWidget_2);
        verticalWidget_3->setObjectName(QStringLiteral("verticalWidget_3"));
        verticalWidget_3->setMinimumSize(QSize(190, 0));
        verticalWidget_3->setMaximumSize(QSize(190, 16777215));
        verticalLayout_3 = new QVBoxLayout(verticalWidget_3);
        verticalLayout_3->setSpacing(20);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(9, 3, 1, -1);
        verticalWidget = new QWidget(verticalWidget_3);
        verticalWidget->setObjectName(QStringLiteral("verticalWidget"));
        verticalWidget->setMinimumSize(QSize(180, 60));
        verticalWidget->setMaximumSize(QSize(180, 60));
        verticalWidget->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(verticalWidget);
        verticalLayout->setSpacing(5);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_zk_port_2 = new QLabel(verticalWidget);
        label_zk_port_2->setObjectName(QStringLiteral("label_zk_port_2"));
        label_zk_port_2->setMinimumSize(QSize(0, 20));
        label_zk_port_2->setMaximumSize(QSize(16777215, 20));
        label_zk_port_2->setFont(font);

        verticalLayout->addWidget(label_zk_port_2);

        lineEdit_zk_port_2 = new QLineEdit(verticalWidget);
        lineEdit_zk_port_2->setObjectName(QStringLiteral("lineEdit_zk_port_2"));
        lineEdit_zk_port_2->setMinimumSize(QSize(0, 30));
        lineEdit_zk_port_2->setMaximumSize(QSize(16777215, 30));
        lineEdit_zk_port_2->setFont(font);
        lineEdit_zk_port_2->setStyleSheet(QLatin1String("background-color: rgb(25, 25, 25, 155);\n"
"border: 1px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding-left:10px;\n"
"padding-right:10px;"));
        lineEdit_zk_port_2->setCursorPosition(6);

        verticalLayout->addWidget(lineEdit_zk_port_2);


        verticalLayout_3->addWidget(verticalWidget);

        verticalWidget_2 = new QWidget(verticalWidget_3);
        verticalWidget_2->setObjectName(QStringLiteral("verticalWidget_2"));
        verticalWidget_2->setMinimumSize(QSize(180, 60));
        verticalWidget_2->setMaximumSize(QSize(180, 60));
        verticalWidget_2->setStyleSheet(QStringLiteral(""));
        verticalLayout_2 = new QVBoxLayout(verticalWidget_2);
        verticalLayout_2->setSpacing(5);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_zk_port_3 = new QLabel(verticalWidget_2);
        label_zk_port_3->setObjectName(QStringLiteral("label_zk_port_3"));
        label_zk_port_3->setMinimumSize(QSize(0, 20));
        label_zk_port_3->setMaximumSize(QSize(16777215, 20));
        label_zk_port_3->setFont(font);

        verticalLayout_2->addWidget(label_zk_port_3);

        lineEdit_zk_port_3 = new QLineEdit(verticalWidget_2);
        lineEdit_zk_port_3->setObjectName(QStringLiteral("lineEdit_zk_port_3"));
        lineEdit_zk_port_3->setMinimumSize(QSize(0, 30));
        lineEdit_zk_port_3->setMaximumSize(QSize(16777215, 30));
        lineEdit_zk_port_3->setFont(font);
        lineEdit_zk_port_3->setStyleSheet(QLatin1String("background-color: rgb(25, 25, 25, 155);\n"
"border: 1px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding-left:10px;\n"
"padding-right:10px;"));

        verticalLayout_2->addWidget(lineEdit_zk_port_3);


        verticalLayout_3->addWidget(verticalWidget_2);

        verticalWidget_5 = new QWidget(verticalWidget_3);
        verticalWidget_5->setObjectName(QStringLiteral("verticalWidget_5"));
        verticalWidget_5->setMinimumSize(QSize(180, 60));
        verticalWidget_5->setMaximumSize(QSize(180, 60));
        verticalWidget_5->setStyleSheet(QStringLiteral(""));
        verticalLayout_5 = new QVBoxLayout(verticalWidget_5);
        verticalLayout_5->setSpacing(5);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_zk_port_6 = new QLabel(verticalWidget_5);
        label_zk_port_6->setObjectName(QStringLiteral("label_zk_port_6"));
        label_zk_port_6->setMinimumSize(QSize(0, 20));
        label_zk_port_6->setMaximumSize(QSize(16777215, 20));
        label_zk_port_6->setFont(font);

        verticalLayout_5->addWidget(label_zk_port_6);

        lineEdit_zk_port_9 = new QLineEdit(verticalWidget_5);
        lineEdit_zk_port_9->setObjectName(QStringLiteral("lineEdit_zk_port_9"));
        lineEdit_zk_port_9->setMinimumSize(QSize(0, 30));
        lineEdit_zk_port_9->setMaximumSize(QSize(16777215, 30));
        lineEdit_zk_port_9->setFont(font);
        lineEdit_zk_port_9->setStyleSheet(QLatin1String("background-color: rgb(25, 25, 25, 155);\n"
"border: 1px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding-left:10px;\n"
"padding-right:10px;\n"
""));
        lineEdit_zk_port_9->setCursorPosition(0);

        verticalLayout_5->addWidget(lineEdit_zk_port_9);


        verticalLayout_3->addWidget(verticalWidget_5);

        horizontalWidget1 = new QWidget(verticalWidget_3);
        horizontalWidget1->setObjectName(QStringLiteral("horizontalWidget1"));
        horizontalWidget1->setMinimumSize(QSize(200, 30));
        horizontalWidget1->setMaximumSize(QSize(200, 35));
        horizontalLayout_5 = new QHBoxLayout(horizontalWidget1);
        horizontalLayout_5->setSpacing(5);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_zk_port_4 = new QLabel(horizontalWidget1);
        label_zk_port_4->setObjectName(QStringLiteral("label_zk_port_4"));
        label_zk_port_4->setMinimumSize(QSize(90, 0));
        label_zk_port_4->setMaximumSize(QSize(90, 16777215));
        label_zk_port_4->setFont(font);

        horizontalLayout_5->addWidget(label_zk_port_4);

        lineEdit_zk_port_4 = new QLineEdit(horizontalWidget1);
        lineEdit_zk_port_4->setObjectName(QStringLiteral("lineEdit_zk_port_4"));
        lineEdit_zk_port_4->setMinimumSize(QSize(86, 30));
        lineEdit_zk_port_4->setMaximumSize(QSize(86, 30));
        lineEdit_zk_port_4->setFont(font);
        lineEdit_zk_port_4->setStyleSheet(QLatin1String("background-color: rgb(25, 25, 25, 155);\n"
"border: 1px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding-left:10px;\n"
"padding-right:10px;"));
        lineEdit_zk_port_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(lineEdit_zk_port_4);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);


        verticalLayout_3->addWidget(horizontalWidget1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        horizontalLayout_6->addWidget(verticalWidget_3);

        verticalWidget_4 = new QWidget(horizontalWidget_2);
        verticalWidget_4->setObjectName(QStringLiteral("verticalWidget_4"));
        verticalLayout_4 = new QVBoxLayout(verticalWidget_4);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        tabWidget = new QTabWidget(verticalWidget_4);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setFont(font3);
        tabWidget->setStyleSheet(QString::fromUtf8("\n"
" QTabWidget::tab-bar {\n"
"         left:0px;       \n"
"}\n"
"	\n"
"\n"
"/*\350\256\276\347\275\256TabWidget\344\270\255tab_1\347\232\204\346\240\267\345\274\217*/\n"
"#tab_1.QWidget{\n"
"	background-color: rgb(108, 117, 125, 0);\n"
"}\n"
" \n"
"/*\350\256\276\347\275\256TabWidget\344\270\255tab_2\347\232\204\346\240\267\345\274\217*/\n"
"#tab_2.QWidget{\n"
"	background-color: rgb(108, 117, 125, 0);\n"
"}\n"
" \n"
"/*\350\256\276\347\275\256TabWidget\344\270\255QTabBar\347\232\204\346\240\267\345\274\217*/\n"
"QTabBar::tab{\n"
"    background-color: rgb(108, 117, 125, 0);\n"
"	/*font-family:Consolas; */   /*\350\256\276\347\275\256tab\344\270\255\347\232\204\346\226\207\346\234\254\347\232\204\345\255\227\344\275\223*/\n"
"	font-size:10pt;\n"
"	color:#ced4da;    /*\350\256\276\347\275\256tab\344\270\255\347\232\204\346\226\207\346\234\254\347\232\204\351\242\234\350\211\262*/\n"
"	border-top-left-radius: 5px;    /*\350\256\276\347\275\256tab\347\232\204\350\276\271\346\241\206\347\232\204\345\234\206\350"
                        "\247\222\357\274\210\345\267\246\344\270\212\345\234\206\350\247\222\357\274\211*/\n"
"	border-top-right-radius: 5px;    /*\350\256\276\347\275\256tab\347\232\204\350\276\271\346\241\206\347\232\204\345\234\206\350\247\222\357\274\210\345\217\263\344\270\212\345\234\206\350\247\222\357\274\211*/\n"
"	width:80px;\n"
"	padding: 4px;\n"
"	margin-right:0px;\n"
"	margin-left: 0px;\n"
"}\n"
" \n"
"/*\350\256\276\347\275\256TabWidget\344\270\255QTabBar\347\232\204tab\350\242\253\351\200\211\344\270\255\346\227\266\347\232\204\346\240\267\345\274\217*/\n"
"QTabBar::tab:selected{\n"
"	/*background-color: #0B0E11;*/\n"
"	background-color: rgb(108, 117, 125, 0);\n"
"	border-bottom: 2px solid rgb(255, 255, 255);\n"
"}\n"
" \n"
"/*\350\256\276\347\275\256TabWidget\344\270\255\351\274\240\346\240\207\346\202\254\346\265\256\345\234\250QTabBar\347\232\204tab\344\270\212\357\274\214\344\275\206\346\234\252\351\200\211\344\270\255\350\257\245Tab\347\232\204\346\240\267\345\274\217*/\n"
"QTabBar::tab:hover:!selected {\n"
"	/*ba"
                        "ckground-color: rgb(100, 117, 125, 125);*/\n"
"}\n"
" \n"
"/*\350\256\276\347\275\256TabWidget\347\232\204\350\276\271\346\241\206\347\232\204\346\240\267\345\274\217*/\n"
"QTabWidget::pane {\n"
"    border: 0px solid rgb(108, 117, 125, 65);\n"
"}\n"
" \n"
"\n"
"QTabBar::close-button{ \n"
"	/*border-image: url(:lib/Kafka.png);*/\n"
"}\n"
"QTabBar::close-button:hover{\n"
"	/*border-image: url(:/Resources/image/close_hover.png);*/\n"
"}\n"
"\n"
"\n"
"/*\345\275\223\346\211\223\345\274\200\345\244\232\344\270\252tab\357\274\214\345\217\263\344\276\247\345\207\272\347\216\260\357\274\214\347\202\271\345\207\273\345\220\216\357\274\214\345\217\257\344\273\245\345\220\221\345\211\215\345\220\221\345\220\216\347\232\204\346\214\211\351\222\256\347\232\204\346\240\267\345\274\217*/\n"
"QTabBar QToolButton {\n"
"    border: none;\n"
"	color: rgb(255, 206, 6);\n"
"    background-color: #0b0e11;\n"
"}\n"
" \n"
"QTabBar QToolButton:hover {\n"
"	background-color: #161a1e; \n"
"}"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        lineEdit_zk_host_2 = new QLineEdit(tab);
        lineEdit_zk_host_2->setObjectName(QStringLiteral("lineEdit_zk_host_2"));
        lineEdit_zk_host_2->setGeometry(QRect(0, 40, 301, 30));
        lineEdit_zk_host_2->setMinimumSize(QSize(0, 30));
        lineEdit_zk_host_2->setFont(font);
        lineEdit_zk_host_2->setStyleSheet(QLatin1String("background-color: rgb(25, 25, 25, 155);\n"
"border: 1px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding-left:10px;\n"
"padding-right:10px;"));
        label_zk_host_2 = new QLabel(tab);
        label_zk_host_2->setObjectName(QStringLiteral("label_zk_host_2"));
        label_zk_host_2->setGeometry(QRect(0, 10, 39, 30));
        label_zk_host_2->setFont(font);
        label_zk_port_5 = new QLabel(tab);
        label_zk_port_5->setObjectName(QStringLiteral("label_zk_port_5"));
        label_zk_port_5->setGeometry(QRect(340, 10, 39, 30));
        label_zk_port_5->setFont(font);
        lineEdit_zk_port_5 = new QLineEdit(tab);
        lineEdit_zk_port_5->setObjectName(QStringLiteral("lineEdit_zk_port_5"));
        lineEdit_zk_port_5->setGeometry(QRect(340, 40, 81, 30));
        lineEdit_zk_port_5->setMinimumSize(QSize(0, 30));
        lineEdit_zk_port_5->setFont(font);
        lineEdit_zk_port_5->setStyleSheet(QLatin1String("background-color: rgb(25, 25, 25, 155);\n"
"border: 1px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding-left:10px;\n"
"padding-right:10px;"));
        label_zk_host_3 = new QLabel(tab);
        label_zk_host_3->setObjectName(QStringLiteral("label_zk_host_3"));
        label_zk_host_3->setGeometry(QRect(0, 80, 39, 30));
        label_zk_host_3->setFont(font);
        lineEdit_zk_port_6 = new QLineEdit(tab);
        lineEdit_zk_port_6->setObjectName(QStringLiteral("lineEdit_zk_port_6"));
        lineEdit_zk_port_6->setGeometry(QRect(0, 110, 421, 31));
        lineEdit_zk_port_6->setMinimumSize(QSize(0, 30));
        lineEdit_zk_port_6->setFont(font);
        lineEdit_zk_port_6->setStyleSheet(QLatin1String("background-color: rgb(25, 25, 25, 155);\n"
"border: 1px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding-left:10px;\n"
"padding-right:10px;"));
        tabWidget_2 = new QTabWidget(tab);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(0, 160, 431, 170));
        tabWidget_2->setFont(font1);
        tabWidget_2->setStyleSheet(QString::fromUtf8("\n"
" QTabWidget::tab-bar {\n"
"         left:0px;       \n"
"}\n"
"	\n"
"\n"
"/*\350\256\276\347\275\256TabWidget\344\270\255tab_1\347\232\204\346\240\267\345\274\217*/\n"
"#tab.QWidget{\n"
"	background-color: rgb(108, 117, 125, 0);\n"
"}\n"
" \n"
"/*\350\256\276\347\275\256TabWidget\344\270\255tab_2\347\232\204\346\240\267\345\274\217*/\n"
"#tab_2.QWidget{\n"
"	background-color: rgb(108, 117, 125, 0);\n"
"}\n"
" \n"
"/*\350\256\276\347\275\256TabWidget\344\270\255QTabBar\347\232\204\346\240\267\345\274\217*/\n"
"QTabBar::tab{\n"
"    background-color: rgb(108, 117, 125, 0);\n"
"	/*font-family:Consolas; */   /*\350\256\276\347\275\256tab\344\270\255\347\232\204\346\226\207\346\234\254\347\232\204\345\255\227\344\275\223*/\n"
"	font-size:10pt;\n"
"	color:#ced4da;    /*\350\256\276\347\275\256tab\344\270\255\347\232\204\346\226\207\346\234\254\347\232\204\351\242\234\350\211\262*/\n"
"	border-top-left-radius: 0px;    /*\350\256\276\347\275\256tab\347\232\204\350\276\271\346\241\206\347\232\204\345\234\206\350\247"
                        "\222\357\274\210\345\267\246\344\270\212\345\234\206\350\247\222\357\274\211*/\n"
"	border-top-right-radius: 0px;    /*\350\256\276\347\275\256tab\347\232\204\350\276\271\346\241\206\347\232\204\345\234\206\350\247\222\357\274\210\345\217\263\344\270\212\345\234\206\350\247\222\357\274\211*/\n"
"	width:60px;\n"
"	padding: 5px;\n"
"	margin-right:0px;\n"
"	margin-left: 0px;\n"
"}\n"
"/*\350\256\276\347\275\256TabWidget\344\270\255QTabBar\347\232\204tab\350\242\253\351\200\211\344\270\255\346\227\266\347\232\204\346\240\267\345\274\217*/\n"
"QTabBar::tab:selected{\n"
"	background-color: rgb(25, 25, 25, 155);\n"
"	border-bottom: 0px solid rgb(255, 255, 255);\n"
"}\n"
" \n"
"/*\350\256\276\347\275\256TabWidget\344\270\255\351\274\240\346\240\207\346\202\254\346\265\256\345\234\250QTabBar\347\232\204tab\344\270\212\357\274\214\344\275\206\346\234\252\351\200\211\344\270\255\350\257\245Tab\347\232\204\346\240\267\345\274\217*/\n"
"QTabBar::tab:hover:!selected {\n"
"	/*background-color: rgb(100, 117, 125, 125);*/\n"
""
                        "}\n"
" \n"
"/*\350\256\276\347\275\256TabWidget\347\232\204\350\276\271\346\241\206\347\232\204\346\240\267\345\274\217*/\n"
"QTabWidget::pane {\n"
"    border: 0px solid rgb(108, 117, 125, 65);\n"
"}\n"
" \n"
"\n"
"QTabBar::close-button{ \n"
"	/*border-image: url(:lib/Kafka.png);*/\n"
"}\n"
"QTabBar::close-button:hover{\n"
"	/*border-image: url(:/Resources/image/close_hover.png);*/\n"
"}\n"
"\n"
"\n"
"/*\345\275\223\346\211\223\345\274\200\345\244\232\344\270\252tab\357\274\214\345\217\263\344\276\247\345\207\272\347\216\260\357\274\214\347\202\271\345\207\273\345\220\216\357\274\214\345\217\257\344\273\245\345\220\221\345\211\215\345\220\221\345\220\216\347\232\204\346\214\211\351\222\256\347\232\204\346\240\267\345\274\217*/\n"
"QTabBar QToolButton {\n"
"    border: none;\n"
"	color: rgb(255, 206, 6);\n"
"    background-color: #0b0e11;\n"
"}\n"
" \n"
"QTabBar QToolButton:hover {\n"
"	background-color: #161a1e; \n"
"}"));
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        lineEdit_zk_port_7 = new QLineEdit(tab_5);
        lineEdit_zk_port_7->setObjectName(QStringLiteral("lineEdit_zk_port_7"));
        lineEdit_zk_port_7->setGeometry(QRect(0, 40, 421, 31));
        lineEdit_zk_port_7->setMinimumSize(QSize(0, 30));
        lineEdit_zk_port_7->setFont(font);
        lineEdit_zk_port_7->setStyleSheet(QLatin1String("background-color: rgb(25, 25, 25, 155);\n"
"border: 1px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding-left:10px;\n"
"padding-right:10px;"));
        label_zk_host_4 = new QLabel(tab_5);
        label_zk_host_4->setObjectName(QStringLiteral("label_zk_host_4"));
        label_zk_host_4->setGeometry(QRect(0, 10, 39, 30));
        label_zk_host_4->setFont(font);
        checkBox = new QCheckBox(tab_5);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(0, 80, 71, 16));
        checkBox->setFont(font1);
        checkBox->setChecked(true);
        toolButton_5 = new QToolButton(tab_5);
        toolButton_5->setObjectName(QStringLiteral("toolButton_5"));
        toolButton_5->setGeometry(QRect(380, 40, 40, 30));
        sizePolicy1.setHeightForWidth(toolButton_5->sizePolicy().hasHeightForWidth());
        toolButton_5->setSizePolicy(sizePolicy1);
        toolButton_5->setMinimumSize(QSize(30, 30));
        toolButton_5->setMaximumSize(QSize(40, 30));
        toolButton_5->setFont(font1);
        toolButton_5->setStyleSheet(QLatin1String("QToolButton {\n"
"background-color: rgba(25, 25, 25,0);\n"
"border: 1px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding-left:10px;\n"
"padding-right:10px;\n"
"}\n"
"\n"
"QToolButton::menu-indicator { \n"
"	image: None;\n"
"}\n"
"\n"
" \n"
"QToolButton:hover {\n"
"background-color: rgba(25, 25, 25,0);\n"
"border: 1px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding-left:10px;\n"
"padding-right:10px;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/lib/eye1.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_5->setIcon(icon1);
        toolButton_5->setIconSize(QSize(14, 14));
        tabWidget_2->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        label_zk_host_5 = new QLabel(tab_6);
        label_zk_host_5->setObjectName(QStringLiteral("label_zk_host_5"));
        label_zk_host_5->setGeometry(QRect(0, 10, 39, 30));
        label_zk_host_5->setFont(font);
        lineEdit_zk_port_8 = new QLineEdit(tab_6);
        lineEdit_zk_port_8->setObjectName(QStringLiteral("lineEdit_zk_port_8"));
        lineEdit_zk_port_8->setGeometry(QRect(0, 40, 331, 31));
        lineEdit_zk_port_8->setMinimumSize(QSize(0, 30));
        lineEdit_zk_port_8->setFont(font);
        lineEdit_zk_port_8->setStyleSheet(QLatin1String("background-color: rgb(25, 25, 25, 155);\n"
"border: 1px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding-left:10px;\n"
"padding-right:10px;"));
        toolButton_4 = new QToolButton(tab_6);
        toolButton_4->setObjectName(QStringLiteral("toolButton_4"));
        toolButton_4->setGeometry(QRect(350, 40, 70, 30));
        sizePolicy1.setHeightForWidth(toolButton_4->sizePolicy().hasHeightForWidth());
        toolButton_4->setSizePolicy(sizePolicy1);
        toolButton_4->setMinimumSize(QSize(70, 30));
        toolButton_4->setMaximumSize(QSize(70, 30));
        toolButton_4->setFont(font1);
        toolButton_4->setStyleSheet(QLatin1String("QToolButton {\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(255, 95, 95);\n"
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
"	background-color: rgb(255, 95, 95);\n"
"}"));
        checkBox_2 = new QCheckBox(tab_6);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(0, 80, 71, 16));
        checkBox_2->setFont(font1);
        checkBox_2->setChecked(true);
        tabWidget_2->addTab(tab_6, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QStringLiteral("tab_7"));
        tabWidget_2->addTab(tab_7, QString());
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tabWidget->addTab(tab_3, QString());

        verticalLayout_4->addWidget(tabWidget);


        horizontalLayout_6->addWidget(verticalWidget_4);


        retranslateUi(createconnect);

        stackedWidget->setCurrentIndex(0);
        tabWidget->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(createconnect);
    } // setupUi

    void retranslateUi(QWidget *createconnect)
    {
        createconnect->setWindowTitle(QApplication::translate("createconnect", "\346\226\260\345\273\272\350\277\236\346\216\245", nullptr));
        toolButton_ssh_connect->setText(QApplication::translate("createconnect", "\350\277\236\346\216\245", nullptr));
        toolButton_ssh_close->setText(QApplication::translate("createconnect", "\345\217\226\346\266\210", nullptr));
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
        toolButton_zk_connect->setText(QApplication::translate("createconnect", "\347\241\256\345\256\232", nullptr));
        toolButton_zk_close->setText(QApplication::translate("createconnect", "\345\217\226\346\266\210", nullptr));
        toolButton_2->setText(QApplication::translate("createconnect", "\350\277\236\346\216\245", nullptr));
        toolButton->setText(QApplication::translate("createconnect", "\344\277\235\345\255\230", nullptr));
        toolButton_3->setText(QApplication::translate("createconnect", "\345\217\226\346\266\210", nullptr));
        label_zk_port_2->setText(QApplication::translate("createconnect", "\345\220\215\347\247\260", nullptr));
        lineEdit_zk_port_2->setText(QApplication::translate("createconnect", "321312", nullptr));
        label_zk_port_3->setText(QApplication::translate("createconnect", "\345\210\206\347\273\204", nullptr));
        lineEdit_zk_port_3->setText(QApplication::translate("createconnect", "ddsadasdas", nullptr));
        label_zk_port_6->setText(QApplication::translate("createconnect", "\345\233\276\346\240\207", nullptr));
        lineEdit_zk_port_9->setText(QString());
        label_zk_port_4->setText(QApplication::translate("createconnect", "\346\240\207\351\242\230\351\242\234\350\211\262", nullptr));
        lineEdit_zk_port_4->setText(QApplication::translate("createconnect", "#dsadas", nullptr));
        lineEdit_zk_host_2->setText(QApplication::translate("createconnect", "172.16.8.153", nullptr));
        label_zk_host_2->setText(QApplication::translate("createconnect", "\344\270\273\346\234\272", nullptr));
        label_zk_port_5->setText(QApplication::translate("createconnect", "\347\253\257\345\217\243", nullptr));
        lineEdit_zk_port_5->setText(QApplication::translate("createconnect", "11100", nullptr));
        label_zk_host_3->setText(QApplication::translate("createconnect", "\347\224\250\346\210\267\345\220\215", nullptr));
        lineEdit_zk_port_6->setText(QApplication::translate("createconnect", "root", nullptr));
        lineEdit_zk_port_7->setText(QApplication::translate("createconnect", "******", nullptr));
        label_zk_host_4->setText(QApplication::translate("createconnect", "\345\257\206\347\240\201", nullptr));
        checkBox->setText(QApplication::translate("createconnect", "\350\256\260\344\275\217\345\257\206\347\240\201", nullptr));
        toolButton_5->setText(QApplication::translate("createconnect", "\345\217\226\346\266\210", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QApplication::translate("createconnect", "\345\257\206\347\240\201", nullptr));
        label_zk_host_5->setText(QApplication::translate("createconnect", "\347\247\201\351\222\245", nullptr));
        lineEdit_zk_port_8->setText(QApplication::translate("createconnect", "******", nullptr));
        toolButton_4->setText(QApplication::translate("createconnect", "\346\265\217\350\247\210...", nullptr));
        checkBox_2->setText(QApplication::translate("createconnect", "\350\256\260\344\275\217\347\247\201\351\222\245", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_6), QApplication::translate("createconnect", "\345\205\254\351\222\245", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_7), QApplication::translate("createconnect", "\351\224\256\347\233\230\344\272\222\344\272\244", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("createconnect", "SSH", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("createconnect", "\350\277\234\347\250\213\350\277\236\346\216\245", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("createconnect", "ZOOKEEPER", nullptr));
    } // retranslateUi

};

namespace Ui {
    class createconnect: public Ui_createconnect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATECONNECT_H
