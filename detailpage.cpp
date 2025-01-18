#include "detailpage.h"
#include "ui_detailpage.h"

DetailPage::DetailPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DetailPage)
{
    ui->setupUi(this);
}

DetailPage::~DetailPage()
{
    delete ui;
}
