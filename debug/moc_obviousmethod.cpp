/****************************************************************************
** Meta object code from reading C++ file 'obviousmethod.h'
**
** Created: Wed 8. May 12:47:20 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../obviousmethod.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'obviousmethod.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ObviousMethod[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x08,
      46,   44,   14,   14, 0x08,
      69,   67,   14,   14, 0x08,
      90,   44,   14,   14, 0x08,
     111,   67,   14,   14, 0x08,
     137,  132,   14,   14, 0x08,
     171,  132,   14,   14, 0x08,
     205,  132,   14,   14, 0x08,
     239,  132,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ObviousMethod[] = {
    "ObviousMethod\0\0on_calculateButton_clicked()\0"
    "a\0setEquationA(double)\0b\0setEquationB(double)\0"
    "setAccurateA(double)\0setAccurateB(double)\0"
    "arg1\0on_equationA_valueChanged(double)\0"
    "on_equationB_valueChanged(double)\0"
    "on_accurateA_valueChanged(double)\0"
    "on_accurateB_valueChanged(double)\0"
};

void ObviousMethod::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ObviousMethod *_t = static_cast<ObviousMethod *>(_o);
        switch (_id) {
        case 0: _t->on_calculateButton_clicked(); break;
        case 1: _t->setEquationA((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->setEquationB((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->setAccurateA((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->setAccurateB((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->on_equationA_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->on_equationB_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->on_accurateA_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: _t->on_accurateB_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ObviousMethod::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ObviousMethod::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ObviousMethod,
      qt_meta_data_ObviousMethod, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ObviousMethod::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ObviousMethod::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ObviousMethod::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ObviousMethod))
        return static_cast<void*>(const_cast< ObviousMethod*>(this));
    return QWidget::qt_metacast(_clname);
}

int ObviousMethod::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
