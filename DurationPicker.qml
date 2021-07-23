import QtQuick 2.12
import QtQuick.Controls 2.0
import QtQml.Models 2.15

import Picker 1.0

Item {
    DelegateModel {
        id: delegateComponent
        model: [
            "qrc:/icons/fourth.png",
            "qrc:/icons/eighths.png",
            "qrc:/icons/shuffle.png",
            "qrc:/icons/sixteenth.png",
            "qrc:/icons/triplets.png"
        ]
        delegate: Rectangle {
            color: "#343434"
            Image {
                x: 35
                width: 30
                height: 30
                source: modelData
            }
        }
    }

    Picker {
        id: picker
        frame.width: 100
        frame.height: 100
        rectangle.width: 100
        rectangle.height: 100
        tumbler.width: 100
        tumbler.height: 100
    }
}
