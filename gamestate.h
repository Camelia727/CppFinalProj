#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <QWidget>
#include <QList>
#include <QPainter>
#include <agents.h>
#include <QPair>
#include <QQueue>
#include <QTimer>
#include <QRandomGenerator>
#include "history.h"

class GameMap{
private:
    int m, n, top, left;
    QList<QPoint> blocks;
public:
    GameMap();
    int getTop() const {return top;}
    int getLeft() const {return left;}
    int getBottom() const {return top+n;}
    int getRight() const {return left+m;}
    QSize getSize();
    QList<QPoint> get_blocks();
};

class FallingObject : public QObject {
    Q_OBJECT
private:
    int type;
    QPointF pos;
    QPixmap pic;
public:
    FallingObject(int t, QPointF pos);
    int getType() const {return type;}
    QPointF getPos() const {return pos;}
    QPixmap getPic() const {return pic;}
};

class Pawn : public QObject{
    Q_OBJECT
private:
    History* history;
    QString name;
    QPointF pos;
    QPixmap pic;
    double max_hp;
    double hp;
    double atk;
    double atp;
    double spd;
    int picking_range;
    int attack_range;
    int coin;
    double coinX;
    int revive;
    double revive_recover;
    int level;
    int exp;
    bool bleeding;
    bool crit;
    bool dead;
public:
    explicit Pawn(History* his, RoleType type, QObject* parent = nullptr);
    void beHurt(double dmg = 0.0);
    void recoverHp(double rec = 0.0) {hp = fmin(max_hp, hp+rec);}
    void attack(Enemy* enemy);
    void setBleeding(bool b) {bleeding = b;}
    void setPos(QPointF npos) {pos = npos;}
    void gainExp(const int e) {exp+=e; if(exp >= 100) levelUp();}
    void levelUp() {level++;exp-=100;emit levelup();}
    void gainBuff(int buff);
    void pickItem(int type);
    QPointF getPos() const {return pos;}
    QPixmap getPic() const {return pic;}
    QRectF getRect() const {return QRectF(pos, QSizeF(40,70));}
    int getExp() const {return exp;}
    int getLevel() const {return level;}
    int getAtkRange() const {return attack_range;}
    int getAtkSpeed() const {return atp;}
    int getRevive() const {return revive;}
    int getPickingRg() const {return picking_range;}
    double getCoinX() const {return coinX;}
    double getSpd() const {return spd;}
    double getHp() const {return hp;}
    double getMaxHp() const {return max_hp;}
    double hpPercent() const {return hp/max_hp;}
    bool isBleeding() const {return bleeding;}
    bool isDead() const {return dead;}
signals:
    void pawnDead();
    void levelup();
    void atpChange();
};

enum class Status{
    GAMEOFF,
    GAMEON,
    GAMETMP,
    GAMEWIN,
    GAMELOSE
};

class GameState : public QObject
{
    Q_OBJECT
private:
    int id;
    int rounds;
    int coins;
    qint64 remainedtime;

    GameMap Map;
    Status status;
    History* history;

    Pawn* Pawn;
    QPointF PawnPos;
    QRect PawnRect;
    QList<Enemy*> EnemyList;
    QList<FallingObject*> FallingList;
    QTimer* secTimer;
    QTimer* enemyMoveTimer;
    QTimer* enemyAttackTimer;
    QTimer* enemyUpdateTimer;
    QTimer* pawnAttackTimer;
    QTimer* pawnMoveTimer;
    QTimer* roundTimer;


public:
    enum Direction{
        LEFT,
        RIGHT,
        UP,
        DOWN,
        NONE
    };
    GameState(History* his, QString name, QObject* parent = nullptr);
    ~GameState();
    int getRounds() const;
    int getCoins() const;
    int getRevive() const {return Pawn->getRevive();}
    double getCoinX() const {return Pawn->getCoinX();}
    Status getStatus() const;
    QPointF generateEdgePoint();
    int getDistance(Enemy* enemy) const;
    QPointF getPawnPos () const;
    QPixmap getPawnPixmap() const;
    QRectF getPawnRect() const;
    double getPawnHpPercent() const;
    GameMap getMap() const;
    QList<FallingObject*> getFallingList() const {return FallingList;}
    QList<Enemy*> getEnemyList() const;
    QPointF EnemyDirection(Enemy* enemy);
    void PawnMove(QPointF direction);
    void EnemyCreate(EnemyType enemy_type = EnemyType::BASE, QPointF pos = QPoint(0,0));
    void EnemyMove(Enemy* enemy = nullptr);
    void EnemyDead(Enemy* enemy = nullptr);
    void gainBuff(int buff);
    void setStatus(Status status);
    void Falling(QPointF pos);
    void pickItem(int type);

signals:
    void levelup();
    void pawnmoving();
    void gameUpdate();
    void gameWin();
    void gameLose();
    void falling(QPointF pos);
    void sec(int time);
    void coinsUpdate();

public slots:
    void secUpdate();
    void GameUpdate();
    void EnemyAttack();
    void EnemyUpdate();
    void PawnAttack();
    void PawnLevelUp();
    void PawnAtpUp();
    void pawnMoving() {emit pawnmoving();}
    void GameWin();
    void GameLose();
    void GameStateChange(Status nxt_status);
};

#endif // GAMESTATE_H
