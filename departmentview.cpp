#include "departmentview.h"
#include "ui_departmentview.h"
#include "idatabase.h"

DepartmentView::DepartmentView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DepartmentView)
{
    ui->setupUi(this);
    //样式
    ui->drupSearchR->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->drupSearchR->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->drupSearchR->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->drupSearchR->setAlternatingRowColors(true);
    //实例数据库
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

void DepartmentView::on_drupSearch_clicked()//查询
{
    QString filter = QString("drupname like '%%1%'").arg(ui->drupTxtSearch->text());
    IDatabase::getInstance().searchP(filter, 1);
}

void DepartmentView::on_drupAdd_clicked()//添加
{
    int cur = IDatabase::getInstance().addP(1);
    emit goDepartmentEdit(cur);
}

void DepartmentView::on_drupDelete_clicked()//修改
{
    IDatabase::getInstance().deleteP(1);
}

void DepartmentView::on_drupEdit_clicked()//删除
{
    QModelIndex cur = IDatabase::getInstance().theDepartmentSelection->currentIndex();
    emit goDepartmentEdit(cur.row());
}
