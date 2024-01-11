#include "recordedit.h"
#include "ui_recordedit.h"
#include "idatabase.h"
#include <QSqlTableModel>

RecordEdit::RecordEdit(QWidget *parent,int rec) :
    QWidget(parent),
    ui(new Ui::RecordEdit)
{
    ui->setupUi(this);

    dataMapper=new QDataWidgetMapper();
    QSqlTableModel *tabModel=IDatabase::getInstance().recordTabModel;
    dataMapper->setModel(IDatabase::getInstance().recordTabModel);
    dataMapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);

    dataMapper->addMapping(ui->recID,tabModel->fieldIndex("ID"));
    dataMapper->addMapping(ui->recName,tabModel->fieldIndex("name"));
    dataMapper->addMapping(ui->recDocName,tabModel->fieldIndex("dname"));
    dataMapper->addMapping(ui->recDate,tabModel->fieldIndex("date"));
    dataMapper->addMapping(ui->recDrup,tabModel->fieldIndex("alldrup"));
    dataMapper->addMapping(ui->recDrupPrice,tabModel->fieldIndex("drupprice"));
    dataMapper->addMapping(ui->recDocPrice,tabModel->fieldIndex("dprice"));
    dataMapper->addMapping(ui->recResult,tabModel->fieldIndex("result"));

    dataMapper->setCurrentIndex(rec);
}

RecordEdit::~RecordEdit()
{
    delete ui;
}

void RecordEdit::on_recSave_clicked()
{
    IDatabase::getInstance().submitP(4);
    emit goPreviousView();
}

void RecordEdit::on_recCancel_clicked()
{
    IDatabase::getInstance().revertP(4);
    emit goPreviousView();
}

