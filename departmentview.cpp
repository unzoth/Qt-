#include "departmentview.h"
#include "ui_departmentview.h"
#include "idatabase.h"

DepartmentView::DepartmentView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DepartmentView)
{
    ui->setupUi(this);

    ui->drupSearchR->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->drupSearchR->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->drupSearchR->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->drupSearchR->setAlternatingRowColors(true);

    IDatabase &idatabase = IDatabase::getInstance();
    if (idatabase.initDepartmentModel()) {
        ui->drupSearchR->setModel(idatabase.departmentTabModel);
        ui->drupSearchR->setSelectionModel(idatabase.theDepartmentSelection);
    }
}

DepartmentView::~DepartmentView()
{
    delete ui;
}

void DepartmentView::on_drupSearch_clicked()
{
    QString filter = QString("drupname like '%%1%'").arg(ui->drupTxtSearch->text());
    IDatabase::getInstance().searchP(filter, 1);
}

void DepartmentView::on_drupAdd_clicked()
{
    int cur = IDatabase::getInstance().addP(1);
    emit goDepartmentEdit(cur);
}

void DepartmentView::on_drupDelete_clicked()
{
    IDatabase::getInstance().deleteP(1);
}

void DepartmentView::on_drupEdit_clicked()
{
    QModelIndex cur = IDatabase::getInstance().theDepartmentSelection->currentIndex();
    emit goDepartmentEdit(cur.row());
}
