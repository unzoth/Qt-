#include "doctorview.h"
#include "ui_doctorview.h"
#include "idatabase.h"

DoctorView::DoctorView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DoctorView)
{
    ui->setupUi(this);

    ui->docSearchR->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->docSearchR->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->docSearchR->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->docSearchR->setAlternatingRowColors(true);

    IDatabase &idatabase = IDatabase::getInstance();
    if (idatabase.initDoctorModel()) {
        ui->docSearchR->setModel(idatabase.doctorTabModel);
        ui->docSearchR->setSelectionModel(idatabase.theDoctorSelection);
    }
}

DoctorView::~DoctorView()
{
    delete ui;
}

void DoctorView::on_docSearch_clicked()
{
    QString filter = QString("dname like '%%1%'").arg(ui->docTxtSearch->text());
    IDatabase::getInstance().searchP(filter, 2);
}

void DoctorView::on_docAdd_clicked()
{
    int cur = IDatabase::getInstance().addP(2);
    emit goDoctorEdit(cur);
}

void DoctorView::on_docDelete_clicked()
{
    IDatabase::getInstance().deleteP(2);
}

void DoctorView::on_docEdit_clicked()
{
    QModelIndex cur = IDatabase::getInstance().theDoctorSelection->currentIndex();
    emit goDoctorEdit(cur.row());
}
