#pragma execution_character_set("utf-8")
#include "mainwindow.h"
#include <QApplication>
#include <QStyleFactory>
#include <QFontDatabase>
#include <QDebug>
int main(int argc, char *argv[])
{
    if(QT_VERSION>=QT_VERSION_CHECK(5,6,0))
            QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication a(argc, argv);
    a.setStyle(QStyleFactory::create("Fusion"));
    int fontId = QFontDatabase::addApplicationFont(":fonts/OPPOSans-B-2.ttf");
    qDebug()<<"family"<<QFontDatabase::applicationFontFamilies(fontId);
    QStringList fontFamilies = QFontDatabase::applicationFontFamilies(fontId);
    if (fontFamilies.size() > 0)
    {
        QFont font;
        font.setFamily(fontFamilies[0]);//设置全局字体
        a.setFont(font);
    } else {
        qDebug() << "错误";
    }
    MainWindow w;
    w.show();
    return a.exec();
}
