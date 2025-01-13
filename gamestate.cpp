#include "gamestate.h"


GameMap::GameMap()
{
    m = 950;
    n = 550;
    blocks = {QPoint(500,500)};
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
    , coins(666)
    , difficulty(diffi)
    , status(Status::GAMEON)
    , history(his)
    , PawnPos(290, 310)
    , EnemyList({})
    , enemyMoveTimer(new QTimer(this))
    , enemyAttackTimer(new QTimer(this))
    , enemyUpdateTimer(new QTimer(this))
    , pawnAttackTimer(new QTimer(this))
    , roundTimer(new QTimer(this))
{
    Pawn = new class Pawn(his, RoleType::SWORDSMAN, this);
    EnemyCreate(EnemyType::HAMADRYAD, QPoint(100, 300));
    // EnemyCreate(EnemyType::DEMON, QPoint(17,0));
    // EnemyCreate(EnemyType::MUTATEDDEMON, QPoint(0,9));
    // EnemyCreate(EnemyType::WIZARD, QPoint(17,9));

    //*******计时器の信号与槽********
    connect(enemyMoveTimer, &QTimer::timeout, this, &GameState::GameUpdate);
    connect(enemyAttackTimer, &QTimer::timeout, this, &GameState::EnemyAttack);
    connect(pawnAttackTimer, &QTimer::timeout, this, &GameState::PawnAttack);
    // connect(enemyUpdateTimer, &QTimer::timeout, this, &GameState::EnemyUpdate);

    enemyMoveTimer->start(100);
    enemyAttackTimer->start(1000);
    enemyUpdateTimer->start(1500);
    pawnAttackTimer->start(800);
    roundTimer->start(30000);

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
    return rounds;
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
        y = 0;
        x = QRandomGenerator::global()->bounded(0, Map.getSize().width()-1);
        break;
    case DOWN:
        y = Map.getSize().height()-1;
        x = QRandomGenerator::global()->bounded(0, Map.getSize().width()-1);
        break;
    case LEFT:
        x = 0;
        y = QRandomGenerator::global()->bounded(0, Map.getSize().height()-1);
        break;
    case RIGHT:
        x = Map.getSize().width()-1;
        y = QRandomGenerator::global()->bounded(0, Map.getSize().height()-1);
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

QPointF GameState::EnemyDirection(Enemy *enemy)
{
    QPointF direction = PawnPos - enemy->getPos();
    // qDebug() << "one direction : " << direction.x() << "," << direction.y();
    double v = direction.x() * direction.x() + direction.y() * direction.y();
    direction.rx() /= std::sqrt(v);
    direction.ry() /= std::sqrt(v);
    // qDebug() << "initial direction : " << direction.x() << "," << direction.y();

    bool collision = false;
    QRectF newEnemyRect(enemy->getPos() + direction * enemy->getSpd(), QSizeF(0.5,0.5));
    if (newEnemyRect.left() < 90 ||
        newEnemyRect.right() > 90+Map.getSize().width() ||
        newEnemyRect.top() < 110 ||
        newEnemyRect.bottom() > 110+Map.getSize().height()
        )
        collision = true;
    for (const QPoint& b : Map.get_blocks()){
        if (newEnemyRect.intersects(QRectF(b, QSizeF(50,50)))){
            collision = true;
        }
    }
    if (!collision)
        return direction;
    else{
        QPointF offset(direction.y(), -direction.x());
        QPointF newPos1 = enemy->getPos() + offset;
        QPointF newPos2 = enemy->getPos() - offset;
        bool isPos1Clear = true;
        bool isPos2Clear = true;
        for (const QPoint& b : Map.get_blocks()) {
            QRectF checkRect1(newPos1, QSizeF(0.5, 0.5));
            QRectF checkRect2(newPos2, QSizeF(0.5, 0.5));
            if (checkRect1.intersects(QRectF(b, QSizeF(50,50)))) isPos1Clear = false;
            if (checkRect2.intersects(QRectF(b, QSizeF(50,50)))) isPos2Clear = false;
        }
        if (isPos1Clear) return offset;
        else if(isPos2Clear) return -offset;
        else return -offset;
    }

}

void GameState::PawnMove(QPointF direction)
{
    QRectF newPlayerRect = QRectF(PawnPos, QSizeF(50, 50)).translated(direction * Pawn->getSpd());
    bool collides = false;
    if (newPlayerRect.left() < 90 ||
        newPlayerRect.right() > 90+Map.getSize().width() ||
        newPlayerRect.top() < 110 ||
        newPlayerRect.bottom() > 110+Map.getSize().height()
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
    for (int i = 0; i < EnemyList.size(); i++){
        if (EnemyList.at(i)->getId() == enemy->getId()){
            delete EnemyList.at(i);
            EnemyList.removeAt(i);
            break;
        }
    }
    Pawn->gainExp(5);
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
    emit levelup();
}

void GameState::GameLose()
{
    GameStateChange(Status::GAMELOSE);
    emit gameLose();
}

void GameState::GameStateChange(Status nxt_status)
{
    status = nxt_status;
    switch (nxt_status){
    case Status::GAMEON:

        break;
    case Status::GAMETMP:

        break;
    case Status::GAMEWIN:

        break;
    case Status::GAMELOSE:
        roundTimer->stop();
        enemyUpdateTimer->stop();
        enemyMoveTimer->stop();
        enemyAttackTimer->stop();
        pawnAttackTimer->stop();
        break;
    case Status::GAMEOFF:
        break;
    default:
        break;
    }
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



void FallingObject::paintEvent(QPaintEvent *event)
{

}

FallingObject::FallingObject(QWidget *parent, int t)
    : QWidget{parent}
    , type(t)
{
    switch(type){
    case NONE:
        break;
    case COINBOX:
        break;
    case MEDICIAN:
        break;
    case EXPBOX:
        break;
    default:
        break;
    }
}

Pawn::Pawn(History* his, RoleType type, QObject* parent)
    : bleeding(false)
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
        atk = 10.0;
        atp = 1.0;
        spd = 1.0;
        picking_range = 2;
        attack_range = 10;
        pic.load(":/pics/pics/swordsman.png");
        break;
    case RoleType::MAGICIAN:
        max_hp = 700.0;
        atk = 15.0;
        atp = 1.0;
        spd = 1.0;
        picking_range = 4;
        attack_range = 5;
        pic.load(":/pics/pics/magician.png");
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

























