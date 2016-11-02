#include "addgundialog.h"
#include "ui_addgundialog.h"

addGunDialog::addGunDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addGunDialog)
{
    ui->setupUi(this);
}

addGunDialog::~addGunDialog()
{
    delete ui;
}

QString addGunDialog::gun()
{
    return ui->gun->text();
}

double addGunDialog::caliber()
{
    return ui->caliber->value();
}

int addGunDialog::count()
{
    return ui->count->value();
}

void addGunDialog::setGun(QString string)
{
    ui->gun->setText(string);
}

void addGunDialog::setCaliber(double caliber)
{
    ui->caliber->setValue(caliber);
}

void addGunDialog::setCount(int count)
{
    ui->count->setValue(count);
}

void addGunDialog::on_buttonBox_accepted()
{
    accept();
}

void addGunDialog::on_buttonBox_rejected()
{
    reject();
}
