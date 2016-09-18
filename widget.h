#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;

public slots:
    void setPageOne();
    void setPageTwo();
    void setPageThree();
private slots:
    void on_stackedWidget_currentChanged(int arg1);
    void on_buttonAdd_clicked();
};

#endif // WIDGET_H
