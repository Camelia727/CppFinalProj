/********************************************************************************
** Form generated from reading UI file 'gamepausepage.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEPAUSEPAGE_H
#define UI_GAMEPAUSEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GamePausePage
{
public:
    QPushButton *goonBtn;

    void setupUi(QWidget *GamePausePage)
    {
        if (GamePausePage->objectName().isEmpty())
            GamePausePage->setObjectName("GamePausePage");
        GamePausePage->resize(400, 300);
        goonBtn = new QPushButton(GamePausePage);
        goonBtn->setObjectName("goonBtn");
        goonBtn->setGeometry(QRect(170, 160, 56, 61));

        retranslateUi(GamePausePage);

        QMetaObject::connectSlotsByName(GamePausePage);
    } // setupUi

    void retranslateUi(QWidget *GamePausePage)
    {
        GamePausePage->setWindowTitle(QCoreApplication::translate("GamePausePage", "Form", nullptr));
        goonBtn->setText(QCoreApplication::translate("GamePausePage", "\347\273\247\347\273\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GamePausePage: public Ui_GamePausePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEPAUSEPAGE_H
