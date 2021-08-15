import QtQuick 2.4
import QtQuick.Controls 2.3

Item {
    id: element
    width: 150
    height: 150
    property alias play: play

    RoundButton {
        id: play
        anchors.fill: parent
        icon.name: "Play"
    }
}
