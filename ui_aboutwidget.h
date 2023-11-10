/********************************************************************************
** Form generated from reading UI file 'aboutwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTWIDGET_H
#define UI_ABOUTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_aboutwidget
{
public:
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;

    void setupUi(QWidget *aboutwidget)
    {
        if (aboutwidget->objectName().isEmpty())
            aboutwidget->setObjectName(QStringLiteral("aboutwidget"));
        aboutwidget->resize(370, 270);
        aboutwidget->setMinimumSize(QSize(370, 270));
        aboutwidget->setMaximumSize(QSize(370, 270));
        QFont font;
        font.setFamily(QStringLiteral("OPPOSans B"));
        font.setPointSize(10);
        font.setStyleStrategy(QFont::PreferAntialias);
        aboutwidget->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/lib/icon9.png"), QSize(), QIcon::Normal, QIcon::Off);
        aboutwidget->setWindowIcon(icon);
        aboutwidget->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(30, 45, 54);"));
        verticalLayout = new QVBoxLayout(aboutwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(30, 9, 30, 9);
        textEdit = new QTextEdit(aboutwidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        textEdit->setStyleSheet(QString::fromUtf8("QTextEdit{\n"
"	background-color: rgba(0, 41, 69, 0);\n"
"	font: 12pt \"Cascadia Mono,OPPOSans B\";\n"
"	border: none;\n"
"	padding-top:0px;\n"
"    padding-bottom:0px;\n"
"	padding-left:0px;\n"
"    padding-right:0px;\n"
"border-radius: 5px;\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"    width: 10px;\n"
"	background-color: rgba(0, 41, 69, 0);\n"
"    margin: 0px,0px,0px,0px;\n"
"    padding-top: 0px;		/*//\351\232\220\350\227\217\344\270\212\344\270\213\347\232\204\347\256\255\345\244\264*/\n"
"    padding-bottom: 0px;\n"
"}\n"
"QScrollBar::handle:vertical {\n"
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
"QSc"
                        "rollBar::add-line:vertical {\n"
"	border: none;\n"
"    height: 0px;\n"
"    subcontrol-position: bottom;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"QScrollBar::sub-line:vertical {\n"
"    border: none;\n"
"    height: 0px;\n"
"    subcontrol-position: top;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::down-arrow:vertical {\n"
"    border:none;\n"
"}\n"
"QScrollBar::up-arrow:vertical {\n"
"    border:none;\n"
"}"));
        textEdit->setReadOnly(true);

        verticalLayout->addWidget(textEdit);


        retranslateUi(aboutwidget);

        QMetaObject::connectSlotsByName(aboutwidget);
    } // setupUi

    void retranslateUi(QWidget *aboutwidget)
    {
        aboutwidget->setWindowTitle(QApplication::translate("aboutwidget", "\345\205\263\344\272\216", nullptr));
        textEdit->setHtml(QApplication::translate("aboutwidget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Cascadia Mono,OPPOSans B'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'OPPOSans B'; font-size:10pt; font-weight:600;\">\345\205\263\344\272\216Fdog-Kit</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'OPPOSans B'; font-size:10pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'OPPOSans B'; font-size:10pt;\">\345\237\272\344\272\216Qt5."
                        "10.0\357\274\210MSVC2015\357\274\21464\344\275\215\357\274\211\346\236\204\345\273\272</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'OPPOSans B'; font-size:10pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'OPPOSans B'; font-size:10pt;\">\347\211\210\346\234\254\357\274\232V1.0.1</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'OPPOSans B'; font-size:10pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'OPPOSans B'; font-size:10pt;\">\344\275\234\350\200\205\357\274\232\350\212\261\347\213\227Fdog</span></p>\n"
"<p style=\"-qt-para"
                        "graph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'OPPOSans B'; font-size:10pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'OPPOSans B'; font-size:10pt;\">\350\201\224\347\263\273\346\210\221\357\274\2322506897252@qq.com</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'OPPOSans B'; font-size:10pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'OPPOSans B'; font-size:10pt;\">\351\241\271\347\233\256\345\234\260\345\235\200\357\274\232</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">"
                        "<a href=\"https://github.com/HuaGouFdog/Fdog-Kit\"><span style=\" font-family:'OPPOSans B'; font-size:10pt; text-decoration: underline; color:#2f7fff;\">https://github.com/HuaGouFdog/Fdog-Kit</span></a></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'OPPOSans B'; font-size:10pt; text-decoration: underline; color:#2f7fff;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a href=\"https://github.com/HuaGouFdog/Fdog-Kit\"><span style=\" font-family:'OPPOSans B'; font-size:10pt; text-decoration: underline; color:#ffffff;\">\346\204\237\350\260\242\346\202\250\347\232\204\344\275\277\347\224\250\357\274\201\360\237\230\212\360\237\230\212\360\237\230\212</span></a></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class aboutwidget: public Ui_aboutwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTWIDGET_H
