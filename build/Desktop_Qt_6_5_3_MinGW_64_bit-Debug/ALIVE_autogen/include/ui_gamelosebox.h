/********************************************************************************
** Form generated from reading UI file 'gamelosebox.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMELOSEBOX_H
#define UI_GAMELOSEBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameLoseBox
{
public:
    QPushButton *home;

    void setupUi(QWidget *GameLoseBox)
    {
        if (GameLoseBox->objectName().isEmpty())
            GameLoseBox->setObjectName("GameLoseBox");
        GameLoseBox->resize(400, 300);
        home = new QPushButton(GameLoseBox);
        home->setObjectName("home");
        home->setGeometry(QRect(150, 240, 93, 28));

        retranslateUi(GameLoseBox);

        QMetaObject::connectSlotsByName(GameLoseBox);
    } // setupUi

    void retranslateUi(QWidget *GameLoseBox)
    {
        GameLoseBox->setWindowTitle(QCoreApplication::translate("GameLoseBox", "Form", nullptr));
        home->setText(QCoreApplication::translate("GameLoseBox", "\344\270\273 \351\241\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameLoseBox: public Ui_GameLoseBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMELOSEBOX_H
