#ifndef DEPARTMENTEDIT_H
#define DEPARTMENTEDIT_H

#include <QWidget>

namespace Ui {
class DepartmentEdit;
}

class DepartmentEdit : public QWidget
{
    Q_OBJECT

public:
    explicit DepartmentEdit(QWidget *parent = nullptr);
    ~DepartmentEdit();

private:
    Ui::DepartmentEdit *ui;
};

#endif // DEPARTMENTEDIT_H
