/****************************************************************************
** Meta object code from reading C++ file 'zookeepermanagewidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../module_zookeeper/zookeepermanagewidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'zookeepermanagewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_zookeepermanagewidget_t {
    QByteArrayData data[12];
    char stringdata0[212];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_zookeepermanagewidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_zookeepermanagewidget_t qt_meta_stringdata_zookeepermanagewidget = {
    {
QT_MOC_LITERAL(0, 0, 21), // "zookeepermanagewidget"
QT_MOC_LITERAL(1, 22, 31), // "on_toolButton_newCreate_clicked"
QT_MOC_LITERAL(2, 54, 0), // ""
QT_MOC_LITERAL(3, 55, 26), // "on_toolButton_save_clicked"
QT_MOC_LITERAL(4, 82, 27), // "on_toolButton_close_clicked"
QT_MOC_LITERAL(5, 110, 21), // "on_toolButton_clicked"
QT_MOC_LITERAL(6, 132, 29), // "on_toolButton_connect_clicked"
QT_MOC_LITERAL(7, 162, 18), // "rece_buttonClicked"
QT_MOC_LITERAL(8, 181, 5), // "index"
QT_MOC_LITERAL(9, 187, 9), // "rece_init"
QT_MOC_LITERAL(10, 197, 9), // "buttonSid"
QT_MOC_LITERAL(11, 207, 4) // "code"

    },
    "zookeepermanagewidget\0"
    "on_toolButton_newCreate_clicked\0\0"
    "on_toolButton_save_clicked\0"
    "on_toolButton_close_clicked\0"
    "on_toolButton_clicked\0"
    "on_toolButton_connect_clicked\0"
    "rece_buttonClicked\0index\0rece_init\0"
    "buttonSid\0code"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_zookeepermanagewidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    1,   54,    2, 0x08 /* Private */,
       9,    2,   57,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   10,   11,

       0        // eod
};

void zookeepermanagewidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        zookeepermanagewidget *_t = static_cast<zookeepermanagewidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_toolButton_newCreate_clicked(); break;
        case 1: _t->on_toolButton_save_clicked(); break;
        case 2: _t->on_toolButton_close_clicked(); break;
        case 3: _t->on_toolButton_clicked(); break;
        case 4: _t->on_toolButton_connect_clicked(); break;
        case 5: _t->rece_buttonClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->rece_init((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject zookeepermanagewidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_zookeepermanagewidget.data,
      qt_meta_data_zookeepermanagewidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *zookeepermanagewidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *zookeepermanagewidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_zookeepermanagewidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int zookeepermanagewidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
