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

int AddSoldierDialog::type()
{
    return ui->type->currentIndex();
}

int AddSoldierDialog::rank()
{
    return ui->rank->currentIndex();
}

QString AddSoldierDialog::position()
{
    return ui->position->text();
}

QDate AddSoldierDialog::date()
{
    return ui->date->date();
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

void AddSoldierDialog::setType(int typeIndex)
{
    ui->type->setCurrentIndex(typeIndex);
}

void AddSoldierDialog::setRank(int rankIndex)
{
    ui->rank->setCurrentIndex(rankIndex);
}

void AddSoldierDialog::setPosition(QString string)
{
    ui->position->setText(string);
}

void AddSoldierDialog::setDate(QDate date)
{
    ui->date->setDate(date);
}

void AddSoldierDialog::on_buttonBox_rejected()
{
    reject();
}

void AddSoldierDialog::on_buttonBox_accepted()
{
    accept();
}
