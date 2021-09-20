import QtQuick 2.12
import QtQuick.Controls 2.0
import QtQml.Models 2.12

import Picker 1.0

Item {
    property alias element: picker.element

    width: 100
    height: 100

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
            color: "#343434";
            radius: 1;
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
        anchors.fill: parent
    }
}
