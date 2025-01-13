#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QWidget>
#include <QPainter>

class myButton : public QWidget
{
    Q_OBJECT
protected:
    QSize size;
    QRect rect;
    QPixmap pic;
public:
    explicit myButton(QSize size, QWidget *parent = nullptr);

protected:
    void enterEvent(QEnterEvent* event);
    void leaveEvent(QEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void paintEvent(QPaintEvent* event);

signals:
};

class gameBtn : public myButton
{
    Q_OBJECT
public:
    explicit gameBtn(QWidget* parent = nullptr);
    void mouseReleaseEvent(QMouseEvent* event);
signals:
    void game_clicked();
};

class shopBtn : public myButton
{
    Q_OBJECT
public:
    explicit shopBtn(QWidget* parent = nullptr);
    void mouseReleaseEvent(QMouseEvent* event);
signals:
    void shop_clicked();
};

class exitBtn : public myButton
{
    Q_OBJECT
public:
    explicit exitBtn(QWidget* parent = nullptr);
    void mouseReleaseEvent(QMouseEvent* event);
signals:
    void exit_clicked();
};

class saveBtn : public myButton
{
    Q_OBJECT
public:
    explicit saveBtn(QWidget* parent = nullptr);
    void mouseReleaseEvent(QMouseEvent* event);
signals:
    void save_clicked();
};

class detailBtn : public myButton{
    Q_OBJECT
public:
    explicit detailBtn(QWidget* parent = nullptr);
    void mouseReleaseEvent(QMouseEvent* event);
signals:
    void detail_clicked();
};

class BuffBtn : public myButton {
    Q_OBJECT
private:
    int buff;
    int coin;
    QPixmap buffpic;
protected:
    void paintEvent(QPaintEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void enterEvent(QEnterEvent* event) override;
public:
    explicit BuffBtn(int buff, QWidget* parent = nullptr);

signals:
    void buybuff(int buff, int coin);
};

#endif // MYBUTTON_H
