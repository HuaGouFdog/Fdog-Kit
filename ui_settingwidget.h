/********************************************************************************
** Form generated from reading UI file 'settingwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGWIDGET_H
#define UI_SETTINGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_settingwidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QToolButton *toolButton_8;
    QToolButton *toolButton_4;
    QToolButton *toolButton_2;
    QToolButton *toolButton_6;
    QToolButton *toolButton_5;
    QToolButton *toolButton_7;
    QSpacerItem *verticalSpacer;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *page_2;

    void setupUi(QWidget *settingwidget)
    {
        if (settingwidget->objectName().isEmpty())
            settingwidget->setObjectName(QStringLiteral("settingwidget"));
        settingwidget->resize(784, 469);
        settingwidget->setStyleSheet(QStringLiteral(""));
        verticalLayout_2 = new QVBoxLayout(settingwidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(settingwidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(widget_2);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(150, 0));
        widget->setMaximumSize(QSize(150, 16777215));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        toolButton_8 = new QToolButton(widget);
        toolButton_8->setObjectName(QStringLiteral("toolButton_8"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolButton_8->sizePolicy().hasHeightForWidth());
        toolButton_8->setSizePolicy(sizePolicy);
        toolButton_8->setMinimumSize(QSize(0, 40));
        toolButton_8->setMaximumSize(QSize(16777215, 40));
        QFont font;
        font.setFamily(QStringLiteral("OPPOSans B"));
        font.setPointSize(10);
        font.setStyleStrategy(QFont::PreferAntialias);
        toolButton_8->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/lib/line-terminal.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_8->setIcon(icon);
        toolButton_8->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout->addWidget(toolButton_8);

        toolButton_4 = new QToolButton(widget);
        toolButton_4->setObjectName(QStringLiteral("toolButton_4"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(3);
        sizePolicy1.setVerticalStretch(4);
        sizePolicy1.setHeightForWidth(toolButton_4->sizePolicy().hasHeightForWidth());
        toolButton_4->setSizePolicy(sizePolicy1);
        toolButton_4->setMinimumSize(QSize(0, 40));
        toolButton_4->setMaximumSize(QSize(16777215, 40));
        toolButton_4->setFont(font);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/lib/bi.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_4->setIcon(icon1);
        toolButton_4->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout->addWidget(toolButton_4);

        toolButton_2 = new QToolButton(widget);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        sizePolicy1.setHeightForWidth(toolButton_2->sizePolicy().hasHeightForWidth());
        toolButton_2->setSizePolicy(sizePolicy1);
        toolButton_2->setMinimumSize(QSize(0, 40));
        toolButton_2->setMaximumSize(QSize(16777215, 40));
        toolButton_2->setFont(font);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/lib/font.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon2);
        toolButton_2->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout->addWidget(toolButton_2);

        toolButton_6 = new QToolButton(widget);
        toolButton_6->setObjectName(QStringLiteral("toolButton_6"));
        sizePolicy1.setHeightForWidth(toolButton_6->sizePolicy().hasHeightForWidth());
        toolButton_6->setSizePolicy(sizePolicy1);
        toolButton_6->setMinimumSize(QSize(0, 40));
        toolButton_6->setMaximumSize(QSize(16777215, 40));
        toolButton_6->setFont(font);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/lib/theme.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_6->setIcon(icon3);
        toolButton_6->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout->addWidget(toolButton_6);

        toolButton_5 = new QToolButton(widget);
        toolButton_5->setObjectName(QStringLiteral("toolButton_5"));
        sizePolicy1.setHeightForWidth(toolButton_5->sizePolicy().hasHeightForWidth());
        toolButton_5->setSizePolicy(sizePolicy1);
        toolButton_5->setMinimumSize(QSize(0, 40));
        toolButton_5->setMaximumSize(QSize(16777215, 40));
        toolButton_5->setFont(font);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/lib/zhuti.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_5->setIcon(icon4);
        toolButton_5->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout->addWidget(toolButton_5);

        toolButton_7 = new QToolButton(widget);
        toolButton_7->setObjectName(QStringLiteral("toolButton_7"));
        sizePolicy1.setHeightForWidth(toolButton_7->sizePolicy().hasHeightForWidth());
        toolButton_7->setSizePolicy(sizePolicy1);
        toolButton_7->setMinimumSize(QSize(0, 40));
        toolButton_7->setMaximumSize(QSize(16777215, 40));
        toolButton_7->setFont(font);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/lib/keyboard.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_7->setIcon(icon5);
        toolButton_7->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout->addWidget(toolButton_7);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addWidget(widget);

        stackedWidget = new QStackedWidget(widget_2);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setStyleSheet(QStringLiteral("background-color: rgb(180, 238, 255);"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        stackedWidget->addWidget(page_2);

        horizontalLayout->addWidget(stackedWidget);


        verticalLayout_2->addWidget(widget_2);


        retranslateUi(settingwidget);

        QMetaObject::connectSlotsByName(settingwidget);
    } // setupUi

    void retranslateUi(QWidget *settingwidget)
    {
        settingwidget->setWindowTitle(QApplication::translate("settingwidget", "Form", nullptr));
        toolButton_8->setText(QApplication::translate("settingwidget", "\347\273\210\347\253\257", nullptr));
        toolButton_4->setText(QApplication::translate("settingwidget", "\345\244\226\350\247\202", nullptr));
        toolButton_2->setText(QApplication::translate("settingwidget", "\345\255\227\344\275\223", nullptr));
        toolButton_6->setText(QApplication::translate("settingwidget", "\351\205\215\350\211\262\346\226\271\346\241\210", nullptr));
        toolButton_5->setText(QApplication::translate("settingwidget", "\344\270\273\351\242\230", nullptr));
        toolButton_7->setText(QApplication::translate("settingwidget", "\345\277\253\346\215\267\351\224\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class settingwidget: public Ui_settingwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGWIDGET_H
