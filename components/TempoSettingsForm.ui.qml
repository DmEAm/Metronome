import QtQuick 2.4
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.11

Item {
    id: element
    width: 200
    height: 200
    property alias lMinTempo: lMinTempo
    property alias lMaxTempo: lMaxTempo
    property alias lTempo: lTempo
    property alias sMinTempo: sMinTempo
    property alias sMaxTempo: sMaxTempo
    property alias sTempo: sTempo
    property alias element: element

    ColumnLayout {
        id: columnLayout
        anchors.fill: parent

        RowLayout {
            id: rlTempo
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
                    text: qsTr("Tempo")
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
                    id: sTempo
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
                    id: lTempo
                    width: 40
                    height: 15
                    text: qsTr("")
                    horizontalAlignment: Text.AlignLeft
                    verticalAlignment: Text.AlignVCenter
                }
            }
        }

        RowLayout {
            id: rlMaxTempo
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
                    id: lbl2
                    width: 100
                    text: qsTr("Max Tempo")
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

                Slider {
                    id: sMaxTempo
                    anchors.fill: parent
                    stepSize: 1
                    value: 0.5
                }
            }

            Item {
                id: element8
                width: 40
                height: 15

                Label {
                    id: lMaxTempo
                    width: 40
                    height: 15
                    text: qsTr("")
                    verticalAlignment: Text.AlignVCenter
                }
            }
        }

        RowLayout {
            id: rlMinTempo
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
                    id: lbl3
                    text: qsTr("Min Tempo")
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

                Slider {
                    id: sMinTempo
                    anchors.fill: parent
                    stepSize: 1
                    value: 0.5
                }
            }

            Item {
                id: element9
                width: 40
                height: 15

                Label {
                    id: lMinTempo
                    width: 40
                    height: 15
                    text: qsTr("")
                    verticalAlignment: Text.AlignVCenter
                }
            }
        }
    }
}
