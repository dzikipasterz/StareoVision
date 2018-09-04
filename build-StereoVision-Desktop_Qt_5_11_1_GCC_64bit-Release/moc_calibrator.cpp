/****************************************************************************
** Meta object code from reading C++ file 'calibrator.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../StereoVision/calibrator.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'calibrator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Calibrator_t {
    QByteArrayData data[15];
    char stringdata0[202];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Calibrator_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Calibrator_t qt_meta_stringdata_Calibrator = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Calibrator"
QT_MOC_LITERAL(1, 11, 21), // "sendCalibrationStatus"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 6), // "status"
QT_MOC_LITERAL(4, 41, 19), // "sendCreatedFilePath"
QT_MOC_LITERAL(5, 61, 8), // "filepath"
QT_MOC_LITERAL(6, 70, 20), // "sendCollectionStatus"
QT_MOC_LITERAL(7, 91, 10), // "setsNumber"
QT_MOC_LITERAL(8, 102, 13), // "lastSetStatus"
QT_MOC_LITERAL(9, 116, 13), // "receiveFrames"
QT_MOC_LITERAL(10, 130, 7), // "cv::Mat"
QT_MOC_LITERAL(11, 138, 9), // "leftFrame"
QT_MOC_LITERAL(12, 148, 10), // "rightFrame"
QT_MOC_LITERAL(13, 159, 18), // "receiveTakePicture"
QT_MOC_LITERAL(14, 178, 23) // "receiveStartCalibration"

    },
    "Calibrator\0sendCalibrationStatus\0\0"
    "status\0sendCreatedFilePath\0filepath\0"
    "sendCollectionStatus\0setsNumber\0"
    "lastSetStatus\0receiveFrames\0cv::Mat\0"
    "leftFrame\0rightFrame\0receiveTakePicture\0"
    "receiveStartCalibration"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Calibrator[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    1,   47,    2, 0x06 /* Public */,
       6,    2,   50,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    2,   55,    2, 0x0a /* Public */,
      13,    0,   60,    2, 0x0a /* Public */,
      14,    0,   61,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    7,    8,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 10, 0x80000000 | 10,   11,   12,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Calibrator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Calibrator *_t = static_cast<Calibrator *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendCalibrationStatus((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sendCreatedFilePath((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->sendCollectionStatus((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 3: _t->receiveFrames((*reinterpret_cast< cv::Mat(*)>(_a[1])),(*reinterpret_cast< cv::Mat(*)>(_a[2]))); break;
        case 4: _t->receiveTakePicture(); break;
        case 5: _t->receiveStartCalibration(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Calibrator::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Calibrator::sendCalibrationStatus)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Calibrator::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Calibrator::sendCreatedFilePath)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Calibrator::*)(int , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Calibrator::sendCollectionStatus)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Calibrator::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Calibrator.data,
      qt_meta_data_Calibrator,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Calibrator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Calibrator::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Calibrator.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Calibrator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void Calibrator::sendCalibrationStatus(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Calibrator::sendCreatedFilePath(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Calibrator::sendCollectionStatus(int _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
