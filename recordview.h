#ifndef RECORDVIEW_H
#define RECORDVIEW_H

#include <QWidget>

namespace Ui {
class RecordView;
}

class RecordView : public QWidget
{
    Q_OBJECT

public:
    explicit RecordView(QWidget *parent = nullptr);
    ~RecordView();

private slots:
    void on_recSearch_clicked();

    void on_recAdd_clicked();

    void on_recDelete_clicked();

    void on_recEdit_clicked();

private:
    Ui::RecordView *ui;
};

#endif // RECORDVIEW_H
