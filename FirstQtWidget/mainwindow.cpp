#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Slot code implementation
void MainWindow::on_btHello_clicked()
{
    qDebug("Simple debug message");

    // Show a message box
    QMessageBox msgBox;
    msgBox.setWindowTitle("Any title");
    msgBox.setText("Hello Qt");
    msgBox.setInformativeText("Informative text");

    msgBox.exec();
}
