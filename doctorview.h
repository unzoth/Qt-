#ifndef DOCTORVIEW_H
#define DOCTORVIEW_H

#include <QWidget>

namespace Ui {
class DoctorView;
}

class DoctorView : public QWidget
{
    Q_OBJECT

public:
    explicit DoctorView(QWidget *parent = nullptr);
    ~DoctorView();

private slots:
    void on_docSearch_clicked();

    void on_docAdd_clicked();

    void on_docDelete_clicked();

    void on_docEdit_clicked();
signals:
    void goDoctorEdit(int doc);

private:
    Ui::DoctorView *ui;
};

#endif // DOCTORVIEW_H
