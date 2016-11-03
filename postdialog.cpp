#include "postdialog.h"
#include "ui_postdialog.h"

PostDialog::PostDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PostDialog)
{
    ui->setupUi(this);
}

PostDialog::~PostDialog()
{
    delete ui;
}

QString PostDialog::postType()
{
    return ui->postType->currentText();
}

int PostDialog::duration()
{
    return ui->duration->value();
}

void PostDialog::setPostType(QString type)
{
//
}

void PostDialog::setDuration(int days)
{
    ui->duration->setValue(days);
}

void PostDialog::on_buttonBox_accepted()
{
    accept();
}

void PostDialog::on_buttonBox_rejected()
{
    reject();
}
