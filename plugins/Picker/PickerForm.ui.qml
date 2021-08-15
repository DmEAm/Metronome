import QtQuick 2.0
import QtQml.Models 2.2
import QtQuick.Controls 2.12

Item {
    id: element
    property alias rectangle: rectangle
    property alias frame: frame
    property alias tumbler: tumbler
    width: 200
    height: 100
    property alias currentItemFrame: currentItemFrame
    property alias element: element
    Rectangle {
        id: rectangle
        anchors.fill: parent
        Frame {
            id: frame
            anchors.fill: parent
            padding: 0

            Tumbler {
                visibleItemCount: 3
                id: tumbler
                anchors.fill: parent
                model: delegateComponent

                Frame {
                    id: currentItemFrame
                    x: 14
                    y: 30
                    width: 200
                    height: 40
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.8999999761581421}D{i:4}D{i:3}D{i:2}D{i:1}
}
##^##*/

