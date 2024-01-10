#include "idatabase.h"

void IDatabase::inindatabase()
{
    database=QSqlDatabase::addDatabase("QSQLITE");
    QString aFile="E:/work/homework3/qt/Hospital.db";
    database.setDatabaseName(aFile);
    database.open();
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

int IDatabase::addP()
{
    patientTabModel->insertRow(patientTabModel->rowCount(),QModelIndex());
    QModelIndex cur=patientTabModel->index(patientTabModel->rowCount()-1,1);
    return cur.row();
}

bool IDatabase::searchP(QString filter)
{
    patientTabModel->setFilter(filter);
    return patientTabModel->select();
}

bool IDatabase::deleteP()
{
    QModelIndex cur=thePatientSelection->currentIndex();
    patientTabModel->removeRow(cur.row());
    patientTabModel->submitAll();
    patientTabModel->select();
}

bool IDatabase::submitP()
{
    return patientTabModel->submitAll();
}

void IDatabase::revertP()
{
    patientTabModel->revertAll();
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
