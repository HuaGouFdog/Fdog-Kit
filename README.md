<div align=center>
<img src="https://github.com/user-attachments/assets/cc639845-5eb4-4d3e-b92c-1aba1af4cf2f" width="15%" height="15%">
<h1>Fdog-Kit</h1>
<img alt="GitHub Repo stars" src="https://img.shields.io/github/stars/HuaGouFdog/Fdog-Kit">
<img alt="GitHub forks" src="https://img.shields.io/github/forks/HuaGouFdog/Fdog-Kit">
</div>

<div align=center>
<img alt="GitHub Created At" src="https://img.shields.io/github/created-at/HuaGouFdog/Fdog-Kit">
<img alt="GitHub License" src="https://img.shields.io/github/license/huagouFdog/fdog-kit">
</div>

<div align=center>
  <img alt="Static Badge" src="https://img.shields.io/badge/Qt5.10.0%2BMSVC2015-passing-brightgreen">
  <img alt="Static Badge" src="https://img.shields.io/badge/Qt5.15.2%2BMSVC2015-passing-brightgreen">

</div>

<div align=center>
  <img alt="GitHub Release" src="https://img.shields.io/github/v/release/HuaGouFdog/Fdog-Kit">
<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/HuaGouFdog/Fdog-Kit">

<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/HuaGouFdog/Fdog-Kit">
<img alt="GitHub Downloads (specific asset, all releases)" src="https://img.shields.io/github/downloads/huagouFdog/Fdog-kit/Fdog-Kit-setup.exe">
</div>

<div align=center>
  <h1> </h1>
</div>

Qt工具集合：无边框窗口集成（可用）zookeeper可视化操作工具（可用），thrift接口调用工具（可用），ssh，qss工具，其他工具集合等）

Fdog-Kit-xxx为单一项目，可以单独编译
Fdog-Kit作为集合，包含所有

如果有缺少库的问题，可以联系我

### 欢迎页

![image](https://github.com/HuaGouFdog/Fdog-Kit/assets/59921436/b5bca273-a85d-443e-9b49-ad88774af67e)


### 一. 无边框模板（正常可用）

使用方法：

在pro文件中添加LIBS += -luser32
将Fdog-Kit-MainWindows文件夹添加到你的qt项目，并进行引用即可，或者将你的MainWindows相关文件替换成我的即可。

模板实现了基本的最小化，最大化，关闭，全屏，拖拽，阴影，任务栏托盘等，可以直接在此基础上进行二次开发。

https://github.com/HuaGouFdog/Fdog-Kit/tree/main/Fdog-Kit-MainWindows

效果图：
![image](https://github.com/user-attachments/assets/813a06f4-fc54-49d1-9816-1d381bdbeddd)

欢迎体验


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




### 三. thirft接口测试工具（正常使用）
通过组合thrift协议进行报文发送的接口测试工具

最大的方便就是，直接导入thrift，填入参数即可，无需进行编译接口

目前仅支持二进制协议，只支持TFramedTransport+TBinaryProtocol

支持：
1. 可以手动创建接口以及参数，也可以导入thrift文件自动生成接口数据
2. 支持识别必选字段以及可选字段
3. 解析报文，并生成可读的json格式数据，并且数据高亮
4. 显示原二进制报文，并对报文进行染色，方便学习阅读排查等。
5. 显示响应类型，调用接口名，接口返回值，以及数据长度。

后续将增加接口性能测试界面，支持自定义线程数调用，自定义请求数。

https://github.com/HuaGouFdog/Fdog-Kit/tree/main/Fdog-Kit-Thirft

效果图：
![image](https://github.com/user-attachments/assets/8266465c-08ef-416b-9246-bfed41ca7ee9)


![image](https://github.com/user-attachments/assets/d33fa24c-bf69-40e6-adc3-774534e18856)

欢迎体验


### 四. linux,windows终端连接(编写中)
提供包括显示服务器信息，上传，下载，历史命令，快捷命令，侧边栏小工具集合等多种功能于一体的终端连接工具
![image](https://github.com/HuaGouFdog/Fdog-Kit/assets/59921436/ceeb5128-c5cd-4c9a-b633-fef3005baebb)
![image](https://github.com/HuaGouFdog/Fdog-Kit/assets/59921436/934228e6-a684-4101-a4a3-90b99bcc0ea8)
![image](https://github.com/HuaGouFdog/Fdog-Kit/assets/59921436/28064809-ee08-495e-9d27-105bde419070)


