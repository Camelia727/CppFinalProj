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
    "gameexit",
    "closed",
    "iconPressEvent",
    "p",
    "iconReleasedEvent",
    "iconMoveEvent",
    "pawnMove",
    "gameUpdateAsked",
    "gameEnd",
    "endHome",
    "endExit",
    "buffPageOpen",
    "buffsel",
    "buff"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSGamePageENDCLASS_t {
    uint offsetsAndSizes[36];
    char stringdata0[9];
    char stringdata1[8];
    char stringdata2[1];
    char stringdata3[7];
    char stringdata4[9];
    char stringdata5[7];
    char stringdata6[15];
    char stringdata7[2];
    char stringdata8[18];
    char stringdata9[14];
    char stringdata10[9];
    char stringdata11[16];
    char stringdata12[8];
    char stringdata13[8];
    char stringdata14[8];
    char stringdata15[13];
    char stringdata16[8];
    char stringdata17[5];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSGamePageENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSGamePageENDCLASS_t qt_meta_stringdata_CLASSGamePageENDCLASS = {
    {
        QT_MOC_LITERAL(0, 8),  // "GamePage"
        QT_MOC_LITERAL(9, 7),  // "gameend"
        QT_MOC_LITERAL(17, 0),  // ""
        QT_MOC_LITERAL(18, 6),  // "rounds"
        QT_MOC_LITERAL(25, 8),  // "gameexit"
        QT_MOC_LITERAL(34, 6),  // "closed"
        QT_MOC_LITERAL(41, 14),  // "iconPressEvent"
        QT_MOC_LITERAL(56, 1),  // "p"
        QT_MOC_LITERAL(58, 17),  // "iconReleasedEvent"
        QT_MOC_LITERAL(76, 13),  // "iconMoveEvent"
        QT_MOC_LITERAL(90, 8),  // "pawnMove"
        QT_MOC_LITERAL(99, 15),  // "gameUpdateAsked"
        QT_MOC_LITERAL(115, 7),  // "gameEnd"
        QT_MOC_LITERAL(123, 7),  // "endHome"
        QT_MOC_LITERAL(131, 7),  // "endExit"
        QT_MOC_LITERAL(139, 12),  // "buffPageOpen"
        QT_MOC_LITERAL(152, 7),  // "buffsel"
        QT_MOC_LITERAL(160, 4)   // "buff"
    },
    "GamePage",
    "gameend",
    "",
    "rounds",
    "gameexit",
    "closed",
    "iconPressEvent",
    "p",
    "iconReleasedEvent",
    "iconMoveEvent",
    "pawnMove",
    "gameUpdateAsked",
    "gameEnd",
    "endHome",
    "endExit",
    "buffPageOpen",
    "buffsel",
    "buff"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSGamePageENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   92,    2, 0x06,    1 /* Public */,
       4,    1,   95,    2, 0x06,    3 /* Public */,
       5,    0,   98,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    1,   99,    2, 0x0a,    6 /* Public */,
       8,    0,  102,    2, 0x0a,    8 /* Public */,
       9,    1,  103,    2, 0x0a,    9 /* Public */,
      10,    0,  106,    2, 0x0a,   11 /* Public */,
      11,    0,  107,    2, 0x0a,   12 /* Public */,
      12,    0,  108,    2, 0x0a,   13 /* Public */,
      13,    0,  109,    2, 0x0a,   14 /* Public */,
      14,    0,  110,    2, 0x0a,   15 /* Public */,
      15,    0,  111,    2, 0x0a,   16 /* Public */,
      16,    1,  112,    2, 0x0a,   17 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QPoint,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   17,

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
        // method 'gameexit'
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
        // method 'gameEnd'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'endHome'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'endExit'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'buffPageOpen'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'buffsel'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
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
        case 1: _t->gameexit((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->closed(); break;
        case 3: _t->iconPressEvent((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 4: _t->iconReleasedEvent(); break;
        case 5: _t->iconMoveEvent((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 6: _t->pawnMove(); break;
        case 7: _t->gameUpdateAsked(); break;
        case 8: _t->gameEnd(); break;
        case 9: _t->endHome(); break;
        case 10: _t->endExit(); break;
        case 11: _t->buffPageOpen(); break;
        case 12: _t->buffsel((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
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
            using _t = void (GamePage::*)(int );
            if (_t _q_method = &GamePage::gameexit; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (GamePage::*)();
            if (_t _q_method = &GamePage::closed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
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
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 13;
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
void GamePage::gameexit(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GamePage::closed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
