/********************************************************************************
** Form generated from reading UI file 'colormatch.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLORMATCH_H
#define UI_COLORMATCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_colormatch
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *horizontalWidget_24;
    QHBoxLayout *horizontalLayout_20;
    QWidget *gridWidget_2;
    QGridLayout *gridLayout_2;
    QLabel *label_color_black;
    QLabel *label_color_brightBlack;
    QLabel *label_color_red;
    QLabel *label_color_green;
    QLabel *label_color_brightRed;
    QLabel *label_color_brightGreen;
    QLabel *label_color_brightYellow;
    QLabel *label_color_yellow;
    QLabel *label_color_blue;
    QLabel *label_color_brightBlue;
    QLabel *label_color_purple;
    QLabel *label_color_brightCyan;
    QLabel *label_color_cyan;
    QLabel *label_color_brightPurple;
    QLabel *label_color_white;
    QLabel *label_color_brightWhite;
    QLabel *label_name;
    QSpacerItem *horizontalSpacer_64;

    void setupUi(QWidget *colormatch)
    {
        if (colormatch->objectName().isEmpty())
            colormatch->setObjectName(QStringLiteral("colormatch"));
        colormatch->resize(521, 49);
        colormatch->setMinimumSize(QSize(0, 49));
        colormatch->setMaximumSize(QSize(16777215, 49));
        colormatch->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);"));
        horizontalLayout = new QHBoxLayout(colormatch);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalWidget_24 = new QWidget(colormatch);
        horizontalWidget_24->setObjectName(QStringLiteral("horizontalWidget_24"));
        horizontalWidget_24->setMinimumSize(QSize(0, 0));
        horizontalWidget_24->setMaximumSize(QSize(400, 50));
        horizontalWidget_24->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 0);\n"
"border-radius:5px;"));
        horizontalLayout_20 = new QHBoxLayout(horizontalWidget_24);
        horizontalLayout_20->setSpacing(10);
        horizontalLayout_20->setObjectName(QStringLiteral("horizontalLayout_20"));
        horizontalLayout_20->setContentsMargins(10, 0, 10, 0);
        gridWidget_2 = new QWidget(horizontalWidget_24);
        gridWidget_2->setObjectName(QStringLiteral("gridWidget_2"));
        gridWidget_2->setMinimumSize(QSize(130, 0));
        gridWidget_2->setMaximumSize(QSize(16777215, 40));
        gridWidget_2->setStyleSheet(QLatin1String("QLabel{\n"
"	border-radius:3px;\n"
"}"));
        gridLayout_2 = new QGridLayout(gridWidget_2);
        gridLayout_2->setSpacing(2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(-1, 2, 1, 2);
        label_color_black = new QLabel(gridWidget_2);
        label_color_black->setObjectName(QStringLiteral("label_color_black"));
        label_color_black->setMinimumSize(QSize(12, 12));
        label_color_black->setMaximumSize(QSize(12, 12));
        label_color_black->setStyleSheet(QStringLiteral("background-color: rgb(12, 12, 12);"));

        gridLayout_2->addWidget(label_color_black, 0, 0, 1, 1);

        label_color_brightBlack = new QLabel(gridWidget_2);
        label_color_brightBlack->setObjectName(QStringLiteral("label_color_brightBlack"));
        label_color_brightBlack->setMinimumSize(QSize(12, 12));
        label_color_brightBlack->setMaximumSize(QSize(12, 12));
        label_color_brightBlack->setStyleSheet(QStringLiteral("background-color: rgb(118, 118, 118);"));

        gridLayout_2->addWidget(label_color_brightBlack, 1, 0, 1, 1);

        label_color_red = new QLabel(gridWidget_2);
        label_color_red->setObjectName(QStringLiteral("label_color_red"));
        label_color_red->setMinimumSize(QSize(12, 12));
        label_color_red->setMaximumSize(QSize(12, 12));
        label_color_red->setStyleSheet(QStringLiteral("background-color: rgb(197, 15, 31);"));

        gridLayout_2->addWidget(label_color_red, 0, 1, 1, 1);

        label_color_green = new QLabel(gridWidget_2);
        label_color_green->setObjectName(QStringLiteral("label_color_green"));
        label_color_green->setMinimumSize(QSize(12, 12));
        label_color_green->setMaximumSize(QSize(12, 12));
        label_color_green->setStyleSheet(QStringLiteral("background-color: rgb(19, 161, 14);"));

        gridLayout_2->addWidget(label_color_green, 0, 2, 1, 1);

        label_color_brightRed = new QLabel(gridWidget_2);
        label_color_brightRed->setObjectName(QStringLiteral("label_color_brightRed"));
        label_color_brightRed->setMinimumSize(QSize(12, 12));
        label_color_brightRed->setMaximumSize(QSize(12, 12));
        label_color_brightRed->setStyleSheet(QStringLiteral("background-color: rgb(231, 72, 86);"));

        gridLayout_2->addWidget(label_color_brightRed, 1, 1, 1, 1);

        label_color_brightGreen = new QLabel(gridWidget_2);
        label_color_brightGreen->setObjectName(QStringLiteral("label_color_brightGreen"));
        label_color_brightGreen->setMinimumSize(QSize(12, 12));
        label_color_brightGreen->setMaximumSize(QSize(12, 12));
        label_color_brightGreen->setStyleSheet(QStringLiteral("background-color: rgb(22, 198, 12);"));

        gridLayout_2->addWidget(label_color_brightGreen, 1, 2, 1, 1);

        label_color_brightYellow = new QLabel(gridWidget_2);
        label_color_brightYellow->setObjectName(QStringLiteral("label_color_brightYellow"));
        label_color_brightYellow->setMinimumSize(QSize(12, 12));
        label_color_brightYellow->setMaximumSize(QSize(12, 12));
        label_color_brightYellow->setStyleSheet(QStringLiteral("background-color: rgb(249, 241, 165);"));

        gridLayout_2->addWidget(label_color_brightYellow, 1, 3, 1, 1);

        label_color_yellow = new QLabel(gridWidget_2);
        label_color_yellow->setObjectName(QStringLiteral("label_color_yellow"));
        label_color_yellow->setMinimumSize(QSize(12, 12));
        label_color_yellow->setMaximumSize(QSize(12, 12));
        label_color_yellow->setStyleSheet(QStringLiteral("background-color: rgb(193, 156, 0);"));

        gridLayout_2->addWidget(label_color_yellow, 0, 3, 1, 1);

        label_color_blue = new QLabel(gridWidget_2);
        label_color_blue->setObjectName(QStringLiteral("label_color_blue"));
        label_color_blue->setMinimumSize(QSize(12, 12));
        label_color_blue->setMaximumSize(QSize(12, 12));
        label_color_blue->setStyleSheet(QStringLiteral("background-color: rgb(0, 55, 218);"));

        gridLayout_2->addWidget(label_color_blue, 0, 4, 1, 1);

        label_color_brightBlue = new QLabel(gridWidget_2);
        label_color_brightBlue->setObjectName(QStringLiteral("label_color_brightBlue"));
        label_color_brightBlue->setMinimumSize(QSize(12, 12));
        label_color_brightBlue->setMaximumSize(QSize(12, 12));
        label_color_brightBlue->setStyleSheet(QStringLiteral("background-color: rgb(59, 120, 255);"));

        gridLayout_2->addWidget(label_color_brightBlue, 1, 4, 1, 1);

        label_color_purple = new QLabel(gridWidget_2);
        label_color_purple->setObjectName(QStringLiteral("label_color_purple"));
        label_color_purple->setMinimumSize(QSize(12, 12));
        label_color_purple->setMaximumSize(QSize(12, 12));
        label_color_purple->setStyleSheet(QStringLiteral("background-color: rgb(136, 23, 152);"));

        gridLayout_2->addWidget(label_color_purple, 0, 5, 1, 1);

        label_color_brightCyan = new QLabel(gridWidget_2);
        label_color_brightCyan->setObjectName(QStringLiteral("label_color_brightCyan"));
        label_color_brightCyan->setMinimumSize(QSize(12, 12));
        label_color_brightCyan->setMaximumSize(QSize(12, 12));
        label_color_brightCyan->setStyleSheet(QStringLiteral("background-color: rgb(97, 214, 214);"));

        gridLayout_2->addWidget(label_color_brightCyan, 1, 6, 1, 1);

        label_color_cyan = new QLabel(gridWidget_2);
        label_color_cyan->setObjectName(QStringLiteral("label_color_cyan"));
        label_color_cyan->setMinimumSize(QSize(12, 12));
        label_color_cyan->setMaximumSize(QSize(12, 12));
        label_color_cyan->setStyleSheet(QStringLiteral("background-color: rgb(58, 150, 221);"));

        gridLayout_2->addWidget(label_color_cyan, 0, 6, 1, 1);

        label_color_brightPurple = new QLabel(gridWidget_2);
        label_color_brightPurple->setObjectName(QStringLiteral("label_color_brightPurple"));
        label_color_brightPurple->setMinimumSize(QSize(12, 12));
        label_color_brightPurple->setMaximumSize(QSize(12, 12));
        label_color_brightPurple->setStyleSheet(QStringLiteral("background-color: rgb(180, 0, 158);"));

        gridLayout_2->addWidget(label_color_brightPurple, 1, 5, 1, 1);

        label_color_white = new QLabel(gridWidget_2);
        label_color_white->setObjectName(QStringLiteral("label_color_white"));
        label_color_white->setMinimumSize(QSize(12, 12));
        label_color_white->setMaximumSize(QSize(12, 12));
        label_color_white->setStyleSheet(QStringLiteral("background-color: rgb(204, 204, 204);"));

        gridLayout_2->addWidget(label_color_white, 0, 7, 1, 1);

        label_color_brightWhite = new QLabel(gridWidget_2);
        label_color_brightWhite->setObjectName(QStringLiteral("label_color_brightWhite"));
        label_color_brightWhite->setMinimumSize(QSize(12, 12));
        label_color_brightWhite->setMaximumSize(QSize(12, 12));
        label_color_brightWhite->setStyleSheet(QLatin1String("background-color: #ffffff;\n"
""));

        gridLayout_2->addWidget(label_color_brightWhite, 1, 7, 1, 1);


        horizontalLayout_20->addWidget(gridWidget_2);

        label_name = new QLabel(horizontalWidget_24);
        label_name->setObjectName(QStringLiteral("label_name"));
        QFont font;
        font.setFamily(QStringLiteral("Cascadia Code"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        font.setStyleStrategy(QFont::PreferAntialias);
        label_name->setFont(font);
        label_name->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout_20->addWidget(label_name);


        horizontalLayout->addWidget(horizontalWidget_24);

        horizontalSpacer_64 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_64);


        retranslateUi(colormatch);

        QMetaObject::connectSlotsByName(colormatch);
    } // setupUi

    void retranslateUi(QWidget *colormatch)
    {
        colormatch->setWindowTitle(QApplication::translate("colormatch", "Form", nullptr));
        label_color_black->setText(QString());
        label_color_brightBlack->setText(QString());
        label_color_red->setText(QString());
        label_color_green->setText(QString());
        label_color_brightRed->setText(QString());
        label_color_brightGreen->setText(QString());
        label_color_brightYellow->setText(QString());
        label_color_yellow->setText(QString());
        label_color_blue->setText(QString());
        label_color_brightBlue->setText(QString());
        label_color_purple->setText(QString());
        label_color_brightCyan->setText(QString());
        label_color_cyan->setText(QString());
        label_color_brightPurple->setText(QString());
        label_color_white->setText(QString());
        label_color_brightWhite->setText(QString());
        label_name->setText(QApplication::translate("colormatch", "Campbell", nullptr));
    } // retranslateUi

};

namespace Ui {
    class colormatch: public Ui_colormatch {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLORMATCH_H
