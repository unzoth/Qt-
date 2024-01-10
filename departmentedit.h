#ifndef DEPARTMENTEDIT_H
#define DEPARTMENTEDIT_H

#include <QWidget>
#include <QDataWidgetMapper>

namespace Ui {
class DepartmentEdit;
}

class DepartmentEdit : public QWidget
{
    Q_OBJECT

public:
    explicit DepartmentEdit(QWidget *parent = nullptr,int dep=0);
    ~DepartmentEdit();

private slots:
    void on_drupSave_clicked();

    void on_drupCancel_clicked();

private:
    Ui::DepartmentEdit *ui;
};

#endif // DEPARTMENTEDIT_H
