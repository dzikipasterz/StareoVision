/****************************************************************************
** Meta object code from reading C++ file 'widgetmeasoffline.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../StereoVision/widgetmeasoffline.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widgetmeasoffline.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_widgetMeasOffline_t {
    QByteArrayData data[13];
    char stringdata0[212];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_widgetMeasOffline_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_widgetMeasOffline_t qt_meta_stringdata_widgetMeasOffline = {
    {
QT_MOC_LITERAL(0, 0, 17), // "widgetMeasOffline"
QT_MOC_LITERAL(1, 18, 13), // "SendStartMeas"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 16), // "receiveDisparity"
QT_MOC_LITERAL(4, 50, 7), // "cv::Mat"
QT_MOC_LITERAL(5, 58, 12), // "leftFrameRaw"
QT_MOC_LITERAL(6, 71, 13), // "rightFrameRaw"
QT_MOC_LITERAL(7, 85, 9), // "disparity"
QT_MOC_LITERAL(8, 95, 15), // "receiveDistance"
QT_MOC_LITERAL(9, 111, 8), // "distance"
QT_MOC_LITERAL(10, 120, 31), // "on_pushButtonLeftSource_clicked"
QT_MOC_LITERAL(11, 152, 32), // "on_pushButtonRightSource_clicked"
QT_MOC_LITERAL(12, 185, 26) // "on_pushButtonStart_clicked"

    },
    "widgetMeasOffline\0SendStartMeas\0\0"
    "receiveDisparity\0cv::Mat\0leftFrameRaw\0"
    "rightFrameRaw\0disparity\0receiveDistance\0"
    "distance\0on_pushButtonLeftSource_clicked\0"
    "on_pushButtonRightSource_clicked\0"
    "on_pushButtonStart_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_widgetMeasOffline[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    3,   45,    2, 0x0a /* Public */,
       8,    1,   52,    2, 0x0a /* Public */,
      10,    0,   55,    2, 0x08 /* Private */,
      11,    0,   56,    2, 0x08 /* Private */,
      12,    0,   57,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 4, 0x80000000 | 4,    5,    6,    7,
    QMetaType::Void, QMetaType::Double,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void widgetMeasOffline::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        widgetMeasOffline *_t = static_cast<widgetMeasOffline *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SendStartMeas(); break;
        case 1: _t->receiveDisparity((*reinterpret_cast< cv::Mat(*)>(_a[1])),(*reinterpret_cast< cv::Mat(*)>(_a[2])),(*reinterpret_cast< cv::Mat(*)>(_a[3]))); break;
        case 2: _t->receiveDistance((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->on_pushButtonLeftSource_clicked(); break;
        case 4: _t->on_pushButtonRightSource_clicked(); break;
        case 5: _t->on_pushButtonStart_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (widgetMeasOffline::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&widgetMeasOffline::SendStartMeas)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject widgetMeasOffline::staticMetaObject = {
    { &AppWidget::staticMetaObject, qt_meta_stringdata_widgetMeasOffline.data,
      qt_meta_data_widgetMeasOffline,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *widgetMeasOffline::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *widgetMeasOffline::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_widgetMeasOffline.stringdata0))
        return static_cast<void*>(this);
    return AppWidget::qt_metacast(_clname);
}

int widgetMeasOffline::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AppWidget::qt_metacall(_c, _id, _a);
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
void widgetMeasOffline::SendStartMeas()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
