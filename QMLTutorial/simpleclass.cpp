#include "simpleclass.h"

SimpleClass::SimpleClass(QObject *parent) :
    QObject(parent)
{
}

void SimpleClass::simpleMethod()
{
    qDebug("Called from QML");
}


