#include "gamestate.h"
#include <queue>


GameMap::GameMap()
{
    m = 940;
    n = 420;
    top = 250;
    left = 90;
    blocks = {QPoint(500,500),QPoint(450,650),QPoint(550,550),
                QPoint(550,330),QPoint(620,400),QPoint(650,250)};
}

QSize GameMap::getSize()
{
    return QSize(m, n);
}

QList<QPoint> GameMap::get_blocks()
{
    return blocks;
}

GameState::GameState(History* his, DiffiLevel diffi, QObject* parent)
    : QObject{parent}
    , id(0)
    , rounds(0)
    , coins(0)
    , difficulty(diffi)
    , status(Status::GAMEON)
    , history(his)
    , PawnPos(290, 360)
    , EnemyList({})
    , enemyMoveTimer(new QTimer(this))
    , enemyAttackTimer(new QTimer(this))
    , enemyUpdateTimer(new QTimer(this))
    , pawnAttackTimer(new QTimer(this))
    , pawnMoveTimer(new QTimer(this))
    , roundTimer(new QTimer(this))
{
    Pawn = new class Pawn(his, RoleType::SWORDSMAN, this);

    //*******计时器の信号与槽********
    connect(enemyMoveTimer, &QTimer::timeout, this, &GameState::GameUpdate);
    connect(enemyAttackTimer, &QTimer::timeout, this, &GameState::EnemyAttack);
    connect(pawnAttackTimer, &QTimer::timeout, this, &GameState::PawnAttack);
    connect(pawnMoveTimer, &QTimer::timeout, this, &GameState::pawnMoving);
    connect(enemyUpdateTimer, &QTimer::timeout, this, &GameState::EnemyUpdate);
    connect(roundTimer, &QTimer::timeout, this, &GameState::GameWin);

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

    qDebug() << history->getbuff(static_cast<BUFFS>(0));

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
    qDebug() << "gamestate delete";
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
        y = 250;
        x = QRandomGenerator::global()->bounded(90, 90+Map.getSize().width());
        break;
    case DOWN:
        y = Map.getSize().height()-90;
        x = QRandomGenerator::global()->bounded(90, Map.getSize().width()+90);
        break;
    case LEFT:
        x = 90;
        y = QRandomGenerator::global()->bounded(250, Map.getSize().height()+250);
        break;
    case RIGHT:
        x = Map.getSize().width()-90;
        y = QRandomGenerator::global()->bounded(250, Map.getSize().height()+250);
        break;
    default:
        break;
    }
    // qDebug() << "edge:" << edge << ", generate a point at (" << x << "," << y << ")";
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
    QPointF dir = PawnPos - enemy->getPos();
    double sum = pow(dir.x(), 2) + pow(dir.y(), 2);
    dir.rx() /= sqrt(sum);
    dir.ry() /= sqrt(sum);
    QList<QPointF> dirs = {dir, QPointF(-dir.y(), dir.x()),
                           QPointF(dir.y(), -dir.x()), -dir};
    for (QPointF direction : dirs){
        QPointF newPos = enemy->getPos() + direction*enemy->getSpd();
        bool collides = false;
        QRectF newrect = QRectF(newPos, QSize(50,50));
        for (QPoint block : Map.get_blocks()){
            if (newrect.intersects(QRect(block, QSize(50,50)))){
                collides = true;
                break;
            }
        }
        if (!collides)
            return direction;
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
    // qDebug() << "position " << PawnPos.x() << "," << PawnPos.y();
}

void GameState::EnemyCreate(EnemyType enemy_type, QPointF pos)
{
    Enemy* new_enemy = new Enemy(id++);
    switch (enemy_type){
    case EnemyType::HAMADRYAD:
        delete new_enemy;
        new_enemy = new Hamadryad(id, pos);
        // qDebug() << "new hamadryad";
        break;
    case EnemyType::DEMON:
        delete new_enemy;
        new_enemy = new Demon(id, pos);
        // qDebug() << "new demon";
        break;
    case EnemyType::MUTATEDDEMON:
        delete new_enemy;
        new_enemy = new MutatedDemon(id, pos);
        // qDebug() << "new mutateddemon";
        break;
    case EnemyType::WIZARD:
        delete new_enemy;
        new_enemy = new Wizard(id, pos);
        // qDebug() << "new wizard";
        break;
    default:
        break;
    }
    // qDebug() << "current id : " << id;
    EnemyList.append(new_enemy);
    connect(new_enemy, &Enemy::enemyDead, this, &GameState::EnemyDead);
}

void GameState::EnemyMove(Enemy *enemy)
{
    QPointF direction = EnemyDirection(enemy);
    // qDebug() << "direction : " << direction.x() << "," << direction.y();
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
    if (name == "demon"){
        if (QRandomGenerator::global()->bounded(100) < 50)
            Falling(pos);
    }
    else if (name == "mutateddemon"){
        if (QRandomGenerator::global()->bounded(100) < 70)
            Falling(pos);
    }
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
            enemyAttackTimer->start(1000);
            enemyMoveTimer->start(100);
            enemyUpdateTimer->start(1500);
            pawnAttackTimer->start(800);
            pawnMoveTimer->start(100);
        }
        break;
    case Status::GAMEOFF:
        if (status == Status::GAMEON){
            qDebug() << "status change";
            status = statu;
            remainedtime = 30000;
            roundTimer->setInterval(30000);
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
            qDebug() << "status change";
            status = statu;
            remainedtime = roundTimer->remainingTime();
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
    qDebug() << "Falling something:" << item->getType();
}

void GameState::pickItem(int type)
{
    qDebug() << "picking";
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
        qDebug() << "bleeding";
        Pawn->beHurt(10);
    }
    for (Enemy* enemy : EnemyList){
        if (Pawn->isDead()) break;
        if (getDistance(enemy) <= enemy->getAtkRange()){
            qDebug() << "enemy atk : " << enemy->getATK();
            Pawn->beHurt(enemy->getATK());
        }
    }
}

void GameState::EnemyUpdate()
{
    int random_type = QRandomGenerator::global()->bounded(0, static_cast<int>(difficulty)+1);
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


void GameMap::importMap(QString fileName)
{

}

void GameMap::exportMap()
{

}

Grid::Grid(Style s)
    : style(s)
    , enemyList({})
{
    switch (s) {
    case PATH:
        pic.load(":/pics/pics/gird.png");
        break;
    case BLOCK:
        pic.load(":/pics/pics/block.png");
        break;
    default:
        break;
    }
}

QPixmap Grid::getPic()
{
    return pic;
}

QList<Enemy *> Grid::getEnemyList()
{
    return enemyList;
}

int Grid::getEnemyCnt()
{
    return enemyList.size();
}

bool Grid::isBlock() const
{
    return style == BLOCK;
}

void Grid::addEnemy(Enemy *enemy)
{
    enemyList.append(enemy);
    // qDebug() << "add enemy grid at (" << enemy->getPos().x() << "," << enemy->getPos().y() << ") have " << enemyList.size() << "enemies";
    // qDebug() << "enemy id : " << enemyList[0]->getId();
}

void Grid::removeEnemy(Enemy *enemy)
{
    // qDebug() << "grid at (" << enemy->getPos().x() << "," << enemy->getPos().y() << ") remove enemy with id " << enemy->getId();
    for (int i = 0; i < enemyList.size(); i++){
        if (enemyList.at(i)->getId() == enemy->getId()){
            enemyList.removeAt(i);
            break;
        }
    }
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
    , QObject{parent}
{
    switch (type){
    case RoleType::SWORDSMAN:
        max_hp = 100.0;
        atk = 30.0;
        atp = 1.0;
        spd = 10.0;
        picking_range = 50;
        attack_range = 500;
        pic.load(":/pawn/pics/swordsman.png");
        break;
    case RoleType::MAGICIAN:
        max_hp = 700.0;
        atk = 1500.0;
        atp = 1.0;
        spd = 10.0;
        picking_range = 400;
        attack_range = 5;
        pic.load(":/pawn/pics/magician.png");
        break;
    default:
        break;
    }
    qDebug() << history->getbuff(static_cast<BUFFS>(0));
    max_hp *= 1+history->getbuff(static_cast<BUFFS>(0))*0.1;
    hp = max_hp;
    atk *= 1+history->getbuff(static_cast<BUFFS>(1))*0.06;
    atp *= 1/(1+history->getbuff(static_cast<BUFFS>(2))*0.05);
    spd *= 1+history->getbuff(static_cast<BUFFS>(3))*0.05;
    coin *= 1+history->getbuff(static_cast<BUFFS>(4))*0.2;
    revive = history->getbuff(static_cast<BUFFS>(5))/3;
    revive_recover *= history->getbuff(static_cast<BUFFS>(5))/3;

    qDebug() << max_hp << " " << atk << " " << atp << " " << spd << " " << revive << " " << revive_recover;
}

void Pawn::beHurt(double dmg)
{
    qDebug() << "current pawn hp : " << hp;
    if (hp-dmg <= 0){
        hp = 0;
        emit pawnDead();
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
    qDebug() << "gain buff " << buff;
    switch (buff){
    case 0:
        atk *= 1.15;
        break;
    case 1:
        atp *= 1.15;
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
        coin *= 1.15;
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

























