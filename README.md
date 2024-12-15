# Fdog-Kit

编码中！！！ 终端工具（支持ssh，zk可视化访问，thrift接口测试，其他工具集合等）
目前已基本完成zookeeper可视化工具，thrift接口测试工具编写。

如果有缺少库的问题，可以提。

欢迎页

![image](https://github.com/HuaGouFdog/Fdog-Kit/assets/59921436/b5bca273-a85d-443e-9b49-ad88774af67e)


### 一. 无边框模板

使用方法：

在pro文件中添加LIBS += -luser32
将Fdog-Kit-MainWindows文件夹添加到你的qt项目，并进行引用即可，或者将你的MainWindows相关文件替换成我的即可。

模板实现了基本的最小化，最大化，关闭，全屏，拖拽，阴影，任务栏托盘等，可以直接在此基础上进行二次开发。

https://github.com/HuaGouFdog/Fdog-Kit/tree/main/Fdog-Kit-MainWindows

效果图：
![image](https://github.com/user-attachments/assets/813a06f4-fc54-49d1-9816-1d381bdbeddd)




### 二. 连接zookeeper工具，可视化操作增删改查（正常使用）

使用zookeeper-c库编写的zk可视化操作工具

支持：
1. 连接信息缓存
2. 同时连接多个zk
3. 支持实时更新当前选中节点数据，如果取消勾选实时更新，则有绿色圆点进行提示
4. 支持快速搜索，支持大小写
5. 支持json数据格式化，节点url解码
6. 支持增删改查
7. 新增编辑区，可用于临时编辑处理

https://github.com/HuaGouFdog/Fdog-Kit/tree/main/Fdog-Kit-Zookeeper


效果图：
![image](https://github.com/user-attachments/assets/085aafc0-1919-434e-9918-13884c6534f2)

欢迎体验




### 三. thirft接口测试工具（调试中）
目前只支持TFramedTransport+TBinaryProtocol协议
可以自己自定义接口参数请求，也可以导入thrift文件自动生成接口参数，自动识别参数类型等，请求结果会解析为类json，同时支持源文本查看。

后续将增加接口性能测试界面，支持自定义线程数调用，自定义请求数。
![image](https://github.com/HuaGouFdog/Fdog-Kit/assets/59921436/6a3b5277-6add-4d6f-86b7-9900551cc58d)


### 四. linux,windows终端连接(编写中)
提供包括显示服务器信息，上传，下载，历史命令，快捷命令，侧边栏小工具集合等多种功能于一体的终端连接工具
![image](https://github.com/HuaGouFdog/Fdog-Kit/assets/59921436/ceeb5128-c5cd-4c9a-b633-fef3005baebb)
![image](https://github.com/HuaGouFdog/Fdog-Kit/assets/59921436/934228e6-a684-4101-a4a3-90b99bcc0ea8)
![image](https://github.com/HuaGouFdog/Fdog-Kit/assets/59921436/28064809-ee08-495e-9d27-105bde419070)


