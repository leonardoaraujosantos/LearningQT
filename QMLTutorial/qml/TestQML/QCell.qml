import QtQuick 1.0

// Item é um elemento visual do QML
Item {
    id: container

    // Cria um alias corCelula para propiedade rectangle.color
    property alias corCelula: rectangle.color
    signal clicked(color cellColor)

    // Tamanho do objeto
    width: 80; height: 50

    Rectangle {
        id: rectangle
        border.color: "green"
        anchors.fill: parent
    }

    // Area do mouse
    MouseArea {
        anchors.fill: parent
        onClicked: container.clicked(container.cellColor)
    }
}
