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

----

## 无边框窗口基础框架
在Fdog-Kit的基础上，提取了MainWindows，BaseWindows两个无边框窗口，BaseWindows在MainWindows的基础上增加一个侧边栏，已经实现最小化，最大化，关闭，全屏，拖拽，阴影，任务栏托盘等，可以直接在此基础上进行二次开发。
| BaseWindows   | MainWindows  |
| ---- | ---- |
| ![image](https://github.com/user-attachments/assets/496e7339-8eed-4f45-86a2-166afd1d09cc) | ![image](https://github.com/user-attachments/assets/27592b54-6d58-46e4-9bee-8c9cfcb48e17) |

----

## 支持主题
目前支持暗黑系，蓝色系，明亮系三种主题。

| 暗黑系   | 蓝色系   | 明亮系   |
| ---- | ---- | ---- |
| ![image](https://github.com/user-attachments/assets/e328507d-f8d3-43e5-b1fd-f9bb0f198a12) | ![image](https://github.com/user-attachments/assets/e57fbcf5-d660-4052-a15d-b4e0cab021bb) | ![image](https://github.com/user-attachments/assets/1b26191c-6880-40b1-88c2-ef5c5fc6951f)|

----

## zookeeper可视化工具
目前支持连接信息缓存，同时连接多个zk，支持增删改查，节点实时更新，快速搜索，支持json数据格式化，节点url解码，编辑区等。

| 欢迎页  | 使用界面  | 创建节点   |
| ---- | ---- | ---- |
| ![image](https://github.com/user-attachments/assets/959be931-188f-4a4d-9be8-b47e4c32899b) | ![image](https://github.com/user-attachments/assets/a627f32a-2865-49d7-b62b-7f7881c9954b) | ![image](https://github.com/user-attachments/assets/de161bd0-4635-4343-8260-40cdf1571e1e) |

----

## thrift协议接口工具
这个工具最方便的就是直接导入thrift文件即可调用，不需要编译thrift接口，工具会根据thrift文件生成参数，非常方便。
目前支持：
   传输层协议支持TFramedTransport，THTTPTransport,协议层仅支持TBinaryProtocol。
   可以手动创建接口以及参数，也可以导入thrift文件自动生成接口数据。
   支持识别必选字段以及可选字段。
   解析报文，并生成可读的json格式数据，并且数据高亮。
   显示原二进制报文，并对报文进行染色，方便学习阅读排查等，如果您想了解TBinaryProtocol,这是一个不错的选择。
   显示响应类型，调用接口名，接口返回值，以及数据长度。
   支持接口压测，可配置线程数，并发数，生成压测报告，包括文字和图列。

| 基础模式  | 压测模式  |
| ---- | ---- | 
|![image](https://github.com/user-attachments/assets/d7557b7e-f2ff-4384-aaa5-a0d66eda16a8)|![image](https://github.com/user-attachments/assets/2950882f-0897-48ca-97d9-2383b7a4c279)|

----

## 终端工具
使用libssh2为底层编写的终端工具，由于需要对大量控制序列进行解析，目前还无法做到完整使用，仅实现基础命令的交互，虽然如此，但是一定比某些挂羊头的程序好，目前支持简单命令，显示服务器信息，上传，下载，历史命令，添加快捷命令等。

| 历史连接  | 终端界面 |
| ---- | ---- | 
| ![image](https://github.com/user-attachments/assets/85caa23d-1a1a-4041-a44c-9f1620b8eaf9) | ![image](https://github.com/user-attachments/assets/29de9773-cbf9-43af-bcef-d92ff781fb1f)| 

----

## 其他界面
| 初始化模块界面 | 综合连接界面 | 设置界面1 | 设置界面2 |
| ---- | ---- | ---- |  ---- | 
| ![image](https://github.com/user-attachments/assets/edc61a5c-fcaa-44bc-874f-696e28797761) |![image](https://github.com/user-attachments/assets/7ff1ca70-7e30-4be6-befb-c76d5459e501)| ![image](https://github.com/user-attachments/assets/2144bf4a-05ea-4657-a716-3a653b270fd7)| ![image](https://github.com/user-attachments/assets/5e884309-b05f-412e-b921-6e909b0476b7)| 


有问题，请提Issues。


----

## Star History

[![Star History Chart](https://api.star-history.com/svg?repos=HuaGouFdog/Fdog-Kit&type=Date)](https://star-history.com/#HuaGouFdog/Fdog-Kit&Date)
