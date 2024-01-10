#include "departmentview.h"
#include "ui_departmentview.h"

DepartmentView::DepartmentView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DepartmentView)
{
    ui->setupUi(this);
}

DepartmentView::~DepartmentView()
{
    delete ui;
}

void DepartmentView::on_drupSearch_clicked()
{

}


void DepartmentView::on_drupAdd_clicked()
{

}


void DepartmentView::on_drupDelete_clicked()
{

}


void DepartmentView::on_drupEdit_clicked()
{

}

