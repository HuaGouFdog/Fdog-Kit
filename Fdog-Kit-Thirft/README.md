通过组合thrift协议进行报文发送的接口测试工具

最大的方便就是，直接导入thrift，填入参数即可，无需进行编译接口

目前仅支持二进制协议

支持：
1. 可以手动创建接口以及参数，也可以导入thrift文件自动生成接口数据
2. 支持识别必选字段以及可选字段
3. 解析报文，并生成可读的json格式数据，并且数据高亮
4. 显示原二进制报文，并对报文进行染色，方便学习阅读排查等。
5. 显示响应类型，调用接口名，接口返回值，以及数据长度。


![image](https://github.com/user-attachments/assets/8266465c-08ef-416b-9246-bfed41ca7ee9)


![image](https://github.com/user-attachments/assets/d33fa24c-bf69-40e6-adc3-774534e18856)

欢迎体验
