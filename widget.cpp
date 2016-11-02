#include "widget.h"
#include "ui_widget.h"
#include "addsoldierdialog.h"
#include "addgundialog.h"

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
    connect(ui->pageFour,SIGNAL(clicked(bool)),this, SLOT(setPageFour()));

}

Widget::~Widget()
{
        delete ui;
}

void Widget::initTable()
{
    ui->soldiersTable->insertRow(ui->soldiersTable->rowCount());
    ui->gunTable->insertRow(ui->gunTable->rowCount());
    int row = ui->gunTable->rowCount()-1;
    QDate date(2000, 1, 25);
    ui->soldiersTable->setItem(row, SURNAME, new QTableWidgetItem("Костюк"));
    ui->soldiersTable->setItem(row, NAME, new QTableWidgetItem("Даниил"));
    ui->soldiersTable->setItem(row, FATHERNAME, new QTableWidgetItem("Иванович"));
    ui->soldiersTable->setItem(row, TYPE, new QTableWidgetItem(typeToString(REGULAR)));
    ui->soldiersTable->setItem(row, RANK, new QTableWidgetItem(rankToString(RJADOVOJ)));
    ui->soldiersTable->setItem(row, POSITION, new QTableWidgetItem("хулиган"));
    ui->soldiersTable->setItem(row, DATE, new QTableWidgetItem(dateToString(date)));

    ui->gunTable->setItem(row, G_SURNAME, new QTableWidgetItem("Костюк"));
    ui->gunTable->setItem(row, G_RANK, new QTableWidgetItem(rankToString(RJADOVOJ)));
    ui->gunTable->setItem(row, G_POSITION, new QTableWidgetItem("хулиган"));
    ui->gunTable->setItem(row, GUN, new QTableWidgetItem("автомат"));
    ui->gunTable->setItem(row, CALIBER, new QTableWidgetItem(QString::number(45.00)));
    ui->gunTable->setItem(row, COUNT, new QTableWidgetItem(QString::number(100)));

    //
    ui->soldiersTable->insertRow(ui->soldiersTable->rowCount());
    ui->gunTable->insertRow(ui->gunTable->rowCount());
    row = ui->gunTable->rowCount()-1;
    ui->soldiersTable->setItem(row, SURNAME, new QTableWidgetItem("Нигматуллина"));
    ui->soldiersTable->setItem(row, NAME, new QTableWidgetItem("Дания"));
    ui->soldiersTable->setItem(row, FATHERNAME, new QTableWidgetItem("Фанилевна"));
    ui->soldiersTable->setItem(row, TYPE, new QTableWidgetItem(typeToString(REGULAR)));
    ui->soldiersTable->setItem(row, RANK, new QTableWidgetItem(rankToString(RJADOVOJ)));
    ui->soldiersTable->setItem(row, POSITION, new QTableWidgetItem("боксер"));
    ui->soldiersTable->setItem(row, DATE, new QTableWidgetItem(dateToString(date)));

    ui->gunTable->setItem(row, G_SURNAME, new QTableWidgetItem("Нигматуллина"));
    ui->gunTable->setItem(row, G_RANK, new QTableWidgetItem(rankToString(RJADOVOJ)));
    ui->gunTable->setItem(row, G_POSITION, new QTableWidgetItem("боксер"));
    ui->gunTable->setItem(row, GUN, new QTableWidgetItem("автомат"));
    ui->gunTable->setItem(row, CALIBER, new QTableWidgetItem(QString::number(45.00)));
    ui->gunTable->setItem(row, COUNT, new QTableWidgetItem(QString::number(100)));

}

QString Widget::dateToString(QDate date)
{
    QString dateString;
    if (date.day() < 10)
        dateString = '0';
    dateString.append(QString::number(date.day()) + '.');
    if (date.month() < 10)
        dateString.append('0');
    dateString.append(QString::number(date.month()) + '.');
    if (date.year() < 10)
        dateString.append('0');
    dateString.append(QString::number(date.year()));
    return dateString;
}

QDate Widget::stringToDate(QString string)
{
    QStringList list = string.split('.');
    QDate date;
    date.setDate(list[2].toInt(), list[1].toInt(), list[0].toInt());
    return date;
}

QString Widget::typeToString(int type)
{
    switch (type) {
    case REGULAR:
        return "Срочная";
    case CONTRACT:
        return "Контрактная";
    default:
        break;
    }
}

int Widget::stringToType(QString string)
{
    if (string == "Срочная")
        return REGULAR;
    if (string == "Контрактная")
        return CONTRACT;
}

QString Widget::rankToString(int rank)
{
    switch (rank) {
    case RJADOVOJ:
        return "Рядовой (курсант)";
    case EFREJTOR:
        return "Ефрейтор";
    case ML_SERZHANT:
        return "Младший сержант";
    case SERZHANT:
        return "Сержант";
    case ST_SERZHANT:
        return "Старший сержант";
    case STARSHINA:
        return "Старшина";
    case PRAPORSHHIK:
        return "Прапорщик";
    case ST_PRAPORSHHIK:
        return "Старший прапорщик";
    case ML_LEJTENANT:
        return "Младший лейтенант";
    case LEJTENANT:
        return "Лейтенант";
    case ST_LEJTENANT:
        return "Старший лейтенант";
    case KAPITAN:
        return "Капитан";
    case MAJOR:
        return "Майор";
    case PODPOLKOVNIK:
        return "Подполковник";
    case POLKOVNIK:
        return "Полковник";
    case GENERAL_MAJOR:
        return "Генерал-майор";
    case GENERAL_LEJTENANT:
        return "Генерал-лейтенант";
    case GENERAL_POLKOVNIK:
        return "Генерал-полковник";
    case GENERAL_ARMII:
        return "Генерал армии";
    case MARSHAL_RF:
        return "Маршал Российской Федерации";
    default:
        break;
    }
}

int Widget::stringToRank(QString string)
{
    if (string == "Рядовой (курсант)")
        return RJADOVOJ;
    if (string == "Ефрейтор")
        return EFREJTOR;
    if (string == "Младший сержант")
        return ML_SERZHANT;
    if (string == "Сержант")
        return SERZHANT;
    if (string == "Старший сержант")
        return ST_SERZHANT;
    if (string == "Старшина")
        return STARSHINA;
    if (string == "Прапорщик")
        return PRAPORSHHIK;
    if (string == "Старший прапорщик")
        return ST_PRAPORSHHIK;
    if (string == "Младший лейтенант")
        return ML_LEJTENANT;
    if (string == "Лейтенант")
        return LEJTENANT;
    if (string == "Старший лейтенант")
        return ST_LEJTENANT;
    if (string == "Капитан")
        return KAPITAN;
    if (string == "Майор")
        return MAJOR;
    if (string == "Подполковник")
        return PODPOLKOVNIK;
    if (string == "Полковник")
        return POLKOVNIK;
    if (string == "Генерал-майор")
        return GENERAL_MAJOR;
    if (string == "Генерал-лейтенант")
        return GENERAL_LEJTENANT;
    if (string == "Генерал-полковник")
        return GENERAL_POLKOVNIK;
    if (string == "Генерал армии")
        return GENERAL_ARMII;
    if (string == "Маршал Российской Федерации")
        return MARSHAL_RF;
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

void Widget::setPageFour(){
    ui->stackedWidget->setCurrentIndex(3);
}


void Widget::on_stackedWidget_currentChanged(int arg1)
{
    // Set all buttons to false
    ui->pageOne->setProperty("pagematches", false);
    ui->pageTwo->setProperty("pagematches", false);
    ui->pageThree->setProperty("pagematches", false);
     ui->pageFour->setProperty("pagematches", false);

    // Set one of the buttons to true
    if (arg1 == 0)
        ui->pageOne->setProperty("pagematches", true);
    else if (arg1 == 1)
        ui->pageTwo->setProperty("pagematches", true);
    else if (arg1 == 3)
        ui->pageFour->setProperty("pagematches", true);
    else
        ui->pageThree->setProperty("pagematches", true);

    // Update buttons style
    ui->pageOne->style()->polish(ui->pageOne);
    ui->pageTwo->style()->polish(ui->pageTwo);
    ui->pageThree->style()->polish(ui->pageThree);
    ui->pageFour->style()->polish(ui->pageFour);
}


// Page One buttons slots

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
    int type = dialog->type();
    int rank = dialog->rank();
    QString position = dialog->position();
    QDate date = dialog->date();
    QString gun = dialog->gun();
    int caliber = dialog->caliber();
    int count = dialog->count();

    //add to soldier table
    ui->soldiersTable->insertRow(ui->soldiersTable->rowCount());
    int row = ui->soldiersTable->rowCount()-1;

    ui->soldiersTable->setItem(row, SURNAME, new QTableWidgetItem(surname));
    ui->soldiersTable->setItem(row, NAME, new QTableWidgetItem(name));
    ui->soldiersTable->setItem(row, FATHERNAME, new QTableWidgetItem(father_name));
    ui->soldiersTable->setItem(row, TYPE, new QTableWidgetItem(typeToString(type)));
    ui->soldiersTable->setItem(row, RANK, new QTableWidgetItem(rankToString(rank)));
    ui->soldiersTable->setItem(row, POSITION, new QTableWidgetItem(position));
    ui->soldiersTable->setItem(row, DATE, new QTableWidgetItem(dateToString(date)));

    //add to gun table

    ui->gunTable->insertRow(ui->gunTable->rowCount());
    int row2 = ui->gunTable->rowCount()-1;

    ui->gunTable->setItem(row2, G_SURNAME, new QTableWidgetItem(surname));
    ui->gunTable->setItem(row2, G_RANK, new QTableWidgetItem(rankToString(rank)));
    ui->gunTable->setItem(row2, G_POSITION, new QTableWidgetItem(position));
    ui->gunTable->setItem(row2, GUN, new QTableWidgetItem(gun));
    ui->gunTable->setItem(row2, CALIBER, new QTableWidgetItem(QString::number(caliber)));
    ui->gunTable->setItem(row2, COUNT, new QTableWidgetItem(QString::number(count)));

    delete dialog;
}

void Widget::on_buttonDelete_clicked()
{
    QItemSelectionModel *itemModel = ui->soldiersTable->selectionModel();
    QModelIndexList indexList = itemModel->selectedRows();
    if (!indexList.isEmpty())
    {
        QMessageBox box;
        box.setText("Удалить?");
        box.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        box.setDefaultButton(QMessageBox::Cancel);
        int res = box.exec();
        if (res == QMessageBox::Ok)
        {
            qSort(indexList.begin(), indexList.end(), qGreater<QModelIndex>());

            for (QModelIndex row : indexList) {
                ui->soldiersTable->removeRow(row.row());
            }
        }
        else
            return;
    }
}

void Widget::on_buttonDeleteAll_clicked()
{
    QMessageBox box;
    box.setText("Удалить все?");
    box.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    box.setDefaultButton(QMessageBox::Cancel);
    int res = box.exec();
    if (res == QMessageBox::Ok)
        ui->soldiersTable->setRowCount(0);
    else
        return;
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
    dialog->setType(stringToType(ui->soldiersTable->item(row, TYPE)->text()));
    dialog->setRank(stringToRank(ui->soldiersTable->item(row, RANK)->text()));
    dialog->setPosition(ui->soldiersTable->item(row, POSITION)->text());
    dialog->setDate(stringToDate(ui->soldiersTable->item(row, DATE)->text()));
//    dialog->setGun(ui->soldiersTable->item(row, GUN)->text());
//    dialog->setCaliber(ui->soldiersTable->item(row, CALIBER)->text().toDouble());
//    dialog->setCount(ui->soldiersTable->item(row, COUNT)->text().toInt());

    int res = dialog->exec();
    if (res == QDialog::Rejected)
    {
        delete dialog;
        return;
    }

    ui->soldiersTable->item(row, SURNAME)->setText(dialog->surname());
    ui->soldiersTable->item(row, NAME)->setText(dialog->name());
    ui->soldiersTable->item(row, FATHERNAME)->setText(dialog->father_name());
    ui->soldiersTable->item(row, TYPE)->setText(typeToString(dialog->type()));
    ui->soldiersTable->item(row, RANK)->setText(rankToString(dialog->rank()));
    ui->soldiersTable->item(row, POSITION)->setText(dialog->position());
    ui->soldiersTable->item(row, DATE)->setText(dateToString(dialog->date()));
//    ui->soldiersTable->item(row, GUN)->setText(dialog->gun());
//    ui->soldiersTable->item(row, CALIBER)->setText(QString::number(dialog->caliber()));
//    ui->soldiersTable->item(row, COUNT)->setText(QString::number(dialog->count()));

    delete dialog;
}

// Page Two buttons slots

void Widget::on_buttonAddGun_clicked()
{
    QItemSelectionModel *itemModel = ui->gunTable->selectionModel();
    if (itemModel->selectedRows().count() != 1) return;
    int row = itemModel->selectedRows()[0].row();

    addGunDialog *dialog = new addGunDialog;

    int res = dialog->exec();
    if (res == QDialog::Rejected)
    {
        delete dialog;
        return;
    }

    ui->gunTable->insertRow(ui->gunTable->rowCount());
    int new_row = ui->gunTable->rowCount()-1;

    ui->gunTable->setItem(new_row, G_SURNAME, new QTableWidgetItem(ui->gunTable->item(row, 0)->text()));
    ui->gunTable->setItem(new_row, G_RANK, new QTableWidgetItem(ui->gunTable->item(row, 1)->text()));
    ui->gunTable->setItem(new_row, G_POSITION, new QTableWidgetItem(ui->gunTable->item(row, 2)->text()));
    ui->gunTable->setItem(new_row, GUN, new QTableWidgetItem(dialog->gun()));
    ui->gunTable->setItem(new_row, CALIBER, new QTableWidgetItem(QString::number(dialog->caliber())));
    ui->gunTable->setItem(new_row, COUNT, new QTableWidgetItem(QString::number(dialog->count())));

    delete dialog;
}

void Widget::on_buttonEditGun_clicked()
{
    QItemSelectionModel *itemModel = ui->gunTable->selectionModel();
    if (itemModel->selectedRows().count() != 1) return;
    int row = itemModel->selectedRows()[0].row();

    addGunDialog *dialog = new addGunDialog;

    dialog->setGun(ui->gunTable->item(row, GUN)->text());
    dialog->setCaliber(ui->gunTable->item(row, CALIBER)->text().toDouble());
    dialog->setCount(ui->gunTable->item(row, COUNT)->text().toInt());

    int res = dialog->exec();
    if (res == QDialog::Rejected)
    {
        delete dialog;
        return;
    }

    ui->gunTable->item(row, GUN)->setText(dialog->gun());
    ui->gunTable->item(row, CALIBER)->setText(QString::number(dialog->caliber()));
    ui->gunTable->item(row, COUNT)->setText(QString::number(dialog->count()));

    delete dialog;
}

void Widget::on_buttonDeleteGun_clicked()
{
    QItemSelectionModel *itemModel = ui->gunTable->selectionModel();
    QModelIndexList indexList = itemModel->selectedRows();
    if (!indexList.isEmpty())
    {
        QMessageBox box;
        box.setText("Удалить?");
        box.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        box.setDefaultButton(QMessageBox::Cancel);
        int res = box.exec();
        if (res == QMessageBox::Ok)
        {
            qSort(indexList.begin(), indexList.end(), qGreater<QModelIndex>());

            for (QModelIndex row : indexList) {
                ui->gunTable->removeRow(row.row());
            }
        }
        else
            return;
    }
}

void Widget::on_buttonDeleteAllGun_clicked()
{
    QMessageBox box;
    box.setText("Удалить все?");
    box.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    box.setDefaultButton(QMessageBox::Cancel);
    int res = box.exec();
    if (res == QMessageBox::Ok)
        ui->gunTable->setRowCount(0);
    else
        return;
}
