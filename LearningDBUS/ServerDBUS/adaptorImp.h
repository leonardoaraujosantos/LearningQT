#ifndef MYDEMO_H
#define MYDEMO_H

#include <QObject>
#include <QtDBus/QtDBus>

// Object that implement the funcionality of the adaptor
class AdaptorImp : public QObject
{
    Q_OBJECT
public:
    explicit AdaptorImp(QObject *parent = 0);
public Q_SLOTS:
    void SayBye();
    void SayHello(const QString &name, const QVariantMap &customdata);
Q_SIGNALS:
    void LateEvent(const QString &eventkind);
signals:

public slots:

};

#endif // MYDEMO_H
