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
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
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
    return QWidget::qt_metacast(_clname);
}

int FallingObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
    "gameUpdate",
    "gameLose",
    "GameUpdate",
    "EnemyAttack",
    "EnemyUpdate",
    "PawnAttack",
    "PawnLevelUp",
    "GameLose",
    "GameStateChange",
    "Status",
    "nxt_status"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSGameStateENDCLASS_t {
    uint offsetsAndSizes[28];
    char stringdata0[10];
    char stringdata1[8];
    char stringdata2[1];
    char stringdata3[11];
    char stringdata4[9];
    char stringdata5[11];
    char stringdata6[12];
    char stringdata7[12];
    char stringdata8[11];
    char stringdata9[12];
    char stringdata10[9];
    char stringdata11[16];
    char stringdata12[7];
    char stringdata13[11];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSGameStateENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSGameStateENDCLASS_t qt_meta_stringdata_CLASSGameStateENDCLASS = {
    {
        QT_MOC_LITERAL(0, 9),  // "GameState"
        QT_MOC_LITERAL(10, 7),  // "levelup"
        QT_MOC_LITERAL(18, 0),  // ""
        QT_MOC_LITERAL(19, 10),  // "gameUpdate"
        QT_MOC_LITERAL(30, 8),  // "gameLose"
        QT_MOC_LITERAL(39, 10),  // "GameUpdate"
        QT_MOC_LITERAL(50, 11),  // "EnemyAttack"
        QT_MOC_LITERAL(62, 11),  // "EnemyUpdate"
        QT_MOC_LITERAL(74, 10),  // "PawnAttack"
        QT_MOC_LITERAL(85, 11),  // "PawnLevelUp"
        QT_MOC_LITERAL(97, 8),  // "GameLose"
        QT_MOC_LITERAL(106, 15),  // "GameStateChange"
        QT_MOC_LITERAL(122, 6),  // "Status"
        QT_MOC_LITERAL(129, 10)   // "nxt_status"
    },
    "GameState",
    "levelup",
    "",
    "gameUpdate",
    "gameLose",
    "GameUpdate",
    "EnemyAttack",
    "EnemyUpdate",
    "PawnAttack",
    "PawnLevelUp",
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
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   74,    2, 0x06,    1 /* Public */,
       3,    0,   75,    2, 0x06,    2 /* Public */,
       4,    0,   76,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    0,   77,    2, 0x0a,    4 /* Public */,
       6,    0,   78,    2, 0x0a,    5 /* Public */,
       7,    0,   79,    2, 0x0a,    6 /* Public */,
       8,    0,   80,    2, 0x0a,    7 /* Public */,
       9,    0,   81,    2, 0x0a,    8 /* Public */,
      10,    0,   82,    2, 0x0a,    9 /* Public */,
      11,    1,   83,    2, 0x0a,   10 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   13,

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
        // method 'gameUpdate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'gameLose'
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
        case 1: _t->gameUpdate(); break;
        case 2: _t->gameLose(); break;
        case 3: _t->GameUpdate(); break;
        case 4: _t->EnemyAttack(); break;
        case 5: _t->EnemyUpdate(); break;
        case 6: _t->PawnAttack(); break;
        case 7: _t->PawnLevelUp(); break;
        case 8: _t->GameLose(); break;
        case 9: _t->GameStateChange((*reinterpret_cast< std::add_pointer_t<Status>>(_a[1]))); break;
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
            if (_t _q_method = &GameState::gameUpdate; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (GameState::*)();
            if (_t _q_method = &GameState::gameLose; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
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
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void GameState::levelup()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void GameState::gameUpdate()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void GameState::gameLose()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
