#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMessageBox>
#include <QDate>

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

private:
    Ui::Widget *ui;

    enum Column {
        SURNAME, NAME, FATHERNAME, TYPE, RANK, POSITION, DATE, GUN, CALIBER, COUNT
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

public slots:
    void setPageOne();
    void setPageTwo();
    void setPageThree();

private slots:
    void on_stackedWidget_currentChanged(int arg1);
    void on_buttonAdd_clicked();
    void on_buttonDelete_clicked();
    void on_buttonDeleteAll_clicked();
    void on_buttonEdit_clicked();
};

#endif // WIDGET_H
