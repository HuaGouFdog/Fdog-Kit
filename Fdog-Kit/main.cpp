#pragma execution_character_set("utf-8")
#include "module_mainwindow/mainwindow.h"
#include <QApplication>
#include "module_setting/settingwidget.h"
#include "module_thrift/thriftwidget.h"
#include "module_zookeeper/zookeeperhandle.h"
#include <iostream>
#include <QStyleFactory>
#include <QThreadPool>
#include "module_activate/activate.h"
#include "module_utils/utils.h"
#include "module_qss/qss.h"
void getChildrenRecursive(zhandle_t* zh, const std::string& path, std::vector<std::string>& nodes, int sum)
{
    if (sum >= 3) {
        return;
    }
    struct String_vector childNodes;
    int ret = zoo_get_children(zh, path.c_str(), 0, &childNodes);
    if (ret != ZOK) {
        std::cout << "Failed to get children nodes for path " << path << ": " << zerror(ret) << std::endl;
        return;
    }

    for (int i = 0; i < childNodes.count; ++i) {
        std::string childPath;
        if (path != "/") {
            childPath = path + "/" + childNodes.data[i];
        } else {
            childPath = path + childNodes.data[i];
        }
        std::cout << "childPath = " << childPath << std::endl;
        //nodes.push_back(childPath);
        getChildrenRecursive(zh, childPath, nodes, ++sum);
    }
}


extern bool signalReceived;

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

#if 1
MainWindow w;
w.show();
//   qss w;
//   w.show();
#endif
#if 0
    Activate aw;
    aw.show();
    while(!signalReceived) {
        a.processEvents(); //防止界面出现无响应
    }
    MainWindow w;
    qDebug() <<  "显示w";
    //aw.close();
    w.show();
#endif
    return a.exec();
}
