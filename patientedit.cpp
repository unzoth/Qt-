#include "patientedit.h"
#include "ui_patientedit.h"
#include "idatabase.h"
#include <QSqlTableModel>

PatientEdit::PatientEdit(QWidget *parent,int row) :
    QWidget(parent),
    ui(new Ui::PatientEdit)
{
    ui->setupUi(this);

    dataMapper=new QDataWidgetMapper();
    QSqlTableModel *tabModel=IDatabase::getInstance().patientTabModel;
    dataMapper->setModel(IDatabase::getInstance().patientTabModel);
    dataMapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);

    dataMapper->addMapping(ui->txtID,tabModel->fieldIndex("ID"));
    dataMapper->addMapping(ui->txtName,tabModel->fieldIndex("name"));
    dataMapper->addMapping(ui->txtIDC,tabModel->fieldIndex("id_card"));
    dataMapper->addMapping(ui->boxHeight,tabModel->fieldIndex("height"));
    dataMapper->addMapping(ui->boxWeight,tabModel->fieldIndex("weight"));
    dataMapper->addMapping(ui->txtPhone,tabModel->fieldIndex("phone"));
    dataMapper->addMapping(ui->edDate,tabModel->fieldIndex("dob"));
    dataMapper->addMapping(ui->btSex,tabModel->fieldIndex("sex"));

    dataMapper->setCurrentIndex(row);
}

PatientEdit::~PatientEdit()
{
    delete ui;
}

void PatientEdit::on_btSave_clicked()
{
    IDatabase::getInstance().submitP(3);
    emit goPreviousView();
}


void PatientEdit::on_btCancel_clicked()
{
    IDatabase::getInstance().revertP(3);
    emit goPreviousView();
}

