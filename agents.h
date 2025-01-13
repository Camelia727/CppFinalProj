#ifndef AGENTS_H
#define AGENTS_H
#include <QObject>
#include <QString>
#include <QPixmap>
#include <QDebug>


enum RoleType{
    NONE,
    SWORDSMAN,
    MAGICIAN
};

class Role{
    QString name;
    double hp;
    double atk;
    double def;
    int spd;
    int picking_range;
    int attack_range;

};







/*
 * *****************************************************
 * *****************************************************
 * Player Roles are above
 * Enemy Roles are below
 * *****************************************************
 * *****************************************************
*/

enum class EnemyType{
    BASE=0,
    HAMADRYAD=50,
    DEMON=75,
    WIZARD=90,
    MUTATEDDEMON=100
};

class Enemy : public QObject{
    Q_OBJECT
protected:
    int id;
    EnemyType type;
    double max_hp;
    double hp;
    double atk;
    double spd;
    int attack_range;
    QPixmap pic;
    QPointF pos;
public:
    enum Direction{
        UP,
        DOWN,
        LEFT,
        RIGHT,
        NONE
    };
    Enemy(int id, EnemyType type = EnemyType::BASE, QPointF position = QPoint(0,0), QObject* parent = nullptr);
    QPointF getPos();
    QPixmap getPixmap();
    double getATK() const;
    double getSpd() const;
    int getId();
    int getAtkRange() const;
    double hpPercent() const;
    void move(QPointF direction);
    void getHurt(double dmg);
signals:
    void enemyDead(Enemy* enemy);
};

class Hamadryad : public Enemy{
public:
    Hamadryad(int id, QPointF position = QPoint(0,0), QObject* parent = nullptr);
    QRect getRect();
};

class Demon : public Enemy{
public:
    Demon(int id, QPointF position = QPoint(0,0), QObject* parent = nullptr);
    QRect getRect();
};

class MutatedDemon : public Enemy{
public:
    MutatedDemon(int id, QPointF position = QPoint(0,0), QObject* parent = nullptr);
    QRect getRect();
};

class Wizard : public Enemy{
public:
    Wizard(int id, QPointF position = QPoint(0,0), QObject* parent = nullptr);
    QRect getRect();
};


/*
 * *****************************************************
 * *****************************************************
 * Enemy Roles are above
 * Weapons are below
 * *****************************************************
 * *****************************************************
*/

// class Weapon{
//     QString name;
//     double atk_mag;
//     double attack_range;
//     double duration;
//     double cd;
// public:
//     enum Weapons{
//         KNIFE,
//         SWORD,
//         LONGSWORD,
//         PEACHWAND,
//         ELDERWAND,
//         DEATHWAND
//     };
//     Weapon();
//     virtual double get_atkmag() const = 0;
//     virtual double get_atkrge() const = 0;
//     virtual double get_duration() const = 0;
//     virtual double get_cd() const = 0;
//     virtual void set_atkmag() = 0;
//     virtual void set_duration() = 0;
//     virtual void set_cd() = 0;
// };

// class Knife : public Weapon{
// public:
//     Knife();
//     double get_atkmag();
//     double get_atkrge() const;
//     double get_duration() const;
//     double get_cd() const;
//     void set_atkmag();
//     void set_duration();
//     void set_cd();
// };




#endif // AGENTS_H
