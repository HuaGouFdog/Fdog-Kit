/****************************************************************************
** Meta object code from reading C++ file 'sshwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../sshwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sshwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_KeyFilter_t {
    QByteArrayData data[3];
    char stringdata0[27];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KeyFilter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KeyFilter_t qt_meta_stringdata_KeyFilter = {
    {
QT_MOC_LITERAL(0, 0, 9), // "KeyFilter"
QT_MOC_LITERAL(1, 10, 15), // "send_enter_sign"
QT_MOC_LITERAL(2, 26, 0) // ""

    },
    "KeyFilter\0send_enter_sign\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KeyFilter[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

void KeyFilter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        KeyFilter *_t = static_cast<KeyFilter *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->send_enter_sign(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (KeyFilter::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KeyFilter::send_enter_sign)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject KeyFilter::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_KeyFilter.data,
      qt_meta_data_KeyFilter,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *KeyFilter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KeyFilter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_KeyFilter.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int KeyFilter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void KeyFilter::send_enter_sign()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_sshwidget_t {
    QByteArrayData data[11];
    char stringdata0[163];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_sshwidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_sshwidget_t qt_meta_stringdata_sshwidget = {
    {
QT_MOC_LITERAL(0, 0, 9), // "sshwidget"
QT_MOC_LITERAL(1, 10, 33), // "on_textEdit_cursorPositionCha..."
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 9), // "rece_init"
QT_MOC_LITERAL(4, 55, 17), // "rece_channel_read"
QT_MOC_LITERAL(5, 73, 4), // "data"
QT_MOC_LITERAL(6, 78, 15), // "rece_enter_sign"
QT_MOC_LITERAL(7, 94, 18), // "rece_getServerInfo"
QT_MOC_LITERAL(8, 113, 16), // "ServerInfoStruct"
QT_MOC_LITERAL(9, 130, 10), // "serverInfo"
QT_MOC_LITERAL(10, 141, 21) // "on_pushButton_clicked"

    },
    "sshwidget\0on_textEdit_cursorPositionChanged\0"
    "\0rece_init\0rece_channel_read\0data\0"
    "rece_enter_sign\0rece_getServerInfo\0"
    "ServerInfoStruct\0serverInfo\0"
    "on_pushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_sshwidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    1,   46,    2, 0x08 /* Private */,
       6,    0,   49,    2, 0x08 /* Private */,
       7,    1,   50,    2, 0x08 /* Private */,
      10,    0,   53,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,

       0        // eod
};

void sshwidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        sshwidget *_t = static_cast<sshwidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_textEdit_cursorPositionChanged(); break;
        case 1: _t->rece_init(); break;
        case 2: _t->rece_channel_read((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->rece_enter_sign(); break;
        case 4: _t->rece_getServerInfo((*reinterpret_cast< ServerInfoStruct(*)>(_a[1]))); break;
        case 5: _t->on_pushButton_clicked(); break;
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
    }
}

const QMetaObject sshwidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_sshwidget.data,
      qt_meta_data_sshwidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *sshwidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *sshwidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_sshwidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int sshwidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
