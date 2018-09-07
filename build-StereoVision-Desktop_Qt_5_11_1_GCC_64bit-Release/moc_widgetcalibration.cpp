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
    QByteArrayData data[26];
    char stringdata0[484];
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
QT_MOC_LITERAL(3, 35, 15), // "sendLoadPicture"
QT_MOC_LITERAL(4, 51, 20), // "sendStartCalibration"
QT_MOC_LITERAL(5, 72, 16), // "sendLoadedFrames"
QT_MOC_LITERAL(6, 89, 7), // "cv::Mat"
QT_MOC_LITERAL(7, 97, 9), // "leftFrame"
QT_MOC_LITERAL(8, 107, 8), // "rightMat"
QT_MOC_LITERAL(9, 116, 13), // "receiveFrames"
QT_MOC_LITERAL(10, 130, 10), // "rightFrame"
QT_MOC_LITERAL(11, 141, 23), // "receiveCalibratorStatus"
QT_MOC_LITERAL(12, 165, 12), // "numberOfSets"
QT_MOC_LITERAL(13, 178, 13), // "lastSetStatus"
QT_MOC_LITERAL(14, 192, 24), // "receiveCalibrationStatus"
QT_MOC_LITERAL(15, 217, 6), // "status"
QT_MOC_LITERAL(16, 224, 26), // "receiveCalibrationFilePath"
QT_MOC_LITERAL(17, 251, 4), // "path"
QT_MOC_LITERAL(18, 256, 32), // "on_pushButtonTakePicture_clicked"
QT_MOC_LITERAL(19, 289, 30), // "on_pushButtonCalibrate_clicked"
QT_MOC_LITERAL(20, 320, 27), // "on_spinBoxRows_valueChanged"
QT_MOC_LITERAL(21, 348, 4), // "arg1"
QT_MOC_LITERAL(22, 353, 27), // "on_spinBoxCols_valueChanged"
QT_MOC_LITERAL(23, 381, 39), // "on_doubleSpinBoxSquareSize_va..."
QT_MOC_LITERAL(24, 421, 36), // "on_pushButtonChooseDirToLoad_..."
QT_MOC_LITERAL(25, 458, 25) // "on_pushButtonLoad_clicked"

    },
    "widgetCalibration\0sendTakePicture\0\0"
    "sendLoadPicture\0sendStartCalibration\0"
    "sendLoadedFrames\0cv::Mat\0leftFrame\0"
    "rightMat\0receiveFrames\0rightFrame\0"
    "receiveCalibratorStatus\0numberOfSets\0"
    "lastSetStatus\0receiveCalibrationStatus\0"
    "status\0receiveCalibrationFilePath\0"
    "path\0on_pushButtonTakePicture_clicked\0"
    "on_pushButtonCalibrate_clicked\0"
    "on_spinBoxRows_valueChanged\0arg1\0"
    "on_spinBoxCols_valueChanged\0"
    "on_doubleSpinBoxSquareSize_valueChanged\0"
    "on_pushButtonChooseDirToLoad_clicked\0"
    "on_pushButtonLoad_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_widgetCalibration[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x06 /* Public */,
       3,    0,   90,    2, 0x06 /* Public */,
       4,    0,   91,    2, 0x06 /* Public */,
       5,    2,   92,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    2,   97,    2, 0x0a /* Public */,
      11,    2,  102,    2, 0x0a /* Public */,
      14,    1,  107,    2, 0x0a /* Public */,
      16,    1,  110,    2, 0x0a /* Public */,
      18,    0,  113,    2, 0x08 /* Private */,
      19,    0,  114,    2, 0x08 /* Private */,
      20,    1,  115,    2, 0x08 /* Private */,
      22,    1,  118,    2, 0x08 /* Private */,
      23,    1,  121,    2, 0x08 /* Private */,
      24,    0,  124,    2, 0x08 /* Private */,
      25,    0,  125,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 6,    7,    8,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 6,    7,   10,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   12,   13,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   21,
    QMetaType::Void, QMetaType::Int,   21,
    QMetaType::Void, QMetaType::Double,   21,
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
        case 1: _t->sendLoadPicture(); break;
        case 2: _t->sendStartCalibration(); break;
        case 3: _t->sendLoadedFrames((*reinterpret_cast< cv::Mat(*)>(_a[1])),(*reinterpret_cast< cv::Mat(*)>(_a[2]))); break;
        case 4: _t->receiveFrames((*reinterpret_cast< cv::Mat(*)>(_a[1])),(*reinterpret_cast< cv::Mat(*)>(_a[2]))); break;
        case 5: _t->receiveCalibratorStatus((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 6: _t->receiveCalibrationStatus((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->receiveCalibrationFilePath((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->on_pushButtonTakePicture_clicked(); break;
        case 9: _t->on_pushButtonCalibrate_clicked(); break;
        case 10: _t->on_spinBoxRows_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_spinBoxCols_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->on_doubleSpinBoxSquareSize_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 13: _t->on_pushButtonChooseDirToLoad_clicked(); break;
        case 14: _t->on_pushButtonLoad_clicked(); break;
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
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&widgetCalibration::sendLoadPicture)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (widgetCalibration::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&widgetCalibration::sendStartCalibration)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (widgetCalibration::*)(cv::Mat , cv::Mat );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&widgetCalibration::sendLoadedFrames)) {
                *result = 3;
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
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void widgetCalibration::sendTakePicture()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void widgetCalibration::sendLoadPicture()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void widgetCalibration::sendStartCalibration()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void widgetCalibration::sendLoadedFrames(cv::Mat _t1, cv::Mat _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
