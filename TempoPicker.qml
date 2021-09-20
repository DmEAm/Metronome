import QtQuick 2.12
import QtQuick.Controls 2.0
import QtQml.Models 2.12

import Picker 1.0

Item {
    property var controller: TempoController
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
            text: controller.formatText(Tumbler.tumbler.count, modelData)
            opacity: 1.0 - Math.abs(Tumbler.displacement) / (Tumbler.tumbler.visibleItemCount / 2)
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: fontMetrics.font.pixelSize * 1.25
        }
    }

    Picker {
        id: picker
        anchors.fill: parent
        tumbler.onCurrentIndexChanged: controller.index = tumbler.currentIndex
    }

    Connections{
        target: controller
        function onRangeChanged(){
            delegateComponent.model = controller.range;
        }
    }

    Component.onCompleted: {
        delegateComponent.model = controller.range;
        //Load again settings after config model range
        controller.loadTempo();
        tumbler.currentIndex = controller.index;
    }
}
