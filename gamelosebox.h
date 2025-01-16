#ifndef GAMELOSEBOX_H
#define GAMELOSEBOX_H

#include <QWidget>
#include <QPainter>

namespace Ui {
class GameLoseBox;
}


class GameLoseBox : public QWidget
{
    Q_OBJECT

public:
    explicit GameLoseBox(QWidget *parent = nullptr);
    ~GameLoseBox();

private:
    Ui::GameLoseBox *ui;
    QPixmap background;

protected:
    void paintEvent(QPaintEvent* event) override;

signals:
    void home_clicked();

public slots:
    void Home();
};

#endif // GAMELOSEBOX_H
