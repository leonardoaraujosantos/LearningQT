#ifndef SIMPLECLASS_H
#define SIMPLECLASS_H

#include <QObject>

class SimpleClass : public QObject
{
    Q_OBJECT
public:
    explicit SimpleClass(QObject *parent = 0);
    Q_INVOKABLE void simpleMethod();

signals:

public slots:

};

#endif // SIMPLECLASS_H
