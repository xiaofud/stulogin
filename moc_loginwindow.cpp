/****************************************************************************
** Meta object code from reading C++ file 'loginwindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "loginwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'loginwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LoginWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   13,   12,   12, 0x05,
      63,   52,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
     144,   97,   12,   12, 0x0a,
     191,   12,   12,   12, 0x0a,
     208,   12,   12,   12, 0x0a,
     216,   12,   12,   12, 0x0a,
     232,  230,  225,   12, 0x0a,
     268,  262,   12,   12, 0x0a,
     293,   12,   12,   12, 0x0a,
     315,  308,   12,   12, 0x0a,
     364,   12,   12,   12, 0x0a,
     398,  371,   12,   12, 0x08,
     443,  427,   12,   12, 0x28,
     476,  467,   12,   12, 0x28,
     492,   12,   12,   12, 0x28,
     501,   12,   12,   12, 0x08,
     513,  230,   12,   12, 0x08,
     535,   12,   12,   12, 0x08,
     550,   12,   12,   12, 0x08,
     575,   12,   12,   12, 0x08,
     593,   12,   12,   12, 0x08,
     615,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_LoginWindow[] = {
    "LoginWindow\0\0list\0accountChanged(QList<ExAccount>*)\0"
    "left,speed\0newConnectionState(double,double)\0"
    "connected,USER_STR,USED_STR,TOTAL_STR,LEFT_STR\0"
    "updateState(bool,QString,double,double,double)\0"
    "setDefaultUser()\0login()\0logout()\0"
    "bool\0,\0eventFilter(QObject*,QEvent*)\0"
    "event\0closeEvent(QCloseEvent*)\0"
    "openSTUEmail()\0reason\0"
    "iconActivated(QSystemTrayIcon::ActivationReason)\0"
    "exit()\0USER_STR,passwd,sendSignal\0"
    "addRow(QString,QString,bool)\0"
    "USER_STR,passwd\0addRow(QString,QString)\0"
    "USER_STR\0addRow(QString)\0addRow()\0"
    "deleteRow()\0showPassword(int,int)\0"
    "hidePassword()\0editAccountLineEdit(int)\0"
    "showHelpMessage()\0showConnectionError()\0"
    "showClientWindow()\0"
};

void LoginWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        LoginWindow *_t = static_cast<LoginWindow *>(_o);
        switch (_id) {
        case 0: _t->accountChanged((*reinterpret_cast< QList<ExAccount>*(*)>(_a[1]))); break;
        case 1: _t->newConnectionState((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 2: _t->updateState((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5]))); break;
        case 3: _t->setDefaultUser(); break;
        case 4: _t->login(); break;
        case 5: _t->logout(); break;
        case 6: { bool _r = _t->eventFilter((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< QEvent*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 7: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 8: _t->openSTUEmail(); break;
        case 9: _t->iconActivated((*reinterpret_cast< QSystemTrayIcon::ActivationReason(*)>(_a[1]))); break;
        case 10: _t->exit(); break;
        case 11: _t->addRow((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 12: _t->addRow((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 13: _t->addRow((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 14: _t->addRow(); break;
        case 15: _t->deleteRow(); break;
        case 16: _t->showPassword((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 17: _t->hidePassword(); break;
        case 18: _t->editAccountLineEdit((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->showHelpMessage(); break;
        case 20: _t->showConnectionError(); break;
        case 21: _t->showClientWindow(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData LoginWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject LoginWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_LoginWindow,
      qt_meta_data_LoginWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LoginWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LoginWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LoginWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LoginWindow))
        return static_cast<void*>(const_cast< LoginWindow*>(this));
    if (!strcmp(_clname, "Ui::LoginWindow"))
        return static_cast< Ui::LoginWindow*>(const_cast< LoginWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int LoginWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    }
    return _id;
}

// SIGNAL 0
void LoginWindow::accountChanged(QList<ExAccount> * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void LoginWindow::newConnectionState(double _t1, double _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
