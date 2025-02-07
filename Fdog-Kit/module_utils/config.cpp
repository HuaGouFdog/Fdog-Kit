#pragma execution_character_set("utf-8")
#include "config.h"
#include <QFile>
#include <QJsonParseError>
#include <QDebug>
#include <QJsonObject>
config::config(QWidget *parent) : QWidget(parent)
{

}

void config::readSettingConf()
{
    qDebug() << "开始读取";
    QFile file(":conf//settings.json");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file.";
        return;
    }
    // 将JSON数据解析为QJsonDocument对象
    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson(file.readAll(), &error);
    file.close();
    if (error.error != QJsonParseError::NoError) {
        qDebug() << "Failed to parse JSON:" << error.errorString();
        //return -1;
    }

    if (doc.isObject()) {
        QJsonObject obj = doc.object();
        
        //是否第一次启动
        QJsonValue isFirstStartValue = obj.value("isFirstStart");
        if (isFirstStartValue.isDouble()) {
            isFirstStart = isFirstStartValue.toInt();
        }
        //module初始化
        QJsonValue moduleValue = obj.value("module");
        if (moduleValue.isObject()) {
            QJsonObject moduleObj = moduleValue.toObject();

            //自动打包模块
            QJsonValue autoValue = moduleObj.value("autoPackage");
            if (autoValue.isDouble()) {
                autoPackage = autoValue.toInt();
            }

            //thrift模块
            QJsonValue thriftValue = moduleObj.value("thrift");
            if (thriftValue.isDouble()) {
                thrift = thriftValue.toInt();
            }

             //zk模块
            QJsonValue zookeeperValue = moduleObj.value("zookeeper");
            if (zookeeperValue.isDouble()) {
                zookeeper = zookeeperValue.toInt();
            }

            //shell模块
            QJsonValue shellValue = moduleObj.value("shell");
            if (shellValue.isDouble()) {
                shell = shellValue.toInt();
            }

            //数据库模块
            QJsonValue dbValue = moduleObj.value("db");
            if (dbValue.isDouble()) {
                db = dbValue.toInt();
            }

            //qss模块
            QJsonValue qssValue = moduleObj.value("qss");
            if (qssValue.isDouble()) {
                qss = qssValue.toInt();
            }

            //tool模块
            QJsonValue toolValue = moduleObj.value("tool");
            if (toolValue.isDouble()) {
                tool = toolValue.toInt();
            }

            //扩展模块
            QJsonValue extendValue = moduleObj.value("extend");
            if (extendValue.isDouble()) {
                extend = extendValue.toInt();
            }
        }

        //启动选项
        QJsonValue activateValue = obj.value("activate");
        if (activateValue.isObject()) {
            QJsonObject activateObj = activateValue.toObject();

            //开机时启动
            QJsonValue selfStartValue = activateObj.value("selfStart");
            if (selfStartValue.isDouble()) {
                selfStart = selfStartValue.toInt();
            }

            //托盘区显示
            QJsonValue trayDisplayValue = activateObj.value("trayDisplay");
            if (trayDisplayValue.isDouble()) {
                trayDisplay = trayDisplayValue.toInt();
            }

            //启动模式 1默认 2最大化 3全屏
            QJsonValue startModeValue = activateObj.value("startMode");
            if (startModeValue.isDouble()) {
                startMode = startModeValue.toInt();
            }

            //启动位置x
            QJsonValue startPositionXValue = activateObj.value("startPositionX");
            if (startPositionXValue.isDouble()) {
                startPositionX = startPositionXValue.toInt();
            }

            //启动位置y
            QJsonValue startPositionYValue = activateObj.value("startPositionY");
            if (startPositionYValue.isDouble()) {
                startPositionY = startPositionYValue.toInt();
            }

            //启动居中
            QJsonValue startCenterValue = activateObj.value("startCenter");
            if (startCenterValue.isDouble()) {
                startCenter = startCenterValue.toInt();
            }
        }

        //外观选项
        QJsonValue appearanceValue = obj.value("appearance");
        if (appearanceValue.isObject()) {
            QJsonObject appearanceObj = appearanceValue.toObject();

            //语言
            QJsonValue languageValue = appearanceObj.value("language");
            if (languageValue.isString()) {
                language = languageValue.toString();
            }
            //顶层显示
            QJsonValue topDisplayValue = appearanceObj.value("topDisplay");
            if (topDisplayValue.isDouble()) {
                topDisplay = topDisplayValue.toInt();
            }
            //新建标签位置 1在最后一个标签之后 2在当前标签之后
            QJsonValue newLabelLocationValue = appearanceObj.value("newLabelLocation");
            if (newLabelLocationValue.isDouble()) {
                newLabelLocation = newLabelLocationValue.toInt();
            }

            //标签宽度
            QJsonValue labelWidthValue = appearanceObj.value("labelWidth");
            if (labelWidthValue.isDouble()) {
                labelWidth = labelWidthValue.toInt();
            }
        }

        //字体选项
        QJsonValue typefaceValue = obj.value("typeface");
        if (typefaceValue.isObject()) {
            QJsonObject typefaceObj = typefaceValue.toObject();

            //字体大小
            QJsonValue fontSizeValue = typefaceObj.value("fontSize");
            if (fontSizeValue.isDouble()) {
                fontSize = fontSizeValue.toInt();
            }

            //英文字体
            QJsonValue fontEnglishValue = typefaceObj.value("fontEnglish");
            if (fontEnglishValue.isString()) {
                fontEnglish = fontEnglishValue.toString();
            }

            //中文字体
            QJsonValue fontChineseValue = typefaceObj.value("fontChinese");
            if (fontChineseValue.isString()) {
                fontChinese = fontChineseValue.toString();
            }
        }

        //配色选项
        QJsonValue colorSchemesValue = obj.value("colorSchemes");
        if (colorSchemesValue.isArray()) {
            QJsonArray colorSchemesArray = colorSchemesValue.toArray();
            for(int i = 0; i < colorSchemesArray.size(); i++) {
                QJsonObject colorSchemeObj = colorSchemesArray[i].toObject();
                ColorScheme cs;
                cs.name = colorSchemeObj["name"].toString();
                cs.background = colorSchemeObj["background"].toString();
                cs.foreground = colorSchemeObj["foreground"].toString();
                cs.selectionBackground = colorSchemeObj["selectionBackground"].toString();
                cs.cursorColor = colorSchemeObj["cursorColor"].toString();
                cs.black = colorSchemeObj["black"].toString();
                cs.blue = colorSchemeObj["blue"].toString();
                cs.cyan = colorSchemeObj["cyan"].toString();
                cs.green = colorSchemeObj["green"].toString();
                cs.purple = colorSchemeObj["purple"].toString();
                cs.red = colorSchemeObj["red"].toString();
                cs.white = colorSchemeObj["white"].toString();
                cs.brightBlack = colorSchemeObj["brightBlack"].toString();
                cs.brightBlue = colorSchemeObj["brightBlue"].toString();
                cs.brightCyan = colorSchemeObj["brightCyan"].toString();
                cs.brightGreen = colorSchemeObj["brightGreen"].toString();
                cs.brightPurple = colorSchemeObj["brightPurple"].toString();
                cs.brightRed = colorSchemeObj["brightRed"].toString();
                cs.brightWhite = colorSchemeObj["brightWhite"].toString();
                cs.brightYellow = colorSchemeObj["brightYellow"].toString();
                colorSchemeList.append(cs);
            }
        }

        //终端选项
        QJsonValue terminalValue = obj.value("terminal");
        if (terminalValue.isObject()) {
            QJsonObject terminalObj = terminalValue.toObject();

            //工具栏信息
            QJsonValue infoDisplayValue = terminalObj.value("infoDisplay");
            if (infoDisplayValue.isDouble()) {
                infoDisplay = infoDisplayValue.toInt();
            }

            //工具栏历史
            QJsonValue historyDisplayValue = terminalObj.value("historyDisplay");
            if (historyDisplayValue.isDouble()) {
                historyDisplay = historyDisplayValue.toInt();
            }

            //工具栏命令
            QJsonValue commandDisplayValue = terminalObj.value("commandDisplay");
            if (commandDisplayValue.isDouble()) {
                commandDisplay = commandDisplayValue.toInt();
            }

            //工具栏属性
            QJsonValue conectStatsDisplayValue = terminalObj.value("conectStatsDisplay");
            if (conectStatsDisplayValue.isDouble()) {
                conectStatsDisplay = conectStatsDisplayValue.toInt();
            }

            //鼠标滚轮单击行为
            QJsonValue mouseRightClickValue = terminalObj.value("mouseRightClick");
            if (mouseRightClickValue.isDouble()) {
                mouseRightClick = mouseRightClickValue.toInt();
            }

            //鼠标右键单击行为
            QJsonValue mouseWheelClickValue = terminalObj.value("mouseWheelClick");
            if (mouseWheelClickValue.isDouble()) {
                mouseWheelClick = mouseWheelClickValue.toInt();
            }

            //终端背景 1默认 2纯色 3图片
            QJsonValue backgroundValue = terminalObj.value("background");
            if (backgroundValue.isDouble()) {
                background = backgroundValue.toInt();
            }

            //当前背景
            QJsonValue currentBackgroundValue = terminalObj.value("currentBackground");
            if (currentBackgroundValue.isDouble()) {
                currentBackground = currentBackgroundValue.toInt();
            }

            //当前颜色
            QJsonValue backgroundTransparencyValue = terminalObj.value("backgroundTransparency");
            if (backgroundTransparencyValue.isDouble()) {
                backgroundTransparency = backgroundTransparencyValue.toInt();
            }

            //图片列表
            QJsonValue pictureListValue = terminalObj.value("pictureList");
            if (pictureListValue.isArray()) {
                for(int i = 0; i < pictureListValue.toArray().size(); i++) {
                    pictureList.append(pictureListValue.toArray()[i].toString());
                }
            }
        }
    }
    file.close();
}

void config::writeSettingConf()
{
    QJsonObject jObj;
    jObj.insert("isFirstStart", isFirstStart);

    QJsonObject jChildObj_module;
    jChildObj_module.insert("autoPackage", autoPackage);
    jChildObj_module.insert("thrift", thrift);
    jChildObj_module.insert("zookeeper", zookeeper);
    jChildObj_module.insert("shell", shell);
    jChildObj_module.insert("db", db);
    jChildObj_module.insert("qss", qss);
    jChildObj_module.insert("tool", tool);
    jChildObj_module.insert("extend", extend);
    jObj.insert("module", jChildObj_module);

    QJsonObject jChildObj_activate;
    jChildObj_activate.insert("selfStart", selfStart);
    jChildObj_activate.insert("trayDisplay", trayDisplay);
    jChildObj_activate.insert("startMode", startMode);
    jChildObj_activate.insert("startPositionX", startPositionX);
    jChildObj_activate.insert("startPositionY", startPositionY);
    jChildObj_activate.insert("startCenter", startCenter);
    jObj.insert("activate", jChildObj_activate);

    QJsonObject jChildObj_appearance;
    jChildObj_appearance.insert("language", language);
    jChildObj_appearance.insert("topDisplay", topDisplay);
    jChildObj_appearance.insert("newLabelLocation", newLabelLocation);
    jChildObj_appearance.insert("labelWidth", labelWidth);
    jObj.insert("appearance", jChildObj_appearance);

    QJsonObject jChildObj_typeface;
    jChildObj_typeface.insert("fontSize", fontSize);
    jChildObj_typeface.insert("fontEnglish", fontEnglish);
    jChildObj_typeface.insert("fontChinese", fontChinese);
    jObj.insert("typeface", jChildObj_typeface);

    QJsonArray colorSchemesValue;
    for(int i =0; i < colorSchemeList.length(); i++) {
        QJsonObject jChildObj_colorScheme;
        jChildObj_colorScheme.insert("name", colorSchemeList[i].name);
        jChildObj_colorScheme.insert("background", colorSchemeList[i].background);
        jChildObj_colorScheme.insert("foreground", colorSchemeList[i].foreground);
        jChildObj_colorScheme.insert("selectionBackground", colorSchemeList[i].selectionBackground);
        jChildObj_colorScheme.insert("cursorColor", colorSchemeList[i].cursorColor);
        jChildObj_colorScheme.insert("black", colorSchemeList[i].black);
        jChildObj_colorScheme.insert("blue", colorSchemeList[i].blue);
        jChildObj_colorScheme.insert("cyan", colorSchemeList[i].cyan);
        jChildObj_colorScheme.insert("green", colorSchemeList[i].green);
        jChildObj_colorScheme.insert("purple", colorSchemeList[i].purple);
        jChildObj_colorScheme.insert("red", colorSchemeList[i].red);
        jChildObj_colorScheme.insert("white", colorSchemeList[i].white);
        jChildObj_colorScheme.insert("brightBlack", colorSchemeList[i].brightBlack);
        jChildObj_colorScheme.insert("brightBlue", colorSchemeList[i].brightBlue);
        jChildObj_colorScheme.insert("brightCyan", colorSchemeList[i].brightCyan);
        jChildObj_colorScheme.insert("brightGreen", colorSchemeList[i].brightGreen);
        jChildObj_colorScheme.insert("brightPurple", colorSchemeList[i].brightPurple);
        jChildObj_colorScheme.insert("brightRed", colorSchemeList[i].brightRed);
        jChildObj_colorScheme.insert("brightWhite", colorSchemeList[i].brightWhite);
        jChildObj_colorScheme.insert("brightYellow", colorSchemeList[i].brightYellow);
        colorSchemesValue.append(jChildObj_colorScheme);
    }
    jObj.insert("colorSchemes", colorSchemesValue);

    QJsonObject jChildObj_terminal;
    jChildObj_terminal.insert("infoDisplay", infoDisplay);
    jChildObj_terminal.insert("historyDisplay", historyDisplay);
    jChildObj_terminal.insert("commandDisplay", commandDisplay);
    jChildObj_terminal.insert("conectStatsDisplay", conectStatsDisplay);
    jChildObj_terminal.insert("mouseRightClick", mouseRightClick);
    jChildObj_terminal.insert("mouseWheelClick", mouseWheelClick);
    jChildObj_terminal.insert("background", background);
    jChildObj_terminal.insert("currentBackground", currentBackground);
    jChildObj_terminal.insert("backgroundTransparency", backgroundTransparency);

    QJsonArray pictureListValue;
    for(int i = 0; i < pictureList.length(); i ++) {
        pictureListValue.append(pictureList[i]);
    }
    jChildObj_terminal.insert("pictureList", pictureListValue);

    jObj.insert("terminal", jChildObj_terminal);
    
    QJsonDocument jDoc(jObj);
    //打开存放json串的文件
    QFile file("conf//settings.json");
    if(!file.open(QIODevice::WriteOnly))
    return ;
    //使用QJsonDocument的toJson方法获取json串并保存到数组
    QByteArray data(jDoc.toJson());
    //将json串写入文件
    file.write(data);
    //file.flush(); // 确保数据被写入文件
    qDebug() << "数据写入完毕";
    file.close();
}
