#ifndef ADDGUNDIALOG_H
#define ADDGUNDIALOG_H

#include <QDialog>

namespace Ui {
class addGunDialog;
}

class addGunDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addGunDialog(QWidget *parent = 0);
    ~addGunDialog();

    QString gun();
    double caliber();
    int count();

    void setGun(QString string);
    void setCaliber(double caliber);
    void setCount(int count);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::addGunDialog *ui;
};

#endif // ADDGUNDIALOG_H
