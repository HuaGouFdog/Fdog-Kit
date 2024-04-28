#pragma execution_character_set("utf-8")
#include "mainwindow.h"
#include <QApplication>
//#include "utils.h"
#include "settingwidget.h"
#include "thriftwidget.h"
#include "zookeeperhandle.h"
#include <iostream>
#include <QStyleFactory>
#include <QThreadPool>

//class Counter : public QRunnable
//{
//public:
//    Counter(zhandle_t* zh, const std::string& path){
//        this->path = path;
//        this->zh = zh;
//    }
//private:
//    void run() {
//        getChildrenRecursive(zh, path);
//    }
//    std::string path;
//    zhandle_t* zh;
//};

//void getChildrenRecursive(zhandle_t* zh, const std::string& path)
//{
//    struct String_vector childNodes;
//    int ret = zoo_get_children(zh, path.c_str(), 0, &childNodes);
//    if (ret != ZOK) {
//        std::cout << "Failed to get children nodes for path " << path << ": " << zerror(ret) << std::endl;
//        return;
//    }

//    for (int i = 0; i < childNodes.count; ++i) {
//        std::string childPath;
//        if (path != "/") {
//            childPath = path + "/" + childNodes.data[i];
//        } else {
//            childPath = path + childNodes.data[i];
//        }
//        //std::cout << "childPath = " << childPath << std::endl;
//        getChildrenRecursive(zh, childPath, nodes);
//    }
//}

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
    MainWindow w;
    w.show();

    // 连接到ZooKeeper服务器
//    QElapsedTimer timer;
//    timer.start();
//    zhandle_t* zh = zookeeper_init("172.16.8.153:11100", nullptr, 10000, nullptr, nullptr, 0);
//    if (!zh) {
//        std::cout << "Failed to connect to ZooKeeper server!" << std::endl;
//        return -1;
//    }

//    // 指定要获取节点的路径
//    std::string path = "/";

//    // 获取指定节点及其所有子节点
//    std::vector<std::string> nodes;
//    getChildrenRecursive(zh, path, nodes, 1);

//    qint64 elapsedMilliseconds = timer.elapsed();
//    std::cout << "响应时间：" << elapsedMilliseconds << "ms" << std::endl;

//    // 打印节点信息
//    std::cout << "Nodes under " << path << ":" << std::endl;
//    for (const auto& node : nodes) {
//        std::cout << node << std::endl;
//    }


//    // 关闭ZooKeeper连接
//    zookeeper_close(zh);

//    find w;
//    w.show();
      //thriftwidget w;
      //w.show();
    return a.exec();
}
