#include "datahandle.h"
#include <QRegExp>
#include <regex>
#include <QDebug>
#include <iostream>
#include <QMap>

QMap<QString, QString> fontColorMap {
    {"30", "黑色"}, {"31", "红色"},{"32", "绿色"}, {"[33", "黄色"},
    {"34", "蓝色"}, {"35", "紫色"},{"36", "天蓝色"}, {"37", "白色"},
    {"90", "灰色"}, {"91", "亮红色"},{"92", "亮绿色"}, {"93", "亮黄色"},
    {"94", "亮蓝色"}, {"95", "亮品红色"},{"96", "亮青色"}, {"97", "亮白色"},
};

QMap<QString, QString> backColorMap {
    {"40", "黑色"}, {"41", "红色"},{"42", "绿色"}, {"43", "黄色"},
    {"44", "蓝色"}, {"45", "紫色"},{"46", "天蓝色"}, {"47", "白色"},
    {"100", "灰色"}, {"101", "亮红色"},{"102", "亮绿色"}, {"103", "亮黄色"},
    {"104", "亮蓝色"}, {"105", "亮品红色"},{"106", "亮青色"}, {"107", "亮白色"},
};

QMap<QString, QString> StatsColorMap {
    {"01", "重置"}, {"01", "粗体"}, {"02", "细体"},{"03", "斜体"}, {"04", "下划线"},
    {"05", "缓慢闪烁"}, {"06", "快速闪烁"},{"07", "反显"}, {"08", "划除"},
};

datahandle::datahandle(QObject *parent) : QObject(parent)
{

}

QString datahandle::processDataStatsAndColor(QString data)
{
    //解析数据
    QRegExp regex("(\\x001B\\[(\\d*)m)*\\x001B\\[(\\d*)\\;*(\\d*)\\;*(\\d*)m(\\S*)\\x001B\\[(\\d*)m");
    int pos = 0;

    while ((pos = regex.indexIn(data, pos)) != -1) {
        QString match = regex.cap(0); // 获取完整的匹配项
        qDebug() << "Matched email:" << match;
        qDebug() << "Matched email 1:" << regex.cap(1);
        qDebug() << "Matched email 2:" << regex.cap(2);
        qDebug() << "Matched email 3:" << regex.cap(3);
        qDebug() << "Matched email 4:" << regex.cap(4);
        qDebug() << "Matched email 5:" << regex.cap(5);
        qDebug() << "Matched email 6:" << regex.cap(6);
        qDebug() << "Matched email 7:" << regex.cap(7);
        //2 重置 3 颜色代码 4 颜色代码 6 文件名字 7 重置
        pos += regex.matchedLength();
    }


    //1. 解析属性

    //2. 解析前背景色

    //3. 解析字体颜色


    return "";
}

QString datahandle::processData(QString data)
{
    processDataStatsAndColor(data);


    qDebug() << "修改前数据：" << data;

    QRegExp regExp("(\\x001B)\\]0;\\S+\\x0007\\x001B\\[\\?1034h");
    if (regExp.indexIn(data)>=0) {
        //替换
        //qDebug() << "修改后数据：" << regExp.cap(1);
        data = data.replace(regExp.cap(0), "");
    }

    QRegExp regExp11("\\x0007");
    if (regExp11.indexIn(data)>=0) {
        //替换
        //qDebug() << "修改后数据：" << regExp11.cap(1);
            data = data.replace(regExp11.cap(0), "");

    }

    QRegExp regExp0("\\x001B\\[\\?1034h");
    if (regExp0.indexIn(data)>=0) {
        //替换
        //qDebug() << "修改后数据：" << regExp0.cap(1);
        data = data.replace(regExp0.cap(0), "");
    }

    QRegExp regExp1("(\\x001B)\\]0;\\S+\\x0007");
    if (regExp1.indexIn(data)>=0) {
        //替换
        //qDebug() << "修改后数据：" << regExp1.cap(1);
        data = data.replace(regExp1.cap(0), "");
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
    //\u001B[01;34mcore\u001B[0m
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

    qDebug() << "修改后数据：" << data;

    return data;
}
