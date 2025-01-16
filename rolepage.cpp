#include "rolepage.h"
#include "ui_rolepage.h"

RolePage::RolePage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RolePage)
{
    ui->setupUi(this);
    setFixedSize(QSize(1000,600));
    setWindowFlag(Qt::FramelessWindowHint);
    setWindowFlags (windowFlags () | Qt::WindowStaysOnTopHint); // 将该页面置顶

    QWidget* mainWidget = new QWidget(this);


    QVBoxLayout* layout_role0 = new QVBoxLayout;
    QVBoxLayout* layout_role1 = new QVBoxLayout;
    QVBoxLayout* layout_role2 = new QVBoxLayout;


    RoleWidget* roleWidget_0 = new RoleWidget(this, "Swordsman");
    RoleWidget* roleWidget_1 = new RoleWidget(this, "Swordsman");
    RoleWidget* roleWidget_2 = new RoleWidget(this, "Magician");
    // QTextEdit* roleEdit_0 = new QTextEdit("this is role A");
    // QTextEdit* roleEdit_1 = new QTextEdit("this is role B");
    // QTextEdit* roleEdit_2 = new QTextEdit("this is role C");
    roleEdit* roleEdit_0 = new roleEdit(this, "Swordsman");
    roleEdit* roleEdit_1 = new roleEdit(this, "Magician");
    roleEdit* roleEdit_2 = new roleEdit(this, "none");

    roleEdit_0->setStyleSheet("background-color:rgba(0,0,0,0);border:none;");


    layout_role0->addWidget(roleWidget_0);
    layout_role0->addWidget(roleEdit_0);
    layout_role1->addWidget(roleWidget_1);
    layout_role1->addWidget(roleEdit_1);
    layout_role2->addWidget(roleWidget_2);
    layout_role2->addWidget(roleEdit_2);


    QHBoxLayout* layout_roles = new QHBoxLayout(mainWidget);
    layout_roles->addLayout(layout_role0);
    layout_roles->addSpacing(100);
    layout_roles->addLayout(layout_role1);
    layout_roles->addSpacing(100);
    layout_roles->addLayout(layout_role2);

    connect(roleWidget_0, &RoleWidget::role_clicked, this, &RolePage::openGame);
}

RolePage::~RolePage()
{
    delete ui;
}

void RolePage::openGame()
{
    emit gameOpen(DiffiLevel::EASY);
    hide();
}
