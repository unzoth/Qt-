#include "recordedit.h"
#include "ui_recordedit.h"

RecordEdit::RecordEdit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RecordEdit)
{
    ui->setupUi(this);
}

RecordEdit::~RecordEdit()
{
    delete ui;
}
