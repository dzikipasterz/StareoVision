/****************************************************************************
** Meta object code from reading C++ file 'widgetsettings.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../StereoVision/widgetsettings.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widgetsettings.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_widgetSettings_t {
    QByteArrayData data[19];
    char stringdata0[366];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_widgetSettings_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_widgetSettings_t qt_meta_stringdata_widgetSettings = {
    {
QT_MOC_LITERAL(0, 0, 14), // "widgetSettings"
QT_MOC_LITERAL(1, 15, 21), // "sendStereoCameraSetup"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 12), // "leftCameraId"
QT_MOC_LITERAL(4, 51, 13), // "rightCameraId"
QT_MOC_LITERAL(5, 65, 13), // "receiveFrames"
QT_MOC_LITERAL(6, 79, 7), // "cv::Mat"
QT_MOC_LITERAL(7, 87, 9), // "leftFrame"
QT_MOC_LITERAL(8, 97, 10), // "rightFrame"
QT_MOC_LITERAL(9, 108, 19), // "receiveCameraStatus"
QT_MOC_LITERAL(10, 128, 16), // "leftCameraStatus"
QT_MOC_LITERAL(11, 145, 17), // "rightCameraStatus"
QT_MOC_LITERAL(12, 163, 28), // "on_leftCameraId_valueChanged"
QT_MOC_LITERAL(13, 192, 2), // "id"
QT_MOC_LITERAL(14, 195, 29), // "on_rightCameraId_valueChanged"
QT_MOC_LITERAL(15, 225, 33), // "on_pushButtonSelectPicDir_cli..."
QT_MOC_LITERAL(16, 259, 36), // "on_pushButtonSelectCalibFile_..."
QT_MOC_LITERAL(17, 296, 33), // "on_pushButtonSelectMovDir_cli..."
QT_MOC_LITERAL(18, 330, 35) // "on_pushButtonSelectCalibDir_c..."

    },
    "widgetSettings\0sendStereoCameraSetup\0"
    "\0leftCameraId\0rightCameraId\0receiveFrames\0"
    "cv::Mat\0leftFrame\0rightFrame\0"
    "receiveCameraStatus\0leftCameraStatus\0"
    "rightCameraStatus\0on_leftCameraId_valueChanged\0"
    "id\0on_rightCameraId_valueChanged\0"
    "on_pushButtonSelectPicDir_clicked\0"
    "on_pushButtonSelectCalibFile_clicked\0"
    "on_pushButtonSelectMovDir_clicked\0"
    "on_pushButtonSelectCalibDir_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_widgetSettings[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    2,   64,    2, 0x0a /* Public */,
       9,    2,   69,    2, 0x0a /* Public */,
      12,    1,   74,    2, 0x08 /* Private */,
      14,    1,   77,    2, 0x08 /* Private */,
      15,    0,   80,    2, 0x08 /* Private */,
      16,    0,   81,    2, 0x08 /* Private */,
      17,    0,   82,    2, 0x08 /* Private */,
      18,    0,   83,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 6,    7,    8,
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool,   10,   11,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void widgetSettings::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        widgetSettings *_t = static_cast<widgetSettings *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendStereoCameraSetup((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 1: _t->receiveFrames((*reinterpret_cast< cv::Mat(*)>(_a[1])),(*reinterpret_cast< cv::Mat(*)>(_a[2]))); break;
        case 2: _t->receiveCameraStatus((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 3: _t->on_leftCameraId_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_rightCameraId_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_pushButtonSelectPicDir_clicked(); break;
        case 6: _t->on_pushButtonSelectCalibFile_clicked(); break;
        case 7: _t->on_pushButtonSelectMovDir_clicked(); break;
        case 8: _t->on_pushButtonSelectCalibDir_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (widgetSettings::*)(const int , const int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&widgetSettings::sendStereoCameraSetup)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject widgetSettings::staticMetaObject = {
    { &AppWidget::staticMetaObject, qt_meta_stringdata_widgetSettings.data,
      qt_meta_data_widgetSettings,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *widgetSettings::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *widgetSettings::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_widgetSettings.stringdata0))
        return static_cast<void*>(this);
    return AppWidget::qt_metacast(_clname);
}

int widgetSettings::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void widgetSettings::sendStereoCameraSetup(const int _t1, const int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
