#include "rolewidget.h"

RoleWidget::RoleWidget(QWidget *parent, QString name)
    : QWidget{parent}
    , name(name)
{
    setFixedSize(QSize(165,255));
    rect.setRect(16,25,133,205);

    if (name == "Swordsman") pic.load(":/pawn/pics/swordsman.png");
    else if (name == "Magician") pic.load(":/pawn/pics/magician.png");
}

void RoleWidget::setName(const QString n)
{
    name = n;
}

void RoleWidget::enterEvent(QEnterEvent *event)
{
    rect.setRect(0,0,165,255);
    update();
}

void RoleWidget::leaveEvent(QEvent *event)
{
    rect.setRect(16,25,133,205);
    update();
}

void RoleWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(rect, pic);
}

void RoleWidget::mousePressEvent(QMouseEvent *event)
{
    rect.setRect(20,30,125,195);
    update();
}

void RoleWidget::mouseReleaseEvent(QMouseEvent *event)
{
    rect.setRect(0,0,165,255);
    emit role_clicked(name);
    update();
}
