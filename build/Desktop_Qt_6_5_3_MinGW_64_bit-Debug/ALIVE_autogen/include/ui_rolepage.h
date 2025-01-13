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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RolePage
{
public:
    QTextEdit *textEdit;
    QPushButton *pushButton;

    void setupUi(QWidget *RolePage)
    {
        if (RolePage->objectName().isEmpty())
            RolePage->setObjectName("RolePage");
        RolePage->resize(1067, 786);
        textEdit = new QTextEdit(RolePage);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(400, 580, 104, 75));
        pushButton = new QPushButton(RolePage);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(570, 590, 271, 71));

        retranslateUi(RolePage);

        QMetaObject::connectSlotsByName(RolePage);
    } // setupUi

    void retranslateUi(QWidget *RolePage)
    {
        RolePage->setWindowTitle(QCoreApplication::translate("RolePage", "Form", nullptr));
        textEdit->setHtml(QCoreApplication::translate("RolePage", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">rolepage</p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("RolePage", "game on", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RolePage: public Ui_RolePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROLEPAGE_H
