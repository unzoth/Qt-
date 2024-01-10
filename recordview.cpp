#include "recordview.h"
#include "ui_recordview.h"

RecordView::RecordView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RecordView)
{
    ui->setupUi(this);
}

RecordView::~RecordView()
{
    delete ui;
}

void RecordView::on_recSearch_clicked()
{

}


void RecordView::on_recAdd_clicked()
{

}


void RecordView::on_recDelete_clicked()
{

}


void RecordView::on_recEdit_clicked()
{

}

