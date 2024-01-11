#ifndef IDATABASE_H
#define IDATABASE_H

#include <QObject>
#include <QtSql>
#include <QSqlDatabase>
#include <QDataWidgetMapper>

class IDatabase : public QObject
{
    Q_OBJECT
public:
    static IDatabase &getInstance(){
        static IDatabase instance;
        return instance;
    }
    QString userLogin(QString username,QString password);
private:
    explicit IDatabase(QObject *parent = nullptr);
    IDatabase(IDatabase const&)=delete;
    void operator=(IDatabase const&)=delete;
    QSqlDatabase database;
    void inindatabase();

signals:
public:
    bool initDepartmentModel();
    bool initDoctorModel();
    bool initPatientModel();
    bool initRecordModel();
    int addP(int add);
    bool searchP(QString filter,int sea);
    void deleteP(int del);
    void submitP(int sub);
    void revertP(int rev);

    QSqlTableModel *departmentTabModel;
    QItemSelectionModel *theDepartmentSelection;
    QSqlTableModel *doctorTabModel;
    QItemSelectionModel *theDoctorSelection;
    QSqlTableModel *patientTabModel;
    QItemSelectionModel *thePatientSelection;
    QSqlTableModel *recordTabModel;
    QItemSelectionModel *theRecordSelection;
};

#endif // IDATABASE_H
