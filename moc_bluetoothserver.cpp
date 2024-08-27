/****************************************************************************
** Meta object code from reading C++ file 'bluetoothserver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "bluetoothserver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bluetoothserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BluetoothServer_t {
    QByteArrayData data[15];
    char stringdata0[222];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BluetoothServer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BluetoothServer_t qt_meta_stringdata_BluetoothServer = {
    {
QT_MOC_LITERAL(0, 0, 15), // "BluetoothServer"
QT_MOC_LITERAL(1, 16, 18), // "messageReceivedSig"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 6), // "sender"
QT_MOC_LITERAL(4, 43, 7), // "message"
QT_MOC_LITERAL(5, 51, 18), // "clientConnectedSig"
QT_MOC_LITERAL(6, 70, 21), // "clientDisconnectedSig"
QT_MOC_LITERAL(7, 92, 20), // "bluetoothOpenSuccess"
QT_MOC_LITERAL(8, 113, 19), // "bluetoothOpenFailed"
QT_MOC_LITERAL(9, 133, 26), // "bluetoothStartTranDataFlag"
QT_MOC_LITERAL(10, 160, 11), // "sendMessage"
QT_MOC_LITERAL(11, 172, 3), // "buf"
QT_MOC_LITERAL(12, 176, 18), // "clientDisconnected"
QT_MOC_LITERAL(13, 195, 15), // "clientConnected"
QT_MOC_LITERAL(14, 211, 10) // "readSocket"

    },
    "BluetoothServer\0messageReceivedSig\0\0"
    "sender\0message\0clientConnectedSig\0"
    "clientDisconnectedSig\0bluetoothOpenSuccess\0"
    "bluetoothOpenFailed\0bluetoothStartTranDataFlag\0"
    "sendMessage\0buf\0clientDisconnected\0"
    "clientConnected\0readSocket"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BluetoothServer[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   64,    2, 0x06 /* Public */,
       5,    0,   69,    2, 0x06 /* Public */,
       6,    0,   70,    2, 0x06 /* Public */,
       7,    0,   71,    2, 0x06 /* Public */,
       8,    0,   72,    2, 0x06 /* Public */,
       9,    1,   73,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    1,   76,    2, 0x0a /* Public */,
      12,    0,   79,    2, 0x0a /* Public */,
      13,    0,   80,    2, 0x08 /* Private */,
      14,    0,   81,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void BluetoothServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BluetoothServer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->messageReceivedSig((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->clientConnectedSig(); break;
        case 2: _t->clientDisconnectedSig(); break;
        case 3: _t->bluetoothOpenSuccess(); break;
        case 4: _t->bluetoothOpenFailed(); break;
        case 5: _t->bluetoothStartTranDataFlag((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->sendMessage((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 7: _t->clientDisconnected(); break;
        case 8: _t->clientConnected(); break;
        case 9: _t->readSocket(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (BluetoothServer::*)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BluetoothServer::messageReceivedSig)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (BluetoothServer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BluetoothServer::clientConnectedSig)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (BluetoothServer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BluetoothServer::clientDisconnectedSig)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (BluetoothServer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BluetoothServer::bluetoothOpenSuccess)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (BluetoothServer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BluetoothServer::bluetoothOpenFailed)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (BluetoothServer::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BluetoothServer::bluetoothStartTranDataFlag)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject BluetoothServer::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_BluetoothServer.data,
    qt_meta_data_BluetoothServer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *BluetoothServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BluetoothServer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BluetoothServer.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int BluetoothServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void BluetoothServer::messageReceivedSig(const QString & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void BluetoothServer::clientConnectedSig()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void BluetoothServer::clientDisconnectedSig()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void BluetoothServer::bluetoothOpenSuccess()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void BluetoothServer::bluetoothOpenFailed()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void BluetoothServer::bluetoothStartTranDataFlag(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
