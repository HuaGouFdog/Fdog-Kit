/********************************************************************************
** Form generated from reading UI file 'zookeepertipswidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZOOKEEPERTIPSWIDGET_H
#define UI_ZOOKEEPERTIPSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_zookeepertipswidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_icon;
    QLabel *label_message;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *zookeepertipswidget)
    {
        if (zookeepertipswidget->objectName().isEmpty())
            zookeepertipswidget->setObjectName(QStringLiteral("zookeepertipswidget"));
        zookeepertipswidget->resize(150, 40);
        zookeepertipswidget->setMinimumSize(QSize(150, 40));
        zookeepertipswidget->setMaximumSize(QSize(150, 40));
        QFont font;
        font.setFamily(QStringLiteral("OPPOSans B"));
        font.setPointSize(10);
        font.setStyleStrategy(QFont::PreferAntialias);
        zookeepertipswidget->setFont(font);
        zookeepertipswidget->setStyleSheet(QLatin1String("#zookeepertipswidget{\n"
"background-color: rgb(27, 27, 27);\n"
"border-radius: 10px;\n"
"}\n"
""));
        verticalLayout = new QVBoxLayout(zookeepertipswidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(zookeepertipswidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setStyleSheet(QStringLiteral(""));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_icon = new QLabel(widget);
        label_icon->setObjectName(QStringLiteral("label_icon"));
        label_icon->setMinimumSize(QSize(20, 20));
        label_icon->setMaximumSize(QSize(20, 20));
        QFont font1;
        font1.setStyleStrategy(QFont::NoAntialias);
        label_icon->setFont(font1);
        label_icon->setStyleSheet(QStringLiteral("image: url(:/lib/node.png);"));

        horizontalLayout->addWidget(label_icon);

        label_message = new QLabel(widget);
        label_message->setObjectName(QStringLiteral("label_message"));
        QFont font2;
        font2.setFamily(QStringLiteral("OPPOSans B"));
        font2.setPointSize(10);
        font2.setBold(false);
        font2.setWeight(50);
        font2.setStyleStrategy(QFont::PreferAntialias);
        label_message->setFont(font2);
        label_message->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(label_message);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget);


        retranslateUi(zookeepertipswidget);

        QMetaObject::connectSlotsByName(zookeepertipswidget);
    } // setupUi

    void retranslateUi(QWidget *zookeepertipswidget)
    {
        zookeepertipswidget->setWindowTitle(QApplication::translate("zookeepertipswidget", "Form", nullptr));
        label_icon->setText(QString());
        label_message->setText(QApplication::translate("zookeepertipswidget", "\345\210\233\345\273\272\350\212\202\347\202\271\346\210\220\345\212\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class zookeepertipswidget: public Ui_zookeepertipswidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZOOKEEPERTIPSWIDGET_H
