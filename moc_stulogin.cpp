/****************************************************************************
** Meta object code from reading C++ file 'stulogin.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "stulogin.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'stulogin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_STULogin[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      41,   10,    9,    9, 0x05,
      89,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
     105,    9,    9,    9, 0x0a,
     126,  114,    9,    9, 0x0a,
     155,  149,    9,    9, 0x0a,
     183,    9,    9,    9, 0x0a,
     203,  194,    9,    9, 0x0a,
     234,    9,    9,    9, 0x0a,
     257,    9,    9,    9, 0x0a,
     282,    9,    9,    9, 0x0a,
     298,    9,    9,    9, 0x0a,
     320,  317,    9,    9, 0x0a,
     370,  357,  342,    9, 0x0a,
     419,  411,  342,    9, 0x0a,
     448,    9,    9,    9, 0x08,
     466,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_STULogin[] = {
    "STULogin\0\0connected,user,used,total,left\0"
    "stateChanged(bool,QString,double,double,double)\0"
    "badConnection()\0logout()\0user,passwd\0"
    "login(QString,QString)\0reply\0"
    "handleReply(QNetworkReply*)\0getState()\0"
    "accounts\0setAccounts(QList<ExAccount>*)\0"
    "setThresholdValue(int)\0setAutoChangeState(bool)\0"
    "changeAccount()\0resetAllAccounts()\0"
    "ms\0delayForSomeTime(int)\0QNetworkReply*\0"
    "request,data\0syncHttpPost(QNetworkRequest,QByteArray)\0"
    "request\0syncHttpGet(QNetworkRequest)\0"
    "clearErrorCount()\0login()\0"
};

void STULogin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        STULogin *_t = static_cast<STULogin *>(_o);
        switch (_id) {
        case 0: _t->stateChanged((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5]))); break;
        case 1: _t->badConnection(); break;
        case 2: _t->logout(); break;
        case 3: _t->login((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 4: _t->handleReply((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 5: _t->getState(); break;
        case 6: _t->setAccounts((*reinterpret_cast< QList<ExAccount>*(*)>(_a[1]))); break;
        case 7: _t->setThresholdValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->setAutoChangeState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->changeAccount(); break;
        case 10: _t->resetAllAccounts(); break;
        case 11: _t->delayForSomeTime((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: { QNetworkReply* _r = _t->syncHttpPost((*reinterpret_cast< const QNetworkRequest(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QNetworkReply**>(_a[0]) = _r; }  break;
        case 13: { QNetworkReply* _r = _t->syncHttpGet((*reinterpret_cast< const QNetworkRequest(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QNetworkReply**>(_a[0]) = _r; }  break;
        case 14: _t->clearErrorCount(); break;
        case 15: _t->login(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData STULogin::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject STULogin::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_STULogin,
      qt_meta_data_STULogin, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &STULogin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *STULogin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *STULogin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_STULogin))
        return static_cast<void*>(const_cast< STULogin*>(this));
    return QObject::qt_metacast(_clname);
}

int STULogin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void STULogin::stateChanged(bool _t1, const QString & _t2, double _t3, double _t4, double _t5)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void STULogin::badConnection()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
