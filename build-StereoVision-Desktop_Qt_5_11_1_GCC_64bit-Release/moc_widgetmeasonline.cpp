/****************************************************************************
** Meta object code from reading C++ file 'widgetmeasonline.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../StereoVision/widgetmeasonline.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widgetmeasonline.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_widgetMeasOnline_t {
    QByteArrayData data[9];
    char stringdata0[105];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_widgetMeasOnline_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_widgetMeasOnline_t qt_meta_stringdata_widgetMeasOnline = {
    {
QT_MOC_LITERAL(0, 0, 16), // "widgetMeasOnline"
QT_MOC_LITERAL(1, 17, 16), // "receiveDisparity"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 7), // "cv::Mat"
QT_MOC_LITERAL(4, 43, 12), // "leftFrameRaw"
QT_MOC_LITERAL(5, 56, 13), // "rightFrameRaw"
QT_MOC_LITERAL(6, 70, 9), // "disparity"
QT_MOC_LITERAL(7, 80, 15), // "receiveDistance"
QT_MOC_LITERAL(8, 96, 8) // "distance"

    },
    "widgetMeasOnline\0receiveDisparity\0\0"
    "cv::Mat\0leftFrameRaw\0rightFrameRaw\0"
    "disparity\0receiveDistance\0distance"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_widgetMeasOnline[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    3,   24,    2, 0x0a /* Public */,
       7,    1,   31,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3,    4,    5,    6,
    QMetaType::Void, QMetaType::Double,    8,

       0        // eod
};

void widgetMeasOnline::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        widgetMeasOnline *_t = static_cast<widgetMeasOnline *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->receiveDisparity((*reinterpret_cast< cv::Mat(*)>(_a[1])),(*reinterpret_cast< cv::Mat(*)>(_a[2])),(*reinterpret_cast< cv::Mat(*)>(_a[3]))); break;
        case 1: _t->receiveDistance((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject widgetMeasOnline::staticMetaObject = {
    { &AppWidget::staticMetaObject, qt_meta_stringdata_widgetMeasOnline.data,
      qt_meta_data_widgetMeasOnline,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *widgetMeasOnline::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *widgetMeasOnline::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_widgetMeasOnline.stringdata0))
        return static_cast<void*>(this);
    return AppWidget::qt_metacast(_clname);
}

int widgetMeasOnline::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AppWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
