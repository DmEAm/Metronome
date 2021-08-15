import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtQml.Models 2.15
import QtMultimedia 5.12

import Player 1.0
import Tapper 1.0
import Picker 1.0

Window{
    property alias playerController: player.controller
    property alias tapperController: tapper.controller
    property alias tempoController: tempoPicker.controller
    property alias accentController: accentPicker.controller
    property alias tempoTumbler: tempoPicker.tumbler

    width: 400
    height: 500
    maximumHeight: height
    maximumWidth: width
    minimumHeight: height
    minimumWidth: width

    visible: true
    title: qsTr("Metronome")

    ColumnLayout{
        spacing: 0
        anchors.fill: parent

        TempoPicker{
            id: tempoPicker
            Layout.alignment: Qt.AlignCenter
            delegateComponent.model: playerController.range
            controller.maxTempo: playerController.tempoMax
            controller.minTempo: playerController.tempoMin
            tumbler.currentIndex: playerController.tempo - playerController.tempoMin
        }

        RowLayout{
            spacing: 2
            Layout.minimumHeight: player.height
            Item{
                Layout.fillWidth: true
                Layout.fillHeight: true
            }
            Item{
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignHCenter
                Player{
                    id: player
                    anchors.centerIn: parent
                }
            }
            Item{
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignHCenter
                Tapper{
                    id: tapper
                    anchors.centerIn: parent
                }
            }
        }

        RowLayout{
            spacing: 2
            Layout.minimumHeight: accentPicker.height
            Item{
                Layout.fillWidth: true
                Layout.fillHeight: true
                DurationPicker{
                    id: durationPicker
                    anchors.centerIn: parent
                }
            }
            Item{
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignHCenter
                DurationPicker{
                    id: durationPicker_2
                    anchors.centerIn: parent
                }
            }
            Item{
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignHCenter
                AccentPicker{
                    id: accentPicker
                    delegateComponent.model: 13
                    anchors.centerIn: parent
                }
            }
        }
    }

    Connections{
        target: tempoController
        function onIndexChanged(){
            playerController.tempo = tempoController.tempo;
        }

    }

    Connections{
        target: tempoController
        function onTempoChanged(){
            playerController.tempo = tempoController.tempo;
            tempoTumbler.currentIndex = tempoController.index;
        }
    }

    Connections{
        target: tapperController
        function onTempoChanged(){
            tempoController.tempo = tapperController.tempo;
        }
    }

    Connections{
        target: accentController
        function onIndexChanged(){
            playerController.accent = accentController.index;
        }
    }
}
