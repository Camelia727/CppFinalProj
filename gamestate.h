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

enum DiffiLevel{
    EASY = 75,
    MEDIUM = 90,
    HARD = 100
};


class Grid {
private:
    int style;
    QPixmap pic;
    QList<Enemy*> enemyList;
public:
    enum Style : int{
        PATH,
        BLOCK
    };
    Grid(Style s = Grid::PATH);
    QPixmap getPic();
    QList<Enemy*> getEnemyList();
    int getEnemyCnt();
    bool isBlock() const;
    void addEnemy(Enemy* enemy);
    void removeEnemy(Enemy* enemy);
};

class GameMap{
private:
    int m, n;
    QList<QPoint> blocks;
public:
    GameMap();
    QSize getSize();
    QList<QPoint> get_blocks();
    void importMap(QString fileName);
    void exportMap();

};

class FallingObject : public QWidget {
    Q_OBJECT
private:
    int type;
protected:
    void paintEvent(QPaintEvent* event);
public:
    enum Type : int{
        NONE,
        COINBOX,
        MEDICIAN,
        EXPBOX
    };
    FallingObject(QWidget* parent = nullptr, int t = 0);
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
    double coin;
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
    void recoverHp(double rec = 0.0) {hp += rec;}
    void attack(Enemy* enemy);
    void setBleeding(bool b) {bleeding = b;}
    void setPos(QPointF npos) {pos = npos;}
    void gainExp(const int e) {exp+=e; if(exp >= 100) levelUp();}
    void levelUp() {level++;exp-=100;emit levelup();}
    void gainBuff(int buff);
    QPointF getPos() const {return pos;}
    QPixmap getPic() const {return pic;}
    QRectF getRect() const {return QRectF(pos, QSizeF(40,70));}
    int getExp() const {return exp;}
    int getLevel() const {return level;}
    int getAtkRange() const {return attack_range;}
    int getAtkSpeed() const {return atp;}
    double getSpd() const {return spd;}
    double hpPercent() const {return hp/max_hp;}
    bool isBleeding() const {return bleeding;}
    bool isDead() const {return dead;}
signals:
    void pawnDead();
    void levelup();
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
    DiffiLevel difficulty;
    Status status;
    History* history;

    Pawn* Pawn;
    QPointF PawnPos;
    QRect PawnRect;
    QList<Enemy*> EnemyList;
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
    GameState(History* his, DiffiLevel diffi = DiffiLevel::EASY, QObject* parent = nullptr);
    ~GameState();
    int getRounds() const;
    int getCoins() const;
    Status getStatus() const;
    QPointF generateEdgePoint();
    int getDistance(Enemy* enemy) const;
    QPointF getPawnPos () const;
    QPixmap getPawnPixmap() const;
    QRectF getPawnRect() const;
    double getPawnHpPercent() const;
    GameMap getMap() const;
    QList<Enemy*> getEnemyList() const;
    QPointF EnemyDirection(Enemy* enemy);
    void PawnMove(QPointF direction);
    void EnemyCreate(EnemyType enemy_type = EnemyType::BASE, QPointF pos = QPoint(0,0));
    void EnemyMove(Enemy* enemy = nullptr);
    void EnemyDead(Enemy* enemy = nullptr);
    void gainBuff(int buff);
    void setStatus(Status status);

signals:
    void levelup();
    void pawnmoving();
    void gameUpdate();
    void gameWin();
    void gameLose();

public slots:
    void GameUpdate();
    void EnemyAttack();
    void EnemyUpdate();
    void PawnAttack();
    void PawnLevelUp();
    void pawnMoving() {emit pawnmoving();}
    void GameWin();
    void GameLose();
    void GameStateChange(Status nxt_status);
};

#endif // GAMESTATE_H
