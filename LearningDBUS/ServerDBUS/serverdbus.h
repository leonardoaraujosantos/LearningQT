/*
 * This file was generated by qdbusxml2cpp version 0.7
 * Command line was: qdbusxml2cpp -c ServerDBus -a serverdbus.h:serverdbus.cpp simpleInterface.xml
 *
 * qdbusxml2cpp is Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * This file may have been hand-edited. Look for HAND-EDIT comments
 * before re-generating it.
 */

#ifndef SERVERDBUS_H_1323265714
#define SERVERDBUS_H_1323265714

#include <QtCore/QObject>
#include <QtDBus/QtDBus>
class QByteArray;
template<class T> class QList;
template<class Key, class Value> class QMap;
class QString;
class QStringList;
class QVariant;

/*
 * Adaptor class for interface com.nokia.Demo
 */
class ServerDBus: public QDBusAbstractAdaptor
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "com.nokia.Demo")
    Q_CLASSINFO("D-Bus Introspection", ""
"  <interface name=\"com.nokia.Demo\">\n"
"    <method name=\"SayHello\">\n"
"      <annotation value=\"QVariantMap\" name=\"com.trolltech.QtDBus.QtTypeName.In1\"/>\n"
"      <arg direction=\"in\" type=\"s\" name=\"name\"/>\n"
"      <arg direction=\"in\" type=\"a{sv}\" name=\"customdata\"/>\n"
"    </method>\n"
"    <method name=\"SayBye\"/>\n"
"    <signal name=\"LateEvent\">\n"
"      <arg direction=\"out\" type=\"s\" name=\"eventkind\"/>\n"
"    </signal>\n"
"  </interface>\n"
        "")
public:
    ServerDBus(QObject *parent);
    virtual ~ServerDBus();

public: // PROPERTIES
public Q_SLOTS: // METHODS
    void SayBye();
    void SayHello(const QString &name, const QVariantMap &customdata);
Q_SIGNALS: // SIGNALS
    void LateEvent(const QString &eventkind);
};

#endif