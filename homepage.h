#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QWidget>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <rolepage.h>
#include <mybutton.h>
#include "shoppage.h"
#include "gamepage.h"
#include "history.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class HomePage;
}
QT_END_NAMESPACE

class HomePage : public QWidget
{
    Q_OBJECT

public:
    HomePage(QWidget *parent = nullptr);
    ~HomePage();
    void saveHistory() const;
    void loadHistory() const;
    void clearHistory() const;

private:
    Ui::HomePage *ui;
    QPixmap background;
    History* history;
    RolePage* role_page;
    GamePage* game_page;
    bool shopOn;
protected:
    void closeEvent(QCloseEvent* event) override;
    void paintEvent(QPaintEvent* event) override;

public slots:
    void openRole();
    void openGame(QString name);
    void openDetail();
    void openSave();
    void openShop();
    void closeShop();
    void buyBuff(int buff, int coin);
    void gameEnd(int rounds);
    void gameExit(int rounds);
};
#endif // HOMEPAGE_H
