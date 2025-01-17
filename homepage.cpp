#include "homepage.h"
#include "./ui_homepage.h"

HomePage::HomePage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HomePage)
    , shopOn(false)
    , history(new History)
{
    ui->setupUi(this);

    setFixedSize(QSize(1000, 600));

    background.load(":/pics/pics/homepage.png");
    role_page = new RolePage(this);
    role_page->hide();
    game_page = nullptr;

    connect(ui->gamebtn, &gameBtn::game_clicked, this, &HomePage::openRole);
    connect(ui->shopbtn, &shopBtn::shop_clicked, this, &HomePage::openShop);
    connect(role_page, &RolePage::gameOpen, this, &HomePage::openGame);

}

HomePage::~HomePage()
{
    delete history;
    history = nullptr;
    delete role_page;
    role_page = nullptr;
    if (game_page)
    {
        delete game_page;
        game_page = nullptr;
    }
    delete ui;
}

void HomePage::closeEvent(QCloseEvent *event)
{

}

void HomePage::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(this->rect(), background);
}

void HomePage::openRole()
{
    if (shopOn) {
        QMessageBox msg;
        msg.setText("请先退出商店再进行冒险哦~");
        msg.exec();
    }
    else{
        role_page->show();
    }
}

void HomePage::openGame(QString name)
{
    qDebug() << "opengame called";
    if (game_page){
        delete game_page;
        game_page = nullptr;
    }
    game_page = new GamePage(history, name);
    connect(game_page, &GamePage::gameend, this, &HomePage::gameEnd);
    connect(game_page, &GamePage::gameexit, this, &HomePage::gameExit);
    game_page->show();
    hide();
}

void HomePage::openDetail()
{

}

void HomePage::openSave()
{

}

void HomePage::openShop()
{
    if (shopOn){
        QMessageBox msg;
        msg.setText("这里只有一家商店啦！");
        msg.exec();
    }
    else
    {
        ShopPage* shop_page = new ShopPage(history);
        if (shop_page != nullptr) {
            shopOn = true;
            connect(shop_page, &ShopPage::buyBuff, this, &HomePage::buyBuff);
            connect(shop_page, &ShopPage::shopClosed, this, &HomePage::closeShop);
            shop_page->show();
        }
    }
}

void HomePage::closeShop()
{
    shopOn = false;
}

void HomePage::buyBuff(int buff, int coin)
{
    history->spendCoins(coin);
    history->gainBuff(static_cast<BUFFS>(buff));
}

void HomePage::gameEnd(int rounds)
{
    show();
    history->HistoryUpdate(rounds);
    disconnect(game_page, &GamePage::gameend, this, &HomePage::gameEnd);
    disconnect(game_page, &GamePage::gameexit, this, &HomePage::gameExit);
    delete game_page;
    game_page = nullptr;
}

void HomePage::gameExit(int rounds)
{
    history->HistoryUpdate(rounds);
    // qDebug() << history->getGamecount();
    disconnect(game_page, &GamePage::gameend, this, &HomePage::gameEnd);
    disconnect(game_page, &GamePage::gameexit, this, &HomePage::gameExit);
    delete game_page;
    game_page = nullptr;
    close();
}
