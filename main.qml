import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtQml.Models 2.15
import QtMultimedia 5.12
import QtCharts 2.15

import Player 1.0
import Tapper 1.0
import Picker 1.0
import AudioAnalysis 1.0

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

    TempoDetector {
        id: tempoDetector
        onDetecting: popup.open()
//        onDetected: popup.close()
    }

    Popup {
        id: popup
        x: 100
        y: 100
        width: 200
        height: 300
        modal: true
        focus: true
        closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutsideParent

        contentItem: ColumnLayout {
            anchors.fill: parent

            ChartView {
                title: "Audio"
                anchors.fill: parent
                antialiasing: true

                SplineSeries {
                    name: "SplineSeries"
                    XYPoint { x: 0; y: 0.0 }
                    XYPoint { x: 1.1; y: 3.2 }
                    XYPoint { x: 1.9; y: 2.4 }
                    XYPoint { x: 2.1; y: 2.1 }
                    XYPoint { x: 2.9; y: 2.6 }
                    XYPoint { x: 3.4; y: 2.3 }
                    XYPoint { x: 4.1; y: 3.1 }
                }
            }

            ProgressBar {
                id: progress
            }
        }

    }

    Connections {
        target: tempoDetector

        function onProgress(percent) {
            progress.value = percent;
        }

        function onDetecting() {
            progress.value = 0;
        }
    }

    DropArea {
        anchors.fill: parent
        onDropped: tempoDetector.detect(drop.text)
    }

    ColumnLayout{
        spacing: 0
        anchors.fill: parent

        RowLayout{
            spacing: 4
            Layout.minimumHeight: tempoPicker.height
            Item{
                Layout.fillWidth: true
                Layout.fillHeight: true

                AudioRecorder {
                    id: audioRecorder
                    x: 0
                    y: 75
                }
            }
            Item{
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignHCenter
                TempoPicker{
                    id: tempoPicker
                    anchors.centerIn: parent
                    delegateComponent.model: playerController.range
                    controller.maxTempo: playerController.tempoMax
                    controller.minTempo: playerController.tempoMin
                    tumbler.currentIndex: playerController.tempo - playerController.tempoMin
                }
            }
            Item{
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignRight
                Tapper{
                    id: tapper
                    anchors.centerIn: parent
                }
            }
        }

        Player{
            id: player
            Layout.alignment: Qt.AlignHCenter
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

    Connections {
        target: tempoDetector
        function onDetected(tempo) {
            tempoController.tempo = tempo;
        }
    }
}
