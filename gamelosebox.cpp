#include "gamelosebox.h"
#include "ui_gamelosebox.h"

GameLoseBox::GameLoseBox(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GameLoseBox)
{
    ui->setupUi(this);
    setFixedSize(400,300);

    connect(ui->home, &QPushButton::clicked, this, &GameLoseBox::Home);
    connect(ui->exit, &QPushButton::clicked, this, &GameLoseBox::Exit);
}

GameLoseBox::~GameLoseBox()
{
    delete ui;
}



void GameLoseBox::paintEvent(QPaintEvent *event)
{

}

void GameLoseBox::Home()
{
    emit home_clicked();
}

void GameLoseBox::Exit()
{
    emit exit_clicked();
}
