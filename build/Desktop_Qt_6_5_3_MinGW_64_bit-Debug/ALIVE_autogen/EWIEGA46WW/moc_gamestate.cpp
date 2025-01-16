/****************************************************************************
** Meta object code from reading C++ file 'gamestate.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../gamestate.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gamestate.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSFallingObjectENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSFallingObjectENDCLASS = QtMocHelpers::stringData(
    "FallingObject"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSFallingObjectENDCLASS_t {
    uint offsetsAndSizes[2];
    char stringdata0[14];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSFallingObjectENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSFallingObjectENDCLASS_t qt_meta_stringdata_CLASSFallingObjectENDCLASS = {
    {
        QT_MOC_LITERAL(0, 13)   // "FallingObject"
    },
    "FallingObject"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSFallingObjectENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

Q_CONSTINIT const QMetaObject FallingObject::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSFallingObjectENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSFallingObjectENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSFallingObjectENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<FallingObject, std::true_type>
    >,
    nullptr
} };

void FallingObject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject *FallingObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FallingObject::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSFallingObjectENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int FallingObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSPawnENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSPawnENDCLASS = QtMocHelpers::stringData(
    "Pawn",
    "pawnDead",
    "",
    "levelup"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSPawnENDCLASS_t {
    uint offsetsAndSizes[8];
    char stringdata0[5];
    char stringdata1[9];
    char stringdata2[1];
    char stringdata3[8];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSPawnENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSPawnENDCLASS_t qt_meta_stringdata_CLASSPawnENDCLASS = {
    {
        QT_MOC_LITERAL(0, 4),  // "Pawn"
        QT_MOC_LITERAL(5, 8),  // "pawnDead"
        QT_MOC_LITERAL(14, 0),  // ""
        QT_MOC_LITERAL(15, 7)   // "levelup"
    },
    "Pawn",
    "pawnDead",
    "",
    "levelup"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSPawnENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   26,    2, 0x06,    1 /* Public */,
       3,    0,   27,    2, 0x06,    2 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Pawn::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSPawnENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSPawnENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSPawnENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Pawn, std::true_type>,
        // method 'pawnDead'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'levelup'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Pawn::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Pawn *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->pawnDead(); break;
        case 1: _t->levelup(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Pawn::*)();
            if (_t _q_method = &Pawn::pawnDead; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Pawn::*)();
            if (_t _q_method = &Pawn::levelup; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject *Pawn::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Pawn::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSPawnENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Pawn::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void Pawn::pawnDead()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Pawn::levelup()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSGameStateENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSGameStateENDCLASS = QtMocHelpers::stringData(
    "GameState",
    "levelup",
    "",
    "pawnmoving",
    "gameUpdate",
    "gameWin",
    "gameLose",
    "falling",
    "pos",
    "sec",
    "time",
    "secUpdate",
    "GameUpdate",
    "EnemyAttack",
    "EnemyUpdate",
    "PawnAttack",
    "PawnLevelUp",
    "pawnMoving",
    "GameWin",
    "GameLose",
    "GameStateChange",
    "Status",
    "nxt_status"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSGameStateENDCLASS_t {
    uint offsetsAndSizes[46];
    char stringdata0[10];
    char stringdata1[8];
    char stringdata2[1];
    char stringdata3[11];
    char stringdata4[11];
    char stringdata5[8];
    char stringdata6[9];
    char stringdata7[8];
    char stringdata8[4];
    char stringdata9[4];
    char stringdata10[5];
    char stringdata11[10];
    char stringdata12[11];
    char stringdata13[12];
    char stringdata14[12];
    char stringdata15[11];
    char stringdata16[12];
    char stringdata17[11];
    char stringdata18[8];
    char stringdata19[9];
    char stringdata20[16];
    char stringdata21[7];
    char stringdata22[11];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSGameStateENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSGameStateENDCLASS_t qt_meta_stringdata_CLASSGameStateENDCLASS = {
    {
        QT_MOC_LITERAL(0, 9),  // "GameState"
        QT_MOC_LITERAL(10, 7),  // "levelup"
        QT_MOC_LITERAL(18, 0),  // ""
        QT_MOC_LITERAL(19, 10),  // "pawnmoving"
        QT_MOC_LITERAL(30, 10),  // "gameUpdate"
        QT_MOC_LITERAL(41, 7),  // "gameWin"
        QT_MOC_LITERAL(49, 8),  // "gameLose"
        QT_MOC_LITERAL(58, 7),  // "falling"
        QT_MOC_LITERAL(66, 3),  // "pos"
        QT_MOC_LITERAL(70, 3),  // "sec"
        QT_MOC_LITERAL(74, 4),  // "time"
        QT_MOC_LITERAL(79, 9),  // "secUpdate"
        QT_MOC_LITERAL(89, 10),  // "GameUpdate"
        QT_MOC_LITERAL(100, 11),  // "EnemyAttack"
        QT_MOC_LITERAL(112, 11),  // "EnemyUpdate"
        QT_MOC_LITERAL(124, 10),  // "PawnAttack"
        QT_MOC_LITERAL(135, 11),  // "PawnLevelUp"
        QT_MOC_LITERAL(147, 10),  // "pawnMoving"
        QT_MOC_LITERAL(158, 7),  // "GameWin"
        QT_MOC_LITERAL(166, 8),  // "GameLose"
        QT_MOC_LITERAL(175, 15),  // "GameStateChange"
        QT_MOC_LITERAL(191, 6),  // "Status"
        QT_MOC_LITERAL(198, 10)   // "nxt_status"
    },
    "GameState",
    "levelup",
    "",
    "pawnmoving",
    "gameUpdate",
    "gameWin",
    "gameLose",
    "falling",
    "pos",
    "sec",
    "time",
    "secUpdate",
    "GameUpdate",
    "EnemyAttack",
    "EnemyUpdate",
    "PawnAttack",
    "PawnLevelUp",
    "pawnMoving",
    "GameWin",
    "GameLose",
    "GameStateChange",
    "Status",
    "nxt_status"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSGameStateENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  116,    2, 0x06,    1 /* Public */,
       3,    0,  117,    2, 0x06,    2 /* Public */,
       4,    0,  118,    2, 0x06,    3 /* Public */,
       5,    0,  119,    2, 0x06,    4 /* Public */,
       6,    0,  120,    2, 0x06,    5 /* Public */,
       7,    1,  121,    2, 0x06,    6 /* Public */,
       9,    1,  124,    2, 0x06,    8 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      11,    0,  127,    2, 0x0a,   10 /* Public */,
      12,    0,  128,    2, 0x0a,   11 /* Public */,
      13,    0,  129,    2, 0x0a,   12 /* Public */,
      14,    0,  130,    2, 0x0a,   13 /* Public */,
      15,    0,  131,    2, 0x0a,   14 /* Public */,
      16,    0,  132,    2, 0x0a,   15 /* Public */,
      17,    0,  133,    2, 0x0a,   16 /* Public */,
      18,    0,  134,    2, 0x0a,   17 /* Public */,
      19,    0,  135,    2, 0x0a,   18 /* Public */,
      20,    1,  136,    2, 0x0a,   19 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPointF,    8,
    QMetaType::Void, QMetaType::Int,   10,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 21,   22,

       0        // eod
};

Q_CONSTINIT const QMetaObject GameState::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSGameStateENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSGameStateENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSGameStateENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<GameState, std::true_type>,
        // method 'levelup'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'pawnmoving'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'gameUpdate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'gameWin'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'gameLose'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'falling'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QPointF, std::false_type>,
        // method 'sec'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'secUpdate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'GameUpdate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'EnemyAttack'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'EnemyUpdate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'PawnAttack'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'PawnLevelUp'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'pawnMoving'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'GameWin'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'GameLose'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'GameStateChange'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Status, std::false_type>
    >,
    nullptr
} };

void GameState::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GameState *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->levelup(); break;
        case 1: _t->pawnmoving(); break;
        case 2: _t->gameUpdate(); break;
        case 3: _t->gameWin(); break;
        case 4: _t->gameLose(); break;
        case 5: _t->falling((*reinterpret_cast< std::add_pointer_t<QPointF>>(_a[1]))); break;
        case 6: _t->sec((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 7: _t->secUpdate(); break;
        case 8: _t->GameUpdate(); break;
        case 9: _t->EnemyAttack(); break;
        case 10: _t->EnemyUpdate(); break;
        case 11: _t->PawnAttack(); break;
        case 12: _t->PawnLevelUp(); break;
        case 13: _t->pawnMoving(); break;
        case 14: _t->GameWin(); break;
        case 15: _t->GameLose(); break;
        case 16: _t->GameStateChange((*reinterpret_cast< std::add_pointer_t<Status>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GameState::*)();
            if (_t _q_method = &GameState::levelup; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GameState::*)();
            if (_t _q_method = &GameState::pawnmoving; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (GameState::*)();
            if (_t _q_method = &GameState::gameUpdate; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (GameState::*)();
            if (_t _q_method = &GameState::gameWin; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (GameState::*)();
            if (_t _q_method = &GameState::gameLose; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (GameState::*)(QPointF );
            if (_t _q_method = &GameState::falling; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (GameState::*)(int );
            if (_t _q_method = &GameState::sec; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
    }
}

const QMetaObject *GameState::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameState::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSGameStateENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int GameState::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void GameState::levelup()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void GameState::pawnmoving()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void GameState::gameUpdate()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void GameState::gameWin()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void GameState::gameLose()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void GameState::falling(QPointF _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void GameState::sec(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
