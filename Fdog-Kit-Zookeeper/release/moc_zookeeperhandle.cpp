/****************************************************************************
** Meta object code from reading C++ file 'zookeeperhandle.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../module_zookeeper/zookeeperhandle.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'zookeeperhandle.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ZkRunnable_t {
    QByteArrayData data[1];
    char stringdata0[11];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ZkRunnable_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ZkRunnable_t qt_meta_stringdata_ZkRunnable = {
    {
QT_MOC_LITERAL(0, 0, 10) // "ZkRunnable"

    },
    "ZkRunnable"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ZkRunnable[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void ZkRunnable::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject ZkRunnable::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ZkRunnable.data,
      qt_meta_data_ZkRunnable,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ZkRunnable::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ZkRunnable::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZkRunnable.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QRunnable"))
        return static_cast< QRunnable*>(this);
    return QObject::qt_metacast(_clname);
}

int ZkRunnable::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_zookeeperhandle_t {
    QByteArrayData data[32];
    char stringdata0[319];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_zookeeperhandle_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_zookeeperhandle_t qt_meta_stringdata_zookeeperhandle = {
    {
QT_MOC_LITERAL(0, 0, 15), // "zookeeperhandle"
QT_MOC_LITERAL(1, 16, 9), // "send_init"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 12), // "connectState"
QT_MOC_LITERAL(4, 40, 4), // "code"
QT_MOC_LITERAL(5, 45, 7), // "message"
QT_MOC_LITERAL(6, 53, 4), // "path"
QT_MOC_LITERAL(7, 58, 5), // "count"
QT_MOC_LITERAL(8, 64, 16), // "send_getChildren"
QT_MOC_LITERAL(9, 81, 8), // "varValue"
QT_MOC_LITERAL(10, 90, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(11, 107, 4), // "item"
QT_MOC_LITERAL(12, 112, 16), // "send_setNodeData"
QT_MOC_LITERAL(13, 129, 16), // "send_getNodeInfo"
QT_MOC_LITERAL(14, 146, 4), // "data"
QT_MOC_LITERAL(15, 151, 15), // "send_createNode"
QT_MOC_LITERAL(16, 167, 15), // "send_deleteNode"
QT_MOC_LITERAL(17, 183, 4), // "init"
QT_MOC_LITERAL(18, 188, 8), // "rootPath"
QT_MOC_LITERAL(19, 197, 4), // "host"
QT_MOC_LITERAL(20, 202, 4), // "port"
QT_MOC_LITERAL(21, 207, 7), // "timeout"
QT_MOC_LITERAL(22, 215, 11), // "getChildren"
QT_MOC_LITERAL(23, 227, 4), // "int&"
QT_MOC_LITERAL(24, 232, 17), // "getSingleChildren"
QT_MOC_LITERAL(25, 250, 4), // "obj_"
QT_MOC_LITERAL(26, 255, 11), // "setNodeData"
QT_MOC_LITERAL(27, 267, 8), // "nodePath"
QT_MOC_LITERAL(28, 276, 8), // "nodeData"
QT_MOC_LITERAL(29, 285, 11), // "getNodeInfo"
QT_MOC_LITERAL(30, 297, 10), // "createNode"
QT_MOC_LITERAL(31, 308, 10) // "deleteNode"

    },
    "zookeeperhandle\0send_init\0\0connectState\0"
    "code\0message\0path\0count\0send_getChildren\0"
    "varValue\0QTreeWidgetItem*\0item\0"
    "send_setNodeData\0send_getNodeInfo\0"
    "data\0send_createNode\0send_deleteNode\0"
    "init\0rootPath\0host\0port\0timeout\0"
    "getChildren\0int&\0getSingleChildren\0"
    "obj_\0setNodeData\0nodePath\0nodeData\0"
    "getNodeInfo\0createNode\0deleteNode"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_zookeeperhandle[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    5,   79,    2, 0x06 /* Public */,
       8,    5,   90,    2, 0x06 /* Public */,
      12,    2,  101,    2, 0x06 /* Public */,
      13,    5,  106,    2, 0x06 /* Public */,
      15,    6,  117,    2, 0x06 /* Public */,
      16,    3,  130,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      17,    4,  137,    2, 0x0a /* Public */,
      22,    3,  146,    2, 0x0a /* Public */,
      24,    2,  153,    2, 0x0a /* Public */,
      26,    2,  158,    2, 0x0a /* Public */,
      29,    1,  163,    2, 0x0a /* Public */,
      30,    3,  166,    2, 0x0a /* Public */,
      31,    2,  173,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::Int,    3,    4,    5,    6,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QVariant, 0x80000000 | 10,    4,    5,    6,    9,   11,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    4,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QVariant, QMetaType::QString, QMetaType::QString,    4,    5,    9,   14,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QVariant, QMetaType::QString, 0x80000000 | 10,    4,    5,    6,    9,   14,   11,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, 0x80000000 | 10,    4,    5,   11,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int,   18,   19,   20,   21,
    QMetaType::Void, 0x80000000 | 23, 0x80000000 | 23, QMetaType::QString,    4,    7,    6,
    QMetaType::Void, QMetaType::QString, QMetaType::VoidStar,    6,   25,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   27,   28,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, 0x80000000 | 10,   27,   28,   11,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 10,    6,   11,

       0        // eod
};

void zookeeperhandle::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        zookeeperhandle *_t = static_cast<zookeeperhandle *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->send_init((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 1: _t->send_getChildren((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< const QVariant(*)>(_a[4])),(*reinterpret_cast< QTreeWidgetItem*(*)>(_a[5]))); break;
        case 2: _t->send_setNodeData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->send_getNodeInfo((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QVariant(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5]))); break;
        case 4: _t->send_createNode((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QVariant(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QTreeWidgetItem*(*)>(_a[6]))); break;
        case 5: _t->send_deleteNode((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QTreeWidgetItem*(*)>(_a[3]))); break;
        case 6: _t->init((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 7: _t->getChildren((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 8: _t->getSingleChildren((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< void*(*)>(_a[2]))); break;
        case 9: _t->setNodeData((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 10: _t->getNodeInfo((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->createNode((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QTreeWidgetItem*(*)>(_a[3]))); break;
        case 12: _t->deleteNode((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QTreeWidgetItem*(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 4:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTreeWidgetItem* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 5:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTreeWidgetItem* >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTreeWidgetItem* >(); break;
            }
            break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTreeWidgetItem* >(); break;
            }
            break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTreeWidgetItem* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (zookeeperhandle::*_t)(int , int , QString , QString , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&zookeeperhandle::send_init)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (zookeeperhandle::*_t)(int , QString , QString , const QVariant , QTreeWidgetItem * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&zookeeperhandle::send_getChildren)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (zookeeperhandle::*_t)(int , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&zookeeperhandle::send_setNodeData)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (zookeeperhandle::*_t)(int , QString , QVariant , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&zookeeperhandle::send_getNodeInfo)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (zookeeperhandle::*_t)(int , QString , QString , QVariant , QString , QTreeWidgetItem * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&zookeeperhandle::send_createNode)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (zookeeperhandle::*_t)(int , QString , QTreeWidgetItem * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&zookeeperhandle::send_deleteNode)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject zookeeperhandle::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_zookeeperhandle.data,
      qt_meta_data_zookeeperhandle,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *zookeeperhandle::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *zookeeperhandle::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_zookeeperhandle.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int zookeeperhandle::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void zookeeperhandle::send_init(int _t1, int _t2, QString _t3, QString _t4, int _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void zookeeperhandle::send_getChildren(int _t1, QString _t2, QString _t3, const QVariant _t4, QTreeWidgetItem * _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void zookeeperhandle::send_setNodeData(int _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void zookeeperhandle::send_getNodeInfo(int _t1, QString _t2, QVariant _t3, QString _t4, QString _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void zookeeperhandle::send_createNode(int _t1, QString _t2, QString _t3, QVariant _t4, QString _t5, QTreeWidgetItem * _t6)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void zookeeperhandle::send_deleteNode(int _t1, QString _t2, QTreeWidgetItem * _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
