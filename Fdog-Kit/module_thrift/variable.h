#ifndef VARIABLE_H
#define VARIABLE_H

#include <QString>
#include <QMap>
#include <QSet>

//请求类型
#define THRIFT_CALL        "80010001"
#define THRIFT_REPLY       "80010002"
#define THRIFT_EXCEPTION   "80010003"
#define THRIFT_ONEWAY      "80010004"

//字段类型编号两个字节
#define THRIFT_BOOL_TYPE   2
#define THRIFT_BYTE_TYPE   3
#define THRIFT_I16_TYPE    6
#define THRIFT_I32_TYPE    8
#define THRIFT_I64_TYPE    10
#define THRIFT_DOUBLE_TYPE 4
#define THRIFT_STRING_TYPE 11
#define THRIFT_STRUCT_TYPE 12
#define THRIFT_MAP_TYPE    13
#define THRIFT_SET_TYPE    14
#define THRIFT_LIST_TYPE   15

//字段类型占用长度  1字节数=2个长度
#define THRIFT_BOOL_SIZE        2
#define THRIFT_BYTE_SIZE        2
#define THRIFT_I16_SIZE         4
#define THRIFT_I32_SIZE         8
#define THRIFT_I64_SIZE         16
#define THRIFT_DOUBLE_SIZE      16
#define THRIFT_STRING_SIZE      0
#define THRIFT_STRUCT_SIZE      0
#define THRIFT_MAP_SIZE         0
#define THRIFT_SET_SIZE         0
#define THRIFT_LIST_SIZE        0

#define TFramedTransport_   "FRAMED"
#define TBufferedTransport_ "BUFFERED"
#define THTTPSTransport_    "HTTPS"
#define THTTPTransport_     "HTTP"

#define TBinaryProtocol_ "Binary"


enum ObjectType {
	OBJECT_BASE = 1,
	OBJECT_STRUCT,
	OBJECT_LIST,
	OBJECT_SET,
    OBJECT_MAP,
};


struct paramInfo {
    QString paramType; //参数类型
    QString paramName; //参数名
    QString typeSign;   //描述符 1 opt-in, req-out 默认 1 required 2 optional  这个是必opt-in, req-out
};

struct structInfo {
    QString paramType;  //参数类型
    QString paramName;  //参数名
    QString typeSign;   //描述符 1 opt-in, req-out 默认 1 required 2 optional
};


struct PcapFileHeader {
    uint32_t magic;       // 文件标识
    uint16_t versionMajor;
    uint16_t versionMinor;
    int32_t thisZone;
    uint32_t sigFigs;
    uint32_t snapLen;
    uint32_t linkType;
};

// pcap 数据包头
//struct PcapPacketHeader {
//    uint32_t tsSec;      // 时间戳（秒）
//    uint32_t tsUsec;     // 时间戳（微秒）
//    uint32_t capLen;     // 捕获的数据包长度
//    uint32_t origLen;    // 原始数据包长度
//};

// 以太网帧头部（最基本的帧，不包含 802.1Q VLAN）
struct EthernetHeader {
    uint8_t destMac[6]; // 目标 MAC
    uint8_t srcMac[6];  // 源 MAC
    uint16_t etherType; // 以太网类型（IPv4 = 0x0800）
};

// IPv4 头部
struct IPv4Header {
    uint8_t ihl : 4, version : 4;
    uint8_t tos;
    uint16_t totalLength;
    uint16_t identification;
    uint16_t flagsFragmentOffset;
    uint8_t ttl;
    uint8_t protocol; // TCP = 6
    uint16_t headerChecksum;
    uint32_t srcIP;
    uint32_t destIP;
};

// TCP 头部
struct TCPHeader {
    uint16_t srcPort;
    uint16_t destPort;
    uint32_t seqNum;
    uint32_t ackNum;
    uint8_t dataOffset;
    uint8_t flags;
    uint16_t windowSize;
    uint16_t checksum;
    uint16_t urgentPointer;
};

#pragma pack(1)  // 避免结构体填充

struct PcapHeader {
    quint32 magic;
    quint16 version_major;
    quint16 version_minor;
    quint32 thiszone;
    quint32 sigfigs;
    quint32 snaplen;
    quint32 network;
};

struct PcapPacketHeader {
    quint32 ts_sec;
    quint32 ts_usec;
    quint32 incl_len;
    quint32 orig_len;
};

#pragma pack() 

struct TableEntry {
    int index;         // 序号
    QString time;      // 时间
    QString flag;      // 标志
    QString request;   // 请求源
    QString target;    // 目标源
    QString info;      // 信息
};

#endif // VARIABLE_H
