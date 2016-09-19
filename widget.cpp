#include "widget.h"
#include "ui_widget.h"
#include "addsoldierdialog.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    initTable();

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
//    ui->soldiersTable->insertRow(ui->soldiersTable->rowCount());
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
        return;

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
    int column = 0;
    ui->soldiersTable->setItem(row, column, new QTableWidgetItem(surname));
    column++;
    ui->soldiersTable->setItem(row, column, new QTableWidgetItem(name));
    column++;
    ui->soldiersTable->setItem(row, column, new QTableWidgetItem(father_name));
    column++;
    ui->soldiersTable->setItem(row, column, new QTableWidgetItem(type));
    column++;
    ui->soldiersTable->setItem(row, column, new QTableWidgetItem(rank));
    column++;
    ui->soldiersTable->setItem(row, column, new QTableWidgetItem(position));
    column++;
    ui->soldiersTable->setItem(row, column, new QTableWidgetItem(date));
    column++;
    ui->soldiersTable->setItem(row, column, new QTableWidgetItem(gun));
    column++;
    ui->soldiersTable->setItem(row, column, new QTableWidgetItem(caliber));
    column++;
    ui->soldiersTable->setItem(row, column, new QTableWidgetItem(count));
    column++;

}

void Widget::on_buttonDelete_clicked()
{
    QItemSelectionModel *itemModel = ui->soldiersTable->selectionModel();
    QModelIndexList indexList = itemModel->selectedRows();
    qSort(indexList.begin(), indexList.end(), qGreater<QModelIndex>());

    foreach (QModelIndex row, indexList) {
        ui->soldiersTable->removeRow(row.row());
    }
}

void Widget::on_buttonDeleteAll_clicked()
{
    ui->soldiersTable->setRowCount(0);
}
