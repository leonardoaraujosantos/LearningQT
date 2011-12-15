#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create the state objects
    s1 = new QState();
    s2 = new QState();
    s3 = new QState();

    // Create transitions triggered by the signal clicked
    s1->addTransition(ui->btState, SIGNAL(clicked()), s2);
    s2->addTransition(ui->btState, SIGNAL(clicked()), s3);
    s3->addTransition(ui->btState, SIGNAL(clicked()), s1);

    // Set some property when the state is entered
    s1->assignProperty(ui->lbShowState, "text", "In s1");
    s2->assignProperty(ui->lbShowState, "text", "In s2");
    s3->assignProperty(ui->lbShowState, "text", "In s3");


    // Add the states on the machine and set it's initial state
    machine.addState(s1);
    machine.addState(s2);
    machine.addState(s3);
    machine.setInitialState(s1);

    // Start the machine (executes asynchronously)
    machine.start();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btState_clicked()
{

}
