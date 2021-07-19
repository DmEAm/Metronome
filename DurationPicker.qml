import QtQuick 2.12
import QtQuick.Controls 2.0
import QtQml.Models 2.15

import Picker 1.0


Item {
    height: 500
    width: 500
    DelegateModel {
        id: durationModel
        model: [
            "qrc:/icons/icons/fourth.png",
            "qrc:/icons/icons/eighths.png",
            "qrc:/icons/icons/shuffle.png",
            "qrc:/icons/icons/sixteenth.png",
            "qrc:/icons/icons/triplets.png"
            ]
        delegate: Rectangle {
            width: 65
            height: 65
            color: "#343434"
            Image {
                source: modelData
            }
        }

    }

    ListView {
        id: listview

        width: parent.width
        height: parent.height
        spacing: 10
        anchors {
            left: parent.left
            right: parent.right
            bottom: parent.bottom
            fill: parent
        }
        orientation: Qt.Vertical
        model: durationModel
    }

}
