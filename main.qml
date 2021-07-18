import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

import Tapper 1.0
import Picker 1.0
import Player 1.0 as Player
import QtMultimedia 5.12

Window {
    width: 400
    height: 500
    visible: true
    title: qsTr("Metronome")

    Player.Player
    {
        id: player
        x: 125
        y: 250
    }
    Tapper {
        id: tapper
        x: 250
        y: 75
    }

    Picker {
        id: tempoPicker
        model: PickerModel { }
        width: 200
        height: 200
        x: 100
        y: 200
        onClicked: console.log('onClicked', date)
    }

    Row {
        x: 300
        y: 350
        Repeater {
            model: 3
            Picker {
                model: PickerModel { }
            }
        }
    }
}
