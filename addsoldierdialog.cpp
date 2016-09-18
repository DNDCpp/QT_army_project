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
