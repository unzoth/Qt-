#ifndef PATIENTEDIT_H
#define PATIENTEDIT_H

#include <QWidget>
#include <QDataWidgetMapper>

namespace Ui {
class PatientEdit;
}

class PatientEdit : public QWidget
{
    Q_OBJECT

public:
    explicit PatientEdit(QWidget *parent = nullptr,int row=0);
    ~PatientEdit();

private slots:
    void on_btSave_clicked();

    void on_btCancel_clicked();

private:
    Ui::PatientEdit *ui;
    QDataWidgetMapper *dataMapper;
signals:
    void goPreviousView();
};

#endif // PATIENTEDIT_H
