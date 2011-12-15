/*
    Simple client DBUS that call the method SayBye defined on the interface
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

    To create the class that will call those methods...
    $ qdbusxml2cpp -v -c ClientDBus -p clientdbus.h:clientdbus.cpp com.nokia.Demo.xml
*/

#include <QtCore/QCoreApplication>
#include "clientdbus.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ClientDBus* client = new ClientDBus("com.nokia.Demo", "/", QDBusConnection::sessionBus(), 0);
    //QObject::connect(client, SIGNAL(LateEvent(QString)), this, SLOT(mySlot(QString)));
    client->SayBye();

    return a.exec();
}
