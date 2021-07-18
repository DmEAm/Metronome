import QtQuick 2.0
import QtQml.Models 2.2

import Picker 1.0

PickerForm {
    id: picker

    property var model;

    PickerController {
        id: controller
    }

    function select(view) {
        view.currentIndex = view.indexAt(0, view.contentY + 0.5 * view.height)
    }

    view.onMovementEnded: {
        select(view)
        timer.restart()
    }

    view.onFlickEnded: {
        select(view);
        timer.restart()
    }

    Timer {
        id: timer
        interval: 1
        onTriggered: clicked(view.currentItem.value)
    }
}
