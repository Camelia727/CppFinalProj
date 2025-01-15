#ifndef BUFFPAGE_H
#define BUFFPAGE_H

#include <QWidget>
#include <QRandomGenerator>
#include <QPainter>

namespace Ui {
class BuffPage;
}

class BuffWidget : public QWidget
{
    Q_OBJECT

    QPixmap pic;
    QSize size;
    QRect rect;
    int buff;
public:
    explicit BuffWidget(int buff, QWidget* parent = nullptr);
protected:
    void enterEvent(QEnterEvent* event);
    void leaveEvent(QEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void paintEvent(QPaintEvent* event);

signals:
    void clicked(int sel);
};

class BuffPage : public QWidget
{
    Q_OBJECT

public:
    explicit BuffPage(QWidget *parent = nullptr);
    ~BuffPage();

protected:
    void paintEvent(QPaintEvent* event);

private:
    Ui::BuffPage *ui;
    int b1,b2,b3;
    BuffWidget *buff1, *buff2, *buff3;
    QPixmap pic;

signals:
    void buffselection(int sel);

public slots:
    void buffselect(int sel);
};





#endif // BUFFPAGE_H


