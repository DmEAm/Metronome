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

    ListView {
        id: listview
        width: parent.width
        height: parent.height
        spacing: 10
        anchors{
            left: parent.left
            right: parent.right
            bottom: parent.bottom
        }
        orientation: Qt.Vertical
        delegate: Rectangle {
            width: 65
            height: 65
            color: "#343434"
            Image {
                source: modelData
            }
        }
    }
    Component.onCompleted: {
        listview.model = [
                    "qrc:/icons/icons/fourth.png",
                    "qrc:/icons/icons/eighths.png",
                    "qrc:/icons/icons/shuffle.png",
                    "qrc:/icons/icons/sixteenth.png",
                    "qrc:/icons/icons/triplets.png"
                ]
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
