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

    QString surname();
    QString name();
    QString father_name();
    QString type();
    QString rank();
    QString position();
    QString date();
    QString gun();
    QString caliber();
    QString count();

private slots:
    void on_buttonBox_rejected();

    void on_buttonBox_accepted();

private:
    Ui::AddSoldierDialog *ui;
};

#endif // ADDSOLDIERDIALOG_H
