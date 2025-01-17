/********************************************************************************
** Form generated from reading UI file 'homepage.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMEPAGE_H
#define UI_HOMEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "mybutton.h"

QT_BEGIN_NAMESPACE

class Ui_HomePage
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    shopBtn *shopbtn;
    gameBtn *gamebtn;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    saveBtn *savebtn;
    detailBtn *detailbtn;

    void setupUi(QWidget *HomePage)
    {
        if (HomePage->objectName().isEmpty())
            HomePage->setObjectName("HomePage");
        HomePage->resize(1000, 600);
        verticalLayoutWidget = new QWidget(HomePage);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(670, 210, 331, 391));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        shopbtn = new shopBtn(verticalLayoutWidget);
        shopbtn->setObjectName("shopbtn");

        verticalLayout->addWidget(shopbtn);

        gamebtn = new gameBtn(verticalLayoutWidget);
        gamebtn->setObjectName("gamebtn");

        verticalLayout->addWidget(gamebtn);

        verticalLayoutWidget_2 = new QWidget(HomePage);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(120, 210, 291, 391));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        savebtn = new saveBtn(verticalLayoutWidget_2);
        savebtn->setObjectName("savebtn");

        verticalLayout_2->addWidget(savebtn);

        detailbtn = new detailBtn(verticalLayoutWidget_2);
        detailbtn->setObjectName("detailbtn");

        verticalLayout_2->addWidget(detailbtn);


        retranslateUi(HomePage);

        QMetaObject::connectSlotsByName(HomePage);
    } // setupUi

    void retranslateUi(QWidget *HomePage)
    {
        HomePage->setWindowTitle(QCoreApplication::translate("HomePage", "ALIVE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HomePage: public Ui_HomePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEPAGE_H
