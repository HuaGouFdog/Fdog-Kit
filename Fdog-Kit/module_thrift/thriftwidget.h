#ifndef THRIFTWIDGET_H
#define THRIFTWIDGET_H

#include <QTcpSocket>
#include <QWidget>
#include <QTreeWidgetItem>
#include <QComboBox>
#include <QElapsedTimer>
#include <QPushButton>
#include <QHBoxLayout>
#include <QTreeWidget>
#include <QToolButton>
#include <QLabel>
#include <QCheckBox>
#include <QKeyEvent>
#include <QtEndian>
#include <QDebug>
#include <QRunnable>
#include <QTest>
#include <QtCharts>
#include <QThreadPool>
#include <QListWidgetItem>
#include <QMutex>
#include <QProcess>
#include "module_ssh/sshsql.h"
#include "module_ssh/sshhandle.h"
#include "prefabricatedata.h"
#include "itemwidget.h"
#include "variable.h"


namespace Ui {
class thriftwidget;
}

class thriftwidget;

class RequestResults {
    public:

    QVector<int32_t> connectTime;  //每次连接延时
    QVector<int32_t> Results;      //每次请求耗时
    QVector<int32_t> writeTimList;    //每次请求耗时
    QVector<int32_t> readTimeList;     //每次请求耗时
    QVector<int32_t> waitTimeList;     //每次等待耗时


    QString startTime;        //开始时间
    QString requestTime;      //请求时间
    QString endTime;          //结束时间
    QMutex mutex;
    int count = 0;        //为0时，执行完毕
    int totalTimes = 0;   //总执行数
    int successCount = 0; //成功请求数
    int failCount = 0;    //失败请求数
    int minRespond = 0;   //最小响应时间
    int maxRespond = 0;   //最大响应时间
    qint64 totalTime = 0; //总执行时间
    qint64 totalData = 0; //总数据量

    bool isN;

    int ms10 = -1;  //前10%的平均耗时
    int ms25 = -1;
    int ms50 = -1;
    int ms75 = -1;
    int ms90 = -1;
    int ms95 = -1;

    void setStartTime(const QString &value);
    void setEndTime(const QString &value);
    void setResults(const int32_t  value);
    void setConnectTime(const int32_t value);
    void setCount(int value);
    void decrease(int value);
    void setRequestTime(const QString &value);
    void setSectionData();
    void setFailCount(int newFailCount);
    void setTotalData(qint64 newTotalData);
    void setSuccessCount(int newSuccessCount);
    void setWriteTimList(const int32_t value);
    void setReadTimeList(const int32_t value);
    void setWaitTimeList(const int32_t value);
};

class thriftwidget : public QWidget
{
    Q_OBJECT

public:
    bool isAddNode = false;
    bool isToolButton_request_param_checked = true; //入参
    bool isToolButton_response_checked = true;      //响应
    bool isToolButton_report_checked = false;       //性能报告
    int  retractNum = 0;
    QProcess process;
    QList<TableEntry> tableData;
    QMap<int, QString> dumpData;
    connnectInfoStruct cInfoStruct;
    QVector<connnectInfoStruct> cInfoStructList;

    bool isAuto = true;

    QSet<QString> baseType = {"bool", "byte", "i16", "i32", "i64", "double", "string"};
    QSet<QString> containerType = {"map", "set", "list"};

    QMap<QString, QMap<int, paramInfo>> funcParamInMap;

    QMap<QString, QMap<int, paramInfo>> funcParamOutMap;
    
    //第一个参数是结构体名，map里面string是序号
    QMap<QString, QMap<int, structInfo>> structParamMap;

    QMap<QString, QString> preDataMap;

    QMap<QString, QVector<QString>> preDataMapV;
    
    QMap<QString, QString> mapReqType = {{"CALL", THRIFT_CALL}, {"ONEWAY", THRIFT_ONEWAY}};
    
    QMap<QString, QString> ExceptionType = {{"1", "Unknown Method"}};
    
    
    QMap<QString, int> mapType = {{"bool", THRIFT_BOOL_TYPE}, {"byte", THRIFT_BYTE_TYPE}, {"i16", THRIFT_I16_TYPE}, {"i32", THRIFT_I32_TYPE},
                    {"i64", THRIFT_I64_TYPE}, {"double", THRIFT_DOUBLE_TYPE}, {"string", THRIFT_STRING_TYPE}, {"struct", THRIFT_STRUCT_TYPE}, 
                    {"map", THRIFT_MAP_TYPE}, {"set", THRIFT_SET_TYPE}, {"list", THRIFT_LIST_TYPE}};
    
    QMap<QString, int> mapSize = {{"bool", THRIFT_BOOL_SIZE}, {"byte", THRIFT_BYTE_SIZE}, {"i16", THRIFT_I16_SIZE}, {"i32", THRIFT_I32_SIZE},
                    {"i64", THRIFT_I64_SIZE}, {"double", THRIFT_DOUBLE_SIZE}, {"string", THRIFT_STRING_SIZE}, {"struct", THRIFT_STRUCT_SIZE}, 
                    {"map", THRIFT_MAP_SIZE}, {"set", THRIFT_SET_SIZE}, {"list", THRIFT_LIST_SIZE}};

    QVector<QString> dataList;
    QVector<QString> dataList_m;
    QString lastValue_;
    QString last2Value_;
    Ui::thriftwidget *ui;
    bool isFirstRead = true;
    int64_t needRead = 0;
    QStringList dataSource;
    QVector<uint32_t> receivedData;
    bool isCreateNode = false;

    //压测
    int64_t count = 0;
    qint64 elapsedMillisecondsAll = 0;
    bool isTestModle = false; //是否压测模式 
    QThreadPool threadpool;
    QChartView *chartView = nullptr;
    QChart *chart = nullptr;
    prefabricatedata * preData;

    int maxPoints = 50;
    QChart *chart_cpu;
    QChartView *chartView_cpu;
    QLineSeries * series_cpu2;
    QAreaSeries *areaSeries_cpu;
    QValueAxis *axisX_cpu;
    QValueAxis *axisY_cpu;
    QVector<qreal> data_cpu;

    QChart *chart_mem;
    QChartView *chartView_mem;
    QLineSeries * series_mem;
    QAreaSeries *areaSeries_mem;
    QValueAxis *axisX_mem;
    QValueAxis *axisY_mem;
    QVector<qreal> data_mem;

    QChart *chart_io;
    QChartView *chartView_io;
    QLineSeries * series_io;
    QAreaSeries *areaSeries_io;
    QValueAxis *axisX_io;
    QValueAxis *axisY_io;
    QVector<qreal> data_io;

    int maxPointsP = 50;
    QChart *chart_p;
    QChartView *chartView_p;
    QLineSeries * series_p1;
    QAreaSeries *areaSeries_p1;
    QLineSeries * series_p2;
    QAreaSeries *areaSeries_p2;
    QLineSeries * series_p3;
    QAreaSeries *areaSeries_p3;
    QLineSeries * series_p4;
    QAreaSeries *areaSeries_p4;
    QValueAxis *axisX_p;
    QValueAxis *axisY_p;
    QVector<qreal> data_p1;
    QVector<qreal> data_p2;
    QVector<qreal> data_p3;
    QVector<qreal> data_p4;

    sshsql * db;
    QThread * threadExec;
    sshHandleExec * sshExec;

    explicit thriftwidget(QWidget *parent = 0);
    void ceateItem();
    QString getCpuInfo(const QString &cmd);
    QString getType(int index);
    QString getType(QString data);
    QString getValue(QString data);
    ~thriftwidget();

    

    uint32_t string2Uint32(QString data);  //将四字节字符串转为需要发送的uint32
    uint16_t string2Uint16(QString data);  //将四字节字符转换位需要发送的uint16
    QVector<uint32_t> string2Uint32List(QVector<QString> & data);
    QVector<uint16_t> string2Uint16List(QVector<QString> & data);
    QVector<uint8_t>  string2Uint8List(QVector<QString> & data);
    void string2stringList(QString data);

    //组装数据 不再使用
    void buildData();

    void baseSerialize(int serialNumber, QString valueType, QString value);
    void containerSerialize(int serialNumber, QString valueType, QString value, QString keyType_, QString valyeType_ = "");
    void structSerialize(int serialNumber, QString valueType, ItemWidget * item);

    void map2List(QStringList &dataList, QString data);

    //清空消息
    void cleanMessage();

    //组装二进制协议消息
    void assembleTBinaryMessage(int buildType = 0, int num = 0);  //0表示普通请求，1表示压测

    //设置二进制请求类型，接口长度，接口名，流水号
    void writeTBinaryHeadMessage(QString serialNumber = "00000000");

    //设置类型序号
    void writeTBinaryTypeAndSerialNumber(QString valueType, int serialNumber);

    //组装基础类型数据
    void writeTBinaryBaseMessage(QString valueType, QString value);

    //组装集合类型数据
    void writeTBinaryCollectionMessage(QString valueType, QString value, ItemWidget *item, QString paramKeyType, QString paramValueType);

    //组装结构体数据
    void writeTBinaryStructMessage(QString valueType, ItemWidget * item, int buildType = 0, int num = 0);

    //写入结束
    void writeTBinaryEndMessage();

    //数据头写入数据长度
    void writeTBinarySizeMessage();

    //写入类型
    void writeTBinaryTypeMessage(QString type_);

    //写入元素数量
    void writeTBinaryKeySize(QStringList &dataList, QString value);

    //写入元素数量2
    void writeTBinaryValueSize(QStringList &dataList, QString value);

    //写入数据
    template<class T>
    void writeTBinaryFormatData(T value, QString valueType) {
       QString fromatData = QString("%1").arg(value, mapSize.value(valueType), 16, QLatin1Char('0'));
       //qDebug() << "writeTBinaryFormatData fromatData =" << fromatData;
       string2stringList(fromatData);
    }

    template<>
    void writeTBinaryFormatData(double value, QString valueType) {
        qulonglong d_long = *(qulonglong*)&value;
        QString fromatData = QString("%1").arg(d_long, mapSize.value(valueType), 16, QLatin1Char('0'));
        QString reversedString;
        while (fromatData.length()!=0) {
            reversedString = reversedString + fromatData.mid(fromatData.length()-2);
            fromatData = fromatData.mid(0, fromatData.length()-2);
        }
        string2stringList(reversedString);
    }

    template<>
    void writeTBinaryFormatData(QString value, QString valueType) {
        //注意中文占三个
        int len = value.length();
        if (value.contains(QRegExp("[\\x4e00-\\x9fff]+"))) {
            //应该判断包含多少个汉字，然后*2
            int count = 0;
            for (QChar c : value) {
                if (c >= QChar(0x4e00) && c <= QChar(0x9fff)) {
                    count++;
                }
            }
            len = len + count*2;
        }
        QString lenData = QString("%1").arg(len, mapSize.value("i32"), 16, QLatin1Char('0'));
        string2stringList(lenData);
        QString valueData = value.toUtf8().toHex();
        string2stringList(valueData);
    }

    void handleMessage(QTextEdit * textEdit_data, QString &data);

    //添加颜色
    QString addColorHtml(QString str, QColor *fontCrl);

    //添加字段颜色
    QString addColorFieldHtml(QString str);

    //添加字段 数值颜色
    QString addColorValueNumHtml(QString str);
    //添加字段 字符串颜色
    QString addColorValueStrHtml(QString str);
    //添加括号颜色
    QString addColorBracketsHtml(QString str);

    QString handleBool(QTextEdit * textEdit_data, QString &str, QString isEnd, QString paramName = "", bool isHandEnd = true, bool isLastEnd = false);

    QString handleByte(QTextEdit * textEdit_data, QString &str, QString isEnd, QString paramName = "", bool isHandEnd = true, bool isLastEnd = false);

    QString handleDouble(QTextEdit * textEdit_data, QString &str, QString isEnd, QString paramName = "", bool isHandEnd = true, bool isLastEnd = false);

    QString handleI16(QTextEdit * textEdit_data, QString &str, QString isEnd, QString paramName = "", bool isHandEnd = true, bool isLastEnd = false);

    QString handleI32(QTextEdit * textEdit_data, QString &str, QString isEnd, QString resType = THRIFT_REPLY, QString paramName = "", bool isHandEnd = true, bool isLastEnd = false);

    QString handleI64(QTextEdit * textEdit_data, QString &str, QString isEnd, QString paramName = "", bool isHandEnd = true, bool isLastEnd = false);

    QString handleString(QTextEdit * textEdit_data, QString &str, QString isEnd, QString resType = THRIFT_REPLY, QString paramName = "", bool isHandEnd = true, bool isLastEnd = false);

    QString handleStruct(QTextEdit * textEdit_data, QString &str, QString isEnd, QString outType = "", QString outParam = "", bool isHandEnd = true);

    QString handleMap(QTextEdit * textEdit_data, QString &str, QString isEnd, QString outType = "", QString paramName = "", bool isHandEnd = true);

    void handleMap_key(QTextEdit * textEdit_data, QString &str, QString isEnd, QString outType, QString & temp, bool isHandEnd = true);
    void handleMap_value(QTextEdit * textEdit_data, QString &str, QString isEnd, QString outType, QString & temp, bool isHandEnd = true);

    QString handleSet(QTextEdit * textEdit_data, QString &str, QString isEnd, QString outType = "", QString outParam = "", bool isHandEnd = true);

    QString handleList(QTextEdit * textEdit_data, QString &str, QString isEnd, QString outType = "", QString outParam = "", bool isHandEnd = true);
    
    QString handleEnd(QTextEdit * textEdit_data, QString &str);

    QString hexToString(QTextEdit * textEdit_data, QString& hex);

    QString hexToLongNumber(QTextEdit * textEdit_data, QString& hex);

    void removeLastComma(QString &str); //移除最后的逗号

    QString getRetract(); //获取缩进

    void deleteComments(char* buf, int n); //删除注释

    void handleComments(QString &fileContent);

    void handleExtraSpace(QString &func, QString type);

    bool containsChinese(QString str);

    QString getServerInterface(QString &fileContent);

    //获取结构体信息
    void getStructInfo(QString &fileContent);
    
    //获取入参
    QMap<int, paramInfo> getFuncInParams(QString data, bool & isok);

    //获取出参
    QMap<int, paramInfo> getFuncOutParams(QString data);

    //获取结构体信息
    QMap<int, structInfo> getStructParams(QString data);
    
    //创建节点
    static ItemWidget* createAndGetNode(thriftwidget * p);
    static ItemWidget* createAndGetNode(thriftwidget * p, QTreeWidget *parent);
    static ItemWidget* createAndGetNode(thriftwidget * p, QTreeWidgetItem *parent);

    //将二进制数据进行解析
    void handleBinData();
    //将十六进制数据进行解析
    void handleHexData(QTextEdit * textEdit_data, QTextEdit * textEdit_data2, QString& data);

    //读取预制数据
    void readPreData();
    //预制数据存在多个 user:${thift/dadsa.txt}
    void readPreDataVector(QString key, QString path);

    //解析thrift文件
    void handleThriftFile(QStringList fileList);
    
    //计算每个线程的工作数

    QVector<int> distributeRequests(int totalRequests, int numThreads);

    QString  detectEncoding(const QByteArray &data);

    void buildChart1();
    void updateChart1(int value);
    void buildChart2();
    void updateChart2(int value);
    void buildChart3();
    void updateChart3(int value);
    void buildChartP();
    void updateChartP(int value1, int value2);

private slots:
    void on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column);
    void read_data();
    void rece_deleteItem(QTreeWidgetItem * item);
    void rece_addItem(QTreeWidgetItem * item);
    void rece_addColumn(QTreeWidgetItem * item);
    void rece_TextChanged(QString data, QTreeWidgetItem * item);
    void rece_currentIndexChanged(QString data, QTreeWidgetItem * item);

    void on_toolButton_test_clicked();

    void on_toolButton_show_thrift_info_clicked();

    void on_comboBox_testType_currentIndexChanged(int index);

    void on_toolButton_request_clicked();

    void on_toolButton_request_param_clicked();

    void on_toolButton_response_clicked();

    void on_toolButton_report_clicked();

    void on_checkBox_show_source_stateChanged(int arg1);

    
    void on_toolButton_inportFile_clicked();

    void on_treeWidget_api_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous);

    void on_textEdit_customContextMenuRequested(const QPoint &pos);

    void rece_textEditCopy();
    void rece_textEditPaste();
    void rece_textEditAll();

    void on_textEdit_data_customContextMenuRequested(const QPoint &pos);

    void rece_textEdit_dataCopy();
    void rece_textEdit_dataPaste();
    void rece_textEdit_dataAll();

    void on_plainTextEdit_edit_customContextMenuRequested(const QPoint &pos);

    void rece_plainTextEdit_editCopy();
    void rece_plainTextEdit_editPaste();
    void rece_plainTextEdit_editAll();

    void on_toolButton_doc_switch_clicked();

    void rece_activated(const QString & text);

    void rece_highlighted(const QString & text);

    void on_toolButton_propertyTest_clicked();

    void rece_propertyTestDone(RequestResults * rr);

    void rece_propertyTestSchedule(int value);

    void sendThriftRequest(QVector<uint8_t> dataArray, QElapsedTimer* timer);

    //http传输协议
    void sendHttpRequest(QVector<uint8_t> dataArray, QElapsedTimer* timer);


    void on_toolButton_return_clicked();

    void on_checkBox_show_source_clicked();

    void on_toolButton_export_clicked();

    void on_toolButton_returnTest_clicked();

    void on_toolButton_preData_clicked();

    void rece_updateMouseStyle();

    void on_toolButton_capturePackage_clicked();

    void rece_execCommand(QString data);

    void rece_ssh_exec_init(bool isok);

    void printHex(const QByteArray &data, int number);

    void on_toolButton_inportpcap_clicked();

    void on_tableWidget_func_itemClicked(QTableWidgetItem *item);

    void parseSLLHeader(const QByteArray &data, int &offset);

    void parseIPv4Header(const QByteArray &data, int &offset, quint8 &protocol, int &ipHeaderLen, TableEntry& entry);

    QString parseTCPHeader(const QByteArray &data, int &offset, int number, TableEntry& entry);
    void on_tableWidget_func_itemSelectionChanged();

    void on_checkBox_show_json_stateChanged(int arg1);

    void on_checkBox_super_stateChanged(int arg1);

    void on_tabWidget_2_currentChanged(int index);

    void on_horizontalSlider_sliderMoved(int position);

    void on_horizontalSlider_valueChanged(int value);

    void rece_getServerInfo(ServerInfoStruct serverInfo);

    void on_toolButton_5_clicked();

    void on_toolButton_6_clicked();

    void onReadyReadOutput();
    void onReadyReadError();

    void on_toolButton_7_clicked();

    void on_lineEdit_host_textChanged(const QString &arg1);
    void on_comboBox_port_currentIndexChanged(const QString &arg1);

    void on_toolButton_8_clicked();

    void on_comboBox_transport_currentTextChanged(const QString &arg1);

    void on_toolButton_close_clicked();
};

Q_DECLARE_METATYPE(QVector<uint8_t>);

Q_DECLARE_METATYPE(QElapsedTimer*);
Q_DECLARE_METATYPE(RequestResults*);

class TestRunnable : public QObject, public QRunnable {
    Q_OBJECT
public:
    QString host_;
    int port_;
    bool isok = false;
    //QElapsedTimer * timer_;
    RequestResults * rr_ = nullptr;
    //QTcpSocket * clientSocket = nullptr;
    //QVector<QTcpSocket *> clientSocketS;
    QVector<uint32_t> receivedData;
    int64_t count_ = 0;
    int64_t totalRequests_ = 0;
    int64_t needRead = 0;
    QObject * obj_;
    QVector<uint8_t> sendData_;
    QVector<QVector<uint8_t>> sendDataS_;
    bool isFirstRead = true;
    qint64 elapsedMillisecondsAll = 0;
    int connectTimeOut_ = 0;
    int requestTimeOut_ = 0;

    TestRunnable(QObject * obj, QVector<uint8_t> sendData, RequestResults * rr, QString host, int port, int connectTimeOut, int requestTimeOut){
        obj_ = obj;
        sendData_ = sendData;
        //timer_ = timer;
        rr_ = rr;
        host_ = host;
        port_ = port;
        connectTimeOut_ = connectTimeOut;
        requestTimeOut_ = requestTimeOut;
    }

    TestRunnable(QObject * obj, QVector<QVector<uint8_t>> sendDataS, RequestResults * rr, QString host, int port, int connectTimeOut, int requestTimeOut, int count){
        obj_ = obj;
        sendDataS_ = sendDataS;
        //timer_ = timer;
        rr_ = rr;
        host_ = host;
        port_ = port;
        connectTimeOut_ = connectTimeOut;
        requestTimeOut_ = requestTimeOut;
        count_ = count;
        totalRequests_ = count;
    }

    void batchSendThriftRequest(QTcpSocket * clientSocket, QVector<uint8_t> dataArray, RequestResults * rr, QString host, int port, int connectTimeOut, int requestTimeOut);
    ~TestRunnable() {
        //不需要释放
    }

    void run() override {
        QVector<QTcpSocket *> clientSocketS;
        clientSocketS.resize(count_);
        for (int i = 0; i < clientSocketS.size(); ++i) {
            clientSocketS[i] = new QTcpSocket();
            if (rr_->isN) {
                clientSocketS[i]->setSocketOption(QAbstractSocket::LowDelayOption, 1);
            }
        }
        QElapsedTimer timer_run;
        timer_run.start();
        for(int i = 0; i< totalRequests_; i++) {
            batchSendThriftRequest(clientSocketS.at(i), sendDataS_.at(i), rr_, host_, port_, connectTimeOut_, requestTimeOut_);
        }

        while(!isok && timer_run.elapsed() < requestTimeOut_) { //&& timer_run.elapsed() < 800
            QCoreApplication::processEvents();
        }
        if (!isok) {
            qDebug() << "超时" << "  thread ID:" << QThread::currentThreadId() << "   time = " << timer_run.elapsed();
            //失败+1
            rr_->setFailCount(1);
            //记录请求时间
            qint64 elapsedMilliseconds = timer_run.elapsed();
            rr_->setResults(elapsedMilliseconds);
            //记录结束时间
            rr_->setEndTime(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz"));
            
        }
        rr_->mutex.lock();
        //请求加1
        rr_->decrease(totalRequests_);
        //qDebug() << " isok = " << isok;
        //记录分段数据
        rr_->setSectionData();
        if (rr_->count == 0) {
            QMetaObject::invokeMethod(obj_,"rece_propertyTestDone",Qt::QueuedConnection, Q_ARG(RequestResults*,rr_));
            QMetaObject::invokeMethod(obj_,"rece_propertyTestSchedule",Qt::QueuedConnection, Q_ARG(int, 100));
        }else {
            QMetaObject::invokeMethod(obj_,"rece_propertyTestSchedule",Qt::QueuedConnection, Q_ARG(int,rr_->totalTimes/rr_->count));
            
        }
        rr_->mutex.unlock();
    }
};


class EnglishOnlyFilter : public QObject
{
    Q_OBJECT
protected:
    bool eventFilter(QObject *obj, QEvent *event) override
    {
        if (event->type() == QEvent::InputMethodQuery) {
            QInputMethodQueryEvent *queryEvent = static_cast<QInputMethodQueryEvent*>(event);
            if (queryEvent->queries() & Qt::ImEnabled) {
                // 如果输入法激活，表示正在进行中文输入，则忽略此事件
                return true;
            }
        } else if (event->type() == QEvent::KeyPress) {
            QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
            QString text = keyEvent->text();
            //qDebug() << "text =" << text;
            // 检查输入的文本是否为英文字符（A-Z、a-z）或数字（0-9）
            if (!text.isEmpty() && !(text >= "A" && text <= "Z") && !(text >= "a" && text <= "z")
                    && !(text >= "0" && text <= "9") && !(keyEvent->key() == Qt::Key_Backspace)
                    && !(text == "\u0001") && !(text == "\u0003") && !(text == "\u0016") && !(text == "\u001A")) {
                return true; // 忽略非英文字符和数字
            }
        } else if (event->type() == QEvent::InputMethod) {
            // 对于输入法事件，获取输入的文本
            QInputMethodEvent *inputMethodEvent = static_cast<QInputMethodEvent*>(event);
            QString text = inputMethodEvent->commitString();
            // 检查输入的文本是否为英文字符（A-Z、a-z）或数字（0-9）
            if (!text.isEmpty()) {
                bool containsNonEnglishOrDigit = false;
                for (const QChar &ch : text) {
                    if (!(ch >= 'A' && ch <= 'Z') && !(ch >= 'a' && ch <= 'z')
                            && !(ch >= '0' && ch <= '9')) {
                        containsNonEnglishOrDigit = true;
                        break;
                    }
                }
                if (containsNonEnglishOrDigit) {
                    return true; // 忽略非英文字符和数字
                }
            }
        }
        return QObject::eventFilter(obj, event);
    }
};



#endif // THRIFTWIDGET_H
