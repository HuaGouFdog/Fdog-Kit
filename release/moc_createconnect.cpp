/****************************************************************************
** Meta object code from reading C++ file 'createconnect.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../createconnect.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'createconnect.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_createconnect_t {
    QByteArrayData data[7];
    char stringdata0[112];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_createconnect_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_createconnect_t qt_meta_stringdata_createconnect = {
    {
QT_MOC_LITERAL(0, 0, 13), // "createconnect"
QT_MOC_LITERAL(1, 14, 9), // "newCreate"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 19), // "connnectInfoStruct&"
QT_MOC_LITERAL(4, 45, 8), // "newClose"
QT_MOC_LITERAL(5, 54, 29), // "on_pushButton_connect_clicked"
QT_MOC_LITERAL(6, 84, 27) // "on_pushButton_close_clicked"

    },
    "createconnect\0newCreate\0\0connnectInfoStruct&\0"
    "newClose\0on_pushButton_connect_clicked\0"
    "on_pushButton_close_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_createconnect[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       4,    0,   37,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   38,    2, 0x08 /* Private */,
       6,    0,   39,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void createconnect::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        createconnect *_t = static_cast<createconnect *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newCreate((*reinterpret_cast< connnectInfoStruct(*)>(_a[1]))); break;
        case 1: _t->newClose(); break;
        case 2: _t->on_pushButton_connect_clicked(); break;
        case 3: _t->on_pushButton_close_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (createconnect::*_t)(connnectInfoStruct & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&createconnect::newCreate)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (createconnect::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&createconnect::newClose)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject createconnect::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_createconnect.data,
      qt_meta_data_createconnect,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *createconnect::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *createconnect::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_createconnect.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int createconnect::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void createconnect::newCreate(connnectInfoStruct & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void createconnect::newClose()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
