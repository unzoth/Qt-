#ifndef MASTERVIEW_H
#define MASTERVIEW_H

#include <QWidget>
#include "departmentview.h"
#include "doctorview.h"
#include "loginview.h"
#include "patientedit.h"
#include "patientview.h"
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
    void goWelcomeView();
    void goDoctorView();
    void goDepartmentView();
    void goPatientEdit(int row);
    void goPatientView();
    void goPreviousView();

private slots:
    void on_btBack_clicked();

    void on_stackedWidget_currentChanged(int arg1);

    void on_btLogout_clicked();

private:
    void pushWidgetToStackView(QWidget *widget);

    Ui::MasterView *ui;

    DepartmentView *departmentview;
    DoctorView *doctorview;
    LoginView *loginview;
    PatientEdit *patientedit;
    PatientView *patientview;
    WelcomeView *welcomeview;
};
#endif // MASTERVIEW_H
