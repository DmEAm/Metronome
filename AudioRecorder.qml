import QtQuick 2.4
import QtQuick.Controls 2.3

import TempoDetector 1.0

Item {
    width: 200
    height: 200
    property alias record: record

    AudioRecordController {
        id: controller
    }

    RoundButton {
        id: record
        width: 100
        height: 100

        icon.name: "Record Tempo"
        icon.source: "qrc:/icons/record.svg"
        icon.width: width / 2
        icon.height: height / 2
        radius: 100
        flat: true
        onPressAndHold: controller.record()
        onReleased: controller.stop()
    }
}
