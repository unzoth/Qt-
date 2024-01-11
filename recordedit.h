#ifndef RECORDEDIT_H
#define RECORDEDIT_H

#include <QWidget>
#include <QDataWidgetMapper>

namespace Ui {
class RecordEdit;
}

class RecordEdit : public QWidget
{
    Q_OBJECT

public:
    explicit RecordEdit(QWidget *parent = nullptr,int rec=0);
    ~RecordEdit();

private slots:
    void on_recSave_clicked();

    void on_recCancel_clicked();

private:
    Ui::RecordEdit *ui;
    QDataWidgetMapper *dataMapper;
signals:
    void goPreviousView();
};

#endif // RECORDEDIT_H
