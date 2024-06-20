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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_createconnect
{
public:
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout_8;
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
    QWidget *widget_remark;
    QVBoxLayout *verticalLayout_5;
    QLabel *widget_remark_label_remark;
    QLineEdit *widget_remark_lineEdit_remark_data;
    QWidget *widget;
    QVBoxLayout *verticalLayout_7;
    QWidget *widget_color;
    QHBoxLayout *horizontalLayout_7;
    QLabel *widget_color_label_color;
    QToolButton *toolButton_color;
    QSpacerItem *widget_color_horizontalSpacer_color;
    QWidget *widget_transparent;
    QHBoxLayout *horizontalLayout_5;
    QLabel *widget_transparent_label_color;
    QLineEdit *lineEdit_transparent;
    QSpacerItem *widget_transparent_horizontalSpacer_color;
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
    QTabWidget *tabWidget_password;
    QWidget *tab_passowrd;
    QLineEdit *tab_passowrd_lineEdit_password_data;
    QLabel *tab_passowrd_label_password;
    QCheckBox *tab_passowrd_checkBox_remember_password;
    QToolButton *tab_passowrd_toolButton_show;
    QWidget *tab_secretkey;
    QLabel *label_zk_host_5;
    QLineEdit *lineEdit_zk_port_8;
    QToolButton *toolButton_browse;
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
    QWidget *horizontalWidget;
    QHBoxLayout *horizontalLayout_4;
    QLabel *tab_passowrd_label_password_3;
    QComboBox *comboBox;
    QCheckBox *tab_passowrd_checkBox_remember_password_3;
    QLabel *widget_dynamic_title_label_3;
    QLineEdit *lineEdit_port_ssh_data_4;
    QLineEdit *lineEdit_port_ssh_data_5;
    QWidget *tab_3;
    QLineEdit *lineEdit_port_zk_data;
    QLabel *label_port_ssh_2;
    QLineEdit *lineEdit_host_zk_data;
    QLabel *label_host_ssh_2;
    QLabel *widget_dynamic_title_label_2;
    QWidget *tab_4;
    QWidget *widget_bottom;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *widget_bottom_horizontalSpacer_left;
    QToolButton *widget_bottom_toolButton_connect;
    QToolButton *widget_bottom_toolButton_save;
    QToolButton *widget_bottom_toolButton_close;
    QSpacerItem *widget_bottom_horizontalSpacer_right;

    void setupUi(QWidget *createconnect)
    {
        if (createconnect->objectName().isEmpty())
            createconnect->setObjectName(QStringLiteral("createconnect"));
        createconnect->resize(699, 473);
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
        icon.addFile(QStringLiteral(":/lib/icon9.png"), QSize(), QIcon::Normal, QIcon::Off);
        createconnect->setWindowIcon(icon);
        createconnect->setStyleSheet(QStringLiteral(""));
        horizontalLayout = new QHBoxLayout(createconnect);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(createconnect);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setStyleSheet(QLatin1String("#frame{ \n"
"border-image: url(:/lib/back1.png);\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_8 = new QVBoxLayout(frame);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 9);
        widget_body = new QWidget(frame);
        widget_body->setObjectName(QStringLiteral("widget_body"));
        widget_body->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        horizontalLayout_6 = new QHBoxLayout(widget_body);
        horizontalLayout_6->setSpacing(20);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(15, 30, 15, 0);
        widget_body_left = new QWidget(widget_body);
        widget_body_left->setObjectName(QStringLiteral("widget_body_left"));
        widget_body_left->setMinimumSize(QSize(190, 0));
        widget_body_left->setMaximumSize(QSize(190, 16777215));
        verticalLayout_3 = new QVBoxLayout(widget_body_left);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(9, 3, 1, 0);
        widget_name = new QWidget(widget_body_left);
        widget_name->setObjectName(QStringLiteral("widget_name"));
        widget_name->setMinimumSize(QSize(180, 70));
        widget_name->setMaximumSize(QSize(180, 70));
        widget_name->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(widget_name);
        verticalLayout->setSpacing(5);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 4);
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
        widget_group->setMinimumSize(QSize(180, 70));
        widget_group->setMaximumSize(QSize(180, 70));
        widget_group->setStyleSheet(QStringLiteral(""));
        verticalLayout_2 = new QVBoxLayout(widget_group);
        verticalLayout_2->setSpacing(5);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 1);
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

        widget_remark = new QWidget(widget_body_left);
        widget_remark->setObjectName(QStringLiteral("widget_remark"));
        widget_remark->setMinimumSize(QSize(180, 110));
        widget_remark->setMaximumSize(QSize(180, 110));
        widget_remark->setStyleSheet(QStringLiteral(""));
        verticalLayout_5 = new QVBoxLayout(widget_remark);
        verticalLayout_5->setSpacing(5);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 4);
        widget_remark_label_remark = new QLabel(widget_remark);
        widget_remark_label_remark->setObjectName(QStringLiteral("widget_remark_label_remark"));
        widget_remark_label_remark->setMinimumSize(QSize(0, 20));
        widget_remark_label_remark->setMaximumSize(QSize(16777215, 20));
        widget_remark_label_remark->setFont(font);

        verticalLayout_5->addWidget(widget_remark_label_remark);

        widget_remark_lineEdit_remark_data = new QLineEdit(widget_remark);
        widget_remark_lineEdit_remark_data->setObjectName(QStringLiteral("widget_remark_lineEdit_remark_data"));
        widget_remark_lineEdit_remark_data->setMinimumSize(QSize(0, 60));
        widget_remark_lineEdit_remark_data->setMaximumSize(QSize(16777215, 60));
        widget_remark_lineEdit_remark_data->setFont(font);
        widget_remark_lineEdit_remark_data->setStyleSheet(QLatin1String("background-color: rgb(25, 25, 25, 155);\n"
"border: 1px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding:10px;"));
        widget_remark_lineEdit_remark_data->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout_5->addWidget(widget_remark_lineEdit_remark_data);


        verticalLayout_3->addWidget(widget_remark);

        widget = new QWidget(widget_body_left);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(0, 80));
        widget->setMaximumSize(QSize(16777215, 80));
        verticalLayout_7 = new QVBoxLayout(widget);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        widget_color = new QWidget(widget);
        widget_color->setObjectName(QStringLiteral("widget_color"));
        widget_color->setMinimumSize(QSize(200, 30));
        widget_color->setMaximumSize(QSize(200, 30));
        horizontalLayout_7 = new QHBoxLayout(widget_color);
        horizontalLayout_7->setSpacing(5);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        widget_color_label_color = new QLabel(widget_color);
        widget_color_label_color->setObjectName(QStringLiteral("widget_color_label_color"));
        widget_color_label_color->setMinimumSize(QSize(85, 0));
        widget_color_label_color->setMaximumSize(QSize(85, 16777215));
        widget_color_label_color->setFont(font);

        horizontalLayout_7->addWidget(widget_color_label_color);

        toolButton_color = new QToolButton(widget_color);
        toolButton_color->setObjectName(QStringLiteral("toolButton_color"));
        toolButton_color->setMinimumSize(QSize(90, 30));
        toolButton_color->setMaximumSize(QSize(90, 30));
        toolButton_color->setStyleSheet(QLatin1String("QToolButton {\n"
"	color: rgb(255, 255, 255);\n"
"	\n"
"	background-color: rgb(48, 10, 36);\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QToolButton::menu-indicator { \n"
"	image: None;\n"
"}"));

        horizontalLayout_7->addWidget(toolButton_color);

        widget_color_horizontalSpacer_color = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(widget_color_horizontalSpacer_color);


        verticalLayout_7->addWidget(widget_color);

        widget_transparent = new QWidget(widget);
        widget_transparent->setObjectName(QStringLiteral("widget_transparent"));
        widget_transparent->setMinimumSize(QSize(200, 30));
        widget_transparent->setMaximumSize(QSize(200, 30));
        horizontalLayout_5 = new QHBoxLayout(widget_transparent);
        horizontalLayout_5->setSpacing(5);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        widget_transparent_label_color = new QLabel(widget_transparent);
        widget_transparent_label_color->setObjectName(QStringLiteral("widget_transparent_label_color"));
        widget_transparent_label_color->setMinimumSize(QSize(85, 0));
        widget_transparent_label_color->setMaximumSize(QSize(85, 16777215));
        widget_transparent_label_color->setFont(font);

        horizontalLayout_5->addWidget(widget_transparent_label_color);

        lineEdit_transparent = new QLineEdit(widget_transparent);
        lineEdit_transparent->setObjectName(QStringLiteral("lineEdit_transparent"));
        lineEdit_transparent->setMinimumSize(QSize(90, 30));
        lineEdit_transparent->setMaximumSize(QSize(90, 30));
        QFont font1;
        font1.setFamily(QStringLiteral("OPPOSans"));
        font1.setPointSize(10);
        lineEdit_transparent->setFont(font1);
        lineEdit_transparent->setStyleSheet(QLatin1String("background-color: rgb(25, 25, 25, 155);\n"
"border: 1px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding-left:10px;\n"
"padding-right:10px;"));

        horizontalLayout_5->addWidget(lineEdit_transparent);

        widget_transparent_horizontalSpacer_color = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(widget_transparent_horizontalSpacer_color);


        verticalLayout_7->addWidget(widget_transparent);


        verticalLayout_3->addWidget(widget);

        widget_dynamic_title = new QWidget(widget_body_left);
        widget_dynamic_title->setObjectName(QStringLiteral("widget_dynamic_title"));
        widget_dynamic_title->setMinimumSize(QSize(180, 50));
        widget_dynamic_title->setMaximumSize(QSize(180, 50));
        verticalLayout_6 = new QVBoxLayout(widget_dynamic_title);
        verticalLayout_6->setSpacing(5);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 6);
        widget_dynamic_title_checkBox = new QCheckBox(widget_dynamic_title);
        widget_dynamic_title_checkBox->setObjectName(QStringLiteral("widget_dynamic_title_checkBox"));
        QFont font2;
        font2.setFamily(QStringLiteral("OPPOSans B"));
        font2.setPointSize(10);
        font2.setStyleStrategy(QFont::PreferAntialias);
        widget_dynamic_title_checkBox->setFont(font2);
        widget_dynamic_title_checkBox->setContextMenuPolicy(Qt::DefaultContextMenu);
        widget_dynamic_title_checkBox->setStyleSheet(QLatin1String("QCheckBox::indicator{\n"
"                width:16px;\n"
"                height:16px;\n"
"           }\n"
"            QCheckBox::indicator::unchecked{\n"
"                image:url(:/lib/gouxuan2.png);\n"
"            }\n"
"            QCheckBox::indicator::checked{\n"
"                image:url(:/lib/gouxuan.png);\n"
"            }\n"
""));
        widget_dynamic_title_checkBox->setChecked(true);
        widget_dynamic_title_checkBox->setTristate(false);

        verticalLayout_6->addWidget(widget_dynamic_title_checkBox);

        widget_dynamic_title_label = new QLabel(widget_dynamic_title);
        widget_dynamic_title_label->setObjectName(QStringLiteral("widget_dynamic_title_label"));
        widget_dynamic_title_label->setMinimumSize(QSize(100, 25));
        widget_dynamic_title_label->setMaximumSize(QSize(180, 16777215));
        QFont font3;
        font3.setFamily(QStringLiteral("OPPOSans B"));
        font3.setPointSize(9);
        widget_dynamic_title_label->setFont(font3);
        widget_dynamic_title_label->setStyleSheet(QStringLiteral("color: rgba(223, 223, 223, 150);"));

        verticalLayout_6->addWidget(widget_dynamic_title_label);


        verticalLayout_3->addWidget(widget_dynamic_title);


        horizontalLayout_6->addWidget(widget_body_left);

        widget_body_right = new QWidget(widget_body);
        widget_body_right->setObjectName(QStringLiteral("widget_body_right"));
        widget_body_right->setStyleSheet(QLatin1String("QCheckBox::indicator{\n"
"                width:16px;\n"
"                height:16px;\n"
"           }\n"
"            QCheckBox::indicator::unchecked{\n"
"                image:url(:/lib/gouxuan2.png);\n"
"            }\n"
"            QCheckBox::indicator::checked{\n"
"                image:url(:/lib/gouxuan.png);\n"
"            }\n"
""));
        verticalLayout_4 = new QVBoxLayout(widget_body_right);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(-1, -1, -1, 0);
        tabWidget = new QTabWidget(widget_body_right);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QFont font4;
        font4.setFamily(QStringLiteral("OPPOSans B"));
        font4.setPointSize(10);
        font4.setBold(false);
        font4.setWeight(50);
        font4.setStyleStrategy(QFont::PreferAntialias);
        tabWidget->setFont(font4);
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
        tabWidget_password = new QTabWidget(tab);
        tabWidget_password->setObjectName(QStringLiteral("tabWidget_password"));
        tabWidget_password->setGeometry(QRect(0, 160, 431, 170));
        tabWidget_password->setFont(font2);
        tabWidget_password->setStyleSheet(QString::fromUtf8("\n"
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
        tab_passowrd_checkBox_remember_password->setGeometry(QRect(0, 80, 81, 16));
        tab_passowrd_checkBox_remember_password->setFont(font2);
        tab_passowrd_checkBox_remember_password->setStyleSheet(QStringLiteral(""));
        tab_passowrd_checkBox_remember_password->setChecked(true);
        tab_passowrd_toolButton_show = new QToolButton(tab_passowrd);
        tab_passowrd_toolButton_show->setObjectName(QStringLiteral("tab_passowrd_toolButton_show"));
        tab_passowrd_toolButton_show->setGeometry(QRect(380, 40, 40, 30));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tab_passowrd_toolButton_show->sizePolicy().hasHeightForWidth());
        tab_passowrd_toolButton_show->setSizePolicy(sizePolicy1);
        tab_passowrd_toolButton_show->setMinimumSize(QSize(30, 30));
        tab_passowrd_toolButton_show->setMaximumSize(QSize(40, 30));
        tab_passowrd_toolButton_show->setFont(font2);
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
        tabWidget_password->addTab(tab_passowrd, QString());
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
        lineEdit_zk_port_8->setEchoMode(QLineEdit::Normal);
        toolButton_browse = new QToolButton(tab_secretkey);
        toolButton_browse->setObjectName(QStringLiteral("toolButton_browse"));
        toolButton_browse->setGeometry(QRect(350, 40, 70, 30));
        sizePolicy1.setHeightForWidth(toolButton_browse->sizePolicy().hasHeightForWidth());
        toolButton_browse->setSizePolicy(sizePolicy1);
        toolButton_browse->setMinimumSize(QSize(70, 30));
        toolButton_browse->setMaximumSize(QSize(70, 30));
        toolButton_browse->setFont(font2);
        toolButton_browse->setStyleSheet(QLatin1String("QToolButton {\n"
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
        checkBox_2->setGeometry(QRect(0, 80, 81, 16));
        checkBox_2->setFont(font2);
        checkBox_2->setChecked(true);
        tabWidget_password->addTab(tab_secretkey, QString());
        tab_keyboard = new QWidget();
        tab_keyboard->setObjectName(QStringLiteral("tab_keyboard"));
        toolButton_6 = new QToolButton(tab_keyboard);
        toolButton_6->setObjectName(QStringLiteral("toolButton_6"));
        toolButton_6->setGeometry(QRect(380, 40, 40, 30));
        sizePolicy1.setHeightForWidth(toolButton_6->sizePolicy().hasHeightForWidth());
        toolButton_6->setSizePolicy(sizePolicy1);
        toolButton_6->setMinimumSize(QSize(30, 30));
        toolButton_6->setMaximumSize(QSize(40, 30));
        toolButton_6->setFont(font2);
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
        checkBox_remember_password_2->setFont(font2);
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
        lineEdit_password_data_2->setEchoMode(QLineEdit::Password);
        label_password_2 = new QLabel(tab_keyboard);
        label_password_2->setObjectName(QStringLiteral("label_password_2"));
        label_password_2->setGeometry(QRect(0, 10, 39, 30));
        label_password_2->setFont(font);
        tabWidget_password->addTab(tab_keyboard, QString());
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
        tab_passowrd_toolButton_show_2->setFont(font2);
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
        tab_passowrd_checkBox_remember_password_2->setGeometry(QRect(0, 220, 81, 16));
        tab_passowrd_checkBox_remember_password_2->setFont(font2);
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
        horizontalWidget = new QWidget(tab_2);
        horizontalWidget->setObjectName(QStringLiteral("horizontalWidget"));
        horizontalWidget->setGeometry(QRect(0, 250, 181, 31));
        horizontalLayout_4 = new QHBoxLayout(horizontalWidget);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        tab_passowrd_label_password_3 = new QLabel(horizontalWidget);
        tab_passowrd_label_password_3->setObjectName(QStringLiteral("tab_passowrd_label_password_3"));
        tab_passowrd_label_password_3->setFont(font);

        horizontalLayout_4->addWidget(tab_passowrd_label_password_3);

        comboBox = new QComboBox(horizontalWidget);
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
        comboBox->setMinimumSize(QSize(0, 28));
        comboBox->setMaximumSize(QSize(120, 28));
        comboBox->setFont(font2);
        comboBox->setStyleSheet(QLatin1String("QComboBox{\n"
"	color:#ffffff;\n"
"	border:1px solid rgb(13, 13, 13);\n"
"	border-radius:3px;\n"
"	background:transparent;\n"
"}\n"
"QComboBox:disabled{\n"
"	border:1px solid gray;\n"
"	color:gray;\n"
"}\n"
"\n"
"QComboBox::drop-down{\n"
"	background:transparent;\n"
"}\n"
"QComboBox::down-arrow{\n"
"	border-image: url(:/lib/up.png);\n"
"    width:20px;\n"
"	height:20px;\n"
"}\n"
"\n"
"\n"
"QComboBox::down-arrow:enabled{\n"
"	color:#52DCFE;\n"
"}\n"
"QComboBox QAbstractItemView{\n"
"	outline:0px solid gray;\n"
"	border:1px solid #1e2d36;\n"
"	color:#ffffff;\n"
"	background-color:#1e2d36;\n"
"	selection-background-color:#52DCFE;\n"
"}"));

        horizontalLayout_4->addWidget(comboBox);

        tab_passowrd_checkBox_remember_password_3 = new QCheckBox(tab_2);
        tab_passowrd_checkBox_remember_password_3->setObjectName(QStringLiteral("tab_passowrd_checkBox_remember_password_3"));
        tab_passowrd_checkBox_remember_password_3->setGeometry(QRect(348, 250, 61, 31));
        tab_passowrd_checkBox_remember_password_3->setFont(font2);
        tab_passowrd_checkBox_remember_password_3->setChecked(false);
        widget_dynamic_title_label_3 = new QLabel(tab_2);
        widget_dynamic_title_label_3->setObjectName(QStringLiteral("widget_dynamic_title_label_3"));
        widget_dynamic_title_label_3->setGeometry(QRect(0, 290, 400, 25));
        widget_dynamic_title_label_3->setMinimumSize(QSize(100, 25));
        widget_dynamic_title_label_3->setMaximumSize(QSize(400, 16777215));
        widget_dynamic_title_label_3->setFont(font3);
        widget_dynamic_title_label_3->setStyleSheet(QStringLiteral("color: rgba(223, 223, 223, 150);"));
        lineEdit_port_ssh_data_4 = new QLineEdit(tab_2);
        lineEdit_port_ssh_data_4->setObjectName(QStringLiteral("lineEdit_port_ssh_data_4"));
        lineEdit_port_ssh_data_4->setGeometry(QRect(200, 250, 61, 30));
        lineEdit_port_ssh_data_4->setMinimumSize(QSize(0, 30));
        lineEdit_port_ssh_data_4->setFont(font);
        lineEdit_port_ssh_data_4->setStyleSheet(QLatin1String("background-color: rgb(25, 25, 25, 155);\n"
"border: 1px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding-left:10px;\n"
"padding-right:10px;"));
        lineEdit_port_ssh_data_5 = new QLineEdit(tab_2);
        lineEdit_port_ssh_data_5->setObjectName(QStringLiteral("lineEdit_port_ssh_data_5"));
        lineEdit_port_ssh_data_5->setGeometry(QRect(270, 250, 61, 30));
        lineEdit_port_ssh_data_5->setMinimumSize(QSize(0, 30));
        lineEdit_port_ssh_data_5->setFont(font);
        lineEdit_port_ssh_data_5->setStyleSheet(QLatin1String("background-color: rgb(25, 25, 25, 155);\n"
"border: 1px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding-left:10px;\n"
"padding-right:10px;"));
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
        horizontalWidget->raise();
        tab_passowrd_checkBox_remember_password_3->raise();
        widget_dynamic_title_label_3->raise();
        lineEdit_port_ssh_data_4->raise();
        lineEdit_port_ssh_data_5->raise();
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        lineEdit_port_zk_data = new QLineEdit(tab_3);
        lineEdit_port_zk_data->setObjectName(QStringLiteral("lineEdit_port_zk_data"));
        lineEdit_port_zk_data->setGeometry(QRect(340, 40, 81, 30));
        lineEdit_port_zk_data->setMinimumSize(QSize(0, 30));
        lineEdit_port_zk_data->setFont(font);
        lineEdit_port_zk_data->setStyleSheet(QLatin1String("background-color: rgb(25, 25, 25, 155);\n"
"border: 1px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding-left:10px;\n"
"padding-right:10px;"));
        label_port_ssh_2 = new QLabel(tab_3);
        label_port_ssh_2->setObjectName(QStringLiteral("label_port_ssh_2"));
        label_port_ssh_2->setGeometry(QRect(340, 10, 39, 30));
        label_port_ssh_2->setFont(font);
        lineEdit_host_zk_data = new QLineEdit(tab_3);
        lineEdit_host_zk_data->setObjectName(QStringLiteral("lineEdit_host_zk_data"));
        lineEdit_host_zk_data->setGeometry(QRect(0, 40, 301, 30));
        lineEdit_host_zk_data->setMinimumSize(QSize(0, 30));
        lineEdit_host_zk_data->setFont(font);
        lineEdit_host_zk_data->setStyleSheet(QLatin1String("background-color: rgb(25, 25, 25, 155);\n"
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
        widget_dynamic_title_label_2->setFont(font3);
        widget_dynamic_title_label_2->setStyleSheet(QStringLiteral("color: rgba(223, 223, 223, 150);"));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        tabWidget->addTab(tab_4, QString());

        verticalLayout_4->addWidget(tabWidget);

        widget_bottom = new QWidget(widget_body_right);
        widget_bottom->setObjectName(QStringLiteral("widget_bottom"));
        widget_bottom->setMinimumSize(QSize(0, 40));
        widget_bottom->setMaximumSize(QSize(16777215, 40));
        widget_bottom->setStyleSheet(QLatin1String("\n"
"color: rgb(255, 255, 255);"));
        horizontalLayout_3 = new QHBoxLayout(widget_bottom);
        horizontalLayout_3->setSpacing(10);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        widget_bottom_horizontalSpacer_left = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(widget_bottom_horizontalSpacer_left);

        widget_bottom_toolButton_connect = new QToolButton(widget_bottom);
        widget_bottom_toolButton_connect->setObjectName(QStringLiteral("widget_bottom_toolButton_connect"));
        sizePolicy1.setHeightForWidth(widget_bottom_toolButton_connect->sizePolicy().hasHeightForWidth());
        widget_bottom_toolButton_connect->setSizePolicy(sizePolicy1);
        widget_bottom_toolButton_connect->setMinimumSize(QSize(70, 30));
        widget_bottom_toolButton_connect->setMaximumSize(QSize(70, 30));
        widget_bottom_toolButton_connect->setFont(font2);
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
        widget_bottom_toolButton_save->setMinimumSize(QSize(70, 30));
        widget_bottom_toolButton_save->setMaximumSize(QSize(70, 30));
        widget_bottom_toolButton_save->setFont(font4);
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
        widget_bottom_toolButton_close->setMinimumSize(QSize(70, 30));
        widget_bottom_toolButton_close->setMaximumSize(QSize(70, 30));
        widget_bottom_toolButton_close->setFont(font2);
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

        widget_bottom_horizontalSpacer_right = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(widget_bottom_horizontalSpacer_right);


        verticalLayout_4->addWidget(widget_bottom);


        horizontalLayout_6->addWidget(widget_body_right);


        verticalLayout_8->addWidget(widget_body);


        horizontalLayout->addWidget(frame);


        retranslateUi(createconnect);

        tabWidget->setCurrentIndex(0);
        tabWidget_password->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(createconnect);
    } // setupUi

    void retranslateUi(QWidget *createconnect)
    {
        createconnect->setWindowTitle(QApplication::translate("createconnect", "\346\226\260\345\273\272\347\273\210\347\253\257", nullptr));
        widget_name_label_name->setText(QApplication::translate("createconnect", "\345\220\215\347\247\260", nullptr));
        widget_name_lineEdit_name_data->setText(QString());
        widget_name_lineEdit_name_data->setPlaceholderText(QApplication::translate("createconnect", "\347\273\210\347\253\257\350\277\236\346\216\245", nullptr));
        widget_group_label_group->setText(QApplication::translate("createconnect", "\345\210\206\347\273\204", nullptr));
        widget_group_lineEdit_group_data->setText(QString());
        widget_group_lineEdit_group_data->setPlaceholderText(QApplication::translate("createconnect", "\351\273\230\350\256\244", nullptr));
        widget_remark_label_remark->setText(QApplication::translate("createconnect", "\345\244\207\346\263\250", nullptr));
        widget_remark_lineEdit_remark_data->setText(QString());
        widget_remark_lineEdit_remark_data->setPlaceholderText(QString());
        widget_color_label_color->setText(QApplication::translate("createconnect", "\347\252\227\345\217\243\351\242\234\350\211\262", nullptr));
        toolButton_color->setText(QString());
        widget_transparent_label_color->setText(QApplication::translate("createconnect", "\347\252\227\345\217\243\351\200\217\346\230\216\345\272\246", nullptr));
        lineEdit_transparent->setText(QApplication::translate("createconnect", "100", nullptr));
        widget_dynamic_title_checkBox->setText(QApplication::translate("createconnect", "\344\275\277\347\224\250\351\273\230\350\256\244\345\217\202\346\225\260", nullptr));
        widget_dynamic_title_label->setText(QApplication::translate("createconnect", "\345\213\276\351\200\211\345\220\216\357\274\214\344\275\277\347\224\250\351\273\230\350\256\244\345\217\202\346\225\260\345\210\233\345\273\272\347\273\210\347\253\257", nullptr));
        lineEdit_host_ssh_data->setText(QString());
        lineEdit_host_ssh_data->setPlaceholderText(QApplication::translate("createconnect", "127.0.0.1", nullptr));
        label_host_ssh->setText(QApplication::translate("createconnect", "\344\270\273\346\234\272", nullptr));
        label_port_ssh->setText(QApplication::translate("createconnect", "\347\253\257\345\217\243", nullptr));
        lineEdit_port_ssh_data->setText(QString());
        lineEdit_port_ssh_data->setPlaceholderText(QApplication::translate("createconnect", "22", nullptr));
        label_user_ssh->setText(QApplication::translate("createconnect", "\347\224\250\346\210\267\345\220\215", nullptr));
        lineEdit_user_ssh_data->setText(QString());
        lineEdit_user_ssh_data->setPlaceholderText(QApplication::translate("createconnect", "root", nullptr));
        tab_passowrd_lineEdit_password_data->setText(QString());
        tab_passowrd_label_password->setText(QApplication::translate("createconnect", "\345\257\206\347\240\201", nullptr));
        tab_passowrd_checkBox_remember_password->setText(QApplication::translate("createconnect", "\350\256\260\344\275\217\345\257\206\347\240\201", nullptr));
        tab_passowrd_toolButton_show->setText(QApplication::translate("createconnect", "\345\217\226\346\266\210", nullptr));
        tabWidget_password->setTabText(tabWidget_password->indexOf(tab_passowrd), QApplication::translate("createconnect", "   \345\257\206\347\240\201   ", nullptr));
        label_zk_host_5->setText(QApplication::translate("createconnect", "\347\247\201\351\222\245", nullptr));
        lineEdit_zk_port_8->setText(QString());
        toolButton_browse->setText(QApplication::translate("createconnect", "\346\265\217\350\247\210...", nullptr));
        checkBox_2->setText(QApplication::translate("createconnect", "\350\256\260\344\275\217\347\247\201\351\222\245", nullptr));
        tabWidget_password->setTabText(tabWidget_password->indexOf(tab_secretkey), QApplication::translate("createconnect", "   \345\205\254\351\222\245   ", nullptr));
        toolButton_6->setText(QApplication::translate("createconnect", "\345\217\226\346\266\210", nullptr));
        checkBox_remember_password_2->setText(QApplication::translate("createconnect", "\350\256\260\344\275\217\345\257\206\347\240\201", nullptr));
        lineEdit_password_data_2->setText(QString());
        label_password_2->setText(QApplication::translate("createconnect", "\345\257\206\347\240\201", nullptr));
        tabWidget_password->setTabText(tabWidget_password->indexOf(tab_keyboard), QApplication::translate("createconnect", "   Keyboard Interactive   ", nullptr));
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
        lineEdit_port_ssh_data_4->setText(QApplication::translate("createconnect", "1024", nullptr));
        lineEdit_port_ssh_data_4->setPlaceholderText(QApplication::translate("createconnect", "22", nullptr));
        lineEdit_port_ssh_data_5->setText(QApplication::translate("createconnect", "1024", nullptr));
        lineEdit_port_ssh_data_5->setPlaceholderText(QApplication::translate("createconnect", "22", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("createconnect", "   windows   ", nullptr));
        lineEdit_port_zk_data->setText(QApplication::translate("createconnect", "11100", nullptr));
        lineEdit_port_zk_data->setPlaceholderText(QApplication::translate("createconnect", "22", nullptr));
        label_port_ssh_2->setText(QApplication::translate("createconnect", "\347\253\257\345\217\243", nullptr));
        lineEdit_host_zk_data->setText(QApplication::translate("createconnect", "172.16.8.153", nullptr));
        lineEdit_host_zk_data->setPlaceholderText(QApplication::translate("createconnect", "127.0.0.1", nullptr));
        label_host_ssh_2->setText(QApplication::translate("createconnect", "\344\270\273\346\234\272", nullptr));
        widget_dynamic_title_label_2->setText(QApplication::translate("createconnect", "\345\260\206\345\210\233\345\273\272\345\217\257\350\247\206\345\214\226zk\344\277\241\346\201\257\347\225\214\351\235\242\357\274\214\350\277\233\350\241\214\345\277\253\351\200\237\344\276\277\346\215\267\347\232\204\345\242\236\345\210\240\346\224\271\346\237\245", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("createconnect", "   zookeeper   ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("createconnect", "   Redis   ", nullptr));
        widget_bottom_toolButton_connect->setText(QApplication::translate("createconnect", "\350\277\236\346\216\245", nullptr));
        widget_bottom_toolButton_save->setText(QApplication::translate("createconnect", "\344\277\235\345\255\230", nullptr));
        widget_bottom_toolButton_close->setText(QApplication::translate("createconnect", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class createconnect: public Ui_createconnect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATECONNECT_H
