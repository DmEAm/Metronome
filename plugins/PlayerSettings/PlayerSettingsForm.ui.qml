import QtQuick 2.4
import QtQuick.Controls 2.3

Item {
    id: element
    width: 150
    height: 150
    property alias sVolume: sVolume
    property alias element: element

    Slider {
        id: sVolume
        anchors.fill: parent
        to: 100
        value: 0.5
    }
}

/*##^##
Designer {
    D{i:1}
}
##^##*/
