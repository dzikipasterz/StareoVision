/****************************************************************************
** Meta object code from reading C++ file 'widgetcalibration.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../StereoVision/widgetcalibration.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widgetcalibration.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_widgetCalibration_t {
    QByteArrayData data[19];
    char stringdata0[320];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_widgetCalibration_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_widgetCalibration_t qt_meta_stringdata_widgetCalibration = {
    {
QT_MOC_LITERAL(0, 0, 17), // "widgetCalibration"
QT_MOC_LITERAL(1, 18, 15), // "sendTakePicture"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 20), // "sendStartCalibration"
QT_MOC_LITERAL(4, 56, 13), // "receiveFrames"
QT_MOC_LITERAL(5, 70, 7), // "cv::Mat"
QT_MOC_LITERAL(6, 78, 9), // "leftFrame"
QT_MOC_LITERAL(7, 88, 10), // "rightFrame"
QT_MOC_LITERAL(8, 99, 23), // "receiveCalibratorStatus"
QT_MOC_LITERAL(9, 123, 12), // "numberOfSets"
QT_MOC_LITERAL(10, 136, 13), // "lastSetStatus"
QT_MOC_LITERAL(11, 150, 24), // "receiveCalibrationStatus"
QT_MOC_LITERAL(12, 175, 6), // "status"
QT_MOC_LITERAL(13, 182, 26), // "receiveCalibrationFilePath"
QT_MOC_LITERAL(14, 209, 4), // "path"
QT_MOC_LITERAL(15, 214, 33), // "on_pushButtonTurnCameraOn_tog..."
QT_MOC_LITERAL(16, 248, 7), // "checked"
QT_MOC_LITERAL(17, 256, 32), // "on_pushButtonTakePicture_clicked"
QT_MOC_LITERAL(18, 289, 30) // "on_pushButtonCalibrate_clicked"

    },
    "widgetCalibration\0sendTakePicture\0\0"
    "sendStartCalibration\0receiveFrames\0"
    "cv::Mat\0leftFrame\0rightFrame\0"
    "receiveCalibratorStatus\0numberOfSets\0"
    "lastSetStatus\0receiveCalibrationStatus\0"
    "status\0receiveCalibrationFilePath\0"
    "path\0on_pushButtonTurnCameraOn_toggled\0"
    "checked\0on_pushButtonTakePicture_clicked\0"
    "on_pushButtonCalibrate_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_widgetCalibration[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    2,   61,    2, 0x0a /* Public */,
       8,    2,   66,    2, 0x0a /* Public */,
      11,    1,   71,    2, 0x0a /* Public */,
      13,    1,   74,    2, 0x0a /* Public */,
      15,    1,   77,    2, 0x08 /* Private */,
      17,    0,   80,    2, 0x08 /* Private */,
      18,    0,   81,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 5,    6,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    9,   10,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::Bool,   16,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void widgetCalibration::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        widgetCalibration *_t = static_cast<widgetCalibration *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendTakePicture(); break;
        case 1: _t->sendStartCalibration(); break;
        case 2: _t->receiveFrames((*reinterpret_cast< cv::Mat(*)>(_a[1])),(*reinterpret_cast< cv::Mat(*)>(_a[2]))); break;
        case 3: _t->receiveCalibratorStatus((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 4: _t->receiveCalibrationStatus((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->receiveCalibrationFilePath((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->on_pushButtonTurnCameraOn_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->on_pushButtonTakePicture_clicked(); break;
        case 8: _t->on_pushButtonCalibrate_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (widgetCalibration::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&widgetCalibration::sendTakePicture)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (widgetCalibration::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&widgetCalibration::sendStartCalibration)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject widgetCalibration::staticMetaObject = {
    { &AppWidget::staticMetaObject, qt_meta_stringdata_widgetCalibration.data,
      qt_meta_data_widgetCalibration,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *widgetCalibration::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *widgetCalibration::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_widgetCalibration.stringdata0))
        return static_cast<void*>(this);
    return AppWidget::qt_metacast(_clname);
}

int widgetCalibration::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AppWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void widgetCalibration::sendTakePicture()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void widgetCalibration::sendStartCalibration()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
