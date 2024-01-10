#include "departmentedit.h"
#include "ui_departmentedit.h"

DepartmentEdit::DepartmentEdit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DepartmentEdit)
{
    ui->setupUi(this);
}

DepartmentEdit::~DepartmentEdit()
{
    delete ui;
}
