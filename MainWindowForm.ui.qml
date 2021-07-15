import QtQuick 2.4

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

/*##^##
Designer {
    D{i:2}
}
##^##*/
