#include "departmentedit.h"
#include "ui_departmentedit.h"

DepartmentEdit::DepartmentEdit(QWidget *parent,int dep) :
    QWidget(parent),
    ui(new Ui::DepartmentEdit)
{
    ui->setupUi(this);
}

DepartmentEdit::~DepartmentEdit()
{
    delete ui;
}

void DepartmentEdit::on_drupSave_clicked()
{

}


void DepartmentEdit::on_drupCancel_clicked()
{

}

