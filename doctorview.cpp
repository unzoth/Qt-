#include "doctorview.h"
#include "ui_doctorview.h"

DoctorView::DoctorView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DoctorView)
{
    ui->setupUi(this);
}

DoctorView::~DoctorView()
{
    delete ui;
}

void DoctorView::on_docSearch_clicked()
{

}


void DoctorView::on_docAdd_clicked()
{

}


void DoctorView::on_docDelete_clicked()
{

}


void DoctorView::on_docEdit_clicked()
{

}

