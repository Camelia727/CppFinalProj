#include "gamewinbox.h"
#include "ui_gamewinbox.h"
#include <qpainter.h>

GameWinBox::GameWinBox(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GameWinBox)
{
    ui->setupUi(this);
    setFixedSize(400,300);
    background.load(":/winorlose/pics/gameWinPic.png");

    connect(ui->home, &QPushButton::clicked, this, &GameWinBox::Home);
}

GameWinBox::~GameWinBox()
{
    delete ui;
}


void GameWinBox::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(QRect(85,50,230,170), background);
}

void GameWinBox::Home()
{
    emit home_clicked();
}
