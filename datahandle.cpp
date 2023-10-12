﻿#include "datahandle.h"
#include <QRegExp>
#include <regex>
#include <QDebug>
#include <iostream>
#include <QMap>
#include <QColor>






/*
 *
 *
 *
文档
https://learn.microsoft.com/zh-cn/windows/console/console-virtual-terminal-sequences?source=recommendations
\u001B[?12;25h：启用光标闪烁。
\u001B[?12l：禁用光标闪烁。
\u001B[27m：关闭所有属性。
\u001B[m：重置所有属性。
\u001B[?25l：隐藏光标。
\u001B[?25h：显示光标。
\u001B[1;24r：设置滚动区域为第 1 行到第 24 行。
\u001B[?1049h：启用交替屏幕缓冲区模式。
\u001B[?1h：启用应用程序光标键模式。
\u001B=：设置键盘模式。在这个上下文中，= 后面可能还有其他参数，缺失了具体的参数。

CSI序列:
0x001B + "[" + <zero or more numbers, separated by ";"> + <a letter>

参数字节	0x30–0x3F	0–9:;<=>?
中间字节	0x20–0x2F	空格、!"#$%&’()*+,-./
最终字节	0x40–0x7E	@A–Z[]^_`a–z{

A	Cursor Up               (n=1)	将光标向上移动n行
B	Cursor Down             (n=1)	将光标向下移动n行
C	Cursor Forward          (n=1)	将光标向前移动n个字符
D	Cursor Back             (n=1)	将光标向后移动n个字符
E	Cursor Next Line        (n=1)	将光标向下移到到n行的行首
F	Cursor Previous Line    (n=1)	将光标向上移到到n行的行首
G	Cursor Horizontal Absolute	(n=1)	将光标移动到当前行中的第n列
H	Cursor Position         (n=1, m=1)	移动光标到第n行，第m列，从左上角开始计数
J	Erase in Display        (n=0)	清除部分屏幕。0、1、2和3有各种特定的功能
K	Erase in Line           (n=0)	清除部分线路。0,1和2有各种特定的功能
S	Scroll Up               (n=1)	将窗口向上滚动到n行
T	Scroll Down             (n=1)	将窗口向下滚动到n行
s	Save Cursor Position	()      保存当前光标位置以供使用u时使用
u	Restore Cursor Position	()      将光标设置回s最后保存的位置
f	…                   …           (同G)
m	SGR                     (*)     设置SGR

A等等类似于函数
*/




QMap<int, QColor *> fontColorMap {
    {30, new QColor(0,0,0)}, {31, new QColor(255, 0, 0)},{32, new QColor(56, 255, 33)}, {33, new QColor(255,255,0)},
    {34, new QColor(20, 96, 210)}, {35, new QColor(153,255,0)},{36, new QColor(0,255,255)}, {37, new QColor(255,255,255)},
    {90, new QColor(102,102,102)}, {91, new QColor(255,0,0)},{92, new QColor(0,255,0)}, {93, new QColor(255,255,0)},
    {94, new QColor(0,0,255)}, {95, new QColor(255,0,0)},{96, new QColor(0,255,0)}, {97, new QColor(255,255,255)},
};
/*
new clrR(255,255,255)
*/
QMap<int, QColor*> backColorMap {
    {40, new QColor(0,0,0)}, {41, new QColor(255,0,0)},{42, new QColor(0,255,0)}, {43, new QColor(255,255,0)},
    {44, new QColor(0,0,255)}, {45, new QColor(153,255,0)},{46, new QColor(0,255,255)}, {47, new QColor(255,255,255)},
    {100, new QColor(102,102,102)}, {101, new QColor(255,0,0)},{102, new QColor(0,255,0)}, {103, new QColor(255,255,0)},
    {104, new QColor(0,0,255)}, {105, new QColor(255,0,0)},{106, new QColor(0,255,0)}, {107, new QColor(255,255,255)},
};

QMap<QString, QString> StatsColorMap {
    {"0", "重置"}, {"01", "粗体"}, {"02", "细体"},{"03", "斜体"}, {"04", "下划线"},
    {"05", "缓慢闪烁"}, {"06", "快速闪烁"},{"07", "反显"}, {"08", "划除"},
};

struct operStatsAndData {
    bool isSats;  //是否设置属性
    int mode;    //模式 键盘模式
    int line_s;  //滚动区间start
    int line_e;  //滚动区间end
    bool isClear;//清空屏幕，这个其实是移动光标到开头
    int  curPos_sline;  //移动光标位置
    int  curPos_scolumn;  //移动光标位置
    QString data;        //输出数据
    int  curPos_eline;  //移动光标位置
    int  curPos_ecolumn;  //移动光标位置
    //
    //
    //
    //
    //
    //
    //
    //
};

datahandle::datahandle(QObject *parent) : QObject(parent)
{

}

void datahandle::stringToHtmlFilter(QString &str)
{
    //注意这几行代码的顺序不能乱，否则会造成多次替换
    str.replace("&","&amp;");
    str.replace(">","&gt;");
    str.replace("<","&lt;");
    str.replace("\"","&quot;");
    str.replace("\'","&#39;");
    str.replace(" ","&nbsp;");
    str.replace("\r\r\n","<br>");
    str.replace("\r\n","<br>");
    str.replace("\n","<br>");
}

void datahandle::stringToHtmlFilter2(QString &str)
{
    str.replace("\r\r\n","<br>");
    str.replace("\r\n","<br>");
    str.replace("\n","<br>");
}

void datahandle::stringToHtmlFilter3(QString &str)
{
    str.replace(" ","&nbsp;");
}

void datahandle::stringToHtmlFilter4(QString &str)
{
    //处理默认
    //qDebug() << "默认处理 str = " << str << endl;
    //先查找第一个<span>
    int index3 = 0;
    index3 = str.indexOf("<span", index3);
    if (index3 != -1) {
        for(int i = 0; i < index3; i++) {
            //qDebug() << "str[index] " << str[i] << endl;
            if (str[i] == " ") {
                str.replace(i, 1,"&nbsp;");
                //qDebug() << str[i] << "替换 " << i;
                index3 = index3 + 5;
            } else {
                //qDebug() << str[i] << "不替换 ";
            }
        }
    } else {
        str.replace(" ","&nbsp;");
    }

    int index = 0;
    int index2 =0;
    do {
        index = str.indexOf("</span>", index + 5);
        if (index != -1) {
            //qDebug() << "找到</span>" << "位置是" << index << endl;
            index2 = str.indexOf("<span", index);
            if (index2 != -1) {
                //qDebug() << "找到<span " << endl;
                //qDebug() << "stringToHtmlFilter4" << str.mid(index,index2-index + 5);
                int c= 0;
                for(int i = index; i < index2 + 5; i++) {
                    //qDebug() << "str[index] " << str[i] << endl;
                    if (str[i] == " ") {
                        str.replace(i, 1,"&nbsp;");
                        //qDebug() << str[i] << "替换 " << i;
                        index2 = index2 + 5;
                        c++;
                    } else {
                        //qDebug() << str[i] << "不替换 ";
                    }
                }
                //qDebug() << "共替换 " <<c;
                index = index2;
            }
        } else {
            //qDebug() << "没找到</span>" << endl;
        }
    } while (index != -1);
}

void datahandle::stringToHtmlFilter5(QString &str)
{
    QRegExp regex("\\\b\\x001B\\[K");
    int pos = 0;

    while ((pos = regex.indexIn(str, pos)) != -1) {
        QString match = regex.cap(0); // 获取完整的匹配项
        str.replace(regex.cap(0), "");
        qDebug() << "Matched stringToHtmlFilter5:" << match;
        pos += regex.matchedLength();
    }
}

/*
\u001B[?1049h：保存当前终端的状态。
\u001B[?1h：设置光标为可见状态。
\u001B=：切换到应用程序键盘模式。
\u001B[1;24r：设置终端的滚动区域为第1行到第24行。
\u001B[?12;25h：启用光标闪烁。
\u001B[?12l：禁用光标闪烁。
\u001B[?25h：显示光标。
\u001B[27m：重置终端的属性和颜色。
\u001B[m：重置终端的属性和颜色。
\u001B[H：将光标移动到终端的起始位置。
\u001B[2J：清空终端屏幕。
\u001B[?25l：隐藏光标。
\u001B[24;1H：将光标移动到第24行的起始位置。
*/

void datahandle::stringToHtmlFilter6(QString &str)
{
    QRegExp regExp("\\x001B\\[(\\d+);(\\d+)H~");
    int pos = 0;
    while ((pos = regExp.indexIn(str, pos)) != -1) {
        QString match = regExp.cap(0); // 获取完整的匹配项
        str.replace(regExp.cap(0), "<br>~");
        qDebug() << "Matched stringToHtmlFilter6:" << match;
        pos += regExp.matchedLength();
    }
}


void datahandle::stringToHtml(QString &str, QColor *fontCrl, QColor *backCrl)
{
    if (fontCrl != NULL && backCrl != NULL) {
        QByteArray array;
        array.append(fontCrl->red());
        array.append(fontCrl->green());
        array.append(fontCrl->blue());
        QString strC(array.toHex());

        QByteArray array2;
        array2.append(backCrl->red());
        array2.append(backCrl->green());
        array2.append(backCrl->blue());
        QString strC2(array2.toHex());
        qDebug() << "stringToHtml" << "设置字体颜色和背景颜色";
        str = QString("<span style=\" color:#%1; background-color:#%2;\">%3</span>").arg(strC).arg(strC2).arg(str);
    } else if (fontCrl != NULL) {
        QByteArray array;
        array.append(fontCrl->red());
        array.append(fontCrl->green());
        array.append(fontCrl->blue());
        QString strC(array.toHex());
        str = QString("<span style=\" color:#%1;\">%2</span>").arg(strC).arg(str);
    } else if (backCrl != NULL) {
        QByteArray array;
        array.append(backCrl->red());
        array.append(backCrl->green());
        array.append(backCrl->blue());
        QString strC(array.toHex());
        str = QString("<span style=\" background-color:#%1;\">%2</span>").arg(strC).arg(str);
    }
}


QString datahandle::processDataStatsAndColor(QString & head, QString & commond, QString data)
{
    //解析数据\u001B[34;42mjenkins_home\u001B[0m
    QRegExp regex("(\\x001B\\[(\\d*)m)*\\x001B\\[(\\d*)\\;*(\\d*)\\;*(\\d*)m(\\S*)\\x001B\\[(\\d*)m(\\s*)");
    int pos = 0;

    while ((pos = regex.indexIn(data, pos)) != -1) {
        QString match = regex.cap(0); // 获取完整的匹配项
        //qDebug() << "Matched email:" << match;
        //qDebug() << "Matched email 1:" << regex.cap(1);
        //qDebug() << "Matched email 2:" << regex.cap(2);
        qDebug() << "Matched email 3:" << regex.cap(3);
        qDebug() << "Matched email 4:" << regex.cap(4);
        //qDebug() << "Matched email 5:" << regex.cap(5);
        qDebug() << "Matched email 6:" << regex.cap(6);
        //qDebug() << "Matched email 7:" << regex.cap(7);
        //qDebug() << "Matched email 8:" << regex.cap(8);
        //2 重置 3 颜色代码 4 颜色代码 6 文件名字 7 重置
        //qDebug() << "processDataStatsAndColor修改前数据：" << regex.cap(6) << " regex.cap(4).toInt() =" <<regex.cap(4).toInt();

        QColor *fontCrl = NULL;
        QColor *backCrl = NULL;

        auto it1 = fontColorMap.find(regex.cap(3).toInt());
        if (it1 != fontColorMap.end()) {
            fontCrl = *it1;
            //qDebug() << "找到字体颜色1";
        }
        auto it2 = fontColorMap.find(regex.cap(4).toInt());
        if (it2 != fontColorMap.end()) {
            fontCrl = *it2;
            //qDebug() << "找到字体颜色2";
        }

        auto it3 = backColorMap.find(regex.cap(3).toInt());
        if (it3 != backColorMap.end()) {
            backCrl = *it3;
            //qDebug() << "找到背景颜色3";
        }
        auto it4 = backColorMap.find(regex.cap(4).toInt());
        if (it4 != backColorMap.end()) {
            backCrl = *it4;
            //qDebug() << "找到背景颜色4";
        }

        //设置颜色
        QString cc = regex.cap(6) + regex.cap(8);
        stringToHtmlFilter(cc);
        stringToHtml(cc, fontCrl, backCrl);
        //替换
        data.replace(match, cc);
        pos += regex.matchedLength();
    }
    return data;
}

QString datahandle::processData(QString data)
{
    QString commond;
    QString head;
    //qDebug() << "head = " << head;
    //qDebug() << "commond = " << commond;
    qDebug() << "processData修改前数据：" << data;

    QRegExp regExp("(\\x001B)\\]0;\\S+\\x0007\\x001B\\[\\?1034h");
    if (regExp.indexIn(data)>=0) {
        //替换
        //qDebug() << "修改后数据：" << regExp.cap(1);
        data = data.replace(regExp.cap(0), "");
    }

    QRegExp regExp1("(\\x001B)\\]0;\\S+\\x0007");
    if (regExp1.indexIn(data)>=0) {
        //替换
        qDebug() << "修改后数据1：";
        data = data.replace(regExp1.cap(0), "");
    }

//    QRegExp regExp2("(\\x001B)\\]0;\\S+\\x0007");
//    if (regExp2.indexIn(data)>=0) {
//        //替换
//        /qDebug() << "修改后数据2：";
//        data = data.replace(regExp2.cap(0), "");
//    }

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

    //\u001B[01;34mcore\u001B[0m
    //\u001B[01;34mzx_test\u001B[0m

    //stringToHtmlFilter3(data);
    //处理属性和颜色
    data = processDataStatsAndColor(head, commond, data);

    stringToHtmlFilter2(data);

    //处理默认属性
    stringToHtmlFilter4(data);

    //清除光标
    stringToHtmlFilter5(data);

    stringToHtmlFilter6(data);

    qDebug() << "processData修改后数据：" << data;

    return data;
}