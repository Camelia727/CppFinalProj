#ifndef GAMEPAGE_H
#define GAMEPAGE_H

#include <QWidget>
#include <QKeyEvent>
#include <QTimer>
#include <QVBoxLayout>
#include "gamestate.h"
#include "gamelosebox.h"
#include "history.h"
#include "buffpage.h"

namespace Ui {
class GamePage;
}

class PawnWidget : public QWidget
{
private:
    QPixmap pic;
    QString name;
    QRect rect;
    QPoint pos;
    QSize size;

public:
    explicit PawnWidget(QWidget *parent = nullptr, QString name = "");
    ~PawnWidget() = default;
    void setName(const QString n);
    void setPos(const QPoint point);
    QRect getRect() const;
    QPixmap getPixmap() const;
};

class MoveIcon : public QWidget
{
    Q_OBJECT

    QRect rect;
    QPixmap pic;
    QPoint diff_; // 处理拖动事件
public:
    explicit MoveIcon(QWidget *parent = nullptr);

protected:
    void enterEvent(QEnterEvent* event) override;
    void leaveEvent(QEvent* event) override;
    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;

signals:
    void iconPressed(QPoint p);
    void iconReleased();
    void iconMoved(QPoint p);
};


class GamePage : public QWidget
{
    Q_OBJECT

public:
    explicit GamePage(History* his, DiffiLevel diffi, QWidget *parent = nullptr);
    ~GamePage();


private:
    QPixmap background;
    QPixmap enemybloodbar;
    QPixmap pawnbloodbar_outer;
    QPixmap pawnbloodbar_inner;
    QPixmap grid;
    QPixmap block;
    Ui::GamePage *ui;
    History* history;
    GameState* gamestate;
    BuffPage* buffpage;
    GameMap map;
    PawnWidget* pawn_widget;
    MoveIcon* move_icon;
    QPoint diff_; // 鼠标拖动事件
    QTimer* pawnMoveTimer;
    QList<bool> keyPressed;

protected:
    void paintEvent(QPaintEvent* event) override;
    void keyPressEvent(QKeyEvent* event) override;
    void keyReleaseEvent(QKeyEvent* event) override;
    void closeEvent(QCloseEvent* event) override;

signals:
    void gameend(int rounds);
    void gameexit(int rounds);
    void closed();

public slots:
    // 拖拽图标
    void iconPressEvent(QPoint p);
    void iconReleasedEvent();
    void iconMoveEvent(QPoint p);

    void pawnMove();                // 人物移动
    void gameUpdateAsked();         // 更新游戏画面
    void gameEnd();                 // 人物死亡，播放战败结算
    void endHome();                 // 结束本场游戏并回到home
    void endExit();                 // 结束本场游戏并直接退出

    void buffPageOpen();            // 游戏角色升级后，选择buff
    void buffsel(int buff);         // 选好buff传给gamestate
};

#endif // GAMEPAGE_H
