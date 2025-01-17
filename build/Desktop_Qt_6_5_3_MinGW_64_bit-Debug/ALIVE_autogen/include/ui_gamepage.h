/********************************************************************************
** Form generated from reading UI file 'gamepage.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEPAGE_H
#define UI_GAMEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GamePage
{
public:
    QWidget *widget;
    QLabel *timer;
    QLabel *coins;

    void setupUi(QWidget *GamePage)
    {
        if (GamePage->objectName().isEmpty())
            GamePage->setObjectName("GamePage");
        GamePage->resize(1121, 761);
        widget = new QWidget(GamePage);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(90, 110, 951, 561));
        timer = new QLabel(GamePage);
        timer->setObjectName("timer");
        timer->setGeometry(QRect(500, 20, 101, 51));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        timer->setFont(font);
        timer->setAlignment(Qt::AlignCenter);
        coins = new QLabel(GamePage);
        coins->setObjectName("coins");
        coins->setGeometry(QRect(920, 30, 141, 41));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        coins->setFont(font1);
        coins->setAlignment(Qt::AlignCenter);

        retranslateUi(GamePage);

        QMetaObject::connectSlotsByName(GamePage);
    } // setupUi

    void retranslateUi(QWidget *GamePage)
    {
        GamePage->setWindowTitle(QCoreApplication::translate("GamePage", "ALIVE", nullptr));
        timer->setText(QCoreApplication::translate("GamePage", "TextLabel", nullptr));
        coins->setText(QCoreApplication::translate("GamePage", "\351\207\221\345\270\201\357\274\2320", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GamePage: public Ui_GamePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEPAGE_H
