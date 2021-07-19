import QtQuick 2.0
import QtQml.Models 2.2
import QtQuick.Controls 2.12

Item {
    Rectangle {
        width: frame.implicitWidth + 10
        height: frame.implicitHeight + 10
        Frame {
            id: frame
            padding: 0
            anchors.centerIn: parent

            Tumbler {
                visibleItemCount: 3
                id: amPmTumbler
                model: delegateComponent
            }
        }
    }

}



/*##^##
Designer {
    D{i:0;formeditorZoom:4}
}
##^##*/
