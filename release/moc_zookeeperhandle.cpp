/****************************************************************************
** Meta object code from reading C++ file 'zookeeperhandle.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../zookeeperhandle.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
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
struct qt_meta_stringdata_zookeeperhandle_t {
    QByteArrayData data[25];
    char stringdata0[248];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_zookeeperhandle_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_zookeeperhandle_t qt_meta_stringdata_zookeeperhandle = {
    {
QT_MOC_LITERAL(0, 0, 15), // "zookeeperhandle"
QT_MOC_LITERAL(1, 16, 16), // "send_getChildren"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 4), // "path"
QT_MOC_LITERAL(4, 39, 8), // "varValue"
QT_MOC_LITERAL(5, 48, 16), // "QVector<QString>"
QT_MOC_LITERAL(6, 65, 8), // "dataList"
QT_MOC_LITERAL(7, 74, 12), // "QVector<int>"
QT_MOC_LITERAL(8, 87, 12), // "childrenList"
QT_MOC_LITERAL(9, 100, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(10, 117, 4), // "item"
QT_MOC_LITERAL(11, 122, 9), // "send_init"
QT_MOC_LITERAL(12, 132, 9), // "connected"
QT_MOC_LITERAL(13, 142, 4), // "data"
QT_MOC_LITERAL(14, 147, 18), // "send_getNodeInfo_2"
QT_MOC_LITERAL(15, 166, 4), // "init"
QT_MOC_LITERAL(16, 171, 8), // "rootPath"
QT_MOC_LITERAL(17, 180, 4), // "host"
QT_MOC_LITERAL(18, 185, 4), // "port"
QT_MOC_LITERAL(19, 190, 11), // "getChildren"
QT_MOC_LITERAL(20, 202, 11), // "getNodeInfo"
QT_MOC_LITERAL(21, 214, 5), // "Stat&"
QT_MOC_LITERAL(22, 220, 4), // "stat"
QT_MOC_LITERAL(23, 225, 8), // "QString&"
QT_MOC_LITERAL(24, 234, 13) // "getNodeInfo_2"

    },
    "zookeeperhandle\0send_getChildren\0\0"
    "path\0varValue\0QVector<QString>\0dataList\0"
    "QVector<int>\0childrenList\0QTreeWidgetItem*\0"
    "item\0send_init\0connected\0data\0"
    "send_getNodeInfo_2\0init\0rootPath\0host\0"
    "port\0getChildren\0getNodeInfo\0Stat&\0"
    "stat\0QString&\0getNodeInfo_2"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_zookeeperhandle[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    5,   49,    2, 0x06 /* Public */,
      11,    4,   60,    2, 0x06 /* Public */,
      14,    3,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      15,    3,   76,    2, 0x0a /* Public */,
      19,    2,   83,    2, 0x0a /* Public */,
      20,    3,   88,    2, 0x0a /* Public */,
      24,    1,   95,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QVariant, 0x80000000 | 5, 0x80000000 | 7, 0x80000000 | 9,    3,    4,    6,    8,   10,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString, QMetaType::QVariant, QMetaType::QString,   12,    3,    4,   13,
    QMetaType::Void, QMetaType::QVariant, QMetaType::QString, QMetaType::QString,    4,   13,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   16,   17,   18,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 9,    3,   10,
    QMetaType::Void, 0x80000000 | 21, 0x80000000 | 23, 0x80000000 | 23,   22,   13,    3,
    QMetaType::Void, QMetaType::QString,    3,

       0        // eod
};

void zookeeperhandle::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        zookeeperhandle *_t = static_cast<zookeeperhandle *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->send_getChildren((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2])),(*reinterpret_cast< QVector<QString>(*)>(_a[3])),(*reinterpret_cast< QVector<int>(*)>(_a[4])),(*reinterpret_cast< QTreeWidgetItem*(*)>(_a[5]))); break;
        case 1: _t->send_init((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< const QVariant(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 2: _t->send_getNodeInfo_2((*reinterpret_cast< QVariant(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 3: _t->init((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 4: _t->getChildren((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QTreeWidgetItem*(*)>(_a[2]))); break;
        case 5: _t->getNodeInfo((*reinterpret_cast< Stat(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 6: _t->getNodeInfo_2((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 4:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTreeWidgetItem* >(); break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QString> >(); break;
            case 3:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<int> >(); break;
            }
            break;
        case 4:
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
            typedef void (zookeeperhandle::*_t)(QString , const QVariant , QVector<QString> , QVector<int> , QTreeWidgetItem * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&zookeeperhandle::send_getChildren)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (zookeeperhandle::*_t)(bool , QString , const QVariant , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&zookeeperhandle::send_init)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (zookeeperhandle::*_t)(QVariant , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&zookeeperhandle::send_getNodeInfo_2)) {
                *result = 2;
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
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void zookeeperhandle::send_getChildren(QString _t1, const QVariant _t2, QVector<QString> _t3, QVector<int> _t4, QTreeWidgetItem * _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void zookeeperhandle::send_init(bool _t1, QString _t2, const QVariant _t3, QString _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void zookeeperhandle::send_getNodeInfo_2(QVariant _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
