#ifndef ADDSOLDIERDIALOG_H
#define ADDSOLDIERDIALOG_H

#include <QDialog>

namespace Ui {
class AddSoldierDialog;
}

class AddSoldierDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddSoldierDialog(QWidget *parent = 0);
    ~AddSoldierDialog();

private:
    Ui::AddSoldierDialog *ui;
};

#endif // ADDSOLDIERDIALOG_H
