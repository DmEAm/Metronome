import QtQuick 2.4
import QtQuick.Controls 2.3

Item {
    width: 100
    height: 100
    property alias tapp: tapp

    RoundButton {
        id: tapp

        icon.name: "Tap Tempo"
        icon.source: "qrc:/icons/tap.svg"
        icon.width: width / 2
        icon.height: height / 2
        radius: 100
        anchors.fill: parent
        autoRepeat: true
        flat: true
    }
}

/*##^##
Designer {
    D{i:1}
}
##^##*/
