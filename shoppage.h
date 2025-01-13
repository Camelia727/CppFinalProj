#ifndef SHOPPAGE_H
#define SHOPPAGE_H

#include <QWidget>
#include <QCloseEvent>
#include <QPainter>
#include <QMessageBox>
#include "history.h"

namespace Ui {
class ShopPage;
}

class ShopPage : public QWidget
{
    Q_OBJECT

public:
    explicit ShopPage(History* his, QWidget *parent = nullptr);
    ~ShopPage();

protected:
    void closeEvent(QCloseEvent* event) override;
    void paintEvent(QPaintEvent* event) override;

private:
    Ui::ShopPage *ui;
    History* history;
    QPixmap pic;
    QList<QLabel*> labels;
signals:
    void shopClosed();
    void buyBuff(int buff, int coin);
public slots:
    void buy(int buff, int coin);
};

#endif // SHOPPAGE_H
