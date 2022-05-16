/****************************************************************************
** Meta object code from reading C++ file 'mygraohicsview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mygraohicsview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mygraohicsview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MyGraohicsView_t {
    QByteArrayData data[11];
    char stringdata0[118];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyGraohicsView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyGraohicsView_t qt_meta_stringdata_MyGraohicsView = {
    {
QT_MOC_LITERAL(0, 0, 14), // "MyGraohicsView"
QT_MOC_LITERAL(1, 15, 14), // "mouseMovePoint"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 5), // "point"
QT_MOC_LITERAL(4, 37, 16), // "mouseDoubleClick"
QT_MOC_LITERAL(5, 54, 8), // "keyPress"
QT_MOC_LITERAL(6, 63, 10), // "QKeyEvent*"
QT_MOC_LITERAL(7, 74, 5), // "event"
QT_MOC_LITERAL(8, 80, 12), // "mouseClicked"
QT_MOC_LITERAL(9, 93, 10), // "viewResize"
QT_MOC_LITERAL(10, 104, 13) // "QResizeEvent*"

    },
    "MyGraohicsView\0mouseMovePoint\0\0point\0"
    "mouseDoubleClick\0keyPress\0QKeyEvent*\0"
    "event\0mouseClicked\0viewResize\0"
    "QResizeEvent*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyGraohicsView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    1,   42,    2, 0x06 /* Public */,
       5,    1,   45,    2, 0x06 /* Public */,
       8,    1,   48,    2, 0x06 /* Public */,
       9,    1,   51,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QPoint,    3,
    QMetaType::Void, QMetaType::QPoint,    3,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::QPoint,    3,
    QMetaType::Void, 0x80000000 | 10,    7,

       0        // eod
};

void MyGraohicsView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyGraohicsView *_t = static_cast<MyGraohicsView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mouseMovePoint((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 1: _t->mouseDoubleClick((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 2: _t->keyPress((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 3: _t->mouseClicked((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 4: _t->viewResize((*reinterpret_cast< QResizeEvent*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MyGraohicsView::*_t)(QPoint );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGraohicsView::mouseMovePoint)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MyGraohicsView::*_t)(QPoint );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGraohicsView::mouseDoubleClick)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MyGraohicsView::*_t)(QKeyEvent * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGraohicsView::keyPress)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MyGraohicsView::*_t)(QPoint );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGraohicsView::mouseClicked)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (MyGraohicsView::*_t)(QResizeEvent * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGraohicsView::viewResize)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject MyGraohicsView::staticMetaObject = {
    { &QGraphicsView::staticMetaObject, qt_meta_stringdata_MyGraohicsView.data,
      qt_meta_data_MyGraohicsView,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MyGraohicsView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyGraohicsView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyGraohicsView.stringdata0))
        return static_cast<void*>(const_cast< MyGraohicsView*>(this));
    return QGraphicsView::qt_metacast(_clname);
}

int MyGraohicsView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void MyGraohicsView::mouseMovePoint(QPoint _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyGraohicsView::mouseDoubleClick(QPoint _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MyGraohicsView::keyPress(QKeyEvent * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MyGraohicsView::mouseClicked(QPoint _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MyGraohicsView::viewResize(QResizeEvent * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
