#include "gamepausepage.h"
#include "ui_gamepausepage.h"

GamePausePage::GamePausePage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GamePausePage)
{
    ui->setupUi(this);
    setFixedSize(400,300);
    connect(ui->goonBtn, &QPushButton::clicked, this, &GamePausePage::goonclicked);
}

GamePausePage::~GamePausePage()
{
    delete ui;
}
