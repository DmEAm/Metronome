import QtQuick 2.4
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.11

Item {
    id: element
    width: 200
    height: 200
    property alias cbAccentSound: cbAccentSound
    property alias cbBaseSound: cbBaseSound
    property alias sVolume: sVolume
    property alias element: element

    ColumnLayout {
        id: columnLayout
        anchors.fill: parent

        RowLayout {
            id: rlVolume
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
                    text: qsTr("Volume")
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
                    id: sVolume
                    anchors.fill: parent
                    to: 100
                    value: 0.5
                }
            }
        }

        RowLayout {
            id: rlSoundBase
            width: 100
            height: 100
            Layout.fillHeight: true
            Layout.fillWidth: true

            Item {
                id: element3
                width: 100
                height: 15
                Layout.fillHeight: false
                Layout.fillWidth: false
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

                Label {
                    id: lBaseSound
                    width: 100
                    text: qsTr("Base Sound")
                    anchors.fill: parent
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
            }

            Item {
                id: element4
                width: 0
                height: 30
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                Layout.fillHeight: false
                Layout.fillWidth: true

                ComboBox {
                    id: cbBaseSound
                    height: 25
                    anchors.fill: parent
                    currentIndex: -1
                    textRole: "text"
                }
            }
        }

        RowLayout {
            id: rlSoundAccent
            width: 100
            height: 100
            Layout.fillHeight: true
            Layout.fillWidth: true

            Item {
                id: element5
                width: 100
                height: 15
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

                Label {
                    id: lAccentSound
                    text: qsTr("Accent Sound")
                    anchors.fill: parent
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
            }

            Item {
                id: element6
                width: 0
                height: 30
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

                ComboBox {
                    id: cbAccentSound
                    height: 25
                    anchors.fill: parent
                    textRole: "text"
                }
            }
        }
    }
}

/*##^##
Designer {
    D{i:1}
}
##^##*/

