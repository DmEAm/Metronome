import QtQuick 2.12
import QtQuick.Controls 2.0
import QtQml.Models 2.15

import Picker 1.0

Item {
    property alias controller: controller
    property alias tumbler: picker.tumbler
    property alias delegateComponent: delegateComponent

    PickerController {
        id: controller
    }

    FontMetrics {
        id: fontMetrics
    }

    DelegateModel {
        id: delegateComponent
        delegate: Label {
            text: controller.formatText(Tumbler.tumbler.count, modelData)
            opacity: 1.0 - Math.abs(Tumbler.displacement) / (Tumbler.tumbler.visibleItemCount / 2)
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: fontMetrics.font.pixelSize * 1.25
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
        tumbler.onCurrentIndexChanged: controller.index = tumbler.currentIndex
    }
}
