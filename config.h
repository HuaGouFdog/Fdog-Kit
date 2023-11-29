#ifndef CONFIG_H
#define CONFIG_H

#include <QWidget>

class config : public QWidget
{
    Q_OBJECT
public:
    explicit config(QWidget *parent = nullptr);
    //启动选项
    int selfStart = 0;
    int trayDisplay = 0;
    int startMode = 0;
    int startPositionX = 0;
    int startPositionY = 0;
    int startCenter = 0;
    //外观选项
    QString language = "cn";
    int topDisplay = 1;
    int newLabelLocation = 1;
    int labelWidth = 1;
    //字体选项
    int fontSize = 0;
    QString fontEnglish = "";
    QString fontChinese = "";
    //配色选项

    //终端
    int infoDisplay = 0;
    int historyDisplay = 0;
    int commandDisplay = 0;
    int conectStatsDisplay = 0;

public slots:

private:


};

#endif // CONFIG_H
