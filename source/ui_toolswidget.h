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
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_toolswidget
{
public:
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *page_json;
    QHBoxLayout *horizontalLayout_2;
    QSplitter *splitter;
    QTextEdit *textEdit_json_source;
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
        verticalLayout = new QVBoxLayout(toolswidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        stackedWidget = new QStackedWidget(toolswidget);
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
        splitter->setOrientation(Qt::Horizontal);
        textEdit_json_source = new QTextEdit(splitter);
        textEdit_json_source->setObjectName(QStringLiteral("textEdit_json_source"));
        QFont font;
        font.setFamily(QStringLiteral("OPPOSans B"));
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        textEdit_json_source->setFont(font);
        textEdit_json_source->setStyleSheet(QLatin1String("font: 12pt \"OPPOSans B\";\n"
"color: rgb(194, 194, 194);"));
        splitter->addWidget(textEdit_json_source);
        textEdit_json_target = new QTextEdit(splitter);
        textEdit_json_target->setObjectName(QStringLiteral("textEdit_json_target"));
        textEdit_json_target->setFont(font);
        textEdit_json_target->setStyleSheet(QLatin1String("font: 12pt \"OPPOSans B\";\n"
"color: rgb(194, 194, 194);"));
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
        QFont font1;
        font1.setFamily(QStringLiteral("OPPOSans"));
        font1.setPointSize(12);
        font1.setStyleStrategy(QFont::PreferAntialias);
        textEdit_xml_source->setFont(font1);
        splitter_2->addWidget(textEdit_xml_source);
        textEdit_xml_target = new QTextEdit(splitter_2);
        textEdit_xml_target->setObjectName(QStringLiteral("textEdit_xml_target"));
        textEdit_xml_target->setFont(font1);
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
        textEdit_diff_source->setFont(font1);
        splitter_3->addWidget(textEdit_diff_source);
        textEdit_diff_target = new QTextEdit(splitter_3);
        textEdit_diff_target->setObjectName(QStringLiteral("textEdit_diff_target"));
        textEdit_diff_target->setFont(font1);
        splitter_3->addWidget(textEdit_diff_target);

        horizontalLayout->addWidget(splitter_3);

        stackedWidget->addWidget(page_diff);

        verticalLayout->addWidget(stackedWidget);


        retranslateUi(toolswidget);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(toolswidget);
    } // setupUi

    void retranslateUi(QWidget *toolswidget)
    {
        toolswidget->setWindowTitle(QApplication::translate("toolswidget", "Form", nullptr));
        textEdit_json_source->setHtml(QApplication::translate("toolswidget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'OPPOSans B'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        textEdit_json_target->setHtml(QApplication::translate("toolswidget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'OPPOSans B'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:15pt;\"><br /></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class toolswidget: public Ui_toolswidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLSWIDGET_H
