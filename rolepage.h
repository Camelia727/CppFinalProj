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

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    Ui::RolePage *ui;
    QPixmap pic;

signals:
    void gameOpen(QString name);

public slots:
    void openGame(QString name);
};

#endif // ROLEPAGE_H
