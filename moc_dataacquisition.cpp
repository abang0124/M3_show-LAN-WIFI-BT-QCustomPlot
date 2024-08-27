/****************************************************************************
** Meta object code from reading C++ file 'dataacquisition.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "dataacquisition.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dataacquisition.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DataAcquisition_t {
    QByteArrayData data[36];
    char stringdata0[696];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DataAcquisition_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DataAcquisition_t qt_meta_stringdata_DataAcquisition = {
    {
QT_MOC_LITERAL(0, 0, 15), // "DataAcquisition"
QT_MOC_LITERAL(1, 16, 22), // "NIBPData2M3DataControl"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 15), // "QList<quint16>*"
QT_MOC_LITERAL(4, 56, 22), // "SPO2Data2M3DataControl"
QT_MOC_LITERAL(5, 79, 14), // "QList<quint8>*"
QT_MOC_LITERAL(6, 94, 23), // "HeartRate2M3DataControl"
QT_MOC_LITERAL(7, 118, 27), // "LeadsShowData2M3DataControl"
QT_MOC_LITERAL(8, 146, 14), // "QList<int>[12]"
QT_MOC_LITERAL(9, 161, 12), // "batValSignal"
QT_MOC_LITERAL(10, 174, 27), // "leadOffSignal2M3DataControl"
QT_MOC_LITERAL(11, 202, 17), // "BtClientConnected"
QT_MOC_LITERAL(12, 220, 20), // "BtClientDisconnected"
QT_MOC_LITERAL(13, 241, 11), // "BtTransData"
QT_MOC_LITERAL(14, 253, 3), // "buf"
QT_MOC_LITERAL(15, 257, 19), // "bluetoothOpenResult"
QT_MOC_LITERAL(16, 277, 7), // "dataAcq"
QT_MOC_LITERAL(17, 285, 20), // "onRecNIBPStartSignal"
QT_MOC_LITERAL(18, 306, 19), // "onRecNIBPStopSignal"
QT_MOC_LITERAL(19, 326, 27), // "onRecordECGFlagChangeSignal"
QT_MOC_LITERAL(20, 354, 23), // "onRecPatientTypeChanged"
QT_MOC_LITERAL(21, 378, 11), // "patientType"
QT_MOC_LITERAL(22, 390, 27), // "onRcvECGDataProcessedSignal"
QT_MOC_LITERAL(23, 418, 31), // "onRecLeadsShowTypeChangedSignal"
QT_MOC_LITERAL(24, 450, 10), // "readBatVal"
QT_MOC_LITERAL(25, 461, 28), // "onDataAcquisitionThreadCreat"
QT_MOC_LITERAL(26, 490, 12), // "startDataAcq"
QT_MOC_LITERAL(27, 503, 19), // "onRecLP_typeChanged"
QT_MOC_LITERAL(28, 523, 19), // "onRecHP_typeChanged"
QT_MOC_LITERAL(29, 543, 19), // "onRecAC_typeChanged"
QT_MOC_LITERAL(30, 563, 27), // "calculate_HR_and_emitSignal"
QT_MOC_LITERAL(31, 591, 20), // "onRecUILoadCompleted"
QT_MOC_LITERAL(32, 612, 25), // "onRecBtServerTransDataSig"
QT_MOC_LITERAL(33, 638, 27), // "onRecM3DataShowCtlBtOpenSig"
QT_MOC_LITERAL(34, 666, 13), // "BluetoothOpen"
QT_MOC_LITERAL(35, 680, 15) // "BluetoothClosed"

    },
    "DataAcquisition\0NIBPData2M3DataControl\0"
    "\0QList<quint16>*\0SPO2Data2M3DataControl\0"
    "QList<quint8>*\0HeartRate2M3DataControl\0"
    "LeadsShowData2M3DataControl\0QList<int>[12]\0"
    "batValSignal\0leadOffSignal2M3DataControl\0"
    "BtClientConnected\0BtClientDisconnected\0"
    "BtTransData\0buf\0bluetoothOpenResult\0"
    "dataAcq\0onRecNIBPStartSignal\0"
    "onRecNIBPStopSignal\0onRecordECGFlagChangeSignal\0"
    "onRecPatientTypeChanged\0patientType\0"
    "onRcvECGDataProcessedSignal\0"
    "onRecLeadsShowTypeChangedSignal\0"
    "readBatVal\0onDataAcquisitionThreadCreat\0"
    "startDataAcq\0onRecLP_typeChanged\0"
    "onRecHP_typeChanged\0onRecAC_typeChanged\0"
    "calculate_HR_and_emitSignal\0"
    "onRecUILoadCompleted\0onRecBtServerTransDataSig\0"
    "onRecM3DataShowCtlBtOpenSig\0BluetoothOpen\0"
    "BluetoothClosed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DataAcquisition[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      29,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,  159,    2, 0x06 /* Public */,
       4,    6,  164,    2, 0x06 /* Public */,
       6,    1,  177,    2, 0x06 /* Public */,
       7,    1,  180,    2, 0x06 /* Public */,
       9,    2,  183,    2, 0x06 /* Public */,
      10,    1,  188,    2, 0x06 /* Public */,
      11,    0,  191,    2, 0x06 /* Public */,
      12,    0,  192,    2, 0x06 /* Public */,
      13,    1,  193,    2, 0x06 /* Public */,
      15,    2,  196,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      16,    0,  201,    2, 0x0a /* Public */,
      17,    0,  202,    2, 0x0a /* Public */,
      18,    0,  203,    2, 0x0a /* Public */,
      19,    1,  204,    2, 0x0a /* Public */,
      20,    1,  207,    2, 0x0a /* Public */,
      22,    0,  210,    2, 0x0a /* Public */,
      23,    1,  211,    2, 0x0a /* Public */,
      24,    0,  214,    2, 0x0a /* Public */,
      25,    0,  215,    2, 0x0a /* Public */,
      26,    0,  216,    2, 0x0a /* Public */,
      27,    1,  217,    2, 0x0a /* Public */,
      28,    1,  220,    2, 0x0a /* Public */,
      29,    1,  223,    2, 0x0a /* Public */,
      30,    1,  226,    2, 0x0a /* Public */,
      31,    0,  229,    2, 0x0a /* Public */,
      32,    1,  230,    2, 0x0a /* Public */,
      33,    1,  233,    2, 0x0a /* Public */,
      34,    0,  236,    2, 0x0a /* Public */,
      35,    0,  237,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    2,    2,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 5, 0x80000000 | 5, 0x80000000 | 5, 0x80000000 | 5, 0x80000000 | 5,    2,    2,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::UShort,    2,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,   14,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::UChar,   21,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UChar,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UChar,    2,
    QMetaType::Void, QMetaType::UChar,    2,
    QMetaType::Void, QMetaType::UChar,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Bool,
    QMetaType::Void,

       0        // eod
};

void DataAcquisition::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DataAcquisition *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->NIBPData2M3DataControl((*reinterpret_cast< QList<quint16>*(*)>(_a[1])),(*reinterpret_cast< QList<quint16>*(*)>(_a[2]))); break;
        case 1: _t->SPO2Data2M3DataControl((*reinterpret_cast< QList<quint8>*(*)>(_a[1])),(*reinterpret_cast< QList<quint8>*(*)>(_a[2])),(*reinterpret_cast< QList<quint8>*(*)>(_a[3])),(*reinterpret_cast< QList<quint8>*(*)>(_a[4])),(*reinterpret_cast< QList<quint8>*(*)>(_a[5])),(*reinterpret_cast< QList<quint8>*(*)>(_a[6]))); break;
        case 2: _t->HeartRate2M3DataControl((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        case 3: _t->LeadsShowData2M3DataControl((*reinterpret_cast< QList<int>(*)[12]>(_a[1]))); break;
        case 4: _t->batValSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->leadOffSignal2M3DataControl((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->BtClientConnected(); break;
        case 7: _t->BtClientDisconnected(); break;
        case 8: _t->BtTransData((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 9: _t->bluetoothOpenResult((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 10: _t->dataAcq(); break;
        case 11: _t->onRecNIBPStartSignal(); break;
        case 12: _t->onRecNIBPStopSignal(); break;
        case 13: _t->onRecordECGFlagChangeSignal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->onRecPatientTypeChanged((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 15: _t->onRcvECGDataProcessedSignal(); break;
        case 16: _t->onRecLeadsShowTypeChangedSignal((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 17: _t->readBatVal(); break;
        case 18: _t->onDataAcquisitionThreadCreat(); break;
        case 19: _t->startDataAcq(); break;
        case 20: _t->onRecLP_typeChanged((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 21: _t->onRecHP_typeChanged((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 22: _t->onRecAC_typeChanged((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 23: _t->calculate_HR_and_emitSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 24: _t->onRecUILoadCompleted(); break;
        case 25: _t->onRecBtServerTransDataSig((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 26: _t->onRecM3DataShowCtlBtOpenSig((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 27: { bool _r = _t->BluetoothOpen();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 28: _t->BluetoothClosed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DataAcquisition::*)(QList<quint16> * , QList<quint16> * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataAcquisition::NIBPData2M3DataControl)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DataAcquisition::*)(QList<quint8> * , QList<quint8> * , QList<quint8> * , QList<quint8> * , QList<quint8> * , QList<quint8> * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataAcquisition::SPO2Data2M3DataControl)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (DataAcquisition::*)(quint16 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataAcquisition::HeartRate2M3DataControl)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (DataAcquisition::*)(QList<int> [12]);
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataAcquisition::LeadsShowData2M3DataControl)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (DataAcquisition::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataAcquisition::batValSignal)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (DataAcquisition::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataAcquisition::leadOffSignal2M3DataControl)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (DataAcquisition::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataAcquisition::BtClientConnected)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (DataAcquisition::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataAcquisition::BtClientDisconnected)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (DataAcquisition::*)(const QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataAcquisition::BtTransData)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (DataAcquisition::*)(bool , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataAcquisition::bluetoothOpenResult)) {
                *result = 9;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DataAcquisition::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_DataAcquisition.data,
    qt_meta_data_DataAcquisition,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DataAcquisition::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DataAcquisition::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DataAcquisition.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DataAcquisition::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 29)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 29;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 29)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 29;
    }
    return _id;
}

// SIGNAL 0
void DataAcquisition::NIBPData2M3DataControl(QList<quint16> * _t1, QList<quint16> * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DataAcquisition::SPO2Data2M3DataControl(QList<quint8> * _t1, QList<quint8> * _t2, QList<quint8> * _t3, QList<quint8> * _t4, QList<quint8> * _t5, QList<quint8> * _t6)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DataAcquisition::HeartRate2M3DataControl(quint16 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void DataAcquisition::LeadsShowData2M3DataControl(QList<int> _t1[12])
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void DataAcquisition::batValSignal(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void DataAcquisition::leadOffSignal2M3DataControl(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void DataAcquisition::BtClientConnected()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void DataAcquisition::BtClientDisconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void DataAcquisition::BtTransData(const QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void DataAcquisition::bluetoothOpenResult(bool _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
