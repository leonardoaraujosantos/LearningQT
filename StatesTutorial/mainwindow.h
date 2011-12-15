#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStateMachine>
#include <QState>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btState_clicked();

private:
    Ui::MainWindow *ui;

    // State machine object
    QStateMachine machine;

    QState *s1,*s2,*s3;
};

#endif // MAINWINDOW_H
