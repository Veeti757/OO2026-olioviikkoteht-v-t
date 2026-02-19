#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    state = 1;
    connect(ui->clear,&QPushButton::clicked,this,&MainWindow::resetLineEdits);
    connect(ui->enter,&QPushButton::clicked,this,&::MainWindow::EnterClickHandler);
    connect(ui->B1,&QPushButton::clicked,this,&MainWindow::numberClickedHandler);
    connect(ui->B2,&QPushButton::clicked,this,&MainWindow::numberClickedHandler);
    connect(ui->B3,&QPushButton::clicked,this,&MainWindow::numberClickedHandler);
    connect(ui->B4,&QPushButton::clicked,this,&MainWindow::numberClickedHandler);
    connect(ui->B5,&QPushButton::clicked,this,&MainWindow::numberClickedHandler);
    connect(ui->B6,&QPushButton::clicked,this,&MainWindow::numberClickedHandler);
    connect(ui->B7,&QPushButton::clicked,this,&MainWindow::numberClickedHandler);
    connect(ui->B8,&QPushButton::clicked,this,&MainWindow::numberClickedHandler);
    connect(ui->B9,&QPushButton::clicked,this,&MainWindow::numberClickedHandler);
    connect(ui->B0,&QPushButton::clicked,this,&MainWindow::numberClickedHandler);
    connect(ui->Bplus,&QPushButton::clicked,this,&MainWindow::operandClickHandler);
    connect(ui->Bmiinus,&QPushButton::clicked,this,&MainWindow::operandClickHandler);
    connect(ui->Bkerto,&QPushButton::clicked,this,&MainWindow::operandClickHandler);
    connect(ui->Bjako,&QPushButton::clicked,this,&MainWindow::operandClickHandler);

}


void MainWindow::numberClickedHandler()
{   if(state==1)
    {
        QPushButton * button = qobject_cast<QPushButton*>(sender());
        qDebug() << "button name:" << button->text();
        QString teksti = ui->Num1->text();
        ui->Num1->setText(teksti+button->text());
        Number1 = ui->Num1->text();
    }
    if(state==2)
    {
        QPushButton * button = qobject_cast<QPushButton*>(sender());
        qDebug() << "button name:" << button->text();
        QString teksti = ui->Num2->text();
        ui->Num2->setText(teksti+button->text());
        Number2 = ui->Num2->text();
    }
}

void MainWindow::EnterClickHandler()
{
    if(operand==0)
    {
        float n1 = Number1.toFloat();
        float n2 = Number2.toFloat();
        result = n1 + n2;
        ui->Result->setText(QString::number(result));
    }
    if(operand==1)
    {
        float n1 = Number1.toFloat();
        float n2 = Number2.toFloat();
        result = n1* n2;
         ui->Result->setText(QString::number(result));
    }
    if(operand==2)
    {
        float n1 = Number1.toFloat();
        float n2 = Number2.toFloat();
        result = n1 / n2;
        ui->Result->setText(QString::number(result));
    }
    if(operand==3)
    {
        float n1 = Number1.toFloat();
        float n2 = Number2.toFloat();
        result = n1 - n2;
        ui->Result->setText(QString::number(result));
    }

}

void MainWindow::operandClickHandler()
{
    state = 2;
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    qDebug() << "button name:" << button->text();
    if(button->text()=="+")
    {
        operand = 0;
    }
    if(button->text()=="*")
    {
        operand = 1;
    }
    if(button->text()=="/")
    {
        operand = 2;
    }
    if(button->text()=="-")
    {
        operand = 3;
    }

}

void MainWindow::resetLineEdits()
{
    ui->Num1->setText(" ");
    ui->Num2->setText(" ");
    ui->Result->setText(" ");
    state = 1;
}

MainWindow::~MainWindow()
{
    delete ui;
}
