import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtQml.Models 2.15

import Tapper 1.0
import Picker 1.0
import Player 1.0
import QtMultimedia 5.12

Window {
    property alias playerController: player.controller
    property alias tapperController: tapper.controller
    property alias tempoTumbler: tempoPicker.tumbler
    property alias pickerController: tempoPicker.controller

    width: 400
    height: 500
    visible: true
    title: qsTr("Metronome")

    Player
    {
        id: player
        x: 125
        y: 220
    }

    Tapper {
        id: tapper
        x: 300
        y: 75
    }

    TempoPicker {
        id: tempoPicker
        x: 100
        y: 75
        delegateComponent.model: playerController.range
        shift: playerController.tempoMin
        tumbler.currentIndex: playerController.tempo - shift

    }
    Connections {
            target: pickerController
            function onValueChanged() {
                playerController.tempo = pickerController.value;
            }
        }

    Connections {
            target: tapperController
            function onTempoChanged() {
                if (tapperController.tempo > playerController.tempoMax)
                    tempoTumbler.currentIndex = playerController.tempoMax;
                else if (tapperController.tempo < playerController.tempoMin)
                    tempoTumbler.currentIndex = playerController.tempoMin;
                else
                    tempoTumbler.currentIndex = tapperController.tempo;
                tempoTumbler.currentIndex -= tempoPicker.shift;
            }
        }

    DurationPicker {
        id: durationPicker
        x: 40
        y: 390
    }

    DurationPicker {
        id: durationPicker_2
        x: 150
        y: 390
    }

    DurationPicker {
        id: durationPicker_3
        x: 260
        y: 390
    }
}
