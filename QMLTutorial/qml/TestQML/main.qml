import QtQuick 1.0

// Tela principal
Rectangle {
    // Tamanho em pixels da tela principal
    width: 300
    height: 300
    id: rectPrincipal

    // Elemento de texto
    Text {
        // Nome do objeto
        id: lblHello
        text: qsTr("APRENDENDO QML")
        y: 150
        //anchors.centerIn: parent
        anchors.horizontalCenter: rectPrincipal.horizontalCenter


        // Area de mouse sob o texto
        MouseArea { id: mouseArea; anchors.fill: parent }

        /*
            Cria estado "desce" que acontece quando o botao for pressionado
            quando isto acontecer poe o label vermelho e roda 180 graus
        */
        states: State
        {
            name: "desce"; when: mouseArea.pressed == true
            PropertyChanges { target: lblHello; y: 300; rotation: 180; color: "red" }
        }

        /*
            Cria uma transicao que acontece entre um estado qualquer e o estado "desce"
            animando as propiedades "y, e rotation" para acontecer mais suavemente, como
            queremos que ter a mesma suavidade quando voltarmos para o estado inicial,
            usamos reversible = true
        */
        transitions: Transition
        {
            from: ""; to: "desce"; reversible: true

            // ParallelAnimation forca que as propiedades y,rotacao animem ao mesmo tempo
            ParallelAnimation
            {
                NumberAnimation { properties: "y,rotation"; duration: 500; easing.type: Easing.InOutQuad }
                ColorAnimation { duration: 500 }
            }
        }



    }

    // Cria um grid de objetos QCell
    Grid {
             id: colorPicker
             x: 4; anchors.bottom: rectPrincipal.bottom; anchors.bottomMargin: 4
             rows: 2; columns: 3; spacing: 6

             /*
                Instancia objeto QCell e altera a propiedade "corCelula"
                caso a celula tenha sido clicada iremos alterar a propiedade
                cor do label "lblHello"
             */
             QCell { corCelula: "red"; onClicked: lblHello.color = corCelula }
             QCell { corCelula: "green"; onClicked: lblHello.color = corCelula }
             QCell { corCelula: "blue"; onClicked: lblHello.color = corCelula }
             QCell { corCelula: "yellow"; onClicked: contextoSimples.simpleMethod() }
             QCell { corCelula: "steelblue"; onClicked: console.log("Botao" + " clicado" ) }
             QCell { corCelula: "black"; onClicked: Qt.quit() }
         }
}
