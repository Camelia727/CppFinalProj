#include "detailpage.h"
#include "ui_detailpage.h"
#include <qpainter.h>

DetailPage::DetailPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DetailPage)
    , cur(0)
{
    ui->setupUi(this);
    pics = QList<QPixmap>(3);
    pics[0].load(":/leading/pics/leading1.png");
    pics[1].load(":/leading/pics/leading2.png");
    pics[2].load(":/leading/pics/leading3.png");
}

DetailPage::~DetailPage()
{
    delete ui;
}

void DetailPage::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(this->rect(), pics[cur]);
}

void DetailPage::mouseReleaseEvent(QMouseEvent *event)
{
    if (++cur == 3){
        cur = 0;
        emit exit();
        hide();
    }
    update();
}
