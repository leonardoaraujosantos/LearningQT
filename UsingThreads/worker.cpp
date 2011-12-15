#include "worker.h"
#include "QTimer"

Worker::Worker()
{
    // Correct the affinity
    //(Put all the code to run under this thread)
    moveToThread(this);
}

void Worker::doTheWork()
{
    // Spend some time
    sleep(5);

    // Emit signal "done"
    emit done();
}

void Worker::run()
{
    QTimer::singleShot(0, this, SLOT(doTheWork()));
    exec();
}
