import QtQuick 2.0
import QtQml.Models 2.2
import QtQuick.Controls 2.12

Item {
    property alias rectangle: rectangle
    property alias frame: frame
    property alias tumbler: tumbler
    Rectangle {
        id: rectangle
        width: 200
        height: 100
        Frame {
            id: frame
            x: 0
            y: 0
            width: 200
            height: 100
            padding: 0
            anchors.centerIn: parent

            Tumbler {
                visibleItemCount: 3
                id: tumbler
                width: 200
                height: 100
                model: delegateComponent
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;formeditorZoom:0.8999999761581421;height:480;width:640}
}
##^##*/

