#include "rolewidget.h"

RoleWidget::RoleWidget(QWidget *parent, QString name)
    : QWidget{parent}
    , name(name)
{
    setFixedSize(QSize(256, 256));
    rect.setRect(28,28,200,200);

    if (name == "Swordsman") pic.load(":/pawn/pics/swordsman.png");
    else if (name == "Magician") pic.load(":/pawn/pics/magician.png");
}

void RoleWidget::setName(const QString n)
{
    name = n;
}

void RoleWidget::enterEvent(QEnterEvent *event)
{
    rect.setRect(0,0,256,256);
    update();
}

void RoleWidget::leaveEvent(QEvent *event)
{
    rect.setRect(28,28,200,200);
    update();
}

void RoleWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(rect, pic);
}

void RoleWidget::mousePressEvent(QMouseEvent *event)
{
    rect.setRect(48,48,160,160);
    update();
}

void RoleWidget::mouseReleaseEvent(QMouseEvent *event)
{
    rect.setRect(0,0,256,256);
    emit role_clicked();
    update();
}
