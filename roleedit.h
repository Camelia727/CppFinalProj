#ifndef ROLEEDIT_H
#define ROLEEDIT_H

#include <QWidget>
#include <QTextEdit>

class roleEdit : public QWidget
{
    Q_OBJECT
private:
    QString name;
    QTextEdit edit;
    QPixmap background;

public:
    explicit roleEdit(QWidget *parent = nullptr, QString name = "none");
    void setName(QString n);


signals:

public slots:
    void textHighLisht();
};

#endif // ROLEEDIT_H
