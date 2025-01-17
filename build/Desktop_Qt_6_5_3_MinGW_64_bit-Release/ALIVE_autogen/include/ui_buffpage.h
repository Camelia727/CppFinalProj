/********************************************************************************
** Form generated from reading UI file 'buffpage.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUFFPAGE_H
#define UI_BUFFPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BuffPage
{
public:

    void setupUi(QWidget *BuffPage)
    {
        if (BuffPage->objectName().isEmpty())
            BuffPage->setObjectName("BuffPage");
        BuffPage->resize(991, 616);

        retranslateUi(BuffPage);

        QMetaObject::connectSlotsByName(BuffPage);
    } // setupUi

    void retranslateUi(QWidget *BuffPage)
    {
        BuffPage->setWindowTitle(QCoreApplication::translate("BuffPage", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BuffPage: public Ui_BuffPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUFFPAGE_H
