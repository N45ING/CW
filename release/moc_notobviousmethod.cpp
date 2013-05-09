/****************************************************************************
** Meta object code from reading C++ file 'notobviousmethod.h'
**
** Created: Thu 9. May 16:23:40 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../notobviousmethod.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'notobviousmethod.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_NotObviousMethod[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x08,
      52,   47,   17,   17, 0x08,
      86,   47,   17,   17, 0x08,
     120,   47,   17,   17, 0x08,
     154,   47,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_NotObviousMethod[] = {
    "NotObviousMethod\0\0on_calculateButton_clicked()\0"
    "arg1\0on_equationA_valueChanged(double)\0"
    "on_equationB_valueChanged(double)\0"
    "on_accurateA_valueChanged(double)\0"
    "on_accurateB_valueChanged(double)\0"
};

void NotObviousMethod::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        NotObviousMethod *_t = static_cast<NotObviousMethod *>(_o);
        switch (_id) {
        case 0: _t->on_calculateButton_clicked(); break;
        case 1: _t->on_equationA_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->on_equationB_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->on_accurateA_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->on_accurateB_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData NotObviousMethod::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject NotObviousMethod::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_NotObviousMethod,
      qt_meta_data_NotObviousMethod, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &NotObviousMethod::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *NotObviousMethod::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *NotObviousMethod::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NotObviousMethod))
        return static_cast<void*>(const_cast< NotObviousMethod*>(this));
    return QWidget::qt_metacast(_clname);
}

int NotObviousMethod::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
