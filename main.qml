import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtQml.Models 2.15
import QtMultimedia 5.12

import Player 1.0
import Tapper 1.0
import Picker 1.0

Window {
    property alias playerController: player.controller
    property alias tapperController: tapper.controller
    property alias tempoTumbler: tempoPicker.tumbler
    property alias tempoController: tempoPicker.controller

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
        controller.maxTempo: playerController.tempoMax
        controller.minTempo: playerController.tempoMin
        shift: playerController.tempoMin
        tumbler.currentIndex: playerController.tempo - shift

    }
    Connections {
            target: tempoController
            function onIndexChanged() {
                console.log("id");
                console.log(tempoController.tempo);
                playerController.tempo = tempoController.tempo;
            }
        }

    Connections {
            target: tempoController
            function onTempoChanged() {
                console.log("--");
                playerController.tempo = tempoController.tempo;
                tempoTumbler.currentIndex = tempoController.index;
            }
        }

    Connections {
            target: tapperController
            function onTempoChanged() {
                tempoController.tempo = tapperController.tempo;
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
