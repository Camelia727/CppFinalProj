#include "history.h"
#include <qdebug.h>

History::History(QObject *parent)
    : QObject{parent}
    , gamecount(0)
    , maxrounds(0)
    , coins(0)
{
    buffs = QList<double>(6, 0);
}

void History::HistoryUpdate(int new_count)
{
    gamecount++;
    maxrounds = std::min(maxrounds, new_count);
}
