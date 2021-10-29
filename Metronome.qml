import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtQml.Models 2.12
import QtMultimedia 5.12

import Player 1.0
import Tapper 1.0
import Picker 1.0
import UpDown 1.0
import TempoPicker 1.0

Component {

    ColumnLayout {
        property alias tapperController: tapper.controller
        property alias accentController: accentPicker.controller
        property alias tempoTumbler: tempoPicker.tumbler
        property alias updownController: updown.controller

        id: mainView
        spacing: 0

        RowLayout {
            spacing: 0
            Layout.maximumHeight: settButton.height
            Layout.minimumHeight: settButton.height
            Item {
                Layout.fillWidth: true
                Layout.fillHeight: true
                Rectangle {
                    anchors.fill: parent
                    color: "#E0E0E0"
                }
            }
            Item {
                Layout.preferredWidth: settButton.width
                Layout.alignment: Qt.AlignRight
                Button {
                    id: settButton
                    width: 50;
                    height: 40;
                    anchors.centerIn: parent
                    icon.source: "qrc:/icons/setting_line.svg";
                }
            }
        }

        RowLayout {
            spacing: 4
            Layout.minimumHeight: tempoPicker.height
            Item{
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignLeft
                UpDown {
                    id: updown
                    anchors.centerIn: parent
                }
            }
            Item {
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignHCenter
                TempoPicker {
                    id: tempoPicker
                    anchors.centerIn: parent
                }
            }
            Item {
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignRight
                Tapper{
                    id: tapper
                    anchors.centerIn: parent
                }
            }
        }

        Player {
            id: player
            Layout.alignment: Qt.AlignHCenter
        }

        RowLayout {
            spacing: 2
            Layout.minimumHeight: accentPicker.height
            Item {
                Layout.fillWidth: true
                Layout.fillHeight: true
                DurationPicker {
                    id: durationPicker
                    anchors.centerIn: parent
                }
            }
            Item {
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignHCenter
                DurationPicker {
                    id: durationPicker_2
                    anchors.centerIn: parent
                }
            }
            Item {
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignHCenter
                AccentPicker {
                    id: accentPicker
                    delegateComponent.model: 13
                    anchors.centerIn: parent
                }
            }
        }

        Connections {
            target: tempoController.tempo
            function onCurrentChanged() {
                tempoTumbler.currentIndex = tempoController.index;
            }
        }

        Connections {
            target: accentController
            function onIndexChanged() {
                playerController.accent = accentController.index;
            }
        }

        Connections {
            target: settButton
            function onClicked() {
                tempoController.saveTempo();
                stack.push(settView);
            }
        }

        Connections {
            target: updownController
            function onUp() {
                tempoTumbler.positionViewAtIndex(tempoTumbler.currentIndex - 1, Tumbler.Center);
            }
        }

        Connections {
            target: updownController
            function onDown() {
                tempoTumbler.positionViewAtIndex(tempoTumbler.currentIndex + 1, Tumbler.Center);
            }
        }
    }
}