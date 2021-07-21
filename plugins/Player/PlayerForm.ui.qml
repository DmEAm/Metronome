import QtQuick 2.4
import QtQuick.Controls 2.3

Item {
    id: element
    width: 150
    height: 150
    property alias bStart: bStart

    RoundButton {
        id: bStart
        x: 0
        y: 0
        width: 150
        height: 150
        icon.name: "Play"
        icon.source: "qrc:/icons/play.svg"
    }
}
