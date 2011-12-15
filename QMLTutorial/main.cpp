#include <QtGui/QApplication>
#include "qmlapplicationviewer.h"

#include <QtDeclarative/QDeclarativeContext>
#include <QtDeclarative/QDeclarativeView>
#include <QtDeclarative/QDeclarativeComponent>

#include "simpleclass.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QmlApplicationViewer viewer;

    // Adciona o contexto para poder ficar visivel pelo QML
    viewer.rootContext()->setContextProperty("contextoSimples", new SimpleClass());

    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(QLatin1String("qml/TestQML/main.qml"));
    viewer.showExpanded();

    return app.exec();
}
