#ifndef MASTERVIEW_H
#define MASTERVIEW_H

#include <QWidget>
#include "departmentedit.h"
#include "departmentview.h"
#include "doctoredit.h"
#include "doctorview.h"
#include "loginview.h"
#include "patientedit.h"
#include "patientview.h"
#include "recordedit.h"
#include "recordview.h"
#include "welcomeview.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MasterView; }
QT_END_NAMESPACE

class MasterView : public QWidget
{
    Q_OBJECT

public:
    MasterView(QWidget *parent = nullptr);
    ~MasterView();

public slots:
    void goLoginView();
    void onLoginSuccess(int tap);
    void goWelcomeView(int tap);
    void goDoctorEdit(int doc);
    void goDoctorView();
    void goDepartmentEdit(int dep);
    void goDepartmentView();
    void goPatientEdit(int row);
    void goPatientView();
    void goRecordEdit(int rec);
    void goRecordView();
    void goPreviousView();

private slots:
    void on_btBack_clicked();

    void on_stackedWidget_currentChanged();

    void on_btLogout_clicked();

private:
    void pushWidgetToStackView(QWidget *widget);

    Ui::MasterView *ui;

    DepartmentEdit *departmentedit;
    DepartmentView *departmentview;
    DoctorEdit *doctoredit;
    DoctorView *doctorview;
    LoginView *loginview;
    PatientEdit *patientedit;
    PatientView *patientview;
    RecordEdit *recordedit;
    RecordView *recordview;
    WelcomeView *welcomeview;
};
#endif // MASTERVIEW_H
