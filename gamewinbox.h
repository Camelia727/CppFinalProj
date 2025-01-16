#ifndef GAMEWINBOX_H
#define GAMEWINBOX_H

#include <QWidget>

namespace Ui {
class GameWinBox;
}


class GameWinBox : public QWidget
{
    Q_OBJECT

public:
    explicit GameWinBox(QWidget *parent = nullptr);
    ~GameWinBox();

private:
    Ui::GameWinBox *ui;
    QPixmap background;

protected:
    void paintEvent(QPaintEvent* event) override;

signals:
    void home_clicked();

public slots:
    void Home();
};

#endif // GAMEWINBOX_H
