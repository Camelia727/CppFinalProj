#include "gamestate.h"
#include <queue>


GameMap::GameMap()
{
    m = 940;
    n = 420;
    top = 250;
    left = 90;
    blocks = {QPoint(180,390),QPoint(320,550),QPoint(450,400),
                QPoint(550,550),QPoint(800,450),QPoint(680,550)};
}

QSize GameMap::getSize()
{
    return QSize(m, n);
}

QList<QPoint> GameMap::get_blocks()
{
    return blocks;
}

GameState::GameState(History* his, QString name, QObject* parent)
    : QObject{parent}
    , id(0)
    , rounds(0)
    , coins(0)
    , status(Status::GAMEON)
    , history(his)
    , PawnPos(290, 360)
    , EnemyList({})
    , secTimer(new QTimer(this))
    , enemyMoveTimer(new QTimer(this))
    , enemyAttackTimer(new QTimer(this))
    , enemyUpdateTimer(new QTimer(this))
    , pawnAttackTimer(new QTimer(this))
    , pawnMoveTimer(new QTimer(this))
    , roundTimer(new QTimer(this))
{
    if (name == "Swordsman")
        Pawn = new class Pawn(his, RoleType::SWORDSMAN, this);
    if (name == "Magician")
        Pawn = new class Pawn(his, RoleType::MAGICIAN, this);

    //*******计时器の信号与槽********
    connect(secTimer, &QTimer::timeout, this, &GameState::secUpdate);
    connect(enemyMoveTimer, &QTimer::timeout, this, &GameState::GameUpdate);
    connect(enemyAttackTimer, &QTimer::timeout, this, &GameState::EnemyAttack);
    connect(pawnAttackTimer, &QTimer::timeout, this, &GameState::PawnAttack);
    connect(pawnMoveTimer, &QTimer::timeout, this, &GameState::pawnMoving);
    connect(enemyUpdateTimer, &QTimer::timeout, this, &GameState::EnemyUpdate);
    connect(roundTimer, &QTimer::timeout, this, &GameState::GameWin);

    secTimer->start(1000);
    enemyMoveTimer->start(100);
    enemyAttackTimer->start(1000);
    enemyUpdateTimer->start(1500);
    pawnAttackTimer->start(800);
    pawnMoveTimer->start(100);
    roundTimer->start(60000);

    //*******游戏状态の信号与槽*******
    connect(Pawn, &Pawn::pawnDead, this, &GameState::GameLose);

    //*******角色升级******
    connect(Pawn, &Pawn::levelup, this, &GameState::PawnLevelUp);
    connect(Pawn, &Pawn::atpChange, this, &GameState::PawnAtpUp);
}

GameState::~GameState()
{
    for (Enemy* enemy : EnemyList){
        delete enemy;
        enemy = nullptr;
    }
    history = nullptr;
    enemyMoveTimer->stop();
    enemyAttackTimer->stop();
    enemyUpdateTimer->stop();
    pawnAttackTimer->stop();
    roundTimer->stop();
    delete enemyMoveTimer;
    delete enemyAttackTimer;
    delete pawnAttackTimer;
}

int GameState::getRounds() const
{
    return (30000 - roundTimer->remainingTime())/1000;
}

int GameState::getCoins() const
{
    return coins;
}

Status GameState::getStatus() const
{
    return status;
}

QPointF GameState::generateEdgePoint()
{
    enum Edge : int {
        TOP,
        DOWN,
        LEFT,
        RIGHT
    };

    Edge edge = static_cast<Edge>(QRandomGenerator::global()->bounded(0,4));
    int x=0, y=0;

    switch (edge) {
    case TOP:
        y = Map.getTop() + 1;
        x = QRandomGenerator::global()->bounded(Map.getLeft()+1, Map.getRight()-51);
        break;
    case DOWN:
        y = Map.getBottom() - 51;
        x = QRandomGenerator::global()->bounded(Map.getLeft()+1, Map.getRight()-51);
        break;
    case LEFT:
        x = Map.getLeft() + 1;
        y = QRandomGenerator::global()->bounded(Map.getTop()+1, Map.getBottom()-51);
        break;
    case RIGHT:
        x = Map.getRight()-51;
        y = QRandomGenerator::global()->bounded(Map.getTop()+1, Map.getBottom()-51);
        break;
    default:
        break;
    }
    return QPoint(x, y);
}

int GameState::getDistance(Enemy *enemy) const
{
    return std::abs(enemy->getPos().x() - PawnPos.x()) + std::abs(enemy->getPos().y() - PawnPos.y());
}

QPointF GameState::getPawnPos() const
{
    return PawnPos;
}

QPixmap GameState::getPawnPixmap() const
{
    return Pawn->getPic();
}

QRectF GameState::getPawnRect() const
{
    return QRectF(PawnPos, QSizeF(40,70));
}

double GameState::getPawnHpPercent() const
{
    return Pawn->hpPercent();
}

GameMap GameState::getMap() const
{
    return Map;
}

QList<Enemy*> GameState::getEnemyList() const
{
    return EnemyList;
}

QPointF GameState::EnemyDirection(Enemy* enemy) {
    QPointF dir;
    if (enemy->getName() == "demon" && enemy->ismoving()){
        dir = enemy->getCurdir();
        double sum = pow(dir.x(), 2) + pow(dir.y(), 2);
        dir.rx() /= sqrt(sum);
        dir.ry() /= sqrt(sum);
        QPointF newPos = enemy->getPos() + dir*enemy->getSpd();
        bool collides = false;
        QRectF newrect = QRectF(newPos, QSize(50,50));
        if (newrect.top() < Map.getTop() || newrect.left() < Map.getLeft() ||
            newrect.bottom() > Map.getBottom() || newrect.right() > Map.getRight())
            collides = true;
        if (!collides)
            for (QPoint block : Map.get_blocks()){
                if (newrect.intersects(QRect(block, QSize(50,50)))){
                    collides = true;
                    break;
                }
            }
        if (!collides)
            return dir;
        else{
            dir = PawnPos - enemy->getPos();
            double sum = pow(dir.x(), 2) + pow(dir.y(), 2);
            dir.rx() /= sqrt(sum);
            dir.ry() /= sqrt(sum);

            QList<QPointF> dirs = {dir, QPointF(-dir.y(), dir.x()),
                                   QPointF(dir.y(), -dir.x()), -dir};
            for (QPointF direction : dirs){
                QPointF newPos = enemy->getPos() + direction*enemy->getSpd();
                bool collides = false;
                QRectF newrect = QRectF(newPos, QSize(50,50));
                if (newrect.top() < Map.getTop() || newrect.left() < Map.getLeft() ||
                    newrect.bottom() > Map.getBottom() || newrect.right() > Map.getRight())
                    collides = true;
                if (!collides)
                    for (QPoint block : Map.get_blocks()){
                        if (newrect.intersects(QRect(block, QSize(50,50)))){
                            collides = true;
                            break;
                        }
                    }
                if (!collides){
                    if (enemy->getName() == "demon"){
                        enemy->setCurdir(direction);
                    }
                    return direction;
                }
            }
        }
    }
    else{
        dir = PawnPos - enemy->getPos();
        double sum = pow(dir.x(), 2) + pow(dir.y(), 2);
        dir.rx() /= sqrt(sum);
        dir.ry() /= sqrt(sum);

        QList<QPointF> dirs = {dir, QPointF(-dir.y(), dir.x()),
                               QPointF(dir.y(), -dir.x()), -dir};
        for (QPointF direction : dirs){
            QPointF newPos = enemy->getPos() + direction*enemy->getSpd();
            bool collides = false;
            QRectF newrect = QRectF(newPos, QSize(50,50));
            if (newrect.top() < Map.getTop() || newrect.left() < Map.getLeft() ||
                newrect.bottom() > Map.getBottom() || newrect.right() > Map.getRight())
                collides = true;
            if (!collides)
                for (QPoint block : Map.get_blocks()){
                    if (newrect.intersects(QRect(block, QSize(50,50)))){
                        collides = true;
                        break;
                    }
                }
            if (!collides){
                if (enemy->getName() == "demon"){
                    enemy->setmoving(true);
                    enemy->setCurdir(direction);
                }
                return direction;
            }
        }
    }
    return QPointF(0,0);
}


void GameState::PawnMove(QPointF direction)
{
    QRectF newPlayerRect = QRectF(PawnPos, QSizeF(50, 50)).translated(direction * Pawn->getSpd());
    bool collides = false;
    if (newPlayerRect.left() < 90 ||
        newPlayerRect.right() > 90+Map.getSize().width() ||
        newPlayerRect.top() < 250 ||
        newPlayerRect.bottom() > 250+Map.getSize().height()
        )
        collides = true;
    for (const QPoint& b : Map.get_blocks()){
        if (newPlayerRect.intersects(QRect(b, QSize(50,50)))){
            collides = true;
            break;
        }
    }
    if (!collides)
    {
        PawnPos += direction * Pawn->getSpd();
        Pawn->setPos(PawnPos);
    }
    for (int i = 0; i < FallingList.size(); i++){
        FallingObject* item = FallingList[i];
        QPointF distP = item->getPos() - PawnPos;
        int dist = std::abs(distP.x()) + std::abs(distP.y());
        if (dist <= Pawn->getPickingRg()) {
            pickItem(item->getType());
            FallingList.removeAt(i);
            delete item;
        }
    }
}

void GameState::EnemyCreate(EnemyType enemy_type, QPointF pos)
{
    Enemy* new_enemy = new Enemy(id++);
    switch (enemy_type){
    case EnemyType::HAMADRYAD:
        delete new_enemy;
        new_enemy = new Hamadryad(id, pos);
        break;
    case EnemyType::DEMON:
        delete new_enemy;
        new_enemy = new Demon(id, pos);
        break;
    case EnemyType::MUTATEDDEMON:
        delete new_enemy;
        new_enemy = new MutatedDemon(id, pos);
        break;
    case EnemyType::WIZARD:
        delete new_enemy;
        new_enemy = new Wizard(id, pos);
        break;
    default:
        break;
    }
    EnemyList.append(new_enemy);
    connect(new_enemy, &Enemy::enemyDead, this, &GameState::EnemyDead);
}

void GameState::EnemyMove(Enemy *enemy)
{
    QPointF direction = EnemyDirection(enemy);
    enemy->move(direction);
}

void GameState::EnemyDead(Enemy *enemy)
{
    QString name = enemy->getName();
    QPointF pos = enemy->getPos();
    for (int i = 0; i < EnemyList.size(); i++){
        if (EnemyList.at(i)->getId() == enemy->getId()){
            delete EnemyList.at(i);
            EnemyList.removeAt(i);
            break;
        }
    }
    Pawn->gainExp(5);
    if (name == "hamadryad"){
        coins += 1;
    }
    else if (name == "wizard"){
        coins += 2;
    }
    else if (name == "demon"){
        coins += 5;
        if (QRandomGenerator::global()->bounded(100) < 50)
            Falling(pos);
    }
    else if (name == "mutateddemon"){
        coins += 10;
        if (QRandomGenerator::global()->bounded(100) < 70)
            Falling(pos);
    }
    emit coinsUpdate();
}

void GameState::gainBuff(int buff)
{
    Pawn->gainBuff(buff);
}

void GameState::setStatus(Status statu)
{
    switch (statu){
    case Status::GAMEON:
        if (status == Status::GAMETMP){
            status = statu;
            roundTimer->start(remainedtime);
            secTimer->start(1000);
            enemyAttackTimer->start(1000);
            enemyMoveTimer->start(100);
            enemyUpdateTimer->start(1500);
            pawnAttackTimer->start(800);
            pawnMoveTimer->start(100);
        }
        break;
    case Status::GAMEOFF:
        if (status == Status::GAMEON){
            status = statu;
            remainedtime = 30000;
            roundTimer->setInterval(30000);
            secTimer->stop();
            enemyAttackTimer->stop();
            enemyMoveTimer->stop();
            enemyUpdateTimer->stop();
            pawnAttackTimer->stop();
            pawnMoveTimer->stop();
            roundTimer->stop();
        }
        break;
    case Status::GAMETMP:
        if (status == Status::GAMEON){
            status = statu;
            remainedtime = roundTimer->remainingTime();
            secTimer->stop();
            enemyAttackTimer->stop();
            enemyMoveTimer->stop();
            enemyUpdateTimer->stop();
            pawnAttackTimer->stop();
            pawnMoveTimer->stop();
            roundTimer->stop();
        }
        break;
    default:
        break;
    }
}

void GameState::Falling(QPointF pos)
{
    FallingObject* item = new FallingObject(QRandomGenerator::global()->bounded(9)/3+1, pos);
    FallingList.append(item);
}

void GameState::pickItem(int type)
{
    switch (type){
    case 1:
        coins += 100;
        break;
    case 2:
        Pawn->recoverHp(Pawn->getMaxHp()*0.25);
        break;
    case 3:
        Pawn->gainExp(50);
        break;
    default:
        break;
    }
}

void GameState::secUpdate()
{
    int time = roundTimer->remainingTime() / 1000;
    emit sec(time);
}

void GameState::GameUpdate()
{
    for (Enemy* enemy : EnemyList){
        EnemyMove(enemy);
    }
    emit gameUpdate();
}

void GameState::EnemyAttack()
{
    if (Pawn->isBleeding()) {
        Pawn->beHurt(10);
    }
    for (Enemy* enemy : EnemyList){
        if (Pawn->isDead()) break;
        if (getDistance(enemy) <= enemy->getAtkRange()){
            Pawn->beHurt(enemy->getATK());
        }
    }
}

void GameState::EnemyUpdate()
{
    int random_type = QRandomGenerator::global()->bounded(0, 100);
    int tmp = 0;
    EnemyType enemy_type;
    if (random_type <= static_cast<int>(EnemyType::HAMADRYAD))
        enemy_type = EnemyType::HAMADRYAD;
    else if (random_type <= static_cast<int>(EnemyType::DEMON))
        enemy_type = EnemyType::DEMON;
    else if (random_type <= static_cast<int>(EnemyType::WIZARD))
        enemy_type = EnemyType::WIZARD;
    else if (random_type <= static_cast<int>(EnemyType::MUTATEDDEMON))
        enemy_type = EnemyType::MUTATEDDEMON;
    EnemyCreate(enemy_type, generateEdgePoint());
}

void GameState::PawnAttack()
{
    for (Enemy* enemy : EnemyList){
        if (getDistance(enemy) <= Pawn->getAtkRange())
            Pawn->attack(enemy);
    }
}

void GameState::PawnLevelUp()
{
    setStatus(Status::GAMETMP);
    emit levelup();
}

void GameState::PawnAtpUp()
{
    pawnAttackTimer->stop();
    pawnAttackTimer->start(Pawn->getAtkSpeed());
}

void GameState::GameWin()
{
    setStatus(Status::GAMEOFF);
    emit gameWin();
}

void GameState::GameLose()
{
    setStatus(Status::GAMEOFF);
    emit gameLose();
}

void GameState::GameStateChange(Status nxt_status)
{
    setStatus(nxt_status);
}

FallingObject::FallingObject(int t, QPointF pos)
    : type(t)
    , pos(pos)
{
    switch(type){
    case 1:
        pic.load(":/falling/pics/fallinggold.png");
        break;
    case 2:
        pic.load(":/falling/pics/fallingfood.png");
        break;
    case 3:
        pic.load(":/falling/pics/fallingexp.png");
        break;
    default:
        break;
    }
}

Pawn::Pawn(History* his, RoleType type, QObject* parent)
    : bleeding(false)
    , crit(false)
    , dead(false)
    , history(his)
    , revive(0)
    , revive_recover(0.3)
    , level(0)
    , exp(0)
    , coinX(1)
    , QObject{parent}
{
    switch (type){
    case RoleType::SWORDSMAN:
        max_hp = 400.0;
        atk = 55.0;
        atp = 1000.0;
        spd = 10.0;
        picking_range = 100;
        attack_range = 150;
        pic.load(":/pawn/pics/swordsman.png");
        break;
    case RoleType::MAGICIAN:
        max_hp = 150.0;
        atk = 25.0;
        atp = 800.0;
        spd = 20.0;
        picking_range = 100;
        attack_range = 500;
        pic.load(":/pawn/pics/magician.png");
        break;
    default:
        break;
    }
    max_hp *= 1+history->getbuff(static_cast<BUFFS>(0))*0.1;
    hp = max_hp;
    atk *= 1+history->getbuff(static_cast<BUFFS>(1))*0.06;
    atp *= 1-history->getbuff(static_cast<BUFFS>(2))*0.05;
    spd *= 1+history->getbuff(static_cast<BUFFS>(3))*0.05;
    coinX *= 1+history->getbuff(static_cast<BUFFS>(4))*0.2;
    revive = history->getbuff(static_cast<BUFFS>(5))/3;
    revive_recover *= 1+history->getbuff(static_cast<BUFFS>(5))/3;
}

void Pawn::beHurt(double dmg)
{
    if (hp-dmg <= 0){
        if (revive > 0){
            revive--;
            hp = max_hp * revive_recover;
        }
        else{
            hp = 0;
            emit pawnDead();
        }
    }
    else
        hp -= dmg;
}

void Pawn::attack(Enemy *enemy)
{
    int hurt = atk;
    if (crit){
        if (QRandomGenerator::global()->bounded(100) < 15)
            hurt *= 2;
    }
    enemy->getHurt(hurt);
}

void Pawn::gainBuff(int buff)
{
    switch (buff){
    case 0:
        atk *= 1.15;
        break;
    case 1:
        atp *= 0.85;
        emit atpChange();
        break;
    case 2:
        revive++;
        break;
    case 3:
        crit = true;
        break;
    case 4:
        spd *= 1.15;
        break;
    case 5:
        coinX += 0.15;
        break;
    default:
        break;
    }
}

void Pawn::pickItem(int type)
{
    switch(type){
    case 1:

        break;
    case 2:
        break;
    case 3:
        break;
    default:
        break;
    }
}

























