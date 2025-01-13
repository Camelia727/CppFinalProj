#ifndef ROLEWIDGET_H
#define ROLEWIDGET_H

#include <QWidget>
#include <QPainter>

class RoleWidget : public QWidget
{
    Q_OBJECT
private:
    QPixmap pic;
    QString name;
    QRect rect;

public:
    explicit RoleWidget(QWidget *parent = nullptr, QString name = "");
    void setName(const QString n);

protected:
    void enterEvent(QEnterEvent* event) override;
    void leaveEvent(QEvent* event) override;
    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;


signals:
    void role_clicked();
};

#endif // ROLEWIDGET_H
