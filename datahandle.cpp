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
    QString return_;
    qDebug() << "修改前数据：" << data;
    //\u001B]0;root@localhost:~\u0007\u001B[?1034h[root@localhost ~]#
    //\u001B]0;root@localhost:~\u0007\u001B[?1034h 为终端标题


//    if (data.indexOf("\u001B]0;") != -1) {
//        qDebug() << "修改后数据2：" << return_;
//    }

//    std::string str = "\\u001B]0;root@localhost:~";
//    std::regex reg("\\\\u[0-9A-Fa-f]{4}");

//    std::smatch match;
//    if (std::regex_search(str, match, reg)) {
//        qDebug()  << "found." <<  QString::fromLocal8Bit(match.str().data());
//    } else {
//        qDebug()  << "No match found.";
//    }

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

//    QRegExp regExp("(\\x001B)\\]0;\\S+\\x0007\\x001B\\[\\?1034h");
//    if (regExp.indexIn(data)>=0) {
//        //替换
//        //qDebug() << "修改后数据：" << regExp.cap(1);
//        data = data.replace(regExp.cap(0), "");
//    }

//    QRegExp regExp2("(\\x001B)\\]0;\\S+\\x0007");
//    if (regExp2.indexIn(data)>=0) {
//        //替换
//        //qDebug() << "修改后数据：" << regExp.cap(1);
//        data = data.replace(regExp2.cap(0), "");
//    }
    qDebug() << "修改后数据：" << data;

    return data;
}
