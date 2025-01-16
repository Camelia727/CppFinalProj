/********************************************************************************
** Form generated from reading UI file 'gamewinbox.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEWINBOX_H
#define UI_GAMEWINBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameWinBox
{
public:
    QPushButton *home;

    void setupUi(QWidget *GameWinBox)
    {
        if (GameWinBox->objectName().isEmpty())
            GameWinBox->setObjectName("GameWinBox");
        GameWinBox->resize(400, 300);
        home = new QPushButton(GameWinBox);
        home->setObjectName("home");
        home->setGeometry(QRect(170, 240, 56, 18));

        retranslateUi(GameWinBox);

        QMetaObject::connectSlotsByName(GameWinBox);
    } // setupUi

    void retranslateUi(QWidget *GameWinBox)
    {
        GameWinBox->setWindowTitle(QCoreApplication::translate("GameWinBox", "Form", nullptr));
        home->setText(QCoreApplication::translate("GameWinBox", " \344\270\273 \351\241\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameWinBox: public Ui_GameWinBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWINBOX_H
