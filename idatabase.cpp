#include "idatabase.h"
#include <QStandardItemModel>
#include <QStringList>
#include <QMessageBox>

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

    departmentTabModel->setHeaderData(departmentTabModel->fieldIndex("ID"), Qt::Horizontal, "药品编号");
    departmentTabModel->setHeaderData(departmentTabModel->fieldIndex("drupname"), Qt::Horizontal, "药品名");
    departmentTabModel->setHeaderData(departmentTabModel->fieldIndex("count"), Qt::Horizontal, "剂量/规格");
    departmentTabModel->setHeaderData(departmentTabModel->fieldIndex("sum"), Qt::Horizontal, "库存数量");
    departmentTabModel->setHeaderData(departmentTabModel->fieldIndex("price"), Qt::Horizontal, "价格");
    departmentTabModel->setHeaderData(departmentTabModel->fieldIndex("prodate"), Qt::Horizontal, "生产日期");
    departmentTabModel->setHeaderData(departmentTabModel->fieldIndex("month"), Qt::Horizontal, "保质期/月");

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

    doctorTabModel->setHeaderData(doctorTabModel->fieldIndex("ID"), Qt::Horizontal, "医生号");
    doctorTabModel->setHeaderData(doctorTabModel->fieldIndex("dname"), Qt::Horizontal, "姓名");
    doctorTabModel->setHeaderData(doctorTabModel->fieldIndex("dsex"), Qt::Horizontal, "性别");
    doctorTabModel->setHeaderData(doctorTabModel->fieldIndex("dage"), Qt::Horizontal, "年龄");
    doctorTabModel->setHeaderData(doctorTabModel->fieldIndex("book"), Qt::Horizontal, "执业证书号");
    doctorTabModel->setHeaderData(doctorTabModel->fieldIndex("dclass"), Qt::Horizontal, "所属科室");
    doctorTabModel->setHeaderData(doctorTabModel->fieldIndex("dtime"), Qt::Horizontal, "工作时间");
    doctorTabModel->setHeaderData(doctorTabModel->fieldIndex("dplace"), Qt::Horizontal, "工作地点");

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

    patientTabModel->setHeaderData(patientTabModel->fieldIndex("ID"), Qt::Horizontal, "患者号");
    patientTabModel->setHeaderData(patientTabModel->fieldIndex("name"), Qt::Horizontal, "姓名");
    patientTabModel->setHeaderData(patientTabModel->fieldIndex("sex"), Qt::Horizontal, "性别");
    patientTabModel->setHeaderData(patientTabModel->fieldIndex("phone"), Qt::Horizontal, "手机号");
    patientTabModel->setHeaderData(patientTabModel->fieldIndex("id_card"), Qt::Horizontal, "身份证号");
    patientTabModel->setHeaderData(patientTabModel->fieldIndex("height"), Qt::Horizontal, "身高(cm)");
    patientTabModel->setHeaderData(patientTabModel->fieldIndex("weight"), Qt::Horizontal, "体重(kg)");
    patientTabModel->setHeaderData(patientTabModel->fieldIndex("dob"), Qt::Horizontal, "出生日期");

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

    recordTabModel->setHeaderData(recordTabModel->fieldIndex("ID"), Qt::Horizontal, "就诊编号");
    recordTabModel->setHeaderData(recordTabModel->fieldIndex("name"), Qt::Horizontal, "患者姓名");
    recordTabModel->setHeaderData(recordTabModel->fieldIndex("dname"), Qt::Horizontal, "医生姓名");
    recordTabModel->setHeaderData(recordTabModel->fieldIndex("date"), Qt::Horizontal, "就诊日期");
    recordTabModel->setHeaderData(recordTabModel->fieldIndex("alldrup"), Qt::Horizontal, "开具药品");
    recordTabModel->setHeaderData(recordTabModel->fieldIndex("drupprice"), Qt::Horizontal, "药品总价格");
    recordTabModel->setHeaderData(recordTabModel->fieldIndex("dprice"), Qt::Horizontal, "就诊费用");
    recordTabModel->setHeaderData(recordTabModel->fieldIndex("result"), Qt::Horizontal, "诊断结果");

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
    query.prepare("select username,password,class from user where username=:USER");
    query.bindValue(":USER",username);
    query.exec();
    if(query.first()&&query.value("username").isValid()){
        QString passwd=query.value("password").toString();
        int tap=query.value("class").toInt();
        if(password==passwd&&tap==1)
            return "admin";//管理员账号
        else if(password==passwd&&tap==2)
            return "doctor";//医生账号
        else {
            QMessageBox::warning(nullptr, "错误", "密码错误",QMessageBox::Ok,QMessageBox::NoButton);
            return "wrong password";}
    }
    else {
        QMessageBox::warning(nullptr, "错误", "账号错误",QMessageBox::Ok,QMessageBox::NoButton);
        return "wrong username";
    }
}

IDatabase::IDatabase(QObject *parent) : QObject(parent)
{
    inindatabase();
}
