import QtQuick 2.4
import QtQuick.Controls 2.3

Item {
    id: element
    width: 400
    height: 400
    property alias txt: txt

    Text {
        id: txt
        x: 73
        y: 53
        width: 78
        height: 30
        text: qsTr("Text")
        font.pixelSize: 12
    }
}
