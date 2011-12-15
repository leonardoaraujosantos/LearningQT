#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "worker.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->progressBar->setRange(0,100);

    connect(this, SIGNAL(progessValueChanged(int)), ui->progressBar, SLOT(setValue(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Blocking code
void MainWindow::on_btBlocking_clicked()
{
    ui->lbCodeStatus->setText("Waiting");
    sleep(5);
    ui->lbCodeStatus->setText("Done");
}

// Non Blocking code
void MainWindow::on_btNonBlocking_clicked()
{
    ui->lbCodeStatus->setText("Waiting");

    // Create the worker thread
    Worker *workThread = new Worker();

    // Connect the slot "threadDone" to our thread "done" signal
    connect(workThread, SIGNAL(done()),this, SLOT(threadDone()), Qt::QueuedConnection);

    // Start the thread
    workThread->start();
}

// Slot called when the thread is done
void MainWindow::threadDone()
{
    ui->lbCodeStatus->setText("Done");
}

void MainWindow::on_btStartProgress_clicked()
{
    static int value = 0;
    value += 10;
    emit progessValueChanged(value);
}
