#include "widget.h"
#include "ui_widget.h"
#include "addsoldierdialog.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    initTable();
    //comment

    ui->stackedWidget->setCurrentIndex(0);
    ui->pageOne->setProperty("pagematches", true);

    connect(ui->pageOne,SIGNAL(clicked(bool)),this, SLOT(setPageOne()));
    connect(ui->pageTwo,SIGNAL(clicked(bool)),this, SLOT(setPageTwo()));
    connect(ui->pageThree,SIGNAL(clicked(bool)),this, SLOT(setPageThree()));

}

Widget::~Widget()
{
    //    delete ui;
}

void Widget::initTable()
{
    for (int i=0; i<10; i++)
    {
        ui->soldiersTable->insertRow(ui->soldiersTable->rowCount());
        for (int j=0; j<ui->soldiersTable->columnCount(); j++)
        {
            ui->soldiersTable->setItem(i, j, new QTableWidgetItem(QString::number(i+j)));
        }
    }
}

void Widget::setPageOne(){
    ui->stackedWidget->setCurrentIndex(0);
}
void Widget::setPageTwo(){
    ui->stackedWidget->setCurrentIndex(1);
}
void Widget::setPageThree(){
    ui->stackedWidget->setCurrentIndex(2);
}


void Widget::on_stackedWidget_currentChanged(int arg1)
{
// Set all buttons to false
ui->pageOne->setProperty("pagematches", false);
ui->pageTwo->setProperty("pagematches", false);
ui->pageThree->setProperty("pagematches", false);
// Set one of the buttons to true
if (arg1 == 0)
ui->pageOne->setProperty("pagematches", true);
else if (arg1 == 1)
ui->pageTwo->setProperty("pagematches", true);
else
ui->pageThree->setProperty("pagematches", true);
// Update buttons style
ui->pageOne->style()->polish(ui->pageOne);
ui->pageTwo->style()->polish(ui->pageTwo);
ui->pageThree->style()->polish(ui->pageThree);
}


void Widget::on_buttonAdd_clicked()
{
    AddSoldierDialog *dialog = new AddSoldierDialog;
    int res = dialog->exec();
    if (res == QDialog::Rejected)
    {
        delete dialog;
        return;
    }

    QString surname = dialog->surname();
    QString name = dialog->name();
    QString father_name = dialog->father_name();
    QString type = dialog->type();
    QString rank = dialog->rank();
    QString position = dialog->position();
    QString date = dialog->date();
    QString gun = dialog->gun();
    QString caliber = dialog->caliber();
    QString count = dialog->count();

    ui->soldiersTable->insertRow(ui->soldiersTable->rowCount());
    int row = ui->soldiersTable->rowCount()-1;

    ui->soldiersTable->setItem(row, SURNAME, new QTableWidgetItem(surname));
    ui->soldiersTable->setItem(row, NAME, new QTableWidgetItem(name));
    ui->soldiersTable->setItem(row, FATHERNAME, new QTableWidgetItem(father_name));
    ui->soldiersTable->setItem(row, TYPE, new QTableWidgetItem(type));
    ui->soldiersTable->setItem(row, RANK, new QTableWidgetItem(rank));
    ui->soldiersTable->setItem(row, POSITION, new QTableWidgetItem(position));
    ui->soldiersTable->setItem(row, DATE, new QTableWidgetItem(date));
    ui->soldiersTable->setItem(row, GUN, new QTableWidgetItem(gun));
    ui->soldiersTable->setItem(row, CALIBER, new QTableWidgetItem(caliber));
    ui->soldiersTable->setItem(row, COUNT, new QTableWidgetItem(count));

    delete dialog;
}

void Widget::on_buttonDelete_clicked()
{
    QItemSelectionModel *itemModel = ui->soldiersTable->selectionModel();
    QModelIndexList indexList = itemModel->selectedRows();
    qSort(indexList.begin(), indexList.end(), qGreater<QModelIndex>());

    for (QModelIndex row : indexList) {
        ui->soldiersTable->removeRow(row.row());
    }
}

void Widget::on_buttonDeleteAll_clicked()
{
    ui->soldiersTable->setRowCount(0);
}

void Widget::on_buttonEdit_clicked()
{

    QItemSelectionModel *itemModel = ui->soldiersTable->selectionModel();
    if (itemModel->selectedRows().count() != 1) return;
    int row = itemModel->selectedRows()[0].row();

    AddSoldierDialog *dialog = new AddSoldierDialog;

    dialog->setSurname(ui->soldiersTable->item(row, SURNAME)->text());
    dialog->setName(ui->soldiersTable->item(row, NAME)->text());
    dialog->setFather_name(ui->soldiersTable->item(row, FATHERNAME)->text());
    dialog->setType(ui->soldiersTable->item(row, TYPE)->text());
    dialog->setRank(ui->soldiersTable->item(row, RANK)->text());
    dialog->setPosition(ui->soldiersTable->item(row, POSITION)->text());
    dialog->setDate(ui->soldiersTable->item(row, DATE)->text());
    dialog->setGun(ui->soldiersTable->item(row, GUN)->text());
    dialog->setCaliber(ui->soldiersTable->item(row, CALIBER)->text());
    dialog->setCount(ui->soldiersTable->item(row, COUNT)->text());

    int res = dialog->exec();
    if (res == QDialog::Rejected)
    {
        delete dialog;
        return;
    }

    ui->soldiersTable->item(row, SURNAME)->setText(dialog->surname());
    ui->soldiersTable->item(row, NAME)->setText(dialog->name());
    ui->soldiersTable->item(row, FATHERNAME)->setText(dialog->father_name());
    ui->soldiersTable->item(row, TYPE)->setText(dialog->type());
    ui->soldiersTable->item(row, RANK)->setText(dialog->rank());
    ui->soldiersTable->item(row, POSITION)->setText(dialog->position());
    ui->soldiersTable->item(row, DATE)->setText(dialog->date());
    ui->soldiersTable->item(row, GUN)->setText(dialog->gun());
    ui->soldiersTable->item(row, CALIBER)->setText(dialog->caliber());
    ui->soldiersTable->item(row, COUNT)->setText(dialog->count());

    delete dialog;
}









