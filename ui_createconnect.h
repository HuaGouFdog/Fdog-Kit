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
    QWidget *widget_bottom;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *widget_bottom_horizontalSpacer_left;
    QToolButton *widget_bottom_toolButton_connect;
    QToolButton *widget_bottom_toolButton_save;
    QToolButton *widget_bottom_toolButton_close;
    QSpacerItem *widget_bottom_horizontalSpacer_right;
    QWidget *widget_body;
    QHBoxLayout *horizontalLayout_6;
    QWidget *widget_body_left;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_name;
    QVBoxLayout *verticalLayout;
    QLabel *widget_name_label_name;
    QLineEdit *widget_name_lineEdit_name_data;
    QWidget *widget_group;
    QVBoxLayout *verticalLayout_2;
    QLabel *widget_group_label_group;
    QLineEdit *widget_group_lineEdit_group_data;
    QWidget *widget_group_2;
    QVBoxLayout *verticalLayout_5;
    QLabel *widget_group_label_group_2;
    QLineEdit *widget_group_lineEdit_group_data_2;
    QWidget *widget_color;
    QHBoxLayout *horizontalLayout_5;
    QLabel *widget_color_label_color;
    QToolButton *widget_color_toolButton_color_data;
    QSpacerItem *widget_color_horizontalSpacer_color;
    QWidget *widget_dynamic_title;
    QVBoxLayout *verticalLayout_6;
    QCheckBox *widget_dynamic_title_checkBox;
    QLabel *widget_dynamic_title_label;
    QWidget *widget_body_right;
    QVBoxLayout *verticalLayout_4;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLineEdit *lineEdit_host_ssh_data;
    QLabel *label_host_ssh;
    QLabel *label_port_ssh;
    QLineEdit *lineEdit_port_ssh_data;
    QLabel *label_user_ssh;
    QLineEdit *lineEdit_user_ssh_data;
    QTabWidget *tabWidget_2;
    QWidget *tab_passowrd;
    QLineEdit *tab_passowrd_lineEdit_password_data;
    QLabel *tab_passowrd_label_password;
    QCheckBox *tab_passowrd_checkBox_remember_password;
    QToolButton *tab_passowrd_toolButton_show;
    QWidget *tab_secretkey;
    QLabel *label_zk_host_5;
    QLineEdit *lineEdit_zk_port_8;
    QToolButton *toolButton_4;
    QCheckBox *checkBox_2;
    QWidget *tab_keyboard;
    QToolButton *toolButton_6;
    QCheckBox *checkBox_remember_password_2;
    QLineEdit *lineEdit_password_data_2;
    QLabel *label_password_2;
    QWidget *tab_2;
    QLineEdit *lineEdit_port_ssh_data_3;
    QLabel *label_port_ssh_3;
    QLineEdit *lineEdit_host_ssh_data_3;
    QLabel *label_host_ssh_3;
    QToolButton *tab_passowrd_toolButton_show_2;
    QLineEdit *lineEdit_user_ssh_data_2;
    QCheckBox *tab_passowrd_checkBox_remember_password_2;
    QLineEdit *tab_passowrd_lineEdit_password_data_2;
    QLabel *label_user_ssh_2;
    QLabel *tab_passowrd_label_password_2;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_4;
    QLabel *tab_passowrd_label_password_3;
    QComboBox *comboBox;
    QCheckBox *tab_passowrd_checkBox_remember_password_3;
    QLabel *widget_dynamic_title_label_3;
    QWidget *tab_3;
    QLineEdit *lineEdit_port_ssh_data_2;
    QLabel *label_port_ssh_2;
    QLineEdit *lineEdit_host_ssh_data_2;
    QLabel *label_host_ssh_2;
    QLabel *widget_dynamic_title_label_2;
    QWidget *tab_4;

    void setupUi(QWidget *createconnect)
    {
        if (createconnect->objectName().isEmpty())
            createconnect->setObjectName(QStringLiteral("createconnect"));
        createconnect->resize(673, 439);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(createconnect->sizePolicy().hasHeightForWidth());
        createconnect->setSizePolicy(sizePolicy);
        createconnect->setMinimumSize(QSize(673, 430));
        createconnect->setMaximumSize(QSize(16777215, 16777215));
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
        stackedWidget->setGeometry(QRect(320, 520, 331, 221));
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
        widget_bottom = new QWidget(createconnect);
        widget_bottom->setObjectName(QStringLiteral("widget_bottom"));
        widget_bottom->setGeometry(QRect(0, 400, 701, 31));
        widget_bottom->setStyleSheet(QLatin1String("background-color: rgb(30, 45, 54);\n"
"color: rgb(255, 255, 255);"));
        horizontalLayout_3 = new QHBoxLayout(widget_bottom);
        horizontalLayout_3->setSpacing(10);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(9, 0, 9, 0);
        widget_bottom_horizontalSpacer_left = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(widget_bottom_horizontalSpacer_left);

        widget_bottom_toolButton_connect = new QToolButton(widget_bottom);
        widget_bottom_toolButton_connect->setObjectName(QStringLiteral("widget_bottom_toolButton_connect"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget_bottom_toolButton_connect->sizePolicy().hasHeightForWidth());
        widget_bottom_toolButton_connect->setSizePolicy(sizePolicy1);
        widget_bottom_toolButton_connect->setMinimumSize(QSize(60, 30));
        widget_bottom_toolButton_connect->setMaximumSize(QSize(60, 30));
        widget_bottom_toolButton_connect->setFont(font1);
        widget_bottom_toolButton_connect->setStyleSheet(QLatin1String("QToolButton {\n"
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

        horizontalLayout_3->addWidget(widget_bottom_toolButton_connect);

        widget_bottom_toolButton_save = new QToolButton(widget_bottom);
        widget_bottom_toolButton_save->setObjectName(QStringLiteral("widget_bottom_toolButton_save"));
        sizePolicy1.setHeightForWidth(widget_bottom_toolButton_save->sizePolicy().hasHeightForWidth());
        widget_bottom_toolButton_save->setSizePolicy(sizePolicy1);
        widget_bottom_toolButton_save->setMinimumSize(QSize(60, 30));
        widget_bottom_toolButton_save->setMaximumSize(QSize(60, 30));
        QFont font3;
        font3.setFamily(QStringLiteral("OPPOSans B"));
        font3.setPointSize(10);
        font3.setBold(false);
        font3.setWeight(50);
        font3.setStyleStrategy(QFont::PreferAntialias);
        widget_bottom_toolButton_save->setFont(font3);
        widget_bottom_toolButton_save->setStyleSheet(QLatin1String("QToolButton {\n"
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

        horizontalLayout_3->addWidget(widget_bottom_toolButton_save);

        widget_bottom_toolButton_close = new QToolButton(widget_bottom);
        widget_bottom_toolButton_close->setObjectName(QStringLiteral("widget_bottom_toolButton_close"));
        sizePolicy1.setHeightForWidth(widget_bottom_toolButton_close->sizePolicy().hasHeightForWidth());
        widget_bottom_toolButton_close->setSizePolicy(sizePolicy1);
        widget_bottom_toolButton_close->setMinimumSize(QSize(60, 30));
        widget_bottom_toolButton_close->setMaximumSize(QSize(60, 30));
        widget_bottom_toolButton_close->setFont(font1);
        widget_bottom_toolButton_close->setStyleSheet(QLatin1String("QToolButton {\n"
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

        horizontalLayout_3->addWidget(widget_bottom_toolButton_close);

        widget_bottom_horizontalSpacer_right = new QSpacerItem(30, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(widget_bottom_horizontalSpacer_right);

        widget_body = new QWidget(createconnect);
        widget_body->setObjectName(QStringLiteral("widget_body"));
        widget_body->setGeometry(QRect(0, 0, 681, 391));
        horizontalLayout_6 = new QHBoxLayout(widget_body);
        horizontalLayout_6->setSpacing(20);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(15, 30, 15, -1);
        widget_body_left = new QWidget(widget_body);
        widget_body_left->setObjectName(QStringLiteral("widget_body_left"));
        widget_body_left->setMinimumSize(QSize(190, 0));
        widget_body_left->setMaximumSize(QSize(190, 16777215));
        verticalLayout_3 = new QVBoxLayout(widget_body_left);
        verticalLayout_3->setSpacing(10);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(9, 3, 1, 0);
        widget_name = new QWidget(widget_body_left);
        widget_name->setObjectName(QStringLiteral("widget_name"));
        widget_name->setMinimumSize(QSize(180, 60));
        widget_name->setMaximumSize(QSize(180, 60));
        widget_name->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(widget_name);
        verticalLayout->setSpacing(5);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_name_label_name = new QLabel(widget_name);
        widget_name_label_name->setObjectName(QStringLiteral("widget_name_label_name"));
        widget_name_label_name->setMinimumSize(QSize(0, 20));
        widget_name_label_name->setMaximumSize(QSize(16777215, 20));
        widget_name_label_name->setFont(font);

        verticalLayout->addWidget(widget_name_label_name);

        widget_name_lineEdit_name_data = new QLineEdit(widget_name);
        widget_name_lineEdit_name_data->setObjectName(QStringLiteral("widget_name_lineEdit_name_data"));
        widget_name_lineEdit_name_data->setMinimumSize(QSize(0, 30));
        widget_name_lineEdit_name_data->setMaximumSize(QSize(16777215, 30));
        widget_name_lineEdit_name_data->setFont(font);
        widget_name_lineEdit_name_data->setStyleSheet(QLatin1String("background-color: rgb(25, 25, 25, 155);\n"
"border: 1px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding-left:10px;\n"
"padding-right:10px;"));
        widget_name_lineEdit_name_data->setCursorPosition(0);

        verticalLayout->addWidget(widget_name_lineEdit_name_data);


        verticalLayout_3->addWidget(widget_name);

        widget_group = new QWidget(widget_body_left);
        widget_group->setObjectName(QStringLiteral("widget_group"));
        widget_group->setMinimumSize(QSize(180, 60));
        widget_group->setMaximumSize(QSize(180, 60));
        widget_group->setStyleSheet(QStringLiteral(""));
        verticalLayout_2 = new QVBoxLayout(widget_group);
        verticalLayout_2->setSpacing(5);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_group_label_group = new QLabel(widget_group);
        widget_group_label_group->setObjectName(QStringLiteral("widget_group_label_group"));
        widget_group_label_group->setMinimumSize(QSize(0, 20));
        widget_group_label_group->setMaximumSize(QSize(16777215, 20));
        widget_group_label_group->setFont(font);

        verticalLayout_2->addWidget(widget_group_label_group);

        widget_group_lineEdit_group_data = new QLineEdit(widget_group);
        widget_group_lineEdit_group_data->setObjectName(QStringLiteral("widget_group_lineEdit_group_data"));
        widget_group_lineEdit_group_data->setMinimumSize(QSize(0, 30));
        widget_group_lineEdit_group_data->setMaximumSize(QSize(16777215, 30));
        widget_group_lineEdit_group_data->setFont(font);
        widget_group_lineEdit_group_data->setStyleSheet(QLatin1String("background-color: rgb(25, 25, 25, 155);\n"
"border: 1px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding-left:10px;\n"
"padding-right:10px;"));

        verticalLayout_2->addWidget(widget_group_lineEdit_group_data);


        verticalLayout_3->addWidget(widget_group);

        widget_group_2 = new QWidget(widget_body_left);
        widget_group_2->setObjectName(QStringLiteral("widget_group_2"));
        widget_group_2->setMinimumSize(QSize(180, 100));
        widget_group_2->setMaximumSize(QSize(180, 100));
        widget_group_2->setStyleSheet(QStringLiteral(""));
        verticalLayout_5 = new QVBoxLayout(widget_group_2);
        verticalLayout_5->setSpacing(5);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        widget_group_label_group_2 = new QLabel(widget_group_2);
        widget_group_label_group_2->setObjectName(QStringLiteral("widget_group_label_group_2"));
        widget_group_label_group_2->setMinimumSize(QSize(0, 20));
        widget_group_label_group_2->setMaximumSize(QSize(16777215, 20));
        widget_group_label_group_2->setFont(font);

        verticalLayout_5->addWidget(widget_group_label_group_2);

        widget_group_lineEdit_group_data_2 = new QLineEdit(widget_group_2);
        widget_group_lineEdit_group_data_2->setObjectName(QStringLiteral("widget_group_lineEdit_group_data_2"));
        widget_group_lineEdit_group_data_2->setMinimumSize(QSize(0, 60));
        widget_group_lineEdit_group_data_2->setMaximumSize(QSize(16777215, 60));
        widget_group_lineEdit_group_data_2->setFont(font);
        widget_group_lineEdit_group_data_2->setStyleSheet(QLatin1String("background-color: rgb(25, 25, 25, 155);\n"
"border: 1px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding-left:10px;\n"
"padding-right:10px;"));
        widget_group_lineEdit_group_data_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_5->addWidget(widget_group_lineEdit_group_data_2);


        verticalLayout_3->addWidget(widget_group_2);

        widget_color = new QWidget(widget_body_left);
        widget_color->setObjectName(QStringLiteral("widget_color"));
        widget_color->setMinimumSize(QSize(200, 30));
        widget_color->setMaximumSize(QSize(200, 35));
        horizontalLayout_5 = new QHBoxLayout(widget_color);
        horizontalLayout_5->setSpacing(5);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        widget_color_label_color = new QLabel(widget_color);
        widget_color_label_color->setObjectName(QStringLiteral("widget_color_label_color"));
        widget_color_label_color->setMinimumSize(QSize(85, 0));
        widget_color_label_color->setMaximumSize(QSize(85, 16777215));
        widget_color_label_color->setFont(font);

        horizontalLayout_5->addWidget(widget_color_label_color);

        widget_color_toolButton_color_data = new QToolButton(widget_color);
        widget_color_toolButton_color_data->setObjectName(QStringLiteral("widget_color_toolButton_color_data"));
        sizePolicy1.setHeightForWidth(widget_color_toolButton_color_data->sizePolicy().hasHeightForWidth());
        widget_color_toolButton_color_data->setSizePolicy(sizePolicy1);
        widget_color_toolButton_color_data->setMinimumSize(QSize(90, 30));
        widget_color_toolButton_color_data->setMaximumSize(QSize(90, 30));
        widget_color_toolButton_color_data->setFont(font1);
        widget_color_toolButton_color_data->setStyleSheet(QLatin1String("QToolButton {\n"
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

        horizontalLayout_5->addWidget(widget_color_toolButton_color_data);

        widget_color_horizontalSpacer_color = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(widget_color_horizontalSpacer_color);


        verticalLayout_3->addWidget(widget_color);

        widget_dynamic_title = new QWidget(widget_body_left);
        widget_dynamic_title->setObjectName(QStringLiteral("widget_dynamic_title"));
        widget_dynamic_title->setMinimumSize(QSize(200, 50));
        widget_dynamic_title->setMaximumSize(QSize(200, 50));
        verticalLayout_6 = new QVBoxLayout(widget_dynamic_title);
        verticalLayout_6->setSpacing(5);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        widget_dynamic_title_checkBox = new QCheckBox(widget_dynamic_title);
        widget_dynamic_title_checkBox->setObjectName(QStringLiteral("widget_dynamic_title_checkBox"));
        widget_dynamic_title_checkBox->setFont(font1);
        widget_dynamic_title_checkBox->setContextMenuPolicy(Qt::DefaultContextMenu);
        widget_dynamic_title_checkBox->setChecked(true);
        widget_dynamic_title_checkBox->setTristate(false);

        verticalLayout_6->addWidget(widget_dynamic_title_checkBox);

        widget_dynamic_title_label = new QLabel(widget_dynamic_title);
        widget_dynamic_title_label->setObjectName(QStringLiteral("widget_dynamic_title_label"));
        widget_dynamic_title_label->setMinimumSize(QSize(100, 25));
        widget_dynamic_title_label->setMaximumSize(QSize(180, 16777215));
        QFont font4;
        font4.setFamily(QStringLiteral("OPPOSans B"));
        font4.setPointSize(9);
        widget_dynamic_title_label->setFont(font4);
        widget_dynamic_title_label->setStyleSheet(QStringLiteral("color: rgba(223, 223, 223, 150);"));

        verticalLayout_6->addWidget(widget_dynamic_title_label);


        verticalLayout_3->addWidget(widget_dynamic_title);


        horizontalLayout_6->addWidget(widget_body_left);

        widget_body_right = new QWidget(widget_body);
        widget_body_right->setObjectName(QStringLiteral("widget_body_right"));
        verticalLayout_4 = new QVBoxLayout(widget_body_right);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(-1, -1, -1, 0);
        tabWidget = new QTabWidget(widget_body_right);
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
"	font-size:11pt;\n"
"	color:#ced4da;    /*\350\256\276\347\275\256tab\344\270\255\347\232\204\346\226\207\346\234\254\347\232\204\351\242\234\350\211\262*/\n"
"	border-top-left-radius: 5px;    /*\350\256\276\347\275\256tab\347\232\204\350\276\271\346\241\206\347\232\204\345\234\206\350"
                        "\247\222\357\274\210\345\267\246\344\270\212\345\234\206\350\247\222\357\274\211*/\n"
"	border-top-right-radius: 5px;    /*\350\256\276\347\275\256tab\347\232\204\350\276\271\346\241\206\347\232\204\345\234\206\350\247\222\357\274\210\345\217\263\344\270\212\345\234\206\350\247\222\357\274\211*/\n"
"	/*width:80px;*/\n"
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
"	"
                        "/*background-color: rgb(100, 117, 125, 125);*/\n"
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
        tabWidget->setTabBarAutoHide(false);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        lineEdit_host_ssh_data = new QLineEdit(tab);
        lineEdit_host_ssh_data->setObjectName(QStringLiteral("lineEdit_host_ssh_data"));
        lineEdit_host_ssh_data->setGeometry(QRect(0, 40, 301, 30));
        lineEdit_host_ssh_data->setMinimumSize(QSize(0, 30));
        lineEdit_host_ssh_data->setFont(font);
        lineEdit_host_ssh_data->setStyleSheet(QLatin1String("background-color: rgb(25, 25, 25, 155);\n"
"border: 1px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding-left:10px;\n"
"padding-right:10px;"));
        label_host_ssh = new QLabel(tab);
        label_host_ssh->setObjectName(QStringLiteral("label_host_ssh"));
        label_host_ssh->setGeometry(QRect(0, 10, 39, 30));
        label_host_ssh->setFont(font);
        label_port_ssh = new QLabel(tab);
        label_port_ssh->setObjectName(QStringLiteral("label_port_ssh"));
        label_port_ssh->setGeometry(QRect(340, 10, 39, 30));
        label_port_ssh->setFont(font);
        lineEdit_port_ssh_data = new QLineEdit(tab);
        lineEdit_port_ssh_data->setObjectName(QStringLiteral("lineEdit_port_ssh_data"));
        lineEdit_port_ssh_data->setGeometry(QRect(340, 40, 81, 30));
        lineEdit_port_ssh_data->setMinimumSize(QSize(0, 30));
        lineEdit_port_ssh_data->setFont(font);
        lineEdit_port_ssh_data->setStyleSheet(QLatin1String("background-color: rgb(25, 25, 25, 155);\n"
"border: 1px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding-left:10px;\n"
"padding-right:10px;"));
        label_user_ssh = new QLabel(tab);
        label_user_ssh->setObjectName(QStringLiteral("label_user_ssh"));
        label_user_ssh->setGeometry(QRect(0, 80, 39, 30));
        label_user_ssh->setFont(font);
        lineEdit_user_ssh_data = new QLineEdit(tab);
        lineEdit_user_ssh_data->setObjectName(QStringLiteral("lineEdit_user_ssh_data"));
        lineEdit_user_ssh_data->setGeometry(QRect(0, 110, 421, 31));
        lineEdit_user_ssh_data->setMinimumSize(QSize(0, 30));
        lineEdit_user_ssh_data->setFont(font);
        lineEdit_user_ssh_data->setStyleSheet(QLatin1String("background-color: rgb(25, 25, 25, 155);\n"
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
"	/*width:60px;*/\n"
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
        tab_passowrd = new QWidget();
        tab_passowrd->setObjectName(QStringLiteral("tab_passowrd"));
        tab_passowrd_lineEdit_password_data = new QLineEdit(tab_passowrd);
        tab_passowrd_lineEdit_password_data->setObjectName(QStringLiteral("tab_passowrd_lineEdit_password_data"));
        tab_passowrd_lineEdit_password_data->setGeometry(QRect(0, 40, 421, 31));
        tab_passowrd_lineEdit_password_data->setMinimumSize(QSize(0, 30));
        tab_passowrd_lineEdit_password_data->setFont(font);
        tab_passowrd_lineEdit_password_data->setStyleSheet(QLatin1String("background-color: rgb(25, 25, 25, 155);\n"
"border: 1px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding-left:10px;\n"
"padding-right:10px;"));
        tab_passowrd_lineEdit_password_data->setEchoMode(QLineEdit::Password);
        tab_passowrd_label_password = new QLabel(tab_passowrd);
        tab_passowrd_label_password->setObjectName(QStringLiteral("tab_passowrd_label_password"));
        tab_passowrd_label_password->setGeometry(QRect(0, 10, 39, 30));
        tab_passowrd_label_password->setFont(font);
        tab_passowrd_checkBox_remember_password = new QCheckBox(tab_passowrd);
        tab_passowrd_checkBox_remember_password->setObjectName(QStringLiteral("tab_passowrd_checkBox_remember_password"));
        tab_passowrd_checkBox_remember_password->setGeometry(QRect(0, 80, 71, 16));
        tab_passowrd_checkBox_remember_password->setFont(font1);
        tab_passowrd_checkBox_remember_password->setChecked(true);
        tab_passowrd_toolButton_show = new QToolButton(tab_passowrd);
        tab_passowrd_toolButton_show->setObjectName(QStringLiteral("tab_passowrd_toolButton_show"));
        tab_passowrd_toolButton_show->setGeometry(QRect(380, 40, 40, 30));
        sizePolicy1.setHeightForWidth(tab_passowrd_toolButton_show->sizePolicy().hasHeightForWidth());
        tab_passowrd_toolButton_show->setSizePolicy(sizePolicy1);
        tab_passowrd_toolButton_show->setMinimumSize(QSize(30, 30));
        tab_passowrd_toolButton_show->setMaximumSize(QSize(40, 30));
        tab_passowrd_toolButton_show->setFont(font1);
        tab_passowrd_toolButton_show->setStyleSheet(QLatin1String("QToolButton {\n"
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
        icon1.addFile(QStringLiteral(":/lib/eye2.png"), QSize(), QIcon::Normal, QIcon::Off);
        tab_passowrd_toolButton_show->setIcon(icon1);
        tab_passowrd_toolButton_show->setIconSize(QSize(14, 14));
        tabWidget_2->addTab(tab_passowrd, QString());
        tab_secretkey = new QWidget();
        tab_secretkey->setObjectName(QStringLiteral("tab_secretkey"));
        label_zk_host_5 = new QLabel(tab_secretkey);
        label_zk_host_5->setObjectName(QStringLiteral("label_zk_host_5"));
        label_zk_host_5->setGeometry(QRect(0, 10, 39, 30));
        label_zk_host_5->setFont(font);
        lineEdit_zk_port_8 = new QLineEdit(tab_secretkey);
        lineEdit_zk_port_8->setObjectName(QStringLiteral("lineEdit_zk_port_8"));
        lineEdit_zk_port_8->setGeometry(QRect(0, 40, 331, 31));
        lineEdit_zk_port_8->setMinimumSize(QSize(0, 30));
        lineEdit_zk_port_8->setFont(font);
        lineEdit_zk_port_8->setStyleSheet(QLatin1String("background-color: rgb(25, 25, 25, 155);\n"
"border: 1px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding-left:10px;\n"
"padding-right:10px;"));
        toolButton_4 = new QToolButton(tab_secretkey);
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
        checkBox_2 = new QCheckBox(tab_secretkey);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(0, 80, 71, 16));
        checkBox_2->setFont(font1);
        checkBox_2->setChecked(true);
        tabWidget_2->addTab(tab_secretkey, QString());
        tab_keyboard = new QWidget();
        tab_keyboard->setObjectName(QStringLiteral("tab_keyboard"));
        toolButton_6 = new QToolButton(tab_keyboard);
        toolButton_6->setObjectName(QStringLiteral("toolButton_6"));
        toolButton_6->setGeometry(QRect(380, 40, 40, 30));
        sizePolicy1.setHeightForWidth(toolButton_6->sizePolicy().hasHeightForWidth());
        toolButton_6->setSizePolicy(sizePolicy1);
        toolButton_6->setMinimumSize(QSize(30, 30));
        toolButton_6->setMaximumSize(QSize(40, 30));
        toolButton_6->setFont(font1);
        toolButton_6->setStyleSheet(QLatin1String("QToolButton {\n"
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
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/lib/eye1.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_6->setIcon(icon2);
        toolButton_6->setIconSize(QSize(14, 14));
        checkBox_remember_password_2 = new QCheckBox(tab_keyboard);
        checkBox_remember_password_2->setObjectName(QStringLiteral("checkBox_remember_password_2"));
        checkBox_remember_password_2->setGeometry(QRect(0, 80, 71, 16));
        checkBox_remember_password_2->setFont(font1);
        checkBox_remember_password_2->setChecked(true);
        lineEdit_password_data_2 = new QLineEdit(tab_keyboard);
        lineEdit_password_data_2->setObjectName(QStringLiteral("lineEdit_password_data_2"));
        lineEdit_password_data_2->setGeometry(QRect(0, 40, 421, 31));
        lineEdit_password_data_2->setMinimumSize(QSize(0, 30));
        lineEdit_password_data_2->setFont(font);
        lineEdit_password_data_2->setStyleSheet(QLatin1String("background-color: rgb(25, 25, 25, 155);\n"
"border: 1px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding-left:10px;\n"
"padding-right:10px;"));
        label_password_2 = new QLabel(tab_keyboard);
        label_password_2->setObjectName(QStringLiteral("label_password_2"));
        label_password_2->setGeometry(QRect(0, 10, 39, 30));
        label_password_2->setFont(font);
        tabWidget_2->addTab(tab_keyboard, QString());
        checkBox_remember_password_2->raise();
        lineEdit_password_data_2->raise();
        label_password_2->raise();
        toolButton_6->raise();
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        lineEdit_port_ssh_data_3 = new QLineEdit(tab_2);
        lineEdit_port_ssh_data_3->setObjectName(QStringLiteral("lineEdit_port_ssh_data_3"));
        lineEdit_port_ssh_data_3->setGeometry(QRect(340, 40, 81, 30));
        lineEdit_port_ssh_data_3->setMinimumSize(QSize(0, 30));
        lineEdit_port_ssh_data_3->setFont(font);
        lineEdit_port_ssh_data_3->setStyleSheet(QLatin1String("background-color: rgb(25, 25, 25, 155);\n"
"border: 1px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding-left:10px;\n"
"padding-right:10px;"));
        label_port_ssh_3 = new QLabel(tab_2);
        label_port_ssh_3->setObjectName(QStringLiteral("label_port_ssh_3"));
        label_port_ssh_3->setGeometry(QRect(340, 10, 39, 30));
        label_port_ssh_3->setFont(font);
        lineEdit_host_ssh_data_3 = new QLineEdit(tab_2);
        lineEdit_host_ssh_data_3->setObjectName(QStringLiteral("lineEdit_host_ssh_data_3"));
        lineEdit_host_ssh_data_3->setGeometry(QRect(0, 40, 301, 30));
        lineEdit_host_ssh_data_3->setMinimumSize(QSize(0, 30));
        lineEdit_host_ssh_data_3->setFont(font);
        lineEdit_host_ssh_data_3->setStyleSheet(QLatin1String("background-color: rgb(25, 25, 25, 155);\n"
"border: 1px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding-left:10px;\n"
"padding-right:10px;"));
        label_host_ssh_3 = new QLabel(tab_2);
        label_host_ssh_3->setObjectName(QStringLiteral("label_host_ssh_3"));
        label_host_ssh_3->setGeometry(QRect(0, 10, 39, 30));
        label_host_ssh_3->setFont(font);
        tab_passowrd_toolButton_show_2 = new QToolButton(tab_2);
        tab_passowrd_toolButton_show_2->setObjectName(QStringLiteral("tab_passowrd_toolButton_show_2"));
        tab_passowrd_toolButton_show_2->setGeometry(QRect(380, 180, 40, 30));
        sizePolicy1.setHeightForWidth(tab_passowrd_toolButton_show_2->sizePolicy().hasHeightForWidth());
        tab_passowrd_toolButton_show_2->setSizePolicy(sizePolicy1);
        tab_passowrd_toolButton_show_2->setMinimumSize(QSize(30, 30));
        tab_passowrd_toolButton_show_2->setMaximumSize(QSize(40, 30));
        tab_passowrd_toolButton_show_2->setFont(font1);
        tab_passowrd_toolButton_show_2->setStyleSheet(QLatin1String("QToolButton {\n"
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
        tab_passowrd_toolButton_show_2->setIcon(icon1);
        tab_passowrd_toolButton_show_2->setIconSize(QSize(14, 14));
        lineEdit_user_ssh_data_2 = new QLineEdit(tab_2);
        lineEdit_user_ssh_data_2->setObjectName(QStringLiteral("lineEdit_user_ssh_data_2"));
        lineEdit_user_ssh_data_2->setGeometry(QRect(0, 110, 421, 31));
        lineEdit_user_ssh_data_2->setMinimumSize(QSize(0, 30));
        lineEdit_user_ssh_data_2->setFont(font);
        lineEdit_user_ssh_data_2->setStyleSheet(QLatin1String("background-color: rgb(25, 25, 25, 155);\n"
"border: 1px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding-left:10px;\n"
"padding-right:10px;"));
        tab_passowrd_checkBox_remember_password_2 = new QCheckBox(tab_2);
        tab_passowrd_checkBox_remember_password_2->setObjectName(QStringLiteral("tab_passowrd_checkBox_remember_password_2"));
        tab_passowrd_checkBox_remember_password_2->setGeometry(QRect(0, 220, 71, 16));
        tab_passowrd_checkBox_remember_password_2->setFont(font1);
        tab_passowrd_checkBox_remember_password_2->setChecked(true);
        tab_passowrd_lineEdit_password_data_2 = new QLineEdit(tab_2);
        tab_passowrd_lineEdit_password_data_2->setObjectName(QStringLiteral("tab_passowrd_lineEdit_password_data_2"));
        tab_passowrd_lineEdit_password_data_2->setGeometry(QRect(0, 180, 421, 31));
        tab_passowrd_lineEdit_password_data_2->setMinimumSize(QSize(0, 30));
        tab_passowrd_lineEdit_password_data_2->setFont(font);
        tab_passowrd_lineEdit_password_data_2->setStyleSheet(QLatin1String("background-color: rgb(25, 25, 25, 155);\n"
"border: 1px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding-left:10px;\n"
"padding-right:10px;"));
        tab_passowrd_lineEdit_password_data_2->setEchoMode(QLineEdit::Password);
        label_user_ssh_2 = new QLabel(tab_2);
        label_user_ssh_2->setObjectName(QStringLiteral("label_user_ssh_2"));
        label_user_ssh_2->setGeometry(QRect(0, 80, 39, 30));
        label_user_ssh_2->setFont(font);
        tab_passowrd_label_password_2 = new QLabel(tab_2);
        tab_passowrd_label_password_2->setObjectName(QStringLiteral("tab_passowrd_label_password_2"));
        tab_passowrd_label_password_2->setGeometry(QRect(0, 150, 39, 30));
        tab_passowrd_label_password_2->setFont(font);
        horizontalLayoutWidget = new QWidget(tab_2);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 250, 181, 31));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        tab_passowrd_label_password_3 = new QLabel(horizontalLayoutWidget);
        tab_passowrd_label_password_3->setObjectName(QStringLiteral("tab_passowrd_label_password_3"));
        tab_passowrd_label_password_3->setFont(font);

        horizontalLayout_4->addWidget(tab_passowrd_label_password_3);

        comboBox = new QComboBox(horizontalLayoutWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setMinimumSize(QSize(120, 26));
        comboBox->setMaximumSize(QSize(120, 26));
        comboBox->setFont(font1);

        horizontalLayout_4->addWidget(comboBox);

        tab_passowrd_checkBox_remember_password_3 = new QCheckBox(tab_2);
        tab_passowrd_checkBox_remember_password_3->setObjectName(QStringLiteral("tab_passowrd_checkBox_remember_password_3"));
        tab_passowrd_checkBox_remember_password_3->setGeometry(QRect(200, 250, 49, 31));
        tab_passowrd_checkBox_remember_password_3->setFont(font1);
        tab_passowrd_checkBox_remember_password_3->setChecked(false);
        widget_dynamic_title_label_3 = new QLabel(tab_2);
        widget_dynamic_title_label_3->setObjectName(QStringLiteral("widget_dynamic_title_label_3"));
        widget_dynamic_title_label_3->setGeometry(QRect(0, 290, 400, 25));
        widget_dynamic_title_label_3->setMinimumSize(QSize(100, 25));
        widget_dynamic_title_label_3->setMaximumSize(QSize(400, 16777215));
        widget_dynamic_title_label_3->setFont(font4);
        widget_dynamic_title_label_3->setStyleSheet(QStringLiteral("color: rgba(223, 223, 223, 150);"));
        tabWidget->addTab(tab_2, QString());
        lineEdit_port_ssh_data_3->raise();
        label_port_ssh_3->raise();
        lineEdit_host_ssh_data_3->raise();
        label_host_ssh_3->raise();
        lineEdit_user_ssh_data_2->raise();
        tab_passowrd_checkBox_remember_password_2->raise();
        tab_passowrd_lineEdit_password_data_2->raise();
        label_user_ssh_2->raise();
        tab_passowrd_label_password_2->raise();
        tab_passowrd_toolButton_show_2->raise();
        horizontalLayoutWidget->raise();
        tab_passowrd_checkBox_remember_password_3->raise();
        widget_dynamic_title_label_3->raise();
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        lineEdit_port_ssh_data_2 = new QLineEdit(tab_3);
        lineEdit_port_ssh_data_2->setObjectName(QStringLiteral("lineEdit_port_ssh_data_2"));
        lineEdit_port_ssh_data_2->setGeometry(QRect(340, 40, 81, 30));
        lineEdit_port_ssh_data_2->setMinimumSize(QSize(0, 30));
        lineEdit_port_ssh_data_2->setFont(font);
        lineEdit_port_ssh_data_2->setStyleSheet(QLatin1String("background-color: rgb(25, 25, 25, 155);\n"
"border: 1px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding-left:10px;\n"
"padding-right:10px;"));
        label_port_ssh_2 = new QLabel(tab_3);
        label_port_ssh_2->setObjectName(QStringLiteral("label_port_ssh_2"));
        label_port_ssh_2->setGeometry(QRect(340, 10, 39, 30));
        label_port_ssh_2->setFont(font);
        lineEdit_host_ssh_data_2 = new QLineEdit(tab_3);
        lineEdit_host_ssh_data_2->setObjectName(QStringLiteral("lineEdit_host_ssh_data_2"));
        lineEdit_host_ssh_data_2->setGeometry(QRect(0, 40, 301, 30));
        lineEdit_host_ssh_data_2->setMinimumSize(QSize(0, 30));
        lineEdit_host_ssh_data_2->setFont(font);
        lineEdit_host_ssh_data_2->setStyleSheet(QLatin1String("background-color: rgb(25, 25, 25, 155);\n"
"border: 1px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding-left:10px;\n"
"padding-right:10px;"));
        label_host_ssh_2 = new QLabel(tab_3);
        label_host_ssh_2->setObjectName(QStringLiteral("label_host_ssh_2"));
        label_host_ssh_2->setGeometry(QRect(0, 10, 39, 30));
        label_host_ssh_2->setFont(font);
        widget_dynamic_title_label_2 = new QLabel(tab_3);
        widget_dynamic_title_label_2->setObjectName(QStringLiteral("widget_dynamic_title_label_2"));
        widget_dynamic_title_label_2->setGeometry(QRect(0, 90, 300, 25));
        widget_dynamic_title_label_2->setMinimumSize(QSize(100, 25));
        widget_dynamic_title_label_2->setMaximumSize(QSize(300, 16777215));
        widget_dynamic_title_label_2->setFont(font4);
        widget_dynamic_title_label_2->setStyleSheet(QStringLiteral("color: rgba(223, 223, 223, 150);"));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        tabWidget->addTab(tab_4, QString());

        verticalLayout_4->addWidget(tabWidget);


        horizontalLayout_6->addWidget(widget_body_right);


        retranslateUi(createconnect);

        stackedWidget->setCurrentIndex(1);
        tabWidget->setCurrentIndex(1);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(createconnect);
    } // setupUi

    void retranslateUi(QWidget *createconnect)
    {
        createconnect->setWindowTitle(QApplication::translate("createconnect", "\346\226\260\345\273\272\347\273\210\347\253\257", nullptr));
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
        widget_bottom_toolButton_connect->setText(QApplication::translate("createconnect", "\350\277\236\346\216\245", nullptr));
        widget_bottom_toolButton_save->setText(QApplication::translate("createconnect", "\344\277\235\345\255\230", nullptr));
        widget_bottom_toolButton_close->setText(QApplication::translate("createconnect", "\345\217\226\346\266\210", nullptr));
        widget_name_label_name->setText(QApplication::translate("createconnect", "\345\220\215\347\247\260", nullptr));
        widget_name_lineEdit_name_data->setText(QString());
        widget_name_lineEdit_name_data->setPlaceholderText(QApplication::translate("createconnect", "\347\273\210\347\253\257\350\277\236\346\216\245", nullptr));
        widget_group_label_group->setText(QApplication::translate("createconnect", "\345\210\206\347\273\204", nullptr));
        widget_group_lineEdit_group_data->setText(QString());
        widget_group_lineEdit_group_data->setPlaceholderText(QApplication::translate("createconnect", "\345\205\250\351\203\250", nullptr));
        widget_group_label_group_2->setText(QApplication::translate("createconnect", "\345\244\207\346\263\250", nullptr));
        widget_group_lineEdit_group_data_2->setText(QApplication::translate("createconnect", "\345\230\273\345\230\273\345\230\273\345\230\273\345\230\273\345\230\273\345\230\273\345\230\273\345\230\273\345\230\273\345\230\273\345\230\273\345\230\273", nullptr));
        widget_group_lineEdit_group_data_2->setPlaceholderText(QApplication::translate("createconnect", "\345\205\250\351\203\250", nullptr));
        widget_color_label_color->setText(QApplication::translate("createconnect", "\346\240\207\351\242\230\351\242\234\350\211\262", nullptr));
        widget_color_toolButton_color_data->setText(QApplication::translate("createconnect", "#000000", nullptr));
        widget_dynamic_title_checkBox->setText(QApplication::translate("createconnect", "\344\275\277\347\224\250\345\212\250\346\200\201\346\240\207\351\242\230", nullptr));
        widget_dynamic_title_label->setText(QApplication::translate("createconnect", "\347\246\201\347\224\250\345\220\216\357\274\214\346\240\207\351\242\230\346\240\217\345\260\206\344\270\272\"Fdog-kit\"", nullptr));
        lineEdit_host_ssh_data->setText(QApplication::translate("createconnect", "172.16.8.154", nullptr));
        lineEdit_host_ssh_data->setPlaceholderText(QApplication::translate("createconnect", "127.0.0.1", nullptr));
        label_host_ssh->setText(QApplication::translate("createconnect", "\344\270\273\346\234\272", nullptr));
        label_port_ssh->setText(QApplication::translate("createconnect", "\347\253\257\345\217\243", nullptr));
        lineEdit_port_ssh_data->setText(QApplication::translate("createconnect", "22", nullptr));
        lineEdit_port_ssh_data->setPlaceholderText(QApplication::translate("createconnect", "22", nullptr));
        label_user_ssh->setText(QApplication::translate("createconnect", "\347\224\250\346\210\267\345\220\215", nullptr));
        lineEdit_user_ssh_data->setText(QString());
        lineEdit_user_ssh_data->setPlaceholderText(QApplication::translate("createconnect", "root", nullptr));
        tab_passowrd_lineEdit_password_data->setText(QApplication::translate("createconnect", "Linkdood@123456", nullptr));
        tab_passowrd_label_password->setText(QApplication::translate("createconnect", "\345\257\206\347\240\201", nullptr));
        tab_passowrd_checkBox_remember_password->setText(QApplication::translate("createconnect", "\350\256\260\344\275\217\345\257\206\347\240\201", nullptr));
        tab_passowrd_toolButton_show->setText(QApplication::translate("createconnect", "\345\217\226\346\266\210", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_passowrd), QApplication::translate("createconnect", "   \345\257\206\347\240\201   ", nullptr));
        label_zk_host_5->setText(QApplication::translate("createconnect", "\347\247\201\351\222\245", nullptr));
        lineEdit_zk_port_8->setText(QApplication::translate("createconnect", "******", nullptr));
        toolButton_4->setText(QApplication::translate("createconnect", "\346\265\217\350\247\210...", nullptr));
        checkBox_2->setText(QApplication::translate("createconnect", "\350\256\260\344\275\217\347\247\201\351\222\245", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_secretkey), QApplication::translate("createconnect", "   \345\205\254\351\222\245   ", nullptr));
        toolButton_6->setText(QApplication::translate("createconnect", "\345\217\226\346\266\210", nullptr));
        checkBox_remember_password_2->setText(QApplication::translate("createconnect", "\350\256\260\344\275\217\345\257\206\347\240\201", nullptr));
        lineEdit_password_data_2->setText(QApplication::translate("createconnect", "******", nullptr));
        label_password_2->setText(QApplication::translate("createconnect", "\345\257\206\347\240\201", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_keyboard), QApplication::translate("createconnect", "   Keyboard Interactive   ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("createconnect", "   ssh   ", nullptr));
        lineEdit_port_ssh_data_3->setText(QApplication::translate("createconnect", "22", nullptr));
        lineEdit_port_ssh_data_3->setPlaceholderText(QApplication::translate("createconnect", "22", nullptr));
        label_port_ssh_3->setText(QApplication::translate("createconnect", "\347\253\257\345\217\243", nullptr));
        lineEdit_host_ssh_data_3->setText(QApplication::translate("createconnect", "172.16.8.154", nullptr));
        lineEdit_host_ssh_data_3->setPlaceholderText(QApplication::translate("createconnect", "127.0.0.1", nullptr));
        label_host_ssh_3->setText(QApplication::translate("createconnect", "\344\270\273\346\234\272", nullptr));
        tab_passowrd_toolButton_show_2->setText(QApplication::translate("createconnect", "\345\217\226\346\266\210", nullptr));
        lineEdit_user_ssh_data_2->setText(QString());
        lineEdit_user_ssh_data_2->setPlaceholderText(QApplication::translate("createconnect", "root", nullptr));
        tab_passowrd_checkBox_remember_password_2->setText(QApplication::translate("createconnect", "\350\256\260\344\275\217\345\257\206\347\240\201", nullptr));
        tab_passowrd_lineEdit_password_data_2->setText(QApplication::translate("createconnect", "Linkdood@123456", nullptr));
        label_user_ssh_2->setText(QApplication::translate("createconnect", "\347\224\250\346\210\267\345\220\215", nullptr));
        tab_passowrd_label_password_2->setText(QApplication::translate("createconnect", "\345\257\206\347\240\201", nullptr));
        tab_passowrd_label_password_3->setText(QApplication::translate("createconnect", "\345\210\206\345\210\253\347\216\207\357\274\232", nullptr));
        comboBox->setItemText(0, QApplication::translate("createconnect", "640 x 480", nullptr));
        comboBox->setItemText(1, QApplication::translate("createconnect", "800 x 600", nullptr));
        comboBox->setItemText(2, QApplication::translate("createconnect", "1024 x 768", nullptr));
        comboBox->setItemText(3, QApplication::translate("createconnect", "1280 x 1024", nullptr));
        comboBox->setItemText(4, QApplication::translate("createconnect", "1600 x 1200", nullptr));
        comboBox->setItemText(5, QApplication::translate("createconnect", "1920 x 1080", nullptr));
        comboBox->setItemText(6, QApplication::translate("createconnect", "1920 x 1020", nullptr));
        comboBox->setItemText(7, QApplication::translate("createconnect", "1560 x 1440", nullptr));
        comboBox->setItemText(8, QApplication::translate("createconnect", "\350\207\252\345\256\232\344\271\211", nullptr));

        tab_passowrd_checkBox_remember_password_3->setText(QApplication::translate("createconnect", "\345\205\250\345\261\217", nullptr));
        widget_dynamic_title_label_3->setText(QApplication::translate("createconnect", "\345\260\206\351\200\232\350\277\207windows\350\277\234\347\250\213\346\241\214\351\235\242\350\277\236\346\216\245\357\274\214\347\241\256\350\256\244\345\257\271\346\226\271\347\224\265\350\204\221\345\205\201\350\256\270\350\277\234\347\250\213\345\215\217\345\212\251", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("createconnect", "   windows   ", nullptr));
        lineEdit_port_ssh_data_2->setText(QApplication::translate("createconnect", "11100", nullptr));
        lineEdit_port_ssh_data_2->setPlaceholderText(QApplication::translate("createconnect", "22", nullptr));
        label_port_ssh_2->setText(QApplication::translate("createconnect", "\347\253\257\345\217\243", nullptr));
        lineEdit_host_ssh_data_2->setText(QApplication::translate("createconnect", "172.16.8.153", nullptr));
        lineEdit_host_ssh_data_2->setPlaceholderText(QApplication::translate("createconnect", "127.0.0.1", nullptr));
        label_host_ssh_2->setText(QApplication::translate("createconnect", "\344\270\273\346\234\272", nullptr));
        widget_dynamic_title_label_2->setText(QApplication::translate("createconnect", "\345\260\206\345\210\233\345\273\272\345\217\257\350\247\206\345\214\226zk\344\277\241\346\201\257\347\225\214\351\235\242\357\274\214\350\277\233\350\241\214\345\277\253\351\200\237\344\276\277\346\215\267\347\232\204\345\242\236\345\210\240\346\224\271\346\237\245", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("createconnect", "   zookeeper   ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("createconnect", "   Redis   ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class createconnect: public Ui_createconnect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATECONNECT_H
