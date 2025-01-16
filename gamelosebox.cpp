#include "gamelosebox.h"
#include "ui_gamelosebox.h"

GameLoseBox::GameLoseBox(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GameLoseBox)
{
    ui->setupUi(this);
    setFixedSize(400,300);
    background.load(":/winorlose/pics/gameLosePic.png");

    connect(ui->home, &QPushButton::clicked, this, &GameLoseBox::Home);
}

GameLoseBox::~GameLoseBox()
{
    delete ui;
}



void GameLoseBox::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(QRect(85,50,230,170), background);
}

void GameLoseBox::Home()
{
    emit home_clicked();
}
