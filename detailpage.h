#ifndef DETAILPAGE_H
#define DETAILPAGE_H

#include <QWidget>

namespace Ui {
class DetailPage;
}

class DetailPage : public QWidget
{
    Q_OBJECT

public:
    explicit DetailPage(QWidget *parent = nullptr);
    ~DetailPage();

protected:
    void paintEvent(QPaintEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;

private:
    Ui::DetailPage *ui;
    int cur;
    QList<QPixmap> pics;

signals:
    void exit();

};

#endif // DETAILPAGE_H
