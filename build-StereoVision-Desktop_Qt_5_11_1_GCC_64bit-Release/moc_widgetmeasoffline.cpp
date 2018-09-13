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
    QByteArrayData data[23];
    char stringdata0[339];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_widgetMeasOffline_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_widgetMeasOffline_t qt_meta_stringdata_widgetMeasOffline = {
    {
QT_MOC_LITERAL(0, 0, 17), // "widgetMeasOffline"
QT_MOC_LITERAL(1, 18, 13), // "sendStartMeas"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 10), // "sendCoords"
QT_MOC_LITERAL(4, 44, 1), // "x"
QT_MOC_LITERAL(5, 46, 1), // "y"
QT_MOC_LITERAL(6, 48, 16), // "receiveDisparity"
QT_MOC_LITERAL(7, 65, 7), // "cv::Mat"
QT_MOC_LITERAL(8, 73, 12), // "leftFrameRaw"
QT_MOC_LITERAL(9, 86, 13), // "rightFrameRaw"
QT_MOC_LITERAL(10, 100, 9), // "disparity"
QT_MOC_LITERAL(11, 110, 15), // "receiveDistance"
QT_MOC_LITERAL(12, 126, 8), // "distance"
QT_MOC_LITERAL(13, 135, 13), // "receiveCoords"
QT_MOC_LITERAL(14, 149, 10), // "receiveFPS"
QT_MOC_LITERAL(15, 160, 3), // "fps"
QT_MOC_LITERAL(16, 164, 31), // "on_pushButtonLeftSource_clicked"
QT_MOC_LITERAL(17, 196, 32), // "on_pushButtonRightSource_clicked"
QT_MOC_LITERAL(18, 229, 26), // "on_pushButtonStart_clicked"
QT_MOC_LITERAL(19, 256, 24), // "on_spinBoxX_valueChanged"
QT_MOC_LITERAL(20, 281, 24), // "on_spinBoxY_valueChanged"
QT_MOC_LITERAL(21, 306, 26), // "on_pushButtonWrite_toggled"
QT_MOC_LITERAL(22, 333, 5) // "write"

    },
    "widgetMeasOffline\0sendStartMeas\0\0"
    "sendCoords\0x\0y\0receiveDisparity\0cv::Mat\0"
    "leftFrameRaw\0rightFrameRaw\0disparity\0"
    "receiveDistance\0distance\0receiveCoords\0"
    "receiveFPS\0fps\0on_pushButtonLeftSource_clicked\0"
    "on_pushButtonRightSource_clicked\0"
    "on_pushButtonStart_clicked\0"
    "on_spinBoxX_valueChanged\0"
    "on_spinBoxY_valueChanged\0"
    "on_pushButtonWrite_toggled\0write"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_widgetMeasOffline[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,
       3,    2,   75,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    3,   80,    2, 0x0a /* Public */,
      11,    1,   87,    2, 0x0a /* Public */,
      13,    2,   90,    2, 0x0a /* Public */,
      14,    1,   95,    2, 0x0a /* Public */,
      16,    0,   98,    2, 0x08 /* Private */,
      17,    0,   99,    2, 0x08 /* Private */,
      18,    0,  100,    2, 0x08 /* Private */,
      19,    1,  101,    2, 0x08 /* Private */,
      20,    1,  104,    2, 0x08 /* Private */,
      21,    1,  107,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,    5,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 7, 0x80000000 | 7,    8,    9,   10,
    QMetaType::Void, QMetaType::Double,   12,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,    5,
    QMetaType::Void, QMetaType::Double,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Bool,   22,

       0        // eod
};

void widgetMeasOffline::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        widgetMeasOffline *_t = static_cast<widgetMeasOffline *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendStartMeas(); break;
        case 1: _t->sendCoords((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->receiveDisparity((*reinterpret_cast< cv::Mat(*)>(_a[1])),(*reinterpret_cast< cv::Mat(*)>(_a[2])),(*reinterpret_cast< cv::Mat(*)>(_a[3]))); break;
        case 3: _t->receiveDistance((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->receiveCoords((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->receiveFPS((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->on_pushButtonLeftSource_clicked(); break;
        case 7: _t->on_pushButtonRightSource_clicked(); break;
        case 8: _t->on_pushButtonStart_clicked(); break;
        case 9: _t->on_spinBoxX_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_spinBoxY_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_pushButtonWrite_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (widgetMeasOffline::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&widgetMeasOffline::sendStartMeas)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (widgetMeasOffline::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&widgetMeasOffline::sendCoords)) {
                *result = 1;
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
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void widgetMeasOffline::sendStartMeas()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void widgetMeasOffline::sendCoords(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
