#include "patientview.h"
#include "ui_patientview.h"
#include "idatabase.h"

PatientView::PatientView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PatientView)
{
    ui->setupUi(this);

    ui->tbSearch->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tbSearch->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tbSearch->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tbSearch->setAlternatingRowColors(true);

    IDatabase &idatabase=IDatabase::getInstance();
    if(idatabase.initPatientModel()){
        ui->tbSearch->setModel(idatabase.patientTabModel);
        ui->tbSearch->setSelectionModel(idatabase.thePatientSelection);
    }
}

PatientView::~PatientView()
{
    delete ui;
}

void PatientView::on_btAdd_clicked()
{
    int cur=IDatabase::getInstance().addP(3);
    emit goPatientEdit(cur);
}


void PatientView::on_btSearch_clicked()
{
    QString filter=QString("name like '%%1%'").arg(ui->txtSearch->text());
    IDatabase::getInstance().searchP(filter,3);
}


void PatientView::on_btDelete_clicked()
{
    IDatabase::getInstance().deleteP(3);
}


void PatientView::on_btEdit_clicked()
{
    QModelIndex cur=IDatabase::getInstance().thePatientSelection->currentIndex();
    emit goPatientEdit(cur.row());
}

