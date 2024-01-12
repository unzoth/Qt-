#include "loginview.h"
#include "ui_loginview.h"
#include "idatabase.h"

LoginView::LoginView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginView)
{
    ui->setupUi(this);
}

LoginView::~LoginView()
{
    delete ui;
}

void LoginView::on_btLog_clicked()
{
    QString status=IDatabase::getInstance().userLogin(ui->textID->text(),ui->textPW->text());
    if(status=="admin")
        emit logSuccess(1);
    else if(status=="doctor")
        emit logSuccess(2);
}

