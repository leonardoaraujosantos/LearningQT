#include "adaptorImp.h"

AdaptorImp::AdaptorImp(QObject *parent) :
    QObject(parent)
{
}

void AdaptorImp::SayBye()
{
    qDebug("Bye!");
}

void AdaptorImp::SayHello(const QString &name, const QVariantMap &customdata)
{
    qDebug("Hello Leo!!");
}

