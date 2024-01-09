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
    dataMapper->addMapping(ui->txtName,tabModel->fieldIndex("NAME"));
    dataMapper->addMapping(ui->txtIDC,tabModel->fieldIndex("ID_CARD"));
    dataMapper->addMapping(ui->boxHeight,tabModel->fieldIndex("HEIGHT"));
    dataMapper->addMapping(ui->boxWeight,tabModel->fieldIndex("WEIGHT"));
    dataMapper->addMapping(ui->txtPhone,tabModel->fieldIndex("MOBILEPHONE"));
    dataMapper->addMapping(ui->edDate,tabModel->fieldIndex("DOB"));
    dataMapper->addMapping(ui->btSex,tabModel->fieldIndex("SEX"));

    dataMapper->setCurrentIndex(row);
}

PatientEdit::~PatientEdit()
{
    delete ui;
}

void PatientEdit::on_btSave_clicked()
{
    IDatabase::getInstance().submitP();
    emit goPreviousView();
}


void PatientEdit::on_btCancel_clicked()
{
    IDatabase::getInstance().revertP();
    emit goPreviousView();
}

