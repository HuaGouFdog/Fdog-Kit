/********************************************************************************
** Form generated from reading UI file 'toolswidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOOLSWIDGET_H
#define UI_TOOLSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_toolswidget
{
public:
    QHBoxLayout *horizontalLayout_4;
    QWidget *widget_left;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QToolButton *toolButton_2;
    QToolButton *toolButton;
    QSpacerItem *verticalSpacer;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QStackedWidget *stackedWidget;
    QWidget *page_json;
    QHBoxLayout *horizontalLayout_2;
    QSplitter *splitter;
    QPlainTextEdit *plainTextEdit_json_source;
    QTextEdit *textEdit_json_target;
    QWidget *page_xml;
    QHBoxLayout *horizontalLayout_3;
    QSplitter *splitter_2;
    QTextEdit *textEdit_xml_source;
    QTextEdit *textEdit_xml_target;
    QWidget *page_diff;
    QHBoxLayout *horizontalLayout;
    QSplitter *splitter_3;
    QTextEdit *textEdit_diff_source;
    QTextEdit *textEdit_diff_target;

    void setupUi(QWidget *toolswidget)
    {
        if (toolswidget->objectName().isEmpty())
            toolswidget->setObjectName(QStringLiteral("toolswidget"));
        toolswidget->resize(974, 631);
        toolswidget->setStyleSheet(QLatin1String("background-color: rgb(30, 45, 54);\n"
"color: rgb(255, 255, 255);"));
        horizontalLayout_4 = new QHBoxLayout(toolswidget);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        widget_left = new QWidget(toolswidget);
        widget_left->setObjectName(QStringLiteral("widget_left"));
        widget_left->setMinimumSize(QSize(200, 0));
        widget_left->setMaximumSize(QSize(200, 16777215));
        widget_left->setStyleSheet(QLatin1String("#widget_left{\n"
"background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:0.733682, stop:0 rgba(30, 45, 54, 157), stop:1 rgba(37, 56, 67, 255));\n"
"border-right:0px solid rgba(108, 117, 125, 65); \n"
"}\n"
""));
        scrollArea = new QScrollArea(widget_left);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(0, 0, 191, 611));
        scrollArea->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 189, 609));
        scrollAreaWidgetContents->setStyleSheet(QLatin1String("QToolButton {\n"
"    qproperty-iconSize: 22px 22px;\n"
"	/*padding-left: 15px;*/\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"	border: none;\n"
"	border-radius:0px;\n"
"	color: rgb(255, 255, 255);\n"
"	text-align: center;\n"
"}\n"
"\n"
"QToolButton::menu-indicator { \n"
"	image: None;\n"
"}\n"
"\n"
"QToolButton:hover {\n"
"	border-radius:0px;\n"
"	color: rgb(255, 255, 255);\n"
"	\n"
"	background-color: rgb(20, 30, 36);\n"
"	border: none;\n"
"}\n"
" \n"
"QToolButton:checked {\n"
"	border-radius:0px;\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(20, 30, 36);\n"
"	border: none;\n"
"}"));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        toolButton_2 = new QToolButton(scrollAreaWidgetContents);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolButton_2->sizePolicy().hasHeightForWidth());
        toolButton_2->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QStringLiteral("OPPOSans B"));
        font.setPointSize(10);
        toolButton_2->setFont(font);
        toolButton_2->setStyleSheet(QStringLiteral(""));
        QIcon icon;
        icon.addFile(QStringLiteral(":/lib/json (2).png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon);
        toolButton_2->setIconSize(QSize(22, 22));
        toolButton_2->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout->addWidget(toolButton_2);

        toolButton = new QToolButton(scrollAreaWidgetContents);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(toolButton->sizePolicy().hasHeightForWidth());
        toolButton->setSizePolicy(sizePolicy1);
        toolButton->setFont(font);
        toolButton->setStyleSheet(QStringLiteral(""));
        toolButton->setIcon(icon);
        toolButton->setIconSize(QSize(22, 22));
        toolButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout->addWidget(toolButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout_4->addWidget(widget_left);

        widget_2 = new QWidget(toolswidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        widget = new QWidget(widget_2);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(0, 50));
        widget->setMaximumSize(QSize(16777215, 50));
        widget->setStyleSheet(QStringLiteral("background-color: rgb(202, 110, 255);"));

        verticalLayout_2->addWidget(widget);

        stackedWidget = new QStackedWidget(widget_2);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setStyleSheet(QString::fromUtf8("QScrollBar:vertical{\n"
"    width: 10px;\n"
"	background-color: rgba(0, 41, 69, 0);\n"
"    margin: 0px,0px,0px,0px;\n"
"    padding-top: 0px;		/*//\351\232\220\350\227\217\344\270\212\344\270\213\347\232\204\347\256\255\345\244\264*/\n"
"    padding-bottom: 0px;\n"
"}\n"
"\n"
"\n"
"QScrollBar::handle:vertical{\n"
"    width: 10px;\n"
"	\n"
"	background-color: rgb(239, 239, 239);\n"
"    /*\346\273\232\345\212\250\346\235\241\344\270\244\347\253\257\345\217\230\346\210\220\346\244\255\345\234\206 */\n"
"    border-radius: 2px;\n"
"    min-height: 0;\n"
"}\n"
"\n"
"QScrollBar::sub-page:vertical {\n"
"    \n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}\n"
"QScrollBar::add-page:vertical \n"
"{\n"
"    background-color: rgba(255, 255, 255, 0);\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical {\n"
"	border: none;\n"
"    height: 0px;\n"
"    subcontrol-position: bottom;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"QScrollBar::sub-line:vertical {\n"
"    border: none;\n"
"    height: 0px;\n"
"    subcontrol-posit"
                        "ion: top;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::down-arrow:vertical {\n"
"    border:none;\n"
"}\n"
"\n"
"QScrollBar::up-arrow:vertical {\n"
"    border:none;\n"
"}"));
        page_json = new QWidget();
        page_json->setObjectName(QStringLiteral("page_json"));
        horizontalLayout_2 = new QHBoxLayout(page_json);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        splitter = new QSplitter(page_json);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setFrameShadow(QFrame::Plain);
        splitter->setLineWidth(5);
        splitter->setOrientation(Qt::Horizontal);
        splitter->setHandleWidth(15);
        plainTextEdit_json_source = new QPlainTextEdit(splitter);
        plainTextEdit_json_source->setObjectName(QStringLiteral("plainTextEdit_json_source"));
        QFont font1;
        font1.setFamily(QStringLiteral("OPPOSans B"));
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        plainTextEdit_json_source->setFont(font1);
        plainTextEdit_json_source->setStyleSheet(QLatin1String("QPlainTextEdit{\n"
"color: rgb(38, 38, 38);\n"
"background-color: rgb(67, 67, 67);\n"
"font: 10pt \"OPPOSans B\";\n"
"border-radius: 14px;\n"
"background-color: rgb(255, 255, 255);\n"
"border: 0px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding:5px;\n"
"}"));
        splitter->addWidget(plainTextEdit_json_source);
        textEdit_json_target = new QTextEdit(splitter);
        textEdit_json_target->setObjectName(QStringLiteral("textEdit_json_target"));
        textEdit_json_target->setFont(font1);
        textEdit_json_target->setStyleSheet(QLatin1String("QTextEdit{\n"
"color: rgb(56, 56, 56);\n"
"font: 10pt \"OPPOSans B\";\n"
"border-radius: 14px;\n"
"background-color: rgb(255, 255, 255);\n"
"border: 0px solid rgba(255, 255, 255, 0);\n"
"border-radius: 5px;\n"
"padding:5px;\n"
"}"));
        splitter->addWidget(textEdit_json_target);

        horizontalLayout_2->addWidget(splitter);

        stackedWidget->addWidget(page_json);
        page_xml = new QWidget();
        page_xml->setObjectName(QStringLiteral("page_xml"));
        horizontalLayout_3 = new QHBoxLayout(page_xml);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        splitter_2 = new QSplitter(page_xml);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        textEdit_xml_source = new QTextEdit(splitter_2);
        textEdit_xml_source->setObjectName(QStringLiteral("textEdit_xml_source"));
        QFont font2;
        font2.setFamily(QStringLiteral("OPPOSans"));
        font2.setPointSize(12);
        font2.setStyleStrategy(QFont::PreferAntialias);
        textEdit_xml_source->setFont(font2);
        splitter_2->addWidget(textEdit_xml_source);
        textEdit_xml_target = new QTextEdit(splitter_2);
        textEdit_xml_target->setObjectName(QStringLiteral("textEdit_xml_target"));
        textEdit_xml_target->setFont(font2);
        splitter_2->addWidget(textEdit_xml_target);

        horizontalLayout_3->addWidget(splitter_2);

        stackedWidget->addWidget(page_xml);
        page_diff = new QWidget();
        page_diff->setObjectName(QStringLiteral("page_diff"));
        horizontalLayout = new QHBoxLayout(page_diff);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        splitter_3 = new QSplitter(page_diff);
        splitter_3->setObjectName(QStringLiteral("splitter_3"));
        splitter_3->setOrientation(Qt::Horizontal);
        textEdit_diff_source = new QTextEdit(splitter_3);
        textEdit_diff_source->setObjectName(QStringLiteral("textEdit_diff_source"));
        textEdit_diff_source->setFont(font2);
        splitter_3->addWidget(textEdit_diff_source);
        textEdit_diff_target = new QTextEdit(splitter_3);
        textEdit_diff_target->setObjectName(QStringLiteral("textEdit_diff_target"));
        textEdit_diff_target->setFont(font2);
        splitter_3->addWidget(textEdit_diff_target);

        horizontalLayout->addWidget(splitter_3);

        stackedWidget->addWidget(page_diff);

        verticalLayout_2->addWidget(stackedWidget);


        horizontalLayout_4->addWidget(widget_2);


        retranslateUi(toolswidget);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(toolswidget);
    } // setupUi

    void retranslateUi(QWidget *toolswidget)
    {
        toolswidget->setWindowTitle(QApplication::translate("toolswidget", "Form", nullptr));
        toolButton_2->setText(QApplication::translate("toolswidget", "    JSON\345\267\245\345\205\267", nullptr));
        toolButton->setText(QApplication::translate("toolswidget", "    JSON\345\267\245\345\205\267", nullptr));
        plainTextEdit_json_source->setPlainText(QString());
        textEdit_json_target->setHtml(QApplication::translate("toolswidget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'OPPOSans B'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:15pt;\"><br /></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class toolswidget: public Ui_toolswidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLSWIDGET_H
