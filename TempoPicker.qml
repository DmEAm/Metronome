import QtQuick 2.12
import QtQuick.Controls 2.0
import QtQml.Models 2.15

import Picker 1.0

Item {
    property alias tumbler: picker.tumbler
    property alias delegateComponent: delegateComponent
    property alias controller: controller
    property alias shift: delegateComponent.shift

    PickerController {
        id: controller
    }

    FontMetrics {
        id: fontMetrics
    }

    DelegateModel {
        id: delegateComponent
        property int shift: 0
        delegate: Label {
            text: controller.formatText(Tumbler.tumbler.count, modelData + shift)
            opacity: 1.0 - Math.abs(Tumbler.displacement) / (Tumbler.tumbler.visibleItemCount / 2)
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: fontMetrics.font.pixelSize * 1.25
        }
    }

    Picker {
        id: picker

    }
}
