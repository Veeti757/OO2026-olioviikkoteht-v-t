#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QTimer>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pQTimer = new QTimer(this);
    pQTimer->setInterval(1000);
    connect(ui->start,&QPushButton::clicked,this,&MainWindow::handleStart);
    connect(ui->stop,&QPushButton::clicked,this,&MainWindow::handleStop);
    connect(ui->time1,&QPushButton::clicked,this,&MainWindow::handle120sec);
    connect(ui->time2,&QPushButton::clicked,this,&MainWindow::handle5min);
    connect(ui->switch1,&QPushButton::clicked,this,&MainWindow::handleSwitch1);
    connect(ui->switch2,&QPushButton::clicked,this,&MainWindow::handleSwitch2);
    connect(pQTimer,&QTimer::timeout,this,&MainWindow::timeout);
    player1Time = 0;
    player2Time = 0;
    gameTime = 0;
    currentPlayer = 1;
    setGameInfoText("Select gametime and press start",12);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timeout()
{
    if(currentPlayer == 1)
    {
        player1Time--;
    }
    else
    {
        player2Time--;
    }
    updateProgressBar();
    if(player1Time <= 0)
    {
        pQTimer->stop();
        setGameInfoText("Player 2 WON!!",12);
    }
    if(player2Time <= 0)
    {
        pQTimer->stop();
        setGameInfoText("Player 1 WON!!",12);
    }
}

void MainWindow::handleStart()
{
    pQTimer->start();
    setGameInfoText("GAME ONGOING",12);
}

void MainWindow::handleStop()
{
    pQTimer->stop();
    setGameInfoText("GAME STOPPED PRESS TIME AND START",12);
}

void MainWindow::handleSwitch1()
{
    if(currentPlayer == 1)
    {
        currentPlayer = 2;
    }
}

void MainWindow::handleSwitch2()
{
    if(currentPlayer == 2)
    {
        currentPlayer = 1;
    }
}

void MainWindow::handle5min()
{
    gameTime = 300;
    player1Time = gameTime;
    player2Time = gameTime;
    currentPlayer = 1;
    updateProgressBar();
}

void MainWindow::handle120sec()
{
    gameTime = 120;
    player1Time = gameTime;
    player2Time = gameTime;
    currentPlayer = 1;
    updateProgressBar();
}

void MainWindow::updateProgressBar()
{
    if(gameTime == 0)
        return;
    int p1pr = (player1Time * 100) / gameTime;
    int p2pr = (player2Time * 100) / gameTime;
    ui->Progress1->setValue(p1pr);
    ui->Progress2->setValue(p2pr);
}

void MainWindow::setGameInfoText(QString t, short s)
{
    ui->label->setText(t);
    QFont f = ui->label->font();
    f.setPointSize(s);
    ui->label->setFont(f);
}
