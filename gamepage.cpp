#include "gamepage.h"
#include "gamewinbox.h"
#include "ui_gamepage.h"

#define GRIDSIZE 50
#define MAPLEFT 90
#define MAPTOP 110





PawnWidget::PawnWidget(QWidget *parent, QString name)
    : QWidget{parent}
    , name(name)
    , pos(QPoint(0,0))
{
    if (name == "Swordsman") {
        setFixedSize(QSize(40, 77));
        size = QSize(40,77);
        pic.load(":/pics/pics/swordsman.png");
    }
    else if (name == "Magician") {
        setFixedSize(QSize(40, 61));
        size = QSize(40,61);
        pic.load(":/pics/pics/magician.png");
    }
    rect.setRect(MAPLEFT+(GRIDSIZE-size.width())/2+pos.x(), MAPTOP+GRIDSIZE-10+pos.y()-size.height(), size.width(), size.height());
}

void PawnWidget::setPos(const QPoint point)
{
    pos = point;
    rect.setRect(MAPLEFT+(GRIDSIZE-size.width())/2+pos.x(), MAPTOP+GRIDSIZE-10+pos.y()-size.height(), size.width(), size.height());
}

QRect PawnWidget::getRect() const
{
    return rect;
}

QPixmap PawnWidget::getPixmap() const
{
    return pic;
}

MoveIcon::MoveIcon(QWidget *parent)
{
    setFixedSize(64, 64);
    rect.setRect(8,8,48,48);
    pic.load(":/pics/pics/moveicon_1.png");
}

void MoveIcon::enterEvent(QEnterEvent *event)
{
    pic.load(":/pics/pics/moveicon.png");
    rect.setRect(4,4,56,56);
    update();
}

void MoveIcon::leaveEvent(QEvent *event)
{
    pic.load(":/pics/pics/moveicon_1.png");
    rect.setRect(8,8,48,48);
    update();
}

void MoveIcon::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(rect, pic);
}

void MoveIcon::mousePressEvent(QMouseEvent *event)
{
    pic.load(":/pics/pics/moveicon.png");
    rect.setRect(12,12,52,52);
    emit iconPressed(event->globalPosition().toPoint());
}

void MoveIcon::mouseReleaseEvent(QMouseEvent *event)
{
    pic.load(":/pics/pics/moveicon.png");
    rect.setRect(4,4,56,56);
    emit iconReleased();
}

void MoveIcon::mouseMoveEvent(QMouseEvent *event)
{
    emit iconMoved(event->globalPosition().toPoint());
}



GamePage::GamePage(History* his, DiffiLevel diffi, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GamePage)
    , gamestate(new GameState(history, diffi))
    , pawn_widget(new PawnWidget(this, "Swordsman"))
    , move_icon(new MoveIcon(this))
    , pawnMoveTimer(new QTimer(this))
    , buffpage(nullptr)
    , pausepage(nullptr)
    , history(his)
    , keyPressed(QList<bool>(256, false))
{
    // setWindowFlag(Qt::FramelessWindowHint); // 边框隐藏
    // setWindowFlags (windowFlags () | Qt::WindowStaysOnTopHint); // 将该页面置顶
    setFixedSize(1120,760);

    ui->setupUi(this);
    map = gamestate->getMap();
    background.load(":/pics/pics/background.png");
    enemybloodbar.load(":/pics/pics/bloodbar.png");
    pawnbloodbar_inner.load(":/pics/pics/pawnbloodbar_inner.png");
    pawnbloodbar_outer.load(":/pics/pics/pawnbloodbar_outer.png");
    grid.load(":/pics/pics/gird.png");
    block.load(":/pics/pics/block.png");
    QVBoxLayout* layout = new QVBoxLayout(this);
    // layout->addWidget(move_icon);
    setLayout(layout);

    // connect(move_icon, &MoveIcon::iconMoved, this, &GamePage::iconMoveEvent);
    // connect(move_icon, &MoveIcon::iconPressed, this, &GamePage::iconPressEvent);
    // connect(move_icon, &MoveIcon::iconReleased, this, &GamePage::iconReleasedEvent);
    connect(gamestate, &GameState::gameUpdate, this, &GamePage::gameUpdateAsked);
    connect(gamestate, &GameState::gameWin, this, &GamePage::gameWin);
    connect(gamestate, &GameState::gameLose, this, &GamePage::gameEnd);
    connect(gamestate, &GameState::pawnmoving, this, &GamePage::pawnMove);

    connect(gamestate, &GameState::levelup, this, &GamePage::buffPageOpen);

    pawnMoveTimer->start(1);

    qDebug() << "gamepage init";

}

GamePage::~GamePage()
{
    delete ui;
    delete gamestate;
    qDebug() << "gamepage delete";
}

void GamePage::paintEvent(QPaintEvent *event)
{
    QPainter Backpainter(this);
    Backpainter.drawPixmap(this->rect(), background);
    QPainter Mappainter(this);
    QPainter Enemypainter(this);
    for (FallingObject* item : gamestate->getFallingList()){
        Mappainter.drawPixmap(QRect(item->getPos().x(), item->getPos().y(), 50, 50), item->getPic());
    }
    for (Enemy* enemy : gamestate->getEnemyList()){
        Enemypainter.drawPixmap(QRect(enemy->getPos().x(), enemy->getPos().y(),GRIDSIZE,GRIDSIZE), enemy->getPixmap());
        Enemypainter.drawPixmap(QRect(enemy->getPos().x(), enemy->getPos().y()-15,GRIDSIZE*enemy->hpPercent(),10), enemybloodbar);
    }
    QPainter Pawnpainter(this);
    Pawnpainter.drawPixmap(gamestate->getPawnPos().x(), gamestate->getPawnPos().y(), 40, 70, gamestate->getPawnPixmap());
    Pawnpainter.drawPixmap(QRect(20,20,300*gamestate->getPawnHpPercent(), 40), pawnbloodbar_inner);
    Pawnpainter.drawPixmap(QRect(20,20,300,40), pawnbloodbar_outer);
}

void GamePage::keyPressEvent(QKeyEvent *event)
{
    if (gamestate->getStatus() != Status::GAMEON){
        keyPressed.fill(false);
        event->ignore();
    }
    else if (event->key() == Qt::Key_Escape){
        gamestate->setStatus(Status::GAMETMP);
        pausepage = new GamePausePage(this);
        pausepage->setGeometry(360,200,400,300);
        pausepage->setWindowFlag(Qt::FramelessWindowHint);
        connect(pausepage, &GamePausePage::goon, this, &GamePage::pausegoon);
        pausepage->show();
    }
    else{
        keyPressed[event->key()] = true;
        // qDebug() << "key " << event->key() << " pressed";
    }

}

void GamePage::keyReleaseEvent(QKeyEvent *event)
{
    if (gamestate->getStatus() != Status::GAMEON){
        keyPressed.fill(false);
        event->ignore();
    }
    else{
        keyPressed[event->key()] = false;
        // qDebug() << "key " << event->key() << " pressed";
    }
}

void GamePage::closeEvent(QCloseEvent *event)
{
    int rounds = gamestate->getRounds();
    int coins = gamestate->getCoins();
    history->gainCoins(coins);
    emit gameend(rounds);
    qDebug() << "gamepage closeevent";
    event->accept();
}

void GamePage::iconPressEvent(QPoint p)
{
    diff_ = p - this->pos();
}

void GamePage::iconReleasedEvent()
{
    diff_ = QPoint();
}

void GamePage::iconMoveEvent(QPoint p)
{
    this->move(p - diff_);
}

void GamePage::pawnMove()
{
    QPointF direction = {0,0};
    if (keyPressed[Qt::Key_W])
        direction.ry()--;
    if (keyPressed[Qt::Key_S])
        direction.ry()++;
    if (keyPressed[Qt::Key_A])
        direction.rx()--;
    if (keyPressed[Qt::Key_D])
        direction.rx()++;
    if (direction.x() != 0 && direction.y() != 0){
        direction.rx() /= std::sqrt(2);
        direction.ry() /= std::sqrt(2);
    }
    // qDebug() << "direction : " << direction.x() << "," << direction.y();
    gamestate->PawnMove(direction);
    update();
}

void GamePage::gameUpdateAsked()
{
    update();
}

void GamePage::gameWin()
{
    qDebug() << "game end";
    update();
    GameWinBox* losebox = new GameWinBox(this);
    losebox->setGeometry(360,200,400,300);
    connect(losebox, &GameWinBox::home_clicked, this, &GamePage::endHome);
    losebox->show();
}

void GamePage::gameEnd()
{
    qDebug() << "game end";
    update();
    GameLoseBox* losebox = new GameLoseBox(this);
    losebox->setGeometry(360,200,400,300);
    connect(losebox, &GameLoseBox::home_clicked, this, &GamePage::endHome);
    losebox->show();
}

void GamePage::endHome()
{
    close();
}

void GamePage::buffPageOpen()
{
    if(buffpage){
        delete buffpage;
        buffpage = nullptr;
    }
    buffpage = new BuffPage(this);
    buffpage->setGeometry(64, 77, 991, 616);
    connect(buffpage, &BuffPage::buffselection, this, &GamePage::buffsel);
    buffpage->show();
}

void GamePage::buffsel(int buff)
{
    gamestate->setStatus(Status::GAMEON);
    gamestate->gainBuff(buff);
}

