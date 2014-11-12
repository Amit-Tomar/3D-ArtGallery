/****************************************************************************
** Meta object code from reading C++ file 'Transform.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Src/Transform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Transform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Transform_t {
    QByteArrayData data[14];
    char stringdata[329];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Transform_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Transform_t qt_meta_stringdata_Transform = {
    {
QT_MOC_LITERAL(0, 0, 9),
QT_MOC_LITERAL(1, 10, 24),
QT_MOC_LITERAL(2, 35, 0),
QT_MOC_LITERAL(3, 36, 24),
QT_MOC_LITERAL(4, 61, 24),
QT_MOC_LITERAL(5, 86, 24),
QT_MOC_LITERAL(6, 111, 24),
QT_MOC_LITERAL(7, 136, 24),
QT_MOC_LITERAL(8, 161, 27),
QT_MOC_LITERAL(9, 189, 27),
QT_MOC_LITERAL(10, 217, 27),
QT_MOC_LITERAL(11, 245, 27),
QT_MOC_LITERAL(12, 273, 27),
QT_MOC_LITERAL(13, 301, 27)
    },
    "Transform\0updateXRotationIncrement\0\0"
    "updateYRotationIncrement\0"
    "updateZRotationIncrement\0"
    "updateXRotationDecrement\0"
    "updateYRotationDecrement\0"
    "updateZRotationDecrement\0"
    "updateXTranslationIncrement\0"
    "updateYTranslationIncrement\0"
    "updateZTranslationIncrement\0"
    "updateXTranslationDecrement\0"
    "updateYTranslationDecrement\0"
    "updateZTranslationDecrement"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Transform[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x0a /* Public */,
       3,    0,   75,    2, 0x0a /* Public */,
       4,    0,   76,    2, 0x0a /* Public */,
       5,    0,   77,    2, 0x0a /* Public */,
       6,    0,   78,    2, 0x0a /* Public */,
       7,    0,   79,    2, 0x0a /* Public */,
       8,    0,   80,    2, 0x0a /* Public */,
       9,    0,   81,    2, 0x0a /* Public */,
      10,    0,   82,    2, 0x0a /* Public */,
      11,    0,   83,    2, 0x0a /* Public */,
      12,    0,   84,    2, 0x0a /* Public */,
      13,    0,   85,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Transform::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Transform *_t = static_cast<Transform *>(_o);
        switch (_id) {
        case 0: _t->updateXRotationIncrement(); break;
        case 1: _t->updateYRotationIncrement(); break;
        case 2: _t->updateZRotationIncrement(); break;
        case 3: _t->updateXRotationDecrement(); break;
        case 4: _t->updateYRotationDecrement(); break;
        case 5: _t->updateZRotationDecrement(); break;
        case 6: _t->updateXTranslationIncrement(); break;
        case 7: _t->updateYTranslationIncrement(); break;
        case 8: _t->updateZTranslationIncrement(); break;
        case 9: _t->updateXTranslationDecrement(); break;
        case 10: _t->updateYTranslationDecrement(); break;
        case 11: _t->updateZTranslationDecrement(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Transform::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Transform.data,
      qt_meta_data_Transform,  qt_static_metacall, 0, 0}
};


const QMetaObject *Transform::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Transform::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Transform.stringdata))
        return static_cast<void*>(const_cast< Transform*>(this));
    if (!strcmp(_clname, "ScenegraphNode"))
        return static_cast< ScenegraphNode*>(const_cast< Transform*>(this));
    return QObject::qt_metacast(_clname);
}

int Transform::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
