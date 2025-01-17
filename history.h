#ifndef HISTORY_H
#define HISTORY_H

#include <QObject>
#include <QWidget>

enum BUFFS{
    HP,
    ATK,
    ATP,
    SPD,
    COIN,
    REVIVE
};

class History : public QObject
{
    Q_OBJECT
private:
    int gamecount;
    int maxrounds;
    int coins;
    QList<double> buffs;

public:
    explicit History(QObject *parent = nullptr);
    int getGamecount() const {return gamecount;}
    int getMaxrounds() const {return maxrounds;}
    int getCoins() const {return coins;}
    double getbuff(const BUFFS buff) const {return buffs[buff];}
    void gainCoins(const int coin) {coins += coin;}
    void spendCoins(const int coin) {coins = coins - coin >= 0 ? coins - coin : 0;}
    void gainBuff(const BUFFS buff) {if (buffs[buff] < 5) buffs[buff]++;}
    void setGamecount(int count) {gamecount = count;}
    void setMaxrounds(int round) {maxrounds = round;}
    void setBuffs(int buff, int level) {buffs[buff] = level;}
    void setCoins(int coin) {coins = coin;}

signals:

public slots:
    void HistoryUpdate(int new_round);
};

#endif // HISTORY_H
