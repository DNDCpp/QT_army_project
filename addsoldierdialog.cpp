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

void AddSoldierDialog::setSurname(QString string)
{
    ui->surname->setText(string);
}

void AddSoldierDialog::setName(QString string)
{
    ui->name->setText(string);
}

void AddSoldierDialog::setFather_name(QString string)
{
    ui->father_name->setText(string);
}

void AddSoldierDialog::setType(QString string)
{
    ui->type->setText(string);
}

void AddSoldierDialog::setRank(QString string)
{
    ui->rank->setText(string);
}

void AddSoldierDialog::setPosition(QString string)
{
    ui->position->setText(string);
}

void AddSoldierDialog::setDate(QString string)
{
    ui->date->setText(string);
}

void AddSoldierDialog::setGun(QString string)
{
    ui->gun->setText(string);
}

void AddSoldierDialog::setCaliber(QString string)
{
    ui->caliber->setText(string);
}

void AddSoldierDialog::setCount(QString string)
{
    ui->count->setText(string);
}

void AddSoldierDialog::on_buttonBox_rejected()
{
    reject();
}

void AddSoldierDialog::on_buttonBox_accepted()
{
    accept();
}
