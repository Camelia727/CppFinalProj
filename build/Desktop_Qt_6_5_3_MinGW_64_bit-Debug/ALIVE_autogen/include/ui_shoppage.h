/********************************************************************************
** Form generated from reading UI file 'shoppage.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOPPAGE_H
#define UI_SHOPPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QWidget>
#include "mybutton.h"

QT_BEGIN_NAMESPACE

class Ui_ShopPage
{
public:
    BuffBtn *hpbtn;
    BuffBtn *atkbtn;
    BuffBtn *atpbtn;
    BuffBtn *spdbtn;
    BuffBtn *coinbtn;
    BuffBtn *revivebtn;
    QPlainTextEdit *curcoinsedit;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_1;

    void setupUi(QWidget *ShopPage)
    {
        if (ShopPage->objectName().isEmpty())
            ShopPage->setObjectName("ShopPage");
        ShopPage->resize(1200, 700);
        hpbtn = new BuffBtn(0,ShopPage);
        hpbtn->setObjectName("hpbtn");
        hpbtn->setGeometry(QRect(90, 70, 120, 120));
        atkbtn = new BuffBtn(1,ShopPage);
        atkbtn->setObjectName("atkbtn");
        atkbtn->setGeometry(QRect(280, 70, 120, 120));
        atpbtn = new BuffBtn(2,ShopPage);
        atpbtn->setObjectName("atpbtn");
        atpbtn->setGeometry(QRect(460, 70, 120, 120));
        spdbtn = new BuffBtn(3,ShopPage);
        spdbtn->setObjectName("spdbtn");
        spdbtn->setGeometry(QRect(90, 250, 120, 120));
        coinbtn = new BuffBtn(4,ShopPage);
        coinbtn->setObjectName("coinbtn");
        coinbtn->setGeometry(QRect(280, 250, 120, 120));
        revivebtn = new BuffBtn(5,ShopPage);
        revivebtn->setObjectName("revivebtn");
        revivebtn->setGeometry(QRect(460, 250, 120, 120));
        curcoinsedit = new QPlainTextEdit(ShopPage);
        curcoinsedit->setObjectName("curcoinsedit");
        curcoinsedit->setGeometry(QRect(90, 510, 321, 75));
        label_3 = new QLabel(ShopPage);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(90, 390, 121, 31));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setItalic(true);
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(ShopPage);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(280, 390, 121, 31));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(ShopPage);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(460, 390, 121, 31));
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignCenter);
        label = new QLabel(ShopPage);
        label->setObjectName("label");
        label->setGeometry(QRect(90, 200, 121, 31));
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(ShopPage);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(460, 200, 121, 31));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);
        label_1 = new QLabel(ShopPage);
        label_1->setObjectName("label_1");
        label_1->setGeometry(QRect(280, 200, 121, 31));
        label_1->setFont(font);
        label_1->setAlignment(Qt::AlignCenter);

        retranslateUi(ShopPage);

        QMetaObject::connectSlotsByName(ShopPage);
    } // setupUi

    void retranslateUi(QWidget *ShopPage)
    {
        ShopPage->setWindowTitle(QCoreApplication::translate("ShopPage", "Form", nullptr));
        label_3->setText(QCoreApplication::translate("ShopPage", "\345\224\256\344\273\267\357\274\23250", nullptr));
        label_4->setText(QCoreApplication::translate("ShopPage", "\345\224\256\344\273\267\357\274\23250", nullptr));
        label_5->setText(QCoreApplication::translate("ShopPage", "\345\224\256\344\273\267\357\274\23250", nullptr));
        label->setText(QCoreApplication::translate("ShopPage", "\345\224\256\344\273\267\357\274\23250", nullptr));
        label_2->setText(QCoreApplication::translate("ShopPage", "\345\224\256\344\273\267\357\274\23250", nullptr));
        label_1->setText(QCoreApplication::translate("ShopPage", "\345\224\256\344\273\267\357\274\23250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShopPage: public Ui_ShopPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOPPAGE_H
