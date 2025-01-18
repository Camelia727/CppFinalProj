/********************************************************************************
** Form generated from reading UI file 'detailpage.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DETAILPAGE_H
#define UI_DETAILPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DetailPage
{
public:

    void setupUi(QWidget *DetailPage)
    {
        if (DetailPage->objectName().isEmpty())
            DetailPage->setObjectName("DetailPage");
        DetailPage->resize(1000, 600);

        retranslateUi(DetailPage);

        QMetaObject::connectSlotsByName(DetailPage);
    } // setupUi

    void retranslateUi(QWidget *DetailPage)
    {
        DetailPage->setWindowTitle(QCoreApplication::translate("DetailPage", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DetailPage: public Ui_DetailPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETAILPAGE_H
