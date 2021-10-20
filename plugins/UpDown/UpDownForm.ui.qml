import QtQuick 2.4
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.11

Item {
    id: element
    width: 70
    height: 50
    property alias buttonDown: buttonDown
    property alias buttonUp: buttonUp

    ColumnLayout {
        id: columnLayout
        anchors.fill: parent
        spacing: 5.9

        Item {
            id: element1
            Layout.fillHeight: true
            Layout.fillWidth: true

            Button {
                id: buttonUp
                text: qsTr("Up")
                anchors.fill: parent
            }
        }

        Item {
            id: element2
            Layout.fillHeight: true
            Layout.fillWidth: true

            Button {
                id: buttonDown
                text: qsTr("Down")
                anchors.fill: parent
            }
        }
    }
}

/*##^##
Designer {
    D{i:1}
}
##^##*/

