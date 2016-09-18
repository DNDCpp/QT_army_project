#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
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

