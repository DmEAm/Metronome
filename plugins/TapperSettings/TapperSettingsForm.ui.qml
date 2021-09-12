import QtQuick 2.4
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.11

Item {
    id: element
    width: 200
    height: 200
    property alias lInertia: lInertia
    property alias sInertia: sInertia
    property alias element: element

    ColumnLayout {
        id: columnLayout
        anchors.fill: parent

        RowLayout {
            id: rlInertia
            width: 100
            height: 100
            Layout.fillHeight: true
            Layout.fillWidth: true

            Item {
                id: element1
                width: 100
                height: 15
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                Layout.fillHeight: false
                Layout.fillWidth: false

                Label {
                    id: label
                    text: qsTr("Inertia")
                    anchors.fill: parent
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
            }

            Item {
                id: element2
                height: 30
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                Layout.fillHeight: false
                Layout.fillWidth: true

                Slider {
                    id: sInertia
                    anchors.fill: parent
                    stepSize: 1
                    to: 100
                    value: 0.5
                }
            }

            Item {
                id: element7
                width: 40
                height: 15
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

                Label {
                    id: lInertia
                    width: 40
                    height: 15
                    text: qsTr("")
                    horizontalAlignment: Text.AlignLeft
                    verticalAlignment: Text.AlignVCenter
                }
            }
        }
    }
}
