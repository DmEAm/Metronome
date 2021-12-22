import QtQuick 2.12
import QtQuick.Controls 2.0
import QtQml.Models 2.12

import Picker 1.0
import TempoPicker 1.0

Item {
    property alias tumbler: picker.tumbler
    property alias element: picker.element
    property alias delegateComponent: delegateComponent

    width: 180
    height: element.height

    FontMetrics {
        id: fontMetrics
    }

    DelegateModel {
        id: delegateComponent
        delegate: Label {
            text: tempoController.formatText(Tumbler.tumbler.count, modelData)
            opacity: 1.0 - Math.abs(Tumbler.displacement) / (Tumbler.tumbler.visibleItemCount / 2)
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: fontMetrics.font.pixelSize * 1.25
        }
    }

    Picker {
        id: picker
        anchors.fill: parent
        tumbler.onCurrentIndexChanged: tempoController.index = tumbler.currentIndex
    }

    Component.onCompleted: {
        delegateComponent.model = tempoController.tempo.range;
        //Load again settings after config model range
        tempoController.loadTempo();
        tumbler.currentIndex = tempoController.index;
    }
}
