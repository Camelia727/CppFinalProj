#include "agents.h"



Enemy::Enemy(int id, EnemyType type, QPointF position, QObject* parent)
    : id(id)
    , type(type)
    , pos(position)
    , QObject(parent)
{
    switch(type){
    case EnemyType::HAMADRYAD:
        max_hp = 200.0;
        hp = 200.0;
        atk = 5.0;
        spd = 10.0;
        attack_range = 10;
        break;
    case EnemyType::DEMON:
        max_hp = 180.0;
        hp = 180.0;
        atk = 10.0;
        spd = 10.0;
        attack_range = 0;
        break;
    case EnemyType::MUTATEDDEMON:
        max_hp = 250.0;
        hp = 250.0;
        atk = 50.0;
        spd = 20.0;
        attack_range = 0;
        break;
    case EnemyType::WIZARD:
        max_hp = 100.0;
        hp = 100.0;
        atk = 15.0;
        spd = 10.0;
        attack_range = 5;
        break;
    default:
        max_hp = 100.0;
        hp = 100.0;
        atk = 1.0;
        spd = 10.0;
        attack_range = 5;
        break;
    }
}

QPointF Enemy::getPos()
{
    return pos;
}

QPixmap Enemy::getPixmap()
{
    return pic;
}

double Enemy::getATK() const
{
    return atk;
}

double Enemy::getSpd() const
{
    return spd;
}

int Enemy::getId()
{
    return id;
}

int Enemy::getAtkRange() const
{
    return attack_range;
}

double Enemy::hpPercent() const
{
    return hp/max_hp;
}


void Enemy::move(QPointF direction)
{
    pos += direction * spd;
}

void Enemy::getHurt(double dmg)
{
    if (hp - dmg <= 0){
        hp = 0;
        emit enemyDead(this);
    }
    else
        hp -= dmg;
}

Hamadryad::Hamadryad(int id, QPointF position, QObject* parent)
    : Enemy(id, EnemyType::HAMADRYAD, position, parent)
{
    pic.load(":/pics/pics/hamadryad.png");
}

QRect Hamadryad::getRect()
{
    return QRect(90+50*pos.x(), 50+50*pos.y(),50,50);
}

Demon::Demon(int id, QPointF position, QObject *parent)
    : Enemy(id, EnemyType::DEMON, position, parent)
{
    pic.load(":/pics/pics/demon.png");
}

QRect Demon::getRect()
{
    return QRect(90+50*pos.x(), 50+50*pos.y(),50,50);
}

MutatedDemon::MutatedDemon(int id, QPointF position, QObject *parent)
    : Enemy(id, EnemyType::MUTATEDDEMON, position, parent)
{
    pic.load(":/pics/pics/mutated_demon.png");
}

QRect MutatedDemon::getRect()
{
    return QRect(90+50*pos.x(), 50+50*pos.y(),50,50);
}

Wizard::Wizard(int id, QPointF position, QObject *parent)
    : Enemy(id, EnemyType::WIZARD, position, parent)
{
    pic.load(":/pics/pics/wizard.png");
}

QRect Wizard::getRect()
{
    return QRect(90+50*pos.x(), 50+50*pos.y(),50,50);
}

