#include "datahandle.h"
#include <QRegExp>
#include <regex>
#include <QDebug>
#include <iostream>
datahandle::datahandle(QObject *parent) : QObject(parent)
{

}

QString datahandle::processData(QString data)
{
    qDebug() << "修改前数据：" << data;

    QRegExp regExp("(\\x001B)\\]0;\\S+\\x0007\\x001B\\[\\?1034h");
    if (regExp.indexIn(data)>=0) {
        //替换
        //qDebug() << "修改后数据：" << regExp.cap(1);
        data = data.replace(regExp.cap(0), "");
    }

    QRegExp regExp2("(\\x001B)\\]0;\\S+\\x0007");
    if (regExp2.indexIn(data)>=0) {
        //替换
        //qDebug() << "修改后数据：" << regExp.cap(1);
        data = data.replace(regExp2.cap(0), "");
    }

    //\u001B[01;34mcore\u001B[0m
    //\u001B[01;34mzx_test\u001B[0m

    QRegExp regExp3("(\\x001B)\\[0m");
    if (regExp3.indexIn(data)>=0) {
        //替换
        //qDebug() << "regExp3.cap(0)：" << regExp3.cap(0);
        //qDebug() << "regExp3.cap(1)：" << regExp3.cap(1);
        //qDebug() << "regExp3.cap(2)：" << regExp3.cap(2);
        data = data.replace(regExp3.cap(0), "");
    }

    QRegExp regExp4("(\\x001B)\\[\\d{2};\\d{2}m");
    if (regExp4.indexIn(data)>=0) {
        //替换
        //qDebug() << "regExp4.cap(0)：" << regExp4.cap(0);
        //qDebug() << "regExp4.cap(1)：" << regExp4.cap(1);
        //qDebug() << "regExp4.cap(2)：" << regExp4.cap(2);
        data = data.replace(regExp4.cap(0), "");
    }

    QRegExp regExp5("(\\x001B)\\[\\d{2};\\d{2}m");
    if (regExp5.indexIn(data)>=0) {
        //替换
        //qDebug() << "regExp5.cap(0)：" << regExp5.cap(0);
        //qDebug() << "regExp5.cap(1)：" << regExp5.cap(1);
        //qDebug() << "regExp5.cap(2)：" << regExp5.cap(2);
        data = data.replace(regExp5.cap(0), "");
    }

    QRegExp regExp6("(\\x001B)\\[\\d{2};\\d{2}m");
    if (regExp6.indexIn(data)>=0) {
        //替换
        //qDebug() << "regExp6.cap(0)：" << regExp6.cap(0);
        //qDebug() << "regExp6.cap(1)：" << regExp6.cap(1);
        //qDebug() << "regExp6.cap(2)：" << regExp6.cap(2);
        data = data.replace(regExp6.cap(0), "");
    }


//    QRegExp regExp3("(\\x001B)\\[01;34m(\\S+)(\\x001B)\\[0m");
//    if (regExp3.indexIn(data)>=0) {
//        //替换
//        qDebug() << "regExp3.cap(0)：" << regExp3.cap(0);
//        qDebug() << "regExp3.cap(1)：" << regExp3.cap(1);
//        qDebug() << "regExp3.cap(2)：" << regExp3.cap(2);
//        data = data.replace(regExp3.cap(0), regExp3.cap(2));
//    }

    //qDebug() << "修改后数据：" << data;

    return data;
}
