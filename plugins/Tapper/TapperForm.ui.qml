import QtQuick 2.4
import QtQuick.Controls 2.15

Item {
    width: 400
    height: 400

    RoundButton {
        id: button
        width: 150
        height: 150

        onPressed: controller.tap()
        icon.name: "Tap Tempo"
        icon.source: "qrc:/icons/tap.svg"
        icon.width: width / 2
        icon.height: height / 2
        radius: 100
        autoRepeat: true
        flat: true
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:1.5}
}
##^##*/
