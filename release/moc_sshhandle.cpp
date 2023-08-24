/****************************************************************************
** Meta object code from reading C++ file 'sshhandle.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../sshhandle.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sshhandle.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_sshhandle_t {
    QByteArrayData data[23];
    char stringdata0[250];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_sshhandle_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_sshhandle_t qt_meta_stringdata_sshhandle = {
    {
QT_MOC_LITERAL(0, 0, 9), // "sshhandle"
QT_MOC_LITERAL(1, 10, 9), // "send_init"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 14), // "send_init_poll"
QT_MOC_LITERAL(4, 36, 18), // "send_channel_write"
QT_MOC_LITERAL(5, 55, 4), // "data"
QT_MOC_LITERAL(6, 60, 17), // "send_channel_read"
QT_MOC_LITERAL(7, 78, 18), // "send_getServerInfo"
QT_MOC_LITERAL(8, 97, 16), // "ServerInfoStruct"
QT_MOC_LITERAL(9, 114, 10), // "serverInfo"
QT_MOC_LITERAL(10, 125, 4), // "init"
QT_MOC_LITERAL(11, 130, 12), // "connrectType"
QT_MOC_LITERAL(12, 143, 4), // "host"
QT_MOC_LITERAL(13, 148, 4), // "port"
QT_MOC_LITERAL(14, 153, 8), // "username"
QT_MOC_LITERAL(15, 162, 8), // "password"
QT_MOC_LITERAL(16, 171, 9), // "init_poll"
QT_MOC_LITERAL(17, 181, 13), // "channel_write"
QT_MOC_LITERAL(18, 195, 7), // "command"
QT_MOC_LITERAL(19, 203, 12), // "channel_read"
QT_MOC_LITERAL(20, 216, 13), // "getServerInfo"
QT_MOC_LITERAL(21, 230, 11), // "commondExec"
QT_MOC_LITERAL(22, 242, 7) // "commond"

    },
    "sshhandle\0send_init\0\0send_init_poll\0"
    "send_channel_write\0data\0send_channel_read\0"
    "send_getServerInfo\0ServerInfoStruct\0"
    "serverInfo\0init\0connrectType\0host\0"
    "port\0username\0password\0init_poll\0"
    "channel_write\0command\0channel_read\0"
    "getServerInfo\0commondExec\0commond"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_sshhandle[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,
       3,    0,   70,    2, 0x06 /* Public */,
       4,    1,   71,    2, 0x06 /* Public */,
       6,    1,   74,    2, 0x06 /* Public */,
       7,    1,   77,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    5,   80,    2, 0x0a /* Public */,
      16,    0,   91,    2, 0x0a /* Public */,
      17,    1,   92,    2, 0x0a /* Public */,
      19,    1,   95,    2, 0x0a /* Public */,
      20,    0,   98,    2, 0x0a /* Public */,
      21,    1,   99,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, 0x80000000 | 8,    9,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   11,   12,   13,   14,   15,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   18,
    QMetaType::Void, QMetaType::QString,   18,
    QMetaType::Void,
    QMetaType::QString, QMetaType::QString,   22,

       0        // eod
};

void sshhandle::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        sshhandle *_t = static_cast<sshhandle *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->send_init(); break;
        case 1: _t->send_init_poll(); break;
        case 2: _t->send_channel_write((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->send_channel_read((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->send_getServerInfo((*reinterpret_cast< ServerInfoStruct(*)>(_a[1]))); break;
        case 5: _t->init((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5]))); break;
        case 6: _t->init_poll(); break;
        case 7: _t->channel_write((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->channel_read((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->getServerInfo(); break;
        case 10: { QString _r = _t->commondExec((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ServerInfoStruct >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (sshhandle::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&sshhandle::send_init)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (sshhandle::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&sshhandle::send_init_poll)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (sshhandle::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&sshhandle::send_channel_write)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (sshhandle::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&sshhandle::send_channel_read)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (sshhandle::*_t)(ServerInfoStruct );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&sshhandle::send_getServerInfo)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject sshhandle::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_sshhandle.data,
      qt_meta_data_sshhandle,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *sshhandle::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *sshhandle::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_sshhandle.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int sshhandle::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void sshhandle::send_init()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void sshhandle::send_init_poll()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void sshhandle::send_channel_write(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void sshhandle::send_channel_read(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void sshhandle::send_getServerInfo(ServerInfoStruct _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
