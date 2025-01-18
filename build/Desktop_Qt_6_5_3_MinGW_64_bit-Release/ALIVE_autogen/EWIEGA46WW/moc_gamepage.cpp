/****************************************************************************
** Meta object code from reading C++ file 'gamepage.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../gamepage.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gamepage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMoveIconENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSMoveIconENDCLASS = QtMocHelpers::stringData(
    "MoveIcon",
    "iconPressed",
    "",
    "p",
    "iconReleased",
    "iconMoved"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMoveIconENDCLASS_t {
    uint offsetsAndSizes[12];
    char stringdata0[9];
    char stringdata1[12];
    char stringdata2[1];
    char stringdata3[2];
    char stringdata4[13];
    char stringdata5[10];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMoveIconENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMoveIconENDCLASS_t qt_meta_stringdata_CLASSMoveIconENDCLASS = {
    {
        QT_MOC_LITERAL(0, 8),  // "MoveIcon"
        QT_MOC_LITERAL(9, 11),  // "iconPressed"
        QT_MOC_LITERAL(21, 0),  // ""
        QT_MOC_LITERAL(22, 1),  // "p"
        QT_MOC_LITERAL(24, 12),  // "iconReleased"
        QT_MOC_LITERAL(37, 9)   // "iconMoved"
    },
    "MoveIcon",
    "iconPressed",
    "",
    "p",
    "iconReleased",
    "iconMoved"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMoveIconENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   32,    2, 0x06,    1 /* Public */,
       4,    0,   35,    2, 0x06,    3 /* Public */,
       5,    1,   36,    2, 0x06,    4 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QPoint,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,    3,

       0        // eod
};

Q_CONSTINIT const QMetaObject MoveIcon::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSMoveIconENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMoveIconENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMoveIconENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MoveIcon, std::true_type>,
        // method 'iconPressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QPoint, std::false_type>,
        // method 'iconReleased'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'iconMoved'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QPoint, std::false_type>
    >,
    nullptr
} };

void MoveIcon::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MoveIcon *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->iconPressed((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 1: _t->iconReleased(); break;
        case 2: _t->iconMoved((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MoveIcon::*)(QPoint );
            if (_t _q_method = &MoveIcon::iconPressed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MoveIcon::*)();
            if (_t _q_method = &MoveIcon::iconReleased; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MoveIcon::*)(QPoint );
            if (_t _q_method = &MoveIcon::iconMoved; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *MoveIcon::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MoveIcon::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMoveIconENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int MoveIcon::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void MoveIcon::iconPressed(QPoint _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MoveIcon::iconReleased()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MoveIcon::iconMoved(QPoint _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSGamePageENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSGamePageENDCLASS = QtMocHelpers::stringData(
    "GamePage",
    "gameend",
    "",
    "rounds",
    "closed",
    "iconPressEvent",
    "p",
    "iconReleasedEvent",
    "iconMoveEvent",
    "pawnMove",
    "gameUpdateAsked",
    "gameWin",
    "gameEnd",
    "endHome",
    "buffPageOpen",
    "buffsel",
    "buff",
    "pausegoon",
    "secUpdate",
    "time",
    "coinUpdate"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSGamePageENDCLASS_t {
    uint offsetsAndSizes[42];
    char stringdata0[9];
    char stringdata1[8];
    char stringdata2[1];
    char stringdata3[7];
    char stringdata4[7];
    char stringdata5[15];
    char stringdata6[2];
    char stringdata7[18];
    char stringdata8[14];
    char stringdata9[9];
    char stringdata10[16];
    char stringdata11[8];
    char stringdata12[8];
    char stringdata13[8];
    char stringdata14[13];
    char stringdata15[8];
    char stringdata16[5];
    char stringdata17[10];
    char stringdata18[10];
    char stringdata19[5];
    char stringdata20[11];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSGamePageENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSGamePageENDCLASS_t qt_meta_stringdata_CLASSGamePageENDCLASS = {
    {
        QT_MOC_LITERAL(0, 8),  // "GamePage"
        QT_MOC_LITERAL(9, 7),  // "gameend"
        QT_MOC_LITERAL(17, 0),  // ""
        QT_MOC_LITERAL(18, 6),  // "rounds"
        QT_MOC_LITERAL(25, 6),  // "closed"
        QT_MOC_LITERAL(32, 14),  // "iconPressEvent"
        QT_MOC_LITERAL(47, 1),  // "p"
        QT_MOC_LITERAL(49, 17),  // "iconReleasedEvent"
        QT_MOC_LITERAL(67, 13),  // "iconMoveEvent"
        QT_MOC_LITERAL(81, 8),  // "pawnMove"
        QT_MOC_LITERAL(90, 15),  // "gameUpdateAsked"
        QT_MOC_LITERAL(106, 7),  // "gameWin"
        QT_MOC_LITERAL(114, 7),  // "gameEnd"
        QT_MOC_LITERAL(122, 7),  // "endHome"
        QT_MOC_LITERAL(130, 12),  // "buffPageOpen"
        QT_MOC_LITERAL(143, 7),  // "buffsel"
        QT_MOC_LITERAL(151, 4),  // "buff"
        QT_MOC_LITERAL(156, 9),  // "pausegoon"
        QT_MOC_LITERAL(166, 9),  // "secUpdate"
        QT_MOC_LITERAL(176, 4),  // "time"
        QT_MOC_LITERAL(181, 10)   // "coinUpdate"
    },
    "GamePage",
    "gameend",
    "",
    "rounds",
    "closed",
    "iconPressEvent",
    "p",
    "iconReleasedEvent",
    "iconMoveEvent",
    "pawnMove",
    "gameUpdateAsked",
    "gameWin",
    "gameEnd",
    "endHome",
    "buffPageOpen",
    "buffsel",
    "buff",
    "pausegoon",
    "secUpdate",
    "time",
    "coinUpdate"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSGamePageENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  104,    2, 0x06,    1 /* Public */,
       4,    0,  107,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    1,  108,    2, 0x0a,    4 /* Public */,
       7,    0,  111,    2, 0x0a,    6 /* Public */,
       8,    1,  112,    2, 0x0a,    7 /* Public */,
       9,    0,  115,    2, 0x0a,    9 /* Public */,
      10,    0,  116,    2, 0x0a,   10 /* Public */,
      11,    0,  117,    2, 0x0a,   11 /* Public */,
      12,    0,  118,    2, 0x0a,   12 /* Public */,
      13,    0,  119,    2, 0x0a,   13 /* Public */,
      14,    0,  120,    2, 0x0a,   14 /* Public */,
      15,    1,  121,    2, 0x0a,   15 /* Public */,
      17,    0,  124,    2, 0x0a,   17 /* Public */,
      18,    1,  125,    2, 0x0a,   18 /* Public */,
      20,    0,  128,    2, 0x0a,   20 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QPoint,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject GamePage::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSGamePageENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSGamePageENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSGamePageENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<GamePage, std::true_type>,
        // method 'gameend'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'closed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'iconPressEvent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QPoint, std::false_type>,
        // method 'iconReleasedEvent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'iconMoveEvent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QPoint, std::false_type>,
        // method 'pawnMove'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'gameUpdateAsked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'gameWin'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'gameEnd'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'endHome'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'buffPageOpen'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'buffsel'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'pausegoon'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'secUpdate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'coinUpdate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void GamePage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GamePage *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->gameend((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->closed(); break;
        case 2: _t->iconPressEvent((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 3: _t->iconReleasedEvent(); break;
        case 4: _t->iconMoveEvent((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 5: _t->pawnMove(); break;
        case 6: _t->gameUpdateAsked(); break;
        case 7: _t->gameWin(); break;
        case 8: _t->gameEnd(); break;
        case 9: _t->endHome(); break;
        case 10: _t->buffPageOpen(); break;
        case 11: _t->buffsel((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 12: _t->pausegoon(); break;
        case 13: _t->secUpdate((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 14: _t->coinUpdate(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GamePage::*)(int );
            if (_t _q_method = &GamePage::gameend; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GamePage::*)();
            if (_t _q_method = &GamePage::closed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *GamePage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GamePage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSGamePageENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int GamePage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void GamePage::gameend(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GamePage::closed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
