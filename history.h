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
    void gainBuff(const BUFFS buff) {if (buffs[buff] < 5) buffs[buff]++;
        /*qDebug() << "gain a buff with ID:" << QString::number(buff) << "curbuffLevel:" << QString::number(buffs[buff]);*/}

signals:

public slots:
    void HistoryUpdate(int new_round);
};

#endif // HISTORY_H
