#include "mybutton.h"

myButton::myButton(QSize size, QWidget *parent)
    : size(size)
    , QWidget{parent}
{
    setFixedSize(size);
    rect.setRect(0.1*size.width(), 0.1*size.height(), 0.8*size.width(), 0.8*size.height());
}

void myButton::enterEvent(QEnterEvent *event)
{
    rect.setRect(0,0,size.width(), size.height());
    update();
}

void myButton::leaveEvent(QEvent *event)
{
    rect.setRect(0.1*size.width(), 0.1*size.height(), 0.8*size.width(), 0.8*size.height());
    update();
}

void myButton::mousePressEvent(QMouseEvent *event)
{
    rect.setRect(0.12*size.width(), 0.12*size.height(), 0.76*size.width(), 0.76*size.height());
    update();
}

void myButton::mouseReleaseEvent(QMouseEvent *event)
{
    rect.setRect(0,0,size.width(), size.height());
    update();
}

void myButton::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(rect, pic);
}



gameBtn::gameBtn(QWidget *parent)
    : myButton{QSize(180, 114), parent}
{
    pic.load(":/pics/pics/gameBtn.png");
}

void gameBtn::mouseReleaseEvent(QMouseEvent *event)
{
    rect.setRect(0,0,180,114);
    emit game_clicked();
    update();
}

shopBtn::shopBtn(QWidget *parent)
    : myButton{QSize(180, 114), parent}
{
    pic.load(":/pics/pics/shopBtn.png");
}

void shopBtn::mouseReleaseEvent(QMouseEvent *event)
{
    rect.setRect(0,0,180,114);
    emit shop_clicked();
    update();
}

exitBtn::exitBtn(QWidget *parent)
    : myButton{QSize(180, 114), parent}
{
    pic.load(":/pics/pics/exitBtn.png");
}

void exitBtn::mouseReleaseEvent(QMouseEvent *event)
{
    rect.setRect(0,0,180,114);
    emit exit_clicked();
    update();
}

saveBtn::saveBtn(QWidget *parent)
    : myButton{QSize(180, 114), parent}
{
    pic.load(":/pics/pics/saveBtn.png");
}

void saveBtn::mouseReleaseEvent(QMouseEvent *event)
{
    rect.setRect(0,0,180,114);
    emit save_clicked();
    update();
}

detailBtn::detailBtn(QWidget *parent)
    : myButton{QSize(180, 114), parent}
{
    pic.load(":/pics/pics/detailBtn.png");
}

void detailBtn::mouseReleaseEvent(QMouseEvent *event)
{
    rect.setRect(0,0,180,114);
    emit detail_clicked();
    update();
}

void BuffBtn::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(QRect(0,0,size.width(), size.height()), pic);
    painter.drawPixmap(rect, buffpic);
}

BuffBtn::BuffBtn(int buff, QWidget *parent)
    : myButton{QSize(120,120), parent}
    , buff(buff)
{
    pic.load(":/pics/pics/itemBack.png");
    switch (buff) {
    case 0:
        buffpic.load(":/buffs/pics/hpbuff.png");
        coin = 50;
        break;
    case 1:
        buffpic.load(":/buffs/pics/atkUpBuff.png");
        coin = 50;
        break;
    case 2:
        buffpic.load(":/buffs/pics/atpbuff.png");
        coin = 50;
        break;
    case 3:
        buffpic.load(":/buffs/pics/spdbuff.png");
        coin = 50;
        break;
    case 4:
        buffpic.load(":/buffs/pics/coinbuff.png");
        coin = 50;
        break;
    case 5:
        buffpic.load(":/buffs/pics/revivebuff.png");
        coin = 50;
        break;
    default:
        break;
    }
}

void BuffBtn::mouseReleaseEvent(QMouseEvent *event)
{
    rect.setRect(0,0,size.width(), size.height());
    emit buybuff(buff, coin);
    update();
}

void BuffBtn::enterEvent(QEnterEvent *event)
{
    rect.setRect(0,0,size.width(), size.height());

    update();
}
