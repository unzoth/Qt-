#include "doctoredit.h"
#include "ui_doctoredit.h"
#include "idatabase.h"
#include <QSqlTableModel>

DoctorEdit::DoctorEdit(QWidget *parent, int doc) :
    QWidget(parent),
    ui(new Ui::DoctorEdit)
{
    ui->setupUi(this);

    dataMapper = new QDataWidgetMapper();
    QSqlTableModel *tabModel = IDatabase::getInstance().doctorTabModel;
    dataMapper->setModel(IDatabase::getInstance().doctorTabModel);
    dataMapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);

    dataMapper->addMapping(ui->docID, tabModel->fieldIndex("ID"));
    dataMapper->addMapping(ui->docName, tabModel->fieldIndex("dname"));
    dataMapper->addMapping(ui->docAge, tabModel->fieldIndex("dage"));
    dataMapper->addMapping(ui->docSex, tabModel->fieldIndex("dsex"));
    dataMapper->addMapping(ui->docBook, tabModel->fieldIndex("book"));

    dataMapper->setCurrentIndex(doc);
}

DoctorEdit::~DoctorEdit()
{
    delete ui;
}

void DoctorEdit::on_docSave_clicked()
{
    IDatabase::getInstance().submitP(2);
    emit goPreviousView();
}

void DoctorEdit::on_docCancel_clicked()
{
    IDatabase::getInstance().revertP(2);
    emit goPreviousView();
}
