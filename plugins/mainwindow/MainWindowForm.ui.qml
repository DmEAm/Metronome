import QtQuick 2.4
import QtQuick.Controls 2.3

Item {
    id: element
    width: 400
    height: 400

    Grid {
        id: grid
        anchors.fill: parent
    }

    Text {
        id: element1
        text: qsTr("Text")
        anchors.fill: parent
        font.pixelSize: 12
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }
}



