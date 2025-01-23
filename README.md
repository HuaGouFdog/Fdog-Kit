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

## Star History

[![Star History Chart](https://api.star-history.com/svg?repos=HuaGouFdog/Fdog-Kit&type=Date)](https://star-history.com/#HuaGouFdog/Fdog-Kit&Date)

我正在将平时学习中用到的功能或技能集成进Fdog-kit中，包括：

1. 无边框窗口模板
> 说明：模板实现了基本的最小化，最大化，关闭，全屏，拖拽，阴影，任务栏托盘等，可以直接在此基础上进行二次开发。

2. 基础窗口
>说明：在无边框窗口模板的基础上增加侧边栏。

3. 主题切换
>说明：Fdog-Kit支持多种主题切换，并集成了大量的qss样式表，如果您想使用qss美化您的程序，可以参考Fdog-Kit。

4. zookeeper可视化操作工具
>说明：对zk进行可视化操作，动态监听节点变化。

>目前支持：
   连接信息缓存
   同时连接多个zk
   支持实时更新当前选中节点数据，如果取消勾选实时更新，则有绿色圆点进行提示
   支持快速搜索，支持大小写
   支持json数据格式化，节点url解码
   支持增删改查
   新增编辑区，可用于临时编辑处理
   
5. thrift协议接口工具
>说明：这个工具最方便的就是直接导入thrift文件即可调用，不需要编译thrift接口，工具会根据thrift文件生成参数，非常方便。

>目前支持：
   传输层协议支持TFramedTransport，THTTPTransport,协议层仅支持TBinaryProtocol。
   可以手动创建接口以及参数，也可以导入thrift文件自动生成接口数据。
   支持识别必选字段以及可选字段。
   解析报文，并生成可读的json格式数据，并且数据高亮。
   显示原二进制报文，并对报文进行染色，方便学习阅读排查等，如果您想了解TBinaryProtocol,这是一个不错的选择。
   显示响应类型，调用接口名，接口返回值，以及数据长度。
   支持接口压测，可配置线程数，并发数，生成压测报告，包括文字和图列。

6. 终端工具（不完善）
>说明：使用libssh2为底层编写的终端工具，由于需要对大量控制序列进行解析，目前还无法做到完整使用，仅实现基础命令的交互，虽然如此，但是一定比某些挂羊头的程序好。

>目前支持：显示服务器信息，上传，下载，历史命令，快捷命令。


下面放一些Fdog-Kit截图

主题：
![image](https://github.com/user-attachments/assets/176105d7-33c3-4136-86ce-7dff7ada9a3a)
![image](https://github.com/user-attachments/assets/87c962c1-e784-40b9-a615-45fb7726b1a2)
![image](https://github.com/user-attachments/assets/acdd46ee-f15b-4f42-9972-95faa5493ff6)

无边框模板：
![image](https://github.com/user-attachments/assets/813a06f4-fc54-49d1-9816-1d381bdbeddd)

zk连接工具：
![image](https://github.com/user-attachments/assets/ed1e5887-3247-4d34-aba6-d6e4ecc562da)

thirft接口测试工具：
![image](https://github.com/user-attachments/assets/9b2bd336-cdfe-4995-9461-dc82fec21e89)

![image](https://github.com/user-attachments/assets/63e2adca-8541-46de-9f13-8d1a68236f24)

![image](https://github.com/user-attachments/assets/d33fa24c-bf69-40e6-adc3-774534e18856)

终端工具：
![image](https://github.com/user-attachments/assets/39b9b814-0e7e-4042-ac52-5298a3883d9a)

![image](https://github.com/HuaGouFdog/Fdog-Kit/assets/59921436/ceeb5128-c5cd-4c9a-b633-fef3005baebb)
![image](https://github.com/HuaGouFdog/Fdog-Kit/assets/59921436/934228e6-a684-4101-a4a3-90b99bcc0ea8)
![image](https://github.com/HuaGouFdog/Fdog-Kit/assets/59921436/28064809-ee08-495e-9d27-105bde419070)

设置：
![image](https://github.com/user-attachments/assets/713e4af5-0f75-4d61-be41-fcf2a6f12db9)

如果您有好的想法，欢迎提Issues。
