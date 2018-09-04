/****************************************************************************
** Meta object code from reading C++ file 'widgetrecord.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../StereoVision/widgetrecord.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widgetrecord.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_widgetRecord_t {
    QByteArrayData data[16];
    char stringdata0[239];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_widgetRecord_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_widgetRecord_t qt_meta_stringdata_widgetRecord = {
    {
QT_MOC_LITERAL(0, 0, 12), // "widgetRecord"
QT_MOC_LITERAL(1, 13, 15), // "sendTakePicture"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 18), // "sendStartRecording"
QT_MOC_LITERAL(4, 49, 17), // "sendStopRecording"
QT_MOC_LITERAL(5, 67, 13), // "receiveFrames"
QT_MOC_LITERAL(6, 81, 7), // "cv::Mat"
QT_MOC_LITERAL(7, 89, 9), // "leftFrame"
QT_MOC_LITERAL(8, 99, 10), // "rightFrame"
QT_MOC_LITERAL(9, 110, 18), // "receiveImagesPaths"
QT_MOC_LITERAL(10, 129, 8), // "leftPath"
QT_MOC_LITERAL(11, 138, 9), // "rightPath"
QT_MOC_LITERAL(12, 148, 18), // "receiveMoviesPaths"
QT_MOC_LITERAL(13, 167, 32), // "on_pushButtonTakePicture_clicked"
QT_MOC_LITERAL(14, 200, 30), // "on_pushButtonMakeMovie_toggled"
QT_MOC_LITERAL(15, 231, 7) // "checked"

    },
    "widgetRecord\0sendTakePicture\0\0"
    "sendStartRecording\0sendStopRecording\0"
    "receiveFrames\0cv::Mat\0leftFrame\0"
    "rightFrame\0receiveImagesPaths\0leftPath\0"
    "rightPath\0receiveMoviesPaths\0"
    "on_pushButtonTakePicture_clicked\0"
    "on_pushButtonMakeMovie_toggled\0checked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_widgetRecord[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,
       4,    0,   56,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    2,   57,    2, 0x0a /* Public */,
       9,    2,   62,    2, 0x0a /* Public */,
      12,    2,   67,    2, 0x0a /* Public */,
      13,    0,   72,    2, 0x08 /* Private */,
      14,    1,   73,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 6,    7,    8,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   10,   11,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   10,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   15,

       0        // eod
};

void widgetRecord::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        widgetRecord *_t = static_cast<widgetRecord *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendTakePicture(); break;
        case 1: _t->sendStartRecording(); break;
        case 2: _t->sendStopRecording(); break;
        case 3: _t->receiveFrames((*reinterpret_cast< cv::Mat(*)>(_a[1])),(*reinterpret_cast< cv::Mat(*)>(_a[2]))); break;
        case 4: _t->receiveImagesPaths((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 5: _t->receiveMoviesPaths((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 6: _t->on_pushButtonTakePicture_clicked(); break;
        case 7: _t->on_pushButtonMakeMovie_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (widgetRecord::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&widgetRecord::sendTakePicture)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (widgetRecord::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&widgetRecord::sendStartRecording)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (widgetRecord::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&widgetRecord::sendStopRecording)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject widgetRecord::staticMetaObject = {
    { &AppWidget::staticMetaObject, qt_meta_stringdata_widgetRecord.data,
      qt_meta_data_widgetRecord,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *widgetRecord::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *widgetRecord::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_widgetRecord.stringdata0))
        return static_cast<void*>(this);
    return AppWidget::qt_metacast(_clname);
}

int widgetRecord::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AppWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void widgetRecord::sendTakePicture()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void widgetRecord::sendStartRecording()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void widgetRecord::sendStopRecording()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
