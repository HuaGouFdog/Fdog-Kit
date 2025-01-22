#ifndef CONFIG_H
#define CONFIG_H

#include <QWidget>
#include <QJsonArray>
struct ColorScheme {
    QString background;     //背景颜色
    QString black;          //黑色
    QString blue;           //蓝色
    QString brightBlack;    //亮黑
    QString brightBlue;     //亮蓝
    QString brightCyan;     //亮青色
    QString brightGreen;    //亮绿色
    QString brightPurple;   //亮粉色
    QString brightRed;      //亮红色
    QString brightWhite;    //亮白色
    QString brightYellow;   //亮黄色
    QString cursorColor;    //光标颜色
    QString cyan;           //青色
    QString foreground;     //前景色
    QString green;          //绿色
    QString name;           //方案名
    QString purple;         //粉色
    QString red;            //红色
    QString selectionBackground;   //选中背景
    QString white;          //白色
    QString yellow;         //黄色
};

class config : public QWidget
{
    Q_OBJECT
public:
    explicit config(QWidget *parent = nullptr);
    //启动选项
    int selfStart = 0;      //开机时启动
    int trayDisplay = 0;    //托盘区显示
    int startMode = 0;      //启动模式 1默认 2最大化 3全屏
    int startPositionX = 0; //启动位置x
    int startPositionY = 0; //启动位置y
    int startCenter = 0;    //启动居中
    //外观选项
    QString language = "cn";    //语言
    int topDisplay = 1;         //顶层显示
    int newLabelLocation = 1;   //新建标签位置 1在最后一个标签之后 2在当前标签之后
    int labelWidth = 1;         //标签宽度
    //字体选项
    int fontSize = 0;           //字体大小
    QString fontEnglish = "";   //英文字体
    QString fontChinese = "";   //中文字体
    //配色选项
    QString selectScheme;       //当前选中
    QVector<ColorScheme> colorSchemeList;
    //终端
    int infoDisplay = 0;        //工具栏信息
    int historyDisplay = 0;     //工具栏历史
    int commandDisplay = 0;     //工具栏命令
    int conectStatsDisplay = 0; //工具栏属性
    int mouseRightClick = 0;    //鼠标滚轮单击行为
    int mouseWheelClick = 0;    //鼠标右键单击行为
    int colorScheme = 0;        //颜色主题
    int background = 0;         //终端背景 1默认 2纯色 3图片
    QString currentBackground = "";  //当前背景
    QString currentColor = "";       //当前颜色
    int backgroundTransparency = 1;  //背景透明度

    QStringList pictureList;         //图片列表

    //读取设置
    void readSettingConf();
    //写入设置
    void writeSettingConf();

public slots:

private:


};

#endif // CONFIG_H
