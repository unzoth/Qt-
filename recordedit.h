#ifndef RECORDEDIT_H
#define RECORDEDIT_H

#include <QWidget>

namespace Ui {
class RecordEdit;
}

class RecordEdit : public QWidget
{
    Q_OBJECT

public:
    explicit RecordEdit(QWidget *parent = nullptr);
    ~RecordEdit();

private:
    Ui::RecordEdit *ui;
};

#endif // RECORDEDIT_H
