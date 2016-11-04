#include "postdialog.h"
#include "ui_postdialog.h"

PostDialog::PostDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PostDialog)
{
    ui->setupUi(this);
    ui->punktLayout->setEnabled(false);
}

PostDialog::~PostDialog()
{
    delete ui;
}

int PostDialog::postType()
{
    return ui->postType->currentIndex();
}

int PostDialog::duration()
{
    return ui->duration->value();
}

int PostDialog::punktNumber()
{
    return ui->punktNumber->value();
}

void PostDialog::setPostType(int type)
{
    ui->postType->setCurrentIndex(type);
}

void PostDialog::setDuration(int days)
{
    ui->duration->setValue(days);
}

void PostDialog::setPunktNumber(int punkt)
{
    ui->punktNumber->setValue(punkt);
}

QString PostDialog::shortType(int currentIndex, int punkt)
{
    QStringList list;
    list << "Б" << "О" << "ДБ" << "ПДБ" << "ПАТ" << "ДР" << "ВАИ" << "НК" << "ПНК"
         << "ДКПП" << "ПКПП" << "КПП" << "ДС" << "ПДС" << "КУМ" << "КПР" << "ВКС" << "К";
    if (punkt > 0)
        return list[currentIndex] + QString::number(punkt);
    else
        return list[currentIndex];
}

void PostDialog::on_buttonBox_accepted()
{
    accept();
}

void PostDialog::on_buttonBox_rejected()
{
    reject();
}

void PostDialog::on_postType_currentIndexChanged(const QString &arg1)
{
    if ((arg1 == "Дежурный по контрольно-пропускному пункту") || (arg1 == "Помощник дежурного по контрольно-пропускному пункту"))
    {
        ui->punktLayout->setEnabled(true);
    }
    else
        ui->punktLayout->setEnabled(false);
}
