import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.0

import Tapper 1.0

Window {
    Tapper {
        id: tapper
    }

    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
}
