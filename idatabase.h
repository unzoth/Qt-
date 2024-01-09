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
    bool initPatientModel();
    int addP();
    bool searchP(QString filter);
    bool deleteP();
    bool submitP();
    void revertP();

    QSqlTableModel *patientTabModel;
    QItemSelectionModel *thePatientSelection;
};

#endif // IDATABASE_H
