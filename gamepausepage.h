#ifndef GAMEPAUSEPAGE_H
#define GAMEPAUSEPAGE_H

#include <QWidget>

namespace Ui {
class GamePausePage;
}

class GamePausePage : public QWidget
{
    Q_OBJECT

public:
    explicit GamePausePage(QWidget *parent = nullptr);
    ~GamePausePage();

private:
    Ui::GamePausePage *ui;
signals:
    void goon();
public slots:
    void goonclicked() {emit goon(); close();}
};

#endif // GAMEPAUSEPAGE_H
