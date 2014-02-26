/****************************************************************************
** Meta object code from reading C++ file 'TPhoneSetting.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "TPhoneSetting.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TPhoneSetting.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TPhoneSetting_t {
    QByteArrayData data[7];
    char stringdata[121];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_TPhoneSetting_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_TPhoneSetting_t qt_meta_stringdata_TPhoneSetting = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 22),
QT_MOC_LITERAL(2, 37, 0),
QT_MOC_LITERAL(3, 38, 5),
QT_MOC_LITERAL(4, 44, 21),
QT_MOC_LITERAL(5, 66, 26),
QT_MOC_LITERAL(6, 93, 26)
    },
    "TPhoneSetting\0PhoneScreenScaleChange\0"
    "\0value\0PhoneScreenSizeChange\0"
    "PhoneScreenPositionXChange\0"
    "PhoneScreenPositionYChange\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TPhoneSetting[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x0a,
       4,    0,   37,    2, 0x0a,
       5,    1,   38,    2, 0x0a,
       6,    1,   41,    2, 0x0a,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void TPhoneSetting::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TPhoneSetting *_t = static_cast<TPhoneSetting *>(_o);
        switch (_id) {
        case 0: _t->PhoneScreenScaleChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->PhoneScreenSizeChange(); break;
        case 2: _t->PhoneScreenPositionXChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->PhoneScreenPositionYChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject TPhoneSetting::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TPhoneSetting.data,
      qt_meta_data_TPhoneSetting,  qt_static_metacall, 0, 0}
};


const QMetaObject *TPhoneSetting::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TPhoneSetting::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TPhoneSetting.stringdata))
        return static_cast<void*>(const_cast< TPhoneSetting*>(this));
    return QWidget::qt_metacast(_clname);
}

int TPhoneSetting::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
