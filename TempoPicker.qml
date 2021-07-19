import QtQuick 2.12
import QtQuick.Controls 2.0
import QtQml.Models 2.15

import Picker 1.0

Item {

    PickerController {
        id: controller
    }

    FontMetrics {
        id: fontMetrics
    }

    DelegateModel {
        id: delegateComponent

        model: 300
        delegate: Label {
            text: controller.formatText(Tumbler.tumbler.count, modelData)
            opacity: 1.0 - Math.abs(Tumbler.displacement) / (Tumbler.tumbler.visibleItemCount / 2)
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: fontMetrics.font.pixelSize * 1.25
        }
    }

    Picker {
        width: 200
        height: 200
        x: 100
        y: 200
    }
}
