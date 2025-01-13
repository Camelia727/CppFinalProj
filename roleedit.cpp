#include "roleedit.h"

QMap<QString, QString> textMap = {
    {"Swordsman", "剑光如织、以诗传情"},
    {"Magician", "星辰为引，魔法为伴"},
    {"none", "none"}
};

roleEdit::roleEdit(QWidget *parent, QString text)
    : QWidget{parent}
    , name(text)
{
    edit.setText(textMap[name]);
    edit.setReadOnly(true);
    edit.setStyleSheet("background-color:rgba(0,0,0,0);border:none;");
}

void roleEdit::setName(QString t)
{
    name = t;
    edit.setText(textMap[name]);
}

void roleEdit::textHighLisht()
{

}
