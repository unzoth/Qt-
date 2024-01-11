#ifndef DOCTOREDIT_H
#define DOCTOREDIT_H

#include <QWidget>
#include <QDataWidgetMapper>

namespace Ui {
class DoctorEdit;
}

class DoctorEdit : public QWidget
{
    Q_OBJECT

public:
    explicit DoctorEdit(QWidget *parent = nullptr,int doc=0);
    ~DoctorEdit();

private slots:
    void on_docSave_clicked();

    void on_docCancel_clicked();

private:
    Ui::DoctorEdit *ui;
    QDataWidgetMapper *dataMapper;
signals:
    void goPreviousView();
};

#endif // DOCTOREDIT_H
