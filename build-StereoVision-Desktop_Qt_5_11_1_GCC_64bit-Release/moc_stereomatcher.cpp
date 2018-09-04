/****************************************************************************
** Meta object code from reading C++ file 'stereomatcher.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../StereoVision/stereomatcher.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'stereomatcher.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_StereoMatcher_t {
    QByteArrayData data[11];
    char stringdata0[139];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_StereoMatcher_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_StereoMatcher_t qt_meta_stringdata_StereoMatcher = {
    {
QT_MOC_LITERAL(0, 0, 13), // "StereoMatcher"
QT_MOC_LITERAL(1, 14, 13), // "sendDisparity"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 7), // "cv::Mat"
QT_MOC_LITERAL(4, 37, 12), // "leftFrameRaw"
QT_MOC_LITERAL(5, 50, 13), // "rightFrameRaw"
QT_MOC_LITERAL(6, 64, 9), // "disparity"
QT_MOC_LITERAL(7, 74, 11), // "sendJobDone"
QT_MOC_LITERAL(8, 86, 13), // "receiveFrames"
QT_MOC_LITERAL(9, 100, 18), // "leftFrameRectified"
QT_MOC_LITERAL(10, 119, 19) // "rightFrameRectified"

    },
    "StereoMatcher\0sendDisparity\0\0cv::Mat\0"
    "leftFrameRaw\0rightFrameRaw\0disparity\0"
    "sendJobDone\0receiveFrames\0leftFrameRectified\0"
    "rightFrameRectified"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StereoMatcher[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   29,    2, 0x06 /* Public */,
       7,    0,   36,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    4,   37,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3,    4,    5,    6,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3,    4,    5,    9,   10,

       0        // eod
};

void StereoMatcher::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        StereoMatcher *_t = static_cast<StereoMatcher *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendDisparity((*reinterpret_cast< cv::Mat(*)>(_a[1])),(*reinterpret_cast< cv::Mat(*)>(_a[2])),(*reinterpret_cast< cv::Mat(*)>(_a[3]))); break;
        case 1: _t->sendJobDone(); break;
        case 2: _t->receiveFrames((*reinterpret_cast< cv::Mat(*)>(_a[1])),(*reinterpret_cast< cv::Mat(*)>(_a[2])),(*reinterpret_cast< cv::Mat(*)>(_a[3])),(*reinterpret_cast< cv::Mat(*)>(_a[4]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (StereoMatcher::*)(cv::Mat , cv::Mat , cv::Mat );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&StereoMatcher::sendDisparity)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (StereoMatcher::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&StereoMatcher::sendJobDone)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject StereoMatcher::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_StereoMatcher.data,
      qt_meta_data_StereoMatcher,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *StereoMatcher::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StereoMatcher::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_StereoMatcher.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int StereoMatcher::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void StereoMatcher::sendDisparity(cv::Mat _t1, cv::Mat _t2, cv::Mat _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void StereoMatcher::sendJobDone()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
