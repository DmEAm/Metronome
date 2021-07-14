import QtQuick 2.4
import QtQuick.Controls 2.0

import Tapper 1.0

TapperForm {

    TapperController {
        id: backend
    }

    TextField {
        text: backend.userName
        placeholderText: qsTr("User name")
        anchors.centerIn: parent
        onEditingFinished: backend.userName = text
    }
}
