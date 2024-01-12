#include "departmentedit.h"
#include "ui_departmentedit.h"
#include "idatabase.h"
#include <QSqlTableModel>

DepartmentEdit::DepartmentEdit(QWidget *parent, int dep) :
    QWidget(parent),
    ui(new Ui::DepartmentEdit)
{
    ui->setupUi(this);

    //获取数据库模型
    dataMapper = new QDataWidgetMapper();
    QSqlTableModel *tabModel = IDatabase::getInstance().departmentTabModel;
    dataMapper->setModel(IDatabase::getInstance().departmentTabModel);
    dataMapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);
    //将界面控件模型的字段进行映射
    dataMapper->addMapping(ui->drupID, tabModel->fieldIndex("ID"));
    dataMapper->addMapping(ui->drupName, tabModel->fieldIndex("drupname"));
    dataMapper->addMapping(ui->drupCount, tabModel->fieldIndex("count"));
    dataMapper->addMapping(ui->drupSum, tabModel->fieldIndex("sum"));
    dataMapper->addMapping(ui->drupPrice, tabModel->fieldIndex("price"));
    dataMapper->addMapping(ui->proDate, tabModel->fieldIndex("prodate"));
    dataMapper->addMapping(ui->drupMonth, tabModel->fieldIndex("month"));

    dataMapper->setCurrentIndex(dep);
}

DepartmentEdit::~DepartmentEdit()
{
    delete ui;
}

void DepartmentEdit::on_drupSave_clicked()//保存
{
    IDatabase::getInstance().submitP(1);
    emit goPreviousView();
}

void DepartmentEdit::on_drupCancel_clicked()//取消
{
    IDatabase::getInstance().revertP(1);
    emit goPreviousView();
}
