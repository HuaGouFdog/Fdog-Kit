# Fdog-Kit

编码中！！！ 终端工具（支持ssh，zk可视化访问，thrift接口测试，其他工具集合等）
目前已基本完成zookeeper可视化工具，thrift接口测试工具编写。
欢迎页
![image](https://github.com/HuaGouFdog/Fdog-Kit/assets/59921436/3b8caf69-f179-4c00-b46e-777bb6bb539c)



### 一. 连接zookeeper工具，可视化操作增删改查（正常使用）
![image](https://github.com/HuaGouFdog/Fdog-Kit/assets/59921436/91213c20-b6a0-411a-860a-c019fcdf4725)

### 二. thirft接口测试工具（调试中）
目前只支持TFramedTransport+TBinaryProtocol协议
可以自己自定义接口参数请求，也可以导入thrift文件自动生成接口参数，自动识别参数类型等，请求结果会解析为类json，同时支持源文本查看。

后续将增加接口性能测试界面，支持自定义线程数调用，自定义请求数。
![image](https://github.com/HuaGouFdog/Fdog-Kit/assets/59921436/238a6a45-27cb-4dcc-aaa6-efb9cf611af0)

### 三. linux,windows终端连接(编写中)
提供包括显示服务器信息，上传，下载，历史命令，快捷命令，侧边栏小工具集合等多种功能于一体的终端连接工具
![image](https://github.com/HuaGouFdog/Fdog-Kit/assets/59921436/4239bb33-e135-40df-b89e-acaef7ba8e33)
![image](https://github.com/HuaGouFdog/Fdog-Kit/assets/59921436/1ba89548-c2ff-4be8-9f42-82f10105ced6)
![image](https://github.com/HuaGouFdog/Fdog-Kit/assets/59921436/18312e30-ca06-480d-8bef-b6c2689d4ae7)

### 后续计划
xml格式化工具
json格式化工具
文件对比工具
增加插件功能，可根据要求自定义插件。
