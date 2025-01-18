#include "buffpage.h"
#include "ui_buffpage.h"
#include <QBoxLayout>

BuffPage::BuffPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BuffPage)
    , buff1(nullptr)
    , buff2(nullptr)
    , buff3(nullptr)
{
    ui->setupUi(this);
    setFixedSize(991, 616);
    setWindowFlags(Qt::FramelessWindowHint);
    // setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);

    pic.load(":/gods/pics/buffpageBack.png");
    b1 = QRandomGenerator::global()->bounded(6);
    b2 = b3 = -1;
    while (b2 == b1 || b2 == -1) {
        b2 = QRandomGenerator::global()->bounded(6);
    }
    while (b3 == b2 || b3 == b1 || b3 == -1) {
        b3 = QRandomGenerator::global()->bounded(6);
    }
    buff1 = new BuffWidget(b1, this);
    buff2 = new BuffWidget(b2, this);
    buff3 = new BuffWidget(b3, this);
    buff1->setGeometry(40,240,324,388);
    buff2->setGeometry(365,240,324,388);
    buff3->setGeometry(690,240,324,388);
    connect(buff1, &BuffWidget::clicked, this, &BuffPage::buffselect);
    connect(buff2, &BuffWidget::clicked, this, &BuffPage::buffselect);
    connect(buff3, &BuffWidget::clicked, this, &BuffPage::buffselect);
}

BuffPage::~BuffPage()
{
    delete ui;
}

void BuffPage::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(this->rect(), pic);
}

void BuffPage::buffselect(int sel)
{
    emit buffselection(sel);
    close();
}

BuffWidget::BuffWidget(int b, QWidget *parent)
    : QWidget{parent}
{
    buff = b;
    size = QSize(270, 324);
    rect.setRect(0.1*size.width(), 0.1*size.height(), 0.8*size.width(), 0.8*size.height());
    switch (buff){
    case 0:
        pic.load(":/gods/pics/cthulu.png");
        break;
    case 1:
        pic.load(":/gods/pics/dagon.png");
        break;
    case 2:
        pic.load(":/gods/pics/shub.png");
        break;
    case 3:
        pic.load(":/gods/pics/horrorhunter.png");
        break;
    case 4:
        pic.load(":/gods/pics/hastura.png");
        break;
    case 5:
        pic.load(":/gods/pics/m_g.png");
        break;
    default:
        break;
    }
}

void BuffWidget::enterEvent(QEnterEvent *event)
{
    rect.setRect(0,0,size.width(), size.height());
    update();
}

void BuffWidget::leaveEvent(QEvent *event)
{
    rect.setRect(0.1*size.width(), 0.1*size.height(), 0.8*size.width(), 0.8*size.height());
    update();
}

void BuffWidget::mousePressEvent(QMouseEvent *event)
{
    rect.setRect(0.12*size.width(), 0.12*size.height(), 0.76*size.width(), 0.76*size.height());
    update();
}

void BuffWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(rect, pic);
}

void BuffWidget::mouseReleaseEvent(QMouseEvent *event)
{
    rect.setRect(0,0,size.width(), size.height());
    emit clicked(buff);
    update();
}
