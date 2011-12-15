/*
    QTConsoleApplication for a DBUS service provider
    Create a dbus services from this interface... (interface.xml)
    <node>
      <interface name="com.nokia.Demo">
        <method name="SayHello">
          <annotation name="com.trolltech.QtDBus.QtTypeName.In1" value="QVariantMap"/>
          <arg name="name" type="s" direction="in" />
          <arg name="customdata" type="a{sv}" direction="in" />
        </method>
        <method name="SayBye"/>
        <signal name="LateEvent">
            <arg name="eventkind" type="s" direction="out"/>
        </signal>
    </node>

    To create the server files (Adaptor class)
    qdbusxml2cpp -c ServerDBus -a serverdbus.h:serverdbus.cpp interface.xml

    After executing the sample check if the dbus service is avaible with:
    dbus-send --type=method_call --print-reply --dest=com.nokia.Demo / org.freedesktop.DBus.Introspectable.Introspect   (or)
    qdbus com.nokia.Demo /


    Calling "SayBye method"
    qdbus com.nokia.Demo / com.nokia.Demo.SayBye
    dbus-send --type=method_call --print-reply --dest=com.nokia.Demo / com.nokia.Demo.SayBye
*/
#include <QtCore/QCoreApplication>
#include <QtDBus/QDBusConnection>
#include <QtDBus/QtDBus>

#include "serverdbus.h"
#include "adaptorImp.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Create the object that implement the adaptor
    AdaptorImp* adaptorImplementation = new AdaptorImp;

    // Pass the object to the adaptor constructor
    new ServerDBus(adaptorImplementation);

    // Register the object on the session bus
    QDBusConnection connection = QDBusConnection::sessionBus();
    bool ret = connection.registerService("com.nokia.Demo");
    ret = connection.registerObject("/", adaptorImplementation);
    return a.exec();
}


