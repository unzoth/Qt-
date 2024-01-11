#include "idatabase.h"

void IDatabase::inindatabase()
{
    database=QSqlDatabase::addDatabase("QSQLITE");
    QString aFile="E:/work/homework3/qt/Hospital.db";
    database.setDatabaseName(aFile);
    database.open();
}

bool IDatabase::initDepartmentModel()
{
    departmentTabModel=new QSqlTableModel(this,database);
    departmentTabModel->setTable("drup");
    departmentTabModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    departmentTabModel->setSort(departmentTabModel->fieldIndex("drupname"),Qt::AscendingOrder);
    if(!(departmentTabModel->select()))
        return false;
    theDepartmentSelection=new QItemSelectionModel(departmentTabModel);
    return true;
}

bool IDatabase::initDoctorModel()
{
    doctorTabModel=new QSqlTableModel(this,database);
    doctorTabModel->setTable("doctor");
    doctorTabModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    doctorTabModel->setSort(doctorTabModel->fieldIndex("dname"),Qt::AscendingOrder);
    if(!(doctorTabModel->select()))
        return false;
    theDoctorSelection=new QItemSelectionModel(doctorTabModel);
    return true;
}

bool IDatabase::initPatientModel()
{
    patientTabModel=new QSqlTableModel(this,database);
    patientTabModel->setTable("patient");
    patientTabModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    patientTabModel->setSort(patientTabModel->fieldIndex("name"),Qt::AscendingOrder);
    if(!(patientTabModel->select()))
        return false;
    thePatientSelection=new QItemSelectionModel(patientTabModel);
    return true;
}

bool IDatabase::initRecordModel()
{
    recordTabModel=new QSqlTableModel(this,database);
    recordTabModel->setTable("record");
    recordTabModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    recordTabModel->setSort(recordTabModel->fieldIndex("name"),Qt::AscendingOrder);
    if(!(recordTabModel->select()))
        return false;
    theRecordSelection=new QItemSelectionModel(recordTabModel);
    return true;
}

int IDatabase::addP(int add)
{
    QModelIndex cur;
    switch (add) {
    case 1:
        departmentTabModel->insertRow(departmentTabModel->rowCount(),QModelIndex());
        cur=departmentTabModel->index(departmentTabModel->rowCount()-1,1);
        return cur.row();
        break;
    case 2:
        doctorTabModel->insertRow(doctorTabModel->rowCount(),QModelIndex());
        cur=doctorTabModel->index(doctorTabModel->rowCount()-1,1);
        return cur.row();
        break;
    case 3:
        patientTabModel->insertRow(patientTabModel->rowCount(),QModelIndex());
        cur=patientTabModel->index(patientTabModel->rowCount()-1,1);
        return cur.row();
        break;
    case 4:
        recordTabModel->insertRow(recordTabModel->rowCount(),QModelIndex());
        cur=recordTabModel->index(recordTabModel->rowCount()-1,1);
        return cur.row();
        break;
    }
}

bool IDatabase::searchP(QString filter,int sea)
{
    switch (sea) {
    case 1:departmentTabModel->setFilter(filter);return departmentTabModel->select();break;
    case 2:doctorTabModel->setFilter(filter);return doctorTabModel->select();break;
    case 3:patientTabModel->setFilter(filter);return patientTabModel->select();break;
    case 4:recordTabModel->setFilter(filter);return recordTabModel->select();break;
    }
}

void IDatabase::deleteP(int del)
{
    QModelIndex cur;
    switch (del) {
    case 1:
        cur=theDepartmentSelection->currentIndex();
        departmentTabModel->removeRow(cur.row());
        departmentTabModel->submitAll();
        departmentTabModel->select();
        break;
    case 2:
        cur=theDoctorSelection->currentIndex();
        doctorTabModel->removeRow(cur.row());
        doctorTabModel->submitAll();
        doctorTabModel->select();
        break;
    case 3:
        cur=thePatientSelection->currentIndex();
        patientTabModel->removeRow(cur.row());
        patientTabModel->submitAll();
        patientTabModel->select();
        break;
    case 4:
        cur=theRecordSelection->currentIndex();
        recordTabModel->removeRow(cur.row());
        recordTabModel->submitAll();
        recordTabModel->select();
        break;
    }
}

void IDatabase::submitP(int sub)
{
    switch (sub) {
    case 1:departmentTabModel->submitAll();departmentTabModel->select();break;
    case 2:doctorTabModel->submitAll();doctorTabModel->select();break;
    case 3:patientTabModel->submitAll();patientTabModel->select();break;
    case 4:recordTabModel->submitAll();recordTabModel->select();break;
    }
}

void IDatabase::revertP(int rev)
{
    switch (rev) {
    case 1:departmentTabModel->revertAll();break;
    case 2:doctorTabModel->revertAll();break;
    case 3:patientTabModel->revertAll();break;
    case 4:recordTabModel->revertAll();break;
    }
}

QString IDatabase::userLogin(QString username, QString password)
{
    QSqlQuery query;
    query.prepare("select username,password from user where username=:USER");
    query.bindValue(":USER",username);
    query.exec();
    if(query.first()&&query.value("username").isValid()){
        QString passwd=query.value("password").toString();
        if(password==passwd)
            return "loginOK";
        else return "wrong password";
    }
    else return "wrong username";
}

IDatabase::IDatabase(QObject *parent) : QObject(parent)
{
    inindatabase();
}
