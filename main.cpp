#pragma execution_character_set("utf-8")
#include "mainwindow.h"
#include <QApplication>
//#include "utils.h"
#include "settingwidget.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

//    find w;
//    w.show();

    return a.exec();
}
