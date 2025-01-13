#ifndef ROLEPAGE_H
#define ROLEPAGE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTextEdit>
#include <QPainter>
#include "gamepage.h"
#include "roleedit.h"
#include "rolewidget.h"

namespace Ui {
class RolePage;
}

class RolePage : public QWidget
{
    Q_OBJECT

public:
    explicit RolePage(QWidget *parent = nullptr);
    ~RolePage();

private:
    Ui::RolePage *ui;

signals:
    void gameOpen(DiffiLevel diffi);

public slots:
    void openGame();
};

#endif // ROLEPAGE_H
