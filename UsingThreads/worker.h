#ifndef WORKER_H
#define WORKER_H

#include <QThread>

class Worker : public QThread
{
    // You need to have this macro to let Qt create the code for the signals/slots
    Q_OBJECT
protected:
    // Called automatic when the Thread is started
    void run();
signals:
    // Signal used by the object Worker to sinalize that it's done
    void done();
private slots:
    // Do the blocking work
    void doTheWork();
public:
    Worker();
};

#endif // WORKER_H
