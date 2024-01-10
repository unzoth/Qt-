#include "doctoredit.h"
#include "ui_doctoredit.h"

DoctorEdit::DoctorEdit(QWidget *parent,int doc) :
    QWidget(parent),
    ui(new Ui::DoctorEdit)
{
    ui->setupUi(this);
}

DoctorEdit::~DoctorEdit()
{
    delete ui;
}

void DoctorEdit::on_docSave_clicked()
{

}


void DoctorEdit::on_docCancel_clicked()
{

}

