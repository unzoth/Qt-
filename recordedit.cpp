#include "recordedit.h"
#include "ui_recordedit.h"

RecordEdit::RecordEdit(QWidget *parent,int rec) :
    QWidget(parent),
    ui(new Ui::RecordEdit)
{
    ui->setupUi(this);
}

RecordEdit::~RecordEdit()
{
    delete ui;
}

void RecordEdit::on_recSave_clicked()
{

}

void RecordEdit::on_recCancel_clicked()
{

}

