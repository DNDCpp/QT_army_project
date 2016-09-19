#include "addsoldierdialog.h"
#include "ui_addsoldierdialog.h"

AddSoldierDialog::AddSoldierDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddSoldierDialog)
{
    ui->setupUi(this);
}

AddSoldierDialog::~AddSoldierDialog()
{
    delete ui;
}

QString AddSoldierDialog::surname()
{
    return ui->surname->text();
}

QString AddSoldierDialog::name()
{
    return ui->name->text();
}

QString AddSoldierDialog::father_name()
{
    return ui->father_name->text();
}

QString AddSoldierDialog::type()
{
    return ui->type->text();
}

QString AddSoldierDialog::rank()
{
    return ui->rank->text();
}

QString AddSoldierDialog::position()
{
    return ui->position->text();
}

QString AddSoldierDialog::date()
{
    return ui->date->text();
}

QString AddSoldierDialog::gun()
{
    return ui->gun->text();
}

QString AddSoldierDialog::caliber()
{
    return ui->caliber->text();
}

QString AddSoldierDialog::count()
{
    return ui->count->text();
}

void AddSoldierDialog::on_buttonBox_rejected()
{
    reject();
}

void AddSoldierDialog::on_buttonBox_accepted()
{
    accept();
}
