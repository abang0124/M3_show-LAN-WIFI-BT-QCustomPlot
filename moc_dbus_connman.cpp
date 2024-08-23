/****************************************************************************
** Meta object code from reading C++ file 'dbus_connman.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "dbus_connman.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dbus_connman.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DBusConnman_t {
    QByteArrayData data[14];
    char stringdata0[195];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DBusConnman_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DBusConnman_t qt_meta_stringdata_DBusConnman = {
    {
QT_MOC_LITERAL(0, 0, 11), // "DBusConnman"
QT_MOC_LITERAL(1, 12, 15), // "service_changed"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 4), // "type"
QT_MOC_LITERAL(4, 34, 18), // "canGetIPAddressSig"
QT_MOC_LITERAL(5, 53, 9), // "scan_wifi"
QT_MOC_LITERAL(6, 63, 12), // "connect_wifi"
QT_MOC_LITERAL(7, 76, 8), // "WIFIName"
QT_MOC_LITERAL(8, 85, 15), // "disconnect_wifi"
QT_MOC_LITERAL(9, 101, 25), // "dbsServicePropertyChanged"
QT_MOC_LITERAL(10, 127, 12), // "QDBusVariant"
QT_MOC_LITERAL(11, 140, 12), // "QDBusMessage"
QT_MOC_LITERAL(12, 153, 18), // "dbsServicesChanged"
QT_MOC_LITERAL(13, 172, 22) // "QList<QDBusObjectPath>"

    },
    "DBusConnman\0service_changed\0\0type\0"
    "canGetIPAddressSig\0scan_wifi\0connect_wifi\0"
    "WIFIName\0disconnect_wifi\0"
    "dbsServicePropertyChanged\0QDBusVariant\0"
    "QDBusMessage\0dbsServicesChanged\0"
    "QList<QDBusObjectPath>"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DBusConnman[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    0,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   53,    2, 0x0a /* Public */,
       6,    1,   54,    2, 0x0a /* Public */,
       8,    1,   57,    2, 0x0a /* Public */,
       9,    3,   60,    2, 0x08 /* Private */,
      12,    3,   67,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 10, 0x80000000 | 11,    2,    2,    2,
    QMetaType::Void, QMetaType::QVariantList, 0x80000000 | 13, 0x80000000 | 11,    2,    2,    2,

       0        // eod
};

void DBusConnman::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DBusConnman *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->service_changed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->canGetIPAddressSig(); break;
        case 2: _t->scan_wifi(); break;
        case 3: _t->connect_wifi((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->disconnect_wifi((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->dbsServicePropertyChanged((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QDBusVariant(*)>(_a[2])),(*reinterpret_cast< QDBusMessage(*)>(_a[3]))); break;
        case 6: _t->dbsServicesChanged((*reinterpret_cast< QList<QVariant>(*)>(_a[1])),(*reinterpret_cast< QList<QDBusObjectPath>(*)>(_a[2])),(*reinterpret_cast< QDBusMessage(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QDBusMessage >(); break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QDBusVariant >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QDBusMessage >(); break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QDBusObjectPath> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DBusConnman::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBusConnman::service_changed)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DBusConnman::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBusConnman::canGetIPAddressSig)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DBusConnman::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_DBusConnman.data,
    qt_meta_data_DBusConnman,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DBusConnman::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DBusConnman::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DBusConnman.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DBusConnman::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void DBusConnman::service_changed(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DBusConnman::canGetIPAddressSig()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
