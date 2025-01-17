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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RolePage
{
public:

    void setupUi(QWidget *RolePage)
    {
        if (RolePage->objectName().isEmpty())
            RolePage->setObjectName("RolePage");
        RolePage->resize(1000, 600);

        retranslateUi(RolePage);

        QMetaObject::connectSlotsByName(RolePage);
    } // setupUi

    void retranslateUi(QWidget *RolePage)
    {
        RolePage->setWindowTitle(QCoreApplication::translate("RolePage", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RolePage: public Ui_RolePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROLEPAGE_H
