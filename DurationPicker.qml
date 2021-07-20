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
                width: 30
                height: 30
                source: modelData
            }
        }
    }

    Picker {
        width: 200
        height: 200
    }
}
