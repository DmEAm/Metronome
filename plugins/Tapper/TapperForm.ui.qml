import QtQuick 2.4
import QtQuick.Controls 2.3

Item {
    width: 400
    height: 400
    property alias tapp: tapp

    RoundButton {
        id: tapp
        width: 100
        height: 100

        icon.name: "Tap Tempo"
        icon.source: "qrc:/icons/tap.svg"
        icon.width: width / 2
        icon.height: height / 2
        radius: 100
        autoRepeat: true
        flat: true
    }
}
