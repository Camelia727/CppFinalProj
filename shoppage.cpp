#include "shoppage.h"
#include "ui_shoppage.h"

ShopPage::ShopPage(History* his, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ShopPage)
    , history(his)
{
    ui->setupUi(this);
    setFixedSize(1200, 700);
    pic.load(":/pics/pics/shop.png");
    ui->curcoinsedit->setReadOnly(true);
    ui->curcoinsedit->setPlainText("当前金币："+QString::number(history->getCoins()));
    ui->curcoinsedit->setStyleSheet(
                                    "background-color: rgba(255, 255, 255, 0);font-size: 32px;font-weight: bold;font-style: italic;color:rgba(234,240,68,255);border:none;");
    labels = {ui->label, ui->label_1, ui->label_2,ui->label_3,ui->label_4,ui->label_5};
    for (int i = 0; i < 6; i++){
        labels[i]->setStyleSheet("color:rgba(234,240,68,255);font-size:14px;");
        labels[i]->setText("售价：50（" + QString::number(history->getbuff(static_cast<BUFFS>(i))) + "/5");
    }
    connect(ui->hpbtn, &BuffBtn::buybuff, this, &ShopPage::buy);
    connect(ui->atkbtn, &BuffBtn::buybuff, this, &ShopPage::buy);
    connect(ui->atpbtn, &BuffBtn::buybuff, this, &ShopPage::buy);
    connect(ui->spdbtn, &BuffBtn::buybuff, this, &ShopPage::buy);
    connect(ui->coinbtn, &BuffBtn::buybuff, this, &ShopPage::buy);
    connect(ui->revivebtn, &BuffBtn::buybuff, this, &ShopPage::buy);
}

ShopPage::~ShopPage()
{
    delete ui;
}

void ShopPage::closeEvent(QCloseEvent *event)
{
    emit shopClosed();
    event->accept();
}

void ShopPage::paintEvent(QPaintEvent *event)
{
    QPainter backPainter(this);
    backPainter.drawPixmap(this->rect(), pic);

}

void ShopPage::buy(int buff, int coin)
{
    if (coin <= history->getCoins() && history->getbuff(static_cast<BUFFS>(buff)) < 5){
        emit buyBuff(buff, coin);
        ui->curcoinsedit->setPlainText("当前金币："+QString::number(history->getCoins()));
        labels[buff]->setText("售价：50（" + QString::number(history->getbuff(static_cast<BUFFS>(buff))) + "/5");
    }
    else if (coin > history->getCoins()){
        QMessageBox::information(this, "提示", "金币不足");
    }
    else if (history->getbuff(static_cast<BUFFS>(buff)) >= 5){
        QMessageBox::information(this, "提示", "已经满级");
    }
}
