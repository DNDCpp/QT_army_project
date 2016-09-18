#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(1);

    connect(ui->pageOne,SIGNAL(clicked(bool)),this, SLOT(setPageOne()));
    connect(ui->pageTwo,SIGNAL(clicked(bool)),this, SLOT(setPageTwo()));
    connect(ui->pageThree,SIGNAL(clicked(bool)),this, SLOT(setPageThree()));
}

Widget::~Widget()
{
//    delete ui;
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
