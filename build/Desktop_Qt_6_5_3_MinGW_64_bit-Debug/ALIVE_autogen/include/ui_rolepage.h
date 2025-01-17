/********************************************************************************
** Form generated from reading UI file 'rolepage.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROLEPAGE_H
#define UI_ROLEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RolePage
{
public:
    QLabel *label;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_2;

    void setupUi(QWidget *RolePage)
    {
        if (RolePage->objectName().isEmpty())
            RolePage->setObjectName("RolePage");
        RolePage->resize(1000, 600);
        label = new QLabel(RolePage);
        label->setObjectName("label");
        label->setGeometry(QRect(260, 380, 61, 21));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(RolePage);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(230, 410, 121, 21));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(RolePage);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(220, 430, 141, 21));
        label_5->setFont(font1);
        label_5->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(RolePage);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(590, 430, 141, 21));
        label_6->setFont(font1);
        label_6->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(RolePage);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(600, 410, 121, 21));
        label_7->setFont(font1);
        label_7->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(RolePage);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(630, 380, 61, 21));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        retranslateUi(RolePage);

        QMetaObject::connectSlotsByName(RolePage);
    } // setupUi

    void retranslateUi(QWidget *RolePage)
    {
        RolePage->setWindowTitle(QCoreApplication::translate("RolePage", "Form", nullptr));
        label->setText(QCoreApplication::translate("RolePage", "\345\211\221 \345\270\210", nullptr));
        label_4->setText(QCoreApplication::translate("RolePage", "\351\207\215\345\211\221\346\227\240\351\224\213\357\274\214\345\244\247\345\267\247\344\270\215\345\267\245", nullptr));
        label_5->setText(QCoreApplication::translate("RolePage", "\350\231\275\346\224\273\351\200\237\347\250\215\347\274\223\357\274\214\344\275\206\344\270\200\345\207\273\346\257\231\345\221\275", nullptr));
        label_6->setText(QCoreApplication::translate("RolePage", "\350\231\275\346\224\273\351\200\237\347\250\215\347\274\223\357\274\214\344\275\206\344\270\200\345\207\273\346\257\231\345\221\275", nullptr));
        label_7->setText(QCoreApplication::translate("RolePage", "\351\207\215\345\211\221\346\227\240\351\224\213\357\274\214\345\244\247\345\267\247\344\270\215\345\267\245", nullptr));
        label_2->setText(QCoreApplication::translate("RolePage", "\345\211\221 \345\270\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RolePage: public Ui_RolePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROLEPAGE_H
