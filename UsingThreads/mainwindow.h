#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void progessValueChanged(int val);


private slots:
    void on_btBlocking_clicked();

    void on_btNonBlocking_clicked();
    void threadDone();

    void on_btStartProgress_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
