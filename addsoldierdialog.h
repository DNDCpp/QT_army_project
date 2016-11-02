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
    int type();
    int rank();
    QString position();
    QDate date();

    void setSurname(QString string);
    void setName(QString string);
    void setFather_name(QString string);
    void setType(int typeIndex);
    void setRank(int rankIndex);
    void setPosition(QString string);
    void setDate(QDate date);


private slots:
    void on_buttonBox_rejected();

    void on_buttonBox_accepted();

private:
    Ui::AddSoldierDialog *ui;
};

#endif // ADDSOLDIERDIALOG_H
