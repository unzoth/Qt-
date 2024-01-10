#include "masterview.h"
#include "ui_masterview.h"
#include "idatabase.h"

MasterView::MasterView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MasterView)
{
    ui->setupUi(this);
    goLoginView();
    IDatabase::getInstance();
}

MasterView::~MasterView()
{
    delete ui;
}

void MasterView::goLoginView()
{
    loginview=new LoginView(this);
    pushWidgetToStackView(loginview);
    connect(loginview,SIGNAL(logSuccess()),this,SLOT(goWelcomeView()));
}

void MasterView::goWelcomeView()
{
    welcomeview=new WelcomeView(this);
    pushWidgetToStackView(welcomeview);
    connect(welcomeview,SIGNAL(goDepartmentView()),this,SLOT(goDepartmentView()));
    connect(welcomeview,SIGNAL(goDoctorView()),this,SLOT(goDoctorView()));
    connect(welcomeview,SIGNAL(goPatientView()),this,SLOT(goPatientView()));
    connect(welcomeview,SIGNAL(goRecordView()),this,SLOT(goRecordView()));
}

void MasterView::goDoctorEdit(int doc)
{
    doctoredit=new DoctorEdit(this,doc);
    pushWidgetToStackView(doctoredit);
    connect(doctoredit,SIGNAL(goPreviousView()),this,SLOT(goPreviousView()));
}

void MasterView::goDoctorView()
{
    doctorview=new DoctorView(this);
    pushWidgetToStackView(doctorview);
}

void MasterView::goDepartmentEdit(int dep)
{
    departmentedit=new DepartmentEdit(this,dep);
    pushWidgetToStackView(departmentedit);
    connect(departmentedit,SIGNAL(goPreviousView()),this,SLOT(goPreviousView()));
}

void MasterView::goDepartmentView()
{
    departmentview=new DepartmentView(this);
    pushWidgetToStackView(departmentview);
}

void MasterView::goPatientEdit(int row)
{
    patientedit=new PatientEdit(this,row);
    pushWidgetToStackView(patientedit);
    connect(patientedit,SIGNAL(goPreviousView()),this,SLOT(goPreviousView()));
}

void MasterView::goPatientView()
{
    patientview=new PatientView(this);
    pushWidgetToStackView(patientview);
    connect(patientview,SIGNAL(goPatientEdit(int)),this,SLOT(goPatientEdit(int)));
}

void MasterView::goRecordEdit(int rec)
{
    recordedit=new RecordEdit(this,rec);
    pushWidgetToStackView(recordedit);
    connect(recordedit,SIGNAL(goPreviousView()),this,SLOT(goPreviousView()));
}

void MasterView::goRecordView()
{
    recordview=new RecordView(this);
    pushWidgetToStackView(recordview);
    connect(recordview,SIGNAL(goRecordEdit(int)),this,SLOT(goRecordEdit(int)));
}

void MasterView::goPreviousView()
{
    int count=ui->stackedWidget->count();
    if(count>1){
        ui->stackedWidget->setCurrentIndex(count-2);
        ui->labelTitle->setText(ui->stackedWidget->currentWidget()->windowTitle());
        QWidget *widget=ui->stackedWidget->widget(count-1);
        ui->stackedWidget->removeWidget(widget);
        delete widget;
    }
}

void MasterView::pushWidgetToStackView(QWidget *widget)
{
    ui->stackedWidget->addWidget(widget);
    int count=ui->stackedWidget->count();
    ui->stackedWidget->setCurrentIndex(count-1);
    ui->labelTitle->setText(widget->windowTitle());
}


void MasterView::on_btBack_clicked()
{
    goPreviousView();
}


void MasterView::on_stackedWidget_currentChanged()
{
    int count=ui->stackedWidget->count();
    if(count>1)
        ui->btBack->setEnabled(true);
    else
        ui->btBack->setEnabled(false);
    QString title=ui->stackedWidget->currentWidget()->windowTitle();
    if(title=="欢迎"){
        ui->btLogout->setEnabled(true);
        ui->btBack->setEnabled(false);
    }
    else
        ui->btLogout->setEnabled(false);
}


void MasterView::on_btLogout_clicked()
{
    goPreviousView();
    ui->btBack->setEnabled(false);
}

