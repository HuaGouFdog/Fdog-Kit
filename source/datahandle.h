#ifndef DATAHANDLE_H
#define DATAHANDLE_H
#pragma execution_character_set("utf-8")
#include <QString>
#include <QObject>


//光标定位相关
//#define CUU     ""  //光标向上 <n> 行
//#define CUD     ""  //光标向下 <n> 行
//#define CUF     ""  //光标向前（右）<n> 行
//#define CUB     ""  //光标向后（左）<n> 行
//#define CNL     ""  //光标从当前位置向下 <n> 行
//#define CPL     ""  //光标从当前位置向上 <n> 行
//#define CHA     ""  //光标在当前行中水平移动到第 <n> 个位置
//#define VPA     ""  //光标在当前列中垂直移动到第 <n> 个位置
//#define CUP     ""  //光标移动到 <x>; <视区中的 y> 坐标，其中 <x> 是 y> 线的<列
//#define HVP     ""  //光标移动到 <x>; <视区中的 y> 坐标，其中 <x> 是 y> 线的<列
//#define SYSSC   ""  //在没有参数的情况下，执行保存游标操作，如 DECSC
//#define SYSRC   ""  //在没有参数的情况下，执行还原游标操作，如 DECRC
////光标可见性
//#define ATT160_H    ""  //文本光标启用闪烁 开始光标闪烁
//#define ATT160_L    ""  //文本光标禁用闪烁 停止闪烁光标
//#define DECTCEM_H   ""  //文本光标启用模式显示 显示光标
//#define DECTCEM_L   ""  //文本光标启用模式隐藏 隐藏光标
////光标形状
//#define DECSCUSR_0  ""  //用户形状  用户配置的默认光标形状
//#define DECSCUSR_1  ""  //闪烁块    闪烁块光标形状
//#define DECSCUSR_2  ""  //稳定块    稳定块光标形状
//#define DECSCUSR_3  ""  //闪烁下划线 闪烁的下划线光标形状
//#define DECSCUSR_4  ""  //稳定下划线 稳定下划线光标形状
//#define DECSCUSR_5  ""  //闪烁条形图 闪烁的条形光标形状
//#define DECSCUSR_6  ""  //稳定条形图 稳定条光标形状
////视区定位
//#define SU  ""  //将文本向上滚动 <n> 行。 也称为向下平移，新行从屏幕底部填充
//#define SD  ""  //向下滚动 <n> 行。 也称为向上平移，新行从屏幕顶部填充
////文本修改
//#define ICH ""  //插入字符 在当前光标位置插入 <n> 个空格，这会将所有现有文本移到右侧。 向右溢出屏幕的文本会被删除。
//#define DCH ""  //删除字符 删除当前光标位置的 <n> 个字符，这会从屏幕右边缘以空格字符移动。
//#define ECH ""  //擦除字符 擦除当前光标位置的 <n> 个字符，方法是使用空格字符覆盖它们。
//#define IL  ""  //插入行 将 <n> 行插入光标位置的缓冲区。 光标所在的行及其下方的行将向下移动。
//#define DL  ""  //删除行 从缓冲区中删除 <n> 行，从光标所在的行开始。
//#define ED  ""  //显示中的擦除 将 <n> 指定的当前视区/屏幕中的所有文本替换为空格字符
//#define EL  ""  //行中的擦除 将行上的所有文本替换为由 <n> 指定的光标与空格字符
////文本格式
//#define SGR ""  //设置图形呈现内容将屏幕和文本的格式设置为由 <n> 指定
////屏幕颜色
//#define ""  //
////模式更改
//#define DECKPAM     ""  //启用键盘应用程序模式 键盘键将发出其应用程序模式序列。
//#define DECKPAM     ""  //启用键盘数字模式 键盘键将发出其数字模式序列。
//#define DECCKM_1    ""  //启用光标键应用程序模式 键盘键将发出其应用程序模式序列。
//#define DECCKM_2    ""  //禁用光标键应用程序模式（使用“常规”模式）键盘键将发出其数字模式序列。
////查询模式
//#define DECXCPR ""  //报告光标位置 将光标位置发出为：ESC [ <r> ; <c> R 其中 <r> = 游标行， <c> = 游标列
//#define DA      ""  //设备属性报告 终端标识，将发出“\x1b[？1;0c”，指示“VT101 无选项”。


static QString lastM = "";

class datahandle : public QObject
{
    Q_OBJECT
public:
    explicit datahandle(QObject *parent = nullptr);
    static void stringToHtmlFilter(QString &str);
    static QString replaceAmpersand(QString original);
    static void stringToHtmlFilter_s(QString &str);
    void stringToHtmlFilter2(QString &str);
    void stringToHtmlFilter3(QString &str);
    void stringToHtmlFilter4(QString &str);
    void stringToHtmlFilter5(QString &str);
    void stringToHtmlFilter6(QString &str);
    static void stringToHtml(QString &str, QColor *fontCrl = NULL, QColor *backCrl = NULL);
    QString processDataStatsAndColor(QString & head, QString & commond, QString data);
    QString processData(QString data);
    QStringList processDataS(QString data);


    int isDTab = 0;
    QString ssh_path; //当前工作目录
signals:

public slots:
};

#endif // DATAHANDLE_H
