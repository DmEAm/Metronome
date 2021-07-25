import QtQuick 2.12
import QtQuick.Controls 2.0
import QtQml.Models 2.15

import Picker 1.0
import TempoPicker 1.0

Item {
    property alias controller: controller
    property alias tumbler: picker.tumbler
    property alias delegateComponent: delegateComponent

    TempoController {
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
        tumbler.onCurrentIndexChanged: controller.index = tumbler.currentIndex
    }
}
