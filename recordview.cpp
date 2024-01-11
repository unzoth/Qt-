#include "recordview.h"
#include "ui_recordview.h"
#include "idatabase.h"

RecordView::RecordView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RecordView)
{
    ui->setupUi(this);

    ui->recSearchR->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->recSearchR->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->recSearchR->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->recSearchR->setAlternatingRowColors(true);

    IDatabase &idatabase=IDatabase::getInstance();
    if(idatabase.initRecordModel()){
        ui->recSearchR->setModel(idatabase.recordTabModel);
        ui->recSearchR->setSelectionModel(idatabase.theRecordSelection);
    }
}

RecordView::~RecordView()
{
    delete ui;
}

void RecordView::on_recSearch_clicked()
{
    QString filter=QString("name like '%%1%'").arg(ui->recTxtSearch->text());
    IDatabase::getInstance().searchP(filter,4);
}


void RecordView::on_recAdd_clicked()
{
    int cur=IDatabase::getInstance().addP(4);
    emit goRecordEdit(cur);
}


void RecordView::on_recDelete_clicked()
{
    IDatabase::getInstance().deleteP(4);
}


void RecordView::on_recEdit_clicked()
{
    QModelIndex cur=IDatabase::getInstance().theRecordSelection->currentIndex();
    emit goRecordEdit(cur.row());
}

