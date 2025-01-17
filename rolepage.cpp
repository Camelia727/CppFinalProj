#include "rolepage.h"
#include "ui_rolepage.h"

RolePage::RolePage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RolePage)
{
    ui->setupUi(this);
    setFixedSize(QSize(1000,600));
    setWindowFlag(Qt::FramelessWindowHint);
    setWindowFlags (windowFlags () | Qt::WindowStaysOnTopHint); // 将该页面置顶

    pic.load(":/pics/pics/back16_9.jpg");
    RoleWidget* roleWidget_0 = new RoleWidget(this, "Swordsman");
    RoleWidget* roleWidget_1 = new RoleWidget(this, "Magician");
    roleWidget_0->setGeometry(250,100,165,255);
    roleWidget_1->setGeometry(585,100,165,255);
    connect(roleWidget_0, &RoleWidget::role_clicked, this, &RolePage::openGame);
    connect(roleWidget_1, &RoleWidget::role_clicked, this, &RolePage::openGame);
}

RolePage::~RolePage()
{
    delete ui;
}

void RolePage::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(this->rect(), pic);
}

void RolePage::openGame(QString name)
{
    emit gameOpen(name);
    hide();
}
