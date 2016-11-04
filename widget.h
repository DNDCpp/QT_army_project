#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMessageBox>
#include <QDate>
#include <QDebug>
#include <QPair>
#include <QStringList>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    void initTable();
    QString dateToString(QDate date);
    QDate stringToDate(QString string);
    QString typeToString(int type);
    int stringToType(QString string);
    QString rankToString(int rank);
    int stringToRank(QString string);
    void addRowToSoldierTable(QString surname, QString name, QString father_name,
                              int type, int rank, QString position, QDate date);
    void addRowToGunTable(QString surname, int rank, QString position,
                          QString gun = 0, double caliber = 0, int count = 0 );
    void editSoldierTableRow(int row, QString surname, QString name, QString father_name,
                             int type, int rank, QString position, QDate date);
    void editGunTableRow(int row, QString gun, double caliber, int count);
    void setCurrentWeek();
    void displayWeekLabel();
    void initScheduleTable();
    QDate getDateFromCell(int col);

private:
    Ui::Widget *ui;

    enum Soldier_Column {
        SURNAME, NAME, FATHERNAME, TYPE, RANK, POSITION, DATE
    };
    enum Types {
        REGULAR, CONTRACT
    };
    enum Ranks {
        RJADOVOJ, EFREJTOR,
        ML_SERZHANT, SERZHANT, ST_SERZHANT, STARSHINA,
        PRAPORSHHIK, ST_PRAPORSHHIK,
        ML_LEJTENANT, LEJTENANT, ST_LEJTENANT, KAPITAN,
        MAJOR, PODPOLKOVNIK, POLKOVNIK,
        GENERAL_MAJOR, GENERAL_LEJTENANT, GENERAL_POLKOVNIK, GENERAL_ARMII, MARSHAL_RF
    };

    enum Gun_Column {
        G_SURNAME, G_RANK, G_POSITION, GUN, CALIBER, COUNT
    };

    QPair <QDate, QDate> currentWeek;

public slots:
    void setPageOne();
    void setPageTwo();
    void setPageThree();
    void setPageFour();

private slots:
    void on_stackedWidget_currentChanged(int arg1);
    void on_buttonAdd_clicked();
    void on_buttonDelete_clicked();
    void on_buttonDeleteAll_clicked();
    void on_buttonEdit_clicked();
    void on_buttonAddGun_clicked();
    void on_buttonEditGun_clicked();
    void on_buttonDeleteGun_clicked();
    void on_buttonDeleteAllGun_clicked();
    void on_buttonPreviousWeek_clicked();
    void on_buttonNextWeek_clicked();
    void cellSlot(int row, int col);
};

#endif // WIDGET_H
