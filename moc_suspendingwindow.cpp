/****************************************************************************
** Meta object code from reading C++ file 'suspendingwindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "suspendingwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'suspendingwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SuspendingWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
      45,   34,   17,   17, 0x0a,
      74,   17,   17,   17, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SuspendingWindow[] = {
    "SuspendingWindow\0\0doubleClicked()\0"
    "left,speed\0updateDisplay(double,double)\0"
    "exit()\0"
};

void SuspendingWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SuspendingWindow *_t = static_cast<SuspendingWindow *>(_o);
        switch (_id) {
        case 0: _t->doubleClicked(); break;
        case 1: _t->updateDisplay((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 2: _t->exit(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SuspendingWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SuspendingWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SuspendingWindow,
      qt_meta_data_SuspendingWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SuspendingWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SuspendingWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SuspendingWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SuspendingWindow))
        return static_cast<void*>(const_cast< SuspendingWindow*>(this));
    if (!strcmp(_clname, "Ui::SuspendingWindow"))
        return static_cast< Ui::SuspendingWindow*>(const_cast< SuspendingWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int SuspendingWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void SuspendingWindow::doubleClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
