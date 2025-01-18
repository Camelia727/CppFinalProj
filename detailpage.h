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

private:
    Ui::DetailPage *ui;
};

#endif // DETAILPAGE_H
