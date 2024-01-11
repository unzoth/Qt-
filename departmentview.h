#ifndef DEPARTMENTVIEW_H
#define DEPARTMENTVIEW_H

#include <QWidget>

namespace Ui {
class DepartmentView;
}

class DepartmentView : public QWidget
{
    Q_OBJECT

public:
    explicit DepartmentView(QWidget *parent = nullptr);
    ~DepartmentView();

private slots:
    void on_drupSearch_clicked();

    void on_drupAdd_clicked();

    void on_drupDelete_clicked();

    void on_drupEdit_clicked();
signals:
    void goDepartmentEdit();

private:
    Ui::DepartmentView *ui;
};

#endif // DEPARTMENTVIEW_H
